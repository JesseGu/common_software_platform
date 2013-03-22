/******************************************************************************
* FileName		       : MyApp.h
* Description          : interface for the CMyApp class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_MYAPP_H__AAC7E7E3_8A3A_4D7C_AAFB_8CB463B193F7__INCLUDED_)
#define AFX_MYAPP_H__AAC7E7E3_8A3A_4D7C_AAFB_8CB463B193F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpxApp.h"

class CMyApp : public CSpxApp
{
public:
	CMyApp();

protected:
	virtual void OnInit(const CEspSize& sizeScreen);
};

#endif // !defined(AFX_MYAPP_H__AAC7E7E3_8A3A_4D7C_AAFB_8CB463B193F7__INCLUDED_)
