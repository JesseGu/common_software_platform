/******************************************************************************
* FileName		       : TabPage5.cpp
* Description          : implementation of the CTabPage5 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "TabPage5.h"
#include "AwsUserDefine.h"
#include "IAwsGc.h"
#include "BComboBox.h"
#include "BLabel.h"
#include "BEdit.h"

const VTab_IAwsContainerBuilder g_tVTab_CTabPage5Builder_IAwsContainerBuilder = {CTabPage5Builder_Build_CAwsWindow1p_CEspRect1p};
void CTabPage5Builder_CInit(CTabPage5Builder* pThis)
{

	pThis->m_oBase_IAwsContainerBuilder.m_pVTab = &g_tVTab_CTabPage5Builder_IAwsContainerBuilder;
}

CAwsContainer * CTabPage5Builder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent,const CEspRect * rect)
{

	CTabPage5Builder* pThis = (CTabPage5Builder*)this;{
	{CTabPage5(*pHeapObj_1)=(CTabPage5(*))malloc(sizeof(CTabPage5));
CTabPage5_CInit(pHeapObj_1);
{CAwsContainer *  pContainer=&((pHeapObj_1)->m_oBase_CAwsContainer);
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pContainer->m_oBase_CAwsWindow),pParent,rect,0,1);

	return pContainer;
}}}
}

const VTab_CAwsWindow g_tVTab_CTabPage5_CAwsWindow = {CTabPage5_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CTabPage5_OnDraw_CEspRect1p, CTabPage5_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CTabPage5_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CTabPage5_OnCreate};
void CTabPage5_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CTabPage5* pThis=(CTabPage5*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CTabPage5*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CTabPage5_CInit(CTabPage5* pThis)
{

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CTabPage5_CAwsWindow;
{
	pThis->m_pLabel=ESP_NULL;
	pThis->m_pComboBox=ESP_NULL;

	pThis->m_pEditLabel=ESP_NULL;
	pThis->m_pEdit=ESP_NULL;
}
}

void CTabPage5_OnCreate(CAwsWindow* this)
{

	CTabPage5* pThis = (CTabPage5*)this;{
	CAwsString str;
	CEspRect rtLabel,rtComboBox,rtEditLabel,rtEdit;
	CAwsRgb rgbLText,rgbELText;

	{CBLabel(*pHeapObj_1)=(CBLabel(*))malloc(sizeof(CBLabel));
CBLabel_CInit(pHeapObj_1);
{CAwsString_CInit_i0p(&(str),100);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtLabel,105,20,205,40);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtComboBox,90,45,160,66);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtEditLabel,105,85,205,105);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtEdit,60,110,190,130);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbLText,173,154,132);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbELText,173,154,132);
pThis->m_pLabel=pHeapObj_1;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pLabel->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtLabel),0,1);
	CAwsString_LoadString_i0p(&(str),StringID_ComboBox);
	CAwsWindow_SetBKTransparent_i0p(&(pThis->m_pLabel->m_oBase_CAwsWindow),1);
	CBLabel_SetTextColor_CAwsRgb1p_i0p(pThis->m_pLabel,&(rgbLText),0);
	CBLabel_SetText_CAwsString1p_i0p(pThis->m_pLabel,&(str),0);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pLabel)->m_oBase_CAwsWindow),0);

	{CBComboBox*pHeapObj_2=(CBComboBox(*))malloc(sizeof(CBComboBox));
CBComboBox_CInit_i0p(pHeapObj_2,10);
{pThis->m_pComboBox=pHeapObj_2;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pComboBox->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtComboBox),0,1);
	{int i;
	for(i=0;i<5;++i){
	{
		CAwsString_LoadString_i0p(&(str),i);
		CBComboBox_AddItem_CAwsString1p(pThis->m_pComboBox,&(str));
	}}

	{CBLabel(*pHeapObj_3)=(CBLabel(*))malloc(sizeof(CBLabel));
CBLabel_CInit(pHeapObj_3);
{pThis->m_pEditLabel=pHeapObj_3;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pEditLabel->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtEditLabel),0,1);
	CAwsString_LoadString_i0p(&(str),StringID_Edit);
	CAwsWindow_SetBKTransparent_i0p(&(pThis->m_pEditLabel->m_oBase_CAwsWindow),1);
	CBLabel_SetTextColor_CAwsRgb1p_i0p(pThis->m_pEditLabel,&(rgbELText),0);
	CBLabel_SetText_CAwsString1p_i0p(pThis->m_pEditLabel,&(str),0);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pEditLabel)->m_oBase_CAwsWindow),0);

	{CBEdit(*pHeapObj_4)=(CBEdit(*))malloc(sizeof(CBEdit));
CBEdit_CInit(pHeapObj_4);
{pThis->m_pEdit=pHeapObj_4;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pEdit->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtEdit),0,1);
//	CAwsString strTB;
//	char* p = "abcd我们好的efghijk";
//	strTB.SetData(p, strlen(p));
//	m_pEdit->SetDefaultString(strTB);
	{CAwsRgb rgbEBorder,rgbEFocusBorder,rgbEBK,rgbEText,rgbECaret;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbEBorder,123,123,123);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbEFocusBorder,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbEBK,67,67,67);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbEText,168,155,131);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbECaret,255,255,255);
CBEdit_SetBorderColor_CAwsRgb1p(pThis->m_pEdit,&(rgbEBorder));
	CBEdit_SetFocusBorderColor_CAwsRgb1p(pThis->m_pEdit,&(rgbEFocusBorder));
	CBEdit_SetBKColor_CAwsRgb1p(pThis->m_pEdit,&(rgbEBK));
	CBEdit_SetTextColor_CAwsRgb1p(pThis->m_pEdit,&(rgbEText));
	CBEdit_SetCaretColor_CAwsRgb1p(pThis->m_pEdit,&(rgbECaret));

	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pEdit)->m_oBase_CAwsWindow),1);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pComboBox)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),1);
}}}}}}}}}}CAwsString_DUninit_i1p(&(str), 0);
}
}

void CTabPage5_OnFocus_i0p(CAwsWindow* this, int bIsFocus)
{

	CTabPage5* pThis = (CTabPage5*)this;{
	CAwsContainer_OnFocus_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),bIsFocus);
}
}

int CTabPage5_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CTabPage5* pThis = (CTabPage5*)this;{
	int bRet=CAwsContainer_OnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);

	if(!bRet){
	{
		if(AWS_Key==type){
		{
			switch(code)
			{
			case AWS_KeyCode_UpArrow:
				if(pThis->m_oBase_CAwsContainer.m_nFocusWndCount-1==pThis->m_oBase_CAwsContainer.m_nFocusWndIndex){
				{
					// 发送消息给TabView，说明要切换到TabPanel
					CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_TabViewSetPanelFocus,0,0);
				}}
				else
				{{
					CAwsContainer_PreFocusWnd(&(pThis->m_oBase_CAwsContainer));
				}}

				break;

			case AWS_KeyCode_DownArrow:
				CAwsContainer_NextFocusWnd(&(pThis->m_oBase_CAwsContainer));
				break;
			}
		}}
	}}

	return bRet;
}
}

void CTabPage5_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CTabPage5* pThis = (CTabPage5*)this;{
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
