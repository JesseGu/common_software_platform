// MyController2.cpp: implementation of the CMyController2 class.
//
//////////////////////////////////////////////////////////////////////

#include "MyController2.h"
#include "MyModel2.h"
#include "AwsSysDefine.h"
#include "MVCUserDefine.h"
#include "ISpxObserver.h"

const VTab_CSpxController g_tVTab_CMyController2_CSpxController = {CMyController2_DUninit_i1p, CMyController2_OnRegisterObserver_ISpxObserver1p, CMyController2_OnUnregisterObserver_ISpxObserver1p, CMyController2_OnMessage_i0p_i0p_i0p_i0p};
void CMyController2_DUninit_i1p(CSpxController* this, int* pOffset)
{
	CMyController2* pThis=(CMyController2*)this;
	pThis->m_oBase_CSpxController.m_pVTab = &g_tVTab_CSpxController_CSpxController;
	CSpxController_DUninit_i1p(&(pThis->m_oBase_CSpxController), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMyController2*)0)->m_oBase_CSpxController));
}

void CMyController2_CInit(CMyController2* pThis)
{

CSpxController_CInit(&(pThis->m_oBase_CSpxController));
	pThis->m_oBase_CSpxController.m_pVTab = &g_tVTab_CMyController2_CSpxController;
{
	{CMyModel2*pHeapObj_1=(CMyModel2(*))malloc(sizeof(CMyModel2));
CMyModel2_CInit(pHeapObj_1);
{pThis->m_oBase_CSpxController.m_pModel=&(pHeapObj_1->m_oBase_CSpxModel);
}}}
}

int CMyController2_OnMessage_i0p_i0p_i0p_i0p(CSpxController* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CMyController2* pThis = (CMyController2*)this;{
	int bRet=0;

	if(!bRet&&EMCID_Model2Button==nWndID&&AWS_SysCmd_ButtonCmd==nCmdID){
	{
		// 改变模型
		CMyModel2_ChangeData(((CMyModel2*)((char*)pThis->m_oBase_CSpxController.m_pModel-(int)(&(((CMyModel2*)0)->m_oBase_CSpxModel)))));

		// 更新显示
		CSpxModel_DataUpdate(pThis->m_oBase_CSpxController.m_pModel);
		bRet=1;
	}}

	return bRet;
}
}

int CMyController2_OnRegisterObserver_ISpxObserver1p(CSpxController* this, ISpxObserver *  pObserver)
{

	CMyController2* pThis = (CMyController2*)this;{
	int bRet=0;
	int nID=pObserver->m_pVTab->m_pGetObserverID(pObserver);
	if(ESP_NULL!=pThis->m_oBase_CSpxController.m_pModel&&(EMSID_Model2Observer1Label==nID||EMSID_Model2Observer2Label==nID)){
	{
		CSpxModel_RegisterObserver_ISpxObserver1p(pThis->m_oBase_CSpxController.m_pModel,pObserver);
		bRet=1;
	}}

	return bRet;
}
}

int CMyController2_OnUnregisterObserver_ISpxObserver1p(CSpxController* this, ISpxObserver *  pObserver)
{

	CMyController2* pThis = (CMyController2*)this;{
	int bRet=0;
	int nID=pObserver->m_pVTab->m_pGetObserverID(pObserver);
	if((ESP_NULL!=pThis->m_oBase_CSpxController.m_pModel)&&(EMSID_Model2Observer1Label==nID||EMSID_Model2Observer2Label==nID)){
	{
		CSpxModel_RemoveObserver_ISpxObserver1p(pThis->m_oBase_CSpxController.m_pModel,pObserver);
		bRet=1;
	}}

	return bRet;
}
}
