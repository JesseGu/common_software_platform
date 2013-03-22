/******************************************************************************
* FileName		       : MUi.h
* Description          : interface for the CMUi class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _MUI_H_2009_10_09_
#define _MUI_H_2009_10_09_

#include "AwsContainer.h"
#include "IAwsContainerBuilder.h"

class CMMenuBar;
class CBTitleBar;
class CMMainContainer;
class CMMenu;

// Mobile UI Manager, MenuBar, TitleBar
class CMUi : public CAwsContainer
{
public:
	CMUi(int nMaxSubWndCount = 6);
	virtual ~CMUi();

	void HideMenuBar(bool bIsHide, bool bIsRedraw = true);
	void HideTitleBar(bool bIsHide, bool bIsRedraw = true);

	CMMenuBar* GetMenuBar()
	{
		return m_pMenuBar;
	}

	CBTitleBar* GetTitleBar()
	{
		return m_pTitleBar;
	}

	CEspRect& GetClientRect();

	bool ChangeMainContainer(int nID, bool bIsHideTitleBar = false, bool bIsHideMenuBar = false, bool bIsDestroyFormer = false);

	virtual void OnDraw(const CEspRect& rect);

protected:
	virtual void OnCreate();

protected:
	bool RegisterMainContainer(int nID, IAwsContainerBuilder* pMainContainerBuilder);

	int GetIndexFromID(int nID);

protected:
	CMMenuBar*	m_pMenuBar;
	CBTitleBar*	m_pTitleBar;

	bool		m_bIsHideMenuBar;
	bool		m_bIsHideTitleBar;

	int			m_nTitleBarHeight;
	int			m_nMenuBarHeight;

	CMMainContainer*	m_pCurMainContainer;
	int					m_nCurMainContainerID;

	struct TRegisterData
	{
		int						m_nID;
		IAwsContainerBuilder*	m_pMainContainerBuilder;
		CMMainContainer*		m_pContainer;
	};
	TRegisterData*	m_pRegData;
	int				m_nMaxMainContainer;
	int				m_nRegDataCount;

	CEspRect		m_rtClient;
};

#endif /* _MUI_H_2009_10_09_ */
