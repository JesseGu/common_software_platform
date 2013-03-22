// Model1Observer2.h: interface for the CModel1Observer2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODEL1OBSERVER2_H__52E25931_3C94_46CB_9ACC_CAA03235D85F__INCLUDED_)
#define AFX_MODEL1OBSERVER2_H__52E25931_3C94_46CB_9ACC_CAA03235D85F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISpxObserver.h"
#include "BLabel.h"

class CModel1Observer2 : public ISpxObserver, public CBLabel
{
public:
	virtual void UpdateData(CSpxModel* pModel);
	virtual int GetObserverID() { return m_nWndID; }
};

#endif // !defined(AFX_MODEL1OBSERVER2_H__52E25931_3C94_46CB_9ACC_CAA03235D85F__INCLUDED_)
