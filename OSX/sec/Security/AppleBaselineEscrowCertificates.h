/*
 * Copyright (c) 2013-2015 Apple Inc. All Rights Reserved.
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


#ifndef sec_AppleBaselineEscrowCertificates_h
#define sec_AppleBaselineEscrowCertificates_h

struct RootRecord
{
	size_t	_length;
	UInt8*	_bytes;
};

/* ==========================================================================
    Production Escrow Certificates
   ========================================================================== */


static const UInt8 kBaseLineEscrowRootGM[] = {
	0x30,0x82,0x03,0xd0,0x30,0x82,0x02,0xb8,0xa0,0x03,0x02,0x01,0x02,0x02,0x01,0x64,
	0x30,0x0d,0x06,0x09,0x2a,0x86,0x48,0x86,0xf7,0x0d,0x01,0x01,0x0b,0x05,0x00,0x30,
	0x79,0x31,0x0c,0x30,0x0a,0x06,0x03,0x55,0x04,0x05,0x13,0x03,0x31,0x30,0x30,0x31,
	0x0b,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x13,0x30,0x11,
	0x06,0x03,0x55,0x04,0x0a,0x13,0x0a,0x41,0x70,0x70,0x6c,0x65,0x20,0x49,0x6e,0x63,
	0x2e,0x31,0x26,0x30,0x24,0x06,0x03,0x55,0x04,0x0b,0x13,0x1d,0x41,0x70,0x70,0x6c,
	0x65,0x20,0x43,0x65,0x72,0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,
	0x41,0x75,0x74,0x68,0x6f,0x72,0x69,0x74,0x79,0x31,0x1f,0x30,0x1d,0x06,0x03,0x55,
	0x04,0x03,0x13,0x16,0x45,0x73,0x63,0x72,0x6f,0x77,0x20,0x53,0x65,0x72,0x76,0x69,
	0x63,0x65,0x20,0x52,0x6f,0x6f,0x74,0x20,0x43,0x41,0x30,0x1e,0x17,0x0d,0x31,0x33,
	0x30,0x38,0x30,0x32,0x32,0x33,0x32,0x34,0x34,0x34,0x5a,0x17,0x0d,0x32,0x33,0x30,
	0x38,0x30,0x32,0x32,0x33,0x32,0x34,0x34,0x34,0x5a,0x30,0x79,0x31,0x0c,0x30,0x0a,
	0x06,0x03,0x55,0x04,0x05,0x13,0x03,0x31,0x30,0x30,0x31,0x0b,0x30,0x09,0x06,0x03,
	0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x13,0x30,0x11,0x06,0x03,0x55,0x04,0x0a,
	0x13,0x0a,0x41,0x70,0x70,0x6c,0x65,0x20,0x49,0x6e,0x63,0x2e,0x31,0x26,0x30,0x24,
	0x06,0x03,0x55,0x04,0x0b,0x13,0x1d,0x41,0x70,0x70,0x6c,0x65,0x20,0x43,0x65,0x72,
	0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x41,0x75,0x74,0x68,0x6f,
	0x72,0x69,0x74,0x79,0x31,0x1f,0x30,0x1d,0x06,0x03,0x55,0x04,0x03,0x13,0x16,0x45,
	0x73,0x63,0x72,0x6f,0x77,0x20,0x53,0x65,0x72,0x76,0x69,0x63,0x65,0x20,0x52,0x6f,
	0x6f,0x74,0x20,0x43,0x41,0x30,0x82,0x01,0x22,0x30,0x0d,0x06,0x09,0x2a,0x86,0x48,
	0x86,0xf7,0x0d,0x01,0x01,0x01,0x05,0x00,0x03,0x82,0x01,0x0f,0x00,0x30,0x82,0x01,
	0x0a,0x02,0x82,0x01,0x01,0x00,0xd0,0xa3,0xf4,0x56,0x7d,0x3f,0x46,0x31,0xd2,0x56,
	0xa0,0xdf,0x42,0xa0,0x29,0x83,0x1e,0xb9,0x82,0xb5,0xa5,0xff,0x3e,0xde,0xb5,0x0f,
	0x4a,0x8a,0x28,0x60,0xcf,0x75,0xb4,0xa0,0x70,0x7c,0xf5,0xe2,0x94,0xf3,0x22,0x02,
	0xc8,0x81,0xce,0x34,0xc7,0x66,0x6a,0x18,0xaa,0xb4,0xfd,0x6d,0xb0,0x0b,0xdd,0x4a,
	0xdd,0xcf,0xe0,0x08,0x1b,0x1c,0xa6,0xdb,0xba,0xb2,0xc1,0xa4,0x10,0x5f,0x35,0x4f,
	0x8b,0x8b,0x7a,0xa3,0xdb,0x3c,0xf6,0x54,0x95,0x42,0xad,0x2a,0x3b,0xfe,0x06,0x8c,
	0xe1,0x92,0xf1,0x60,0x97,0x58,0x1b,0xd9,0x8f,0xbe,0xfb,0x46,0x4c,0x29,0x5c,0x1c,
	0xf0,0x20,0xb6,0x2b,0xa5,0x12,0x09,0x9b,0x28,0x41,0x34,0x97,0x9f,0xf3,0x88,0x4b,
	0x69,0x72,0xea,0x3a,0x27,0xb0,0x50,0x1d,0x88,0x29,0x0d,0xbb,0xed,0x04,0xa2,0x11,
	0xcf,0x0c,0x5b,0x65,0x61,0x35,0xbd,0xf2,0x0d,0xfc,0xe2,0xb9,0x20,0xd3,0xb7,0x03,
	0x70,0x39,0xd5,0xe0,0x86,0x7c,0x04,0xcc,0xc9,0xa1,0x85,0xb4,0x9b,0xbc,0x88,0x4e,
	0xd7,0xad,0x5c,0xff,0x2c,0x0d,0x80,0x8e,0x51,0x39,0x20,0x8b,0xaf,0x1e,0x46,0x95,
	0xfa,0x0d,0x1b,0xd2,0xbf,0x80,0xe0,0x9f,0x6d,0x4a,0xf5,0x31,0x67,0x18,0x11,0xa5,
	0x63,0x27,0x08,0xee,0xd9,0x07,0x29,0xd0,0xd4,0x36,0x91,0x5b,0xfb,0x4a,0x0b,0x07,
	0xd1,0x0d,0x79,0x16,0x6e,0x16,0x02,0x23,0x80,0xc6,0x15,0x07,0x6d,0xa0,0x06,0xb6,
	0x45,0x90,0xb0,0xae,0xa4,0xad,0x0e,0x75,0x04,0x2b,0x2b,0x78,0xf1,0x57,0x84,0x23,
	0x87,0x24,0xec,0x58,0xc4,0xf1,0x02,0x03,0x01,0x00,0x01,0xa3,0x63,0x30,0x61,0x30,
	0x0f,0x06,0x03,0x55,0x1d,0x13,0x01,0x01,0xff,0x04,0x05,0x30,0x03,0x01,0x01,0xff,
	0x30,0x0e,0x06,0x03,0x55,0x1d,0x0f,0x01,0x01,0xff,0x04,0x04,0x03,0x02,0x01,0x06,
	0x30,0x1d,0x06,0x03,0x55,0x1d,0x0e,0x04,0x16,0x04,0x14,0xfd,0x78,0x96,0x53,0x80,
	0xd6,0xf6,0xdc,0xa6,0xc3,0x59,0x06,0x38,0xed,0x79,0x3e,0x8f,0x50,0x1b,0x50,0x30,
	0x1f,0x06,0x03,0x55,0x1d,0x23,0x04,0x18,0x30,0x16,0x80,0x14,0xfd,0x78,0x96,0x53,
	0x80,0xd6,0xf6,0xdc,0xa6,0xc3,0x59,0x06,0x38,0xed,0x79,0x3e,0x8f,0x50,0x1b,0x50,
	0x30,0x0d,0x06,0x09,0x2a,0x86,0x48,0x86,0xf7,0x0d,0x01,0x01,0x0b,0x05,0x00,0x03,
	0x82,0x01,0x01,0x00,0x71,0x15,0xca,0x87,0xd0,0x2d,0xb5,0x18,0xd5,0x35,0x7a,0xcd,
	0xdf,0x62,0x28,0xf0,0x0b,0x63,0x4d,0x4e,0x02,0xba,0x3d,0xb8,0xb4,0x37,0xea,0xb0,
	0x93,0x93,0xab,0x1c,0xfd,0x9f,0xe8,0x72,0xbf,0xf3,0xdb,0xe6,0xad,0x16,0xfe,0x71,
	0x61,0xa8,0x5a,0xd0,0x58,0x0f,0x65,0x7a,0x57,0x7a,0xe0,0x34,0x80,0x8e,0xbb,0x41,
	0x01,0xe7,0xb0,0x3b,0xf7,0x2b,0x3a,0x6d,0x44,0x2a,0x3a,0x04,0x52,0xfa,0x2b,0x7b,
	0x3b,0x21,0xdd,0x0c,0x70,0x3d,0xfb,0x45,0xc6,0x79,0x68,0x62,0xe2,0x89,0xb8,0x25,
	0xee,0x63,0x76,0x02,0xb2,0x22,0xe9,0x53,0x85,0x68,0x3e,0x75,0xb6,0x0b,0x65,0xe9,
	0x1c,0xba,0x84,0x93,0xb0,0x8a,0xef,0xb5,0x1a,0x12,0xe4,0x8f,0xae,0xd5,0x5c,0xa1,
	0x05,0x4a,0x01,0xbc,0x6f,0xf9,0x58,0x5e,0xf7,0x04,0x61,0xee,0xf5,0xc6,0xa0,0x1b,
	0x44,0x2e,0x5a,0x3a,0x59,0xa1,0xb3,0xb0,0xf4,0xb6,0xcb,0xe0,0x6c,0x2b,0x59,0x8a,
	0xfb,0x6a,0xe0,0xa2,0x57,0x09,0x79,0xc1,0xdd,0xfb,0x84,0x86,0xeb,0x66,0x29,0x73,
	0xae,0xbf,0x58,0xae,0x47,0x4d,0x48,0x37,0xd6,0xb1,0x8c,0x5f,0x26,0x5f,0xb5,0x26,
	0x07,0x0b,0x85,0xb7,0x36,0x37,0x14,0xcf,0x5e,0x55,0xa5,0x3c,0xf3,0x1e,0x79,0x50,
	0xbb,0x85,0x3b,0xb2,0x94,0x68,0xb0,0x25,0x4f,0x75,0xec,0xf0,0xf9,0xc0,0x5a,0x2d,
	0xe5,0xed,0x67,0xcd,0x88,0x55,0xa0,0x42,0xde,0x78,0xbc,0xfe,0x30,0xb1,0x62,0x2d,
	0xe1,0xfd,0xec,0x75,0x03,0xa6,0x1f,0x7c,0xc4,0x3a,0x4a,0x59,0xfe,0x77,0xc3,0x99,
	0x96,0x87,0x44,0xc3,
};

