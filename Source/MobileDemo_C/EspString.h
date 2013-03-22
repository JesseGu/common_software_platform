/******************************************************************************
* FileName		       : AwsString.h
* Description          : interface for the CAwsString class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _AWSSTRING_H_2009_10_09_
#define _AWSSTRING_H_2009_10_09_

typedef enum tagECharType ECharType;
enum tagECharType
{
	CharType_DBCS,
	CharType_UNICODE
};


// 可以选择两种字符串描述方式
typedef struct tagCAwsString CAwsString;

// 类声明
struct tagCAwsString
{
	int m_nStrID;
	ECharType m_eCharType;
	int m_nMaxCharCB;
	int m_nCharCount;
	int m_nCharCB;
	char *  m_pCharData;
};

// 成员函数声明
void CAwsString_CInit_i0p(CAwsString* pThis, int nMaxCharCB);
void CAwsString_DUninit_i1p(CAwsString* pThis, int * pOffset);
void CAwsString_SetCharType_0p(CAwsString* pThis, ECharType type);
void CAwsString_LoadString_i0p(CAwsString* pThis, int nStrID);
int CAwsString_GetStrID(const CAwsString* pThis);
void CAwsString_SetData_c1p_i0p(CAwsString* pThis, const char *  pData, int nCharCB);
int CAwsString_RemoveChar_i0p(CAwsString* pThis, int nIndex);
int CAwsString_AddChar_s0p_i0p(CAwsString* pThis, short nChar, int nIndex);
int CAwsString_AddCharToEnd_s0p(CAwsString* pThis, short nChar);
int CAwsString_AddString_CAwsString1p_i0p(CAwsString* pThis, const CAwsString * str, int nIndex);
const char *  CAwsString_GetStringData(const CAwsString* pThis);
int CAwsString_GetSubString_CAwsString1p_i0p_i0p(CAwsString* pThis, CAwsString * strSub, int nStartIndex, int nEndIndex);
int CAwsString_GetCharCount(const CAwsString* pThis);
int CAwsString_GetByteCount(const CAwsString* pThis);
void CAwsString_Reset(CAwsString* pThis);
void CAwsString_SetMaxCharCB_i0p(CAwsString* pThis, int nMaxCB);
int CAwsString_CreateStr(CAwsString* pThis);
int CAwsString_GetBytePosFromCharIndex_i0p(CAwsString* pThis, int nIndex);


#endif /* _AWSSTRING_H_2009_10_09_ */
