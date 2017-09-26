/*
 * Copyright (c) 2008-2014 Apple Inc. All Rights Reserved.
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


#include <regressions/test/testmore.h>
#include <Security/SecCMS.h>
#include <Security/SecItem.h>
#include <Security/SecItemPriv.h>
#include <Security/SecPolicyPriv.h>
#include <Security/SecBasePriv.h>
#include <Security/SecCertificatePriv.h>
#include <Security/SecIdentityPriv.h>
#include <Security/SecCertificateRequest.h>
#include <utilities/array_size.h>
#include <utilities/SecCFRelease.h>

#include <stdlib.h>
#include <unistd.h>

int smime_cms_test(int argc, char *const *argv);

/*
   Bag Attributes
friendlyName: uranusLeaf
localKeyID: 46 E0 8A 05 63 4D 17 3F CA A4 AA B6 5A DA CF BA 84 22 7C 23
subject=/CN=uranusLeaf/emailAddress=uranus@uranus.com
issuer=/CN=plutoCA/emailAddress=pluto@pluto.com
 */
static const uint8_t _c1[] = {
    0x30, 0x82, 0x02, 0xe0, 0x30, 0x82, 0x01, 0xc8,
    0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x01, 0x02,
    0x30, 0x0b, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86,
    0xf7, 0x0d, 0x01, 0x01, 0x05, 0x30, 0x32, 0x31,
    0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x03,
    0x0c, 0x07, 0x70, 0x6c, 0x75, 0x74, 0x6f, 0x43,
    0x41, 0x31, 0x1e, 0x30, 0x1c, 0x06, 0x09, 0x2a,
    0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x01,
    0x0c, 0x0f, 0x70, 0x6c, 0x75, 0x74, 0x6f, 0x40,
    0x70, 0x6c, 0x75, 0x74, 0x6f, 0x2e, 0x63, 0x6f,
    0x6d, 0x30, 0x1e, 0x17, 0x0d, 0x30, 0x35, 0x31,
    0x32, 0x31, 0x37, 0x30, 0x30, 0x30, 0x34, 0x32,
    0x35, 0x5a, 0x17, 0x0d, 0x30, 0x36, 0x31, 0x32,
    0x31, 0x37, 0x30, 0x30, 0x30, 0x34, 0x32, 0x35,
    0x5a, 0x30, 0x37, 0x31, 0x13, 0x30, 0x11, 0x06,
    0x03, 0x55, 0x04, 0x03, 0x0c, 0x0a, 0x75, 0x72,
    0x61, 0x6e, 0x75, 0x73, 0x4c, 0x65, 0x61, 0x66,
    0x31, 0x20, 0x30, 0x1e, 0x06, 0x09, 0x2a, 0x86,
    0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x01, 0x0c,
    0x11, 0x75, 0x72, 0x61, 0x6e, 0x75, 0x73, 0x40,
    0x75, 0x72, 0x61, 0x6e, 0x75, 0x73, 0x2e, 0x63,
    0x6f, 0x6d, 0x30, 0x82, 0x01, 0x22, 0x30, 0x0d,
    0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d,
    0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x01,
    0x0f, 0x00, 0x30, 0x82, 0x01, 0x0a, 0x02, 0x82,
    0x01, 0x01, 0x00, 0xa6, 0x82, 0x8e, 0xc6, 0x7e,
    0xc9, 0x8c, 0x99, 0x6f, 0xb0, 0x62, 0x32, 0x35,
    0xe7, 0xdb, 0xff, 0x34, 0x84, 0xdc, 0x72, 0xa8,
    0xef, 0x22, 0x6f, 0x93, 0x63, 0x64, 0x80, 0x80,
    0x5d, 0x50, 0x7e, 0xb4, 0x2e, 0x1b, 0x93, 0x93,
    0x49, 0xca, 0xae, 0xcd, 0x34, 0x44, 0x4b, 0xd7,
    0xfa, 0x9f, 0x3c, 0xfc, 0x9e, 0x65, 0xa9, 0xfb,
    0x5e, 0x5d, 0x18, 0xa3, 0xf8, 0xb0, 0x08, 0xac,
    0x8f, 0xfd, 0x03, 0xcb, 0xbd, 0x7f, 0xa0, 0x2a,
    0xa6, 0xea, 0xca, 0xa3, 0x24, 0xef, 0x7c, 0xc3,
    0xeb, 0x95, 0xcb, 0x90, 0x3f, 0x5e, 0xde, 0x78,
    0xf2, 0x3d, 0x32, 0x72, 0xdb, 0x33, 0x6e, 0x9b,
    0x52, 0x9f, 0x0c, 0x60, 0x4a, 0x24, 0xa1, 0xf6,
    0x3b, 0x80, 0xbd, 0xa1, 0xdc, 0x40, 0x03, 0xe7,
    0xa0, 0x59, 0x1f, 0xdb, 0xb4, 0xed, 0x57, 0xdc,
    0x74, 0x0d, 0x99, 0x5a, 0x12, 0x74, 0x64, 0xaa,
    0xb6, 0xa5, 0x96, 0x75, 0xf9, 0x42, 0x43, 0xe2,
    0x52, 0xc2, 0x57, 0x23, 0x75, 0xd7, 0xa9, 0x4f,
    0x07, 0x32, 0x99, 0xbd, 0x3d, 0x44, 0xbd, 0x04,
    0x62, 0xe5, 0xb7, 0x2c, 0x0c, 0x11, 0xc5, 0xb2,
    0x2e, 0xc4, 0x12, 0x1d, 0x7f, 0x42, 0x1e, 0x71,
    0xaf, 0x39, 0x2b, 0x78, 0x47, 0x92, 0x23, 0x44,
    0xef, 0xe3, 0xc1, 0x47, 0x69, 0x5a, 0xf1, 0x48,
    0xaa, 0x37, 0xa4, 0x94, 0x6b, 0x96, 0xe5, 0x4b,
    0xfd, 0x05, 0xc7, 0x9c, 0xcc, 0x38, 0xd1, 0x47,
    0x85, 0x60, 0x7f, 0xef, 0xe9, 0x2e, 0x25, 0x08,
    0xf8, 0x7d, 0x98, 0xdd, 0x6c, 0xeb, 0x4a, 0x32,
    0x33, 0x44, 0x0b, 0x61, 0xb3, 0xf9, 0xae, 0x26,
    0x41, 0xb5, 0x38, 0xdb, 0xcf, 0x13, 0x72, 0x23,
    0x5b, 0x66, 0x20, 0x86, 0x4d, 0x24, 0xc2, 0xd4,
    0x94, 0xde, 0xe3, 0x24, 0xb7, 0xcd, 0x75, 0x9e,
    0x1d, 0x9f, 0xbc, 0xd0, 0x60, 0x34, 0x7d, 0xf8,
    0xcb, 0x41, 0x39, 0x02, 0x03, 0x01, 0x00, 0x01,
    0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86,
    0xf7, 0x0d, 0x01, 0x01, 0x05, 0x05, 0x00, 0x03,
    0x82, 0x01, 0x01, 0x00, 0x17, 0xa5, 0x22, 0xed,
    0xb8, 0x3e, 0x1f, 0x11, 0x99, 0xc5, 0xba, 0x28,
    0x3e, 0x7e, 0xa6, 0xeb, 0x02, 0x81, 0x06, 0xa1,
    0xc6, 0x80, 0xb9, 0x7e, 0x5c, 0x5a, 0x63, 0xe0,
    0x8d, 0xeb, 0xd0, 0xec, 0x9c, 0x3a, 0x94, 0x64,
    0x7c, 0x13, 0x54, 0x0d, 0xd6, 0xe3, 0x27, 0x88,
    0xa6, 0xd2, 0x4b, 0x36, 0xdd, 0x2e, 0xfa, 0x94,
    0xe5, 0x03, 0x27, 0xc9, 0xa6, 0x31, 0x02, 0xea,
    0x40, 0x77, 0x2e, 0x93, 0xc4, 0x4d, 0xe2, 0x70,
    0xe2, 0x67, 0x1c, 0xa8, 0x0d, 0xcd, 0x1a, 0x72,
    0x86, 0x2c, 0xea, 0xdc, 0x7f, 0x8c, 0x49, 0x2c,
    0xe7, 0x99, 0x13, 0xda, 0x3f, 0x58, 0x9e, 0xf5,
    0x4d, 0x3c, 0x8c, 0x1c, 0xed, 0x85, 0xa7, 0xe2,
    0xae, 0xda, 0x5f, 0xbe, 0x36, 0x1c, 0x9f, 0x5a,
    0xa0, 0xdc, 0x2a, 0xc0, 0xee, 0x71, 0x07, 0x26,
    0x8b, 0xe8, 0x8a, 0xf8, 0x2d, 0x36, 0x78, 0xc9,
    0x79, 0xfa, 0xbe, 0x98, 0x59, 0x95, 0x12, 0x24,
    0xf1, 0xda, 0x20, 0xc7, 0x78, 0xf9, 0x7c, 0x6a,
    0x24, 0x43, 0x82, 0xa8, 0x0f, 0xb1, 0x7d, 0x94,
    0xaa, 0x30, 0x35, 0xe5, 0x69, 0xdc, 0x0a, 0x0e,
    0xaf, 0x10, 0x5e, 0x1a, 0x81, 0x50, 0x5c, 0x7e,
    0x24, 0xb3, 0x07, 0x65, 0x4b, 0xc1, 0x7e, 0xc6,
    0x38, 0xdb, 0xd3, 0x6a, 0xf0, 0xd8, 0x85, 0x61,
    0x9a, 0x9f, 0xfe, 0x02, 0x46, 0x29, 0xb2, 0x9a,
    0xe2, 0x04, 0xe7, 0x72, 0xcc, 0x87, 0x46, 0xba,
    0x7d, 0xa8, 0xf9, 0xd0, 0x0f, 0x29, 0xfc, 0xfd,
    0xd1, 0xd0, 0x7f, 0x36, 0xc1, 0xd8, 0x7d, 0x88,
    0x03, 0x62, 0xf5, 0x8c, 0x00, 0xb5, 0xc2, 0x81,
    0x44, 0x67, 0x58, 0x11, 0xb4, 0x3a, 0xbb, 0xd1,
    0x8c, 0x94, 0x20, 0x60, 0xea, 0xa0, 0xac, 0xc1,
    0xf1, 0x08, 0x54, 0xb8, 0xf6, 0x5e, 0xac, 0xf1,
    0xec, 0x78, 0x69, 0x9d, 0x7e, 0x4d, 0x06, 0x3b,
    0x9b, 0x78, 0x78, 0x10
};

