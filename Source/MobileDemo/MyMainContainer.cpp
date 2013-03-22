/******************************************************************************
* FileName		       : MyMainContainer.cpp
* Description          : implementation of the CMyMainContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
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

CAwsContainer* CMyMainContainerBuilder::Build(CAwsWindow* pParent, const CEspRect& rect)
{
	CAwsContainer* pContainer = new CMyMainContainer();
	pContainer->Create(pParent, rect);

	return pContainer;
}

CMyMainContainer::CMyMainContainer() : CMMainContainer(30)
{
	m_pScrollBar = ESP_NULL;
	m_nScrollTotalLength = 10;
	m_nScrollPos = 0;

	m_pListView = ESP_NULL;
}

void CMyMainContainer::OnCreate()
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
		UpdateMenuBar(StringID_Menu, StringID_Exit, false);
	}

	m_pListView = new CBListView(30);
	CEspRect rect(0, 0, GetSize()->m_nWidth, GetSize()->m_nHeight);
	m_pListView->Create(this, rect);
	int i;
	int nImageIndex = 133;
	CAwsImage iconMask;
	iconMask.LoadImage(IDB_MAINMASK);
	CAwsImage iconSmall, iconBig;
	for ( i = 0; i < 12; ++i )
	{
		str.LoadString(i);
		iconSmall.LoadImage(nImageIndex);
		iconBig.LoadImage(nImageIndex++);
		m_pListView->AddItem(str, iconSmall, iconBig, &iconMask, &iconMask);
	}
	nImageIndex = 133;
	for ( i = 0; i < 8; ++i )
	{
		str.LoadString(i);
		iconSmall.LoadImage(nImageIndex);
		iconBig.LoadImage(nImageIndex++);
		m_pListView->AddItem(str, iconSmall, iconBig, &iconMask, &iconMask);
	}
	str.LoadString(10);
	iconBig.LoadImage(133);
	iconSmall.LoadImage(133);
	m_pListView->AddItem(str, iconSmall, iconBig, &iconMask, &iconMask, true);
	AddSubWnd(m_pListView, true);
}

void CMyMainContainer::InActive()
{
	OnFocus(false);
}

void CMyMainContainer::OnActive()
{
	UpdateMenuBar(StringID_Menu, StringID_Exit, false);
}

bool CMyMainContainer::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	// 命令解析
	switch (nCmdID )
	{
	case AWS_SysCmd_MenuCmd:
		if ( AWS_MenuID_Left == nWndID )
		{
			switch ( nParam1 )
			{
			case 0:
				// 打开
				return OnCommand(0, AWS_SysCmd_ListViewCmd, 0, 0);
				break;
				
			case 1:
				// 删除当前项
				{
					CMMsgBox* pMsg = new CMMsgBox(this, EWndID_Msg_DeleteItem);
					CAwsString str;
					str.LoadString(StringID_RealDelete);
					pMsg->ShowMsg(AWS_MBT_OK_Cancel, str);
				}
				break;

			case 2:
				// 视图切换
				break;

			case 3:
				// 改变主容器，此时要Post一个消息
				PostCommand(m_nWndID, EWndID_Msg_ChangeMainContainer);
				break;
				
			case 4:
				// 退出
				OnRightMenu();
				break;
			}
		}
		else if ( EWndID_Menu1_Sub1 == nWndID )
		{
			switch ( nParam1 )
			{
			case 0:
				m_pListView->SetShowMode(LVShowMode_List);
				break;
				
			case 1:
				m_pListView->SetShowMode(LVShowMode_Icon);
				break;
			}
		}
		break;

	case AWS_SysCmd_MsgBox_OK:
		if ( EWndID_Msg_DeleteItem == nWndID )
		{
			UpdateMenuBar(StringID_Menu, StringID_Exit);

			// 确定删除
			m_pListView->RemoveItem(m_pListView->GetCurItemIndex());
		}
		else if ( EWndID_Msg_Selected == nWndID )
		{
			UpdateMenuBar(StringID_Menu, StringID_Exit);
		}
		else if ( EWndID_Msg_ExitApp == nWndID )
		{
			GetUi()->ExitSys();
		}
		break;

	case AWS_SysCmd_MsgBox_Cancel:
		if ( EWndID_Msg_DeleteItem == nWndID || EWndID_Msg_ExitApp == nWndID )
		{
			UpdateMenuBar(StringID_Menu, StringID_Exit);
		}
		break;

	case AWS_SysCmd_MenuDestroy:
		// 改变菜单条的显示
		UpdateMenuBar(StringID_Menu, StringID_Exit);
		break;

	case AWS_SysCmd_ListViewCmd:
		{
			CMMsgBox* pMsg = new CMMsgBox(this, EWndID_Msg_Selected);
			CAwsString str;
			str.LoadString(StringID_WelcomeUse);
			pMsg->ShowMsg(AWS_MBT_OK, str);
		}
		break;

	case EWndID_Msg_ChangeMainContainer:
		GetMUi()->ChangeMainContainer(TabMainContainerID, false, false, false);
		break;
	}

	return CMMainContainer::OnCommand(nWndID, nCmdID, nParam1, nParam2);
}

bool CMyMainContainer::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	bool bRet = CMMainContainer::OnKey(type, code);

	if ( !bRet )
	{
		if ( AWS_Key == type )
		{
			switch ( code )
			{
			case AWS_KeyCode_LeftArrow:
				PreFocusWnd();
				bRet = true;
				break;

			case AWS_KeyCode_RightArrow:
				NextFocusWnd();
				bRet = true;
				break;

			case AWS_KeyCode_UpArrow:
				if ( 0 == m_nScrollPos )
				{
					m_nScrollPos = m_nScrollTotalLength - 1;
				}
				else
				{
					--m_nScrollPos;
				}
				m_pScrollBar->SetCurPos(m_nScrollPos);
				bRet = true;
				break;

			case AWS_KeyCode_DownArrow:
				if ( m_nScrollPos + 1 < m_nScrollTotalLength )
				{
					++m_nScrollPos;
				}
				else
				{
					m_nScrollPos = 0;
				}
				m_pScrollBar->SetCurPos(m_nScrollPos);
				bRet = true;
				break;
			}
		}
	}

	return bRet;
}

void CMyMainContainer::OnSize(const CEspSize& size, bool bIsRedraw /*= true*/)
{
	CAwsContainer::OnSize(size, bIsRedraw);

	CEspRect rt;
	rt.m_ptLT.m_nX = size.m_nWidth - 10;
	rt.m_ptRB.m_nX = size.m_nWidth;
	rt.m_ptRB.m_nY = size.m_nHeight;

	if ( ESP_NULL != m_pScrollBar )
	{
		m_pScrollBar->MoveTo(rt, bIsRedraw);
		m_pScrollBar->SetTotalLength(m_nScrollTotalLength);
	}

	if ( ESP_NULL != m_pListView )
	{
		rt.m_ptLT.m_nX = 0;
		rt.m_ptRB.m_nX = size.m_nWidth;
		rt.m_ptRB.m_nY = size.m_nHeight;
		m_pListView->MoveTo(rt, bIsRedraw);
	}
}

