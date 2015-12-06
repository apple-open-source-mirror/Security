/*
 * Copyright (c) 2015 Apple Inc. All Rights Reserved.
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
 * SecTrustSettingsCertificates.h
 *
 * Contains some CA certificates which may be included in results
 * returned by SecTrustSettingsCopyCertificates as a workaround for
 * issues in client applications when the original self-signed root is
 * no longer present, e.g. when providing anchor certificates to OpenSSL code.
 * Note that these CAs are not generally trusted by the system, they are just
 * returned from the SecTrustSettingsCopyCertificates function.
 */

#ifndef _SEC_TRUST_SETTINGS_CERTIFICATES_H_
#define _SEC_TRUST_SETTINGS_CERTIFICATES_H_

#if 0
/* SHA1 Fingerprint=4D:34:EA:92:76:4B:3A:31:49:11:99:52:F4:19:30:CA:11:34:83:61 */
/* subject:/C=IE/O=Baltimore/OU=CyberTrust/CN=Baltimore CyberTrust Root */
/* issuer :/C=US/O=GTE Corporation/OU=GTE CyberTrust Solutions, Inc./CN=GTE CyberTrust Global Root */
/* 2048-bit RSA */
unsigned char _BaltimoreCyberTrustCSICA[1049]={
0x30,0x82,0x04,0x15,0x30,0x82,0x03,0x7E,0xA0,0x03,0x02,0x01,0x02,0x02,0x04,0x07,
0x27,0x8E,0xED,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x05,
0x05,0x00,0x30,0x75,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,
0x53,0x31,0x18,0x30,0x16,0x06,0x03,0x55,0x04,0x0A,0x13,0x0F,0x47,0x54,0x45,0x20,
0x43,0x6F,0x72,0x70,0x6F,0x72,0x61,0x74,0x69,0x6F,0x6E,0x31,0x27,0x30,0x25,0x06,
0x03,0x55,0x04,0x0B,0x13,0x1E,0x47,0x54,0x45,0x20,0x43,0x79,0x62,0x65,0x72,0x54,
0x72,0x75,0x73,0x74,0x20,0x53,0x6F,0x6C,0x75,0x74,0x69,0x6F,0x6E,0x73,0x2C,0x20,
0x49,0x6E,0x63,0x2E,0x31,0x23,0x30,0x21,0x06,0x03,0x55,0x04,0x03,0x13,0x1A,0x47,
0x54,0x45,0x20,0x43,0x79,0x62,0x65,0x72,0x54,0x72,0x75,0x73,0x74,0x20,0x47,0x6C,
0x6F,0x62,0x61,0x6C,0x20,0x52,0x6F,0x6F,0x74,0x30,0x1E,0x17,0x0D,0x31,0x32,0x30,
0x34,0x31,0x38,0x31,0x36,0x33,0x36,0x31,0x38,0x5A,0x17,0x0D,0x31,0x38,0x30,0x38,
0x31,0x33,0x31,0x36,0x33,0x35,0x31,0x37,0x5A,0x30,0x5A,0x31,0x0B,0x30,0x09,0x06,
0x03,0x55,0x04,0x06,0x13,0x02,0x49,0x45,0x31,0x12,0x30,0x10,0x06,0x03,0x55,0x04,
0x0A,0x13,0x09,0x42,0x61,0x6C,0x74,0x69,0x6D,0x6F,0x72,0x65,0x31,0x13,0x30,0x11,
0x06,0x03,0x55,0x04,0x0B,0x13,0x0A,0x43,0x79,0x62,0x65,0x72,0x54,0x72,0x75,0x73,
0x74,0x31,0x22,0x30,0x20,0x06,0x03,0x55,0x04,0x03,0x13,0x19,0x42,0x61,0x6C,0x74,
0x69,0x6D,0x6F,0x72,0x65,0x20,0x43,0x79,0x62,0x65,0x72,0x54,0x72,0x75,0x73,0x74,
0x20,0x52,0x6F,0x6F,0x74,0x30,0x82,0x01,0x22,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,
0x86,0xF7,0x0D,0x01,0x01,0x01,0x05,0x00,0x03,0x82,0x01,0x0F,0x00,0x30,0x82,0x01,
0x0A,0x02,0x82,0x01,0x01,0x00,0xA3,0x04,0xBB,0x22,0xAB,0x98,0x3D,0x57,0xE8,0x26,
0x72,0x9A,0xB5,0x79,0xD4,0x29,0xE2,0xE1,0xE8,0x95,0x80,0xB1,0xB0,0xE3,0x5B,0x8E,
0x2B,0x29,0x9A,0x64,0xDF,0xA1,0x5D,0xED,0xB0,0x09,0x05,0x6D,0xDB,0x28,0x2E,0xCE,
0x62,0xA2,0x62,0xFE,0xB4,0x88,0xDA,0x12,0xEB,0x38,0xEB,0x21,0x9D,0xC0,0x41,0x2B,
0x01,0x52,0x7B,0x88,0x77,0xD3,0x1C,0x8F,0xC7,0xBA,0xB9,0x88,0xB5,0x6A,0x09,0xE7,
0x73,0xE8,0x11,0x40,0xA7,0xD1,0xCC,0xCA,0x62,0x8D,0x2D,0xE5,0x8F,0x0B,0xA6,0x50,
0xD2,0xA8,0x50,0xC3,0x28,0xEA,0xF5,0xAB,0x25,0x87,0x8A,0x9A,0x96,0x1C,0xA9,0x67,
0xB8,0x3F,0x0C,0xD5,0xF7,0xF9,0x52,0x13,0x2F,0xC2,0x1B,0xD5,0x70,0x70,0xF0,0x8F,
0xC0,0x12,0xCA,0x06,0xCB,0x9A,0xE1,0xD9,0xCA,0x33,0x7A,0x77,0xD6,0xF8,0xEC,0xB9,
0xF1,0x68,0x44,0x42,0x48,0x13,0xD2,0xC0,0xC2,0xA4,0xAE,0x5E,0x60,0xFE,0xB6,0xA6,
0x05,0xFC,0xB4,0xDD,0x07,0x59,0x02,0xD4,0x59,0x18,0x98,0x63,0xF5,0xA5,0x63,0xE0,
0x90,0x0C,0x7D,0x5D,0xB2,0x06,0x7A,0xF3,0x85,0xEA,0xEB,0xD4,0x03,0xAE,0x5E,0x84,
0x3E,0x5F,0xFF,0x15,0xED,0x69,0xBC,0xF9,0x39,0x36,0x72,0x75,0xCF,0x77,0x52,0x4D,
0xF3,0xC9,0x90,0x2C,0xB9,0x3D,0xE5,0xC9,0x23,0x53,0x3F,0x1F,0x24,0x98,0x21,0x5C,
0x07,0x99,0x29,0xBD,0xC6,0x3A,0xEC,0xE7,0x6E,0x86,0x3A,0x6B,0x97,0x74,0x63,0x33,
0xBD,0x68,0x18,0x31,0xF0,0x78,0x8D,0x76,0xBF,0xFC,0x9E,0x8E,0x5D,0x2A,0x86,0xA7,
0x4D,0x90,0xDC,0x27,0x1A,0x39,0x02,0x03,0x01,0x00,0x01,0xA3,0x82,0x01,0x47,0x30,
0x82,0x01,0x43,0x30,0x12,0x06,0x03,0x55,0x1D,0x13,0x01,0x01,0xFF,0x04,0x08,0x30,
0x06,0x01,0x01,0xFF,0x02,0x01,0x03,0x30,0x4A,0x06,0x03,0x55,0x1D,0x20,0x04,0x43,
0x30,0x41,0x30,0x3F,0x06,0x04,0x55,0x1D,0x20,0x00,0x30,0x37,0x30,0x35,0x06,0x08,
0x2B,0x06,0x01,0x05,0x05,0x07,0x02,0x01,0x16,0x29,0x68,0x74,0x74,0x70,0x3A,0x2F,
0x2F,0x63,0x79,0x62,0x65,0x72,0x74,0x72,0x75,0x73,0x74,0x2E,0x6F,0x6D,0x6E,0x69,
0x72,0x6F,0x6F,0x74,0x2E,0x63,0x6F,0x6D,0x2F,0x72,0x65,0x70,0x6F,0x73,0x69,0x74,
0x6F,0x72,0x79,0x30,0x0E,0x06,0x03,0x55,0x1D,0x0F,0x01,0x01,0xFF,0x04,0x04,0x03,
0x02,0x01,0x06,0x30,0x81,0x89,0x06,0x03,0x55,0x1D,0x23,0x04,0x81,0x81,0x30,0x7F,
0xA1,0x79,0xA4,0x77,0x30,0x75,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,
0x02,0x55,0x53,0x31,0x18,0x30,0x16,0x06,0x03,0x55,0x04,0x0A,0x13,0x0F,0x47,0x54,
0x45,0x20,0x43,0x6F,0x72,0x70,0x6F,0x72,0x61,0x74,0x69,0x6F,0x6E,0x31,0x27,0x30,
0x25,0x06,0x03,0x55,0x04,0x0B,0x13,0x1E,0x47,0x54,0x45,0x20,0x43,0x79,0x62,0x65,
0x72,0x54,0x72,0x75,0x73,0x74,0x20,0x53,0x6F,0x6C,0x75,0x74,0x69,0x6F,0x6E,0x73,
0x2C,0x20,0x49,0x6E,0x63,0x2E,0x31,0x23,0x30,0x21,0x06,0x03,0x55,0x04,0x03,0x13,
0x1A,0x47,0x54,0x45,0x20,0x43,0x79,0x62,0x65,0x72,0x54,0x72,0x75,0x73,0x74,0x20,
0x47,0x6C,0x6F,0x62,0x61,0x6C,0x20,0x52,0x6F,0x6F,0x74,0x82,0x02,0x01,0xA5,0x30,
0x45,0x06,0x03,0x55,0x1D,0x1F,0x04,0x3E,0x30,0x3C,0x30,0x3A,0xA0,0x38,0xA0,0x36,
0x86,0x34,0x68,0x74,0x74,0x70,0x3A,0x2F,0x2F,0x77,0x77,0x77,0x2E,0x70,0x75,0x62,
0x6C,0x69,0x63,0x2D,0x74,0x72,0x75,0x73,0x74,0x2E,0x63,0x6F,0x6D,0x2F,0x63,0x67,
0x69,0x2D,0x62,0x69,0x6E,0x2F,0x43,0x52,0x4C,0x2F,0x32,0x30,0x31,0x38,0x2F,0x63,
0x64,0x70,0x2E,0x63,0x72,0x6C,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,
0x01,0x01,0x05,0x05,0x00,0x03,0x81,0x81,0x00,0x93,0x1D,0xFE,0x8B,0xAE,0x46,0xEC,
0xCB,0xA9,0x0F,0xAB,0xE5,0xEF,0xCA,0xB2,0x68,0x16,0x68,0xD8,0x8F,0xFA,0x13,0xA9,
0xAF,0xB3,0xCB,0x2D,0xE7,0x4B,0x6E,0x8E,0x69,0x2A,0xC2,0x2B,0x10,0x0A,0x8D,0xF6,
0xAE,0x73,0xB6,0xB9,0xFB,0x14,0xFD,0x5F,0x6D,0xB8,0x50,0xB6,0xC4,0x8A,0xD6,0x40,
0x7E,0xD7,0xC3,0xCB,0x73,0xDC,0xC9,0x5D,0x5B,0xAF,0xB0,0x41,0xB5,0x37,0xEB,0xEA,
0xDC,0x20,0x91,0xC4,0x34,0x6A,0xF4,0xA1,0xF3,0x96,0x9D,0x37,0x86,0x97,0xE1,0x71,
0xA4,0xDD,0x7D,0xFA,0x44,0x84,0x94,0xAE,0xD7,0x09,0x04,0x22,0x76,0x0F,0x64,0x51,
0x35,0xA9,0x24,0x0F,0xF9,0x0B,0xDB,0x32,0xDA,0xC2,0xFE,0xC1,0xB9,0x2A,0x5C,0x7A,
0x27,0x13,0xCA,0xB1,0x48,0x3A,0x71,0xD0,0x43,
};

