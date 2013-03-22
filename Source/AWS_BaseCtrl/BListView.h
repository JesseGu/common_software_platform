/******************************************************************************
* FileName		       : BListView.h
* Description          : interface for the CBListView class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BLISTVIEW_H_2009_10_09_
#define _BLISTVIEW_H_2009_10_09_

#include "AwsContainer.h"

class CBScrollBar;

enum LV_ShowMode
{
	LVShowMode_List,	// 列表显示模式
	LVShowMode_Icon		// 图标显示模式
};

class CBListView : public CAwsContainer
{
public:
	CBListView(int nMaxItemCount);
	virtual ~CBListView();

	// 在调用Create之后调用
	void AddItem(const CAwsString& strText, const CAwsImage& iconSmall, const CAwsImage& iconBig, const CAwsImage* pSmallMask = ESP_NULL, const CAwsImage* pBigMask = ESP_NULL, bool bIsEnd = false);

	void RemoveItem(int nItemIndex);
	int GetCurItemIndex() { return m_nCurItemIndex; }

	void SetShowMode(LV_ShowMode mode);

	void SetFontSize(int nSize) { m_nFontSize = nSize; }

	void SetListItemSize(const CEspSize& size) { m_oListModeItemSize = size; }
	void setIconItemSize(const CEspSize& size) { m_oIconModeItemSize = size; }
	void SetSmallIconSize(const CEspSize& size) { m_oSmallIconSize = size; }
	void SetBigIconSize(const CEspSize& size) { m_oBigIconSize = size; }

	void SetBorderColor(const CAwsRgb& color) { m_oBorderColor = color; }
	void SetItemSelectBKColor(const CAwsRgb& color) { m_oItemSelectBKColor = color; }
	void SetItemBKColor(const CAwsRgb& color) { m_oItemBKColor = color; }
	void SetTextColor(const CAwsRgb& color) { m_oTextColor = color; }
	void SetSelectTextColor(const CAwsRgb& color) { m_oSelectTextColor = color; }
	void SetBKColor(const CAwsRgb& color) { m_oBKColor = color; }

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);
	void OnSize(const CEspSize& size, bool bIsRedraw = true);

protected:
	virtual void OnCreate();

protected:
	// 在Create控件后规整参数，
	void RegulateParam();
	// 计算显示参数
	void CalcShowParam();

	void GetItemRectFromIndex(int nIndex, CEspRect& rect);

	virtual void DrawBorder(IAwsGc* pGc, const CEspRect& rect);
	virtual void DrawBK(IAwsGc* pGc, const CEspRect& rect);
	virtual void DrawItem(IAwsGc* pGc, const CEspRect& rect, int nIndex, bool bIsSelected);

	int GetDrawStartIndexFromCurIndex(int nIndex);

protected:
	struct TLVData
	{
		CAwsString	m_oText;			// 显示的文本
		CAwsImage	m_oSmallIcon;		// 小图标，用于列表试图
		CAwsImage	m_oBigIcon;			// 大图标，用于图标试图
		CAwsImage	m_oSmallMask;		// 小图标掩码，用于列表试图
		CAwsImage	m_oBigMask;			// 大图标掩码，用于图标试图
	};
	TLVData*	m_pLVData;

	int			m_nMaxItemCount;		// 最大支持的Item数
	int			m_nItemCount;			// 已经加入的Item数目
	int			m_nCurItemIndex;		// 当前Item索引

	LV_ShowMode	m_eShowMode;			// 显示模式

	int			m_nDrawItemStartIndex;	// 画Item最开始的索引
	int			m_nWidthDrawItemCount;	// 宽度方向可以画的Item数
	int			m_nHeightDrawItemCount;	// 高度方向可以画的Item数

	CEspSize	m_oListModeItemSize;	// 列表模式Item大小
	CEspSize	m_oIconModeItemSize;	// 图标模式Item大小
	CEspSize	m_oDrawItemSize;		// 实际上画Item大小
	CEspSize	m_oSmallIconSize;		// 小图标大小
	CEspSize	m_oBigIconSize;			// 大图标大小

	int			m_nListIconTextMargin;	// List试图视图中图标和文本间距

	int			m_nLRBorderWidth;		// 左、右边框的宽度
	int			m_nTBBorderHeight;		// 上、下边框的高度
	int			m_nLeftMargin;			// 左边空白边距
	int			m_nRightMargin;			// 右边空白边距
	int			m_nTopMargin;			// 上边空白边距
	int			m_nBottomMargin;		// 下边空白边距

	CAwsFont	m_oFont;
	int			m_nFontSize;

	CBScrollBar*	m_pScrollBar;		// 滚动条
	int				m_nScrollBarWidth;	// 滚动条的宽度
	int				m_nScrollLength;	// 滚动长度
	int				m_nScrollPos;		// 滚动块位置

	CAwsRgb			m_oBorderColor;
	CAwsRgb			m_oItemSelectBKColor;
	CAwsRgb			m_oItemBKColor;
	CAwsRgb			m_oTextColor;
	CAwsRgb			m_oSelectTextColor;
	CAwsRgb			m_oBKColor;
};

#endif /* _BLISTVIEW_H_2009_10_09_ */
