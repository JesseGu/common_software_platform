// MyController2.cpp: implementation of the CMyController2 class.
//
//////////////////////////////////////////////////////////////////////

#include "MyController2.h"
#include "MyModel2.h"
#include "AwsSysDefine.h"
#include "MVCUserDefine.h"
#include "ISpxObserver.h"

CMyController2::CMyController2()
{
	m_pModel = new CMyModel2();
}

bool CMyController2::OnMessage(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	bool bRet = false;

	if ( !bRet && EMCID_Model2Button == nWndID && AWS_SysCmd_ButtonCmd == nCmdID )
	{
		// 改变模型
		((CMyModel2*)m_pModel)->ChangeData();

		// 更新显示
		m_pModel->DataUpdate();
		bRet = true;
	}

	return bRet;
}

bool CMyController2::OnRegisterObserver(ISpxObserver* pObserver)
{
	bool bRet = false;
	int nID = pObserver->GetObserverID();
	if ( ESP_NULL != m_pModel && (EMSID_Model2Observer1Label == nID || EMSID_Model2Observer2Label == nID) )
	{
		m_pModel->RegisterObserver(pObserver);
		bRet = true;
	}

	return bRet;
}

bool CMyController2::OnUnregisterObserver(ISpxObserver* pObserver)
{
	bool bRet = false;
	int nID = pObserver->GetObserverID();
	if ( (ESP_NULL != m_pModel) && (EMSID_Model2Observer1Label == nID || EMSID_Model2Observer2Label == nID) )
	{
		m_pModel->RemoveObserver(pObserver);
		bRet = true;
	}

	return bRet;
}
