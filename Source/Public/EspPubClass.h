/******************************************************************************
* FileName		       : EspPubClass.h
* Description          : interface for the ESP public class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-12

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _ESPPUBCLASS_H__2011_03_12_
#define _ESPPUBCLASS_H__2011_03_12_

#include "EspString.h"

class CEspPoint
{
public:
	CEspPoint(int x = 0, int y = 0);

	void operator+=(const CEspPoint& pt);
	void operator-=(const CEspPoint& pt);
	bool operator!=(const CEspPoint& pt)const;

public:
	int m_nX;
	int m_nY;
};

class CEspSize
{
public:
	CEspSize(int nWidth = 0, int nHeight = 0);
	bool operator==(const CEspSize& size) const;

public:
	int m_nWidth;
	int	m_nHeight;
};

class CEspRect
{
public:
	CEspRect();
	CEspRect(int nLTx, int nLTy, int nRBx, int nRBy);
	CEspRect(const CEspPoint& ptLT, const CEspPoint& ptRB);

	void operator+=(const CEspRect& pt);
	bool operator!=(const CEspRect& pt) const;

	const CEspSize* GetSize()const ;

	// 求两个矩形的交集矩形
	bool InterRect(const CEspRect& rect, CEspRect& DesRect)const;

public:
	CEspPoint	m_ptLT;
	CEspPoint	m_ptRB;

	CEspSize	m_oSize;
};

#endif /* _ESPPUBCLASS_H__2011_03_12_ */
