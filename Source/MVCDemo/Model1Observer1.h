// Model1Observer1.h: interface for the CModel1Observer1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODEL1OBSERVER1_H__D56F2DE8_CF4F_4FA5_BA5A_3661BFCBA092__INCLUDED_)
#define AFX_MODEL1OBSERVER1_H__D56F2DE8_CF4F_4FA5_BA5A_3661BFCBA092__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISpxObserver.h"
#include "BLabel.h"

class CModel1Observer1 : public CBLabel, public ISpxObserver
{
public:
	virtual void UpdateData(CSpxModel* pModel);
	virtual int GetObserverID() { return m_nWndID; }
};

#endif // !defined(AFX_MODEL1OBSERVER1_H__D56F2DE8_CF4F_4FA5_BA5A_3661BFCBA092__INCLUDED_)
