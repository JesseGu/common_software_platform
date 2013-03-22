/******************************************************************************
* FileName		       : EspPubClass.cpp
* Description          : implementation of the ESP public class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-12

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "EspPubClass.h"
void CAwsString_SetMaxCharCB_i0p(CAwsString* pThis, int nMaxCB) { pThis->m_nMaxCharCB=nMaxCB; } 

int CAwsString_GetByteCount(const CAwsString* pThis)  { return pThis->m_nCharCB; } 

int CAwsString_GetCharCount(const CAwsString* pThis)  { return pThis->m_nCharCount; } 

const char *  CAwsString_GetStringData(const CAwsString* pThis)  { return pThis->m_pCharData; } 

int CAwsString_GetStrID(const CAwsString* pThis)  { return pThis->m_nStrID; } 

void CAwsString_LoadString_i0p(CAwsString* pThis, int nStrID) { pThis->m_nStrID=nStrID; } 


void CEspPoint_CInit_i0p_i0p(CEspPoint* pThis, int x,int y)
{
	pThis->m_nX=x;
	pThis->m_nY=y;
}

void CEspPoint_Operator_SubEqu_CEspPoint1p(CEspPoint* pThis, const CEspPoint * pt)
{
	pThis->m_nX-=pt->m_nX;
	pThis->m_nY-=pt->m_nY;
}

void CEspPoint_Operator_AddEqu_CEspPoint1p(CEspPoint* pThis, const CEspPoint * pt)
{
	pThis->m_nX+=pt->m_nX;
	pThis->m_nY+=pt->m_nY;
}

int CEspPoint_Operator_NotEqu_CEspPoint1p(const CEspPoint* pThis, const CEspPoint * pt)
{
	if(pThis->m_nX!=pt->m_nX||pThis->m_nY!=pt->m_nY){
		return 1;}
	else
		{return 0;}
}

void CEspSize_CInit_i0p_i0p(CEspSize* pThis, int nWidth,int nHeight)
{
	pThis->m_nWidth=nWidth;
	pThis->m_nHeight=nHeight;
}
int CEspSize_Operator_EquEqu_CEspSize1p(const CEspSize* pThis, const CEspSize * size) 
{
	if(pThis->m_nHeight==size->m_nHeight||pThis->m_nWidth==size->m_nWidth){
	{
		return 1;
	}}

	return 0;
}


void CEspRect_CInit(CEspRect* pThis)
{

CEspPoint_CInit_i0p_i0p(&(pThis->m_ptLT),0,0);
CEspPoint_CInit_i0p_i0p(&(pThis->m_ptRB),0,0);
CEspSize_CInit_i0p_i0p(&(pThis->m_oSize),0,0);
{
	pThis->m_ptLT.m_nX=0;
	pThis->m_ptLT.m_nY=0;

	pThis->m_ptRB.m_nX=0;
	pThis->m_ptRB.m_nY=0;
}
}

void CEspRect_Operator_AddEqu_CEspRect1p(CEspRect* pThis, const CEspRect * rt)
{
	CEspPoint_Operator_AddEqu_CEspPoint1p(&(pThis->m_ptLT),&(rt->m_ptLT));
	CEspPoint_Operator_AddEqu_CEspPoint1p(&(pThis->m_ptRB),&(rt->m_ptRB));
}

int CEspRect_Operator_NotEqu_CEspRect1p(const CEspRect* pThis, const CEspRect * pt) 
{
	if(CEspPoint_Operator_NotEqu_CEspPoint1p(&(pThis->m_ptLT),&(pt->m_ptLT))||CEspPoint_Operator_NotEqu_CEspPoint1p(&(pThis->m_ptRB),&(pt->m_ptRB))){
		return 1;}
	else
		{return 0;}
}

void CEspRect_CInit_i0p_i0p_i0p_i0p(CEspRect* pThis, int nLTx,int nLTy,int nRBx,int nRBy)
{

CEspPoint_CInit_i0p_i0p(&(pThis->m_ptLT),0,0);
CEspPoint_CInit_i0p_i0p(&(pThis->m_ptRB),0,0);
CEspSize_CInit_i0p_i0p(&(pThis->m_oSize),0,0);
{
	pThis->m_ptLT.m_nX=nLTx;
	pThis->m_ptLT.m_nY=nLTy;

	pThis->m_ptRB.m_nX=nRBx;
	pThis->m_ptRB.m_nY=nRBy;
}
}

void CEspRect_CInit_CEspPoint1p_CEspPoint1p(CEspRect* pThis, const CEspPoint * ptLT,const CEspPoint * ptRB)
{

CEspPoint_CInit_i0p_i0p(&(pThis->m_ptLT),0,0);
CEspPoint_CInit_i0p_i0p(&(pThis->m_ptRB),0,0);
CEspSize_CInit_i0p_i0p(&(pThis->m_oSize),0,0);
{
	pThis->m_ptLT=*ptLT;
	pThis->m_ptRB=*ptRB;

}
}

const CEspSize * CEspRect_GetSize(const CEspRect* pThis)  
{
	CEspRect *  pTHIS=(CEspRect*)pThis;
	pTHIS->m_oSize.m_nWidth=pThis->m_ptRB.m_nX-pThis->m_ptLT.m_nX;
	pTHIS->m_oSize.m_nHeight=pThis->m_ptRB.m_nY-pThis->m_ptLT.m_nY;

	return &pTHIS->m_oSize;
}

// 获取两个矩形相交矩形
int CEspRect_InterRect_CEspRect1p_CEspRect1p(const CEspRect* pThis, const CEspRect * rect,CEspRect * DesRect) 
{
	int bRet=1;

	// 判断x
	if(rect->m_ptLT.m_nX<pThis->m_ptLT.m_nX){
	{
		DesRect->m_ptLT.m_nX=pThis->m_ptLT.m_nX;
		if(rect->m_ptRB.m_nX>=pThis->m_ptLT.m_nX&&rect->m_ptRB.m_nX<=pThis->m_ptRB.m_nX){
		{
			DesRect->m_ptRB.m_nX=rect->m_ptRB.m_nX;
		}}
		else if(rect->m_ptRB.m_nX>pThis->m_ptRB.m_nX){
		{
			DesRect->m_ptRB.m_nX=pThis->m_ptRB.m_nX;
		}}
		else
		{{
			bRet=0;
		}}
	}}
	else if(rect->m_ptLT.m_nX>=pThis->m_ptLT.m_nX&&rect->m_ptLT.m_nX<=pThis->m_ptRB.m_nX){
	{
		DesRect->m_ptLT.m_nX=rect->m_ptLT.m_nX;

		if(rect->m_ptRB.m_nX<=pThis->m_ptRB.m_nX){
		{
			DesRect->m_ptRB.m_nX=rect->m_ptRB.m_nX;
		}}
		else
		{{
			DesRect->m_ptRB.m_nX=pThis->m_ptRB.m_nX;
		}}
	}}
	else
	{{
		bRet=0;
	}}

	// 判断y
	if(bRet){
	{
		if(rect->m_ptLT.m_nY<pThis->m_ptLT.m_nY){
		{
			DesRect->m_ptLT.m_nY=pThis->m_ptLT.m_nY;
			if(rect->m_ptRB.m_nY>=pThis->m_ptLT.m_nY&&rect->m_ptRB.m_nY<=pThis->m_ptRB.m_nY){
			{
				DesRect->m_ptRB.m_nY=rect->m_ptRB.m_nY;
			}}
			else if(rect->m_ptRB.m_nY>pThis->m_ptRB.m_nY){
			{
				DesRect->m_ptRB.m_nY=pThis->m_ptRB.m_nY;
			}}
			else
			{{
				bRet=0;
			}}
		}}
		else if(rect->m_ptLT.m_nY>=pThis->m_ptLT.m_nY&&rect->m_ptLT.m_nY<=pThis->m_ptRB.m_nY){
		{
			DesRect->m_ptLT.m_nY=rect->m_ptLT.m_nY;

			if(rect->m_ptRB.m_nY<=pThis->m_ptRB.m_nY){
			{
				DesRect->m_ptRB.m_nY=rect->m_ptRB.m_nY;
			}}
			else
			{{
				DesRect->m_ptRB.m_nY=pThis->m_ptRB.m_nY;
			}}
		}}
		else
		{{
			bRet=0;
		}}
	}}

	if(bRet&&(DesRect->m_ptLT.m_nX==DesRect->m_ptRB.m_nX||DesRect->m_ptLT.m_nY==DesRect->m_ptRB.m_nY)){
		bRet=0;}

	return bRet;
}
