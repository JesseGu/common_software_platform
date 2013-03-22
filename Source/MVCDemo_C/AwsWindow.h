/******************************************************************************
* FileName		       : AwsWindow.h
* Description          : interface for the CAwsWindow class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _AWSWINDOW_H__2009_10_09_
#define _AWSWINDOW_H__2009_10_09_

#include "Aws.h"

typedef struct tagCAwsUi CAwsUi;
typedef struct tagCAwsUi_TTimerData CAwsUi_TTimerData;
typedef struct tagCAwsUi_TCommand CAwsUi_TCommand;

typedef struct tagIAwsGc IAwsGc;


// 所有窗口的基类
typedef struct tagCAwsWindow CAwsWindow;

// 虚函数表
typedef void(*PVCAwsWindow_DUninit_i1p)(CAwsWindow* pThis, int * pOffset);
typedef void(*PVCAwsWindow_InvalideRect_CEspRect1p)(CAwsWindow* pThis, const CEspRect * rect);
typedef CAwsWindow * (*PVCAwsWindow_GetFocusSubWnd)(CAwsWindow* pThis);
typedef void(*PVCAwsWindow_OnDraw_CEspRect1p)(CAwsWindow* pThis, const CEspRect * rect);
typedef int(*PVCAwsWindow_OnKey_0p_0p)(CAwsWindow* pThis, AWS_KeyType type, AWS_KeyCode code);
typedef void(*PVCAwsWindow_OnSize_CEspSize1p_i0p)(CAwsWindow* pThis, const CEspSize * size, int bIsRedraw);
typedef void(*PVCAwsWindow_OnFocus_i0p)(CAwsWindow* pThis, int bIsFocus);
typedef void(*PVCAwsWindow_OnTimer)(CAwsWindow* pThis);
typedef void(*PVCAwsWindow_OnImeChar_s0p)(CAwsWindow* pThis, short nChar);
typedef int(*PVCAwsWindow_OnCommand_i0p_i0p_i0p_i0p)(CAwsWindow* pThis, int nWndID, int nCmdID, int nParam1, int nParam2);
typedef void(*PVCAwsWindow_OnCreate)(CAwsWindow* pThis);
typedef struct tagVTab_CAwsWindow VTab_CAwsWindow;
struct tagVTab_CAwsWindow
{
	PVCAwsWindow_DUninit_i1p	m_pDUninit_i1p;
	PVCAwsWindow_InvalideRect_CEspRect1p	m_pInvalideRect_CEspRect1p;
	PVCAwsWindow_GetFocusSubWnd	m_pGetFocusSubWnd;
	PVCAwsWindow_OnDraw_CEspRect1p	m_pOnDraw_CEspRect1p;
	PVCAwsWindow_OnKey_0p_0p	m_pOnKey_0p_0p;
	PVCAwsWindow_OnSize_CEspSize1p_i0p	m_pOnSize_CEspSize1p_i0p;
	PVCAwsWindow_OnFocus_i0p	m_pOnFocus_i0p;
	PVCAwsWindow_OnTimer	m_pOnTimer;
	PVCAwsWindow_OnImeChar_s0p	m_pOnImeChar_s0p;
	PVCAwsWindow_OnCommand_i0p_i0p_i0p_i0p	m_pOnCommand_i0p_i0p_i0p_i0p;
	PVCAwsWindow_OnCreate	m_pOnCreate;
};

// 类声明
struct tagCAwsWindow
{
	CAwsWindow *  m_pParent;
	IAwsGc *  m_pGc;
	CAwsUi *  m_pUi;
	CEspRect m_tRect;
	CEspPoint m_tOrigin;
	int m_nWndID;
	int m_bIsVisible;
	int m_bIsFocus;
	int m_bIsBKTransparent;
	const VTab_CAwsWindow*	m_pVTab;
};

// 成员函数声明
void CAwsWindow_DUninit_i1p(CAwsWindow* pThis, int * pOffset);
void CAwsWindow_InvalideRect_CEspRect1p(CAwsWindow* pThis, const CEspRect * rect);
CAwsWindow *  CAwsWindow_GetFocusSubWnd(CAwsWindow* pThis);
void CAwsWindow_OnDraw_CEspRect1p(CAwsWindow* pThis, const CEspRect * rect);
int CAwsWindow_OnKey_0p_0p(CAwsWindow* pThis, AWS_KeyType type, AWS_KeyCode code);
void CAwsWindow_OnSize_CEspSize1p_i0p(CAwsWindow* pThis, const CEspSize * size, int bIsRedraw);
void CAwsWindow_OnFocus_i0p(CAwsWindow* pThis, int bIsFocus);
void CAwsWindow_OnTimer(CAwsWindow* pThis);
void CAwsWindow_OnImeChar_s0p(CAwsWindow* pThis, short nChar);
int CAwsWindow_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* pThis, int nWndID, int nCmdID, int nParam1, int nParam2);
void CAwsWindow_OnCreate(CAwsWindow* pThis);
void CAwsWindow_CInit(CAwsWindow* pThis);
void CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(CAwsWindow* pThis, CAwsWindow *  pParent, const CEspRect * rect, int nID, int bIsVisible);
const CEspPoint * CAwsWindow_GetOrigin(CAwsWindow* pThis);
void CAwsWindow_SetUi_CAwsUi1p(CAwsWindow* pThis, CAwsUi *  pUi);
CAwsUi *  CAwsWindow_GetUi(CAwsWindow* pThis);
const CEspRect * CAwsWindow_GetRect(CAwsWindow* pThis);
const CEspSize *  CAwsWindow_GetSize(CAwsWindow* pThis);
CAwsWindow *  CAwsWindow_GetParent(CAwsWindow* pThis);
int CAwsWindow_IsVisible(CAwsWindow* pThis);
int CAwsWindow_GetWndID(CAwsWindow* pThis);
void CAwsWindow_MoveTo_CEspRect1p_i0p(CAwsWindow* pThis, const CEspRect * rect, int bIsReDraw);
void CAwsWindow_Invalide(CAwsWindow* pThis);
void CAwsWindow_SetVisible_i0p_i0p(CAwsWindow* pThis, int bIsVisible, int bIsReDraw);
void CAwsWindow_ConvertCoordinate_CEspRect1p(CAwsWindow* pThis, CEspRect * rect);
int CAwsWindow_StartTimer_i0p(CAwsWindow* pThis, int nTimer);
void CAwsWindow_EndTimer(CAwsWindow* pThis);
void CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(CAwsWindow* pThis, int nWndID, int nCmdID, int nParam1, int nParam2);
void CAwsWindow_PostCommand_i0p_i0p_i0p_i0p(CAwsWindow* pThis, int nWndID, int nCmdID, int nParam1, int nParam2);
void CAwsWindow_SetBKTransparent_i0p(CAwsWindow* pThis, int bIsTransparent);
void CAwsWindow_Draw_CEspRect1p(CAwsWindow* pThis, const CEspRect * rect);
IAwsGc *  CAwsWindow_GetGc(CAwsWindow* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CAwsWindow_CAwsWindow;


#endif /* _AWSWINDOW_H__2009_10_09_ */
