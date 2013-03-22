/******************************************************************************
* FileName		       : BTabContainer.h
* Description          : interface for the CBTabContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BTABCONTAINER_H_2009_10_09_
#define _BTABCONTAINER_H_2009_10_09_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

class CBTabPanel;

class CBTabView : public CAwsContainer
{
public:
	CBTabView();
	virtual ~CBTabView();

	// ×¢²á¡¢ÇÐ»»ÈÝÆ÷
	bool RegisterMainContainer(IAwsContainerBuilder* pContainBuilder);
	bool SwitchContainer(int nIndex);

	CBTabPanel* GetTabPanel() { return m_pTabPanel; }
	CAwsContainer* GetCurContainer() { return m_pCurContainer; }

public:
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2);
	virtual void OnSize(const CEspSize& size, bool bIsRedraw = true);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);

protected:
	virtual void OnCreate();

protected:
	// »ñµÃ´æ·ÅÈÝÆ÷µÄÇøÓò
	CEspRect& GetClientRect();

protected:
	CBTabPanel*		m_pTabPanel;		// Tab¿ØÖÆÃæ°å

	struct TRegisterData
	{
		IAwsContainerBuilder*	m_pContainBuilder;
		CAwsContainer*			m_pContainer;
	};
	TRegisterData*	m_pRegData;
	int				m_nMaxMainContainer;
	int				m_nRegDataCount;

	CAwsContainer*	m_pCurContainer;
	int				m_nCurContainerIndex;

	CEspRect		m_rtClient;
};

#endif /* _BTABCONTAINER_H_2009_10_09_ */
