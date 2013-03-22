// MyModel1.h: interface for the CMyModel1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMODEL1_H__91FAF2C4_ACAF_454F_B1BB_D7804EF994CB__INCLUDED_)
#define AFX_MYMODEL1_H__91FAF2C4_ACAF_454F_B1BB_D7804EF994CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpxModel.h"

typedef struct tagCMyModel1 CMyModel1;

// 类声明
struct tagCMyModel1
{
	CSpxModel m_oBase_CSpxModel;

	int m_nData;
};

// 成员函数声明
void CMyModel1_DUninit_i1p(CSpxModel* this, int* pOffset);
void CMyModel1_CInit(CMyModel1* pThis);
void CMyModel1_ChangeData(CMyModel1* pThis);
int CMyModel1_GetData(CMyModel1* pThis);

// 虚函数表的声明
extern const VTab_CSpxModel g_tVTab_CMyModel1_CSpxModel;


#endif // !defined(AFX_MYMODEL1_H__91FAF2C4_ACAF_454F_B1BB_D7804EF994CB__INCLUDED_)
