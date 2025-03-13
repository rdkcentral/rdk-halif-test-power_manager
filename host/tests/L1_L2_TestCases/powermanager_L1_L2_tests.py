#!/usr/bin/env python3
#** *****************************************************************************
# *
# * If not stated otherwise in this file or this component's LICENSE file the
# * following copyright and licenses apply:
# *
# * Copyright 2024 RDK Management
# *
# * Licensed under the Apache License, Version 2.0 (the "License");
# * you may not use this file except in compliance with the License.
# * You may obtain a copy of the License at
# *
# *
# http://www.apache.org/licenses/LICENSE-2.0
# *
# * Unless required by applicable law or agreed to in writing, software
# * distributed under the License is distributed on an "AS IS" BASIS,
# * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# * See the License for the specific language governing permissions and
# * limitations under the License.
# *
#* ******************************************************************************

import os
import sys
import time

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from raft.framework.plugins.ut_raft.configRead import ConfigRead
from raft.framework.core.logModule import logModule
from raft.framework.plugins.ut_raft import utHelperClass
from raft.framework.plugins.ut_raft.utSuiteNavigator import UTSuiteNavigatorClass
from raft.framework.plugins.ut_raft.utBaseUtils import utBaseUtils
from raft.framework.core.commandModules.sshConsole import sshConsole

class powermanager_L1_L2_tests(utHelperClass):
    """
    Test class to interact with the device 
    
    and run the L1 and L2 tests on the device.

    """
    def __init__(self, log:logModule=None):
        """
        Initializes the test class
        """
        moduleName = "powermanager"

        testName = "powermanager_Test"
        qcId = "1"
        super().__init__(testName, qcId, log)

        deviceTestSetup = self.cpe.get("test")
        targetWorkspace = self.cpe.get("target_directory")

        # Get path to device profile file
        self.moduleConfigProfileFile = os.path.join(dir_path, deviceTestSetup.get("profile"))
        # Get the target workspace
        self.targetWorkspace = os.path.join(targetWorkspace, moduleName)

        # Load test setup configuration
        testSetupPath = os.path.join(dir_path, "powermanager_L1_L2_testSetup.yml")
        self.testSetup = ConfigRead(testSetupPath, moduleName)
        self.hal_session = self.dut.getConsoleSession("ssh_hal_test")

    def config_powermanager(self, moduleConfigProfileFile :str, session=None, testSuite:str=" ", targetWorkspace="/tmp"):
        """
        Initializes the powermanager instance with configuration settings.

        """
        self.moduleName = "powermanager"
        self.testConfigFile = os.path.join(dir_path, "powermanager_testConfig.yml")
        self.testSuite = testSuite

        # Load configurations for device profile and menu
        self.moduleConfigProfile = ConfigRead( moduleConfigProfileFile , self.moduleName)
        self.testConfig    = ConfigRead(self.testConfigFile, self.moduleName)
        self.testConfig.test.execute = os.path.join(targetWorkspace, self.testConfig.test.execute)
        self.utMenu        = UTSuiteNavigatorClass(self.testConfig, None, session)
        self.testConfig.test.execute = self.testConfig.test.execute + f" -p {os.path.basename(moduleConfigProfileFile)}"
        self.testSession   = session
        self.utils         = utBaseUtils()
        self.ports = self.moduleConfigProfile.fields.get("Ports")

        # Copy bin files to the target
        for artifact in self.testConfig.test.artifacts:
            filesPath = os.path.join(dir_path, artifact)
            self.utils.rsync(self.testSession, filesPath, targetWorkspace)

        # Copy the profile file to the target
        self.utils.scpCopy(self.testSession, moduleConfigProfileFile, targetWorkspace)

        # Start the user interface menu
        self.utMenu.start()
    
    def runTest(self, test_case:str=None):
        """
        Runs the test case passed to this funtion
        Args:
            test_case (str, optional): test case name to run, default runs all test
        Returns:
            bool: True - test pass, False - test fails
        """
        output = self.utMenu.select( self.testSuite, test_case)
        results = self.utMenu.collect_results(output)
        if results == None:
            results = False
        return results
    
    def waitAndVerifyDeviceUp(self, timeout: int = 120):
        """
        Waits for the system to come back up.

        Args:
            timeout (int): Maximum time in seconds to wait for the system to come up.

        Raises:
            TimeoutError: If the system doesn't come up within the timeout period.
        """
        time.sleep(timeout)
        status = self.waitForBoot()
        return status

    def testFunction(self):
        """
        The main test function to run the L1 and L2 tests.

        Returns:
            bool: Final result of the test.
        """
        testsuites = self.testSetup.fields.get('test_suites')

        finalresult = True

        for testsuite in testsuites:
            testsuite_name = testsuite.get("name")

            # Create the powermanager config instance
            self.config_powermanager(self.moduleConfigProfileFile, self.hal_session, testsuite_name, self.targetWorkspace)
            test_cases = testsuite.get("test_cases")

            if len(test_cases) == 1 and test_cases[0] == "all":
                self.log.stepStart(f'Test Suit: {testsuite_name} Run all Tests cases')
                # If 'all' test case mentioned in list, run all tests with 'r' option
                finalresult &= result
                self.log.stepResult(result, f'Test Suit: {testsuite_name} Run all Tests cases')
            else:
                for test_case in testsuite.get("test_cases"):
                    self.log.stepStart(f'Test Suit: {testsuite_name} Test Case: {test_case}')
                    result = self.runTest(test_case)
                    if test_case == "PLAT_Reset_L1_pos" or test_case == "PLAT_Reset_L1_neg":
                        result = self.waitAndVerifyDeviceUp()
                        if result == True:
                             self.hal_session.shell = None
                    finalresult &= result
                    self.log.stepResult(result, f'Test Suit: {testsuite_name} Test Case: {test_case}')

            if test_case == "PLAT_Reset_L1_pos" or test_case == "PLAT_Reset_L1_neg":
                continue
            else:
                self.utMenu.stop()
                
        return finalresult

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = powermanager_L1_L2_tests(summeryLog)
    test.run(False)
