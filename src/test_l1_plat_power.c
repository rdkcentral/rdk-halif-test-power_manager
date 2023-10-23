/**
*  If not stated otherwise in this file or this component's Licenses.txt
*  file the following copyright and licenses apply:
*
*  Copyright 2022 RDK Management
*
*  Licensed under the Apache License, Version 2.0 (the License);
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*  http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an AS IS BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*/

/**
 * @addtogroup HPK Hardware Porting Kit
 * @{
 * @par The Hardware Porting Kit
 * HPK is the next evolution of the well-defined Hardware Abstraction Layer
 * (HAL), but augmented with more comprehensive documentation and test suites
 * that OEM or SOC vendors can use to self-certify their ports before taking
 * them to RDKM for validation or to an operator for final integration and
 * deployment. The Hardware Porting Kit effectively enables an OEM and/or SOC
 * vendor to self-certify their own Video Accelerator devices, with minimal RDKM
 * assistance.
 *
 */

/**
 * @addtogroup POWER_MANAGER Power Manager Module
 * @{
 */

/**
 * @addtogroup POWER_MANAGER_HALTEST Power Manager HAL Tests
 * @{
 */

/**
 * @defgroup PLAT_POWER_HALTEST_L1 Power Manager L1 Test Cases
 * @{
 */

/**
* @file test_l1_plat_power.c
* @page POWER_MANAGER_L1_Tests POWER_MANAGER Level 1 Tests
*
* ## Module's Role
* This module includes Level 1 functional tests (success and failure scenarios)
* This is to ensure that the API meets the operational requirements of the Power Manager across all vendors
*
* **Pre-Conditions:**  None@n
* **Dependencies:** None@n
*
* Ref to API Definition specification documentation : [power-manager_halSpec.md](../../../docs/pages/power-manager_halSpec.md)
*/

#include <string.h>
#include <stdlib.h>

#include "plat_power.h"
#include <stdbool.h>
#include <ut.h>
#include <ut_log.h>

static int gTestGroup = 1;
static int gTestID = 1;

/**
 * @brief Ensure PLAT_INIT() returns correct error codes during positive scenarios
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
 * |02|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_l1_plat_power_positive_PLAT_INIT (void)
{
    gTestID = 1;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID); 
	pmStatus_t ret;

    // Variation/Step 01: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 02: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    UT_LOG("\n Out %s\n", __FUNCTION__); 
}

/**
 * @brief Ensure PLAT_INIT() returns correct error codes during negative scenarios
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 002@n
 * 
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
 * |02|Call PLAT_INIT() - again open interface | | PWRMGR_ALREADY_INITIALIZED | Should Pass |
 * |03|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 * 
 * @note The error code PWRMGR_INIT_FAILURE is not able to be tested here.
 */
void test_l1_plat_power_negative_PLAT_INIT (void)
{
    gTestID = 2;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	pmStatus_t ret;

    // Variation/Step 01: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 02: Call PLAT_INIT() - again open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_ALREADY_INITIALIZED); // Ensure the returned value is PWRMGR_ALREADY_INITIALIZED

    // Variation/Step 03: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    UT_LOG("\n Out %s\n", __FUNCTION__); 
}


/**
 * @brief Ensure PLAT_TERM() returns correct error codes during positive scenarios
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
 * |02|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_l1_plat_power_positive_PLAT_TERM (void)
{
    gTestID = 3;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	 pmStatus_t ret;

    // Variation/Step 01: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 02: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS
    UT_LOG("\n Out %s\n", __FUNCTION__); 
}

/**
 * @brief Ensure PLAT_TERM() returns correct error codes during negative scenarios
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
 * |01|Call PLAT_TERM() - close interface | | PWRMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * |04|Call PLAT_TERM() - close interface again | | PWRMGR_NOT_INITIALIZED | Should Pass |
 * 
 * @note The error code PWRMGR_TERM_FAILURE is not able to be tested here.
 */
