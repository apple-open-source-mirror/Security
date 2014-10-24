/*
 * Copyright (c) 2012-2014 Apple Inc. All Rights Reserved.
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


#include "SOSCircle_regressions.h"

#include "SOSRegressionUtilities.h"

#include <SecureObjectSync/SOSCloudCircle.h>
#include <utilities/SecCFWrappers.h>

static const int kSOSCCTestCount = 6;   // # of "ok"s in "tests" below
static int kTestTestCount = kSOSCCTestCount;
static void tests(void)
{
    CFErrorRef error = NULL;
    CFDataRef cfpassword = CFDataCreate(NULL, (uint8_t *) "FooFooFoo", 10);

    ok(SOSCCSetUserCredentials(CFSTR("foo1"), cfpassword, &error), "Added Creds (%@)", error);
    CFReleaseNull(error);
    CFReleaseNull(cfpassword);
    
    ok(SOSCCThisDeviceIsInCircle(&error) == kSOSCCCircleAbsent, "Circle Absent (%@)", error);
    CFReleaseNull(error);
    ok(SOSCCResetToOffering(&error), "SOSCCOfferPotentialCircle (%@)", error);
    CFReleaseNull(error);
    
    ok(SOSCCThisDeviceIsInCircle(&error) == kSOSCCInCircle, "Circle Absent (%@)", error);
    CFReleaseNull(error);
    ok(SOSCCRemoveThisDeviceFromCircle(&error), "Leaving (%@)", error);
    CFReleaseNull(error);
    
    ok(SOSCCThisDeviceIsInCircle(&error) == kSOSCCCircleAbsent, "Circle Absent (%@)", error);
    CFReleaseNull(error);
}

int sc_41_cloudcircle(int argc, char *const *argv)
{
    plan_tests(kTestTestCount);
	
    tests();
    
	return 0;
}
