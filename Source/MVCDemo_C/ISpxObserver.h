/******************************************************************************
* FileName		       : IEspObserver.h
* Description          : interface of the IEspObserver
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _IESPOBSERVER_H_2011_03_10_
#define _IESPOBSERVER_H_2011_03_10_

typedef struct tagCSpxModel CSpxModel;


// 观察者接口，用于在View中实现
typedef struct tagISpxObserver ISpxObserver;

// 虚函数表
typedef void(*PVISpxObserver_UpdateData_CSpxModel1p)(ISpxObserver* pThis, CSpxModel *  pModel);
typedef int(*PVISpxObserver_GetObserverID)(ISpxObserver* pThis);
typedef struct tagVTab_ISpxObserver VTab_ISpxObserver;
struct tagVTab_ISpxObserver
{
	PVISpxObserver_UpdateData_CSpxModel1p	m_pUpdateData_CSpxModel1p;
	PVISpxObserver_GetObserverID	m_pGetObserverID;
};

// 类声明
struct tagISpxObserver
{
	const VTab_ISpxObserver*	m_pVTab;
};

// 成员函数声明
void ISpxObserver_UpdateData_CSpxModel1p(ISpxObserver* pThis, CSpxModel *  pModel);
int ISpxObserver_GetObserverID(ISpxObserver* pThis);

// 虚函数表的声明
extern const VTab_ISpxObserver g_tVTab_ISpxObserver_ISpxObserver;


#endif /* _IESPOBSERVER_H_2011_03_10_ */
