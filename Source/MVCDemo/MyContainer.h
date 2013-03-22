// MyContainer.h: interface for the CMyContainer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCONTAINER_H__56EEA06B_2399_4A70_B878_717DA5E56688__INCLUDED_)
#define AFX_MYCONTAINER_H__56EEA06B_2399_4A70_B878_717DA5E56688__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AwsContainer.h"
#include "Model1Observer1.h"
#include "Model1Observer2.h"
#include "Model2Observer1.h"
#include "Model2Observer2.h"

#include "BButton.h"

class CMyContainer : public CAwsContainer
{
public:
	CMyContainer(int nMaxSubWndCount);

	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);

protected:
	virtual void OnCreate();

	CModel1Observer1*	m_pM1O1Label;
	CModel1Observer2*	m_pM1O2Label;
	CModel2Observer1*	m_pM2O1Label;
	CModel2Observer2*	m_pM2O2Label;

	CBButton*			m_pM1Button;
	CBButton*			m_pM2Button;
};

#endif // !defined(AFX_MYCONTAINER_H__56EEA06B_2399_4A70_B878_717DA5E56688__INCLUDED_)
