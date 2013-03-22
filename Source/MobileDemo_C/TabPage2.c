/******************************************************************************
* FileName		       : TabPage3.cpp
* Description          : implementation of the CTabPage3 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "TabPage2.h"
#include "AwsUserDefine.h"
#include "IAwsGc.h"
#include "BListBox.h"
#include "BLabel.h"
#include "MMsgBox.h"

const VTab_IAwsContainerBuilder g_tVTab_CTabPage2Builder_IAwsContainerBuilder = {CTabPage2Builder_Build_CAwsWindow1p_CEspRect1p};
void CTabPage2Builder_CInit(CTabPage2Builder* pThis)
{

	pThis->m_oBase_IAwsContainerBuilder.m_pVTab = &g_tVTab_CTabPage2Builder_IAwsContainerBuilder;
}

CAwsContainer * CTabPage2Builder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent,const CEspRect * rect)
{

	CTabPage2Builder* pThis = (CTabPage2Builder*)this;{
	{CTabPage2(*pHeapObj_1)=(CTabPage2(*))malloc(sizeof(CTabPage2));
CTabPage2_CInit(pHeapObj_1);
{CAwsContainer *  pContainer=&((pHeapObj_1)->m_oBase_CAwsContainer);
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pContainer->m_oBase_CAwsWindow),pParent,rect,0,1);

	return pContainer;
}}}
}

const VTab_CAwsWindow g_tVTab_CTabPage2_CAwsWindow = {CTabPage2_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CTabPage2_OnDraw_CEspRect1p, CAwsContainer_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CTabPage2_OnCommand_i0p_i0p_i0p_i0p, CTabPage2_OnCreate};
void CTabPage2_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CTabPage2* pThis=(CTabPage2*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CTabPage2*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CTabPage2_CInit(CTabPage2* pThis)
{

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CTabPage2_CAwsWindow;
{
	pThis->m_pListBox=ESP_NULL;
}
}

void CTabPage2_OnCreate(CAwsWindow* this)
{

	CTabPage2* pThis = (CTabPage2*)this;{
	CAwsString str;

	CEspRect rtLabel,rtListBox;
	CAwsRgb rgbText,rgbBorder;

	{CBLabel(*pHeapObj_1)=(CBLabel(*))malloc(sizeof(CBLabel));
CBLabel_CInit(pHeapObj_1);
{CAwsString_CInit_i0p(&(str),100);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtLabel,100,20,200,40);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtListBox,70,50,170,152);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,173,154,132);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBorder,173,154,132);
pThis->m_pLabel=pHeapObj_1;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pLabel->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtLabel),0,1);
	CAwsString_LoadString_i0p(&(str),StringID_ListBox);
	CAwsWindow_SetBKTransparent_i0p(&(pThis->m_pLabel->m_oBase_CAwsWindow),1);
	CBLabel_SetTextColor_CAwsRgb1p_i0p(pThis->m_pLabel,&(rgbText),0);
	CBLabel_SetText_CAwsString1p_i0p(pThis->m_pLabel,&(str),0);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pLabel)->m_oBase_CAwsWindow),0);

	{CBListBox*pHeapObj_2=(CBListBox(*))malloc(sizeof(CBListBox));
CBListBox_CInit_i0p(pHeapObj_2,30);
{pThis->m_pListBox=pHeapObj_2;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pListBox->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtListBox),0,1);
	{int i;
	for(i=1;i<=10;++i){
	{
		CAwsString_LoadString_i0p(&(str),i);
		CBListBox_AddItem_CAwsString1p(pThis->m_pListBox,&(str));
	}}
	CBListBox_AddItemEnd(pThis->m_pListBox);
	CBListBox_SetBorderColor_CAwsRgb1p(pThis->m_pListBox,&(rgbBorder));
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pListBox)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),1);
}}}}}CAwsString_DUninit_i1p(&(str), 0);
}
}

int CTabPage2_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CTabPage2* pThis = (CTabPage2*)this;{
	if(AWS_SysCmd_ListBoxCmd==nCmdID){
	{
		{CMMsgBox*pHeapObj_1=(CMMsgBox(*))malloc(sizeof(CMMsgBox));
CMMsgBox_CInit_CAwsWindow1p_i0p(pHeapObj_1,&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),EWndID_Msg_Selected);
{CMMsgBox *  pMsg=pHeapObj_1;
		CAwsString str;
		CAwsString_CInit_i0p(&(str),100);
CAwsString_LoadString_i0p(&(str),StringID_WelcomeUse);
		CMMsgBox_ShowMsg_0p_CAwsString1p(pMsg,AWS_MBT_OK,&(str));
	CAwsString_DUninit_i1p(&(str), 0);
}}}}

	return CAwsWindow_OnCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),nWndID,nCmdID,nParam1,nParam2);
}
}

void CTabPage2_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CTabPage2* pThis = (CTabPage2*)this;{
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
