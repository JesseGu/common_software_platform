// Model1Observer2.h: interface for the CModel1Observer2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODEL1OBSERVER2_H__52E25931_3C94_46CB_9ACC_CAA03235D85F__INCLUDED_)
#define AFX_MODEL1OBSERVER2_H__52E25931_3C94_46CB_9ACC_CAA03235D85F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISpxObserver.h"
#include "BLabel.h"

typedef struct tagCModel1Observer2 CModel1Observer2;

// 类声明
struct tagCModel1Observer2
{
	ISpxObserver m_oBase_ISpxObserver;
	CBLabel m_oBase_CBLabel;

};

// 成员函数声明
void CModel1Observer2_UpdateData_CSpxModel1p(ISpxObserver* this, CSpxModel *  pModel);
int CModel1Observer2_GetObserverID(ISpxObserver* this);
void CModel1Observer2_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CModel1Observer2_CInit(CModel1Observer2* pThis);

// 虚函数表的声明
extern const VTab_ISpxObserver g_tVTab_CModel1Observer2_ISpxObserver;
extern const VTab_CAwsWindow g_tVTab_CModel1Observer2_CAwsWindow;


#endif // !defined(AFX_MODEL1OBSERVER2_H__52E25931_3C94_46CB_9ACC_CAA03235D85F__INCLUDED_)
