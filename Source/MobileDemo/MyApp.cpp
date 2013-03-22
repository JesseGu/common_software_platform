/******************************************************************************
* FileName		       : MyApp.cpp
* Description          : implementation of the CMyApp class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "MyApp.h"
#include "MyUi.h"

CMyApp::CMyApp()
{
}

void CMyApp::OnInit(const CEspSize& sizeScreen)
{
	CMyUi* pContainer = new CMyUi;

	CEspRect rect;
	rect.m_ptRB.m_nX = sizeScreen.m_nWidth;
	rect.m_ptRB.m_nY = sizeScreen.m_nHeight;

	pContainer->SetUi(m_pUi);
	pContainer->Create(ESP_NULL, rect);
	m_pUi->AddWndToStack(pContainer);

	m_pUi->SetTopWnd(pContainer);
}
