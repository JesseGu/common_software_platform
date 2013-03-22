/******************************************************************************
* FileName		       : BTabPanel.cpp
* Description          : implementation of the CBTabPanel class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BTabPanel.h"
const VTab_CAwsWindow g_tVTab_CBTabPanel_CAwsWindow = {CBTabPanel_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CBTabPanel_OnDraw_CEspRect1p, CAwsContainer_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CBTabPanel_OnCommand_i0p_i0p_i0p_i0p, CBTabPanel_OnCreate};
void CBTabPanel_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CBTabPanel* pThis=(CBTabPanel*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBTabPanel*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

CBSelectBox * CBTabPanel_GetSelectBox(CBTabPanel* pThis) { return pThis->m_pSelectBox; } 

#include "BSelectBox.h"
#include "IAwsGc.h"

void CBTabPanel_CInit(CBTabPanel* pThis)
{

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
CAwsImage_CInit(&(pThis->m_oImageBK));
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBTabPanel_CAwsWindow;
{
	pThis->m_pSelectBox=ESP_NULL;
}
}

void CBTabPanel_OnCreate(CAwsWindow* this)
{

	CBTabPanel* pThis = (CBTabPanel*)this;{
	CEspRect rt;
	{CBSelectBox*pHeapObj_1=(CBSelectBox(*))malloc(sizeof(CBSelectBox));
CBSelectBox_CInit_i0p(pHeapObj_1,10);
{CEspRect_CInit_i0p_i0p_i0p_i0p(&rt,0,0,180,30);
pThis->m_pSelectBox=pHeapObj_1;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pSelectBox->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt),0,1);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pSelectBox)->m_oBase_CAwsWindow),1);
}}}
}

int CBTabPanel_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CBTabPanel* pThis = (CBTabPanel*)this;{
	if(AWS_SysCmd_SelectBoxFocusItemChange==nCmdID){
	{
		// 收到改变的消息
		CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_TabPanelChangePage,nParam1,0);

		return 1;
	}}

	return CAwsWindow_OnCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),nWndID,nCmdID,nParam1,nParam2);
}
}

void CBTabPanel_SetBKImage_CAwsImage1p(CBTabPanel* pThis, const CAwsImage * imageBK)
{
	pThis->m_oImageBK=*imageBK;
}

void CBTabPanel_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CBTabPanel* pThis = (CBTabPanel*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));

	if(CAwsImage_GetID(&(pThis->m_oImageBK))>0){
	{
		// 画背景图片
		CEspPoint pt;
		CEspPoint_CInit_i0p_i0p(&pt,0,0);
pGc->m_pVTab->m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(pGc,&(pt),&(pThis->m_oImageBK),ESP_NULL);
	}}

	CAwsContainer_OnDraw_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),rect);
}
}
