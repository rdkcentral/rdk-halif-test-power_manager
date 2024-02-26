# Power Manager Test Document
 
## Version History
 
| Date(DD/MM/YY) | Comment       | Version |
| -------------- | ------------- | ------- |
| 20/02/24       | First Release | 1.0.0   |
 
## Table of Contents
- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Overview](#overview)
- [Power Manager RDK HAL Functionality](#power-manager-rdk-hal-functionality)
- [Test Scenarios](#test-scenarios)
 
## Acronyms, Terms and Abbreviations
- `HAL`   - Hardware Abstraction layer
- `L2` - Level 2 Testing ()
- `L3` - Level 3 Testing ()
- `IR` - Infrared
## Scope
This document defines the requirements for testing the Power Manager from a level 2/3 based on being a sink device.

## Overview

## Power Manager RDK HAL Functionality
The HAL layer of Power Manager facilitate the following functionalities:
- Sets the Wakeup Sources for Standby/Light Sleep/Deep Sleep Mode
- Maintains the power state
- Resets the device on user requests

## Test Scenarios
The current test cases will verify responses from connected devices for a subset of opcodes as part of the testing process.

|S.No.|Test Functionality|Description|
|-----|------------------|-----------|
| 1 | [Set And Get Various Power States](#set-and-get-various-power-states)|Power Manager should set the power state provided by caller and same should be retrived |
| 2| [Testing Wakeup Source](#testing-wakeup-source)| Power manager should accept the supported wakeup soruces and device should wakeup from standby/sleep modes using wakeup sources set by caller|
| 3|[Test Reset Functionlity](#test-reset-functionlity) | Power manager should reboot the device |

## Set And Get Various Power States
|S.No.|Test Functionality|Description|L2|L3|Control plane requirements|
|-----|------------------|-----------|--|--|--------------------------|
| 1 |[Set And Get Various Power States](#set-and-get-various-power-states)|Set various power states and retrive it for verification |Y|NA|NA|
### Emulator Requirements
NA
### Control Plane Requirements
NA
## Testing Wakeup Source
|S.No.|Test Functionality|Description|L2|L3|Control plane requirements|
|-----|------------------|-----------|--|--|--------------------------|
| 1 |[Testing Wakeup Source](#testing-wakeup-source)| Power manager should accept the supported wakeup soruces and device should wakeup from standby/sleep modes using wakeup sources set by caller|NA|Y|Control panel to trigger the wakeup source. Supported Wakeup sources are: <br/> <ul><li>Voice Wakeup</li><li>Presence Detection wake up</li><li>Bluetooth wake up</li><li>Wifi wake up</li><li>IR wake up</li><li>Power key wake up</li><li>Timer wake up</li><li>CEC wake up</li><li>LAN wake up</li></ul>|
### Emulator Requirements
- Boot configuration: Wakeup sources supported by the device
### Control Plane Requirements
- Control panel to trigger the wakeup source (IR, Bluetooth, front panel etc)
## Test Reset Functionlity
|S.No.|Test Functionality|Description|L2|L3|Control plane requirements|
|-----|------------------|-----------|--|--|--------------------------|
| 1 |[Test Reset Functionlity](#test-reset-functionlity)|  Power manager should reboot the device|Y|NA|NA|
### Emulator Requirements
- NA
### Control Plane Requirements
- NA
