# Unit Testing Suite For Power Manager HAL

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Description](#description)
- [Reference Documents](#reference-documents)
- [How to build the test suite](#how-to-build-the-test-suite)
- [Notes](#notes)
- [Manual way of running the L1 and L2 test cases](#manual-way-of-running-the-l1-and-l2-test-cases)
- [Setting Python environment for running the L1 L2 automation test cases](#setting-python-environment-for-running-the-l1-l2-automation-test-cases)

## Acronyms, Terms and Abbreviations

- `HAL`- Hardware Abstraction Layer
- `L1` - Functional Tests
- `L2` - Module functional Testing
- `High-Level Test Specification` : These specification will provide a broad overview of the system's functionality from the callers' perspective. It focuses on major use cases, system behavior, and overall caller experience.
- `Low-Level Test Specification` : These specification will deeper into the technical details. They will define specific test cases with inputs, expected outputs, and pass/fail criteria for individual functionalities, modules, or APIs.

## Description

This repository contains the Unit Test Suites (`L1` and `L2`) for Power Manager `HAL`.

## Reference Documents

|SNo|Document Name|Document Description|Document Link|
|---|-------------|--------------------|-------------|
|1|`HAL` Specification Document|This document provides specific information on the APIs for which tests are written in this module|[power-manager_halSpec.md](https://github.com/rdkcentral/rdk-halif-power_manager/blob/main/docs/pages/power-manager_halSpec.md)|
|2|High Level Test Specification |High Level Test Specification Documentation this module |[power-manager_High-Level_TestSpec.md](https://github.com/rdkcentral/rdk-halif-test-power_manager/blob/main/docs/pages/power-manager_High-Level_TestSpec.md)|
|3|`L2` Low Level Test Specification |`L2`Low Level Test Specification Documentation this module |[power-manager_L2_Low-Level_TestSpec.md](https://github.com/rdkcentral/rdk-halif-test-power_manager/blob/main/docs/pages/power-manager_L2_Low-Level_TestSpec.md)|
|4|`L1` and `L2` Test Procedure Document|`L1` and `L2` Test Procedure Document|[power-manager_L1_L2_TestProcedure.md](docs/pages/power-manager_L1_L2_TestProcedure.md)|

## Notes

- All APIs need to be implemented in this current version. If any API is not supported, please add stub implementation with return type PWRMGR_OPERATION_NOT_SUPPORTED for the same.
- Building against the actual library may introduce SOC dependencies. Hence, a template SKELETON library is created without SOC dependencies. On the real platform (target), it can be mounted, copied and bound with the actual library.
- When executing the binary, ensure to include a platform-specific profile file as an argument for the designated test cases. The following example illustrates this:

## How to build the test suite

In order to build the test suits, there is a requirement to supply the toolchain, either as a vendor independent toolchain, an SDK, or an RDK Docker Toolchain .

For more information about RDK Docker Toolchain, please check [RDK Docker Toolchain](https://github.com/rdkcentral/ut-core/wiki/FAQ:-RDK-Docker-Toolchain)

- Export the Toolchain Path:

```bash
export TOOLCHAIN_PATH=/opt/toolchains/rdk-glibc-x86_64/sysroots/armv7at2hf-neon-rdk-linux-gnueabi
export CC="arm-rdk-linux-gnueabi-gcc  -march=armv7-a -mthumb -mfpu=neon -mfloat-abi=hard --sysroot=$TOOLCHAIN_PATH"
```

- Clone the `HAL` Repository:

```bash
git clone git@github.com:rdkcentral/rdk-halif-power_manager.git
```

- Set Project Version:

If you want to build the test repository with a specific tag or branch, set the UT_PROJECT_VERSION variable accordingly. If not set, the default main branch will be used.

```bash
export UT_PROJECT_VERSION=1.0.1  # Build using a specific tag
```

or

```bash
export UT_PROJECT_VERSION=develop  # Build using a specific branch
```

- Build Targets:

 There are two targets for the platform

  1. linux - (default)
  2. arm - TARGET=arm

```bash
build_ut.sh TARGET=arm
```

- `build_ut.sh` script will clone the hal-test repo, ut-core and generate a `hal_test_iarmmgrs-power-hal` binary in `ut/bin/` upon successful completion.

### Manual way of running the `L1` and `L2` test cases

```bash
./hal_test_iarmmgrs-power-hal -p sink_powerManager.yaml
 ```

Alternatively, use the run.sh script with the profile file:

```bash
./run.sh -p /absolute/path/to/profile/file
 ```

- Profiles file available for sink [sink_powerManager yaml file](https://github.com/rdkcentral/rdk-halif-test-power_manager/blob/main/profiles/sink/sink_powerManager.yaml)
- Profiles file available for source [source_powerManager yaml file](https://github.com/rdkcentral/rdk-halif-test-power_manager/blob/main/profiles/source/source_powerManager.yaml)

### Setting Python environment for running the `L1` `L2` automation test cases

- Install Python Environment and Activation Scripts please check the[HPK Documentation](https://github.com/rdkcentral/rdk-hpk-documentation/blob/main/README.md)
- To run the `L1` `L2` test cases follow the [power-manager_L1_L2_TestProcedure.md](docs/pages/power-manager_L1_L2_TestProcedure.md)
