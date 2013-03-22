// MyModel1.cpp: implementation of the CMyModel1 class.
//
//////////////////////////////////////////////////////////////////////

#include "MyModel1.h"
#include "MVCUserDefine.h"

void CMyModel1_CInit(CMyModel1* pThis) {

CSpxModel_CInit_i0p(&(pThis->m_oBase_CSpxModel),2);
	pThis->m_oBase_CSpxModel.m_pVTab = &g_tVTab_CMyModel1_CSpxModel;
{
	pThis->m_nData=EMSID_Model1Data1;
}
}

void CMyModel1_ChangeData(CMyModel1* pThis)
{
	if(EMSID_Model1Data1==pThis->m_nData){
		pThis->m_nData=EMSID_Model1Data2;}
	else if(EMSID_Model1Data2==pThis->m_nData){
		pThis->m_nData=EMSID_Model1Data1;}
}
