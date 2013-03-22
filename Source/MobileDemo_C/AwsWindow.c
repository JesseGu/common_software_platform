/******************************************************************************
* FileName		       : AwsWindow.cpp
* Description          : implementation of the CAwsWindow class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "AwsWindow.h"

#include "IAwsGc.h"
#include "AwsUi.h"

void CAwsWindow_CInit(CAwsWindow* pThis)
{

CEspRect_CInit(&(pThis->m_tRect));
CEspPoint_CInit_i0p_i0p(&(pThis->m_tOrigin),0,0);
	pThis->m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
{
	pThis->m_pParent=ESP_NULL;
	pThis->m_pGc=ESP_NULL;

	pThis->m_pUi=ESP_NULL;

	pThis->m_bIsVisible=1;
	pThis->m_bIsFocus=0;

	pThis->m_bIsBKTransparent=0;
}
}

// 一般只有主容器有Ui，所以要跳到主容器中
CAwsUi * CAwsWindow_GetUi(CAwsWindow* pThis)
{
	if(ESP_NULL!=pThis->m_pParent){
	{
		return CAwsWindow_GetUi(pThis->m_pParent);
	}}
	else
	{{
		return pThis->m_pUi;
	}}
}

void CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(CAwsWindow* pThis, CAwsWindow *  pParent,const CEspRect * rect,int nID,int bIsVisible)
{
	pThis->m_nWndID=nID;

	pThis->m_pParent=pParent;
	pThis->m_tRect=*rect;

	if(ESP_NULL!=pThis->m_pParent){
	{
		pThis->m_tOrigin=*CAwsWindow_GetOrigin(pThis->m_pParent);
		CEspPoint_Operator_AddEqu_CEspPoint1p(&(pThis->m_tOrigin),&(pThis->m_tRect.m_ptLT));
	}}
	else
	{{
		pThis->m_tOrigin=pThis->m_tRect.m_ptLT;
	}}

	pThis->m_bIsVisible=bIsVisible;

	pThis->m_pVTab->m_pOnCreate(pThis);
}

// 有可能是窗口位置和大小都改变了
void CAwsWindow_MoveTo_CEspRect1p_i0p(CAwsWindow* pThis, const CEspRect * rect,int bIsRedraw)
{
	// 如果是顶层窗口则无法移动了
	if(ESP_NULL!=pThis->m_pParent){
	{
		CEspRect rtOld=pThis->m_tRect;
		pThis->m_tRect=*rect;

		// 通知父窗口刷新该窗口以前的位置
		{CEspSize sizeParent=*CAwsWindow_GetSize(pThis->m_pParent);
		if(rtOld.m_ptRB.m_nX<=sizeParent.m_nWidth&&rtOld.m_ptRB.m_nY<=sizeParent.m_nWidth&&bIsRedraw){
		{
			pThis->m_pParent->m_pVTab->m_pInvalideRect_CEspRect1p(pThis->m_pParent,&(rtOld));
		}}

		pThis->m_tOrigin=*CAwsWindow_GetOrigin(pThis->m_pParent);
		CEspPoint_Operator_AddEqu_CEspPoint1p(&(pThis->m_tOrigin),&(pThis->m_tRect.m_ptLT));

		// 窗口大小改变通知，这时不需要刷新，只是通知子窗口调整自己的位置和大小
		pThis->m_pVTab->m_pOnSize_CEspSize1p_i0p(pThis,&(*CEspRect_GetSize(&(pThis->m_tRect))),0);

		// 刷新自己的新区域
		if(bIsRedraw){
			CAwsWindow_Invalide(pThis);}
	}}}
}

void CAwsWindow_Invalide(CAwsWindow* pThis)
{
	CEspRect rtInvalide;
	CEspRect_CInit(&(rtInvalide));
rtInvalide.m_ptRB.m_nX=pThis->m_tRect.m_ptRB.m_nX-pThis->m_tRect.m_ptLT.m_nX;
	rtInvalide.m_ptRB.m_nY=pThis->m_tRect.m_ptRB.m_nY-pThis->m_tRect.m_ptLT.m_nY;
	pThis->m_pVTab->m_pInvalideRect_CEspRect1p(pThis,&(rtInvalide));
}

void CAwsWindow_InvalideRect_CEspRect1p(CAwsWindow* pThis, const CEspRect * rect)
{
	if(pThis->m_bIsVisible){
	{
		// 如果是透明的则调用父窗口的InvalideRect函数
		if(pThis->m_bIsBKTransparent){
		{
			// 转换成父窗口坐标
			CEspRect rt=*(rect);
			CEspPoint_Operator_AddEqu_CEspPoint1p(&(rt.m_ptLT),&(pThis->m_tRect.m_ptLT));
			CEspPoint_Operator_AddEqu_CEspPoint1p(&(rt.m_ptRB),&(pThis->m_tRect.m_ptLT));
			pThis->m_pParent->m_pVTab->m_pInvalideRect_CEspRect1p(pThis->m_pParent,&(rt));
		}}
		else
		{{
			CAwsWindow_Draw_CEspRect1p(pThis,rect);
		}}
	}}
}

void CAwsWindow_SetVisible_i0p_i0p(CAwsWindow* pThis, int bIsVisible,int bIsReDraw)
{
	// 增加焦点窗口改变

	if(bIsVisible&&!pThis->m_bIsVisible){
	{
		pThis->m_bIsVisible=1;

		// 重新绘制自己
		if(bIsReDraw){
			CAwsWindow_Invalide(pThis);}
	}}
	else if(!bIsVisible&&pThis->m_bIsVisible){
	{
		pThis->m_bIsVisible=0;
		// 通知父窗口绘制
		if(bIsReDraw){
			pThis->m_pParent->m_pVTab->m_pInvalideRect_CEspRect1p(pThis->m_pParent,&(pThis->m_tRect));}
	}}
}

void CAwsWindow_ConvertCoordinate_CEspRect1p(CAwsWindow* pThis, CEspRect * rect)
{
	// 转换为自己的坐标
	CEspPoint_Operator_SubEqu_CEspPoint1p(&(rect->m_ptLT),&(pThis->m_tRect.m_ptLT));
	CEspPoint_Operator_SubEqu_CEspPoint1p(&(rect->m_ptRB),&(pThis->m_tRect.m_ptLT));
}

void CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(CAwsWindow* pThis, int nWndID,int nCmdID,int nParam1,int nParam2)
{
	CAwsUi_CommandRouter_i0p_i0p_i0p_i0p(CAwsWindow_GetUi(pThis),nWndID,nCmdID,nParam1,nParam2);
}

void CAwsWindow_PostCommand_i0p_i0p_i0p_i0p(CAwsWindow* pThis, int nWndID,int nCmdID,int nParam1,int nParam2)
{
	CAwsUi_AddPostCommand_i0p_i0p_i0p_i0p(CAwsWindow_GetUi(pThis),nWndID,nCmdID,nParam1,nParam2);
}

int CAwsWindow_StartTimer_i0p(CAwsWindow* pThis, int nTimer)
{
	return CAwsUi_StartTimer_CAwsWindow1p_i0p(CAwsWindow_GetUi(pThis),pThis,nTimer);
}

void CAwsWindow_EndTimer(CAwsWindow* pThis)
{
	CAwsUi_EndTimer_CAwsWindow1p(CAwsWindow_GetUi(pThis),pThis);
}

void CAwsWindow_OnFocus_i0p(CAwsWindow* pThis, int bIsFocus)
{
	pThis->m_bIsFocus=bIsFocus;
}

IAwsGc * CAwsWindow_GetGc(CAwsWindow* pThis)
{
	// 获取Gc
	IAwsGc *  pGc=ESP_NULL;
	CAwsUi *  pUi=CAwsWindow_GetUi(pThis);
	if(ESP_NULL!=pUi){
	{
		pGc=CAwsUi_GetSysGc(pUi);

		if(ESP_NULL!=pGc){
		{
			CEspPoint pt=*(CAwsWindow_GetOrigin(pThis));
			pGc->m_pVTab->m_pSetOrigin_CEspPoint1p(pGc,&(pt));
		}}
	}}

	return pGc;
}

void CAwsWindow_Draw_CEspRect1p(CAwsWindow* pThis, const CEspRect * rect)
{
	IAwsGc *  pGc=CAwsWindow_GetGc(pThis);
	if(ESP_NULL!=pGc){
	{
		pGc->m_pVTab->m_pSetClipRect_CEspRect1p(pGc,rect);
		pThis->m_pVTab->m_pOnDraw_CEspRect1p(pThis,rect);
		pGc->m_pVTab->m_pResetClipRect(pGc);
	}}
}
