/******************************************************************************
* FileName		       : BScrollBar.cpp
* Description          : implementation of the CBScrollBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BScrollBar.h"
#include "IAwsGc.h"

void CBScrollBar_CInit(CBScrollBar* pThis)
{

CAwsWindow_CInit(&(pThis->m_oBase_CAwsWindow));
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBlockColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
	pThis->m_pVTab = &g_tVTab_CBScrollBar_CBScrollBar;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBScrollBar_CAwsWindow;
{
	pThis->m_eDir=ESB_Vertical;
	pThis->m_nTotalLength=0;
	pThis->m_nCurPos=0;

	pThis->m_nMinBlockDim=10;
	pThis->m_nMaxScrolldis=20;

	{CAwsRgb rgbBlock,rgbBK;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbBlock,0,255,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,117,125,138);
pThis->m_oBlockColor=rgbBlock;
	pThis->m_oBKColor=rgbBK;
}}
}

void CBScrollBar_SetTotalLength_i0p(CBScrollBar* pThis, int nTotal)
{
	pThis->m_nTotalLength=nTotal;

	{CEspSize size=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow));

	int nWndDim;
	if(ESB_Vertical==pThis->m_eDir){
	{
		nWndDim=size.m_nHeight;
	}}
	else if(ESB_Horizontal==pThis->m_eDir){
	{
		nWndDim=size.m_nWidth;
	}}

	if(nWndDim-(pThis->m_nTotalLength-1)*pThis->m_nMaxScrolldis<pThis->m_nMinBlockDim){
	{
		pThis->m_nCurBlockDim=pThis->m_nMinBlockDim;
		pThis->m_fCurScrolldis=(float)(nWndDim-pThis->m_nMinBlockDim)/(pThis->m_nTotalLength-1);
	}}
	else
	{{
		pThis->m_fCurScrolldis=(float)pThis->m_nMaxScrolldis;
		pThis->m_nCurBlockDim=nWndDim-(pThis->m_nTotalLength-1)*pThis->m_nMaxScrolldis;
	}}
}}

void CBScrollBar_SetCurPos_i0p(CBScrollBar* pThis, int nCur)
{
	if(nCur<pThis->m_nTotalLength){
	{
		pThis->m_nCurPos=nCur;
		CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));
	}}
}

void CBScrollBar_DrawBK_IAwsGc1p_CEspRect1p(CBScrollBar* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);
}

void CBScrollBar_DrawBlock_IAwsGc1p_CEspRect1p(CBScrollBar* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBlockColor));
	pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBlockColor));
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);
}

void CBScrollBar_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CBScrollBar* pThis = (CBScrollBar*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsWindow));

	if(ESP_NULL!=pGc){
	{
		// »­±³¾°
		pThis->m_pVTab->m_pDrawBK_IAwsGc1p_CEspRect1p(pThis,pGc,rect);

		// »­¿é
		{CEspRect rt;
		CEspRect_CInit(&(rt));
if(ESB_Vertical==pThis->m_eDir){
		{
			rt.m_ptLT.m_nX=0;
			rt.m_ptLT.m_nY=(int)(pThis->m_nCurPos*pThis->m_fCurScrolldis);
			rt.m_ptRB.m_nX=CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow))->m_nWidth;
			rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nCurBlockDim;
		}}
		else if(ESB_Horizontal==pThis->m_eDir){
		{
			rt.m_ptLT.m_nX=(int)(pThis->m_nCurPos*pThis->m_fCurScrolldis);
			rt.m_ptLT.m_nY=0;
			rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nCurBlockDim;
			rt.m_ptRB.m_nY=CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow))->m_nHeight;
		}}

		pThis->m_pVTab->m_pDrawBlock_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));
	}}}
}
}
