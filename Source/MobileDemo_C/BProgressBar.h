/******************************************************************************
* FileName		       : BProgressBar.h
* Description          : interface for the CBProgressBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BPROGRESSBAR_H_2009_10_09_
#define _BPROGRESSBAR_H_2009_10_09_

#include "AwsWindow.h"

typedef struct tagCBProgressBar CBProgressBar;

// 虚函数表
typedef void(*PVCBProgressBar_OnDrawBK_IAwsGc1p_CEspRect1p)(CBProgressBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBProgressBar_OnDrawBorder_IAwsGc1p_CEspRect1p)(CBProgressBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBProgressBar_OnDrawProgress_IAwsGc1p_CEspRect1p)(CBProgressBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef struct tagVTab_CBProgressBar VTab_CBProgressBar;
struct tagVTab_CBProgressBar
{
	PVCBProgressBar_OnDrawBK_IAwsGc1p_CEspRect1p	m_pOnDrawBK_IAwsGc1p_CEspRect1p;
	PVCBProgressBar_OnDrawBorder_IAwsGc1p_CEspRect1p	m_pOnDrawBorder_IAwsGc1p_CEspRect1p;
	PVCBProgressBar_OnDrawProgress_IAwsGc1p_CEspRect1p	m_pOnDrawProgress_IAwsGc1p_CEspRect1p;
};

// 类声明
struct tagCBProgressBar
{
	CAwsWindow m_oBase_CAwsWindow;

	int m_nLength;
	int m_nCurPos;
	int m_nDrawPos;
	CAwsRgb m_oBKColor;
	CAwsRgb m_oProgressColor;
	CAwsRgb m_oBorderColor;
	int m_nBorderPixels;
	const VTab_CBProgressBar*	m_pVTab;
};

// 成员函数声明
void CBProgressBar_OnDrawBK_IAwsGc1p_CEspRect1p(CBProgressBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBProgressBar_OnDrawBorder_IAwsGc1p_CEspRect1p(CBProgressBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBProgressBar_OnDrawProgress_IAwsGc1p_CEspRect1p(CBProgressBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBProgressBar_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
void CBProgressBar_OnCreate(CAwsWindow* this);
void CBProgressBar_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CBProgressBar_CInit(CBProgressBar* pThis);
void CBProgressBar_SetTotalLenght_i0p(CBProgressBar* pThis, int nLength);
void CBProgressBar_SetPos_i0p(CBProgressBar* pThis, int nPos);
int CBProgressBar_GetPos(CBProgressBar* pThis);
void CBProgressBar_SetBKColor_CAwsRgb1p(CBProgressBar* pThis, const CAwsRgb * color);
void CBProgressBar_SetProgressColor_CAwsRgb1p(CBProgressBar* pThis, const CAwsRgb * color);
void CBProgressBar_SetBorderColor_CAwsRgb1p(CBProgressBar* pThis, const CAwsRgb * color);

// 虚函数表的声明
extern const VTab_CBProgressBar g_tVTab_CBProgressBar_CBProgressBar;
extern const VTab_CAwsWindow g_tVTab_CBProgressBar_CAwsWindow;


#endif /* _BPROGRESSBAR_H_2009_10_09_ */
