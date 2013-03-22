/******************************************************************************
* FileName		       : SpxController.h
* Description          : interface for the CSpxController class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _ESPCONTROLLER_H_2011_03_10_
#define _ESPCONTROLLER_H_2011_03_10_

#include "SpxSysDefine.h"

class ISpxObserver;
class CSpxModel;

// 控制器，其每个子类负责相应的消息逻辑，注意一种控制器只负责处理规定的一些消息
class CSpxController
{
public:
	CSpxController();
	virtual ~CSpxController();

	// 在此过滤，仅仅处理自己感兴趣的消息，注意在ESP_SysCmd_RegisterObserver中对消息
	// 如果界面中有数据需要传送过来，则请将数据打包，以指针的形式通过参数传递
	bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);

protected:
	// 在子类中实现该函数，并根据模型的ID确定
	virtual bool OnRegisterObserver(ISpxObserver* pObserver) { return false; }
	virtual bool OnUnregisterObserver(ISpxObserver* pObserver) { return false; }

	virtual bool OnMessage(int nWndID, int nCmdID, int nParam1, int nParam2) { return false; }

protected:
	CSpxModel*	m_pModel;
};

#endif /* _ESPCONTROLLER_H_2011_03_10_ */
