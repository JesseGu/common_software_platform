/******************************************************************************
* FileName		       : MScrollLabel.h
* Description          : interface for the CMScrollLabel class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _MSCROLLLABEL_H_2009_10_09_
#define _MSCROLLLABEL_H_2009_10_09_

#include "BLabel.h"

typedef struct tagCMScrollLabel CMScrollLabel;

// 类声明
struct tagCMScrollLabel
{
	CBLabel m_oBase_CBLabel;

	int m_nScrollCount;
	int m_nCurCount;
	int m_nMoveLength;
	int m_nMoveStep;
	int m_nTextLen;
	CEspSize m_oSizeWnd;
	int m_nTimes;
};

// 成员函数声明
void CMScrollLabel_OnTimer(CAwsWindow* this);
void CMScrollLabel_OnCreate(CAwsWindow* this);
void CMScrollLabel_DrawText_IAwsGc1p_CEspRect1p(CBLabel* this, IAwsGc *  pGc, const CEspRect * rect);
void CMScrollLabel_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CMScrollLabel_CInit(CMScrollLabel* pThis);
void CMScrollLabel_StartScroll_i0p(CMScrollLabel* pThis, int nCount);
void CMScrollLabel_EndScroll(CMScrollLabel* pThis);
void CMScrollLabel_SetTimers_i0p(CMScrollLabel* pThis, int nTimers);
int CMScrollLabel_IsStartScroll(CMScrollLabel* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CMScrollLabel_CAwsWindow;
extern const VTab_CBLabel g_tVTab_CMScrollLabel_CBLabel;


#endif /* _MSCROLLLABEL_H_2009_10_09_ */
