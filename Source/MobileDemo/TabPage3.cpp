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

#include "TabPage3.h"
#include "AwsUserDefine.h"
#include "IAwsGc.h"
#include "BButton.h"
#include "BImageButton.h"
#include "BRadioBox.h"
#include "BCheckBox.h"
#include "MMsgBox.h"

CAwsContainer* CTabPage3Builder::Build(CAwsWindow* pParent, const CEspRect& rect)
{
	CAwsContainer* pContainer = new CTabPage3;
	pContainer->Create(pParent, rect);

	return pContainer;
}

CTabPage3::CTabPage3()
{
	m_pButton = ESP_NULL;
	m_pImageButton = ESP_NULL;
	m_pRadioBox = ESP_NULL;
	m_pCheckBox = ESP_NULL;
}

void CTabPage3::OnCreate()
{
	CAwsString str;

	CEspRect rtRadioBox(90, 60, 150, 80), rtCheckBox(90, 90, 150, 110), rtImageButton(90, 120, 150, 180), rtButton(90, 20, 150, 40);
	CAwsRgb rgbRBText(173, 154, 132), rgbRBTextFocus(255, 255, 255), rgbCBText(173, 154, 132), rgbCBTextFocus(255, 255, 255), rgbIBText(168,155,131);
	CEspSize sizeRB(15, 15), sizeCB(16, 16), sizeIB(40, 40);

	m_pRadioBox = new CBRadioBox;
	m_pRadioBox->Create(this, rtRadioBox);
	str.LoadString(StringID_RadioBox);
	m_pRadioBox->SetText(str);
	m_pRadioBox->SetTextColor(rgbRBText);
	m_pRadioBox->SetTextFocusColor(rgbRBTextFocus);
	CAwsImage image, imageFocus, imageSel, imageSelFocus, imageMask;
	image.LoadImage(IDB_RADIO);
	imageFocus.LoadImage(IDB_RADIOFOCUS);
	imageSel.LoadImage(IDB_RADIOSEL);
	imageSelFocus.LoadImage(IDB_RADIOSELFOCUS);
	imageMask.LoadImage(IDB_RADIOMASK);
	m_pRadioBox->SetImage(image, imageFocus, imageSel, imageSelFocus, imageMask);
	m_pRadioBox->SetIconSize(sizeRB);
	AddSubWnd(m_pRadioBox, true);

	m_pCheckBox = new CBCheckBox;
	m_pCheckBox->Create(this, rtCheckBox);
	str.LoadString(StringID_CheckBox);
	m_pCheckBox->SetText(str);
	m_pCheckBox->SetTextColor(rgbCBText);
	m_pCheckBox->SetTextFocusColor(rgbCBTextFocus);
	image.LoadImage(IDB_CHECK);
	imageFocus.LoadImage(IDB_CHECKFOCUS);
	imageSel.LoadImage(IDB_CHECKSEL);
	imageSelFocus.LoadImage(IDB_CHECKSELFOCUS);
	imageMask.LoadImage(IDB_CHECKMASK);
	m_pCheckBox->SetImage(image, imageFocus, imageSel, imageSelFocus, imageMask);
	m_pCheckBox->SetIconSize(sizeCB);
	AddSubWnd(m_pCheckBox, true);

	m_pImageButton = new CBImageButton;
	m_pImageButton->Create(this, rtImageButton, EWndID_Button2);
	m_pImageButton->SetMode(MIBMode_IconTop);
	image.LoadImage(IDB_MAIN1);
	imageMask.LoadImage(IDB_MAINMASK);
	m_pImageButton->SetImage(image, imageMask);
	str.LoadString(StringID_Button);
	m_pImageButton->SetText(str);
	m_pImageButton->SetBKTransparent(true);
	m_pImageButton->SetIconSize(sizeIB);
	m_pImageButton->SetTextColor(rgbIBText);
	AddSubWnd(m_pImageButton, true);

	m_pButton = new CBButton;
	m_pButton->Create(this, rtButton, EWndID_Button1);
	str.LoadString(StringID_Button);
	m_pButton->SetText(str);
//	m_pButton->SetTextColor(CAwsRgb(173, 154, 132));
//	m_pButton->SetTextFocusColor(CAwsRgb(255, 255, 255));
	AddSubWnd(m_pButton, true);
}

bool CTabPage3::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	if ( AWS_SysCmd_ButtonCmd == nCmdID )
	{
		if ( EWndID_Button1 == nWndID || EWndID_Button2 == nWndID )
		{
			CMMsgBox* pMsg = new CMMsgBox(this, EWndID_Msg_Selected);
			CAwsString str;
			str.LoadString(StringID_WelcomeUse);
			pMsg->ShowMsg(AWS_MBT_OK, str);
		}
	}

	return CAwsContainer::OnCommand(nWndID, nCmdID, nParam1, nParam2);
}

bool CTabPage3::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	bool bRet = CAwsContainer::OnKey(type, code);

	if ( !bRet )
	{
		if ( AWS_Key == type )
		{
			switch ( code )
			{
			case AWS_KeyCode_UpArrow:
				PreFocusWnd();
				bRet = true;
				break;

			case AWS_KeyCode_DownArrow:
				NextFocusWnd();
				bRet = true;
				break;
			}
		}
	}

	return bRet;
}

void CTabPage3::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();
	CAwsRgb rgbPen(0, 0, 0), rgbBrush(0, 0, 0);
	pGc->SetPenColor(rgbPen);
	pGc->SetBrushColor(rgbBrush);
	pGc->DrawFillRect(rect);

	CAwsContainer::OnDraw(rect);
}
