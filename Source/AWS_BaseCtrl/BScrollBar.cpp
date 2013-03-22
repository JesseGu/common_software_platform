/******************************************************************************
* FileName		       : BScrollBar.cpp
* Description          : implementation of the CBScrollBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BScrollBar.h"
#include "IAwsGc.h"

CBScrollBar::CBScrollBar()
{
	m_eDir = ESB_Vertical;
	m_nTotalLength = 0;
	m_nCurPos = 0;

	m_nMinBlockDim = 10;
	m_nMaxScrolldis = 20;

	CAwsRgb rgbBlock(0, 255, 0), rgbBK(117, 125, 138);
	m_oBlockColor = rgbBlock;
	m_oBKColor = rgbBK;
}

void CBScrollBar::SetTotalLength(int nTotal)
{
	m_nTotalLength = nTotal;

	CEspSize size = *GetSize();

	int nWndDim;
	if ( ESB_Vertical == m_eDir )
	{
		nWndDim = size.m_nHeight;
	}
	else if ( ESB_Horizontal == m_eDir )
	{
		nWndDim = size.m_nWidth;
	}

	if ( nWndDim - (m_nTotalLength - 1) * m_nMaxScrolldis < m_nMinBlockDim )
	{
		m_nCurBlockDim = m_nMinBlockDim;
		m_fCurScrolldis = (float)(nWndDim - m_nMinBlockDim) / (m_nTotalLength - 1);
	}
	else
	{
		m_fCurScrolldis = (float)m_nMaxScrolldis;
		m_nCurBlockDim = nWndDim - (m_nTotalLength - 1) * m_nMaxScrolldis;
	}
}

void CBScrollBar::SetCurPos(int nCur)
{
	if ( nCur < m_nTotalLength )
	{
		m_nCurPos = nCur;
		Invalide();
	}
}

void CBScrollBar::DrawBK(IAwsGc* pGc, const CEspRect& rect)
{
	pGc->SetPenColor(m_oBKColor);
	pGc->SetBrushColor(m_oBKColor);
	pGc->DrawFillRect(rect);
}

void CBScrollBar::DrawBlock(IAwsGc* pGc, const CEspRect& rect)
{
	pGc->SetPenColor(m_oBlockColor);
	pGc->SetBrushColor(m_oBlockColor);
	pGc->DrawFillRect(rect);
}

void CBScrollBar::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();

	if ( ESP_NULL != pGc )
	{
		// »­±³¾°
		DrawBK(pGc, rect);

		// »­¿é
		CEspRect rt;
		if ( ESB_Vertical == m_eDir )
		{
			rt.m_ptLT.m_nX = 0;
			rt.m_ptLT.m_nY = (int)(m_nCurPos * m_fCurScrolldis);
			rt.m_ptRB.m_nX = GetSize()->m_nWidth;
			rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nCurBlockDim;
		}
		else if ( ESB_Horizontal == m_eDir )
		{
			rt.m_ptLT.m_nX = (int)(m_nCurPos * m_fCurScrolldis);
			rt.m_ptLT.m_nY = 0;
			rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nCurBlockDim;
			rt.m_ptRB.m_nY = GetSize()->m_nHeight;
		}

		DrawBlock(pGc, rt);
	}
}
