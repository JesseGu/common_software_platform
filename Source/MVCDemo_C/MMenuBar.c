/******************************************************************************
* FileName		       : MMenuBar.cpp
* Description          : implementation of the CMMenuBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

//#include <AFX.h>

#include "MMenuBar.h"
#include "BLabel.h"
#include "IAwsGc.h"
#include "AwsUi.h"

void CMMenuBar_CInit_i0p_CAwsWindow1p(CMMenuBar* pThis, int nMenuBarHeight,CAwsWindow *  pMidCtrl)
{

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBackColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsImage_CInit(&(pThis->m_oBKImage));
CEspSize_CInit_i0p_i0p(&(pThis->m_oBKImageSize),0,0);
	pThis->m_pVTab = &g_tVTab_CMMenuBar_CMMenuBar;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CMMenuBar_CAwsWindow;
{
	pThis->m_nMenuBarHeight=nMenuBarHeight;

	pThis->m_pLeftBar=ESP_NULL;
	pThis->m_pRightBar=ESP_NULL;

	pThis->m_nBarUnitWidth=40;

	pThis->m_pMidCtrl=pMidCtrl;

	{CAwsRgb rgbBack,rgbBorder,rgbText;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbBack,236,233,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBorder,0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,255,255,255);
pThis->m_oBackColor=rgbBack;
	pThis->m_oBorderColor=rgbBorder;
	pThis->m_oTextColor=rgbText;

	pThis->m_nFontSize=14;

	pThis->m_bIsSetImage=0;
}}
}

void CMMenuBar_OnCreate(CAwsWindow* this)
{

	CMMenuBar* pThis = (CMMenuBar*)this;{
	// 重新设置菜单条的大小
	CEspSize size=*(CAwsUi_GetScreenSize(CAwsWindow_GetUi(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow))));
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect.m_ptLT.m_nX=0;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect.m_ptLT.m_nY=size.m_nHeight-pThis->m_nMenuBarHeight;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect.m_ptRB.m_nX=pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect.m_ptLT.m_nX+size.m_nWidth;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect.m_ptRB.m_nY=size.m_nHeight;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tOrigin=pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect.m_ptLT;

	{CAwsString strText;
	CEspRect rt;

	{CBLabel(*pHeapObj_1)=(CBLabel(*))malloc(sizeof(CBLabel));
CBLabel_CInit(pHeapObj_1);
{CAwsString_CInit_i0p(&(strText),100);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rt,1,1+3,pThis->m_nBarUnitWidth+1,CEspRect_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect))->m_nHeight-1-3);
pThis->m_pLeftBar=pHeapObj_1;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pLeftBar->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt),0,1);
	CBLabel_SetTextColor_CAwsRgb1p_i0p(pThis->m_pLeftBar,&(pThis->m_oTextColor),0);
	CBLabel_SetTextAlignment_0p_i0p(pThis->m_pLeftBar,AWS_TAM_Left,0);
	CBLabel_SetTextSize_i0p(pThis->m_pLeftBar,pThis->m_nFontSize);
	CAwsWindow_SetBKTransparent_i0p(&(pThis->m_pLeftBar->m_oBase_CAwsWindow),1);
	CAwsString_LoadString_i0p(&(strText),1);
	CBLabel_SetText_CAwsString1p_i0p(pThis->m_pLeftBar,&(strText),0);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pLeftBar)->m_oBase_CAwsWindow),0);

	if(ESP_NULL!=pThis->m_pMidCtrl){
	{
		CEspRect rt;
		CEspRect_CInit_i0p_i0p_i0p_i0p(&rt,pThis->m_nBarUnitWidth,0,pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect.m_ptRB.m_nY-pThis->m_nBarUnitWidth,pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect.m_ptRB.m_nY);
CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(pThis->m_pMidCtrl,&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt),0,1);
		CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),pThis->m_pMidCtrl,0);
	}}

	{CEspRect rect;
	{CBLabel(*pHeapObj_2)=(CBLabel(*))malloc(sizeof(CBLabel));
CBLabel_CInit(pHeapObj_2);
{CEspRect_CInit_i0p_i0p_i0p_i0p(&rect,CEspRect_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect))->m_nWidth-pThis->m_nBarUnitWidth-1,1+3,CEspRect_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect))->m_nWidth-1,CEspRect_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect))->m_nHeight-1-3);
pThis->m_pRightBar=pHeapObj_2;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pRightBar->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rect),0,1);
	CBLabel_SetTextColor_CAwsRgb1p_i0p(pThis->m_pRightBar,&(pThis->m_oTextColor),0);
	CBLabel_SetTextAlignment_0p_i0p(pThis->m_pRightBar,AWS_TAM_Right,0);
	CAwsWindow_SetBKTransparent_i0p(&(pThis->m_pRightBar->m_oBase_CAwsWindow),1);
	CBLabel_SetTextSize_i0p(pThis->m_pRightBar,pThis->m_nFontSize);
	CAwsString_LoadString_i0p(&(strText),2);
	CBLabel_SetText_CAwsString1p_i0p(pThis->m_pRightBar,&(strText),0);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pRightBar)->m_oBase_CAwsWindow),0);
}}}}}CAwsString_DUninit_i1p(&(strText), 0);
}}
}

void CMMenuBar_SetMidCtrl_CAwsWindow1p(CMMenuBar* pThis, CAwsWindow *  pMidCtrl)
{
}

void CMMenuBar_SetBKImage_CAwsImage1p_CEspSize1p(CMMenuBar* pThis, const CAwsImage * imageBK,const CEspSize * sizeIamge)
{
	pThis->m_oBKImage=*imageBK;
	pThis->m_oBKImageSize=*sizeIamge;
	pThis->m_bIsSetImage=1;
}

void CMMenuBar_SetLeftMenuText_CAwsString1p_i0p(CMMenuBar* pThis, const CAwsString * strText,int bIsRedraw)
{
	CBLabel_SetText_CAwsString1p_i0p(pThis->m_pLeftBar,strText,0);
	if(bIsRedraw){
		pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),CAwsWindow_GetRect(&(pThis->m_pLeftBar->m_oBase_CAwsWindow)));}
}

void CMMenuBar_SetRightMenuText_CAwsString1p_i0p(CMMenuBar* pThis, const CAwsString * strText,int bIsRedraw)
{
	CBLabel_SetText_CAwsString1p_i0p(pThis->m_pRightBar,strText,0);
	if(bIsRedraw){
		pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),CAwsWindow_GetRect(&(pThis->m_pRightBar->m_oBase_CAwsWindow)));}
}

void CMMenuBar_DrawBK_IAwsGc1p_CEspRect1p(CMMenuBar* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	CEspSize size=*CEspRect_GetSize(rect);
	CEspRect rt=*(rect);

	if(pThis->m_bIsSetImage){
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
		if(CEspRect_GetSize(rect)->m_nWidth==CAwsWindow_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow))->m_nWidth){
		{
			pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBorderColor));
			pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBackColor));
			pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,&(rt));
		}}
		else
		{{
			pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBackColor));
			pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBackColor));
			pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,&(rt));
		}}
	}}
}

void CMMenuBar_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CMMenuBar* pThis = (CMMenuBar*)this;{
//	TRACE("menubar draw, X(%d),Y(%d), Width(%d), Height(%d)\n", rect.m_ptLT.m_nX, rect.m_ptLT.m_nY, rect.GetSize()->m_nWidth, rect.GetSize()->m_nHeight);

	// 画背景
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));

	if(ESP_NULL!=pGc){
	{
		pThis->m_pVTab->m_pDrawBK_IAwsGc1p_CEspRect1p(pThis,pGc,rect);

		// 调用父类的绘制函数
		CAwsContainer_OnDraw_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),rect);
	}}
}
}
