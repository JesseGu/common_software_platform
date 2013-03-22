/******************************************************************************
* FileName		       : MMenuBar.h
* Description          : interface for the CMMenuBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _MMENUBAR_H_2009_10_09_
#define _MMENUBAR_H_2009_10_09_

#include "AwsContainer.h"

class CBLabel;

class CMMenuBar : public CAwsContainer
{
public:
	CMMenuBar(int nMenuBarHeight, CAwsWindow* pMidCtrl = ESP_NULL);

	void SetMidCtrl(CAwsWindow* pMidCtrl);

	CAwsWindow* GetMidCtrl()
	{
		return m_pMidCtrl;
	}

	void SetLeftMenuText(const CAwsString& strText, bool bIsRedraw = true);
	void SetRightMenuText(const CAwsString& strText, bool bIsRedraw = true);

	void SetTextColor(const CAwsRgb& color) { m_oTextColor = color; }
	void SetBKColor(const CAwsRgb& color) { m_oBackColor = color; }

	void SetBKImage(const CAwsImage& imageBK, const CEspSize& sizeIamge);

public:
	virtual void OnDraw(const CEspRect& rect);

protected:
	virtual void OnCreate();

protected:
	virtual void DrawBK(IAwsGc* pGc, const CEspRect& rect);

protected:
	CBLabel*	m_pLeftBar;
	CBLabel*	m_pRightBar;

	CAwsRgb		m_oBorderColor;
	CAwsRgb		m_oBackColor;
	CAwsRgb		m_oTextColor;
	CAwsFont	m_oFont;
	int			m_nFontSize;

	CAwsWindow*	m_pMidCtrl;	// 中间控件，可以嵌入任何控件

	int			m_nBarUnitWidth;
	int			m_nMenuBarHeight;

	CAwsImage	m_oBKImage;
	CEspSize	m_oBKImageSize;
	bool		m_bIsSetImage;
};

#endif /* _MMENUBAR_H_2009_10_09_ */
