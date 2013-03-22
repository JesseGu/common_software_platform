/******************************************************************************
* FileName		       : TabPage6.h
* Description          : interface for the CTabPage6 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABPAGE6_H__7AA82EB1_4BD6_4534_9A3B_2E0985985314__INCLUDED_)
#define AFX_TABPAGE6_H__7AA82EB1_4BD6_4534_9A3B_2E0985985314__INCLUDED_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

typedef struct tagCMScrollLabel CMScrollLabel;

typedef struct tagCBButton CBButton;

typedef struct tagCBLabel CBLabel;


typedef struct tagCTabPage6Builder CTabPage6Builder;

// 类声明
struct tagCTabPage6Builder
{
	IAwsContainerBuilder m_oBase_IAwsContainerBuilder;

};

// 成员函数声明
CAwsContainer *  CTabPage6Builder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent, const CEspRect * rect);
void CTabPage6Builder_CInit(CTabPage6Builder* pThis);

// 虚函数表的声明
extern const VTab_IAwsContainerBuilder g_tVTab_CTabPage6Builder_IAwsContainerBuilder;


typedef struct tagCTabPage6 CTabPage6;

// 类声明
struct tagCTabPage6
{
	CAwsContainer m_oBase_CAwsContainer;

	CMScrollLabel *  m_pScrollLabel;
	CBButton *  m_pButton;
	CBLabel *  m_pLabel;
};

// 成员函数声明
void CTabPage6_OnCreate(CAwsWindow* this);
void CTabPage6_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CTabPage6_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID, int nCmdID, int nParam1, int nParam2);
void CTabPage6_OnFocus_i0p(CAwsWindow* this, int bIsFocus);
int CTabPage6_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CTabPage6_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CTabPage6_CInit(CTabPage6* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CTabPage6_CAwsWindow;


#endif // !defined(AFX_TABPAGE6_H__7AA82EB1_4BD6_4534_9A3B_2E0985985314__INCLUDED_)
