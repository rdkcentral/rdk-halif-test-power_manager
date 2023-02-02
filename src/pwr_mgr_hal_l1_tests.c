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
void test_l1_PLAT_INIT(void)
{
    pmError_t result;

    /* Positive */
    /* Calling to Initialized Platform Power manager HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    /* Negative */
    /*Calling PLAT_INIT second time, should return the general failure*/
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_GENERAL_ERROR);

    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM(); 
} 

/**
 * @brief This function will do the unit testing of PLAT_API_SetPowerState ().
 * This function will ensure underlying API implementation is handling
 * the invalid call sequences to the API properly.
 * This UT implementation will verify it by calling the function in all
 * invalid possibilities.
 * In all the invalid call sequence 
 * scenarios API should return the expected error codes defined in the respective HAL
 * documentation. Please see all the expected error codes and respective scenarios
 * in which the error codes will be returned.
 * PM_SUCCESS - It will be returned if PLAT_API_SetPowerState() is executed successfully.
 * PM_INVALID_STATE - It's invalid failure state, it will returns if calling without platform initialized method PLAT_INIT().
 * PM_INVALID_ARGUMENT - It will returned if invalid argument passed to this method.
 * PM_GENERAL_ERROR - It will returns if any error or general failure occured in underneath layer.
 */
void test_l1_PLAT_API_SetPowerState(void)
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

    PLAT_TERM();

    /* Negative result */
    /* Calling without Initialized Platform HAL */
    result = PLAT_API_SetPowerState(newState);    
    UT_ASSERT_EQUAL( result, PM_INVALID_STATE );

    /* Negative result */
    /* Calling with invalid argument after Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    /* Calling with Invalid argument */
    result = PLAT_API_SetPowerState(-1);  
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);

     /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();
    
    /* 
    * #TODO: Unclear how the function will fail, it may be due failure in underneath layer 
    */
} 

/**
 * @brief This function will do the unit testing of PLAT_API_GetPowerState ().
 * This function will ensure underlying API implementation is handling
 * the invalid call sequences to the API properly.
 * This UT implementation will verify it by calling the function in all
 * invalid possibilities.
 * In all the invalid call sequence 
 * scenarios API should return the expected error codes defined in the respective HAL
 * documentation. Please see all the expected error codes and respective scenarios
 * in which the error codes will be returned.
 * PM_SUCCESS - It will be returned if PLAT_API_GetPowerState() is executed successfully.
 * PM_INVALID_STATE - It's invalid failure state, it will returns if calling without platform initialized method PLAT_INIT().
 * PM_INVALID_ARGUMENT - It will returned if invalid argument passed to this method.
 * PM_GENERAL_ERROR - It will returns if any error or general failure occured in underneath layer.
 */
void test_l1_PLAT_API_GetPowerState(void)
{
    /* Positive */
    pmError_t result;
    /* Calling to Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);
    
    IARM_Bus_PWRMgr_PowerState_t *curState = NULL;
    /*Get the Current Power State */
    result =  PLAT_API_GetPowerState(curState);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();

    /* Negative */
    /* Calling without Initialized Platform HAL */
    IARM_Bus_PWRMgr_PowerState_t *newState = NULL; 
    result = PLAT_API_GetPowerState(newState);    
    UT_ASSERT_EQUAL( result, PM_INVALID_STATE );

    /* Negative  */
    /* Calling with invalid argument after Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    /* Calling with NULL as Invalid argument */
    result = PLAT_API_GetPowerState(NULL);  
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);

     /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();
    
    /* 
    * #TODO: Unclear how the function will fail, it may be due failure in underneath layer 
    */ 
} 

/**
 * @brief This function will do the unit testing of PLAT_API_GetTemperature ().
 * This function will ensure underlying API implementation is handling
 * the invalid call sequences to the API properly.
 * This UT implementation will verify it by calling the function in all
 * invalid possibilities.
 * In all the invalid call sequence 
 * scenarios API should return the expected error codes defined in the respective HAL
 * documentation. Please see all the expected error codes and respective scenarios
 * in which the error codes will be returned.
 * PM_SUCCESS - It will be returned if PLAT_API_GetTemperature() is executed successfully.
 * PM_INVALID_STATE - It's invalid failure state, it will returns if calling without platform initialized method PLAT_INIT().
 * PM_INVALID_ARGUMENT - It will returned if invalid argument passed to this method.
 * PM_GENERAL_ERROR - It will returns if any error or general failure occured in underneath layer.
 */