void CMyMainContainer::OnLeftMenu()
{
	CMMenuBar* pMenuBar = GetMUi()->GetMenuBar();
	if ( ESP_NULL != pMenuBar )
	{
		UpdateMenuBar(StringID_Select, StringID_Cancel);
	}

	CEspPoint pt;
	PopMenu(AWS_MenuID_Left, pt);
}

void CMyMainContainer::OnRightMenu()
{
	// 退出应用程序
	CMMsgBox* pMsg = new CMMsgBox(this, EWndID_Msg_ExitApp);
	CAwsString str;
	str.LoadString(StringID_ExitProgramme);
	pMsg->ShowMsg(AWS_MBT_OK_Cancel, str);
}

void CMyMainContainer::PopMenu(int nMenuID, const CEspPoint& pt)
{
	switch ( nMenuID )
	{
	case AWS_MenuID_Left:
		{
			CBMenu* pMenu = new CBMenu(this);
			CAwsString str;
			str.LoadString(StringID_Menu_Open);
			pMenu->AddItem(str);
			str.LoadString(StringID_Menu_Delete);
			pMenu->AddItem(str);
			str.LoadString(StringID_Menu_ChangeView);
			pMenu->AddItem(str, EWndID_Menu1_Sub1);
			str.LoadString(StringID_Menu_OtherPage);
			pMenu->AddItem(str);
			str.LoadString(StringID_Menu_Exit);
			pMenu->AddItem(str);
			pMenu->AddItemEnd();

			CEspRect rect;
			AdjustMenuPos(pMenu, rect, pt, false);
			PopWnd(pMenu, rect, AWS_MenuID_Left);
		}
		break;

	case EWndID_Menu1_Sub1:
		{
			// 弹出子窗口
			CBMenu* pMenu = new CBMenu(this, 15, 1, true);
			CAwsString str;
			str.LoadString(StringID_Menu_ListView);
			pMenu->AddItem(str);
			str.LoadString(StringID_Menu_IconView);
			pMenu->AddItem(str);
			pMenu->AddItemEnd();

			CEspRect rect;
			AdjustMenuPos(pMenu, rect, pt, true);
			PopWnd(pMenu, rect, EWndID_Menu1_Sub1);
		}
		break;
	}
}
