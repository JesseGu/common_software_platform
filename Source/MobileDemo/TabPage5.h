/******************************************************************************
* FileName		       : TabPage5.h
* Description          : interface for the CTabPage5 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABPAGE5_H__EC18370D_AFC4_41F1_88EE_C5E739495707__INCLUDED_)
#define AFX_TABPAGE5_H__EC18370D_AFC4_41F1_88EE_C5E739495707__INCLUDED_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

class CBComboBox;
class CBLabel;
class CBEdit;

class CTabPage5Builder : public IAwsContainerBuilder
{
public:
	virtual CAwsContainer* Build(CAwsWindow* pParent, const CEspRect& rect);	
};

class CTabPage5 : public CAwsContainer
{
public:
	CTabPage5();

protected:
	virtual void OnCreate();

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);
	virtual void OnFocus(bool bIsFocus);

protected:
	CBLabel*	m_pLabel;
	CBComboBox*	m_pComboBox;

	CBLabel*	m_pEditLabel;
	CBEdit*		m_pEdit;
};

#endif // !defined(AFX_TABPAGE5_H__EC18370D_AFC4_41F1_88EE_C5E739495707__INCLUDED_)
