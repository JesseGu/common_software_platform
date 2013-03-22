/******************************************************************************
* FileName		       : BButton.h
* Description          : interface for the CBButton class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BBUTTON_H__2009_10_09_
#define _BBUTTON_H__2009_10_09_

#include "AwsWindow.h"

class CBButton : public CAwsWindow
{
public:
	CBButton();

	void SetText(const CAwsString& strText);

	void SetTextAlignment(AWS_TextAlignMode mode) { m_eTextAlignMode = mode; }

	void SetTextColor(const CAwsRgb& colorText) { m_oTextColor = colorText; }
	void SetTextFocusColor(const CAwsRgb& colorText) { m_oTextFocusColor = colorText; }
	void SetBKColor(const CAwsRgb& colorBK) { m_oBKColor = colorBK; }
	void SetBorderColor(const CAwsRgb& colorBorder) { m_oBorderColor = colorBorder; }

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);
	virtual void OnFocus(bool bIsFocus);

protected:
	virtual void DrawBK(IAwsGc* pGc, const CEspRect& rect);
	// œ‘ æ–≈œ¢
	virtual void DrawInf(IAwsGc* pGc, const CEspRect& rect);
	virtual void DrawText(IAwsGc* pGc, const CEspRect& rect);

	virtual void OnClick();

protected:
	CAwsString	m_oText;

	CAwsRgb		m_oBorderColor;
	CAwsRgb		m_oBKColor;
	CAwsRgb		m_oTextColor;
	CAwsRgb		m_oTextFocusColor;

	CAwsFont	m_oFont;
	int			m_nFontSize;

	AWS_TextAlignMode	m_eTextAlignMode;
};

#endif /* _BBUTTON_H__2009_10_09_ */
