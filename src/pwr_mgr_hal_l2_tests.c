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
 * @brief This routine will verify PowerState configurations works fine
 * This function will set the differet PowerStates and verify the 
 * same Power state applied correctly. 
 */
void test_l2_PLAT_API_CheckPowerState(void)
{
    pmError_t result;
    
    /* Positive */
    /* Calling to Initialized Platform Power manager HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);
    
    /* Set Power State to ON with proper argument*/
    IARM_Bus_PWRMgr_PowerState_t newState;
    newState = IARM_BUS_PWRMGR_POWERSTATE_ON;
    result = PLAT_API_SetPowerState(newState);
    UT_ASSERT_EQUAL( result, PM_SUCCESS); 
    
    /*Get the Current Power State */
    IARM_Bus_PWRMgr_PowerState_t curState;
    result =  PLAT_API_GetPowerState(&curState);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    UT_ASSERT_EQUAL( newState, curState);

    /* Set Power State to OFF with proper argument*/
    newState = IARM_BUS_PWRMGR_POWERSTATE_OFF;
    result = PLAT_API_SetPowerState(newState);
    UT_ASSERT_EQUAL( result, PM_SUCCESS); 
    
    /*Get the Current Power State */
    result =  PLAT_API_GetPowerState(&curState);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    UT_ASSERT_EQUAL( newState, curState);

    /* Set Power State to STANDBY with proper argument*/
    result = PLAT_API_SetPowerState(newState);
    UT_ASSERT_EQUAL( result, PM_SUCCESS); 
    
    /*Get the Current Power State */
    result =  PLAT_API_GetPowerState(&curState);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    UT_ASSERT_EQUAL( newState, curState);

    /* Set Power State to LIGHTSLEEP with proper argument*/
    newState = IARM_BUS_PWRMGR_POWERSTATE_STANDBY_LIGHT_SLEEP;
    result = PLAT_API_SetPowerState(newState);
    UT_ASSERT_EQUAL( result, PM_SUCCESS); 
    
    /*Get the Current Power State */
    result =  PLAT_API_GetPowerState(&curState);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    UT_ASSERT_EQUAL( newState, curState);


     /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();
    
} 


/**
 * @brief This function will do the unit testing of CPU Temperature module.
 * This function will set the Temperature Thresholds and verify the 
 * same applied correctly.  
 */
void test_l2_PLAT_API_CheckTempThresholds(void)
{
    pmError_t result;
    float tempHigh = 60; //(in celcus)
    float tempCritical = 100; // (in celcus)

   /* Positive */
    
    /* Calling to Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS); 

    /*Set the high temperature (in celcus) and Critical temperature (in celcus) thresholds */ 
    result = PLAT_API_SetTempThresholds(tempHigh, tempCritical);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);    

   
    float curTempHigh = 0; 
    float curTempCritical = 0;
    
    /* Call to get temerature threshold */
    result = PLAT_API_GetTempThresholds(&curTempHigh, &curTempCritical);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);   

    /* Verify : The Current temperature thresholds are the same as set before */ 
    UT_ASSERT_EQUAL( tempHigh, curTempHigh); 
    UT_ASSERT_EQUAL( tempCritical, curTempCritical); 
    
    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();
} 


/**
 * @brief This function will do the unit testing of CPU Clock Speed module.
 * This function will set the CPU Speed and verify the same applied correctly.  
 */
void test_l2_PLAT_API_CheckClockSpeed(void)
{
    pmError_t result;

    /* Postive Case */
    /* Calling to Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    uint32_t speed = 100;
    result = PLAT_API_SetClockSpeed(speed);
    UT_ASSERT_EQUAL(result, PM_SUCCESS)
    
    uint32_t curSpeed = 0;
    result = PLAT_API_GetClockSpeed(&curSpeed);
    UT_ASSERT_EQUAL(result, PM_SUCCESS)

    /* Verify : The Current Clock Speed are the same as set before */ 
    UT_ASSERT_EQUAL( speed, curSpeed); 
    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM(); 
}


static UT_test_suite_t *pSuite = NULL;

/**
 * @brief Register the main tests for this module
 * 
 * @return int - 0 on success, otherwise failure
 */
int test_l2_register( void )
{
    /* add a suite to the registry */
    pSuite = UT_add_suite("[L2 test_Example]", NULL, NULL);
    if (NULL == pSuite) 
    {
        return -1;
    }

    UT_add_test( pSuite, "PowerManager_test_l2_PLAT_API_CheckPowerState", test_l2_PLAT_API_CheckPowerState);
    UT_add_test( pSuite, "PowerManager_test_l2_PLAT_API_CheckTempThresholds", test_l2_PLAT_API_CheckTempThresholds);
    UT_add_test( pSuite, "PowerManager_test_l2_PLAT_API_CheckClockSpeed", test_l2_PLAT_API_CheckClockSpeed);

    return 0;
}
