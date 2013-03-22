/******************************************************************************
* FileName		       : TabPage3.cpp
* Description          : implementation of the CTabPage3 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "TabPage2.h"
#include "AwsUserDefine.h"
#include "IAwsGc.h"
#include "BListBox.h"
#include "BLabel.h"
#include "MMsgBox.h"

CAwsContainer* CTabPage2Builder::Build(CAwsWindow* pParent, const CEspRect& rect)
{
	CAwsContainer* pContainer = new CTabPage2;
	pContainer->Create(pParent, rect);

	return pContainer;
}

CTabPage2::CTabPage2()
{
	m_pListBox = ESP_NULL;
}

void CTabPage2::OnCreate()
{
	CAwsString str;

	CEspRect rtLabel(100, 20, 200, 40), rtListBox(70, 50, 170, 152);
	CAwsRgb rgbText(173, 154, 132), rgbBorder(173, 154, 132);

	m_pLabel = new CBLabel;
	m_pLabel->Create(this, rtLabel);
	str.LoadString(StringID_ListBox);
	m_pLabel->SetBKTransparent(true);
	m_pLabel->SetTextColor(rgbText);
	m_pLabel->SetText(str);
	AddSubWnd(m_pLabel, false);

	m_pListBox = new CBListBox(30);
	m_pListBox->Create(this, rtListBox);
	int i;
	for ( i = 1; i <= 10; ++i )
	{
		str.LoadString(i);
		m_pListBox->AddItem(str);
	}
	m_pListBox->AddItemEnd();
	m_pListBox->SetBorderColor(rgbBorder);
	AddSubWnd(m_pListBox, true);
}

bool CTabPage2::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	if ( AWS_SysCmd_ListBoxCmd == nCmdID )
	{
		CMMsgBox* pMsg = new CMMsgBox(this, EWndID_Msg_Selected);
		CAwsString str;
		str.LoadString(StringID_WelcomeUse);
		pMsg->ShowMsg(AWS_MBT_OK, str);
	}

	return CAwsContainer::OnCommand(nWndID, nCmdID, nParam1, nParam2);
}

void CTabPage2::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();
	CAwsRgb rgbPen(0, 0, 0), rgbBrush(0, 0, 0);

	pGc->SetPenColor(rgbPen);
	pGc->SetBrushColor(rgbBrush);
	pGc->DrawFillRect(rect);

	CAwsContainer::OnDraw(rect);
}
