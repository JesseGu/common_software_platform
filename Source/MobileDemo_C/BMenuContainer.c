/******************************************************************************
* FileName		       : BMenuContainer.cpp
* Description          : implementation of the CBMenuContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-09

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BMenuContainer.h"
const VTab_CBMenuContainer g_tVTab_CBMenuContainer_CBMenuContainer = {CBMenuContainer_PopMenu_i0p_CEspPoint1p};
const VTab_CAwsWindow g_tVTab_CBMenuContainer_CAwsWindow = {CBMenuContainer_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CAwsContainer_OnDraw_CEspRect1p, CAwsContainer_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CBMenuContainer_OnCommand_i0p_i0p_i0p_i0p, CAwsContainer_OnCreate};
void CBMenuContainer_CInit(CBMenuContainer* pThis)
{
CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
	pThis->m_pVTab = &g_tVTab_CBMenuContainer_CBMenuContainer;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBMenuContainer_CAwsWindow;
}

void CBMenuContainer_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CBMenuContainer* pThis=(CBMenuContainer*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBMenuContainer*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CBMenuContainer_PopMenu_i0p_CEspPoint1p(CBMenuContainer* pThis, int nMenuID,const CEspPoint * pt) { } 


void CBMenuContainer_CInit_i0p(CBMenuContainer* pThis, int nMaxSubWndCount) {

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),nMaxSubWndCount);
	pThis->m_pVTab = &g_tVTab_CBMenuContainer_CBMenuContainer;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBMenuContainer_CAwsWindow;
{
}
}

int CBMenuContainer_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CBMenuContainer* pThis = (CBMenuContainer*)this;{
	int bRet=1;

	switch(nCmdID)
	{
	case AWS_SysCmd_PopMenu:
		pThis->m_pVTab->m_pPopMenu_i0p_CEspPoint1p(pThis,nParam1,&(*((CEspPoint*)nParam2)));
		break;

	default:
		bRet=0;
	}
	
	return bRet;
}
}
