/******************************************************************************
* FileName		       : TabPage1.cpp
* Description          : implementation of the CTabPage1 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "TabPage1.h"
#include "AwsUserDefine.h"
#include "IAwsGc.h"
#include "BLabel.h"
#include "BProgressBar.h"
#include "BButton.h"

const VTab_IAwsContainerBuilder g_tVTab_CTabPage1Builder_IAwsContainerBuilder = {CTabPage1Builder_Build_CAwsWindow1p_CEspRect1p};
void CTabPage1Builder_CInit(CTabPage1Builder* pThis)
{

	pThis->m_oBase_IAwsContainerBuilder.m_pVTab = &g_tVTab_CTabPage1Builder_IAwsContainerBuilder;
}

CAwsContainer * CTabPage1Builder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent,const CEspRect * rect)
{

	CTabPage1Builder* pThis = (CTabPage1Builder*)this;{
	{CTabPage1(*pHeapObj_1)=(CTabPage1(*))malloc(sizeof(CTabPage1));
CTabPage1_CInit(pHeapObj_1);
{CAwsContainer *  pContainer=&((pHeapObj_1)->m_oBase_CAwsContainer);
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pContainer->m_oBase_CAwsWindow),pParent,rect,0,1);

	return pContainer;
}}}
}

const VTab_CAwsWindow g_tVTab_CTabPage1_CAwsWindow = {CTabPage1_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CTabPage1_OnDraw_CEspRect1p, CTabPage1_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CTabPage1_OnFocus_i0p, CTabPage1_OnTimer, CAwsContainer_OnImeChar_s0p, CTabPage1_OnCommand_i0p_i0p_i0p_i0p, CTabPage1_OnCreate};
void CTabPage1_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CTabPage1* pThis=(CTabPage1*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CTabPage1*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CTabPage1_CInit(CTabPage1* pThis)
{

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CTabPage1_CAwsWindow;
{
	pThis->m_pLabel=ESP_NULL;

	pThis->m_pProgressBar=ESP_NULL;
	pThis->m_nProgressBarLength=100;
	pThis->m_nCurProgressBarPos=0;

	pThis->m_pButton=ESP_NULL;

	pThis->m_bIsStart=0;
}
}

void CTabPage1_OnCreate(CAwsWindow* this)
{

	CTabPage1* pThis = (CTabPage1*)this;{
	// 创建各种控件
	CAwsString str;
	CEspRect rtLabel,rtButton,rtProgressBar;
	CAwsRgb rgbText;

	{CBLabel(*pHeapObj_1)=(CBLabel(*))malloc(sizeof(CBLabel));
CBLabel_CInit(pHeapObj_1);
{CAwsString_CInit_i0p(&(str),100);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtLabel,100,20,180,40);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtButton,90,50,150,70);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtProgressBar,75,90,175,100);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,173,154,132);
pThis->m_pLabel=pHeapObj_1;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pLabel->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtLabel),0,1);
	CAwsString_LoadString_i0p(&(str),StringID_ProgressBar);
	CAwsWindow_SetBKTransparent_i0p(&(pThis->m_pLabel->m_oBase_CAwsWindow),1);
	CBLabel_SetTextColor_CAwsRgb1p_i0p(pThis->m_pLabel,&(rgbText),0);
	CBLabel_SetText_CAwsString1p_i0p(pThis->m_pLabel,&(str),0);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pLabel)->m_oBase_CAwsWindow),0);

	{CBButton(*pHeapObj_2)=(CBButton(*))malloc(sizeof(CBButton));
CBButton_CInit(pHeapObj_2);
{pThis->m_pButton=pHeapObj_2;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pButton->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtButton),EWndID_Button1,1);
	CAwsString_LoadString_i0p(&(str),StringID_Start);
	CBButton_SetText_CAwsString1p(pThis->m_pButton,&(str));
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pButton)->m_oBase_CAwsWindow),1);

	{CBProgressBar(*pHeapObj_3)=(CBProgressBar(*))malloc(sizeof(CBProgressBar));
CBProgressBar_CInit(pHeapObj_3);
{pThis->m_pProgressBar=pHeapObj_3;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pProgressBar->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtProgressBar),0,1);
	CBProgressBar_SetTotalLenght_i0p(pThis->m_pProgressBar,pThis->m_nProgressBarLength);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pProgressBar)->m_oBase_CAwsWindow),0);
}}}}}}CAwsString_DUninit_i1p(&(str), 0);
}
}

int CTabPage1_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CTabPage1* pThis = (CTabPage1*)this;{
	int bRet=CAwsContainer_OnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);

	if(!bRet){
	{
		if(AWS_Key==type){
		{
			switch(code)
			{
			case AWS_KeyCode_UpArrow:
				// 发送消息给TabView，说明要切换到TabPanel
				CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_TabViewSetPanelFocus,0,0);
				break;
			}
		}}
	}}

	return bRet;
}
}

int CTabPage1_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CTabPage1* pThis = (CTabPage1*)this;{
	CAwsString str;

	CAwsString_CInit_i0p(&(str),100);
if(AWS_SysCmd_ButtonCmd==nCmdID&&nWndID==EWndID_Button1){
	{
		if(!pThis->m_bIsStart){
		{
			CAwsWindow_StartTimer_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),100);
			CAwsString_LoadString_i0p(&(str),StringID_End);
			CBButton_SetText_CAwsString1p(pThis->m_pButton,&(str));
		}}
		else
		{{
			CAwsWindow_EndTimer(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
			CAwsString_LoadString_i0p(&(str),StringID_Start);
			CBButton_SetText_CAwsString1p(pThis->m_pButton,&(str));
		}}

		pThis->m_bIsStart=!pThis->m_bIsStart;

		{CAwsString_DUninit_i1p(&(str), 0);
return 1;}
	}}

	{CAwsString_DUninit_i1p(&(str), 0);
return CAwsWindow_OnCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),nWndID,nCmdID,nParam1,nParam2);}
}
}

void CTabPage1_OnTimer(CAwsWindow* this)
{

	CTabPage1* pThis = (CTabPage1*)this;{
	if(ESP_NULL!=pThis->m_pProgressBar){
	{
		CBProgressBar_SetPos_i0p(pThis->m_pProgressBar,pThis->m_nCurProgressBarPos++);

		if(pThis->m_nCurProgressBarPos>pThis->m_nProgressBarLength){
			pThis->m_nCurProgressBarPos=1;}
	}}
}
}

void CTabPage1_OnFocus_i0p(CAwsWindow* this, int bIsFocus)
{

	CTabPage1* pThis = (CTabPage1*)this;{
	CAwsContainer_OnFocus_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),bIsFocus);

	if(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_bIsFocus){
	{
//		StartTimer(100);
	}}
	else
	{{
		// 停止
		CAwsString str;
		CAwsString_CInit_i0p(&(str),100);
CAwsWindow_EndTimer(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
		CAwsString_LoadString_i0p(&(str),StringID_Start);
		CBButton_SetText_CAwsString1p(pThis->m_pButton,&(str));
		pThis->m_bIsStart=0;
	CAwsString_DUninit_i1p(&(str), 0);
}}
}
}

void CTabPage1_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CTabPage1* pThis = (CTabPage1*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
	CAwsRgb rgbPen,rgbBrush;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbPen,0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBrush,0,0,0);
pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(rgbPen));
	pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(rgbBrush));
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);

	CAwsContainer_OnDraw_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),rect);
}
}
