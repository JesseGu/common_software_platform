// MyController1.h: interface for the CMyController1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCONTROLLER1_H__482F041F_3B29_49BF_997E_C9028F2DB0FC__INCLUDED_)
#define AFX_MYCONTROLLER1_H__482F041F_3B29_49BF_997E_C9028F2DB0FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpxController.h"

class CMyController1 : public CSpxController
{
public:
	CMyController1();

protected:
	virtual bool OnRegisterObserver(ISpxObserver* pObserver);
	virtual bool OnUnregisterObserver(ISpxObserver* pObserver);

	virtual bool OnMessage(int nWndID, int nCmdID, int nParam1, int nParam2);
};

#endif // !defined(AFX_MYCONTROLLER1_H__482F041F_3B29_49BF_997E_C9028F2DB0FC__INCLUDED_)
