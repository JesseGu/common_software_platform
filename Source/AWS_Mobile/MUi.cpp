/******************************************************************************
* FileName		       : MUi.cpp
* Description          : implementation of the CMUi class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "MUi.h"
#include "MMenuBar.h"
#include "BTitleBar.h"
#include "MMainContainer.h"
#include "BMenu.h"

CMUi::CMUi(int nMaxSubWndCount) : CAwsContainer(nMaxSubWndCount)
{
	m_pMenuBar = ESP_NULL;
	m_pTitleBar = ESP_NULL;

	m_bIsHideMenuBar = false;
	m_bIsHideTitleBar = false;

	// 默认的标题条和菜单条的高度
	m_nTitleBarHeight = 24;
	m_nMenuBarHeight = 24;

	m_pCurMainContainer = ESP_NULL;
	m_nCurMainContainerID = 0;

	m_nMaxMainContainer = 5;
	m_nRegDataCount = 0;
	m_pRegData = new TRegisterData[m_nMaxMainContainer];
	int i;
	for ( i = 0; i < m_nMaxMainContainer; ++i )
	{
		m_pRegData[i].m_nID = 0;
		m_pRegData[i].m_pMainContainerBuilder = ESP_NULL;
		m_pRegData[i].m_pContainer = ESP_NULL;
	}
}

CMUi::~CMUi()
{
	int i;
	for ( i = 0; i < m_nRegDataCount; ++i )
	{
		delete m_pRegData[i].m_pMainContainerBuilder;
		m_pRegData[i].m_pMainContainerBuilder = ESP_NULL;
	}
	delete []m_pRegData;
}

void CMUi::OnCreate()
{
	// 创建标题
	CAwsString str;
	str.LoadString(StringID_NULL);
	m_pTitleBar = new CBTitleBar(m_nTitleBarHeight);
	m_pTitleBar->SetCaption(str);

	CEspRect rt;
	m_pTitleBar->Create(this, rt, 0, !m_bIsHideTitleBar);
	AddSubWnd(m_pTitleBar, false);

	// 创建菜单
	m_pMenuBar = new CMMenuBar(m_nMenuBarHeight);
	m_pMenuBar->Create(this, rt, 0, !m_bIsHideMenuBar);
	AddSubWnd(m_pMenuBar, false);
}

bool CMUi::RegisterMainContainer(int nID, IAwsContainerBuilder* pMainContainerBuilder)
{
	bool bRet = false;

	if ( m_nRegDataCount < m_nMaxMainContainer )
	{
		m_pRegData[m_nRegDataCount].m_nID = nID;
		m_pRegData[m_nRegDataCount++].m_pMainContainerBuilder = pMainContainerBuilder;

		bRet = true;
	}

	return bRet;
}

int CMUi::GetIndexFromID(int nID)
{
	int i;
	for ( i = 0; i < m_nRegDataCount; ++i )
	{
		if ( m_pRegData[i].m_nID == nID )
			return i;
	}

	return -1;
}

bool CMUi::ChangeMainContainer(int nID, bool bIsHideTitleBar, bool bIsHideMenuBar, bool bIsDestroyFormer)
{
	bool bRet = false;

	if ( nID >= 0 && nID < m_nMaxMainContainer && nID != m_nCurMainContainerID )
	{
		int i;
		for ( i = 0; i < m_nRegDataCount; ++i )
		{
			if ( m_pRegData[i].m_nID == nID )
			{
				break;
			}
		}

		if ( i < m_nRegDataCount )
		{
			if ( m_nCurMainContainerID > 0 )
			{
				int nIndex = GetIndexFromID(m_nCurMainContainerID);

				// 逆激活
				m_pRegData[nIndex].m_pContainer->InActive();

				if ( bIsDestroyFormer )
				{
					// 销毁
					DeleteWindow(m_pRegData[nIndex].m_pContainer);
					m_pRegData[nIndex].m_pContainer = ESP_NULL;
				}
				else
				{
					// 隐藏
					m_pRegData[nIndex].m_pContainer->SetVisible(false, false);
				}
			}

			// 找到，先看是否已经存在
			if ( ESP_NULL == m_pRegData[i].m_pContainer )
			{
				// 新创建
				m_pRegData[i].m_pContainer = (CMMainContainer*)m_pRegData[i].m_pMainContainerBuilder->Build(this, GetClientRect());

				AddSubWnd(m_pRegData[i].m_pContainer, true);
			}
			else
			{
				// 已经存在，则直接显示
				m_pRegData[i].m_pContainer->SetVisible(true, false);
			}

			// 激活
			m_pRegData[i].m_pContainer->OnActive();

			SetFocus(m_pRegData[i].m_pContainer);

			m_pCurMainContainer = m_pRegData[i].m_pContainer;
			m_nCurMainContainerID = nID;

			// 对标题栏和菜单条处理
			HideTitleBar(bIsHideTitleBar, false);
			HideMenuBar(bIsHideMenuBar, false);

			// 重绘制所有窗口
			Invalide();

			bRet = true;
		}
	}

	return bRet;
}

void CMUi::HideMenuBar(bool bIsHide, bool bIsRedraw /*= true*/)
{
	CEspSize size;

	if ( bIsHide && !m_bIsHideMenuBar )
	{
		m_bIsHideMenuBar = true;
		m_pMenuBar->SetVisible(false, bIsRedraw);

		if ( ESP_NULL != m_pCurMainContainer )
		{
			// 移动MainContainer
			m_pCurMainContainer->MoveTo(GetClientRect(), bIsRedraw);
		}
	}
	else if ( !bIsHide && m_bIsHideMenuBar )
	{
		m_bIsHideMenuBar = false;

		if ( ESP_NULL != m_pCurMainContainer )
		{
			// 移动MainContainer
			m_pCurMainContainer->MoveTo(GetClientRect(), bIsRedraw);
		}
		m_pMenuBar->SetVisible(true, bIsRedraw);
	}
}

