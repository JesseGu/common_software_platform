/******************************************************************************
* FileName		       : TabPage3.cpp
* Description          : implementation of the CTabPage3 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "TabPage3.h"
#include "AwsUserDefine.h"
#include "IAwsGc.h"
#include "BButton.h"
#include "BImageButton.h"
#include "BRadioBox.h"
#include "BCheckBox.h"
#include "MMsgBox.h"

const VTab_IAwsContainerBuilder g_tVTab_CTabPage3Builder_IAwsContainerBuilder = {CTabPage3Builder_Build_CAwsWindow1p_CEspRect1p};
void CTabPage3Builder_CInit(CTabPage3Builder* pThis)
{

	pThis->m_oBase_IAwsContainerBuilder.m_pVTab = &g_tVTab_CTabPage3Builder_IAwsContainerBuilder;
}

CAwsContainer * CTabPage3Builder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent,const CEspRect * rect)
{

	CTabPage3Builder* pThis = (CTabPage3Builder*)this;{
	{CTabPage3(*pHeapObj_1)=(CTabPage3(*))malloc(sizeof(CTabPage3));
CTabPage3_CInit(pHeapObj_1);
{CAwsContainer *  pContainer=&((pHeapObj_1)->m_oBase_CAwsContainer);
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pContainer->m_oBase_CAwsWindow),pParent,rect,0,1);

	return pContainer;
}}}
}

const VTab_CAwsWindow g_tVTab_CTabPage3_CAwsWindow = {CTabPage3_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CTabPage3_OnDraw_CEspRect1p, CTabPage3_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CTabPage3_OnCommand_i0p_i0p_i0p_i0p, CTabPage3_OnCreate};
void CTabPage3_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CTabPage3* pThis=(CTabPage3*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CTabPage3*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CTabPage3_CInit(CTabPage3* pThis)
{

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CTabPage3_CAwsWindow;
{
	pThis->m_pButton=ESP_NULL;
	pThis->m_pImageButton=ESP_NULL;
	pThis->m_pRadioBox=ESP_NULL;
	pThis->m_pCheckBox=ESP_NULL;
}
}

void CTabPage3_OnCreate(CAwsWindow* this)
{

	CTabPage3* pThis = (CTabPage3*)this;{
	CAwsString str;

	CEspRect rtRadioBox,rtCheckBox,rtImageButton,rtButton;
	CAwsRgb rgbRBText,rgbRBTextFocus,rgbCBText,rgbCBTextFocus,rgbIBText;
	CEspSize sizeRB,sizeCB,sizeIB;

	{CBRadioBox(*pHeapObj_1)=(CBRadioBox(*))malloc(sizeof(CBRadioBox));
CBRadioBox_CInit(pHeapObj_1);
{CAwsString_CInit_i0p(&(str),100);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtRadioBox,90,60,150,80);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtCheckBox,90,90,150,110);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtImageButton,90,120,150,180);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtButton,90,20,150,40);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbRBText,173,154,132);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbRBTextFocus,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbCBText,173,154,132);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbCBTextFocus,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbIBText,168,155,131);
CEspSize_CInit_i0p_i0p(&sizeRB,15,15);
CEspSize_CInit_i0p_i0p(&sizeCB,16,16);
CEspSize_CInit_i0p_i0p(&sizeIB,40,40);
pThis->m_pRadioBox=pHeapObj_1;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pRadioBox->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtRadioBox),0,1);
	CAwsString_LoadString_i0p(&(str),StringID_RadioBox);
	CBButton_SetText_CAwsString1p(&(pThis->m_pRadioBox->m_oBase_CBImageButton.m_oBase_CBButton),&(str));
	CBButton_SetTextColor_CAwsRgb1p(&(pThis->m_pRadioBox->m_oBase_CBImageButton.m_oBase_CBButton),&(rgbRBText));
	CBButton_SetTextFocusColor_CAwsRgb1p(&(pThis->m_pRadioBox->m_oBase_CBImageButton.m_oBase_CBButton),&(rgbRBTextFocus));
	{CAwsImage image,imageFocus,imageSel,imageSelFocus,imageMask;
	CAwsImage_CInit(&(image));
CAwsImage_CInit(&(imageFocus));
CAwsImage_CInit(&(imageSel));
CAwsImage_CInit(&(imageSelFocus));
CAwsImage_CInit(&(imageMask));
CAwsImage_LoadImage_i0p(&(image),IDB_RADIO);
	CAwsImage_LoadImage_i0p(&(imageFocus),IDB_RADIOFOCUS);
	CAwsImage_LoadImage_i0p(&(imageSel),IDB_RADIOSEL);
	CAwsImage_LoadImage_i0p(&(imageSelFocus),IDB_RADIOSELFOCUS);
	CAwsImage_LoadImage_i0p(&(imageMask),IDB_RADIOMASK);
	CBRadioBox_SetImage_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p(pThis->m_pRadioBox,&(image),&(imageFocus),&(imageSel),&(imageSelFocus),&(imageMask));
	CBImageButton_SetIconSize_CEspSize1p(&(pThis->m_pRadioBox->m_oBase_CBImageButton),&(sizeRB));
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pRadioBox)->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow),1);

	{CBCheckBox(*pHeapObj_2)=(CBCheckBox(*))malloc(sizeof(CBCheckBox));
CBCheckBox_CInit(pHeapObj_2);
{pThis->m_pCheckBox=pHeapObj_2;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pCheckBox->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtCheckBox),0,1);
	CAwsString_LoadString_i0p(&(str),StringID_CheckBox);
	CBButton_SetText_CAwsString1p(&(pThis->m_pCheckBox->m_oBase_CBImageButton.m_oBase_CBButton),&(str));
	CBButton_SetTextColor_CAwsRgb1p(&(pThis->m_pCheckBox->m_oBase_CBImageButton.m_oBase_CBButton),&(rgbCBText));
	CBButton_SetTextFocusColor_CAwsRgb1p(&(pThis->m_pCheckBox->m_oBase_CBImageButton.m_oBase_CBButton),&(rgbCBTextFocus));
	CAwsImage_LoadImage_i0p(&(image),IDB_CHECK);
	CAwsImage_LoadImage_i0p(&(imageFocus),IDB_CHECKFOCUS);
	CAwsImage_LoadImage_i0p(&(imageSel),IDB_CHECKSEL);
	CAwsImage_LoadImage_i0p(&(imageSelFocus),IDB_CHECKSELFOCUS);
	CAwsImage_LoadImage_i0p(&(imageMask),IDB_CHECKMASK);
	CBCheckBox_SetImage_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p(pThis->m_pCheckBox,&(image),&(imageFocus),&(imageSel),&(imageSelFocus),&(imageMask));
	CBImageButton_SetIconSize_CEspSize1p(&(pThis->m_pCheckBox->m_oBase_CBImageButton),&(sizeCB));
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pCheckBox)->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow),1);

	{CBImageButton(*pHeapObj_3)=(CBImageButton(*))malloc(sizeof(CBImageButton));
CBImageButton_CInit(pHeapObj_3);
{pThis->m_pImageButton=pHeapObj_3;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pImageButton->m_oBase_CBButton.m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtImageButton),EWndID_Button2,1);
	CBImageButton_SetMode_0p(pThis->m_pImageButton,MIBMode_IconTop);
	CAwsImage_LoadImage_i0p(&(image),IDB_MAIN1);
	CAwsImage_LoadImage_i0p(&(imageMask),IDB_MAINMASK);
	CBImageButton_SetImage_CAwsImage1p_CAwsImage1p(pThis->m_pImageButton,&(image),&(imageMask));
	CAwsString_LoadString_i0p(&(str),StringID_Button);
	CBButton_SetText_CAwsString1p(&(pThis->m_pImageButton->m_oBase_CBButton),&(str));
	CAwsWindow_SetBKTransparent_i0p(&(pThis->m_pImageButton->m_oBase_CBButton.m_oBase_CAwsWindow),1);
	CBImageButton_SetIconSize_CEspSize1p(pThis->m_pImageButton,&(sizeIB));
	CBButton_SetTextColor_CAwsRgb1p(&(pThis->m_pImageButton->m_oBase_CBButton),&(rgbIBText));
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pImageButton)->m_oBase_CBButton.m_oBase_CAwsWindow),1);

	{CBButton(*pHeapObj_4)=(CBButton(*))malloc(sizeof(CBButton));
CBButton_CInit(pHeapObj_4);
{pThis->m_pButton=pHeapObj_4;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pButton->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtButton),EWndID_Button1,1);
	CAwsString_LoadString_i0p(&(str),StringID_Button);
	CBButton_SetText_CAwsString1p(pThis->m_pButton,&(str));
//	m_pButton->SetTextColor(CAwsRgb(173, 154, 132));
//	m_pButton->SetTextFocusColor(CAwsRgb(255, 255, 255));
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pButton)->m_oBase_CAwsWindow),1);
}}}}}}}}}CAwsString_DUninit_i1p(&(str), 0);
}
}

int CTabPage3_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CTabPage3* pThis = (CTabPage3*)this;{
	if(AWS_SysCmd_ButtonCmd==nCmdID){
	{
		if(EWndID_Button1==nWndID||EWndID_Button2==nWndID){
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
	}}

	return CAwsWindow_OnCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),nWndID,nCmdID,nParam1,nParam2);
}
}

int CTabPage3_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CTabPage3* pThis = (CTabPage3*)this;{
	int bRet=CAwsContainer_OnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);

	if(!bRet){
	{
		if(AWS_Key==type){
		{
			switch(code)
			{
			case AWS_KeyCode_UpArrow:
				CAwsContainer_PreFocusWnd(&(pThis->m_oBase_CAwsContainer));
				bRet=1;
				break;

			case AWS_KeyCode_DownArrow:
				CAwsContainer_NextFocusWnd(&(pThis->m_oBase_CAwsContainer));
				bRet=1;
				break;
			}
		}}
	}}

	return bRet;
}
}

void CTabPage3_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CTabPage3* pThis = (CTabPage3*)this;{
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
