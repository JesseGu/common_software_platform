// MyApp.cpp: implementation of the CMyApp class.
//
//////////////////////////////////////////////////////////////////////

#include "MyApp.h"
#include "MyUi.h"

const VTab_CSpxApp g_tVTab_CMyApp_CSpxApp = {CMyApp_DUninit_i1p, CMyApp_OnInit_CEspSize1p};
void CMyApp_DUninit_i1p(CSpxApp* this, int* pOffset)
{
	CMyApp* pThis=(CMyApp*)this;
	pThis->m_oBase_CSpxApp.m_pVTab = &g_tVTab_CSpxApp_CSpxApp;
	CSpxApp_DUninit_i1p(&(pThis->m_oBase_CSpxApp), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMyApp*)0)->m_oBase_CSpxApp));
}

void CMyApp_CInit(CMyApp* pThis)
{

CSpxApp_CInit_i0p(&(pThis->m_oBase_CSpxApp),1);
	pThis->m_oBase_CSpxApp.m_pVTab = &g_tVTab_CMyApp_CSpxApp;
{
}
}

void CMyApp_OnInit_CEspSize1p(CSpxApp* this, const CEspSize * sizeScreen)
{

	CMyApp* pThis = (CMyApp*)this;{
	{CMyUi(*pHeapObj_1)=(CMyUi(*))malloc(sizeof(CMyUi));
CMyUi_CInit(pHeapObj_1);
{CMyUi *  pContainer=pHeapObj_1;

	CEspRect rect;
	CEspRect_CInit(&(rect));
rect.m_ptRB.m_nX=sizeScreen->m_nWidth;
	rect.m_ptRB.m_nY=sizeScreen->m_nHeight;

	CAwsWindow_SetUi_CAwsUi1p(&(pContainer->m_oBase_CMUi.m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CSpxApp.m_pUi);
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pContainer->m_oBase_CMUi.m_oBase_CAwsContainer.m_oBase_CAwsWindow),ESP_NULL,&(rect),0,1);
	CAwsUi_AddWndToStack_CAwsWindow1p(pThis->m_oBase_CSpxApp.m_pUi,&((pContainer)->m_oBase_CMUi.m_oBase_CAwsContainer.m_oBase_CAwsWindow));

	CAwsUi_SetTopWnd_CAwsContainer1p(pThis->m_oBase_CSpxApp.m_pUi,&((pContainer)->m_oBase_CMUi.m_oBase_CAwsContainer));
}}}
}
