/******************************************************************************
* FileName		       : MMsgBox.h
* Description          : interface for the CMMsgBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _MMSGBOX_H_2009_10_09_
#define _MMSGBOX_H_2009_10_09_

#include "AwsContainer.h"

typedef struct tagIAwsGc IAwsGc;


typedef struct tagCMMsgBox CMMsgBox;

// 虚函数表
typedef void(*PVCMMsgBox_DrawBK_IAwsGc1p_CEspRect1p)(CMMsgBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCMMsgBox_DrawInf_IAwsGc1p_CEspRect1p)(CMMsgBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCMMsgBox_OnLeftMenu)(CMMsgBox* pThis);
typedef void(*PVCMMsgBox_OnRightMenu)(CMMsgBox* pThis);
typedef struct tagVTab_CMMsgBox VTab_CMMsgBox;
struct tagVTab_CMMsgBox
{
	PVCMMsgBox_DrawBK_IAwsGc1p_CEspRect1p	m_pDrawBK_IAwsGc1p_CEspRect1p;
	PVCMMsgBox_DrawInf_IAwsGc1p_CEspRect1p	m_pDrawInf_IAwsGc1p_CEspRect1p;
	PVCMMsgBox_OnLeftMenu	m_pOnLeftMenu;
	PVCMMsgBox_OnRightMenu	m_pOnRightMenu;
};

// 类声明
struct tagCMMsgBox
{
	CAwsContainer m_oBase_CAwsContainer;

	AWS_MsgBoxType m_eType;
	CAwsString m_strText;
	CAwsRgb m_oBorderColor;
	CAwsRgb m_oBKColor;
	CAwsRgb m_oTextColor;
	CAwsFont m_oFont;
	int m_nFontSize;
	const VTab_CMMsgBox*	m_pVTab;
};

// 成员函数声明
void CMMsgBox_DrawBK_IAwsGc1p_CEspRect1p(CMMsgBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CMMsgBox_DrawInf_IAwsGc1p_CEspRect1p(CMMsgBox* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CMMsgBox_OnLeftMenu(CMMsgBox* pThis);
void CMMsgBox_OnRightMenu(CMMsgBox* pThis);
void CMMsgBox_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CMMsgBox_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID, int nCmdID, int nParam1, int nParam2);
int CMMsgBox_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CMMsgBox_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CMMsgBox_CInit_CAwsWindow1p_i0p(CMMsgBox* pThis, CAwsWindow *  pParentWnd, int nWndID);
void CMMsgBox_ShowMsg_0p_CAwsString1p(CMMsgBox* pThis, AWS_MsgBoxType eType, const CAwsString * strText);
void CMMsgBox_SetBorderColor_CAwsRgb1p(CMMsgBox* pThis, const CAwsRgb * color);
void CMMsgBox_SetBKColor_CAwsRgb1p(CMMsgBox* pThis, const CAwsRgb * color);
void CMMsgBox_SetTextColor_CAwsRgb1p(CMMsgBox* pThis, const CAwsRgb * color);
void CMMsgBox_SetFontSize_i0p(CMMsgBox* pThis, int nFontSize);
void CMMsgBox_CInit(CMMsgBox* pThis);

// 虚函数表的声明
extern const VTab_CMMsgBox g_tVTab_CMMsgBox_CMMsgBox;
extern const VTab_CAwsWindow g_tVTab_CMMsgBox_CAwsWindow;


#endif /* _MMSGBOX_H_2009_10_09_ */
