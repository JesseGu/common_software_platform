// MyController1.h: interface for the CMyController1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCONTROLLER1_H__482F041F_3B29_49BF_997E_C9028F2DB0FC__INCLUDED_)
#define AFX_MYCONTROLLER1_H__482F041F_3B29_49BF_997E_C9028F2DB0FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpxController.h"

typedef struct tagCMyController1 CMyController1;

// 类声明
struct tagCMyController1
{
	CSpxController m_oBase_CSpxController;

};

// 成员函数声明
int CMyController1_OnRegisterObserver_ISpxObserver1p(CSpxController* this, ISpxObserver *  pObserver);
int CMyController1_OnUnregisterObserver_ISpxObserver1p(CSpxController* this, ISpxObserver *  pObserver);
int CMyController1_OnMessage_i0p_i0p_i0p_i0p(CSpxController* this, int nWndID, int nCmdID, int nParam1, int nParam2);
void CMyController1_DUninit_i1p(CSpxController* this, int* pOffset);
void CMyController1_CInit(CMyController1* pThis);

// 虚函数表的声明
extern const VTab_CSpxController g_tVTab_CMyController1_CSpxController;


#endif // !defined(AFX_MYCONTROLLER1_H__482F041F_3B29_49BF_997E_C9028F2DB0FC__INCLUDED_)
