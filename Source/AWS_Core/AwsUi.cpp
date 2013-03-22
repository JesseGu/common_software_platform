/******************************************************************************
* FileName		       : AwsUi.cpp
* Description          : implementation of the CAwsUi class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "AwsUi.h"
#include "IAwsGc.h"
#include "AwsContainer.h"
#include "SpxApp.h"

CAwsUi::CAwsUi(int nMaxTopWndCount)
{
	m_pCurTopWnd = ESP_NULL;
	m_nCurTopWndCount = 0;
	m_nMaxTopWndCount = nMaxTopWndCount;

	if ( m_nMaxTopWndCount > 0 )
		m_pTopWndData = new CAwsWindow*[m_nMaxTopWndCount];
	else
		m_pTopWndData = ESP_NULL;

	m_pSysGc = ESP_NULL;

	m_nCommandCount = 0;

	int i;
	for ( i = 0; i < MAX_TIMERDATA; ++i )
	{
		m_tTimerData[i].m_pWnd = ESP_NULL;
	}

	m_pApp = ESP_NULL;
}

CAwsUi::~CAwsUi()
{
	int i;
	for ( i = 0; i < m_nCurTopWndCount; ++i )
	{
		delete m_pTopWndData[i];
	}

	delete []m_pTopWndData;
}

bool CAwsUi::StartTimer(CAwsWindow* pWnd, int nTimes)
{
	bool bRet = false;

	if ( ESP_NULL != pWnd )
	{
		int i;
		for ( i = 0; i < MAX_TIMERDATA; ++i )
		{
			if ( ESP_NULL == m_tTimerData[i].m_pWnd )
			{
				m_tTimerData[i].m_pWnd = pWnd;
				m_tTimerData[i].m_nTime = nTimes;

				// ������ʱ��
				Timer(i, nTimes);
				bRet = true;
				break;
			}
		}
	}

	return bRet;
}

void CAwsUi::EndTimer(CAwsWindow* pWnd)
{
	int i;
	for ( i = 0; i < MAX_TIMERDATA; ++i )
	{
		if ( pWnd == m_tTimerData[i].m_pWnd )
		{
			// ֹͣ��ʱ��
			KillTimer(i);

			m_tTimerData[i].m_pWnd = ESP_NULL;
			break;
		}
	}
}

void CAwsUi::OnDraw(const CEspRect& rect)
{
	if ( ESP_NULL != m_pCurTopWnd )
		m_pCurTopWnd->Draw(rect);

	PostCommandRouter();
}

void CAwsUi::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	// ���õ�ǰ���㴰�ڵİ�����Ӧ����
	if ( ESP_NULL != m_pCurTopWnd )
		m_pCurTopWnd->OnKey(type, code);

	PostCommandRouter();
}

void CAwsUi::OnSize(const CEspSize& size, bool bIsRedraw /*= true*/)
{
	m_tScreenSize = size;

	if ( ESP_NULL != m_pCurTopWnd )
		m_pCurTopWnd->OnSize(size, bIsRedraw);

	PostCommandRouter();
}

void CAwsUi::OnFocus(bool bIsFocus)
{
	if ( ESP_NULL != m_pCurTopWnd )
		m_pCurTopWnd->OnFocus(bIsFocus);

	PostCommandRouter();
}

void CAwsUi::OnTimer( int nTimerID)
{
	int i;
	for ( i = 0; i < MAX_TIMERDATA; ++i )
	{
		if ( i == nTimerID )
		{
			if ( ESP_NULL != m_tTimerData[i].m_pWnd )
				m_tTimerData[i].m_pWnd->OnTimer();
			break;
		}
	}

	PostCommandRouter();
}

void CAwsUi::OnImeChar(short nChar)
{
	if ( ESP_NULL != m_pCurTopWnd )
		m_pCurTopWnd->OnImeChar(nChar);

	PostCommandRouter();
}

void CAwsUi::Init(const CEspSize& sizeScreen)
{
	m_tScreenSize = sizeScreen;
}

bool CAwsUi::AddWndToStack(CAwsWindow* pWnd)
{
	bool bRet = true;

	if ( ESP_NULL != pWnd && m_nCurTopWndCount < m_nMaxTopWndCount )
		m_pTopWndData[m_nCurTopWndCount++] = pWnd;
	else
		bRet = false;

	return bRet;
}

