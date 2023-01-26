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

void test_l1_PLAT_INIT(void)
{
    /* Positive */
    pmError_t result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);
} 

void test_l1_PLAT_API_SetPowerState(void)
{
    pmError_t result;
    /* Set Power State to ON */
    IARM_Bus_PWRMgr_PowerState_t newState;
    newState = IARM_BUS_PWRMGR_POWERSTATE_ON;
    result = PLAT_API_SetPowerState(newState);
    UT_ASSERT_EQUAL( result, PM_SUCCESS); 
} 


void test_l1_PLAT_API_GetPowerState(void)
{
    /* Positive */
    pmError_t result;
    IARM_Bus_PWRMgr_PowerState_t *curState = NULL;
    
    result =  PLAT_API_GetPowerState(curState);
    UT_ASSERT_EQUAL( result, PM_SUCCESS); 
} 


void test_l1_PLAT_API_GetTemperature(void)
{
    pmError_t result;
    IARM_Bus_PWRMgr_ThermalState_t curState = IARM_BUS_PWRMGR_TEMPERATURE_NORMAL;
    float curTemperature = 0;
    float wifiTemperature = 0;
    result = PLAT_API_GetTemperature(&curState, &curTemperature, &wifiTemperature);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);    

} 


void test_l1_PLAT_API_SetTempThresholds(void)
{
    pmError_t result;
    float tempHigh = 60.1; 
    float tempCritical = 80.5;
    result = PLAT_API_SetTempThresholds(tempHigh, tempCritical);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);    
} 


void test_l1_PLAT_API_GetTempThresholds(void)
{
    pmError_t result;
    /* Positive Case*/
    float tempHigh = 0; 
    float tempCritical = 0;
    
    result = PLAT_API_GetTempThresholds(&tempHigh, &tempCritical);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);   
} 


void test_l1_PLAT_API_DetemineClockSpeeds(void)
{
    pmError_t result;
    
    uint32_t cpu_rate_Normal = 0;
    uint32_t cpu_rate_Scaled = 0;
    uint32_t cpu_rate_Minimal = 0;
    /* Positive Test cases*/    
    result = PLAT_API_DetemineClockSpeeds(&cpu_rate_Normal, &cpu_rate_Scaled, &cpu_rate_Minimal);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);   

} 

void test_l1_PLAT_API_SetClockSpeed(void)
{
    pmError_t result;

    /* Postive Case */
    uint32_t speed = 100;
    result = PLAT_API_SetClockSpeed(speed);
    UT_ASSERT_EQUAL(result, PM_SUCCESS)

}

void test_l1_PLAT_API_GetClockSpeed(void)
{
    pmError_t result;
    
    /* Postive Case */
    uint32_t speed = 0;
    result = PLAT_API_GetClockSpeed(&speed);
    UT_ASSERT_EQUAL(result, PM_SUCCESS)

}

void test_l1_PLAT_TERM(void)
{
    PLAT_TERM();
}
static UT_test_suite_t *pSuite = NULL;

/**
 * @brief Register the main tests for this module
 * 
 * @return int - 0 on success, otherwise failure
 */
int test_l1_register( void )
{
    /* add a suite to the registry */
    pSuite = UT_add_suite("[L1 test_Example]", NULL, NULL);
    if (NULL == pSuite) 
    {
        return -1;
    }

    UT_add_test( pSuite, "pwr_level1_test_PLAT_INIT", test_l1_PLAT_INIT);
    UT_add_test( pSuite, "pwr_level1_test_PLAT_API_SetPowerState", test_l1_PLAT_API_SetPowerState);
    UT_add_test( pSuite, "pwr_level1_test_PLAT_API_GetPowerState", test_l1_PLAT_API_GetPowerState);
    UT_add_test( pSuite, "pwr_level1_test_PLAT_API_GetTemperature", test_l1_PLAT_API_GetTemperature);
    UT_add_test( pSuite, "pwr_level1_test_PLAT_API_SetTempThresholds", test_l1_PLAT_API_SetTempThresholds);
    UT_add_test( pSuite, "pwr_level1_test_PLAT_API_DetemineClockSpeeds", test_l1_PLAT_API_DetemineClockSpeeds);
    UT_add_test( pSuite, "pwr_level1_test_PLAT_API_DetemineClockSpeeds", test_l1_PLAT_API_DetemineClockSpeeds);
    UT_add_test( pSuite, "pwr_level1_test_PLAT_API_SetClockSpeed", test_l1_PLAT_API_SetClockSpeed);
    UT_add_test( pSuite, "pwr_level1_test_PLAT_TERM", test_l1_PLAT_TERM);

    return 0;
}
