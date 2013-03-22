/******************************************************************************
* FileName		       : BComboBox.cpp
* Description          : implementation of the CBComboBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BComboBox.h"
const VTab_CBComboBox g_tVTab_CBComboBox_CBComboBox = {CBComboBox_DrawBK_IAwsGc1p_CEspRect1p, CBComboBox_DrawText_IAwsGc1p_CEspRect1p, CBComboBox_DrawIcon_IAwsGc1p_CEspRect1p};
const VTab_CAwsWindow g_tVTab_CBComboBox_CAwsWindow = {CBComboBox_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CBComboBox_OnDraw_CEspRect1p, CBComboBox_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CBComboBox_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CBComboBox_OnCommand_i0p_i0p_i0p_i0p, CBComboBox_OnCreate};
void CBComboBox_CInit(CBComboBox* pThis)
{
CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
CEspSize_CInit_i0p_i0p(&(pThis->m_oIconSize),0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusTextColor),0,0,0);
CAwsImage_CInit(&(pThis->m_oIcon));
CAwsImage_CInit(&(pThis->m_oIconMask));
	pThis->m_pVTab = &g_tVTab_CBComboBox_CBComboBox;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBComboBox_CAwsWindow;
}

void CBComboBox_SetFocusTextColor_CAwsRgb1p(CBComboBox* pThis, const CAwsRgb * color) { pThis->m_oFocusTextColor=*color; } 

void CBComboBox_SetTextColor_CAwsRgb1p(CBComboBox* pThis, const CAwsRgb * color) { pThis->m_oTextColor=*color; } 

void CBComboBox_SetFocusBKColor_CAwsRgb1p(CBComboBox* pThis, const CAwsRgb * color) { pThis->m_oFocusBKColor=*color; } 

void CBComboBox_SetBKColor_CAwsRgb1p(CBComboBox* pThis, const CAwsRgb * color) { pThis->m_oBKColor=*color; } 

void CBComboBox_SetFocusBorderColor_CAwsRgb1p(CBComboBox* pThis, const CAwsRgb * color) { pThis->m_oFocusBorderColor=*color; } 

void CBComboBox_SetBorderColor_CAwsRgb1p(CBComboBox* pThis, const CAwsRgb * color) { pThis->m_oBorderColor=*color; } 

void CBComboBox_SetIconSize_CEspSize1p(CBComboBox* pThis, const CEspSize * size) { pThis->m_oIconSize=*size; } 

void CBComboBox_SetFontSize_i0p(CBComboBox* pThis, int nSize) { pThis->m_nFontSize=nSize; } 

#include "IAwsGc.h"
#include "BMenu.h"
const VTab_CBMenu g_tVTab_CBMenu_CBMenu = {CBMenu_DrawFullBorder_IAwsGc1p_CEspRect1p, CBMenu_DrawTopBorder_IAwsGc1p_CEspRect1p_i0p, CBMenu_DrawBottomBorder_IAwsGc1p_CEspRect1p_i0p, CBMenu_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p_i0p};
const VTab_CAwsWindow g_tVTab_CBMenu_CAwsWindow = {CBMenu_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CBMenu_OnDraw_CEspRect1p, CBMenu_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CBMenu_OnCreate};
void CBMenu_CInit(CBMenu* pThis)
{
CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
CEspSize_CInit_i0p_i0p(&(pThis->m_tSize),0,0);
CEspSize_CInit_i0p_i0p(&(pThis->m_oMaxTextSize),0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oArrowColor),0,0,0);
	pThis->m_pVTab = &g_tVTab_CBMenu_CBMenu;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBMenu_CAwsWindow;
}

void CBMenu_TItemData_CInit(CBMenu_TItemData* pThis)
{
CAwsString_CInit_i0p(&(pThis->m_strText),100);
}

void CBMenu_TItemData_DUninit_i1p(CBMenu_TItemData* pThis, int* pOffset)
{
	CAwsString_DUninit_i1p(&(pThis->m_strText), 0);
}

void CBMenu_SetPopupOnly_i0p(CBMenu* pThis, int bIsPopupOnly) { pThis->m_bIsPopupOnly=bIsPopupOnly; } 

void CBMenu_SetDefaultItemWidth_i0p(CBMenu* pThis, int nWidth) { pThis->m_nMenuWidth=nWidth; } 

void CBMenu_SetDefaultItemHeight_i0p(CBMenu* pThis, int nHeight) { pThis->m_nItemHeight=nHeight; } 

void CBMenu_SetItemRightMargin_i0p(CBMenu* pThis, int nMargin) { pThis->m_nItemRightMargin=nMargin; } 

void CBMenu_SetItemLeftMargin_i0p(CBMenu* pThis, int nMargin) { pThis->m_nItemLeftMargin=nMargin; } 

void CBMenu_SetTBBorderHeight_i0p(CBMenu* pThis, int nHeight) { pThis->m_nTBBorderHeight=nHeight; } 

void CBMenu_SetBorderColor_CAwsRgb1p(CBMenu* pThis, const CAwsRgb * color) { pThis->m_oBorderColor=*color; } 

void CBMenu_SetBKColor_CAwsRgb1p(CBMenu* pThis, const CAwsRgb * color) { pThis->m_oBKColor=*color; } 

void CBMenu_SetFocusBKColor_CAwsRgb1p(CBMenu* pThis, const CAwsRgb * color) { pThis->m_oFocusBKColor=*color; } 

void CBMenu_SetTextColor_CAwsRgb1p(CBMenu* pThis, const CAwsRgb * color) { pThis->m_oTextColor=*color; } 

void CBMenu_SetFocusTextColor_CAwsRgb1p(CBMenu* pThis, const CAwsRgb * color) { pThis->m_oFocusTextColor=*color; } 

const CEspSize * CBMenu_GetMenuSize(CBMenu* pThis) { return &(pThis->m_tSize); } 


void CBComboBox_CInit_i0p(CBComboBox* pThis, int nMaxItemCount)
{

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
CEspSize_CInit_i0p_i0p(&(pThis->m_oIconSize),0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusTextColor),0,0,0);
CAwsImage_CInit(&(pThis->m_oIcon));
CAwsImage_CInit(&(pThis->m_oIconMask));
	pThis->m_pVTab = &g_tVTab_CBComboBox_CBComboBox;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBComboBox_CAwsWindow;
{
	pThis->m_nMaxItemCount=nMaxItemCount;
	pThis->m_nItemCount=0;
	pThis->m_nCurItemIndex=0;
	{CAwsString(*pHeapObj_1)=(CAwsString(*))((char*)malloc(sizeof(CAwsString)*pThis->m_nMaxItemCount+sizeof(unsigned int))+sizeof(unsigned int));
*((unsigned int*)((char*)pHeapObj_1-sizeof(unsigned int)))=pThis->m_nMaxItemCount;{int i0;for(i0=0;i0<pThis->m_nMaxItemCount;++i0){CAwsString_CInit_i0p(pHeapObj_1+i0,100);}}
{pThis->m_pItemData=pHeapObj_1;

	pThis->m_nItemHeight=20;

	pThis->m_nBorderWidth=1;
	
	pThis->m_oIconSize.m_nWidth=16;
	pThis->m_oIconSize.m_nHeight=17;
	pThis->m_nLeftMargin=3;
	pThis->m_nRightMargin=1;

	{CAwsRgb rgbBorder,rgbFocusBorder,rgbBK,rgbFocusBK,rgbText,rgbFocusText;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbBorder,123,123,123);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbFocusBorder,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,67,67,67);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbFocusBK,67,67,67);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,168,155,131);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbFocusText,255,255,255);
pThis->m_oBorderColor=rgbBorder;
	pThis->m_oFocusBorderColor=rgbFocusBorder;
	pThis->m_oBKColor=rgbBK;
	pThis->m_oFocusBKColor=rgbFocusBK;
	pThis->m_oTextColor=rgbText;
	pThis->m_oFocusTextColor=rgbFocusText;

	pThis->m_nFontSize=12;
}}}}
}

void CBComboBox_DUninit_i1p(CAwsWindow* this, int * pOffset)
{

	CBComboBox* pThis = (CBComboBox*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBComboBox*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
{
	{int nOffset = 0;unsigned int* p=(unsigned int*)((char*)(pThis->m_pItemData)-sizeof(unsigned int));int i,nSize=*p;for(i=0;i<nSize;++i)CAwsString_DUninit_i1p(pThis->m_pItemData+i, &nOffset);free(p);};
	pThis->m_pItemData=ESP_NULL;
}
}

void CBComboBox_OnCreate(CAwsWindow* this)
{

	CBComboBox* pThis = (CBComboBox*)this;{
}
}

void CBComboBox_AddItem_CAwsString1p(CBComboBox* pThis, const CAwsString * strText)
{
	if(pThis->m_nItemCount<pThis->m_nMaxItemCount){
	{
		pThis->m_pItemData[pThis->m_nItemCount++]=*strText;
	}}
}

void CBComboBox_SetIcon_CAwsImage1p_CAwsImage1p(CBComboBox* pThis, const CAwsImage * icon,const CAwsImage * iconMask)
{
	pThis->m_oIcon=*icon;
	pThis->m_oIconMask=*iconMask;
}

int CBComboBox_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* this, int nWndID,int nCmdID,int nParam1,int nParam2)
{

	CBComboBox* pThis = (CBComboBox*)this;{
	if(AWS_ComboBox_PopupWnd==nWndID&&AWS_SysCmd_MenuCmd==nCmdID){
	{
		CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_ComboBoxItemChange,nParam1,0);
		pThis->m_nCurItemIndex=nParam1;

		// 弹出式菜单已经销毁了
		return 1;
	}}

	return CAwsWindow_OnCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),nWndID,nCmdID,nParam1,nParam2);
}
}

void CBComboBox_OnFocus_i0p(CAwsWindow* this, int bIsFocus)
{

	CBComboBox* pThis = (CBComboBox*)this;{
	CAwsContainer_OnFocus_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),bIsFocus);

	if(!bIsFocus){
	{
		// 销毁该弹出式窗口
		CAwsContainer_DestroyPopWnd_i0p(&(pThis->m_oBase_CAwsContainer),1);
	}}

	CAwsWindow_Invalide(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}
}

void CBComboBox_AdjustMenuPos_CBMenu1p_CEspRect1p(CBComboBox* pThis, CBMenu *  pMenu,CEspRect * rect)
{
	// 首先看从下面弹出是否够，如果够的画就从下面弹出，不够就从上面弹出(不应该超过父窗口的范围)
	CEspSize sizeMenu=*(CBMenu_GetMenuSize(pMenu));
	CEspSize sizeParent=*CAwsWindow_GetSize(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pParent);

	CEspRect rt;
	CEspRect_CInit(&(rt));
rt.m_ptLT.m_nX=rect->m_ptLT.m_nX;
	rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+sizeMenu.m_nWidth;

	if(rect->m_ptRB.m_nY+sizeMenu.m_nHeight<=sizeParent.m_nHeight){
	{
		// 在下面画
		rt.m_ptLT.m_nY=rect->m_ptRB.m_nY;
		rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+sizeMenu.m_nHeight;
	}}
	else
	{{
		// 在上面画
		rt.m_ptRB.m_nY=rect->m_ptLT.m_nY;
		rt.m_ptLT.m_nY=rt.m_ptRB.m_nY-sizeMenu.m_nHeight;
	}}

	{CEspPoint pt=*(CAwsWindow_GetOrigin(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pParent));
	CEspPoint_Operator_AddEqu_CEspPoint1p(&(rt.m_ptLT),&(pt));
	CEspPoint_Operator_AddEqu_CEspPoint1p(&(rt.m_ptRB),&(pt));

	*rect=rt;
}}

int CBComboBox_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CBComboBox* pThis = (CBComboBox*)this;{
	if(AWS_Key==type){
	{
		switch(code)
		{
		case AWS_KeyCode_OK:
			{
				// 弹出菜单，供选择
				{CBMenu*pHeapObj_1=(CBMenu(*))malloc(sizeof(CBMenu));
CBMenu_CInit_CAwsWindow1p_i0p_i0p_i0p(pHeapObj_1,&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),15,0,0);
{CBMenu *  pMenu=pHeapObj_1;
				CBMenu_SetTBBorderHeight_i0p(pMenu,0);
				CBMenu_SetItemLeftMargin_i0p(pMenu,2);
				CBMenu_SetItemRightMargin_i0p(pMenu,0);
				CBMenu_SetDefaultItemHeight_i0p(pMenu,18);
				CBMenu_SetDefaultItemWidth_i0p(pMenu,CAwsWindow_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow))->m_nWidth);
				CBMenu_SetPopupOnly_i0p(pMenu,1);

				{int i;
				for(i=0;i<pThis->m_nItemCount;++i){
				{
					CBMenu_AddItem_CAwsString1p_i0p(pMenu,&(pThis->m_pItemData[i]),0);
				}}
				CBMenu_AddItemEnd(pMenu);

				{CEspRect rect=*(CAwsWindow_GetRect(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow)));
				CBComboBox_AdjustMenuPos_CBMenu1p_CEspRect1p(pThis,pMenu,&(rect));
				CAwsContainer_PopWnd_CAwsWindow1p_CEspRect1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pMenu)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rect),AWS_ComboBox_PopupWnd);
			}}}}}
			return 1;
		}
	}}

	return CAwsContainer_OnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);
}
}

void CBComboBox_DrawBK_IAwsGc1p_CEspRect1p(CBComboBox* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	if(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_bIsFocus){
	{
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oFocusBorderColor));
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oFocusBKColor));
	}}
	else
	{{
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBorderColor));
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	}}

	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);
}

void CBComboBox_DrawText_IAwsGc1p_CEspRect1p(CBComboBox* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	if(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_bIsFocus){
	{
		pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oFocusTextColor));
	}}
	else
	{{
		pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oTextColor));
	}}

	pGc->m_pVTab->m_pSetTextAlignment_0p(pGc,AWS_TAM_Left);

	CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
	pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));
	{const CEspSize *  size=pGc->m_pVTab->m_pGetTextSize_CAwsString1p(pGc,&(pThis->m_pItemData[pThis->m_nCurItemIndex]));
	CEspRect rt=*(rect);
	const CEspSize sizeDraw=*CEspRect_GetSize(rect);
	rt.m_ptLT.m_nY=rt.m_ptLT.m_nY+(sizeDraw.m_nHeight-size->m_nHeight)/2;

	pGc->m_pVTab->m_pDrawText_CAwsString1p_CEspRect1p(pGc,&(pThis->m_pItemData[pThis->m_nCurItemIndex]),&(rt));
	pGc->m_pVTab->m_pDiscardFont(pGc);
}}

void CBComboBox_DrawIcon_IAwsGc1p_CEspRect1p(CBComboBox* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	if(CAwsImage_GetID(&(pThis->m_oIcon))>0){
	{
		pGc->m_pVTab->m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(pGc,&(rect->m_ptLT),&(pThis->m_oIcon),&pThis->m_oIconMask);
	}}
	else
	{{
		// 自己绘制
		CEspRect rt=*(rect);
		CEspSize size=*CEspRect_GetSize(rect);
		// 画边框
		CAwsRgb rgbPen1;
		CAwsRgb_CInit_i0p_i0p_i0p(&rgbPen1,49,52,49);
pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(rgbPen1));
		pGc->m_pVTab->m_pDrawRect_CEspRect1p(pGc,&(rt));

		// 画底色
		rt.m_ptLT.m_nX+=1;
		rt.m_ptLT.m_nY+=1;
		rt.m_ptRB.m_nX-=1;
		rt.m_ptRB.m_nY-=size.m_nHeight/2;
		{CAwsRgb rgbPen2;
		CAwsRgb_CInit_i0p_i0p_i0p(&rgbPen2,123,123,123);
pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(rgbPen2));
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(rgbPen2));
		pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,&(rt));
		rt.m_ptLT.m_nY=rt.m_ptRB.m_nY;
		rt.m_ptRB.m_nY=rect->m_ptRB.m_nY-1;
		{CAwsRgb rgbPen3;
		CAwsRgb_CInit_i0p_i0p_i0p(&rgbPen3,0,0,0);
pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(rgbPen3));
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(rgbPen3));
		pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,&(rt));

		// 画小三角
		{CAwsRgb rgbPen4;
		CAwsRgb_CInit_i0p_i0p_i0p(&rgbPen4,255,255,255);
pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(rgbPen4));
		{CEspPoint ptStart,ptEnd;
		CEspPoint_CInit_i0p_i0p(&(ptStart),0,0);
CEspPoint_CInit_i0p_i0p(&(ptEnd),0,0);
ptStart.m_nX=rect->m_ptLT.m_nX+(size.m_nWidth-5)/2;
		ptStart.m_nY=rect->m_ptLT.m_nY+(size.m_nHeight-3)/2;
		ptEnd.m_nX=ptStart.m_nX+5;
		ptEnd.m_nY=ptStart.m_nY;
		{int i;
		for(i=0;i<3;++i){
		{
			pGc->m_pVTab->m_pDrawLine_CEspPoint1p_CEspPoint1p(pGc,&(ptStart),&(ptEnd));
			ptStart.m_nX+=1;
			ptStart.m_nY+=1;
			ptEnd.m_nX-=1;
			ptEnd.m_nY=ptStart.m_nY;
		}}
	}}}}}}}
}

void CBComboBox_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CBComboBox* pThis = (CBComboBox*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));

	if(ESP_NULL!=pGc){
	{
		// 画背景
		CEspRect rt;
		CEspSize sizeWnd=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
		CEspRect_CInit(&(rt));
rt.m_ptRB.m_nX=sizeWnd.m_nWidth;
		rt.m_ptRB.m_nY=sizeWnd.m_nHeight;
		pThis->m_pVTab->m_pDrawBK_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));

		// 画文字
		rt.m_ptLT.m_nX=pThis->m_nLeftMargin+pThis->m_nBorderWidth;
		rt.m_ptLT.m_nY=pThis->m_nBorderWidth;
		rt.m_ptRB.m_nX=rt.m_ptRB.m_nX-pThis->m_nBorderWidth-pThis->m_nRightMargin-pThis->m_oIconSize.m_nWidth;
		rt.m_ptRB.m_nY-=pThis->m_nBorderWidth;
		pThis->m_pVTab->m_pDrawText_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));

		// 画右边图标
		rt.m_ptLT.m_nX=rt.m_ptRB.m_nX;
		rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_oIconSize.m_nWidth;
		rt.m_ptLT.m_nY=(sizeWnd.m_nHeight-pThis->m_oIconSize.m_nHeight)/2;
		rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_oIconSize.m_nHeight;
		pThis->m_pVTab->m_pDrawIcon_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));
	}}

	CAwsContainer_OnDraw_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),rect);
}
}
