/******************************************************************************
* FileName		       : BRadioBox.h
* Description          : interface for the CBRadioBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BRADIOBOX_H_2009_10_09_
#define _BRADIOBOX_H_2009_10_09_

#include "BImageButton.h"

class CBRadioBox : public CBImageButton
{
public:
	CBRadioBox();

	void SetSelected(bool bIsSelect);
	bool IsSelected() { return m_bIsSelect; }

	void SetBorderColor(CAwsRgb& color) { m_oBorderColor = color; }
	void SetFocusBorderColor(CAwsRgb& color) { m_oFocusBorderColor = color; }
	void SetBKColor(CAwsRgb& color) { m_oBKColor = color; }
	void SetSelectColor(CAwsRgb& color) { m_oSelectColor = color; }

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

	int		m_nSelectDim;	// 选择后的小图标尺寸

	CAwsImage	m_oImage;
	CAwsImage	m_oImageFocus;
	CAwsImage	m_oImageSel;
	CAwsImage	m_oImageSelFocus;
	CAwsImage	m_oImageMask;
};

#endif /* _BRADIOBOX_H_2009_10_09_ */
