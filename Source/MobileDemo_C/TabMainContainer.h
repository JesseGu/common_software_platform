/******************************************************************************
* FileName		       : TabMainContainer.h
* Description          : interface for the CTabMainContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABMAINCONTAINER_H__98979F34_09AF_41C3_8997_0D50C2379768__INCLUDED_)
#define AFX_TABMAINCONTAINER_H__98979F34_09AF_41C3_8997_0D50C2379768__INCLUDED_

#include "MMainContainer.h"
#include "IAwsContainerBuilder.h"

typedef struct tagCBTabView CBTabView;
typedef struct tagCBTabView_TRegisterData CBTabView_TRegisterData;


typedef struct tagCTabMainContainerBuilder CTabMainContainerBuilder;

// 类声明
struct tagCTabMainContainerBuilder
{
	IAwsContainerBuilder m_oBase_IAwsContainerBuilder;

};

// 成员函数声明
CAwsContainer *  CTabMainContainerBuilder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent, const CEspRect * rect);
void CTabMainContainerBuilder_CInit(CTabMainContainerBuilder* pThis);

// 虚函数表的声明
extern const VTab_IAwsContainerBuilder g_tVTab_CTabMainContainerBuilder_IAwsContainerBuilder;


typedef struct tagCTabMainContainer CTabMainContainer;

// 类声明
struct tagCTabMainContainer
{
	CMMainContainer m_oBase_CMMainContainer;

	CBTabView *  m_pTabView;
};

// 成员函数声明
int CTabMainContainer_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID, int nCmdID, int nParam1, int nParam2);
int CTabMainContainer_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CTabMainContainer_OnSize_CEspSize1p_i0p(CAwsWindow* this, const CEspSize * size, int bIsRedraw);
void CTabMainContainer_OnActive(CMMainContainer* this);
void CTabMainContainer_InActive(CMMainContainer* this);
void CTabMainContainer_OnCreate(CAwsWindow* this);
void CTabMainContainer_OnLeftMenu(CMMainContainer* this);
void CTabMainContainer_OnRightMenu(CMMainContainer* this);
void CTabMainContainer_PopMenu_i0p_CEspPoint1p(CBMenuContainer* this, int nMenuID, const CEspPoint * pt);
void CTabMainContainer_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CTabMainContainer_CInit(CTabMainContainer* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CTabMainContainer_CAwsWindow;
extern const VTab_CMMainContainer g_tVTab_CTabMainContainer_CMMainContainer;
extern const VTab_CBMenuContainer g_tVTab_CTabMainContainer_CBMenuContainer;


#endif // !defined(AFX_TABMAINCONTAINER_H__98979F34_09AF_41C3_8997_0D50C2379768__INCLUDED_)
