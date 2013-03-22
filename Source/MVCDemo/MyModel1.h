// MyModel1.h: interface for the CMyModel1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMODEL1_H__91FAF2C4_ACAF_454F_B1BB_D7804EF994CB__INCLUDED_)
#define AFX_MYMODEL1_H__91FAF2C4_ACAF_454F_B1BB_D7804EF994CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpxModel.h"

class CMyModel1 : public CSpxModel
{
public:
	CMyModel1();

	void ChangeData();
	int GetData() { return m_nData; }

protected:
	int m_nData;
};

#endif // !defined(AFX_MYMODEL1_H__91FAF2C4_ACAF_454F_B1BB_D7804EF994CB__INCLUDED_)
