// MyController2.h: interface for the CMyController2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCONTROLLER2_H__3357CECD_4745_4899_A905_9DD0526C052A__INCLUDED_)
#define AFX_MYCONTROLLER2_H__3357CECD_4745_4899_A905_9DD0526C052A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpxController.h"

typedef struct tagCMyController2 CMyController2;

// 类声明
struct tagCMyController2
{
	CSpxController m_oBase_CSpxController;

};

// 成员函数声明
int CMyController2_OnRegisterObserver_ISpxObserver1p(CSpxController* this, ISpxObserver *  pObserver);
int CMyController2_OnUnregisterObserver_ISpxObserver1p(CSpxController* this, ISpxObserver *  pObserver);
int CMyController2_OnMessage_i0p_i0p_i0p_i0p(CSpxController* this, int nWndID, int nCmdID, int nParam1, int nParam2);
void CMyController2_DUninit_i1p(CSpxController* this, int* pOffset);
void CMyController2_CInit(CMyController2* pThis);

// 虚函数表的声明
extern const VTab_CSpxController g_tVTab_CMyController2_CSpxController;


#endif // !defined(AFX_MYCONTROLLER2_H__3357CECD_4745_4899_A905_9DD0526C052A__INCLUDED_)
