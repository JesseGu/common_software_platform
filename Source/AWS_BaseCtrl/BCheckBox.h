/******************************************************************************
* FileName		       : BCheckBox.h
* Description          : interface for the CBCheckBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BCHECKBOX_H__2009_10_09_
#define _BCHECKBOX_H__2009_10_09_

#include "BImageButton.h"

class CBCheckBox : public CBImageButton
{
public:
	CBCheckBox();

	void SetSelected(bool bIsSelect);
	bool IsSelected() { return m_bIsSelect; }

	void SetBorderColor(const CAwsRgb& color) { m_oBorderColor = color; }
	void SetFocusBorderColor(const CAwsRgb& color) { m_oFocusBorderColor = color; }
	void SetBKColor(const CAwsRgb& color) { m_oBKColor = color; }
	void SetSelectColor(const CAwsRgb& color) { m_oSelectColor = color; }

	void SetImage(const CAwsImage& image, const CAwsImage& imageFocus, const CAwsImage& imageSel, const CAwsImage& imageSelFocus, const CAwsImage& imageMask);

protected:
	virtual void DrawIcon(IAwsGc* pGc, const CEspRect& rect);
	virtual void OnClick();

protected:
	bool	m_bIsSelect;

	CAwsRgb	m_oBorderColor;
	CAwsRgb	m_oFocusBorderColor;
	CAwsRgb	m_oBKColor;
	CAwsRgb	m_oSelectColor;

	CAwsImage	m_oImage;
	CAwsImage	m_oImageFocus;
	CAwsImage	m_oImageSel;
	CAwsImage	m_oImageSelFocus;
	CAwsImage	m_oImageMask;
};

#endif /* _BCHECKBOX_H__2009_10_09_ */