/* A certs only cms message. */
static UInt8 certsOnlyMsg[] = {
    0x30, 0x82, 0x04, 0xdc, 0x06, 0x09, 0x2a, 0x86,
    0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x02, 0xa0,
    0x82, 0x04, 0xcd, 0x30, 0x82, 0x04, 0xc9, 0x02,
    0x01, 0x01, 0x31, 0x00, 0x30, 0x0b, 0x06, 0x09,
    0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07,
    0x01, 0xa0, 0x82, 0x04, 0xb1, 0x30, 0x82, 0x04,
    0xad, 0x30, 0x82, 0x03, 0x95, 0xa0, 0x03, 0x02,
    0x01, 0x02, 0x02, 0x10, 0x4e, 0x2d, 0x47, 0x54,
    0xcd, 0xbb, 0x8e, 0x98, 0x42, 0xdb, 0x18, 0x9e,
    0x3a, 0xca, 0x80, 0xcc, 0x30, 0x0d, 0x06, 0x09,
    0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01,
    0x05, 0x05, 0x00, 0x30, 0x57, 0x31, 0x13, 0x30,
    0x11, 0x06, 0x0a, 0x09, 0x92, 0x26, 0x89, 0x93,
    0xf2, 0x2c, 0x64, 0x01, 0x19, 0x16, 0x03, 0x63,
    0x6f, 0x6d, 0x31, 0x15, 0x30, 0x13, 0x06, 0x0a,
    0x09, 0x92, 0x26, 0x89, 0x93, 0xf2, 0x2c, 0x64,
    0x01, 0x19, 0x16, 0x05, 0x61, 0x70, 0x70, 0x6c,
    0x65, 0x31, 0x17, 0x30, 0x15, 0x06, 0x0a, 0x09,
    0x92, 0x26, 0x89, 0x93, 0xf2, 0x2c, 0x64, 0x01,
    0x19, 0x16, 0x07, 0x63, 0x61, 0x6c, 0x6c, 0x69,
    0x65, 0x39, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03,
    0x55, 0x04, 0x03, 0x13, 0x07, 0x63, 0x61, 0x6c,
    0x6c, 0x69, 0x65, 0x39, 0x30, 0x1e, 0x17, 0x0d,
    0x30, 0x34, 0x30, 0x32, 0x32, 0x34, 0x31, 0x39,
    0x31, 0x35, 0x35, 0x37, 0x5a, 0x17, 0x0d, 0x30,
    0x39, 0x30, 0x32, 0x32, 0x34, 0x31, 0x39, 0x32,
    0x35, 0x30, 0x31, 0x5a, 0x30, 0x57, 0x31, 0x13,
    0x30, 0x11, 0x06, 0x0a, 0x09, 0x92, 0x26, 0x89,
    0x93, 0xf2, 0x2c, 0x64, 0x01, 0x19, 0x16, 0x03,
    0x63, 0x6f, 0x6d, 0x31, 0x15, 0x30, 0x13, 0x06,
    0x0a, 0x09, 0x92, 0x26, 0x89, 0x93, 0xf2, 0x2c,
    0x64, 0x01, 0x19, 0x16, 0x05, 0x61, 0x70, 0x70,
    0x6c, 0x65, 0x31, 0x17, 0x30, 0x15, 0x06, 0x0a,
    0x09, 0x92, 0x26, 0x89, 0x93, 0xf2, 0x2c, 0x64,
    0x01, 0x19, 0x16, 0x07, 0x63, 0x61, 0x6c, 0x6c,
    0x69, 0x65, 0x39, 0x31, 0x10, 0x30, 0x0e, 0x06,
    0x03, 0x55, 0x04, 0x03, 0x13, 0x07, 0x63, 0x61,
    0x6c, 0x6c, 0x69, 0x65, 0x39, 0x30, 0x82, 0x01,
    0x22, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48,
    0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00,
    0x03, 0x82, 0x01, 0x0f, 0x00, 0x30, 0x82, 0x01,
    0x0a, 0x02, 0x82, 0x01, 0x01, 0x00, 0x9d, 0xbf,
    0x50, 0x9c, 0x42, 0xea, 0xad, 0xfa, 0xb7, 0x3e,
    0x22, 0xcf, 0xc5, 0xba, 0xd3, 0x3a, 0xe8, 0x62,
    0xb5, 0x62, 0x3d, 0x1e, 0xcf, 0xec, 0x52, 0x48,
    0x51, 0xa0, 0xef, 0x20, 0xf2, 0x7b, 0xb2, 0x57,
    0x25, 0x86, 0xd7, 0x15, 0xd8, 0xc6, 0x1a, 0x5f,
    0x95, 0xe0, 0x35, 0x97, 0x23, 0x7c, 0xc6, 0x88,
    0x11, 0x1c, 0x8d, 0x8d, 0x7d, 0xf0, 0xc0, 0xbd,
    0x71, 0x49, 0xbd, 0x9e, 0x51, 0x02, 0x3c, 0x70,
    0xd7, 0xaa, 0xd2, 0x80, 0xb4, 0xda, 0xb0, 0x3b,
    0x42, 0x16, 0x50, 0xc6, 0x1b, 0x17, 0x29, 0xd6,
    0xbe, 0x40, 0xce, 0x3c, 0x54, 0xaf, 0xf5, 0x29,
    0xc6, 0x12, 0x47, 0xc4, 0x96, 0x85, 0x46, 0xaa,
    0xf1, 0x76, 0xd1, 0x76, 0x22, 0xd3, 0x45, 0xf7,
    0x71, 0xea, 0x4b, 0x42, 0x7b, 0x97, 0x39, 0x02,
    0x2c, 0x6d, 0x36, 0x2a, 0x80, 0xaa, 0x01, 0x58,
    0xbc, 0x52, 0xa2, 0xa4, 0xc4, 0x3c, 0xe8, 0xcd,
    0xb2, 0xb8, 0x4a, 0xd3, 0x4e, 0x06, 0xcc, 0x52,
    0x0f, 0x5e, 0xd2, 0xe9, 0xe9, 0xb8, 0xe6, 0x79,
    0xe3, 0x91, 0x24, 0x72, 0x44, 0x65, 0x3c, 0xfe,
    0x01, 0x69, 0x70, 0x0a, 0xce, 0xd1, 0x9a, 0xd1,
    0x3f, 0x77, 0xa6, 0x78, 0x04, 0x9b, 0x7b, 0x14,
    0x37, 0x71, 0x3d, 0x4b, 0x56, 0xe9, 0xc3, 0xf6,
    0x58, 0x16, 0x0c, 0x10, 0x86, 0x5b, 0xbd, 0x93,
    0xc0, 0xf5, 0xb8, 0xbb, 0x78, 0xcf, 0xf3, 0xb2,
    0xaa, 0xaf, 0xc4, 0x0c, 0x66, 0x13, 0x1d, 0xce,
    0x98, 0x4e, 0x99, 0x93, 0xb6, 0xf7, 0xe0, 0x73,
    0xb6, 0x74, 0x55, 0xcf, 0x83, 0x1d, 0x8d, 0x68,
    0xcf, 0x59, 0x5e, 0x1b, 0x3e, 0xb5, 0x5a, 0x71,
    0x36, 0x07, 0xb6, 0xfa, 0xc4, 0x6f, 0xe5, 0x7b,
    0x69, 0x09, 0xe7, 0xe5, 0xce, 0x8a, 0x1c, 0xfa,
    0x5c, 0xdc, 0x5d, 0x18, 0xf4, 0x5a, 0x5b, 0x0d,
    0x37, 0x44, 0x56, 0x9e, 0xe9, 0x95, 0x02, 0x03,
    0x01, 0x00, 0x01, 0xa3, 0x82, 0x01, 0x73, 0x30,
    0x82, 0x01, 0x6f, 0x30, 0x0b, 0x06, 0x03, 0x55,
    0x1d, 0x0f, 0x04, 0x04, 0x03, 0x02, 0x01, 0x86,
    0x30, 0x0f, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01,
    0x01, 0xff, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01,
    0xff, 0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d, 0x0e,
    0x04, 0x16, 0x04, 0x14, 0x6c, 0xde, 0x50, 0x56,
    0x01, 0x34, 0xdc, 0x26, 0xec, 0x85, 0xdf, 0xf7,
    0x32, 0x67, 0x68, 0x08, 0x04, 0xa0, 0xa8, 0xcd,
    0x30, 0x82, 0x01, 0x1c, 0x06, 0x03, 0x55, 0x1d,
    0x1f, 0x04, 0x82, 0x01, 0x13, 0x30, 0x82, 0x01,
    0x0f, 0x30, 0x82, 0x01, 0x0b, 0xa0, 0x82, 0x01,
    0x07, 0xa0, 0x82, 0x01, 0x03, 0x86, 0x81, 0xbf,
    0x6c, 0x64, 0x61, 0x70, 0x3a, 0x2f, 0x2f, 0x2f,
    0x43, 0x4e, 0x3d, 0x63, 0x61, 0x6c, 0x6c, 0x69,
    0x65, 0x39, 0x2c, 0x43, 0x4e, 0x3d, 0x63, 0x68,
    0x72, 0x69, 0x73, 0x74, 0x6f, 0x70, 0x2d, 0x6d,
    0x74, 0x33, 0x71, 0x66, 0x6f, 0x2c, 0x43, 0x4e,
    0x3d, 0x43, 0x44, 0x50, 0x2c, 0x43, 0x4e, 0x3d,
    0x50, 0x75, 0x62, 0x6c, 0x69, 0x63, 0x25, 0x32,
    0x30, 0x4b, 0x65, 0x79, 0x25, 0x32, 0x30, 0x53,
    0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x73, 0x2c,
    0x43, 0x4e, 0x3d, 0x53, 0x65, 0x72, 0x76, 0x69,
    0x63, 0x65, 0x73, 0x2c, 0x43, 0x4e, 0x3d, 0x43,
    0x6f, 0x6e, 0x66, 0x69, 0x67, 0x75, 0x72, 0x61,
    0x74, 0x69, 0x6f, 0x6e, 0x2c, 0x44, 0x43, 0x3d,
    0x63, 0x61, 0x6c, 0x6c, 0x69, 0x65, 0x39, 0x2c,
    0x44, 0x43, 0x3d, 0x61, 0x70, 0x70, 0x6c, 0x65,
    0x2c, 0x44, 0x43, 0x3d, 0x63, 0x6f, 0x6d, 0x3f,
    0x63, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63,
    0x61, 0x74, 0x65, 0x52, 0x65, 0x76, 0x6f, 0x63,
    0x61, 0x74, 0x69, 0x6f, 0x6e, 0x4c, 0x69, 0x73,
    0x74, 0x3f, 0x62, 0x61, 0x73, 0x65, 0x3f, 0x6f,
    0x62, 0x6a, 0x65, 0x63, 0x74, 0x43, 0x6c, 0x61,
    0x73, 0x73, 0x3d, 0x63, 0x52, 0x4c, 0x44, 0x69,
    0x73, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x69,
    0x6f, 0x6e, 0x50, 0x6f, 0x69, 0x6e, 0x74, 0x86,
    0x3f, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f,
    0x63, 0x68, 0x72, 0x69, 0x73, 0x74, 0x6f, 0x70,
    0x2d, 0x6d, 0x74, 0x33, 0x71, 0x66, 0x6f, 0x2e,
    0x63, 0x61, 0x6c, 0x6c, 0x69, 0x65, 0x39, 0x2e,
    0x61, 0x70, 0x70, 0x6c, 0x65, 0x2e, 0x63, 0x6f,
    0x6d, 0x2f, 0x43, 0x65, 0x72, 0x74, 0x45, 0x6e,
    0x72, 0x6f, 0x6c, 0x6c, 0x2f, 0x63, 0x61, 0x6c,
    0x6c, 0x69, 0x65, 0x39, 0x2e, 0x63, 0x72, 0x6c,
    0x30, 0x10, 0x06, 0x09, 0x2b, 0x06, 0x01, 0x04,
    0x01, 0x82, 0x37, 0x15, 0x01, 0x04, 0x03, 0x02,
    0x01, 0x00, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86,
    0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x05, 0x05,
    0x00, 0x03, 0x82, 0x01, 0x01, 0x00, 0x9d, 0xba,
    0x9a, 0xeb, 0x1d, 0x78, 0x99, 0x93, 0xc6, 0x2c,
    0x36, 0x16, 0xa0, 0x15, 0x18, 0xe8, 0x20, 0x2e,
    0xb2, 0x0a, 0x8c, 0x02, 0x2e, 0x69, 0xe3, 0x9c,
    0x03, 0x26, 0x56, 0x41, 0xdd, 0x5a, 0xe1, 0x49,
    0x38, 0x5d, 0xf8, 0x1d, 0x09, 0x57, 0x22, 0xad,
    0xd9, 0xf4, 0x47, 0xa4, 0x0a, 0x46, 0xd7, 0x13,
    0xda, 0x08, 0xa1, 0x2c, 0xff, 0xb3, 0xbd, 0x07,
    0xfa, 0x95, 0x98, 0x0f, 0x53, 0x40, 0x79, 0xb2,
    0xf7, 0x85, 0x67, 0xf6, 0x37, 0x7f, 0xec, 0x21,
    0xf6, 0xb4, 0x6c, 0xda, 0x93, 0x03, 0x32, 0x74,
    0x5a, 0xa8, 0x81, 0x86, 0x10, 0xb7, 0x55, 0x11,
    0xe7, 0x53, 0xc3, 0x0a, 0x7e, 0x47, 0xba, 0xf5,
    0x8a, 0xaa, 0xab, 0x02, 0xc2, 0x01, 0xd6, 0x5b,
    0xb2, 0x96, 0xa9, 0x04, 0xda, 0xc2, 0x83, 0xb5,
    0x09, 0x54, 0x69, 0x67, 0xd2, 0x3a, 0x13, 0x6a,
    0x6c, 0xce, 0xc0, 0x64, 0x92, 0xb5, 0xda, 0x48,
    0x1c, 0x07, 0x15, 0xfb, 0xdd, 0x5f, 0xb6, 0x66,
    0x4c, 0x89, 0x44, 0xa0, 0x5c, 0x22, 0x41, 0x3d,
    0x5f, 0x21, 0x97, 0xa9, 0x0f, 0x58, 0xe9, 0xf8,
    0x16, 0x5e, 0xd9, 0x1e, 0x9d, 0x99, 0x0a, 0x9c,
    0xf3, 0x8b, 0x35, 0x3d, 0x0e, 0xc1, 0x10, 0x13,
    0x77, 0xcf, 0x4d, 0x4c, 0x85, 0xb4, 0x66, 0x27,
    0xa8, 0x79, 0x8f, 0xa4, 0x9f, 0x5f, 0x1f, 0xe9,
    0xe6, 0x39, 0xc0, 0xcf, 0x3d, 0x4a, 0x17, 0x3f,
    0x0b, 0xbf, 0x35, 0xe7, 0xe4, 0x47, 0x66, 0x4d,
    0x1e, 0xbc, 0x58, 0xf5, 0x62, 0xf8, 0x31, 0x02,
    0x84, 0xfb, 0x52, 0x39, 0x26, 0x92, 0xc3, 0xff,
    0x2a, 0x0a, 0x8e, 0x76, 0x66, 0xbc, 0x94, 0x38,
    0xe2, 0x28, 0x19, 0xcd, 0x40, 0xde, 0x88, 0xdd,
    0xfe, 0xf1, 0xdd, 0x62, 0xf4, 0xb5, 0x58, 0xf6,
    0x30, 0x22, 0xc3, 0x94, 0xed, 0xd2, 0x0a, 0x9a,
    0x71, 0x14, 0xd4, 0xed, 0x70, 0x94, 0x31, 0x00
};

