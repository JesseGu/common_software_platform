/******************************************************************************
* FileName		       : TabPage5.h
* Description          : interface for the CTabPage5 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABPAGE5_H__EC18370D_AFC4_41F1_88EE_C5E739495707__INCLUDED_)
#define AFX_TABPAGE5_H__EC18370D_AFC4_41F1_88EE_C5E739495707__INCLUDED_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

typedef struct tagCBComboBox CBComboBox;

typedef struct tagCBLabel CBLabel;

typedef struct tagCBEdit CBEdit;


typedef struct tagCTabPage5Builder CTabPage5Builder;

// 类声明
struct tagCTabPage5Builder
{
	IAwsContainerBuilder m_oBase_IAwsContainerBuilder;

};

// 成员函数声明
CAwsContainer *  CTabPage5Builder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent, const CEspRect * rect);
void CTabPage5Builder_CInit(CTabPage5Builder* pThis);

// 虚函数表的声明
extern const VTab_IAwsContainerBuilder g_tVTab_CTabPage5Builder_IAwsContainerBuilder;


typedef struct tagCTabPage5 CTabPage5;

// 类声明
struct tagCTabPage5
{
	CAwsContainer m_oBase_CAwsContainer;

	CBLabel *  m_pLabel;
	CBComboBox *  m_pComboBox;
	CBLabel *  m_pEditLabel;
	CBEdit *  m_pEdit;
};

// 成员函数声明
void CTabPage5_OnCreate(CAwsWindow* this);
void CTabPage5_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CTabPage5_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CTabPage5_OnFocus_i0p(CAwsWindow* this, int bIsFocus);
void CTabPage5_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CTabPage5_CInit(CTabPage5* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CTabPage5_CAwsWindow;


#endif // !defined(AFX_TABPAGE5_H__EC18370D_AFC4_41F1_88EE_C5E739495707__INCLUDED_)
