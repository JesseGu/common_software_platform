// Model2Observer1.h: interface for the CModel2Observer1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODEL2OBSERVER1_H__D02628CB_DDC4_4EA8_A16B_5C1513EDB29C__INCLUDED_)
#define AFX_MODEL2OBSERVER1_H__D02628CB_DDC4_4EA8_A16B_5C1513EDB29C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISpxObserver.h"
#include "BLabel.h"

class CModel2Observer1 : public ISpxObserver, public CBLabel
{
public:
	virtual void UpdateData(CSpxModel* pModel);
	virtual int GetObserverID() { return m_nWndID; }
};

#endif // !defined(AFX_MODEL2OBSERVER1_H__D02628CB_DDC4_4EA8_A16B_5C1513EDB29C__INCLUDED_)
