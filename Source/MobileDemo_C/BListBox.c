/******************************************************************************
* FileName		       : BListBox.cpp
* Description          : implementation of the CBListBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BListBox.h"
const VTab_CBListBox g_tVTab_CBListBox_CBListBox = {CBListBox_DrawBorder_IAwsGc1p_CEspRect1p, CBListBox_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p};
const VTab_CAwsWindow g_tVTab_CBListBox_CAwsWindow = {CBListBox_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CBListBox_OnDraw_CEspRect1p, CBListBox_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CBListBox_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CBListBox_OnCreate};
void CBListBox_CInit(CBListBox* pThis)
{
CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oSelectBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oSelectBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oSelectTextColor),0,0,0);
	pThis->m_pVTab = &g_tVTab_CBListBox_CBListBox;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBListBox_CAwsWindow;
}

void CBListBox_SetBorderPixels_i0p(CBListBox* pThis, int nPixels) { pThis->m_nBorderPixels=nPixels; } 

void CBListBox_SetSelectBKColor_CAwsRgb1p(CBListBox* pThis, const CAwsRgb * color) { pThis->m_oSelectBKColor=*color; } 

void CBListBox_SetBKColor_CAwsRgb1p(CBListBox* pThis, const CAwsRgb * color) { pThis->m_oBKColor=*color; } 

void CBListBox_SetSelectTextColor_CAwsRgb1p(CBListBox* pThis, const CAwsRgb * color) { pThis->m_oSelectTextColor=*color; } 

void CBListBox_SetTextColor_CAwsRgb1p(CBListBox* pThis, const CAwsRgb * color) { pThis->m_oTextColor=*color; } 

void CBListBox_SetBorderColor_CAwsRgb1p(CBListBox* pThis, const CAwsRgb * color) { pThis->m_oBorderColor=*color; } 

#include "IAwsGc.h"
#include "BScrollBar.h"
const VTab_CBScrollBar g_tVTab_CBScrollBar_CBScrollBar = {CBScrollBar_DrawBK_IAwsGc1p_CEspRect1p, CBScrollBar_DrawBlock_IAwsGc1p_CEspRect1p};
const VTab_CAwsWindow g_tVTab_CBScrollBar_CAwsWindow = {CBScrollBar_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CBScrollBar_OnDraw_CEspRect1p, CAwsWindow_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CAwsWindow_OnFocus_i0p, CAwsWindow_OnTimer, CAwsWindow_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CAwsWindow_OnCreate};
void CBScrollBar_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CBScrollBar* pThis=(CBScrollBar*)this;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsWindow_DUninit_i1p(&(pThis->m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBScrollBar*)0)->m_oBase_CAwsWindow));
}

void CBScrollBar_SetDirection_0p(CBScrollBar* pThis, ESBDir dir) { pThis->m_eDir=dir; } 


void CBListBox_CInit_i0p(CBListBox* pThis, int nMaxItemCount)
{

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oSelectBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oSelectBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oSelectTextColor),0,0,0);
	pThis->m_pVTab = &g_tVTab_CBListBox_CBListBox;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBListBox_CAwsWindow;
{
	pThis->m_nMaxItemCount=nMaxItemCount;
	pThis->m_nItemCount=0;
	pThis->m_nCurItemIndex=0;
	{CAwsString(*pHeapObj_1)=(CAwsString(*))((char*)malloc(sizeof(CAwsString)*pThis->m_nMaxItemCount+sizeof(unsigned int))+sizeof(unsigned int));
*((unsigned int*)((char*)pHeapObj_1-sizeof(unsigned int)))=pThis->m_nMaxItemCount;{int i0;for(i0=0;i0<pThis->m_nMaxItemCount;++i0){CAwsString_CInit_i0p(pHeapObj_1+i0,100);}}
{pThis->m_pItemData=pHeapObj_1;

	pThis->m_pScrollBar=ESP_NULL;
	pThis->m_nScrollLength=0;
	pThis->m_nScrollPos=0;

	pThis->m_nItemHeight=20;

	pThis->m_nBorderPixels=1;

	{CAwsRgb rgbBorder,rgbSelectBorder,rgbSelectBK,rgbBK,rgbText,rgbSelectText;

	CAwsRgb_CInit_i0p_i0p_i0p(&rgbBorder,123,123,123);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbSelectBorder,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbSelectBK,0,0,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,65,65,65);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbSelectText,255,255,255);
pThis->m_oBorderColor=rgbBorder;
	pThis->m_oSelectBorderColor=rgbSelectBorder;
	pThis->m_oSelectBKColor=rgbSelectBK;
	pThis->m_oBKColor=rgbBK;
	pThis->m_oTextColor=rgbText;
	pThis->m_oSelectTextColor=rgbSelectText;

	pThis->m_nDrawItemCount=0;
	pThis->m_nDrawItemStartIndex=0;
	pThis->m_nItemLeftMargin=5;
	pThis->m_nScrollBarWidth=5;

	pThis->m_nFontSize=12;
}}}}
}

void CBListBox_DUninit_i1p(CAwsWindow* this, int * pOffset)
{

	CBListBox* pThis = (CBListBox*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBListBox*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
{
	{int nOffset = 0;unsigned int* p=(unsigned int*)((char*)(pThis->m_pItemData)-sizeof(unsigned int));int i,nSize=*p;for(i=0;i<nSize;++i)CAwsString_DUninit_i1p(pThis->m_pItemData+i, &nOffset);free(p);};
	pThis->m_pItemData=ESP_NULL;
}
}

void CBListBox_AddItem_CAwsString1p(CBListBox* pThis, const CAwsString * strText)
{
	if(pThis->m_nItemCount<pThis->m_nMaxItemCount){
	{
		pThis->m_pItemData[pThis->m_nItemCount++]=*strText;
	}}
}

void CBListBox_AddItemEnd(CBListBox* pThis)
{
	// 计算是否需要显示滚动条

	CEspSize size=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));

	// 计算最多能Draw多少个
	pThis->m_nDrawItemCount=(size.m_nHeight-pThis->m_nBorderPixels*2)/pThis->m_nItemHeight;

	if(pThis->m_nDrawItemCount<pThis->m_nItemCount){
	{
		pThis->m_nScrollLength=pThis->m_nItemCount-pThis->m_nDrawItemCount+1;
		CBScrollBar_SetTotalLength_i0p(pThis->m_pScrollBar,pThis->m_nScrollLength);
	}}
	else
	{{
		pThis->m_nDrawItemCount=pThis->m_nItemCount;
		CAwsWindow_SetVisible_i0p_i0p(&(pThis->m_pScrollBar->m_oBase_CAwsWindow),0,1);
	}}
}

void CBListBox_OnCreate(CAwsWindow* this)
{

	CBListBox* pThis = (CBListBox*)this;{
	// 创建滚动条
	CEspRect rt;
	CEspSize size=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
	CEspRect_CInit(&(rt));
rt.m_ptLT.m_nX=size.m_nWidth-pThis->m_nScrollBarWidth-pThis->m_nBorderPixels;
	rt.m_ptLT.m_nY=pThis->m_nBorderPixels;
	rt.m_ptRB.m_nX=size.m_nWidth-pThis->m_nBorderPixels;
	rt.m_ptRB.m_nY=size.m_nHeight-pThis->m_nBorderPixels;
	{CBScrollBar(*pHeapObj_1)=(CBScrollBar(*))malloc(sizeof(CBScrollBar));
CBScrollBar_CInit(pHeapObj_1);
{pThis->m_pScrollBar=pHeapObj_1;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pScrollBar->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt),0,1);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pScrollBar)->m_oBase_CAwsWindow),0);
}}}
}

void CBListBox_DrawBorder_IAwsGc1p_CEspRect1p(CBListBox* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	if(pThis->m_nBorderPixels>0){
	{
		if(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_bIsFocus){
			pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oSelectBorderColor));}
		else
			{pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBorderColor));}

		pGc->m_pVTab->m_pDrawRect_CEspRect1p(pGc,rect);
	}}
}

void CBListBox_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p(CBListBox* pThis, IAwsGc *  pGc,const CEspRect * rect,int nIndex,int bIsSelected)
{
	// 画背景
	if(bIsSelected){
	{
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBorderColor));
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oSelectBKColor));
		pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oSelectTextColor));
	}}
	else
	{{
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBorderColor));
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
		pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oTextColor));
	}}
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);

	pGc->m_pVTab->m_pSetTextAlignment_0p(pGc,AWS_TAM_Left);

	CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
	pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));
	{const CEspSize *  size=pGc->m_pVTab->m_pGetTextSize_CAwsString1p(pGc,&(pThis->m_pItemData[nIndex]));
	CEspRect rt=*(rect);
	rt.m_ptLT.m_nX=rt.m_ptLT.m_nX+pThis->m_nItemLeftMargin;
	rt.m_ptLT.m_nY=rt.m_ptLT.m_nY+(pThis->m_nItemHeight-size->m_nHeight)/2;

	pGc->m_pVTab->m_pDrawText_CAwsString1p_CEspRect1p(pGc,&(pThis->m_pItemData[nIndex]),&(rt));
	pGc->m_pVTab->m_pDiscardFont(pGc);
}}

void CBListBox_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CBListBox* pThis = (CBListBox*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
	CEspRect rt,rtTemp;

	CEspSize size=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));

	CEspRect_CInit(&(rt));
CEspRect_CInit(&(rtTemp));
if(ESP_NULL!=pGc){
	{
		CEspRect rt;

		// 画全边框
		CEspRect_CInit_i0p_i0p_i0p_i0p(&rt,0,0,size.m_nWidth,size.m_nHeight);
if(!pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_bIsBKTransparent){
			pThis->m_pVTab->m_pDrawBorder_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));}

		// 画中间Item
		rt.m_ptLT.m_nX=pThis->m_nBorderPixels;
		rt.m_ptLT.m_nY=pThis->m_nBorderPixels;
		rt.m_ptRB.m_nX=size.m_nWidth-pThis->m_nBorderPixels-CAwsWindow_GetSize(&(pThis->m_pScrollBar->m_oBase_CAwsWindow))->m_nWidth;
		rt.m_ptRB.m_nY=rt.m_ptLT.m_nX+pThis->m_nItemHeight;
		{int i;
		for(i=0;i<pThis->m_nDrawItemCount;++i){
		{
			if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
			{
				if(pThis->m_nCurItemIndex==i+pThis->m_nDrawItemStartIndex){
				{
					// 选中
					pThis->m_pVTab->m_pDrawItem_IAwsGc1p_CEspRect1p_i0p_i0p(pThis,pGc,&(rt),i+pThis->m_nDrawItemStartIndex,1);
				}}
				else
				{{
					// 没选中
					pThis->m_pVTab->m_pDrawItem_IAwsGc1p_CEspRect1p_i0p_i0p(pThis,pGc,&(rt),i+pThis->m_nDrawItemStartIndex,0);
				}}
			}}

			rt.m_ptLT.m_nY+=pThis->m_nItemHeight;
			rt.m_ptRB.m_nY+=pThis->m_nItemHeight;
		}}
	}}}

	CAwsContainer_OnDraw_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),rect);
}
}

void CBListBox_OnFocus_i0p(CAwsWindow* this, int bIsFocus)
{

	CBListBox* pThis = (CBListBox*)this;{
	CAwsContainer_OnFocus_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),bIsFocus);

	CAwsWindow_Invalide(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}
}

int CBListBox_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CBListBox* pThis = (CBListBox*)this;{
	CEspRect rt;
	CEspRect_CInit(&(rt));
rt.m_ptLT.m_nX=pThis->m_nBorderPixels;
	rt.m_ptRB.m_nX=CAwsWindow_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow))->m_nWidth-pThis->m_nBorderPixels-CAwsWindow_GetSize(&(pThis->m_pScrollBar->m_oBase_CAwsWindow))->m_nWidth;

	if(AWS_Key==type){
	{
		switch(code)
		{
		case AWS_KeyCode_UpArrow:
			if(pThis->m_nCurItemIndex>0){
			{
				--pThis->m_nCurItemIndex;
				if(pThis->m_nCurItemIndex<pThis->m_nDrawItemStartIndex){
				{
					pThis->m_nDrawItemStartIndex=pThis->m_nCurItemIndex;
					// 全都要移动
					CAwsWindow_Invalide(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
					if(0==pThis->m_nScrollPos){
					{
						pThis->m_nScrollPos=pThis->m_nScrollLength-1;
					}}
					else
					{{
						--pThis->m_nScrollPos;
					}}
					CBScrollBar_SetCurPos_i0p(pThis->m_pScrollBar,pThis->m_nScrollPos);
				}}
				else
				{{
					// 只需要移动两个
					rt.m_ptLT.m_nY=pThis->m_nBorderPixels+(pThis->m_nCurItemIndex-pThis->m_nDrawItemStartIndex)*pThis->m_nItemHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nItemHeight*2;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
			}}
			else
			{{
				pThis->m_nCurItemIndex=pThis->m_nItemCount-1;
				{int n=pThis->m_nItemCount-pThis->m_nDrawItemCount;

				if(n!=pThis->m_nDrawItemStartIndex){
				{
					// 全都要移动
					pThis->m_nDrawItemStartIndex=n;
					CAwsWindow_Invalide(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
					if(0==pThis->m_nScrollPos){
					{
						pThis->m_nScrollPos=pThis->m_nScrollLength-1;
					}}
					else
					{{
						--pThis->m_nScrollPos;
					}}
					CBScrollBar_SetCurPos_i0p(pThis->m_pScrollBar,pThis->m_nScrollPos);
				}}
				else
				{{
					// 只需要移动两个
					rt.m_ptLT.m_nY=pThis->m_nBorderPixels;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nItemHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

					rt.m_ptLT.m_nY=pThis->m_nBorderPixels+(pThis->m_nDrawItemCount-1)*pThis->m_nItemHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nItemHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
			}}}

			return 1;

		case AWS_KeyCode_DownArrow:
			if(pThis->m_nCurItemIndex<pThis->m_nItemCount-1){
			{
				++pThis->m_nCurItemIndex;
				if(pThis->m_nCurItemIndex-pThis->m_nDrawItemStartIndex>=pThis->m_nDrawItemCount){
				{
					++pThis->m_nDrawItemStartIndex;
					CAwsWindow_Invalide(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
					if(pThis->m_nScrollPos+1<pThis->m_nScrollLength){
					{
						++pThis->m_nScrollPos;
					}}
					else
					{{
						pThis->m_nScrollPos=0;
					}}
					CBScrollBar_SetCurPos_i0p(pThis->m_pScrollBar,pThis->m_nScrollPos);
				}}
				else
				{{
					// 只需要移动两个
					rt.m_ptLT.m_nY=pThis->m_nBorderPixels+(pThis->m_nCurItemIndex-1-pThis->m_nDrawItemStartIndex)*pThis->m_nItemHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nItemHeight*2;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
			}}
			else
			{{
				int n=pThis->m_nDrawItemStartIndex;
				pThis->m_nCurItemIndex=0;
				pThis->m_nDrawItemStartIndex=0;

				if(0!=n){
				{
					CAwsWindow_Invalide(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
					if(pThis->m_nScrollPos+1<pThis->m_nScrollLength){
					{
						++pThis->m_nScrollPos;
					}}
					else
					{{
						pThis->m_nScrollPos=0;
					}}
					CBScrollBar_SetCurPos_i0p(pThis->m_pScrollBar,pThis->m_nScrollPos);
				}}
				else
				{{
					// 只需要移动两个
					rt.m_ptLT.m_nY=pThis->m_nBorderPixels;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nItemHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

					rt.m_ptLT.m_nY=pThis->m_nBorderPixels+(pThis->m_nDrawItemCount-1)*pThis->m_nItemHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nItemHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
			}}
			return 1;

		case AWS_KeyCode_OK:
			CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_ListBoxCmd,pThis->m_nCurItemIndex,0);
			return 1;
		}
	}}

	return CAwsWindow_OnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);
}
}
