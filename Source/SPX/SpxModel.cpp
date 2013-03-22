/******************************************************************************
* FileName		       : SpxModel.cpp
* Description          : implementation of the CSpxModel class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "ISpxObserver.h"
#include "SpxModel.h"

CSpxModel::CSpxModel(int nObserverMaxCount /*= 1*/)
{
	m_nObserverMaxCount = nObserverMaxCount;

	if ( m_nObserverMaxCount > 0 )
		m_ppObserver = new ISpxObserver*[m_nObserverMaxCount];
	else
		m_ppObserver = ESP_NULL;

	m_nObserverCount = 0;
}

CSpxModel::~CSpxModel()
{
	delete []m_ppObserver;
}

bool CSpxModel::RegisterObserver(ISpxObserver* pObserver)
{
	bool bRet = true;

	if ( ESP_NULL != pObserver && m_nObserverCount < m_nObserverMaxCount )
		m_ppObserver[m_nObserverCount++] = pObserver;
	else
		bRet = false;

	return bRet;
}

void CSpxModel::RemoveObserver(ISpxObserver* pObserver)
{
	if ( ESP_NULL != pObserver )
	{
		int i, j;
		for ( i = 0; i < m_nObserverCount; ++i )
		{
			if ( pObserver == m_ppObserver[i] )
			{
				for ( j = i; j < m_nObserverCount - 1; ++j )
					m_ppObserver[j] = m_ppObserver[j + 1];

				--m_nObserverCount;
				break;
			}
		}
	}
}

void CSpxModel::DataUpdate()
{
	// 依次通知每个观察者更新显示
	int i;
	for ( i = 0; i < m_nObserverCount; ++i )
		m_ppObserver[i]->UpdateData(this);
}
