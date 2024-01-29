/**
*  If not stated otherwise in this file or this component's LICENSE
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
 *
 */

/**
 * @defgroup PLAT_POWER_HALTEST_L2 Power Manager HAL Test L2 File
 * @{
 * @parblock
 *
 * ### L2 Tests for Power Manager HAL :
 *
 * Level 2 module tests will perform module level testing by exercising the full set of APIs to validate various use cases.
 * This is to ensure that the APIs meets the operational requirements of the module across all vendors.
 *
 * **Pre-Conditions:**  None @n
 * **Dependencies:** None @n
 *
 * Refer to API Definition specification documentation : [power-manager_halSpec.md](../../docs/pages/power-manager_halSpec.md)
 *
 * @endparblock
 */

/**
* @file test_l2_plat_power.c
*
*/

#include <string.h>
#include <stdlib.h>

#include <ut.h>
#include <ut_log.h>

/**
* @brief TODO Describe the object of the test
*
* TODO Add the description of what is tested and why in this test
*
* **Test Group ID:** TODO Add the group this test belongs to - Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO Add the ID of the test case so that it can be logically tracked in the logs@n
*
* **Test Procedure:**
* Refer to UT specification documentation [l2_module_test_specification.md](l2_module_test_specification.md)
*/
void test_l2_plat_power (void)
{
	UT_FAIL("This function needs to be implemented!");
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main test(s) for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int test_l2_plat_power_register ( void )
{
	/* add a suite to the registry */
	pSuite = UT_add_suite( "[L2 plat_power]", NULL, NULL );
	if ( NULL == pSuite )
	{
		return -1;
	}	

	
	UT_add_test( pSuite, "test_l2_plat_power" ,test_l2_plat_power );

	return 0;
} 

/** @} */ // End of PLAT_POWER_HALTEST_L2
/** @} */ // End of POWER_MANAGER_HALTEST
/** @} */ // End of POWER_MANAGER
/** @} */ // End of HPK
