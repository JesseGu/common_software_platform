/******************************************************************************
* FileName		       : TabPage1.h
* Description          : interface for the CTabPage1 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABPAGE1_H__7955D5A3_7F38_4758_A361_64E253330A97__INCLUDED_)
#define AFX_TABPAGE1_H__7955D5A3_7F38_4758_A361_64E253330A97__INCLUDED_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

typedef struct tagCBLabel CBLabel;

typedef struct tagCBProgressBar CBProgressBar;

typedef struct tagCBButton CBButton;


typedef struct tagCTabPage1Builder CTabPage1Builder;

// 类声明
struct tagCTabPage1Builder
{
	IAwsContainerBuilder m_oBase_IAwsContainerBuilder;

};

// 成员函数声明
CAwsContainer *  CTabPage1Builder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent, const CEspRect * rect);
void CTabPage1Builder_CInit(CTabPage1Builder* pThis);

// 虚函数表的声明
extern const VTab_IAwsContainerBuilder g_tVTab_CTabPage1Builder_IAwsContainerBuilder;


typedef struct tagCTabPage1 CTabPage1;

// 类声明
struct tagCTabPage1
{
	CAwsContainer m_oBase_CAwsContainer;

	CBLabel *  m_pLabel;
	CBProgressBar *  m_pProgressBar;
	int m_nProgressBarLength;
	int m_nCurProgressBarPos;
	CBButton *  m_pButton;
	int m_bIsStart;
};

// 成员函数声明
void CTabPage1_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
void CTabPage1_OnTimer(CAwsWindow* this);
void CTabPage1_OnFocus_i0p(CAwsWindow* this, int bIsFocus);
int CTabPage1_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID, int nCmdID, int nParam1, int nParam2);
int CTabPage1_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CTabPage1_OnCreate(CAwsWindow* this);
void CTabPage1_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CTabPage1_CInit(CTabPage1* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CTabPage1_CAwsWindow;


#endif // !defined(AFX_TABPAGE1_H__7955D5A3_7F38_4758_A361_64E253330A97__INCLUDED_)
