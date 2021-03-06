// This file was automatically generated by protocompiler
// DO NOT EDIT!
// Compiled from OTPairingMessage.proto

#import "OTPairingMessage.h"
#import <ProtocolBuffer/PBConstants.h>
#import <ProtocolBuffer/PBHashUtil.h>
#import <ProtocolBuffer/PBDataReader.h>

#import "OTApplicantToSponsorRound2M1.h"
#import "OTSOSMessage.h"
#import "OTSponsorToApplicantRound1M2.h"
#import "OTSponsorToApplicantRound2M2.h"

#if !__has_feature(objc_arc)
# error This generated file depends on ARC but it is not enabled; turn on ARC, or use 'objc_use_arc' option to generate non-ARC code.
#endif

@implementation OTPairingMessage

- (BOOL)hasEpoch
{
    return _epoch != nil;
}
@synthesize epoch = _epoch;
- (BOOL)hasPrepare
{
    return _prepare != nil;
}
@synthesize prepare = _prepare;
- (BOOL)hasVoucher
{
    return _voucher != nil;
}
@synthesize voucher = _voucher;
- (BOOL)hasSosPairingMessage
{
    return _sosPairingMessage != nil;
}
@synthesize sosPairingMessage = _sosPairingMessage;

- (NSString *)description
{
    return [NSString stringWithFormat:@"%@ %@", [super description], [self dictionaryRepresentation]];
}

- (NSDictionary *)dictionaryRepresentation
{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    if (self->_epoch)
    {
        [dict setObject:[_epoch dictionaryRepresentation] forKey:@"epoch"];
    }
    if (self->_prepare)
    {
        [dict setObject:[_prepare dictionaryRepresentation] forKey:@"prepare"];
    }
    if (self->_voucher)
    {
        [dict setObject:[_voucher dictionaryRepresentation] forKey:@"voucher"];
    }
    if (self->_sosPairingMessage)
    {
        [dict setObject:[_sosPairingMessage dictionaryRepresentation] forKey:@"sosPairingMessage"];
    }
    return dict;
}

BOOL OTPairingMessageReadFrom(__unsafe_unretained OTPairingMessage *self, __unsafe_unretained PBDataReader *reader) {
    while (PBReaderHasMoreData(reader)) {
        uint32_t tag = 0;
        uint8_t aType = 0;

        PBReaderReadTag32AndType(reader, &tag, &aType);

        if (PBReaderHasError(reader))
            break;

        if (aType == TYPE_END_GROUP) {
            break;
        }

        switch (tag) {

            case 1 /* epoch */:
            {
                OTSponsorToApplicantRound1M2 *new_epoch = [[OTSponsorToApplicantRound1M2 alloc] init];
                self->_epoch = new_epoch;
                PBDataReaderMark mark_epoch;
                BOOL markError = !PBReaderPlaceMark(reader, &mark_epoch);
                if (markError)
                {
                    return NO;
                }
                BOOL inError = !OTSponsorToApplicantRound1M2ReadFrom(new_epoch, reader);
                if (inError)
                {
                    return NO;
                }
                PBReaderRecallMark(reader, &mark_epoch);
            }
            break;
            case 2 /* prepare */:
            {
                OTApplicantToSponsorRound2M1 *new_prepare = [[OTApplicantToSponsorRound2M1 alloc] init];
                self->_prepare = new_prepare;
                PBDataReaderMark mark_prepare;
                BOOL markError = !PBReaderPlaceMark(reader, &mark_prepare);
                if (markError)
                {
                    return NO;
                }
                BOOL inError = !OTApplicantToSponsorRound2M1ReadFrom(new_prepare, reader);
                if (inError)
                {
                    return NO;
                }
                PBReaderRecallMark(reader, &mark_prepare);
            }
            break;
            case 3 /* voucher */:
            {
                OTSponsorToApplicantRound2M2 *new_voucher = [[OTSponsorToApplicantRound2M2 alloc] init];
                self->_voucher = new_voucher;
                PBDataReaderMark mark_voucher;
                BOOL markError = !PBReaderPlaceMark(reader, &mark_voucher);
                if (markError)
                {
                    return NO;
                }
                BOOL inError = !OTSponsorToApplicantRound2M2ReadFrom(new_voucher, reader);
                if (inError)
                {
                    return NO;
                }
                PBReaderRecallMark(reader, &mark_voucher);
            }
            break;
            case 4 /* sosPairingMessage */:
            {
                OTSOSMessage *new_sosPairingMessage = [[OTSOSMessage alloc] init];
                self->_sosPairingMessage = new_sosPairingMessage;
                PBDataReaderMark mark_sosPairingMessage;
                BOOL markError = !PBReaderPlaceMark(reader, &mark_sosPairingMessage);
                if (markError)
                {
                    return NO;
                }
                BOOL inError = !OTSOSMessageReadFrom(new_sosPairingMessage, reader);
                if (inError)
                {
                    return NO;
                }
                PBReaderRecallMark(reader, &mark_sosPairingMessage);
            }
            break;
            default:
                if (!PBReaderSkipValueWithTag(reader, tag, aType))
                    return NO;
                break;
        }
    }
    return !PBReaderHasError(reader);
}