// X.509 IPACCG2 Test Certificate Valid Class 87 device, cms format
const uint8_t gkIPACCG2DevCertClass87 [] =
{
    0x30, 0x82, 0x03, 0x8a, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d,
    0x01, 0x07, 0x02, 0xa0, 0x82, 0x03, 0x7b, 0x30, 0x82, 0x03, 0x77, 0x02,
    0x01, 0x01, 0x31, 0x00, 0x30, 0x0b, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86,
    0xf7, 0x0d, 0x01, 0x07, 0x01, 0xa0, 0x82, 0x03, 0x5d, 0x30, 0x82, 0x03,
    0x59, 0x30, 0x82, 0x02, 0x41, 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x0f,
    0x33, 0x33, 0xaa, 0x13, 0x02, 0x07, 0xaa, 0x87, 0xaa, 0x00, 0x01, 0xaa,
    0x00, 0x00, 0x01, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7,
    0x0d, 0x01, 0x01, 0x05, 0x05, 0x00, 0x30, 0x81, 0x83, 0x31, 0x0b, 0x30,
    0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x13,
    0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x0a, 0x41, 0x70, 0x70,
    0x6c, 0x65, 0x20, 0x49, 0x6e, 0x63, 0x2e, 0x31, 0x26, 0x30, 0x24, 0x06,
    0x03, 0x55, 0x04, 0x0b, 0x13, 0x1d, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20,
    0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f,
    0x6e, 0x20, 0x41, 0x75, 0x74, 0x68, 0x6f, 0x72, 0x69, 0x74, 0x79, 0x31,
    0x37, 0x30, 0x35, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x2e, 0x41, 0x70,
    0x70, 0x6c, 0x65, 0x20, 0x69, 0x50, 0x6f, 0x64, 0x20, 0x41, 0x63, 0x63,
    0x65, 0x73, 0x73, 0x6f, 0x72, 0x69, 0x65, 0x73, 0x20, 0x43, 0x65, 0x72,
    0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x41,
    0x75, 0x74, 0x68, 0x6f, 0x72, 0x69, 0x74, 0x79, 0x30, 0x1e, 0x17, 0x0d,
    0x31, 0x33, 0x30, 0x32, 0x30, 0x37, 0x30, 0x31, 0x32, 0x33, 0x31, 0x30,
    0x5a, 0x17, 0x0d, 0x32, 0x31, 0x30, 0x32, 0x30, 0x37, 0x30, 0x31, 0x32,
    0x33, 0x31, 0x30, 0x5a, 0x30, 0x70, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03,
    0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x13, 0x30, 0x11, 0x06,
    0x03, 0x55, 0x04, 0x0a, 0x13, 0x0a, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20,
    0x49, 0x6e, 0x63, 0x2e, 0x31, 0x1f, 0x30, 0x1d, 0x06, 0x03, 0x55, 0x04,
    0x0b, 0x13, 0x16, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x20, 0x69, 0x50, 0x6f,
    0x64, 0x20, 0x41, 0x63, 0x63, 0x65, 0x73, 0x73, 0x6f, 0x72, 0x69, 0x65,
    0x73, 0x31, 0x2b, 0x30, 0x29, 0x06, 0x03, 0x55, 0x04, 0x03, 0x14, 0x22,
    0x49, 0x50, 0x41, 0x5f, 0x33, 0x33, 0x33, 0x33, 0x41, 0x41, 0x31, 0x33,
    0x30, 0x32, 0x30, 0x37, 0x41, 0x41, 0x38, 0x37, 0x41, 0x41, 0x30, 0x30,
    0x30, 0x31, 0x41, 0x41, 0x30, 0x30, 0x30, 0x30, 0x30, 0x31, 0x30, 0x81,
    0x9f, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01,
    0x01, 0x01, 0x05, 0x00, 0x03, 0x81, 0x8d, 0x00, 0x30, 0x81, 0x89, 0x02,
    0x81, 0x81, 0x00, 0xbc, 0xa8, 0x7b, 0xa8, 0xdb, 0x0c, 0xb8, 0x6e, 0x3a,
    0x1d, 0x57, 0x8c, 0x3a, 0x8c, 0x91, 0xe7, 0x0e, 0x86, 0xc8, 0xe8, 0xd8,
    0x41, 0xfe, 0x30, 0xd4, 0x77, 0x8c, 0x81, 0xb8, 0x5e, 0x6c, 0x79, 0x29,
    0xff, 0x57, 0x50, 0x41, 0x0b, 0x2e, 0x7f, 0x64, 0xa5, 0xc5, 0xc6, 0x2a,
    0x7e, 0x49, 0xdf, 0x65, 0x19, 0x5d, 0x6d, 0x0e, 0x7c, 0xc4, 0xb8, 0xb3,
    0x1a, 0x59, 0x00, 0x86, 0xa6, 0xde, 0xc3, 0x98, 0x80, 0x20, 0x0e, 0xf1,
    0xb3, 0x21, 0x1f, 0x68, 0x33, 0xe4, 0x2c, 0xd3, 0x8b, 0x7a, 0x24, 0x55,
    0xb5, 0xb3, 0x42, 0xa3, 0x2a, 0x40, 0x7c, 0xe4, 0xda, 0x32, 0xb3, 0x41,
    0xa0, 0x74, 0xe7, 0xfd, 0x97, 0x0c, 0xbe, 0x6f, 0xe3, 0xfd, 0xb9, 0x14,
    0x89, 0x50, 0xc5, 0xb3, 0x22, 0xcf, 0x47, 0xc7, 0x2e, 0x3b, 0xe3, 0x80,
    0x13, 0xac, 0x08, 0xe5, 0x3c, 0xe9, 0xbc, 0x56, 0x5f, 0x3b, 0xb9, 0x02,
    0x03, 0x01, 0x00, 0x01, 0xa3, 0x60, 0x30, 0x5e, 0x30, 0x0e, 0x06, 0x03,
    0x55, 0x1d, 0x0f, 0x01, 0x01, 0xff, 0x04, 0x04, 0x03, 0x02, 0x03, 0xb8,
    0x30, 0x0c, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01, 0xff, 0x04, 0x02,
    0x30, 0x00, 0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04,
    0x14, 0x09, 0xa5, 0x78, 0x7d, 0xfe, 0x2b, 0x75, 0x6d, 0x3f, 0xf4, 0x2b,
    0xa2, 0xa2, 0x96, 0xc8, 0x50, 0x16, 0xf7, 0x8b, 0x9f, 0x30, 0x1f, 0x06,
    0x03, 0x55, 0x1d, 0x23, 0x04, 0x18, 0x30, 0x16, 0x80, 0x14, 0xff, 0x4b,
    0x1a, 0x43, 0x9a, 0xf5, 0x19, 0x96, 0xab, 0x18, 0x00, 0x2b, 0x61, 0xc9,
    0xee, 0x40, 0x9d, 0x8e, 0xc7, 0x04, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86,
    0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x05, 0x05, 0x00, 0x03, 0x82, 0x01,
    0x01, 0x00, 0x6b, 0xbb, 0x91, 0x97, 0xcd, 0x17, 0xc5, 0x1b, 0x10, 0xbf,
    0x29, 0x2d, 0x69, 0xeb, 0xd0, 0x96, 0x32, 0x4f, 0x89, 0x64, 0x82, 0x96,
    0x52, 0x59, 0x73, 0x15, 0x6b, 0x5d, 0x01, 0xa7, 0x90, 0x34, 0xd7, 0xc0,
    0x46, 0xc3, 0xfc, 0x27, 0xf0, 0x68, 0xfe, 0xf8, 0x54, 0x76, 0xf8, 0x61,
    0xc9, 0x91, 0xf8, 0x7d, 0x96, 0x1f, 0x14, 0x7c, 0x09, 0x27, 0xf9, 0x16,
    0x34, 0x15, 0x19, 0xa8, 0xb3, 0xd0, 0x0f, 0xf3, 0x16, 0xe1, 0xb0, 0x2e,
    0x70, 0xfe, 0xee, 0x3a, 0xbc, 0x3d, 0x4e, 0x07, 0x86, 0x89, 0x1c, 0xdb,
    0xe3, 0x2e, 0xc8, 0x66, 0x6a, 0x10, 0x82, 0x13, 0x8f, 0xf0, 0x75, 0xfa,
    0x6a, 0x25, 0x9d, 0xdb, 0x83, 0x66, 0xb1, 0xae, 0x72, 0x25, 0x03, 0x01,
    0x2b, 0x74, 0x8b, 0xbb, 0x37, 0xee, 0x92, 0x17, 0x81, 0xb3, 0x9a, 0xd3,
    0x7b, 0xfc, 0x0c, 0x35, 0xe8, 0xd5, 0x2c, 0xdb, 0x3e, 0x83, 0x9d, 0x05,
    0x3e, 0x40, 0x18, 0xb0, 0xe6, 0xcf, 0x18, 0x2d, 0x85, 0x96, 0x3f, 0x80,
    0xcd, 0xff, 0xb5, 0x71, 0xcf, 0xb2, 0x54, 0xab, 0xd3, 0xea, 0x24, 0x86,
    0xd0, 0xb8, 0xc6, 0x84, 0x75, 0xfa, 0x5e, 0xbf, 0xee, 0x3a, 0xde, 0x2b,
    0xdf, 0x05, 0x19, 0xf4, 0x1c, 0x02, 0x2f, 0x7f, 0x46, 0xbd, 0x58, 0x0f,
    0x8a, 0xb6, 0xdf, 0x84, 0xe5, 0xa3, 0x3d, 0x22, 0xf4, 0xff, 0x4a, 0x1a,
    0x87, 0x1c, 0xa9, 0x0f, 0x73, 0x62, 0x96, 0x96, 0x27, 0x5a, 0x1d, 0x4e,
    0xfa, 0x1f, 0xa5, 0xf4, 0x08, 0xbf, 0x09, 0x66, 0xde, 0xee, 0x8c, 0xd1,
    0x57, 0xaf, 0x13, 0xf2, 0x51, 0x93, 0x0b, 0xa9, 0x39, 0x94, 0x71, 0xbc,
    0x05, 0xa7, 0xa0, 0xda, 0xfa, 0x65, 0x7d, 0x23, 0xa8, 0xb2, 0xa0, 0x89,
    0x86, 0x1f, 0xd2, 0x57, 0xd8, 0x1b, 0x22, 0x69, 0x8b, 0x48, 0x94, 0x5a,
    0x5b, 0xaf, 0x92, 0xd9, 0xb6, 0x77, 0xa1, 0x00, 0x31, 0x00
}; // gkIPACCG2DevCertClass87 []

