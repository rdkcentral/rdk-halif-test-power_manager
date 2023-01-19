# Level 1 HAL Testing Specification (TBC)

## History

|Version|Date (YY-MM-DD)|Author|
|-------|-----|-----|
|1.0.0| 12/22/2022 |Rajnish Dey|

## Document Scope

This document will define the requirements for Level 1 testing for this HAL.

## Table of Contents

- [Overview](#overview)
- [Acronyms](#acronyms)
- [Definitions](#definitions)
- [References](#references)
- [L1 Testing Requirements](#l1-testing-requirements)

## Acronyms

- `HAL` \- Hardware Abstraction Layer, may include some common components
- `HAL.h` \- Abstracted defined API to control the hardware
- `HAL.c` \- Implementation wrapper layer created by the `OEM` or `SoC` Vendor.
- `RDK` \- Reference Design Kit for All Devices
- `RDK-B` \- Reference Design Kit for Broadband Devices
- `RDK-V` \- Reference Design Kit for Video Devices
- `UT` \- Unit Test(s)
- `OEM` \- Original Equipment Manufacture (Sky is also an OEM)
- `SoC` \- System on a Chip

## Definitions

- `Broadcom` \- `SoC` manufacturer [https://www.broadcom.com/]
- `Amlogic` \- `SoC` manufacturer [https://en.wikipedia.org/wiki/Amlogic]
- `Soc Vendor` \- Definition to encompass multiple vendors
- `Unit Tests` \- C Function tests that run on the target hardware
- `Common Testing Framework` \- Off the shelf 3rd Party Testing Framework, or framework that does not require infrastructure to control it. That's not to say it cannot be controlled via infrastructure if required. Examples of which are.
  - GTest - [https://google.github.io/googletest] \- Google Test Suit
  - CUnit - [http://cunit.sourceforge.net/] \- C Testing Suit
  - Unity - [http://www.throwtheswitch.org/unity] -C Embedded Testing Suit
- `ut-core` - Common Testing Framework [https://github.com/comcast-sky/rdk-components-ut-core]

## References

- `Feedback Loops` \- [https://www.softwaretestingnews.co.uk/4-methods-to-improve-your-feedback-loops-and-supercharge-your-testing-process/]
- `Doxygen` \- SourceCode documentation tool - [https://www.doxygen.nl/index.html]
- `Black Box Testing` \- [https://en.wikipedia.org/wiki/Black-box_testing]

## L1 Testing Requirements

As per the definition of the header files, take all the API's possible and create positive and negative test cases to ideally exercise the complete interface.

The interface is defined by the git repository `[git@github.com:comcast-sky/rdk-components-haltest-powermanager.git]` which is accessible via the link [https://github.com/comcast-sky/rdk-components-haltest-powermanager]

from the template in `ut-core/framework/hal_template` the `UT` suite will be triggered.

## plat_power.h

```
pwrmgrHalError_t PLAT_INIT(void);
pwrmgrHalError_t PLAT_API_SetPowerState(IARM_Bus_PWRMgr_PowerState_t newState);
pwrmgrHalError_t PLAT_API_GetPowerState(IARM_Bus_PWRMgr_PowerState_t *curState);
pwrmgrHalError_t PLAT_API_GetTemperature(IARM_Bus_PWRMgr_ThermalState_t *curState, float *curTemperature, float *wifiTemperature);
pwrmgrHalError_t PLAT_API_SetTempThresholds(float tempHigh, float tempCritical);
pwrmgrHalError_t PLAT_API_GetTempThresholds(float *tempHigh, float *tempCritical);
pwrmgrHalError_t PLAT_API_DetemineClockSpeeds(uint32_t *cpu_rate_Normal, uint32_t *cpu_rate_Scaled, uint32_t *cpu_rate_Minimal);
pwrmgrHalError_t PLAT_API_SetClockSpeed(uint32_t speed);
pwrmgrHalError_t PLAT_API_GetClockSpeed(uint32_t *speed);
void PLAT_TERM(void);
```