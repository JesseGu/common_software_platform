/******************************************************************************
* FileName		       : MImageBox.h
* Description          : interface for the CMImageBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _MIMAGEBOX_H_2009_10_09_
#define _MIMAGEBOX_H_2009_10_09_

#include "AwsWindow.h"

class CMImageBox : public CAwsWindow
{
public:
	void ShowImage(const CAwsImage& image, const CAwsImage& imageMask);

public:
	virtual void OnDraw(const CEspRect& rect);

protected:
	CAwsImage	m_oImage;
	CAwsImage	m_oImageMask;
};

#endif /* _MIMAGEBOX_H_2009_10_09_ */
