/******************************************************************************
* FileName		       : BTabContainer.h
* Description          : interface for the CBTabContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BTABCONTAINER_H_2009_10_09_
#define _BTABCONTAINER_H_2009_10_09_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

typedef struct tagCBTabPanel CBTabPanel;


typedef struct tagCBTabView CBTabView;
typedef struct tagCBTabView_TRegisterData CBTabView_TRegisterData;

// 类声明
struct tagCBTabView_TRegisterData
{
	IAwsContainerBuilder *  m_pContainBuilder;
	CAwsContainer *  m_pContainer;
};


// 类声明
struct tagCBTabView
{
	CAwsContainer m_oBase_CAwsContainer;

	CBTabPanel *  m_pTabPanel;
	CBTabView_TRegisterData *  m_pRegData;
	int m_nMaxMainContainer;
	int m_nRegDataCount;
	CAwsContainer *  m_pCurContainer;
	int m_nCurContainerIndex;
	CEspRect m_rtClient;
};

// 成员函数声明
void CBTabView_DUninit_i1p(CAwsWindow* this, int * pOffset);
int CBTabView_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID, int nCmdID, int nParam1, int nParam2);
void CBTabView_OnSize_CEspSize1p_i0p(CAwsWindow* this, const CEspSize * size, int bIsRedraw);
int CBTabView_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CBTabView_OnCreate(CAwsWindow* this);
void CBTabView_CInit(CBTabView* pThis);
int CBTabView_RegisterMainContainer_IAwsContainerBuilder1p(CBTabView* pThis, IAwsContainerBuilder *  pContainBuilder);
int CBTabView_SwitchContainer_i0p(CBTabView* pThis, int nIndex);
CBTabPanel *  CBTabView_GetTabPanel(CBTabView* pThis);
CAwsContainer *  CBTabView_GetCurContainer(CBTabView* pThis);
CEspRect * CBTabView_GetClientRect(CBTabView* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CBTabView_CAwsWindow;


#endif /* _BTABCONTAINER_H_2009_10_09_ */
