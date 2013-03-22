/******************************************************************************
* FileName		       : MMainContainer.cpp
* Description          : implementation of the CMMainContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "MMainContainer.h"
#include "MUi.h"
#include "BMenu.h"
#include "MMenuBar.h"
#include "IAwsGc.h"

CMMainContainer::CMMainContainer(int nMaxSubWndCount) : CBMenuContainer(nMaxSubWndCount)
{
}

CMUi* CMMainContainer::GetMUi()
{
	return (CMUi*)GetParent();
}

void CMMainContainer::OnDraw(const CEspRect& rect)
{
	// 绘制自己的背景
	IAwsGc* pGc = GetGc();

	CAwsContainer::OnDraw(rect);
}

bool CMMainContainer::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	if ( AWS_Key_Up == type )
	{
		switch ( code )
		{
		case AWS_KeyCode_LeftMenu:
			OnLeftMenu();
			return true;

		case AWS_KeyCode_RightMenu:
			OnRightMenu();
			return true;
		}
	}

	return CAwsContainer::OnKey(type, code);
}

void CMMainContainer::AdjustMenuPos(CBMenu* pMenu, CEspRect& rect, const CEspPoint& pt, bool bIsSubMenu)
{
	CEspSize sizeMenu = pMenu->GetMenuSize();
	CEspSize sizeMB = *GetMUi()->GetMenuBar()->GetSize();
	CEspSize sizeScreen = *GetMUi()->GetSize();

	if ( bIsSubMenu )
	{
		rect.m_ptLT = pt;

		if ( rect.m_ptLT.m_nX + sizeMenu.m_nWidth > sizeScreen.m_nWidth )
		{
			// 若超出了屏幕范围，改变x
			rect.m_ptLT.m_nX = sizeScreen.m_nWidth - sizeMenu.m_nWidth;
		}

		if ( rect.m_ptLT.m_nY + sizeMenu.m_nHeight > sizeScreen.m_nHeight - sizeMB.m_nHeight )
		{
			// 改变y
			rect.m_ptLT.m_nY = sizeScreen.m_nHeight - sizeMB.m_nHeight - sizeMenu.m_nHeight;
		}
		rect.m_ptRB.m_nX = rect.m_ptLT.m_nX + sizeMenu.m_nWidth;
		rect.m_ptRB.m_nY = rect.m_ptLT.m_nY + sizeMenu.m_nHeight;
	}
	else
	{
		rect.m_ptLT.m_nY = sizeScreen.m_nHeight - sizeMB.m_nHeight - sizeMenu.m_nHeight;
		rect.m_ptRB.m_nX = sizeMenu.m_nWidth;
		rect.m_ptRB.m_nY = sizeScreen.m_nHeight - sizeMB.m_nHeight;
	}
}

void CMMainContainer::UpdateMenuBar(AWS_SysStringID eLeftStrID, AWS_SysStringID eRightStrID, bool bIsRedraw /*= true*/)
{
	CMMenuBar* pMenuBar = GetMUi()->GetMenuBar();
	if ( ESP_NULL != pMenuBar )
	{		
		m_strLeftMenu.LoadString(eLeftStrID);
		m_strRightMenu.LoadString(eRightStrID);

		pMenuBar->SetLeftMenuText(m_strLeftMenu, bIsRedraw);
		pMenuBar->SetRightMenuText(m_strRightMenu, bIsRedraw);
	}
}