static const UInt8 kBaseLinePCSEscrowRootGM[] = {
	0x30,0x82,0x03,0xD8,0x30,0x82,0x02,0xC0,0xA0,0x03,0x02,0x01,0x02,0x02,0x01,0x64,
	0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B,0x05,0x00,0x30,
	0x7D,0x31,0x0C,0x30,0x0A,0x06,0x03,0x55,0x04,0x05,0x13,0x03,0x31,0x30,0x30,0x31,
	0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x13,0x30,0x11,
	0x06,0x03,0x55,0x04,0x0A,0x13,0x0A,0x41,0x70,0x70,0x6C,0x65,0x20,0x49,0x6E,0x63,
	0x2E,0x31,0x26,0x30,0x24,0x06,0x03,0x55,0x04,0x0B,0x13,0x1D,0x41,0x70,0x70,0x6C,
	0x65,0x20,0x43,0x65,0x72,0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x69,0x6F,0x6E,0x20,
	0x41,0x75,0x74,0x68,0x6F,0x72,0x69,0x74,0x79,0x31,0x23,0x30,0x21,0x06,0x03,0x55,
	0x04,0x03,0x13,0x1A,0x45,0x66,0x66,0x61,0x63,0x65,0x61,0x62,0x6C,0x65,0x20,0x53,
	0x65,0x72,0x76,0x69,0x63,0x65,0x20,0x52,0x6F,0x6F,0x74,0x20,0x43,0x41,0x30,0x1E,
	0x17,0x0D,0x31,0x34,0x30,0x37,0x32,0x38,0x32,0x31,0x30,0x33,0x35,0x32,0x5A,0x17,
	0x0D,0x32,0x34,0x30,0x37,0x32,0x38,0x32,0x31,0x30,0x33,0x35,0x32,0x5A,0x30,0x7D,
	0x31,0x0C,0x30,0x0A,0x06,0x03,0x55,0x04,0x05,0x13,0x03,0x31,0x30,0x30,0x31,0x0B,
	0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x13,0x30,0x11,0x06,
	0x03,0x55,0x04,0x0A,0x13,0x0A,0x41,0x70,0x70,0x6C,0x65,0x20,0x49,0x6E,0x63,0x2E,
	0x31,0x26,0x30,0x24,0x06,0x03,0x55,0x04,0x0B,0x13,0x1D,0x41,0x70,0x70,0x6C,0x65,
	0x20,0x43,0x65,0x72,0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x69,0x6F,0x6E,0x20,0x41,
	0x75,0x74,0x68,0x6F,0x72,0x69,0x74,0x79,0x31,0x23,0x30,0x21,0x06,0x03,0x55,0x04,
	0x03,0x13,0x1A,0x45,0x66,0x66,0x61,0x63,0x65,0x61,0x62,0x6C,0x65,0x20,0x53,0x65,
	0x72,0x76,0x69,0x63,0x65,0x20,0x52,0x6F,0x6F,0x74,0x20,0x43,0x41,0x30,0x82,0x01,
	0x22,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x01,0x05,0x00,
	0x03,0x82,0x01,0x0F,0x00,0x30,0x82,0x01,0x0A,0x02,0x82,0x01,0x01,0x00,0xC0,0x55,
	0xCC,0x74,0xCF,0x49,0xE9,0xEC,0x9A,0x76,0x17,0x30,0x12,0x40,0x7D,0xC1,0x69,0x98,
	0x97,0x2C,0xA7,0xC0,0xD6,0xF4,0x9A,0x1D,0xC2,0x46,0x75,0xB6,0xAD,0x81,0xE2,0x2F,
	0x65,0xF1,0xAF,0xF6,0xBA,0xBD,0xC1,0x44,0x37,0x93,0xB8,0x92,0x2A,0x83,0xCC,0xE3,
	0x6F,0xFD,0x95,0xAA,0x86,0xAE,0x4D,0x62,0x98,0xBC,0xE6,0x90,0x40,0x5B,0x5A,0x2E,
	0x65,0x0C,0xFF,0x07,0xB9,0x79,0xC4,0x2E,0x2E,0x72,0x80,0xE3,0xB9,0x98,0x08,0xE9,
	0x3B,0x79,0x3B,0x46,0x99,0xD7,0xB9,0xDF,0x1F,0xC4,0x0D,0x49,0xB9,0x78,0x39,0xAF,
	0x7F,0xF5,0xDC,0x9C,0xEE,0xC1,0xB0,0x90,0x70,0x97,0xD6,0xE7,0x49,0x0C,0x11,0x19,
	0xE9,0xDD,0xEA,0x38,0x30,0xB9,0x1D,0xF4,0xD7,0xFF,0xBB,0xFC,0x6B,0x49,0xFC,0x69,
	0xE8,0x05,0x8E,0x96,0x14,0x87,0x62,0xD6,0x82,0x2F,0xA2,0x97,0xB5,0x4A,0x80,0x46,
	0x43,0xF5,0xF2,0x1B,0x94,0xBF,0xFE,0x48,0x8B,0x7F,0x4D,0xD6,0x3D,0x3E,0x64,0xBE,
	0x09,0x7C,0x9E,0x24,0x80,0xDE,0xAB,0xC9,0x17,0x91,0xAC,0x60,0x06,0x98,0x9C,0xCB,
	0xAD,0x04,0x41,0x1F,0x7F,0xE5,0xC2,0x08,0xD5,0x80,0xD7,0x63,0xF1,0x5C,0x60,0xA2,
	0xE5,0xAD,0x5F,0x6E,0xBC,0x3A,0xC4,0x9F,0x4D,0xE4,0x65,0xA3,0xF2,0x18,0x0B,0x1A,
	0x2D,0xB4,0x64,0x3D,0x53,0x5A,0x14,0xF6,0x26,0x92,0x13,0x23,0x83,0x33,0xBE,0xE0,
	0xA4,0x43,0xFC,0x79,0xA0,0x91,0xFB,0x1C,0x17,0xF0,0x87,0xE5,0x8C,0x68,0xF2,0xCF,
	0xAE,0x3B,0xC5,0xD5,0xD2,0x58,0x8E,0xFB,0x29,0x53,0xFE,0x9E,0xDE,0x4F,0x02,0x03,
	0x01,0x00,0x01,0xA3,0x63,0x30,0x61,0x30,0x0F,0x06,0x03,0x55,0x1D,0x13,0x01,0x01,
	0xFF,0x04,0x05,0x30,0x03,0x01,0x01,0xFF,0x30,0x0E,0x06,0x03,0x55,0x1D,0x0F,0x01,
	0x01,0xFF,0x04,0x04,0x03,0x02,0x01,0x06,0x30,0x1D,0x06,0x03,0x55,0x1D,0x0E,0x04,
	0x16,0x04,0x14,0x64,0x0B,0xE4,0x72,0x73,0x5C,0x54,0xB2,0x58,0x59,0xAE,0x42,0xDF,
	0x2B,0xB7,0xBA,0xB9,0xEB,0x86,0xAE,0x30,0x1F,0x06,0x03,0x55,0x1D,0x23,0x04,0x18,
	0x30,0x16,0x80,0x14,0x64,0x0B,0xE4,0x72,0x73,0x5C,0x54,0xB2,0x58,0x59,0xAE,0x42,
	0xDF,0x2B,0xB7,0xBA,0xB9,0xEB,0x86,0xAE,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,
	0xF7,0x0D,0x01,0x01,0x0B,0x05,0x00,0x03,0x82,0x01,0x01,0x00,0x79,0xF4,0x22,0xC9,
	0x6C,0x25,0x64,0x2D,0x8E,0x91,0x53,0x7B,0xFB,0xA7,0xD2,0x0C,0xAD,0xDC,0xA9,0x83,
	0x90,0x75,0x16,0x98,0xC1,0x2C,0xFE,0x7C,0x16,0xCE,0x2A,0xA0,0xB8,0x8A,0xF6,0xDB,
	0x3E,0x2D,0x6C,0x5D,0x61,0x41,0x10,0xBB,0x02,0xBA,0x51,0x5B,0x42,0x62,0x18,0x9F,
	0xC4,0x25,0xF3,0x24,0xCC,0x1D,0xD2,0xFF,0x47,0xB2,0x14,0x9E,0x6A,0x31,0xA3,0xA7,
	0xB1,0x0C,0x7E,0x55,0xCE,0xC4,0x9E,0xA6,0x0A,0x06,0x9B,0x50,0x40,0x04,0x13,0xA0,
	0xC7,0x4D,0x37,0xD9,0x85,0xCF,0xB2,0xD9,0x16,0x38,0x4B,0xA3,0xA5,0x3E,0xDC,0x06,
	0x0D,0xE0,0xB1,0x13,0x7C,0x8B,0x79,0x1F,0x67,0xD8,0xBA,0xB4,0x58,0x9C,0x84,0x18,
	0xE4,0xED,0x22,0x17,0x41,0xA9,0x3B,0x88,0xD5,0x55,0x54,0x5F,0x33,0x4D,0xE2,0xBD,
	0xBE,0x66,0x46,0x59,0xC0,0x60,0xC5,0xB2,0x7A,0xF6,0xCA,0xCD,0xB9,0x2D,0xBD,0x50,
	0xB3,0xD6,0x18,0xD5,0x1F,0xFA,0x42,0x30,0x4C,0x10,0xFB,0x12,0xA9,0x9A,0x0E,0x39,
	0xFA,0x77,0xB6,0x82,0x53,0xF3,0x35,0x74,0xB5,0x10,0x5A,0x22,0xAE,0x17,0x25,0xD1,
	0x09,0xB9,0x71,0x08,0xA1,0xFA,0x2D,0xB9,0xEA,0x8C,0xC5,0xAC,0x31,0x6C,0x45,0x46,
	0x2E,0x11,0x2D,0x75,0x07,0x88,0x39,0xA3,0x14,0x08,0xA6,0xBF,0x7B,0x2C,0x26,0xAE,
	0x28,0xE9,0x1D,0x6C,0xFF,0xAC,0x99,0x53,0x44,0x91,0x26,0x2E,0x82,0x1A,0x11,0x66,
	0xB5,0x9C,0xEF,0x9E,0xC1,0x52,0x8F,0xCE,0x12,0xF3,0x88,0x86,0x06,0xF0,0xE8,0x62,
	0x69,0x12,0x04,0x6D,0x2B,0x75,0x83,0xE1,0x12,0xFC,0x3E,0xF1,
};

