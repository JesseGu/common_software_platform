/******************************************************************************
* FileName		       : MMainContainer.h
* Description          : interface for the CMMainContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _MMAINCONTAINER_H_2009_10_09_
#define _MMAINCONTAINER_H_2009_10_09_

#include "BMenuContainer.h"

typedef struct tagCMUi CMUi;

typedef struct tagCBMenu CBMenu;
typedef struct tagCBMenu_TItemData CBMenu_TItemData;


typedef struct tagCMMainContainer CMMainContainer;

// 虚函数表
typedef void(*PVCMMainContainer_OnActive)(CMMainContainer* pThis);
typedef void(*PVCMMainContainer_InActive)(CMMainContainer* pThis);
typedef void(*PVCMMainContainer_OnLeftMenu)(CMMainContainer* pThis);
typedef void(*PVCMMainContainer_OnRightMenu)(CMMainContainer* pThis);
typedef struct tagVTab_CMMainContainer VTab_CMMainContainer;
struct tagVTab_CMMainContainer
{
	PVCMMainContainer_OnActive	m_pOnActive;
	PVCMMainContainer_InActive	m_pInActive;
	PVCMMainContainer_OnLeftMenu	m_pOnLeftMenu;
	PVCMMainContainer_OnRightMenu	m_pOnRightMenu;
};

// 类声明
struct tagCMMainContainer
{
	CBMenuContainer m_oBase_CBMenuContainer;

	CAwsString m_strLeftMenu;
	CAwsString m_strRightMenu;
	const VTab_CMMainContainer*	m_pVTab;
};

// 成员函数声明
void CMMainContainer_OnActive(CMMainContainer* pThis);
void CMMainContainer_InActive(CMMainContainer* pThis);
void CMMainContainer_OnLeftMenu(CMMainContainer* pThis);
void CMMainContainer_OnRightMenu(CMMainContainer* pThis);
void CMMainContainer_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CMMainContainer_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CMMainContainer_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CMMainContainer_CInit_i0p(CMMainContainer* pThis, int nMaxSubWndCount);
CMUi *  CMMainContainer_GetMUi(CMMainContainer* pThis);
void CMMainContainer_AdjustMenuPos_CBMenu1p_CEspRect1p_CEspPoint1p_i0p(CMMainContainer* pThis, CBMenu *  pMenu, CEspRect * rect, const CEspPoint * pt, int bIsSubMenu);
void CMMainContainer_UpdateMenuBar_0p_0p_i0p(CMMainContainer* pThis, AWS_SysStringID eLeftStrID, AWS_SysStringID eRightStrID, int bIsRedraw);
void CMMainContainer_CInit(CMMainContainer* pThis);

// 虚函数表的声明
extern const VTab_CMMainContainer g_tVTab_CMMainContainer_CMMainContainer;
extern const VTab_CAwsWindow g_tVTab_CMMainContainer_CAwsWindow;


#endif /* _MMAINCONTAINER_H_2009_10_09_ */
