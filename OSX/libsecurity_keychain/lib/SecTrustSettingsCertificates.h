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

/* SHA1 Fingerprint=D2:32:09:AD:23:D3:14:23:21:74:E4:0D:7F:9D:62:13:97:86:63:3A */
/* subject:/C=US/O=Equifax/OU=Equifax Secure Certificate Authority */
/* issuer :/C=US/O=Equifax/OU=Equifax Secure Certificate Authority */
unsigned char _EquifaxSecureCA[804]={
0x30,0x82,0x03,0x20,0x30,0x82,0x02,0x89,0xA0,0x03,0x02,0x01,0x02,0x02,0x04,0x35,
0xDE,0xF4,0xCF,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x05,
0x05,0x00,0x30,0x4E,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,
0x53,0x31,0x10,0x30,0x0E,0x06,0x03,0x55,0x04,0x0A,0x13,0x07,0x45,0x71,0x75,0x69,
0x66,0x61,0x78,0x31,0x2D,0x30,0x2B,0x06,0x03,0x55,0x04,0x0B,0x13,0x24,0x45,0x71,
0x75,0x69,0x66,0x61,0x78,0x20,0x53,0x65,0x63,0x75,0x72,0x65,0x20,0x43,0x65,0x72,
0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x65,0x20,0x41,0x75,0x74,0x68,0x6F,0x72,0x69,
0x74,0x79,0x30,0x1E,0x17,0x0D,0x39,0x38,0x30,0x38,0x32,0x32,0x31,0x36,0x34,0x31,
0x35,0x31,0x5A,0x17,0x0D,0x31,0x38,0x30,0x38,0x32,0x32,0x31,0x36,0x34,0x31,0x35,
0x31,0x5A,0x30,0x4E,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,
0x53,0x31,0x10,0x30,0x0E,0x06,0x03,0x55,0x04,0x0A,0x13,0x07,0x45,0x71,0x75,0x69,
0x66,0x61,0x78,0x31,0x2D,0x30,0x2B,0x06,0x03,0x55,0x04,0x0B,0x13,0x24,0x45,0x71,
0x75,0x69,0x66,0x61,0x78,0x20,0x53,0x65,0x63,0x75,0x72,0x65,0x20,0x43,0x65,0x72,
0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x65,0x20,0x41,0x75,0x74,0x68,0x6F,0x72,0x69,
0x74,0x79,0x30,0x81,0x9F,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,
0x01,0x01,0x05,0x00,0x03,0x81,0x8D,0x00,0x30,0x81,0x89,0x02,0x81,0x81,0x00,0xC1,
0x5D,0xB1,0x58,0x67,0x08,0x62,0xEE,0xA0,0x9A,0x2D,0x1F,0x08,0x6D,0x91,0x14,0x68,
0x98,0x0A,0x1E,0xFE,0xDA,0x04,0x6F,0x13,0x84,0x62,0x21,0xC3,0xD1,0x7C,0xCE,0x9F,
0x05,0xE0,0xB8,0x01,0xF0,0x4E,0x34,0xEC,0xE2,0x8A,0x95,0x04,0x64,0xAC,0xF1,0x6B,
0x53,0x5F,0x05,0xB3,0xCB,0x67,0x80,0xBF,0x42,0x02,0x8E,0xFE,0xDD,0x01,0x09,0xEC,
0xE1,0x00,0x14,0x4F,0xFC,0xFB,0xF0,0x0C,0xDD,0x43,0xBA,0x5B,0x2B,0xE1,0x1F,0x80,
0x70,0x99,0x15,0x57,0x93,0x16,0xF1,0x0F,0x97,0x6A,0xB7,0xC2,0x68,0x23,0x1C,0xCC,
0x4D,0x59,0x30,0xAC,0x51,0x1E,0x3B,0xAF,0x2B,0xD6,0xEE,0x63,0x45,0x7B,0xC5,0xD9,
0x5F,0x50,0xD2,0xE3,0x50,0x0F,0x3A,0x88,0xE7,0xBF,0x14,0xFD,0xE0,0xC7,0xB9,0x02,
0x03,0x01,0x00,0x01,0xA3,0x82,0x01,0x09,0x30,0x82,0x01,0x05,0x30,0x70,0x06,0x03,
0x55,0x1D,0x1F,0x04,0x69,0x30,0x67,0x30,0x65,0xA0,0x63,0xA0,0x61,0xA4,0x5F,0x30,
0x5D,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x10,
0x30,0x0E,0x06,0x03,0x55,0x04,0x0A,0x13,0x07,0x45,0x71,0x75,0x69,0x66,0x61,0x78,
0x31,0x2D,0x30,0x2B,0x06,0x03,0x55,0x04,0x0B,0x13,0x24,0x45,0x71,0x75,0x69,0x66,
0x61,0x78,0x20,0x53,0x65,0x63,0x75,0x72,0x65,0x20,0x43,0x65,0x72,0x74,0x69,0x66,
0x69,0x63,0x61,0x74,0x65,0x20,0x41,0x75,0x74,0x68,0x6F,0x72,0x69,0x74,0x79,0x31,
0x0D,0x30,0x0B,0x06,0x03,0x55,0x04,0x03,0x13,0x04,0x43,0x52,0x4C,0x31,0x30,0x1A,
0x06,0x03,0x55,0x1D,0x10,0x04,0x13,0x30,0x11,0x81,0x0F,0x32,0x30,0x31,0x38,0x30,
0x38,0x32,0x32,0x31,0x36,0x34,0x31,0x35,0x31,0x5A,0x30,0x0B,0x06,0x03,0x55,0x1D,
0x0F,0x04,0x04,0x03,0x02,0x01,0x06,0x30,0x1F,0x06,0x03,0x55,0x1D,0x23,0x04,0x18,
0x30,0x16,0x80,0x14,0x48,0xE6,0x68,0xF9,0x2B,0xD2,0xB2,0x95,0xD7,0x47,0xD8,0x23,
0x20,0x10,0x4F,0x33,0x98,0x90,0x9F,0xD4,0x30,0x1D,0x06,0x03,0x55,0x1D,0x0E,0x04,
0x16,0x04,0x14,0x48,0xE6,0x68,0xF9,0x2B,0xD2,0xB2,0x95,0xD7,0x47,0xD8,0x23,0x20,
0x10,0x4F,0x33,0x98,0x90,0x9F,0xD4,0x30,0x0C,0x06,0x03,0x55,0x1D,0x13,0x04,0x05,
0x30,0x03,0x01,0x01,0xFF,0x30,0x1A,0x06,0x09,0x2A,0x86,0x48,0x86,0xF6,0x7D,0x07,
0x41,0x00,0x04,0x0D,0x30,0x0B,0x1B,0x05,0x56,0x33,0x2E,0x30,0x63,0x03,0x02,0x06,
0xC0,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x05,0x05,0x00,
0x03,0x81,0x81,0x00,0x58,0xCE,0x29,0xEA,0xFC,0xF7,0xDE,0xB5,0xCE,0x02,0xB9,0x17,
0xB5,0x85,0xD1,0xB9,0xE3,0xE0,0x95,0xCC,0x25,0x31,0x0D,0x00,0xA6,0x92,0x6E,0x7F,
0xB6,0x92,0x63,0x9E,0x50,0x95,0xD1,0x9A,0x6F,0xE4,0x11,0xDE,0x63,0x85,0x6E,0x98,
0xEE,0xA8,0xFF,0x5A,0xC8,0xD3,0x55,0xB2,0x66,0x71,0x57,0xDE,0xC0,0x21,0xEB,0x3D,
0x2A,0xA7,0x23,0x49,0x01,0x04,0x86,0x42,0x7B,0xFC,0xEE,0x7F,0xA2,0x16,0x52,0xB5,
0x67,0x67,0xD3,0x40,0xDB,0x3B,0x26,0x58,0xB2,0x28,0x77,0x3D,0xAE,0x14,0x77,0x61,
0xD6,0xFA,0x2A,0x66,0x27,0xA0,0x0D,0xFA,0xA7,0x73,0x5C,0xEA,0x70,0xF1,0x94,0x21,
0x65,0x44,0x5F,0xFA,0xFC,0xEF,0x29,0x68,0xA9,0xA2,0x87,0x79,0xEF,0x79,0xEF,0x4F,
0xAC,0x07,0x77,0x38,
};

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

