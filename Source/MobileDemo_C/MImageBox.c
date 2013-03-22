/******************************************************************************
* FileName		       : MImageBox.cpp
* Description          : implementation of the CMImageBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "MImageBox.h"
#include "IAwsGc.h"

const VTab_CAwsWindow g_tVTab_CMImageBox_CAwsWindow = {CMImageBox_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CMImageBox_OnDraw_CEspRect1p, CAwsWindow_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CAwsWindow_OnFocus_i0p, CAwsWindow_OnTimer, CAwsWindow_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CAwsWindow_OnCreate};
void CMImageBox_CInit(CMImageBox* pThis)
{
CAwsWindow_CInit(&(pThis->m_oBase_CAwsWindow));
CAwsImage_CInit(&(pThis->m_oImage));
CAwsImage_CInit(&(pThis->m_oImageMask));
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CMImageBox_CAwsWindow;
}

void CMImageBox_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CMImageBox* pThis=(CMImageBox*)this;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsWindow_DUninit_i1p(&(pThis->m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMImageBox*)0)->m_oBase_CAwsWindow));
}

void CMImageBox_ShowImage_CAwsImage1p_CAwsImage1p(CMImageBox* pThis, const CAwsImage * image,const CAwsImage * imageMask)
{
	pThis->m_oImage=*image;
	pThis->m_oImageMask=*imageMask;
	CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));
}

void CMImageBox_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CMImageBox* pThis = (CMImageBox*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsWindow));
	if(CAwsImage_GetID(&(pThis->m_oImage))>0){
	{
		CEspPoint pt;
		CEspPoint_CInit_i0p_i0p(&pt,0,0);
pGc->m_pVTab->m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(pGc,&(pt),&(pThis->m_oImage),&pThis->m_oImageMask);
	}}
}
}
