/******************************************************************************
* FileName		       : BSelectBox.h
* Description          : interface for the CBSelectBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BSELECTBOX_H_2009_10_09_
#define _BSELECTBOX_H_2009_10_09_

#include "AwsWindow.h"

typedef struct tagCBSelectBox CBSelectBox;

// 虚函数表
typedef void(*PVCBSelectBox_DrawBorder_IAwsGc1p_CEspRect1p)(CBSelectBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBSelectBox_DrawBK_IAwsGc1p_CEspRect1p)(CBSelectBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBSelectBox_DrawLeftArrow_IAwsGc1p_CEspRect1p_i0p)(CBSelectBox* pThis, IAwsGc *  pGc, const CEspRect * rect, int bIsDrawArrow);
typedef void(*PVCBSelectBox_DrawRightArrow_IAwsGc1p_CEspRect1p_i0p)(CBSelectBox* pThis, IAwsGc *  pGc, const CEspRect * rect, int bIsDrawArrow);
typedef void(*PVCBSelectBox_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p)(CBSelectBox* pThis, IAwsGc *  pGc, const CEspRect * rect, int nItemIndex, int bIsSelect);
typedef struct tagVTab_CBSelectBox VTab_CBSelectBox;
struct tagVTab_CBSelectBox
{
	PVCBSelectBox_DrawBorder_IAwsGc1p_CEspRect1p	m_pDrawBorder_IAwsGc1p_CEspRect1p;
	PVCBSelectBox_DrawBK_IAwsGc1p_CEspRect1p	m_pDrawBK_IAwsGc1p_CEspRect1p;
	PVCBSelectBox_DrawLeftArrow_IAwsGc1p_CEspRect1p_i0p	m_pDrawLeftArrow_IAwsGc1p_CEspRect1p_i0p;
	PVCBSelectBox_DrawRightArrow_IAwsGc1p_CEspRect1p_i0p	m_pDrawRightArrow_IAwsGc1p_CEspRect1p_i0p;
	PVCBSelectBox_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p	m_pDrawItem_IAwsGc1p_CEspRect1p_i0p_i0p;
};

// 类声明
struct tagCBSelectBox
{
	CAwsWindow m_oBase_CAwsWindow;

	int m_nMaxItemCount;
	int m_nItemCount;
	int m_nCurItemIndex;
	CAwsString *  m_pItemData;
	int m_nDrawItemCount;
	int m_nDrawItemStartIndex;
	CEspSize m_oItemSize;
	int m_nLeftMargin;
	int m_nRightMargin;
	int m_nBorderWidth;
	CAwsRgb m_oBorderColor;
	CAwsRgb m_oFocusBorderColor;
	CAwsRgb m_oTextColor;
	CAwsRgb m_oFocusTextColor;
	CAwsRgb m_oBKColor;
	CAwsRgb m_oArrowColor;
	CAwsFont m_oFont;
	int m_nFontSize;
	CAwsImage m_oImageSelectBK;
	CAwsImage m_oImageMask;
	int m_bIsSetImageSelectBK;
	const VTab_CBSelectBox*	m_pVTab;
};

// 成员函数声明
void CBSelectBox_DrawBorder_IAwsGc1p_CEspRect1p(CBSelectBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBSelectBox_DrawBK_IAwsGc1p_CEspRect1p(CBSelectBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBSelectBox_DrawLeftArrow_IAwsGc1p_CEspRect1p_i0p(CBSelectBox* pThis, IAwsGc *  pGc, const CEspRect * rect, int bIsDrawArrow);
void CBSelectBox_DrawRightArrow_IAwsGc1p_CEspRect1p_i0p(CBSelectBox* pThis, IAwsGc *  pGc, const CEspRect * rect, int bIsDrawArrow);
void CBSelectBox_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p(CBSelectBox* pThis, IAwsGc *  pGc, const CEspRect * rect, int nItemIndex, int bIsSelect);
void CBSelectBox_DUninit_i1p(CAwsWindow* this, int * pOffset);
void CBSelectBox_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CBSelectBox_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CBSelectBox_OnFocus_i0p(CAwsWindow* this, int bIsFocus);
void CBSelectBox_CInit_i0p(CBSelectBox* pThis, int nMaxItemCount);
void CBSelectBox_AddItem_CAwsString1p(CBSelectBox* pThis, const CAwsString * strText);
void CBSelectBox_AddItemEnd(CBSelectBox* pThis);
void CBSelectBox_SetSelectImage_CAwsImage1p_CAwsImage1p(CBSelectBox* pThis, const CAwsImage * imageSelectBK, const CAwsImage * imageMask);
void CBSelectBox_SetTextColor_CAwsRgb1p(CBSelectBox* pThis, const CAwsRgb * color);
void CBSelectBox_SetFocusTextColor_CAwsRgb1p(CBSelectBox* pThis, const CAwsRgb * color);
void CBSelectBox_SetTextFontSize_i0p(CBSelectBox* pThis, int nSize);
void CBSelectBox_SetLeftMargin_i0p(CBSelectBox* pThis, int nLeftMargin);
void CBSelectBox_SetRightMargin_i0p(CBSelectBox* pThis, int nRightMargin);
void CBSelectBox_SetItemRegionSize_CEspSize1p(CBSelectBox* pThis, const CEspSize * size);
void CBSelectBox_SetArrowColor_CAwsRgb1p(CBSelectBox* pThis, const CAwsRgb * color);
void CBSelectBox_CInit(CBSelectBox* pThis);

// 虚函数表的声明
extern const VTab_CBSelectBox g_tVTab_CBSelectBox_CBSelectBox;
extern const VTab_CAwsWindow g_tVTab_CBSelectBox_CAwsWindow;


#endif /* _BSELECTBOX_H_2009_10_09_ */
