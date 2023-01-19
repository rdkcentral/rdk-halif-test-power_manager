#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "MockpwrMgr.h"


static struct MockpwrMgrInstance
{
  unsigned char placeHolder;
} Mock;

extern jmp_buf AbortFrame;

void MockpwrMgr_Verify(void)
{
}

void MockpwrMgr_Init(void)
{
  MockpwrMgr_Destroy();
}

void MockpwrMgr_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

