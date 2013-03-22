/******************************************************************************
* FileName		       : BTreeView.cpp
* Description          : implementation of the CBTreeView class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BTreeView.h"

const VTab_CAwsWindow g_tVTab_CBTreeView_CAwsWindow = {CBTreeView_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CAwsContainer_OnDraw_CEspRect1p, CAwsContainer_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CAwsContainer_OnCreate};
void CBTreeView_CInit(CBTreeView* pThis)
{

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBTreeView_CAwsWindow;
{
}
}

void CBTreeView_DUninit_i1p(CAwsWindow* this, int * pOffset)
{

	CBTreeView* pThis = (CBTreeView*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBTreeView*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
{
}
}
