// MyApp.h: interface for the CMyApp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYAPP_H__3EFEF79D_B308_4018_90C9_4B8B5A8ED2AF__INCLUDED_)
#define AFX_MYAPP_H__3EFEF79D_B308_4018_90C9_4B8B5A8ED2AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpxApp.h"

typedef struct tagCMyApp CMyApp;

// ������
struct tagCMyApp
{
	CSpxApp m_oBase_CSpxApp;

};

// ��Ա��������
void CMyApp_OnInit_CEspSize1p(CSpxApp* this, const CEspSize * sizeScreen);
void CMyApp_DUninit_i1p(CSpxApp* this, int* pOffset);
void CMyApp_CInit(CMyApp* pThis);

// �麯���������
extern const VTab_CSpxApp g_tVTab_CMyApp_CSpxApp;


#endif // !defined(AFX_MYAPP_H__3EFEF79D_B308_4018_90C9_4B8B5A8ED2AF__INCLUDED_)
