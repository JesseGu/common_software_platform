/******************************************************************************
* FileName		       : BTabPanel.cpp
* Description          : implementation of the CBTabPanel class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BTabPanel.h"
#include "BSelectBox.h"
#include "IAwsGc.h"

CBTabPanel::CBTabPanel()
{
	m_pSelectBox = ESP_NULL;
}

void CBTabPanel::OnCreate()
{
	CEspRect rt(0, 0, 180, 30);
	m_pSelectBox = new CBSelectBox(10);
	m_pSelectBox->Create(this, rt);
	AddSubWnd(m_pSelectBox, true);
}

bool CBTabPanel::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	if ( AWS_SysCmd_SelectBoxFocusItemChange == nCmdID )
	{
		// 收到改变的消息
		PumpCommand(m_nWndID, AWS_SysCmd_TabPanelChangePage, nParam1);

		return true;
	}

	return CAwsContainer::OnCommand(nWndID, nCmdID, nParam1, nParam2);
}

void CBTabPanel::SetBKImage(const CAwsImage& imageBK)
{
	m_oImageBK = imageBK;
}

void CBTabPanel::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();

	if ( m_oImageBK.GetID() > 0 )
	{
		// 画背景图片
		CEspPoint pt(0, 0);
		pGc->DrawImage(pt, m_oImageBK);
	}

	CAwsContainer::OnDraw(rect);
}
