// AwsDemo.h : main header file for the AWSDEMO application
//

#if !defined(AFX_AWSDEMO_H__848E154D_D40F_4659_9D9B_23CBC8F3E493__INCLUDED_)
#define AFX_AWSDEMO_H__848E154D_D40F_4659_9D9B_23CBC8F3E493__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAwsDemoApp:
// See AwsDemo.cpp for the implementation of this class
//

class CWin32AdapterApp : public CWinApp
{
public:
	CWin32AdapterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAwsDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAwsDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AWSDEMO_H__848E154D_D40F_4659_9D9B_23CBC8F3E493__INCLUDED_)
