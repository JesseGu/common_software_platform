/******************************************************************************
* FileName		       : TabPage4.h
* Description          : interface for the CTabPage4 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABPAGE4_H__04FBC39C_1306_4C65_8616_35BA1DF9F02E__INCLUDED_)
#define AFX_TABPAGE4_H__04FBC39C_1306_4C65_8616_35BA1DF9F02E__INCLUDED_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

typedef struct tagCBSelectBox CBSelectBox;

typedef struct tagCBLabel CBLabel;

typedef struct tagCMImageBox CMImageBox;


typedef struct tagCTabPage4Builder CTabPage4Builder;

// 类声明
struct tagCTabPage4Builder
{
	IAwsContainerBuilder m_oBase_IAwsContainerBuilder;

};

// 成员函数声明
CAwsContainer *  CTabPage4Builder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent, const CEspRect * rect);
void CTabPage4Builder_CInit(CTabPage4Builder* pThis);

// 虚函数表的声明
extern const VTab_IAwsContainerBuilder g_tVTab_CTabPage4Builder_IAwsContainerBuilder;


typedef struct tagCTabPage4 CTabPage4;

// 类声明
struct tagCTabPage4
{
	CAwsContainer m_oBase_CAwsContainer;

	CBLabel *  m_pLabel;
	CBSelectBox *  m_pSelectBox;
	CMImageBox *  m_pImageBox;
};

// 成员函数声明
void CTabPage4_OnCreate(CAwsWindow* this);
void CTabPage4_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CTabPage4_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID, int nCmdID, int nParam1, int nParam2);
int CTabPage4_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CTabPage4_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CTabPage4_CInit(CTabPage4* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CTabPage4_CAwsWindow;


#endif // !defined(AFX_TABPAGE4_H__04FBC39C_1306_4C65_8616_35BA1DF9F02E__INCLUDED_)
