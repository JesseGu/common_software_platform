/******************************************************************************
* FileName		       : AwsPubClass.h
* Description          : interface for the AWS public class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _AWSPUBCLASS_H_2009_10_09
#define _AWSPUBCLASS_H_2009_10_09

typedef struct tagCAwsRgb CAwsRgb;

// 类声明
struct tagCAwsRgb
{
	unsigned int m_nValue;
};

// 成员函数声明
void CAwsRgb_CInit_i0p_i0p_i0p(CAwsRgb* pThis, int nRed, int nGreen, int nBlue);


typedef struct tagCAwsFont CAwsFont;

// 类声明
struct tagCAwsFont
{
	int m_nFontID;
	int m_nFontSize;
	int m_nFontWeight;
};

// 成员函数声明
void CAwsFont_CreateFont_i0p_i0p_i0p(CAwsFont* pThis, int nID, int nSize, int nWeight);
int CAwsFont_GetFontID(const CAwsFont* pThis);
int CAwsFont_GetFontSize(const CAwsFont* pThis);
int CAwsFont_GetFontWeight(const CAwsFont* pThis);


typedef struct tagCAwsImage CAwsImage;

// 类声明
struct tagCAwsImage
{
	int m_nImageID;
};

// 成员函数声明
void CAwsImage_CInit(CAwsImage* pThis);
void CAwsImage_LoadImage_i0p(CAwsImage* pThis, int nID);
int CAwsImage_GetID(const CAwsImage* pThis);


#endif /* _AWSPUBCLASS_H_2009_10_09 */
