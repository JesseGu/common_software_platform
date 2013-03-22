/******************************************************************************
* FileName		       : AwsPubClass.h
* Description          : interface for the AWS public class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _AWSPUBCLASS_H_2009_10_09
#define _AWSPUBCLASS_H_2009_10_09

class CAwsRgb
{
public:
	CAwsRgb(int nRed = 0, int nGreen = 0, int nBlue = 0)
	{
		m_nValue = ((unsigned int)(((unsigned char)(nRed)|((unsigned short)((unsigned char)(nGreen))<<8))|(((unsigned int)(unsigned char)(nBlue))<<16)));
	}

public:
	unsigned int m_nValue;
};

class CAwsFont
{
public:
	void CreateFont(int nID, int nSize, int nWeight = 400)
	{
		m_nFontID = nID;
		m_nFontSize = nSize;
		m_nFontWeight = nWeight;
	}

	int GetFontID() const 
	{
		return m_nFontID;
	}

	int GetFontSize() const
	{
		return m_nFontSize;
	}

	int GetFontWeight() const
	{
		return m_nFontWeight;
	}

private:
	int		m_nFontID;		// 字体ID
	int		m_nFontSize;	// 字大小
	int		m_nFontWeight;
};

class CAwsImage
{
public:
	CAwsImage()
	{
		// 0是无效的ID
		m_nImageID = 0;
	}

	void LoadImage(int nID)
	{
		m_nImageID = nID;
	}

	int GetID() const
	{
		return m_nImageID;
	}

private:
	int	m_nImageID;
};

#endif /* _AWSPUBCLASS_H_2009_10_09 */
