/******************************************************************************
* FileName		       : MMsgBox.cpp
* Description          : implementation of the CMMsgBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "MMsgBox.h"
const VTab_CMMsgBox g_tVTab_CMMsgBox_CMMsgBox = {CMMsgBox_DrawBK_IAwsGc1p_CEspRect1p, CMMsgBox_DrawInf_IAwsGc1p_CEspRect1p, CMMsgBox_OnLeftMenu, CMMsgBox_OnRightMenu};
const VTab_CAwsWindow g_tVTab_CMMsgBox_CAwsWindow = {CMMsgBox_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CMMsgBox_OnDraw_CEspRect1p, CMMsgBox_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CMMsgBox_OnCommand_i0p_i0p_i0p_i0p, CAwsContainer_OnCreate};
void CMMsgBox_CInit(CMMsgBox* pThis)
{
CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
CAwsString_CInit_i0p(&(pThis->m_strText),100);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
	pThis->m_pVTab = &g_tVTab_CMMsgBox_CMMsgBox;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CMMsgBox_CAwsWindow;
}

void CMMsgBox_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CMMsgBox* pThis=(CMMsgBox*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsString_DUninit_i1p(&(pThis->m_strText), 0);
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMMsgBox*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CMMsgBox_SetFontSize_i0p(CMMsgBox* pThis, int nFontSize) { pThis->m_nFontSize=nFontSize; } 

void CMMsgBox_SetTextColor_CAwsRgb1p(CMMsgBox* pThis, const CAwsRgb * color) { pThis->m_oTextColor=*color; } 

void CMMsgBox_SetBKColor_CAwsRgb1p(CMMsgBox* pThis, const CAwsRgb * color) { pThis->m_oBKColor=*color; } 

void CMMsgBox_SetBorderColor_CAwsRgb1p(CMMsgBox* pThis, const CAwsRgb * color) { pThis->m_oBorderColor=*color; } 

#include "AwsUi.h"
#include "IAwsGc.h"
#include "MUi.h"
#include "MMenuBar.h"

void CMMsgBox_CInit_CAwsWindow1p_i0p(CMMsgBox* pThis, CAwsWindow *  pParentWnd,int nWndID)
{

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
CAwsString_CInit_i0p(&(pThis->m_strText),100);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
	pThis->m_pVTab = &g_tVTab_CMMsgBox_CMMsgBox;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CMMsgBox_CAwsWindow;
{
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pParent=pParentWnd;

	{CAwsRgb rgbBorder,rgbBK,rgbText;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbBorder,73,73,73);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,255,255,255);
pThis->m_oBorderColor=rgbBorder;
	pThis->m_oBKColor=rgbBK;
	pThis->m_oTextColor=rgbText;

	pThis->m_nFontSize=12;

	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID=nWndID;
}}
}

void CMMsgBox_ShowMsg_0p_CAwsString1p(CMMsgBox* pThis, AWS_MsgBoxType eType,const CAwsString * strText)
{
	pThis->m_eType=eType;
	pThis->m_strText=*strText;

	{CAwsWindow *  pWnd=&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow);
	while(ESP_NULL!=CAwsWindow_GetParent(pWnd)){
		pWnd=CAwsWindow_GetParent(pWnd);}

	{CMUi *  pUi=(CMUi*)((char*)pWnd-(int)(&(((CMUi*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow)));
	CAwsString str;

	CAwsString_CInit_i0p(&(str),100);
switch(pThis->m_eType)
	{
	case AWS_MBT_OK_Cancel:
		CAwsString_LoadString_i0p(&(str),StringID_OK);
		CMMenuBar_SetLeftMenuText_CAwsString1p_i0p(CMUi_GetMenuBar(pUi),&(str),1);
		CAwsString_LoadString_i0p(&(str),StringID_Cancel);
		CMMenuBar_SetRightMenuText_CAwsString1p_i0p(CMUi_GetMenuBar(pUi),&(str),1);
		break;

	case AWS_MBT_OK:
		CAwsString_LoadString_i0p(&(str),StringID_OK);
		CMMenuBar_SetLeftMenuText_CAwsString1p_i0p(CMUi_GetMenuBar(pUi),&(str),1);
		CAwsString_LoadString_i0p(&(str),StringID_NULL);
		CMMenuBar_SetRightMenuText_CAwsString1p_i0p(CMUi_GetMenuBar(pUi),&(str),1);
		break;
	}

	//  弹出窗口
	{CEspRect rect;
	CEspSize sizeScreen=*CAwsWindow_GetSize(&(pUi->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
	CEspRect_CInit(&(rect));
rect.m_ptRB.m_nX=sizeScreen.m_nWidth;
	rect.m_ptRB.m_nY=sizeScreen.m_nHeight-CAwsWindow_GetSize(&(CMUi_GetMenuBar(pUi)->m_oBase_CAwsContainer.m_oBase_CAwsWindow))->m_nHeight;
	rect.m_ptLT.m_nY=rect.m_ptRB.m_nY-80;

	CAwsContainer_PopWnd_CAwsWindow1p_CEspRect1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rect),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID);
}CAwsString_DUninit_i1p(&(str), 0);
}}}

void CMMsgBox_DrawBK_IAwsGc1p_CEspRect1p(CMMsgBox* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBorderColor));
	pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);
}

void CMMsgBox_DrawInf_IAwsGc1p_CEspRect1p(CMMsgBox* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oTextColor));

	pGc->m_pVTab->m_pSetTextAlignment_0p(pGc,AWS_TAM_Mid);

	CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
	pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));
	{const CEspSize *  size=pGc->m_pVTab->m_pGetTextSize_CAwsString1p(pGc,&(pThis->m_strText));
	CEspRect rt=*(rect);
	rt.m_ptLT.m_nY=rt.m_ptLT.m_nY+(CEspRect_GetSize(rect)->m_nHeight-size->m_nHeight)/2;

	pGc->m_pVTab->m_pDrawText_CAwsString1p_CEspRect1p(pGc,&(pThis->m_strText),&(rt));
	pGc->m_pVTab->m_pDiscardFont(pGc);
}}

void CMMsgBox_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CMMsgBox* pThis = (CMMsgBox*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));

	if(ESP_NULL!=pGc){
	{
		// 画背景
		pThis->m_pVTab->m_pDrawBK_IAwsGc1p_CEspRect1p(pThis,pGc,rect);

		// 画信息
		pThis->m_pVTab->m_pDrawInf_IAwsGc1p_CEspRect1p(pThis,pGc,rect);
	}}

	CAwsContainer_OnDraw_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),rect);
}
}

int CMMsgBox_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CMMsgBox* pThis = (CMMsgBox*)this;{
	if(AWS_SysCmd_LeftMenuClick==nCmdID){
	{
		CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_MsgBox_OK,0,0);
		return 1;
	}}

	return 0;
}
}

void CMMsgBox_OnLeftMenu(CMMsgBox* pThis)
{
	CAwsContainer_DestroyPopWnd_i0p(&(pThis->m_oBase_CAwsContainer),1);

	switch(pThis->m_eType)
	{
	case AWS_MBT_OK_Cancel:
		CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_MsgBox_OK,0,0);
		break;

	case AWS_MBT_OK:
		CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_MsgBox_OK,0,0);
		break;
	}
}

void CMMsgBox_OnRightMenu(CMMsgBox* pThis)
{
	switch(pThis->m_eType)
	{
	case AWS_MBT_OK_Cancel:
		CAwsContainer_DestroyPopWnd_i0p(&(pThis->m_oBase_CAwsContainer),1);
		CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_MsgBox_Cancel,0,0);
		break;
	}
}

int CMMsgBox_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CMMsgBox* pThis = (CMMsgBox*)this;{
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

	if(AWS_Key==type){
	{
		switch(code)
		{
		case AWS_KeyCode_OK:
			return pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pOnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),AWS_Key_Up,AWS_KeyCode_LeftMenu);
		}
	}}

	return 1;
//	return CAwsContainer::OnKey(type, code);
}
}
