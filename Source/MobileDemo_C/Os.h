/******************************************************************************
* FileName		       : Os.h
* Description          : interface for the the Os class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-12

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _OS_H_2011_03_12_
#define _OS_H_2011_03_12_

typedef struct tagIOsFile IOsFile;


typedef struct tagCOs COs;

// 虚函数表
typedef void(*PVCOs_InitOs)(COs* pThis);
typedef struct tagVTab_COs VTab_COs;
struct tagVTab_COs
{
	PVCOs_InitOs	m_pInitOs;
};

// 类声明
struct tagCOs
{
	IOsFile *  m_pFile;
	const VTab_COs*	m_pVTab;
};

// 成员函数声明
void COs_InitOs(COs* pThis);
void COs_CInit(COs* pThis);
IOsFile *  COs_GetFile(COs* pThis);

// 虚函数表的声明
extern const VTab_COs g_tVTab_COs_COs;


#endif /* _OS_H_2011_03_12_ */
