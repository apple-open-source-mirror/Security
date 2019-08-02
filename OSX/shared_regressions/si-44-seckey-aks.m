//
//  Copyright 2016 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>
#import <Security/SecItemPriv.h>
#import <Security/SecKeyPriv.h>
#import <Security/SecAccessControlPriv.h>
#import <libaks_acl_cf_keys.h>
#if !TARGET_OS_OSX
#import "MobileGestalt.h"
#else
#import <RemoteServiceDiscovery/RemoteServiceDiscovery.h>
#endif

#import "shared_regressions.h"

static id generateKey(id keyType, CFStringRef protection, BOOL noACL) {
    id accessControl;
    if (noACL) {
        accessControl = CFBridgingRelease(SecAccessControlCreate(kCFAllocatorDefault, NULL));
        SecAccessControlSetProtection((__bridge SecAccessControlRef)accessControl, protection, NULL);
    } else {
        accessControl = CFBridgingRelease(SecAccessControlCreateWithFlags(NULL, protection, kSecAccessControlPrivateKeyUsage, NULL));
    }
    NSDictionary *keyAttributes = @{ (id)kSecAttrTokenID : (id)kSecAttrTokenIDAppleKeyStore,
                                     (id)kSecAttrKeyType : keyType,
                                     (id)kSecAttrAccessControl : accessControl,
                                     (id)kSecAttrIsPermanent : @NO };
    NSError *error;
    id key = (__bridge_transfer id)SecKeyCreateRandomKey((CFDictionaryRef)keyAttributes, (void *)&error);
    ok(key, "failed to create random key %@", error);
    return key;
}

