/******************************************************************************
* FileName		       : BImageButton.h
* Description          : interface for the CBImageButton class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BIMAGEBUTTON_H_2009_10_09_
#define _BIMAGEBUTTON_H_2009_10_09_

#include "BButton.h"

enum MIB_ShowMode
{
	MIBMode_IconLeft,
	MIBMode_IconTop
};

class CBImageButton : public CBButton
{
public:
	CBImageButton();

	void SetMode(MIB_ShowMode mode) { m_eMode = mode; }
	void SetIconSize(const CEspSize& size) { m_nIconSize = size; }

	void SetImage(const CAwsImage& image, const CAwsImage& imageMask);

protected:
	virtual void DrawInf(IAwsGc* pGc, const CEspRect& rect);
	virtual void DrawIcon(IAwsGc* pGc, const CEspRect& rect);

protected:
	CEspSize		m_nIconSize;	// Í¼±ê³ß´ç
	MIB_ShowMode	m_eMode;

	CAwsImage		m_oImage;
	CAwsImage		m_oImageMask;
};

#endif /* _BIMAGEBUTTON_H_2009_10_09_ */
