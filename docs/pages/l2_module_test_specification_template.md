# L2 Test Specification template

## Version History

|Date(DD/MM/YY)|Comment|Version|
|--------------|-------|-------|
|20/02/24|First Release|1.0.0|

## Table of Contents

- [Overview](#overview)
  - [Acronyms](#acronyms-terms-and-abbreviations)
  - [Definitions](#definitions)
  - [References](#references)
- [Level 2 Test Suite](#level-2-test-suite)
  - [Set And Get Power States](#set-and-get-power-states)
  - [Set and Get Status of Wakeup Sources](#set-and-get-status-of-wakeup-sources)
  - [Testing Wakeup Source](#testing-wakeup-source)
  - [Test Reset Functionlity](#test-reset-functionlity)

## Overview

This document describes the level 2 testing suite for the module.

### Acronyms, Terms and Abbreviations

- `HAL` \- Hardware Abstraction Layer, may include some common components
- `HAL.h`  \- Abstracted defined API to control the hardware
- `HAL.c`  \- Implementation wrapper layer created by the `OEM` or `SoC` Vendor.
- `RDK`  \- Reference Design Kit for All Devices
- `RDK-B`  \- Reference Design Kit for Broadband Devices
- `RDK-V`  \- Reference Design Kit for Video Devices
- `UT`  \- Unit Test(s)
- `OEM`  \- Original Equipment Manufacture (Sky is also an OEM)
- `SoC`  \- System on a Chip
- `NA` \- Not Applicable

### Definitions

- `Broadcom` \- `SoC` manufacturer <https://www.broadcom.com/>
- `Amlogic` \- `SoC` manufacturer <https://en.wikipedia.org/wiki/Amlogic>
- `Soc Vendor` \- Definition to encompass multiple vendors
- `Unit Tests` \- C Function tests that run on the target hardware
- `Common Testing Framework` \- Off the shelf 3rd Party Testing Framework, or framework that does not require infrastructure to control it. That's not to say it cannot be controlled via infrastructure if required. Examples of which are.
  - `GTest` \- Google Test Suit <https://google.github.io/googletest>
  - `CUnit` \- C Testing Suit <http://cunit.sourceforge.net/>
  - `Unity` \- C Embedded Testing Suit <http://www.throwtheswitch.org/unity>
  - `ut-core` \- Common Testing Framework <https://github.com/rdkcentral/ut-core>, which wraps a open-source framework that can be expanded based on future requirements.

### References

- `Feedback Loops` \- <https://www.softwaretestingnews.co.uk/4-methods-to-improve-your-feedback-loops-and-supercharge-your-testing-process/>
- `Doxygen` \- SourceCode documentation tool - <https://www.doxygen.nl/index.html>
- `Black Box Testing` \- <https://en.wikipedia.org/wiki/Black-box_testing>

## Level 2 Test Suite

The following functions are expecting to test the module operates correctly.

### Set And Get Power States

|Title|Details|
|-----|-------|
|Function Name|`PLAT_API_SetPowerState()`|
|Description|This fumction is just required to hold the value of the current power state status|
|Test Group|02|
|Priority|High|

|Title|Details|
|-----|-------|
|Function Name|`PLAT_API_GetPowerState()`|
|Description|This fumction is gets the current power state status|
|Test Group|02|
|Priority|High|

**Pre-Conditions :**

- `PLAT_INIT()` must be called before calling dsGetSocIDFromSDK() function
- `PLAT_TERM()` must be called after calling dsGetSocIDFromSDK() function

**Dependencies :**

`NA`

**User Interaction :**

`NA`

#### Test Procedure - Set And Get Power States

- Set the Power state using the function `PLAT_API_SetPowerState()`
- Get the Power state using the function `PLAT_API_GetPowerState()`
- Verify the Power state retrived matches with the set value

|Variation / Steps|Description|Test Data|Expected Result|Notes|
|-----------------|-----------|---------|---------------|-----|
|01|Set the Power State|`NA`|Set the Power power state|Should be successful|
|02|Get the Power State|`NA`|Get the Power power state|Should be successful|
|03|Validate Power State|`NA`|Compare the power state values from step 01 and 02|Values should match|

### Set and Get Status of Wakeup Sources

|Title|Details|
|-----|-------|
|Function Name|`PLAT_API_SetWakeupSrc()`|
|Description|This fumction enables or disables the Wakeup source type|
|Test Group|02|
|Priority|High|

|Title|Details|
|-----|-------|
|Function Name|`PLAT_API_GetWakeupSrc()`|
|Description|This fumction checks if the wake up source is enabled or disabled for the device|
|Test Group|02|
|Priority|High|

**Pre-Conditions :**

- `PLAT_INIT()` must be called before calling dsGetSocIDFromSDK() function
- `PLAT_TERM()` must be called after calling dsGetSocIDFromSDK() function

**Dependencies :**

`NA`

**User Interaction :**

`NA`

#### Test Procedure - Set and Get Status of Wakeup Sources

- Enable/Disable the wakeup source using the function `PLAT_API_SetWakeupSrc()`
- Get the status of wakeup source using the function `PLAT_API_GetWakeupSrc()`
- Verify the status of wakeup source retrived matches with the set value

|Variation / Steps|Description|Test Data|Expected Result|Notes|
|-----------------|-----------|---------|---------------|-----|
|01|Set the status of wakeup source|`NA`|Set the status of wakeup source|Should be successful|
|02|Get the status of wakeup source|`NA`|Get the status of wakeup source|Should be successful|
|03|Validate Status|`NA`|Compare the set status values from step 01 and 02|Status should match|

### Testing Wakeup Source

|Title|Details|
|-----|-------|
|Function Name|`PLAT_API_SetWakeupSrc()`|
|Description|This fumction enables or disables the Wakeup source type|
|Test Group|02|
|Priority|High|

**Pre-Conditions :**

- `PLAT_INIT()` must be called before calling dsGetSocIDFromSDK() function
- `PLAT_TERM()` must be called after calling dsGetSocIDFromSDK() function

**Dependencies :**

`NA`

**User Interaction :**

`NA`

#### Test Procedure - Testing Wakeup Source

- Enable/Disable the wakeup source using the function `PLAT_API_SetWakeupSrc()`
- Change the device state to Standby
- Wakeup the device
- Verify the wakeup source matches with the set value

|Variation / Steps|Description|Test Data|Expected Result|Notes|
|-----------------|-----------|---------|---------------|-----|
|01|Set the status of wakeup source|`NA`|Set the status of wakeup source|Should be successful|
|02|Change the device state to Standby|`NA`|Change the device state to Standby|Should be successful|
|03|Wakeup the device|`NA`|Wakeup the device|Should be successful|
|04|Verify the wakeup source|`NA`|Wakeup source should matches with the set value|Should be successful|

### Test Reset Functionlity

|Title|Details|
|-----|-------|
|Function Name|`PLAT_Reset()`|
|Description|Resets the power state of the device|
|Test Group|02|
|Priority|High|

**Pre-Conditions :**

- `PLAT_INIT()` must be called before calling dsGetSocIDFromSDK() function
- `PLAT_TERM()` must be called after calling dsGetSocIDFromSDK() function

**Dependencies :**

`NA`

**User Interaction :**

`NA`

#### Test Procedure - Test Reset Functionlity

- Reboot the box using `PLAT_Reset()`

|Variation / Steps|Description|Test Data|Expected Result|Notes|
|-----------------|-----------|---------|---------------|-----|
|01|Reboot the box|`NA`|Reboot the box|Should be successful|
