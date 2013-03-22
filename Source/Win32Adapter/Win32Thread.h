// Win32Thread.h: interface for the CWin32Thread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WIN32THREAD_H__EFF23DCD_99DD_4861_A556_AC5D4ED11A71__INCLUDED_)
#define AFX_WIN32THREAD_H__EFF23DCD_99DD_4861_A556_AC5D4ED11A71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IOsThread.h"

class CWin32Thread : public IOsThread
{
public:
	CWin32Thread(IRunable* pRunable);
	virtual ~CWin32Thread();

	virtual void Start();
	virtual void Suspend();
	virtual void Resume();
	virtual void Stop();
	virtual void Join();

private:
	static unsigned __stdcall ThreadFunc(void* pParam);

private:
	HANDLE	m_hThread;
};

#endif // !defined(AFX_WIN32THREAD_H__EFF23DCD_99DD_4861_A556_AC5D4ED11A71__INCLUDED_)
