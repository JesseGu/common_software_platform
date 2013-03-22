/******************************************************************************
* FileName		       : MMenuBar.h
* Description          : interface for the CMMenuBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _MMENUBAR_H_2009_10_09_
#define _MMENUBAR_H_2009_10_09_

#include "AwsContainer.h"

typedef struct tagCBLabel CBLabel;


typedef struct tagCMMenuBar CMMenuBar;

// 虚函数表
typedef void(*PVCMMenuBar_DrawBK_IAwsGc1p_CEspRect1p)(CMMenuBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef struct tagVTab_CMMenuBar VTab_CMMenuBar;
struct tagVTab_CMMenuBar
{
	PVCMMenuBar_DrawBK_IAwsGc1p_CEspRect1p	m_pDrawBK_IAwsGc1p_CEspRect1p;
};

// 类声明
struct tagCMMenuBar
{
	CAwsContainer m_oBase_CAwsContainer;

	CBLabel *  m_pLeftBar;
	CBLabel *  m_pRightBar;
	CAwsRgb m_oBorderColor;
	CAwsRgb m_oBackColor;
	CAwsRgb m_oTextColor;
	CAwsFont m_oFont;
	int m_nFontSize;
	CAwsWindow *  m_pMidCtrl;
	int m_nBarUnitWidth;
	int m_nMenuBarHeight;
	CAwsImage m_oBKImage;
	CEspSize m_oBKImageSize;
	int m_bIsSetImage;
	const VTab_CMMenuBar*	m_pVTab;
};

// 成员函数声明
void CMMenuBar_DrawBK_IAwsGc1p_CEspRect1p(CMMenuBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CMMenuBar_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
void CMMenuBar_OnCreate(CAwsWindow* this);
void CMMenuBar_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CMMenuBar_CInit_i0p_CAwsWindow1p(CMMenuBar* pThis, int nMenuBarHeight, CAwsWindow *  pMidCtrl);
void CMMenuBar_SetMidCtrl_CAwsWindow1p(CMMenuBar* pThis, CAwsWindow *  pMidCtrl);
CAwsWindow *  CMMenuBar_GetMidCtrl(CMMenuBar* pThis);
void CMMenuBar_SetLeftMenuText_CAwsString1p_i0p(CMMenuBar* pThis, const CAwsString * strText, int bIsRedraw);
void CMMenuBar_SetRightMenuText_CAwsString1p_i0p(CMMenuBar* pThis, const CAwsString * strText, int bIsRedraw);
void CMMenuBar_SetTextColor_CAwsRgb1p(CMMenuBar* pThis, const CAwsRgb * color);
void CMMenuBar_SetBKColor_CAwsRgb1p(CMMenuBar* pThis, const CAwsRgb * color);
void CMMenuBar_SetBKImage_CAwsImage1p_CEspSize1p(CMMenuBar* pThis, const CAwsImage * imageBK, const CEspSize * sizeIamge);
void CMMenuBar_CInit(CMMenuBar* pThis);

// 虚函数表的声明
extern const VTab_CMMenuBar g_tVTab_CMMenuBar_CMMenuBar;
extern const VTab_CAwsWindow g_tVTab_CMMenuBar_CAwsWindow;


#endif /* _MMENUBAR_H_2009_10_09_ */
