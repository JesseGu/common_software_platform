/******************************************************************************
* FileName		       : MyUi.cpp
* Description          : implementation of the CMyUi class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "MyUi.h"

#include "MyMainContainer.h"
#include "TabMainContainer.h"

#include "BMenu.h"
#include "AwsUserDefine.h"
#include "MMenuBar.h"
#include "IAwsGc.h"

// 注册所有需要用到的主容器

const VTab_CAwsWindow g_tVTab_CMyUi_CAwsWindow = {CMyUi_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CMUi_OnDraw_CEspRect1p, CAwsContainer_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CMyUi_OnCreate};
void CMyUi_CInit(CMyUi* pThis)
{
CMUi_CInit_i0p(&(pThis->m_oBase_CMUi),6);
	pThis->m_oBase_CMUi.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CMyUi_CAwsWindow;
}

void CMyUi_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CMyUi* pThis=(CMyUi*)this;
	pThis->m_oBase_CMUi.m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CMUi_DUninit_i1p(&(pThis->m_oBase_CMUi.m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMyUi*)0)->m_oBase_CMUi.m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CMyUi_OnCreate(CAwsWindow* this)
{

	CMyUi* pThis = (CMyUi*)this;{
	CMUi_OnCreate(&(pThis->m_oBase_CMUi.m_oBase_CAwsContainer.m_oBase_CAwsWindow));

	// 注册主窗口
	{CMyMainContainerBuilder*pHeapObj_1=(CMyMainContainerBuilder(*))malloc(sizeof(CMyMainContainerBuilder));
CMyMainContainerBuilder_CInit(pHeapObj_1);
{CMUi_RegisterMainContainer_i0p_IAwsContainerBuilder1p(&(pThis->m_oBase_CMUi),MyMainContainerID,&((pHeapObj_1)->m_oBase_IAwsContainerBuilder));
	{CTabMainContainerBuilder*pHeapObj_2=(CTabMainContainerBuilder(*))malloc(sizeof(CTabMainContainerBuilder));
CTabMainContainerBuilder_CInit(pHeapObj_2);
{CMUi_RegisterMainContainer_i0p_IAwsContainerBuilder1p(&(pThis->m_oBase_CMUi),TabMainContainerID,&((pHeapObj_2)->m_oBase_IAwsContainerBuilder));

	// 设置默认主窗口
	CMUi_ChangeMainContainer_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CMUi),MyMainContainerID,0,0,0);
}}}}}
}
