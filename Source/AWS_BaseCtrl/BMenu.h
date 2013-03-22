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
	// �ڴ�����ʼ������
	virtual void OnCreate();

protected:
	struct TItemData
	{
		CAwsString	m_strText;
		int			m_nSubMenuID;
	};
	int			m_nMaxItemCount;	// ֧�ֵ����Item��
	TItemData*	m_pItemData;		// Item����

	int	m_nItemCount;				// ʵ��Item��
	int	m_nFocusItemIndex;			// ����Item����
	int	m_nDrawItemCount;			// ��Ҫ��ʾ��Item��
	int	m_nDrawItemStartIndex;		// ��Ҫ��ʾ����ʼItem����

	int m_nMaxShowItemCount;		// һ�������ʾ��Item��

	int	m_nFullBorderPixel;			// ȫ�߿�������
	int	m_nTBBorderHeight;			// ���±߿�߶�
	int m_nItemLeftMargin;			// Item��ߵĿհ�
	int m_nItemRightMargin;			// Item�ұߵĿհ�
	int	m_nItemHeight;				// Item�߶�
	int	m_nMenuWidth;				// �����˵����

	CAwsFont	m_oFont;			// ����
	int			m_nFontSize;		// �����С
	CEspSize	m_tSize;			// �����Ĵ��ڳߴ�
	CEspSize	m_oMaxTextSize;		// ����ı��ߴ�

	CAwsRgb		m_oFocusTextColor;	// �����ı���ɫ
	CAwsRgb		m_oTextColor;		// �ı���ɫ
	CAwsRgb		m_oFocusBKColor;	// ���㱳����ɫ
	CAwsRgb		m_oBKColor;			// ������ɫ
	CAwsRgb		m_oBorderColor;		// ������ɫ

	CAwsRgb		m_oArrowColor;

	bool		m_bIsSubMenu;		// �Ƿ�Ϊ�Ӵ���

	bool		m_bIsPopupOnly;		// �Ƿ��������Ϊһ��ĵ���ʽ����

	int			m_nPopMenuCount;	// ĿǰΪֹ�Ѿ������Ĳ˵���
};

#endif /* _BMENU_H_2009_10_09_ */
