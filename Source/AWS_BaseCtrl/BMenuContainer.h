/******************************************************************************
* FileName		       : BMenuContainer.h
* Description          : interface for the CBMenuContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BMENUCONTAINER_H_2011_03_09_
#define _BMENUCONTAINER_H_2011_03_09_

#include "AwsContainer.h"

// 带菜单的容器
class CBMenuContainer : public CAwsContainer
{
public:
	CBMenuContainer(int nMaxSubWndCount);
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);

protected:
	// 当需要在子类弹出几个PopMenu时，实现该函数，
	virtual void PopMenu(int nMenuID, const CEspPoint& pt) {}
};

#endif /* _BMENUCONTAINER_H_2011_03_09_ */
