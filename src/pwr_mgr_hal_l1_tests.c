/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include <string.h>
#include <stdlib.h>

#include <ut.h>
#include "plat_power.h"


/**
 * @brief This function will do the unit testing of PLAT_INIT().
 * This function will ensure underlying API implementation is handling
 * the invalid call sequences to the API properly.
 * This UT implementation will verify it by calling the function in all
 * invalid possibilities.
 * In all the invalid call sequence 
 * scenarios API should return the expected error codes defined in the respective HAL
 * documentation. Please see all the expected error codes and respective scenarios
 * in which the error codes will be returned.
 * PM_SUCCESS: will be returned if PLAT_INIT() is executed successfully.
 * PM_GENERAL_ERROR : will be returned if PLAT_INIT is called second time or 
 * underlying platform implementation is failed.
 */

/**
 * @brief Ensure PLAT_INIT() returns correct error codes during all of this API's invocation scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_INIT() should return PWRMGR_SUCCESS when initializing the module.
 * 2. PLAT_INIT() should return PWRMGR_ALREADY_INITIALIZED when trying to initialize again.
 * 3. PLAT_TERM() should return PWRMGR_SUCCESS after successful termination.
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 001@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |02|Call PLAT_INIT() again | | PWRMGR_ALREADY_INITIALIZED | Should Pass |
 * |03|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_PLAT_INIT(void)
{
    // Step 01
    pmStatus_t status = PLAT_INIT();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 02
    status = PLAT_INIT();
    UT_ASSERT_EQUAL(PWRMGR_ALREADY_INITIALIZED, status);

    // Step 03
    status = PLAT_TERM();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);
}

/**
 * @brief Ensure PLAT_API_SetPowerState() returns correct error codes during all of this API's invocation scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_INIT() is called to initialize power manager.
 * 2. PLAT_API_SetPowerState() should return PWRMGR_SUCCESS by setting a proper state.
 * 3. PLAT_TERM() should return PWRMGR_SUCCESS after successful termination.
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 002@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |02|Call PLAT_API_SetPowerState() - set a power state | newState=PWRMGR_POWERSTATE_ON | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_PLAT_API_SetPowerState_positive(void)
{
    // Step 01
    pmStatus_t status = PLAT_INIT();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 02
    status = PLAT_API_SetPowerState(PWRMGR_POWERSTATE_ON);
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 03
    status = PLAT_TERM();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);
}

/**
 * @brief Ensure PLAT_API_GetPowerState() returns correct error codes during all of this API's invocation scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_INIT() is called to initialize power manager.
 * 2. PLAT_API_GetPowerState() should return PWRMGR_SUCCESS by retrieving the state correctly.
 * 3. PLAT_TERM() should return PWRMGR_SUCCESS after successful termination.
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 003@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |02|Call PLAT_API_GetPowerState() - get power state | | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_PLAT_API_GetPowerState_positive(void)
{
    // Step 01
    pmStatus_t status = PLAT_INIT();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 02
    PWRMgr_PowerState_t curState;
    status = PLAT_API_GetPowerState(&curState);
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 03
    status = PLAT_TERM();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);
}

/**
 * @brief Ensure PLAT_API_SetWakeupSrc() returns correct error codes during all of this API's invocation scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_INIT() is called to initialize power manager.
 * 2. PLAT_API_SetWakeupSrc() should return PWRMGR_SUCCESS by setting a valid wakeup source.
 * 3. PLAT_TERM() should return PWRMGR_SUCCESS after successful termination.
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 004@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |02|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=WAKEUPSRC_VOICE | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_PLAT_API_SetWakeupSrc_positive(void)
{
    // Step 01
    pmStatus_t status = PLAT_INIT();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 02
    status = PLAT_API_SetWakeupSrc(WAKEUPSRC_VOICE);
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 03
    status = PLAT_TERM();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);
}

/**
 * @brief Ensure PLAT_API_GetWakeupSrc() returns correct error codes during all of this API's invocation scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_INIT() is called to initialize power manager.
 * 2. PLAT_API_GetWakeupSrc() should return PWRMGR_SUCCESS by retrieving the wakeup source correctly.
 * 3. PLAT_TERM() should return PWRMGR_SUCCESS after successful termination.
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 005@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |02|Call PLAT_API_GetWakeupSrc() - get wakeup source | | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_PLAT_API_GetWakeupSrc_positive(void)
{
    // Step 01
    pmStatus_t status = PLAT_INIT();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 02
    PWRMgr_WakeupSrc_t curSrc;
    status = PLAT_API_GetWakeupSrc(&curSrc);
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 03
    status = PLAT_TERM();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);
}

/**
 * @brief Ensure PLAT_TERM() returns correct error codes during all of this API's invocation scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_INIT() is called to initialize power manager.
 * 2. PLAT_TERM() should return PWRMGR_SUCCESS by terminating the power manager correctly.
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 006@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |02|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_PLAT_TERM(void)
{
    // Step 01
    pmStatus_t status = PLAT_INIT();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 02
    status = PLAT_TERM();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);
}

/**
 * @brief Ensure PLAT_API_SetPowerState() returns correct error codes during negative scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_API_SetPowerState() should return PWRMGR_NOT_INITIALIZED due to power manager not being initialized.
 * 2. Call PLAT_INIT() to initialize power manager.
 * 3. PLAT_API_SetPowerState() will return PWRMGR_INVALID_ARGUMENT by sending an invalid value.
 * 4. PLAT_TERM() will return PWRMGR_SUCCESS during successive calls
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 007@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |01|Call PLAT_API_SetPowerState() - call without initializing the module | newState=PWRMGR_POWERSTATE_ON | PWRMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_SetPowerState() - call with invalid value | invalidState=100 | PWRMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_PLAT_API_SetPowerState_negative(void)
{
    // Step 01
    pmStatus_t status = PLAT_API_SetPowerState(PWRMGR_POWERSTATE_ON);
    UT_ASSERT_EQUAL(PWRMGR_NOT_INITIALIZED, status);

    // Step 02
    status = PLAT_INIT();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 03
    status = PLAT_API_SetPowerState(100);
    UT_ASSERT_EQUAL(PWRMGR_INVALID_ARGUMENT, status);

    // Step 04
    status = PLAT_TERM();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);
}

/**
 * @brief Ensure PLAT_API_GetPowerState() returns correct error codes during negative scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_API_GetPowerState() should return PWRMGR_NOT_INITIALIZED due to power manager not being initialized.
 * 2. Call PLAT_INIT() to initialize power manager.
 * 3. PLAT_API_GetPowerState() will return PWRMGR_INVALID_ARGUMENT by sending an invalid value.
 * 4. PLAT_TERM() will return PWRMGR_SUCCESS during successive calls
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 008@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |01|Call PLAT_API_GetPowerState() - call without initializing the module | curState=NULL | PWRMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_GetPowerState() - call with NULL pointer | NULL | PWRMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_PLAT_API_GetPowerState_negative(void)
{
    // Step 01
    pmStatus_t status = PLAT_API_GetPowerState(NULL);
    UT_ASSERT_EQUAL(PWRMGR_NOT_INITIALIZED, status);

    // Step 02
    status = PLAT_INIT();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 03
    status = PLAT_API_GetPowerState(NULL);
    UT_ASSERT_EQUAL(PWRMGR_INVALID_ARGUMENT, status);

    // Step 04
    status = PLAT_TERM();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);
}

/**
 * @brief Ensure PLAT_API_SetWakeupSrc() returns correct error codes during negative scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_API_SetWakeupSrc() should return PWRMGR_NOT_INITIALIZED due to power manager not being initialized.
 * 2. Call PLAT_INIT() to initialize power manager.
 * 3. PLAT_API_SetWakeupSrc() will return PWRMGR_INVALID_ARGUMENT by sending an invalid value.
 * 4. PLAT_TERM() will return PWRMGR_SUCCESS during successive calls
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 009@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |01|Call PLAT_API_SetWakeupSrc() - call without initializing the module | newState=WAKEUPSRC_VOICE | PWRMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_SetWakeupSrc() - call with invalid value | invalidState=100 | PWRMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_PLAT_API_SetWakeupSrc_negative(void)
{
    // Step 01
    pmStatus_t status = PLAT_API_SetWakeupSrc(WAKEUPSRC_VOICE);
    UT_ASSERT_EQUAL(PWRMGR_NOT_INITIALIZED, status);

    // Step 02
    status = PLAT_INIT();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 03
    status = PLAT_API_SetWakeupSrc(100);
    UT_ASSERT_EQUAL(PWRMGR_INVALID_ARGUMENT, status);

    // Step 04
    status = PLAT_TERM();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);
}

/**
 * @brief Ensure PLAT_API_GetWakeupSrc() returns correct error codes during negative scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_API_GetWakeupSrc() should return PWRMGR_NOT_INITIALIZED due to power manager not being initialized.
 * 2. Call PLAT_INIT() to initialize power manager.
 * 3. PLAT_API_GetWakeupSrc() will return PWRMGR_INVALID_ARGUMENT by sending an invalid value.
 * 4. PLAT_TERM() will return PWRMGR_SUCCESS during successive calls
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 010@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |01|Call PLAT_API_GetWakeupSrc() - call without initializing the module | curSrc=NULL | PWRMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_GetWakeupSrc() - call with NULL pointer | NULL | PWRMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_PLAT_API_GetWakeupSrc_negative(void)
{
    // Step 01
    pmStatus_t status = PLAT_API_GetWakeupSrc(NULL);
    UT_ASSERT_EQUAL(PWRMGR_NOT_INITIALIZED, status);

    // Step 02
    status = PLAT_INIT();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);

    // Step 03
    status = PLAT_API_GetWakeupSrc(NULL);
    UT_ASSERT_EQUAL(PWRMGR_INVALID_ARGUMENT, status);

    // Step 04
    status = PLAT_TERM();
    UT_ASSERT_EQUAL(PWRMGR_SUCCESS, status);
}

static UT_test_suite_t *pSuite = NULL;

/**
 * @brief This function registers all the test cases
 * 
 * This function creates a test suite, and adds all test cases to this suite. 
 * It is called by the test runner.
 */
