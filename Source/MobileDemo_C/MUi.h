/******************************************************************************
* FileName		       : MUi.h
* Description          : interface for the CMUi class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _MUI_H_2009_10_09_
#define _MUI_H_2009_10_09_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

typedef struct tagCMMenuBar CMMenuBar;

typedef struct tagCBTitleBar CBTitleBar;

typedef struct tagCMMainContainer CMMainContainer;

typedef struct tagCMMenu CMMenu;


// Mobile UI Manager, MenuBar, TitleBar
typedef struct tagCMUi CMUi;
typedef struct tagCMUi_TRegisterData CMUi_TRegisterData;

// 类声明
struct tagCMUi_TRegisterData
{
	int m_nID;
	IAwsContainerBuilder *  m_pMainContainerBuilder;
	CMMainContainer *  m_pContainer;
};


// 类声明
struct tagCMUi
{
	CAwsContainer m_oBase_CAwsContainer;

	CMMenuBar *  m_pMenuBar;
	CBTitleBar *  m_pTitleBar;
	int m_bIsHideMenuBar;
	int m_bIsHideTitleBar;
	int m_nTitleBarHeight;
	int m_nMenuBarHeight;
	CMMainContainer *  m_pCurMainContainer;
	int m_nCurMainContainerID;
	CMUi_TRegisterData *  m_pRegData;
	int m_nMaxMainContainer;
	int m_nRegDataCount;
	CEspRect m_rtClient;
};

// 成员函数声明
void CMUi_DUninit_i1p(CAwsWindow* this, int * pOffset);
void CMUi_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
void CMUi_OnCreate(CAwsWindow* this);
void CMUi_CInit_i0p(CMUi* pThis, int nMaxSubWndCount);
void CMUi_HideMenuBar_i0p_i0p(CMUi* pThis, int bIsHide, int bIsRedraw);
void CMUi_HideTitleBar_i0p_i0p(CMUi* pThis, int bIsHide, int bIsRedraw);
CMMenuBar *  CMUi_GetMenuBar(CMUi* pThis);
CBTitleBar *  CMUi_GetTitleBar(CMUi* pThis);
CEspRect * CMUi_GetClientRect(CMUi* pThis);
int CMUi_ChangeMainContainer_i0p_i0p_i0p_i0p(CMUi* pThis, int nID, int bIsHideTitleBar, int bIsHideMenuBar, int bIsDestroyFormer);
int CMUi_RegisterMainContainer_i0p_IAwsContainerBuilder1p(CMUi* pThis, int nID, IAwsContainerBuilder *  pMainContainerBuilder);
int CMUi_GetIndexFromID_i0p(CMUi* pThis, int nID);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CMUi_CAwsWindow;


#endif /* _MUI_H_2009_10_09_ */
