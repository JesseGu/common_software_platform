/******************************************************************************
* FileName		       : BSelectBox.cpp
* Description          : implementation of the CBSelectBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BSelectBox.h"
const VTab_CBSelectBox g_tVTab_CBSelectBox_CBSelectBox = {CBSelectBox_DrawBorder_IAwsGc1p_CEspRect1p, CBSelectBox_DrawBK_IAwsGc1p_CEspRect1p, CBSelectBox_DrawLeftArrow_IAwsGc1p_CEspRect1p_i0p, CBSelectBox_DrawRightArrow_IAwsGc1p_CEspRect1p_i0p, CBSelectBox_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p};
const VTab_CAwsWindow g_tVTab_CBSelectBox_CAwsWindow = {CBSelectBox_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CBSelectBox_OnDraw_CEspRect1p, CBSelectBox_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CBSelectBox_OnFocus_i0p, CAwsWindow_OnTimer, CAwsWindow_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CAwsWindow_OnCreate};
void CBSelectBox_CInit(CBSelectBox* pThis)
{
CAwsWindow_CInit(&(pThis->m_oBase_CAwsWindow));
CEspSize_CInit_i0p_i0p(&(pThis->m_oItemSize),0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oArrowColor),0,0,0);
CAwsImage_CInit(&(pThis->m_oImageSelectBK));
CAwsImage_CInit(&(pThis->m_oImageMask));
	pThis->m_pVTab = &g_tVTab_CBSelectBox_CBSelectBox;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBSelectBox_CAwsWindow;
}

void CBSelectBox_SetArrowColor_CAwsRgb1p(CBSelectBox* pThis, const CAwsRgb * color) { pThis->m_oArrowColor=*color; } 

void CBSelectBox_SetItemRegionSize_CEspSize1p(CBSelectBox* pThis, const CEspSize * size) { pThis->m_oItemSize=*size; } 

void CBSelectBox_SetRightMargin_i0p(CBSelectBox* pThis, int nRightMargin) { pThis->m_nRightMargin=nRightMargin; } 

void CBSelectBox_SetLeftMargin_i0p(CBSelectBox* pThis, int nLeftMargin) { pThis->m_nLeftMargin=nLeftMargin; } 

void CBSelectBox_SetTextFontSize_i0p(CBSelectBox* pThis, int nSize) { pThis->m_nFontSize=nSize; } 

void CBSelectBox_SetFocusTextColor_CAwsRgb1p(CBSelectBox* pThis, const CAwsRgb * color) { pThis->m_oFocusTextColor=*color; } 

void CBSelectBox_SetTextColor_CAwsRgb1p(CBSelectBox* pThis, const CAwsRgb * color) { pThis->m_oTextColor=*color; } 

#include "IAwsGc.h"

void CBSelectBox_CInit_i0p(CBSelectBox* pThis, int nMaxItemCount)
{

CAwsWindow_CInit(&(pThis->m_oBase_CAwsWindow));
CEspSize_CInit_i0p_i0p(&(pThis->m_oItemSize),0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusTextColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oArrowColor),0,0,0);
CAwsImage_CInit(&(pThis->m_oImageSelectBK));
CAwsImage_CInit(&(pThis->m_oImageMask));
	pThis->m_pVTab = &g_tVTab_CBSelectBox_CBSelectBox;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBSelectBox_CAwsWindow;
{
	pThis->m_nMaxItemCount=nMaxItemCount;
	pThis->m_nItemCount=0;
	pThis->m_nCurItemIndex=0;

	{CAwsString(*pHeapObj_1)=(CAwsString(*))((char*)malloc(sizeof(CAwsString)*pThis->m_nMaxItemCount+sizeof(unsigned int))+sizeof(unsigned int));
*((unsigned int*)((char*)pHeapObj_1-sizeof(unsigned int)))=pThis->m_nMaxItemCount;{int i0;for(i0=0;i0<pThis->m_nMaxItemCount;++i0){CAwsString_CInit_i0p(pHeapObj_1+i0,100);}}
{pThis->m_pItemData=pHeapObj_1;

	pThis->m_nDrawItemCount=0;
	pThis->m_nDrawItemStartIndex=0;

	pThis->m_oItemSize.m_nWidth=30;
	pThis->m_oItemSize.m_nHeight=20;

	pThis->m_nLeftMargin=10;
	pThis->m_nRightMargin=10;
	pThis->m_nBorderWidth=1;

	{CAwsRgb rgbBorder,rgbFocusBorder,rgbText,rgbFocusText,rgbBK,rgbArrow;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbBorder,123,123,123);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbFocusBorder,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbFocusText,255,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,100,100,100);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbArrow,0,0,0);
pThis->m_oBorderColor=rgbBorder;
	pThis->m_oFocusBorderColor=rgbFocusBorder;
	pThis->m_oTextColor=rgbText;
	pThis->m_oFocusTextColor=rgbFocusText;
	pThis->m_oBKColor=rgbBK;
	pThis->m_oArrowColor=rgbArrow;

	pThis->m_nFontSize=12;

	pThis->m_bIsSetImageSelectBK=0;
}}}}
}

void CBSelectBox_DUninit_i1p(CAwsWindow* this, int * pOffset)
{

	CBSelectBox* pThis = (CBSelectBox*)this;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsWindow_DUninit_i1p(&(pThis->m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBSelectBox*)0)->m_oBase_CAwsWindow));
{
	{int nOffset = 0;unsigned int* p=(unsigned int*)((char*)(pThis->m_pItemData)-sizeof(unsigned int));int i,nSize=*p;for(i=0;i<nSize;++i)CAwsString_DUninit_i1p(pThis->m_pItemData+i, &nOffset);free(p);};
}
}

void CBSelectBox_AddItem_CAwsString1p(CBSelectBox* pThis, const CAwsString * strText)
{
	if(pThis->m_nItemCount<pThis->m_nMaxItemCount){
	{
		pThis->m_pItemData[pThis->m_nItemCount++]=*strText;
	}}
}

void CBSelectBox_AddItemEnd(CBSelectBox* pThis)
{
	CEspSize size=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow));

	// 计算最多能Draw多少个
	pThis->m_nDrawItemCount=(size.m_nWidth-pThis->m_nLeftMargin-pThis->m_nRightMargin)/pThis->m_oItemSize.m_nWidth;
}

void CBSelectBox_SetSelectImage_CAwsImage1p_CAwsImage1p(CBSelectBox* pThis, const CAwsImage * imageSelectBK,const CAwsImage * imageMask)
{
	pThis->m_oImageSelectBK=*imageSelectBK;
	pThis->m_oImageMask=*imageMask;

	pThis->m_bIsSetImageSelectBK=1;
}

void CBSelectBox_DrawBorder_IAwsGc1p_CEspRect1p(CBSelectBox* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	if(pThis->m_oBase_CAwsWindow.m_bIsFocus){
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oFocusBorderColor));}
	else
		 {pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBorderColor));}
	pGc->m_pVTab->m_pDrawRect_CEspRect1p(pGc,rect);
}

void CBSelectBox_DrawBK_IAwsGc1p_CEspRect1p(CBSelectBox* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);
}

void CBSelectBox_DrawLeftArrow_IAwsGc1p_CEspRect1p_i0p(CBSelectBox* pThis, IAwsGc *  pGc,const CEspRect * rect,int bIsDrawArrow)
{
	if(bIsDrawArrow){
	{
		// 画左箭头
		CEspPoint ptStart,ptEnd;
		CEspPoint_CInit_i0p_i0p(&(ptStart),0,0);
CEspPoint_CInit_i0p_i0p(&(ptEnd),0,0);
ptStart.m_nX=rect->m_ptLT.m_nX+(pThis->m_nLeftMargin-4)/2;
		ptStart.m_nY=(rect->m_ptLT.m_nY+rect->m_ptRB.m_nY)/2;
		ptEnd.m_nX=ptStart.m_nX;
		ptEnd.m_nY=ptStart.m_nY+1;
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oArrowColor));
		{int i;
		for(i=0;i<4;++i){
		{
			pGc->m_pVTab->m_pDrawLine_CEspPoint1p_CEspPoint1p(pGc,&(ptStart),&(ptEnd));
			ptStart.m_nX+=1;
			ptStart.m_nY-=1;

			ptEnd.m_nX=ptStart.m_nX;
			ptEnd.m_nY+=1;
		}}
	}}}
}

void CBSelectBox_DrawRightArrow_IAwsGc1p_CEspRect1p_i0p(CBSelectBox* pThis, IAwsGc *  pGc,const CEspRect * rect,int bIsDrawArrow)
{
	if(bIsDrawArrow){
	{
		// 画右箭头
		CEspPoint ptStart,ptEnd;
		CEspPoint_CInit_i0p_i0p(&(ptStart),0,0);
CEspPoint_CInit_i0p_i0p(&(ptEnd),0,0);
ptStart.m_nX=rect->m_ptRB.m_nX-pThis->m_nRightMargin+(pThis->m_nRightMargin-4)/2;
		ptStart.m_nY=(rect->m_ptLT.m_nY+rect->m_ptRB.m_nY)/2-3;
		ptEnd.m_nX=ptStart.m_nX;
		ptEnd.m_nY=ptStart.m_nY+7;
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oArrowColor));
		{int i;
		for(i=0;i<4;++i){
		{
			pGc->m_pVTab->m_pDrawLine_CEspPoint1p_CEspPoint1p(pGc,&(ptStart),&(ptEnd));
			ptStart.m_nX+=1;
			ptStart.m_nY+=1;

			ptEnd.m_nX=ptStart.m_nX;
			ptEnd.m_nY-=1;
		}}
	}}}
}

void CBSelectBox_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p(CBSelectBox* pThis, IAwsGc *  pGc,const CEspRect * rect,int nItemIndex,int bIsSelect)
{
	if(bIsSelect){
	{
		if(pThis->m_bIsSetImageSelectBK){
		{
			// 设置选中的背景
			pGc->m_pVTab->m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(pGc,&(rect->m_ptLT),&(pThis->m_oImageSelectBK),&pThis->m_oImageMask);
		}}
		pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oFocusTextColor));
	}}
	else
	{{
		pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oTextColor));
	}}

	pGc->m_pVTab->m_pSetTextAlignment_0p(pGc,AWS_TAM_Mid);

	CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
	pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));
	{const CEspSize *  size=pGc->m_pVTab->m_pGetTextSize_CAwsString1p(pGc,&(pThis->m_pItemData[nItemIndex]));
	CEspRect rt=*(rect);
	rt.m_ptLT.m_nY=rt.m_ptLT.m_nY+(CEspRect_GetSize(rect)->m_nHeight-size->m_nHeight)/2;

	pGc->m_pVTab->m_pDrawText_CAwsString1p_CEspRect1p(pGc,&(pThis->m_pItemData[nItemIndex]),&(rt));
	pGc->m_pVTab->m_pDiscardFont(pGc);
}}

void CBSelectBox_OnFocus_i0p(CAwsWindow* this, int bIsFocus)
{

	CBSelectBox* pThis = (CBSelectBox*)this;{
	CAwsWindow_OnFocus_i0p(&(pThis->m_oBase_CAwsWindow),bIsFocus);

	CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));
}
}

void CBSelectBox_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CBSelectBox* pThis = (CBSelectBox*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsWindow));
	CEspRect rt,rtTemp;

	CEspSize size=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow));
	CEspRect_CInit(&(rt));
CEspRect_CInit(&(rtTemp));
rt.m_ptRB.m_nY=size.m_nHeight;
	// 画背景
	if(!pThis->m_oBase_CAwsWindow.m_bIsBKTransparent){
	{
		CEspRect rtTemp;
		CEspRect_CInit_i0p_i0p_i0p_i0p(&rtTemp,0,0,size.m_nWidth,size.m_nHeight);
pThis->m_pVTab->m_pDrawBorder_IAwsGc1p_CEspRect1p(pThis,pGc,&(rtTemp));

		rtTemp=*rect;
		rtTemp.m_ptLT.m_nY+=pThis->m_nBorderWidth;
		rtTemp.m_ptRB.m_nY-=pThis->m_nBorderWidth;

		if(rect->m_ptLT.m_nX==0){
			rtTemp.m_ptLT.m_nX=pThis->m_nBorderWidth;}
		if(rect->m_ptRB.m_nX==size.m_nWidth){
			rtTemp.m_ptRB.m_nX-=pThis->m_nBorderWidth;}
		pThis->m_pVTab->m_pDrawBK_IAwsGc1p_CEspRect1p(pThis,pGc,&(rtTemp));
	}}

	// 画左边箭头
	rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nLeftMargin;

	if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
	{
		if(pThis->m_nCurItemIndex>0){
		{
			pThis->m_pVTab->m_pDrawLeftArrow_IAwsGc1p_CEspRect1p_i0p(pThis,pGc,&(rt),1);
		}}
		else
		{{
			pThis->m_pVTab->m_pDrawLeftArrow_IAwsGc1p_CEspRect1p_i0p(pThis,pGc,&(rt),0);
		}}
	}}

	rt.m_ptLT.m_nX=rt.m_ptRB.m_nX;
	rt.m_ptRB.m_nX+=pThis->m_oItemSize.m_nWidth;
	// 画Item
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

		rt.m_ptLT.m_nX+=pThis->m_oItemSize.m_nWidth;
		rt.m_ptRB.m_nX+=pThis->m_oItemSize.m_nWidth;
	}}

	//  画右边箭头
	if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
	{
		if(pThis->m_nCurItemIndex<pThis->m_nItemCount-1){
		{
			rt.m_ptRB.m_nX=rect->m_ptRB.m_nX;
			pThis->m_pVTab->m_pDrawRightArrow_IAwsGc1p_CEspRect1p_i0p(pThis,pGc,&(rt),1);
		}}
		else
		{{
			pThis->m_pVTab->m_pDrawRightArrow_IAwsGc1p_CEspRect1p_i0p(pThis,pGc,&(rt),0);
		}}
	}}
}}
}

int CBSelectBox_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CBSelectBox* pThis = (CBSelectBox*)this;{
	CEspRect rt;
	CEspRect_CInit(&(rt));
rt.m_ptLT.m_nY=0;
	rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_oItemSize.m_nHeight;

	if(AWS_Key==type){
	{
		switch(code)
		{
		case AWS_KeyCode_LeftArrow:
			if(pThis->m_nCurItemIndex>0){
			{
				--pThis->m_nCurItemIndex;
				if(pThis->m_nItemCount-2==pThis->m_nCurItemIndex){
				{
					// 显示右箭头
					rt.m_ptRB.m_nX=CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow))->m_nWidth;
					rt.m_ptLT.m_nX=rt.m_ptRB.m_nX-pThis->m_nRightMargin;
					rt.m_ptLT.m_nY=0;
					rt.m_ptRB.m_nY=CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow))->m_nHeight;
					pThis->m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsWindow),&(rt));
				}}

				if(pThis->m_nCurItemIndex<pThis->m_nDrawItemStartIndex){
				{
					pThis->m_nDrawItemStartIndex=pThis->m_nCurItemIndex;
					// 全都要移动
					CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));
				}}
				else
				{{
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_oItemSize.m_nHeight;
					// 只需要移动两个
					rt.m_ptLT.m_nX=pThis->m_nLeftMargin+(pThis->m_nCurItemIndex-pThis->m_nDrawItemStartIndex)*pThis->m_oItemSize.m_nWidth;
					rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_oItemSize.m_nWidth*2;
					pThis->m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsWindow),&(rt));
				}}

				if(0==pThis->m_nCurItemIndex){
				{
					// 关闭左箭头显示
					rt.m_ptLT.m_nX=0;
					rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nLeftMargin;
					rt.m_ptLT.m_nY=0;
					rt.m_ptRB.m_nY=CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow))->m_nHeight;
					pThis->m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsWindow),&(rt));
				}}

				CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsWindow),pThis->m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_SelectBoxFocusItemChange,pThis->m_nCurItemIndex,0);
			}}
			return 1;

		case AWS_KeyCode_RightArrow:
			if(pThis->m_nCurItemIndex<pThis->m_nItemCount-1){
			{
				++pThis->m_nCurItemIndex;

				if(1==pThis->m_nCurItemIndex){
				{
					// 显示左箭头
					rt.m_ptLT.m_nX=0;
					rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nLeftMargin;
					rt.m_ptLT.m_nY=0;
					rt.m_ptRB.m_nY=CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow))->m_nHeight;
					pThis->m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsWindow),&(rt));
				}}

				if(pThis->m_nCurItemIndex-pThis->m_nDrawItemStartIndex>=pThis->m_nDrawItemCount){
				{
					++pThis->m_nDrawItemStartIndex;
					CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));
				}}
				else
				{{
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_oItemSize.m_nHeight;
					// 只需要移动两个
					rt.m_ptLT.m_nX=pThis->m_nLeftMargin+(pThis->m_nCurItemIndex-1-pThis->m_nDrawItemStartIndex)*pThis->m_oItemSize.m_nWidth;
					rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_oItemSize.m_nWidth*2;
					pThis->m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsWindow),&(rt));
				}}

				if(pThis->m_nItemCount-1==pThis->m_nCurItemIndex){
				{
					// 关闭显示右箭头
					rt.m_ptRB.m_nX=CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow))->m_nWidth;
					rt.m_ptLT.m_nX=rt.m_ptRB.m_nX-pThis->m_nRightMargin;
					rt.m_ptLT.m_nY=0;
					rt.m_ptRB.m_nY=CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow))->m_nHeight;
					pThis->m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsWindow),&(rt));
				}}

				CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsWindow),pThis->m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_SelectBoxFocusItemChange,pThis->m_nCurItemIndex,0);
			}}
			return 1;

		case AWS_KeyCode_OK:
			CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsWindow),pThis->m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_SelectBoxCmd,pThis->m_nCurItemIndex,0);
			return 1;
		}
	}}

	return CAwsWindow_OnKey_0p_0p(&(pThis->m_oBase_CAwsWindow),type,code);
}
}