void test_l1_plat_power_negative_PLAT_TERM (void)
{
    gTestID = 4;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	pmStatus_t ret;

    // Variation/Step 01: Call PLAT_TERM() - close interface without initializing
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_NOT_INITIALIZED); // Ensure the returned value is PWRMGR_NOT_INITIALIZED

    // Variation/Step 02: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 03: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 04: Call PLAT_TERM() - close interface again
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_NOT_INITIALIZED); // Ensure the returned value is PWRMGR_NOT_INITIALIZED
    UT_LOG("\n Out %s\n", __FUNCTION__); 
}

/**
 * @brief Ensure PLAT_API_SetPowerState() returns correct error codes during positive scenarios
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
 * |02|Call PLAT_API_SetPowerState() - set a power state | newState=PWRMGR_POWERSTATE_STANDBY_DEEP_SLEEP | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_SetPowerState() - set a power state | newState=PWRMGR_POWERSTATE_STANDBY_LIGHT_SLEEP | PWRMGR_SUCCESS | Should Pass |
 * |04|Call PLAT_API_SetPowerState() - set a power state | newState=PWRMGR_POWERSTATE_ON | PWRMGR_SUCCESS | Should Pass |
 * |05|Call PLAT_API_SetPowerState() - set a power state | newState=PWRMGR_POWERSTATE_STANDBY | PWRMGR_SUCCESS | Should Pass |
 * |06|Call PLAT_API_SetPowerState() - set a power state | newState=PWRMGR_POWERSTATE_OFF | PWRMGR_SUCCESS | Should Pass |
 * |07|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_l1_plat_power_positive_PLAT_API_SetPowerState (void)
{
    gTestID = 5;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	pmStatus_t ret;

    // Variation/Step 01: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    PWRMgr_PowerState_t powerStates[] = {
        PWRMGR_POWERSTATE_STANDBY_DEEP_SLEEP,
        PWRMGR_POWERSTATE_STANDBY_LIGHT_SLEEP,
        PWRMGR_POWERSTATE_ON,
        PWRMGR_POWERSTATE_STANDBY,
        PWRMGR_POWERSTATE_OFF
    };

    // Variation/step 02-06: Call PLAT_API_SetPowerState() - set a power state
    for (int i = 0; i < sizeof(powerStates); i++) {
        UT_LOG("\n Function: %s Setting power state :[%d]\n", __FUNCTION__, powerStates[i]);
        ret = PLAT_API_SetPowerState(powerStates[i]);
        UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS
    }

    // Variation/Step 07: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS
    UT_LOG("\n Out %s\n", __FUNCTION__); 
}

/**
 * @brief Ensure PLAT_API_SetPowerState() returns correct error codes during negative scenarios
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
 * |01|Call PLAT_API_SetPowerState() - call without initializing the module | newState=PWRMGR_POWERSTATE_ON | PWRMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_SetPowerState() - call with invalid value | newState=PWRMGR_POWERSTATE_MAX | PWRMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * |05|Call PLAT_API_SetPowerState() - call after terminating the module | newState=PWRMGR_POWERSTATE_ON | PWRMGR_NOT_INITIALIZED | Should Pass |
 * 
 * 
 * @note The error code PWRMGR_SET_FAILURE is not able to be tested here.
 */
void test_l1_plat_power_negative_PLAT_API_SetPowerState (void)
{
    gTestID = 6;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	pmStatus_t ret;

    // Variation/Step 01: Call PLAT_API_SetPowerState() - call without initializing the module
    ret = PLAT_API_SetPowerState(PWRMGR_POWERSTATE_ON);
    UT_ASSERT_EQUAL(ret, PWRMGR_NOT_INITIALIZED); // Ensure the returned value is PWRMGR_NOT_INITIALIZED

    // Variation/Step 02: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 03: Call PLAT_API_SetPowerState() - call with invalid value
    ret = PLAT_API_SetPowerState(PWRMGR_POWERSTATE_MAX);
    UT_ASSERT_EQUAL(ret, PWRMGR_INVALID_ARGUMENT); // Ensure the returned value is PWRMGR_INVALID_ARGUMENT

    // Variation/Step 04: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 05: Call PLAT_API_SetPowerState() - call after terminating the module
    ret = PLAT_API_SetPowerState(PWRMGR_POWERSTATE_ON);
    UT_ASSERT_EQUAL(ret, PWRMGR_NOT_INITIALIZED); // Ensure the returned value is PWRMGR_NOT_INITIALIZED 
    UT_LOG("\n Out %s\n", __FUNCTION__); 
}

