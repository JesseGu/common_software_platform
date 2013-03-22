
#include "stdafx.h"
#include "Win32Os.h"

void CWin32Os_CInit(CWin32Os* pThis)
{
	COs_CInit(&pThis->m_oBase_Os);
}

void CWin32Os_DUninit(CWin32Os* pThis)
{
}
