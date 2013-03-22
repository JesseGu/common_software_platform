/******************************************************************************
* FileName		       : BTitleBar.cpp
* Description          : implementation of the CBTitleBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

//#include <afx.h>

#include "BTitleBar.h"
const VTab_CBTitleBar g_tVTab_CBTitleBar_CBTitleBar = {CBTitleBar_DrawBackground_IAwsGc1p_CEspRect1p, CBTitleBar_DrawIcon_IAwsGc1p_CEspRect1p_CEspSize1p, CBTitleBar_DrawText_IAwsGc1p_CEspRect1p};
const VTab_CAwsWindow g_tVTab_CBTitleBar_CAwsWindow = {CBTitleBar_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CBTitleBar_OnDraw_CEspRect1p, CAwsWindow_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CAwsWindow_OnFocus_i0p, CAwsWindow_OnTimer, CAwsWindow_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CBTitleBar_OnCreate};
void CBTitleBar_CInit(CBTitleBar* pThis)
{
CAwsWindow_CInit(&(pThis->m_oBase_CAwsWindow));
CAwsImage_CInit(&(pThis->m_oIconImage));
CAwsImage_CInit(&(pThis->m_oIconMask));
CEspSize_CInit_i0p_i0p(&(pThis->m_oIconSize),0,0);
CAwsString_CInit_i0p(&(pThis->m_oStrCaption),100);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsImage_CInit(&(pThis->m_oBKImage));
CEspSize_CInit_i0p_i0p(&(pThis->m_oBKImageSize),0,0);
	pThis->m_pVTab = &g_tVTab_CBTitleBar_CBTitleBar;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBTitleBar_CAwsWindow;
}

void CBTitleBar_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CBTitleBar* pThis=(CBTitleBar*)this;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsString_DUninit_i1p(&(pThis->m_oStrCaption), 0);
	CAwsWindow_DUninit_i1p(&(pThis->m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBTitleBar*)0)->m_oBase_CAwsWindow));
}

void CBTitleBar_SetTitleBarHeight_i0p(CBTitleBar* pThis, int nHeight) { pThis->m_nTitleBarHeight=nHeight; } 

void CBTitleBar_SetTextFontSize_i0p(CBTitleBar* pThis, int nSize) { pThis->m_nFontSize=nSize; } 

void CBTitleBar_SetBKColor_CAwsRgb1p(CBTitleBar* pThis, const CAwsRgb * color) { pThis->m_oBKColor=*color; } 

void CBTitleBar_SetTextColor_CAwsRgb1p(CBTitleBar* pThis, const CAwsRgb * color) { pThis->m_oTextColor=*color; } 

#include "IAwsGc.h"
#include "AwsUi.h"

void CBTitleBar_CInit_i0p(CBTitleBar* pThis, int nTitleBarHeight)
{

CAwsWindow_CInit(&(pThis->m_oBase_CAwsWindow));
CAwsImage_CInit(&(pThis->m_oIconImage));
CAwsImage_CInit(&(pThis->m_oIconMask));
CEspSize_CInit_i0p_i0p(&(pThis->m_oIconSize),0,0);
CAwsString_CInit_i0p(&(pThis->m_oStrCaption),100);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsImage_CInit(&(pThis->m_oBKImage));
CEspSize_CInit_i0p_i0p(&(pThis->m_oBKImageSize),0,0);
	pThis->m_pVTab = &g_tVTab_CBTitleBar_CBTitleBar;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBTitleBar_CAwsWindow;
{
	pThis->m_nTitleBarHeight=nTitleBarHeight;

	pThis->m_nFontSize=12;

	{CAwsRgb rgbText,rgbBK;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,0,233,216);
pThis->m_oTextColor=rgbText;
	pThis->m_oBKColor=rgbBK;

	pThis->m_bIsSetBKImage=0;

	pThis->m_nLeftMargin=3;
}}
}

void CBTitleBar_OnCreate(CAwsWindow* this)
{

	CBTitleBar* pThis = (CBTitleBar*)this;{
	// 重新设置菜单条的大小
	CEspSize size=*(CAwsUi_GetScreenSize(CAwsWindow_GetUi(&(pThis->m_oBase_CAwsWindow))));
	pThis->m_oBase_CAwsWindow.m_tRect.m_ptLT.m_nX=0;
	pThis->m_oBase_CAwsWindow.m_tRect.m_ptLT.m_nY=0;
	pThis->m_oBase_CAwsWindow.m_tRect.m_ptRB.m_nX=size.m_nWidth;
	pThis->m_oBase_CAwsWindow.m_tRect.m_ptRB.m_nY=pThis->m_nTitleBarHeight;
	pThis->m_oBase_CAwsWindow.m_tOrigin=pThis->m_oBase_CAwsWindow.m_tRect.m_ptLT;
}
}

void CBTitleBar_SetIcon_CAwsImage1p_CEspSize1p_CAwsImage1p(CBTitleBar* pThis, const CAwsImage * icon,const CEspSize * size,const CAwsImage *  pIconMask)
{
	pThis->m_oIconImage=*icon;
	pThis->m_oIconSize=*size;
	if(ESP_NULL!=pIconMask){
	{
		pThis->m_oIconMask=*pIconMask;
	}}
}

void CBTitleBar_SetCaption_CAwsString1p(CBTitleBar* pThis, const CAwsString * strText)
{
	pThis->m_oStrCaption=*strText;
	CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));
}

void CBTitleBar_SetBKImage_CAwsImage1p_CEspSize1p(CBTitleBar* pThis, const CAwsImage * imageBK,const CEspSize * sizeImage)
{
	pThis->m_oBKImage=*imageBK;
	pThis->m_oBKImageSize=*sizeImage;

	pThis->m_bIsSetBKImage=1;
}

void CBTitleBar_DrawBackground_IAwsGc1p_CEspRect1p(CBTitleBar* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	CEspSize size=*CEspRect_GetSize(rect);
	CEspRect rt=*(rect);
	if(pThis->m_bIsSetBKImage){
	{
		rt.m_ptLT.m_nY=0;
		{int i,nCount=size.m_nWidth/pThis->m_oBKImageSize.m_nWidth+(size.m_nWidth%pThis->m_oBKImageSize.m_nWidth>0?1:0);
		for(i=0;i<nCount;++i){
		{
			pGc->m_pVTab->m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(pGc,&(rt.m_ptLT),&(pThis->m_oBKImage),ESP_NULL);
			rt.m_ptLT.m_nX+=pThis->m_oBKImageSize.m_nWidth;
		}}
	}}}
	else
	{{
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
		pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);
	}}
}

int CBTitleBar_DrawIcon_IAwsGc1p_CEspRect1p_CEspSize1p(CBTitleBar* pThis, IAwsGc *  pGc,const CEspRect * rect,CEspSize * sizeIcon)
{
	int bRet=0;
	if(CAwsImage_GetID(&(pThis->m_oIconImage))>0){
	{
		// 画图标

		CEspPoint pt=rect->m_ptLT;
		pt.m_nY+=(CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow))->m_nHeight-pThis->m_oIconSize.m_nHeight)/2;

		pGc->m_pVTab->m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(pGc,&(pt),&(pThis->m_oIconImage),&pThis->m_oIconMask);
		*sizeIcon=pThis->m_oIconSize;
		bRet=1;
	}}

	return bRet;
}

void CBTitleBar_DrawText_IAwsGc1p_CEspRect1p(CBTitleBar* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	CEspRect rt=*(rect);
	pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oTextColor));
	pGc->m_pVTab->m_pSetTextAlignment_0p(pGc,AWS_TAM_Left);
	pGc->m_pVTab->m_pSetTextBKMode_0p(pGc,AWS_TSM_Transparent);

	CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
	pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));
	{const CEspSize *  size=pGc->m_pVTab->m_pGetTextSize_CAwsString1p(pGc,&(pThis->m_oStrCaption));
	rt.m_ptLT.m_nY=rt.m_ptLT.m_nY+(CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow))->m_nHeight-size->m_nHeight)/2;
	pGc->m_pVTab->m_pDrawText_CAwsString1p_CEspRect1p(pGc,&(pThis->m_oStrCaption),&(rt));
}}

void CBTitleBar_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CBTitleBar* pThis = (CBTitleBar*)this;{
	// 画背景
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsWindow));

//	TRACE("titlebar draw, X(%d),Y(%d), Width(%d), Height(%d)\n", rect.m_ptLT.m_nX, rect.m_ptLT.m_nY, rect.GetSize()->m_nWidth, rect.GetSize()->m_nHeight);

	if(ESP_NULL!=pGc){
	{
		pThis->m_pVTab->m_pDrawBackground_IAwsGc1p_CEspRect1p(pThis,pGc,rect);

		{CEspRect rt=*(rect);
		rt.m_ptLT.m_nX+=pThis->m_nLeftMargin;

		{CEspSize sizeIcon;
		CEspSize_CInit_i0p_i0p(&(sizeIcon),0,0);
if(pThis->m_pVTab->m_pDrawIcon_IAwsGc1p_CEspRect1p_CEspSize1p(pThis,pGc,&(rt),&(sizeIcon))){
		{
			rt.m_ptLT.m_nX+=sizeIcon.m_nWidth;
		}}

		pThis->m_pVTab->m_pDrawText_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));
	}}}}
}
}
