/******************************************************************************
* FileName		       : TabPage3.h
* Description          : interface for the CTabPage3 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#if !defined(AFX_TABPAGE3_H__7CD8642C_8403_4130_A705_0000BCDD77B5__INCLUDED_)
#define AFX_TABPAGE3_H__7CD8642C_8403_4130_A705_0000BCDD77B5__INCLUDED_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

class CBButton;
class CBImageButton;
class CBRadioBox;
class CBCheckBox;

class CTabPage3Builder : public IAwsContainerBuilder
{
public:
	virtual CAwsContainer* Build(CAwsWindow* pParent, const CEspRect& rect);
};

class CTabPage3 : public CAwsContainer
{
public:
	CTabPage3();

protected:
	virtual void OnCreate();

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);

private:
	CBButton*		m_pButton;
	CBImageButton*	m_pImageButton;
	CBRadioBox*		m_pRadioBox;
	CBCheckBox*		m_pCheckBox;
};

#endif // !defined(AFX_TABPAGE3_H__7CD8642C_8403_4130_A705_0000BCDD77B5__INCLUDED_)
