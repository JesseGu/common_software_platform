// MyModel2.cpp: implementation of the CMyModel2 class.
//
//////////////////////////////////////////////////////////////////////

#include "MyModel2.h"
#include "MVCUserDefine.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void CMyModel2_CInit(CMyModel2* pThis) {

CSpxModel_CInit_i0p(&(pThis->m_oBase_CSpxModel),2);
	pThis->m_oBase_CSpxModel.m_pVTab = &g_tVTab_CMyModel2_CSpxModel;
{
	pThis->m_nData=EMSID_Model2Data1;
}
}

void CMyModel2_ChangeData(CMyModel2* pThis)
{
	if(EMSID_Model2Data1==pThis->m_nData){
		pThis->m_nData=EMSID_Model2Data2;}
	else if(EMSID_Model2Data2==pThis->m_nData){
		pThis->m_nData=EMSID_Model2Data1;}
}