/**
 * @brief Ensure PLAT_API_GetPowerState() returns correct error codes during positive scenarios
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 007@n
 * 
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
 * |02|Call PLAT_API_GetPowerState() - get power state | curState* | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_GetPowerState() - get power state | curState* | PWRMGR_SUCCESS | Should Pass |
 * |04|Verify that PLAT_API_GetPowerState() calls returns the same value | | | Should Pass |
 * |05|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_l1_plat_power_positive_PLAT_API_GetPowerState (void)
{
    gTestID = 7;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	pmStatus_t ret;
    PWRMgr_PowerState_t state1, state2;

    // Variation/Step 01: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 02: Call PLAT_API_GetPowerState() - get power state
    ret = PLAT_API_GetPowerState(&state1);
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 03: Call PLAT_API_GetPowerState() - get power state
    ret = PLAT_API_GetPowerState(&state2);
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 04: Verify that PLAT_API_GetPowerState() calls return the same value
    UT_ASSERT_EQUAL(state1, state2); // Ensure both states are the same

    // Variation/Step 05: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS
    UT_LOG("\n Out %s\n", __FUNCTION__); 
}

/**
 * @brief Ensure PLAT_API_GetPowerState() returns correct error codes during negative scenarios
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
 * |01|Call PLAT_API_GetPowerState() - call without initializing the module | curState* | PWRMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_GetPowerState() - call with NULL pointer | curState*=NULL | PWRMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * |05|Call PLAT_API_GetPowerState() - call after terminating the module | curState* | PWRMGR_NOT_INITIALIZED | Should Pass |
 * 
 * 
 * @note The error code PWRMGR_GET_FAILURE is not able to be tested here.
 */
void test_l1_plat_power_negative_PLAT_API_GetPowerState (void)
{
    gTestID = 8;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	pmStatus_t ret;
    PWRMgr_PowerState_t state;

    // Variation/Step 01: Call PLAT_API_GetPowerState() - call without initializing the module
    ret = PLAT_API_GetPowerState(&state);
    UT_ASSERT_EQUAL(ret, PWRMGR_NOT_INITIALIZED); // Ensure the returned value is PWRMGR_NOT_INITIALIZED

    // Variation/Step 02: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 03: Call PLAT_API_GetPowerState() - call with NULL pointer
    ret = PLAT_API_GetPowerState(NULL);
    UT_ASSERT_EQUAL(ret, PWRMGR_INVALID_ARGUMENT); // Ensure the returned value is PWRMGR_INVALID_ARGUMENT

    // Variation/Step 04: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 05: Call PLAT_API_GetPowerState() - call after terminating the module
    ret = PLAT_API_GetPowerState(&state);
    UT_ASSERT_EQUAL(ret, PWRMGR_NOT_INITIALIZED); // Ensure the returned value is PWRMGR_NOT_INITIALIZED
    UT_LOG("\n Out %s\n", __FUNCTION__); 
}

