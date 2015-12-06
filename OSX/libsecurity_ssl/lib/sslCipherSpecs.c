/*
 * Copyright (c) 1999-2001,2005-2014 Apple Inc. All Rights Reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

/*
 * cipherSpecs.c - SSLCipherSpec declarations
 */

#include "sslBuildFlags.h"
#include "sslContext.h"
#include "sslCipherSpecs.h"
#include "sslDebug.h"
#include "sslMemory.h"
#include "sslDebug.h"
#include "sslUtils.h"
#include "sslPriv.h"

#include <tls_handshake.h>

#include <string.h>
#include <assert.h>
#include <Security/SecBase.h>

#include <TargetConditionals.h>


/* SecureTransport needs it's own copy of KnownCipherSuites for now, there is a copy in coreTLS,
   that is exported, but it actually should only included the "default" not the supported */

#define ENABLE_ECDH      		1
#define ENABLE_AES_GCM          1
#define ENABLE_PSK              1

static const uint16_t STKnownCipherSuites[] = {
#if ENABLE_AES_GCM
    TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384,
    TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256,
#endif
    TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384,
    TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256,
    TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA,
    TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA,
    TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA,
#if ENABLE_AES_GCM
    TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384,
    TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256,
#endif
    TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384,
    TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256,
    TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA,
    TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA,
    TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA,
#if ENABLE_ECDH
#if ENABLE_AES_GCM
    TLS_ECDH_ECDSA_WITH_AES_256_GCM_SHA384,
    TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256,
#endif
    TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA384,
    TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256,
    TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA,
    TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA,
    TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA,
#if ENABLE_AES_GCM
    TLS_ECDH_RSA_WITH_AES_256_GCM_SHA384,
    TLS_ECDH_RSA_WITH_AES_128_GCM_SHA256,
#endif
    TLS_ECDH_RSA_WITH_AES_256_CBC_SHA384,
    TLS_ECDH_RSA_WITH_AES_128_CBC_SHA256,
    TLS_ECDH_RSA_WITH_AES_256_CBC_SHA,
    TLS_ECDH_RSA_WITH_AES_128_CBC_SHA,
    TLS_ECDH_RSA_WITH_3DES_EDE_CBC_SHA,
#endif

#if ENABLE_AES_GCM
    TLS_DHE_RSA_WITH_AES_256_GCM_SHA384,
    TLS_DHE_RSA_WITH_AES_128_GCM_SHA256,
#endif // ENABLE_AES_GCM
    TLS_DHE_RSA_WITH_AES_256_CBC_SHA256,
    TLS_DHE_RSA_WITH_AES_128_CBC_SHA256,
    TLS_DHE_RSA_WITH_AES_256_CBC_SHA,
    TLS_DHE_RSA_WITH_AES_128_CBC_SHA,
    SSL_DHE_RSA_WITH_3DES_EDE_CBC_SHA,

#if ENABLE_AES_GCM
    TLS_RSA_WITH_AES_256_GCM_SHA384,
    TLS_RSA_WITH_AES_128_GCM_SHA256,
#endif
    TLS_RSA_WITH_AES_256_CBC_SHA256,
    TLS_RSA_WITH_AES_128_CBC_SHA256,
    TLS_RSA_WITH_AES_256_CBC_SHA,
    TLS_RSA_WITH_AES_128_CBC_SHA,
    SSL_RSA_WITH_3DES_EDE_CBC_SHA,

#if ENABLE_RC4
    TLS_ECDHE_ECDSA_WITH_RC4_128_SHA,
    TLS_ECDHE_RSA_WITH_RC4_128_SHA,
    TLS_ECDH_ECDSA_WITH_RC4_128_SHA,
    TLS_ECDH_RSA_WITH_RC4_128_SHA,
    SSL_RSA_WITH_RC4_128_SHA,
    SSL_RSA_WITH_RC4_128_MD5,
#endif


    /* Unsafe ciphersuites */

#if ENABLE_AES_GCM
    TLS_DH_anon_WITH_AES_256_GCM_SHA384,
    TLS_DH_anon_WITH_AES_128_GCM_SHA256,
#endif
    TLS_DH_anon_WITH_AES_128_CBC_SHA256,
    TLS_DH_anon_WITH_AES_256_CBC_SHA256,
    TLS_DH_anon_WITH_AES_128_CBC_SHA,
    TLS_DH_anon_WITH_AES_256_CBC_SHA,
    SSL_DH_anon_WITH_RC4_128_MD5,
    SSL_DH_anon_WITH_3DES_EDE_CBC_SHA,

    TLS_ECDHE_ECDSA_WITH_NULL_SHA,
    TLS_ECDHE_RSA_WITH_NULL_SHA,
#if ENABLE_ECDH
    TLS_ECDH_ECDSA_WITH_NULL_SHA,
    TLS_ECDH_RSA_WITH_NULL_SHA,
#endif

#if ENABLE_PSK
    TLS_PSK_WITH_AES_256_CBC_SHA384,
    TLS_PSK_WITH_AES_128_CBC_SHA256,
    TLS_PSK_WITH_AES_256_CBC_SHA,
    TLS_PSK_WITH_AES_128_CBC_SHA,
    TLS_PSK_WITH_RC4_128_SHA,
    TLS_PSK_WITH_3DES_EDE_CBC_SHA,
    TLS_PSK_WITH_NULL_SHA384,
    TLS_PSK_WITH_NULL_SHA256,
    TLS_PSK_WITH_NULL_SHA,
#endif

    TLS_RSA_WITH_NULL_SHA256,
    SSL_RSA_WITH_NULL_SHA,
    SSL_RSA_WITH_NULL_MD5

};