/* SHA1 Fingerprint=32:F3:08:82:62:2B:87:CF:88:56:C6:3D:B8:73:DF:08:53:B4:DD:27 */
/* subject:/C=US/O=VeriSign, Inc./OU=VeriSign Trust Network/OU=(c) 2006 VeriSign, Inc. - For authorized use only/CN=VeriSign Class 3 Public Primary Certification Authority - G5 */
/* issuer :/C=US/O=VeriSign, Inc./OU=Class 3 Public Primary Certification Authority */
/* 2048-bit RSA */
unsigned char _VeriSignG5CSICA[1236]={
0x30,0x82,0x04,0xD0,0x30,0x82,0x04,0x39,0xA0,0x03,0x02,0x01,0x02,0x02,0x10,0x25,
0x0C,0xE8,0xE0,0x30,0x61,0x2E,0x9F,0x2B,0x89,0xF7,0x05,0x4D,0x7C,0xF8,0xFD,0x30,
0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x05,0x05,0x00,0x30,0x5F,
0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x17,0x30,
0x15,0x06,0x03,0x55,0x04,0x0A,0x13,0x0E,0x56,0x65,0x72,0x69,0x53,0x69,0x67,0x6E,
0x2C,0x20,0x49,0x6E,0x63,0x2E,0x31,0x37,0x30,0x35,0x06,0x03,0x55,0x04,0x0B,0x13,
0x2E,0x43,0x6C,0x61,0x73,0x73,0x20,0x33,0x20,0x50,0x75,0x62,0x6C,0x69,0x63,0x20,
0x50,0x72,0x69,0x6D,0x61,0x72,0x79,0x20,0x43,0x65,0x72,0x74,0x69,0x66,0x69,0x63,
0x61,0x74,0x69,0x6F,0x6E,0x20,0x41,0x75,0x74,0x68,0x6F,0x72,0x69,0x74,0x79,0x30,
0x1E,0x17,0x0D,0x30,0x36,0x31,0x31,0x30,0x38,0x30,0x30,0x30,0x30,0x30,0x30,0x5A,
0x17,0x0D,0x32,0x31,0x31,0x31,0x30,0x37,0x32,0x33,0x35,0x39,0x35,0x39,0x5A,0x30,
0x81,0xCA,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,
0x17,0x30,0x15,0x06,0x03,0x55,0x04,0x0A,0x13,0x0E,0x56,0x65,0x72,0x69,0x53,0x69,
0x67,0x6E,0x2C,0x20,0x49,0x6E,0x63,0x2E,0x31,0x1F,0x30,0x1D,0x06,0x03,0x55,0x04,
0x0B,0x13,0x16,0x56,0x65,0x72,0x69,0x53,0x69,0x67,0x6E,0x20,0x54,0x72,0x75,0x73,
0x74,0x20,0x4E,0x65,0x74,0x77,0x6F,0x72,0x6B,0x31,0x3A,0x30,0x38,0x06,0x03,0x55,
0x04,0x0B,0x13,0x31,0x28,0x63,0x29,0x20,0x32,0x30,0x30,0x36,0x20,0x56,0x65,0x72,
0x69,0x53,0x69,0x67,0x6E,0x2C,0x20,0x49,0x6E,0x63,0x2E,0x20,0x2D,0x20,0x46,0x6F,
0x72,0x20,0x61,0x75,0x74,0x68,0x6F,0x72,0x69,0x7A,0x65,0x64,0x20,0x75,0x73,0x65,
0x20,0x6F,0x6E,0x6C,0x79,0x31,0x45,0x30,0x43,0x06,0x03,0x55,0x04,0x03,0x13,0x3C,
0x56,0x65,0x72,0x69,0x53,0x69,0x67,0x6E,0x20,0x43,0x6C,0x61,0x73,0x73,0x20,0x33,
0x20,0x50,0x75,0x62,0x6C,0x69,0x63,0x20,0x50,0x72,0x69,0x6D,0x61,0x72,0x79,0x20,
0x43,0x65,0x72,0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x69,0x6F,0x6E,0x20,0x41,0x75,
0x74,0x68,0x6F,0x72,0x69,0x74,0x79,0x20,0x2D,0x20,0x47,0x35,0x30,0x82,0x01,0x22,
0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x01,0x05,0x00,0x03,
0x82,0x01,0x0F,0x00,0x30,0x82,0x01,0x0A,0x02,0x82,0x01,0x01,0x00,0xAF,0x24,0x08,
0x08,0x29,0x7A,0x35,0x9E,0x60,0x0C,0xAA,0xE7,0x4B,0x3B,0x4E,0xDC,0x7C,0xBC,0x3C,
0x45,0x1C,0xBB,0x2B,0xE0,0xFE,0x29,0x02,0xF9,0x57,0x08,0xA3,0x64,0x85,0x15,0x27,
0xF5,0xF1,0xAD,0xC8,0x31,0x89,0x5D,0x22,0xE8,0x2A,0xAA,0xA6,0x42,0xB3,0x8F,0xF8,
0xB9,0x55,0xB7,0xB1,0xB7,0x4B,0xB3,0xFE,0x8F,0x7E,0x07,0x57,0xEC,0xEF,0x43,0xDB,
0x66,0x62,0x15,0x61,0xCF,0x60,0x0D,0xA4,0xD8,0xDE,0xF8,0xE0,0xC3,0x62,0x08,0x3D,
0x54,0x13,0xEB,0x49,0xCA,0x59,0x54,0x85,0x26,0xE5,0x2B,0x8F,0x1B,0x9F,0xEB,0xF5,
0xA1,0x91,0xC2,0x33,0x49,0xD8,0x43,0x63,0x6A,0x52,0x4B,0xD2,0x8F,0xE8,0x70,0x51,
0x4D,0xD1,0x89,0x69,0x7B,0xC7,0x70,0xF6,0xB3,0xDC,0x12,0x74,0xDB,0x7B,0x5D,0x4B,
0x56,0xD3,0x96,0xBF,0x15,0x77,0xA1,0xB0,0xF4,0xA2,0x25,0xF2,0xAF,0x1C,0x92,0x67,
0x18,0xE5,0xF4,0x06,0x04,0xEF,0x90,0xB9,0xE4,0x00,0xE4,0xDD,0x3A,0xB5,0x19,0xFF,
0x02,0xBA,0xF4,0x3C,0xEE,0xE0,0x8B,0xEB,0x37,0x8B,0xEC,0xF4,0xD7,0xAC,0xF2,0xF6,
0xF0,0x3D,0xAF,0xDD,0x75,0x91,0x33,0x19,0x1D,0x1C,0x40,0xCB,0x74,0x24,0x19,0x21,
0x93,0xD9,0x14,0xFE,0xAC,0x2A,0x52,0xC7,0x8F,0xD5,0x04,0x49,0xE4,0x8D,0x63,0x47,
0x88,0x3C,0x69,0x83,0xCB,0xFE,0x47,0xBD,0x2B,0x7E,0x4F,0xC5,0x95,0xAE,0x0E,0x9D,
0xD4,0xD1,0x43,0xC0,0x67,0x73,0xE3,0x14,0x08,0x7E,0xE5,0x3F,0x9F,0x73,0xB8,0x33,
0x0A,0xCF,0x5D,0x3F,0x34,0x87,0x96,0x8A,0xEE,0x53,0xE8,0x25,0x15,0x02,0x03,0x01,
0x00,0x01,0xA3,0x82,0x01,0x9B,0x30,0x82,0x01,0x97,0x30,0x0F,0x06,0x03,0x55,0x1D,
0x13,0x01,0x01,0xFF,0x04,0x05,0x30,0x03,0x01,0x01,0xFF,0x30,0x31,0x06,0x03,0x55,
0x1D,0x1F,0x04,0x2A,0x30,0x28,0x30,0x26,0xA0,0x24,0xA0,0x22,0x86,0x20,0x68,0x74,
0x74,0x70,0x3A,0x2F,0x2F,0x63,0x72,0x6C,0x2E,0x76,0x65,0x72,0x69,0x73,0x69,0x67,
0x6E,0x2E,0x63,0x6F,0x6D,0x2F,0x70,0x63,0x61,0x33,0x2E,0x63,0x72,0x6C,0x30,0x0E,
0x06,0x03,0x55,0x1D,0x0F,0x01,0x01,0xFF,0x04,0x04,0x03,0x02,0x01,0x06,0x30,0x3D,
0x06,0x03,0x55,0x1D,0x20,0x04,0x36,0x30,0x34,0x30,0x32,0x06,0x04,0x55,0x1D,0x20,
0x00,0x30,0x2A,0x30,0x28,0x06,0x08,0x2B,0x06,0x01,0x05,0x05,0x07,0x02,0x01,0x16,
0x1C,0x68,0x74,0x74,0x70,0x73,0x3A,0x2F,0x2F,0x77,0x77,0x77,0x2E,0x76,0x65,0x72,
0x69,0x73,0x69,0x67,0x6E,0x2E,0x63,0x6F,0x6D,0x2F,0x63,0x70,0x73,0x30,0x1D,0x06,
0x03,0x55,0x1D,0x0E,0x04,0x16,0x04,0x14,0x7F,0xD3,0x65,0xA7,0xC2,0xDD,0xEC,0xBB,
0xF0,0x30,0x09,0xF3,0x43,0x39,0xFA,0x02,0xAF,0x33,0x31,0x33,0x30,0x6D,0x06,0x08,
0x2B,0x06,0x01,0x05,0x05,0x07,0x01,0x0C,0x04,0x61,0x30,0x5F,0xA1,0x5D,0xA0,0x5B,
0x30,0x59,0x30,0x57,0x30,0x55,0x16,0x09,0x69,0x6D,0x61,0x67,0x65,0x2F,0x67,0x69,
0x66,0x30,0x21,0x30,0x1F,0x30,0x07,0x06,0x05,0x2B,0x0E,0x03,0x02,0x1A,0x04,0x14,
0x8F,0xE5,0xD3,0x1A,0x86,0xAC,0x8D,0x8E,0x6B,0xC3,0xCF,0x80,0x6A,0xD4,0x48,0x18,
0x2C,0x7B,0x19,0x2E,0x30,0x25,0x16,0x23,0x68,0x74,0x74,0x70,0x3A,0x2F,0x2F,0x6C,
0x6F,0x67,0x6F,0x2E,0x76,0x65,0x72,0x69,0x73,0x69,0x67,0x6E,0x2E,0x63,0x6F,0x6D,
0x2F,0x76,0x73,0x6C,0x6F,0x67,0x6F,0x2E,0x67,0x69,0x66,0x30,0x34,0x06,0x08,0x2B,
0x06,0x01,0x05,0x05,0x07,0x01,0x01,0x04,0x28,0x30,0x26,0x30,0x24,0x06,0x08,0x2B,
0x06,0x01,0x05,0x05,0x07,0x30,0x01,0x86,0x18,0x68,0x74,0x74,0x70,0x3A,0x2F,0x2F,
0x6F,0x63,0x73,0x70,0x2E,0x76,0x65,0x72,0x69,0x73,0x69,0x67,0x6E,0x2E,0x63,0x6F,
0x6D,0x30,0x3E,0x06,0x03,0x55,0x1D,0x25,0x04,0x37,0x30,0x35,0x06,0x08,0x2B,0x06,
0x01,0x05,0x05,0x07,0x03,0x01,0x06,0x08,0x2B,0x06,0x01,0x05,0x05,0x07,0x03,0x02,
0x06,0x08,0x2B,0x06,0x01,0x05,0x05,0x07,0x03,0x03,0x06,0x09,0x60,0x86,0x48,0x01,
0x86,0xF8,0x42,0x04,0x01,0x06,0x0A,0x60,0x86,0x48,0x01,0x86,0xF8,0x45,0x01,0x08,
0x01,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x05,0x05,0x00,
0x03,0x81,0x81,0x00,0x13,0x02,0xDD,0xF8,0xE8,0x86,0x00,0xF2,0x5A,0xF8,0xF8,0x20,
0x0C,0x59,0x88,0x62,0x07,0xCE,0xCE,0xF7,0x4E,0xF9,0xBB,0x59,0xA1,0x98,0xE5,0xE1,
0x38,0xDD,0x4E,0xBC,0x66,0x18,0xD3,0xAD,0xEB,0x18,0xF2,0x0D,0xC9,0x6D,0x3E,0x4A,
0x94,0x20,0xC3,0x3C,0xBA,0xBD,0x65,0x54,0xC6,0xAF,0x44,0xB3,0x10,0xAD,0x2C,0x6B,
0x3E,0xAB,0xD7,0x07,0xB6,0xB8,0x81,0x63,0xC5,0xF9,0x5E,0x2E,0xE5,0x2A,0x67,0xCE,
0xCD,0x33,0x0C,0x2A,0xD7,0x89,0x56,0x03,0x23,0x1F,0xB3,0xBE,0xE8,0x3A,0x08,0x59,
0xB4,0xEC,0x45,0x35,0xF7,0x8A,0x5B,0xFF,0x66,0xCF,0x50,0xAF,0xC6,0x6D,0x57,0x8D,
0x19,0x78,0xB7,0xB9,0xA2,0xD1,0x57,0xEA,0x1F,0x9A,0x4B,0xAF,0xBA,0xC9,0x8E,0x12,
0x7E,0xC6,0xBD,0xFF,
};
#endif

