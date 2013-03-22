/******************************************************************************
* FileName		       : BScrollBar.h
* Description          : interface for the CBScrollBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BSCROLLBAR_H_2009_10_09_
#define _BSCROLLBAR_H_2009_10_09_

#include "AwsWindow.h"

// �������ķ���
typedef enum tagESBDir ESBDir;
enum tagESBDir
{
	ESB_Vertical,
	ESB_Horizontal
};


typedef struct tagCBScrollBar CBScrollBar;

// �麯����
typedef void(*PVCBScrollBar_DrawBK_IAwsGc1p_CEspRect1p)(CBScrollBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef void(*PVCBScrollBar_DrawBlock_IAwsGc1p_CEspRect1p)(CBScrollBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef struct tagVTab_CBScrollBar VTab_CBScrollBar;
struct tagVTab_CBScrollBar
{
	PVCBScrollBar_DrawBK_IAwsGc1p_CEspRect1p	m_pDrawBK_IAwsGc1p_CEspRect1p;
	PVCBScrollBar_DrawBlock_IAwsGc1p_CEspRect1p	m_pDrawBlock_IAwsGc1p_CEspRect1p;
};

// ������
struct tagCBScrollBar
{
	CAwsWindow m_oBase_CAwsWindow;

	ESBDir m_eDir;
	int m_nTotalLength;
	int m_nCurPos;
	int m_nMinBlockDim;
	int m_nCurBlockDim;
	int m_nMaxScrolldis;
	float m_fCurScrolldis;
	CAwsRgb m_oBlockColor;
	CAwsRgb m_oBKColor;
	const VTab_CBScrollBar*	m_pVTab;
};

// ��Ա��������
void CBScrollBar_DrawBK_IAwsGc1p_CEspRect1p(CBScrollBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBScrollBar_DrawBlock_IAwsGc1p_CEspRect1p(CBScrollBar* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBScrollBar_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
void CBScrollBar_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CBScrollBar_CInit(CBScrollBar* pThis);
void CBScrollBar_SetDirection_0p(CBScrollBar* pThis, ESBDir dir);
void CBScrollBar_SetTotalLength_i0p(CBScrollBar* pThis, int nTotal);
void CBScrollBar_SetCurPos_i0p(CBScrollBar* pThis, int nCur);

// �麯���������
extern const VTab_CBScrollBar g_tVTab_CBScrollBar_CBScrollBar;
extern const VTab_CAwsWindow g_tVTab_CBScrollBar_CAwsWindow;


#endif /* _BSCROLLBAR_H_2009_10_09_ */
