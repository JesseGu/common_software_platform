/******************************************************************************
* FileName		       : BListBox.h
* Description          : interface for the CBListBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BLISTBOX_H_2009_10_09_
#define _BLISTBOX_H_2009_10_09_

#include "AwsContainer.h"

class CBScrollBar;

class CBListBox : public CAwsContainer
{
public:
	CBListBox(int nMaxItemCount);
	virtual ~CBListBox();

	// 在调用Create之后调用
	void AddItem(const CAwsString& strText);
	void AddItemEnd();

	void SetBorderColor(const CAwsRgb& color) { m_oBorderColor = color; }
	void SetTextColor(const CAwsRgb& color) { m_oTextColor = color; }
	void SetSelectTextColor(const CAwsRgb& color) { m_oSelectTextColor = color; }
	void SetBKColor(const CAwsRgb& color) { m_oBKColor = color; }
	void SetSelectBKColor(const CAwsRgb& color) { m_oSelectBKColor = color; }

	void SetBorderPixels(int nPixels) { m_nBorderPixels = nPixels; }

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);
	virtual void OnFocus(bool bIsFocus);

protected:
	// 在此做初始化工作
	virtual void OnCreate();

protected:
	virtual void DrawBorder(IAwsGc* pGc, const CEspRect& rect);
	virtual void DrawItem(IAwsGc* pGc, const CEspRect& rect, int nIndex, bool bIsSelected);

protected:
	int				m_nMaxItemCount;	// 最大Item数
	int				m_nItemCount;		// 当前Item数
	int				m_nCurItemIndex;	// 当前Item索引
	CAwsString*		m_pItemData;

	int				m_nDrawItemCount;
	int				m_nDrawItemStartIndex;

	CBScrollBar*	m_pScrollBar;
	int				m_nScrollLength;
	int				m_nScrollPos;

	int				m_nItemHeight;
	int				m_nBorderPixels;
	int				m_nItemLeftMargin;

	CAwsRgb			m_oBorderColor;
	CAwsRgb			m_oSelectBorderColor;
	CAwsRgb			m_oSelectBKColor;
	CAwsRgb			m_oBKColor;
	CAwsRgb			m_oTextColor;
	CAwsRgb			m_oSelectTextColor;

	CAwsFont		m_oFont;
	int				m_nFontSize;

	int				m_nScrollBarWidth;
};

#endif /* _BLISTBOX_H_2009_10_09_ */
