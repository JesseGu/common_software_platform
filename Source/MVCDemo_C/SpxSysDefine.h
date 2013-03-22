/******************************************************************************
* FileName		       : SpxSysDefine.h
* Description          : SPX system define
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _SPXSYSDEFINE_H_2011_03_10_
#define _SPXSYSDEFINE_H_2011_03_10_

#include "EspSysDefine.h"

typedef enum tagESP_SysCommand ESP_SysCommand;
enum tagESP_SysCommand
{
	SPX_SysCmd = 1000,
	SPX_SysCmd_RegisterObserver,
	SPX_SysCmd_UnregisterObserver
};


#endif /* _SPXSYSDEFINE_H_2011_03_10_ */
