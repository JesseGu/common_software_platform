// EMyui.h: interface for the CEMyui class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EMYUI_H__D40D538F_A066_4715_9D47_5BF97FDFBA31__INCLUDED_)
#define AFX_EMYUI_H__D40D538F_A066_4715_9D47_5BF97FDFBA31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AwsUi.h"

class CWnd;

class CEMyUi : public CAwsUi
{
public:
	CEMyUi();

	void SetScreen(CWnd* pScreen)
	{
		m_pScreen = pScreen;
	}

public:
	virtual void Timer(int nTimerID, int nTime);
	virtual void KillTimer(int nTimerID);
	virtual void ExitSys();

private:
	CWnd* m_pScreen;
};

#endif // !defined(AFX_EMYUI_H__D40D538F_A066_4715_9D47_5BF97FDFBA31__INCLUDED_)
