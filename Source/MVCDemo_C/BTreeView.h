/******************************************************************************
* FileName		       : BTreeView.h
* Description          : interface for the CBTreeView class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BTREEVIEW_H_2009_10_09_
#define _BTREEVIEW_H_2009_10_09_

#include "AwsContainer.h"

typedef struct tagCBTreeView CBTreeView;

// 类声明
struct tagCBTreeView
{
	CAwsContainer m_oBase_CAwsContainer;

};

// 成员函数声明
void CBTreeView_DUninit_i1p(CAwsWindow* this, int * pOffset);
void CBTreeView_CInit(CBTreeView* pThis);

// 虚函数表的声明
extern const VTab_CAwsWindow g_tVTab_CBTreeView_CAwsWindow;


#endif /* _BTREEVIEW_H_2009_10_09_ */
