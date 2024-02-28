# Power Manager Test Document
 
## Version History
 
|Date(DD/MM/YY)|Comment|Version|
|--------------|-------|-------|
|20/02/24|First Release|1.0.0|
 
## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Overview](#overview)
- [Power Manager RDK HAL Functionality](#power-manager-rdk-hal-functionality)
- [Test Scenarios](#test-scenarios)
 
## Acronyms, Terms and Abbreviations

- `HAL` - Hardware Abstraction Layer
- `API` - Application Programming Interface
- `L2` - Level 2 Testing ()
- `L3` - Level 3 Testing ()
- `IR` - Infrared
- `CEC` - Consumer Electronics Control
- `LAN` - Local Area Network
- `NA` - Not Applicable

## Scope

This document defines the requirements for testing the Power Manager from a level 2/3.

## Overview

The Power manger `HAL` provides a set of `APIs` to initialize, query and set the power state, and query and set the wake up source.
Refer [Power Manager HAL header](https://github.com/rdkcentral/rdk-halif-power_manager/blob/main/include/plat_power.h) for more information

## Power Manager RDK HAL Functionality

The `HAL` layer of Power Manager facilitate the following functionalities:
- Sets the Wakeup Sources for Standby/Light Sleep/Deep Sleep Mode
- Maintains the power state
- Resets the device on user requests

## Test Scenarios

|#|Test Functionality|Description|
|-|------------------|-----------|
|1|[Set And Get Power States](#set-and-get-power-states)|Power Manager should set the power state provided by caller and same should be retrived|
|2|[Set and Get Status of Wakeup Sources](#set-and-get-status-of-wakeup-sources)|Power Manager should set the wakeup source provided by caller and same should be retrived|
|3|[Testing Wakeup Source](#testing-wakeup-source)|Power manager should accept the supported wakeup soruces and device should wakeup from standby/sleep modes using wakeup sources set by caller|
|4|[Test Reset Functionlity](#test-reset-functionlity)|Power manager should reboot the device|

## Set And Get Power States

|Description|L2|L3|Control plane requirements|
|-----------|--|--|--------------------------|
|Set various power states and retrive it for verification |Y|`NA`|`NA`|

### Test Startup Requirement

`NA`

### Emulator Requirements

`NA`

### Control Plane Requirements

`NA`

### Test Procedure

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

**Procedure :**

- Set the Power state using the function `PLAT_API_SetPowerState()`
- Get the Power state using the function `PLAT_API_GetPowerState()`
- Verify the Power state retrived matches with the set value

|Variation / Steps|Description|Test Data|Expected Result|Notes|
|-----------------|-----------|---------|---------------|-----|
|01|Set the Power State|`NA`|Set the Power power state|Should be successful|
|02|Get the Power State|`NA`|Get the Power power state|Should be successful|
|03|Validate Power State|`NA`|Compare the power state values from step 01 and 02|Values should match|

## Set and Get Status of Wakeup Sources

|Description|L2|L3|Control plane requirements|
|-----------|--|--|--------------------------|
|Set status of various wakeup sources and retrives status for verification |Y|`NA`|`NA`|

### Test Startup Requirement

`NA`

### Emulator Requirements

Boot configuration: Wakeup sources supported by the device
Wakeup sources:
- Voice Wakeup
- Presence Detection wake up
- Bluetooth wake up
- Wifi wake up
- `IR` wake up
- Power key wake up
- Timer wake up
- `CEC` wake up
- `LAN` wake up</li></ul>

### Control Plane Requirements

`NA`

### Test Procedure

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

**Procedure :**

- Enable/Disable the wakeup source using the function `PLAT_API_SetWakeupSrc()`
- Get the status of wakeup source using the function `PLAT_API_GetWakeupSrc()`
- Verify the status of wakeup source retrived matches with the set value

|Variation / Steps|Description|Test Data|Expected Result|Notes|
|-----------------|-----------|---------|---------------|-----|
|01|Set the status of wakeup source|`NA`|Set the status of wakeup source|Should be successful|
|02|Get the status of wakeup source|`NA`|Get the status of wakeup source|Should be successful|
|03|Validate Status|`NA`|Compare the set status values from step 01 and 02|Status should match|

## Testing Wakeup Source

|Description|L2|L3|Control plane requirements|
|-----------|--|--|--------------------------|
|Power manager should accept the supported wakeup soruces and device should wakeup from standby/sleep modes using wakeup sources set by caller|`NA`|Y|Control panel to trigger the wakeup source|

### Test Startup Requirement

`NA`

### Emulator Requirements

Boot configuration: Wakeup sources supported by the device

### Control Plane Requirements

Control panel to trigger the wakeup source. Supported Wakeup sources are:
- Voice Wakeup
- Presence Detection wake up
- Bluetooth wake up
- Wifi wake up
- `IR` wake up
- Power key wake up
- Timer wake up
- `CEC` wake up
- `LAN` wake up</li></ul>

### Test Procedure

|Title|Details|
|-----|-------|
|Function Name|`PLAT_API_SetWakeupSrc()`|
|Description|This fumction enables or disables the Wakeup source type|
|Test Group|02|
|Priority|High|

**Pre-Conditions :**

- `PLAT_INIT()` must be called before calling dsGetSocIDFromSDK() function
- `PLAT_TERM()` must be called after calling dsGetSocIDFromSDK() function

**Procedure :**

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

## Test Reset Functionlity

|Description|L2|L3|Control plane requirements|
|-----------|--|--|--------------------------|
|Power manager should reboot the device|Y|`NA`|`NA`|

### Test Startup Requirement

`NA`

### Emulator Requirements

`NA`

### Control Plane Requirements
`NA`

### Test Procedure

|Title|Details|
|-----|-------|
|Function Name|`PLAT_Reset()`|
|Description|Resets the power state of the device|
|Test Group|02|
|Priority|High|

**Pre-Conditions :**

- `PLAT_INIT()` must be called before calling dsGetSocIDFromSDK() function
- `PLAT_TERM()` must be called after calling dsGetSocIDFromSDK() function

**Procedure :**

- Reboot the box using `PLAT_Reset()`

|Variation / Steps|Description|Test Data|Expected Result|Notes|
|-----------------|-----------|---------|---------------|-----|
|01|Reboot the box|`NA`|Reboot the box|Should be successful|

