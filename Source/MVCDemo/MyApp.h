// MyApp.h: interface for the CMyApp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYAPP_H__3EFEF79D_B308_4018_90C9_4B8B5A8ED2AF__INCLUDED_)
#define AFX_MYAPP_H__3EFEF79D_B308_4018_90C9_4B8B5A8ED2AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpxApp.h"

class CMyApp : public CSpxApp
{
public:
	CMyApp();

protected:
	virtual void OnInit(const CEspSize& sizeScreen);
};

#endif // !defined(AFX_MYAPP_H__3EFEF79D_B308_4018_90C9_4B8B5A8ED2AF__INCLUDED_)
