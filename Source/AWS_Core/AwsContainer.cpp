/******************************************************************************
* FileName		       : AwsContainer.cpp
* Description          : implementation of the CAwsContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "AwsContainer.h"
#include "IAwsGc.h"

CAwsContainer::CAwsContainer(int nMaxSubWndCount)
{
	if ( nMaxSubWndCount > 0 )
		m_pSubWndData = new CAwsWindow*[nMaxSubWndCount];
	else
		m_pSubWndData = ESP_NULL;
	m_nSubWndCount = 0;
	m_nMaxSubWndCount = nMaxSubWndCount;

	if ( nMaxSubWndCount > 0 )
		m_pFocusWndData = new CAwsWindow*[nMaxSubWndCount];
	else
		m_pFocusWndData = ESP_NULL;
	m_nFocusWndCount = 0;
	m_nFocusWndIndex = 0;
	m_pFocusWnd = ESP_NULL;

	m_nPopWndCount = 0;
}

CAwsContainer::~CAwsContainer()
{
	int i;
	for ( i = 0; i < m_nSubWndCount; ++i )
		delete m_pSubWndData[i];

	delete []m_pSubWndData;
	delete []m_pFocusWndData;
}

void CAwsContainer::OnCreate()
{
	// ����ӿؼ�
}

CAwsWindow* CAwsContainer::GetWndFromID(int nWndID)
{
	CAwsWindow* pWnd = ESP_NULL;

	if ( nWndID > 0 )
	{
		int i;
		for ( i = 0; i < m_nSubWndCount; ++i )
		{
			if ( nWndID == m_pSubWndData[i]->GetWndID() )
			{
				pWnd = m_pSubWndData[i];
				break;
			}
		}
	}

	return pWnd;
}

void CAwsContainer::SetFocus(CAwsWindow* pSubWnd)
{
	if ( ESP_NULL != pSubWnd )
	{
		int i;
		for ( i = 0; i < m_nFocusWndCount; ++i )
		{
			if ( m_pFocusWndData[i] == pSubWnd )
				break;
		}

		if ( i < m_nFocusWndCount )
		{
			// �ҵ�
			if ( ESP_NULL != m_pFocusWnd )
			{
				m_pFocusWnd->OnFocus(false);
			}
			m_pFocusWnd = pSubWnd;
			m_nFocusWndIndex = i;
			m_pFocusWnd->OnFocus(true);
		}
	}
}

void CAwsContainer::PopWnd(CAwsWindow* pWnd, const CEspRect& rect, int nWndID)
{
	// �ҵ����㴰�ڣ��ڶ��㴰���е�������ʽ����
	CAwsContainer* pParent = (CAwsContainer*)GetParent();
	if ( ESP_NULL != pParent )
	{
		pParent->PopWnd(pWnd, rect, nWndID);
	}
	else
	{
		// �ɶ���Ĵ��ڵ���
		pWnd->Create(this, rect, nWndID);

		if ( AddSubWnd(pWnd, false) )
		{
			if ( 0 == m_nPopWndCount  && ESP_NULL != m_pFocusWnd )
			{
				// ���㴰��ʧȥ����
				m_pFocusWnd->OnFocus(false);
			}

			++m_nPopWndCount;

			// ������ʽ����
			pWnd->Invalide();
		}
		else
		{
			// ʧ����
			delete pWnd;
		}
	}
}

// ע��Pop���ڶ�λ�����ϲ�
void CAwsContainer::DestroyPopWnd(int nCount)
{
	// �ҵ����㴰��
	if ( nCount > 0 )
	{
		CAwsContainer* pParent = (CAwsContainer*)GetParent();
		if ( ESP_NULL != pParent )
		{
			pParent->DestroyPopWnd(nCount);
		}
		else if ( m_nPopWndCount > 0 )
		{
			if ( nCount > m_nPopWndCount )
				nCount = m_nPopWndCount;

			while ( nCount > 0 )
			{
				--m_nPopWndCount;

				DeleteWindow(m_pSubWndData[m_nSubWndCount - 1], true);

				--nCount;
			}

			if ( 0 == m_nPopWndCount && ESP_NULL != m_pFocusWnd )
			{
				// ���㴰�����»�ý���
				m_pFocusWnd->OnFocus(true);
			}
		}
	}
}

// ɾ��һ������
void CAwsContainer::DeleteWindow(CAwsWindow* pWnd, bool bIsRedraw /*= true*/)
{
	if ( ESP_NULL != pWnd )
	{
		CAwsContainer* pParent = (CAwsContainer*)pWnd->GetParent();

		if ( ESP_NULL != pParent )
		{
			int i, j;
			for ( i = 0; i < pParent->m_nSubWndCount; ++i )
			{
				if ( pWnd == pParent->m_pSubWndData[i] )
				{
					// �ҵ������Ӵ������Ƴ��ô���
					for ( j = i; j < pParent->m_nSubWndCount - 1; ++j )
						pParent->m_pSubWndData[j] = pParent->m_pSubWndData[j + 1];
					--pParent->m_nSubWndCount;

					// ��Focus�������Ƴ�
					int ii, jj;
					for ( ii = 0; ii < pParent->m_nFocusWndCount; ++ii )
					{
						if ( pWnd == pParent->m_pFocusWndData[ii] )
						{
							// �ҵ�
							for ( jj = ii; jj < pParent->m_nFocusWndCount; ++jj )
								pParent->m_pFocusWndData[jj] = pParent->m_pFocusWndData[jj + 1];
							-- pParent->m_nFocusWndCount;

							// ���㴰�ڵ��л�����һ�����㴰���Զ���ȡ����
							if ( pParent->m_nFocusWndIndex >= pParent->m_nFocusWndCount )
							{
								if ( pParent->m_nFocusWndCount > 0 )
								{
									pParent->m_nFocusWndIndex = pParent->m_nFocusWndCount - 1;
									pParent->m_pFocusWnd = pParent->m_pFocusWndData[pParent->m_nFocusWndIndex];
								}
								else
								{
									pParent->m_nFocusWndIndex = 0;
									pParent->m_pFocusWnd = ESP_NULL;
								}
							}
							break;
						}
					}
					break;
				}
			}
		}

		if ( bIsRedraw && ESP_NULL != pParent )
		{
			InvalideRect(pWnd->GetRect());
		}
		// ����ϵͳ�ں��ʵ�ʱ�򽫸ô���ɾ����
		PostCommand(m_nWndID, AWS_SysCmd_DeleteWnd, (int)pWnd);
	}
}

