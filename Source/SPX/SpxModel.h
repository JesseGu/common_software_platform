/******************************************************************************
* FileName		       : SpxModel.h
* Description          : interface for the CSpxModel class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _ESPMODEL_H_2011_03_10_
#define _ESPMODEL_H_2011_03_10_

#include "SpxSysDefine.h"

class ISpxObserver;

// ģ�ͣ���Ҫ���ڶ����ݺ��߼��ķ�װ�����������ṩ��������ݷ��ʽӿ�
// ע�⣬��Observer�п���ǿ�ƽ�Modelת��Ϊ��ԭ�������ͣ�Ȼ���������
class CSpxModel
{
public:
	CSpxModel(int nObserverMaxCount = 1);
	virtual ~CSpxModel();

	bool RegisterObserver(ISpxObserver* pObserver);
	void RemoveObserver(ISpxObserver* pObserver);

	// ģ�͸ı��ˣ�֪ͨView��ʱ������ʾ
	void DataUpdate();

private:
	ISpxObserver**	m_ppObserver;
	int				m_nObserverCount;
	int				m_nObserverMaxCount;
};

#endif /* _ESPMODEL_H_2011_03_10_ */
