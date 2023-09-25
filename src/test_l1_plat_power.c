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
* @file TODO: test_l1_plat_power.c
* @page module_name TODO: Required field, name of the main module
* @subpage sub_page_name TODO: Add a function group if relevant
*
* ## Module's Role
* TODO: Explain the module's role in the system in general
* This is to ensure that the API meets the operational requirements of the module across all vendors.
*
* **Pre-Conditions:**  TODO: Add pre-conditions if any@n
* **Dependencies:** TODO: Add dependencies if any@n
*
* Ref to API Definition specification documentation : [halSpec.md](../../../docs/halSpec.md)
*/

#include <string.h>
#include <stdlib.h>

#include <ut.h>
#include <ut_log.h>

/**
 * @brief Ensure PLAT_INIT() returns correct error codes during positive scenarios
 * @todo Check to see additional failures to see if they can be trigger. If not, mention that they are not reproducible
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
	UT_FAIL(This function needs to be implemented!); 
}

/**
 * @brief Ensure PLAT_INIT() returns correct error codes during negative scenarios
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
 * |02|Call PLAT_INIT() again | | PWRMGR_ALREADY_INITIALIZED | Should Pass |
 * |03|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_l1_plat_power_negative_PLAT_INIT (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
	UT_FAIL(This function needs to be implemented!); 
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
 */
void test_l1_plat_power_negative_PLAT_TERM (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
	UT_FAIL(This function needs to be implemented!); 
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
 */
void test_l1_plat_power_negative_PLAT_API_SetPowerState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
 * @brief Ensure PLAT_API_GetPowerState() returns correct error codes during positive scenarios
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
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |02|Call PLAT_API_GetPowerState() - get power state | curState* | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_GetPowerState() - get power state | curState* | PWRMGR_SUCCESS | Should Pass |
 * |04|Verify that PLAT_API_GetPowerState returns the same value | | | Should Pass |
 * |05|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_l1_plat_power_positive_PLAT_API_GetPowerState (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
 */
void test_l1_plat_power_negative_PLAT_API_GetPowerState (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
 * |02|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=WAKEUPSRC_VOICE, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=WAKEUPSRC_VOICE, enabled=true | PWRMGR_SUCCESS | Should Pass |
 * |04|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_PRESENCE_DETECTION, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |05|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_BLUETOOTH, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |06|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_WIFI, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |07|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_IR, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |08|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_POWER_KEY, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |09|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_TIMER, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |10|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_CEC, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |11|Call PLAT_API_SetWakeupSrc() - set wakeup source | newSrc=PWRMGR_WAKEUPSRC_LAN, enabled=false | PWRMGR_SUCCESS | Should Pass |
 * |12|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_l1_plat_power_positive_PLAT_API_SetWakeupSrc (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
 */
void test_l1_plat_power_negative_PLAT_API_SetWakeupSrc (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_INIT() - open interface | | PWRMGR_SUCCESS | Should Pass |
 * |02|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=WAKEUPSRC_VOICE, *enable| PWRMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_PRESENCE_DETECTION, *enable| PWRMGR_SUCCESS | Should Pass |
 * |04|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_BLUETOOTH, *enable| PWRMGR_SUCCESS | Should Pass |
 * |05|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_WIFI, *enable| PWRMGR_SUCCESS | Should Pass |
 * |06|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_IR, *enable| PWRMGR_SUCCESS | Should Pass |
 * |07|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_POWER_KEY, *enable| PWRMGR_SUCCESS | Should Pass |
 * |08|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_TIMER, *enable| PWRMGR_SUCCESS | Should Pass |
 * |09|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_CEC, *enable| PWRMGR_SUCCESS | Should Pass |
 * |10|Call PLAT_API_GetWakeupSrc() - get wakeup source | srcType=PWRMGR_WAKEUPSRC_LAN, *enable| PWRMGR_SUCCESS | Should Pass |
 * |11|Verify that PLAT_API_GetWakeupSrc returns the same values upon return | | | Should Pass |
 * |12|Call PLAT_TERM() - close interface | | PWRMGR_SUCCESS | Should Pass |
 * 
 */
void test_l1_plat_power_positive_PLAT_API_GetWakeupSrc (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
 */
void test_l1_plat_power_negative_PLAT_API_GetWakeupSrc (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
	UT_FAIL(This function needs to be implemented!); 
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
 */
void test_l1_plat_power_negative_PLAT_Reset (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
