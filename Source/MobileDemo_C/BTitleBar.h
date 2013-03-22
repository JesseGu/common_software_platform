/******************************************************************************
* FileName		       : BTitleBar.h
* Description          : interface for the CBTitleBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BTITLEBAR_H_2009_10_09_
#define _BTITLEBAR_H_2009_10_09_

#include "AwsWindow.h"

typedef struct tagCAwsImage CAwsImage;


typedef struct tagCBTitleBar CBTitleBar;

// 虚函数表
typedef void(*PVCBTitleBar_DrawBackground_IAwsGc1p_CEspRect1p)(CBTitleBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef int(*PVCBTitleBar_DrawIcon_IAwsGc1p_CEspRect1p_CEspSize1p)(CBTitleBar* pThis, IAwsGc *  pGc, const CEspRect * rect, CEspSize * sizeIcon);
typedef void(*PVCBTitleBar_DrawText_IAwsGc1p_CEspRect1p)(CBTitleBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef struct tagVTab_CBTitleBar VTab_CBTitleBar;
struct tagVTab_CBTitleBar
{
	PVCBTitleBar_DrawBackground_IAwsGc1p_CEspRect1p	m_pDrawBackground_IAwsGc1p_CEspRect1p;
	PVCBTitleBar_DrawIcon_IAwsGc1p_CEspRect1p_CEspSize1p	m_pDrawIcon_IAwsGc1p_CEspRect1p_CEspSize1p;
	PVCBTitleBar_DrawText_IAwsGc1p_CEspRect1p	m_pDrawText_IAwsGc1p_CEspRect1p;
};

// 类声明
struct tagCBTitleBar
{
	CAwsWindow m_oBase_CAwsWindow;

	CAwsImage m_oIconImage;
	CAwsImage m_oIconMask;
	CEspSize m_oIconSize;
	CAwsString m_oStrCaption;
	CAwsRgb m_oTextColor;
	CAwsRgb m_oBKColor;
	int m_nTitleBarHeight;
	CAwsFont m_oFont;
	int m_nFontSize;
	CAwsImage m_oBKImage;
	CEspSize m_oBKImageSize;
	int m_bIsSetBKImage;
	int m_nLeftMargin;
	const VTab_CBTitleBar*	m_pVTab;
};

// 成员函数声明
void CBTitleBar_DrawBackground_IAwsGc1p_CEspRect1p(CBTitleBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
int CBTitleBar_DrawIcon_IAwsGc1p_CEspRect1p_CEspSize1p(CBTitleBar* pThis, IAwsGc *  pGc, const CEspRect * rect, CEspSize * sizeIcon);
void CBTitleBar_DrawText_IAwsGc1p_CEspRect1p(CBTitleBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBTitleBar_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
void CBTitleBar_OnCreate(CAwsWindow* this);
void CBTitleBar_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CBTitleBar_CInit_i0p(CBTitleBar* pThis, int nTitleBarHeight);
void CBTitleBar_SetIcon_CAwsImage1p_CEspSize1p_CAwsImage1p(CBTitleBar* pThis, const CAwsImage * icon, const CEspSize * size, const CAwsImage *  pIconMask);
void CBTitleBar_SetCaption_CAwsString1p(CBTitleBar* pThis, const CAwsString * strText);
void CBTitleBar_SetTextColor_CAwsRgb1p(CBTitleBar* pThis, const CAwsRgb * color);
void CBTitleBar_SetBKColor_CAwsRgb1p(CBTitleBar* pThis, const CAwsRgb * color);
void CBTitleBar_SetTextFontSize_i0p(CBTitleBar* pThis, int nSize);
void CBTitleBar_SetTitleBarHeight_i0p(CBTitleBar* pThis, int nHeight);
void CBTitleBar_SetBKImage_CAwsImage1p_CEspSize1p(CBTitleBar* pThis, const CAwsImage * imageBK, const CEspSize * sizeImage);
void CBTitleBar_CInit(CBTitleBar* pThis);

// 虚函数表的声明
extern const VTab_CBTitleBar g_tVTab_CBTitleBar_CBTitleBar;
extern const VTab_CAwsWindow g_tVTab_CBTitleBar_CAwsWindow;


#endif /* _BTITLEBAR_H_2009_10_09_ */