/* SHA1 Fingerprint=E0:AB:05:94:20:72:54:93:05:60:62:02:36:70:F7:CD:2E:FC:66:66 */
/* subject:/C=ZA/ST=Western Cape/L=Cape Town/O=Thawte Consulting cc/OU=Certification Services Division/CN=Thawte Premium Server CA/emailAddress=premium-server@thawte.com */
/* issuer :/C=ZA/ST=Western Cape/L=Cape Town/O=Thawte Consulting cc/OU=Certification Services Division/CN=Thawte Premium Server CA/emailAddress=premium-server@thawte.com */
unsigned char _ThawtePremiumServerCA[826]={
0x30,0x82,0x03,0x36,0x30,0x82,0x02,0x9F,0xA0,0x03,0x02,0x01,0x02,0x02,0x10,0x36,
0x12,0x22,0x96,0xC5,0xE3,0x38,0xA5,0x20,0xA1,0xD2,0x5F,0x4C,0xD7,0x09,0x54,0x30,
0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x05,0x05,0x00,0x30,0x81,
0xCE,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x5A,0x41,0x31,0x15,
0x30,0x13,0x06,0x03,0x55,0x04,0x08,0x13,0x0C,0x57,0x65,0x73,0x74,0x65,0x72,0x6E,
0x20,0x43,0x61,0x70,0x65,0x31,0x12,0x30,0x10,0x06,0x03,0x55,0x04,0x07,0x13,0x09,
0x43,0x61,0x70,0x65,0x20,0x54,0x6F,0x77,0x6E,0x31,0x1D,0x30,0x1B,0x06,0x03,0x55,
0x04,0x0A,0x13,0x14,0x54,0x68,0x61,0x77,0x74,0x65,0x20,0x43,0x6F,0x6E,0x73,0x75,
0x6C,0x74,0x69,0x6E,0x67,0x20,0x63,0x63,0x31,0x28,0x30,0x26,0x06,0x03,0x55,0x04,
0x0B,0x13,0x1F,0x43,0x65,0x72,0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x69,0x6F,0x6E,
0x20,0x53,0x65,0x72,0x76,0x69,0x63,0x65,0x73,0x20,0x44,0x69,0x76,0x69,0x73,0x69,
0x6F,0x6E,0x31,0x21,0x30,0x1F,0x06,0x03,0x55,0x04,0x03,0x13,0x18,0x54,0x68,0x61,
0x77,0x74,0x65,0x20,0x50,0x72,0x65,0x6D,0x69,0x75,0x6D,0x20,0x53,0x65,0x72,0x76,
0x65,0x72,0x20,0x43,0x41,0x31,0x28,0x30,0x26,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,
0x0D,0x01,0x09,0x01,0x16,0x19,0x70,0x72,0x65,0x6D,0x69,0x75,0x6D,0x2D,0x73,0x65,
0x72,0x76,0x65,0x72,0x40,0x74,0x68,0x61,0x77,0x74,0x65,0x2E,0x63,0x6F,0x6D,0x30,
0x1E,0x17,0x0D,0x39,0x36,0x30,0x38,0x30,0x31,0x30,0x30,0x30,0x30,0x30,0x30,0x5A,
0x17,0x0D,0x32,0x31,0x30,0x31,0x30,0x31,0x32,0x33,0x35,0x39,0x35,0x39,0x5A,0x30,
0x81,0xCE,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x5A,0x41,0x31,
0x15,0x30,0x13,0x06,0x03,0x55,0x04,0x08,0x13,0x0C,0x57,0x65,0x73,0x74,0x65,0x72,
0x6E,0x20,0x43,0x61,0x70,0x65,0x31,0x12,0x30,0x10,0x06,0x03,0x55,0x04,0x07,0x13,
0x09,0x43,0x61,0x70,0x65,0x20,0x54,0x6F,0x77,0x6E,0x31,0x1D,0x30,0x1B,0x06,0x03,
0x55,0x04,0x0A,0x13,0x14,0x54,0x68,0x61,0x77,0x74,0x65,0x20,0x43,0x6F,0x6E,0x73,
0x75,0x6C,0x74,0x69,0x6E,0x67,0x20,0x63,0x63,0x31,0x28,0x30,0x26,0x06,0x03,0x55,
0x04,0x0B,0x13,0x1F,0x43,0x65,0x72,0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x69,0x6F,
0x6E,0x20,0x53,0x65,0x72,0x76,0x69,0x63,0x65,0x73,0x20,0x44,0x69,0x76,0x69,0x73,
0x69,0x6F,0x6E,0x31,0x21,0x30,0x1F,0x06,0x03,0x55,0x04,0x03,0x13,0x18,0x54,0x68,
0x61,0x77,0x74,0x65,0x20,0x50,0x72,0x65,0x6D,0x69,0x75,0x6D,0x20,0x53,0x65,0x72,
0x76,0x65,0x72,0x20,0x43,0x41,0x31,0x28,0x30,0x26,0x06,0x09,0x2A,0x86,0x48,0x86,
0xF7,0x0D,0x01,0x09,0x01,0x16,0x19,0x70,0x72,0x65,0x6D,0x69,0x75,0x6D,0x2D,0x73,
0x65,0x72,0x76,0x65,0x72,0x40,0x74,0x68,0x61,0x77,0x74,0x65,0x2E,0x63,0x6F,0x6D,
0x30,0x81,0x9F,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x01,
0x05,0x00,0x03,0x81,0x8D,0x00,0x30,0x81,0x89,0x02,0x81,0x81,0x00,0xD2,0x36,0x36,
0x6A,0x8B,0xD7,0xC2,0x5B,0x9E,0xDA,0x81,0x41,0x62,0x8F,0x38,0xEE,0x49,0x04,0x55,
0xD6,0xD0,0xEF,0x1C,0x1B,0x95,0x16,0x47,0xEF,0x18,0x48,0x35,0x3A,0x52,0xF4,0x2B,
0x6A,0x06,0x8F,0x3B,0x2F,0xEA,0x56,0xE3,0xAF,0x86,0x8D,0x9E,0x17,0xF7,0x9E,0xB4,
0x65,0x75,0x02,0x4D,0xEF,0xCB,0x09,0xA2,0x21,0x51,0xD8,0x9B,0xD0,0x67,0xD0,0xBA,
0x0D,0x92,0x06,0x14,0x73,0xD4,0x93,0xCB,0x97,0x2A,0x00,0x9C,0x5C,0x4E,0x0C,0xBC,
0xFA,0x15,0x52,0xFC,0xF2,0x44,0x6E,0xDA,0x11,0x4A,0x6E,0x08,0x9F,0x2F,0x2D,0xE3,
0xF9,0xAA,0x3A,0x86,0x73,0xB6,0x46,0x53,0x58,0xC8,0x89,0x05,0xBD,0x83,0x11,0xB8,
0x73,0x3F,0xAA,0x07,0x8D,0xF4,0x42,0x4D,0xE7,0x40,0x9D,0x1C,0x37,0x02,0x03,0x01,
0x00,0x01,0xA3,0x13,0x30,0x11,0x30,0x0F,0x06,0x03,0x55,0x1D,0x13,0x01,0x01,0xFF,
0x04,0x05,0x30,0x03,0x01,0x01,0xFF,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,
0x0D,0x01,0x01,0x05,0x05,0x00,0x03,0x81,0x81,0x00,0x65,0x90,0xAC,0x88,0x0F,0x56,
0xD9,0xE6,0x30,0x34,0xD4,0x26,0xC7,0xD0,0x50,0xF1,0x92,0xDE,0x6B,0xD4,0x39,0x88,
0x09,0x22,0xC6,0xA6,0x63,0x83,0x03,0xF7,0x99,0x77,0xD8,0xB2,0xE5,0x18,0xB8,0x5D,
0x63,0xF3,0xD4,0x73,0xFB,0x6C,0x9C,0x99,0x78,0xF1,0x4B,0x78,0x7D,0x19,0x24,0xC3,
0x2B,0x02,0x84,0xF8,0xBC,0x22,0xD9,0x8A,0x22,0xD7,0xA0,0xFC,0x71,0xEC,0x91,0x87,
0x20,0xF1,0xB8,0xEC,0xB1,0xE5,0x55,0x80,0xAC,0x3D,0x52,0xC8,0x39,0x0E,0xC2,0xF0,
0xC0,0x05,0x4F,0xD6,0x82,0x75,0x8C,0xBD,0x5F,0xD2,0xDC,0x76,0x9A,0x05,0x12,0xC9,
0xAF,0x72,0xC3,0xDC,0x25,0x7E,0xA4,0x4D,0x8E,0x17,0xA5,0xE0,0x87,0x7F,0xE1,0x9A,
0x5A,0xE1,0x60,0xDC,0x64,0x23,0x3C,0x42,0x2E,0x4D,
};