// Concatenated blob of 2 DER certificat
const uint8_t TestDoubleCerts1 [] =
{
    0x30, 0x82, 0x01, 0xbe, 0x30, 0x82, 0x01, 0x27, 0x02, 0x01, 0x01, 0x30,
    0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x05,
    0x05, 0x00, 0x30, 0x25, 0x31, 0x23, 0x30, 0x21, 0x06, 0x03, 0x55, 0x04,
    0x03, 0x13, 0x1a, 0x53, 0x65, 0x63, 0x75, 0x72, 0x69, 0x74, 0x79, 0x54,
    0x65, 0x73, 0x74, 0x20, 0x43, 0x41, 0x20, 0x43, 0x65, 0x72, 0x74, 0x20,
    0x28, 0x52, 0x53, 0x41, 0x29, 0x30, 0x1e, 0x17, 0x0d, 0x31, 0x34, 0x30,
    0x32, 0x32, 0x30, 0x30, 0x30, 0x34, 0x36, 0x33, 0x36, 0x5a, 0x17, 0x0d,
    0x31, 0x34, 0x30, 0x33, 0x32, 0x32, 0x30, 0x30, 0x34, 0x36, 0x33, 0x36,
    0x5a, 0x30, 0x2a, 0x31, 0x28, 0x30, 0x26, 0x06, 0x03, 0x55, 0x04, 0x03,
    0x13, 0x1f, 0x53, 0x65, 0x63, 0x75, 0x72, 0x69, 0x74, 0x79, 0x54, 0x65,
    0x73, 0x74, 0x73, 0x20, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x20, 0x43,
    0x65, 0x72, 0x74, 0x20, 0x28, 0x52, 0x53, 0x41, 0x29, 0x30, 0x81, 0x9f,
    0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01,
    0x01, 0x05, 0x00, 0x03, 0x81, 0x8d, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81,
    0x81, 0x00, 0xc8, 0x22, 0x8a, 0x23, 0x42, 0x66, 0x0d, 0x48, 0x64, 0x30,
    0xf2, 0xe9, 0xa2, 0x2f, 0xdf, 0x55, 0x5b, 0xb9, 0xb8, 0xe4, 0xe7, 0xb3,
    0xfb, 0x10, 0x63, 0x38, 0x7f, 0x57, 0x55, 0x6a, 0xe8, 0x08, 0xb9, 0x8b,
    0x70, 0x80, 0x15, 0x3b, 0x4e, 0xdb, 0x0c, 0xa3, 0xc5, 0x0b, 0xdf, 0x28,
    0xd3, 0x9a, 0x39, 0xb6, 0xca, 0x1d, 0x7b, 0x5f, 0x7b, 0x0c, 0x58, 0x87,
    0x3d, 0x81, 0xc7, 0xfd, 0x54, 0x3c, 0x0a, 0x60, 0xa2, 0x16, 0xf3, 0x35,
    0x29, 0x62, 0x40, 0xb2, 0x17, 0x09, 0x5a, 0x9a, 0x81, 0xa7, 0xb3, 0x4f,
    0x8d, 0x73, 0x3d, 0xe6, 0xbc, 0x53, 0x25, 0x2c, 0x43, 0x07, 0x4b, 0xda,
    0x0d, 0x73, 0x1b, 0x84, 0x32, 0x85, 0x9e, 0x60, 0xfe, 0xe0, 0xdb, 0x1c,
    0xf2, 0x4a, 0xed, 0x1b, 0xe9, 0xbc, 0xbc, 0xdd, 0x38, 0xe9, 0x62, 0x16,
    0xcb, 0x74, 0x2a, 0xa8, 0xe8, 0xbb, 0x74, 0x19, 0x56, 0xfd, 0x02, 0x03,
    0x01, 0x00, 0x01, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7,
    0x0d, 0x01, 0x01, 0x05, 0x05, 0x00, 0x03, 0x81, 0x81, 0x00, 0x4a, 0xde,
    0xd1, 0x1d, 0xc6, 0xaf, 0xc4, 0xe0, 0x12, 0x0b, 0xb8, 0xd7, 0xc8, 0xaf,
    0xe9, 0x90, 0x6f, 0x53, 0x15, 0xaa, 0xd1, 0xd5, 0x54, 0x4f, 0x62, 0xb8,
    0xc7, 0xfc, 0x68, 0x97, 0x3c, 0xdb, 0xca, 0x75, 0x4f, 0xb8, 0x52, 0xe7,
    0x77, 0xe2, 0x18, 0x78, 0x11, 0x74, 0xd7, 0x2e, 0xf5, 0xc6, 0xc8, 0x00,
    0x1d, 0xa1, 0x9c, 0xdd, 0xc7, 0x01, 0xb1, 0x34, 0x7a, 0x48, 0x8a, 0x2c,
    0x34, 0x7e, 0x43, 0x56, 0x50, 0xc2, 0xf1, 0x7c, 0x02, 0x5e, 0xd7, 0x16,
    0xae, 0xea, 0x31, 0x70, 0x54, 0xd9, 0xad, 0x15, 0xcd, 0xc7, 0x07, 0x99,
    0x30, 0x0a, 0xff, 0xdb, 0x7a, 0x72, 0xf6, 0x89, 0x51, 0x01, 0x81, 0x3b,
    0x97, 0x46, 0x99, 0x8a, 0x52, 0x42, 0xaf, 0x63, 0xa2, 0x1d, 0xc0, 0xae,
    0x09, 0xa6, 0x6c, 0x7c, 0x7f, 0x93, 0xc7, 0xd0, 0x18, 0x97, 0x6b, 0x59,
    0xa9, 0x23, 0x84, 0x65, 0xf9, 0xfd,
};

