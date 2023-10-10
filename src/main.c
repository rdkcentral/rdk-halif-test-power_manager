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
 * @defgroup POWER_MANAGER_HALTEST Power Manager HAL Tests
 * @{
 */

/**
 * @defgroup PLAT_POWER_HALTEST_MAIN Power Manager Test Main File
 * @{
 */

/**
* @file main.c
* @page module_name @todo Required field, name of the main module
* @subpage sub_page_name @todo Add a function group if relevant
*
* ## Module's Role
* @todo Explain the module's role in the system in general
* This is to ensure that the API meets the operational requirements of the module across all vendors.
*
* **Pre-Conditions:**  @todo Add pre-conditions if any@n
* **Dependencies:** @todo Add dependencies if any@n
*
* Ref to API Definition specification documentation : [halSpec.md](../../../docs/halSpec.md)
*/

#include <ut.h>

extern int UT_register_APIDEF_l1_tests( void );
extern int UT_register_APIDEF_l2_tests( void );

int main(int argc, char** argv) 
{
	int registerReturn = 0;

	/* Register tests as required, then call the UT-main to support switches and triggering */
	UT_init( argc, argv );

	/* Check if tests are registered successfully */

	registerReturn = UT_register_APIDEF_l1_tests();
	if ( registerReturn == -1 )
	{
		printf("\n UT_register_APIDEF_l1_tests() returned failure");
		return -1;
	}

	registerReturn = UT_register_APIDEF_l2_tests();
	if ( registerReturn == -1 )
	{	
		printf("\n UT_register_APIDEF_l2_tests() returned failure");
		return -1;
	}

	/* Begin test executions */
	UT_run_tests();

	return 0;

}