void test_l1_PLAT_API_GetTemperature(void)
{
    pmError_t result;
    /* Positive */
    
    /* Calling to Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    /*Get the Current State, current temperature (in celcus) and WiFi temperature (in celcus) */ 
    IARM_Bus_PWRMgr_ThermalState_t curState;
    float curTemperature = 0;
    float wifiTemperature = 0;
    result = PLAT_API_GetTemperature(&curState, &curTemperature, &wifiTemperature);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();

    /* Negative */
    /* Calling without Initialized Platform HAL */
    result = PLAT_API_GetTemperature(&curState, &curTemperature, &wifiTemperature);
    UT_ASSERT_EQUAL( result, PM_INVALID_STATE );

    /* Negative  */
    /* Calling with invalid argument after Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    /* Calling with NULL as Invalid first argument */
    result = PLAT_API_GetTemperature(NULL, &curTemperature, &wifiTemperature);
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);

    /* Calling with NULL as Invalid Second argument */
    result = PLAT_API_GetTemperature(&curState, NULL, &wifiTemperature);
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);
    
    /* Calling with NULL as Invalid third argument */
    result = PLAT_API_GetTemperature(&curState, &curTemperature, NULL);
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);

    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();
    
    /* 
    * #TODO: Unclear how the function will fail, it may be due failure in underneath layer 
    */     

} 

/**
 * @brief This function will do the unit testing of PLAT_API_SetTempThresholds() for the Temperature (in celcus) .
 * This function will ensure underlying API implementation is handling
 * the invalid call sequences to the API properly.
 * This UT implementation will verify it by calling the function in all
 * invalid possibilities.
 * In all the invalid call sequence 
 * scenarios API should return the expected error codes defined in the respective HAL
 * documentation. Please see all the expected error codes and respective scenarios
 * in which the error codes will be returned.
 * PM_SUCCESS - It will be returned if PLAT_API_SetTempThresholds() is executed successfully.
 * PM_INVALID_STATE - It's invalid failure state, it will returns if calling without platform initialized method PLAT_INIT().
 * PM_INVALID_ARGUMENT - It will returned if invalid argument passed to this method.
 * PM_GENERAL_ERROR - It will returns if any error or general failure occured in underneath layer.
 * 
 * Recomanded temperature settings in different scenarioes 
 * Temperature (in celcus) at which box will ALWAYS be rebooted 
 *     static int thermal_reboot_critical_threshold        = 120;
 * Temperature (in celcus) at which box will be rebooted after grace_interval has passed
 *     static int thermal_reboot_concern_threshold         = 112;
 * Temperature (in celcus) at which box is considered safe and will stop reboot consideration 
 *     static int thermal_reboot_safe_threshold            = 110;
 * Temperature (in celcus) at which box will ALWAYS go to deep sleep 
 *     static int thermal_deepsleep_critical_threshold     = 115;
 * Temperature (in celcus) at which box will go to deep sleep after grace_interval has passed.
 *     static int thermal_deepsleep_concern_threshold      = 110;
 * Temperature (in celcus) at which box is considered safe and will stop deep sleep consideration
 *     static int thermal_deepsleep_safe_threshold         = 100;
 * 
 * Temperature (in celcus) at which box will ALWAYS be switched to the LOWEST clock mode.
 *     static int thermal_declock_critical_threshold       = 110;
 * Temperature (in celcus) at which box will ALWAYS be switched to the middle clock mode 
 *     static int thermal_declock_concern_threshold        = 100;
 * Temperature (in celcus) at which box will be switched back to highest clock mode after 'thermal_declock_grace_interval' has passed 
 *     static int thermal_declock_safe_threshold           = 90;
 */
void test_l1_PLAT_API_SetTempThresholds(void)
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
    
    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();


    /* Negative */
    /* Calling without Initialized Platform HAL */
    /*Set the high temperature (in celcus) as negative value and Critical temperature (in celcus) thresholds */ 
    result = PLAT_API_SetTempThresholds(tempHigh, tempCritical);
    UT_ASSERT_EQUAL( result, PM_INVALID_STATE );


    /* Negative  */
    /* Calling with invalid argument after Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    /*Set the high temperature (in celcus) as negative value and Critical temperature (in celcus) thresholds */ 
    result = PLAT_API_SetTempThresholds(-1, tempCritical);
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);

    /*Set the high temperature (in celcus) and Critical temperature as negative (in celcus) thresholds */ 
    result = PLAT_API_SetTempThresholds(tempHigh, -1);
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);

    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();
     
    /* 
    * #TODO: Unclear how the function will fail, it may be due failure in underneath layer 
    */    

} 

