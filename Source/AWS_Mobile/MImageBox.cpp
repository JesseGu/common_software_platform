/******************************************************************************
* FileName		       : MImageBox.cpp
* Description          : implementation of the CMImageBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "MImageBox.h"
#include "IAwsGc.h"

void CMImageBox::ShowImage(const CAwsImage& image, const CAwsImage& imageMask)
{
	m_oImage = image;
	m_oImageMask = imageMask;
	Invalide();
}

void CMImageBox::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();
	if ( m_oImage.GetID() > 0 )
	{
		CEspPoint pt(0, 0);
		pGc->DrawImage(pt, m_oImage, &m_oImageMask);
	}
}
