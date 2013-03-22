/******************************************************************************
* FileName		       : AwsUi.cpp
* Description          : implementation of the CAwsUi class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "AwsUi.h"
#include "IAwsGc.h"
#include "AwsContainer.h"
#include "SpxApp.h"

void CAwsUi_CInit_i0p(CAwsUi* pThis, int nMaxTopWndCount)
{

CEspSize_CInit_i0p_i0p(&(pThis->m_tScreenSize),0,0);
	pThis->m_pVTab = &g_tVTab_CAwsUi_CAwsUi;
{
	pThis->m_pCurTopWnd=ESP_NULL;
	pThis->m_nCurTopWndCount=0;
	pThis->m_nMaxTopWndCount=nMaxTopWndCount;

	if(pThis->m_nMaxTopWndCount>0){
		pThis->m_pTopWndData=(CAwsWindow * (*))malloc(sizeof(CAwsWindow * )*pThis->m_nMaxTopWndCount);}
	else
		{pThis->m_pTopWndData=ESP_NULL;}

	pThis->m_pSysGc=ESP_NULL;

	pThis->m_nCommandCount=0;

	{int i;
	for(i=0;i<MAX_TIMERDATA;++i){
	{
		pThis->m_tTimerData[i].m_pWnd=ESP_NULL;
	}}

	pThis->m_pApp=ESP_NULL;
}}
}

void CAwsUi_DUninit_i1p(CAwsUi* pThis, int * pOffset)
{
	int i;
	for(i=0;i<pThis->m_nCurTopWndCount;++i){
	{
		{int nOffset = 0;(pThis->m_pTopWndData[i])->m_pVTab->m_pDUninit_i1p(pThis->m_pTopWndData[i], &nOffset);free((void*)((int)(pThis->m_pTopWndData[i]) - nOffset));};
	}}

	free(pThis->m_pTopWndData);;
}

int CAwsUi_StartTimer_CAwsWindow1p_i0p(CAwsUi* pThis, CAwsWindow *  pWnd,int nTimes)
{
	int bRet=0;

	if(ESP_NULL!=pWnd){
	{
		int i;
		for(i=0;i<MAX_TIMERDATA;++i){
		{
			if(ESP_NULL==pThis->m_tTimerData[i].m_pWnd){
			{
				pThis->m_tTimerData[i].m_pWnd=pWnd;
				pThis->m_tTimerData[i].m_nTime=nTimes;

				// 启动定时器
				pThis->m_pVTab->m_pTimer_i0p_i0p(pThis,i,nTimes);
				bRet=1;
				break;
			}}
		}}
	}}

	return bRet;
}

void CAwsUi_EndTimer_CAwsWindow1p(CAwsUi* pThis, CAwsWindow *  pWnd)
{
	int i;
	for(i=0;i<MAX_TIMERDATA;++i){
	{
		if(pWnd==pThis->m_tTimerData[i].m_pWnd){
		{
			// 停止定时器
			pThis->m_pVTab->m_pKillTimer_i0p(pThis,i);

			pThis->m_tTimerData[i].m_pWnd=ESP_NULL;
			break;
		}}
	}}
}

void CAwsUi_OnDraw_CEspRect1p(CAwsUi* pThis, const CEspRect * rect)
{
	if(ESP_NULL!=pThis->m_pCurTopWnd){
		CAwsWindow_Draw_CEspRect1p(pThis->m_pCurTopWnd,rect);}

	CAwsUi_PostCommandRouter(pThis);
}

void CAwsUi_OnKey_0p_0p(CAwsUi* pThis, AWS_KeyType type,AWS_KeyCode code)
{
	// 调用当前顶层窗口的按键响应函数
	if(ESP_NULL!=pThis->m_pCurTopWnd){
		pThis->m_pCurTopWnd->m_pVTab->m_pOnKey_0p_0p(pThis->m_pCurTopWnd,type,code);}

	CAwsUi_PostCommandRouter(pThis);
}

void CAwsUi_OnSize_CEspSize1p_i0p(CAwsUi* pThis, const CEspSize * size,int bIsRedraw)
{
	pThis->m_tScreenSize=*size;

	if(ESP_NULL!=pThis->m_pCurTopWnd){
		pThis->m_pCurTopWnd->m_pVTab->m_pOnSize_CEspSize1p_i0p(pThis->m_pCurTopWnd,size,bIsRedraw);}

	CAwsUi_PostCommandRouter(pThis);
}

void CAwsUi_OnFocus_i0p(CAwsUi* pThis, int bIsFocus)
{
	if(ESP_NULL!=pThis->m_pCurTopWnd){
		pThis->m_pCurTopWnd->m_pVTab->m_pOnFocus_i0p(pThis->m_pCurTopWnd,bIsFocus);}

	CAwsUi_PostCommandRouter(pThis);
}

void CAwsUi_OnTimer_i0p(CAwsUi* pThis, int nTimerID)
{
	int i;
	for(i=0;i<MAX_TIMERDATA;++i){
	{
		if(i==nTimerID){
		{
			if(ESP_NULL!=pThis->m_tTimerData[i].m_pWnd){
				pThis->m_tTimerData[i].m_pWnd->m_pVTab->m_pOnTimer(pThis->m_tTimerData[i].m_pWnd);}
			break;
		}}
	}}

	CAwsUi_PostCommandRouter(pThis);
}

void CAwsUi_OnImeChar_s0p(CAwsUi* pThis, short nChar)
{
	if(ESP_NULL!=pThis->m_pCurTopWnd){
		pThis->m_pCurTopWnd->m_pVTab->m_pOnImeChar_s0p(pThis->m_pCurTopWnd,nChar);}

	CAwsUi_PostCommandRouter(pThis);
}

void CAwsUi_Init_CEspSize1p(CAwsUi* pThis, const CEspSize * sizeScreen)
{
	pThis->m_tScreenSize=*sizeScreen;
}

int CAwsUi_AddWndToStack_CAwsWindow1p(CAwsUi* pThis, CAwsWindow *  pWnd)
{
	int bRet=1;

	if(ESP_NULL!=pWnd&&pThis->m_nCurTopWndCount<pThis->m_nMaxTopWndCount){
		pThis->m_pTopWndData[pThis->m_nCurTopWndCount++]=pWnd;}
	else
		{bRet=0;}

	return bRet;
}

void CAwsUi_RemoveWndFromStack_CAwsWindow1p(CAwsUi* pThis, CAwsWindow *  pWnd)
{
	if(ESP_NULL!=pWnd){
	{
		int i;
		for(i=0;i<pThis->m_nCurTopWndCount;++i){
		{
			if(pThis->m_pTopWndData[i]==pWnd){
			{
				{int nOffset = 0;(pWnd)->m_pVTab->m_pDUninit_i1p(pWnd, &nOffset);free((void*)((int)(pWnd) - nOffset));};
				{int j;
				for(j=i;j<pThis->m_nCurTopWndCount-1;++j){
					pThis->m_pTopWndData[j]=pThis->m_pTopWndData[j+1];}
				--pThis->m_nCurTopWndCount;
				break;
			}}}
		}}
	}}
}

void CAwsUi_RemoveWndFromTopStack(CAwsUi* pThis)
{
	if(pThis->m_nCurTopWndCount>0){
	{
		--pThis->m_nCurTopWndCount;
		{int nOffset = 0;(pThis->m_pTopWndData[pThis->m_nCurTopWndCount])->m_pVTab->m_pDUninit_i1p(pThis->m_pTopWndData[pThis->m_nCurTopWndCount], &nOffset);free((void*)((int)(pThis->m_pTopWndData[pThis->m_nCurTopWndCount]) - nOffset));};
	}}
}

void CAwsUi_SetTopWnd_CAwsContainer1p(CAwsUi* pThis, CAwsContainer *  pWnd)
{
	if(ESP_NULL!=pWnd){
	{
		// 以前的顶层窗口失去焦点
		if(ESP_NULL!=pThis->m_pCurTopWnd){
			pThis->m_pCurTopWnd->m_pVTab->m_pOnFocus_i0p(pThis->m_pCurTopWnd,0);}

		pThis->m_pCurTopWnd=&(pWnd->m_oBase_CAwsWindow);

		// 激活新的顶层窗口
		pThis->m_pCurTopWnd->m_pVTab->m_pOnFocus_i0p(pThis->m_pCurTopWnd,1);
	}}
}

int CAwsUi_AddPostCommand_i0p_i0p_i0p_i0p(CAwsUi* pThis, int nWndID,int nCmdID,int nParam1,int nParam2)
{
	int bRet=1;
	// 将Post的Command放入队列中存起来
	if(pThis->m_nCommandCount<MAX_POSTCOMMAND){
	{
		pThis->m_tPostCommands[pThis->m_nCommandCount].m_nWndID=nWndID;
		pThis->m_tPostCommands[pThis->m_nCommandCount].m_nCmdID=nCmdID;
		pThis->m_tPostCommands[pThis->m_nCommandCount].m_nParam1=nParam1;
		pThis->m_tPostCommands[pThis->m_nCommandCount].m_nParam2=nParam2;

		++pThis->m_nCommandCount;
	}}
	else
	{{
		bRet=0;
	}}

	return bRet;
}

void CAwsUi_ClearWnd_CAwsWindow1p(CAwsUi* pThis, CAwsWindow *  pWnd)
{
	if(ESP_NULL!=pWnd){
	{
		CAwsWindow *  pFatherWnd=CAwsWindow_GetParent(pWnd);
		if(ESP_NULL==pFatherWnd){
		{
			// 是顶层窗口，则将其
			CAwsUi_RemoveWndFromStack_CAwsWindow1p(pThis,pWnd);
		}}
		else
		{{
			// 直接删除了
			{int nOffset = 0;(pWnd)->m_pVTab->m_pDUninit_i1p(pWnd, &nOffset);free((void*)((int)(pWnd) - nOffset));};
		}}
	}}
}

void CAwsUi_PostCommandRouter(CAwsUi* pThis)
{
	int i,nCommand=pThis->m_nCommandCount;

	// 注意在实行命令期间可能还会继续有命令的Post进来，这里要一并处理
	for(i=0;i<nCommand;++i){
	{
		if(AWS_SysCmd_DeleteWnd==pThis->m_tPostCommands[i].m_nCmdID){
		{
			// 清除窗口
			CAwsUi_ClearWnd_CAwsWindow1p(pThis,(CAwsWindow*)pThis->m_tPostCommands[i].m_nParam1);
		}}
		else
		{{
			CAwsUi_CommandRouter_i0p_i0p_i0p_i0p(pThis,pThis->m_tPostCommands[i].m_nWndID,pThis->m_tPostCommands[i].m_nCmdID,pThis->m_tPostCommands[i].m_nParam1,pThis->m_tPostCommands[i].m_nParam2);
		}}
	}}

	if(pThis->m_nCommandCount>nCommand){
	{
		// 说明在执行命令期间又有新的命令发送进来了
		pThis->m_nCommandCount-=nCommand;
		for(i=0;i<pThis->m_nCommandCount;++i){
			pThis->m_tPostCommands[i]=pThis->m_tPostCommands[i+nCommand];}

		// 继续执行命令
		CAwsUi_PostCommandRouter(pThis);
	}}
	else
	{{
		pThis->m_nCommandCount=0;
	}}
}

// 命令路由，首先传递给应用程序类，然后传递给焦点窗口，如果某个地方处理了该消息，则就不再传递了
void CAwsUi_CommandRouter_i0p_i0p_i0p_i0p(CAwsUi* pThis, int nWndID,int nCmdID,int nParam1,int nParam2)
{
	int bIsProcessed=0;

	if(ESP_NULL!=pThis->m_pApp){
		bIsProcessed=CSpxApp_OnCommand_i0p_i0p_i0p_i0p(pThis->m_pApp,nWndID,nCmdID,nParam1,nParam2);}

	if(!bIsProcessed&&ESP_NULL!=pThis->m_pCurTopWnd){
	{
		CAwsWindow *  pWnd=pThis->m_pCurTopWnd;
		while(ESP_NULL!=pWnd&&!pWnd->m_pVTab->m_pOnCommand_i0p_i0p_i0p_i0p(pWnd,nWndID,nCmdID,nParam1,nParam2)){
			pWnd=pWnd->m_pVTab->m_pGetFocusSubWnd(pWnd);}
	}}
}
