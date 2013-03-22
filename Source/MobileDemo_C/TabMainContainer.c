/******************************************************************************
* FileName		       : TabMainContainer.cpp
* Description          : implementation of the CTabMainContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "TabMainContainer.h"

#include "BTitleBar.h"
#include "MMenuBar.h"

#include "AwsUserDefine.h"
#include "IAwsGc.h"
#include "MUi.h"
#include "BMenu.h"
#include "MMenuBar.h"
#include "BTabView.h"
#include "BTabPanel.h"
#include "BSelectBox.h"
#include "TabPage1.h"
#include "TabPage2.h"
#include "TabPage3.h"
#include "TabPage4.h"
#include "TabPage5.h"
#include "TabPage6.h"

const VTab_IAwsContainerBuilder g_tVTab_CTabMainContainerBuilder_IAwsContainerBuilder = {CTabMainContainerBuilder_Build_CAwsWindow1p_CEspRect1p};
void CTabMainContainerBuilder_CInit(CTabMainContainerBuilder* pThis)
{

	pThis->m_oBase_IAwsContainerBuilder.m_pVTab = &g_tVTab_CTabMainContainerBuilder_IAwsContainerBuilder;
}

CAwsContainer * CTabMainContainerBuilder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent,const CEspRect * rect)
{

	CTabMainContainerBuilder* pThis = (CTabMainContainerBuilder*)this;{
	{CTabMainContainer*pHeapObj_1=(CTabMainContainer(*))malloc(sizeof(CTabMainContainer));
CTabMainContainer_CInit(pHeapObj_1);
{CAwsContainer *  pContainer=&((pHeapObj_1)->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer);
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pContainer->m_oBase_CAwsWindow),pParent,rect,0,1);

	return pContainer;
}}}
}

const VTab_CAwsWindow g_tVTab_CTabMainContainer_CAwsWindow = {CTabMainContainer_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CMMainContainer_OnDraw_CEspRect1p, CTabMainContainer_OnKey_0p_0p, CTabMainContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CTabMainContainer_OnCommand_i0p_i0p_i0p_i0p, CTabMainContainer_OnCreate};
const VTab_CMMainContainer g_tVTab_CTabMainContainer_CMMainContainer = {CTabMainContainer_OnActive, CTabMainContainer_InActive, CTabMainContainer_OnLeftMenu, CTabMainContainer_OnRightMenu};
const VTab_CBMenuContainer g_tVTab_CTabMainContainer_CBMenuContainer = {CTabMainContainer_PopMenu_i0p_CEspPoint1p};
void CTabMainContainer_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CTabMainContainer* pThis=(CTabMainContainer*)this;
	pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	pThis->m_oBase_CMMainContainer.m_pVTab = &g_tVTab_CMMainContainer_CMMainContainer;
	CMMainContainer_DUninit_i1p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CTabMainContainer*)0)->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CTabMainContainer_CInit(CTabMainContainer* pThis) {

CMMainContainer_CInit_i0p(&(pThis->m_oBase_CMMainContainer),30);
	pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CTabMainContainer_CAwsWindow;
	pThis->m_oBase_CMMainContainer.m_pVTab = &g_tVTab_CTabMainContainer_CMMainContainer;
	pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_pVTab = &g_tVTab_CTabMainContainer_CBMenuContainer;
{
	pThis->m_pTabView=ESP_NULL;
	CAwsString_LoadString_i0p(&(pThis->m_oBase_CMMainContainer.m_strLeftMenu),StringID_Menu);
	CAwsString_LoadString_i0p(&(pThis->m_oBase_CMMainContainer.m_strRightMenu),StringID_Return);
}
}

void CTabMainContainer_OnCreate(CAwsWindow* this)
{

	CTabMainContainer* pThis = (CTabMainContainer*)this;{
	CAwsContainer_OnCreate(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow));
	
	{CAwsString str;
	CAwsImage imageBK;
	CEspSize imageSize;
	CBTitleBar *  pTitleBar=CMUi_GetTitleBar(CMMainContainer_GetMUi(&(pThis->m_oBase_CMMainContainer)));
	CAwsString_CInit_i0p(&(str),100);
CAwsImage_CInit(&(imageBK));
CEspSize_CInit_i0p_i0p(&(imageSize),0,0);
CAwsString_LoadString_i0p(&(str),StringID_TitleBar);
	CBTitleBar_SetCaption_CAwsString1p(pTitleBar,&(str));
	imageSize.m_nHeight=24;
	imageSize.m_nWidth=2;
	CAwsImage_LoadImage_i0p(&(imageBK),IDB_TITLEBAR);
	CBTitleBar_SetBKImage_CAwsImage1p_CEspSize1p(pTitleBar,&(imageBK),&(imageSize));
	
	CAwsImage_LoadImage_i0p(&(imageBK),IDB_TITLEICON);
	{CAwsImage imageMask;
	CAwsImage_CInit(&(imageMask));
CAwsImage_LoadImage_i0p(&(imageMask),IDB_TITLEMASK);
	{CEspSize size;
	CEspSize_CInit_i0p_i0p(&size,33,20);
CBTitleBar_SetIcon_CAwsImage1p_CEspSize1p_CAwsImage1p(pTitleBar,&(imageBK),&(size),&imageMask);
	
	imageSize.m_nHeight=24;
	imageSize.m_nWidth=2;
	CAwsImage_LoadImage_i0p(&(imageBK),IDB_MENUBAR);
	{CMMenuBar *  pMenuBar=CMUi_GetMenuBar(CMMainContainer_GetMUi(&(pThis->m_oBase_CMMainContainer)));
	if(ESP_NULL!=pMenuBar){
	{
		CMMenuBar_SetBKImage_CAwsImage1p_CEspSize1p(pMenuBar,&(imageBK),&(imageSize));
		CMMainContainer_UpdateMenuBar_0p_0p_i0p(&(pThis->m_oBase_CMMainContainer),StringID_Menu,StringID_Return,0);
	}}

	// 创建TabView
	{CBTabView(*pHeapObj_1)=(CBTabView(*))malloc(sizeof(CBTabView));
CBTabView_CInit(pHeapObj_1);
{pThis->m_pTabView=pHeapObj_1;
	{CEspRect rt;
	CEspRect_CInit_i0p_i0p_i0p_i0p(&rt,0,0,CAwsWindow_GetSize(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow))->m_nWidth,CAwsWindow_GetSize(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow))->m_nHeight);
CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pTabView->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&((pThis)->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt),0,1);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer),&((pThis->m_pTabView)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),1);
	{CTabPage1Builder*pHeapObj_2=(CTabPage1Builder(*))malloc(sizeof(CTabPage1Builder));
CTabPage1Builder_CInit(pHeapObj_2);
{CBTabView_RegisterMainContainer_IAwsContainerBuilder1p(pThis->m_pTabView,&((pHeapObj_2)->m_oBase_IAwsContainerBuilder));
	{CTabPage2Builder*pHeapObj_3=(CTabPage2Builder(*))malloc(sizeof(CTabPage2Builder));
CTabPage2Builder_CInit(pHeapObj_3);
{CBTabView_RegisterMainContainer_IAwsContainerBuilder1p(pThis->m_pTabView,&((pHeapObj_3)->m_oBase_IAwsContainerBuilder));
	{CTabPage3Builder*pHeapObj_4=(CTabPage3Builder(*))malloc(sizeof(CTabPage3Builder));
CTabPage3Builder_CInit(pHeapObj_4);
{CBTabView_RegisterMainContainer_IAwsContainerBuilder1p(pThis->m_pTabView,&((pHeapObj_4)->m_oBase_IAwsContainerBuilder));
	{CTabPage4Builder*pHeapObj_5=(CTabPage4Builder(*))malloc(sizeof(CTabPage4Builder));
CTabPage4Builder_CInit(pHeapObj_5);
{CBTabView_RegisterMainContainer_IAwsContainerBuilder1p(pThis->m_pTabView,&((pHeapObj_5)->m_oBase_IAwsContainerBuilder));
	{CTabPage5Builder*pHeapObj_6=(CTabPage5Builder(*))malloc(sizeof(CTabPage5Builder));
CTabPage5Builder_CInit(pHeapObj_6);
{CBTabView_RegisterMainContainer_IAwsContainerBuilder1p(pThis->m_pTabView,&((pHeapObj_6)->m_oBase_IAwsContainerBuilder));
	{CTabPage6Builder*pHeapObj_7=(CTabPage6Builder(*))malloc(sizeof(CTabPage6Builder));
CTabPage6Builder_CInit(pHeapObj_7);
{CBTabView_RegisterMainContainer_IAwsContainerBuilder1p(pThis->m_pTabView,&((pHeapObj_7)->m_oBase_IAwsContainerBuilder));
	CBTabView_SwitchContainer_i0p(pThis->m_pTabView,0);

	// 设置TabPanel参数
	{CAwsImage imageBKMask;
	CBTabPanel *  pTabPanel=CBTabView_GetTabPanel(pThis->m_pTabView);
	CAwsImage_CInit(&(imageBKMask));
CAwsImage_LoadImage_i0p(&(imageBK),IDB_TABPANELBK);
	CBTabPanel_SetBKImage_CAwsImage1p(pTabPanel,&(imageBK));

	// 设置pSelectBox参数
	{CBSelectBox *  pSelectBox=CBTabPanel_GetSelectBox(pTabPanel);
	CAwsImage_LoadImage_i0p(&(imageBK),IDB_TABITEMSELBK);
	CAwsImage_LoadImage_i0p(&(imageBKMask),IDB_TABITEMSELBKMASK);
	CBSelectBox_SetSelectImage_CAwsImage1p_CAwsImage1p(pSelectBox,&(imageBK),&(imageBKMask));
	CAwsWindow_SetBKTransparent_i0p(&(pSelectBox->m_oBase_CAwsWindow),1);

	{CEspSize sizeItemRegion;
	CEspRect rtMoveTo;
	CAwsRgb rgbText,rgbFocusText,rgbArrow;
	CEspSize_CInit_i0p_i0p(&sizeItemRegion,41,24);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtMoveTo,55,27,239,50);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,173,154,132);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbFocusText,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbArrow,255,255,255);
CBSelectBox_SetItemRegionSize_CEspSize1p(pSelectBox,&(sizeItemRegion));
	CAwsWindow_MoveTo_CEspRect1p_i0p(&(pSelectBox->m_oBase_CAwsWindow),&(rtMoveTo),1);
	CBSelectBox_SetTextColor_CAwsRgb1p(pSelectBox,&(rgbText));
	CBSelectBox_SetFocusTextColor_CAwsRgb1p(pSelectBox,&(rgbFocusText));
	CBSelectBox_SetArrowColor_CAwsRgb1p(pSelectBox,&(rgbArrow));

	{int i;
	for(i=0;i<6;++i){
	{
		CAwsString_LoadString_i0p(&(str),i);
		CBSelectBox_AddItem_CAwsString1p(pSelectBox,&(str));
	}}
	CBSelectBox_AddItemEnd(pSelectBox);
}}}}}}}}}}}}}}}}}}}}}}CAwsString_DUninit_i1p(&(str), 0);
}}
}

void CTabMainContainer_InActive(CMMainContainer* this)
{

	CTabMainContainer* pThis = (CTabMainContainer*)this;{
	pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pOnFocus_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),0);
}
}

void CTabMainContainer_OnActive(CMMainContainer* this)
{

	CTabMainContainer* pThis = (CTabMainContainer*)this;{
	CMMainContainer_UpdateMenuBar_0p_0p_i0p(&(pThis->m_oBase_CMMainContainer),StringID_Menu,StringID_Return,0);
}
}

int CTabMainContainer_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CTabMainContainer* pThis = (CTabMainContainer*)this;{
	switch(nCmdID)
	{
	case AWS_SysCmd_MenuCmd:
		if(AWS_MenuID_Left==nWndID){
		{
			switch(nParam1)
			{
			case 0:
				CAwsWindow_PostCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,EWndID_Msg_ChangeMainContainer,0,0);
				break;
			}
		}}
		break;

	case AWS_SysCmd_MsgBox_OK:
		if(EWndID_Msg_Selected==nWndID){
		{
			CMMainContainer_UpdateMenuBar_0p_0p_i0p(&(pThis->m_oBase_CMMainContainer),StringID_Menu,StringID_Return,1);
		}}
		break;

	case AWS_SysCmd_MenuDestroy:
		// 改变菜单条的显示
		if(ESP_NULL!=CMUi_GetMenuBar(CMMainContainer_GetMUi(&(pThis->m_oBase_CMMainContainer)))){
		{
			CMMainContainer_UpdateMenuBar_0p_0p_i0p(&(pThis->m_oBase_CMMainContainer),StringID_Menu,StringID_Return,1);
		}}
		break;

	case EWndID_Msg_ChangeMainContainer:
		CMUi_ChangeMainContainer_i0p_i0p_i0p_i0p(CMMainContainer_GetMUi(&(pThis->m_oBase_CMMainContainer)),MyMainContainerID,0,0,0);
		break;
	}

	return CBMenuContainer_OnCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),nWndID,nCmdID,nParam1,nParam2);
}
}

int CTabMainContainer_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CTabMainContainer* pThis = (CTabMainContainer*)this;{
	return CMMainContainer_OnKey_0p_0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);
}
}

void CTabMainContainer_OnSize_CEspSize1p_i0p(CAwsWindow* this, const CEspSize * size,int bIsRedraw)
{

	CTabMainContainer* pThis = (CTabMainContainer*)this;{
	CAwsContainer_OnSize_CEspSize1p_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),size,bIsRedraw);

	if(ESP_NULL!=pThis->m_pTabView){
	{
		CEspRect rt;
		CEspRect_CInit_i0p_i0p_i0p_i0p(&rt,0,0,size->m_nWidth,size->m_nHeight);
CAwsWindow_MoveTo_CEspRect1p_i0p(&(pThis->m_pTabView->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt),bIsRedraw);
	}}
}
}

void CTabMainContainer_OnLeftMenu(CMMainContainer* this)
{

	CTabMainContainer* pThis = (CTabMainContainer*)this;{
	CMMenuBar *  pMenuBar=CMUi_GetMenuBar(CMMainContainer_GetMUi(&(pThis->m_oBase_CMMainContainer)));
	if(ESP_NULL!=pMenuBar){
	{
		CMMainContainer_UpdateMenuBar_0p_0p_i0p(&(pThis->m_oBase_CMMainContainer),StringID_Select,StringID_Cancel,1);
	}}

	{CEspPoint pt;
	CEspPoint_CInit_i0p_i0p(&(pt),0,0);
pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_pVTab->m_pPopMenu_i0p_CEspPoint1p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer),AWS_MenuID_Left,&(pt));
}}
}

void CTabMainContainer_OnRightMenu(CMMainContainer* this)
{

	CTabMainContainer* pThis = (CTabMainContainer*)this;{
	CAwsWindow_PostCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,EWndID_Msg_ChangeMainContainer,0,0);
}
}

void CTabMainContainer_PopMenu_i0p_CEspPoint1p(CBMenuContainer* this, int nMenuID,const CEspPoint * pt)
{

	CTabMainContainer* pThis = (CTabMainContainer*)this;{
	switch(nMenuID)
	{
	case AWS_MenuID_Left:
		{
			{CBMenu*pHeapObj_1=(CBMenu(*))malloc(sizeof(CBMenu));
CBMenu_CInit_CAwsWindow1p_i0p_i0p_i0p(pHeapObj_1,&((pThis)->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),15,0,0);
{CBMenu *  pMenu=pHeapObj_1;
			CAwsString str;
			CAwsString_CInit_i0p(&(str),100);
CAwsString_LoadString_i0p(&(str),StringID_Menu_ReturnMainPage);
			CBMenu_AddItem_CAwsString1p_i0p(pMenu,&(str),0);
			CBMenu_AddItemEnd(pMenu);

			{CEspRect rect;
			CEspRect_CInit(&(rect));
CMMainContainer_AdjustMenuPos_CBMenu1p_CEspRect1p_CEspPoint1p_i0p(&(pThis->m_oBase_CMMainContainer),pMenu,&(rect),pt,0);
			CAwsContainer_PopWnd_CAwsWindow1p_CEspRect1p_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer),&((pMenu)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rect),AWS_MenuID_Left);
		}CAwsString_DUninit_i1p(&(str), 0);
}}}
		break;
	}
}
}
