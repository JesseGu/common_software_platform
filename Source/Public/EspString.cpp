/******************************************************************************
* FileName		       : AwsString.cpp
* Description          : implementation of the CAwsString class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "EspString.h"
#include "EspPubClass.h"
#include "EspSysDefine.h"

CAwsString::CAwsString(int nMaxCharCB)
{
	// 默认的串ID为-1
	m_nStrID = -1;

	m_eCharType = CharType_DBCS;

	m_pCharData = ESP_NULL;
	m_nCharCount = 0;
	m_nCharCB = 0;

	m_nMaxCharCB = nMaxCharCB;
}

CAwsString::~CAwsString()
{
	delete []m_pCharData;
}

void CAwsString::SetCharType(ECharType type)
{
	m_eCharType = type;
}

void CAwsString::SetData(const char* pData, int nCharCB)
{
	m_nCharCount = 0;
	int i;

	if ( ESP_NULL == m_pCharData )
	{
		CreateStr();
	}

	switch ( m_eCharType )
	{
	case CharType_DBCS:
		for ( i = 0; i < nCharCB; ++i )
		{
			m_pCharData[i] = pData[i];
			if ( ((unsigned char)pData[i]) > 0x7f )
			{
				// 双字节
				++i;
				m_pCharData[i] = pData[i];
			}
			++m_nCharCount;
		}
		m_pCharData[i] = 0;
		break;

	case CharType_UNICODE:
		for ( i = 0; i < nCharCB; ++i )
		{
			m_pCharData[i] = pData[i];
			++i;
			m_pCharData[i] = pData[i];
			++m_nCharCount;
		}
		break;
	}

	m_nCharCB = nCharCB;
}

bool CAwsString::RemoveChar(int nIndex)
{
	if ( nIndex >= 0 )
	{
		int nPos = GetBytePosFromCharIndex(nIndex);

		int nStep = 1;
		if ( m_pCharData[nPos] < 0 )
		{
			nStep = 2;
			// 双字节
		}

		// 往前移动
		int i;
		for ( i = nPos; i < m_nCharCB - nStep; ++i )
			m_pCharData[i] = m_pCharData[i + nStep];

		m_pCharData[i] = 0;

		-- m_nCharCount;
		m_nCharCB -= nStep;
		return true;
	}

	return false;
}

bool CAwsString::AddCharToEnd(short nChar)
{
	bool bRet = false;

	int nBytes = 1;

	switch ( m_eCharType )
	{
	case CharType_DBCS:
		if ( ((unsigned char)nChar) > 0x7f )
		{
			// 是双字节
			nBytes = 2;
		}

		if ( m_nCharCB + nBytes <= m_nMaxCharCB )
		{
			// 填充字符
			m_pCharData[m_nCharCB++] = *((char*)(&nChar));
			if ( nBytes > 1 )
			{
				char* p = (char*)(&nChar);
				m_pCharData[m_nCharCB++] = *(++p);
			}

			m_pCharData[m_nCharCB] = 0;
			++m_nCharCount;

			bRet = true;
		}

		break;

	case CharType_UNICODE:
		// 填充字符
		short* p = (short*)(m_pCharData + m_nCharCount * 2);
		*p = nChar;

		m_nCharCB += 2;
		break;
	}

	return bRet;
}

// 在第nIndex个字符处插入(从0开始)
bool CAwsString::AddChar(short nChar, int nIndex)
{
	bool bRet = false;

	if ( ESP_NULL == m_pCharData )
		CreateStr();

	if ( nIndex <= m_nCharCount )
	{
		int i;
		int nPos = 0;
		int nBytes = 1;
		switch ( m_eCharType )
		{
		case CharType_DBCS:
			for ( i = 0; i < nIndex; ++i )
			{
				if ( m_pCharData[nPos] > 0 )
				{
					// 是单字节
					++nPos;
				}
				else
				{
					// 双字节
					nPos += 2;
				}
			}

			if ( ((unsigned char)nChar) > 0x7f )
			{
				// 是双字节
				nBytes = 2;
			}

			if ( m_nCharCB + nBytes <= m_nMaxCharCB )
			{
				// 把后面的往后移动
				for ( i = m_nCharCB - 1; i >= nPos ; --i )
				{
					m_pCharData[i + nBytes] = m_pCharData[i];
				}

				// 填充字符
				if ( nBytes > 1 )
				{
					char* p = (char*)(&nChar);
					m_pCharData[nPos++] = *(++p);
				}
				m_pCharData[nPos++] = *((char*)(&nChar));

				m_nCharCB += nBytes;
				++m_nCharCount;
				m_pCharData[m_nCharCB] = 0;

				bRet = true;
			}

			break;

		case CharType_UNICODE:
			nBytes = 2;

			// 把后面的往后移动
			for ( i = nIndex * 2; i < m_nCharCount * 2; ++i )
			{
				m_pCharData[i + nBytes] = m_pCharData[i];
			}

			// 填充字符
			short* p = (short*)(m_pCharData + nIndex * 2);
			*p = nChar;
			break;
		}
	}

	return bRet;
}

bool CAwsString::AddString(const CAwsString& str, int nIndex)
{
	return true;
}

// 字符左边的位置
int CAwsString::GetBytePosFromCharIndex(int nIndex)
{
	int nRet = -1;

	if ( -1 == nIndex )
		nIndex = m_nCharCount;

	switch ( m_eCharType )
	{
	case CharType_DBCS:
		{
			int i;
			nRet = 0;
			for ( i = 0; i < nIndex; ++i )
			{
				if ( m_pCharData[nRet] > 0 )
				{
					// 是单字节
					++nRet;
				}
				else
				{
					// 双字节
					nRet += 2;
				}
			}
		}
		break;
	}

	return nRet;
}

bool CAwsString::GetSubString(CAwsString& strSub, int nStartIndex, int nEndIndex)
{
	if ( (ESP_NULL != m_pCharData) && (nStartIndex < m_nCharCount) )
	{
		int nStartPos = GetBytePosFromCharIndex(nStartIndex);
		int nEndPos = GetBytePosFromCharIndex(nEndIndex);
		strSub.SetData(m_pCharData + nStartPos, nEndPos - nStartPos);

		return true;
	}

	return false;
}

void CAwsString::Reset()
{
	if ( ESP_NULL != m_pCharData )
	{
		m_nCharCount = 0;
		m_nCharCB = 0;

		m_pCharData[0] = 0;
	}
}

bool CAwsString::CreateStr()
{
	bool bRet = false;

	if ( ESP_NULL == m_pCharData )
	{
		switch ( m_eCharType )
		{
		case CharType_DBCS:
			m_pCharData = new char[m_nMaxCharCB + 1];
			break;

		case CharType_UNICODE:
			m_pCharData = (char*)(new short[m_nMaxCharCB + 1]);
			break;
		}

		if ( ESP_NULL != m_pCharData )
		{
			m_nCharCount = 0;
			bRet = true;

			int i;
			for ( i = 0; i < m_nMaxCharCB + 1; ++i )
				m_pCharData[i] = 0;
		}
	}

	return bRet;
}