static const unsigned STCipherSuiteCount = sizeof(STKnownCipherSuites)/sizeof(STKnownCipherSuites[0]);

/*
 * Build ctx->validCipherSpecs as a copy of KnownCipherSpecs, assuming that
 * validCipherSpecs is currently not valid (i.e., SSLSetEnabledCiphers() has
 * not been called).
 */
OSStatus sslBuildCipherSuiteArray(SSLContext *ctx)
{
	size_t          size;
	unsigned        dex;

	assert(ctx != NULL);
	assert(ctx->validCipherSuites == NULL);

	ctx->numValidCipherSuites = STCipherSuiteCount;
	size = STCipherSuiteCount * sizeof(uint16_t);
	ctx->validCipherSuites = (uint16_t *)sslMalloc(size);
	if(ctx->validCipherSuites == NULL) {
		ctx->numValidCipherSuites = 0;
		return errSecAllocate;
	}

	/*
	 * Trim out inappropriate ciphers:
	 *  -- trim anonymous ciphers if !ctx->anonCipherEnable
	 *  -- trim ECDSA ciphers for server side if appropriate
	 *  -- trim ECDSA ciphers if TLSv1 disable or SSLv2 enabled (since
	 *     we MUST do the Client Hello extensions to make these ciphers
	 *     work reliably)
     *  -- trim Stream ciphers if DTLSv1 enable
     *  -- trim CBC ciphers when doing SSLv3 fallback
	 */
	uint16_t *dst = ctx->validCipherSuites;
	const uint16_t *src = STKnownCipherSuites;

    bool trimDHE = !ctx->dheEnabled;
    bool trimECDHE = false;
    const bool trimECDH = true;

    if(ctx->maxProtocolVersion == SSL_Version_3_0) {
        /* We trim ECDSA cipher suites if SSL2 is enabled or
         The maximum allowed protocol is SSL3.  Note that this
         won't trim ECDSA cipherspecs for DTLS which should be
         the right thing to do here. */
		trimECDHE = true;
	}

    /* trim Stream Ciphers for DTLS */
    bool trimRC4 = ctx->isDTLS;

    /* trim CBC cipher when doing SSLv3 only fallback */
    bool trimCBC = (ctx->protocolSide==kSSLClientSide)
                    && (ctx->maxProtocolVersion == SSL_Version_3_0)
                    && ctx->fallbackEnabled;

	for(dex=0; dex<STCipherSuiteCount; dex++) {
        KeyExchangeMethod kem = sslCipherSuiteGetKeyExchangeMethod(*src);
        uint8_t keySize = sslCipherSuiteGetSymmetricCipherKeySize(*src);
        HMAC_Algs mac = sslCipherSuiteGetMacAlgorithm(*src);
        SSL_CipherAlgorithm cipher = sslCipherSuiteGetSymmetricCipherAlgorithm(*src);
		/* Skip ciphers as appropriate */
        switch(kem) {
            case SSL_ECDHE_ECDSA:
            case SSL_ECDHE_RSA:
                if(trimECDHE) {
                    /* Skip this one */
                    ctx->numValidCipherSuites--;
                    src++;
                    continue;
                }
                else {
                    break;
                }
            case SSL_ECDH_ECDSA:
            case SSL_ECDH_RSA:
            case SSL_ECDH_anon:
                if(trimECDH) {
                    /* Skip this one */
                    ctx->numValidCipherSuites--;
                    src++;
                    continue;
				}
                else {
                    break;
                }
            case SSL_DHE_RSA:
                if(trimDHE) {
                    /* Skip this one */
                    ctx->numValidCipherSuites--;
                    src++;
                    continue;
                }
            default:
                break;
        }
		if(!ctx->anonCipherEnable) {
			/* trim out the anonymous (and null-auth-cipher) ciphers */
			if(mac == HA_Null) {
                /* skip this one */
				ctx->numValidCipherSuites--;
				src++;
				continue;
			}
			switch(kem) {
				case SSL_DH_anon:
				case SSL_DH_anon_EXPORT:
				case SSL_ECDH_anon:
					/* skip this one */
					ctx->numValidCipherSuites--;
					src++;
					continue;
				default:
					break;
			}
		}

        /* This will skip the simple DES cipher suites, but not the NULL cipher ones */
        if (keySize == 8)
        {
            /* skip this one */
            ctx->numValidCipherSuites--;
            src++;
            continue;
        }

        /* Trim PSK ciphersuites, they need to be enabled explicitely */
        if (kem==TLS_PSK) {
            ctx->numValidCipherSuites--;
            src++;
            continue;
        }

        if (trimRC4 && (cipher==SSL_CipherAlgorithmRC4_128)) {
            ctx->numValidCipherSuites--;
            src++;
            continue;
        }

        if(trimCBC) {
            switch (cipher) {
                case SSL_CipherAlgorithmAES_128_CBC:
                case SSL_CipherAlgorithmAES_256_CBC:
                case SSL_CipherAlgorithm3DES_CBC:
                    ctx->numValidCipherSuites--;
                    src++;
                    continue;
                default:
                    break;
            }
        }

        if(cipher==SSL_CipherAlgorithmNull) {
            ctx->numValidCipherSuites--;
            src++;
            continue;
        }

        /* This one is good to go */
        *dst++ = *src++;
	}

    tls_handshake_set_ciphersuites(ctx->hdsk, ctx->validCipherSuites, ctx->numValidCipherSuites);

	return errSecSuccess;
}


