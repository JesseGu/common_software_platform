/******************************************************************************
* FileName		       : MyUi.h
* Description          : interface for the CMyUi class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_MYUI_H__F72381B5_B81F_4211_9186_01DD52041B30__INCLUDED_)
#define AFX_MYUI_H__F72381B5_B81F_4211_9186_01DD52041B30__INCLUDED_

#include "MUi.h"

typedef struct tagCMyUi CMyUi;

// 类声明
struct tagCMyUi
{
	CMUi m_oBase_CMUi;

};

// 成员函数声明
void CMyUi_OnCreate(CAwsWindow* this);
void CMyUi_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CMyUi_CInit(CMyUi* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CMyUi_CAwsWindow;


#endif // !defined(AFX_MYUI_H__F72381B5_B81F_4211_9186_01DD52041B30__INCLUDED_)
