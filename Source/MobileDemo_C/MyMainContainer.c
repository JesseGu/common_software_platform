/******************************************************************************
* FileName		       : MyMainContainer.cpp
* Description          : implementation of the CMyMainContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "MyMainContainer.h"

#include "BMenu.h"
#include "AwsUserDefine.h"
#include "MUi.h"
#include "AwsUi.h"
#include "MMenuBar.h"

#include "BTitleBar.h"
#include "MMenuBar.h"
#include "BScrollBar.h"
#include "MMsgBox.h"
#include "BListView.h"

const VTab_IAwsContainerBuilder g_tVTab_CMyMainContainerBuilder_IAwsContainerBuilder = {CMyMainContainerBuilder_Build_CAwsWindow1p_CEspRect1p};
void CMyMainContainerBuilder_CInit(CMyMainContainerBuilder* pThis)
{

	pThis->m_oBase_IAwsContainerBuilder.m_pVTab = &g_tVTab_CMyMainContainerBuilder_IAwsContainerBuilder;
}

CAwsContainer * CMyMainContainerBuilder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent,const CEspRect * rect)
{

	CMyMainContainerBuilder* pThis = (CMyMainContainerBuilder*)this;{
	{CMyMainContainer*pHeapObj_1=(CMyMainContainer(*))malloc(sizeof(CMyMainContainer));
CMyMainContainer_CInit(pHeapObj_1);
{CAwsContainer *  pContainer=&((pHeapObj_1)->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer);
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pContainer->m_oBase_CAwsWindow),pParent,rect,0,1);

	return pContainer;
}}}
}

const VTab_CAwsWindow g_tVTab_CMyMainContainer_CAwsWindow = {CMyMainContainer_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CMMainContainer_OnDraw_CEspRect1p, CMyMainContainer_OnKey_0p_0p, CMyMainContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CMyMainContainer_OnCommand_i0p_i0p_i0p_i0p, CMyMainContainer_OnCreate};
const VTab_CMMainContainer g_tVTab_CMyMainContainer_CMMainContainer = {CMyMainContainer_OnActive, CMyMainContainer_InActive, CMyMainContainer_OnLeftMenu, CMyMainContainer_OnRightMenu};
const VTab_CBMenuContainer g_tVTab_CMyMainContainer_CBMenuContainer = {CMyMainContainer_PopMenu_i0p_CEspPoint1p};
void CMyMainContainer_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CMyMainContainer* pThis=(CMyMainContainer*)this;
	pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	pThis->m_oBase_CMMainContainer.m_pVTab = &g_tVTab_CMMainContainer_CMMainContainer;
	CMMainContainer_DUninit_i1p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMyMainContainer*)0)->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CMyMainContainer_CInit(CMyMainContainer* pThis) {

CMMainContainer_CInit_i0p(&(pThis->m_oBase_CMMainContainer),30);
	pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CMyMainContainer_CAwsWindow;
	pThis->m_oBase_CMMainContainer.m_pVTab = &g_tVTab_CMyMainContainer_CMMainContainer;
	pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_pVTab = &g_tVTab_CMyMainContainer_CBMenuContainer;
{
	pThis->m_pScrollBar=ESP_NULL;
	pThis->m_nScrollTotalLength=10;
	pThis->m_nScrollPos=0;

	pThis->m_pListView=ESP_NULL;
}
}

void CMyMainContainer_OnCreate(CAwsWindow* this)
{

	CMyMainContainer* pThis = (CMyMainContainer*)this;{
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
		CMMainContainer_UpdateMenuBar_0p_0p_i0p(&(pThis->m_oBase_CMMainContainer),StringID_Menu,StringID_Exit,0);
	}}

	{CBListView*pHeapObj_1=(CBListView(*))malloc(sizeof(CBListView));
CBListView_CInit_i0p(pHeapObj_1,30);
{pThis->m_pListView=pHeapObj_1;
	{CEspRect rect;
	CEspRect_CInit_i0p_i0p_i0p_i0p(&rect,0,0,CAwsWindow_GetSize(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow))->m_nWidth,CAwsWindow_GetSize(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow))->m_nHeight);
CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pListView->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&((pThis)->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rect),0,1);
	{int i;
	int nImageIndex=133;
	CAwsImage iconMask;
	CAwsImage_CInit(&(iconMask));
CAwsImage_LoadImage_i0p(&(iconMask),IDB_MAINMASK);
	{CAwsImage iconSmall,iconBig;
	CAwsImage_CInit(&(iconSmall));
CAwsImage_CInit(&(iconBig));
for(i=0;i<12;++i){
	{
		CAwsString_LoadString_i0p(&(str),i);
		CAwsImage_LoadImage_i0p(&(iconSmall),nImageIndex);
		CAwsImage_LoadImage_i0p(&(iconBig),nImageIndex++);
		CBListView_AddItem_CAwsString1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_i0p(pThis->m_pListView,&(str),&(iconSmall),&(iconBig),&iconMask,&iconMask,0);
	}}
	nImageIndex=133;
	for(i=0;i<8;++i){
	{
		CAwsString_LoadString_i0p(&(str),i);
		CAwsImage_LoadImage_i0p(&(iconSmall),nImageIndex);
		CAwsImage_LoadImage_i0p(&(iconBig),nImageIndex++);
		CBListView_AddItem_CAwsString1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_i0p(pThis->m_pListView,&(str),&(iconSmall),&(iconBig),&iconMask,&iconMask,0);
	}}
	CAwsString_LoadString_i0p(&(str),10);
	CAwsImage_LoadImage_i0p(&(iconBig),133);
	CAwsImage_LoadImage_i0p(&(iconSmall),133);
	CBListView_AddItem_CAwsString1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_i0p(pThis->m_pListView,&(str),&(iconSmall),&(iconBig),&iconMask,&iconMask,1);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer),&((pThis->m_pListView)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),1);
}}}}}}}}CAwsString_DUninit_i1p(&(str), 0);
}}
}

void CMyMainContainer_InActive(CMMainContainer* this)
{

	CMyMainContainer* pThis = (CMyMainContainer*)this;{
	pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pOnFocus_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),0);
}
}

void CMyMainContainer_OnActive(CMMainContainer* this)
{

	CMyMainContainer* pThis = (CMyMainContainer*)this;{
	CMMainContainer_UpdateMenuBar_0p_0p_i0p(&(pThis->m_oBase_CMMainContainer),StringID_Menu,StringID_Exit,0);
}
}

int CMyMainContainer_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CMyMainContainer* pThis = (CMyMainContainer*)this;{
	// 命令解析
	switch(nCmdID)
	{
	case AWS_SysCmd_MenuCmd:
		if(AWS_MenuID_Left==nWndID){
		{
			switch(nParam1)
			{
			case 0:
				// 打开
				return pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pOnCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),0,AWS_SysCmd_ListViewCmd,0,0);
				break;
				
			case 1:
				// 删除当前项
				{
					{CMMsgBox*pHeapObj_1=(CMMsgBox(*))malloc(sizeof(CMMsgBox));
CMMsgBox_CInit_CAwsWindow1p_i0p(pHeapObj_1,&((pThis)->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),EWndID_Msg_DeleteItem);
{CMMsgBox *  pMsg=pHeapObj_1;
					CAwsString str;
					CAwsString_CInit_i0p(&(str),100);
CAwsString_LoadString_i0p(&(str),StringID_RealDelete);
					CMMsgBox_ShowMsg_0p_CAwsString1p(pMsg,AWS_MBT_OK_Cancel,&(str));
				CAwsString_DUninit_i1p(&(str), 0);
}}}
				break;

			case 2:
				// 视图切换
				break;

			case 3:
				// 改变主容器，此时要Post一个消息
				CAwsWindow_PostCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,EWndID_Msg_ChangeMainContainer,0,0);
				break;
				
			case 4:
				// 退出
				pThis->m_oBase_CMMainContainer.m_pVTab->m_pOnRightMenu(&(pThis->m_oBase_CMMainContainer));
				break;
			}
		}}
		else if(EWndID_Menu1_Sub1==nWndID){
		{
			switch(nParam1)
			{
			case 0:
				CBListView_SetShowMode_0p(pThis->m_pListView,LVShowMode_List);
				break;
				
			case 1:
				CBListView_SetShowMode_0p(pThis->m_pListView,LVShowMode_Icon);
				break;
			}
		}}
		break;

	case AWS_SysCmd_MsgBox_OK:
		if(EWndID_Msg_DeleteItem==nWndID){
		{
			CMMainContainer_UpdateMenuBar_0p_0p_i0p(&(pThis->m_oBase_CMMainContainer),StringID_Menu,StringID_Exit,1);

			// 确定删除
			CBListView_RemoveItem_i0p(pThis->m_pListView,CBListView_GetCurItemIndex(pThis->m_pListView));
		}}
		else if(EWndID_Msg_Selected==nWndID){
		{
			CMMainContainer_UpdateMenuBar_0p_0p_i0p(&(pThis->m_oBase_CMMainContainer),StringID_Menu,StringID_Exit,1);
		}}
		else if(EWndID_Msg_ExitApp==nWndID){
		{
			CAwsWindow_GetUi(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow))->m_pVTab->m_pExitSys(CAwsWindow_GetUi(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow)));
		}}
		break;

	case AWS_SysCmd_MsgBox_Cancel:
		if(EWndID_Msg_DeleteItem==nWndID||EWndID_Msg_ExitApp==nWndID){
		{
			CMMainContainer_UpdateMenuBar_0p_0p_i0p(&(pThis->m_oBase_CMMainContainer),StringID_Menu,StringID_Exit,1);
		}}
		break;

	case AWS_SysCmd_MenuDestroy:
		// 改变菜单条的显示
		CMMainContainer_UpdateMenuBar_0p_0p_i0p(&(pThis->m_oBase_CMMainContainer),StringID_Menu,StringID_Exit,1);
		break;

	case AWS_SysCmd_ListViewCmd:
		{
			{CMMsgBox*pHeapObj_2=(CMMsgBox(*))malloc(sizeof(CMMsgBox));
CMMsgBox_CInit_CAwsWindow1p_i0p(pHeapObj_2,&((pThis)->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),EWndID_Msg_Selected);
{CMMsgBox *  pMsg=pHeapObj_2;
			CAwsString str;
			CAwsString_CInit_i0p(&(str),100);
CAwsString_LoadString_i0p(&(str),StringID_WelcomeUse);
			CMMsgBox_ShowMsg_0p_CAwsString1p(pMsg,AWS_MBT_OK,&(str));
		CAwsString_DUninit_i1p(&(str), 0);
}}}
		break;

	case EWndID_Msg_ChangeMainContainer:
		CMUi_ChangeMainContainer_i0p_i0p_i0p_i0p(CMMainContainer_GetMUi(&(pThis->m_oBase_CMMainContainer)),TabMainContainerID,0,0,0);
		break;
	}

	return CBMenuContainer_OnCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),nWndID,nCmdID,nParam1,nParam2);
}
}

int CMyMainContainer_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CMyMainContainer* pThis = (CMyMainContainer*)this;{
	int bRet=CMMainContainer_OnKey_0p_0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);

	if(!bRet){
	{
		if(AWS_Key==type){
		{
			switch(code)
			{
			case AWS_KeyCode_LeftArrow:
				CAwsContainer_PreFocusWnd(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer));
				bRet=1;
				break;

			case AWS_KeyCode_RightArrow:
				CAwsContainer_NextFocusWnd(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer));
				bRet=1;
				break;

			case AWS_KeyCode_UpArrow:
				if(0==pThis->m_nScrollPos){
				{
					pThis->m_nScrollPos=pThis->m_nScrollTotalLength-1;
				}}
				else
				{{
					--pThis->m_nScrollPos;
				}}
				CBScrollBar_SetCurPos_i0p(pThis->m_pScrollBar,pThis->m_nScrollPos);
				bRet=1;
				break;

			case AWS_KeyCode_DownArrow:
				if(pThis->m_nScrollPos+1<pThis->m_nScrollTotalLength){
				{
					++pThis->m_nScrollPos;
				}}
				else
				{{
					pThis->m_nScrollPos=0;
				}}
				CBScrollBar_SetCurPos_i0p(pThis->m_pScrollBar,pThis->m_nScrollPos);
				bRet=1;
				break;
			}
		}}
	}}

	return bRet;
}
}

void CMyMainContainer_OnSize_CEspSize1p_i0p(CAwsWindow* this, const CEspSize * size,int bIsRedraw)
{

	CMyMainContainer* pThis = (CMyMainContainer*)this;{
	CAwsContainer_OnSize_CEspSize1p_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),size,bIsRedraw);

	{CEspRect rt;
	CEspRect_CInit(&(rt));
rt.m_ptLT.m_nX=size->m_nWidth-10;
	rt.m_ptRB.m_nX=size->m_nWidth;
	rt.m_ptRB.m_nY=size->m_nHeight;

	if(ESP_NULL!=pThis->m_pScrollBar){
	{
		CAwsWindow_MoveTo_CEspRect1p_i0p(&(pThis->m_pScrollBar->m_oBase_CAwsWindow),&(rt),bIsRedraw);
		CBScrollBar_SetTotalLength_i0p(pThis->m_pScrollBar,pThis->m_nScrollTotalLength);
	}}

	if(ESP_NULL!=pThis->m_pListView){
	{
		rt.m_ptLT.m_nX=0;
		rt.m_ptRB.m_nX=size->m_nWidth;
		rt.m_ptRB.m_nY=size->m_nHeight;
		CAwsWindow_MoveTo_CEspRect1p_i0p(&(pThis->m_pListView->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt),bIsRedraw);
	}}
}}
}

void CMyMainContainer_OnLeftMenu(CMMainContainer* this)
{

	CMyMainContainer* pThis = (CMyMainContainer*)this;{
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

void CMyMainContainer_OnRightMenu(CMMainContainer* this)
{

	CMyMainContainer* pThis = (CMyMainContainer*)this;{
	// 退出应用程序
	{CMMsgBox*pHeapObj_1=(CMMsgBox(*))malloc(sizeof(CMMsgBox));
CMMsgBox_CInit_CAwsWindow1p_i0p(pHeapObj_1,&((pThis)->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),EWndID_Msg_ExitApp);
{CMMsgBox *  pMsg=pHeapObj_1;
	CAwsString str;
	CAwsString_CInit_i0p(&(str),100);
CAwsString_LoadString_i0p(&(str),StringID_ExitProgramme);
	CMMsgBox_ShowMsg_0p_CAwsString1p(pMsg,AWS_MBT_OK_Cancel,&(str));
CAwsString_DUninit_i1p(&(str), 0);
}}}
}

void CMyMainContainer_PopMenu_i0p_CEspPoint1p(CBMenuContainer* this, int nMenuID,const CEspPoint * pt)
{

	CMyMainContainer* pThis = (CMyMainContainer*)this;{
	switch(nMenuID)
	{
	case AWS_MenuID_Left:
		{
			{CBMenu*pHeapObj_1=(CBMenu(*))malloc(sizeof(CBMenu));
CBMenu_CInit_CAwsWindow1p_i0p_i0p_i0p(pHeapObj_1,&((pThis)->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),15,0,0);
{CBMenu *  pMenu=pHeapObj_1;
			CAwsString str;
			CAwsString_CInit_i0p(&(str),100);
CAwsString_LoadString_i0p(&(str),StringID_Menu_Open);
			CBMenu_AddItem_CAwsString1p_i0p(pMenu,&(str),0);
			CAwsString_LoadString_i0p(&(str),StringID_Menu_Delete);
			CBMenu_AddItem_CAwsString1p_i0p(pMenu,&(str),0);
			CAwsString_LoadString_i0p(&(str),StringID_Menu_ChangeView);
			CBMenu_AddItem_CAwsString1p_i0p(pMenu,&(str),EWndID_Menu1_Sub1);
			CAwsString_LoadString_i0p(&(str),StringID_Menu_OtherPage);
			CBMenu_AddItem_CAwsString1p_i0p(pMenu,&(str),0);
			CAwsString_LoadString_i0p(&(str),StringID_Menu_Exit);
			CBMenu_AddItem_CAwsString1p_i0p(pMenu,&(str),0);
			CBMenu_AddItemEnd(pMenu);

			{CEspRect rect;
			CEspRect_CInit(&(rect));
CMMainContainer_AdjustMenuPos_CBMenu1p_CEspRect1p_CEspPoint1p_i0p(&(pThis->m_oBase_CMMainContainer),pMenu,&(rect),pt,0);
			CAwsContainer_PopWnd_CAwsWindow1p_CEspRect1p_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer),&((pMenu)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rect),AWS_MenuID_Left);
		}CAwsString_DUninit_i1p(&(str), 0);
}}}
		break;

	case EWndID_Menu1_Sub1:
		{
			// 弹出子窗口
			{CBMenu*pHeapObj_2=(CBMenu(*))malloc(sizeof(CBMenu));
CBMenu_CInit_CAwsWindow1p_i0p_i0p_i0p(pHeapObj_2,&((pThis)->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),15,1,1);
{CBMenu *  pMenu=pHeapObj_2;
			CAwsString str;
			CAwsString_CInit_i0p(&(str),100);
CAwsString_LoadString_i0p(&(str),StringID_Menu_ListView);
			CBMenu_AddItem_CAwsString1p_i0p(pMenu,&(str),0);
			CAwsString_LoadString_i0p(&(str),StringID_Menu_IconView);
			CBMenu_AddItem_CAwsString1p_i0p(pMenu,&(str),0);
			CBMenu_AddItemEnd(pMenu);

			{CEspRect rect;
			CEspRect_CInit(&(rect));
CMMainContainer_AdjustMenuPos_CBMenu1p_CEspRect1p_CEspPoint1p_i0p(&(pThis->m_oBase_CMMainContainer),pMenu,&(rect),pt,1);
			CAwsContainer_PopWnd_CAwsWindow1p_CEspRect1p_i0p(&(pThis->m_oBase_CMMainContainer.m_oBase_CBMenuContainer.m_oBase_CAwsContainer),&((pMenu)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rect),EWndID_Menu1_Sub1);
		}CAwsString_DUninit_i1p(&(str), 0);
}}}
		break;
	}
}
}
