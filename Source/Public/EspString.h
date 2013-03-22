/******************************************************************************
* FileName		       : AwsString.h
* Description          : interface for the CAwsString class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _AWSSTRING_H_2009_10_09_
#define _AWSSTRING_H_2009_10_09_

enum ECharType
{
	CharType_DBCS,
	CharType_UNICODE
};

// 可以选择两种字符串描述方式
class CAwsString
{
public:
	CAwsString(int nMaxCharCB = 100);
	~CAwsString();

	void SetCharType(ECharType type);

	void LoadString(int nStrID)
	{
		m_nStrID = nStrID;
	}
	int GetStrID() const
	{
		return m_nStrID;
	}

	void SetData(const char* pData, int nCharCB);
	bool RemoveChar(int nIndex);
	bool AddChar(short nChar, int nIndex);
	bool AddCharToEnd(short nChar);
	bool AddString(const CAwsString& str, int nIndex);
	const char* GetStringData() const { return m_pCharData; }
	bool GetSubString(CAwsString& strSub, int nStartIndex, int nEndIndex);

	int GetCharCount() const { return m_nCharCount; }
	int GetByteCount() const { return m_nCharCB; }

	void Reset();

	void SetMaxCharCB(int nMaxCB) { m_nMaxCharCB = nMaxCB; }

protected:
	bool CreateStr();
	// 由字符索引得到物理字节的位置
	int GetBytePosFromCharIndex(int nIndex = -1);

protected:
	int			m_nStrID;		// 字符串ID
	ECharType	m_eCharType;

	int			m_nMaxCharCB;	// 最大字节长度
	int			m_nCharCount;	// 字符的个数
	int			m_nCharCB;		// 字符占用byte数
	char*		m_pCharData;
};

#endif /* _AWSSTRING_H_2009_10_09_ */
