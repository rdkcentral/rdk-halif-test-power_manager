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
 * @defgroup PLAT_POWER_HALTEST_L2 Power Manager HAL Tests L2 File
 * @{
 * @parblock
 *
 * ### L2 Tests for Power Manager HAL :
 *
 * Level 2 unit test cases for all APIs of Power Manager HAL
 *
 * **Pre-Conditions:**  None@n
 * **Dependencies:** None@n
 *
 * Refer to API Definition specification documentation : [power-manager_halSpec.md](../../docs/pages/power-manager_halSpec.md)
 *
 * @endparblock
 */
/**
* @file test_l2_plat_power.c
*
*/

#include <ut.h>
#include <ut_log.h>
#include <ut_kvp_profile.h>
#include "plat_power.h"

#define POWER_MANAGER_KEY_SIZE 50

static int gTestGroup = 3;
static int gTestID = 1;

/*PWRMGR_WakeupSrcType_t*/
const static ut_control_keyStringMapping_t plat_source_types_mapTable [] = {
  { "PWRMGR_WAKEUPSRC_VOICE",               (int32_t)PWRMGR_WAKEUPSRC_VOICE     },
  { "PWRMGR_WAKEUPSRC_PRESENCE_DETECTION",  (int32_t)PWRMGR_WAKEUPSRC_PRESENCE_DETECTION      },
  { "PWRMGR_WAKEUPSRC_BLUETOOTH",           (int32_t)PWRMGR_WAKEUPSRC_BLUETOOTH     },
  { "PWRMGR_WAKEUPSRC_WIFI",                (int32_t)PWRMGR_WAKEUPSRC_WIFI   },
  { "PWRMGR_WAKEUPSRC_IR",                  (int32_t)PWRMGR_WAKEUPSRC_IR  },
  { "PWRMGR_WAKEUPSRC_POWER_KEY",           (int32_t)PWRMGR_WAKEUPSRC_POWER_KEY },
  { "PWRMGR_WAKEUPSRC_TIMER",               (int32_t)PWRMGR_WAKEUPSRC_TIMER },
  { "PWRMGR_WAKEUPSRC_CEC",                 (int32_t)PWRMGR_WAKEUPSRC_CEC },
  { "PWRMGR_WAKEUPSRC_LAN",                 (int32_t)PWRMGR_WAKEUPSRC_LAN },
  { "PWRMGR_WAKEUPSRC_MAX",                 (int32_t)PWRMGR_WAKEUPSRC_MAX       },
  {  NULL, -1 }
};


/* pmStatus_t */
const static ut_control_keyStringMapping_t pmStatus_mapTable [] = {
  { "PWRMGR_SUCCESS",                   (int32_t)PWRMGR_SUCCESS                     },
  { "PWRMGR_INVALID_ARGUMENT",          (int32_t)PWRMGR_INVALID_ARGUMENT                 },
  { "PWRMGR_ALREADY_INITIALIZED",       (int32_t)PWRMGR_ALREADY_INITIALIZED           },
  { "PWRMGR_NOT_INITIALIZED",           (int32_t)PWRMGR_NOT_INITIALIZED           },
  { "PWRMGR_INIT_FAILURE",              (int32_t)PWRMGR_INIT_FAILURE     },
  { "PWRMGR_SET_FAILURE",               (int32_t)PWRMGR_SET_FAILURE         },
  { "PWRMGR_GET_FAILURE",               (int32_t)PWRMGR_GET_FAILURE },
  { "PWRMGR_OPERATION_NOT_SUPPORTED",   (int32_t)PWRMGR_OPERATION_NOT_SUPPORTED  },
  { "PWRMGR_TERM_FAILURE",              (int32_t)PWRMGR_TERM_FAILURE        },
  { "PWRMGR_MAX",                       (int32_t)PWRMGR_MAX                                           },
  {  NULL, -1 }
};


/**
 * @brief This function clears the stdin buffer.
 *
 * This function clears the stdin buffer.
 */
void readAndDiscardRestOfLine(FILE* in)
{
   int c;
   while ( (c = fgetc(in)) != EOF && c != '\n');
}

/**
* @brief Initialization of the HAL Power Manager Module
*
* This test provides a scope to open the HAL Power Manager module.

*
* **Test Group ID:** 03@n
*
* **Test Case ID:** 001@n
*
* **Pre-Conditions:** None@n
*
* **Dependencies:** None@n
*
* **User Interaction:** @n
* User or Automation tool should select the Test 1 to before running any test.
*
*/

void test_l3_power_manager_hal_Init(void)
{
   gTestID = 1;
   pmStatus_t status = PWRMGR_SUCCESS ;

   UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

   // Step 1: Call PLAT_INIT()
   status = PLAT_INIT();
   UT_LOG_INFO("Result PLAT_INIT: pmStatus_t:[%s]",
                UT_Control_GetMapString(pmStatus_mapTable, status));

   UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Initialization of the HAL Power Manager Module
*
* This test provides a scope to set what wake up sources are active.

*
* **Test Group ID:** 03@n
*
* **Test Case ID:** 002@n
*
* **Pre-Conditions:** None@n
*
* **Dependencies:** None@n
*
* **User Interaction:** @n
* User or Automation tool should select the Test 1 to before running any test.
*
*/
void test_l3_power_manager_hal_Set_Wakeup_Source(void)
{
   gTestID = 2;
   pmStatus_t status = PWRMGR_SUCCESS ;

   UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

   int32_t  sourceType =0;
   int  enableGet = false;


   UT_LOG_MENU_INFO("----------------------------------------------------------");
   UT_LOG_MENU_INFO("Supported Wake Up Source Types");
   UT_LOG_MENU_INFO("----------------------------------------------------------");
   UT_LOG_MENU_INFO("\t#  %-20s","Wakeup Source Type");
   for(int32_t i = PWRMGR_WAKEUPSRC_VOICE; i <= PWRMGR_WAKEUPSRC_LAN; i++)
   {
       UT_LOG_MENU_INFO("\t%d.  %-20s", i, UT_Control_GetMapString(plat_source_types_mapTable, i));
   }
   UT_LOG_MENU_INFO("----------------------------------------------------------");
   UT_LOG_MENU_INFO("Select Wake Up Source Type: ");
   scanf("%d", &sourceType);
   readAndDiscardRestOfLine(stdin);
   if(sourceType < PWRMGR_WAKEUPSRC_VOICE || sourceType > PWRMGR_WAKEUPSRC_LAN)
        {
            UT_LOG_ERROR("Invalid ARC Type");
            goto exit;
        }
   PWRMGR_WakeupSrcType_t srcType = (PWRMGR_WakeupSrcType_t)sourceType;
   UT_LOG_MENU_INFO("----------------------------------------------------------");
   UT_LOG_MENU_INFO("Supported Wake Up Source Types enabled/disabled");
   UT_LOG_MENU_INFO("----------------------------------------------------------");
   UT_LOG_MENU_INFO("\t#  %-20s","Enable/Disable Wakeup Source");
   UT_LOG_MENU_INFO("\t%d  %-20s", 0, "Disable");
   UT_LOG_MENU_INFO("\t%d  %-20s", 1, "Enable");
   UT_LOG_MENU_INFO("----------------------------------------------------------");
   UT_LOG_MENU_INFO("Select Enable/Disable Wakeup Source: ");
   scanf("%d", &enableGet);
   readAndDiscardRestOfLine(stdin);
   if(sourceType != 0 && sourceType != 1)
        {
            UT_LOG_ERROR("Invalid enable type");
            goto exit;
        }
    bool enable = (bool)enableGet;
   // Step 1: Call PLAT_DS_INIT()
   status = PLAT_API_SetWakeupSrc( srcType, enable );
   UT_LOG_INFO("Result PLAT_API_SetWakeupSrc: pmStatus_t:[%s]",
                UT_Control_GetMapString(pmStatus_mapTable, status));

   exit:
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
* @brief Initialization of the HAL Power Manager Module
*
* This test provides a scope to get what wake up sources are active.

*
* **Test Group ID:** 03@n
*
* **Test Case ID:** 003@n
*
* **Pre-Conditions:** None@n
*
* **Dependencies:** None@n
*
* **User Interaction:** @n
* User or Automation tool should select the Test 1 to before running any test.
*
*/
void test_l3_power_manager_hal_Get_Wakeup_Source(void)
{
   gTestID = 2;
   pmStatus_t status = PWRMGR_SUCCESS ;

   UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

   int32_t  sourceType =0;
   bool  enable = false;


   UT_LOG_MENU_INFO("----------------------------------------------------------");
   UT_LOG_MENU_INFO("Supported Wake Up Source Types");
   UT_LOG_MENU_INFO("----------------------------------------------------------");
   UT_LOG_MENU_INFO("\t#  %-20s","Wakeup Source Type");
   for(int32_t i = PWRMGR_WAKEUPSRC_VOICE; i <= PWRMGR_WAKEUPSRC_LAN; i++)
   {
       UT_LOG_MENU_INFO("\t%d.  %-20s", i, UT_Control_GetMapString(plat_source_types_mapTable, i));
   }
   UT_LOG_MENU_INFO("----------------------------------------------------------");
   UT_LOG_MENU_INFO("Select Wake Up Source Type: ");
   scanf("%d", &sourceType);
   readAndDiscardRestOfLine(stdin);
   if(sourceType < PWRMGR_WAKEUPSRC_VOICE || sourceType > PWRMGR_WAKEUPSRC_LAN)
        {
            UT_LOG_ERROR("Invalid ARC Type");
            goto exit;
        }
   PWRMGR_WakeupSrcType_t srcType = (PWRMGR_WakeupSrcType_t)sourceType;
   // Step 1: Call PLAT_DS_INIT()
   status = PLAT_API_GetWakeupSrc(srcType,*enable);
   if ((status != PWRMGR_SUCCESS ))
   {
       UT_LOG_INFO("Result PLAT_API_GetWakeupSrc: pmStatus_t:[%s]",
                UT_Control_GetMapString(pmStatus_mapTable, status));
   }
   else{
    UT_LOG_MENU_INFO("\t%d.  %-20s is ", sourceType, UT_Control_GetMapString(plat_source_types_mapTable, sourceType), enable ? "enabled" : "disabled");
   }

   UT_LOG_INFO("Out %s\n", __FUNCTION__);
}


/**
* @brief Initialization of the HAL Power Manager Module
*
* This test provides a scope to close the HAL Power Manager module.

*
* **Test Group ID:** 03@n
*
* **Test Case ID:** 004@n
*
* **Pre-Conditions:** None@n
*
* **Dependencies:** None@n
*
* **User Interaction:** @n
* User or Automation tool should select the Test 1 to before running any test.
*
*/

void test_l3_power_manager_hal_Term(void)
{
   gTestID = 3;
   pmStatus_t status = PWRMGR_SUCCESS ;

   UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

   // Step 1: Call PLAT_TERM()
   status = PLAT_TERM();
   UT_LOG_INFO("Result PLAT_TERM: pmStatus_t:[%s]",
                UT_Control_GetMapString(pmStatus_mapTable, status));

   UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int test_l3_plat_power_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L3 power manager Functions] ", NULL, NULL);
    if (pSuite == NULL)
    {
        return -1;
    }
    // List of test function names and strings

    UT_add_test( pSuite, "L3_Init_pwrmgr", test_l3_power_manager_hal_Init);
    UT_add_test( pSuite, "L3_pwrmgr_SetWakeUpSource", test_l3_power_manager_hal_Set_Wakeup_Source);
    UT_add_test( pSuite, "L3_pwrmgr_GetWakeUpSource", test_l3_power_manager_hal_Get_Wakeup_Source);
    UT_add_test( pSuite, "L3_Term_pwrmgr", test_l3_power_manager_hal_Term);

    return 0;
}

/** @} */ // End of PLAT_POWER_HALTEST_L3
/** @} */ // End of POWER_MANAGER_HALTEST
/** @} */ // End of POWER_MANAGER
/** @} */ // End of HPK