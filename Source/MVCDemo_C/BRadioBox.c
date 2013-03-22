/******************************************************************************
* FileName		       : BRadioBox.cpp
* Description          : implementation of the CBRadioBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BRadioBox.h"
const VTab_CBImageButton g_tVTab_CBRadioBox_CBImageButton = {CBRadioBox_DrawIcon_IAwsGc1p_CEspRect1p};
const VTab_CBButton g_tVTab_CBRadioBox_CBButton = {CBButton_DrawBK_IAwsGc1p_CEspRect1p, CBImageButton_DrawInf_IAwsGc1p_CEspRect1p, CBButton_DrawText_IAwsGc1p_CEspRect1p, CBRadioBox_OnClick};
const VTab_CAwsWindow g_tVTab_CBRadioBox_CAwsWindow = {CBRadioBox_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CBButton_OnDraw_CEspRect1p, CBButton_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CBButton_OnFocus_i0p, CAwsWindow_OnTimer, CAwsWindow_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CAwsWindow_OnCreate};
void CBRadioBox_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CBRadioBox* pThis=(CBRadioBox*)this;
	pThis->m_oBase_CBImageButton.m_pVTab = &g_tVTab_CBImageButton_CBImageButton;
	pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_pVTab = &g_tVTab_CBButton_CBButton;
	pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CBImageButton_DUninit_i1p(&(pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBRadioBox*)0)->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow));
}

void CBRadioBox_SetSelectColor_CAwsRgb1p(CBRadioBox* pThis, CAwsRgb * color) { pThis->m_oSelectColor=*color; } 

void CBRadioBox_SetBKColor_CAwsRgb1p(CBRadioBox* pThis, CAwsRgb * color) { pThis->m_oBKColor=*color; } 

void CBRadioBox_SetFocusBorderColor_CAwsRgb1p(CBRadioBox* pThis, CAwsRgb * color) { pThis->m_oFocusBorderColor=*color; } 

void CBRadioBox_SetBorderColor_CAwsRgb1p(CBRadioBox* pThis, CAwsRgb * color) { pThis->m_oBorderColor=*color; } 

int CBRadioBox_IsSelected(CBRadioBox* pThis) { return pThis->m_bIsSelect; } 

#include "IAwsGc.h"

void CBRadioBox_CInit(CBRadioBox* pThis)
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
	pThis->m_oBase_CBImageButton.m_pVTab = &g_tVTab_CBRadioBox_CBImageButton;
	pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_pVTab = &g_tVTab_CBRadioBox_CBButton;
	pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBRadioBox_CAwsWindow;
{
	pThis->m_bIsSelect=0;

	pThis->m_oBase_CBImageButton.m_nIconSize.m_nHeight=12;
	pThis->m_oBase_CBImageButton.m_nIconSize.m_nWidth=12;
	pThis->m_nSelectDim=4;

	{CAwsRgb rgbBorder,rgbFocusBorder,rgbBK,rgbSelect;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbBorder,89,104,160);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbFocusBorder,241,108,13);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbSelect,83,106,147);
pThis->m_oBorderColor=rgbBorder;
	pThis->m_oFocusBorderColor=rgbFocusBorder;
	pThis->m_oBKColor=rgbBK;
	pThis->m_oSelectColor=rgbSelect;

	pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow.m_bIsBKTransparent=1;

	pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oTextFocusColor=pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oTextColor;
}}
}

void CBRadioBox_SetSelected_i0p(CBRadioBox* pThis, int bIsSelect)
{ 
	int b=pThis->m_bIsSelect;
	pThis->m_bIsSelect=bIsSelect;

	if(b!=pThis->m_bIsSelect){
		CAwsWindow_Invalide(&(pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow));}
}

void CBRadioBox_SetImage_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p(CBRadioBox* pThis, const CAwsImage * image,const CAwsImage * imageFocus,const CAwsImage * imageSel,const CAwsImage * imageSelFocus,const CAwsImage * imageMask)
{
	pThis->m_oImage=*image;
	pThis->m_oImageFocus=*imageFocus;
	pThis->m_oImageSel=*imageSel;
	pThis->m_oImageSelFocus=*imageSelFocus;
	pThis->m_oImageMask=*imageMask;
}

void CBRadioBox_DrawIcon_IAwsGc1p_CEspRect1p(CBImageButton* this, IAwsGc *  pGc,const CEspRect * rect)
{

	CBRadioBox* pThis = (CBRadioBox*)this;{
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
		pGc->m_pVTab->m_pDrawEllipse_CEspRect1p(pGc,&(rt));

		if(pThis->m_bIsSelect){
		{
			rt.m_ptLT.m_nX+=(pThis->m_oBase_CBImageButton.m_nIconSize.m_nWidth-pThis->m_nSelectDim)/2;
			rt.m_ptLT.m_nY+=(pThis->m_oBase_CBImageButton.m_nIconSize.m_nHeight-pThis->m_nSelectDim)/2;
			rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nSelectDim;
			rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nSelectDim;

			pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oSelectColor));
			pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oSelectColor));
			pGc->m_pVTab->m_pDrawEllipse_CEspRect1p(pGc,&(rt));
		}}
	}}
}
}

void CBRadioBox_OnClick(CBButton* this)
{

	CBRadioBox* pThis = (CBRadioBox*)this;{
	if(!pThis->m_bIsSelect){
	{
		pThis->m_bIsSelect=1;
		CAwsWindow_Invalide(&(pThis->m_oBase_CBImageButton.m_oBase_CBButton.m_oBase_CAwsWindow));
	}}

	CBButton_OnClick(&(pThis->m_oBase_CBImageButton.m_oBase_CBButton));
}
}
