/******************************************************************************
* FileName		       : BListView.h
* Description          : interface for the CBListView class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BLISTVIEW_H_2009_10_09_
#define _BLISTVIEW_H_2009_10_09_

#include "AwsContainer.h"

typedef struct tagCBScrollBar CBScrollBar;


typedef enum tagLV_ShowMode LV_ShowMode;
enum tagLV_ShowMode
{
	LVShowMode_List,
	LVShowMode_Icon
};


typedef struct tagCBListView CBListView;
typedef struct tagCBListView_TLVData CBListView_TLVData;

// 类声明
struct tagCBListView_TLVData
{
	CAwsString m_oText;
	CAwsImage m_oSmallIcon;
	CAwsImage m_oBigIcon;
	CAwsImage m_oSmallMask;
	CAwsImage m_oBigMask;
};

// 成员函数声明
void CBListView_TLVData_CInit(CBListView_TLVData* pThis);
void CBListView_TLVData_DUninit_i1p(CBListView_TLVData* pThis, int* pOffset);

// 虚函数表
typedef void(*PVCBListView_DrawBorder_IAwsGc1p_CEspRect1p)(CBListView* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBListView_DrawBK_IAwsGc1p_CEspRect1p)(CBListView* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBListView_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p)(CBListView* pThis, IAwsGc *  pGc, const CEspRect * rect, int nIndex, int bIsSelected);
typedef struct tagVTab_CBListView VTab_CBListView;
struct tagVTab_CBListView
{
	PVCBListView_DrawBorder_IAwsGc1p_CEspRect1p	m_pDrawBorder_IAwsGc1p_CEspRect1p;
	PVCBListView_DrawBK_IAwsGc1p_CEspRect1p	m_pDrawBK_IAwsGc1p_CEspRect1p;
	PVCBListView_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p	m_pDrawItem_IAwsGc1p_CEspRect1p_i0p_i0p;
};

// 类声明
struct tagCBListView
{
	CAwsContainer m_oBase_CAwsContainer;

	CBListView_TLVData *  m_pLVData;
	int m_nMaxItemCount;
	int m_nItemCount;
	int m_nCurItemIndex;
	LV_ShowMode m_eShowMode;
	int m_nDrawItemStartIndex;
	int m_nWidthDrawItemCount;
	int m_nHeightDrawItemCount;
	CEspSize m_oListModeItemSize;
	CEspSize m_oIconModeItemSize;
	CEspSize m_oDrawItemSize;
	CEspSize m_oSmallIconSize;
	CEspSize m_oBigIconSize;
	int m_nListIconTextMargin;
	int m_nLRBorderWidth;
	int m_nTBBorderHeight;
	int m_nLeftMargin;
	int m_nRightMargin;
	int m_nTopMargin;
	int m_nBottomMargin;
	CAwsFont m_oFont;
	int m_nFontSize;
	CBScrollBar *  m_pScrollBar;
	int m_nScrollBarWidth;
	int m_nScrollLength;
	int m_nScrollPos;
	CAwsRgb m_oBorderColor;
	CAwsRgb m_oItemSelectBKColor;
	CAwsRgb m_oItemBKColor;
	CAwsRgb m_oTextColor;
	CAwsRgb m_oSelectTextColor;
	CAwsRgb m_oBKColor;
	const VTab_CBListView*	m_pVTab;
};

// 成员函数声明
void CBListView_DrawBorder_IAwsGc1p_CEspRect1p(CBListView* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBListView_DrawBK_IAwsGc1p_CEspRect1p(CBListView* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBListView_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p(CBListView* pThis, IAwsGc *  pGc, const CEspRect * rect, int nIndex, int bIsSelected);
void CBListView_DUninit_i1p(CAwsWindow* this, int * pOffset);
void CBListView_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CBListView_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CBListView_OnSize_CEspSize1p_i0p(CAwsWindow* this, const CEspSize * size, int bIsRedraw);
void CBListView_OnCreate(CAwsWindow* this);
void CBListView_CInit_i0p(CBListView* pThis, int nMaxItemCount);
void CBListView_AddItem_CAwsString1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_i0p(CBListView* pThis, const CAwsString * strText, const CAwsImage * iconSmall, const CAwsImage * iconBig, const CAwsImage *  pSmallMask, const CAwsImage *  pBigMask, int bIsEnd);
void CBListView_RemoveItem_i0p(CBListView* pThis, int nItemIndex);
int CBListView_GetCurItemIndex(CBListView* pThis);
void CBListView_SetShowMode_0p(CBListView* pThis, LV_ShowMode mode);
void CBListView_SetFontSize_i0p(CBListView* pThis, int nSize);
void CBListView_SetListItemSize_CEspSize1p(CBListView* pThis, const CEspSize * size);
void CBListView_setIconItemSize_CEspSize1p(CBListView* pThis, const CEspSize * size);
void CBListView_SetSmallIconSize_CEspSize1p(CBListView* pThis, const CEspSize * size);
void CBListView_SetBigIconSize_CEspSize1p(CBListView* pThis, const CEspSize * size);
void CBListView_SetBorderColor_CAwsRgb1p(CBListView* pThis, const CAwsRgb * color);
void CBListView_SetItemSelectBKColor_CAwsRgb1p(CBListView* pThis, const CAwsRgb * color);
void CBListView_SetItemBKColor_CAwsRgb1p(CBListView* pThis, const CAwsRgb * color);
void CBListView_SetTextColor_CAwsRgb1p(CBListView* pThis, const CAwsRgb * color);
void CBListView_SetSelectTextColor_CAwsRgb1p(CBListView* pThis, const CAwsRgb * color);
void CBListView_SetBKColor_CAwsRgb1p(CBListView* pThis, const CAwsRgb * color);
void CBListView_RegulateParam(CBListView* pThis);
void CBListView_CalcShowParam(CBListView* pThis);
void CBListView_GetItemRectFromIndex_i0p_CEspRect1p(CBListView* pThis, int nIndex, CEspRect * rect);
int CBListView_GetDrawStartIndexFromCurIndex_i0p(CBListView* pThis, int nIndex);
void CBListView_CInit(CBListView* pThis);

// 虚函数表的声明
extern const VTab_CBListView g_tVTab_CBListView_CBListView;
extern const VTab_CAwsWindow g_tVTab_CBListView_CAwsWindow;


#endif /* _BLISTVIEW_H_2009_10_09_ */
