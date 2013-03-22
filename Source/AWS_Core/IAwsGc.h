/******************************************************************************
* FileName		       : IAwsGc.h
* Description          : interface of the IAwsGc
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _IAWSGC_H_2009_09_17_
#define _IAWSGC_H_2009_09_17_

#include "Aws.h"

class IAwsGc
{
public:
	virtual void SetOrigin(CEspPoint& pt) = 0;

	virtual void SetPenWidth(int nPixels) = 0;
	virtual void SetPenColor(const CAwsRgb& color) = 0;
	virtual void SetBrushColor(const CAwsRgb& color) = 0;
	virtual void DrawLine(const CEspPoint& ptStart, const CEspPoint& ptEnd) = 0;
	virtual void DrawRect(const CEspRect& rect) = 0;
	virtual void DrawFillRect(const CEspRect& rect) = 0;

	virtual void DrawEllipse(const CEspRect& rect) = 0;

	virtual void SetTextColor(const CAwsRgb& color) = 0;
	virtual void SetTextBKColor(const CAwsRgb& color) = 0;
	virtual void SetTextBKMode(AWS_TextShowMode mode) = 0;
	virtual void SetTextAlignment(AWS_TextAlignMode mode) = 0;
	virtual void DrawText(const CAwsString& strText, const CEspRect& rect) = 0;

	virtual const CEspSize* GetTextSize(const CAwsString& strText) = 0;

	virtual void UseFont(const CAwsFont& font) = 0;
	virtual void DiscardFont() = 0;

	virtual void DrawImage(const CEspPoint& pt, const CAwsImage& image, const CAwsImage* pMaskImage = ESP_NULL) = 0;

	virtual void SetClipRect(const CEspRect& rect) = 0;
	virtual void ResetClipRect() = 0;
};

#endif /* _IAWSGC_H_2009_09_17_ */
