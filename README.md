# Unit Testing Suite For Power Manager HAL

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Description](#description)
- [Reference Documents](#reference-documents)
- [Notes](#notes)

## Acronyms, Terms and Abbreviations

- `L1` - Functional Tests
- `HAL`- Hardware Abstraction Layer

## Description

This repository contains the Unit Test Suites (L1) for Power Manager `HAL`.

## Reference Documents

<!-- Need to update links to rdkcentral and point to branch main-->
|SNo|Document Name|Document Description|Document Link|
|---|-------------|--------------------|-------------|
|1|`HAL` Specification Document|This document provides specific information on the APIs for which tests are written in this module|[power-manager_halSpec.md](https://github.com/rdkcentral/rdk-halif-power_manager/blob/main/docs/pages/power-manager_halSpec.md "power-manager_halSpec.md")|
|2|`L1` Tests |`L1` Test Case File for this module |[test_l1_plat_power.c](https://github.com/rdkcentral/rdk-halif-test-power_manager/blob/main/src/test_l1_plat_power.c "test_l1_plat_power.c")|

## Notes

- All APIs need to be implemented in this current version. If any API is not supported, please add stub implementation with return type PWRMGR_SUCCESS for the same.
- Building against the actual library may introduce SOC dependencies. Hence, a template SKELETON library is created without SOC dependencies. On the real platform (target), it can be mounted, copied and bound with the actual library.
- To run the binary, ensure that pass the profile file as an argument. The following example demonstrates how to do this: ./hal_test -p powermanagerExtendedEnumsNotSupported.yaml
- Profiles file available in [profile yaml file](./profiles/powermanagerExtendedEnumsNotSupported.yaml)