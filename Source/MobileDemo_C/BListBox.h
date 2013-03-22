/******************************************************************************
* FileName		       : BListBox.h
* Description          : interface for the CBListBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BLISTBOX_H_2009_10_09_
#define _BLISTBOX_H_2009_10_09_

#include "AwsContainer.h"

typedef struct tagCBScrollBar CBScrollBar;


typedef struct tagCBListBox CBListBox;

// 虚函数表
typedef void(*PVCBListBox_DrawBorder_IAwsGc1p_CEspRect1p)(CBListBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBListBox_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p)(CBListBox* pThis, IAwsGc *  pGc, const CEspRect * rect, int nIndex, int bIsSelected);
typedef struct tagVTab_CBListBox VTab_CBListBox;
struct tagVTab_CBListBox
{
	PVCBListBox_DrawBorder_IAwsGc1p_CEspRect1p	m_pDrawBorder_IAwsGc1p_CEspRect1p;
	PVCBListBox_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p	m_pDrawItem_IAwsGc1p_CEspRect1p_i0p_i0p;
};

// 类声明
struct tagCBListBox
{
	CAwsContainer m_oBase_CAwsContainer;

	int m_nMaxItemCount;
	int m_nItemCount;
	int m_nCurItemIndex;
	CAwsString *  m_pItemData;
	int m_nDrawItemCount;
	int m_nDrawItemStartIndex;
	CBScrollBar *  m_pScrollBar;
	int m_nScrollLength;
	int m_nScrollPos;
	int m_nItemHeight;
	int m_nBorderPixels;
	int m_nItemLeftMargin;
	CAwsRgb m_oBorderColor;
	CAwsRgb m_oSelectBorderColor;
	CAwsRgb m_oSelectBKColor;
	CAwsRgb m_oBKColor;
	CAwsRgb m_oTextColor;
	CAwsRgb m_oSelectTextColor;
	CAwsFont m_oFont;
	int m_nFontSize;
	int m_nScrollBarWidth;
	const VTab_CBListBox*	m_pVTab;
};

// 成员函数声明
void CBListBox_DrawBorder_IAwsGc1p_CEspRect1p(CBListBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBListBox_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p(CBListBox* pThis, IAwsGc *  pGc, const CEspRect * rect, int nIndex, int bIsSelected);
void CBListBox_DUninit_i1p(CAwsWindow* this, int * pOffset);
void CBListBox_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CBListBox_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CBListBox_OnFocus_i0p(CAwsWindow* this, int bIsFocus);
void CBListBox_OnCreate(CAwsWindow* this);
void CBListBox_CInit_i0p(CBListBox* pThis, int nMaxItemCount);
void CBListBox_AddItem_CAwsString1p(CBListBox* pThis, const CAwsString * strText);
void CBListBox_AddItemEnd(CBListBox* pThis);
void CBListBox_SetBorderColor_CAwsRgb1p(CBListBox* pThis, const CAwsRgb * color);
void CBListBox_SetTextColor_CAwsRgb1p(CBListBox* pThis, const CAwsRgb * color);
void CBListBox_SetSelectTextColor_CAwsRgb1p(CBListBox* pThis, const CAwsRgb * color);
void CBListBox_SetBKColor_CAwsRgb1p(CBListBox* pThis, const CAwsRgb * color);
void CBListBox_SetSelectBKColor_CAwsRgb1p(CBListBox* pThis, const CAwsRgb * color);
void CBListBox_SetBorderPixels_i0p(CBListBox* pThis, int nPixels);
void CBListBox_CInit(CBListBox* pThis);

// 虚函数表的声明
extern const VTab_CBListBox g_tVTab_CBListBox_CBListBox;
extern const VTab_CAwsWindow g_tVTab_CBListBox_CAwsWindow;


#endif /* _BLISTBOX_H_2009_10_09_ */
