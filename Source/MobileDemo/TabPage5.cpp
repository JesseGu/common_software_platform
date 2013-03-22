/******************************************************************************
* FileName		       : TabPage5.cpp
* Description          : implementation of the CTabPage5 class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "TabPage5.h"
#include "AwsUserDefine.h"
#include "IAwsGc.h"
#include "BComboBox.h"
#include "BLabel.h"
#include "BEdit.h"

CAwsContainer* CTabPage5Builder::Build(CAwsWindow* pParent, const CEspRect& rect)
{
	CAwsContainer* pContainer = new CTabPage5;
	pContainer->Create(pParent, rect);

	return pContainer;
}

CTabPage5::CTabPage5()
{
	m_pLabel = ESP_NULL;
	m_pComboBox = ESP_NULL;

	m_pEditLabel = ESP_NULL;
	m_pEdit = ESP_NULL;
}

void CTabPage5::OnCreate()
{
	CAwsString str;
	CEspRect rtLabel(105, 20, 205, 40), rtComboBox(90, 45, 160, 66), rtEditLabel(105, 85, 205, 105), rtEdit(60, 110, 190, 130);
	CAwsRgb rgbLText(173, 154, 132), rgbELText(173, 154, 132);

	m_pLabel = new CBLabel;
	m_pLabel->Create(this, rtLabel);
	str.LoadString(StringID_ComboBox);
	m_pLabel->SetBKTransparent(true);
	m_pLabel->SetTextColor(rgbLText);
	m_pLabel->SetText(str);
	AddSubWnd(m_pLabel, false);

	m_pComboBox = new CBComboBox(10);
	m_pComboBox->Create(this, rtComboBox);
	int i;
	for ( i = 0; i < 5; ++i )
	{
		str.LoadString(i);
		m_pComboBox->AddItem(str);
	}

	m_pEditLabel = new CBLabel;
	m_pEditLabel->Create(this, rtEditLabel);
	str.LoadString(StringID_Edit);
	m_pEditLabel->SetBKTransparent(true);
	m_pEditLabel->SetTextColor(rgbELText);
	m_pEditLabel->SetText(str);
	AddSubWnd(m_pEditLabel, false);

	m_pEdit = new CBEdit;
	m_pEdit->Create(this, rtEdit);
//	CAwsString strTB;
//	char* p = "abcd我们好的efghijk";
//	strTB.SetData(p, strlen(p));
//	m_pEdit->SetDefaultString(strTB);
	CAwsRgb rgbEBorder(123, 123, 123), rgbEFocusBorder(255, 255, 255), rgbEBK(67, 67, 67), rgbEText(168,155,131), rgbECaret(255, 255, 255);
	m_pEdit->SetBorderColor(rgbEBorder);
	m_pEdit->SetFocusBorderColor(rgbEFocusBorder);
	m_pEdit->SetBKColor(rgbEBK);
	m_pEdit->SetTextColor(rgbEText);
	m_pEdit->SetCaretColor(rgbECaret);

	AddSubWnd(m_pEdit, true);
	AddSubWnd(m_pComboBox, true);
}

void CTabPage5::OnFocus(bool bIsFocus)
{
	CAwsContainer::OnFocus(bIsFocus);
}

bool CTabPage5::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	bool bRet = CAwsContainer::OnKey(type, code);

	if ( !bRet )
	{
		if ( AWS_Key == type )
		{
			switch ( code )
			{
			case AWS_KeyCode_UpArrow:
				if ( m_nFocusWndCount - 1 == m_nFocusWndIndex )
				{
					// 发送消息给TabView，说明要切换到TabPanel
					PumpCommand(m_nWndID, AWS_SysCmd_TabViewSetPanelFocus);
				}
				else
				{
					PreFocusWnd();
				}

				break;

			case AWS_KeyCode_DownArrow:
				NextFocusWnd();
				break;
			}
		}
	}

	return bRet;
}

void CTabPage5::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();
	CAwsRgb rgbPen(0, 0, 0), rgbBrush(0, 0, 0);
	pGc->SetPenColor(rgbPen);
	pGc->SetBrushColor(rgbBrush);
	pGc->DrawFillRect(rect);

	CAwsContainer::OnDraw(rect);
}
