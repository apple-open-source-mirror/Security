// This file was automatically generated by protocompiler
// DO NOT EDIT!
// Compiled from stdin

#import <TargetConditionals.h>
#if !TARGET_OS_BRIDGE

#import "AWDKeychainCKKSRateLimiterTopWriters.h"
#import <ProtocolBuffer/PBConstants.h>
#import <ProtocolBuffer/PBHashUtil.h>
#import <ProtocolBuffer/PBDataReader.h>

#if !__has_feature(objc_arc)
# error This generated file depends on ARC but it is not enabled; turn on ARC, or use 'objc_use_arc' option to generate non-ARC code.
#endif

@implementation AWDKeychainCKKSRateLimiterTopWriters

@synthesize timestamp = _timestamp;
- (void)setTimestamp:(uint64_t)v
{
    _has.timestamp = YES;
    _timestamp = v;
}
- (void)setHasTimestamp:(BOOL)f
{
    _has.timestamp = f;
}
- (BOOL)hasTimestamp
{
    return _has.timestamp;
}
@synthesize writers = _writers;
- (void)clearWriters
{
    [_writers removeAllObjects];
}
- (void)addWriter:(NSString *)i
{
    if (!_writers)
    {
        _writers = [[NSMutableArray alloc] init];
    }
    [_writers addObject:i];
}
- (NSUInteger)writersCount
{
    return [_writers count];
}
- (NSString *)writerAtIndex:(NSUInteger)idx
{
    return [_writers objectAtIndex:idx];
}
+ (Class)writerType
{
    return [NSString class];
}
- (BOOL)hasRatelimitertype
{
    return _ratelimitertype != nil;
}
@synthesize ratelimitertype = _ratelimitertype;

- (NSString *)description
{
    return [NSString stringWithFormat:@"%@ %@", [super description], [self dictionaryRepresentation]];
}

- (NSDictionary *)dictionaryRepresentation
{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    if (self->_has.timestamp)
    {
        [dict setObject:[NSNumber numberWithUnsignedLongLong:self->_timestamp] forKey:@"timestamp"];
    }
    if (self->_writers)
    {
        [dict setObject:self->_writers forKey:@"writer"];
    }
    if (self->_ratelimitertype)
    {
        [dict setObject:self->_ratelimitertype forKey:@"ratelimitertype"];
    }
    return dict;
}

BOOL AWDKeychainCKKSRateLimiterTopWritersReadFrom(__unsafe_unretained AWDKeychainCKKSRateLimiterTopWriters *self, __unsafe_unretained PBDataReader *reader) {
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

            case 1 /* timestamp */:
            {
                self->_has.timestamp = YES;
                self->_timestamp = PBReaderReadUint64(reader);
            }
            break;
            case 2 /* writers */:
            {
                NSString *new_writers = PBReaderReadString(reader);
                if (new_writers)
                {
                    [self addWriter:new_writers];
                }
            }
            break;
            case 3 /* ratelimitertype */:
            {
                NSString *new_ratelimitertype = PBReaderReadString(reader);
                self->_ratelimitertype = new_ratelimitertype;
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
    return AWDKeychainCKKSRateLimiterTopWritersReadFrom(self, reader);
}
- (void)writeTo:(PBDataWriter *)writer
{
    /* timestamp */
    {
        if (self->_has.timestamp)
        {
            PBDataWriterWriteUint64Field(writer, self->_timestamp, 1);
        }
    }
    /* writers */
    {
        for (NSString *s_writers in self->_writers)
        {
            PBDataWriterWriteStringField(writer, s_writers, 2);
        }
    }
    /* ratelimitertype */
    {
        if (self->_ratelimitertype)
        {
            PBDataWriterWriteStringField(writer, self->_ratelimitertype, 3);
        }
    }
}

- (void)copyTo:(AWDKeychainCKKSRateLimiterTopWriters *)other
{
    if (self->_has.timestamp)
    {
        other->_timestamp = _timestamp;
        other->_has.timestamp = YES;
    }
    if ([self writersCount])
    {
        [other clearWriters];
        NSUInteger writersCnt = [self writersCount];
        for (NSUInteger i = 0; i < writersCnt; i++)
        {
            [other addWriter:[self writerAtIndex:i]];
        }
    }
    if (_ratelimitertype)
    {
        other.ratelimitertype = _ratelimitertype;
    }
}

- (id)copyWithZone:(NSZone *)zone
{
    AWDKeychainCKKSRateLimiterTopWriters *copy = [[[self class] allocWithZone:zone] init];
    if (self->_has.timestamp)
    {
        copy->_timestamp = _timestamp;
        copy->_has.timestamp = YES;
    }
    for (NSString *v in _writers)
    {
        NSString *vCopy = [v copyWithZone:zone];
        [copy addWriter:vCopy];
    }
    copy->_ratelimitertype = [_ratelimitertype copyWithZone:zone];
    return copy;
}

- (BOOL)isEqual:(id)object
{
    AWDKeychainCKKSRateLimiterTopWriters *other = (AWDKeychainCKKSRateLimiterTopWriters *)object;
    return [other isMemberOfClass:[self class]]
    &&
    ((self->_has.timestamp && other->_has.timestamp && self->_timestamp == other->_timestamp) || (!self->_has.timestamp && !other->_has.timestamp))
    &&
    ((!self->_writers && !other->_writers) || [self->_writers isEqual:other->_writers])
    &&
    ((!self->_ratelimitertype && !other->_ratelimitertype) || [self->_ratelimitertype isEqual:other->_ratelimitertype])
    ;
}

- (NSUInteger)hash
{
    return 0
    ^
    (self->_has.timestamp ? PBHashInt((NSUInteger)self->_timestamp) : 0)
    ^
    [self->_writers hash]
    ^
    [self->_ratelimitertype hash]
    ;
}

- (void)mergeFrom:(AWDKeychainCKKSRateLimiterTopWriters *)other
{
    if (other->_has.timestamp)
    {
        self->_timestamp = other->_timestamp;
        self->_has.timestamp = YES;
    }
    for (NSString *iter_writers in other->_writers)
    {
        [self addWriter:iter_writers];
    }
    if (other->_ratelimitertype)
    {
        [self setRatelimitertype:other->_ratelimitertype];
    }
}

@end
#endif