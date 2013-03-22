/******************************************************************************
* FileName		       : IOsThread.h
* Description          : interface of the IOsThread
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-11

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _IOSTHREAD_H_2011_03_11_
#define _IOSTHREAD_H_2011_03_11_

class IRunable
{
public:
	virtual int Run() = 0;
};

class IOsThread
{
public:
	virtual void Start() = 0;
	virtual void Suspend() = 0;
	virtual void Resume() = 0;
	virtual void Stop() = 0;
	virtual void Join() = 0;

protected:
	IRunable*		m_pRunable;
	unsigned int	m_nThreadId;
};

#endif /* _IOSTHREAD_H_2011_03_11_ */
