
#ifndef __EMYUI_2011_03_05_H__
#define __EMYUI_2011_03_05_H__

#include "AwsUi.h"

typedef struct tagCEMyUi CEMyUi;

struct tagCEMyUi
{
	CAwsUi	m_oBaseAwsUi;

	HWND	m_hWnd;
};

void CEMyUi_CInit(CEMyUi* pThis);
void CEMyUi_SetScreen(CEMyUi* pThis, HWND hWnd);

void CEMyUi_DUninit(CAwsUi* this, int* pOffset);
void CEMyUi_Timer(CAwsUi* this, int nTimerID, int nTime);
void CEMyUi_KillTimer(CAwsUi* this, int nTimerID);
void CEMyUi_ExitSys(CAwsUi* this);

extern const VTab_CAwsUi g_tVTab_CEMyUi_CAwsUi;

#endif /*__EMYUI_2011_03_05_H__*/
