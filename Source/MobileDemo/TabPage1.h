/******************************************************************************
* FileName		       : TabPage1.h
* Description          : interface for the CTabPage1 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABPAGE1_H__7955D5A3_7F38_4758_A361_64E253330A97__INCLUDED_)
#define AFX_TABPAGE1_H__7955D5A3_7F38_4758_A361_64E253330A97__INCLUDED_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

class CBLabel;
class CBProgressBar;
class CBButton;

class CTabPage1Builder : public IAwsContainerBuilder
{
public:
	virtual CAwsContainer* Build(CAwsWindow* pParent, const CEspRect& rect);
};

class CTabPage1 : public CAwsContainer
{
public:
	CTabPage1();

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual void OnTimer();
	virtual void OnFocus(bool bIsFocus);
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);

protected:
	virtual void OnCreate();

private:
	CBLabel*		m_pLabel;

	CBProgressBar*	m_pProgressBar;
	int				m_nProgressBarLength;
	int				m_nCurProgressBarPos;

	CBButton*		m_pButton;

	bool			m_bIsStart;
};

#endif // !defined(AFX_TABPAGE1_H__7955D5A3_7F38_4758_A361_64E253330A97__INCLUDED_)
