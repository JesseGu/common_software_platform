/******************************************************************************
* FileName		       : AwsContainer.h
* Description          : interface for the CAwsContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _AWSCONTAINER_H__2009_10_09_
#define _AWSCONTAINER_H__2009_10_09_

#include "AwsWindow.h"

// 所有容器窗口的基类
typedef struct tagCAwsContainer CAwsContainer;

// 类声明
struct tagCAwsContainer
{
	CAwsWindow m_oBase_CAwsWindow;

	CAwsWindow * *  m_pSubWndData;
	int m_nSubWndCount;
	int m_nMaxSubWndCount;
	CAwsWindow * *  m_pFocusWndData;
	int m_nFocusWndCount;
	int m_nFocusWndIndex;
	CAwsWindow *  m_pFocusWnd;
	int m_nPopWndCount;
};

// 成员函数声明
void CAwsContainer_DUninit_i1p(CAwsWindow* this, int * pOffset);
CAwsWindow *  CAwsContainer_GetFocusSubWnd(CAwsWindow* this);
void CAwsContainer_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CAwsContainer_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CAwsContainer_OnSize_CEspSize1p_i0p(CAwsWindow* this, const CEspSize * size, int bIsRedraw);
void CAwsContainer_OnFocus_i0p(CAwsWindow* this, int bIsFocus);
void CAwsContainer_OnTimer(CAwsWindow* this);
void CAwsContainer_OnImeChar_s0p(CAwsWindow* this, short nChar);
void CAwsContainer_OnCreate(CAwsWindow* this);
void CAwsContainer_CInit_i0p(CAwsContainer* pThis, int nMaxSubWndCount);
void CAwsContainer_PopWnd_CAwsWindow1p_CEspRect1p_i0p(CAwsContainer* pThis, CAwsWindow *  pWnd, const CEspRect * rect, int nWndID);
void CAwsContainer_DestroyPopWnd_i0p(CAwsContainer* pThis, int nCount);
CAwsWindow *  CAwsContainer_GetWndFromID_i0p(CAwsContainer* pThis, int nWndID);
void CAwsContainer_SetFocus_CAwsWindow1p(CAwsContainer* pThis, CAwsWindow *  pSubWnd);
void CAwsContainer_DeleteWindow_CAwsWindow1p_i0p(CAwsContainer* pThis, CAwsWindow *  pWnd, int bIsRedraw);
int CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(CAwsContainer* pThis, CAwsWindow *  pWnd, int bIsNeedFocus);
void CAwsContainer_PreFocusWnd(CAwsContainer* pThis);
void CAwsContainer_NextFocusWnd(CAwsContainer* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CAwsContainer_CAwsWindow;


#endif /* _AWSCONTAINER_H__2009_10_09_ */
