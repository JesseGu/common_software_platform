// MyApp.cpp: implementation of the CMyApp class.
//
//////////////////////////////////////////////////////////////////////

#include "MyApp.h"

#include "MyController1.h"
#include "MyController2.h"
#include "MyContainer.h"

const VTab_CSpxApp g_tVTab_CMyApp_CSpxApp = {CMyApp_DUninit_i1p, CMyApp_OnInit_CEspSize1p};
void CMyApp_DUninit_i1p(CSpxApp* this, int* pOffset)
{
	CMyApp* pThis=(CMyApp*)this;
	pThis->m_oBase_CSpxApp.m_pVTab = &g_tVTab_CSpxApp_CSpxApp;
	CSpxApp_DUninit_i1p(&(pThis->m_oBase_CSpxApp), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMyApp*)0)->m_oBase_CSpxApp));
}

void CMyApp_CInit(CMyApp* pThis) {

CSpxApp_CInit_i0p(&(pThis->m_oBase_CSpxApp),2);
	pThis->m_oBase_CSpxApp.m_pVTab = &g_tVTab_CMyApp_CSpxApp;
{
	// 添加控制器
	{CMyController1*pHeapObj_1=(CMyController1(*))malloc(sizeof(CMyController1));
CMyController1_CInit(pHeapObj_1);
{CSpxApp_AddController_CSpxController1p(&(pThis->m_oBase_CSpxApp),&((pHeapObj_1)->m_oBase_CSpxController));
	{CMyController2*pHeapObj_2=(CMyController2(*))malloc(sizeof(CMyController2));
CMyController2_CInit(pHeapObj_2);
{CSpxApp_AddController_CSpxController1p(&(pThis->m_oBase_CSpxApp),&((pHeapObj_2)->m_oBase_CSpxController));
}}}}}
}

void CMyApp_OnInit_CEspSize1p(CSpxApp* this, const CEspSize * sizeScreen)
{

	CMyApp* pThis = (CMyApp*)this;{
	// 创建主容器
	{CMyContainer*pHeapObj_1=(CMyContainer(*))malloc(sizeof(CMyContainer));
CMyContainer_CInit_i0p(pHeapObj_1,10);
{CAwsContainer *  pContainer=&((pHeapObj_1)->m_oBase_CAwsContainer);
	CEspRect rect;
	CEspRect_CInit(&(rect));
rect.m_ptRB.m_nX=sizeScreen->m_nWidth;
	rect.m_ptRB.m_nY=sizeScreen->m_nHeight;

	CAwsWindow_SetUi_CAwsUi1p(&(pContainer->m_oBase_CAwsWindow),pThis->m_oBase_CSpxApp.m_pUi);
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pContainer->m_oBase_CAwsWindow),ESP_NULL,&(rect),0,1);
	CAwsUi_AddWndToStack_CAwsWindow1p(pThis->m_oBase_CSpxApp.m_pUi,&((pContainer)->m_oBase_CAwsWindow));

	CAwsUi_SetTopWnd_CAwsContainer1p(pThis->m_oBase_CSpxApp.m_pUi,pContainer);
}}}
}
