/******************************************************************************
* FileName		       : BProgressBar.cpp
* Description          : implementation of the CBProgressBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BProgressBar.h"
const VTab_CBProgressBar g_tVTab_CBProgressBar_CBProgressBar = {CBProgressBar_OnDrawBK_IAwsGc1p_CEspRect1p, CBProgressBar_OnDrawBorder_IAwsGc1p_CEspRect1p, CBProgressBar_OnDrawProgress_IAwsGc1p_CEspRect1p};
const VTab_CAwsWindow g_tVTab_CBProgressBar_CAwsWindow = {CBProgressBar_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CBProgressBar_OnDraw_CEspRect1p, CAwsWindow_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CAwsWindow_OnFocus_i0p, CAwsWindow_OnTimer, CAwsWindow_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CBProgressBar_OnCreate};
void CBProgressBar_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CBProgressBar* pThis=(CBProgressBar*)this;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsWindow_DUninit_i1p(&(pThis->m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBProgressBar*)0)->m_oBase_CAwsWindow));
}

void CBProgressBar_SetBorderColor_CAwsRgb1p(CBProgressBar* pThis, const CAwsRgb * color) { pThis->m_oBorderColor=*color; } 

void CBProgressBar_SetProgressColor_CAwsRgb1p(CBProgressBar* pThis, const CAwsRgb * color) { pThis->m_oProgressColor=*color; } 

void CBProgressBar_SetBKColor_CAwsRgb1p(CBProgressBar* pThis, const CAwsRgb * color) { pThis->m_oBKColor=*color; } 

int CBProgressBar_GetPos(CBProgressBar* pThis) { return pThis->m_nCurPos; } 

void CBProgressBar_SetTotalLenght_i0p(CBProgressBar* pThis, int nLength) { pThis->m_nLength=nLength; } 

#include "IAwsGc.h"

void CBProgressBar_CInit(CBProgressBar* pThis)
{

CAwsWindow_CInit(&(pThis->m_oBase_CAwsWindow));
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oProgressColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
	pThis->m_pVTab = &g_tVTab_CBProgressBar_CBProgressBar;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBProgressBar_CAwsWindow;
{
	pThis->m_nLength=0;
	pThis->m_nCurPos=0;
	pThis->m_nDrawPos=0;

	{CAwsRgb rgbBK,rgbProgress,rgbBorder;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbProgress,0,0,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBorder,30,26,18);
pThis->m_oBKColor=rgbBK;
	pThis->m_oProgressColor=rgbProgress;
	pThis->m_oBorderColor=rgbBorder;

	pThis->m_nBorderPixels=1;
}}
}

void CBProgressBar_OnCreate(CAwsWindow* this)
{

	CBProgressBar* pThis = (CBProgressBar*)this;{
	// 加载图片等资源
}
}

void CBProgressBar_SetPos_i0p(CBProgressBar* pThis, int nPos)
{
	int n=pThis->m_nCurPos;
	pThis->m_nCurPos=nPos;
	if(nPos<n){
	{
		CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));
	}}
	else
	{{
		// 部分更新即可
		CEspRect rect;
		CEspSize size=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow));
		CEspRect_CInit(&(rect));
rect.m_ptLT.m_nY=pThis->m_nBorderPixels;
		rect.m_ptRB.m_nY=size.m_nHeight-pThis->m_nBorderPixels;

		rect.m_ptLT.m_nX=pThis->m_nBorderPixels+(n*(size.m_nWidth-2))/pThis->m_nLength;
		rect.m_ptRB.m_nX=pThis->m_nBorderPixels+(pThis->m_nCurPos*(size.m_nWidth-2))/pThis->m_nLength;

		pThis->m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsWindow),&(rect));
	}}
}

void CBProgressBar_OnDrawBK_IAwsGc1p_CEspRect1p(CBProgressBar* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);
}

void CBProgressBar_OnDrawBorder_IAwsGc1p_CEspRect1p(CBProgressBar* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBorderColor));
	pGc->m_pVTab->m_pDrawRect_CEspRect1p(pGc,rect);
}

void CBProgressBar_OnDrawProgress_IAwsGc1p_CEspRect1p(CBProgressBar* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	if(pThis->m_nCurPos>0){
	{
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oProgressColor));
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oProgressColor));

		pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);
	}}
}

void CBProgressBar_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CBProgressBar* pThis = (CBProgressBar*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsWindow));

	CEspSize size=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow));
	CEspRect rtTemp;
	CEspRect rt;

	// 画边框
	CEspRect_CInit(&(rtTemp));
CEspRect_CInit_i0p_i0p_i0p_i0p(&rt,0,0,size.m_nWidth,size.m_nHeight);
pThis->m_pVTab->m_pOnDrawBorder_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));

	// 画进度
	rt.m_ptLT.m_nY=pThis->m_nBorderPixels;
	rt.m_ptRB.m_nY=size.m_nHeight-pThis->m_nBorderPixels;
	rt.m_ptLT.m_nX=pThis->m_nBorderPixels;
	rt.m_ptRB.m_nX=pThis->m_nBorderPixels+(pThis->m_nCurPos*(size.m_nWidth-2))/pThis->m_nLength;
	if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
	{
		pThis->m_pVTab->m_pOnDrawProgress_IAwsGc1p_CEspRect1p(pThis,pGc,&(rtTemp));
	}}

	// 画背景
	rt.m_ptLT.m_nX=pThis->m_nBorderPixels+(pThis->m_nCurPos*(size.m_nWidth-2))/pThis->m_nLength;
	rt.m_ptRB.m_nX=pThis->m_nBorderPixels+(size.m_nWidth-2);
	if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
	{
		pThis->m_pVTab->m_pOnDrawBK_IAwsGc1p_CEspRect1p(pThis,pGc,&(rtTemp));
	}}
	/*
	if ( 0 == rect.m_ptLT.m_nX )
	{
		// 画背景
		OnDrawBK(pGc, rect);

		// 画边框
		OnDrawBorder(pGc, rect);
		// 画进度
		CAwsRect rt;
		rt.m_ptLT.m_nX = m_nBorderPixels;
		rt.m_ptLT.m_nY = m_nBorderPixels;
		rt.m_ptRB.m_nX = (m_nCurPos * rect.m_ptRB.m_nX) / m_nLength;
		rt.m_ptRB.m_nY = rect.m_ptRB.m_nY - m_nBorderPixels;
		OnDrawProgress(pGc, rt);
	}
	else
	{
		OnDrawProgress(pGc, rect);
	}
	*/
}
}
