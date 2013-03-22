/******************************************************************************
* FileName		       : BButton.cpp
* Description          : implementation of the CBButton class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BButton.h"
const VTab_CBButton g_tVTab_CBButton_CBButton = {CBButton_DrawBK_IAwsGc1p_CEspRect1p, CBButton_DrawInf_IAwsGc1p_CEspRect1p, CBButton_DrawText_IAwsGc1p_CEspRect1p, CBButton_OnClick};
const VTab_CAwsWindow g_tVTab_CBButton_CAwsWindow = {CBButton_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CBButton_OnDraw_CEspRect1p, CBButton_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CBButton_OnFocus_i0p, CAwsWindow_OnTimer, CAwsWindow_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CAwsWindow_OnCreate};
void CBButton_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CBButton* pThis=(CBButton*)this;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsString_DUninit_i1p(&(pThis->m_oText), 0);
	CAwsWindow_DUninit_i1p(&(pThis->m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBButton*)0)->m_oBase_CAwsWindow));
}

void CBButton_SetBorderColor_CAwsRgb1p(CBButton* pThis, const CAwsRgb * colorBorder) { pThis->m_oBorderColor=*colorBorder; } 

void CBButton_SetBKColor_CAwsRgb1p(CBButton* pThis, const CAwsRgb * colorBK) { pThis->m_oBKColor=*colorBK; } 

void CBButton_SetTextFocusColor_CAwsRgb1p(CBButton* pThis, const CAwsRgb * colorText) { pThis->m_oTextFocusColor=*colorText; } 

void CBButton_SetTextColor_CAwsRgb1p(CBButton* pThis, const CAwsRgb * colorText) { pThis->m_oTextColor=*colorText; } 

void CBButton_SetTextAlignment_0p(CBButton* pThis, AWS_TextAlignMode mode) { pThis->m_eTextAlignMode=mode; } 

#include "IAwsGc.h"

void CBButton_CInit(CBButton* pThis)
{

CAwsWindow_CInit(&(pThis->m_oBase_CAwsWindow));
CAwsString_CInit_i0p(&(pThis->m_oText),100);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextFocusColor),0,0,0);
	pThis->m_pVTab = &g_tVTab_CBButton_CBButton;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBButton_CAwsWindow;
{
	pThis->m_nFontSize=12;

	pThis->m_eTextAlignMode=AWS_TAM_Mid;

	{CAwsRgb rgbBorder,rgbBK,rgbText,rgbFocus;

	CAwsRgb_CInit_i0p_i0p_i0p(&rgbBorder,0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,236,233,216);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbFocus,255,0,0);
pThis->m_oBorderColor=rgbBorder;
	pThis->m_oBKColor=rgbBK;
	pThis->m_oTextColor=rgbText;
	pThis->m_oTextFocusColor=rgbFocus;
}}
}

void CBButton_SetText_CAwsString1p(CBButton* pThis, const CAwsString * strText)
{
	pThis->m_oText=*strText;
	CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));
}

void CBButton_DrawBK_IAwsGc1p_CEspRect1p(CBButton* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBorderColor));
	pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);
}

void CBButton_DrawText_IAwsGc1p_CEspRect1p(CBButton* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
	pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));

	{CEspRect rt=*(rect);
	const CEspSize *  size=pGc->m_pVTab->m_pGetTextSize_CAwsString1p(pGc,&(pThis->m_oText));
	rt.m_ptLT.m_nY+=(CEspRect_GetSize(&(rt))->m_nHeight-size->m_nHeight)/2;

	pGc->m_pVTab->m_pSetTextAlignment_0p(pGc,pThis->m_eTextAlignMode);

	if(pThis->m_oBase_CAwsWindow.m_bIsFocus){
	{
		pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oTextFocusColor));
	}}
	else
	{{
		pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oTextColor));
	}}

	pGc->m_pVTab->m_pDrawText_CAwsString1p_CEspRect1p(pGc,&(pThis->m_oText),&(rt));
}}

void CBButton_DrawInf_IAwsGc1p_CEspRect1p(CBButton* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	pThis->m_pVTab->m_pDrawText_IAwsGc1p_CEspRect1p(pThis,pGc,rect);
}

void CBButton_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CBButton* pThis = (CBButton*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsWindow));

	CEspSize size=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow));
	CEspRect rt;

	CEspRect_CInit_i0p_i0p_i0p_i0p(&rt,0,0,size.m_nWidth,size.m_nHeight);
if(ESP_NULL!=pGc){
	{
		// »­±³¾°
		if(!pThis->m_oBase_CAwsWindow.m_bIsBKTransparent){
			pThis->m_pVTab->m_pDrawBK_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));}

		// ÏÔÊ¾ÐÅÏ¢
		pThis->m_pVTab->m_pDrawInf_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));
	}}
}
}

void CBButton_OnClick(CBButton* pThis)
{
	CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsWindow),pThis->m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_ButtonCmd,0,0);
}

int CBButton_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CBButton* pThis = (CBButton*)this;{
	if(AWS_Key==type){
	{
		switch(code)
		{
		case AWS_KeyCode_OK:
			pThis->m_pVTab->m_pOnClick(pThis);
			return 1;
		}
	}}

	return CAwsWindow_OnKey_0p_0p(&(pThis->m_oBase_CAwsWindow),type,code);
}
}

void CBButton_OnFocus_i0p(CAwsWindow* this, int bIsFocus)
{

	CBButton* pThis = (CBButton*)this;{
	CAwsWindow_OnFocus_i0p(&(pThis->m_oBase_CAwsWindow),bIsFocus);

	CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));
}
}