/**
 * @brief This function will do the unit testing of PLAT_API_GetTempThresholds ().
 * This function will ensure underlying API implementation is handling
 * the invalid call sequences to the API properly.
 * This UT implementation will verify it by calling the function in all
 * invalid possibilities.
 * In all the invalid call sequence 
 * scenarios API should return the expected error codes defined in the respective HAL
 * documentation. Please see all the expected error codes and respective scenarios
 * in which the error codes will be returned.
 * DEEPSLEEP_SUCCESS - It will be returned if PLAT_API_GetTempThresholds() is executed successfully.
 * DEEPSLEEP_INVALID_STATE - It's invalid failure state, it will returns if calling without platform initialized method PLAT_INIT().
 * DEEPSLEEP_INVALID_ARGUMENT - It will returned if invalid argument passed to this method.
 * DEEPSLEEP_GENERAL_ERROR - It will returns if any error or general failure occured in underneath layer.
 */
void test_l1_PLAT_API_GetTempThresholds(void)
{
    pmError_t result;
    /* Positive Case*/
    /* Calling to Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS); 

    float tempHigh = 0; 
    float tempCritical = 0;
    
    /* Call to get temerature threshold */
    result = PLAT_API_GetTempThresholds(&tempHigh, &tempCritical);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);   

    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();

    /* Negative */
    /* Calling without Initialized Platform HAL */
    /*Get the current temperature (in celcus) thresholds */  
    result = PLAT_API_GetTempThresholds(&tempHigh, &tempCritical);
    UT_ASSERT_EQUAL( result, PM_INVALID_STATE);

    /* Negative  */
    /* Calling with invalid argument after Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    /*Get the current temperature (in celcus) thresholds */
    result = PLAT_API_GetTempThresholds(NULL, &tempCritical);
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);

    /*Get the current temperature (in celcus) thresholds */
    result = PLAT_API_GetTempThresholds(&tempHigh, NULL);
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);

    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();
     
    /* 
    * #TODO: Unclear how the function will fail, it may be due failure in underneath layer 
    */    
} 

/**
 * @brief This function will do the unit testing of PLAT_API_DetemineClockSpeeds ().
 * This function will ensure underlying API implementation is handling
 * the invalid call sequences to the API properly.
 * This UT implementation will verify it by calling the function in all
 * invalid possibilities.
 * In all the invalid call sequence 
 * scenarios API should return the expected error codes defined in the respective HAL
 * documentation. Please see all the expected error codes and respective scenarios
 * in which the error codes will be returned.
 * DEEPSLEEP_SUCCESS - It will be returned if PLAT_API_DetemineClockSpeeds() is executed successfully.
 * DEEPSLEEP_INVALID_STATE - It's invalid failure state, it will returns if calling without platform initialized method PLAT_INIT().
 * DEEPSLEEP_INVALID_ARGUMENT - It will returned if invalid argument passed to this method.
 * DEEPSLEEP_GENERAL_ERROR - It will returns if any error or general failure occured in underneath layer.
 */
void test_l1_PLAT_API_DetemineClockSpeeds(void)
{
    pmError_t result;
    
    uint32_t cpu_rate_Normal = 0;
    uint32_t cpu_rate_Scaled = 0;
    uint32_t cpu_rate_Minimal = 0;
    /* Positive Test cases*/

    /* Calling to Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    result = PLAT_API_DetemineClockSpeeds(&cpu_rate_Normal, &cpu_rate_Scaled, &cpu_rate_Minimal);
    UT_ASSERT_EQUAL( result, PM_SUCCESS);   

    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();

    /* Negative */
    /* Calling without Initialized Platform HAL */
    result = PLAT_API_DetemineClockSpeeds(&cpu_rate_Normal, &cpu_rate_Scaled, &cpu_rate_Minimal);
    UT_ASSERT_EQUAL( result, PM_INVALID_STATE);

    /* Negative  */
    /* Calling with invalid argument after Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    result = PLAT_API_DetemineClockSpeeds(NULL, &cpu_rate_Scaled, &cpu_rate_Minimal);
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);   

    result = PLAT_API_DetemineClockSpeeds(&cpu_rate_Normal, NULL, &cpu_rate_Minimal);
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);   
    
    result = PLAT_API_DetemineClockSpeeds(&cpu_rate_Normal, &cpu_rate_Scaled, NULL);
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);   

    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM(); 
    /* 
    * #TODO: Unclear how the function will fail, it may be due failure in underneath layer 
    */    
} 

