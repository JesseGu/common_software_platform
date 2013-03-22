/******************************************************************************
* FileName		       : TabPage1.cpp
* Description          : implementation of the CTabPage1 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "TabPage1.h"
#include "AwsUserDefine.h"
#include "IAwsGc.h"
#include "BLabel.h"
#include "BProgressBar.h"
#include "BButton.h"

CAwsContainer* CTabPage1Builder::Build(CAwsWindow* pParent, const CEspRect& rect)
{
	CAwsContainer* pContainer = new CTabPage1;
	pContainer->Create(pParent, rect);

	return pContainer;
}

CTabPage1::CTabPage1()
{
	m_pLabel = ESP_NULL;

	m_pProgressBar = ESP_NULL;
	m_nProgressBarLength = 100;
	m_nCurProgressBarPos = 0;

	m_pButton = ESP_NULL;

	m_bIsStart = false;
}

void CTabPage1::OnCreate()
{
	// 创建各种控件
	CAwsString str;
	CEspRect rtLabel(100, 20, 180, 40), rtButton(90, 50, 150, 70), rtProgressBar(75, 90, 175, 100);
	CAwsRgb rgbText(173, 154, 132);

	m_pLabel = new CBLabel;
	m_pLabel->Create(this, rtLabel);
	str.LoadString(StringID_ProgressBar);
	m_pLabel->SetBKTransparent(true);
	m_pLabel->SetTextColor(rgbText);
	m_pLabel->SetText(str);
	AddSubWnd(m_pLabel, false);

	m_pButton = new CBButton;
	m_pButton->Create(this, rtButton, EWndID_Button1);
	str.LoadString(StringID_Start);
	m_pButton->SetText(str);
	AddSubWnd(m_pButton, true);

	m_pProgressBar = new CBProgressBar;
	m_pProgressBar->Create(this, rtProgressBar);
	m_pProgressBar->SetTotalLenght(m_nProgressBarLength);
	AddSubWnd(m_pProgressBar, false);
}

bool CTabPage1::OnKey(AWS_KeyType type, AWS_KeyCode code)
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

bool CTabPage1::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	CAwsString str;

	if ( AWS_SysCmd_ButtonCmd == nCmdID && nWndID == EWndID_Button1 )
	{
		if ( !m_bIsStart )
		{
			StartTimer(100);
			str.LoadString(StringID_End);
			m_pButton->SetText(str);
		}
		else
		{
			EndTimer();
			str.LoadString(StringID_Start);
			m_pButton->SetText(str);
		}

		m_bIsStart = !m_bIsStart;

		return true;
	}

	return CAwsContainer::OnCommand(nWndID, nCmdID, nParam1, nParam2);
}

void CTabPage1::OnTimer()
{
	if ( ESP_NULL != m_pProgressBar )
	{
		m_pProgressBar->SetPos(m_nCurProgressBarPos++);

		if ( m_nCurProgressBarPos > m_nProgressBarLength )
			m_nCurProgressBarPos = 1;
	}
}

void CTabPage1::OnFocus(bool bIsFocus)
{
	CAwsContainer::OnFocus(bIsFocus);

	if ( m_bIsFocus )
	{
//		StartTimer(100);
	}
	else
	{
		// 停止
		CAwsString str;
		EndTimer();
		str.LoadString(StringID_Start);
		m_pButton->SetText(str);
		m_bIsStart = false;
	}
}

void CTabPage1::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();
	CAwsRgb rgbPen(0, 0, 0), rgbBrush(0, 0, 0);
	pGc->SetPenColor(rgbPen);
	pGc->SetBrushColor(rgbBrush);
	pGc->DrawFillRect(rect);

	CAwsContainer::OnDraw(rect);
}
