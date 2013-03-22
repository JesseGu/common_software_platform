
#ifndef _WIN32OS_H_2011_03_13_
#define _WIN32OS_H_2011_03_13_

#include "Os.h"

typedef struct tagWin32Os CWin32Os;

struct tagWin32Os
{
	COs	m_oBase_Os;
};

void CWin32Os_CInit(CWin32Os* pThis);
void CWin32Os_DUninit(CWin32Os* pThis);

#endif /*_WIN32OS_H_2011_03_13_*/