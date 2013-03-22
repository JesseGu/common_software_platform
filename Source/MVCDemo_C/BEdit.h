/******************************************************************************
* FileName		       : BEdit.h
* Description          : interface for the CBEdit class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BEDIT_H_2009_10_09_
#define _BEDIT_H_2009_10_09_

#include "AwsWindow.h"
#include "EspString.h"

typedef struct tagIAwsGc IAwsGc;


typedef struct tagCBEdit CBEdit;

// 类声明
struct tagCBEdit
{
	CAwsWindow m_oBase_CAwsWindow;

	CAwsString m_strText;
	CAwsString m_strDrawText;
	CAwsRgb m_oBorderColor;
	CAwsRgb m_oFocusBorderColor;
	CAwsRgb m_oBKColor;
	CAwsRgb m_oCaretColor;
	CAwsRgb m_oTextColor;
	CEspPoint m_oCaretPos;
	CEspSize m_oCaretSize;
	int m_bCaretIsShow;
	int m_nCaretCharIndex;
	int m_bCaretIsVisible;
	int m_nCaretInterval;
	int m_nStartDrawCharIndex;
	CAwsFont m_oFont;
	int m_nFontSize;
};

// 成员函数声明
void CBEdit_OnTimer(CAwsWindow* this);
void CBEdit_OnImeChar_s0p(CAwsWindow* this, short nChar);
void CBEdit_OnFocus_i0p(CAwsWindow* this, int bIsFocus);
void CBEdit_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CBEdit_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CBEdit_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CBEdit_CInit(CBEdit* pThis);
void CBEdit_SetDefaultString_CAwsString1p(CBEdit* pThis, const CAwsString * str);
const CAwsString * CBEdit_GetString(CBEdit* pThis);
void CBEdit_SetCaretInterval_i0p(CBEdit* pThis, int nTimes);
void CBEdit_SetBorderColor_CAwsRgb1p(CBEdit* pThis, const CAwsRgb * color);
void CBEdit_SetFocusBorderColor_CAwsRgb1p(CBEdit* pThis, const CAwsRgb * color);
void CBEdit_SetBKColor_CAwsRgb1p(CBEdit* pThis, const CAwsRgb * color);
void CBEdit_SetCaretColor_CAwsRgb1p(CBEdit* pThis, const CAwsRgb * color);
void CBEdit_SetTextColor_CAwsRgb1p(CBEdit* pThis, const CAwsRgb * color);
void CBEdit_ShowCaret(CBEdit* pThis);
void CBEdit_HideCaret(CBEdit* pThis);
void CBEdit_DrawBK_IAwsGc1p_CEspRect1p(CBEdit* pThis, IAwsGc *  pGc, const CEspRect * rect);
int CBEdit_RightMoveOneChar(CBEdit* pThis);
int CBEdit_LeftMoveOneChar(CBEdit* pThis);
void CBEdit_DeleteOneChar(CBEdit* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CBEdit_CAwsWindow;


#endif /* _BEDIT_H_2009_10_09_ */
