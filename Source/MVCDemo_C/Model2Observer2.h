// Model2Observer2.h: interface for the CModel2Observer2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODEL2OBSERVER2_H__E383C6D4_727C_46ED_A0C4_2017492D789E__INCLUDED_)
#define AFX_MODEL2OBSERVER2_H__E383C6D4_727C_46ED_A0C4_2017492D789E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISpxObserver.h"
#include "BLabel.h"

typedef struct tagCModel2Observer2 CModel2Observer2;

// 类声明
struct tagCModel2Observer2
{
	ISpxObserver m_oBase_ISpxObserver;
	CBLabel m_oBase_CBLabel;

};

// 成员函数声明
void CModel2Observer2_UpdateData_CSpxModel1p(ISpxObserver* this, CSpxModel *  pModel);
int CModel2Observer2_GetObserverID(ISpxObserver* this);
void CModel2Observer2_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CModel2Observer2_CInit(CModel2Observer2* pThis);

// 虚函数表的声明
extern const VTab_ISpxObserver g_tVTab_CModel2Observer2_ISpxObserver;
extern const VTab_CAwsWindow g_tVTab_CModel2Observer2_CAwsWindow;


#endif // !defined(AFX_MODEL2OBSERVER2_H__E383C6D4_727C_46ED_A0C4_2017492D789E__INCLUDED_)
