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

// 注册所有需要用到的主容器

void CMyUi::OnCreate()
{
	CMUi::OnCreate();

	// 注册主窗口
	RegisterMainContainer(MyMainContainerID, new CMyMainContainerBuilder());
	RegisterMainContainer(TabMainContainerID, new CTabMainContainerBuilder());

	// 设置默认主窗口
	ChangeMainContainer(MyMainContainerID);
}
