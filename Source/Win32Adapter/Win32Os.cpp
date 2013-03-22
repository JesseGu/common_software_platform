// WindowsOs.cpp: implementation of the CWindowsOs class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EspSysDefine.h"
#include "Win32Os.h"

#include "Win32File.h"
#include "Win32Thread.h"

CWin32Os::CWin32Os()
{
}

CWin32Os::~CWin32Os()
{
}

IOsFile* CWin32Os::GetFile()
{
	return new CWin32File();
}

IOsThread* CWin32Os::GetThread(IRunable* pRunable)
{
	return new CWin32Thread(pRunable);
}
