/******************************************************************************
* FileName		       : BMenu.h
* Description          : interface for the CBMenu class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BMENU_H_2009_10_09_
#define _BMENU_H_2009_10_09_

#include "AwsContainer.h"

class CBMenu : public CAwsContainer
{
public:
	CBMenu(CAwsWindow* pWnd, int nMaxItemCount = 15, int nPopedMenu = 0, bool bIsSubMenu = false);
	virtual ~CBMenu();

public:
	bool AddItem(const CAwsString& strText, int nSubMenuID = 0);
	void AddItemEnd();

	const CEspSize& GetMenuSize() { return m_tSize; }

	void SetFocusTextColor(const CAwsRgb& color) { m_oFocusTextColor = color; }
	void SetTextColor(const CAwsRgb& color) { m_oTextColor = color; }
	void SetFocusBKColor(const CAwsRgb& color) { m_oFocusBKColor = color; }
	void SetBKColor(const CAwsRgb& color) { m_oBKColor = color; }
	void SetBorderColor(const CAwsRgb& color) { m_oBorderColor = color; }

	void SetTBBorderHeight(int nHeight) { m_nTBBorderHeight = nHeight; }
	void SetItemLeftMargin(int nMargin) { m_nItemLeftMargin = nMargin; }
	void SetItemRightMargin(int nMargin) { m_nItemRightMargin = nMargin; }
	void SetDefaultItemHeight(int nHeight) { m_nItemHeight = nHeight; }
	void SetDefaultItemWidth(int nWidth) { m_nMenuWidth = nWidth; }

	void SetPopupOnly(bool bIsPopupOnly) { m_bIsPopupOnly = bIsPopupOnly; }

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);

protected:
	virtual void DrawFullBorder(IAwsGc* pGc, const CEspRect& rect);
	virtual void DrawTopBorder(IAwsGc* pGc, const CEspRect& rect, bool bIsScroll = false);
	virtual void DrawBottomBorder(IAwsGc* pGc, const CEspRect& rect, bool bIsScroll = false);
	virtual void DrawItem(IAwsGc* pGc, const CEspRect& rect, int nIndex, bool bIsSelected = false, bool bIsSubMenu = false);

	bool GetItemRectFromIndex(int nIndex, CEspRect& rect);

protected:
	// 在此做初始化工作
	virtual void OnCreate();

protected:
	struct TItemData
	{
		CAwsString	m_strText;
		int			m_nSubMenuID;
	};
	int			m_nMaxItemCount;	// 支持的最大Item数
	TItemData*	m_pItemData;		// Item数据

	int	m_nItemCount;				// 实际Item数
	int	m_nFocusItemIndex;			// 焦点Item索引
	int	m_nDrawItemCount;			// 需要显示的Item数
	int	m_nDrawItemStartIndex;		// 需要显示的起始Item索引

	int m_nMaxShowItemCount;		// 一次最大显示的Item数

	int	m_nFullBorderPixel;			// 全边框像素数
	int	m_nTBBorderHeight;			// 上下边框高度
	int m_nItemLeftMargin;			// Item左边的空白
	int m_nItemRightMargin;			// Item右边的空白
	int	m_nItemHeight;				// Item高度
	int	m_nMenuWidth;				// 整个菜单宽度

	CAwsFont	m_oFont;			// 字体
	int			m_nFontSize;		// 字体大小
	CEspSize	m_tSize;			// 计算后的窗口尺寸
	CEspSize	m_oMaxTextSize;		// 最大文本尺寸

	CAwsRgb		m_oFocusTextColor;	// 焦点文本颜色
	CAwsRgb		m_oTextColor;		// 文本颜色
	CAwsRgb		m_oFocusBKColor;	// 焦点背景颜色
	CAwsRgb		m_oBKColor;			// 背景颜色
	CAwsRgb		m_oBorderColor;		// 背景颜色

	CAwsRgb		m_oArrowColor;

	bool		m_bIsSubMenu;		// 是否为子窗口

	bool		m_bIsPopupOnly;		// 是否仅仅是作为一般的弹出式窗口

	int			m_nPopMenuCount;	// 目前为止已经弹出的菜单数
};

#endif /* _BMENU_H_2009_10_09_ */