/**
 * @brief Ensure PLAT_API_SetWakeupSrc() returns correct error codes during positive scenarios
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
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |02|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_VOICE, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_VOICE, enabled=true | PWRMGR_SUCCESS | Should Pass |
 * |04|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_PRESENCE_DETECTION, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |05|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_PRESENCE_DETECTION, enabled=true | PWRMGR_SUCCESS | Should Pass |
 * |06|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_BLUETOOTH, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |07|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_BLUETOOTH, enabled=true | PWRMGR_SUCCESS | Should Pass |
 * |08|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_WIFI, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |09|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_WIFI, enabled=true | PWRMGR_SUCCESS | Should Pass |
 * |10|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_IR, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |11|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_IR, enabled=true | PWRMGR_SUCCESS | Should Pass |
 * |12|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_POWER_KEY, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |13|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_POWER_KEY, enabled=true | PWRMGR_SUCCESS | Should Pass |
 * |14|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_TIMER, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |15|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_TIMER, enabled=true | PWRMGR_SUCCESS | Should Pass |
 * |16|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_CEC, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |17|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_CEC, enabled=true | PWRMGR_SUCCESS | Should Pass |
 * |18|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_LAN, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |19|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_LAN, enabled=true | PWRMGR_SUCCESS | Should Pass |
 * |20|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_l1_plat_power_positive_PLAT_API_SetWakeupSrc (void)
{
    gTestID = 9;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	pmStatus_t ret;

    // Variation/Step 01: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    typedef struct {
        PWRMGR_WakeupSrcType_t src;
        bool enabled;
    } WakeupTest;

    WakeupTest tests[] = {
        { PWRMGR_WAKEUPSRC_VOICE, false },
        { PWRMGR_WAKEUPSRC_VOICE, true },
        { PWRMGR_WAKEUPSRC_PRESENCE_DETECTION, false },
        { PWRMGR_WAKEUPSRC_PRESENCE_DETECTION, true },
        { PWRMGR_WAKEUPSRC_BLUETOOTH, false },
        { PWRMGR_WAKEUPSRC_BLUETOOTH, true },
        { PWRMGR_WAKEUPSRC_WIFI, false },
        { PWRMGR_WAKEUPSRC_WIFI, true },
        { PWRMGR_WAKEUPSRC_IR, false },
        { PWRMGR_WAKEUPSRC_IR, true },
        { PWRMGR_WAKEUPSRC_POWER_KEY, false },
        { PWRMGR_WAKEUPSRC_POWER_KEY, true },
        { PWRMGR_WAKEUPSRC_TIMER, false },
        { PWRMGR_WAKEUPSRC_TIMER, true },
        { PWRMGR_WAKEUPSRC_CEC, false },
        { PWRMGR_WAKEUPSRC_CEC, true },
        { PWRMGR_WAKEUPSRC_LAN, false },
        { PWRMGR_WAKEUPSRC_LAN,true }
    };

    // Variation/Step 2-19: Verify that the function runs properly with each possible input
    for(int i = 0; i < sizeof(tests); i++) {
        UT_LOG("\n Function: %s Wake up source test inputs values :[%d%d]\n", __FUNCTION__, tests[i].src, tests[i].enabled);
        ret = PLAT_API_SetWakeupSrc(tests[i].src, tests[i].enabled);
        if(ret == PWRMGR_OPERATION_NOT_SUPPORTED){// Check for operation not supported case
            UT_ASSERT_EQUAL(ret, PWRMGR_OPERATION_NOT_SUPPORTED)
            UT_LOG("\n Function: %s Wake up source is not supported\n", __FUNCTION__);
        } 
        else{
            UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS)
        }

    }

    // Variation/Step 20: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS
    UT_LOG("\n Out %s\n", __FUNCTION__); 
}

/**
 * @brief Ensure PLAT_API_SetWakeupSrc() returns correct error codes during negative scenarios
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
 * |01|Call PLAT_API_SetWakeupSrc() - call without initializing the module | newState=WAKEUPSRC_VOICE, enabled=false | PWRMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_SetWakeupSrc() - call with invalid value | newState=PWRMGR_WAKEUPSRC_MAX | PWRMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * |05|Call PLAT_API_SetWakeupSrc() - call after terminating the module | newState=WAKEUPSRC_VOICE, enabled=false | PWRMGR_NOT_INITIALIZED | Should Pass |
 * 
 * @note The error code PWRMGR_SET_FAILURE is not able to be tested here.
 */
