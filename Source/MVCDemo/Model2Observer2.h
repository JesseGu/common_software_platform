// Model2Observer2.h: interface for the CModel2Observer2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODEL2OBSERVER2_H__E383C6D4_727C_46ED_A0C4_2017492D789E__INCLUDED_)
#define AFX_MODEL2OBSERVER2_H__E383C6D4_727C_46ED_A0C4_2017492D789E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISpxObserver.h"
#include "BLabel.h"

class CModel2Observer2 : public ISpxObserver, public CBLabel
{
public:
	virtual void UpdateData(CSpxModel* pModel);
	virtual int GetObserverID() { return m_nWndID; }
};

#endif // !defined(AFX_MODEL2OBSERVER2_H__E383C6D4_727C_46ED_A0C4_2017492D789E__INCLUDED_)
