/******************************************************************************
* FileName		       : BEdit.cpp
* Description          : implementation of the CBEdit class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BEdit.h"
const VTab_CAwsWindow g_tVTab_CBEdit_CAwsWindow = {CBEdit_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CBEdit_OnDraw_CEspRect1p, CBEdit_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CBEdit_OnFocus_i0p, CBEdit_OnTimer, CBEdit_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CAwsWindow_OnCreate};
void CBEdit_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CBEdit* pThis=(CBEdit*)this;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsString_DUninit_i1p(&(pThis->m_strDrawText), 0);
	CAwsString_DUninit_i1p(&(pThis->m_strText), 0);
	CAwsWindow_DUninit_i1p(&(pThis->m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CBEdit*)0)->m_oBase_CAwsWindow));
}

void CBEdit_SetTextColor_CAwsRgb1p(CBEdit* pThis, const CAwsRgb * color) { pThis->m_oTextColor=*color; } 

void CBEdit_SetCaretColor_CAwsRgb1p(CBEdit* pThis, const CAwsRgb * color) { pThis->m_oCaretColor=*color; } 

void CBEdit_SetBKColor_CAwsRgb1p(CBEdit* pThis, const CAwsRgb * color) { pThis->m_oBKColor=*color; } 

void CBEdit_SetFocusBorderColor_CAwsRgb1p(CBEdit* pThis, const CAwsRgb * color) { pThis->m_oFocusBorderColor=*color; } 

void CBEdit_SetBorderColor_CAwsRgb1p(CBEdit* pThis, const CAwsRgb * color) { pThis->m_oBorderColor=*color; } 

void CBEdit_SetCaretInterval_i0p(CBEdit* pThis, int nTimes) { pThis->m_nCaretInterval=nTimes; } 

const CAwsString * CBEdit_GetString(CBEdit* pThis) { return &(pThis->m_strText); } 

#include "AwsUi.h"
#include "IAwsGc.h"

void CBEdit_CInit(CBEdit* pThis)
{

CAwsWindow_CInit(&(pThis->m_oBase_CAwsWindow));
CAwsString_CInit_i0p(&(pThis->m_strText),100);
CAwsString_CInit_i0p(&(pThis->m_strDrawText),100);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oFocusBorderColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oBKColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oCaretColor),0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&(pThis->m_oTextColor),0,0,0);
CEspPoint_CInit_i0p_i0p(&(pThis->m_oCaretPos),0,0);
CEspSize_CInit_i0p_i0p(&(pThis->m_oCaretSize),0,0);
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBEdit_CAwsWindow;
{
	CAwsRgb rgbBorder,rgbFocus,rgbBK,rgbCaret,rgbText;
	CAwsRgb_CInit_i0p_i0p_i0p(&rgbBorder,0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbFocus,255,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbBK,255,255,255);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbCaret,0,0,0);
CAwsRgb_CInit_i0p_i0p_i0p(&rgbText,0,0,0);
pThis->m_oBorderColor=rgbBorder;
	pThis->m_oFocusBorderColor=rgbFocus;
	pThis->m_oBKColor=rgbBK;
	pThis->m_oCaretColor=rgbCaret;
	pThis->m_oTextColor=rgbText;

	pThis->m_oCaretPos.m_nX=3;
	pThis->m_oCaretPos.m_nY=3;

	pThis->m_bCaretIsVisible=0;
	pThis->m_oCaretSize.m_nWidth=1;
	pThis->m_oCaretSize.m_nHeight=14;
	pThis->m_nCaretCharIndex=-1;

	pThis->m_bCaretIsShow=0;
	pThis->m_nCaretInterval=500;

	pThis->m_nStartDrawCharIndex=0;

	pThis->m_nFontSize=12;
}
}

void CBEdit_SetDefaultString_CAwsString1p(CBEdit* pThis, const CAwsString * str)
{
	CAwsString_SetData_c1p_i0p(&(pThis->m_strText),CAwsString_GetStringData(str),CAwsString_GetByteCount(str));
}

void CBEdit_ShowCaret(CBEdit* pThis)
{
	if(!pThis->m_bCaretIsShow){
	{
		pThis->m_bCaretIsShow=1;
		CAwsWindow_StartTimer_i0p(&(pThis->m_oBase_CAwsWindow),pThis->m_nCaretInterval);
	}}
}

void CBEdit_HideCaret(CBEdit* pThis)
{
	if(pThis->m_bCaretIsShow){
	{
		pThis->m_bCaretIsShow=0;
		CAwsWindow_EndTimer(&(pThis->m_oBase_CAwsWindow));

		pThis->m_bCaretIsVisible=0;
		{CEspRect rt;
		CEspRect_CInit(&(rt));
rt.m_ptLT=pThis->m_oCaretPos;
		rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_oCaretSize.m_nWidth;
		rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_oCaretSize.m_nHeight;
		pThis->m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsWindow),&(rt));
	}}}
}

void CBEdit_OnTimer(CAwsWindow* this)
{

	CBEdit* pThis = (CBEdit*)this;{
	if(pThis->m_oBase_CAwsWindow.m_bIsFocus&&pThis->m_bCaretIsShow){
	{
		pThis->m_bCaretIsVisible=!pThis->m_bCaretIsVisible;

		{CEspRect rt;
		CEspRect_CInit(&(rt));
rt.m_ptLT=pThis->m_oCaretPos;
		rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_oCaretSize.m_nWidth;
		rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_oCaretSize.m_nHeight;
		pThis->m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsWindow),&(rt));
	}}}
}
}

int CBEdit_RightMoveOneChar(CBEdit* pThis)
{
	int nCount=CAwsString_GetCharCount(&(pThis->m_strText));
	if(pThis->m_nCaretCharIndex<nCount-1){
	{
		CAwsString strSub;
		CAwsString_CInit_i0p(&(strSub),100);
CAwsString_GetSubString_CAwsString1p_i0p_i0p(&(pThis->m_strText),&(strSub),pThis->m_nCaretCharIndex+1,pThis->m_nCaretCharIndex+2);

		// 获得字符的宽度
		{IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsWindow));
		CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
		pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));
		{const CEspSize *  size=pGc->m_pVTab->m_pGetTextSize_CAwsString1p(pGc,&(strSub));
		int nWidth=size->m_nWidth;

		// 确认移动
		pThis->m_oCaretPos.m_nX+=nWidth;
		if(pThis->m_oCaretPos.m_nX<CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow))->m_nWidth-2){
		{
		}}
		else
		{{
			// 否则整体向左移动3个字符，改变
			CAwsString strSub;
			CAwsString_CInit_i0p(&(strSub),100);
CAwsString_GetSubString_CAwsString1p_i0p_i0p(&(pThis->m_strText),&(strSub),pThis->m_nStartDrawCharIndex,pThis->m_nStartDrawCharIndex+3);

			// 获得字符的宽度
			{IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsWindow));
			CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
			pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));
			{const CEspSize *  size=pGc->m_pVTab->m_pGetTextSize_CAwsString1p(pGc,&(strSub));
			int nWidth=size->m_nWidth;

			pThis->m_oCaretPos.m_nX-=nWidth;

			pThis->m_nStartDrawCharIndex+=3;
		}}CAwsString_DUninit_i1p(&(strSub), 0);
}}

		++pThis->m_nCaretCharIndex;

		{CAwsString_DUninit_i1p(&(strSub), 0);
return 1;}
	}}}}

	return 0;
}

int CBEdit_LeftMoveOneChar(CBEdit* pThis)
{
	if(pThis->m_nCaretCharIndex>=0){
	{
		CAwsString strSub;
		CAwsString_CInit_i0p(&(strSub),100);
CAwsString_GetSubString_CAwsString1p_i0p_i0p(&(pThis->m_strText),&(strSub),pThis->m_nCaretCharIndex,pThis->m_nCaretCharIndex+1);

		// 获得字符的宽度
		{IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsWindow));
		CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
		pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));
		{const CEspSize *  size=pGc->m_pVTab->m_pGetTextSize_CAwsString1p(pGc,&(strSub));
		int nWidth=size->m_nWidth;

		// 确认移动
		pThis->m_oCaretPos.m_nX-=nWidth;
		if(pThis->m_oCaretPos.m_nX>5){
		{
		}}
		else
		{{
			// 否则整体向右移动3个字符，有可能少于3个字符
			CAwsString strSub;
			int nMoveCharCount=3;
			int nStartIndex=pThis->m_nStartDrawCharIndex-3;
			int nEndIndex=pThis->m_nStartDrawCharIndex;

			CAwsString_CInit_i0p(&(strSub),100);
if(nStartIndex<0){
			{
				nStartIndex=0;
				nMoveCharCount=nEndIndex-nStartIndex;
			}}

			CAwsString_GetSubString_CAwsString1p_i0p_i0p(&(pThis->m_strText),&(strSub),nStartIndex,nEndIndex);

			// 获得字符的宽度
			{IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsWindow));
			CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
			pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));
			{const CEspSize *  size=pGc->m_pVTab->m_pGetTextSize_CAwsString1p(pGc,&(strSub));
			int nWidth=size->m_nWidth;

			pThis->m_oCaretPos.m_nX+=nWidth;

			pThis->m_nStartDrawCharIndex-=nMoveCharCount;
		}}CAwsString_DUninit_i1p(&(strSub), 0);
}}

		--pThis->m_nCaretCharIndex;

		{CAwsString_DUninit_i1p(&(strSub), 0);
return 1;}
	}}}}

	return 0;
}

void CBEdit_DeleteOneChar(CBEdit* pThis)
{
	// 删除一个字符
	int n=pThis->m_nCaretCharIndex;
	if(CBEdit_LeftMoveOneChar(pThis)){
	{
		if(CAwsString_RemoveChar_i0p(&(pThis->m_strText),n)){
		{
			CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));
		}}
	}}
}

void CBEdit_OnImeChar_s0p(CAwsWindow* this, short nChar)
{

	CBEdit* pThis = (CBEdit*)this;{
	// 插入字符到字符串
	if(CAwsString_AddChar_s0p_i0p(&(pThis->m_strText),nChar,pThis->m_nCaretCharIndex+1)){
	{
		// 插入符右移一个字符
		CBEdit_RightMoveOneChar(pThis);

		CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));
	}}
}
}

void CBEdit_OnFocus_i0p(CAwsWindow* this, int bIsFocus)
{

	CBEdit* pThis = (CBEdit*)this;{
	CAwsWindow_OnFocus_i0p(&(pThis->m_oBase_CAwsWindow),bIsFocus);

	if(pThis->m_oBase_CAwsWindow.m_bIsFocus){
	{
		// 激活输入法
		CAwsWindow_GetUi(&(pThis->m_oBase_CAwsWindow))->m_pVTab->m_pActiveIME(CAwsWindow_GetUi(&(pThis->m_oBase_CAwsWindow)));

		// 显示插入符
		CBEdit_ShowCaret(pThis);
	}}
	else
	{{
		// 关闭输入法
		CAwsWindow_GetUi(&(pThis->m_oBase_CAwsWindow))->m_pVTab->m_pInactiveIME(CAwsWindow_GetUi(&(pThis->m_oBase_CAwsWindow)));

		// 隐藏插入符
		CBEdit_HideCaret(pThis);
	}}

	CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));
}
}

int CBEdit_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CBEdit* pThis = (CBEdit*)this;{
	if(AWS_Key==type){
	{
		switch(code)
		{
		case AWS_KeyCode_LeftArrow:
			if(CBEdit_LeftMoveOneChar(pThis)){
				CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));}
			return 1;

		case AWS_KeyCode_RightArrow:
			if(CBEdit_RightMoveOneChar(pThis)){
				CAwsWindow_Invalide(&(pThis->m_oBase_CAwsWindow));}
			return 1;

		case AWS_KeyCode_Delete:
			CBEdit_DeleteOneChar(pThis);
			return 1;
		}
	}}

	return CAwsWindow_OnKey_0p_0p(&(pThis->m_oBase_CAwsWindow),type,code);
}
}

void CBEdit_DrawBK_IAwsGc1p_CEspRect1p(CBEdit* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oBKColor));
	pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,rect);
}

void CBEdit_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CBEdit* pThis = (CBEdit*)this;{
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsWindow));
	CEspSize size=*CAwsWindow_GetSize(&(pThis->m_oBase_CAwsWindow));
	CEspRect rt,rtTemp;

	// 用背景填充区域
	CEspRect_CInit(&(rt));
CEspRect_CInit(&(rtTemp));
CBEdit_DrawBK_IAwsGc1p_CEspRect1p(pThis,pGc,rect);

	// 绘制边框
	if(0==rect->m_ptLT.m_nX||0==rect->m_ptLT.m_nY||size.m_nWidth==rect->m_ptRB.m_nX||size.m_nHeight==rect->m_ptRB.m_nY){
	{
		if(pThis->m_oBase_CAwsWindow.m_bIsFocus){
		{
			pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oFocusBorderColor));
		}}
		else
		{{
			pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oBorderColor));
		}}
		{CEspRect rtTemp;
		CEspRect_CInit_i0p_i0p_i0p_i0p(&rtTemp,0,0,size.m_nWidth,size.m_nHeight);
pGc->m_pVTab->m_pDrawRect_CEspRect1p(pGc,&(rtTemp));
	}}}

	// 绘制文字
//	rt = rect;
	rt.m_ptLT.m_nX=3;
	rt.m_ptLT.m_nY=3;
	rt.m_ptRB.m_nX=size.m_nWidth-2;
	rt.m_ptRB.m_nY=size.m_nHeight-2;
	pGc->m_pVTab->m_pSetTextColor_CAwsRgb1p(pGc,&(pThis->m_oTextColor));
	pGc->m_pVTab->m_pSetTextAlignment_0p(pGc,AWS_TAM_Left);
	CAwsFont_CreateFont_i0p_i0p_i0p(&(pThis->m_oFont),0,pThis->m_nFontSize,400);
	pGc->m_pVTab->m_pUseFont_CAwsFont1p(pGc,&(pThis->m_oFont));

//	CAwsString strSub;
	CAwsString_Reset(&(pThis->m_strDrawText));
	CAwsString_GetSubString_CAwsString1p_i0p_i0p(&(pThis->m_strText),&(pThis->m_strDrawText),pThis->m_nStartDrawCharIndex,-1);
	pGc->m_pVTab->m_pDrawText_CAwsString1p_CEspRect1p(pGc,&(pThis->m_strDrawText),&(rt));

	pGc->m_pVTab->m_pDiscardFont(pGc);

	// 绘制插入符
	rt.m_ptLT=pThis->m_oCaretPos;
	rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_oCaretSize.m_nWidth;
	rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_oCaretSize.m_nHeight;
	if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,&(rt),&(rtTemp))){
	{
		if(pThis->m_bCaretIsVisible){
		{
			pGc->m_pVTab->m_pSetPenColor_CAwsRgb1p(pGc,&(pThis->m_oCaretColor));
			pGc->m_pVTab->m_pSetBrushColor_CAwsRgb1p(pGc,&(pThis->m_oCaretColor));

			pGc->m_pVTab->m_pDrawFillRect_CEspRect1p(pGc,&(rt));
		}}
	}}
}
}
