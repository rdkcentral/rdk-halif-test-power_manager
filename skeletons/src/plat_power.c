#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
//#include "cmock.h"
#include "plat_power.h"


pmError_t PLAT_INIT(void)
{
  /*TODO: Implement Me!*/
  return (pmError_t)0;
}

pmError_t PLAT_API_SetPowerState(IARM_Bus_PWRMgr_PowerState_t newState)
{
  /*TODO: Implement Me!*/
  (void)newState;
  return (pmError_t)0;
}

pmError_t PLAT_API_GetPowerState(IARM_Bus_PWRMgr_PowerState_t* curState)
{
  /*TODO: Implement Me!*/
  (void)curState;
  return (pmError_t)0;
}

pmError_t PLAT_API_GetTemperature(IARM_Bus_PWRMgr_ThermalState_t* curState, float* curTemperature, float* wifiTemperature)
{
  /*TODO: Implement Me!*/
  (void)curState;
  (void)curTemperature;
  (void)wifiTemperature;
  return (pmError_t)0;
}

pmError_t PLAT_API_SetTempThresholds(float tempHigh, float tempCritical)
{
  /*TODO: Implement Me!*/
  (void)tempHigh;
  (void)tempCritical;
  return (pmError_t)0;
}

pmError_t PLAT_API_GetTempThresholds(float* tempHigh, float* tempCritical)
{
  /*TODO: Implement Me!*/
  (void)tempHigh;
  (void)tempCritical;
  return (pmError_t)0;
}

pmError_t PLAT_API_DetemineClockSpeeds(uint32_t* cpu_rate_Normal, uint32_t* cpu_rate_Scaled, uint32_t* cpu_rate_Minimal)
{
  /*TODO: Implement Me!*/
  (void)cpu_rate_Normal;
  (void)cpu_rate_Scaled;
  (void)cpu_rate_Minimal;
  return (pmError_t)0;
}

pmError_t PLAT_API_SetClockSpeed(uint32_t speed)
{
  /*TODO: Implement Me!*/
  (void)speed;
  return (pmError_t)0;
}

pmError_t PLAT_API_GetClockSpeed(uint32_t* speed)
{
  /*TODO: Implement Me!*/
  (void)speed;
  return (pmError_t)0;
}

void PLAT_TERM(void)
{
  /*TODO: Implement Me!*/
}

