/******************************************************************************
* FileName		       : BRadioBox.cpp
* Description          : implementation of the CBRadioBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BRadioBox.h"
#include "IAwsGc.h"

CBRadioBox::CBRadioBox()
{
	m_bIsSelect = false;

	m_nIconSize.m_nHeight = 12;
	m_nIconSize.m_nWidth = 12;
	m_nSelectDim = 4;

	CAwsRgb rgbBorder(89, 104, 160), rgbFocusBorder(241, 108, 13), rgbBK(255, 255, 255), rgbSelect(83, 106, 147);
	m_oBorderColor = rgbBorder;
	m_oFocusBorderColor = rgbFocusBorder;
	m_oBKColor = rgbBK;
	m_oSelectColor = rgbSelect;

	m_bIsBKTransparent = true;

	m_oTextFocusColor = m_oTextColor;
}

void CBRadioBox::SetSelected(bool bIsSelect)
{ 
	bool b = m_bIsSelect;
	m_bIsSelect = bIsSelect;

	if ( b != m_bIsSelect )
		Invalide();
}

void CBRadioBox::SetImage(const CAwsImage& image, const CAwsImage& imageFocus, const CAwsImage& imageSel, const CAwsImage& imageSelFocus, const CAwsImage& imageMask)
{
	m_oImage = image;
	m_oImageFocus = imageFocus;
	m_oImageSel = imageSel;
	m_oImageSelFocus = imageSelFocus;
	m_oImageMask = imageMask;
}

void CBRadioBox::DrawIcon(IAwsGc* pGc, const CEspRect& rect)
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
		pGc->DrawEllipse(rt);

		if ( m_bIsSelect )
		{
			rt.m_ptLT.m_nX += ( m_nIconSize.m_nWidth - m_nSelectDim) / 2;
			rt.m_ptLT.m_nY += (m_nIconSize.m_nHeight - m_nSelectDim) / 2;
			rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nSelectDim;
			rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nSelectDim;

			pGc->SetPenColor(m_oSelectColor);
			pGc->SetBrushColor(m_oSelectColor);
			pGc->DrawEllipse(rt);
		}
	}
}

void CBRadioBox::OnClick()
{
	if ( !m_bIsSelect )
	{
		m_bIsSelect = true;
		Invalide();
	}

	CBButton::OnClick();
}
