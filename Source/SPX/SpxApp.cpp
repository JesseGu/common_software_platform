/******************************************************************************
* FileName		       : SpxAPP.cpp
* Description          : implementation of the CSpxAPP class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "SpxApp.h"
#include "SpxController.h"
#include "Os.h"

CSpxApp::CSpxApp(int nMaxControllerCount /*= 1*/)
{
	m_nMaxControllerCount = nMaxControllerCount;
	if ( m_nMaxControllerCount > 0 )
		m_ppController = new CSpxController*[m_nMaxControllerCount];
	else
		m_ppController = ESP_NULL;

	m_nControllerCount = 0;

	m_pUi = ESP_NULL;
	m_pOs = ESP_NULL;
}

CSpxApp::~CSpxApp()
{
	int i;
	for ( i = 0; i < m_nControllerCount; ++i )
		delete m_ppController[i];

	delete []m_ppController;
}

void CSpxApp::Init(CAwsUi* pUi, COs* pOs)
{
	m_pUi = pUi;
	m_pOs = pOs;

	m_pUi->SetApp(this);

	OnInit(m_pUi->GetScreenSize());
}

// 将消息分派给每个控制器处理
bool CSpxApp::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	bool bRet = false;
	int i;

	for ( i = 0; i < m_nControllerCount; ++i )
	{
		if ( bRet = m_ppController[i]->OnCommand(nWndID, nCmdID, nParam1, nParam2) )
			break;
	}

	return bRet;
}

bool CSpxApp::AddController(CSpxController* pController)
{
	bool bRet = true;

	if ( ESP_NULL != pController && m_nControllerCount < m_nMaxControllerCount )
		m_ppController[m_nControllerCount++] = pController;
	else
		bRet = false;

	return bRet;
}

void CSpxApp::RemoveController(CSpxController* pController)
{
	if ( ESP_NULL != pController )
	{
		int i, j;
		for ( i = 0; i < m_nControllerCount; ++i )
		{
			if ( pController == m_ppController[i] )
			{
				for ( j = i; j < m_nControllerCount - 1; ++j )
					m_ppController[j] = m_ppController[j + 1];

				--m_nControllerCount;
				break;
			}
		}
	}
}
