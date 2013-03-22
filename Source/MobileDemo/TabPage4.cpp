/******************************************************************************
* FileName		       : TabPage4.cpp
* Description          : implementation of the CTabPage4 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "TabPage4.h"
#include "AwsUserDefine.h"
#include "IAwsGc.h"
#include "BSelectBox.h"
#include "MImageBox.h"
#include "BLabel.h"

CAwsContainer* CTabPage4Builder::Build(CAwsWindow* pParent, const CEspRect& rect)
{
	CAwsContainer* pContainer = new CTabPage4;	
	pContainer->Create(pParent, rect);
	
	return pContainer;
}

CTabPage4::CTabPage4()
{
	m_pLabel = ESP_NULL;
	m_pImageBox = ESP_NULL;
	m_pSelectBox = ESP_NULL;
}

void CTabPage4::OnCreate()
{
	CAwsString str;
	CEspRect rtLabel(100, 20, 200, 40), rtImageBox(100, 50, 140, 90), rtSelectBox(70, 100, 180, 120);
	CAwsRgb rgbLabelText(173, 154, 132);

	m_pLabel = new CBLabel;
	m_pLabel->Create(this, rtLabel);
	str.LoadString(StringID_SelectBox);
	m_pLabel->SetBKTransparent(true);
	m_pLabel->SetTextColor(rgbLabelText);
	m_pLabel->SetText(str);
	AddSubWnd(m_pLabel, false);

	m_pImageBox = new CMImageBox;
	m_pImageBox->Create(this, rtImageBox);
	AddSubWnd(m_pImageBox, false);
	CAwsImage image, imageMask;
	image.LoadImage(IDB_MAIN1);
	imageMask.LoadImage(IDB_MAINMASK);
	m_pImageBox->ShowImage(image, imageMask);

	m_pSelectBox = new CBSelectBox(10);
	m_pSelectBox->Create(this, rtSelectBox);
	str.LoadString(1);
	m_pSelectBox->AddItem(str);
	str.LoadString(2);
	m_pSelectBox->AddItem(str);
	str.LoadString(3);
	m_pSelectBox->AddItem(str);
	str.LoadString(4);
	m_pSelectBox->AddItem(str);
	str.LoadString(5);
	m_pSelectBox->AddItem(str);
	str.LoadString(2);
	m_pSelectBox->AddItem(str);
	m_pSelectBox->AddItemEnd();
	AddSubWnd(m_pSelectBox, true);
}

bool CTabPage4::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	if ( AWS_SysCmd_SelectBoxFocusItemChange == nCmdID )
	{
		CAwsImage image, imageMask;
		image.LoadImage(IDB_MAIN1 + nParam1);
		imageMask.LoadImage(IDB_MAINMASK);
		m_pImageBox->ShowImage(image, imageMask);

		return true;
	}

	return CAwsContainer::OnCommand(nWndID, nCmdID, nParam1, nParam2);
}

bool CTabPage4::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	bool bRet = CAwsContainer::OnKey(type, code);

	if ( !bRet )
	{
		if ( AWS_Key == type )
		{
			switch ( code )
			{
			case AWS_KeyCode_UpArrow:
				// 发送消息给TabView，说明要切换到TabPanel
				PumpCommand(m_nWndID, AWS_SysCmd_TabViewSetPanelFocus);
				break;
			}
		}
	}

	return bRet;
}

void CTabPage4::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();
	CAwsRgb rgbPen(0, 0, 0), rgbBrush(0, 0, 0);
	pGc->SetPenColor(rgbPen);
	pGc->SetBrushColor(rgbBrush);
	pGc->DrawFillRect(rect);

	CAwsContainer::OnDraw(rect);
}
