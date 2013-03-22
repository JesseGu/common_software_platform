/******************************************************************************
* FileName		       : SpxApp.h
* Description          : interface for the CSpxApp class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-10

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _ESPAPP_H_2011_03_10_
#define _ESPAPP_H_2011_03_10_

#include "SpxSysDefine.h"
#include "AWS.h"
#include "AwsUi.h"

typedef struct tagCOs COs;

typedef struct tagCSpxController CSpxController;


// 管理所有的Controller，在其派生类中创建所有Controller
typedef struct tagCSpxApp CSpxApp;

// 虚函数表
typedef void(*PVCSpxApp_DUninit_i1p)(CSpxApp* pThis, int * pOffset);
typedef void(*PVCSpxApp_OnInit_CEspSize1p)(CSpxApp* pThis, const CEspSize * sizeScreen);
typedef struct tagVTab_CSpxApp VTab_CSpxApp;
struct tagVTab_CSpxApp
{
	PVCSpxApp_DUninit_i1p	m_pDUninit_i1p;
	PVCSpxApp_OnInit_CEspSize1p	m_pOnInit_CEspSize1p;
};

// 类声明
struct tagCSpxApp
{
	CSpxController * *  m_ppController;
	int m_nMaxControllerCount;
	int m_nControllerCount;
	CAwsUi *  m_pUi;
	COs *  m_pOs;
	const VTab_CSpxApp*	m_pVTab;
};

// 成员函数声明
void CSpxApp_DUninit_i1p(CSpxApp* pThis, int * pOffset);
void CSpxApp_OnInit_CEspSize1p(CSpxApp* pThis, const CEspSize * sizeScreen);
void CSpxApp_CInit_i0p(CSpxApp* pThis, int nMaxControllerCount);
void CSpxApp_Init_CAwsUi1p_COs1p(CSpxApp* pThis, CAwsUi *  pUi, COs *  pOs);
CAwsUi *  CSpxApp_GetUi_CAwsUi1p(CSpxApp* pThis, CAwsUi *  pUi);
COs *  CSpxApp_GetOs_COs1p(CSpxApp* pThis, COs *  pOs);
int CSpxApp_OnCommand_i0p_i0p_i0p_i0p(CSpxApp* pThis, int nWndID, int nCmdID, int nParam1, int nParam2);
int CSpxApp_AddController_CSpxController1p(CSpxApp* pThis, CSpxController *  pController);
void CSpxApp_RemoveController_CSpxController1p(CSpxApp* pThis, CSpxController *  pController);

// 虚函数表的声明
extern const VTab_CSpxApp g_tVTab_CSpxApp_CSpxApp;


#endif /* _ESPAPP_H_2011_03_10_ */
