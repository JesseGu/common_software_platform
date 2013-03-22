/******************************************************************************
* FileName		       : BMenu.h
* Description          : interface for the CBMenu class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BMENU_H_2009_10_09_
#define _BMENU_H_2009_10_09_

#include "AwsContainer.h"

typedef struct tagCBMenu CBMenu;
typedef struct tagCBMenu_TItemData CBMenu_TItemData;

// 类声明
struct tagCBMenu_TItemData
{
	CAwsString m_strText;
	int m_nSubMenuID;
};

// 成员函数声明
void CBMenu_TItemData_CInit(CBMenu_TItemData* pThis);
void CBMenu_TItemData_DUninit_i1p(CBMenu_TItemData* pThis, int* pOffset);

// 虚函数表
typedef void(*PVCBMenu_DrawFullBorder_IAwsGc1p_CEspRect1p)(CBMenu* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBMenu_DrawTopBorder_IAwsGc1p_CEspRect1p_i0p)(CBMenu* pThis, IAwsGc *  pGc, const CEspRect * rect, int bIsScroll);
typedef void(*PVCBMenu_DrawBottomBorder_IAwsGc1p_CEspRect1p_i0p)(CBMenu* pThis, IAwsGc *  pGc, const CEspRect * rect, int bIsScroll);
typedef void(*PVCBMenu_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p_i0p)(CBMenu* pThis, IAwsGc *  pGc, const CEspRect * rect, int nIndex, int bIsSelected, int bIsSubMenu);
typedef struct tagVTab_CBMenu VTab_CBMenu;
struct tagVTab_CBMenu
{
	PVCBMenu_DrawFullBorder_IAwsGc1p_CEspRect1p	m_pDrawFullBorder_IAwsGc1p_CEspRect1p;
	PVCBMenu_DrawTopBorder_IAwsGc1p_CEspRect1p_i0p	m_pDrawTopBorder_IAwsGc1p_CEspRect1p_i0p;
	PVCBMenu_DrawBottomBorder_IAwsGc1p_CEspRect1p_i0p	m_pDrawBottomBorder_IAwsGc1p_CEspRect1p_i0p;
	PVCBMenu_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p_i0p	m_pDrawItem_IAwsGc1p_CEspRect1p_i0p_i0p_i0p;
};

// 类声明
struct tagCBMenu
{
	CAwsContainer m_oBase_CAwsContainer;

	int m_nMaxItemCount;
	CBMenu_TItemData *  m_pItemData;
	int m_nItemCount;
	int m_nFocusItemIndex;
	int m_nDrawItemCount;
	int m_nDrawItemStartIndex;
	int m_nMaxShowItemCount;
	int m_nFullBorderPixel;
	int m_nTBBorderHeight;
	int m_nItemLeftMargin;
	int m_nItemRightMargin;
	int m_nItemHeight;
	int m_nMenuWidth;
	CAwsFont m_oFont;
	int m_nFontSize;
	CEspSize m_tSize;
	CEspSize m_oMaxTextSize;
	CAwsRgb m_oFocusTextColor;
	CAwsRgb m_oTextColor;
	CAwsRgb m_oFocusBKColor;
	CAwsRgb m_oBKColor;
	CAwsRgb m_oBorderColor;
	CAwsRgb m_oArrowColor;
	int m_bIsSubMenu;
	int m_bIsPopupOnly;
	int m_nPopMenuCount;
	const VTab_CBMenu*	m_pVTab;
};

// 成员函数声明
void CBMenu_DrawFullBorder_IAwsGc1p_CEspRect1p(CBMenu* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBMenu_DrawTopBorder_IAwsGc1p_CEspRect1p_i0p(CBMenu* pThis, IAwsGc *  pGc, const CEspRect * rect, int bIsScroll);
void CBMenu_DrawBottomBorder_IAwsGc1p_CEspRect1p_i0p(CBMenu* pThis, IAwsGc *  pGc, const CEspRect * rect, int bIsScroll);
void CBMenu_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p_i0p(CBMenu* pThis, IAwsGc *  pGc, const CEspRect * rect, int nIndex, int bIsSelected, int bIsSubMenu);
void CBMenu_DUninit_i1p(CAwsWindow* this, int * pOffset);
void CBMenu_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CBMenu_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CBMenu_OnCreate(CAwsWindow* this);
void CBMenu_CInit_CAwsWindow1p_i0p_i0p_i0p(CBMenu* pThis, CAwsWindow *  pWnd, int nMaxItemCount, int nPopedMenu, int bIsSubMenu);
int CBMenu_AddItem_CAwsString1p_i0p(CBMenu* pThis, const CAwsString * strText, int nSubMenuID);
void CBMenu_AddItemEnd(CBMenu* pThis);
const CEspSize * CBMenu_GetMenuSize(CBMenu* pThis);
void CBMenu_SetFocusTextColor_CAwsRgb1p(CBMenu* pThis, const CAwsRgb * color);
void CBMenu_SetTextColor_CAwsRgb1p(CBMenu* pThis, const CAwsRgb * color);
void CBMenu_SetFocusBKColor_CAwsRgb1p(CBMenu* pThis, const CAwsRgb * color);
void CBMenu_SetBKColor_CAwsRgb1p(CBMenu* pThis, const CAwsRgb * color);
void CBMenu_SetBorderColor_CAwsRgb1p(CBMenu* pThis, const CAwsRgb * color);
void CBMenu_SetTBBorderHeight_i0p(CBMenu* pThis, int nHeight);
void CBMenu_SetItemLeftMargin_i0p(CBMenu* pThis, int nMargin);
void CBMenu_SetItemRightMargin_i0p(CBMenu* pThis, int nMargin);
void CBMenu_SetDefaultItemHeight_i0p(CBMenu* pThis, int nHeight);
void CBMenu_SetDefaultItemWidth_i0p(CBMenu* pThis, int nWidth);
void CBMenu_SetPopupOnly_i0p(CBMenu* pThis, int bIsPopupOnly);
int CBMenu_GetItemRectFromIndex_i0p_CEspRect1p(CBMenu* pThis, int nIndex, CEspRect * rect);
void CBMenu_CInit(CBMenu* pThis);

// 虚函数表的声明
extern const VTab_CBMenu g_tVTab_CBMenu_CBMenu;
extern const VTab_CAwsWindow g_tVTab_CBMenu_CAwsWindow;


#endif /* _BMENU_H_2009_10_09_ */
