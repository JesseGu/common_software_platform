/******************************************************************************
* FileName		       : MUi.cpp
* Description          : implementation of the CMUi class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "MUi.h"
#include "MMenuBar.h"
#include "BTitleBar.h"
#include "MMainContainer.h"
#include "BMenu.h"

void CMUi_CInit_i0p(CMUi* pThis, int nMaxSubWndCount) {

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),nMaxSubWndCount);
CEspRect_CInit(&(pThis->m_rtClient));
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CMUi_CAwsWindow;
{
	pThis->m_pMenuBar=ESP_NULL;
	pThis->m_pTitleBar=ESP_NULL;

	pThis->m_bIsHideMenuBar=0;
	pThis->m_bIsHideTitleBar=0;

	// 默认的标题条和菜单条的高度
	pThis->m_nTitleBarHeight=24;
	pThis->m_nMenuBarHeight=24;

	pThis->m_pCurMainContainer=ESP_NULL;
	pThis->m_nCurMainContainerID=0;

	pThis->m_nMaxMainContainer=5;
	pThis->m_nRegDataCount=0;
	{CMUi_TRegisterData(*pHeapObj_1)=(CMUi_TRegisterData(*))malloc(sizeof(CMUi_TRegisterData)*pThis->m_nMaxMainContainer);

{pThis->m_pRegData=pHeapObj_1;
	{int i;
	for(i=0;i<pThis->m_nMaxMainContainer;++i){
	{
		pThis->m_pRegData[i].m_nID=0;
		pThis->m_pRegData[i].m_pMainContainerBuilder=ESP_NULL;
		pThis->m_pRegData[i].m_pContainer=ESP_NULL;
	}}
}}}}
}

void CMUi_DUninit_i1p(CAwsWindow* this, int * pOffset)
{

	CMUi* pThis = (CMUi*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMUi*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
{
	int i;
	for(i=0;i<pThis->m_nRegDataCount;++i){
	{
		free(pThis->m_pRegData[i].m_pMainContainerBuilder);;
		pThis->m_pRegData[i].m_pMainContainerBuilder=ESP_NULL;
	}}
	free(pThis->m_pRegData);;
}
}

void CMUi_OnCreate(CAwsWindow* this)
{

	CMUi* pThis = (CMUi*)this;{
	// 创建标题
	CAwsString str;
	CAwsString_CInit_i0p(&(str),100);
CAwsString_LoadString_i0p(&(str),StringID_NULL);
	{CBTitleBar*pHeapObj_1=(CBTitleBar(*))malloc(sizeof(CBTitleBar));
CBTitleBar_CInit_i0p(pHeapObj_1,pThis->m_nTitleBarHeight);
{pThis->m_pTitleBar=pHeapObj_1;
	CBTitleBar_SetCaption_CAwsString1p(pThis->m_pTitleBar,&(str));

	{CEspRect rt;
	CEspRect_CInit(&(rt));
CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pTitleBar->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt),0,!pThis->m_bIsHideTitleBar);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pTitleBar)->m_oBase_CAwsWindow),0);

	// 创建菜单
	{CMMenuBar*pHeapObj_2=(CMMenuBar(*))malloc(sizeof(CMMenuBar));
CMMenuBar_CInit_i0p_CAwsWindow1p(pHeapObj_2,pThis->m_nMenuBarHeight,ESP_NULL);
{pThis->m_pMenuBar=pHeapObj_2;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pMenuBar->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt),0,!pThis->m_bIsHideMenuBar);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pMenuBar)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),0);
}}}}}CAwsString_DUninit_i1p(&(str), 0);
}
}

int CMUi_RegisterMainContainer_i0p_IAwsContainerBuilder1p(CMUi* pThis, int nID,IAwsContainerBuilder *  pMainContainerBuilder)
{
	int bRet=0;

	if(pThis->m_nRegDataCount<pThis->m_nMaxMainContainer){
	{
		pThis->m_pRegData[pThis->m_nRegDataCount].m_nID=nID;
		pThis->m_pRegData[pThis->m_nRegDataCount++].m_pMainContainerBuilder=pMainContainerBuilder;

		bRet=1;
	}}

	return bRet;
}

int CMUi_GetIndexFromID_i0p(CMUi* pThis, int nID)
{
	int i;
	for(i=0;i<pThis->m_nRegDataCount;++i){
	{
		if(pThis->m_pRegData[i].m_nID==nID){
			return i;}
	}}

	return -1;
}

int CMUi_ChangeMainContainer_i0p_i0p_i0p_i0p(CMUi* pThis, int nID,int bIsHideTitleBar,int bIsHideMenuBar,int bIsDestroyFormer)
{
	int bRet=0;

	if(nID>=0&&nID<pThis->m_nMaxMainContainer&&nID!=pThis->m_nCurMainContainerID){
	{
		int i;
		for(i=0;i<pThis->m_nRegDataCount;++i){
		{
			if(pThis->m_pRegData[i].m_nID==nID){
			{
				break;
			}}
		}}

		if(i<pThis->m_nRegDataCount){
		{
			if(pThis->m_nCurMainContainerID>0){
			{
				int nIndex=CMUi_GetIndexFromID_i0p(pThis,pThis->m_nCurMainContainerID);

				// 逆激活
				pThis->m_pRegData[nIndex].m_pContainer->m_pVTab->m_pInActive(pThis->m_pRegData[nIndex].m_pContainer);

				if(bIsDestroyFormer){
				{
					// 销毁
					CAwsContainer_DeleteWindow_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pRegData[nIndex].m_pContainer)->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),1);
					pThis->m_pRegData[nIndex].m_pContainer=ESP_NULL;
				}}
				else
				{{
					// 隐藏
					CAwsWindow_SetVisible_i0p_i0p(&(pThis->m_pRegData[nIndex].m_pContainer->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),0,0);
				}}
			}}

			// 找到，先看是否已经存在
			if(ESP_NULL==pThis->m_pRegData[i].m_pContainer){
			{
				// 新创建
				pThis->m_pRegData[i].m_pContainer=(CMMainContainer*)((char*)pThis->m_pRegData[i].m_pMainContainerBuilder->m_pVTab->m_pBuild_CAwsWindow1p_CEspRect1p(pThis->m_pRegData[i].m_pMainContainerBuilder,&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),CMUi_GetClientRect(pThis))-(int)(&(((CMMainContainer*)0)->m_oBase_CBMenuContainer.m_oBase_CAwsContainer)));

				CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pRegData[i].m_pContainer)->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),1);
			}}
			else
			{{
				// 已经存在，则直接显示
				CAwsWindow_SetVisible_i0p_i0p(&(pThis->m_pRegData[i].m_pContainer->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),1,0);
			}}

			// 激活
			pThis->m_pRegData[i].m_pContainer->m_pVTab->m_pOnActive(pThis->m_pRegData[i].m_pContainer);

			CAwsContainer_SetFocus_CAwsWindow1p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pRegData[i].m_pContainer)->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow));

			pThis->m_pCurMainContainer=pThis->m_pRegData[i].m_pContainer;
			pThis->m_nCurMainContainerID=nID;

			// 对标题栏和菜单条处理
			CMUi_HideTitleBar_i0p_i0p(pThis,bIsHideTitleBar,0);
			CMUi_HideMenuBar_i0p_i0p(pThis,bIsHideMenuBar,0);

			// 重绘制所有窗口
			CAwsWindow_Invalide(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));

			bRet=1;
		}}
	}}

	return bRet;
}

void CMUi_HideMenuBar_i0p_i0p(CMUi* pThis, int bIsHide,int bIsRedraw)
{
	CEspSize size;

	CEspSize_CInit_i0p_i0p(&(size),0,0);
if(bIsHide&&!pThis->m_bIsHideMenuBar){
	{
		pThis->m_bIsHideMenuBar=1;
		CAwsWindow_SetVisible_i0p_i0p(&(pThis->m_pMenuBar->m_oBase_CAwsContainer.m_oBase_CAwsWindow),0,bIsRedraw);

		if(ESP_NULL!=pThis->m_pCurMainContainer){
		{
			// 移动MainContainer
			CAwsWindow_MoveTo_CEspRect1p_i0p(&(pThis->m_pCurMainContainer->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),CMUi_GetClientRect(pThis),bIsRedraw);
		}}
	}}
	else if(!bIsHide&&pThis->m_bIsHideMenuBar){
	{
		pThis->m_bIsHideMenuBar=0;

		if(ESP_NULL!=pThis->m_pCurMainContainer){
		{
			// 移动MainContainer
			CAwsWindow_MoveTo_CEspRect1p_i0p(&(pThis->m_pCurMainContainer->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),CMUi_GetClientRect(pThis),bIsRedraw);
		}}
		CAwsWindow_SetVisible_i0p_i0p(&(pThis->m_pMenuBar->m_oBase_CAwsContainer.m_oBase_CAwsWindow),1,bIsRedraw);
	}}
}

void CMUi_HideTitleBar_i0p_i0p(CMUi* pThis, int bIsHide,int bIsRedraw)
{
	CEspSize size;

	CEspSize_CInit_i0p_i0p(&(size),0,0);
if(bIsHide){
	{
		pThis->m_bIsHideTitleBar=1;
		CAwsWindow_SetVisible_i0p_i0p(&(pThis->m_pTitleBar->m_oBase_CAwsWindow),0,bIsRedraw);

		if(ESP_NULL!=pThis->m_pCurMainContainer){
		{
			// 移动MainContainer
			CAwsWindow_MoveTo_CEspRect1p_i0p(&(pThis->m_pCurMainContainer->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),CMUi_GetClientRect(pThis),bIsRedraw);
		}}
	}}
	else if(!bIsHide){
	{
		pThis->m_bIsHideTitleBar=0;

		CAwsWindow_SetVisible_i0p_i0p(&(pThis->m_pTitleBar->m_oBase_CAwsWindow),1,0);
		if(ESP_NULL!=pThis->m_pCurMainContainer){
		{
			// 移动MainContainer
			CAwsWindow_MoveTo_CEspRect1p_i0p(&(pThis->m_pCurMainContainer->m_oBase_CBMenuContainer.m_oBase_CAwsContainer.m_oBase_CAwsWindow),CMUi_GetClientRect(pThis),bIsRedraw);
		}}

		if(bIsRedraw){
			CAwsWindow_Invalide(&(pThis->m_pTitleBar->m_oBase_CAwsWindow));}
	}}
}

CEspRect * CMUi_GetClientRect(CMUi* pThis)
{
	pThis->m_rtClient.m_ptLT.m_nX=0;
	if(!pThis->m_bIsHideTitleBar){
		pThis->m_rtClient.m_ptLT.m_nY=pThis->m_nTitleBarHeight;}
	else
		{pThis->m_rtClient.m_ptLT.m_nY=0;}

	pThis->m_rtClient.m_ptRB.m_nY=CAwsWindow_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow))->m_nHeight;
	pThis->m_rtClient.m_ptRB.m_nX=CAwsWindow_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow))->m_nWidth;
	if(!pThis->m_bIsHideMenuBar){
		pThis->m_rtClient.m_ptRB.m_nY-=pThis->m_nMenuBarHeight;}

	return &(pThis->m_rtClient);
}

//#include <afx.h>
void CMUi_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CMUi* pThis = (CMUi*)this;{
//	TRACE("MUi draw, X(%d),Y(%d), Width(%d), Height(%d)\n", rect.m_ptLT.m_nX, rect.m_ptLT.m_nY, rect.GetSize()->m_nWidth, rect.GetSize()->m_nHeight);

	CAwsContainer_OnDraw_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),rect);
}
}
