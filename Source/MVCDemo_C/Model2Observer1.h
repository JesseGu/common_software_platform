// Model2Observer1.h: interface for the CModel2Observer1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODEL2OBSERVER1_H__D02628CB_DDC4_4EA8_A16B_5C1513EDB29C__INCLUDED_)
#define AFX_MODEL2OBSERVER1_H__D02628CB_DDC4_4EA8_A16B_5C1513EDB29C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISpxObserver.h"
#include "BLabel.h"

typedef struct tagCModel2Observer1 CModel2Observer1;

// 类声明
struct tagCModel2Observer1
{
	ISpxObserver m_oBase_ISpxObserver;
	CBLabel m_oBase_CBLabel;

};

// 成员函数声明
void CModel2Observer1_UpdateData_CSpxModel1p(ISpxObserver* this, CSpxModel *  pModel);
int CModel2Observer1_GetObserverID(ISpxObserver* this);
void CModel2Observer1_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CModel2Observer1_CInit(CModel2Observer1* pThis);

// 虚函数表的声明
extern const VTab_ISpxObserver g_tVTab_CModel2Observer1_ISpxObserver;
extern const VTab_CAwsWindow g_tVTab_CModel2Observer1_CAwsWindow;


#endif // !defined(AFX_MODEL2OBSERVER1_H__D02628CB_DDC4_4EA8_A16B_5C1513EDB29C__INCLUDED_)
