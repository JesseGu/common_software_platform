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
	CAwsString	m_strText;			// ��ŵ����е��ı�
	CAwsString	m_strDrawText;		// ���ڻ��Ƶ��ı�

	CAwsRgb		m_oBorderColor;
	CAwsRgb		m_oFocusBorderColor;
	CAwsRgb		m_oBKColor;
	CAwsRgb		m_oCaretColor;		// �������ɫ
	CAwsRgb		m_oTextColor;

	CEspPoint	m_oCaretPos;		// �����λ��(����λ��)
	CEspSize	m_oCaretSize;		// �������С
	bool		m_bCaretIsShow;		// ������Ƿ���ʾ
	int			m_nCaretCharIndex;	// ��������ڵ��ַ�λ�ã�λ���ַ����ұߣ����û���ַ���Ϊ-1

	bool		m_bCaretIsVisible;	// �������ǰ�Ƿ�ɼ�
	int			m_nCaretInterval;	// �������˸�ļ��

	int			m_nStartDrawCharIndex;	// ���ĵ�һ���ַ�����������ߵ�һ����ʾ�ַ���������

	CAwsFont	m_oFont;
	int			m_nFontSize;
};

#endif /* _BEDIT_H_2009_10_09_ */
