/******************************************************************************
* FileName		       : BComboBox.h
* Description          : interface for the CBComboBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BCOMBOBOX_H_2009_10_09_
#define _BCOMBOBOX_H_2009_10_09_

#include "AwsContainer.h"

typedef struct tagCBMenu CBMenu;


typedef struct tagCBComboBox CBComboBox;

// 虚函数表
typedef void(*PVCBComboBox_DrawBK_IAwsGc1p_CEspRect1p)(CBComboBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBComboBox_DrawText_IAwsGc1p_CEspRect1p)(CBComboBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBComboBox_DrawIcon_IAwsGc1p_CEspRect1p)(CBComboBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef struct tagVTab_CBComboBox VTab_CBComboBox;
struct tagVTab_CBComboBox
{
	PVCBComboBox_DrawBK_IAwsGc1p_CEspRect1p	m_pDrawBK_IAwsGc1p_CEspRect1p;
	PVCBComboBox_DrawText_IAwsGc1p_CEspRect1p	m_pDrawText_IAwsGc1p_CEspRect1p;
	PVCBComboBox_DrawIcon_IAwsGc1p_CEspRect1p	m_pDrawIcon_IAwsGc1p_CEspRect1p;
};

// 类声明
struct tagCBComboBox
{
	CAwsContainer m_oBase_CAwsContainer;

	int m_nMaxItemCount;
	int m_nItemCount;
	int m_nCurItemIndex;
	CAwsString *  m_pItemData;
	int m_nItemHeight;
	int m_nLeftMargin;
	int m_nRightMargin;
	int m_nBorderWidth;
	CEspSize m_oIconSize;
	CAwsRgb m_oBorderColor;
	CAwsRgb m_oFocusBorderColor;
	CAwsRgb m_oBKColor;
	CAwsRgb m_oFocusBKColor;
	CAwsRgb m_oTextColor;
	CAwsRgb m_oFocusTextColor;
	CAwsFont m_oFont;
	int m_nFontSize;
	CAwsImage m_oIcon;
	CAwsImage m_oIconMask;
	const VTab_CBComboBox*	m_pVTab;
};

// 成员函数声明
void CBComboBox_DrawBK_IAwsGc1p_CEspRect1p(CBComboBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBComboBox_DrawText_IAwsGc1p_CEspRect1p(CBComboBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBComboBox_DrawIcon_IAwsGc1p_CEspRect1p(CBComboBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBComboBox_DUninit_i1p(CAwsWindow* this, int * pOffset);
void CBComboBox_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CBComboBox_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CBComboBox_OnFocus_i0p(CAwsWindow* this, int bIsFocus);
int CBComboBox_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID, int nCmdID, int nParam1, int nParam2);
void CBComboBox_OnCreate(CAwsWindow* this);
void CBComboBox_CInit_i0p(CBComboBox* pThis, int nMaxItemCount);
void CBComboBox_AddItem_CAwsString1p(CBComboBox* pThis, const CAwsString * strText);
void CBComboBox_SetFontSize_i0p(CBComboBox* pThis, int nSize);
void CBComboBox_SetIconSize_CEspSize1p(CBComboBox* pThis, const CEspSize * size);
void CBComboBox_SetIcon_CAwsImage1p_CAwsImage1p(CBComboBox* pThis, const CAwsImage * icon, const CAwsImage * iconMask);
void CBComboBox_SetBorderColor_CAwsRgb1p(CBComboBox* pThis, const CAwsRgb * color);
void CBComboBox_SetFocusBorderColor_CAwsRgb1p(CBComboBox* pThis, const CAwsRgb * color);
void CBComboBox_SetBKColor_CAwsRgb1p(CBComboBox* pThis, const CAwsRgb * color);
void CBComboBox_SetFocusBKColor_CAwsRgb1p(CBComboBox* pThis, const CAwsRgb * color);
void CBComboBox_SetTextColor_CAwsRgb1p(CBComboBox* pThis, const CAwsRgb * color);
void CBComboBox_SetFocusTextColor_CAwsRgb1p(CBComboBox* pThis, const CAwsRgb * color);
void CBComboBox_AdjustMenuPos_CBMenu1p_CEspRect1p(CBComboBox* pThis, CBMenu *  pMenu, CEspRect * rect);
void CBComboBox_CInit(CBComboBox* pThis);

// 虚函数表的声明
extern const VTab_CBComboBox g_tVTab_CBComboBox_CBComboBox;
extern const VTab_CAwsWindow g_tVTab_CBComboBox_CAwsWindow;


#endif /* _BCOMBOBOX_H_2009_10_09_ */
