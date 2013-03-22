// WindowsOs.h: interface for the CWindowsOs class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDOWSOS_H__E518B34E_6054_4119_AC35_C92549712376__INCLUDED_)
#define AFX_WINDOWSOS_H__E518B34E_6054_4119_AC35_C92549712376__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Os.h"

class CWin32Os : public COs
{
public:
	CWin32Os();
	virtual ~CWin32Os();

	virtual IOsFile* GetFile();
	virtual IOsThread* GetThread(IRunable* pRunable);
};

#endif // !defined(AFX_WINDOWSOS_H__E518B34E_6054_4119_AC35_C92549712376__INCLUDED_)
