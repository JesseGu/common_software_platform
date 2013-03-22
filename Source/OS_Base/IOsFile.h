/******************************************************************************
* FileName		       : IOsFile.h
* Description          : interface of the IOsFile
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-12

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _IOSFILE_H_2011_03_12_
#define _IOSFILE_H_2011_03_12_

// 所有的文件都是以二进制的格式读入和写入的
enum EFileAccessFlags
{
	EFF_ReadOnly,		// 只读
	EFF_WriteOnly,		// 只写
	EFF_ReadWrite,		// 读写
};

enum EFileSeek
{
	EFS_Begin,
	EFS_Current,
	EFS_End,
};

class IOsFile
{
public:
	virtual bool Open(const char* pFileName, EFileAccessFlags eOpenFlags) = 0;
	virtual void Close() = 0;
	virtual void Seek(long nOffset, EFileSeek eFrom) = 0;
	virtual unsigned long GetCurPos() = 0;

	virtual unsigned long Read(void* pBuf, unsigned long nCount) = 0;
	virtual void Write(const void* pBuf, unsigned long nCount) = 0;
};

#endif /* _IOSFILE_H_2011_03_12_ */
