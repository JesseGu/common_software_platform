/******************************************************************************
* FileName		       : BTabPanel.h
* Description          : interface for the CBTabPanel class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BTABPANEL_H_2009_10_09_
#define _BTABPANEL_H_2009_10_09_

#include "AwsContainer.h"

typedef struct tagCBSelectBox CBSelectBox;


typedef struct tagCBTabPanel CBTabPanel;

// 类声明
struct tagCBTabPanel
{
	CAwsContainer m_oBase_CAwsContainer;

	CBSelectBox *  m_pSelectBox;
	CAwsImage m_oImageBK;
};

// 成员函数声明
int CBTabPanel_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID, int nCmdID, int nParam1, int nParam2);
void CBTabPanel_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
void CBTabPanel_OnCreate(CAwsWindow* this);
void CBTabPanel_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CBTabPanel_CInit(CBTabPanel* pThis);
void CBTabPanel_SetBKImage_CAwsImage1p(CBTabPanel* pThis, const CAwsImage * imageBK);
CBSelectBox *  CBTabPanel_GetSelectBox(CBTabPanel* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CBTabPanel_CAwsWindow;


#endif /* _BTABPANEL_H_2009_10_09_ */