void test_l1_plat_power_negative_PLAT_API_SetWakeupSrc (void)
{
    gTestID = 10;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	pmStatus_t ret;

    // Variation/Step 01: Call PLAT_API_SetWakeupSrc() - call without initializing the module
    ret = PLAT_API_SetWakeupSrc(PWRMGR_WAKEUPSRC_VOICE, false);
    UT_ASSERT_EQUAL(ret, PWRMGR_NOT_INITIALIZED); // Ensure the returned value is PWRMGR_NOT_INITIALIZED

    // Variation/Step 02: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 03: Call PLAT_API_SetWakeupSrc() - call with invalid value
    ret = PLAT_API_SetWakeupSrc(PWRMGR_WAKEUPSRC_MAX, false);
    UT_ASSERT_EQUAL(ret, PWRMGR_INVALID_ARGUMENT); // Ensure the returned value is PWRMGR_INVALID_ARGUMENT

    // Variation/Step 04: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 05: Call PLAT_API_SetWakeupSrc() - call after terminating the module
    ret = PLAT_API_SetWakeupSrc(PWRMGR_WAKEUPSRC_VOICE, false);
    UT_ASSERT_EQUAL(ret, PWRMGR_NOT_INITIALIZED); // Ensure the returned value is PWRMGR_NOT_INITIALIZED
    UT_LOG("\n Out %s\n", __FUNCTION__); 
}

/**
 * @brief Ensure PLAT_API_GetWakeupSrc() returns correct error codes during positive scenarios
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 011@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * @todo Do the double check first
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |02|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_VOICE, *enable| PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_PRESENCE_DETECTION, *enable| PWRMGR_SUCCESS | Should Pass |
 * |04|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_BLUETOOTH, *enable| PWRMGR_SUCCESS | Should Pass |
 * |05|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_WIFI, *enable| PWRMGR_SUCCESS | Should Pass |
 * |06|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_IR, *enable| PWRMGR_SUCCESS | Should Pass |
 * |07|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_POWER_KEY, *enable| PWRMGR_SUCCESS | Should Pass |
 * |08|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_TIMER, *enable| PWRMGR_SUCCESS | Should Pass |
 * |09|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_CEC, *enable| PWRMGR_SUCCESS | Should Pass |
 * |10|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_LAN, *enable| PWRMGR_SUCCESS | Should Pass |
 * |11|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_LAN, *enable| PWRMGR_SUCCESS | Should Pass |
 * |12|Verify that PLAT_API_GetWakeupSrc() returns the same values upon return | | | Should Pass |
 * |13|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_l1_plat_power_positive_PLAT_API_GetWakeupSrc (void)
{
    gTestID = 11;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	pmStatus_t ret;
    bool enable1, enable2;

    // Step 01: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS);

    //Move IR to be the double at the end.
    PWRMGR_WakeupSrcType_t sources[] = {
        PWRMGR_WAKEUPSRC_VOICE,
        PWRMGR_WAKEUPSRC_PRESENCE_DETECTION,
        PWRMGR_WAKEUPSRC_BLUETOOTH,
        PWRMGR_WAKEUPSRC_WIFI,
        PWRMGR_WAKEUPSRC_IR,
        PWRMGR_WAKEUPSRC_POWER_KEY,
        PWRMGR_WAKEUPSRC_TIMER,
        PWRMGR_WAKEUPSRC_CEC,
        PWRMGR_WAKEUPSRC_LAN,
        PWRMGR_WAKEUPSRC_LAN  // Intentional duplicate for verification
    };

    // Step 2-11: Verify that using all the wake up sources do not throw errors
    for (int i = 0; i < sizeof(sources); i++) {
        UT_LOG("\n Function: %s Wake up source :[%d]\n", __FUNCTION__, sources[i]);
        ret = PLAT_API_GetWakeupSrc(sources[i], &enable1);
        UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS);

        if (i == sizeof(sources) - 2) {
            // Save the result from the penultimate call
            enable2 = enable1;
        }
    }

    // Step 12: Verify that the last two PLAT_API_GetWakeupSrc() calls return the same value
    UT_ASSERT_EQUAL(enable1, enable2);

    // Step 13: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS);
    UT_LOG("\n Out %s\n", __FUNCTION__); 
}

/**
 * @brief Ensure PLAT_API_GetWakeupSrc() returns correct error codes during negative scenarios
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 012@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |01|Call PLAT_API_GetWakeupSrc() - call without initializing the module | srcType, *enable | PWRMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_GetWakeupSrc() - call with NULL pointer | srcType, *enable=NULL | PWRMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * |05|Call PLAT_API_GetWakeupSrc() - call after terminating the module | srcType, *enable | PWRMGR_NOT_INITIALIZED | Should Pass |
 * 
 * 
 * @note The error code PWRMGR_GET_FAILURE is not able to be tested here.
 */
