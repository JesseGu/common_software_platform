/******************************************************************************
* FileName		       : TabPage4.h
* Description          : interface for the CTabPage4 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABPAGE4_H__04FBC39C_1306_4C65_8616_35BA1DF9F02E__INCLUDED_)
#define AFX_TABPAGE4_H__04FBC39C_1306_4C65_8616_35BA1DF9F02E__INCLUDED_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

class CBSelectBox;
class CBLabel;
class CMImageBox;

class CTabPage4Builder : public IAwsContainerBuilder
{
public:
	virtual CAwsContainer* Build(CAwsWindow* pParent, const CEspRect& rect);
};

class CTabPage4 : public CAwsContainer
{
public:
	CTabPage4();

protected:
	virtual void OnCreate();

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);

private:
	CBLabel*		m_pLabel;
	CBSelectBox*	m_pSelectBox;
	CMImageBox*		m_pImageBox;
};

#endif // !defined(AFX_TABPAGE4_H__04FBC39C_1306_4C65_8616_35BA1DF9F02E__INCLUDED_)
