/******************************************************************************
* FileName		       : BImageButton.cpp
* Description          : implementation of the CBImageButton class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BImageButton.h"
#include "IAwsGc.h"

CBImageButton::CBImageButton()
{
	m_eMode = MIBMode_IconLeft;

	m_nIconSize.m_nWidth = 12;
	m_nIconSize.m_nHeight = 12;
}

void CBImageButton::SetImage(const CAwsImage& image, const CAwsImage& imageMask)
{
	m_oImage = image;
	m_oImageMask = imageMask;
}

void CBImageButton::DrawIcon(IAwsGc* pGc, const CEspRect& rect)
{
	if ( m_oImage.GetID() > 0 )
	{
		pGc->DrawImage(rect.m_ptLT, m_oImage, &m_oImageMask);
	}
}

void CBImageButton::DrawInf(IAwsGc* pGc, const CEspRect& rect)
{
	CEspRect rt;
	CEspRect rtText = rect;

	switch ( m_eMode )
	{
	case MIBMode_IconLeft:
		{
			rt.m_ptLT.m_nX = rect.m_ptLT.m_nX;
			rt.m_ptLT.m_nY = (rect.GetSize()->m_nHeight - m_nIconSize.m_nHeight) / 2;
			rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nIconSize.m_nWidth;
			rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nIconSize.m_nHeight;

			rtText.m_ptLT.m_nX += m_nIconSize.m_nWidth + 2;
		}
		break;

	case MIBMode_IconTop:
		{
			rt.m_ptLT.m_nX = rect.m_ptLT.m_nX + (rect.GetSize()->m_nWidth - m_nIconSize.m_nWidth) / 2;
			rt.m_ptLT.m_nY = rect.m_ptLT.m_nY;
			rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nIconSize.m_nWidth;
			rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nIconSize.m_nHeight;

			rtText.m_ptLT.m_nY += m_nIconSize.m_nHeight + 2;
		}
		break;
	}

	DrawIcon(pGc, rt);

	DrawText(pGc, rtText);

}
