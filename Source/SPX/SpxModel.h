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

// 模型，主要用于对数据和逻辑的封装，其派生类提供具体的数据访问接口
// 注意，在Observer中可以强制将Model转换为其原来的类型，然后访问数据
class CSpxModel
{
public:
	CSpxModel(int nObserverMaxCount = 1);
	virtual ~CSpxModel();

	bool RegisterObserver(ISpxObserver* pObserver);
	void RemoveObserver(ISpxObserver* pObserver);

	// 模型改变了，通知View及时更新显示
	void DataUpdate();

private:
	ISpxObserver**	m_ppObserver;
	int				m_nObserverCount;
	int				m_nObserverMaxCount;
};

#endif /* _ESPMODEL_H_2011_03_10_ */
