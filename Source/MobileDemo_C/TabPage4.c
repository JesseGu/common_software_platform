/******************************************************************************
* FileName		       : TabPage4.cpp
* Description          : implementation of the CTabPage4 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "TabPage4.h"
#include "AwsUserDefine.h"
#include "IAwsGc.h"
#include "BSelectBox.h"
#include "MImageBox.h"
#include "BLabel.h"

const VTab_IAwsContainerBuilder g_tVTab_CTabPage4Builder_IAwsContainerBuilder = {CTabPage4Builder_Build_CAwsWindow1p_CEspRect1p};
void CTabPage4Builder_CInit(CTabPage4Builder* pThis)
{

	pThis->m_oBase_IAwsContainerBuilder.m_pVTab = &g_tVTab_CTabPage4Builder_IAwsContainerBuilder;
}

CAwsContainer * CTabPage4Builder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent,const CEspRect * rect)
{

	CTabPage4Builder* pThis = (CTabPage4Builder*)this;{
	{CTabPage4(*pHeapObj_1)=(CTabPage4(*))malloc(sizeof(CTabPage4));
CTabPage4_CInit(pHeapObj_1);
{CAwsContainer *  pContainer=&((pHeapObj_1)->m_oBase_CAwsContainer);	
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pContainer->m_oBase_CAwsWindow),pParent,rect,0,1);
	
	return pContainer;
}}}
}

const VTab_CAwsWindow g_tVTab_CTabPage4_CAwsWindow = {CTabPage4_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CTabPage4_OnDraw_CEspRect1p, CTabPage4_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CTabPage4_OnCommand_i0p_i0p_i0p_i0p, CTabPage4_OnCreate};
void CTabPage4_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CTabPage4* pThis=(CTabPage4*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CTabPage4*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CTabPage4_CInit(CTabPage4* pThis)
{

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CTabPage4_CAwsWindow;
{
	pThis->m_pLabel=ESP_NULL;
	pThis->m_pImageBox=ESP_NULL;
	pThis->m_pSelectBox=ESP_NULL;
}
}

void CTabPage4_OnCreate(CAwsWindow* this)
{

	CTabPage4* pThis = (CTabPage4*)this;{
	CAwsString str;
	CEspRect rtLabel,rtImageBox,rtSelectBox;
	CAwsRgb rgbLabelText;

	{CBLabel(*pHeapObj_1)=(CBLabel(*))malloc(sizeof(CBLabel));
CBLabel_CInit(pHeapObj_1);
{CAwsString_CInit_i0p(&(str),100);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtLabel,100,20,200,40);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtImageBox,100,50,140,90);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtSelectBox,70,100,180,120);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbLabelText,173,154,132);
pThis->m_pLabel=pHeapObj_1;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pLabel->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtLabel),0,1);
	CAwsString_LoadString_i0p(&(str),StringID_SelectBox);
	CAwsWindow_SetBKTransparent_i0p(&(pThis->m_pLabel->m_oBase_CAwsWindow),1);
	CBLabel_SetTextColor_CAwsRgb1p_i0p(pThis->m_pLabel,&(rgbLabelText),0);
	CBLabel_SetText_CAwsString1p_i0p(pThis->m_pLabel,&(str),0);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pLabel)->m_oBase_CAwsWindow),0);

	{CMImageBox(*pHeapObj_2)=(CMImageBox(*))malloc(sizeof(CMImageBox));
CMImageBox_CInit(pHeapObj_2);
{pThis->m_pImageBox=pHeapObj_2;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pImageBox->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtImageBox),0,1);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pImageBox)->m_oBase_CAwsWindow),0);
	{CAwsImage image,imageMask;
	CAwsImage_CInit(&(image));
CAwsImage_CInit(&(imageMask));
CAwsImage_LoadImage_i0p(&(image),IDB_MAIN1);
	CAwsImage_LoadImage_i0p(&(imageMask),IDB_MAINMASK);
	CMImageBox_ShowImage_CAwsImage1p_CAwsImage1p(pThis->m_pImageBox,&(image),&(imageMask));

	{CBSelectBox*pHeapObj_3=(CBSelectBox(*))malloc(sizeof(CBSelectBox));
CBSelectBox_CInit_i0p(pHeapObj_3,10);
{pThis->m_pSelectBox=pHeapObj_3;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pSelectBox->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtSelectBox),0,1);
	CAwsString_LoadString_i0p(&(str),1);
	CBSelectBox_AddItem_CAwsString1p(pThis->m_pSelectBox,&(str));
	CAwsString_LoadString_i0p(&(str),2);
	CBSelectBox_AddItem_CAwsString1p(pThis->m_pSelectBox,&(str));
	CAwsString_LoadString_i0p(&(str),3);
	CBSelectBox_AddItem_CAwsString1p(pThis->m_pSelectBox,&(str));
	CAwsString_LoadString_i0p(&(str),4);
	CBSelectBox_AddItem_CAwsString1p(pThis->m_pSelectBox,&(str));
	CAwsString_LoadString_i0p(&(str),5);
	CBSelectBox_AddItem_CAwsString1p(pThis->m_pSelectBox,&(str));
	CAwsString_LoadString_i0p(&(str),2);
	CBSelectBox_AddItem_CAwsString1p(pThis->m_pSelectBox,&(str));
	CBSelectBox_AddItemEnd(pThis->m_pSelectBox);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pSelectBox)->m_oBase_CAwsWindow),1);
}}}}}}}CAwsString_DUninit_i1p(&(str), 0);
}
}

int CTabPage4_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CTabPage4* pThis = (CTabPage4*)this;{
	if(AWS_SysCmd_SelectBoxFocusItemChange==nCmdID){
	{
		CAwsImage image,imageMask;
		CAwsImage_CInit(&(image));
CAwsImage_CInit(&(imageMask));
CAwsImage_LoadImage_i0p(&(image),IDB_MAIN1+nParam1);
		CAwsImage_LoadImage_i0p(&(imageMask),IDB_MAINMASK);
		CMImageBox_ShowImage_CAwsImage1p_CAwsImage1p(pThis->m_pImageBox,&(image),&(imageMask));

		return 1;
	}}

	return CAwsWindow_OnCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),nWndID,nCmdID,nParam1,nParam2);
}
}

int CTabPage4_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CTabPage4* pThis = (CTabPage4*)this;{
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

void CTabPage4_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CTabPage4* pThis = (CTabPage4*)this;{
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