void CAwsUi::RemoveWndFromStack(CAwsWindow* pWnd)
{
	if ( ESP_NULL != pWnd )
	{
		int i;
		for ( i = 0; i < m_nCurTopWndCount; ++i )
		{
			if ( m_pTopWndData[i] == pWnd )
			{
				delete pWnd;
				int j;
				for ( j = i; j < m_nCurTopWndCount - 1; ++j )
					m_pTopWndData[j] = m_pTopWndData[j + 1];
				--m_nCurTopWndCount;
				break;
			}
		}
	}
}

void CAwsUi::RemoveWndFromTopStack()
{
	if ( m_nCurTopWndCount > 0 )
	{
		--m_nCurTopWndCount;
		delete m_pTopWndData[m_nCurTopWndCount];
	}
}

void CAwsUi::SetTopWnd(CAwsContainer* pWnd)
{
	if ( ESP_NULL != pWnd )
	{
		// ��ǰ�Ķ��㴰��ʧȥ����
		if ( ESP_NULL != m_pCurTopWnd )
			m_pCurTopWnd->OnFocus(false);

		m_pCurTopWnd = pWnd;

		// �����µĶ��㴰��
		m_pCurTopWnd->OnFocus(true);
	}
}

bool CAwsUi::AddPostCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	bool bRet = true;
	// ��Post��Command��������д�����
	if ( m_nCommandCount < MAX_POSTCOMMAND )
	{
		m_tPostCommands[m_nCommandCount].m_nWndID = nWndID;
		m_tPostCommands[m_nCommandCount].m_nCmdID = nCmdID;
		m_tPostCommands[m_nCommandCount].m_nParam1 = nParam1;
		m_tPostCommands[m_nCommandCount].m_nParam2 = nParam2;

		++m_nCommandCount;
	}
	else
	{
		bRet = false;
	}

	return bRet;
}

void CAwsUi::ClearWnd(CAwsWindow* pWnd)
{
	if ( ESP_NULL != pWnd )
	{
		CAwsWindow* pFatherWnd = pWnd->GetParent();
		if ( ESP_NULL == pFatherWnd )
		{
			// �Ƕ��㴰�ڣ�����
			RemoveWndFromStack(pWnd);
		}
		else
		{
			// ֱ��ɾ����
			delete pWnd;
		}
	}
}

void CAwsUi::PostCommandRouter()
{
	int i, nCommand = m_nCommandCount;

	// ע����ʵ�������ڼ���ܻ�������������Post����������Ҫһ������
	for ( i = 0; i < nCommand; ++i )
	{
		if ( AWS_SysCmd_DeleteWnd == m_tPostCommands[i].m_nCmdID )
		{
			// �������
			ClearWnd((CAwsWindow*)m_tPostCommands[i].m_nParam1);
		}
		else
		{
			CommandRouter(m_tPostCommands[i].m_nWndID, m_tPostCommands[i].m_nCmdID, m_tPostCommands[i].m_nParam1, m_tPostCommands[i].m_nParam2);
		}
	}

	if ( m_nCommandCount > nCommand )
	{
		// ˵����ִ�������ڼ������µ�����ͽ�����
		m_nCommandCount -= nCommand;
		for ( i = 0; i < m_nCommandCount; ++i )
			m_tPostCommands[i] = m_tPostCommands[i + nCommand];

		// ����ִ������
		PostCommandRouter();
	}
	else
	{
		m_nCommandCount = 0;
	}
}

// ����·�ɣ����ȴ��ݸ�Ӧ�ó����࣬Ȼ�󴫵ݸ����㴰�ڣ����ĳ���ط������˸���Ϣ����Ͳ��ٴ�����
void CAwsUi::CommandRouter(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	bool bIsProcessed = false;

	if ( ESP_NULL != m_pApp )
		bIsProcessed = m_pApp->OnCommand(nWndID, nCmdID, nParam1, nParam2);

	if ( !bIsProcessed && ESP_NULL != m_pCurTopWnd )
	{
		CAwsWindow* pWnd = m_pCurTopWnd;
		while ( ESP_NULL != pWnd && !pWnd->OnCommand(nWndID, nCmdID, nParam1, nParam2) )
			pWnd = pWnd->GetFocusSubWnd();
	}
}
