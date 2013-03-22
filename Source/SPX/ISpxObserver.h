/******************************************************************************
* FileName		       : IEspObserver.h
* Description          : interface of the IEspObserver
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _IESPOBSERVER_H_2011_03_10_
#define _IESPOBSERVER_H_2011_03_10_

class CSpxModel;

// 观察者接口，用于在View中实现
class ISpxObserver
{
public:
	virtual void UpdateData(CSpxModel* pModel) = 0;
	virtual int GetObserverID() = 0;
};

#endif /* _IESPOBSERVER_H_2011_03_10_ */