void test_l1_plat_power_negative_PLAT_API_GetWakeupSrc (void)
{
    gTestID = 12;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	pmStatus_t ret;
    bool enable;
    PWRMGR_WakeupSrcType_t srcType = PWRMGR_WAKEUPSRC_VOICE; // You can choose any valid srcType for this test

    // Variation/Step 01: Call PLAT_API_GetWakeupSrc() - call without initializing the module
    ret = PLAT_API_GetWakeupSrc(srcType, &enable);
    UT_ASSERT_EQUAL(ret, PWRMGR_NOT_INITIALIZED); // Ensure the returned value is PWRMGR_NOT_INITIALIZED

    // Variation/Step 02: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 03: Call PLAT_API_GetWakeupSrc() - call with NULL pointer
    ret = PLAT_API_GetWakeupSrc(srcType, NULL);
    UT_ASSERT_EQUAL(ret, PWRMGR_INVALID_ARGUMENT); // Ensure the returned value is PWRMGR_INVALID_ARGUMENT

    // Variation/Step 04: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Variation/Step 05: Call PLAT_API_GetWakeupSrc() - call after terminating the module
    ret = PLAT_API_GetWakeupSrc(srcType, &enable);
    UT_ASSERT_EQUAL(ret, PWRMGR_NOT_INITIALIZED); // Ensure the returned value is PWRMGR_NOT_INITIALIZED
    UT_LOG("\n Out %s\n", __FUNCTION__); 
}

/**
 * @brief Ensure PLAT_Reset() returns correct error codes during positive scenarios
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 013@n
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
 * |02|Call PLAT_Reset() - set a power state | newState=PWRMGR_POWERSTATE_STANDBY_DEEP_SLEEP | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_Reset() - set a power state | newState=PWRMGR_POWERSTATE_STANDBY_LIGHT_SLEEP | PWRMGR_SUCCESS | Should Pass |
 * |04|Call PLAT_Reset() - set a power state | newState=PWRMGR_POWERSTATE_ON | PWRMGR_SUCCESS | Should Pass |
 * |05|Call PLAT_Reset() - set a power state | newState=PWRMGR_POWERSTATE_STANDBY | PWRMGR_SUCCESS | Should Pass |
 * |06|Call PLAT_Reset() - set a power state | newState=PWRMGR_POWERSTATE_OFF | PWRMGR_SUCCESS | Should Pass |
 * |07|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_l1_plat_power_positive_PLAT_Reset (void)
{
    gTestID = 13;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	pmStatus_t ret;
    PWRMgr_PowerState_t powerStates[] = {
        PWRMGR_POWERSTATE_STANDBY_DEEP_SLEEP,
        PWRMGR_POWERSTATE_STANDBY_LIGHT_SLEEP,
        PWRMGR_POWERSTATE_ON,
        PWRMGR_POWERSTATE_STANDBY,
        PWRMGR_POWERSTATE_OFF
    };

    // Step 01: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS);

    // Loop over each power state and call PLAT_Reset()
    for (int i = 0; i < sizeof(powerStates) / sizeof(PWRMgr_PowerState_t); i++) {
        UT_LOG("\n Function: %s Setting power state :[%d]\n", __FUNCTION__, powerStates[i]);
        ret = PLAT_Reset(powerStates[i]);
        UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS
    }

    // Step 07: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS
    UT_LOG("\n Out %s\n", __FUNCTION__); 
}

/**
 * @brief Ensure PLAT_Reset() returns correct error codes during negative scenarios
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 014@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |01|Call PLAT_Reset() - call without initializing the module | newState=PWRMGR_POWERSTATE_ON | PWRMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_Reset() - call with invalid value | newState=PWRMGR_POWERSTATE_MAX | PWRMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * |05|Call PLAT_Reset() - call after terminating the module | newState=PWRMGR_POWERSTATE_ON | PWRMGR_NOT_INITIALIZED | Should Pass |
 * 
 * 
 * @note The error code PWRMGR_SET_FAILURE is not able to be tested here.
 */
