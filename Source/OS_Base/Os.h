/******************************************************************************
* FileName		       : Os.h
* Description          : interface for the the Os class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-12

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _OS_H_2011_03_12_
#define _OS_H_2011_03_12_

class IOsFile;
class IOsThread;
class IRunable;

class COs
{
public:
	virtual IOsFile* GetFile() = 0;
	virtual IOsThread* GetThread(IRunable* pRunable) = 0;
};

#endif /* _OS_H_2011_03_12_ */
