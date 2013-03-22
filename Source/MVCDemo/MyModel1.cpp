// MyModel1.cpp: implementation of the CMyModel1 class.
//
//////////////////////////////////////////////////////////////////////

#include "MyModel1.h"
#include "MVCUserDefine.h"

CMyModel1::CMyModel1() : CSpxModel(2)
{
	m_nData = EMSID_Model1Data1;
}

void CMyModel1::ChangeData()
{
	if ( EMSID_Model1Data1 == m_nData )
		m_nData = EMSID_Model1Data2;
	else if ( EMSID_Model1Data2 == m_nData )
		m_nData = EMSID_Model1Data1;
}
