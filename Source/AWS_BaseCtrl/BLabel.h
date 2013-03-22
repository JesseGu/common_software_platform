/******************************************************************************
* FileName		       : BLabel.h
* Description          : interface for the CBLabel class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BLABEL_H_2009_10_09_
#define _BLABEL_H_2009_10_09_

#include "AwsWindow.h"

class CBLabel : public CAwsWindow
{
public:
	CBLabel();

	void SetText(const CAwsString& str, bool bIsRedraw = false);
	void GetText(CAwsString& str) { str = m_oStrText; }
	void SetTextColor(const CAwsRgb& color, bool bIsRedraw = false);
	void SetBKColor(const CAwsRgb& color, bool bIsRedraw = false);
	void SetTextSize(int nSize) { m_nTextSize = nSize; }
	void SetTextAlignment(AWS_TextAlignMode mode, bool bIsRedraw = false);

public:
	virtual void OnDraw(const CEspRect& rect);

protected:
	virtual void DrawText(IAwsGc* pGc, const CEspRect& rect);

protected:
	CAwsFont	m_oFont;
	int			m_nTextSize;

	CAwsString	m_oStrText;
	CAwsRgb		m_oTextColor;
	CAwsRgb		m_oBKColor;

	AWS_TextAlignMode m_eAlignMode;
};

#endif /* _BLABEL_H_2009_10_09_ */
