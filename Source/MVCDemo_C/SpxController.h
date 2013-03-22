/******************************************************************************
* FileName		       : SpxController.h
* Description          : interface for the CSpxController class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _ESPCONTROLLER_H_2011_03_10_
#define _ESPCONTROLLER_H_2011_03_10_

#include "SpxSysDefine.h"

typedef struct tagISpxObserver ISpxObserver;

typedef struct tagCSpxModel CSpxModel;


// ����������ÿ�����ฺ����Ӧ����Ϣ�߼���ע��һ�ֿ�����ֻ������涨��һЩ��Ϣ
typedef struct tagCSpxController CSpxController;

// �麯����
typedef void(*PVCSpxController_DUninit_i1p)(CSpxController* pThis, int * pOffset);
typedef int(*PVCSpxController_OnRegisterObserver_ISpxObserver1p)(CSpxController* pThis, ISpxObserver *  pObserver);
typedef int(*PVCSpxController_OnUnregisterObserver_ISpxObserver1p)(CSpxController* pThis, ISpxObserver *  pObserver);
typedef int(*PVCSpxController_OnMessage_i0p_i0p_i0p_i0p)(CSpxController* pThis, int nWndID, int nCmdID, int nParam1, int nParam2);
typedef struct tagVTab_CSpxController VTab_CSpxController;
struct tagVTab_CSpxController
{
	PVCSpxController_DUninit_i1p	m_pDUninit_i1p;
	PVCSpxController_OnRegisterObserver_ISpxObserver1p	m_pOnRegisterObserver_ISpxObserver1p;
	PVCSpxController_OnUnregisterObserver_ISpxObserver1p	m_pOnUnregisterObserver_ISpxObserver1p;
	PVCSpxController_OnMessage_i0p_i0p_i0p_i0p	m_pOnMessage_i0p_i0p_i0p_i0p;
};

// ������
struct tagCSpxController
{
	CSpxModel *  m_pModel;
	const VTab_CSpxController*	m_pVTab;
};

// ��Ա��������
void CSpxController_DUninit_i1p(CSpxController* pThis, int * pOffset);
int CSpxController_OnRegisterObserver_ISpxObserver1p(CSpxController* pThis, ISpxObserver *  pObserver);
int CSpxController_OnUnregisterObserver_ISpxObserver1p(CSpxController* pThis, ISpxObserver *  pObserver);
int CSpxController_OnMessage_i0p_i0p_i0p_i0p(CSpxController* pThis, int nWndID, int nCmdID, int nParam1, int nParam2);
void CSpxController_CInit(CSpxController* pThis);
int CSpxController_OnCommand_i0p_i0p_i0p_i0p(CSpxController* pThis, int nWndID, int nCmdID, int nParam1, int nParam2);

// �麯���������
extern const VTab_CSpxController g_tVTab_CSpxController_CSpxController;


#endif /* _ESPCONTROLLER_H_2011_03_10_ */
