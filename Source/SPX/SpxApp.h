/******************************************************************************
* FileName		       : SpxApp.h
* Description          : interface for the CSpxApp class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _ESPAPP_H_2011_03_10_
#define _ESPAPP_H_2011_03_10_

#include "SpxSysDefine.h"
#include "AWS.h"
#include "AwsUi.h"

class COs;
class CSpxController;

// 管理所有的Controller，在其派生类中创建所有Controller
class CSpxApp
{
public:
	CSpxApp(int nMaxControllerCount = 1);
	virtual ~CSpxApp();

	// 应用程序的初始化
	void Init(CAwsUi* pUi, COs* pOs);

	CAwsUi* GetUi(CAwsUi* pUi) { return m_pUi; }
	COs* GetOs(COs* pOs) { return m_pOs; }

	bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);

protected:
	// 初始化通知，在子类中实现
	virtual void OnInit(const CEspSize& sizeScreen) {}

	bool AddController(CSpxController* pController);
	void RemoveController(CSpxController* pController);

protected:
	CSpxController**	m_ppController;
	int					m_nMaxControllerCount;
	int					m_nControllerCount;

	CAwsUi*				m_pUi;
	COs*				m_pOs;
};

#endif /* _ESPAPP_H_2011_03_10_ */
