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

// ������
struct tagCAwsRgb
{
	unsigned int m_nValue;
};

// ��Ա��������
void CAwsRgb_CInit_i0p_i0p_i0p(CAwsRgb* pThis, int nRed, int nGreen, int nBlue);


typedef struct tagCAwsFont CAwsFont;

// ������
struct tagCAwsFont
{
	int m_nFontID;
	int m_nFontSize;
	int m_nFontWeight;
};

// ��Ա��������
void CAwsFont_CreateFont_i0p_i0p_i0p(CAwsFont* pThis, int nID, int nSize, int nWeight);
int CAwsFont_GetFontID(const CAwsFont* pThis);
int CAwsFont_GetFontSize(const CAwsFont* pThis);
int CAwsFont_GetFontWeight(const CAwsFont* pThis);


typedef struct tagCAwsImage CAwsImage;

// ������
struct tagCAwsImage
{
	int m_nImageID;
};

// ��Ա��������
void CAwsImage_CInit(CAwsImage* pThis);
void CAwsImage_LoadImage_i0p(CAwsImage* pThis, int nID);
int CAwsImage_GetID(const CAwsImage* pThis);


#endif /* _AWSPUBCLASS_H_2009_10_09 */
