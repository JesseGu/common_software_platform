/******************************************************************************
* FileName		       : MScrollLabel.cpp
* Description          : implementation of the CMScrollLabel class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "MScrollLabel.h"
#include "IAwsGc.h"

CMScrollLabel::CMScrollLabel()
{
	m_nScrollCount = 0;
	m_nCurCount = 0;
	m_nMoveLength = 0;

	m_nMoveStep = 5;
	m_nTextLen = -1;
	m_nTimes = 150;
}

void CMScrollLabel::OnCreate()
{
	CBLabel::OnCreate();

	m_oSizeWnd = *GetSize();
}

void CMScrollLabel::StartScroll(int nCount)
{
	m_nScrollCount = nCount;
	m_nCurCount = 0;
	StartTimer(m_nTimes);
}

void CMScrollLabel::EndScroll()
{
	if ( m_nScrollCount > 0 )
	{
		m_nScrollCount = 0;
		m_nMoveLength = 0;
		m_nCurCount = 0;
		Invalide();
		EndTimer();

		PumpCommand(m_nWndID, AWS_SysCmd_ScrollLabelEndScroll);
	}
}

void CMScrollLabel::DrawText(IAwsGc* pGc, const CEspRect& rect)
{
	CEspRect rt = rect;
	rt.m_ptLT.m_nX += m_nMoveLength;

	if ( -1 == m_nTextLen )
	{
		m_nTextLen = pGc->GetTextSize(m_oStrText)->m_nWidth;
	}

	pGc->DrawText(m_oStrText, rt);
}

void CMScrollLabel::OnTimer()
{
	if ( m_nCurCount < m_nScrollCount )
	{
		// 
		if ( m_nMoveLength + m_nTextLen > 0 )
		{
			// 继续移动
			m_nMoveLength -= m_nMoveStep;
			Invalide();
		}
		else
		{
			// 一次移动完毕
			++m_nCurCount;
			m_nMoveLength = m_nMoveStep;
		}
	}
	else
	{
		// 自动结束滚动
		EndScroll();
	}
}
