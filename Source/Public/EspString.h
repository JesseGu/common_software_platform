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

// ����ѡ�������ַ���������ʽ
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
	// ���ַ������õ������ֽڵ�λ��
	int GetBytePosFromCharIndex(int nIndex = -1);

protected:
	int			m_nStrID;		// �ַ���ID
	ECharType	m_eCharType;

	int			m_nMaxCharCB;	// ����ֽڳ���
	int			m_nCharCount;	// �ַ��ĸ���
	int			m_nCharCB;		// �ַ�ռ��byte��
	char*		m_pCharData;
};

#endif /* _AWSSTRING_H_2009_10_09_ */
