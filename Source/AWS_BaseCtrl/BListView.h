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
	LVShowMode_List,	// �б���ʾģʽ
	LVShowMode_Icon		// ͼ����ʾģʽ
};

class CBListView : public CAwsContainer
{
public:
	CBListView(int nMaxItemCount);
	virtual ~CBListView();

	// �ڵ���Create֮�����
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
	// ��Create�ؼ������������
	void RegulateParam();
	// ������ʾ����
	void CalcShowParam();

	void GetItemRectFromIndex(int nIndex, CEspRect& rect);

	virtual void DrawBorder(IAwsGc* pGc, const CEspRect& rect);
	virtual void DrawBK(IAwsGc* pGc, const CEspRect& rect);
	virtual void DrawItem(IAwsGc* pGc, const CEspRect& rect, int nIndex, bool bIsSelected);

	int GetDrawStartIndexFromCurIndex(int nIndex);

protected:
	struct TLVData
	{
		CAwsString	m_oText;			// ��ʾ���ı�
		CAwsImage	m_oSmallIcon;		// Сͼ�꣬�����б���ͼ
		CAwsImage	m_oBigIcon;			// ��ͼ�꣬����ͼ����ͼ
		CAwsImage	m_oSmallMask;		// Сͼ�����룬�����б���ͼ
		CAwsImage	m_oBigMask;			// ��ͼ�����룬����ͼ����ͼ
	};
	TLVData*	m_pLVData;

	int			m_nMaxItemCount;		// ���֧�ֵ�Item��
	int			m_nItemCount;			// �Ѿ������Item��Ŀ
	int			m_nCurItemIndex;		// ��ǰItem����

	LV_ShowMode	m_eShowMode;			// ��ʾģʽ

	int			m_nDrawItemStartIndex;	// ��Item�ʼ������
	int			m_nWidthDrawItemCount;	// ��ȷ�����Ի���Item��
	int			m_nHeightDrawItemCount;	// �߶ȷ�����Ի���Item��

	CEspSize	m_oListModeItemSize;	// �б�ģʽItem��С
	CEspSize	m_oIconModeItemSize;	// ͼ��ģʽItem��С
	CEspSize	m_oDrawItemSize;		// ʵ���ϻ�Item��С
	CEspSize	m_oSmallIconSize;		// Сͼ���С
	CEspSize	m_oBigIconSize;			// ��ͼ���С

	int			m_nListIconTextMargin;	// List��ͼ��ͼ��ͼ����ı����

	int			m_nLRBorderWidth;		// ���ұ߿�Ŀ��
	int			m_nTBBorderHeight;		// �ϡ��±߿�ĸ߶�
	int			m_nLeftMargin;			// ��߿հױ߾�
	int			m_nRightMargin;			// �ұ߿հױ߾�
	int			m_nTopMargin;			// �ϱ߿հױ߾�
	int			m_nBottomMargin;		// �±߿հױ߾�

	CAwsFont	m_oFont;
	int			m_nFontSize;

	CBScrollBar*	m_pScrollBar;		// ������
	int				m_nScrollBarWidth;	// �������Ŀ��
	int				m_nScrollLength;	// ��������
	int				m_nScrollPos;		// ������λ��

	CAwsRgb			m_oBorderColor;
	CAwsRgb			m_oItemSelectBKColor;
	CAwsRgb			m_oItemBKColor;
	CAwsRgb			m_oTextColor;
	CAwsRgb			m_oSelectTextColor;
	CAwsRgb			m_oBKColor;
};

#endif /* _BLISTVIEW_H_2009_10_09_ */
