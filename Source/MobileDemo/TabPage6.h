/******************************************************************************
* FileName		       : TabPage6.h
* Description          : interface for the CTabPage6 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABPAGE6_H__7AA82EB1_4BD6_4534_9A3B_2E0985985314__INCLUDED_)
#define AFX_TABPAGE6_H__7AA82EB1_4BD6_4534_9A3B_2E0985985314__INCLUDED_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

class CMScrollLabel;
class CBButton;
class CBLabel;

class CTabPage6Builder : public IAwsContainerBuilder
{
public:
	virtual CAwsContainer* Build(CAwsWindow* pParent, const CEspRect& rect);
};

class CTabPage6 : public CAwsContainer
{
public:
	CTabPage6();

protected:
	virtual void OnCreate();

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);
	virtual void OnFocus(bool bIsFocus);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);

private:
	CMScrollLabel*	m_pScrollLabel;
	CBButton*		m_pButton;
	CBLabel*		m_pLabel;
};

#endif // !defined(AFX_TABPAGE6_H__7AA82EB1_4BD6_4534_9A3B_2E0985985314__INCLUDED_)