static void secKeySepTest(BOOL testPKA) {
    NSArray *keyTypes;
    if (testPKA) {
        keyTypes = @[(id)kSecAttrKeyTypeECSECPrimeRandom, (id)kSecAttrKeyTypeECSECPrimeRandomPKA, (id)kSecAttrKeyTypeSecureEnclaveAttestation];
    } else {
        keyTypes = @[(id)kSecAttrKeyTypeECSECPrimeRandom, (id)kSecAttrKeyTypeSecureEnclaveAttestation];
    }
    BOOL noACL = YES;
    for (id keyType in keyTypes) {
        id privateKey = generateKey((id)keyType, kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly, (noACL = !noACL));
        ok(privateKey, "failed to create key '%@'", keyType);
        id publicKey = (__bridge_transfer id)SecKeyCopyPublicKey((SecKeyRef)privateKey);

        NSArray *attestaionKeyTypes = @[@(kSecKeyAttestationKeyTypeSIK), @(kSecKeyAttestationKeyTypeGID)];
        for (NSNumber *attestationKeyType in attestaionKeyTypes) {
            id attestationKey = (__bridge_transfer id)SecKeyCopyAttestationKey([attestationKeyType unsignedIntValue], NULL);
            ok(attestationKey, "failed to create attestaion key '%@'", attestationKeyType);
            NSError *error;
            if (![keyType isEqual:(id)kSecAttrKeyTypeSecureEnclaveAttestation]) {
                const char rawData[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
                NSData *dataToSign = [NSData dataWithBytes:rawData length:sizeof(rawData)];
                NSData *signedData = (__bridge_transfer NSData*)SecKeyCreateSignature((SecKeyRef)privateKey, kSecKeyAlgorithmECDSASignatureMessageX962SHA256, (__bridge CFDataRef)dataToSign, (void *)&error);
                ok(signedData, "failed to sign data, error %@", error);
                error = nil;
                ok(SecKeyVerifySignature((SecKeyRef)publicKey, kSecKeyAlgorithmECDSASignatureMessageX962SHA256, (__bridge CFDataRef)dataToSign, (__bridge CFDataRef)signedData, (void *)&error),
                   "failed to verify data '%@'", error);

                // Try signing large data.
                dataToSign = [NSMutableData dataWithLength:10 * 1024 * 1024];
                error = nil;
                signedData = (__bridge_transfer NSData*)SecKeyCreateSignature((SecKeyRef)privateKey, kSecKeyAlgorithmECDSASignatureMessageX962SHA256, (__bridge CFDataRef)dataToSign, (void *)&error);
                ok(signedData, "failed to sign data, error %@", error);
                error = nil;
                ok(SecKeyVerifySignature((SecKeyRef)publicKey, kSecKeyAlgorithmECDSASignatureMessageX962SHA256, (__bridge CFDataRef)dataToSign, (__bridge CFDataRef)signedData, (void *)&error),
                   "failed to verify data '%@'", error);
            }
            NSData *attestationData = (__bridge_transfer NSData *)SecKeyCreateAttestation((__bridge SecKeyRef)attestationKey, (__bridge SecKeyRef)privateKey, (void *)&error);
            ok(attestationData, "failed to attest key '%@'", error);
        }

        NSDictionary *keyAttrs = (__bridge_transfer NSDictionary *)SecKeyCopyAttributes((SecKeyRef)privateKey);
        NSData *keyBlob = keyAttrs[(id)kSecAttrTokenOID];

        NSDictionary *params = @{ (id)kSecAttrTokenID : (id)kSecAttrTokenIDAppleKeyStore,
                                  (id)kSecAttrTokenOID : keyBlob,
                                  (id)kSecReturnRef : @YES };

        privateKey = nil;
        NSError *error;
        privateKey = (__bridge_transfer id)SecKeyCreateWithData((__bridge CFDataRef)keyBlob, (__bridge CFDictionaryRef)params, (void *)&error);
        ok(privateKey, "failed to create key with data '%@'", error);
//        <rdar://problem/30651629> SecItemAdd fails to create SecKey from aks key blob
//
//        ok_status(SecItemAdd((__bridge CFDictionaryRef)params, (void *)&privateKey), "failed to create key from aks blob");
//        ok_status(SecItemDelete((__bridge CFDictionaryRef) @{(id)kSecValueRef : privateKey}), "failed to delete key from aks blob");
    }
}

static void attestationTest(CFStringRef protection, BOOL noACL) {
    NSError *error;
    id privKey = generateKey((id)kSecAttrKeyTypeECSECPrimeRandom, protection, noACL);
    id uik = generateKey((id)kSecAttrKeyTypeSecureEnclaveAttestation, protection, noACL);
    id sik = CFBridgingRelease(SecKeyCopyAttestationKey(kSecKeyAttestationKeyTypeSIK, (void *)&error));
    ok(sik != nil, "get SIK key: %@", error);

    id pubSIK = CFBridgingRelease(SecKeyCopyPublicKey((__bridge SecKeyRef)sik));
    ok(pubSIK != nil, "get SIK pubkey");

    error = nil;
    NSData *attSIKPlain = CFBridgingRelease(SecKeyCreateAttestation((__bridge SecKeyRef)sik, (__bridge SecKeyRef)uik, (void *)&error));
    ok(attSIKPlain != nil, "SIK attesting UIK, no nonce: %@", error);

    error = nil;
    NSData *attUIKPlain = CFBridgingRelease(SecKeyCreateAttestation((__bridge SecKeyRef)uik, (__bridge SecKeyRef)privKey, (void *)&error));
    ok(attUIKPlain != nil, "UIK attesting privKey, no nonce: %@", error);

    error = nil;
    NSData *nonce = [@"TESTnonce" dataUsingEncoding:NSUTF8StringEncoding];
    ok(SecKeySetParameter((__bridge SecKeyRef)sik, kSecKeyParameterSETokenAttestationNonce, (__bridge CFPropertyListRef)nonce, (void *)&error), "Set nonce to SIK: %@", error);
    NSData *attSIKNonce = CFBridgingRelease(SecKeyCreateAttestation((__bridge SecKeyRef)sik, (__bridge SecKeyRef)uik, (void *)&error));
    ok(attSIKNonce != nil, "SIK attesting UIK, with nonce: %@", error);

    error = nil;
    ok(SecKeySetParameter((__bridge SecKeyRef)uik, kSecKeyParameterSETokenAttestationNonce, (__bridge CFPropertyListRef)nonce, (void *)&error), "Set nonce to UIK: %@", error);
    NSData *attUIKNonce = CFBridgingRelease(SecKeyCreateAttestation((__bridge SecKeyRef)uik, (__bridge SecKeyRef)privKey, (void *)&error));
    ok(attUIKNonce != nil, "SIK attesting UIK, with nonce: %@", error);

    error = nil;
    id sysUikC = CFBridgingRelease(SecKeyCopyAttestationKey(kSecKeyAttestationKeyTypeUIKCommitted, (void *)&error));
    if (sysUikC == nil) {
        // Platform does not support system UIK, so just fake test rounds to avoid testplan counting failures.
        for (int i = 0; i < 19; i++) {
            ok(true);
        }
    } else {
        ok(sysUikC != nil, "get UIK-committed key, error: %@", error);
        error = nil;
        id sysUikP = CFBridgingRelease(SecKeyCopyAttestationKey(kSecKeyAttestationKeyTypeUIKProposed, (void *)&error));
        ok(sysUikP != nil, "get UIK-proposed key: %@", error);

        error = nil;
        NSData *attUIKC = CFBridgingRelease(SecKeyCreateAttestation((__bridge SecKeyRef)sysUikC, (__bridge SecKeyRef)privKey, (void *)&error));
        ok(attUIKC != nil, "Sys-UIK-committed attesting privKey: %@", error);

        error = nil;
        NSData *attUIKP = CFBridgingRelease(SecKeyCreateAttestation((__bridge SecKeyRef)sysUikP, (__bridge SecKeyRef)privKey, (void *)&error));
        ok(attUIKP != nil, "Sys-UIK-proposed attesting privKey: %@", error);

        id pubUIKP = CFBridgingRelease(SecKeyCopyPublicKey((__bridge SecKeyRef)sysUikP));
        ok(pubUIKP != nil, "Sys-UIK-proposed copy public key");
        id pubUIKC = CFBridgingRelease(SecKeyCopyPublicKey((__bridge SecKeyRef)sysUikC));
        ok(pubUIKC != nil, "Sys-UIK-proposed copy public key");
        ok([pubUIKP isEqual:pubUIKC], "Sys-UIK proposed and committed are same before bump");

        BOOL res = SecKeyControlLifetime((__bridge SecKeyRef)sysUikC, kSecKeyControlLifetimeTypeBump, (void *)&error);
        ok(res, "bumping sys-uik: %@", error);

        error = nil;
        NSData *attUIKCN = CFBridgingRelease(SecKeyCreateAttestation((__bridge SecKeyRef)sysUikC, (__bridge SecKeyRef)privKey, (void *)&error));
        ok(attUIKCN != nil, "Sys-UIK-committed attesting privKey: %@", error);

        error = nil;
        NSData *attUIKPN = CFBridgingRelease(SecKeyCreateAttestation((__bridge SecKeyRef)sysUikP, (__bridge SecKeyRef)privKey, (void *)&error));
        ok(attUIKPN != nil, "Sys-UIK-proposed attesting privKey: %@", error);

        id pubUIKPN = CFBridgingRelease(SecKeyCopyPublicKey((__bridge SecKeyRef)sysUikP));
        ok(pubUIKPN != nil, "Sys-UIK-proposed copy public key");
        ok(![pubUIKPN isEqual:pubUIKC], "Sys-UIK proposed and committed differ after bump");

        res = SecKeyControlLifetime((__bridge SecKeyRef)sysUikP, kSecKeyControlLifetimeTypeCommit, (void *)&error);
        ok(res, "committing sys-uik: %@", error);

        error = nil;
        NSData *attUIKCNN = CFBridgingRelease(SecKeyCreateAttestation((__bridge SecKeyRef)sysUikC, (__bridge SecKeyRef)privKey, (void *)&error));
        ok(attUIKCNN != nil, "Sys-UIK-committed attesting privKey: %@", error);

        error = nil;
        NSData *attUIKPNN = CFBridgingRelease(SecKeyCreateAttestation((__bridge SecKeyRef)sysUikP, (__bridge SecKeyRef)privKey, (void *)&error));
        ok(attUIKPNN != nil, "Sys-UIK-proposed attesting privKey: %@", error);

        id pubUIKCN = CFBridgingRelease(SecKeyCopyPublicKey((__bridge SecKeyRef)sysUikC));
        ok(pubUIKCN != nil, "Sys-UIK-committed copy public key");
        ok([pubUIKPN isEqual:pubUIKC], "Sys-UIK proposed and committed same after commit");

        // Attest system-UIK with SIK
        NSData *attSIKUIKP = CFBridgingRelease(SecKeyCreateAttestation((__bridge SecKeyRef)sik, (__bridge SecKeyRef)sysUikP, (void *)&error));
        ok(attSIKUIKP != nil, "SIK attesting Sys-UIK-proposed, error: %@", error);

        NSData *attSIKUIKC = CFBridgingRelease(SecKeyCreateAttestation((__bridge SecKeyRef)sik, (__bridge SecKeyRef)sysUikC, (void *)&error));
        ok(attSIKUIKC != nil, "SIK attesting Sys-UIK-committed, error: %@", error);
    }
}

static const uint8_t satori_pub[] = {
    0x04, 0xe4, 0xef, 0x00, 0x27, 0xcb, 0xa6, 0x46, 0x0d, 0xa6, 0xbd, 0x77, 0x14, 0x65, 0xe5, 0x5a,
    0x14, 0xc9, 0xf8, 0xd8, 0xdd, 0x4c, 0x70, 0x44, 0x50, 0x49, 0xe4, 0xfa, 0x24, 0x71, 0xaa, 0x4c,
    0xe2, 0x74, 0x3b, 0xfd, 0x23, 0xda, 0x6f, 0x92, 0x04, 0x4c, 0x93, 0x6c, 0xea, 0x8a, 0xac, 0x22,
    0x99, 0xd9, 0x6e, 0x3f, 0xed, 0x20, 0xfd, 0xdd, 0x95, 0xe2, 0x32, 0xa0, 0xeb, 0x23, 0xa2, 0xd2,
    0x8b
};

static const uint8_t satori_priv[] = {
    0x04, 0xe4, 0xef, 0x00, 0x27, 0xcb, 0xa6, 0x46,
    0x0d, 0xa6, 0xbd, 0x77, 0x14, 0x65, 0xe5, 0x5a, 0x14, 0xc9, 0xf8, 0xd8, 0xdd, 0x4c, 0x70, 0x44,
    0x50, 0x49, 0xe4, 0xfa, 0x24, 0x71, 0xaa, 0x4c, 0xe2, 0x74, 0x3b, 0xfd, 0x23, 0xda, 0x6f, 0x92,
    0x04, 0x4c, 0x93, 0x6c, 0xea, 0x8a, 0xac, 0x22, 0x99, 0xd9, 0x6e, 0x3f, 0xed, 0x20, 0xfd, 0xdd,
    0x95, 0xe2, 0x32, 0xa0, 0xeb, 0x23, 0xa2, 0xd2, 0x8b, 0x23, 0xcf, 0x74, 0xb4, 0x76, 0x93, 0xdf,
    0x6d, 0x31, 0x63, 0xc9, 0x87, 0x85, 0x3f, 0x44, 0x09, 0x1f, 0x0d, 0xe2, 0x9a, 0x94, 0x29, 0x03,
    0x70, 0xbf, 0x87, 0x2a, 0x7e, 0xac, 0xa8, 0x8d, 0x11,
};

static const uint8_t satori_test_cert[] = {
    0x30, 0x82, 0x03, 0xf2, 0x30, 0x82, 0x03, 0x98, 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x08, 0x75,
    0x0e, 0x97, 0x07, 0xb3, 0x6e, 0x48, 0xe9, 0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d,
    0x04, 0x03, 0x02, 0x30, 0x7f, 0x31, 0x33, 0x30, 0x31, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x2a,
    0x54, 0x65, 0x73, 0x74, 0x20, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20, 0x41, 0x70, 0x70, 0x6c, 0x69,
    0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x49, 0x6e, 0x74, 0x65, 0x67, 0x72, 0x61, 0x74, 0x69,
    0x6f, 0x6e, 0x20, 0x43, 0x41, 0x20, 0x2d, 0x20, 0x47, 0x33, 0x31, 0x26, 0x30, 0x24, 0x06, 0x03,
    0x55, 0x04, 0x0b, 0x0c, 0x1d, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20, 0x43, 0x65, 0x72, 0x74, 0x69,
    0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x41, 0x75, 0x74, 0x68, 0x6f, 0x72, 0x69,
    0x74, 0x79, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x0a, 0x41, 0x70, 0x70,
    0x6c, 0x65, 0x20, 0x49, 0x6e, 0x63, 0x2e, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06,
    0x13, 0x02, 0x55, 0x53, 0x30, 0x1e, 0x17, 0x0d, 0x31, 0x38, 0x30, 0x39, 0x32, 0x37, 0x31, 0x38,
    0x33, 0x31, 0x30, 0x37, 0x5a, 0x17, 0x0d, 0x32, 0x30, 0x31, 0x30, 0x32, 0x36, 0x31, 0x38, 0x33,
    0x31, 0x30, 0x37, 0x5a, 0x30, 0x73, 0x31, 0x17, 0x30, 0x15, 0x06, 0x0a, 0x09, 0x92, 0x26, 0x89,
    0x93, 0xf2, 0x2c, 0x64, 0x01, 0x01, 0x0c, 0x07, 0x44, 0x65, 0x66, 0x61, 0x75, 0x6c, 0x74, 0x31,
    0x15, 0x30, 0x13, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x0c, 0x54, 0x65, 0x73, 0x74, 0x20, 0x53,
    0x50, 0x20, 0x4c, 0x65, 0x61, 0x66, 0x31, 0x22, 0x30, 0x20, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x0c,
    0x19, 0x31, 0x2e, 0x32, 0x2e, 0x38, 0x34, 0x30, 0x2e, 0x31, 0x31, 0x33, 0x36, 0x33, 0x35, 0x2e,
    0x31, 0x30, 0x30, 0x2e, 0x36, 0x2e, 0x36, 0x34, 0x2e, 0x33, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03,
    0x55, 0x04, 0x0a, 0x0c, 0x07, 0x54, 0x65, 0x73, 0x74, 0x20, 0x53, 0x50, 0x31, 0x0b, 0x30, 0x09,
    0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2a,
    0x86, 0x48, 0xce, 0x3d, 0x02, 0x01, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07,
    0x03, 0x42, 0x00, 0x04, 0xe4, 0xef, 0x00, 0x27, 0xcb, 0xa6, 0x46, 0x0d, 0xa6, 0xbd, 0x77, 0x14,
    0x65, 0xe5, 0x5a, 0x14, 0xc9, 0xf8, 0xd8, 0xdd, 0x4c, 0x70, 0x44, 0x50, 0x49, 0xe4, 0xfa, 0x24,
    0x71, 0xaa, 0x4c, 0xe2, 0x74, 0x3b, 0xfd, 0x23, 0xda, 0x6f, 0x92, 0x04, 0x4c, 0x93, 0x6c, 0xea,
    0x8a, 0xac, 0x22, 0x99, 0xd9, 0x6e, 0x3f, 0xed, 0x20, 0xfd, 0xdd, 0x95, 0xe2, 0x32, 0xa0, 0xeb,
    0x23, 0xa2, 0xd2, 0x8b, 0xa3, 0x82, 0x02, 0x08, 0x30, 0x82, 0x02, 0x04, 0x30, 0x0c, 0x06, 0x03,
    0x55, 0x1d, 0x13, 0x01, 0x01, 0xff, 0x04, 0x02, 0x30, 0x00, 0x30, 0x1f, 0x06, 0x03, 0x55, 0x1d,
    0x23, 0x04, 0x18, 0x30, 0x16, 0x80, 0x14, 0xb9, 0x04, 0x1a, 0x95, 0x5b, 0x6b, 0x91, 0x04, 0x39,
    0xea, 0x70, 0x2a, 0x47, 0xb7, 0xa8, 0x49, 0x36, 0xe4, 0x4d, 0xdb, 0x30, 0x4d, 0x06, 0x08, 0x2b,
    0x06, 0x01, 0x05, 0x05, 0x07, 0x01, 0x01, 0x04, 0x41, 0x30, 0x3f, 0x30, 0x3d, 0x06, 0x08, 0x2b,
    0x06, 0x01, 0x05, 0x05, 0x07, 0x30, 0x01, 0x86, 0x31, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f,
    0x6f, 0x63, 0x73, 0x70, 0x2d, 0x75, 0x61, 0x74, 0x2e, 0x63, 0x6f, 0x72, 0x70, 0x2e, 0x61, 0x70,
    0x70, 0x6c, 0x65, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x6f, 0x63, 0x73, 0x70, 0x30, 0x33, 0x2d, 0x74,
    0x73, 0x61, 0x61, 0x69, 0x63, 0x61, 0x67, 0x33, 0x31, 0x30, 0x30, 0x82, 0x01, 0x03, 0x06, 0x03,
    0x55, 0x1d, 0x20, 0x04, 0x81, 0xfb, 0x30, 0x81, 0xf8, 0x30, 0x81, 0xf5, 0x06, 0x09, 0x2a, 0x86,
    0x48, 0x86, 0xf7, 0x63, 0x64, 0x05, 0x01, 0x30, 0x81, 0xe7, 0x30, 0x81, 0xac, 0x06, 0x08, 0x2b,
    0x06, 0x01, 0x05, 0x05, 0x07, 0x02, 0x02, 0x30, 0x81, 0x9f, 0x0c, 0x81, 0x9c, 0x52, 0x65, 0x6c,
    0x69, 0x61, 0x6e, 0x63, 0x65, 0x20, 0x6f, 0x6e, 0x20, 0x74, 0x68, 0x69, 0x73, 0x20, 0x63, 0x65,
    0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x65, 0x20, 0x62, 0x79, 0x20, 0x61, 0x6e, 0x79,
    0x20, 0x70, 0x61, 0x72, 0x74, 0x79, 0x20, 0x69, 0x73, 0x20, 0x73, 0x75, 0x62, 0x6a, 0x65, 0x63,
    0x74, 0x20, 0x74, 0x6f, 0x20, 0x74, 0x68, 0x65, 0x20, 0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69,
    0x63, 0x61, 0x74, 0x65, 0x20, 0x50, 0x6f, 0x6c, 0x69, 0x63, 0x79, 0x2c, 0x20, 0x43, 0x65, 0x72,
    0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x50, 0x72, 0x61, 0x63, 0x74,
    0x69, 0x63, 0x65, 0x20, 0x53, 0x74, 0x61, 0x74, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x2c, 0x20, 0x61,
    0x6e, 0x64, 0x20, 0x74, 0x68, 0x65, 0x20, 0x74, 0x65, 0x72, 0x6d, 0x73, 0x20, 0x6f, 0x66, 0x20,
    0x61, 0x6e, 0x79, 0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x62, 0x6c, 0x65, 0x20, 0x61,
    0x67, 0x72, 0x65, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x2e, 0x30, 0x36, 0x06, 0x08, 0x2b, 0x06, 0x01,
    0x05, 0x05, 0x07, 0x02, 0x01, 0x16, 0x2a, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x77, 0x77,
    0x77, 0x2e, 0x61, 0x70, 0x70, 0x6c, 0x65, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x63, 0x65, 0x72, 0x74,
    0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x65, 0x61, 0x75, 0x74, 0x68, 0x6f, 0x72, 0x69, 0x74, 0x79,
    0x2f, 0x30, 0x3c, 0x06, 0x03, 0x55, 0x1d, 0x1f, 0x04, 0x35, 0x30, 0x33, 0x30, 0x31, 0xa0, 0x2f,
    0xa0, 0x2d, 0x86, 0x2b, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x63, 0x72, 0x6c, 0x2d, 0x75,
    0x61, 0x74, 0x2e, 0x63, 0x6f, 0x72, 0x70, 0x2e, 0x61, 0x70, 0x70, 0x6c, 0x65, 0x2e, 0x63, 0x6f,
    0x6d, 0x2f, 0x74, 0x73, 0x61, 0x61, 0x69, 0x63, 0x61, 0x67, 0x33, 0x2e, 0x63, 0x72, 0x6c, 0x30,
    0x1d, 0x06, 0x03, 0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0xa0, 0xe6, 0xdf, 0x03, 0xb1, 0x2a,
    0x53, 0x40, 0x35, 0xc4, 0x01, 0x4b, 0x6a, 0xbd, 0x35, 0x8f, 0x6d, 0x28, 0x63, 0xba, 0x30, 0x0e,
    0x06, 0x03, 0x55, 0x1d, 0x0f, 0x01, 0x01, 0xff, 0x04, 0x04, 0x03, 0x02, 0x03, 0x28, 0x30, 0x10,
    0x06, 0x0a, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x63, 0x64, 0x06, 0x40, 0x03, 0x04, 0x02, 0x05, 0x00,
    0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02, 0x03, 0x48, 0x00, 0x30,
    0x45, 0x02, 0x20, 0x6a, 0x7e, 0xf1, 0x0b, 0x60, 0xba, 0x4c, 0x3c, 0x83, 0xd5, 0xbd, 0x4a, 0xb1,
    0x62, 0x2f, 0x52, 0x92, 0xba, 0xb9, 0x64, 0xcd, 0xaa, 0x63, 0x96, 0xa6, 0xd8, 0x6d, 0x3a, 0xf3,
    0x83, 0x81, 0xb9, 0x02, 0x21, 0x00, 0xc2, 0x37, 0x2d, 0x3a, 0xb7, 0x03, 0x81, 0x2f, 0x3e, 0xf1,
    0x32, 0x98, 0x43, 0x27, 0xbb, 0x64, 0xbf, 0xfb, 0xb9, 0x9a, 0x0c, 0xad, 0x9a, 0x98, 0x6f, 0xbc,
    0x87, 0x30, 0xfe, 0xfe, 0x3c, 0x2e, 0x30, 0x82, 0x03, 0x17, 0x30, 0x82, 0x02, 0x9e, 0xa0, 0x03,
    0x02, 0x01, 0x02, 0x02, 0x08, 0x5b, 0x7d, 0xce, 0x90, 0x32, 0x77, 0x34, 0xd6, 0x30, 0x0a, 0x06,
    0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x03, 0x30, 0x6c, 0x31, 0x20, 0x30, 0x1e, 0x06,
    0x03, 0x55, 0x04, 0x03, 0x0c, 0x17, 0x54, 0x65, 0x73, 0x74, 0x20, 0x41, 0x70, 0x70, 0x6c, 0x65,
    0x20, 0x52, 0x6f, 0x6f, 0x74, 0x20, 0x43, 0x41, 0x20, 0x2d, 0x20, 0x47, 0x33, 0x31, 0x26, 0x30,
    0x24, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x0c, 0x1d, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20, 0x43, 0x65,
    0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x41, 0x75, 0x74, 0x68,
    0x6f, 0x72, 0x69, 0x74, 0x79, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x0a,
    0x41, 0x70, 0x70, 0x6c, 0x65, 0x20, 0x49, 0x6e, 0x63, 0x2e, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03,
    0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x30, 0x1e, 0x17, 0x0d, 0x31, 0x37, 0x30, 0x35, 0x33,
    0x30, 0x32, 0x31, 0x33, 0x35, 0x35, 0x35, 0x5a, 0x17, 0x0d, 0x33, 0x32, 0x30, 0x35, 0x32, 0x36,
    0x32, 0x31, 0x33, 0x35, 0x35, 0x35, 0x5a, 0x30, 0x7f, 0x31, 0x33, 0x30, 0x31, 0x06, 0x03, 0x55,
    0x04, 0x03, 0x0c, 0x2a, 0x54, 0x65, 0x73, 0x74, 0x20, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20, 0x41,
    0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x49, 0x6e, 0x74, 0x65, 0x67,
    0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x43, 0x41, 0x20, 0x2d, 0x20, 0x47, 0x33, 0x31, 0x26,
    0x30, 0x24, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x0c, 0x1d, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20, 0x43,
    0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x41, 0x75, 0x74,
    0x68, 0x6f, 0x72, 0x69, 0x74, 0x79, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c,
    0x0a, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20, 0x49, 0x6e, 0x63, 0x2e, 0x31, 0x0b, 0x30, 0x09, 0x06,
    0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2a, 0x86,
    0x48, 0xce, 0x3d, 0x02, 0x01, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07, 0x03,
    0x42, 0x00, 0x04, 0xfa, 0xdc, 0xcc, 0x11, 0x10, 0x74, 0x7b, 0x30, 0xc4, 0x69, 0xdd, 0x65, 0xc3,
    0xda, 0xa1, 0x55, 0xdf, 0xeb, 0x09, 0x5c, 0x29, 0xd0, 0x50, 0x3e, 0x1c, 0x0a, 0x34, 0xfa, 0x83,
    0xb1, 0x79, 0x49, 0x4d, 0x9d, 0xb3, 0xb9, 0x46, 0xa1, 0xc9, 0x43, 0x67, 0xb3, 0x03, 0x45, 0xd3,
    0xa4, 0x01, 0x60, 0xc3, 0x58, 0xdb, 0x98, 0x83, 0x19, 0x32, 0xce, 0xc5, 0xa3, 0x68, 0x38, 0xb6,
    0xca, 0x4d, 0x63, 0xa3, 0x82, 0x01, 0x15, 0x30, 0x82, 0x01, 0x11, 0x30, 0x53, 0x06, 0x08, 0x2b,
    0x06, 0x01, 0x05, 0x05, 0x07, 0x01, 0x01, 0x04, 0x47, 0x30, 0x45, 0x30, 0x43, 0x06, 0x08, 0x2b,
    0x06, 0x01, 0x05, 0x05, 0x07, 0x30, 0x01, 0x86, 0x37, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f,
    0x6f, 0x63, 0x73, 0x70, 0x2d, 0x75, 0x61, 0x74, 0x2e, 0x63, 0x6f, 0x72, 0x70, 0x2e, 0x61, 0x70,
    0x70, 0x6c, 0x65, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x6f, 0x63, 0x73, 0x70, 0x30, 0x34, 0x2d, 0x74,
    0x65, 0x73, 0x74, 0x61, 0x70, 0x70, 0x6c, 0x65, 0x72, 0x6f, 0x6f, 0x74, 0x63, 0x61, 0x67, 0x33,
    0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0xb9, 0x04, 0x1a, 0x95, 0x5b,
    0x6b, 0x91, 0x04, 0x39, 0xea, 0x70, 0x2a, 0x47, 0xb7, 0xa8, 0x49, 0x36, 0xe4, 0x4d, 0xdb, 0x30,
    0x12, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01, 0xff, 0x04, 0x08, 0x30, 0x06, 0x01, 0x01, 0xff,
    0x02, 0x01, 0x00, 0x30, 0x1f, 0x06, 0x03, 0x55, 0x1d, 0x23, 0x04, 0x18, 0x30, 0x16, 0x80, 0x14,
    0xfc, 0x46, 0xd8, 0x83, 0x6c, 0x1f, 0xe6, 0xf2, 0xdc, 0xdf, 0xa7, 0x99, 0x17, 0xae, 0x0b, 0x44,
    0x67, 0x17, 0x1b, 0x46, 0x30, 0x44, 0x06, 0x03, 0x55, 0x1d, 0x1f, 0x04, 0x3d, 0x30, 0x3b, 0x30,
    0x39, 0xa0, 0x37, 0xa0, 0x35, 0x86, 0x33, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x63, 0x72,
    0x6c, 0x2d, 0x75, 0x61, 0x74, 0x2e, 0x63, 0x6f, 0x72, 0x70, 0x2e, 0x61, 0x70, 0x70, 0x6c, 0x65,
    0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x74, 0x65, 0x73, 0x74, 0x61, 0x70, 0x70, 0x6c, 0x65, 0x72, 0x6f,
    0x6f, 0x74, 0x63, 0x61, 0x67, 0x33, 0x2e, 0x63, 0x72, 0x6c, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x1d,
    0x0f, 0x01, 0x01, 0xff, 0x04, 0x04, 0x03, 0x02, 0x01, 0x06, 0x30, 0x10, 0x06, 0x0a, 0x2a, 0x86,
    0x48, 0x86, 0xf7, 0x63, 0x64, 0x06, 0x02, 0x0e, 0x04, 0x02, 0x05, 0x00, 0x30, 0x0a, 0x06, 0x08,
    0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x03, 0x03, 0x67, 0x00, 0x30, 0x64, 0x02, 0x30, 0x6a,
    0x26, 0x0d, 0x2a, 0x80, 0xcd, 0x69, 0x33, 0xef, 0x50, 0xbb, 0x78, 0xbc, 0x17, 0x4c, 0xcd, 0xa6,
    0x6b, 0x86, 0xe2, 0x86, 0xd3, 0xe7, 0x3d, 0xc3, 0x8f, 0x01, 0xd8, 0x83, 0xe6, 0xc8, 0x1c, 0x7d,
    0xe7, 0x78, 0xca, 0xfd, 0x29, 0xd5, 0xfa, 0x32, 0x63, 0x98, 0xdb, 0x65, 0x17, 0x2e, 0x05, 0x02,
    0x30, 0x4d, 0xd7, 0x31, 0x32, 0xfa, 0x17, 0x73, 0x50, 0x9c, 0xb6, 0x04, 0x1d, 0xca, 0xa6, 0x1f,
    0x60, 0x0a, 0x72, 0x59, 0x6d, 0x7f, 0xc9, 0x5b, 0x93, 0x4a, 0x13, 0x40, 0x60, 0xae, 0x6c, 0x13,
    0x43, 0xd2, 0x71, 0xc2, 0xdd, 0x32, 0xaa, 0x90, 0xa9, 0xc5, 0xe2, 0xdd, 0x32, 0x23, 0x2f, 0xaa,
    0xda, 0x30, 0x82, 0x02, 0x4c, 0x30, 0x82, 0x01, 0xd3, 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x08,
    0x78, 0x36, 0x0b, 0xf4, 0xb7, 0xc8, 0xb6, 0xb0, 0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce,
    0x3d, 0x04, 0x03, 0x03, 0x30, 0x6c, 0x31, 0x20, 0x30, 0x1e, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c,
    0x17, 0x54, 0x65, 0x73, 0x74, 0x20, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20, 0x52, 0x6f, 0x6f, 0x74,
    0x20, 0x43, 0x41, 0x20, 0x2d, 0x20, 0x47, 0x33, 0x31, 0x26, 0x30, 0x24, 0x06, 0x03, 0x55, 0x04,
    0x0b, 0x0c, 0x1d, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20, 0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69,
    0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x41, 0x75, 0x74, 0x68, 0x6f, 0x72, 0x69, 0x74, 0x79,
    0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x0a, 0x41, 0x70, 0x70, 0x6c, 0x65,
    0x20, 0x49, 0x6e, 0x63, 0x2e, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
    0x55, 0x53, 0x30, 0x1e, 0x17, 0x0d, 0x31, 0x35, 0x30, 0x34, 0x32, 0x32, 0x30, 0x33, 0x31, 0x37,
    0x34, 0x34, 0x5a, 0x17, 0x0d, 0x34, 0x30, 0x31, 0x32, 0x32, 0x36, 0x30, 0x33, 0x31, 0x33, 0x33,
    0x37, 0x5a, 0x30, 0x6c, 0x31, 0x20, 0x30, 0x1e, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x17, 0x54,
    0x65, 0x73, 0x74, 0x20, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20, 0x52, 0x6f, 0x6f, 0x74, 0x20, 0x43,
    0x41, 0x20, 0x2d, 0x20, 0x47, 0x33, 0x31, 0x26, 0x30, 0x24, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x0c,
    0x1d, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20, 0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61,
    0x74, 0x69, 0x6f, 0x6e, 0x20, 0x41, 0x75, 0x74, 0x68, 0x6f, 0x72, 0x69, 0x74, 0x79, 0x31, 0x13,
    0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x0a, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20, 0x49,
    0x6e, 0x63, 0x2e, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53,
    0x30, 0x76, 0x30, 0x10, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x02, 0x01, 0x06, 0x05, 0x2b,
    0x81, 0x04, 0x00, 0x22, 0x03, 0x62, 0x00, 0x04, 0xa9, 0x1a, 0x63, 0x34, 0xef, 0xbc, 0xa6, 0x8a,
    0xd6, 0x2a, 0x6a, 0x38, 0x22, 0xe9, 0x25, 0xad, 0xda, 0x28, 0xa0, 0x49, 0xc5, 0x64, 0xfe, 0x5d,
    0x91, 0xc3, 0x6c, 0xf7, 0x99, 0xe4, 0xba, 0xe4, 0x2a, 0x5f, 0x61, 0xd2, 0xbf, 0x3b, 0x6c, 0xa8,
    0x61, 0x11, 0xb5, 0xe0, 0x66, 0xf7, 0x22, 0x11, 0x86, 0x97, 0x5d, 0xc3, 0xba, 0x1b, 0x6d, 0x55,
    0x7f, 0xd0, 0xf9, 0x80, 0xe0, 0xff, 0xd9, 0x05, 0xad, 0x5a, 0x5b, 0xbf, 0x3a, 0x7a, 0xa7, 0x09,
    0x52, 0x1a, 0x31, 0x7f, 0x0c, 0xa2, 0xe8, 0x10, 0xf5, 0x36, 0xd3, 0xc8, 0xea, 0xa0, 0x5b, 0x0a,
    0x28, 0x85, 0x30, 0x28, 0x5f, 0x94, 0xf6, 0x94, 0xa3, 0x42, 0x30, 0x40, 0x30, 0x1d, 0x06, 0x03,
    0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0xfc, 0x46, 0xd8, 0x83, 0x6c, 0x1f, 0xe6, 0xf2, 0xdc,
    0xdf, 0xa7, 0x99, 0x17, 0xae, 0x0b, 0x44, 0x67, 0x17, 0x1b, 0x46, 0x30, 0x0f, 0x06, 0x03, 0x55,
    0x1d, 0x13, 0x01, 0x01, 0xff, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01, 0xff, 0x30, 0x0e, 0x06, 0x03,
    0x55, 0x1d, 0x0f, 0x01, 0x01, 0xff, 0x04, 0x04, 0x03, 0x02, 0x01, 0x06, 0x30, 0x0a, 0x06, 0x08,
    0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x03, 0x03, 0x67, 0x00, 0x30, 0x64, 0x02, 0x30, 0x1a,
    0x14, 0x38, 0x24, 0xff, 0xb4, 0x08, 0xcb, 0xea, 0xc9, 0x3b, 0xda, 0xcc, 0x82, 0xf3, 0xd9, 0x0d,
    0xd1, 0x2b, 0x6e, 0xbf, 0x1f, 0xc4, 0x15, 0x14, 0x44, 0xdf, 0x98, 0x9b, 0xd7, 0xdd, 0xba, 0x1b,
    0xbe, 0x4f, 0x9f, 0x17, 0xa4, 0xd2, 0x02, 0x75, 0x90, 0x7d, 0x76, 0xcc, 0x93, 0x16, 0x2f, 0x02,
    0x30, 0x02, 0xd7, 0xda, 0x0b, 0xbe, 0xdd, 0x3d, 0xed, 0xf9, 0xa3, 0x06, 0x90, 0xa9, 0x58, 0xbd,
    0x6b, 0x7c, 0x7c, 0xe5, 0xc5, 0x4e, 0x0e, 0x44, 0xa2, 0x94, 0x2f, 0xb4, 0x04, 0x9a, 0xcd, 0x9b,
    0x69, 0x8d, 0x2a, 0xc6, 0x1d, 0x58, 0xff, 0xe3, 0x32, 0xb6, 0xdb, 0x3e, 0x34, 0xff, 0x67, 0x70,
    0xf1
};

static void rewrapTest(void) {
    id accessControl;
    accessControl = CFBridgingRelease(SecAccessControlCreate(kCFAllocatorDefault, NULL));
    SecAccessControlSetProtection((__bridge SecAccessControlRef)accessControl, kSecAttrAccessibleWhenUnlocked, NULL);
    SecAccessControlSetConstraints((__bridge SecAccessControlRef)accessControl, (__bridge CFDictionaryRef)@{(id)kAKSKeyOpECIESTranscode: @YES});

    NSDictionary *keyAttributes = @{ (id)kSecAttrTokenID : (id)kSecAttrTokenIDAppleKeyStore,
                                     (id)kSecAttrKeyType : (id)kSecAttrKeyTypeECSECPrimeRandom,
                                     (id)kSecKeyApplePayEnabled: @YES,
                                     (id)kSecAttrAccessControl : accessControl,
                                     (id)kSecAttrIsPermanent : @NO };
    NSError *error;
    id key = (__bridge_transfer id)SecKeyCreateRandomKey((CFDictionaryRef)keyAttributes, (void *)&error);
    ok(key, "failed to create random key %@", error);

    // Encrypt message with SEP key.
    NSData *message = [@"message" dataUsingEncoding:NSUTF8StringEncoding];
    id pubKey = CFBridgingRelease(SecKeyCopyPublicKey((SecKeyRef)key));
    NSData *encrypted = CFBridgingRelease(SecKeyCreateEncryptedDataWithParameters((__bridge SecKeyRef)pubKey, kSecKeyAlgorithmECIESEncryptionStandardVariableIVX963SHA256AESGCM, (__bridge CFDataRef)message, (__bridge CFDictionaryRef)@{(id)kSecKeyEncryptionParameterSymmetricKeySizeInBits: @256}, (void *)&error));
    ok(encrypted, "failed to encrypt with public key, %@", error);
    NSData *cert = [NSData dataWithBytes:satori_test_cert length:sizeof(satori_test_cert)];
    NSDictionary *recryptParams = @{
                                    (id)kSecKeyEncryptionParameterRecryptCertificate: cert,
                                    (id)kSecKeyEncryptionParameterSymmetricKeySizeInBits: @256,
                                    (id)kSecKeyEncryptionParameterRecryptParameters: @{
                                            (id)kSecKeyEncryptionParameterSymmetricKeySizeInBits: @256
                                            },
                                    };
    NSData *recrypted = CFBridgingRelease(SecKeyCreateDecryptedDataWithParameters((__bridge SecKeyRef)key, kSecKeyAlgorithmECIESEncryptionStandardVariableIVX963SHA256AESGCM, (__bridge CFDataRef)encrypted, (__bridge CFDictionaryRef)recryptParams, (void *)&error));
    ok(recrypted, "failed to recrypt, %@", error);

    id recryptKey = CFBridgingRelease(SecKeyCreateWithData((CFDataRef)[NSData dataWithBytes:satori_priv length:sizeof(satori_priv)], (CFDictionaryRef)@{(id)kSecAttrKeyType: (id)kSecAttrKeyTypeECSECPrimeRandom, (id)kSecAttrKeyClass: (id)kSecAttrKeyClassPrivate}, (void *)&error));
    NSData *decrypted = CFBridgingRelease(SecKeyCreateDecryptedDataWithParameters((__bridge SecKeyRef)recryptKey, kSecKeyAlgorithmECIESEncryptionStandardVariableIVX963SHA256AESGCM, (__bridge CFDataRef)recrypted, (__bridge CFDictionaryRef)@{(id)kSecKeyEncryptionParameterSymmetricKeySizeInBits: @256}, (void *)&error));
    ok(decrypted, "failed to decrypt, %@", error);
    ok([decrypted isEqualToData:message], "Decrypted data differs: %@ vs %@", decrypted, message);
}

int si_44_seckey_aks(int argc, char *const *argv) {
    @autoreleasepool {
        BOOL testPKA = YES;
#if !TARGET_OS_OSX
        NSNumber *hasPKA = (__bridge_transfer id)MGCopyAnswer(kMGQHasPKA, NULL);
        if(![hasPKA isKindOfClass:NSNumber.class] || ![hasPKA boolValue]) {
            testPKA = NO;
        }
#else
        if (remote_device_copy_unique_of_type(REMOTE_DEVICE_TYPE_EOS) == nil && remote_device_copy_unique_of_type(REMOTE_DEVICE_TYPE_BRIDGE_COPROC) == nil) {
            // macOS without SEP cannot run attestations at all.
            plan_tests(1);
            ok(true);
            return 0;
        }

        testPKA = NO;
#endif
        plan_tests(testPKA ? 100 : 85);

        // Put SEP keys into test-keybag mode. Available only when running in direct-mode, not with extension.
        SecKeySetParameter(NULL, kSecAttrTokenIDAppleKeyStore, kCFBooleanTrue, NULL);
        rewrapTest();
        SecKeySetParameter(NULL, kSecAttrTokenIDAppleKeyStore, kCFBooleanFalse, NULL);

        secKeySepTest(testPKA);
        attestationTest(kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly, NO);
        attestationTest(kSecAttrAccessibleUntilReboot, YES);
        return 0;
    }
}
