/******************************************************************************
* FileName		       : MyMainContainer.h
* Description          : interface for the CMyMainContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_MYMAIN_H__B82014C3_03FC_4243_AC38_77925A5B61AC__INCLUDED_)
#define AFX_MYMAIN_H__B82014C3_03FC_4243_AC38_77925A5B61AC__INCLUDED_

#include "MMainContainer.h"
#include "IAwsContainerBuilder.h"

typedef struct tagCBScrollBar CBScrollBar;

typedef struct tagCBListView CBListView;
typedef struct tagCBListView_TLVData CBListView_TLVData;


typedef struct tagCMyMainContainerBuilder CMyMainContainerBuilder;

// 类声明
struct tagCMyMainContainerBuilder
{
	IAwsContainerBuilder m_oBase_IAwsContainerBuilder;

};

// 成员函数声明
CAwsContainer *  CMyMainContainerBuilder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* this, CAwsWindow *  pParent, const CEspRect * rect);
void CMyMainContainerBuilder_CInit(CMyMainContainerBuilder* pThis);

// 虚函数表的声明
extern const VTab_IAwsContainerBuilder g_tVTab_CMyMainContainerBuilder_IAwsContainerBuilder;


typedef struct tagCMyMainContainer CMyMainContainer;

// 类声明
struct tagCMyMainContainer
{
	CMMainContainer m_oBase_CMMainContainer;

	CBScrollBar *  m_pScrollBar;
	int m_nScrollTotalLength;
	int m_nScrollPos;
	CBListView *  m_pListView;
};

// 成员函数声明
int CMyMainContainer_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID, int nCmdID, int nParam1, int nParam2);
int CMyMainContainer_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type, AWS_KeyCode code);
void CMyMainContainer_OnSize_CEspSize1p_i0p(CAwsWindow* this, const CEspSize * size, int bIsRedraw);
void CMyMainContainer_OnActive(CMMainContainer* this);
void CMyMainContainer_InActive(CMMainContainer* this);
void CMyMainContainer_OnCreate(CAwsWindow* this);
void CMyMainContainer_OnLeftMenu(CMMainContainer* this);
void CMyMainContainer_OnRightMenu(CMMainContainer* this);
void CMyMainContainer_PopMenu_i0p_CEspPoint1p(CBMenuContainer* this, int nMenuID, const CEspPoint * pt);
void CMyMainContainer_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CMyMainContainer_CInit(CMyMainContainer* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CMyMainContainer_CAwsWindow;
extern const VTab_CMMainContainer g_tVTab_CMyMainContainer_CMMainContainer;
extern const VTab_CBMenuContainer g_tVTab_CMyMainContainer_CBMenuContainer;


#endif // !defined(AFX_MYMAIN_H__B82014C3_03FC_4243_AC38_77925A5B61AC__INCLUDED_)
