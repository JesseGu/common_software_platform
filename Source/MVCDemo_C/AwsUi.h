/******************************************************************************
* FileName		       : AwsUi.h
* Description          : interface for the CAwsUi class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _AWSUI_H__2009_10_09_
#define _AWSUI_H__2009_10_09_

#include "Aws.h"

typedef struct tagIAwsGc IAwsGc;

typedef struct tagCAwsWindow CAwsWindow;

typedef struct tagCAwsContainer CAwsContainer;

typedef struct tagCSpxApp CSpxApp;


enum 
{
	MAX_TIMERDATA = 5,
	MAX_POSTCOMMAND = 10
};


typedef struct tagCAwsUi CAwsUi;
typedef struct tagCAwsUi_TTimerData CAwsUi_TTimerData;
typedef struct tagCAwsUi_TCommand CAwsUi_TCommand;

// 类声明
struct tagCAwsUi_TTimerData
{
	CAwsWindow *  m_pWnd;
	int m_nTime;
};


// 类声明
struct tagCAwsUi_TCommand
{
	int m_nWndID;
	int m_nCmdID;
	int m_nParam1;
	int m_nParam2;
};


// 虚函数表
typedef void(*PVCAwsUi_DUninit_i1p)(CAwsUi* pThis, int * pOffset);
typedef void(*PVCAwsUi_ActiveIME)(CAwsUi* pThis);
typedef void(*PVCAwsUi_InactiveIME)(CAwsUi* pThis);
typedef void(*PVCAwsUi_ExitSys)(CAwsUi* pThis);
typedef void(*PVCAwsUi_Timer_i0p_i0p)(CAwsUi* pThis, int nTimerID, int nTime);
typedef void(*PVCAwsUi_KillTimer_i0p)(CAwsUi* pThis, int nTimerID);
typedef struct tagVTab_CAwsUi VTab_CAwsUi;
struct tagVTab_CAwsUi
{
	PVCAwsUi_DUninit_i1p	m_pDUninit_i1p;
	PVCAwsUi_ActiveIME	m_pActiveIME;
	PVCAwsUi_InactiveIME	m_pInactiveIME;
	PVCAwsUi_ExitSys	m_pExitSys;
	PVCAwsUi_Timer_i0p_i0p	m_pTimer_i0p_i0p;
	PVCAwsUi_KillTimer_i0p	m_pKillTimer_i0p;
};

// 类声明
struct tagCAwsUi
{
	CAwsWindow *  m_pCurTopWnd;
	CAwsWindow * *  m_pTopWndData;
	int m_nCurTopWndCount;
	int m_nMaxTopWndCount;
	CEspSize m_tScreenSize;
	IAwsGc *  m_pSysGc;
	CAwsUi_TTimerData m_tTimerData[MAX_TIMERDATA];
	CAwsUi_TCommand m_tPostCommands[MAX_POSTCOMMAND];
	int m_nCommandCount;
	CSpxApp *  m_pApp;
	const VTab_CAwsUi*	m_pVTab;
};

// 成员函数声明
void CAwsUi_DUninit_i1p(CAwsUi* pThis, int * pOffset);
void CAwsUi_ActiveIME(CAwsUi* pThis);
void CAwsUi_InactiveIME(CAwsUi* pThis);
void CAwsUi_ExitSys(CAwsUi* pThis);
void CAwsUi_Timer_i0p_i0p(CAwsUi* pThis, int nTimerID, int nTime);
void CAwsUi_KillTimer_i0p(CAwsUi* pThis, int nTimerID);
void CAwsUi_CInit_i0p(CAwsUi* pThis, int nMaxTopWndCount);
void CAwsUi_Init_CEspSize1p(CAwsUi* pThis, const CEspSize * sizeScreen);
void CAwsUi_SetApp_CSpxApp1p(CAwsUi* pThis, CSpxApp *  pApp);
void CAwsUi_OnDraw_CEspRect1p(CAwsUi* pThis, const CEspRect * rect);
void CAwsUi_OnKey_0p_0p(CAwsUi* pThis, AWS_KeyType type, AWS_KeyCode code);
void CAwsUi_OnSize_CEspSize1p_i0p(CAwsUi* pThis, const CEspSize * size, int bIsRedraw);
void CAwsUi_OnFocus_i0p(CAwsUi* pThis, int bIsFocus);
void CAwsUi_OnTimer_i0p(CAwsUi* pThis, int nTimerID);
void CAwsUi_OnImeChar_s0p(CAwsUi* pThis, short nChar);
CSpxApp *  CAwsUi_GetApp(CAwsUi* pThis);
CEspSize * CAwsUi_GetScreenSize(CAwsUi* pThis);
void CAwsUi_SetSysGc_IAwsGc1p(CAwsUi* pThis, IAwsGc *  pGc);
IAwsGc *  CAwsUi_GetSysGc(CAwsUi* pThis);
CAwsWindow *  CAwsUi_GetCurTopWnd(CAwsUi* pThis);
int CAwsUi_StartTimer_CAwsWindow1p_i0p(CAwsUi* pThis, CAwsWindow *  pWnd, int nTimes);
void CAwsUi_EndTimer_CAwsWindow1p(CAwsUi* pThis, CAwsWindow *  pWnd);
void CAwsUi_CommandRouter_i0p_i0p_i0p_i0p(CAwsUi* pThis, int nWndID, int nCmdID, int nParam1, int nParam2);
int CAwsUi_AddPostCommand_i0p_i0p_i0p_i0p(CAwsUi* pThis, int nWndID, int nCmdID, int nParam1, int nParam2);
int CAwsUi_AddWndToStack_CAwsWindow1p(CAwsUi* pThis, CAwsWindow *  pWnd);
void CAwsUi_RemoveWndFromStack_CAwsWindow1p(CAwsUi* pThis, CAwsWindow *  pWnd);
void CAwsUi_RemoveWndFromTopStack(CAwsUi* pThis);
void CAwsUi_SetTopWnd_CAwsContainer1p(CAwsUi* pThis, CAwsContainer *  pWnd);
void CAwsUi_PostCommandRouter(CAwsUi* pThis);
void CAwsUi_ClearWnd_CAwsWindow1p(CAwsUi* pThis, CAwsWindow *  pWnd);

// 虚函数表的声明
extern const VTab_CAwsUi g_tVTab_CAwsUi_CAwsUi;


#endif /* _AWSUI_H__2009_10_09_ */
