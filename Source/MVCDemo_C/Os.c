/******************************************************************************
* FileName		       : Os.cpp
* Description          : implementation of the Os class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-12

*------------------------------------------------------------------------------
* Copyright (C) 2011 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "EspSysDefine.h"
#include "Os.h"
const VTab_COs g_tVTab_COs_COs = {COs_InitOs};
void COs_InitOs(COs* pThis) { } 

IOsFile * COs_GetFile(COs* pThis) { return pThis->m_pFile; } 


void COs_CInit(COs* pThis)
{

	pThis->m_pVTab = &g_tVTab_COs_COs;
{
	pThis->m_pFile=ESP_NULL;
}
}
