/******************************************************************************
* FileName		       : BEdit.h
* Description          : interface for the CBEdit class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BEDIT_H_2009_10_09_
#define _BEDIT_H_2009_10_09_

#include "AwsWindow.h"
#include "EspString.h"

class IAwsGc;

class CBEdit : public CAwsWindow
{
public:
	CBEdit();

	void SetDefaultString(const CAwsString& str);
	const CAwsString& GetString() { return m_strText; }
	void SetCaretInterval(int nTimes) { m_nCaretInterval = nTimes; }

	void SetBorderColor(const CAwsRgb& color) { m_oBorderColor = color; }
	void SetFocusBorderColor(const CAwsRgb& color) { m_oFocusBorderColor = color; }
	void SetBKColor(const CAwsRgb& color) { m_oBKColor = color; }
	void SetCaretColor(const CAwsRgb& color) { m_oCaretColor = color; }
	void SetTextColor(const CAwsRgb& color) { m_oTextColor = color; }

public:
	virtual void OnTimer();
	virtual void OnImeChar(short nChar);
	virtual void OnFocus(bool bIsFocus);
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);

protected:
	void ShowCaret();
	void HideCaret();
	void DrawBK(IAwsGc* pGc, const CEspRect& rect);

	bool RightMoveOneChar();
	bool LeftMoveOneChar();
	void DeleteOneChar();

protected:
	CAwsString	m_strText;			// 存放的所有的文本
	CAwsString	m_strDrawText;		// 用于绘制的文本

	CAwsRgb		m_oBorderColor;
	CAwsRgb		m_oFocusBorderColor;
	CAwsRgb		m_oBKColor;
	CAwsRgb		m_oCaretColor;		// 插入符颜色
	CAwsRgb		m_oTextColor;

	CEspPoint	m_oCaretPos;		// 插入符位置(物理位置)
	CEspSize	m_oCaretSize;		// 插入符大小
	bool		m_bCaretIsShow;		// 插入符是否显示
	int			m_nCaretCharIndex;	// 插入符处于的字符位置，位于字符的右边，如果没有字符则为-1

	bool		m_bCaretIsVisible;	// 插入符当前是否可见
	int			m_nCaretInterval;	// 插入符闪烁的间隔

	int			m_nStartDrawCharIndex;	// 画的第一个字符的索引（左边第一个显示字符的索引）

	CAwsFont	m_oFont;
	int			m_nFontSize;
};

#endif /* _BEDIT_H_2009_10_09_ */
