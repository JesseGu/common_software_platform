// MyContainer.cpp: implementation of the CMyContainer class.
//
//////////////////////////////////////////////////////////////////////

#include "SpxSysDefine.h"
#include "MVCUserDefine.h"
#include "MyContainer.h"
#include "AwsUi.h"

CMyContainer::CMyContainer(int nMaxSubWndCount) : CAwsContainer(nMaxSubWndCount)
{
}

void CMyContainer::OnCreate()
{
	CAwsString str;
	CEspRect rtButton1(40, 50, 100, 70), rtButton2(120, 50, 180, 70); 
	CEspRect rtLabel1(40, 80, 140, 100), rtLabel2(140, 80, 240, 100), rtLabel3(40, 120, 140, 140), rtLabel4(140, 120, 240, 140);

	m_pM1Button = new CBButton;
	m_pM1Button->Create(this, rtButton1, EMCID_Model1Button);
	str.LoadString(EMSID_Model1Button);
	m_pM1Button->SetText(str);
	AddSubWnd(m_pM1Button, true);

	m_pM2Button = new CBButton;
	m_pM2Button->Create(this, rtButton2, EMCID_Model2Button);
	str.LoadString(EMSID_Model2Button);
	m_pM2Button->SetText(str);
	AddSubWnd(m_pM2Button, true);

	m_pM1O1Label = new CModel1Observer1;
	m_pM1O1Label->Create(this, rtLabel1, EMSID_Model1Observer1Label);
	str.LoadString(EMSID_Model1Data1);
	m_pM1O1Label->SetText(str);
	AddSubWnd(m_pM1O1Label, false);

	m_pM1O2Label = new CModel1Observer2;
	m_pM1O2Label->Create(this, rtLabel2, EMSID_Model1Observer2Label);
	str.LoadString(EMSID_Model1Data1);
	m_pM1O2Label->SetText(str);
	AddSubWnd(m_pM1O2Label, false);

	m_pM2O1Label = new CModel2Observer1;
	m_pM2O1Label->Create(this, rtLabel3, EMSID_Model2Observer1Label);
	str.LoadString(EMSID_Model2Data1);
	m_pM2O1Label->SetText(str);
	AddSubWnd(m_pM2O1Label, false);

	m_pM2O2Label = new CModel2Observer2;
	m_pM2O2Label->Create(this, rtLabel4, EMSID_Model2Observer2Label);
	str.LoadString(EMSID_Model2Data1);
	m_pM2O2Label->SetText(str);
	AddSubWnd(m_pM2O2Label, false);

	// 将观察者注册给对应的模型
	PumpCommand(m_nWndID, SPX_SysCmd_RegisterObserver, (int)(ISpxObserver*)m_pM1O1Label);
	PumpCommand(m_nWndID, SPX_SysCmd_RegisterObserver, (int)(ISpxObserver*)m_pM1O2Label);
	PumpCommand(m_nWndID, SPX_SysCmd_RegisterObserver, (int)(ISpxObserver*)m_pM2O1Label);
	PumpCommand(m_nWndID, SPX_SysCmd_RegisterObserver, (int)(ISpxObserver*)m_pM2O2Label);
}

bool CMyContainer::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	bool bRet = CAwsContainer::OnKey(type, code);

	if ( !bRet )
	{
		if ( AWS_Key == type )
		{
			switch ( code )
			{
			case AWS_KeyCode_LeftArrow:
				PreFocusWnd();
				bRet = true;
				break;

			case AWS_KeyCode_RightArrow:
				NextFocusWnd();
				bRet = true;
				break;

			case AWS_KeyCode_RightMenu:
				GetUi()->ExitSys();
				break;
			}
		}
	}

	return bRet;
}

void CMyContainer::OnDraw(const CEspRect& rect)
{
	CAwsContainer::OnDraw(rect);
}
