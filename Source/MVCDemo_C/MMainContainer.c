/******************************************************************************
* FileName		       : MMainContainer.cpp
* Description          : implementation of the CMMainContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "MMainContainer.h"
const VTab_CMMainContainer g_tVTab_CMMainContainer_CMMainContainer = {CMMainContainer_OnActive, CMMainContainer_InActive, CMMainContainer_OnLeftMenu, CMMainContainer_OnRightMenu};
const VTab_CAwsWindow g_tVTab_CMMainContainer_CAwsWindow = {CMMainContainer_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CMMainContainer_OnDraw_CEspRect1p, CMMainContainer_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CBMenuContainer_OnCommand_i0p_i0p_i0p_i0p, CAwsContainer_OnCreate};
void CMMainContainer_CInit(CMMainContainer* pThis)
{
CBMenuContainer_CInit(&(pThis->m_oBase_CBMenuContainer));
CAwsString_CInit_i0p(&(pThis->m_strLeftMenu),100);
CAwsString_CInit_i0p(&(pThis->m_strRightMenu),100);
	pThis->m_pVTab = &g_tVTab_CMMainContainer_CMMainContainer;
	pThis->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CMMainContainer_CAwsWindow;
}

void CMMainContainer_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CMMainContainer* pThis=(CMMainContainer*)this;
	pThis->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsString_DUninit_i1p(&(pThis->m_strRightMenu), 0);
	CAwsString_DUninit_i1p(&(pThis->m_strLeftMenu), 0);
	CBMenuContainer_DUninit_i1p(&(pThis->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMMainContainer*)0)->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CMMainContainer_OnRightMenu(CMMainContainer* pThis) { } 

void CMMainContainer_OnLeftMenu(CMMainContainer* pThis) { } 

void CMMainContainer_InActive(CMMainContainer* pThis) { } 

void CMMainContainer_OnActive(CMMainContainer* pThis) { } 

#include "MUi.h"
const VTab_CAwsWindow g_tVTab_CMUi_CAwsWindow = {CMUi_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CMUi_OnDraw_CEspRect1p, CAwsContainer_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CMUi_OnCreate};
CBTitleBar * CMUi_GetTitleBar(CMUi* pThis) { return pThis->m_pTitleBar; } 

CMMenuBar * CMUi_GetMenuBar(CMUi* pThis) { return pThis->m_pMenuBar; } 

#include "BMenu.h"
#include "MMenuBar.h"
const VTab_CMMenuBar g_tVTab_CMMenuBar_CMMenuBar = {CMMenuBar_DrawBK_IAwsGc1p_CEspRect1p};
const VTab_CAwsWindow g_tVTab_CMMenuBar_CAwsWindow = {CMMenuBar_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CMMenuBar_OnDraw_CEspRect1p, CAwsContainer_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CMMenuBar_OnCreate};
void CMMenuBar_CInit(CMMenuBar* pThis)
{
CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBackColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsImage_CInit(&(pThis->m_oBKImage));
CEspSize_CInit_i0p_i0p(&(pThis->m_oBKImageSize),0,0);
	pThis->m_pVTab = &g_tVTab_CMMenuBar_CMMenuBar;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CMMenuBar_CAwsWindow;
}

void CMMenuBar_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CMMenuBar* pThis=(CMMenuBar*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMMenuBar*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CMMenuBar_SetBKColor_CAwsRgb1p(CMMenuBar* pThis, const CAwsRgb * color) { pThis->m_oBackColor=*color; } 

void CMMenuBar_SetTextColor_CAwsRgb1p(CMMenuBar* pThis, const CAwsRgb * color) { pThis->m_oTextColor=*color; } 

CAwsWindow * CMMenuBar_GetMidCtrl(CMMenuBar* pThis) { return pThis->m_pMidCtrl; } 

#include "IAwsGc.h"

void CMMainContainer_CInit_i0p(CMMainContainer* pThis, int nMaxSubWndCount) {

CBMenuContainer_CInit_i0p(&(pThis->m_oBase_CBMenuContainer),nMaxSubWndCount);
CAwsString_CInit_i0p(&(pThis->m_strLeftMenu),100);
CAwsString_CInit_i0p(&(pThis->m_strRightMenu),100);
	pThis->m_pVTab = &g_tVTab_CMMainContainer_CMMainContainer;
	pThis->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CMMainContainer_CAwsWindow;
{
}
}

CMUi * CMMainContainer_GetMUi(CMMainContainer* pThis)
{
	return (CMUi*)((char*)CAwsWindow_GetParent(&(pThis->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow))-(int)(&(((CMUi*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow)));
}

void CMMainContainer_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CMMainContainer* pThis = (CMMainContainer*)this;{
	// 绘制自己的背景
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow));

	CAwsContainer_OnDraw_CEspRect1p(&(pThis->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),rect);
}
}

int CMMainContainer_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CMMainContainer* pThis = (CMMainContainer*)this;{
	if(AWS_Key_Up==type){
	{
		switch(code)
		{
		case AWS_KeyCode_LeftMenu:
			pThis->m_pVTab->m_pOnLeftMenu(pThis);
			return 1;

		case AWS_KeyCode_RightMenu:
			pThis->m_pVTab->m_pOnRightMenu(pThis);
			return 1;
		}
	}}

	return CAwsContainer_OnKey_0p_0p(&(pThis->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);
}
}

void CMMainContainer_AdjustMenuPos_CBMenu1p_CEspRect1p_CEspPoint1p_i0p(CMMainContainer* pThis, CBMenu *  pMenu,CEspRect * rect,const CEspPoint * pt,int bIsSubMenu)
{
	CEspSize sizeMenu=*(CBMenu_GetMenuSize(pMenu));
	CEspSize sizeMB=*CAwsWindow_GetSize(&(CMUi_GetMenuBar(CMMainContainer_GetMUi(pThis))->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
	CEspSize sizeScreen=*CAwsWindow_GetSize(&(CMMainContainer_GetMUi(pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));

	if(bIsSubMenu){
	{
		rect->m_ptLT=*pt;

		if(rect->m_ptLT.m_nX+sizeMenu.m_nWidth>sizeScreen.m_nWidth){
		{
			// 若超出了屏幕范围，改变x
			rect->m_ptLT.m_nX=sizeScreen.m_nWidth-sizeMenu.m_nWidth;
		}}

		if(rect->m_ptLT.m_nY+sizeMenu.m_nHeight>sizeScreen.m_nHeight-sizeMB.m_nHeight){
		{
			// 改变y
			rect->m_ptLT.m_nY=sizeScreen.m_nHeight-sizeMB.m_nHeight-sizeMenu.m_nHeight;
		}}
		rect->m_ptRB.m_nX=rect->m_ptLT.m_nX+sizeMenu.m_nWidth;
		rect->m_ptRB.m_nY=rect->m_ptLT.m_nY+sizeMenu.m_nHeight;
	}}
	else
	{{
		rect->m_ptLT.m_nY=sizeScreen.m_nHeight-sizeMB.m_nHeight-sizeMenu.m_nHeight;
		rect->m_ptRB.m_nX=sizeMenu.m_nWidth;
		rect->m_ptRB.m_nY=sizeScreen.m_nHeight-sizeMB.m_nHeight;
	}}
}

void CMMainContainer_UpdateMenuBar_0p_0p_i0p(CMMainContainer* pThis, AWS_SysStringID eLeftStrID,AWS_SysStringID eRightStrID,int bIsRedraw)
{
	CMMenuBar *  pMenuBar=CMUi_GetMenuBar(CMMainContainer_GetMUi(pThis));
	if(ESP_NULL!=pMenuBar){
	{		
		CAwsString_LoadString_i0p(&(pThis->m_strLeftMenu),eLeftStrID);
		CAwsString_LoadString_i0p(&(pThis->m_strRightMenu),eRightStrID);

		CMMenuBar_SetLeftMenuText_CAwsString1p_i0p(pMenuBar,&(pThis->m_strLeftMenu),bIsRedraw);
		CMMenuBar_SetRightMenuText_CAwsString1p_i0p(pMenuBar,&(pThis->m_strRightMenu),bIsRedraw);
	}}
}
