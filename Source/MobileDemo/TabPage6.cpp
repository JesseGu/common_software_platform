/******************************************************************************
* FileName		       : TabPage6.cpp
* Description          : implementation of the CTabPage6 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "TabPage6.h"
#include "AwsUserDefine.h"
#include "IAwsGc.h"
#include "MScrollLabel.h"
#include "BButton.h"
#include "BLabel.h"

CAwsContainer* CTabPage6Builder::Build(CAwsWindow* pParent, const CEspRect& rect)
{
	CAwsContainer* pContainer = new CTabPage6;
	pContainer->Create(pParent, rect);

	return pContainer;
}

CTabPage6::CTabPage6()
{
	m_pScrollLabel = ESP_NULL;
	m_pButton = ESP_NULL;

	m_pLabel = ESP_NULL;
}

void CTabPage6::OnCreate()
{
	CAwsContainer::OnCreate();

	CAwsString str;
	CEspRect rtLabel(95, 20, 190, 40), rtButton(90, 50, 150, 70), rtScrollLabel(80, 90, 180, 110);
	CAwsRgb rgbLText(173, 154, 132), rgbSLText(173, 154, 132);

	m_pLabel = new CBLabel;
	m_pLabel->Create(this, rtLabel);
	str.LoadString(StringID_ScrollLabel);
	m_pLabel->SetBKTransparent(true);
	m_pLabel->SetTextColor(rgbLText);
	m_pLabel->SetText(str);
	AddSubWnd(m_pLabel, false);

	m_pButton = new CBButton;
	m_pButton->Create(this, rtButton, EWndID_Button1);
	str.LoadString(StringID_Start);
	m_pButton->SetText(str);
	AddSubWnd(m_pButton, true);

	m_pScrollLabel = new CMScrollLabel;
	m_pScrollLabel->Create(this, rtScrollLabel);
	str.LoadString(StringID_NJUST);
	m_pScrollLabel->SetBKTransparent(true);
	m_pScrollLabel->SetTextColor(rgbSLText);
	m_pScrollLabel->SetText(str);
	AddSubWnd(m_pScrollLabel, false);

}

void CTabPage6::OnFocus(bool bIsFocus)
{
	CAwsContainer::OnFocus(bIsFocus);

	if ( !m_bIsFocus )
	{
		m_pScrollLabel->EndScroll();
	}
}

bool CTabPage6::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	CAwsString str;
	if ( AWS_SysCmd_ButtonCmd == nCmdID && nWndID == EWndID_Button1 )
	{
		if ( m_pScrollLabel->IsStartScroll() )
		{
			m_pScrollLabel->EndScroll();
		}
		else
		{
			str.LoadString(StringID_End);
			m_pButton->SetText(str);
			m_pScrollLabel->StartScroll(1);
		}

		return true;
	}
	else if ( AWS_SysCmd_ScrollLabelEndScroll == nCmdID )
	{
		str.LoadString(StringID_Start);
		m_pButton->SetText(str);
	}

	return CAwsContainer::OnCommand(nWndID, nCmdID, nParam1, nParam2);
}

bool CTabPage6::OnKey(AWS_KeyType type, AWS_KeyCode code)
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

void CTabPage6::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();
	CAwsRgb rgbPen(0, 0, 0), rgbBrush(0, 0, 0);
	pGc->SetPenColor(rgbPen);
	pGc->SetBrushColor(rgbBrush);
	pGc->DrawFillRect(rect);

	CAwsContainer::OnDraw(rect);
}
