/******************************************************************************
* FileName		       : BLabel.cpp
* Description          : implementation of the CBLabel class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BLabel.h"
#include "IAwsGc.h"

CBLabel::CBLabel()
{
	CAwsRgb rgbText(0, 0, 0), rgbBK(255, 255, 255);
	m_oTextColor = rgbText;
	m_oBKColor = rgbBK;

	m_nTextSize = 12;
	m_eAlignMode = AWS_TAM_Left;
}

void CBLabel::SetText(const CAwsString& str, bool bIsRedraw /*= false*/)
{
	m_oStrText = str;

	if ( bIsRedraw )
		Invalide();
}

void CBLabel::SetTextColor(const CAwsRgb& color, bool bIsRedraw /*= false*/)
{
	m_oTextColor = color;

	if ( bIsRedraw )
		Invalide();
}

void CBLabel::SetBKColor(const CAwsRgb& color, bool bIsRedraw /*= false*/)
{
	m_oBKColor = color;

	if ( bIsRedraw )
		Invalide();
}

void CBLabel::SetTextAlignment(AWS_TextAlignMode mode, bool bIsRedraw /*= false*/)
{
	m_eAlignMode = mode;

	if ( bIsRedraw )
		Invalide();
}

void CBLabel::DrawText(IAwsGc* pGc, const CEspRect& rect)
{
	pGc->DrawText(m_oStrText, rect);
}

void CBLabel::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();

	if ( !m_bIsBKTransparent )
	{
		pGc->SetPenColor(m_oBKColor);
		pGc->SetBrushColor(m_oBKColor);
		pGc->DrawFillRect(rect);
	}

	m_oFont.CreateFont(0, m_nTextSize);
	pGc->UseFont(m_oFont);

	pGc->SetTextColor(m_oTextColor);
	pGc->SetTextAlignment(m_eAlignMode);
	pGc->SetTextBKMode(AWS_TSM_Transparent);

	DrawText(pGc, rect);
}
