// WindowsFile.h: interface for the CWindowsFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDOWSFILE_H__D18DE1CC_178B_4B82_8A55_D550D984A4E9__INCLUDED_)
#define AFX_WINDOWSFILE_H__D18DE1CC_178B_4B82_8A55_D550D984A4E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IOsFile.h"

class CWin32File : public IOsFile
{
public:
	CWin32File();
	virtual ~CWin32File();

	virtual bool Open(const char* pFileName, EFileAccessFlags eOpenFlags);
	virtual void Close();
	virtual void Seek(long nOffset, EFileSeek eFrom);
	virtual unsigned long GetCurPos();

	virtual unsigned long Read(void* pBuf, unsigned long nCount);
	virtual void Write(const void* pBuf, unsigned long nCount);

private:
	FILE*	m_pFile;
};

#endif // !defined(AFX_WINDOWSFILE_H__D18DE1CC_178B_4B82_8A55_D550D984A4E9__INCLUDED_)
