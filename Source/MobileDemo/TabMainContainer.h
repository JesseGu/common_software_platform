/******************************************************************************
* FileName		       : TabMainContainer.h
* Description          : interface for the CTabMainContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABMAINCONTAINER_H__98979F34_09AF_41C3_8997_0D50C2379768__INCLUDED_)
#define AFX_TABMAINCONTAINER_H__98979F34_09AF_41C3_8997_0D50C2379768__INCLUDED_

#include "MMainContainer.h"
#include "IAwsContainerBuilder.h"

class CBTabView;

class CTabMainContainerBuilder : public IAwsContainerBuilder
{
public:
	virtual CAwsContainer* Build(CAwsWindow* pParent, const CEspRect& rect);
};

class CTabMainContainer : public CMMainContainer
{
public:
	CTabMainContainer();

public:
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);
	virtual void OnSize(const CEspSize& size, bool bIsRedraw = true);
	virtual void OnActive();
	virtual void InActive();

protected:
	virtual void OnCreate();

	virtual void OnLeftMenu();
	virtual void OnRightMenu();

	virtual void PopMenu(int nMenuID, const CEspPoint& pt);

protected:
	CBTabView*	m_pTabView;
};

#endif // !defined(AFX_TABMAINCONTAINER_H__98979F34_09AF_41C3_8997_0D50C2379768__INCLUDED_)
