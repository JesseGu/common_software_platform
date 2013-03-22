/******************************************************************************
* FileName		       : TabPage2.h
* Description          : interface for the CTabPage2 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABPAGE2_H__E09650F0_D652_4051_8C41_36707E6368B3__INCLUDED_)
#define AFX_TABPAGE2_H__E09650F0_D652_4051_8C41_36707E6368B3__INCLUDED_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

class CBListBox;
class CBLabel;

class CTabPage2Builder : public IAwsContainerBuilder
{
public:
	virtual CAwsContainer* Build(CAwsWindow* pParent, const CEspRect& rect);
};

class CTabPage2 : public CAwsContainer
{
public:
	CTabPage2();

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);

protected:
	virtual void OnCreate();

protected:
	CBListBox*	m_pListBox;
	CBLabel*	m_pLabel;
};

#endif // !defined(AFX_TABPAGE2_H__E09650F0_D652_4051_8C41_36707E6368B3__INCLUDED_)
