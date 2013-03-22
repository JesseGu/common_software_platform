// MyController1.cpp: implementation of the CMyController1 class.
//
//////////////////////////////////////////////////////////////////////

#include "MyController1.h"
#include "ISpxObserver.h"
#include "MVCUserDefine.h"
#include "SpxModel.h"
#include "AwsSysDefine.h"
#include "MyModel1.h"

CMyController1::CMyController1()
{
	m_pModel = new CMyModel1();
}

bool CMyController1::OnMessage(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	bool bRet = false;

	if ( !bRet && EMCID_Model1Button == nWndID && AWS_SysCmd_ButtonCmd == nCmdID )
	{
		// 改变模型
		((CMyModel1*)m_pModel)->ChangeData();

		// 更新显示
		m_pModel->DataUpdate();
		bRet = true;
	}

	return bRet;
}

bool CMyController1::OnRegisterObserver(ISpxObserver* pObserver)
{
	bool bRet = false;
	int nID = pObserver->GetObserverID();
	if ( ESP_NULL != m_pModel && (EMSID_Model1Observer1Label == nID || EMSID_Model1Observer2Label == nID) )
	{
		m_pModel->RegisterObserver(pObserver);
		bRet = true;
	}

	return bRet;
}

bool CMyController1::OnUnregisterObserver(ISpxObserver* pObserver)
{
	bool bRet = false;
	int nID = pObserver->GetObserverID();
	if ( (ESP_NULL != m_pModel) && (EMSID_Model1Observer1Label == nID || EMSID_Model1Observer2Label == nID) )
	{
		m_pModel->RemoveObserver(pObserver);
		bRet = true;
	}

	return bRet;
}
