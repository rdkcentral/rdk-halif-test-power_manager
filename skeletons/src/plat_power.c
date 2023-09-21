#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "plat_power.h"


pmStatus_t PLAT_INIT(void)
{
  /*TODO: Implement Me!*/
  return (pmStatus_t)0;
}

pmStatus_t PLAT_API_SetPowerState(PWRMgr_PowerState_t newState)
{
  /*TODO: Implement Me!*/
  (void)newState;
  return (pmStatus_t)0;
}

pmStatus_t PLAT_API_GetPowerState(PWRMgr_PowerState_t* curState)
{
  /*TODO: Implement Me!*/
  (void)curState;
  return (pmStatus_t)0;
}

pmStatus_t PLAT_API_SetWakeupSrc(PWRMGR_WakeupSrcType_t srcType, bool enable)
{
  /*TODO: Implement Me!*/
  (void)srcType;
  (void)enable;
  return (pmStatus_t)0;
}

pmStatus_t PLAT_API_GetWakeupSrc(PWRMGR_WakeupSrcType_t srcType, bool* enable)
{
  /*TODO: Implement Me!*/
  (void)srcType;
  (void)enable;
  return (pmStatus_t)0;
}

pmStatus_t PLAT_Reset(PWRMgr_PowerState_t newState)
{
  /*TODO: Implement Me!*/
  (void)newState;
  return (pmStatus_t)0;
}

pmStatus_t PLAT_TERM(void)
{
  /*TODO: Implement Me!*/
  return (pmStatus_t)0;
}

