/******************************************************************************
* FileName		       : BTabContainer.cpp
* Description          : implementation of the CBTabView class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BTabView.h"
#include "BTabPanel.h"
#include "IAwsGc.h"

CBTabView::CBTabView() : CAwsContainer(10)
{
	m_pTabPanel = ESP_NULL;

	m_nMaxMainContainer = 10;
	m_nRegDataCount = 0;
	m_pRegData = new TRegisterData[m_nMaxMainContainer];
	int i;
	for ( i = 0; i < m_nMaxMainContainer; ++i )
	{
		m_pRegData[i].m_pContainBuilder = ESP_NULL;
		m_pRegData[i].m_pContainer = ESP_NULL;
	}

	m_pCurContainer = ESP_NULL;
	m_nCurContainerIndex = -1;
}

CBTabView::~CBTabView()
{
	int i;
	for ( i = 0; i < m_nMaxMainContainer; ++i )
	{
		delete m_pRegData[i].m_pContainBuilder;
		m_pRegData[i].m_pContainBuilder = ESP_NULL;
	}

	delete []m_pRegData;
}

void CBTabView::OnCreate()
{
	CAwsContainer::OnCreate();

	// 创建TablePanel
	m_pTabPanel = new CBTabPanel;
	CEspRect rt(0, 0, 240, 51);
	m_pTabPanel->Create(this, rt);
	AddSubWnd(m_pTabPanel, true);
}

bool CBTabView::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	if ( AWS_SysCmd_TabPanelChangePage == nCmdID )
	{
		// 收到改变的消息
		SwitchContainer(nParam1);
		return true;
	}
	else if ( AWS_SysCmd_TabViewSetPanelFocus == nCmdID )
	{
		// 把TabPanel设置为焦点
		SetFocus(m_pTabPanel);
		return true;
	}

	return CAwsContainer::OnCommand(nWndID, nCmdID, nParam1, nParam2);
}

void CBTabView::OnSize(const CEspSize& size, bool bIsRedraw /*= true*/)
{
	CAwsContainer::OnSize(size, bIsRedraw);
	
	if ( ESP_NULL != m_pCurContainer )
	{
		CEspRect rt = m_pTabPanel->GetRect();
		CEspRect rect(0, rt.m_ptRB.m_nY, size.m_nWidth, size.m_nHeight);
		m_pCurContainer->MoveTo(rect, bIsRedraw);
	}
}

bool CBTabView::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	bool bRet = CAwsContainer::OnKey(type, code);

	if ( !bRet )
	{
		if ( AWS_Key == type )
		{
			switch ( code )
			{
			case AWS_KeyCode_DownArrow:
				if ( ESP_NULL != m_pCurContainer )
				{
					SetFocus(m_pCurContainer);
				}
				break;

			case AWS_KeyCode_LeftArrow:
				SetFocus(m_pTabPanel);
				m_pTabPanel->OnKey(type, code);
				break;

			case AWS_KeyCode_RightArrow:
				SetFocus(m_pTabPanel);
				m_pTabPanel->OnKey(type, code);
				break;
			}
		}
	}

	return bRet;
}

CEspRect& CBTabView::GetClientRect()
{
	CEspSize size = *GetSize();
	CEspSize sizePanel = *m_pTabPanel->GetSize();

	CEspRect rt(0, sizePanel.m_nHeight, size.m_nWidth, size.m_nHeight);
	m_rtClient = rt;
	return m_rtClient;
}

bool CBTabView::RegisterMainContainer(IAwsContainerBuilder* pContainBuilder)
{
	bool bRet = false;

	if ( m_nRegDataCount < m_nMaxMainContainer )
	{
		m_pRegData[m_nRegDataCount].m_pContainBuilder = pContainBuilder;
		++m_nRegDataCount;
		bRet = true;
	}

	return bRet;
}

bool CBTabView::SwitchContainer(int nIndex)
{
	bool bRet = false;

	if ( nIndex >= 0 && nIndex < m_nMaxMainContainer && nIndex != m_nCurContainerIndex )
	{
		if ( m_nCurContainerIndex >= 0 )
		{
			// 隐藏先前的
			m_pRegData[m_nCurContainerIndex].m_pContainer->SetVisible(false, false);
		}

		// 找到，先看是否已经存在
		if ( ESP_NULL == m_pRegData[nIndex].m_pContainer )
		{
			// 新创建
			m_pRegData[nIndex].m_pContainer = m_pRegData[nIndex].m_pContainBuilder->Build(this, GetClientRect());

			AddSubWnd(m_pRegData[nIndex].m_pContainer, true);
			InvalideRect(GetClientRect());
			SetFocus(m_pTabPanel);
		}
		else
		{
			// 已经存在，则直接显示
			m_pRegData[nIndex].m_pContainer->SetVisible(true);
		}

		m_pCurContainer = m_pRegData[nIndex].m_pContainer;
		m_nCurContainerIndex = nIndex;

		bRet = true;
	}

	return bRet;
}
