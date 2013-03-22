/******************************************************************************
* FileName		       : TabMainContainer.cpp
* Description          : implementation of the CTabMainContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
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

CAwsContainer* CTabMainContainerBuilder::Build(CAwsWindow* pParent, const CEspRect& rect)
{
	CAwsContainer* pContainer = new CTabMainContainer();
	pContainer->Create(pParent, rect);

	return pContainer;
}

CTabMainContainer::CTabMainContainer() : CMMainContainer(30)
{
	m_pTabView = ESP_NULL;
	m_strLeftMenu.LoadString(StringID_Menu);
	m_strRightMenu.LoadString(StringID_Return);
}

void CTabMainContainer::OnCreate()
{
	CMMainContainer::OnCreate();
	
	CAwsString str;
	CAwsImage imageBK;
	CEspSize imageSize;
	CBTitleBar* pTitleBar = GetMUi()->GetTitleBar();
	str.LoadString(StringID_TitleBar);
	pTitleBar->SetCaption(str);
	imageSize.m_nHeight = 24;
	imageSize.m_nWidth = 2;
	imageBK.LoadImage(IDB_TITLEBAR);
	pTitleBar->SetBKImage(imageBK, imageSize);
	
	imageBK.LoadImage(IDB_TITLEICON);
	CAwsImage imageMask;
	imageMask.LoadImage(IDB_TITLEMASK);
	CEspSize size(33, 20);
	pTitleBar->SetIcon(imageBK, size, &imageMask);
	
	imageSize.m_nHeight = 24;
	imageSize.m_nWidth = 2;
	imageBK.LoadImage(IDB_MENUBAR);
	CMMenuBar* pMenuBar = GetMUi()->GetMenuBar();
	if ( ESP_NULL != pMenuBar )
	{
		pMenuBar->SetBKImage(imageBK, imageSize);
		UpdateMenuBar(StringID_Menu, StringID_Return, false);
	}

	// 创建TabView
	m_pTabView = new CBTabView;
	CEspRect rt(0, 0, GetSize()->m_nWidth, GetSize()->m_nHeight);
	m_pTabView->Create(this, rt);
	AddSubWnd(m_pTabView, true);
	m_pTabView->RegisterMainContainer(new CTabPage1Builder());
	m_pTabView->RegisterMainContainer(new CTabPage2Builder());
	m_pTabView->RegisterMainContainer(new CTabPage3Builder());
	m_pTabView->RegisterMainContainer(new CTabPage4Builder());
	m_pTabView->RegisterMainContainer(new CTabPage5Builder());
	m_pTabView->RegisterMainContainer(new CTabPage6Builder());
	m_pTabView->SwitchContainer(0);

	// 设置TabPanel参数
	CAwsImage imageBKMask;
	CBTabPanel* pTabPanel = m_pTabView->GetTabPanel();
	imageBK.LoadImage(IDB_TABPANELBK);
	pTabPanel->SetBKImage(imageBK);

	// 设置pSelectBox参数
	CBSelectBox* pSelectBox = pTabPanel->GetSelectBox();
	imageBK.LoadImage(IDB_TABITEMSELBK);
	imageBKMask.LoadImage(IDB_TABITEMSELBKMASK);
	pSelectBox->SetSelectImage(imageBK, imageBKMask);
	pSelectBox->SetBKTransparent(true);

	CEspSize sizeItemRegion(41, 24);
	CEspRect rtMoveTo(55, 27, 239, 50);
	CAwsRgb rgbText(173, 154, 132), rgbFocusText(255, 255, 255), rgbArrow(255, 255, 255);
	pSelectBox->SetItemRegionSize(sizeItemRegion);
	pSelectBox->MoveTo(rtMoveTo);
	pSelectBox->SetTextColor(rgbText);
	pSelectBox->SetFocusTextColor(rgbFocusText);
	pSelectBox->SetArrowColor(rgbArrow);

	int i;
	for ( i = 0; i < 6; ++i )
	{
		str.LoadString(i);
		pSelectBox->AddItem(str);
	}
	pSelectBox->AddItemEnd();
}

void CTabMainContainer::InActive()
{
	OnFocus(false);
}

void CTabMainContainer::OnActive()
{
	UpdateMenuBar(StringID_Menu, StringID_Return, false);
}

bool CTabMainContainer::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	switch ( nCmdID )
	{
	case AWS_SysCmd_MenuCmd:
		if ( AWS_MenuID_Left == nWndID )
		{
			switch ( nParam1 )
			{
			case 0:
				PostCommand(m_nWndID, EWndID_Msg_ChangeMainContainer);
				break;
			}
		}
		break;

	case AWS_SysCmd_MsgBox_OK:
		if ( EWndID_Msg_Selected == nWndID )
		{
			UpdateMenuBar(StringID_Menu, StringID_Return);
		}
		break;

	case AWS_SysCmd_MenuDestroy:
		// 改变菜单条的显示
		if ( ESP_NULL != GetMUi()->GetMenuBar() )
		{
			UpdateMenuBar(StringID_Menu, StringID_Return);
		}
		break;

	case EWndID_Msg_ChangeMainContainer:
		GetMUi()->ChangeMainContainer(MyMainContainerID, false, false, false);
		break;
	}

	return CMMainContainer::OnCommand(nWndID, nCmdID, nParam1, nParam2);
}

bool CTabMainContainer::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	return CMMainContainer::OnKey(type, code);
}

void CTabMainContainer::OnSize(const CEspSize& size, bool bIsRedraw /*= true*/)
{
	CMMainContainer::OnSize(size, bIsRedraw);

	if ( ESP_NULL != m_pTabView )
	{
		CEspRect rt(0, 0, size.m_nWidth, size.m_nHeight);
		m_pTabView->MoveTo(rt, bIsRedraw);
	}
}

void CTabMainContainer::OnLeftMenu()
{
	CMMenuBar* pMenuBar = GetMUi()->GetMenuBar();
	if ( ESP_NULL != pMenuBar )
	{
		UpdateMenuBar(StringID_Select, StringID_Cancel);
	}

	CEspPoint pt;
	PopMenu(AWS_MenuID_Left, pt);
}

void CTabMainContainer::OnRightMenu()
{
	PostCommand(m_nWndID, EWndID_Msg_ChangeMainContainer);
}

void CTabMainContainer::PopMenu(int nMenuID, const CEspPoint& pt)
{
	switch ( nMenuID )
	{
	case AWS_MenuID_Left:
		{
			CBMenu* pMenu = new CBMenu(this);
			CAwsString str;
			str.LoadString(StringID_Menu_ReturnMainPage);
			pMenu->AddItem(str);
			pMenu->AddItemEnd();

			CEspRect rect;
			AdjustMenuPos(pMenu, rect, pt, false);
			PopWnd(pMenu, rect, AWS_MenuID_Left);
		}
		break;
	}
}