/* SHA1 Fingerprint=9F:AD:91:A6:CE:6A:C6:C5:00:47:C4:4E:C9:D4:A5:0D:92:D8:49:79 */
/* subject:/C=ZA/ST=Western Cape/L=Cape Town/O=Thawte Consulting cc/OU=Certification Services Division/CN=Thawte Server CA/emailAddress=server-certs@thawte.com */
/* issuer :/C=ZA/ST=Western Cape/L=Cape Town/O=Thawte Consulting cc/OU=Certification Services Division/CN=Thawte Server CA/emailAddress=server-certs@thawte.com */
unsigned char _ThawteServerCA[806]={
0x30,0x82,0x03,0x22,0x30,0x82,0x02,0x8B,0xA0,0x03,0x02,0x01,0x02,0x02,0x10,0x34,
0xA4,0xFF,0xF6,0x30,0xAF,0x4C,0xA5,0x3C,0x33,0x17,0x42,0xA1,0x94,0x66,0x75,0x30,
0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x05,0x05,0x00,0x30,0x81,
0xC4,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x5A,0x41,0x31,0x15,
0x30,0x13,0x06,0x03,0x55,0x04,0x08,0x13,0x0C,0x57,0x65,0x73,0x74,0x65,0x72,0x6E,
0x20,0x43,0x61,0x70,0x65,0x31,0x12,0x30,0x10,0x06,0x03,0x55,0x04,0x07,0x13,0x09,
0x43,0x61,0x70,0x65,0x20,0x54,0x6F,0x77,0x6E,0x31,0x1D,0x30,0x1B,0x06,0x03,0x55,
0x04,0x0A,0x13,0x14,0x54,0x68,0x61,0x77,0x74,0x65,0x20,0x43,0x6F,0x6E,0x73,0x75,
0x6C,0x74,0x69,0x6E,0x67,0x20,0x63,0x63,0x31,0x28,0x30,0x26,0x06,0x03,0x55,0x04,
0x0B,0x13,0x1F,0x43,0x65,0x72,0x74,0x69,0x66,0x69,0x63,0x61,0x74,0x69,0x6F,0x6E,
0x20,0x53,0x65,0x72,0x76,0x69,0x63,0x65,0x73,0x20,0x44,0x69,0x76,0x69,0x73,0x69,
0x6F,0x6E,0x31,0x19,0x30,0x17,0x06,0x03,0x55,0x04,0x03,0x13,0x10,0x54,0x68,0x61,
0x77,0x74,0x65,0x20,0x53,0x65,0x72,0x76,0x65,0x72,0x20,0x43,0x41,0x31,0x26,0x30,
0x24,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x09,0x01,0x16,0x17,0x73,0x65,
0x72,0x76,0x65,0x72,0x2D,0x63,0x65,0x72,0x74,0x73,0x40,0x74,0x68,0x61,0x77,0x74,
0x65,0x2E,0x63,0x6F,0x6D,0x30,0x1E,0x17,0x0D,0x39,0x36,0x30,0x38,0x30,0x31,0x30,
0x30,0x30,0x30,0x30,0x30,0x5A,0x17,0x0D,0x32,0x31,0x30,0x31,0x30,0x31,0x32,0x33,
0x35,0x39,0x35,0x39,0x5A,0x30,0x81,0xC4,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,
0x06,0x13,0x02,0x5A,0x41,0x31,0x15,0x30,0x13,0x06,0x03,0x55,0x04,0x08,0x13,0x0C,
0x57,0x65,0x73,0x74,0x65,0x72,0x6E,0x20,0x43,0x61,0x70,0x65,0x31,0x12,0x30,0x10,
0x06,0x03,0x55,0x04,0x07,0x13,0x09,0x43,0x61,0x70,0x65,0x20,0x54,0x6F,0x77,0x6E,
0x31,0x1D,0x30,0x1B,0x06,0x03,0x55,0x04,0x0A,0x13,0x14,0x54,0x68,0x61,0x77,0x74,
0x65,0x20,0x43,0x6F,0x6E,0x73,0x75,0x6C,0x74,0x69,0x6E,0x67,0x20,0x63,0x63,0x31,
0x28,0x30,0x26,0x06,0x03,0x55,0x04,0x0B,0x13,0x1F,0x43,0x65,0x72,0x74,0x69,0x66,
0x69,0x63,0x61,0x74,0x69,0x6F,0x6E,0x20,0x53,0x65,0x72,0x76,0x69,0x63,0x65,0x73,
0x20,0x44,0x69,0x76,0x69,0x73,0x69,0x6F,0x6E,0x31,0x19,0x30,0x17,0x06,0x03,0x55,
0x04,0x03,0x13,0x10,0x54,0x68,0x61,0x77,0x74,0x65,0x20,0x53,0x65,0x72,0x76,0x65,
0x72,0x20,0x43,0x41,0x31,0x26,0x30,0x24,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,
0x01,0x09,0x01,0x16,0x17,0x73,0x65,0x72,0x76,0x65,0x72,0x2D,0x63,0x65,0x72,0x74,
0x73,0x40,0x74,0x68,0x61,0x77,0x74,0x65,0x2E,0x63,0x6F,0x6D,0x30,0x81,0x9F,0x30,
0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x01,0x05,0x00,0x03,0x81,
0x8D,0x00,0x30,0x81,0x89,0x02,0x81,0x81,0x00,0xD3,0xA4,0x50,0x6E,0xC8,0xFF,0x56,
0x6B,0xE6,0xCF,0x5D,0xB6,0xEA,0x0C,0x68,0x75,0x47,0xA2,0xAA,0xC2,0xDA,0x84,0x25,
0xFC,0xA8,0xF4,0x47,0x51,0xDA,0x85,0xB5,0x20,0x74,0x94,0x86,0x1E,0x0F,0x75,0xC9,
0xE9,0x08,0x61,0xF5,0x06,0x6D,0x30,0x6E,0x15,0x19,0x02,0xE9,0x52,0xC0,0x62,0xDB,
0x4D,0x99,0x9E,0xE2,0x6A,0x0C,0x44,0x38,0xCD,0xFE,0xBE,0xE3,0x64,0x09,0x70,0xC5,
0xFE,0xB1,0x6B,0x29,0xB6,0x2F,0x49,0xC8,0x3B,0xD4,0x27,0x04,0x25,0x10,0x97,0x2F,
0xE7,0x90,0x6D,0xC0,0x28,0x42,0x99,0xD7,0x4C,0x43,0xDE,0xC3,0xF5,0x21,0x6D,0x54,
0x9F,0x5D,0xC3,0x58,0xE1,0xC0,0xE4,0xD9,0x5B,0xB0,0xB8,0xDC,0xB4,0x7B,0xDF,0x36,
0x3A,0xC2,0xB5,0x66,0x22,0x12,0xD6,0x87,0x0D,0x02,0x03,0x01,0x00,0x01,0xA3,0x13,
0x30,0x11,0x30,0x0F,0x06,0x03,0x55,0x1D,0x13,0x01,0x01,0xFF,0x04,0x05,0x30,0x03,
0x01,0x01,0xFF,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x05,
0x05,0x00,0x03,0x81,0x81,0x00,0xBE,0x40,0x69,0x41,0x6F,0xC6,0xDB,0xC1,0xA7,0xBF,
0x07,0xC0,0x45,0xE4,0xD0,0xB5,0x43,0x1E,0x4C,0x95,0x33,0x35,0xE9,0x5E,0xC2,0x3E,
0x28,0xF6,0xA8,0x0D,0x50,0xD5,0xFF,0xE2,0x0C,0x0F,0xFC,0x50,0x02,0x8E,0xAE,0x91,
0xB9,0xAD,0x34,0x8A,0x8D,0x9F,0x27,0x71,0xAA,0x19,0xCC,0x4B,0xE8,0x04,0xCA,0xD4,
0x17,0x6B,0x12,0x1A,0xD6,0xC6,0x5F,0xD6,0xCD,0x5E,0xFF,0x89,0x76,0xBF,0xD8,0x48,
0xD8,0x59,0xBD,0x08,0x8A,0x89,0x1D,0x57,0xCD,0x45,0x1E,0x52,0xBA,0x12,0x9A,0x84,
0xFA,0x18,0x89,0x5F,0xE8,0xF9,0x30,0x35,0x6A,0x01,0x60,0xB9,0x99,0x80,0x83,0x85,
0x0A,0x6E,0xDA,0xF4,0xC9,0x8F,0x5E,0x73,0x2D,0x31,0x4A,0x63,0xA0,0x74,0xF2,0x1F,
0x8B,0x22,0xD2,0x29,0x3E,0xEB,
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