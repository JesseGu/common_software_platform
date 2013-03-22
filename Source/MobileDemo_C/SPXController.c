/******************************************************************************
* FileName		       : SpxController.cpp
* Description          : implementation of the CSpxController class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "SpxModel.h"
#include "ISpxObserver.h"
#include "SpxController.h"

void CSpxController_CInit(CSpxController* pThis)
{

	pThis->m_pVTab = &g_tVTab_CSpxController_CSpxController;
{
	pThis->m_pModel=ESP_NULL;
}
}

void CSpxController_DUninit_i1p(CSpxController* pThis, int * pOffset)
{
	{int nOffset = 0;(pThis->m_pModel)->m_pVTab->m_pDUninit_i1p(pThis->m_pModel, &nOffset);free((void*)((int)(pThis->m_pModel) - nOffset));};
}

int CSpxController_OnCommand_i0p_i0p_i0p_i0p(CSpxController* pThis, int nWndID,int nCmdID,int nParam1,int nParam2)
{
	int bRet=0;

	switch(nCmdID)
	{
	case SPX_SysCmd_RegisterObserver:
		bRet=pThis->m_pVTab->m_pOnRegisterObserver_ISpxObserver1p(pThis,(ISpxObserver*)nParam1);
		break;

	case SPX_SysCmd_UnregisterObserver:
		bRet=pThis->m_pVTab->m_pOnUnregisterObserver_ISpxObserver1p(pThis,(ISpxObserver*)nParam1);
		break;

	default:
		bRet=pThis->m_pVTab->m_pOnMessage_i0p_i0p_i0p_i0p(pThis,nWndID,nCmdID,nParam1,nParam2);
	}

	return bRet;
}
