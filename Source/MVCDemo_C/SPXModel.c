/******************************************************************************
* FileName		       : SpxModel.cpp
* Description          : implementation of the CSpxModel class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "ISpxObserver.h"
#include "SpxModel.h"

const VTab_CSpxModel g_tVTab_CSpxModel_CSpxModel = {CSpxModel_DUninit_i1p};
void CSpxModel_CInit_i0p(CSpxModel* pThis, int nObserverMaxCount)
{

	pThis->m_pVTab = &g_tVTab_CSpxModel_CSpxModel;
{
	pThis->m_nObserverMaxCount=nObserverMaxCount;

	if(pThis->m_nObserverMaxCount>0){
		pThis->m_ppObserver=(ISpxObserver * (*))malloc(sizeof(ISpxObserver * )*pThis->m_nObserverMaxCount);}
	else
		{pThis->m_ppObserver=ESP_NULL;}

	pThis->m_nObserverCount=0;
}
}

void CSpxModel_DUninit_i1p(CSpxModel* pThis, int * pOffset)
{
	free(pThis->m_ppObserver);;
}

int CSpxModel_RegisterObserver_ISpxObserver1p(CSpxModel* pThis, ISpxObserver *  pObserver)
{
	int bRet=1;

	if(ESP_NULL!=pObserver&&pThis->m_nObserverCount<pThis->m_nObserverMaxCount){
		pThis->m_ppObserver[pThis->m_nObserverCount++]=pObserver;}
	else
		{bRet=0;}

	return bRet;
}

void CSpxModel_RemoveObserver_ISpxObserver1p(CSpxModel* pThis, ISpxObserver *  pObserver)
{
	if(ESP_NULL!=pObserver){
	{
		int i,j;
		for(i=0;i<pThis->m_nObserverCount;++i){
		{
			if(pObserver==pThis->m_ppObserver[i]){
			{
				for(j=i;j<pThis->m_nObserverCount-1;++j){
					pThis->m_ppObserver[j]=pThis->m_ppObserver[j+1];}

				--pThis->m_nObserverCount;
				break;
			}}
		}}
	}}
}

void CSpxModel_DataUpdate(CSpxModel* pThis)
{
	// 依次通知每个观察者更新显示
	int i;
	for(i=0;i<pThis->m_nObserverCount;++i){
		pThis->m_ppObserver[i]->m_pVTab->m_pUpdateData_CSpxModel1p(pThis->m_ppObserver[i],pThis);}
}
