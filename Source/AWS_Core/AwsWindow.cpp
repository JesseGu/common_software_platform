/******************************************************************************
* FileName		       : AwsWindow.cpp
* Description          : implementation of the CAwsWindow class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "AwsWindow.h"

#include "IAwsGc.h"
#include "AwsUi.h"

CAwsWindow::CAwsWindow()
{
	m_pParent = ESP_NULL;
	m_pGc = ESP_NULL;

	m_pUi = ESP_NULL;

	m_bIsVisible = true;
	m_bIsFocus = false;

	m_bIsBKTransparent = false;
}

// һ��ֻ����������Ui������Ҫ������������
CAwsUi* CAwsWindow::GetUi()
{
	if ( ESP_NULL != m_pParent )
	{
		return m_pParent->GetUi();
	}
	else
	{
		return m_pUi;
	}
}

void CAwsWindow::Create(CAwsWindow* pParent, const CEspRect& rect, int nID, bool bIsVisible)
{
	m_nWndID = nID;

	m_pParent = pParent;
	m_tRect = rect;

	if ( ESP_NULL != m_pParent )
	{
		m_tOrigin = m_pParent->GetOrigin();
		m_tOrigin += m_tRect .m_ptLT;
	}
	else
	{
		m_tOrigin = m_tRect .m_ptLT;
	}

	m_bIsVisible = bIsVisible;

	OnCreate();
}

// �п����Ǵ���λ�úʹ�С���ı���
void CAwsWindow::MoveTo(const CEspRect& rect, bool bIsRedraw /*= true*/)
{
	// ����Ƕ��㴰�����޷��ƶ���
	if ( ESP_NULL != m_pParent /*&& rect != m_tRect*/ )
	{
		CEspRect rtOld = m_tRect;
		m_tRect = rect;

		// ֪ͨ������ˢ�¸ô�����ǰ��λ��
		CEspSize sizeParent = *m_pParent->GetSize();
		if ( rtOld.m_ptRB.m_nX <= sizeParent.m_nWidth && rtOld.m_ptRB.m_nY <= sizeParent.m_nWidth && bIsRedraw )
		{
			m_pParent->InvalideRect(rtOld);
		}

		m_tOrigin = m_pParent->GetOrigin();
		m_tOrigin += m_tRect.m_ptLT;

		// ���ڴ�С�ı�֪ͨ����ʱ����Ҫˢ�£�ֻ��֪ͨ�Ӵ��ڵ����Լ���λ�úʹ�С
		OnSize(*m_tRect.GetSize(), false);

		// ˢ���Լ���������
		if ( bIsRedraw )
			Invalide();
	}
}

void CAwsWindow::Invalide()
{
	CEspRect rtInvalide;
	rtInvalide.m_ptRB.m_nX = m_tRect.m_ptRB.m_nX - m_tRect.m_ptLT.m_nX;
	rtInvalide.m_ptRB.m_nY = m_tRect.m_ptRB.m_nY - m_tRect.m_ptLT.m_nY;
	InvalideRect(rtInvalide);
}

void CAwsWindow::InvalideRect(const CEspRect& rect)
{
	if ( m_bIsVisible )
	{
		// �����͸��������ø����ڵ�InvalideRect����
		if ( m_bIsBKTransparent )
		{
			// ת���ɸ���������
			CEspRect rt = rect;
			rt.m_ptLT += m_tRect.m_ptLT;
			rt.m_ptRB += m_tRect.m_ptLT;
			m_pParent->InvalideRect(rt);
		}
		else
		{
			Draw(rect);
		}
	}
}

void CAwsWindow::SetVisible(bool bIsVisible, bool bIsReDraw)
{
	// ���ӽ��㴰�ڸı�

	if ( bIsVisible && !m_bIsVisible)
	{
		m_bIsVisible = true;

		// ���»����Լ�
		if ( bIsReDraw )
			Invalide();
	}
	else if ( !bIsVisible && m_bIsVisible )
	{
		m_bIsVisible = false;
		// ֪ͨ�����ڻ���
		if ( bIsReDraw )
			m_pParent->InvalideRect(m_tRect);
	}
}

void CAwsWindow::ConvertCoordinate(CEspRect& rect)
{
	// ת��Ϊ�Լ�������
	rect.m_ptLT -= m_tRect.m_ptLT;
	rect.m_ptRB -= m_tRect.m_ptLT;
}

void CAwsWindow::PumpCommand(int nWndID, int nCmdID, int nParam1 /*= 0*/, int nParam2 /*= 0*/)
{
	GetUi()->CommandRouter(nWndID, nCmdID, nParam1, nParam2);
}

void CAwsWindow::PostCommand(int nWndID, int nCmdID, int nParam1 /*= 0*/, int nParam2 /*= 0*/)
{
	GetUi()->AddPostCommand(nWndID, nCmdID, nParam1, nParam2);
}

bool CAwsWindow::StartTimer(int nTimer)
{
	return GetUi()->StartTimer(this, nTimer);
}

void CAwsWindow::EndTimer()
{
	GetUi()->EndTimer(this);
}

void CAwsWindow::OnFocus(bool bIsFocus)
{
	m_bIsFocus = bIsFocus;
}

IAwsGc* CAwsWindow::GetGc()
{
	// ��ȡGc
	IAwsGc* pGc = ESP_NULL;
	CAwsUi* pUi = GetUi();
	if ( ESP_NULL != pUi )
	{
		pGc = pUi->GetSysGc();

		if ( ESP_NULL != pGc )
		{
			CEspPoint pt = GetOrigin();
			pGc->SetOrigin(pt);
		}
	}

	return pGc;
}

void CAwsWindow::Draw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();
	if ( ESP_NULL != pGc )
	{
		pGc->SetClipRect(rect);
		OnDraw(rect);
		pGc->ResetClipRect();
	}
}
