// EMyui.cpp: implementation of the CEMyui class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EMyui.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CEMyUi::CEMyUi()
{
	m_pScreen = ESP_NULL;
}

void CEMyUi::Timer(int nTimerID, int nTime)
{
	m_pScreen->SetTimer(nTimerID, nTime, NULL);
}

void CEMyUi::KillTimer(int nTimerID)
{
	m_pScreen->KillTimer(nTimerID);
}

void CEMyUi::ExitSys()
{
	::PostMessage(m_pScreen->GetSafeHwnd(), WM_QUIT, 0, 0);
}