int RegisterTestCases(void)
{

    pSuite = UT_add_suite("L1 Power Manager Test Suite", NULL, NULL);
    if (NULL == pSuite) {
         return -1;
    }

    // Add all the test cases
    UT_add_test(pSuite, "L1 test case for PLAT_INIT() - Positive", test_PLAT_INIT);
    UT_add_test(pSuite, "L1 test case for PLAT_TERM() - Positive", test_PLAT_TERM);
    UT_add_test(pSuite, "L1 test case for PLAT_API_SetPowerState() - Positive", test_PLAT_API_SetPowerState_positive);
    UT_add_test(pSuite, "L1 test case for PLAT_API_SetPowerState() - Negative", test_PLAT_API_SetPowerState_negative);
    UT_add_test(pSuite, "L1 test case for PLAT_API_GetPowerState() - Positive", test_PLAT_API_GetPowerState_positive);
    UT_add_test(pSuite, "L1 test case for PLAT_API_GetPowerState() - Negative", test_PLAT_API_GetPowerState_negative);
    UT_add_test(pSuite, "L1 test case for PLAT_API_SetWakeupSrc() - Positive", test_PLAT_API_SetWakeupSrc_positive);
    UT_add_test(pSuite, "L1 test case for PLAT_API_SetWakeupSrc() - Negative", test_PLAT_API_SetWakeupSrc_negative);
    UT_add_test(pSuite, "L1 test case for PLAT_API_GetWakeupSrc() - Positive", test_PLAT_API_GetWakeupSrc_positive);
    UT_add_test(pSuite, "L1 test case for PLAT_API_GetWakeupSrc() - Negative", test_PLAT_API_GetWakeupSrc_negative);

    return 0;
}
