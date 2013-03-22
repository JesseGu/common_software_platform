/******************************************************************************
* FileName		       : MScrollLabel.cpp
* Description          : implementation of the CMScrollLabel class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "MScrollLabel.h"
const VTab_CAwsWindow g_tVTab_CMScrollLabel_CAwsWindow = {CMScrollLabel_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CBLabel_OnDraw_CEspRect1p, CAwsWindow_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CAwsWindow_OnFocus_i0p, CMScrollLabel_OnTimer, CAwsWindow_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CMScrollLabel_OnCreate};
const VTab_CBLabel g_tVTab_CMScrollLabel_CBLabel = {CMScrollLabel_DrawText_IAwsGc1p_CEspRect1p};
void CMScrollLabel_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CMScrollLabel* pThis=(CMScrollLabel*)this;
	pThis->m_oBase_CBLabel.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	pThis->m_oBase_CBLabel.m_pVTab = &g_tVTab_CBLabel_CBLabel;
	CBLabel_DUninit_i1p(&(pThis->m_oBase_CBLabel.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMScrollLabel*)0)->m_oBase_CBLabel.m_oBase_CAwsWindow));
}

int CMScrollLabel_IsStartScroll(CMScrollLabel* pThis) { return pThis->m_nScrollCount>0?1:0; } 

void CMScrollLabel_SetTimers_i0p(CMScrollLabel* pThis, int nTimers) { pThis->m_nTimes=nTimers; } 

#include "IAwsGc.h"

void CMScrollLabel_CInit(CMScrollLabel* pThis)
{

CBLabel_CInit(&(pThis->m_oBase_CBLabel));
CEspSize_CInit_i0p_i0p(&(pThis->m_oSizeWnd),0,0);
	pThis->m_oBase_CBLabel.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CMScrollLabel_CAwsWindow;
	pThis->m_oBase_CBLabel.m_pVTab = &g_tVTab_CMScrollLabel_CBLabel;
{
	pThis->m_nScrollCount=0;
	pThis->m_nCurCount=0;
	pThis->m_nMoveLength=0;

	pThis->m_nMoveStep=5;
	pThis->m_nTextLen=-1;
	pThis->m_nTimes=150;
}
}

void CMScrollLabel_OnCreate(CAwsWindow* this)
{

	CMScrollLabel* pThis = (CMScrollLabel*)this;{
	CAwsWindow_OnCreate(&(pThis->m_oBase_CBLabel.m_oBase_CAwsWindow));

	pThis->m_oSizeWnd=*CAwsWindow_GetSize(&(pThis->m_oBase_CBLabel.m_oBase_CAwsWindow));
}
}

void CMScrollLabel_StartScroll_i0p(CMScrollLabel* pThis, int nCount)
{
	pThis->m_nScrollCount=nCount;
	pThis->m_nCurCount=0;
	CAwsWindow_StartTimer_i0p(&(pThis->m_oBase_CBLabel.m_oBase_CAwsWindow),pThis->m_nTimes);
}

void CMScrollLabel_EndScroll(CMScrollLabel* pThis)
{
	if(pThis->m_nScrollCount>0){
	{
		pThis->m_nScrollCount=0;
		pThis->m_nMoveLength=0;
		pThis->m_nCurCount=0;
		CAwsWindow_Invalide(&(pThis->m_oBase_CBLabel.m_oBase_CAwsWindow));
		CAwsWindow_EndTimer(&(pThis->m_oBase_CBLabel.m_oBase_CAwsWindow));

		CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CBLabel.m_oBase_CAwsWindow),pThis->m_oBase_CBLabel.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_ScrollLabelEndScroll,0,0);
	}}
}

void CMScrollLabel_DrawText_IAwsGc1p_CEspRect1p(CBLabel* this, IAwsGc *  pGc,const CEspRect * rect)
{

	CMScrollLabel* pThis = (CMScrollLabel*)this;{
	CEspRect rt=*(rect);
	rt.m_ptLT.m_nX+=pThis->m_nMoveLength;

	if(-1==pThis->m_nTextLen){
	{
		pThis->m_nTextLen=pGc->m_pVTab->m_pGetTextSize_CAwsString1p(pGc,&(pThis->m_oBase_CBLabel.m_oStrText))->m_nWidth;
	}}

	pGc->m_pVTab->m_pDrawText_CAwsString1p_CEspRect1p(pGc,&(pThis->m_oBase_CBLabel.m_oStrText),&(rt));
}
}

void CMScrollLabel_OnTimer(CAwsWindow* this)
{

	CMScrollLabel* pThis = (CMScrollLabel*)this;{
	if(pThis->m_nCurCount<pThis->m_nScrollCount){
	{
		// 
		if(pThis->m_nMoveLength+pThis->m_nTextLen>0){
		{
			// 继续移动
			pThis->m_nMoveLength-=pThis->m_nMoveStep;
			CAwsWindow_Invalide(&(pThis->m_oBase_CBLabel.m_oBase_CAwsWindow));
		}}
		else
		{{
			// 一次移动完毕
			++pThis->m_nCurCount;
			pThis->m_nMoveLength=pThis->m_nMoveStep;
		}}
	}}
	else
	{{
		// 自动结束滚动
		CMScrollLabel_EndScroll(pThis);
	}}
}
}
