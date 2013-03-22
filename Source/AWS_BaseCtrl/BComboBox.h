/******************************************************************************
* FileName		       : BComboBox.h
* Description          : interface for the CBComboBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BCOMBOBOX_H_2009_10_09_
#define _BCOMBOBOX_H_2009_10_09_

#include "AwsContainer.h"

class CBMenu;

class CBComboBox : public CAwsContainer
{
public:
	CBComboBox(int nMaxItemCount);
	virtual ~CBComboBox();

	// 在调用Create之后调用
	void AddItem(const CAwsString& strText);

	void SetFontSize(int nSize) { m_nFontSize = nSize; }

	void SetIconSize(const CEspSize& size) { m_oIconSize = size; }
	void SetIcon(const CAwsImage& icon, const CAwsImage& iconMask);

	void SetBorderColor(const CAwsRgb& color) { m_oBorderColor = color; }
	void SetFocusBorderColor(const CAwsRgb& color) { m_oFocusBorderColor = color; }
	void SetBKColor(const CAwsRgb& color) { m_oBKColor = color; }
	void SetFocusBKColor(const CAwsRgb& color) { m_oFocusBKColor = color; }
	void SetTextColor(const CAwsRgb& color) { m_oTextColor = color; }
	void SetFocusTextColor(const CAwsRgb& color) { m_oFocusTextColor = color; }

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);
	virtual void OnFocus(bool bIsFocus);
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);

protected:
	// 在此做初始化工作
	virtual void OnCreate();

protected:
	virtual void DrawBK(IAwsGc* pGc, const CEspRect& rect);
	virtual void DrawText(IAwsGc* pGc, const CEspRect& rect);
	virtual void DrawIcon(IAwsGc* pGc, const CEspRect& rect);

	void AdjustMenuPos(CBMenu* pMenu, CEspRect& rect);

protected:
	int				m_nMaxItemCount;	// 最大Item数
	int				m_nItemCount;		// 当前Item数
	int				m_nCurItemIndex;	// 当前Item索引
	CAwsString*		m_pItemData;

	int				m_nItemHeight;
	int				m_nLeftMargin;		// 距文字左边距离
	int				m_nRightMargin;		// 距图标右边距离
	int				m_nBorderWidth;		// 边框宽度

	CEspSize		m_oIconSize;

	CAwsRgb			m_oBorderColor;
	CAwsRgb			m_oFocusBorderColor;
	CAwsRgb			m_oBKColor;
	CAwsRgb			m_oFocusBKColor;
	CAwsRgb			m_oTextColor;
	CAwsRgb			m_oFocusTextColor;

	CAwsFont		m_oFont;
	int				m_nFontSize;

	CAwsImage		m_oIcon;
	CAwsImage		m_oIconMask;
};

#endif /* _BCOMBOBOX_H_2009_10_09_ */
