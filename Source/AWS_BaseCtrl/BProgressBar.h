/******************************************************************************
* FileName		       : BProgressBar.h
* Description          : interface for the CBProgressBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BPROGRESSBAR_H_2009_10_09_
#define _BPROGRESSBAR_H_2009_10_09_

#include "AwsWindow.h"

class CBProgressBar : public CAwsWindow
{
public:
	CBProgressBar();

public:
	void SetTotalLenght(int nLength)
	{
		m_nLength = nLength;
	}
	void SetPos(int nPos);
	int GetPos()
	{
		return m_nCurPos;
	}

	void SetBKColor(const CAwsRgb& color) { m_oBKColor = color; }
	void SetProgressColor(const CAwsRgb& color) { m_oProgressColor = color; }
	void SetBorderColor(const CAwsRgb& color) { m_oBorderColor = color; }

public:
	virtual void OnDraw(const CEspRect& rect);

protected:
	virtual void OnCreate();

protected:
	virtual void OnDrawBK(IAwsGc* pGc, const CEspRect& rect);
	virtual void OnDrawBorder(IAwsGc* pGc, const CEspRect& rect);
	virtual void OnDrawProgress(IAwsGc* pGc, const CEspRect& rect);

protected:
	int	m_nLength;
	int	m_nCurPos;
	int	m_nDrawPos;

	CAwsRgb	m_oBKColor;
	CAwsRgb m_oProgressColor;
	CAwsRgb	m_oBorderColor;

	int	m_nBorderPixels;
};

#endif /* _BPROGRESSBAR_H_2009_10_09_ */