static const UInt8 kBaseLineACFEscrowRootGM[] = {
    0x30,0x82,0x03,0xD0,0x30,0x82,0x02,0xB8,0xA0,0x03,0x02,0x01,0x02,0x02,0x01,0x65,
    0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B,0x05,0x00,0x30,
    0x79,0x31,0x0C,0x30,0x0A,0x06,0x03,0x55,0x04,0x05,0x13,0x03,0x31,0x30,0x31,0x31,
    0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x13,0x30,0x11,
    0x06,0x03,0x55,0x04,0x0A,0x13,0x0A,0x41,0x70,0x70,0x6C,0x65,0x20,0x49,0x6E,0x63,
    0x2E,0x31,0x26,0x30,0x24,0x06,0x03,0x55,0x04,0x0B,0x13,0x1D,0x41,0x70,0x70,0x6C,
    0x65,0x20,0x43,0x65,0x72,0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x69,0x6F,0x6E,0x20,
    0x41,0x75,0x74,0x68,0x6F,0x72,0x69,0x74,0x79,0x31,0x1F,0x30,0x1D,0x06,0x03,0x55,
    0x04,0x03,0x13,0x16,0x45,0x73,0x63,0x72,0x6F,0x77,0x20,0x53,0x65,0x72,0x76,0x69,
    0x63,0x65,0x20,0x52,0x6F,0x6F,0x74,0x20,0x43,0x41,0x30,0x1E,0x17,0x0D,0x31,0x35,
    0x30,0x35,0x31,0x36,0x30,0x35,0x32,0x38,0x32,0x31,0x5A,0x17,0x0D,0x34,0x39,0x30,
    0x35,0x31,0x36,0x30,0x35,0x32,0x38,0x32,0x31,0x5A,0x30,0x79,0x31,0x0C,0x30,0x0A,
    0x06,0x03,0x55,0x04,0x05,0x13,0x03,0x31,0x30,0x31,0x31,0x0B,0x30,0x09,0x06,0x03,
    0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x13,0x30,0x11,0x06,0x03,0x55,0x04,0x0A,
    0x13,0x0A,0x41,0x70,0x70,0x6C,0x65,0x20,0x49,0x6E,0x63,0x2E,0x31,0x26,0x30,0x24,
    0x06,0x03,0x55,0x04,0x0B,0x13,0x1D,0x41,0x70,0x70,0x6C,0x65,0x20,0x43,0x65,0x72,
    0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x69,0x6F,0x6E,0x20,0x41,0x75,0x74,0x68,0x6F,
    0x72,0x69,0x74,0x79,0x31,0x1F,0x30,0x1D,0x06,0x03,0x55,0x04,0x03,0x13,0x16,0x45,
    0x73,0x63,0x72,0x6F,0x77,0x20,0x53,0x65,0x72,0x76,0x69,0x63,0x65,0x20,0x52,0x6F,
    0x6F,0x74,0x20,0x43,0x41,0x30,0x82,0x01,0x22,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,
    0x86,0xF7,0x0D,0x01,0x01,0x01,0x05,0x00,0x03,0x82,0x01,0x0F,0x00,0x30,0x82,0x01,
    0x0A,0x02,0x82,0x01,0x01,0x00,0xD4,0xA6,0xF0,0x01,0x97,0xDA,0x08,0x7D,0xA5,0xF9,
    0xB5,0x48,0x9D,0x4E,0x4C,0x30,0x5A,0x67,0xE4,0x12,0x6F,0x4C,0x36,0x4B,0xC6,0xE1,
    0x1F,0x6B,0x41,0xF2,0x46,0x21,0x0D,0x71,0x3D,0xCF,0xB4,0x6C,0x67,0x92,0x9B,0x37,
    0x39,0x24,0x25,0xD2,0x7B,0xFF,0x54,0xF2,0x44,0x4A,0x08,0xE2,0xE5,0xB2,0xB7,0xC9,
    0x56,0xCE,0x25,0x2E,0x41,0xBB,0xED,0xCC,0x24,0x8E,0x05,0x0F,0x28,0xDF,0xE3,0xAB,
    0xCA,0xA1,0x7C,0xCC,0xE6,0x66,0x15,0x89,0xD7,0x5C,0x68,0x35,0x48,0x9D,0xD3,0xDA,
    0x80,0x8E,0xE7,0xEE,0x15,0x73,0x67,0xD2,0xB1,0xF9,0xB3,0x09,0x4F,0xBA,0x2F,0x09,
    0x76,0xEE,0x9F,0x08,0x0D,0x8E,0x34,0x6D,0x14,0x4B,0xD7,0x57,0x17,0xE3,0xEC,0x23,
    0x6E,0xC3,0xA1,0xBD,0x2F,0xC3,0x22,0x9D,0x0E,0x8E,0x67,0x8D,0x78,0xB9,0x50,0xCB,
    0x08,0x82,0xAB,0xAC,0x90,0x91,0x45,0x86,0x18,0x7C,0x0A,0xF5,0xBA,0x22,0x67,0x4B,
    0xED,0x5F,0xC0,0x92,0xB3,0x07,0x06,0x64,0xA7,0xDA,0x11,0x13,0xF8,0xDD,0xA0,0xA8,
    0xFC,0xC9,0xF0,0xA5,0xF1,0xA5,0x90,0xF9,0x13,0xDA,0xF9,0x07,0x16,0xD6,0x38,0xCC,
    0x22,0x37,0x37,0x42,0xB3,0x6A,0x63,0xAA,0x76,0x9E,0xB3,0x87,0xA4,0x36,0x3B,0xE3,
    0x54,0x20,0x00,0x33,0x93,0x09,0x2C,0x46,0x9E,0x69,0x86,0x83,0xD8,0xE9,0xC0,0x42,
    0x5B,0x04,0x16,0x0D,0xE2,0x86,0x9F,0x57,0x0F,0xB7,0x56,0xB8,0x6E,0xE0,0x58,0xD8,
    0x78,0xDE,0xAC,0xF1,0x52,0x07,0x49,0xA5,0xC9,0x97,0x6F,0x26,0x49,0x35,0x71,0x14,
    0x38,0x11,0x3E,0x76,0x7C,0xD9,0x02,0x03,0x01,0x00,0x01,0xA3,0x63,0x30,0x61,0x30,
    0x0F,0x06,0x03,0x55,0x1D,0x13,0x01,0x01,0xFF,0x04,0x05,0x30,0x03,0x01,0x01,0xFF,
    0x30,0x0E,0x06,0x03,0x55,0x1D,0x0F,0x01,0x01,0xFF,0x04,0x04,0x03,0x02,0x01,0x06,
    0x30,0x1D,0x06,0x03,0x55,0x1D,0x0E,0x04,0x16,0x04,0x14,0x8C,0xC8,0x0F,0xA1,0x55,
    0xB0,0x84,0x7B,0x8D,0xC1,0x99,0x8C,0xF3,0x4F,0x18,0xB5,0x0F,0x83,0x80,0x6F,0x30,
    0x1F,0x06,0x03,0x55,0x1D,0x23,0x04,0x18,0x30,0x16,0x80,0x14,0x8C,0xC8,0x0F,0xA1,
    0x55,0xB0,0x84,0x7B,0x8D,0xC1,0x99,0x8C,0xF3,0x4F,0x18,0xB5,0x0F,0x83,0x80,0x6F,
    0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B,0x05,0x00,0x03,
    0x82,0x01,0x01,0x00,0x43,0x8D,0xA8,0x86,0x77,0xB7,0xF5,0xA8,0xD8,0xE5,0x32,0xE5,
    0xE7,0xAA,0x99,0x04,0x4C,0xD2,0x86,0x81,0x4B,0x72,0x89,0xBA,0x40,0x14,0xAD,0x75,
    0xDB,0xA1,0xBF,0xC3,0x73,0x22,0xAF,0xAE,0x33,0xAC,0xB3,0x13,0x62,0xB2,0x3D,0xCA,
    0xD3,0xBC,0x45,0x7A,0xC2,0xBC,0x2C,0xCA,0xA1,0x3F,0xD9,0x52,0xA8,0x54,0xC2,0x44,
    0xB8,0x6B,0xA5,0xCA,0xF4,0x7D,0xF6,0xE3,0x0B,0x1F,0x38,0x16,0x67,0xF1,0x0B,0xA8,
    0x2A,0xDC,0x72,0xC8,0x87,0x3B,0x44,0x55,0xF7,0x0F,0x04,0x57,0x67,0xF1,0x11,0x91,
    0xA0,0xD2,0x78,0xEC,0x8C,0xBB,0x76,0x24,0x66,0x4F,0xA1,0xFE,0xBB,0xDE,0x00,0x01,
    0x9F,0x30,0x18,0x27,0x32,0xFF,0xFF,0xF6,0x9B,0xEA,0x43,0x36,0x67,0x2F,0x83,0x97,
    0x4D,0xE8,0x4E,0x9C,0xC1,0xEE,0x24,0xC8,0x21,0x72,0xFB,0x12,0xA9,0x2E,0x65,0xDE,
    0x84,0xB8,0xFF,0xC4,0xAB,0xDB,0x5D,0x3A,0xE9,0x3C,0x8F,0x1C,0x26,0x65,0x5F,0x34,
    0x50,0xB2,0x60,0x76,0x8B,0x42,0x64,0x5A,0x59,0xEA,0xD1,0x4E,0x23,0xF4,0xC8,0x28,
    0x8F,0x60,0xE5,0x75,0x36,0x3B,0x4C,0x38,0xC9,0x0F,0xCD,0x54,0x79,0x47,0x1D,0xC3,
    0x2F,0x9B,0x33,0x39,0x9F,0x50,0xD2,0x0B,0x68,0x3D,0x8A,0xCA,0x1F,0x5A,0xA5,0x5E,
    0x29,0x68,0x96,0xC2,0x1E,0x02,0xBA,0x8F,0x9C,0x55,0xB3,0x2E,0x24,0x2C,0x58,0xD8,
    0xAC,0xE4,0xF0,0x6C,0xDE,0x16,0x47,0x37,0x0D,0xA8,0x5C,0x09,0x4B,0x23,0x4D,0x21,
    0xFD,0xFF,0xCD,0x50,0xD5,0x59,0x0E,0x37,0x63,0xD0,0xA5,0xC7,0xBF,0xDD,0x88,0xF3,
    0x81,0xB1,0x3F,0x4E,
};


static struct RootRecord kBaseLineEscrowRootRecord = {sizeof(kBaseLineEscrowRootGM), (UInt8*)kBaseLineEscrowRootGM};
static struct RootRecord kBaseLineACFEscrowRootRecord = {sizeof(kBaseLineACFEscrowRootGM), (UInt8*)kBaseLineACFEscrowRootGM};
static struct RootRecord* kBaseLineEscrowRoots[] = {&kBaseLineEscrowRootRecord, &kBaseLineACFEscrowRootRecord};
static const int kNumberOfBaseLineEscrowRoots = (int)(sizeof(kBaseLineEscrowRoots)/sizeof(kBaseLineEscrowRoots[0]));

static struct RootRecord kBaseLinePCSEscrowRootRecord = {sizeof(kBaseLinePCSEscrowRootGM), (UInt8*)kBaseLinePCSEscrowRootGM};
static struct RootRecord* kBaseLinePCSEscrowRoots[] = {&kBaseLinePCSEscrowRootRecord};
static const int kNumberOfBaseLinePCSEscrowRoots = (int)(sizeof(kBaseLinePCSEscrowRoots)/sizeof(kBaseLinePCSEscrowRoots[0]));

#endif
