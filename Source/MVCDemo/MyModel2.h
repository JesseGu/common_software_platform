// MyModel2.h: interface for the CMyModel2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMODEL2_H__6BB967E9_66E5_4AE0_A7DC_EAF080D58DEB__INCLUDED_)
#define AFX_MYMODEL2_H__6BB967E9_66E5_4AE0_A7DC_EAF080D58DEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpxModel.h"

class CMyModel2 : public CSpxModel
{
public:
	CMyModel2();

	void ChangeData();
	int GetData() { return m_nData; }

protected:
	int	m_nData;
};

#endif // !defined(AFX_MYMODEL2_H__6BB967E9_66E5_4AE0_A7DC_EAF080D58DEB__INCLUDED_)
