/******************************************************************************
* FileName		       : BLabel.cpp
* Description          : implementation of the CBLabel class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BLabel.h"
const VTab_CBLabel g_tVTab_CBLabel_CBLabel = {CBLabel_DrawText_IAwsGc1p_CEspRect1p};
const VTab_CAwsWindow g_tVTab_CBLabel_CAwsWindow = {CBLabel_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CBLabel_OnDraw_CEspRect1p, CAwsWindow_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CAwsWindow_OnFocus_i0p, CAwsWindow_OnTimer, CAwsWindow_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CAwsWindow_OnCreate};
void CBLabel_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CBLabel* pThis=(CBLabel*)this;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsString_DUninit_i1p(&(pThis->m_oStrText), 0);
	CAwsWindow_DUninit_i1p(&(pThis->m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBLabel*)0)->m_oBase_CAwsWindow));
}

void CBLabel_SetTextSize_i0p(CBLabel* pThis, int nSize) { pThis->m_nTextSize=nSize; } 

void CBLabel_GetText_CAwsString1p(CBLabel* pThis, CAwsString * str) { *str=pThis->m_oStrText; } 

#include "IAwsGc.h"

void CBLabel_CInit(CBLabel* pThis)
{

CAwsWindow_CInit(&(pThis->m_oBase_CAwsWindow));
CAwsString_CInit_i0p(&(pThis->m_oStrText),100);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
	pThis->m_pVTab = &g_tVTab_CBLabel_CBLabel;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBLabel_CAwsWindow;
{
	CAwsRgb rgbText,rgbBK;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,255,255,255);
pThis->m_oTextColor=rgbText;
	pThis->m_oBKColor=rgbBK;

	pThis->m_nTextSize=12;
	pThis->m_eAlignMode=AWS_TAM_Left;
}
}

void CBLabel_SetText_CAwsString1p_i0p(CBLabel* pThis, const CAwsString * str,int bIsRedraw)
{
	pThis->m_oStrText=*str;

	if(bIsRedraw){
		CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));}
}

void CBLabel_SetTextColor_CAwsRgb1p_i0p(CBLabel* pThis, const CAwsRgb * color,int bIsRedraw)
{
	pThis->m_oTextColor=*color;

	if(bIsRedraw){
		CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));}
}

void CBLabel_SetBKColor_CAwsRgb1p_i0p(CBLabel* pThis, const CAwsRgb * color,int bIsRedraw)
{
	pThis->m_oBKColor=*color;

	if(bIsRedraw){
		CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));}
}

void CBLabel_SetTextAlignment_0p_i0p(CBLabel* pThis, AWS_TextAlignMode mode,int bIsRedraw)
{
	pThis->m_eAlignMode=mode;

	if(bIsRedraw){
		CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));}
}

void CBLabel_DrawText_IAwsGc1p_CEspRect1p(CBLabel* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	pGc->m_pVTab->m_pDrawText_CAwsString1p_CEspRect1p(pGc,&(pThis->m_oStrText),rect);
}

void CBLabel_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CBLabel* pThis = (CBLabel*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsWindow));

	if(!pThis->m_oBase_CAwsWindow.m_bIsBKTransparent){
	{
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
		pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);
	}}

	CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nTextSize,400);
	pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));

	pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oTextColor));
	pGc->m_pVTab->m_pSetTextAlignment_0p(pGc,pThis->m_eAlignMode);
	pGc->m_pVTab->m_pSetTextBKMode_0p(pGc,AWS_TSM_Transparent);

	pThis->m_pVTab->m_pDrawText_IAwsGc1p_CEspRect1p(pThis,pGc,rect);
}
}
