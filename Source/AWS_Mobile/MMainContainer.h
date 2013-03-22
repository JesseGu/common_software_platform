/******************************************************************************
* FileName		       : MMainContainer.h
* Description          : interface for the CMMainContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _MMAINCONTAINER_H_2009_10_09_
#define _MMAINCONTAINER_H_2009_10_09_

#include "BMenuContainer.h"

class CMUi;
class CBMenu;

class CMMainContainer : public CBMenuContainer
{
public:
	CMMainContainer(int nMaxSubWndCount);

	CMUi* GetMUi();

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);

	// 被激活了，有可能是已经存在被重新唤回，也可能是刚创建的
	virtual void OnActive() {}
	// 被切换离开主界面时调用
	virtual void InActive() {}

protected:
	virtual void OnLeftMenu() {}
	virtual void OnRightMenu() {}

protected:
	// 用于调整菜单的位置
	void AdjustMenuPos(CBMenu* pMenu, CEspRect& rect, const CEspPoint& pt, bool bIsSubMenu);

	// 更新菜单显示的信息
	void UpdateMenuBar(AWS_SysStringID eLeftStrID, AWS_SysStringID eRightStrID, bool bIsRedraw = true);

protected:
	CAwsString	m_strLeftMenu;
	CAwsString	m_strRightMenu;
};

#endif /* _MMAINCONTAINER_H_2009_10_09_ */
