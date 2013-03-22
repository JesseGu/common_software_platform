// Win32Thread.cpp: implementation of the CWin32Thread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Win32Thread.h"

CWin32Thread::CWin32Thread(IRunable* pRunable)
{
	m_pRunable = pRunable;
	m_hThread = NULL;
}

CWin32Thread::~CWin32Thread()
{
}

void CWin32Thread::Start()
{
	m_hThread = (HANDLE)_beginthreadex(NULL, 0, &ThreadFunc, (void*)this,NULL,&m_nThreadId);
}

void CWin32Thread::Suspend()
{
	if ( NULL != m_hThread )
		::SuspendThread(m_hThread);
}

void CWin32Thread::Resume()
{
	if ( NULL != m_hThread )
		::ResumeThread(m_hThread);
}

void CWin32Thread::Stop()
{
	if ( NULL != m_hThread )
		::TerminateThread(m_hThread, 0);
}

void CWin32Thread::Join()
{
	if ( NULL != m_hThread )
		::WaitForSingleObject(m_hThread, INFINITE);
}

unsigned __stdcall CWin32Thread::ThreadFunc(void* pParam)
{
	CWin32Thread* pThis = (CWin32Thread*)pParam;

	if ( NULL != pThis->m_pRunable )
		pThis->m_pRunable->Run();

	HANDLE handle = pThis->m_hThread;
	pThis->m_hThread = NULL;
	::CloseHandle(handle);

	return 0;
}
