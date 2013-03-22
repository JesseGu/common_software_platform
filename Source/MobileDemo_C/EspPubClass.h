/******************************************************************************
* FileName		       : EspPubClass.h
* Description          : interface for the ESP public class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-12

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _ESPPUBCLASS_H__2011_03_12_
#define _ESPPUBCLASS_H__2011_03_12_

#include "EspString.h"

typedef struct tagCEspPoint CEspPoint;

// 类声明
struct tagCEspPoint
{
	int m_nX;
	int m_nY;
};

// 成员函数声明
void CEspPoint_CInit_i0p_i0p(CEspPoint* pThis, int x, int y);
void CEspPoint_Operator_AddEqu_CEspPoint1p(CEspPoint* pThis, const CEspPoint * pt);
void CEspPoint_Operator_SubEqu_CEspPoint1p(CEspPoint* pThis, const CEspPoint * pt);
int CEspPoint_Operator_NotEqu_CEspPoint1p(const CEspPoint* pThis, const CEspPoint * pt);


typedef struct tagCEspSize CEspSize;

// 类声明
struct tagCEspSize
{
	int m_nWidth;
	int m_nHeight;
};

// 成员函数声明
void CEspSize_CInit_i0p_i0p(CEspSize* pThis, int nWidth, int nHeight);
int CEspSize_Operator_EquEqu_CEspSize1p(const CEspSize* pThis, const CEspSize * size);


typedef struct tagCEspRect CEspRect;

// 类声明
struct tagCEspRect
{
	CEspPoint m_ptLT;
	CEspPoint m_ptRB;
	CEspSize m_oSize;
};

// 成员函数声明
void CEspRect_CInit(CEspRect* pThis);
void CEspRect_CInit_i0p_i0p_i0p_i0p(CEspRect* pThis, int nLTx, int nLTy, int nRBx, int nRBy);
void CEspRect_CInit_CEspPoint1p_CEspPoint1p(CEspRect* pThis, const CEspPoint * ptLT, const CEspPoint * ptRB);
void CEspRect_Operator_AddEqu_CEspRect1p(CEspRect* pThis, const CEspRect * pt);
int CEspRect_Operator_NotEqu_CEspRect1p(const CEspRect* pThis, const CEspRect * pt);
const CEspSize *  CEspRect_GetSize(const CEspRect* pThis);
int CEspRect_InterRect_CEspRect1p_CEspRect1p(const CEspRect* pThis, const CEspRect * rect, CEspRect * DesRect);


#endif /* _ESPPUBCLASS_H__2011_03_12_ */