bool CAwsContainer::AddSubWnd(CAwsWindow* pWnd, bool bIsNeedFocus)
{
	bool bRet = true;

	if ( ESP_NULL != pWnd && m_nSubWndCount < m_nMaxSubWndCount )
	{
		m_pSubWndData[m_nSubWndCount++] = pWnd;

		if ( bIsNeedFocus )
		{
			m_pFocusWndData[m_nFocusWndCount++] = pWnd;

			// �ı佹�㴰��
			m_nFocusWndIndex = m_nFocusWndCount - 1;
			m_pFocusWnd = pWnd;
		}
	}
	else
	{
		bRet = false;
	}

	return bRet;
}

void CAwsContainer::OnDraw(const CEspRect& rect)
{
	// ��������Ļ��ƺ���
	IAwsGc* pGc = GetGc();

	if ( m_nSubWndCount > 0 )
	{
		int i;
		for ( i = 0; i < m_nSubWndCount; ++i )
		{
			if ( m_pSubWndData[i]->IsVisible() )
			{
				// �ؼ����ػ������н���ͻ�
				CEspRect rt;
				if ( rect.InterRect(m_pSubWndData[i]->GetRect(), rt) )
				{
					// ת������
					m_pSubWndData[i]->ConvertCoordinate(rt);
					m_pSubWndData[i]->OnDraw(rt);
				}
			}
		}
	}
}

bool CAwsContainer::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	bool bRet = false;

	// ���Ƚ���Ϣ��������ĵ���ʽ���ڣ�������ʽ����û�����������ӿؼ�����Ѱ���㴰��
	if ( m_nPopWndCount > 0 )
	{
		bRet = m_pSubWndData[m_nSubWndCount - 1]->OnKey(type, code);
	}

	if ( !bRet && m_nFocusWndCount > 0 )
	{
		// ֪ͨ�ӽ��㴰��
		bRet = m_pFocusWnd->OnKey(type, code);
	}

	return bRet;
}

void CAwsContainer::OnSize(const CEspSize& size, bool bIsRedraw /*= true*/)
{
	CAwsWindow::OnSize(size, bIsRedraw);

	if ( m_nSubWndCount > 0 )
	{
		int i;
		for ( i = 0; i < m_nSubWndCount; ++i )
		{
			// Ĭ�ϵ�OnSize�����У��ӿؼ��п��ܻᳬ����Size�ķ�Χ
			CEspRect rect = m_pSubWndData[i]->GetRect();
			if ( rect.m_ptRB.m_nX <= size.m_nWidth && rect.m_ptRB.m_nY <= size.m_nHeight )
				m_pSubWndData[i]->MoveTo(m_pSubWndData[i]->GetRect(), bIsRedraw);
		}
	}
}

void CAwsContainer::OnFocus(bool bIsFocus)
{
	CAwsWindow::OnFocus(bIsFocus);

	// ֪ͨ�ӽ��㴰��
	if ( m_nFocusWndCount > 0 )
	{
		m_pFocusWnd = m_pFocusWndData[m_nFocusWndIndex];
		m_pFocusWnd->OnFocus(bIsFocus);
	}
}

void CAwsContainer::OnTimer()
{
	CAwsWindow::OnTimer();

	// ֪ͨ�ӽ��㴰��
	if ( m_nFocusWndCount > 0 )
	{
		m_pFocusWnd->OnTimer();
	}
}

void CAwsContainer::OnImeChar(short nChar)
{
	// ֪ͨ�ӽ��㴰��
	if ( m_nFocusWndCount > 0 )
	{
		m_pFocusWnd->OnImeChar(nChar);
	}
}

void CAwsContainer::PreFocusWnd()
{
	if ( m_nFocusWndCount > 0 )
	{
		if ( 0 == m_nFocusWndIndex )
		{
			m_nFocusWndIndex = m_nFocusWndCount - 1;
		}
		else
		{
			--m_nFocusWndIndex;
		}

		m_pFocusWnd->OnFocus(false);
		m_pFocusWnd = m_pFocusWndData[m_nFocusWndIndex];
		m_pFocusWnd->OnFocus(true);
	}
}

void CAwsContainer::NextFocusWnd()
{
	if ( m_nFocusWndCount > 0 )
	{
		if ( m_nFocusWndCount - 1 == m_nFocusWndIndex )
		{
			m_nFocusWndIndex = 0;
		}
		else
		{
			++m_nFocusWndIndex;
		}

		m_pFocusWnd->OnFocus(false);
		m_pFocusWnd = m_pFocusWndData[m_nFocusWndIndex];
		m_pFocusWnd->OnFocus(true);
	}
}
