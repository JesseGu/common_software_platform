/******************************************************************************
* FileName		       : IAwsGc.h
* Description          : interface of the IAwsGc
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _IAWSGC_H_2009_09_17_
#define _IAWSGC_H_2009_09_17_

#include "Aws.h"

typedef struct tagIAwsGc IAwsGc;

// 虚函数表
typedef void(*PVIAwsGc_SetOrigin_CEspPoint1p)(IAwsGc* pThis, CEspPoint * pt);
typedef void(*PVIAwsGc_SetPenWidth_i0p)(IAwsGc* pThis, int nPixels);
typedef void(*PVIAwsGc_SetPenColor_CAwsRgb1p)(IAwsGc* pThis, const CAwsRgb * color);
typedef void(*PVIAwsGc_SetBrushColor_CAwsRgb1p)(IAwsGc* pThis, const CAwsRgb * color);
typedef void(*PVIAwsGc_DrawLine_CEspPoint1p_CEspPoint1p)(IAwsGc* pThis, const CEspPoint * ptStart, const CEspPoint * ptEnd);
typedef void(*PVIAwsGc_DrawRect_CEspRect1p)(IAwsGc* pThis, const CEspRect * rect);
typedef void(*PVIAwsGc_DrawFillRect_CEspRect1p)(IAwsGc* pThis, const CEspRect * rect);
typedef void(*PVIAwsGc_DrawEllipse_CEspRect1p)(IAwsGc* pThis, const CEspRect * rect);
typedef void(*PVIAwsGc_SetTextColor_CAwsRgb1p)(IAwsGc* pThis, const CAwsRgb * color);
typedef void(*PVIAwsGc_SetTextBKColor_CAwsRgb1p)(IAwsGc* pThis, const CAwsRgb * color);
typedef void(*PVIAwsGc_SetTextBKMode_0p)(IAwsGc* pThis, AWS_TextShowMode mode);
typedef void(*PVIAwsGc_SetTextAlignment_0p)(IAwsGc* pThis, AWS_TextAlignMode mode);
typedef void(*PVIAwsGc_DrawText_CAwsString1p_CEspRect1p)(IAwsGc* pThis, const CAwsString * strText, const CEspRect * rect);
typedef const CEspSize * (*PVIAwsGc_GetTextSize_CAwsString1p)(IAwsGc* pThis, const CAwsString * strText);
typedef void(*PVIAwsGc_UseFont_CAwsFont1p)(IAwsGc* pThis, const CAwsFont * font);
typedef void(*PVIAwsGc_DiscardFont)(IAwsGc* pThis);
typedef void(*PVIAwsGc_DrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p)(IAwsGc* pThis, const CEspPoint * pt, const CAwsImage * image, const CAwsImage *  pMaskImage);
typedef void(*PVIAwsGc_SetClipRect_CEspRect1p)(IAwsGc* pThis, const CEspRect * rect);
typedef void(*PVIAwsGc_ResetClipRect)(IAwsGc* pThis);
typedef struct tagVTab_IAwsGc VTab_IAwsGc;
struct tagVTab_IAwsGc
{
	PVIAwsGc_SetOrigin_CEspPoint1p	m_pSetOrigin_CEspPoint1p;
	PVIAwsGc_SetPenWidth_i0p	m_pSetPenWidth_i0p;
	PVIAwsGc_SetPenColor_CAwsRgb1p	m_pSetPenColor_CAwsRgb1p;
	PVIAwsGc_SetBrushColor_CAwsRgb1p	m_pSetBrushColor_CAwsRgb1p;
	PVIAwsGc_DrawLine_CEspPoint1p_CEspPoint1p	m_pDrawLine_CEspPoint1p_CEspPoint1p;
	PVIAwsGc_DrawRect_CEspRect1p	m_pDrawRect_CEspRect1p;
	PVIAwsGc_DrawFillRect_CEspRect1p	m_pDrawFillRect_CEspRect1p;
	PVIAwsGc_DrawEllipse_CEspRect1p	m_pDrawEllipse_CEspRect1p;
	PVIAwsGc_SetTextColor_CAwsRgb1p	m_pSetTextColor_CAwsRgb1p;
	PVIAwsGc_SetTextBKColor_CAwsRgb1p	m_pSetTextBKColor_CAwsRgb1p;
	PVIAwsGc_SetTextBKMode_0p	m_pSetTextBKMode_0p;
	PVIAwsGc_SetTextAlignment_0p	m_pSetTextAlignment_0p;
	PVIAwsGc_DrawText_CAwsString1p_CEspRect1p	m_pDrawText_CAwsString1p_CEspRect1p;
	PVIAwsGc_GetTextSize_CAwsString1p	m_pGetTextSize_CAwsString1p;
	PVIAwsGc_UseFont_CAwsFont1p	m_pUseFont_CAwsFont1p;
	PVIAwsGc_DiscardFont	m_pDiscardFont;
	PVIAwsGc_DrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p	m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p;
	PVIAwsGc_SetClipRect_CEspRect1p	m_pSetClipRect_CEspRect1p;
	PVIAwsGc_ResetClipRect	m_pResetClipRect;
};

// 类声明
struct tagIAwsGc
{
	const VTab_IAwsGc*	m_pVTab;
};

// 成员函数声明
void IAwsGc_SetOrigin_CEspPoint1p(IAwsGc* pThis, CEspPoint * pt);
void IAwsGc_SetPenWidth_i0p(IAwsGc* pThis, int nPixels);
void IAwsGc_SetPenColor_CAwsRgb1p(IAwsGc* pThis, const CAwsRgb * color);
void IAwsGc_SetBrushColor_CAwsRgb1p(IAwsGc* pThis, const CAwsRgb * color);
void IAwsGc_DrawLine_CEspPoint1p_CEspPoint1p(IAwsGc* pThis, const CEspPoint * ptStart, const CEspPoint * ptEnd);
void IAwsGc_DrawRect_CEspRect1p(IAwsGc* pThis, const CEspRect * rect);
void IAwsGc_DrawFillRect_CEspRect1p(IAwsGc* pThis, const CEspRect * rect);
void IAwsGc_DrawEllipse_CEspRect1p(IAwsGc* pThis, const CEspRect * rect);
void IAwsGc_SetTextColor_CAwsRgb1p(IAwsGc* pThis, const CAwsRgb * color);
void IAwsGc_SetTextBKColor_CAwsRgb1p(IAwsGc* pThis, const CAwsRgb * color);
void IAwsGc_SetTextBKMode_0p(IAwsGc* pThis, AWS_TextShowMode mode);
void IAwsGc_SetTextAlignment_0p(IAwsGc* pThis, AWS_TextAlignMode mode);
void IAwsGc_DrawText_CAwsString1p_CEspRect1p(IAwsGc* pThis, const CAwsString * strText, const CEspRect * rect);
const CEspSize *  IAwsGc_GetTextSize_CAwsString1p(IAwsGc* pThis, const CAwsString * strText);
void IAwsGc_UseFont_CAwsFont1p(IAwsGc* pThis, const CAwsFont * font);
void IAwsGc_DiscardFont(IAwsGc* pThis);
void IAwsGc_DrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(IAwsGc* pThis, const CEspPoint * pt, const CAwsImage * image, const CAwsImage *  pMaskImage);
void IAwsGc_SetClipRect_CEspRect1p(IAwsGc* pThis, const CEspRect * rect);
void IAwsGc_ResetClipRect(IAwsGc* pThis);

// 虚函数表的声明
extern const VTab_IAwsGc g_tVTab_IAwsGc_IAwsGc;


#endif /* _IAWSGC_H_2009_09_17_ */
