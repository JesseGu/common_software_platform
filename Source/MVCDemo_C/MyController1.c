// MyController1.cpp: implementation of the CMyController1 class.
//
//////////////////////////////////////////////////////////////////////

#include "MyController1.h"
#include "ISpxObserver.h"
#include "MVCUserDefine.h"
#include "SpxModel.h"
#include "AwsSysDefine.h"
#include "MyModel1.h"

const VTab_CSpxController g_tVTab_CMyController1_CSpxController = {CMyController1_DUninit_i1p, CMyController1_OnRegisterObserver_ISpxObserver1p, CMyController1_OnUnregisterObserver_ISpxObserver1p, CMyController1_OnMessage_i0p_i0p_i0p_i0p};
void CMyController1_DUninit_i1p(CSpxController* this, int* pOffset)
{
	CMyController1* pThis=(CMyController1*)this;
	pThis->m_oBase_CSpxController.m_pVTab = &g_tVTab_CSpxController_CSpxController;
	CSpxController_DUninit_i1p(&(pThis->m_oBase_CSpxController), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMyController1*)0)->m_oBase_CSpxController));
}

void CMyController1_CInit(CMyController1* pThis)
{

CSpxController_CInit(&(pThis->m_oBase_CSpxController));
	pThis->m_oBase_CSpxController.m_pVTab = &g_tVTab_CMyController1_CSpxController;
{
	{CMyModel1*pHeapObj_1=(CMyModel1(*))malloc(sizeof(CMyModel1));
CMyModel1_CInit(pHeapObj_1);
{pThis->m_oBase_CSpxController.m_pModel=&(pHeapObj_1->m_oBase_CSpxModel);
}}}
}

int CMyController1_OnMessage_i0p_i0p_i0p_i0p(CSpxController* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CMyController1* pThis = (CMyController1*)this;{
	int bRet=0;

	if(!bRet&&EMCID_Model1Button==nWndID&&AWS_SysCmd_ButtonCmd==nCmdID){
	{
		// 改变模型
		CMyModel1_ChangeData(((CMyModel1*)((char*)pThis->m_oBase_CSpxController.m_pModel-(int)(&(((CMyModel1*)0)->m_oBase_CSpxModel)))));

		// 更新显示
		CSpxModel_DataUpdate(pThis->m_oBase_CSpxController.m_pModel);
		bRet=1;
	}}

	return bRet;
}
}

int CMyController1_OnRegisterObserver_ISpxObserver1p(CSpxController* this, ISpxObserver *  pObserver)
{

	CMyController1* pThis = (CMyController1*)this;{
	int bRet=0;
	int nID=pObserver->m_pVTab->m_pGetObserverID(pObserver);
	if(ESP_NULL!=pThis->m_oBase_CSpxController.m_pModel&&(EMSID_Model1Observer1Label==nID||EMSID_Model1Observer2Label==nID)){
	{
		CSpxModel_RegisterObserver_ISpxObserver1p(pThis->m_oBase_CSpxController.m_pModel,pObserver);
		bRet=1;
	}}

	return bRet;
}
}

int CMyController1_OnUnregisterObserver_ISpxObserver1p(CSpxController* this, ISpxObserver *  pObserver)
{

	CMyController1* pThis = (CMyController1*)this;{
	int bRet=0;
	int nID=pObserver->m_pVTab->m_pGetObserverID(pObserver);
	if((ESP_NULL!=pThis->m_oBase_CSpxController.m_pModel)&&(EMSID_Model1Observer1Label==nID||EMSID_Model1Observer2Label==nID)){
	{
		CSpxModel_RemoveObserver_ISpxObserver1p(pThis->m_oBase_CSpxController.m_pModel,pObserver);
		bRet=1;
	}}

	return bRet;
}
}
