/******************************************************************************
* FileName		       : BProgressBar.cpp
* Description          : implementation of the CBProgressBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BProgressBar.h"
#include "IAwsGc.h"

CBProgressBar::CBProgressBar()
{
	m_nLength = 0;
	m_nCurPos = 0;
	m_nDrawPos = 0;

	CAwsRgb rgbBK(255, 255, 255), rgbProgress(0, 0, 255), rgbBorder(30, 26, 18);
	m_oBKColor = rgbBK;
	m_oProgressColor = rgbProgress;
	m_oBorderColor = rgbBorder;

	m_nBorderPixels = 1;
}

void CBProgressBar::OnCreate()
{
	// 加载图片等资源
}

void CBProgressBar::SetPos(int nPos)
{
	int n = m_nCurPos;
	m_nCurPos = nPos;
	if ( nPos < n )
	{
		Invalide();
	}
	else
	{
		// 部分更新即可
		CEspRect rect;
		CEspSize size = *GetSize();
		rect.m_ptLT.m_nY = m_nBorderPixels;
		rect.m_ptRB.m_nY = size.m_nHeight - m_nBorderPixels;

		rect.m_ptLT.m_nX = m_nBorderPixels + (n * (size.m_nWidth - 2)) / m_nLength;
		rect.m_ptRB.m_nX = m_nBorderPixels + (m_nCurPos * (size.m_nWidth - 2)) / m_nLength;

		InvalideRect(rect);
	}
}

void CBProgressBar::OnDrawBK(IAwsGc* pGc, const CEspRect& rect)
{
	pGc->SetPenColor(m_oBKColor);
	pGc->SetBrushColor(m_oBKColor);
	pGc->DrawFillRect(rect);
}

void CBProgressBar::OnDrawBorder(IAwsGc* pGc, const CEspRect& rect)
{
	pGc->SetPenColor(m_oBorderColor);
	pGc->DrawRect(rect);
}

void CBProgressBar::OnDrawProgress(IAwsGc* pGc, const CEspRect& rect)
{
	if ( m_nCurPos > 0 )
	{
		pGc->SetPenColor(m_oProgressColor);
		pGc->SetBrushColor(m_oProgressColor);

		pGc->DrawFillRect(rect);
	}
}

void CBProgressBar::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();

	CEspSize size = *GetSize();
	CEspRect rtTemp;
	CEspRect rt(0, 0, size.m_nWidth, size.m_nHeight);

	// 画边框
	OnDrawBorder(pGc, rt);

	// 画进度
	rt.m_ptLT.m_nY = m_nBorderPixels;
	rt.m_ptRB.m_nY = size.m_nHeight - m_nBorderPixels;
	rt.m_ptLT.m_nX = m_nBorderPixels;
	rt.m_ptRB.m_nX = m_nBorderPixels + (m_nCurPos * (size.m_nWidth - 2)) / m_nLength;
	if ( rect.InterRect(rt, rtTemp) )
	{
		OnDrawProgress(pGc, rtTemp);
	}

	// 画背景
	rt.m_ptLT.m_nX = m_nBorderPixels + (m_nCurPos * (size.m_nWidth - 2)) / m_nLength;
	rt.m_ptRB.m_nX = m_nBorderPixels + (size.m_nWidth - 2);
	if ( rect.InterRect(rt, rtTemp) )
	{
		OnDrawBK(pGc, rtTemp);
	}
	/*
	if ( 0 == rect.m_ptLT.m_nX )
	{
		// 画背景
		OnDrawBK(pGc, rect);

		// 画边框
		OnDrawBorder(pGc, rect);
		// 画进度
		CAwsRect rt;
		rt.m_ptLT.m_nX = m_nBorderPixels;
		rt.m_ptLT.m_nY = m_nBorderPixels;
		rt.m_ptRB.m_nX = (m_nCurPos * rect.m_ptRB.m_nX) / m_nLength;
		rt.m_ptRB.m_nY = rect.m_ptRB.m_nY - m_nBorderPixels;
		OnDrawProgress(pGc, rt);
	}
	else
	{
		OnDrawProgress(pGc, rect);
	}
	*/
}
