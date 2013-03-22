/******************************************************************************
* FileName		       : BListView.cpp
* Description          : implementation of the CBListView class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BListView.h"
const VTab_CBListView g_tVTab_CBListView_CBListView = {CBListView_DrawBorder_IAwsGc1p_CEspRect1p, CBListView_DrawBK_IAwsGc1p_CEspRect1p, CBListView_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p};
const VTab_CAwsWindow g_tVTab_CBListView_CAwsWindow = {CBListView_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CBListView_OnDraw_CEspRect1p, CBListView_OnKey_0p_0p, CBListView_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CBListView_OnCreate};
void CBListView_CInit(CBListView* pThis)
{
CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
CEspSize_CInit_i0p_i0p(&(pThis->m_oListModeItemSize),0,0);
CEspSize_CInit_i0p_i0p(&(pThis->m_oIconModeItemSize),0,0);
CEspSize_CInit_i0p_i0p(&(pThis->m_oDrawItemSize),0,0);
CEspSize_CInit_i0p_i0p(&(pThis->m_oSmallIconSize),0,0);
CEspSize_CInit_i0p_i0p(&(pThis->m_oBigIconSize),0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oItemSelectBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oItemBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oSelectTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
	pThis->m_pVTab = &g_tVTab_CBListView_CBListView;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBListView_CAwsWindow;
}

void CBListView_TLVData_CInit(CBListView_TLVData* pThis)
{
CAwsString_CInit_i0p(&(pThis->m_oText),100);
CAwsImage_CInit(&(pThis->m_oSmallIcon));
CAwsImage_CInit(&(pThis->m_oBigIcon));
CAwsImage_CInit(&(pThis->m_oSmallMask));
CAwsImage_CInit(&(pThis->m_oBigMask));
}

void CBListView_TLVData_DUninit_i1p(CBListView_TLVData* pThis, int* pOffset)
{
	CAwsString_DUninit_i1p(&(pThis->m_oText), 0);
}

void CBListView_SetBKColor_CAwsRgb1p(CBListView* pThis, const CAwsRgb * color) { pThis->m_oBKColor=*color; } 

void CBListView_SetSelectTextColor_CAwsRgb1p(CBListView* pThis, const CAwsRgb * color) { pThis->m_oSelectTextColor=*color; } 

void CBListView_SetTextColor_CAwsRgb1p(CBListView* pThis, const CAwsRgb * color) { pThis->m_oTextColor=*color; } 

void CBListView_SetItemBKColor_CAwsRgb1p(CBListView* pThis, const CAwsRgb * color) { pThis->m_oItemBKColor=*color; } 

void CBListView_SetItemSelectBKColor_CAwsRgb1p(CBListView* pThis, const CAwsRgb * color) { pThis->m_oItemSelectBKColor=*color; } 

void CBListView_SetBorderColor_CAwsRgb1p(CBListView* pThis, const CAwsRgb * color) { pThis->m_oBorderColor=*color; } 

void CBListView_SetBigIconSize_CEspSize1p(CBListView* pThis, const CEspSize * size) { pThis->m_oBigIconSize=*size; } 

void CBListView_SetSmallIconSize_CEspSize1p(CBListView* pThis, const CEspSize * size) { pThis->m_oSmallIconSize=*size; } 

void CBListView_setIconItemSize_CEspSize1p(CBListView* pThis, const CEspSize * size) { pThis->m_oIconModeItemSize=*size; } 

void CBListView_SetListItemSize_CEspSize1p(CBListView* pThis, const CEspSize * size) { pThis->m_oListModeItemSize=*size; } 

void CBListView_SetFontSize_i0p(CBListView* pThis, int nSize) { pThis->m_nFontSize=nSize; } 

int CBListView_GetCurItemIndex(CBListView* pThis) { return pThis->m_nCurItemIndex; } 

#include "BScrollBar.h"
#include "IAwsGc.h"

void CBListView_CInit_i0p(CBListView* pThis, int nMaxItemCount)
{

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
CEspSize_CInit_i0p_i0p(&(pThis->m_oListModeItemSize),0,0);
CEspSize_CInit_i0p_i0p(&(pThis->m_oIconModeItemSize),0,0);
CEspSize_CInit_i0p_i0p(&(pThis->m_oDrawItemSize),0,0);
CEspSize_CInit_i0p_i0p(&(pThis->m_oSmallIconSize),0,0);
CEspSize_CInit_i0p_i0p(&(pThis->m_oBigIconSize),0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oItemSelectBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oItemBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oSelectTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
	pThis->m_pVTab = &g_tVTab_CBListView_CBListView;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBListView_CAwsWindow;
{
	pThis->m_eShowMode=LVShowMode_Icon;

	pThis->m_nMaxItemCount=nMaxItemCount;
	{CBListView_TLVData(*pHeapObj_1)=(CBListView_TLVData(*))((char*)malloc(sizeof(CBListView_TLVData)*pThis->m_nMaxItemCount+sizeof(unsigned int))+sizeof(unsigned int));
*((unsigned int*)((char*)pHeapObj_1-sizeof(unsigned int)))=pThis->m_nMaxItemCount;{int i0;for(i0=0;i0<pThis->m_nMaxItemCount;++i0){CBListView_TLVData_CInit(pHeapObj_1+i0);}}
{pThis->m_pLVData=pHeapObj_1;
	pThis->m_nItemCount=0;
	pThis->m_nCurItemIndex=0;

	pThis->m_nDrawItemStartIndex=0;
	pThis->m_nWidthDrawItemCount=0;
	pThis->m_nHeightDrawItemCount=0;

	pThis->m_oListModeItemSize.m_nHeight=45;
	pThis->m_oIconModeItemSize.m_nWidth=77;
	pThis->m_oIconModeItemSize.m_nHeight=67;
	pThis->m_oSmallIconSize.m_nHeight=39;
	pThis->m_oSmallIconSize.m_nWidth=40;
	pThis->m_oBigIconSize.m_nHeight=39;
	pThis->m_oBigIconSize.m_nWidth=40;

	pThis->m_nListIconTextMargin=5;

	pThis->m_nLRBorderWidth=1;
	pThis->m_nTBBorderHeight=1;
	pThis->m_nLeftMargin=0;
	pThis->m_nRightMargin=0;
	pThis->m_nTopMargin=0;
	pThis->m_nBottomMargin=0;

	pThis->m_nFontSize=12;

	pThis->m_pScrollBar=ESP_NULL;
	pThis->m_nScrollBarWidth=5;
	pThis->m_nScrollLength=0;
	pThis->m_nScrollPos=0;

	{CAwsRgb rgbBorder,rgbItemSelectBK,rgbItemBK,rgbText,rgbSelectText,rgbBK;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbBorder,32,28,16);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbItemSelectBK,0,0,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbItemBK,32,28,16);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,181,181,181);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbSelectText,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,32,28,16);
pThis->m_oBorderColor=rgbBorder;
	pThis->m_oItemSelectBKColor=rgbItemSelectBK;
	pThis->m_oItemBKColor=rgbItemBK;
	pThis->m_oTextColor=rgbText;
	pThis->m_oSelectTextColor=rgbSelectText;
	pThis->m_oBKColor=rgbBK;
}}}}
}

void CBListView_DUninit_i1p(CAwsWindow* this, int * pOffset)
{

	CBListView* pThis = (CBListView*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBListView*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
{
	{int nOffset = 0;unsigned int* p=(unsigned int*)((char*)(pThis->m_pLVData)-sizeof(unsigned int));int i,nSize=*p;for(i=0;i<nSize;++i)CBListView_TLVData_DUninit_i1p(pThis->m_pLVData+i, &nOffset);free(p);};
}
}

void CBListView_OnCreate(CAwsWindow* this)
{

	CBListView* pThis = (CBListView*)this;{
	// 创建滚动条
	CEspRect rt;
	CEspSize size=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
	CEspRect_CInit(&(rt));
rt.m_ptLT.m_nX=size.m_nWidth-pThis->m_nScrollBarWidth-pThis->m_nLRBorderWidth;
	rt.m_ptLT.m_nY=pThis->m_nTBBorderHeight;
	rt.m_ptRB.m_nX=size.m_nWidth-pThis->m_nLRBorderWidth;
	rt.m_ptRB.m_nY=size.m_nHeight-pThis->m_nTBBorderHeight;
	{CBScrollBar(*pHeapObj_1)=(CBScrollBar(*))malloc(sizeof(CBScrollBar));
CBScrollBar_CInit(pHeapObj_1);
{pThis->m_pScrollBar=pHeapObj_1;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pScrollBar->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt),0,1);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pScrollBar)->m_oBase_CAwsWindow),0);
}}}
}

void CBListView_AddItem_CAwsString1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_i0p(CBListView* pThis, const CAwsString * strText,const CAwsImage * iconSmall,const CAwsImage * iconBig,const CAwsImage *  pSmallMask,const CAwsImage *  pBigMask,int bIsEnd)
{
	if(pThis->m_nItemCount<pThis->m_nMaxItemCount){
	{
		pThis->m_pLVData[pThis->m_nItemCount].m_oText=*strText;
		pThis->m_pLVData[pThis->m_nItemCount].m_oSmallIcon=*iconSmall;
		pThis->m_pLVData[pThis->m_nItemCount].m_oBigIcon=*iconBig;
		if(ESP_NULL!=pSmallMask){
		{
			pThis->m_pLVData[pThis->m_nItemCount].m_oSmallMask=*pSmallMask;
		}}
		if(ESP_NULL!=pBigMask){
		{
			pThis->m_pLVData[pThis->m_nItemCount].m_oBigMask=*pBigMask;
		}}
		++pThis->m_nItemCount;

		if(bIsEnd){
		{
			// 计算显示参数
			CBListView_CalcShowParam(pThis);
		}}
	}}
}

void CBListView_RemoveItem_i0p(CBListView* pThis, int nItemIndex)
{
	if(nItemIndex<pThis->m_nItemCount){
	{
		int i;
		for(i=nItemIndex;i<pThis->m_nItemCount-1;++i){
		{
			pThis->m_pLVData[i]=pThis->m_pLVData[i+1];
		}}

		--pThis->m_nItemCount;

		if(pThis->m_nCurItemIndex>nItemIndex){
		{
			--pThis->m_nCurItemIndex;
		}}
		else if(pThis->m_nCurItemIndex==nItemIndex&&pThis->m_nItemCount==pThis->m_nCurItemIndex){
		{
			// 是最后一个
			--pThis->m_nCurItemIndex;
		}}

		CBListView_CalcShowParam(pThis);
		CBScrollBar_SetCurPos_i0p(pThis->m_pScrollBar,pThis->m_nScrollPos);
		CAwsWindow_Invalide(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
	}}
}

int CBListView_GetDrawStartIndexFromCurIndex_i0p(CBListView* pThis, int nIndex)
{
	int nItemsPerPage=(pThis->m_nWidthDrawItemCount*pThis->m_nHeightDrawItemCount);
	int n=pThis->m_nCurItemIndex;
	pThis->m_nDrawItemStartIndex=0;
	pThis->m_nScrollPos=0;

	while(n>=nItemsPerPage){
	{
		n-=pThis->m_nWidthDrawItemCount;
		pThis->m_nDrawItemStartIndex+=pThis->m_nWidthDrawItemCount;

		++pThis->m_nScrollPos;
	}}

	return pThis->m_nDrawItemStartIndex;
}

void CBListView_SetShowMode_0p(CBListView* pThis, LV_ShowMode mode)
{
	if(pThis->m_eShowMode!=mode){
	{
		pThis->m_eShowMode=mode;

		// 改变显示模式
		CBListView_CalcShowParam(pThis);

		// 修改m_nDrawItemStartIndex
		pThis->m_nDrawItemStartIndex=CBListView_GetDrawStartIndexFromCurIndex_i0p(pThis,pThis->m_nCurItemIndex);
		CBScrollBar_SetCurPos_i0p(pThis->m_pScrollBar,pThis->m_nScrollPos);

		CAwsWindow_Invalide(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
	}}
}

void CBListView_RegulateParam(CBListView* pThis)
{
	CEspSize sizeWnd=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
	pThis->m_oListModeItemSize.m_nWidth=sizeWnd.m_nWidth-pThis->m_nLRBorderWidth*2-pThis->m_nScrollBarWidth;

	switch(pThis->m_eShowMode)
	{
	case LVShowMode_List:
		{
			pThis->m_nWidthDrawItemCount=1;
			pThis->m_nHeightDrawItemCount=(sizeWnd.m_nHeight-pThis->m_nTBBorderHeight*2)/pThis->m_oListModeItemSize.m_nHeight;

			pThis->m_oDrawItemSize=pThis->m_oListModeItemSize;
		}
		break;

	case LVShowMode_Icon:
		{
			pThis->m_nWidthDrawItemCount=(sizeWnd.m_nWidth-pThis->m_nLRBorderWidth*2)/pThis->m_oIconModeItemSize.m_nWidth;
			pThis->m_nHeightDrawItemCount=(sizeWnd.m_nHeight-pThis->m_nTBBorderHeight*2)/pThis->m_oIconModeItemSize.m_nHeight;

			pThis->m_oDrawItemSize=pThis->m_oIconModeItemSize;
		}
		break;
	}
	{int n=pThis->m_nItemCount/pThis->m_nWidthDrawItemCount+(pThis->m_nItemCount%pThis->m_nWidthDrawItemCount>0?1:0);
	if(pThis->m_nHeightDrawItemCount>n){
	{
		pThis->m_nHeightDrawItemCount=n;
	}}

	{int nRemainWidth=(sizeWnd.m_nWidth-pThis->m_nLRBorderWidth*2-pThis->m_nScrollBarWidth)%pThis->m_oDrawItemSize.m_nWidth;
	int nRemainHeight=(sizeWnd.m_nHeight-pThis->m_nTBBorderHeight*2)%pThis->m_oDrawItemSize.m_nHeight;
	pThis->m_nLeftMargin=nRemainWidth/2+nRemainWidth%2;
	pThis->m_nRightMargin=nRemainWidth/2;
	pThis->m_nTopMargin=nRemainHeight/2;
	pThis->m_nBottomMargin=nRemainHeight/2+nRemainHeight%2;
}}}

void CBListView_CalcShowParam(CBListView* pThis)
{
//	CEspSize sizeWnd = *GetSize();

	CBListView_RegulateParam(pThis);

	// 设置滚动条参数
	if(pThis->m_nWidthDrawItemCount*pThis->m_nHeightDrawItemCount<pThis->m_nItemCount){
	{
		pThis->m_nScrollLength=(pThis->m_nItemCount/pThis->m_nWidthDrawItemCount+((pThis->m_nItemCount%pThis->m_nWidthDrawItemCount)>0?1:0))-pThis->m_nHeightDrawItemCount+1;
		CBScrollBar_SetTotalLength_i0p(pThis->m_pScrollBar,pThis->m_nScrollLength);
		CAwsWindow_SetVisible_i0p_i0p(&(pThis->m_pScrollBar->m_oBase_CAwsWindow),1,1);
	}}
	else
	{{
		// 不用显示滚动条
		CAwsWindow_SetVisible_i0p_i0p(&(pThis->m_pScrollBar->m_oBase_CAwsWindow),0,1);
	}}
}

void CBListView_DrawBorder_IAwsGc1p_CEspRect1p(CBListView* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBorderColor));
	pGc->m_pVTab->m_pDrawRect_CEspRect1p(pGc,rect);
}

void CBListView_DrawBK_IAwsGc1p_CEspRect1p(CBListView* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);
}

void CBListView_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p(CBListView* pThis, IAwsGc *  pGc,const CEspRect * rect,int nIndex,int bIsSelected)
{
	// 画背景
	if(bIsSelected){
	{
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oItemSelectBKColor));
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oItemSelectBKColor));
		pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oSelectTextColor));
	}}
	else
	{{
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oItemBKColor));
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oItemBKColor));
		pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oTextColor));
	}}
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);

	{const CEspSize *  sizeText=pGc->m_pVTab->m_pGetTextSize_CAwsString1p(pGc,&(pThis->m_pLVData[nIndex].m_oText));
	CEspRect rt=*(rect);
	CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
	pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));

	switch(pThis->m_eShowMode)
	{
	case LVShowMode_List:
		{
			// 先在左边画小图标，再在紧接着的地方画字
			rt.m_ptLT.m_nY=rect->m_ptLT.m_nY+(pThis->m_oDrawItemSize.m_nHeight-pThis->m_oSmallIconSize.m_nHeight)/2;

			pGc->m_pVTab->m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(pGc,&(rt.m_ptLT),&(pThis->m_pLVData[nIndex].m_oSmallIcon),&pThis->m_pLVData[nIndex].m_oSmallMask);

			rt.m_ptLT.m_nX=rt.m_ptLT.m_nX+pThis->m_oSmallIconSize.m_nWidth+pThis->m_nListIconTextMargin;
			rt.m_ptLT.m_nY=rect->m_ptLT.m_nY+(pThis->m_oDrawItemSize.m_nHeight-sizeText->m_nHeight)/2;
			pGc->m_pVTab->m_pSetTextAlignment_0p(pGc,AWS_TAM_Left);
			pGc->m_pVTab->m_pDrawText_CAwsString1p_CEspRect1p(pGc,&(pThis->m_pLVData[nIndex].m_oText),&(rt));
		}
		break;

	case LVShowMode_Icon:
		{
			// 现在上面画大图标，再在下面画字
			rt.m_ptLT.m_nX=rect->m_ptLT.m_nX+(pThis->m_oDrawItemSize.m_nWidth-pThis->m_oBigIconSize.m_nWidth)/2;
			rt.m_ptLT.m_nY=rect->m_ptLT.m_nY+(pThis->m_oDrawItemSize.m_nHeight-pThis->m_oBigIconSize.m_nHeight-sizeText->m_nHeight)/2;

			pGc->m_pVTab->m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(pGc,&(rt.m_ptLT),&(pThis->m_pLVData[nIndex].m_oBigIcon),&pThis->m_pLVData[nIndex].m_oBigMask);

			rt.m_ptLT.m_nX=rect->m_ptLT.m_nX;
			rt.m_ptLT.m_nY=rt.m_ptLT.m_nY+pThis->m_oBigIconSize.m_nHeight;
			pGc->m_pVTab->m_pSetTextAlignment_0p(pGc,AWS_TAM_Mid);
			pGc->m_pVTab->m_pDrawText_CAwsString1p_CEspRect1p(pGc,&(pThis->m_pLVData[nIndex].m_oText),&(rt));
		}
		break;
	}

	pGc->m_pVTab->m_pDiscardFont(pGc);
}}

void CBListView_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CBListView* pThis = (CBListView*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
	CEspRect rt,rtTemp;

	CEspRect_CInit(&(rt));
CEspRect_CInit(&(rtTemp));
if(ESP_NULL!=pGc){
	{
		CEspSize sizeWnd=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
		CEspRect rt;

		// 画全边框
		CEspRect_CInit_i0p_i0p_i0p_i0p(&rt,0,0,sizeWnd.m_nWidth,sizeWnd.m_nHeight);
if(!pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_bIsBKTransparent){
			pThis->m_pVTab->m_pDrawBorder_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));}

		// 是否有背景需要画
		{
			// 上
			CEspRect rtWnd;
			CEspRect_CInit_i0p_i0p_i0p_i0p(&rtWnd,0,0,sizeWnd.m_nWidth,sizeWnd.m_nHeight);
rt.m_ptLT.m_nX=rtWnd.m_ptLT.m_nX+pThis->m_nLRBorderWidth;
			rt.m_ptLT.m_nY=rtWnd.m_ptLT.m_nY+pThis->m_nTBBorderHeight;
			rt.m_ptRB.m_nX=rtWnd.m_ptRB.m_nX-pThis->m_nLRBorderWidth;
			rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nTopMargin;
			if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
			{
				pThis->m_pVTab->m_pDrawBK_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));
			}}

			// 下
			rt.m_ptLT.m_nY=rtWnd.m_ptRB.m_nY-pThis->m_nTBBorderHeight-pThis->m_nBottomMargin;
			rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nBottomMargin;
			if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
			{
				pThis->m_pVTab->m_pDrawBK_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));
			}}

			// 左
			rt.m_ptLT.m_nY=rtWnd.m_ptLT.m_nY+pThis->m_nTBBorderHeight+pThis->m_nTopMargin;
			rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nLeftMargin;
			rt.m_ptRB.m_nY=rtWnd.m_ptRB.m_nY-pThis->m_nTBBorderHeight-pThis->m_nBottomMargin;
			if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
			{
				pThis->m_pVTab->m_pDrawBK_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));
			}}

			// 右
			rt.m_ptLT.m_nX=rtWnd.m_ptRB.m_nX-pThis->m_nLRBorderWidth-pThis->m_nRightMargin-pThis->m_nScrollBarWidth;
			rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nRightMargin;
			if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
			{
				pThis->m_pVTab->m_pDrawBK_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));
			}}
		}

		// 画中间Item
		rt.m_ptLT.m_nY=pThis->m_nTBBorderHeight+pThis->m_nTopMargin;
		{int i,j;
		for(i=0;i<pThis->m_nHeightDrawItemCount;++i){
		{
			rt.m_ptLT.m_nX=pThis->m_nLRBorderWidth+pThis->m_nLeftMargin;
			rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_oDrawItemSize.m_nHeight;

			for(j=0;j<pThis->m_nWidthDrawItemCount;++j){
			{
				int nIndex=i*pThis->m_nWidthDrawItemCount+j+pThis->m_nDrawItemStartIndex;
				rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_oDrawItemSize.m_nWidth;

				if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
				{
					if(nIndex>=pThis->m_nItemCount){
					{
						// 画背景
						pThis->m_pVTab->m_pDrawBK_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));
					}}
					else
					{{
						if(pThis->m_nCurItemIndex==nIndex){
						{
							// 选中
							pThis->m_pVTab->m_pDrawItem_IAwsGc1p_CEspRect1p_i0p_i0p(pThis,pGc,&(rt),nIndex,1);
						}}
						else
						{{
							// 没选中
							pThis->m_pVTab->m_pDrawItem_IAwsGc1p_CEspRect1p_i0p_i0p(pThis,pGc,&(rt),nIndex,0);
						}}
					}}
				}}

				rt.m_ptLT.m_nX+=pThis->m_oDrawItemSize.m_nWidth;
			}}

			rt.m_ptLT.m_nY+=pThis->m_oDrawItemSize.m_nHeight;
		}}
	}}}

	CAwsContainer_OnDraw_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),rect);
}
}

void CBListView_GetItemRectFromIndex_i0p_CEspRect1p(CBListView* pThis, int nIndex,CEspRect * rect)
{
	int n=nIndex-pThis->m_nDrawItemStartIndex;

	int nRow=n/pThis->m_nWidthDrawItemCount;
	int nCol=n%pThis->m_nWidthDrawItemCount;

	rect->m_ptLT.m_nX=pThis->m_nLRBorderWidth+pThis->m_nLeftMargin+nCol*pThis->m_oDrawItemSize.m_nWidth;
	rect->m_ptLT.m_nY=pThis->m_nTBBorderHeight+pThis->m_nTopMargin+nRow*pThis->m_oDrawItemSize.m_nHeight;
	rect->m_ptRB.m_nX=rect->m_ptLT.m_nX+pThis->m_oDrawItemSize.m_nWidth;
	rect->m_ptRB.m_nY=rect->m_ptLT.m_nY+pThis->m_oDrawItemSize.m_nHeight;
}

int CBListView_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CBListView* pThis = (CBListView*)this;{
	CEspRect rt;

	CEspRect_CInit(&(rt));
if(AWS_Key==type){
	{
		switch(code)
		{
		case AWS_KeyCode_UpArrow:
			{
				int n=(pThis->m_nCurItemIndex-pThis->m_nDrawItemStartIndex)/pThis->m_nWidthDrawItemCount;
				if(n>0){
				{
					// 只需调整CurItem索引到上一行
					n=pThis->m_nCurItemIndex;
					pThis->m_nCurItemIndex-=pThis->m_nWidthDrawItemCount;

					// 重绘先前焦点Item
					CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,n,&(rt));
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

					// 重绘当前焦点Item
					CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,pThis->m_nCurItemIndex,&(rt));
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
				else
				{{
					if(pThis->m_nDrawItemStartIndex>0){
					{
						// 整体向上更新一行
						pThis->m_nDrawItemStartIndex-=pThis->m_nWidthDrawItemCount;
						pThis->m_nCurItemIndex-=pThis->m_nWidthDrawItemCount;

						rt.m_ptLT.m_nX=pThis->m_nLRBorderWidth+pThis->m_nLeftMargin;
						rt.m_ptLT.m_nY=pThis->m_nTBBorderHeight+pThis->m_nTopMargin;
						rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nWidthDrawItemCount*pThis->m_oDrawItemSize.m_nWidth;
						rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nHeightDrawItemCount*pThis->m_oDrawItemSize.m_nHeight;
						pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

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
						// 需要跳跃，跳到对应列的最后一个，如果没有，则跳到最后一个Item
						n=pThis->m_nCurItemIndex;
						pThis->m_nCurItemIndex+=pThis->m_nWidthDrawItemCount*((pThis->m_nItemCount-1)/pThis->m_nWidthDrawItemCount);
						if(pThis->m_nCurItemIndex>=pThis->m_nItemCount){
						{
							pThis->m_nCurItemIndex=pThis->m_nItemCount-1;
						}}

						// 看看m_nDrawItemStartIndex是否有变化
						if((pThis->m_nCurItemIndex-pThis->m_nDrawItemStartIndex)/pThis->m_nWidthDrawItemCount<pThis->m_nHeightDrawItemCount){
						{
							// m_nDrawItemStartIndex没变化，只需更新两个Item
							CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,n,&(rt));
							pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

							CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,pThis->m_nCurItemIndex,&(rt));
							pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
						}}
						else
						{{
							// 改变DrawStart
							pThis->m_nDrawItemStartIndex=pThis->m_nCurItemIndex-(pThis->m_nCurItemIndex)%pThis->m_nWidthDrawItemCount-(pThis->m_nHeightDrawItemCount-1)*pThis->m_nWidthDrawItemCount;

							// 更新所有Item
							rt.m_ptLT.m_nX=pThis->m_nLRBorderWidth+pThis->m_nLeftMargin;
							rt.m_ptLT.m_nY=pThis->m_nTBBorderHeight+pThis->m_nTopMargin;
							rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nWidthDrawItemCount*pThis->m_oDrawItemSize.m_nWidth;
							rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nHeightDrawItemCount*pThis->m_oDrawItemSize.m_nHeight;
							pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

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
					}}
				}}
			}
			return 1;

		case AWS_KeyCode_DownArrow:
			{
				int n=(pThis->m_nCurItemIndex+pThis->m_nWidthDrawItemCount-pThis->m_nDrawItemStartIndex)/pThis->m_nWidthDrawItemCount;
				if(n<pThis->m_nHeightDrawItemCount){
				{
					// 只需调整CurItem索引到下一行
					n=pThis->m_nCurItemIndex;
					if(pThis->m_nCurItemIndex+pThis->m_nWidthDrawItemCount>pThis->m_nItemCount-1){
					{
						pThis->m_nCurItemIndex=pThis->m_nItemCount-1;
					}}
					else
					{{
						pThis->m_nCurItemIndex+=pThis->m_nWidthDrawItemCount;
					}}

					// 重绘先前焦点Item
					CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,n,&(rt));
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

					// 重绘当前焦点Item
					CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,pThis->m_nCurItemIndex,&(rt));
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
				else
				{{
					n=pThis->m_nCurItemIndex;
					if(pThis->m_nCurItemIndex+pThis->m_nWidthDrawItemCount<pThis->m_nItemCount){
					{
						pThis->m_nCurItemIndex+=pThis->m_nWidthDrawItemCount;
						// 整体向下更新一行
						pThis->m_nDrawItemStartIndex+=pThis->m_nWidthDrawItemCount;

						rt.m_ptLT.m_nX=pThis->m_nLRBorderWidth+pThis->m_nLeftMargin;
						rt.m_ptLT.m_nY=pThis->m_nTBBorderHeight+pThis->m_nTopMargin;
						rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nWidthDrawItemCount*pThis->m_oDrawItemSize.m_nWidth;
						rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nHeightDrawItemCount*pThis->m_oDrawItemSize.m_nHeight;
						pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

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
						// 看最后一个和当前是否在同一行，如果在同一行则转到最后，否则跳到对应的最开头
						if((pThis->m_nItemCount-1)/pThis->m_nWidthDrawItemCount>pThis->m_nCurItemIndex/pThis->m_nWidthDrawItemCount){
						{
							// 转到最后
							pThis->m_nDrawItemStartIndex+=pThis->m_nWidthDrawItemCount;
							pThis->m_nCurItemIndex=pThis->m_nItemCount-1;

							rt.m_ptLT.m_nX=pThis->m_nLRBorderWidth+pThis->m_nLeftMargin;
							rt.m_ptLT.m_nY=pThis->m_nTBBorderHeight+pThis->m_nTopMargin;
							rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nWidthDrawItemCount*pThis->m_oDrawItemSize.m_nWidth;
							rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nHeightDrawItemCount*pThis->m_oDrawItemSize.m_nHeight;
							pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

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
							// 跳到对应的最开头
							if(pThis->m_nItemCount<=pThis->m_nWidthDrawItemCount*pThis->m_nHeightDrawItemCount){
							{
								pThis->m_nCurItemIndex=n%pThis->m_nWidthDrawItemCount;
								// 只需要更新两个
								CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,n,&(rt));
								pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

								CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,pThis->m_nCurItemIndex,&(rt));
								pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
							}}
							else
							{{
								// 全部更新
								pThis->m_nDrawItemStartIndex=0;
								pThis->m_nCurItemIndex=n%pThis->m_nWidthDrawItemCount;

								rt.m_ptLT.m_nX=pThis->m_nLRBorderWidth+pThis->m_nLeftMargin;
								rt.m_ptLT.m_nY=pThis->m_nTBBorderHeight+pThis->m_nTopMargin;
								rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nWidthDrawItemCount*pThis->m_oDrawItemSize.m_nWidth;
								rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nHeightDrawItemCount*pThis->m_oDrawItemSize.m_nHeight;
								pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

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
						}}
					}}
				}}
			}
			return 1;

		case AWS_KeyCode_LeftArrow:
			if(pThis->m_nCurItemIndex>pThis->m_nDrawItemStartIndex){
			{
				// 只需更新显示两个
				--pThis->m_nCurItemIndex;
				CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,pThis->m_nCurItemIndex+1,&(rt));
				pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

				CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,pThis->m_nCurItemIndex,&(rt));
				pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
			}}
			else
			{{
				if(0==pThis->m_nCurItemIndex){
				{
					pThis->m_nCurItemIndex=pThis->m_nItemCount-1;

					// 如果一屏幕可以显示所有的Item，则只需要更新显示两个；如果一屏幕显示不下，则需要全部更新
					if(pThis->m_nHeightDrawItemCount*pThis->m_nWidthDrawItemCount>=pThis->m_nItemCount){
					{
						CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,0,&(rt));
						pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

						CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,pThis->m_nCurItemIndex,&(rt));
						pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));						
					}}
					else
					{{
						// 改变DrawStart
						pThis->m_nDrawItemStartIndex=pThis->m_nCurItemIndex-(pThis->m_nItemCount-1)%pThis->m_nWidthDrawItemCount-(pThis->m_nHeightDrawItemCount-1)*pThis->m_nWidthDrawItemCount;

						rt.m_ptLT.m_nX=pThis->m_nLRBorderWidth+pThis->m_nLeftMargin;
						rt.m_ptLT.m_nY=pThis->m_nTBBorderHeight+pThis->m_nTopMargin;
						rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nWidthDrawItemCount*pThis->m_oDrawItemSize.m_nWidth;
						rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nHeightDrawItemCount*pThis->m_oDrawItemSize.m_nHeight;
						pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

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
				}}
				else
				{{
					// 全部更新
					pThis->m_nDrawItemStartIndex-=pThis->m_nWidthDrawItemCount;
					--pThis->m_nCurItemIndex;

					rt.m_ptLT.m_nX=pThis->m_nLRBorderWidth+pThis->m_nLeftMargin;
					rt.m_ptLT.m_nY=pThis->m_nTBBorderHeight+pThis->m_nTopMargin;
					rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nWidthDrawItemCount*pThis->m_oDrawItemSize.m_nWidth;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nHeightDrawItemCount*pThis->m_oDrawItemSize.m_nHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

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
			}}
			return 1;

		case AWS_KeyCode_RightArrow:
			{
				int n=pThis->m_nDrawItemStartIndex+pThis->m_nWidthDrawItemCount*pThis->m_nHeightDrawItemCount;
				if(n>pThis->m_nItemCount){
				{
					n=pThis->m_nItemCount;
				}}
				if(pThis->m_nCurItemIndex<n-1){
				{
					// 只需更新显示两个
					++pThis->m_nCurItemIndex;
					CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,pThis->m_nCurItemIndex-1,&(rt));
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

					CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,pThis->m_nCurItemIndex,&(rt));
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
				else
				{{
					if(pThis->m_nItemCount-1==pThis->m_nCurItemIndex){
					{
						pThis->m_nCurItemIndex=0;

						// 如果一屏幕可以显示所有的Item，则只需要更新显示两个；如果一屏幕显示不下，则需要全部更新
						if(pThis->m_nHeightDrawItemCount*pThis->m_nWidthDrawItemCount>=pThis->m_nItemCount){
						{
							CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,pThis->m_nItemCount-1,&(rt));
							pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

							CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,pThis->m_nCurItemIndex,&(rt));
							pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));						
						}}
						else
						{{
							pThis->m_nDrawItemStartIndex=0;

							rt.m_ptLT.m_nX=pThis->m_nLRBorderWidth+pThis->m_nLeftMargin;
							rt.m_ptLT.m_nY=pThis->m_nTBBorderHeight+pThis->m_nTopMargin;
							rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nWidthDrawItemCount*pThis->m_oDrawItemSize.m_nWidth;
							rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nHeightDrawItemCount*pThis->m_oDrawItemSize.m_nHeight;
							pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

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
					}}
					else
					{{
						// 全部更新
						pThis->m_nDrawItemStartIndex+=pThis->m_nWidthDrawItemCount;
						++pThis->m_nCurItemIndex;

						rt.m_ptLT.m_nX=pThis->m_nLRBorderWidth+pThis->m_nLeftMargin;
						rt.m_ptLT.m_nY=pThis->m_nTBBorderHeight+pThis->m_nTopMargin;
						rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nWidthDrawItemCount*pThis->m_oDrawItemSize.m_nWidth;
						rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nHeightDrawItemCount*pThis->m_oDrawItemSize.m_nHeight;
						pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

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
				}}

			}
			return 1;

		case AWS_KeyCode_OK:
			CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_ListViewCmd,pThis->m_nCurItemIndex,0);
			return 1;
		}
	}}

	if(AWS_Key_Up==type){
	{
		// 响应0-9、*、#的对应
		if(code>=AWS_KeyCode_1&&code<=AWS_KeyCode_Well){
		{
			int nIndex=code-AWS_KeyCode_1;
			if(nIndex<pThis->m_nItemCount){
			{
				// 重绘前focus窗口
				int n=pThis->m_nCurItemIndex;
				CEspRect rect;
				CEspRect_CInit(&(rect));
pThis->m_nCurItemIndex=nIndex;

				if(pThis->m_nCurItemIndex>=pThis->m_nDrawItemStartIndex&&(pThis->m_nCurItemIndex-pThis->m_nDrawItemStartIndex)<pThis->m_nWidthDrawItemCount*pThis->m_nHeightDrawItemCount-1){
				{
					CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,n,&(rect));
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rect));

					CBListView_GetItemRectFromIndex_i0p_CEspRect1p(pThis,pThis->m_nCurItemIndex,&(rect));
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rect));
				}}
				else
				{{
					pThis->m_nDrawItemStartIndex=0;

					rt.m_ptLT.m_nX=pThis->m_nLRBorderWidth+pThis->m_nLeftMargin;
					rt.m_ptLT.m_nY=pThis->m_nTBBorderHeight+pThis->m_nTopMargin;
					rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nWidthDrawItemCount*pThis->m_oDrawItemSize.m_nWidth;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nHeightDrawItemCount*pThis->m_oDrawItemSize.m_nHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

					pThis->m_nScrollPos=0;
					CBScrollBar_SetCurPos_i0p(pThis->m_pScrollBar,pThis->m_nScrollPos);
				}}

				return pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pOnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),AWS_Key,AWS_KeyCode_OK);
			}}
		}}
	}}

	return CAwsContainer_OnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);
}
}

void CBListView_OnSize_CEspSize1p_i0p(CAwsWindow* this, const CEspSize * size,int bIsRedraw)
{

	CBListView* pThis = (CBListView*)this;{
	CAwsContainer_OnSize_CEspSize1p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),size,bIsRedraw);

	if(ESP_NULL!=pThis->m_pScrollBar){
	{
		CEspRect rt;
		CEspRect_CInit(&(rt));
rt.m_ptLT.m_nX=size->m_nWidth-pThis->m_nScrollBarWidth-pThis->m_nLRBorderWidth;
		rt.m_ptLT.m_nY=pThis->m_nTBBorderHeight;
		rt.m_ptRB.m_nX=size->m_nWidth-pThis->m_nLRBorderWidth;
		rt.m_ptRB.m_nY=size->m_nHeight-pThis->m_nTBBorderHeight;

		CAwsWindow_MoveTo_CEspRect1p_i0p(&(pThis->m_pScrollBar->m_oBase_CAwsWindow),&(rt),bIsRedraw);
	}}
}
}
