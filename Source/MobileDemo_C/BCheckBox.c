/******************************************************************************
* FileName		       : BCheckBox.cpp
* Description          : implementation of the CBCheckBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BCheckBox.h"
const VTab_CBImageButton g_tVTab_CBCheckBox_CBImageButton = {CBCheckBox_DrawIcon_IAwsGc1p_CEspRect1p};
const VTab_CBButton g_tVTab_CBCheckBox_CBButton = {CBButton_DrawBK_IAwsGc1p_CEspRect1p, CBImageButton_DrawInf_IAwsGc1p_CEspRect1p, CBButton_DrawText_IAwsGc1p_CEspRect1p, CBCheckBox_OnClick};
const VTab_CAwsWindow g_tVTab_CBCheckBox_CAwsWindow = {CBCheckBox_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CBButton_OnDraw_CEspRect1p, CBButton_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CBButton_OnFocus_i0p, CAwsWindow_OnTimer, CAwsWindow_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CAwsWindow_OnCreate};
void CBCheckBox_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CBCheckBox* pThis=(CBCheckBox*)this;
	pThis->m_oBase_CBImageButton.m_pVTab = &g_tVTab_CBImageButton_CBImageButton;
	pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_pVTab = &g_tVTab_CBButton_CBButton;
	pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CBImageButton_DUninit_i1p(&(pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBCheckBox*)0)->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow));
}

void CBCheckBox_SetSelectColor_CAwsRgb1p(CBCheckBox* pThis, const CAwsRgb * color) { pThis->m_oSelectColor=*color; } 

void CBCheckBox_SetBKColor_CAwsRgb1p(CBCheckBox* pThis, const CAwsRgb * color) { pThis->m_oBKColor=*color; } 

void CBCheckBox_SetFocusBorderColor_CAwsRgb1p(CBCheckBox* pThis, const CAwsRgb * color) { pThis->m_oFocusBorderColor=*color; } 

void CBCheckBox_SetBorderColor_CAwsRgb1p(CBCheckBox* pThis, const CAwsRgb * color) { pThis->m_oBorderColor=*color; } 

int CBCheckBox_IsSelected(CBCheckBox* pThis) { return pThis->m_bIsSelect; } 

const VTab_CBImageButton g_tVTab_CBImageButton_CBImageButton = {CBImageButton_DrawIcon_IAwsGc1p_CEspRect1p};
const VTab_CBButton g_tVTab_CBImageButton_CBButton = {CBButton_DrawBK_IAwsGc1p_CEspRect1p, CBImageButton_DrawInf_IAwsGc1p_CEspRect1p, CBButton_DrawText_IAwsGc1p_CEspRect1p, CBButton_OnClick};
const VTab_CAwsWindow g_tVTab_CBImageButton_CAwsWindow = {CBImageButton_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CBButton_OnDraw_CEspRect1p, CBButton_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CBButton_OnFocus_i0p, CAwsWindow_OnTimer, CAwsWindow_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CAwsWindow_OnCreate};
void CBImageButton_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CBImageButton* pThis=(CBImageButton*)this;
	pThis->m_oBase_CBButton.m_pVTab = &g_tVTab_CBButton_CBButton;
	pThis->m_oBase_CBButton.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CBButton_DUninit_i1p(&(pThis->m_oBase_CBButton.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBImageButton*)0)->m_oBase_CBButton.m_oBase_CAwsWindow));
}

void CBImageButton_SetIconSize_CEspSize1p(CBImageButton* pThis, const CEspSize * size) { pThis->m_nIconSize=*size; } 

void CBImageButton_SetMode_0p(CBImageButton* pThis, MIB_ShowMode mode) { pThis->m_eMode=mode; } 

#include "IAwsGc.h"

void CBCheckBox_CInit(CBCheckBox* pThis)
{

CBImageButton_CInit(&(pThis->m_oBase_CBImageButton));
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oSelectColor),0,0,0);
CAwsImage_CInit(&(pThis->m_oImage));
CAwsImage_CInit(&(pThis->m_oImageFocus));
CAwsImage_CInit(&(pThis->m_oImageSel));
CAwsImage_CInit(&(pThis->m_oImageSelFocus));
CAwsImage_CInit(&(pThis->m_oImageMask));
	pThis->m_oBase_CBImageButton.m_pVTab = &g_tVTab_CBCheckBox_CBImageButton;
	pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_pVTab = &g_tVTab_CBCheckBox_CBButton;
	pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBCheckBox_CAwsWindow;
{
	pThis->m_bIsSelect=0;

	pThis->m_oBase_CBImageButton.m_nIconSize.m_nHeight=12;
	pThis->m_oBase_CBImageButton.m_nIconSize.m_nWidth=12;

	{CAwsRgb rgbBorder,rgbFocus,rgbBK,rgbSelect;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbBorder,89,104,160);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbFocus,255,108,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbSelect,0,0,0);
pThis->m_oBorderColor=rgbBorder;
	pThis->m_oFocusBorderColor=rgbFocus;
	pThis->m_oBKColor=rgbBK;
	pThis->m_oSelectColor=rgbSelect;

	pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow.m_bIsBKTransparent=1;

	pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oTextFocusColor=pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oTextColor;
}}
}

void CBCheckBox_SetSelected_i0p(CBCheckBox* pThis, int bIsSelect)
{ 
	int b=pThis->m_bIsSelect;
	pThis->m_bIsSelect=bIsSelect;

	if(b!=pThis->m_bIsSelect){
		CAwsWindow_Invalide(&(pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow));}
}

void CBCheckBox_SetImage_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p(CBCheckBox* pThis, const CAwsImage * image,const CAwsImage * imageFocus,const CAwsImage * imageSel,const CAwsImage * imageSelFocus,const CAwsImage * imageMask)
{
	pThis->m_oImage=*image;
	pThis->m_oImageFocus=*imageFocus;
	pThis->m_oImageSel=*imageSel;
	pThis->m_oImageSelFocus=*imageSelFocus;
	pThis->m_oImageMask=*imageMask;
}

void CBCheckBox_DrawIcon_IAwsGc1p_CEspRect1p(CBImageButton* this, IAwsGc *  pGc,const CEspRect * rect)
{

	CBCheckBox* pThis = (CBCheckBox*)this;{
	CEspRect rt=*(rect);

	if(CAwsImage_GetID(&(pThis->m_oImage))>0){
	{
		// ÌùÍ¼
		if(pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow.m_bIsFocus){
		{
			if(pThis->m_bIsSelect){
				pGc->m_pVTab->m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(pGc,&(rect->m_ptLT),&(pThis->m_oImageSelFocus),&pThis->m_oImageMask);}
			else
				{pGc->m_pVTab->m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(pGc,&(rect->m_ptLT),&(pThis->m_oImageFocus),&pThis->m_oImageMask);}
		}}
		else
		{{
			if(pThis->m_bIsSelect){
				pGc->m_pVTab->m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(pGc,&(rect->m_ptLT),&(pThis->m_oImageSel),&pThis->m_oImageMask);}
			else
				{pGc->m_pVTab->m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(pGc,&(rect->m_ptLT),&(pThis->m_oImage),&pThis->m_oImageMask);}
		}}
	}}
	else
	{{
		// »­Í¼±ê
		if(pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow.m_bIsFocus){
		{
			pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oFocusBorderColor));
		}}
		else
		{{
			pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBorderColor));
		}}
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
		pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,&(rt));

		if(pThis->m_bIsSelect){
		{
			pGc->m_pVTab->m_pSetPenWidth_i0p(pGc,2);
			pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oSelectColor));

			{CEspPoint ptStart,ptEnd;
			CEspPoint_CInit_i0p_i0p(&(ptStart),0,0);
CEspPoint_CInit_i0p_i0p(&(ptEnd),0,0);
ptStart.m_nX=rt.m_ptLT.m_nX+2;
			ptStart.m_nY=rt.m_ptLT.m_nY+2;
			ptEnd.m_nX=rt.m_ptRB.m_nX-2;
			ptEnd.m_nY=rt.m_ptRB.m_nY-2;
			pGc->m_pVTab->m_pDrawLine_CEspPoint1p_CEspPoint1p(pGc,&(ptStart),&(ptEnd));

			ptStart.m_nX=rt.m_ptLT.m_nX+2;
			ptStart.m_nY=rt.m_ptRB.m_nY-2;
			ptEnd.m_nX=rt.m_ptRB.m_nX-2;
			ptEnd.m_nY=rt.m_ptLT.m_nY+2;
			pGc->m_pVTab->m_pDrawLine_CEspPoint1p_CEspPoint1p(pGc,&(ptStart),&(ptEnd));

			pGc->m_pVTab->m_pSetPenWidth_i0p(pGc,1);
		}}}
	}}
}
}

void CBCheckBox_OnClick(CBButton* this)
{

	CBCheckBox* pThis = (CBCheckBox*)this;{
	pThis->m_bIsSelect=!pThis->m_bIsSelect;
	CAwsWindow_Invalide(&(pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow));

	CBButton_OnClick(&(pThis->m_oBase_CBImageButton.m_oBase_CBButton));
}
}
