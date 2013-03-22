// Model1Observer1.h: interface for the CModel1Observer1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODEL1OBSERVER1_H__D56F2DE8_CF4F_4FA5_BA5A_3661BFCBA092__INCLUDED_)
#define AFX_MODEL1OBSERVER1_H__D56F2DE8_CF4F_4FA5_BA5A_3661BFCBA092__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISpxObserver.h"
#include "BLabel.h"

typedef struct tagCModel1Observer1 CModel1Observer1;

// 类声明
struct tagCModel1Observer1
{
	CBLabel m_oBase_CBLabel;
	ISpxObserver m_oBase_ISpxObserver;

};

// 成员函数声明
void CModel1Observer1_UpdateData_CSpxModel1p(ISpxObserver* this, CSpxModel *  pModel);
int CModel1Observer1_GetObserverID(ISpxObserver* this);
void CModel1Observer1_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CModel1Observer1_CInit(CModel1Observer1* pThis);

// 虚函数表的声明
extern const VTab_ISpxObserver g_tVTab_CModel1Observer1_ISpxObserver;
extern const VTab_CAwsWindow g_tVTab_CModel1Observer1_CAwsWindow;


#endif // !defined(AFX_MODEL1OBSERVER1_H__D56F2DE8_CF4F_4FA5_BA5A_3661BFCBA092__INCLUDED_)