/*
 * Convert an array of uint16_t
 * to an array of SSLCipherSuites.
 */
static OSStatus
cipherSuitesToCipherSuites(
                          size_t				numCipherSuites,
                          const uint16_t        *cipherSuites,
                          SSLCipherSuite		*ciphers,		/* RETURNED */
                          size_t				*numCiphers)	/* IN/OUT */
{
    size_t i;
	if(*numCiphers < numCipherSuites) {
		return errSSLBufferOverflow;
	}

    /* NOTE: this is required to go from uint16_t to SSLCipherSuite 
       which is either 32 or 16 bits, depending on the platform */
    for(i=0;i<numCipherSuites; i++) {
        ciphers[i]=cipherSuites[i];
    }
	*numCiphers = numCipherSuites;
	return errSecSuccess;
}

/***
 *** Publically exported functions declared in SecureTransport.h
 ***/

/*
 * Determine number and values of all of the SSLCipherSuites we support.
 * Caller allocates output buffer for SSLGetSupportedCiphers() and passes in
 * its size in *numCiphers. If supplied buffer is too small, errSSLBufferOverflow
 * will be returned.
 */
OSStatus
SSLGetNumberSupportedCiphers (SSLContextRef	ctx,
							  size_t		*numCiphers)
{
	if((ctx == NULL) || (numCiphers == NULL)) {
		return errSecParam;
	}
	*numCiphers = STCipherSuiteCount;
	return errSecSuccess;
}

