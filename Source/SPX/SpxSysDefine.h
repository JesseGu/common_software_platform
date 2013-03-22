/******************************************************************************
* FileName		       : SpxSysDefine.h
* Description          : SPX system define
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _SPXSYSDEFINE_H_2011_03_10_
#define _SPXSYSDEFINE_H_2011_03_10_

#include "EspSysDefine.h"

enum ESP_SysCommand
{
	SPX_SysCmd = 1000,

	// ע��۲��ߣ�nParam1��ʾIEspObserverָ��
	SPX_SysCmd_RegisterObserver,
	SPX_SysCmd_UnregisterObserver,
};

#endif /* _SPXSYSDEFINE_H_2011_03_10_ */