const uint8_t TestDoubleCerts2 [] =
{
    0x30, 0x82, 0x01, 0xbf, 0x30, 0x82,
    0x01, 0x28, 0x02, 0x02, 0x03, 0xe9, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86,
    0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x05, 0x05, 0x00, 0x30, 0x25, 0x31,
    0x23, 0x30, 0x21, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x1a, 0x53, 0x65,
    0x63, 0x75, 0x72, 0x69, 0x74, 0x79, 0x54, 0x65, 0x73, 0x74, 0x20, 0x43,
    0x41, 0x20, 0x43, 0x65, 0x72, 0x74, 0x20, 0x28, 0x52, 0x53, 0x41, 0x29,
    0x30, 0x1e, 0x17, 0x0d, 0x31, 0x34, 0x30, 0x32, 0x32, 0x31, 0x31, 0x37,
    0x34, 0x38, 0x32, 0x39, 0x5a, 0x17, 0x0d, 0x31, 0x34, 0x30, 0x33, 0x32,
    0x33, 0x31, 0x37, 0x34, 0x38, 0x32, 0x39, 0x5a, 0x30, 0x2a, 0x31, 0x28,
    0x30, 0x26, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x1f, 0x53, 0x65, 0x63,
    0x75, 0x72, 0x69, 0x74, 0x79, 0x54, 0x65, 0x73, 0x74, 0x73, 0x20, 0x43,
    0x6c, 0x69, 0x65, 0x6e, 0x74, 0x20, 0x43, 0x65, 0x72, 0x74, 0x20, 0x28,
    0x52, 0x53, 0x41, 0x29, 0x30, 0x81, 0x9f, 0x30, 0x0d, 0x06, 0x09, 0x2a,
    0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x81,
    0x8d, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xd0, 0x4a, 0x1a,
    0x4d, 0xd7, 0x53, 0x22, 0xcf, 0xd3, 0xf3, 0x40, 0x9e, 0x14, 0xb5, 0x60,
    0xca, 0xcf, 0x2b, 0xd6, 0x48, 0x82, 0x6c, 0x15, 0x8f, 0xd8, 0xfb, 0xd1,
    0x38, 0x9a, 0x80, 0x3a, 0xcf, 0x03, 0xc6, 0xcd, 0x30, 0xc3, 0xe2, 0xa6,
    0x95, 0x23, 0x4f, 0xba, 0x1a, 0x6d, 0x78, 0x25, 0xd5, 0x63, 0x21, 0xe3,
    0x0f, 0x82, 0xfc, 0xcd, 0x84, 0xb0, 0xf5, 0xd2, 0xa6, 0x8c, 0x61, 0x26,
    0x7c, 0x50, 0x1a, 0x8b, 0xb0, 0x2c, 0x14, 0xaf, 0xf9, 0xb1, 0xb8, 0x96,
    0x72, 0x37, 0x67, 0x50, 0x57, 0x5b, 0x9f, 0xa2, 0x68, 0x04, 0x9b, 0x53,
    0x42, 0x1f, 0x24, 0xc3, 0x5d, 0x57, 0x66, 0x48, 0x2b, 0xe7, 0xd5, 0xf4,
    0x33, 0x84, 0xb3, 0x4a, 0x71, 0x6d, 0x69, 0xc1, 0xc4, 0x97, 0x22, 0x20,
    0xf6, 0x4e, 0x83, 0xda, 0x69, 0x6e, 0x07, 0x3c, 0x8b, 0xa3, 0xe4, 0x38,
    0x89, 0x64, 0x41, 0x25, 0x49, 0x02, 0x03, 0x01, 0x00, 0x01, 0x30, 0x0d,
    0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x05, 0x05,
    0x00, 0x03, 0x81, 0x81, 0x00, 0x9c, 0x2d, 0xe5, 0x32, 0x6b, 0x41, 0xaf,
    0x37, 0x30, 0x61, 0xd8, 0xf5, 0x0e, 0x7b, 0x3b, 0x57, 0x42, 0x08, 0x5c,
    0x28, 0x42, 0x7c, 0x1f, 0x40, 0xe9, 0xfc, 0xd4, 0x4b, 0x5c, 0x56, 0x83,
    0xb2, 0x85, 0x67, 0x11, 0x6c, 0x7a, 0x16, 0x16, 0x3f, 0xd6, 0xe0, 0xe9,
    0x89, 0xa5, 0xd9, 0xdc, 0x91, 0x34, 0xb9, 0x83, 0x71, 0xee, 0x69, 0xe1,
    0x7b, 0x4a, 0x4f, 0x1c, 0x1e, 0x7f, 0x74, 0x7c, 0xb6, 0x1c, 0xf3, 0xca,
    0xf8, 0xe7, 0x67, 0xbc, 0x73, 0xfc, 0xfa, 0x5e, 0x98, 0x52, 0xe3, 0x43,
    0x77, 0x32, 0xad, 0xcf, 0x81, 0x6f, 0xf4, 0xba, 0x61, 0x37, 0xff, 0xa7,
    0xf3, 0xfe, 0xf6, 0x67, 0x44, 0x41, 0x2e, 0x56, 0x91, 0x25, 0x8c, 0xc3,
    0xea, 0x9c, 0x85, 0xc9, 0x32, 0xde, 0xa9, 0x62, 0xcb, 0x3c, 0xb7, 0xbd,
    0x8d, 0x16, 0xec, 0xcf, 0x52, 0x17, 0xc8, 0x47, 0x99, 0x94, 0xe1, 0x4c,
    0x39
};