/* SHA1 Fingerprint=97:81:79:50:D8:1C:96:70:CC:34:D8:09:CF:79:44:31:36:7E:F4:74 */
/* subject:/C=US/O=GTE Corporation/OU=GTE CyberTrust Solutions, Inc./CN=GTE CyberTrust Global Root */
/* issuer :/C=US/O=GTE Corporation/OU=GTE CyberTrust Solutions, Inc./CN=GTE CyberTrust Global Root */
unsigned char _GTECyberTrustGlobalRootCA[606]={
0x30,0x82,0x02,0x5A,0x30,0x82,0x01,0xC3,0x02,0x02,0x01,0xA5,0x30,0x0D,0x06,0x09,
0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x04,0x05,0x00,0x30,0x75,0x31,0x0B,0x30,
0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x18,0x30,0x16,0x06,0x03,
0x55,0x04,0x0A,0x13,0x0F,0x47,0x54,0x45,0x20,0x43,0x6F,0x72,0x70,0x6F,0x72,0x61,
0x74,0x69,0x6F,0x6E,0x31,0x27,0x30,0x25,0x06,0x03,0x55,0x04,0x0B,0x13,0x1E,0x47,
0x54,0x45,0x20,0x43,0x79,0x62,0x65,0x72,0x54,0x72,0x75,0x73,0x74,0x20,0x53,0x6F,
0x6C,0x75,0x74,0x69,0x6F,0x6E,0x73,0x2C,0x20,0x49,0x6E,0x63,0x2E,0x31,0x23,0x30,
0x21,0x06,0x03,0x55,0x04,0x03,0x13,0x1A,0x47,0x54,0x45,0x20,0x43,0x79,0x62,0x65,
0x72,0x54,0x72,0x75,0x73,0x74,0x20,0x47,0x6C,0x6F,0x62,0x61,0x6C,0x20,0x52,0x6F,
0x6F,0x74,0x30,0x1E,0x17,0x0D,0x39,0x38,0x30,0x38,0x31,0x33,0x30,0x30,0x32,0x39,
0x30,0x30,0x5A,0x17,0x0D,0x31,0x38,0x30,0x38,0x31,0x33,0x32,0x33,0x35,0x39,0x30,
0x30,0x5A,0x30,0x75,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,
0x53,0x31,0x18,0x30,0x16,0x06,0x03,0x55,0x04,0x0A,0x13,0x0F,0x47,0x54,0x45,0x20,
0x43,0x6F,0x72,0x70,0x6F,0x72,0x61,0x74,0x69,0x6F,0x6E,0x31,0x27,0x30,0x25,0x06,
0x03,0x55,0x04,0x0B,0x13,0x1E,0x47,0x54,0x45,0x20,0x43,0x79,0x62,0x65,0x72,0x54,
0x72,0x75,0x73,0x74,0x20,0x53,0x6F,0x6C,0x75,0x74,0x69,0x6F,0x6E,0x73,0x2C,0x20,
0x49,0x6E,0x63,0x2E,0x31,0x23,0x30,0x21,0x06,0x03,0x55,0x04,0x03,0x13,0x1A,0x47,
0x54,0x45,0x20,0x43,0x79,0x62,0x65,0x72,0x54,0x72,0x75,0x73,0x74,0x20,0x47,0x6C,
0x6F,0x62,0x61,0x6C,0x20,0x52,0x6F,0x6F,0x74,0x30,0x81,0x9F,0x30,0x0D,0x06,0x09,
0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x01,0x05,0x00,0x03,0x81,0x8D,0x00,0x30,
0x81,0x89,0x02,0x81,0x81,0x00,0x95,0x0F,0xA0,0xB6,0xF0,0x50,0x9C,0xE8,0x7A,0xC7,
0x88,0xCD,0xDD,0x17,0x0E,0x2E,0xB0,0x94,0xD0,0x1B,0x3D,0x0E,0xF6,0x94,0xC0,0x8A,
0x94,0xC7,0x06,0xC8,0x90,0x97,0xC8,0xB8,0x64,0x1A,0x7A,0x7E,0x6C,0x3C,0x53,0xE1,
0x37,0x28,0x73,0x60,0x7F,0xB2,0x97,0x53,0x07,0x9F,0x53,0xF9,0x6D,0x58,0x94,0xD2,
0xAF,0x8D,0x6D,0x88,0x67,0x80,0xE6,0xED,0xB2,0x95,0xCF,0x72,0x31,0xCA,0xA5,0x1C,
0x72,0xBA,0x5C,0x02,0xE7,0x64,0x42,0xE7,0xF9,0xA9,0x2C,0xD6,0x3A,0x0D,0xAC,0x8D,
0x42,0xAA,0x24,0x01,0x39,0xE6,0x9C,0x3F,0x01,0x85,0x57,0x0D,0x58,0x87,0x45,0xF8,
0xD3,0x85,0xAA,0x93,0x69,0x26,0x85,0x70,0x48,0x80,0x3F,0x12,0x15,0xC7,0x79,0xB4,
0x1F,0x05,0x2F,0x3B,0x62,0x99,0x02,0x03,0x01,0x00,0x01,0x30,0x0D,0x06,0x09,0x2A,
0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x04,0x05,0x00,0x03,0x81,0x81,0x00,0x6D,0xEB,
0x1B,0x09,0xE9,0x5E,0xD9,0x51,0xDB,0x67,0x22,0x61,0xA4,0x2A,0x3C,0x48,0x77,0xE3,
0xA0,0x7C,0xA6,0xDE,0x73,0xA2,0x14,0x03,0x85,0x3D,0xFB,0xAB,0x0E,0x30,0xC5,0x83,
0x16,0x33,0x81,0x13,0x08,0x9E,0x7B,0x34,0x4E,0xDF,0x40,0xC8,0x74,0xD7,0xB9,0x7D,
0xDC,0xF4,0x76,0x55,0x7D,0x9B,0x63,0x54,0x18,0xE9,0xF0,0xEA,0xF3,0x5C,0xB1,0xD9,
0x8B,0x42,0x1E,0xB9,0xC0,0x95,0x4E,0xBA,0xFA,0xD5,0xE2,0x7C,0xF5,0x68,0x61,0xBF,
0x8E,0xEC,0x05,0x97,0x5F,0x5B,0xB0,0xD7,0xA3,0x85,0x34,0xC4,0x24,0xA7,0x0D,0x0F,
0x95,0x93,0xEF,0xCB,0x94,0xD8,0x9E,0x1F,0x9D,0x5C,0x85,0x6D,0xC7,0xAA,0xAE,0x4F,
0x1F,0x22,0xB5,0xCD,0x95,0xAD,0xBA,0xA7,0xCC,0xF9,0xAB,0x0B,0x7A,0x7F,
};

