/******************************************************************************
* FileName		       : BTabContainer.cpp
* Description          : implementation of the CBTabView class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BTabView.h"
const VTab_CAwsWindow g_tVTab_CBTabView_CAwsWindow = {CBTabView_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CAwsContainer_OnDraw_CEspRect1p, CBTabView_OnKey_0p_0p, CBTabView_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CBTabView_OnCommand_i0p_i0p_i0p_i0p, CBTabView_OnCreate};
CAwsContainer * CBTabView_GetCurContainer(CBTabView* pThis) { return pThis->m_pCurContainer; } 

CBTabPanel * CBTabView_GetTabPanel(CBTabView* pThis) { return pThis->m_pTabPanel; } 

#include "BTabPanel.h"
#include "IAwsGc.h"

void CBTabView_CInit(CBTabView* pThis) {

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
CEspRect_CInit(&(pThis->m_rtClient));
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBTabView_CAwsWindow;
{
	pThis->m_pTabPanel=ESP_NULL;

	pThis->m_nMaxMainContainer=10;
	pThis->m_nRegDataCount=0;
	{CBTabView_TRegisterData(*pHeapObj_1)=(CBTabView_TRegisterData(*))malloc(sizeof(CBTabView_TRegisterData)*pThis->m_nMaxMainContainer);

{pThis->m_pRegData=pHeapObj_1;
	{int i;
	for(i=0;i<pThis->m_nMaxMainContainer;++i){
	{
		pThis->m_pRegData[i].m_pContainBuilder=ESP_NULL;
		pThis->m_pRegData[i].m_pContainer=ESP_NULL;
	}}

	pThis->m_pCurContainer=ESP_NULL;
	pThis->m_nCurContainerIndex=-1;
}}}}
}

void CBTabView_DUninit_i1p(CAwsWindow* this, int * pOffset)
{

	CBTabView* pThis = (CBTabView*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBTabView*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
{
	int i;
	for(i=0;i<pThis->m_nMaxMainContainer;++i){
	{
		free(pThis->m_pRegData[i].m_pContainBuilder);;
		pThis->m_pRegData[i].m_pContainBuilder=ESP_NULL;
	}}

	free(pThis->m_pRegData);;
}
}

void CBTabView_OnCreate(CAwsWindow* this)
{

	CBTabView* pThis = (CBTabView*)this;{
	CAwsContainer_OnCreate(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));

	// 创建TablePanel
	{CBTabPanel(*pHeapObj_1)=(CBTabPanel(*))malloc(sizeof(CBTabPanel));
CBTabPanel_CInit(pHeapObj_1);
{pThis->m_pTabPanel=pHeapObj_1;
	{CEspRect rt;
	CEspRect_CInit_i0p_i0p_i0p_i0p(&rt,0,0,240,51);
CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pTabPanel->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt),0,1);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pTabPanel)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),1);
}}}}
}

int CBTabView_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CBTabView* pThis = (CBTabView*)this;{
	if(AWS_SysCmd_TabPanelChangePage==nCmdID){
	{
		// 收到改变的消息
		CBTabView_SwitchContainer_i0p(pThis,nParam1);
		return 1;
	}}
	else if(AWS_SysCmd_TabViewSetPanelFocus==nCmdID){
	{
		// 把TabPanel设置为焦点
		CAwsContainer_SetFocus_CAwsWindow1p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pTabPanel)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
		return 1;
	}}

	return CAwsWindow_OnCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),nWndID,nCmdID,nParam1,nParam2);
}
}

void CBTabView_OnSize_CEspSize1p_i0p(CAwsWindow* this, const CEspSize * size,int bIsRedraw)
{

	CBTabView* pThis = (CBTabView*)this;{
	CAwsContainer_OnSize_CEspSize1p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),size,bIsRedraw);
	
	if(ESP_NULL!=pThis->m_pCurContainer){
	{
		CEspRect rt=*(CAwsWindow_GetRect(&(pThis->m_pTabPanel->m_oBase_CAwsContainer.m_oBase_CAwsWindow)));
		CEspRect rect;
		CEspRect_CInit_i0p_i0p_i0p_i0p(&rect,0,rt.m_ptRB.m_nY,size->m_nWidth,size->m_nHeight);
CAwsWindow_MoveTo_CEspRect1p_i0p(&(pThis->m_pCurContainer->m_oBase_CAwsWindow),&(rect),bIsRedraw);
	}}
}
}

int CBTabView_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CBTabView* pThis = (CBTabView*)this;{
	int bRet=CAwsContainer_OnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);

	if(!bRet){
	{
		if(AWS_Key==type){
		{
			switch(code)
			{
			case AWS_KeyCode_DownArrow:
				if(ESP_NULL!=pThis->m_pCurContainer){
				{
					CAwsContainer_SetFocus_CAwsWindow1p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pCurContainer)->m_oBase_CAwsWindow));
				}}
				break;

			case AWS_KeyCode_LeftArrow:
				CAwsContainer_SetFocus_CAwsWindow1p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pTabPanel)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
				pThis->m_pTabPanel->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pOnKey_0p_0p(&(pThis->m_pTabPanel->m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);
				break;

			case AWS_KeyCode_RightArrow:
				CAwsContainer_SetFocus_CAwsWindow1p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pTabPanel)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
				pThis->m_pTabPanel->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pOnKey_0p_0p(&(pThis->m_pTabPanel->m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);
				break;
			}
		}}
	}}

	return bRet;
}
}

CEspRect * CBTabView_GetClientRect(CBTabView* pThis)
{
	CEspSize size=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
	CEspSize sizePanel=*CAwsWindow_GetSize(&(pThis->m_pTabPanel->m_oBase_CAwsContainer.m_oBase_CAwsWindow));

	CEspRect rt;
	CEspRect_CInit_i0p_i0p_i0p_i0p(&rt,0,sizePanel.m_nHeight,size.m_nWidth,size.m_nHeight);
pThis->m_rtClient=rt;
	return &(pThis->m_rtClient);
}

int CBTabView_RegisterMainContainer_IAwsContainerBuilder1p(CBTabView* pThis, IAwsContainerBuilder *  pContainBuilder)
{
	int bRet=0;

	if(pThis->m_nRegDataCount<pThis->m_nMaxMainContainer){
	{
		pThis->m_pRegData[pThis->m_nRegDataCount].m_pContainBuilder=pContainBuilder;
		++pThis->m_nRegDataCount;
		bRet=1;
	}}

	return bRet;
}

int CBTabView_SwitchContainer_i0p(CBTabView* pThis, int nIndex)
{
	int bRet=0;

	if(nIndex>=0&&nIndex<pThis->m_nMaxMainContainer&&nIndex!=pThis->m_nCurContainerIndex){
	{
		if(pThis->m_nCurContainerIndex>=0){
		{
			// 隐藏先前的
			CAwsWindow_SetVisible_i0p_i0p(&(pThis->m_pRegData[pThis->m_nCurContainerIndex].m_pContainer->m_oBase_CAwsWindow),0,0);
		}}

		// 找到，先看是否已经存在
		if(ESP_NULL==pThis->m_pRegData[nIndex].m_pContainer){
		{
			// 新创建
			pThis->m_pRegData[nIndex].m_pContainer=pThis->m_pRegData[nIndex].m_pContainBuilder->m_pVTab->m_pBuild_CAwsWindow1p_CEspRect1p(pThis->m_pRegData[nIndex].m_pContainBuilder,&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),CBTabView_GetClientRect(pThis));

			CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pRegData[nIndex].m_pContainer)->m_oBase_CAwsWindow),1);
			pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),CBTabView_GetClientRect(pThis));
			CAwsContainer_SetFocus_CAwsWindow1p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pTabPanel)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
		}}
		else
		{{
			// 已经存在，则直接显示
			CAwsWindow_SetVisible_i0p_i0p(&(pThis->m_pRegData[nIndex].m_pContainer->m_oBase_CAwsWindow),1,1);
		}}

		pThis->m_pCurContainer=pThis->m_pRegData[nIndex].m_pContainer;
		pThis->m_nCurContainerIndex=nIndex;

		bRet=1;
	}}

	return bRet;
}