OSStatus
SSLGetSupportedCiphers		 (SSLContextRef		ctx,
							  SSLCipherSuite	*ciphers,		/* RETURNED */
							  size_t			*numCiphers)	/* IN/OUT */
{
	if((ctx == NULL) || (ciphers == NULL) || (numCiphers == NULL)) {
		return errSecParam;
	}
	return cipherSuitesToCipherSuites(STCipherSuiteCount,
		STKnownCipherSuites,
		ciphers,
		numCiphers);
}

/*
 * Specify a (typically) restricted set of SSLCipherSuites to be enabled by
 * the current SSLContext. Can only be called when no session is active. Default
 * set of enabled SSLCipherSuites is NOT the same as the complete set of supported
 * SSLCipherSuites as obtained by SSLGetSupportedCiphers().
 */
OSStatus
SSLSetEnabledCiphers		(SSLContextRef			ctx,
							 const SSLCipherSuite	*ciphers,
							 size_t					numCiphers)
{
	size_t size;
    unsigned foundCiphers=0;
	unsigned callerDex;
	unsigned tableDex;

	if((ctx == NULL) || (ciphers == NULL) || (numCiphers == 0)) {
		return errSecParam;
	}
	if(sslIsSessionActive(ctx)) {
		/* can't do this with an active session */
		return errSecBadReq;
	}
	size = numCiphers * sizeof(uint16_t);
	ctx->validCipherSuites = (uint16_t *)sslMalloc(size);
	if(ctx->validCipherSuites == NULL) {
		ctx->numValidCipherSuites = 0;
		return errSecAllocate;
	}

	/*
	 * Run thru caller's specs, keep only the supported ones.
	 */
    for(callerDex=0; callerDex<numCiphers; callerDex++) {
        /* find matching CipherSpec in our known table */
        for(tableDex=0; tableDex<STCipherSuiteCount; tableDex++) {
            if(ciphers[callerDex] == STKnownCipherSuites[tableDex]) {
                ctx->validCipherSuites[foundCiphers] = STKnownCipherSuites[tableDex];
                foundCiphers++;
                break;
            }
        }
	}

    if(foundCiphers==0) {
        /* caller specified only unsupported ciphersuites */
        sslFree(ctx->validCipherSuites);
        ctx->validCipherSuites = NULL;
        return errSSLBadCipherSuite;
    }
    
	/* success */
	ctx->numValidCipherSuites = foundCiphers;

    tls_handshake_set_ciphersuites(ctx->hdsk, ctx->validCipherSuites, ctx->numValidCipherSuites);

    return errSecSuccess;
}

/*
 * Determine number and values of all of the SSLCipherSuites currently enabled.
 * Caller allocates output buffer for SSLGetEnabledCiphers() and passes in
 * its size in *numCiphers. If supplied buffer is too small, errSSLBufferOverflow
 * will be returned.
 */
OSStatus
SSLGetNumberEnabledCiphers 	(SSLContextRef			ctx,
							 size_t					*numCiphers)
{
	if((ctx == NULL) || (numCiphers == NULL)) {
		return errSecParam;
	}

    unsigned n;
    const uint16_t *ciphersuites;
    int err;

    err = tls_handshake_get_ciphersuites(ctx->hdsk, &ciphersuites, &n);

    if(err) {
        return err;
    } else {
        *numCiphers = n;
        return errSecSuccess;
    }
}

OSStatus
SSLGetEnabledCiphers		(SSLContextRef			ctx,
							 SSLCipherSuite			*ciphers,		/* RETURNED */
							 size_t					*numCiphers)	/* IN/OUT */
{
	if((ctx == NULL) || (ciphers == NULL) || (numCiphers == NULL)) {
		return errSecParam;
	}

    unsigned n;
    const uint16_t *ciphersuites;
    int err;

    err = tls_handshake_get_ciphersuites(ctx->hdsk, &ciphersuites, &n);

    return cipherSuitesToCipherSuites(n,
                                      ciphersuites,
                                      ciphers,
                                      numCiphers);

}
