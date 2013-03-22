/******************************************************************************
* FileName		       : MMsgBox.h
* Description          : interface for the CMMsgBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _MMSGBOX_H_2009_10_09_
#define _MMSGBOX_H_2009_10_09_

#include "AwsContainer.h"

class IAwsGc;

class CMMsgBox : public CAwsContainer
{
public:
	CMMsgBox(CAwsWindow* pParentWnd, int nWndID = 0);

	void ShowMsg(AWS_MsgBoxType eType, const CAwsString& strText);

	void SetBorderColor(const CAwsRgb& color) { m_oBorderColor = color; }
	void SetBKColor(const CAwsRgb& color) { m_oBKColor = color; }
	void SetTextColor(const CAwsRgb& color) { m_oTextColor = color; }

	void SetFontSize(int nFontSize) { m_nFontSize = nFontSize; }

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);

protected:
	// ª≠±≥æ∞
	virtual void DrawBK(IAwsGc* pGc, const CEspRect& rect);
	// ª≠–≈œ¢
	virtual void DrawInf(IAwsGc* pGc, const CEspRect& rect);

	virtual void OnLeftMenu();
	virtual void OnRightMenu();

protected:
	AWS_MsgBoxType	m_eType;
	CAwsString		m_strText;

	CAwsRgb		m_oBorderColor;
	CAwsRgb		m_oBKColor;
	CAwsRgb		m_oTextColor;

	CAwsFont	m_oFont;
	int			m_nFontSize;
};

#endif /* _MMSGBOX_H_2009_10_09_ */
