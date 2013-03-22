/******************************************************************************
* FileName		       : BButton.cpp
* Description          : implementation of the CBButton class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BButton.h"
#include "IAwsGc.h"

CBButton::CBButton()
{
	m_nFontSize = 12;

	m_eTextAlignMode = AWS_TAM_Mid;

	CAwsRgb rgbBorder(0, 0, 0), rgbBK(236, 233, 216), rgbText(0, 0, 0), rgbFocus(255, 0, 0);

	m_oBorderColor = rgbBorder;
	m_oBKColor = rgbBK;
	m_oTextColor = rgbText;
	m_oTextFocusColor = rgbFocus;
}

void CBButton::SetText(const CAwsString& strText)
{
	m_oText = strText;
	Invalide();
}

void CBButton::DrawBK(IAwsGc* pGc, const CEspRect& rect)
{
	pGc->SetPenColor(m_oBorderColor);
	pGc->SetBrushColor(m_oBKColor);
	pGc->DrawFillRect(rect);
}

void CBButton::DrawText(IAwsGc* pGc, const CEspRect& rect)
{
	m_oFont.CreateFont(0, m_nFontSize);
	pGc->UseFont(m_oFont);

	CEspRect rt = rect;
	const CEspSize* size = pGc->GetTextSize(m_oText);
	rt.m_ptLT.m_nY += (rt.GetSize()->m_nHeight - size->m_nHeight) / 2;

	pGc->SetTextAlignment(m_eTextAlignMode);

	if ( m_bIsFocus )
	{
		pGc->SetTextColor(m_oTextFocusColor);
	}
	else
	{
		pGc->SetTextColor(m_oTextColor);
	}

	pGc->DrawText(m_oText, rt);
}

void CBButton::DrawInf(IAwsGc* pGc, const CEspRect& rect)
{
	DrawText(pGc, rect);
}

void CBButton::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();

	CEspSize size = *GetSize();
	CEspRect rt(0, 0, size.m_nWidth, size.m_nHeight);

	if ( ESP_NULL != pGc )
	{
		// ª≠±≥æ∞
		if ( !m_bIsBKTransparent )
			DrawBK(pGc, rt);

		// œ‘ æ–≈œ¢
		DrawInf(pGc, rt);
	}
}

void CBButton::OnClick()
{
	PumpCommand(m_nWndID, AWS_SysCmd_ButtonCmd);
}

bool CBButton::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	if ( AWS_Key == type )
	{
		switch ( code )
		{
		case AWS_KeyCode_OK:
			OnClick();
			return true;
		}
	}

	return CAwsWindow::OnKey(type, code);
}

void CBButton::OnFocus(bool bIsFocus)
{
	CAwsWindow::OnFocus(bIsFocus);

	Invalide();
}
