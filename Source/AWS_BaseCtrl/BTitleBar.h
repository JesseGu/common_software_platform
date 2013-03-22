/******************************************************************************
* FileName		       : BTitleBar.h
* Description          : interface for the CBTitleBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BTITLEBAR_H_2009_10_09_
#define _BTITLEBAR_H_2009_10_09_

#include "AwsWindow.h"

class CAwsImage;

class CBTitleBar : public CAwsWindow
{
public:
	CBTitleBar(int nTitleBarHeight);

	void SetIcon(const CAwsImage& icon, const CEspSize& size, const CAwsImage* pIconMask = ESP_NULL);
	void SetCaption(const CAwsString& strText);

	void SetTextColor(const CAwsRgb& color) { m_oTextColor = color; }
	void SetBKColor(const CAwsRgb& color) { m_oBKColor = color; }

	void SetTextFontSize(int nSize) { m_nFontSize = nSize; }
	void SetTitleBarHeight( int nHeight ) { m_nTitleBarHeight = nHeight; }

	void SetBKImage(const CAwsImage& imageBK, const CEspSize& sizeImage);

public:
	virtual void OnDraw(const CEspRect& rect);

protected:
	virtual void OnCreate();

protected:
	virtual void DrawBackground(IAwsGc* pGc, const CEspRect& rect);
	virtual bool DrawIcon(IAwsGc* pGc, const CEspRect& rect, CEspSize& sizeIcon);
	virtual void DrawText(IAwsGc* pGc, const CEspRect& rect);

protected:
	CAwsImage	m_oIconImage;
	CAwsImage	m_oIconMask;
	CEspSize	m_oIconSize;
	CAwsString	m_oStrCaption;

	CAwsRgb		m_oTextColor;
	CAwsRgb		m_oBKColor;

	int			m_nTitleBarHeight;

	CAwsFont	m_oFont;
	int			m_nFontSize;

	CAwsImage	m_oBKImage;
	CEspSize	m_oBKImageSize;
	bool		m_bIsSetBKImage;

	int			m_nLeftMargin;
};

#endif /* _BTITLEBAR_H_2009_10_09_ */
