/******************************************************************************
* FileName		       : MyMainContainer.h
* Description          : interface for the CMyMainContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_MYMAIN_H__B82014C3_03FC_4243_AC38_77925A5B61AC__INCLUDED_)
#define AFX_MYMAIN_H__B82014C3_03FC_4243_AC38_77925A5B61AC__INCLUDED_

#include "MMainContainer.h"
#include "IAwsContainerBuilder.h"

class CBScrollBar;
class CBListView;

class CMyMainContainerBuilder : public IAwsContainerBuilder
{
public:
	virtual CAwsContainer* Build(CAwsWindow* pParent, const CEspRect& rect);
};

class CMyMainContainer : public CMMainContainer
{
public:
	CMyMainContainer();

public:
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);
	virtual void OnSize(const CEspSize& size, bool bIsRedraw = true);

	virtual void OnActive();
	void InActive();

protected:
	virtual void OnCreate();

	virtual void OnLeftMenu();
	virtual void OnRightMenu();

	virtual void PopMenu(int nMenuID, const CEspPoint& pt);

private:
	CBScrollBar*	m_pScrollBar;
	int				m_nScrollTotalLength;
	int				m_nScrollPos;

	CBListView*		m_pListView;
};

#endif // !defined(AFX_MYMAIN_H__B82014C3_03FC_4243_AC38_77925A5B61AC__INCLUDED_)
