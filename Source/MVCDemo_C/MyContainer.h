// MyContainer.h: interface for the CMyContainer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCONTAINER_H__56EEA06B_2399_4A70_B878_717DA5E56688__INCLUDED_)
#define AFX_MYCONTAINER_H__56EEA06B_2399_4A70_B878_717DA5E56688__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AwsContainer.h"
#include "Model1Observer1.h"
#include "Model1Observer2.h"
#include "Model2Observer1.h"
#include "Model2Observer2.h"

#include "BButton.h"

typedef struct tagCMyContainer CMyContainer;

// 类声明
struct tagCMyContainer
{
	CAwsContainer m_oBase_CAwsContainer;

	CModel1Observer1 *  m_pM1O1Label;
	CModel1Observer2 *  m_pM1O2Label;
	CModel2Observer1 *  m_pM2O1Label;
	CModel2Observer2 *  m_pM2O2Label;
	CBButton *  m_pM1Button;
	CBButton *  m_pM2Button;
};

// 成员函数声明
void CMyContainer_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
int CMyContainer_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CMyContainer_OnCreate(CAwsWindow* this);
void CMyContainer_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CMyContainer_CInit_i0p(CMyContainer* pThis, int nMaxSubWndCount);
void CMyContainer_CInit(CMyContainer* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CMyContainer_CAwsWindow;


#endif // !defined(AFX_MYCONTAINER_H__56EEA06B_2399_4A70_B878_717DA5E56688__INCLUDED_)
