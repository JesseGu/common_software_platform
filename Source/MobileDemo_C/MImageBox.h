/******************************************************************************
* FileName		       : MImageBox.h
* Description          : interface for the CMImageBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _MIMAGEBOX_H_2009_10_09_
#define _MIMAGEBOX_H_2009_10_09_

#include "AwsWindow.h"

typedef struct tagCMImageBox CMImageBox;

// 类声明
struct tagCMImageBox
{
	CAwsWindow m_oBase_CAwsWindow;

	CAwsImage m_oImage;
	CAwsImage m_oImageMask;
};

// 成员函数声明
void CMImageBox_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect);
void CMImageBox_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CMImageBox_ShowImage_CAwsImage1p_CAwsImage1p(CMImageBox* pThis, const CAwsImage * image, const CAwsImage * imageMask);
void CMImageBox_CInit(CMImageBox* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CMImageBox_CAwsWindow;


#endif /* _MIMAGEBOX_H_2009_10_09_ */
