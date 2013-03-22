/******************************************************************************
* FileName		       : TabPage3.h
* Description          : interface for the CTabPage3 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABPAGE3_H__7CD8642C_8403_4130_A705_0000BCDD77B5__INCLUDED_)
#define AFX_TABPAGE3_H__7CD8642C_8403_4130_A705_0000BCDD77B5__INCLUDED_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

typedef struct tagCBButton CBButton;

typedef struct tagCBImageButton CBImageButton;

typedef struct tagCBRadioBox CBRadioBox;

typedef struct tagCBCheckBox CBCheckBox;


typedef struct tagCTabPage3Builder CTabPage3Builder;

// 类声明
struct tagCTabPage3Builder
{
	IAwsContainerBuilder m_oBase_IAwsContainerBuilder;

};

// 成员函数声明
CAwsContainer *  CTabPage3Builder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent, const CEspRect * rect);
void CTabPage3Builder_CInit(CTabPage3Builder* pThis);

// 虚函数表的声明
extern const VTab_IAwsContainerBuilder g_tVTab_CTabPage3Builder_IAwsContainerBuilder;


typedef struct tagCTabPage3 CTabPage3;

// 类声明
struct tagCTabPage3
{
	CAwsContainer m_oBase_CAwsContainer;

	CBButton *  m_pButton;
	CBImageButton *  m_pImageButton;
	CBRadioBox *  m_pRadioBox;
	CBCheckBox *  m_pCheckBox;
};

// 成员函数声明
void CTabPage3_OnCreate(CAwsWindow* this);
void CTabPage3_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CTabPage3_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
int CTabPage3_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID, int nCmdID, int nParam1, int nParam2);
void CTabPage3_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CTabPage3_CInit(CTabPage3* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CTabPage3_CAwsWindow;


#endif // !defined(AFX_TABPAGE3_H__7CD8642C_8403_4130_A705_0000BCDD77B5__INCLUDED_)
