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

// 一般只有主容器有Ui，所以要跳到主容器中
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

// 有可能是窗口位置和大小都改变了
void CAwsWindow::MoveTo(const CEspRect& rect, bool bIsRedraw /*= true*/)
{
	// 如果是顶层窗口则无法移动了
	if ( ESP_NULL != m_pParent /*&& rect != m_tRect*/ )
	{
		CEspRect rtOld = m_tRect;
		m_tRect = rect;

		// 通知父窗口刷新该窗口以前的位置
		CEspSize sizeParent = *m_pParent->GetSize();
		if ( rtOld.m_ptRB.m_nX <= sizeParent.m_nWidth && rtOld.m_ptRB.m_nY <= sizeParent.m_nWidth && bIsRedraw )
		{
			m_pParent->InvalideRect(rtOld);
		}

		m_tOrigin = m_pParent->GetOrigin();
		m_tOrigin += m_tRect.m_ptLT;

		// 窗口大小改变通知，这时不需要刷新，只是通知子窗口调整自己的位置和大小
		OnSize(*m_tRect.GetSize(), false);

		// 刷新自己的新区域
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
		// 如果是透明的则调用父窗口的InvalideRect函数
		if ( m_bIsBKTransparent )
		{
			// 转换成父窗口坐标
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
	// 增加焦点窗口改变

	if ( bIsVisible && !m_bIsVisible)
	{
		m_bIsVisible = true;

		// 重新绘制自己
		if ( bIsReDraw )
			Invalide();
	}
	else if ( !bIsVisible && m_bIsVisible )
	{
		m_bIsVisible = false;
		// 通知父窗口绘制
		if ( bIsReDraw )
			m_pParent->InvalideRect(m_tRect);
	}
}

void CAwsWindow::ConvertCoordinate(CEspRect& rect)
{
	// 转换为自己的坐标
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
	// 获取Gc
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
