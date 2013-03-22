/******************************************************************************
* FileName		       : BLabel.h
* Description          : interface for the CBLabel class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BLABEL_H_2009_10_09_
#define _BLABEL_H_2009_10_09_

#include "AwsWindow.h"

typedef struct tagCBLabel CBLabel;

// 虚函数表
typedef void(*PVCBLabel_DrawText_IAwsGc1p_CEspRect1p)(CBLabel* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef struct tagVTab_CBLabel VTab_CBLabel;
struct tagVTab_CBLabel
{
	PVCBLabel_DrawText_IAwsGc1p_CEspRect1p	m_pDrawText_IAwsGc1p_CEspRect1p;
};

// 类声明
struct tagCBLabel
{
	CAwsWindow m_oBase_CAwsWindow;

	CAwsFont m_oFont;
	int m_nTextSize;
	CAwsString m_oStrText;
	CAwsRgb m_oTextColor;
	CAwsRgb m_oBKColor;
	AWS_TextAlignMode m_eAlignMode;
	const VTab_CBLabel*	m_pVTab;
};

// 成员函数声明
void CBLabel_DrawText_IAwsGc1p_CEspRect1p(CBLabel* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBLabel_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
void CBLabel_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CBLabel_CInit(CBLabel* pThis);
void CBLabel_SetText_CAwsString1p_i0p(CBLabel* pThis, const CAwsString * str, int bIsRedraw);
void CBLabel_GetText_CAwsString1p(CBLabel* pThis, CAwsString * str);
void CBLabel_SetTextColor_CAwsRgb1p_i0p(CBLabel* pThis, const CAwsRgb * color, int bIsRedraw);
void CBLabel_SetBKColor_CAwsRgb1p_i0p(CBLabel* pThis, const CAwsRgb * color, int bIsRedraw);
void CBLabel_SetTextSize_i0p(CBLabel* pThis, int nSize);
void CBLabel_SetTextAlignment_0p_i0p(CBLabel* pThis, AWS_TextAlignMode mode, int bIsRedraw);

// 虚函数表的声明
extern const VTab_CBLabel g_tVTab_CBLabel_CBLabel;
extern const VTab_CAwsWindow g_tVTab_CBLabel_CAwsWindow;


#endif /* _BLABEL_H_2009_10_09_ */
