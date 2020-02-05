/*
 * Copyright (c) 2019 Apple Inc. All Rights Reserved.
 */

#ifndef _TRUSTTESTS_EVALUATION_PATH_PARSE_TESTS_H_
#define _TRUSTTESTS_EVALUATION_PATH_PARSE_TESTS_H_

/* subject:/C=US/ST=California/L=Cupertino/O=Apple Inc./OU=Security Engineering/CN=CoreTrust Test Leaf 1 */
/* issuer :/C=US/ST=California/L=Cupertino/O=Apple Inc./OU=Security Engineering/CN=CoreTrust Test CA */
const uint8_t _bad_extension_leaf[] = {
    0x30,0x82,0x02,0x85,0x30,0x82,0x02,0x2C,0xA0,0x03,0x02,0x01,0x02,0x02,0x15,0x00,
    0xD5,0xEC,0xDB,0x27,0x18,0xA7,0xEC,0x88,0x42,0xBA,0xC8,0xCD,0xE6,0xFC,0x34,0x9A,
    0x4D,0x36,0xD3,0x4C,0x30,0x09,0x06,0x07,0x2A,0x86,0x48,0xCE,0x3D,0x04,0x01,0x30,
    0x81,0x86,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,
    0x13,0x30,0x11,0x06,0x03,0x55,0x04,0x08,0x0C,0x0A,0x43,0x61,0x6C,0x69,0x66,0x6F,
    0x72,0x6E,0x69,0x61,0x31,0x12,0x30,0x10,0x06,0x03,0x55,0x04,0x07,0x0C,0x09,0x43,
    0x75,0x70,0x65,0x72,0x74,0x69,0x6E,0x6F,0x31,0x13,0x30,0x11,0x06,0x03,0x55,0x04,
    0x0A,0x0C,0x0A,0x41,0x70,0x70,0x6C,0x65,0x20,0x49,0x6E,0x63,0x2E,0x31,0x1D,0x30,
    0x1B,0x06,0x03,0x55,0x04,0x0B,0x0C,0x14,0x53,0x65,0x63,0x75,0x72,0x69,0x74,0x79,
    0x20,0x45,0x6E,0x67,0x69,0x6E,0x65,0x65,0x72,0x69,0x6E,0x67,0x31,0x1A,0x30,0x18,
    0x06,0x03,0x55,0x04,0x03,0x0C,0x11,0x43,0x6F,0x72,0x65,0x54,0x72,0x75,0x73,0x74,
    0x20,0x54,0x65,0x73,0x74,0x20,0x43,0x41,0x30,0x1E,0x17,0x0D,0x31,0x37,0x30,0x31,
    0x32,0x36,0x32,0x33,0x32,0x33,0x33,0x32,0x5A,0x17,0x0D,0x31,0x37,0x30,0x31,0x32,
    0x37,0x32,0x33,0x32,0x33,0x33,0x32,0x5A,0x30,0x81,0x8A,0x31,0x0B,0x30,0x09,0x06,
    0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x13,0x30,0x11,0x06,0x03,0x55,0x04,
    0x08,0x0C,0x0A,0x43,0x61,0x6C,0x69,0x66,0x6F,0x72,0x6E,0x69,0x61,0x31,0x12,0x30,
    0x10,0x06,0x03,0x55,0x04,0x07,0x0C,0x09,0x43,0x75,0x70,0x65,0x72,0x74,0x69,0x6E,
    0x6F,0x31,0x13,0x30,0x11,0x06,0x03,0x55,0x04,0x0A,0x0C,0x0A,0x41,0x70,0x70,0x6C,
    0x65,0x20,0x49,0x6E,0x63,0x2E,0x31,0x1D,0x30,0x1B,0x06,0x03,0x55,0x04,0x0B,0x0C,
    0x14,0x53,0x65,0x63,0x75,0x72,0x69,0x74,0x79,0x20,0x45,0x6E,0x67,0x69,0x6E,0x65,
    0x65,0x72,0x69,0x6E,0x67,0x31,0x1E,0x30,0x1C,0x06,0x03,0x55,0x04,0x03,0x0C,0x15,
    0x43,0x6F,0x72,0x65,0x54,0x72,0x75,0x73,0x74,0x20,0x54,0x65,0x73,0x74,0x20,0x4C,
    0x65,0x61,0x66,0x20,0x31,0x30,0x56,0x30,0x10,0x06,0x07,0x2A,0x86,0x48,0xCE,0x3D,
    0x02,0x01,0x06,0x05,0x2B,0x81,0x04,0x00,0x0A,0x03,0x42,0x00,0x04,0xFA,0x43,0x00,
    0x5E,0xEF,0xEF,0x33,0xBA,0x03,0x5F,0x7B,0x42,0xE2,0xCF,0x7D,0x2A,0x61,0x69,0xE2,
    0xEB,0x7A,0xE1,0x98,0x49,0x60,0x0D,0xD8,0xCB,0x99,0x09,0x91,0x4E,0x8B,0x12,0xA4,
    0x7F,0x19,0xAE,0xF4,0x62,0x8D,0x36,0x1A,0x34,0x9C,0x64,0xFE,0xE9,0xB2,0x02,0x3E,
    0xFD,0x83,0x9D,0x7E,0x40,0x7D,0x21,0x0E,0xD4,0xDA,0x97,0x12,0xE2,0xA3,0x75,0x30,
    0x73,0x30,0x0C,0x06,0x03,0x55,0x1D,0x13,0x01,0x01,0xFF,0x04,0x02,0x30,0x00,0x30,
    0x0E,0x06,0x03,0x55,0x1D,0x0F,0x01,0x01,0xFF,0x04,0x04,0x03,0x02,0x05,0xA0,0x30,
    0x13,0x06,0x03,0x55,0x1D,0x25,0x04,0x0C,0x31,0x0A,0x06,0x08,0x2B,0x06,0x01,0x05,
    0x05,0x07,0x03,0x02,0x30,0x1D,0x06,0x03,0x55,0x1D,0x0E,0x04,0x16,0x04,0x14,0xBB,
    0x3E,0xCE,0xF4,0xBA,0x9A,0xBC,0x9F,0x1E,0xF9,0x73,0xDB,0x11,0xEB,0x55,0x93,0xA3,
    0x59,0x5B,0x6C,0x30,0x1F,0x06,0x03,0x55,0x1D,0x23,0x04,0x18,0x30,0x16,0x80,0x14,
    0xEC,0xC0,0x39,0x7A,0xDF,0x66,0x7B,0x15,0xB1,0x13,0x9E,0x8D,0xD6,0xB2,0x77,0xA6,
    0xBA,0xEE,0x2A,0xA1,0x30,0x09,0x06,0x07,0x2A,0x86,0x48,0xCE,0x3D,0x04,0x01,0x03,
    0x48,0x00,0x30,0x45,0x02,0x20,0x2B,0x9C,0xC9,0xD3,0x86,0x66,0x7A,0xCD,0x58,0xFC,
    0x48,0x06,0xF6,0xC6,0xCC,0xE2,0x0F,0xA8,0xE4,0x66,0x16,0x2C,0xA8,0xCC,0x51,0xB6,
    0x1B,0x56,0xAC,0xBB,0x9F,0xD4,0x02,0x21,0x00,0xA2,0x51,0xAC,0x76,0xE6,0x3B,0x3B,
    0x0D,0x79,0xCD,0xB6,0x71,0x66,0x9E,0xEF,0x3C,0xB8,0x56,0xEA,0xBF,0x64,0x48,0x5B,
    0x0B,0x9B,0x38,0x06,0xBE,0xBA,0xE5,0xC9,0x17,
};


#endif /* _TRUSTTESTS_EVALUATION_PATH_PARSE_TESTS_H_ */
