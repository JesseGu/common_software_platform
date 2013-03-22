/******************************************************************************
* FileName		       : SpxAPP.cpp
* Description          : implementation of the CSpxAPP class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "SpxApp.h"
const VTab_CSpxApp g_tVTab_CSpxApp_CSpxApp = {CSpxApp_DUninit_i1p, CSpxApp_OnInit_CEspSize1p};
void CSpxApp_OnInit_CEspSize1p(CSpxApp* pThis, const CEspSize * sizeScreen) { } 

COs * CSpxApp_GetOs_COs1p(CSpxApp* pThis, COs *  pOs) { return pThis->m_pOs; } 

CAwsUi * CSpxApp_GetUi_CAwsUi1p(CSpxApp* pThis, CAwsUi *  pUi) { return pThis->m_pUi; } 

const VTab_CAwsUi g_tVTab_CAwsUi_CAwsUi = {CAwsUi_DUninit_i1p, CAwsUi_ActiveIME, CAwsUi_InactiveIME, CAwsUi_ExitSys, CAwsUi_Timer_i0p_i0p, CAwsUi_KillTimer_i0p};
void CAwsUi_KillTimer_i0p(CAwsUi* pThis, int nTimerID) { } 

void CAwsUi_Timer_i0p_i0p(CAwsUi* pThis, int nTimerID,int nTime) { } 

void CAwsUi_ExitSys(CAwsUi* pThis) { } 

void CAwsUi_InactiveIME(CAwsUi* pThis) { } 

void CAwsUi_ActiveIME(CAwsUi* pThis) { } 

CAwsWindow * CAwsUi_GetCurTopWnd(CAwsUi* pThis) { return pThis->m_pCurTopWnd; } 

IAwsGc * CAwsUi_GetSysGc(CAwsUi* pThis) { return pThis->m_pSysGc; } 

void CAwsUi_SetSysGc_IAwsGc1p(CAwsUi* pThis, IAwsGc *  pGc) { pThis->m_pSysGc=pGc; } 

CEspSize * CAwsUi_GetScreenSize(CAwsUi* pThis) { return &(pThis->m_tScreenSize); } 

CSpxApp * CAwsUi_GetApp(CAwsUi* pThis) { return pThis->m_pApp; } 

void CAwsUi_SetApp_CSpxApp1p(CAwsUi* pThis, CSpxApp *  pApp) { pThis->m_pApp=pApp; } 

int CAwsImage_GetID(const CAwsImage* pThis)  { return pThis->m_nImageID; } 

void CAwsImage_LoadImage_i0p(CAwsImage* pThis, int nID) { pThis->m_nImageID=nID; } 

void CAwsImage_CInit(CAwsImage* pThis) { pThis->m_nImageID=0; } 

int CAwsFont_GetFontWeight(const CAwsFont* pThis)  { return pThis->m_nFontWeight; } 

int CAwsFont_GetFontSize(const CAwsFont* pThis)  { return pThis->m_nFontSize; } 

int CAwsFont_GetFontID(const CAwsFont* pThis)  { return pThis->m_nFontID; } 

void CAwsFont_CreateFont_i0p_i0p_i0p(CAwsFont* pThis, int nID,int nSize,int nWeight) { pThis->m_nFontID=nID; pThis->m_nFontSize=nSize; pThis->m_nFontWeight=nWeight; } 

void CAwsRgb_CInit_i0p_i0p_i0p(CAwsRgb* pThis, int nRed,int nGreen,int nBlue) { pThis->m_nValue=((unsigned int)(((unsigned char)(nRed)|((unsigned short)((unsigned char)(nGreen))<<8))|(((unsigned int)(unsigned char)(nBlue))<<16))); } 

#include "SpxController.h"
const VTab_CSpxController g_tVTab_CSpxController_CSpxController = {CSpxController_DUninit_i1p, CSpxController_OnRegisterObserver_ISpxObserver1p, CSpxController_OnUnregisterObserver_ISpxObserver1p, CSpxController_OnMessage_i0p_i0p_i0p_i0p};
int CSpxController_OnMessage_i0p_i0p_i0p_i0p(CSpxController* pThis, int nWndID,int nCmdID,int nParam1,int nParam2) { return 0; } 

int CSpxController_OnUnregisterObserver_ISpxObserver1p(CSpxController* pThis, ISpxObserver *  pObserver) { return 0; } 

int CSpxController_OnRegisterObserver_ISpxObserver1p(CSpxController* pThis, ISpxObserver *  pObserver) { return 0; } 

#include "Os.h"

void CSpxApp_CInit_i0p(CSpxApp* pThis, int nMaxControllerCount)
{

	pThis->m_pVTab = &g_tVTab_CSpxApp_CSpxApp;
{
	pThis->m_nMaxControllerCount=nMaxControllerCount;
	if(pThis->m_nMaxControllerCount>0){
		pThis->m_ppController=(CSpxController * (*))malloc(sizeof(CSpxController * )*pThis->m_nMaxControllerCount);}
	else
		{pThis->m_ppController=ESP_NULL;}

	pThis->m_nControllerCount=0;

	pThis->m_pUi=ESP_NULL;
	pThis->m_pOs=ESP_NULL;
}
}

void CSpxApp_DUninit_i1p(CSpxApp* pThis, int * pOffset)
{
	int i;
	for(i=0;i<pThis->m_nControllerCount;++i){
		{int nOffset = 0;(pThis->m_ppController[i])->m_pVTab->m_pDUninit_i1p(pThis->m_ppController[i], &nOffset);free((void*)((int)(pThis->m_ppController[i]) - nOffset));};}

	free(pThis->m_ppController);;
}

void CSpxApp_Init_CAwsUi1p_COs1p(CSpxApp* pThis, CAwsUi *  pUi,COs *  pOs)
{
	pThis->m_pUi=pUi;
	pThis->m_pOs=pOs;

	CAwsUi_SetApp_CSpxApp1p(pThis->m_pUi,pThis);
	pThis->m_pOs->m_pVTab->m_pInitOs(pThis->m_pOs);

	pThis->m_pVTab->m_pOnInit_CEspSize1p(pThis,CAwsUi_GetScreenSize(pThis->m_pUi));
}

// 将消息分派给每个控制器处理
int CSpxApp_OnCommand_i0p_i0p_i0p_i0p(CSpxApp* pThis, int nWndID,int nCmdID,int nParam1,int nParam2)
{
	int bRet=0;
	int i;

	for(i=0;i<pThis->m_nControllerCount;++i){
	{
		if(bRet=CSpxController_OnCommand_i0p_i0p_i0p_i0p(pThis->m_ppController[i],nWndID,nCmdID,nParam1,nParam2)){
			break;}
	}}

	return bRet;
}

int CSpxApp_AddController_CSpxController1p(CSpxApp* pThis, CSpxController *  pController)
{
	int bRet=1;

	if(ESP_NULL!=pController&&pThis->m_nControllerCount<pThis->m_nMaxControllerCount){
		pThis->m_ppController[pThis->m_nControllerCount++]=pController;}
	else
		{bRet=0;}

	return bRet;
}

void CSpxApp_RemoveController_CSpxController1p(CSpxApp* pThis, CSpxController *  pController)
{
	if(ESP_NULL!=pController){
	{
		int i,j;
		for(i=0;i<pThis->m_nControllerCount;++i){
		{
			if(pController==pThis->m_ppController[i]){
			{
				for(j=i;j<pThis->m_nControllerCount-1;++j){
					pThis->m_ppController[j]=pThis->m_ppController[j+1];}

				--pThis->m_nControllerCount;
				break;
			}}
		}}
	}}
}
