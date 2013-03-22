/******************************************************************************
* FileName		       : BMenuContainer.h
* Description          : interface for the CBMenuContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-09

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BMENUCONTAINER_H_2011_03_09_
#define _BMENUCONTAINER_H_2011_03_09_

#include "AwsContainer.h"

// 带菜单的容器
typedef struct tagCBMenuContainer CBMenuContainer;

// 虚函数表
typedef void(*PVCBMenuContainer_PopMenu_i0p_CEspPoint1p)(CBMenuContainer* pThis, int nMenuID, const CEspPoint * pt);
typedef struct tagVTab_CBMenuContainer VTab_CBMenuContainer;
struct tagVTab_CBMenuContainer
{
	PVCBMenuContainer_PopMenu_i0p_CEspPoint1p	m_pPopMenu_i0p_CEspPoint1p;
};

// 类声明
struct tagCBMenuContainer
{
	CAwsContainer m_oBase_CAwsContainer;

	const VTab_CBMenuContainer*	m_pVTab;
};

// 成员函数声明
void CBMenuContainer_PopMenu_i0p_CEspPoint1p(CBMenuContainer* pThis, int nMenuID, const CEspPoint * pt);
int CBMenuContainer_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID, int nCmdID, int nParam1, int nParam2);
void CBMenuContainer_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CBMenuContainer_CInit_i0p(CBMenuContainer* pThis, int nMaxSubWndCount);
void CBMenuContainer_CInit(CBMenuContainer* pThis);

// 虚函数表的声明
extern const VTab_CBMenuContainer g_tVTab_CBMenuContainer_CBMenuContainer;
extern const VTab_CAwsWindow g_tVTab_CBMenuContainer_CAwsWindow;


#endif /* _BMENUCONTAINER_H_2011_03_09_ */
