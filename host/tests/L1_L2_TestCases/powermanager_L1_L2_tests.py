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

        # Open the session
        self.hal_session = self.dut.getConsoleSession("ssh_hal_test")

        # Open Suite navigator
        self.testConfigFile = os.path.join(dir_path, "powermanager_testConfig.yml")
        self.testConfig    = ConfigRead(self.testConfigFile, moduleName)
        self.testConfig.test.execute = os.path.join(self.targetWorkspace, self.testConfig.test.execute)
        self.testConfig.test.execute = self.testConfig.test.execute + f" -p {os.path.basename(self.moduleConfigProfileFile)}"
        self.utMenu        = UTSuiteNavigatorClass(self.testConfig, None, self.hal_session)

        # Copy the binaries to the target
        self.baseUtils         = utBaseUtils()

        # Copy bin files to the target
        for artifact in self.testConfig.test.artifacts:
            filesPath = os.path.join(dir_path, artifact)
            self.baseUtils.rsync(self.hal_session, filesPath, targetWorkspace)

        # Copy the profile file to the target
        self.baseUtils.scpCopy(self.hal_session, self.moduleConfigProfileFile, targetWorkspace)

    def runTest(self, testsuite_name:str, test_case:str=None):
        """
        Runs the test case passed to this funtion
        Args:
            test_case (str, optional): test case name to run, default runs all test
        Returns:
            bool: True - test pass, False - test fails
        """
        output = self.utMenu.select( testsuite_name, test_case)
        results = self.utMenu.collect_results(output)
        if results == None:
            results = False
        return results

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

            self.utMenu.start()

            test_cases = testsuite.get("test_cases")

            if len(test_cases) == 1 and test_cases[0] == "all":
                self.log.stepStart(f'Test Suit: {testsuite_name} Run all Tests cases')
                # If 'all' test case mentioned in list, run all tests with 'r' option
                result = self.runTest()
                if not result:
                    finalresult = False
                self.log.stepResult(result, f'Test Suit: {testsuite_name} Run all Tests cases')
            else:
                for test_case in testsuite.get("test_cases"):
                    self.log.stepStart(f'Test Suit: {testsuite_name} Test Case: {test_case}')
                    result = self.runTest(testsuite_name, test_case)
                    if not result:
                        finalresult = False
                    self.log.stepResult(result, f'Test Suit: {testsuite_name} Test Case: {test_case}')

            self.utMenu.stop()

        return finalresult

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = powermanager_L1_L2_tests(summeryLog)
    test.run(False)
