/******************************************************************************
* FileName		       : EspPubClass.cpp
* Description          : implementation of the ESP public class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-12

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "EspPubClass.h"

CEspPoint::CEspPoint(int x, int y)
{
	m_nX = x;
	m_nY = y;
}

void CEspPoint::operator-=(const CEspPoint& pt)
{
	m_nX -= pt.m_nX;
	m_nY -= pt.m_nY;
}

void CEspPoint::operator+=(const CEspPoint& pt)
{
	m_nX += pt.m_nX;
	m_nY += pt.m_nY;
}

bool CEspPoint::operator!=(const CEspPoint& pt)const
{
	if ( m_nX != pt.m_nX || m_nY != pt.m_nY )
		return true;
	else
		return false;
}

CEspSize::CEspSize(int nWidth, int nHeight)
{
	m_nWidth = nWidth;
	m_nHeight = nHeight;
}
bool CEspSize::operator==(const CEspSize& size) const
{
	if ( m_nHeight == size.m_nHeight || m_nWidth == size.m_nWidth )
	{
		return true;
	}

	return false;
}


CEspRect::CEspRect()
{
	m_ptLT.m_nX = 0;
	m_ptLT.m_nY = 0;

	m_ptRB.m_nX = 0;
	m_ptRB.m_nY = 0;
}

void CEspRect::operator+=(const CEspRect& rt)
{
	m_ptLT += rt.m_ptLT;
	m_ptRB += rt.m_ptRB;
}

bool CEspRect::operator!=(const CEspRect& pt) const
{
	if ( m_ptLT != pt.m_ptLT || m_ptRB != pt.m_ptRB )
		return true;
	else
		return false;
}

CEspRect::CEspRect(int nLTx, int nLTy, int nRBx, int nRBy)
{
	m_ptLT.m_nX = nLTx;
	m_ptLT.m_nY = nLTy;

	m_ptRB.m_nX = nRBx;
	m_ptRB.m_nY = nRBy;
}

CEspRect::CEspRect(const CEspPoint& ptLT, const CEspPoint& ptRB)
{
	m_ptLT = ptLT;
	m_ptRB = ptRB;

}

const CEspSize* CEspRect::GetSize() const 
{
	CEspRect* pTHIS = (CEspRect*)this;
	pTHIS->m_oSize.m_nWidth = m_ptRB.m_nX - m_ptLT.m_nX;
	pTHIS->m_oSize.m_nHeight = m_ptRB.m_nY - m_ptLT.m_nY;

	return &pTHIS->m_oSize;
}

// 获取两个矩形相交矩形
bool CEspRect::InterRect(const CEspRect& rect, CEspRect& DesRect) const
{
	bool bRet = true;

	// 判断x
	if ( rect.m_ptLT.m_nX < m_ptLT.m_nX )
	{
		DesRect.m_ptLT.m_nX = m_ptLT.m_nX;
		if ( rect.m_ptRB.m_nX >= m_ptLT.m_nX && rect.m_ptRB.m_nX <= m_ptRB.m_nX )
		{
			DesRect.m_ptRB.m_nX = rect.m_ptRB.m_nX;
		}
		else if ( rect.m_ptRB.m_nX > m_ptRB.m_nX )
		{
			DesRect.m_ptRB.m_nX = m_ptRB.m_nX;
		}
		else
		{
			bRet = false;
		}
	}
	else if ( rect.m_ptLT.m_nX >= m_ptLT.m_nX && rect.m_ptLT.m_nX <= m_ptRB.m_nX )
	{
		DesRect.m_ptLT.m_nX = rect.m_ptLT.m_nX;

		if ( rect.m_ptRB.m_nX <= m_ptRB.m_nX )
		{
			DesRect.m_ptRB.m_nX = rect.m_ptRB.m_nX;
		}
		else
		{
			DesRect.m_ptRB.m_nX = m_ptRB.m_nX;
		}
	}
	else
	{
		bRet = false;
	}

	// 判断y
	if ( bRet )
	{
		if ( rect.m_ptLT.m_nY < m_ptLT.m_nY )
		{
			DesRect.m_ptLT.m_nY = m_ptLT.m_nY;
			if ( rect.m_ptRB.m_nY >= m_ptLT.m_nY && rect.m_ptRB.m_nY <= m_ptRB.m_nY )
			{
				DesRect.m_ptRB.m_nY = rect.m_ptRB.m_nY;
			}
			else if ( rect.m_ptRB.m_nY > m_ptRB.m_nY )
			{
				DesRect.m_ptRB.m_nY = m_ptRB.m_nY;
			}
			else
			{
				bRet = false;
			}
		}
		else if ( rect.m_ptLT.m_nY >= m_ptLT.m_nY && rect.m_ptLT.m_nY <= m_ptRB.m_nY )
		{
			DesRect.m_ptLT.m_nY = rect.m_ptLT.m_nY;

			if ( rect.m_ptRB.m_nY <= m_ptRB.m_nY )
			{
				DesRect.m_ptRB.m_nY = rect.m_ptRB.m_nY;
			}
			else
			{
				DesRect.m_ptRB.m_nY = m_ptRB.m_nY;
			}
		}
		else
		{
			bRet = false;
		}
	}

	if ( bRet && (DesRect.m_ptLT.m_nX == DesRect.m_ptRB.m_nX || DesRect.m_ptLT.m_nY == DesRect.m_ptRB.m_nY ) )
		bRet = false;

	return bRet;
}
