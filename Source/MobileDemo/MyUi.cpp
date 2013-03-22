/******************************************************************************
* FileName		       : MyUi.cpp
* Description          : implementation of the CMyUi class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "MyUi.h"

#include "MyMainContainer.h"
#include "TabMainContainer.h"

#include "BMenu.h"
#include "AwsUserDefine.h"
#include "MMenuBar.h"
#include "IAwsGc.h"

// ע��������Ҫ�õ���������

void CMyUi::OnCreate()
{
	CMUi::OnCreate();

	// ע��������
	RegisterMainContainer(MyMainContainerID, new CMyMainContainerBuilder());
	RegisterMainContainer(TabMainContainerID, new CTabMainContainerBuilder());

	// ����Ĭ��������
	ChangeMainContainer(MyMainContainerID);
}