void CMUi::HideTitleBar(bool bIsHide, bool bIsRedraw /*= true*/)
{
	CEspSize size;

	if ( bIsHide )
	{
		m_bIsHideTitleBar = true;
		m_pTitleBar->SetVisible(false, bIsRedraw);

		if ( ESP_NULL != m_pCurMainContainer )
		{
			// 移动MainContainer
			m_pCurMainContainer->MoveTo(GetClientRect(), bIsRedraw);
		}
	}
	else if ( !bIsHide )
	{
		m_bIsHideTitleBar = false;

		m_pTitleBar->SetVisible(true, false);
		if ( ESP_NULL != m_pCurMainContainer )
		{
			// 移动MainContainer
			m_pCurMainContainer->MoveTo(GetClientRect(), bIsRedraw);
		}

		if ( bIsRedraw )
			m_pTitleBar->Invalide();
	}
}

CEspRect& CMUi::GetClientRect()
{
	m_rtClient.m_ptLT.m_nX = 0;
	if ( !m_bIsHideTitleBar )
		m_rtClient.m_ptLT.m_nY = m_nTitleBarHeight;
	else
		m_rtClient.m_ptLT.m_nY = 0;

	m_rtClient.m_ptRB.m_nY = GetSize()->m_nHeight;
	m_rtClient.m_ptRB.m_nX = GetSize()->m_nWidth;
	if ( !m_bIsHideMenuBar )
		m_rtClient.m_ptRB.m_nY -= m_nMenuBarHeight;

	return m_rtClient;
}

//#include <afx.h>
void CMUi::OnDraw(const CEspRect& rect)
{
//	TRACE("MUi draw, X(%d),Y(%d), Width(%d), Height(%d)\n", rect.m_ptLT.m_nX, rect.m_ptLT.m_nY, rect.GetSize()->m_nWidth, rect.GetSize()->m_nHeight);

	CAwsContainer::OnDraw(rect);
}
