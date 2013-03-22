// MyModel2.h: interface for the CMyModel2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMODEL2_H__6BB967E9_66E5_4AE0_A7DC_EAF080D58DEB__INCLUDED_)
#define AFX_MYMODEL2_H__6BB967E9_66E5_4AE0_A7DC_EAF080D58DEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpxModel.h"

typedef struct tagCMyModel2 CMyModel2;

// 类声明
struct tagCMyModel2
{
	CSpxModel m_oBase_CSpxModel;

	int m_nData;
};

// 成员函数声明
void CMyModel2_DUninit_i1p(CSpxModel* this, int* pOffset);
void CMyModel2_CInit(CMyModel2* pThis);
void CMyModel2_ChangeData(CMyModel2* pThis);
int CMyModel2_GetData(CMyModel2* pThis);

// 虚函数表的声明
extern const VTab_CSpxModel g_tVTab_CMyModel2_CSpxModel;


#endif // !defined(AFX_MYMODEL2_H__6BB967E9_66E5_4AE0_A7DC_EAF080D58DEB__INCLUDED_)
