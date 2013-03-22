// MyModel2.cpp: implementation of the CMyModel2 class.
//
//////////////////////////////////////////////////////////////////////

#include "MyModel2.h"
#include "MVCUserDefine.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyModel2::CMyModel2() : CSpxModel(2)
{
	m_nData = EMSID_Model2Data1;
}

void CMyModel2::ChangeData()
{
	if ( EMSID_Model2Data1 == m_nData )
		m_nData = EMSID_Model2Data2;
	else if ( EMSID_Model2Data2 == m_nData )
		m_nData = EMSID_Model2Data1;
}
