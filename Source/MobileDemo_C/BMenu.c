/******************************************************************************
* FileName		       : BMenu.cpp
* Description          : implementation of the CBMenu class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BMenu.h"
#include "IAwsGc.h"

void CBMenu_CInit_CAwsWindow1p_i0p_i0p_i0p(CBMenu* pThis, CAwsWindow *  pWnd,int nMaxItemCount,int nPopedMenu,int bIsSubMenu)
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
{
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pParent=pWnd;

	pThis->m_nItemCount=0;
	pThis->m_nFocusItemIndex=0;
	pThis->m_nDrawItemCount=0;
	pThis->m_nDrawItemStartIndex=0;

	pThis->m_nMaxItemCount=nMaxItemCount;

	pThis->m_nMaxShowItemCount=10;
	pThis->m_nFullBorderPixel=1;
	pThis->m_nTBBorderHeight=12;
	pThis->m_nItemHeight=23;
	pThis->m_nMenuWidth=82;
	pThis->m_nItemLeftMargin=5;
	pThis->m_nItemRightMargin=10;

	pThis->m_nFontSize=12;

	{CBMenu_TItemData(*pHeapObj_1)=(CBMenu_TItemData(*))((char*)malloc(sizeof(CBMenu_TItemData)*pThis->m_nMaxItemCount+sizeof(unsigned int))+sizeof(unsigned int));
*((unsigned int*)((char*)pHeapObj_1-sizeof(unsigned int)))=pThis->m_nMaxItemCount;{int i0;for(i0=0;i0<pThis->m_nMaxItemCount;++i0){CBMenu_TItemData_CInit(pHeapObj_1+i0);}}
{pThis->m_pItemData=pHeapObj_1;

	{CAwsRgb rgbFocusText,rgbText,rgbFocusBK,rgbBK,rgbBorder,rgbArrow;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbFocusText,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,173,154,132);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbFocusBK,24,24,20);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,62,59,53);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBorder,101,99,94);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbArrow,255,255,255);
pThis->m_oFocusTextColor=rgbFocusText;
	pThis->m_oTextColor=rgbText;
	pThis->m_oFocusBKColor=rgbFocusBK;
	pThis->m_oBKColor=rgbBK;
	pThis->m_oBorderColor=rgbBorder;
	pThis->m_oArrowColor=rgbArrow;

	pThis->m_bIsSubMenu=bIsSubMenu;

	pThis->m_bIsPopupOnly=0;

	pThis->m_nPopMenuCount=nPopedMenu+1;
}}}}
}

void CBMenu_DUninit_i1p(CAwsWindow* this, int * pOffset)
{

	CBMenu* pThis = (CBMenu*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBMenu*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
{
	{int nOffset = 0;unsigned int* p=(unsigned int*)((char*)(pThis->m_pItemData)-sizeof(unsigned int));int i,nSize=*p;for(i=0;i<nSize;++i)CBMenu_TItemData_DUninit_i1p(pThis->m_pItemData+i, &nOffset);free(p);};
	pThis->m_pItemData=ESP_NULL;
}
}

void CBMenu_OnCreate(CAwsWindow* this)
{

	CBMenu* pThis = (CBMenu*)this;{
	// 在此改写属性
}
}

int CBMenu_AddItem_CAwsString1p_i0p(CBMenu* pThis, const CAwsString * strText,int nSubMenuID)
{
	int bRet=0;

	if(pThis->m_nItemCount<pThis->m_nMaxItemCount){
	{
		pThis->m_pItemData[pThis->m_nItemCount].m_strText=*strText;
		pThis->m_pItemData[pThis->m_nItemCount++].m_nSubMenuID=nSubMenuID;

		{IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
		CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
		pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));
		{const CEspSize *  size=pGc->m_pVTab->m_pGetTextSize_CAwsString1p(pGc,strText);
		if(size->m_nWidth>pThis->m_oMaxTextSize.m_nWidth){
			pThis->m_oMaxTextSize.m_nWidth=size->m_nWidth;}

		if(size->m_nHeight>pThis->m_oMaxTextSize.m_nHeight){
			pThis->m_oMaxTextSize.m_nHeight=size->m_nHeight;}

		bRet=1;
	}}}}

	return bRet;
}

void CBMenu_AddItemEnd(CBMenu* pThis)
{
	if(pThis->m_nItemCount>=pThis->m_nMaxShowItemCount){
		pThis->m_nDrawItemCount=pThis->m_nMaxShowItemCount;}
	else
		{pThis->m_nDrawItemCount=pThis->m_nItemCount;}

	// 调整窗口宽度
	if(pThis->m_oMaxTextSize.m_nWidth+pThis->m_nItemLeftMargin+pThis->m_nItemRightMargin+pThis->m_nFullBorderPixel*2>pThis->m_nMenuWidth){
		pThis->m_nMenuWidth=pThis->m_oMaxTextSize.m_nWidth+pThis->m_nItemLeftMargin+pThis->m_nItemRightMargin+pThis->m_nFullBorderPixel*2;}

	// 算出菜单所占宽和高
	{CEspSize size;
	CEspSize_CInit_i0p_i0p(&size,pThis->m_nMenuWidth,pThis->m_nFullBorderPixel*2+pThis->m_nTBBorderHeight*2+pThis->m_nItemHeight*pThis->m_nDrawItemCount);
pThis->m_tSize=size;
}}

void CBMenu_DrawFullBorder_IAwsGc1p_CEspRect1p(CBMenu* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	if(pThis->m_nFullBorderPixel>0){
	{
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBorderColor));
		pGc->m_pVTab->m_pDrawRect_CEspRect1p(pGc,rect);
	}}
}

void CBMenu_DrawTopBorder_IAwsGc1p_CEspRect1p_i0p(CBMenu* pThis, IAwsGc *  pGc,const CEspRect * rect,int bIsScroll)
{
	// 画背景
	pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);

	if(bIsScroll){
	{
		// 画上箭头
		CEspPoint ptStart,ptEnd;
		CEspPoint_CInit_i0p_i0p(&(ptStart),0,0);
CEspPoint_CInit_i0p_i0p(&(ptEnd),0,0);
ptStart.m_nX=(rect->m_ptLT.m_nX+rect->m_ptRB.m_nX)/2;
		ptStart.m_nY=rect->m_ptLT.m_nY+(CEspRect_GetSize(rect)->m_nHeight-7)/2;
		ptEnd.m_nX=ptStart.m_nX+1;
		ptEnd.m_nY=ptStart.m_nY;
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oArrowColor));
		{int i;
		for(i=0;i<4;++i){
		{
			pGc->m_pVTab->m_pDrawLine_CEspPoint1p_CEspPoint1p(pGc,&(ptStart),&(ptEnd));
			ptStart.m_nX-=1;
			ptStart.m_nY+=1;

			ptEnd.m_nX+=1;
			ptEnd.m_nY=ptStart.m_nY;
		}}
	}}}
}

void CBMenu_DrawBottomBorder_IAwsGc1p_CEspRect1p_i0p(CBMenu* pThis, IAwsGc *  pGc,const CEspRect * rect,int bIsScroll)
{
	// 画背景
	pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);

	if(bIsScroll){
	{
		// 画下箭头
		CEspPoint ptStart,ptEnd;
		CEspPoint_CInit_i0p_i0p(&(ptStart),0,0);
CEspPoint_CInit_i0p_i0p(&(ptEnd),0,0);
ptStart.m_nX=(rect->m_ptLT.m_nX+rect->m_ptRB.m_nX)/2-3;
		ptStart.m_nY=rect->m_ptLT.m_nY+(CEspRect_GetSize(rect)->m_nHeight-7)/2;
		ptEnd.m_nX=ptStart.m_nX+7;
		ptEnd.m_nY=ptStart.m_nY;
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oArrowColor));
		{int i;
		for(i=0;i<4;++i){
		{
			pGc->m_pVTab->m_pDrawLine_CEspPoint1p_CEspPoint1p(pGc,&(ptStart),&(ptEnd));
			ptStart.m_nX+=1;
			ptStart.m_nY+=1;

			ptEnd.m_nX-=1;
			ptEnd.m_nY=ptStart.m_nY;
		}}
	}}}
}

void CBMenu_DrawItem_IAwsGc1p_CEspRect1p_i0p_i0p_i0p(CBMenu* pThis, IAwsGc *  pGc,const CEspRect * rect,int nIndex,int bIsSelected,int bIsSubMenu)
{
	if(bIsSelected){
	{
		pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oFocusTextColor));
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oFocusBKColor));
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oFocusBKColor));
	}}
	else
	{{
		pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oTextColor));
		pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
		pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	}}
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);

	if(bIsSubMenu){
	{
		// 画右箭头
		CEspPoint ptStart,ptEnd;
		CEspPoint_CInit_i0p_i0p(&(ptStart),0,0);
CEspPoint_CInit_i0p_i0p(&(ptEnd),0,0);
ptStart.m_nX=rect->m_ptRB.m_nX-pThis->m_nItemRightMargin+(pThis->m_nItemRightMargin-4)/2;
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

	{CEspRect rt;
	CEspRect_CInit(&(rt));
rt.m_ptLT.m_nX=rect->m_ptLT.m_nX+pThis->m_nItemLeftMargin;
	rt.m_ptLT.m_nY=rect->m_ptLT.m_nY+(pThis->m_nItemHeight-pThis->m_oMaxTextSize.m_nHeight)/2;
	rt.m_ptRB.m_nX=rect->m_ptRB.m_nX-pThis->m_nItemRightMargin;
	rt.m_ptRB.m_nY=rect->m_ptLT.m_nY+pThis->m_nItemHeight;
	pGc->m_pVTab->m_pSetTextAlignment_0p(pGc,AWS_TAM_Left);

	CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
	pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));
	pGc->m_pVTab->m_pDrawText_CAwsString1p_CEspRect1p(pGc,&(pThis->m_pItemData[nIndex].m_strText),&(rt));
	pGc->m_pVTab->m_pDiscardFont(pGc);
}}

void CBMenu_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CBMenu* pThis = (CBMenu*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
	CEspRect rt,rtTemp;

	CEspRect_CInit(&(rt));
CEspRect_CInit(&(rtTemp));
if(ESP_NULL!=pGc){
	{
		// 画全边框
		pThis->m_pVTab->m_pDrawFullBorder_IAwsGc1p_CEspRect1p(pThis,pGc,rect);

		// 画上边框
		rt.m_ptLT.m_nX=pThis->m_nFullBorderPixel;
		rt.m_ptLT.m_nY=pThis->m_nFullBorderPixel;
		rt.m_ptRB.m_nX=pThis->m_nMenuWidth-pThis->m_nFullBorderPixel;
		rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nTBBorderHeight;

		if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
		{
			if(pThis->m_nItemCount>pThis->m_nMaxShowItemCount){
			{
				pThis->m_pVTab->m_pDrawTopBorder_IAwsGc1p_CEspRect1p_i0p(pThis,pGc,&(rt),1);
			}}
			else
			{{
				pThis->m_pVTab->m_pDrawTopBorder_IAwsGc1p_CEspRect1p_i0p(pThis,pGc,&(rt),0);
			}}
		}}
		rt.m_ptLT.m_nY=rt.m_ptRB.m_nY;

		// 画中间Item
		rt.m_ptRB.m_nY+=pThis->m_nItemHeight;
		{int i;
		for(i=0;i<pThis->m_nDrawItemCount;++i){
		{
			if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
			{
				if(pThis->m_nFocusItemIndex==i+pThis->m_nDrawItemStartIndex){
				{
					// 选中
					if(pThis->m_pItemData[i+pThis->m_nDrawItemStartIndex].m_nSubMenuID>0){
						pThis->m_pVTab->m_pDrawItem_IAwsGc1p_CEspRect1p_i0p_i0p_i0p(pThis,pGc,&(rt),i+pThis->m_nDrawItemStartIndex,1,1);}
					else
						{pThis->m_pVTab->m_pDrawItem_IAwsGc1p_CEspRect1p_i0p_i0p_i0p(pThis,pGc,&(rt),i+pThis->m_nDrawItemStartIndex,1,0);}
				}}
				else
				{{
					// 没选中
					if(pThis->m_pItemData[i+pThis->m_nDrawItemStartIndex].m_nSubMenuID>0){
						pThis->m_pVTab->m_pDrawItem_IAwsGc1p_CEspRect1p_i0p_i0p_i0p(pThis,pGc,&(rt),i+pThis->m_nDrawItemStartIndex,0,1);}
					else
						{pThis->m_pVTab->m_pDrawItem_IAwsGc1p_CEspRect1p_i0p_i0p_i0p(pThis,pGc,&(rt),i+pThis->m_nDrawItemStartIndex,0,0);}
				}}
			}}

			rt.m_ptLT.m_nY+=pThis->m_nItemHeight;
			rt.m_ptRB.m_nY+=pThis->m_nItemHeight;
		}}

		// 画下边框
		rt.m_ptRB.m_nY+=pThis->m_nTBBorderHeight-pThis->m_nItemHeight;

		if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
		{
			if(pThis->m_nItemCount>pThis->m_nMaxShowItemCount){
			{
				pThis->m_pVTab->m_pDrawBottomBorder_IAwsGc1p_CEspRect1p_i0p(pThis,pGc,&(rt),1);
			}}
			else
			{{
				pThis->m_pVTab->m_pDrawBottomBorder_IAwsGc1p_CEspRect1p_i0p(pThis,pGc,&(rt),0);
			}}
		}}
	}}}
}
}

int CBMenu_GetItemRectFromIndex_i0p_CEspRect1p(CBMenu* pThis, int nIndex,CEspRect * rect)
{
	int bRet=0;
	int n=nIndex-pThis->m_nDrawItemStartIndex;

	if(n<pThis->m_nMaxShowItemCount){
	{
		rect->m_ptLT.m_nX=pThis->m_nFullBorderPixel;
		rect->m_ptRB.m_nX=pThis->m_nMenuWidth-pThis->m_nFullBorderPixel;

		rect->m_ptLT.m_nY=pThis->m_nFullBorderPixel+pThis->m_nTBBorderHeight+n*pThis->m_nItemHeight;
		rect->m_ptRB.m_nY=rect->m_ptLT.m_nY+pThis->m_nItemHeight;

		bRet=1;
	}}

	return bRet;
}

int CBMenu_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CBMenu* pThis = (CBMenu*)this;{
	CEspRect rt;
	CEspRect_CInit(&(rt));
rt.m_ptLT.m_nX=pThis->m_nFullBorderPixel;
	rt.m_ptRB.m_nX=pThis->m_nMenuWidth-pThis->m_nFullBorderPixel;
	if(AWS_Key==type){
	{
		switch(code)
		{
		case AWS_KeyCode_UpArrow:
			if(pThis->m_nFocusItemIndex>0){
			{
				--pThis->m_nFocusItemIndex;
				if(pThis->m_nFocusItemIndex<pThis->m_nDrawItemStartIndex){
				{
					pThis->m_nDrawItemStartIndex=pThis->m_nFocusItemIndex;
					// 全都要移动
					rt.m_ptLT.m_nY=pThis->m_nFullBorderPixel+pThis->m_nTBBorderHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nDrawItemCount*pThis->m_nItemHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
				else
				{{
					// 只需要移动两个
					rt.m_ptLT.m_nY=pThis->m_nFullBorderPixel+pThis->m_nTBBorderHeight+(pThis->m_nFocusItemIndex-pThis->m_nDrawItemStartIndex)*pThis->m_nItemHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nItemHeight*2;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
			}}
			else
			{{
				pThis->m_nFocusItemIndex=pThis->m_nItemCount-1;
				{int n=pThis->m_nItemCount-pThis->m_nDrawItemCount;

				if(n!=pThis->m_nDrawItemStartIndex){
				{
					// 全都要移动
					pThis->m_nDrawItemStartIndex=n;

					rt.m_ptLT.m_nY=pThis->m_nFullBorderPixel+pThis->m_nTBBorderHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nDrawItemCount*pThis->m_nItemHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
				else
				{{
					// 只需要移动两个
					rt.m_ptLT.m_nY=pThis->m_nFullBorderPixel+pThis->m_nTBBorderHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nItemHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

					rt.m_ptLT.m_nY=pThis->m_nFullBorderPixel+pThis->m_nTBBorderHeight+(pThis->m_nDrawItemCount-1)*pThis->m_nItemHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nItemHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
			}}}
			return 1;

		case AWS_KeyCode_DownArrow:
			if(pThis->m_nFocusItemIndex<pThis->m_nItemCount-1){
			{
				++pThis->m_nFocusItemIndex;
				if(pThis->m_nFocusItemIndex-pThis->m_nDrawItemStartIndex>=pThis->m_nDrawItemCount){
				{
					++pThis->m_nDrawItemStartIndex;

					rt.m_ptLT.m_nY=pThis->m_nFullBorderPixel+pThis->m_nTBBorderHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nDrawItemCount*pThis->m_nItemHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
				else
				{{
					// 只需要移动两个
					rt.m_ptLT.m_nY=pThis->m_nFullBorderPixel+pThis->m_nTBBorderHeight+(pThis->m_nFocusItemIndex-1-pThis->m_nDrawItemStartIndex)*pThis->m_nItemHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nItemHeight*2;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
			}}
			else
			{{
				int n=pThis->m_nDrawItemStartIndex;
				pThis->m_nFocusItemIndex=0;
				pThis->m_nDrawItemStartIndex=0;

				if(0!=n){
				{
					rt.m_ptLT.m_nY=pThis->m_nFullBorderPixel+pThis->m_nTBBorderHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nDrawItemCount*pThis->m_nItemHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
				else
				{{
					// 只需要移动两个
					rt.m_ptLT.m_nY=pThis->m_nFullBorderPixel+pThis->m_nTBBorderHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nItemHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));

					rt.m_ptLT.m_nY=pThis->m_nFullBorderPixel+pThis->m_nTBBorderHeight+(pThis->m_nDrawItemCount-1)*pThis->m_nItemHeight;
					rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nItemHeight;
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rt));
				}}
			}}
			return 1;

		case AWS_KeyCode_LeftArrow:
			if(pThis->m_bIsSubMenu){
			{
				// 销毁自己
				CAwsContainer_DestroyPopWnd_i0p(&(pThis->m_oBase_CAwsContainer),1);
			}}
			return 1;

		case AWS_KeyCode_RightArrow:
			if(pThis->m_pItemData[pThis->m_nFocusItemIndex].m_nSubMenuID>0){
			{
				CEspPoint ptLT;
				CEspPoint_CInit_i0p_i0p(&(ptLT),0,0);
ptLT.m_nX=pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect.m_ptLT.m_nX+pThis->m_nMenuWidth;
				ptLT.m_nY=pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_tRect.m_ptLT.m_nY+pThis->m_nItemHeight*(pThis->m_nFocusItemIndex-pThis->m_nDrawItemStartIndex);
				CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_PopMenu,pThis->m_pItemData[pThis->m_nFocusItemIndex].m_nSubMenuID,(int)(&ptLT));
			}}
			return 1;

		case AWS_KeyCode_OK:
			if(pThis->m_pItemData[pThis->m_nFocusItemIndex].m_nSubMenuID>0){
			{
				return pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pOnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,AWS_KeyCode_RightArrow);
			}}
			else
			{{
				CAwsWindow_PostCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_MenuCmd,pThis->m_nFocusItemIndex,0);
				CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_MenuDestroy,0,0);

				// 销毁所有弹出式菜单
				CAwsContainer_DestroyPopWnd_i0p(&(pThis->m_oBase_CAwsContainer),pThis->m_nPopMenuCount);
				return 1;
			}}
		}
	}}

	if(AWS_Key_Up==type){
	{
		if(!pThis->m_bIsPopupOnly){
		{
			switch(code)
			{
			case AWS_KeyCode_LeftMenu:
				return pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pOnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),AWS_Key,AWS_KeyCode_OK);

			case AWS_KeyCode_RightMenu:
				// 销毁所有弹出式菜单
				CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_MenuDestroy,0,0);
				CAwsContainer_DestroyPopWnd_i0p(&(pThis->m_oBase_CAwsContainer),pThis->m_nPopMenuCount);
				return 1;
			}
		}}

		if(code>=AWS_KeyCode_1&&code<=AWS_KeyCode_9){
		{
			int nIndex=code-AWS_KeyCode_1;
			if(nIndex<pThis->m_nItemCount){
			{
				// 重绘前focus窗口
				int n=pThis->m_nFocusItemIndex;
				CEspRect rect;
				CEspRect_CInit(&(rect));
pThis->m_nFocusItemIndex=nIndex;
				if(CBMenu_GetItemRectFromIndex_i0p_CEspRect1p(pThis,n,&(rect))){
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rect));}
				if(CBMenu_GetItemRectFromIndex_i0p_CEspRect1p(pThis,pThis->m_nFocusItemIndex,&(rect))){
					pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rect));}
				
				return pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab->m_pOnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),AWS_Key,AWS_KeyCode_OK);
			}}
		}}
	}}

	if(pThis->m_bIsPopupOnly){
		return CAwsContainer_OnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);}
	else
		{return 1;}
}
}
