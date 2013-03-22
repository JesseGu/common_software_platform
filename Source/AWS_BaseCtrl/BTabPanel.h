/******************************************************************************
* FileName		       : BTabPanel.h
* Description          : interface for the CBTabPanel class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BTABPANEL_H_2009_10_09_
#define _BTABPANEL_H_2009_10_09_

#include "AwsContainer.h"

class CBSelectBox;

class CBTabPanel : public CAwsContainer
{
public:
	CBTabPanel();

	void SetBKImage(const CAwsImage& imageBK);

	CBSelectBox* GetSelectBox() { return m_pSelectBox; }

public:
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);
	virtual void OnDraw(const CEspRect& rect);

protected:
	virtual void OnCreate();

protected:
	CBSelectBox*	m_pSelectBox;
	CAwsImage		m_oImageBK;
};

#endif /* _BTABPANEL_H_2009_10_09_ */