/* SHA1 Fingerprint=A1:DB:63:93:91:6F:17:E4:18:55:09:40:04:15:C7:02:40:B0:AE:6B */
/* subject:/C=US/O=VeriSign, Inc./OU=Class 3 Public Primary Certification Authority */
/* issuer :/C=US/O=VeriSign, Inc./OU=Class 3 Public Primary Certification Authority */
unsigned char _VeriSignClass3CA[576]={
0x30,0x82,0x02,0x3C,0x30,0x82,0x01,0xA5,0x02,0x10,0x3C,0x91,0x31,0xCB,0x1F,0xF6,
0xD0,0x1B,0x0E,0x9A,0xB8,0xD0,0x44,0xBF,0x12,0xBE,0x30,0x0D,0x06,0x09,0x2A,0x86,
0x48,0x86,0xF7,0x0D,0x01,0x01,0x05,0x05,0x00,0x30,0x5F,0x31,0x0B,0x30,0x09,0x06,
0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x17,0x30,0x15,0x06,0x03,0x55,0x04,
0x0A,0x13,0x0E,0x56,0x65,0x72,0x69,0x53,0x69,0x67,0x6E,0x2C,0x20,0x49,0x6E,0x63,
0x2E,0x31,0x37,0x30,0x35,0x06,0x03,0x55,0x04,0x0B,0x13,0x2E,0x43,0x6C,0x61,0x73,
0x73,0x20,0x33,0x20,0x50,0x75,0x62,0x6C,0x69,0x63,0x20,0x50,0x72,0x69,0x6D,0x61,
0x72,0x79,0x20,0x43,0x65,0x72,0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x69,0x6F,0x6E,
0x20,0x41,0x75,0x74,0x68,0x6F,0x72,0x69,0x74,0x79,0x30,0x1E,0x17,0x0D,0x39,0x36,
0x30,0x31,0x32,0x39,0x30,0x30,0x30,0x30,0x30,0x30,0x5A,0x17,0x0D,0x32,0x38,0x30,
0x38,0x30,0x32,0x32,0x33,0x35,0x39,0x35,0x39,0x5A,0x30,0x5F,0x31,0x0B,0x30,0x09,
0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x17,0x30,0x15,0x06,0x03,0x55,
0x04,0x0A,0x13,0x0E,0x56,0x65,0x72,0x69,0x53,0x69,0x67,0x6E,0x2C,0x20,0x49,0x6E,
0x63,0x2E,0x31,0x37,0x30,0x35,0x06,0x03,0x55,0x04,0x0B,0x13,0x2E,0x43,0x6C,0x61,
0x73,0x73,0x20,0x33,0x20,0x50,0x75,0x62,0x6C,0x69,0x63,0x20,0x50,0x72,0x69,0x6D,
0x61,0x72,0x79,0x20,0x43,0x65,0x72,0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x69,0x6F,
0x6E,0x20,0x41,0x75,0x74,0x68,0x6F,0x72,0x69,0x74,0x79,0x30,0x81,0x9F,0x30,0x0D,
0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x01,0x05,0x00,0x03,0x81,0x8D,
0x00,0x30,0x81,0x89,0x02,0x81,0x81,0x00,0xC9,0x5C,0x59,0x9E,0xF2,0x1B,0x8A,0x01,
0x14,0xB4,0x10,0xDF,0x04,0x40,0xDB,0xE3,0x57,0xAF,0x6A,0x45,0x40,0x8F,0x84,0x0C,
0x0B,0xD1,0x33,0xD9,0xD9,0x11,0xCF,0xEE,0x02,0x58,0x1F,0x25,0xF7,0x2A,0xA8,0x44,
0x05,0xAA,0xEC,0x03,0x1F,0x78,0x7F,0x9E,0x93,0xB9,0x9A,0x00,0xAA,0x23,0x7D,0xD6,
0xAC,0x85,0xA2,0x63,0x45,0xC7,0x72,0x27,0xCC,0xF4,0x4C,0xC6,0x75,0x71,0xD2,0x39,
0xEF,0x4F,0x42,0xF0,0x75,0xDF,0x0A,0x90,0xC6,0x8E,0x20,0x6F,0x98,0x0F,0xF8,0xAC,
0x23,0x5F,0x70,0x29,0x36,0xA4,0xC9,0x86,0xE7,0xB1,0x9A,0x20,0xCB,0x53,0xA5,0x85,
0xE7,0x3D,0xBE,0x7D,0x9A,0xFE,0x24,0x45,0x33,0xDC,0x76,0x15,0xED,0x0F,0xA2,0x71,
0x64,0x4C,0x65,0x2E,0x81,0x68,0x45,0xA7,0x02,0x03,0x01,0x00,0x01,0x30,0x0D,0x06,
0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x05,0x05,0x00,0x03,0x81,0x81,0x00,
0x10,0x72,0x52,0xA9,0x05,0x14,0x19,0x32,0x08,0x41,0xF0,0xC5,0x6B,0x0A,0xCC,0x7E,
0x0F,0x21,0x19,0xCD,0xE4,0x67,0xDC,0x5F,0xA9,0x1B,0xE6,0xCA,0xE8,0x73,0x9D,0x22,
0xD8,0x98,0x6E,0x73,0x03,0x61,0x91,0xC5,0x7C,0xB0,0x45,0x40,0x6E,0x44,0x9D,0x8D,
0xB0,0xB1,0x96,0x74,0x61,0x2D,0x0D,0xA9,0x45,0xD2,0xA4,0x92,0x2A,0xD6,0x9A,0x75,
0x97,0x6E,0x3F,0x53,0xFD,0x45,0x99,0x60,0x1D,0xA8,0x2B,0x4C,0xF9,0x5E,0xA7,0x09,
0xD8,0x75,0x30,0xD7,0xD2,0x65,0x60,0x3D,0x67,0xD6,0x48,0x55,0x75,0x69,0x3F,0x91,
0xF5,0x48,0x0B,0x47,0x69,0x22,0x69,0x82,0x96,0xBE,0xC9,0xC8,0x38,0x86,0x4A,0x7A,
0x2C,0x73,0x19,0x48,0x69,0x4E,0x6B,0x7C,0x65,0xBF,0x0F,0xFC,0x70,0xCE,0x88,0x90,
};


#endif /* _SEC_TRUST_SETTINGS_CERTIFICATES_H_ */
