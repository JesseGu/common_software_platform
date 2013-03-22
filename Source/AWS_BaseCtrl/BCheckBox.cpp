/******************************************************************************
* FileName		       : BCheckBox.cpp
* Description          : implementation of the CBCheckBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BCheckBox.h"
#include "IAwsGc.h"

CBCheckBox::CBCheckBox()
{
	m_bIsSelect = false;

	m_nIconSize.m_nHeight = 12;
	m_nIconSize.m_nWidth = 12;

	CAwsRgb rgbBorder(89, 104, 160), rgbFocus(255, 108, 0), rgbBK(255, 255, 255), rgbSelect(0, 0, 0);
	m_oBorderColor = rgbBorder;
	m_oFocusBorderColor = rgbFocus;
	m_oBKColor = rgbBK;
	m_oSelectColor = rgbSelect;

	m_bIsBKTransparent = true;

	m_oTextFocusColor = m_oTextColor;
}

void CBCheckBox::SetSelected(bool bIsSelect)
{ 
	bool b = m_bIsSelect;
	m_bIsSelect = bIsSelect;

	if ( b != m_bIsSelect )
		Invalide();
}

void CBCheckBox::SetImage(const CAwsImage& image, const CAwsImage& imageFocus, const CAwsImage& imageSel, const CAwsImage& imageSelFocus, const CAwsImage& imageMask)
{
	m_oImage = image;
	m_oImageFocus = imageFocus;
	m_oImageSel = imageSel;
	m_oImageSelFocus = imageSelFocus;
	m_oImageMask = imageMask;
}

void CBCheckBox::DrawIcon(IAwsGc* pGc, const CEspRect& rect)
{
	CEspRect rt = rect;

	if ( m_oImage.GetID() > 0 )
	{
		// ÌùÍ¼
		if ( m_bIsFocus )
		{
			if ( m_bIsSelect )
				pGc->DrawImage(rect.m_ptLT, m_oImageSelFocus, &m_oImageMask);
			else
				pGc->DrawImage(rect.m_ptLT, m_oImageFocus, &m_oImageMask);
		}
		else
		{
			if ( m_bIsSelect )
				pGc->DrawImage(rect.m_ptLT, m_oImageSel, &m_oImageMask);
			else
				pGc->DrawImage(rect.m_ptLT, m_oImage, &m_oImageMask);
		}
	}
	else
	{
		// »­Í¼±ê
		if ( m_bIsFocus )
		{
			pGc->SetPenColor(m_oFocusBorderColor);
		}
		else
		{
			pGc->SetPenColor(m_oBorderColor);
		}
		pGc->SetBrushColor(m_oBKColor);
		pGc->DrawFillRect(rt);

		if ( m_bIsSelect )
		{
			pGc->SetPenWidth(2);
			pGc->SetPenColor(m_oSelectColor);

			CEspPoint ptStart, ptEnd;
			ptStart.m_nX = rt.m_ptLT.m_nX + 2;
			ptStart.m_nY = rt.m_ptLT.m_nY + 2;
			ptEnd.m_nX = rt.m_ptRB.m_nX - 2;
			ptEnd.m_nY = rt.m_ptRB.m_nY - 2;
			pGc->DrawLine(ptStart, ptEnd);

			ptStart.m_nX = rt.m_ptLT.m_nX + 2;
			ptStart.m_nY = rt.m_ptRB.m_nY - 2;
			ptEnd.m_nX = rt.m_ptRB.m_nX - 2;
			ptEnd.m_nY = rt.m_ptLT.m_nY + 2;
			pGc->DrawLine(ptStart, ptEnd);

			pGc->SetPenWidth(1);
		}
	}
}

void CBCheckBox::OnClick()
{
	m_bIsSelect = !m_bIsSelect;
	Invalide();

	CBButton::OnClick();
}
