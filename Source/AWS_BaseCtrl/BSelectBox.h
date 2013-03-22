/******************************************************************************
* FileName		       : BSelectBox.h
* Description          : interface for the CBSelectBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BSELECTBOX_H_2009_10_09_
#define _BSELECTBOX_H_2009_10_09_

#include "AwsWindow.h"

class CBSelectBox : public CAwsWindow
{
public:
	CBSelectBox(int nMaxItemCount);
	virtual ~CBSelectBox();

	// �ڵ���Create֮�����
	void AddItem(const CAwsString& strText);
	void AddItemEnd();

	// ����ѡ��ʱ�ı���ͼƬ
	void SetSelectImage(const CAwsImage& imageSelectBK, const CAwsImage& imageMask);

	// �ı�����
	void SetTextColor(const CAwsRgb& color) { m_oTextColor = color; }
	void SetFocusTextColor(const CAwsRgb& color) { m_oFocusTextColor = color; }
	void SetTextFontSize(int nSize) { m_nFontSize = nSize; }
	void SetLeftMargin(int nLeftMargin) { m_nLeftMargin = nLeftMargin; }
	void SetRightMargin(int nRightMargin) { m_nRightMargin = nRightMargin; }
	void SetItemRegionSize(const CEspSize& size) { m_oItemSize = size; }
	void SetArrowColor(const CAwsRgb& color) { m_oArrowColor = color; }

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);
	virtual void OnFocus(bool bIsFocus);

protected:
	virtual void DrawBorder(IAwsGc* pGc, const CEspRect& rect);
	virtual void DrawBK(IAwsGc* pGc, const CEspRect& rect);
	virtual void DrawLeftArrow(IAwsGc* pGc, const CEspRect& rect, bool bIsDrawArrow);
	virtual void DrawRightArrow(IAwsGc* pGc, const CEspRect& rect, bool bIsDrawArrow);
	virtual void DrawItem(IAwsGc* pGc, const CEspRect& rect, int nItemIndex, bool bIsSelect);

protected:
	int				m_nMaxItemCount;	// ���Item��
	int				m_nItemCount;		// ��ǰItem��
	int				m_nCurItemIndex;	// ��ǰItem����
	CAwsString*		m_pItemData;

	int				m_nDrawItemCount;
	int				m_nDrawItemStartIndex;

	CEspSize		m_oItemSize;	// ÿ��Item��ռ�õط���С
	int				m_nLeftMargin;	// ��߾�
	int				m_nRightMargin; // �ұ߾�

	int				m_nBorderWidth;

	CAwsRgb			m_oBorderColor;
	CAwsRgb			m_oFocusBorderColor;
	CAwsRgb			m_oTextColor;
	CAwsRgb			m_oFocusTextColor;
	CAwsRgb			m_oBKColor;
	CAwsRgb			m_oArrowColor;

	CAwsFont		m_oFont;
	int				m_nFontSize;

	CAwsImage		m_oImageSelectBK;
	CAwsImage		m_oImageMask;
	bool			m_bIsSetImageSelectBK;
};

#endif /* _BSELECTBOX_H_2009_10_09_ */