/* Basic processing of input */
static void tests(void)
{
    CFArrayRef certs = NULL;
    CFDataRef message;
    CFIndex count;

    // Premade message containing one certificate blob
    message = CFDataCreateWithBytesNoCopy(kCFAllocatorDefault,
                                          certsOnlyMsg, sizeof(certsOnlyMsg), kCFAllocatorNull);
    ok(certs = SecCMSCertificatesOnlyMessageCopyCertificates(message),
       "SecCMSCertificatesOnlyMessageCopyCertificates");
    is(CFArrayGetCount(certs), 1, "certificate count is 1");
    CFReleaseNull(message);
    CFReleaseNull(certs);

    // Premade message containing one certificate blob
    message = CFDataCreateWithBytesNoCopy(kCFAllocatorDefault,
                                          gkIPACCG2DevCertClass87, sizeof(gkIPACCG2DevCertClass87), kCFAllocatorNull);
    ok(certs = SecCMSCertificatesOnlyMessageCopyCertificates(message),
       "SecCMSCertificatesOnlyMessageCopyCertificates");
    is(CFArrayGetCount(certs), 1, "certificate count is 1");
    CFReleaseNull(message);
    CFReleaseNull(certs);

    SecCertificateRef another_cert = NULL;
    CFMutableArrayRef input_certs = NULL;

    // Process a single raw certificate and make it a message
    isnt(another_cert = SecCertificateCreateWithBytes(NULL, _c1, sizeof(_c1)),
         NULL, "create certificate");
    ok(message = SecCMSCreateCertificatesOnlyMessageIAP(another_cert), "create iAP specific cert only message (1cert)");
    ok(certs = SecCMSCertificatesOnlyMessageCopyCertificates(message),
       "SecCMSCertificatesOnlyMessageCopyCertificates");
    is(CFArrayGetCount(certs), 1, "certificate count is 1");
    CFReleaseNull(certs);
    CFReleaseNull(message);
    CFReleaseNull(another_cert);

    // Process two raw certificates and make it a message
    input_certs = CFArrayCreateMutable(NULL, 3, &kCFTypeArrayCallBacks);
    isnt(another_cert = SecCertificateCreateWithBytes(NULL, TestDoubleCerts1, sizeof(TestDoubleCerts1)),
         NULL, "create certificate");
    CFArrayAppendValue(input_certs, another_cert);
    CFReleaseNull(another_cert);
    isnt(another_cert = SecCertificateCreateWithBytes(NULL, TestDoubleCerts2, sizeof(TestDoubleCerts2)),
         NULL, "create certificate");
    CFArrayAppendValue(input_certs, another_cert);
    CFReleaseNull(another_cert);

    ok(message = SecCMSCreateCertificatesOnlyMessage(input_certs), "create cert only message (2certs)");
    ok(certs = SecCMSCertificatesOnlyMessageCopyCertificates(message),
       "SecCMSCertificatesOnlyMessageCopyCertificates");
    count = (certs) ? CFArrayGetCount(certs) : 0;
    ok(count == 2, "certificate count is 2");

    // Clean up
    CFReleaseNull(another_cert);
    CFReleaseNull(message);
    CFReleaseNull(input_certs);
    CFReleaseNull(certs);
}


int smime_cms_test(int argc, char *const *argv)
{
	plan_tests(13);

	tests();

	return 0;
}
