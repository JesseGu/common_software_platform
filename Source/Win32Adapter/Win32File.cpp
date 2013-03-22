// WindowsFile.cpp: implementation of the CWindowsFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Win32File.h"

CWin32File::CWin32File()
{
	m_pFile = NULL;
}

CWin32File::~CWin32File()
{
	Close();
}

bool CWin32File::Open(const char* pFileName, EFileAccessFlags eOpenFlags)
{
	bool bRet = false;
	if ( NULL == m_pFile )
	{
		switch ( eOpenFlags )
		{
		case EFF_ReadOnly:
			m_pFile = fopen(pFileName, "rb");
			break;

		case EFF_WriteOnly:
			m_pFile = fopen(pFileName, "wb");
			break;

		case EFF_ReadWrite:
			m_pFile = fopen(pFileName, "wb+");
			break;
		}

		if ( NULL != m_pFile )
			bRet = true;
	}

	return bRet;
}

void CWin32File::Close()
{
	if ( NULL != m_pFile )
	{
		fclose(m_pFile);
		m_pFile = NULL;
	}
}

void CWin32File::Seek(long nOffset, EFileSeek eFrom)
{
	if ( NULL != m_pFile )
	{
		switch ( eFrom )
		{
		case EFS_Begin:
			fseek(m_pFile, nOffset, SEEK_SET);
			break;

		case EFS_Current:
			fseek(m_pFile, nOffset, SEEK_CUR);
			break;

		case EFS_End:
			fseek(m_pFile, nOffset, SEEK_END);
			break;
		}
	}
}

unsigned long CWin32File::GetCurPos()
{
	unsigned long nPos = 0;

	if ( NULL != m_pFile )
		nPos = ftell(m_pFile);

	return nPos;
}

unsigned long CWin32File::Read(void* pBuf, unsigned long nCount)
{
	unsigned long nReadedCount = 0;

	if ( NULL != m_pFile )
		nReadedCount = fread(pBuf, nCount, 1, m_pFile);

	return nReadedCount;
}

void CWin32File::Write(const void* pBuf, unsigned long nCount)
{
	if ( NULL != m_pFile )
		fwrite(pBuf, nCount, 1, m_pFile);
}