void test_l1_plat_power_negative_PLAT_Reset (void)
{
    gTestID = 14;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	pmStatus_t ret;
    
    // Step 01: Call PLAT_Reset() - call without initializing the module
    ret = PLAT_Reset(PWRMGR_POWERSTATE_ON);
    UT_ASSERT_EQUAL(ret, PWRMGR_NOT_INITIALIZED); // Ensure the returned value is PWRMGR_NOT_INITIALIZED

    // Step 02: Call PLAT_INIT() - open interface
    ret = PLAT_INIT();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Step 03: Call PLAT_Reset() - call with invalid value
    ret = PLAT_Reset(PWRMGR_POWERSTATE_MAX);
    UT_ASSERT_EQUAL(ret, PWRMGR_INVALID_ARGUMENT); // Ensure the returned value is PWRMGR_INVALID_ARGUMENT

    // Step 04: Call PLAT_TERM() - close interface
    ret = PLAT_TERM();
    UT_ASSERT_EQUAL(ret, PWRMGR_SUCCESS); // Ensure the returned value is PWRMGR_SUCCESS

    // Step 05: Call PLAT_Reset() - call after terminating the module
    ret = PLAT_Reset(PWRMGR_POWERSTATE_ON);
    UT_ASSERT_EQUAL(ret, PWRMGR_NOT_INITIALIZED); // Ensure the returned value is PWRMGR_NOT_INITIALIZED
    UT_LOG("\n Out %s\n", __FUNCTION__); 
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main test(s) for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int test_l1_plat_power_register ( void )
{
	/* add a suite to the registry */
	pSuite = UT_add_suite( "[L1 plat_power]", NULL, NULL );
	if ( NULL == pSuite )
	{
		return -1;
	}	

	UT_add_test( pSuite, "PLAT_INIT_L1_positive" ,test_l1_plat_power_positive_PLAT_INIT );
	UT_add_test( pSuite, "PLAT_INIT_L1_negative" ,test_l1_plat_power_negative_PLAT_INIT );
    UT_add_test( pSuite, "PLAT_TERM_L1_positive" ,test_l1_plat_power_positive_PLAT_TERM );
	UT_add_test( pSuite, "PLAT_TERM_L1_negative" ,test_l1_plat_power_negative_PLAT_TERM );
	UT_add_test( pSuite, "PLAT_API_SetPowerState_L1_positive" ,test_l1_plat_power_positive_PLAT_API_SetPowerState );
	UT_add_test( pSuite, "PLAT_API_SetPowerState_L1_negative" ,test_l1_plat_power_negative_PLAT_API_SetPowerState );
	UT_add_test( pSuite, "PLAT_API_GetPowerState_L1_positive" ,test_l1_plat_power_positive_PLAT_API_GetPowerState );
	UT_add_test( pSuite, "PLAT_API_GetPowerState_L1_negative" ,test_l1_plat_power_negative_PLAT_API_GetPowerState );
	UT_add_test( pSuite, "PLAT_API_SetWakeupSrc_L1_positive" ,test_l1_plat_power_positive_PLAT_API_SetWakeupSrc );
	UT_add_test( pSuite, "PLAT_API_SetWakeupSrc_L1_negative" ,test_l1_plat_power_negative_PLAT_API_SetWakeupSrc );
	UT_add_test( pSuite, "PLAT_API_GetWakeupSrc_L1_positive" ,test_l1_plat_power_positive_PLAT_API_GetWakeupSrc );
	UT_add_test( pSuite, "PLAT_API_GetWakeupSrc_L1_negative" ,test_l1_plat_power_negative_PLAT_API_GetWakeupSrc );
	UT_add_test( pSuite, "PLAT_Reset_L1_positive" ,test_l1_plat_power_positive_PLAT_Reset );
	UT_add_test( pSuite, "PLAT_Reset_L1_negative" ,test_l1_plat_power_negative_PLAT_Reset );
	

	return 0;
} 
/** @} */ // End of PLAT_POWER_HALTEST_L1
/** @} */ // End of POWER_MANAGER_HALTEST
/** @} */ // End of POWER_MANAGER
/** @} */ // End of HPK
