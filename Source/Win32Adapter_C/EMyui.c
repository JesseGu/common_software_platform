
#include "stdafx.h"
#include "EMyui.h"
//#include "MyUi.h"

const VTab_CAwsUi g_tVTab_CEMyUi_CAwsUi = { CEMyUi_DUninit, CAwsUi_ActiveIME, CAwsUi_InactiveIME, CEMyUi_ExitSys, CEMyUi_Timer, CEMyUi_KillTimer };

void CEMyUi_CInit(CEMyUi* pThis)
{
	// �����ʼ��
	CAwsUi_CInit_i0p(&pThis->m_oBaseAwsUi, 3);

	// �滻�麯����
	pThis->m_oBaseAwsUi.m_pVTab = &g_tVTab_CEMyUi_CAwsUi;

	// �����Լ���ʼ��
	pThis->m_hWnd = NULL;
}

void CEMyUi_DUninit(CAwsUi* this, int* pOffset)
{
	// �滻���麯����
	this->m_pVTab = &g_tVTab_CAwsUi_CAwsUi;

	CAwsUi_DUninit_i1p(this, NULL);
}

void CEMyUi_SetScreen(CEMyUi* pThis, HWND hWnd)
{
	pThis->m_hWnd = hWnd;
}

void CEMyUi_Timer(CAwsUi* this, int nTimerID, int nTime)
{
	CEMyUi* pThis = (CEMyUi*)this;

	SetTimer(pThis->m_hWnd, nTimerID, nTime, ESP_NULL);
}

void CEMyUi_KillTimer(CAwsUi* this, int nTimerID)
{
	CEMyUi* pThis = (CEMyUi*)this;
	KillTimer(pThis->m_hWnd, nTimerID);
}

void CEMyUi_ExitSys(CAwsUi* this)
{
	CEMyUi* pThis = (CEMyUi*)this;

	// �˳�ϵͳ
	PostMessage(pThis->m_hWnd, WM_QUIT, 0, 0);
}
