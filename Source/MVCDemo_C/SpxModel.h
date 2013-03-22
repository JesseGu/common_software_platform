/******************************************************************************
* FileName		       : SpxModel.h
* Description          : interface for the CSpxModel class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _ESPMODEL_H_2011_03_10_
#define _ESPMODEL_H_2011_03_10_

#include "SpxSysDefine.h"

typedef struct tagISpxObserver ISpxObserver;


// 模型，主要用于对数据的封装，其派生类提供具体的数据访问接口
// 注意，在Observer中可以强制将Model转换为其原来的类型，然后访问数据
typedef struct tagCSpxModel CSpxModel;

// 虚函数表
typedef void(*PVCSpxModel_DUninit_i1p)(CSpxModel* pThis, int * pOffset);
typedef struct tagVTab_CSpxModel VTab_CSpxModel;
struct tagVTab_CSpxModel
{
	PVCSpxModel_DUninit_i1p	m_pDUninit_i1p;
};

// 类声明
struct tagCSpxModel
{
	ISpxObserver * *  m_ppObserver;
	int m_nObserverCount;
	int m_nObserverMaxCount;
	const VTab_CSpxModel*	m_pVTab;
};

// 成员函数声明
void CSpxModel_DUninit_i1p(CSpxModel* pThis, int * pOffset);
void CSpxModel_CInit_i0p(CSpxModel* pThis, int nObserverMaxCount);
int CSpxModel_RegisterObserver_ISpxObserver1p(CSpxModel* pThis, ISpxObserver *  pObserver);
void CSpxModel_RemoveObserver_ISpxObserver1p(CSpxModel* pThis, ISpxObserver *  pObserver);
void CSpxModel_DataUpdate(CSpxModel* pThis);

// 虚函数表的声明
extern const VTab_CSpxModel g_tVTab_CSpxModel_CSpxModel;


#endif /* _ESPMODEL_H_2011_03_10_ */
