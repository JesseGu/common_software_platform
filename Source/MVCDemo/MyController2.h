// MyController2.h: interface for the CMyController2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCONTROLLER2_H__3357CECD_4745_4899_A905_9DD0526C052A__INCLUDED_)
#define AFX_MYCONTROLLER2_H__3357CECD_4745_4899_A905_9DD0526C052A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpxController.h"

class CMyController2 : public CSpxController
{
public:
	CMyController2();

protected:
	virtual bool OnRegisterObserver(ISpxObserver* pObserver);
	virtual bool OnUnregisterObserver(ISpxObserver* pObserver);

	virtual bool OnMessage(int nWndID, int nCmdID, int nParam1, int nParam2);
};

#endif // !defined(AFX_MYCONTROLLER2_H__3357CECD_4745_4899_A905_9DD0526C052A__INCLUDED_)
