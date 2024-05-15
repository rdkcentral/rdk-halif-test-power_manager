# Power Manager Test Document

## Version History

|Date(DD/MM/YY)|Comment|Version|
|--------------|-------|-------|
|20/02/24|First Release|1.0.0|

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Introduction](#introduction)
- [Module Description](#module-description)
- [Testing Scope](#testing-scope)
  - [Set And Get Power States](#set-and-get-power-states)
  - [Set and Get Status of Wakeup Sources](#set-and-get-status-of-wakeup-sources)
  - [Testing Wakeup Source](#testing-wakeup-source)
  - [Test Reset Functionality](#test-reset-functionality)

## Acronyms, Terms and Abbreviations

- `HAL` - Hardware Abstraction Layer
- `API` - Application Programming Interface
- `L2` - Level 2 Testing ()
- `L3` - Level 3 Testing ()
- `IR` - Infrared
- `CEC` - Consumer Electronics Control
- `LAN` - Local Area Network
- `NA` - Not Applicable

## Introduction

This document provides an overview of the testing requirements for the Power Manager module. It outlines the scope of testing, objectives, testing levels and approaches, specific test requirements, control plane emulator requirements and expected deliverables.

Interface of the test is available here: [Power Manager HAL header](https://github.com/rdkcentral/rdk-halif-power_manager/blob/main/include/plat_power.h)

## Module Description

The Power manger `HAL` provides a set of `APIs` to initialize, query and set the power state, and query and set the wake up source.

## Testing Scope

|#|Test Functionality|Description|
|-|------------------|-----------|
|1|[Set And Get Power States](#set-and-get-power-states)|Power Manager should set the power state provided by caller and same should be retrieved|
|2|[Set and Get Status of Wakeup Sources](#set-and-get-status-of-wakeup-sources)|Power Manager should set the wakeup source provided by caller and same should be retrieved|
|3|[Testing Wakeup Source](#testing-wakeup-source)|Power manager should accept the supported wakeup sources and device should wakeup from standby/sleep modes using wakeup sources set by caller|
|4|[Test Reset Functionality](#test-reset-functionality)|Power manager should reboot the device|

## Emulator Requirements

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
- `LAN` wake up

## Set And Get Power States

|S.No.|Test Functionality|Description|HAL APIs|L2|L3|Control plane requirements|
|-----|------------------|-----------|--------|--|--|--------------------------|
|1|[Set and Get Power States](#set-and-get-power-states)|Set various power states and retrieve it for verification |PLAT_API_SetPowerState, PLAT_API_GetPowerState|Y|`NA`|`NA`|`NA`|

### Test Startup Requirement - Set And Get Power States

`NA`

### Emulator Requirements - Set And Get Power States

`NA`

### Control Plane Requirements - Set And Get Power States

`NA`

## Set and Get Status of Wakeup Sources

|S.No.|Test Functionality|Description|HAL APIs|L2|L3|Control plane requirements|
|-----|------------------|-----------|--------|--|--|--------------------------|
|1|[Set and Get Status of Wakeup Sources](#set-and-get-status-of-wakeup-sources)|Set status of various wakeup sources and retrieves status for verification |PLAT_API_SetWakeupSrc, PLAT_API_GetWakeupSrc|Y|`NA`|`NA`|`NA`|

### Test Startup Requirement - Set and Get Status of Wakeup Sources

`NA`

### Emulator Requirements - Set and Get Status of Wakeup Sources

[Emulator Requirements](#emulator-requirements)

### Control Plane Requirements - Set and Get Status of Wakeup Sources

`NA`

## Testing Wakeup Source

|S.No.|Test Functionality|Description|HAL APIs|L2|L3|Control plane requirements|
|-----|------------------|-----------|--------|--|--|--------------------------|
|1|[Testing Wakeup Source](#testing-wakeup-source)|Power manager should accept the supported wakeup sources and device should wakeup from standby/sleep modes using wakeup sources set by caller|PLAT_API_SetWakeupSrc, PLAT_DS_SetDeepSleep|`NA`|Y|Control plane to trigger the wakeup source|

### Test Startup Requirement - Testing Wakeup Source

`NA`

### Emulator Requirements - Testing Wakeup Source

[Emulator Requirements](#emulator-requirements)

### Control Plane Requirements - Testing Wakeup Source

Control plane to trigger the wakeup source supported by platform

## Test Reset Functionality

|S.No.|Test Functionality|Description|HAL APIs|L2|L3|Control plane requirements|
|-----|------------------|-----------|--------|--|--|--------------------------|
|1|[Test Reset Functionality](#test-reset-functionality)|Power manager should reboot the device|PLAT_Reset|`NA`|Y|`NA`||

### Test Startup Requirement - Test Reset Functionality

`NA`

### Emulator Requirements - Test Reset Functionality

`NA`

### Control Plane Requirements - Test Reset Functionality

- Discuss options to verify that the device as rebooted successfuly.
    - Monitor power usage via control panel
    - Verify that the device has rebooted via connectivity with another device
    - Verify that the reboot as occurred by reconnecting to the device and calling linux `uptime` command