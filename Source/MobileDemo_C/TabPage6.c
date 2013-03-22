/******************************************************************************
* FileName		       : TabPage6.cpp
* Description          : implementation of the CTabPage6 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "TabPage6.h"
#include "AwsUserDefine.h"
#include "IAwsGc.h"
#include "MScrollLabel.h"
#include "BButton.h"
#include "BLabel.h"

const VTab_IAwsContainerBuilder g_tVTab_CTabPage6Builder_IAwsContainerBuilder = {CTabPage6Builder_Build_CAwsWindow1p_CEspRect1p};
void CTabPage6Builder_CInit(CTabPage6Builder* pThis)
{

	pThis->m_oBase_IAwsContainerBuilder.m_pVTab = &g_tVTab_CTabPage6Builder_IAwsContainerBuilder;
}

CAwsContainer * CTabPage6Builder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent,const CEspRect * rect)
{

	CTabPage6Builder* pThis = (CTabPage6Builder*)this;{
	{CTabPage6(*pHeapObj_1)=(CTabPage6(*))malloc(sizeof(CTabPage6));
CTabPage6_CInit(pHeapObj_1);
{CAwsContainer *  pContainer=&((pHeapObj_1)->m_oBase_CAwsContainer);
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pContainer->m_oBase_CAwsWindow),pParent,rect,0,1);

	return pContainer;
}}}
}

const VTab_CAwsWindow g_tVTab_CTabPage6_CAwsWindow = {CTabPage6_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CTabPage6_OnDraw_CEspRect1p, CTabPage6_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CTabPage6_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CTabPage6_OnCommand_i0p_i0p_i0p_i0p, CTabPage6_OnCreate};
void CTabPage6_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CTabPage6* pThis=(CTabPage6*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CTabPage6*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CTabPage6_CInit(CTabPage6* pThis)
{

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CTabPage6_CAwsWindow;
{
	pThis->m_pScrollLabel=ESP_NULL;
	pThis->m_pButton=ESP_NULL;

	pThis->m_pLabel=ESP_NULL;
}
}

void CTabPage6_OnCreate(CAwsWindow* this)
{

	CTabPage6* pThis = (CTabPage6*)this;{
	CAwsContainer_OnCreate(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));

	{CAwsString str;
	CEspRect rtLabel,rtButton,rtScrollLabel;
	CAwsRgb rgbLText,rgbSLText;

	{CBLabel(*pHeapObj_1)=(CBLabel(*))malloc(sizeof(CBLabel));
CBLabel_CInit(pHeapObj_1);
{CAwsString_CInit_i0p(&(str),100);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtLabel,95,20,190,40);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtButton,90,50,150,70);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtScrollLabel,80,90,180,110);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbLText,173,154,132);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbSLText,173,154,132);
pThis->m_pLabel=pHeapObj_1;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pLabel->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtLabel),0,1);
	CAwsString_LoadString_i0p(&(str),StringID_ScrollLabel);
	CAwsWindow_SetBKTransparent_i0p(&(pThis->m_pLabel->m_oBase_CAwsWindow),1);
	CBLabel_SetTextColor_CAwsRgb1p_i0p(pThis->m_pLabel,&(rgbLText),0);
	CBLabel_SetText_CAwsString1p_i0p(pThis->m_pLabel,&(str),0);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pLabel)->m_oBase_CAwsWindow),0);

	{CBButton(*pHeapObj_2)=(CBButton(*))malloc(sizeof(CBButton));
CBButton_CInit(pHeapObj_2);
{pThis->m_pButton=pHeapObj_2;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pButton->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtButton),EWndID_Button1,1);
	CAwsString_LoadString_i0p(&(str),StringID_Start);
	CBButton_SetText_CAwsString1p(pThis->m_pButton,&(str));
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pButton)->m_oBase_CAwsWindow),1);

	{CMScrollLabel(*pHeapObj_3)=(CMScrollLabel(*))malloc(sizeof(CMScrollLabel));
CMScrollLabel_CInit(pHeapObj_3);
{pThis->m_pScrollLabel=pHeapObj_3;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pScrollLabel->m_oBase_CBLabel.m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtScrollLabel),0,1);
	CAwsString_LoadString_i0p(&(str),StringID_NJUST);
	CAwsWindow_SetBKTransparent_i0p(&(pThis->m_pScrollLabel->m_oBase_CBLabel.m_oBase_CAwsWindow),1);
	CBLabel_SetTextColor_CAwsRgb1p_i0p(&(pThis->m_pScrollLabel->m_oBase_CBLabel),&(rgbSLText),0);
	CBLabel_SetText_CAwsString1p_i0p(&(pThis->m_pScrollLabel->m_oBase_CBLabel),&(str),0);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pScrollLabel)->m_oBase_CBLabel.m_oBase_CAwsWindow),0);

}}}}}}CAwsString_DUninit_i1p(&(str), 0);
}}
}

void CTabPage6_OnFocus_i0p(CAwsWindow* this, int bIsFocus)
{

	CTabPage6* pThis = (CTabPage6*)this;{
	CAwsContainer_OnFocus_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),bIsFocus);

	if(!pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_bIsFocus){
	{
		CMScrollLabel_EndScroll(pThis->m_pScrollLabel);
	}}
}
}

int CTabPage6_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CTabPage6* pThis = (CTabPage6*)this;{
	CAwsString str;
	CAwsString_CInit_i0p(&(str),100);
if(AWS_SysCmd_ButtonCmd==nCmdID&&nWndID==EWndID_Button1){
	{
		if(CMScrollLabel_IsStartScroll(pThis->m_pScrollLabel)){
		{
			CMScrollLabel_EndScroll(pThis->m_pScrollLabel);
		}}
		else
		{{
			CAwsString_LoadString_i0p(&(str),StringID_End);
			CBButton_SetText_CAwsString1p(pThis->m_pButton,&(str));
			CMScrollLabel_StartScroll_i0p(pThis->m_pScrollLabel,1);
		}}

		{CAwsString_DUninit_i1p(&(str), 0);
return 1;}
	}}
	else if(AWS_SysCmd_ScrollLabelEndScroll==nCmdID){
	{
		CAwsString_LoadString_i0p(&(str),StringID_Start);
		CBButton_SetText_CAwsString1p(pThis->m_pButton,&(str));
	}}

	{CAwsString_DUninit_i1p(&(str), 0);
return CAwsWindow_OnCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),nWndID,nCmdID,nParam1,nParam2);}
}
}

int CTabPage6_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CTabPage6* pThis = (CTabPage6*)this;{
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

void CTabPage6_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CTabPage6* pThis = (CTabPage6*)this;{
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