- (BOOL)readFrom:(PBDataReader *)reader
{
    return OTPairingMessageReadFrom(self, reader);
}
- (void)writeTo:(PBDataWriter *)writer
{
    /* epoch */
    {
        if (self->_epoch != nil)
        {
            PBDataWriterWriteSubmessage(writer, self->_epoch, 1);
        }
    }
    /* prepare */
    {
        if (self->_prepare != nil)
        {
            PBDataWriterWriteSubmessage(writer, self->_prepare, 2);
        }
    }
    /* voucher */
    {
        if (self->_voucher != nil)
        {
            PBDataWriterWriteSubmessage(writer, self->_voucher, 3);
        }
    }
    /* sosPairingMessage */
    {
        if (self->_sosPairingMessage != nil)
        {
            PBDataWriterWriteSubmessage(writer, self->_sosPairingMessage, 4);
        }
    }
}

- (void)copyTo:(OTPairingMessage *)other
{
    if (_epoch)
    {
        other.epoch = _epoch;
    }
    if (_prepare)
    {
        other.prepare = _prepare;
    }
    if (_voucher)
    {
        other.voucher = _voucher;
    }
    if (_sosPairingMessage)
    {
        other.sosPairingMessage = _sosPairingMessage;
    }
}

- (id)copyWithZone:(NSZone *)zone
{
    OTPairingMessage *copy = [[[self class] allocWithZone:zone] init];
    copy->_epoch = [_epoch copyWithZone:zone];
    copy->_prepare = [_prepare copyWithZone:zone];
    copy->_voucher = [_voucher copyWithZone:zone];
    copy->_sosPairingMessage = [_sosPairingMessage copyWithZone:zone];
    return copy;
}

- (BOOL)isEqual:(id)object
{
    OTPairingMessage *other = (OTPairingMessage *)object;
    return [other isMemberOfClass:[self class]]
    &&
    ((!self->_epoch && !other->_epoch) || [self->_epoch isEqual:other->_epoch])
    &&
    ((!self->_prepare && !other->_prepare) || [self->_prepare isEqual:other->_prepare])
    &&
    ((!self->_voucher && !other->_voucher) || [self->_voucher isEqual:other->_voucher])
    &&
    ((!self->_sosPairingMessage && !other->_sosPairingMessage) || [self->_sosPairingMessage isEqual:other->_sosPairingMessage])
    ;
}

- (NSUInteger)hash
{
    return 0
    ^
    [self->_epoch hash]
    ^
    [self->_prepare hash]
    ^
    [self->_voucher hash]
    ^
    [self->_sosPairingMessage hash]
    ;
}

- (void)mergeFrom:(OTPairingMessage *)other
{
    if (self->_epoch && other->_epoch)
    {
        [self->_epoch mergeFrom:other->_epoch];
    }
    else if (!self->_epoch && other->_epoch)
    {
        [self setEpoch:other->_epoch];
    }
    if (self->_prepare && other->_prepare)
    {
        [self->_prepare mergeFrom:other->_prepare];
    }
    else if (!self->_prepare && other->_prepare)
    {
        [self setPrepare:other->_prepare];
    }
    if (self->_voucher && other->_voucher)
    {
        [self->_voucher mergeFrom:other->_voucher];
    }
    else if (!self->_voucher && other->_voucher)
    {
        [self setVoucher:other->_voucher];
    }
    if (self->_sosPairingMessage && other->_sosPairingMessage)
    {
        [self->_sosPairingMessage mergeFrom:other->_sosPairingMessage];
    }
    else if (!self->_sosPairingMessage && other->_sosPairingMessage)
    {
        [self setSosPairingMessage:other->_sosPairingMessage];
    }
}

@end

