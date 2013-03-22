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

// ����������ÿ�����ฺ����Ӧ����Ϣ�߼���ע��һ�ֿ�����ֻ������涨��һЩ��Ϣ
class CSpxController
{
public:
	CSpxController();
	virtual ~CSpxController();

	// �ڴ˹��ˣ����������Լ�����Ȥ����Ϣ��ע����ESP_SysCmd_RegisterObserver�ж���Ϣ
	// �����������������Ҫ���͹��������뽫���ݴ������ָ�����ʽͨ����������
	bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);

protected:
	// ��������ʵ�ָú�����������ģ�͵�IDȷ��
	virtual bool OnRegisterObserver(ISpxObserver* pObserver) { return false; }
	virtual bool OnUnregisterObserver(ISpxObserver* pObserver) { return false; }

	virtual bool OnMessage(int nWndID, int nCmdID, int nParam1, int nParam2) { return false; }

protected:
	CSpxModel*	m_pModel;
};

#endif /* _ESPCONTROLLER_H_2011_03_10_ */
