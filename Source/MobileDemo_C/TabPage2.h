/******************************************************************************
* FileName		       : TabPage2.h
* Description          : interface for the CTabPage2 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABPAGE2_H__E09650F0_D652_4051_8C41_36707E6368B3__INCLUDED_)
#define AFX_TABPAGE2_H__E09650F0_D652_4051_8C41_36707E6368B3__INCLUDED_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

typedef struct tagCBListBox CBListBox;

typedef struct tagCBLabel CBLabel;


typedef struct tagCTabPage2Builder CTabPage2Builder;

// 类声明
struct tagCTabPage2Builder
{
	IAwsContainerBuilder m_oBase_IAwsContainerBuilder;

};

// 成员函数声明
CAwsContainer *  CTabPage2Builder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent, const CEspRect * rect);
void CTabPage2Builder_CInit(CTabPage2Builder* pThis);

// 虚函数表的声明
extern const VTab_IAwsContainerBuilder g_tVTab_CTabPage2Builder_IAwsContainerBuilder;


typedef struct tagCTabPage2 CTabPage2;

// 类声明
struct tagCTabPage2
{
	CAwsContainer m_oBase_CAwsContainer;

	CBListBox *  m_pListBox;
	CBLabel *  m_pLabel;
};

// 成员函数声明
void CTabPage2_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CTabPage2_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID, int nCmdID, int nParam1, int nParam2);
void CTabPage2_OnCreate(CAwsWindow* this);
void CTabPage2_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CTabPage2_CInit(CTabPage2* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CTabPage2_CAwsWindow;


#endif // !defined(AFX_TABPAGE2_H__E09650F0_D652_4051_8C41_36707E6368B3__INCLUDED_)
