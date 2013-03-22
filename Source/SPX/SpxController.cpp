/******************************************************************************
* FileName		       : SpxController.cpp
* Description          : implementation of the CSpxController class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "SpxModel.h"
#include "ISpxObserver.h"
#include "SpxController.h"

CSpxController::CSpxController()
{
	m_pModel = ESP_NULL;
}

CSpxController::~CSpxController()
{
	delete m_pModel;
}

bool CSpxController::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	bool bRet = false;

	switch ( nCmdID )
	{
	case SPX_SysCmd_RegisterObserver:
		bRet = OnRegisterObserver((ISpxObserver*)nParam1);
		break;

	case SPX_SysCmd_UnregisterObserver:
		bRet = OnUnregisterObserver((ISpxObserver*)nParam1);
		break;

	default:
		bRet = OnMessage(nWndID, nCmdID, nParam1, nParam2);
	}

	return bRet;
}