/**
 * @brief This function will do the unit testing of PLAT_API_SetClockSpeed ().
 * This function will ensure underlying API implementation is handling
 * the invalid call sequences to the API properly.
 * This UT implementation will verify it by calling the function in all
 * invalid possibilities.
 * In all the invalid call sequence 
 * scenarios API should return the expected error codes defined in the respective HAL
 * documentation. Please see all the expected error codes and respective scenarios
 * in which the error codes will be returned.
 * DEEPSLEEP_SUCCESS - It will be returned if PLAT_API_SetClockSpeed() is executed successfully.
 * DEEPSLEEP_INVALID_STATE - It's invalid failure state, it will returns if calling without platform initialized method PLAT_INIT().
 * DEEPSLEEP_INVALID_ARGUMENT - It will returned if invalid argument passed to this method.
 * DEEPSLEEP_GENERAL_ERROR - It will returns if any error or general failure occured in underneath layer.
 */
void test_l1_PLAT_API_SetClockSpeed(void)
{
    pmError_t result;

    /* Postive Case */
    /* Calling to Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    uint32_t speed = 100;
    result = PLAT_API_SetClockSpeed(speed);
    UT_ASSERT_EQUAL(result, PM_SUCCESS)

    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM(); 

    /* Negative */
    /* Calling without Initialized Platform HAL */
    result = PLAT_API_SetClockSpeed(speed);
    UT_ASSERT_EQUAL( result, PM_INVALID_STATE); 

    /* Negative  */
    /* Calling with invalid argument after Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);
    
    /* Set negative value*/
    result = PLAT_API_SetClockSpeed(-1);
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);  

    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();

    /* 
    * #TODO: Unclear how the function will fail, it may be due failure in underneath layer 
    */  

}

/**
 * @brief This function will do the unit testing of PLAT_API_GetClockSpeed ().
 * This function will ensure underlying API implementation is handling
 * the invalid call sequences to the API properly.
 * This UT implementation will verify it by calling the function in all
 * invalid possibilities.
 * In all the invalid call sequence 
 * scenarios API should return the expected error codes defined in the respective HAL
 * documentation. Please see all the expected error codes and respective scenarios
 * in which the error codes will be returned.
 * DEEPSLEEP_SUCCESS - It will be returned if PLAT_API_GetClockSpeed() is executed successfully.
 * DEEPSLEEP_INVALID_STATE - It's invalid failure state, it will returns if calling without platform initialized method PLAT_INIT().
 * DEEPSLEEP_INVALID_ARGUMENT - It will returned if invalid argument passed to this method.
 * DEEPSLEEP_GENERAL_ERROR - It will returns if any error or general failure occured in underneath layer.
 */
void test_l1_PLAT_API_GetClockSpeed(void)
{
    pmError_t result;
    
    /* Postive Case */
    /* Calling to Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);

    uint32_t speed = 0;
    result = PLAT_API_GetClockSpeed(&speed);
    UT_ASSERT_EQUAL(result, PM_SUCCESS)

    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();

    /* Negative */
    /* Calling without Initialized Platform HAL */
    result = PLAT_API_GetClockSpeed(&speed);
    UT_ASSERT_EQUAL( result, PM_INVALID_STATE); 

    /* Negative  */
    /* Calling with invalid argument after Initialized Platform HAL */
    result = PLAT_INIT();
    UT_ASSERT_EQUAL( result, PM_SUCCESS);
    
    /* Pass NULL value*/
    result = PLAT_API_GetClockSpeed(NULL);
    UT_ASSERT_EQUAL( result, PM_INVALID_ARGUMENT);  

    /* Calling to deinitialized the Platform HAL */
    PLAT_TERM();
    /* 
    * #TODO: Unclear how the function will fail, it may be due failure in underneath layer 
    */  


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

    return 0;
}
