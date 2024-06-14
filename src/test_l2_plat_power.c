/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:*
* Copyright 2024 RDK Management
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

/**
* @file test_l2_plat_power.c
* @page plat_power Level 2 Tests
*
* ## Module's Role
* This module includes Level 2 functional tests (success and failure scenarios).
* This is to ensure that the plat_power APIs meet the requirements across all vendors.
*
* **Pre-Conditions:**  None@n
* **Dependencies:** None@n
*
* Ref to API Definition specification documentation : [plat-power_halSpec.md](../../docs/pages/plat-power_halSpec.md)
*/

#include <ut.h>
#include <ut_log.h>
#include <ut_kvp_profile.h>
#include "plat_power.h"

static int gTestGroup = 2;
static int gTestID = 1;

/**
* @brief Test for setting and getting power state in the power management module
*
* This test function first initializes the power management module using `PLAT_INIT` and checks if it returns `PWRMGR_SUCCESS`. Then it sets and gets the power state for each power state defined in `PWRMgr_PowerState_t` using `PLAT_API_SetPowerState` and `PLAT_API_GetPowerState` respectively, and checks if the set and get operations are successful and the power state is as expected. Finally, it terminates the power management module using `PLAT_TERM` and checks if it returns `PWRMGR_SUCCESS`.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 001@n
*
* **Test Procedure:**
* Refer to UT specification documentation [plat_power_L2_Low-Level_TestSpecification.md](../../docs/pages/plat_power_L2_Low-Level_TestSpecification.md)
*/

void test_l2_plat_power_SetAndGetPowerState(void)
{
    gTestID = 1;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    pmStatus_t status;
    PWRMgr_PowerState_t powerState, getState;

    UT_LOG_DEBUG("Invoking PLAT_INIT");
    status = PLAT_INIT();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, PWRMGR_SUCCESS);

    for (powerState = PWRMGR_POWERSTATE_OFF; powerState < PWRMGR_POWERSTATE_MAX ; powerState++)
    {
        UT_LOG_DEBUG("Invoking PLAT_API_SetPowerState with powerState: %d", powerState);
        status = PLAT_API_SetPowerState(powerState);
        UT_LOG_DEBUG("Return status: %d", status);
        UT_ASSERT_EQUAL(status, PWRMGR_SUCCESS);
        if (status != PWRMGR_SUCCESS)
        {
            UT_LOG_ERROR("Failed to set power state");
            continue;
        }

        UT_LOG_DEBUG("Invoking PLAT_API_GetPowerState");
        status = PLAT_API_GetPowerState(&getState);
        UT_LOG_DEBUG("Return powerState: %d, status: %d", getState, status);
        UT_ASSERT_EQUAL(status, PWRMGR_SUCCESS);

        UT_ASSERT_EQUAL(powerState, getState);
    }

    UT_LOG_DEBUG("Invoking PLAT_TERM");
    status = PLAT_TERM();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, PWRMGR_SUCCESS);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test for setting and getting the wakeup source in the platform power management module
*
* This test verifies the functionality of the SetWakeupSrc and GetWakeupSrc functions in the platform power management module.
* It checks if the wakeup source can be successfully set and retrieved, and if the correct status is returned for each operation.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 002@n
*
* **Test Procedure:**
* Refer to UT specification documentation [plat_power_L2_Low-Level_TestSpecification.md](../../docs/pages/plat_power_L2_Low-Level_TestSpecification.md)
*/

void test_l2_plat_power_SetAndGetWakeupSrc(void)
{
    gTestID = 2;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    pmStatus_t status;
    bool enable;
    PWRMGR_WakeupSrcType_t srcType;

    UT_LOG_DEBUG("Invoking PLAT_INIT");
    status = PLAT_INIT();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, PWRMGR_SUCCESS);

    for(srcType = PWRMGR_WAKEUPSRC_VOICE; srcType < PWRMGR_WAKEUPSRC_MAX; srcType++)
    {
        UT_LOG_DEBUG("Invoking PLAT_API_SetWakeupSrc with srcType: %d and enable: true", srcType);
        status = PLAT_API_SetWakeupSrc(srcType, true);
        UT_LOG_DEBUG("Return status: %d", status);
        UT_ASSERT_EQUAL(status, PWRMGR_SUCCESS);
        if (status != PWRMGR_SUCCESS)
        {
            UT_LOG_ERROR("Failed to set Wakeup Src");
            continue;
        }

        UT_LOG_DEBUG("Invoking PLAT_API_GetWakeupSrc with srcType: %d", srcType);
        status = PLAT_API_GetWakeupSrc(srcType, &enable);
        UT_LOG_DEBUG("Return status: %d, enable: %d", status, enable);
        UT_ASSERT_EQUAL(status, PWRMGR_SUCCESS);
        UT_ASSERT_EQUAL(enable, true);

        UT_LOG_DEBUG("Invoking PLAT_API_SetWakeupSrc with srcType: %d and enable: false", srcType);
        status = PLAT_API_SetWakeupSrc(srcType, false);
        UT_LOG_DEBUG("Return status: %d", status);
        UT_ASSERT_EQUAL(status, PWRMGR_SUCCESS);
        if (status != PWRMGR_SUCCESS)
        {
            UT_LOG_ERROR("Failed to set Wakeup Src");
            continue;
        }

        UT_LOG_DEBUG("Invoking PLAT_API_GetWakeupSrc with srcType: %d", srcType);
        status = PLAT_API_GetWakeupSrc(srcType, &enable);
        UT_LOG_DEBUG("Return status: %d, enable: %d", status, enable);
        UT_ASSERT_EQUAL(status, PWRMGR_SUCCESS);
        UT_ASSERT_EQUAL(enable, false);
    }

    UT_LOG_DEBUG("Invoking PLAT_TERM");
    status = PLAT_TERM();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, PWRMGR_SUCCESS);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int - 0 on success, otherwise failure
 */

int test_plat_power_l2_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L2 plat_power]", NULL, NULL);
    if (pSuite == NULL)
    {
        return -1;
    }
    // List of test function names and strings

    UT_add_test( pSuite, "l2_plat_power_SetAndGetPowerState", test_l2_plat_power_SetAndGetPowerState);
    UT_add_test( pSuite, "l2_plat_power_SetAndGetWakeupSrc", test_l2_plat_power_SetAndGetWakeupSrc);

    return 0;
}