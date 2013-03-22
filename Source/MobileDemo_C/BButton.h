/******************************************************************************
* FileName		       : BButton.h
* Description          : interface for the CBButton class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BBUTTON_H__2009_10_09_
#define _BBUTTON_H__2009_10_09_

#include "AwsWindow.h"

typedef struct tagCBButton CBButton;

// 虚函数表
typedef void(*PVCBButton_DrawBK_IAwsGc1p_CEspRect1p)(CBButton* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBButton_DrawInf_IAwsGc1p_CEspRect1p)(CBButton* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBButton_DrawText_IAwsGc1p_CEspRect1p)(CBButton* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBButton_OnClick)(CBButton* pThis);
typedef struct tagVTab_CBButton VTab_CBButton;
struct tagVTab_CBButton
{
	PVCBButton_DrawBK_IAwsGc1p_CEspRect1p	m_pDrawBK_IAwsGc1p_CEspRect1p;
	PVCBButton_DrawInf_IAwsGc1p_CEspRect1p	m_pDrawInf_IAwsGc1p_CEspRect1p;
	PVCBButton_DrawText_IAwsGc1p_CEspRect1p	m_pDrawText_IAwsGc1p_CEspRect1p;
	PVCBButton_OnClick	m_pOnClick;
};

// 类声明
struct tagCBButton
{
	CAwsWindow m_oBase_CAwsWindow;

	CAwsString m_oText;
	CAwsRgb m_oBorderColor;
	CAwsRgb m_oBKColor;
	CAwsRgb m_oTextColor;
	CAwsRgb m_oTextFocusColor;
	CAwsFont m_oFont;
	int m_nFontSize;
	AWS_TextAlignMode m_eTextAlignMode;
	const VTab_CBButton*	m_pVTab;
};

// 成员函数声明
void CBButton_DrawBK_IAwsGc1p_CEspRect1p(CBButton* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBButton_DrawInf_IAwsGc1p_CEspRect1p(CBButton* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBButton_DrawText_IAwsGc1p_CEspRect1p(CBButton* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBButton_OnClick(CBButton* pThis);
void CBButton_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CBButton_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CBButton_OnFocus_i0p(CAwsWindow* this, int bIsFocus);
void CBButton_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CBButton_CInit(CBButton* pThis);
void CBButton_SetText_CAwsString1p(CBButton* pThis, const CAwsString * strText);
void CBButton_SetTextAlignment_0p(CBButton* pThis, AWS_TextAlignMode mode);
void CBButton_SetTextColor_CAwsRgb1p(CBButton* pThis, const CAwsRgb * colorText);
void CBButton_SetTextFocusColor_CAwsRgb1p(CBButton* pThis, const CAwsRgb * colorText);
void CBButton_SetBKColor_CAwsRgb1p(CBButton* pThis, const CAwsRgb * colorBK);
void CBButton_SetBorderColor_CAwsRgb1p(CBButton* pThis, const CAwsRgb * colorBorder);

// 虚函数表的声明
extern const VTab_CBButton g_tVTab_CBButton_CBButton;
extern const VTab_CAwsWindow g_tVTab_CBButton_CAwsWindow;


#endif /* _BBUTTON_H__2009_10_09_ */
