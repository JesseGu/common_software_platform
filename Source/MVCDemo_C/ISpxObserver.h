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


// �۲��߽ӿڣ�������View��ʵ��
typedef struct tagISpxObserver ISpxObserver;

// �麯����
typedef void(*PVISpxObserver_UpdateData_CSpxModel1p)(ISpxObserver* pThis, CSpxModel *  pModel);
typedef int(*PVISpxObserver_GetObserverID)(ISpxObserver* pThis);
typedef struct tagVTab_ISpxObserver VTab_ISpxObserver;
struct tagVTab_ISpxObserver
{
	PVISpxObserver_UpdateData_CSpxModel1p	m_pUpdateData_CSpxModel1p;
	PVISpxObserver_GetObserverID	m_pGetObserverID;
};

// ������
struct tagISpxObserver
{
	const VTab_ISpxObserver*	m_pVTab;
};

// ��Ա��������
void ISpxObserver_UpdateData_CSpxModel1p(ISpxObserver* pThis, CSpxModel *  pModel);
int ISpxObserver_GetObserverID(ISpxObserver* pThis);

// �麯���������
extern const VTab_ISpxObserver g_tVTab_ISpxObserver_ISpxObserver;


#endif /* _IESPOBSERVER_H_2011_03_10_ */
