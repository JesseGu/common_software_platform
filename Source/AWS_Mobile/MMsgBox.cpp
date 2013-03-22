/******************************************************************************
* FileName		       : MMsgBox.cpp
* Description          : implementation of the CMMsgBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "MMsgBox.h"
#include "AwsUi.h"
#include "IAwsGc.h"
#include "MUi.h"
#include "MMenuBar.h"

CMMsgBox::CMMsgBox(CAwsWindow* pParentWnd, int nWndID)
{
	m_pParent = pParentWnd;

	CAwsRgb rgbBorder(73, 73, 73), rgbBK(0, 0, 0), rgbText(255, 255, 255);
	m_oBorderColor = rgbBorder;
	m_oBKColor = rgbBK;
	m_oTextColor = rgbText;

	m_nFontSize = 12;

	m_nWndID = nWndID;
}

void CMMsgBox::ShowMsg(AWS_MsgBoxType eType, const CAwsString& strText)
{
	m_eType = eType;
	m_strText = strText;

	CAwsWindow* pWnd = this;
	while ( ESP_NULL != pWnd->GetParent() )
		pWnd = pWnd->GetParent();

	CMUi* pUi = (CMUi*)pWnd;
	CAwsString str;

	switch ( m_eType )
	{
	case AWS_MBT_OK_Cancel:
		str.LoadString(StringID_OK);
		pUi->GetMenuBar()->SetLeftMenuText(str);
		str.LoadString(StringID_Cancel);
		pUi->GetMenuBar()->SetRightMenuText(str);
		break;

	case AWS_MBT_OK:
		str.LoadString(StringID_OK);
		pUi->GetMenuBar()->SetLeftMenuText(str);
		str.LoadString(StringID_NULL);
		pUi->GetMenuBar()->SetRightMenuText(str);
		break;
	}

	//  弹出窗口
	CEspRect rect;
	CEspSize sizeScreen = *pUi->GetSize();
	rect.m_ptRB.m_nX = sizeScreen.m_nWidth;
	rect.m_ptRB.m_nY = sizeScreen.m_nHeight - pUi->GetMenuBar()->GetSize()->m_nHeight;
	rect.m_ptLT.m_nY = rect.m_ptRB.m_nY - 80;

	PopWnd(this, rect, m_nWndID);
}

void CMMsgBox::DrawBK(IAwsGc* pGc, const CEspRect& rect)
{
	pGc->SetPenColor(m_oBorderColor);
	pGc->SetBrushColor(m_oBKColor);
	pGc->DrawFillRect(rect);
}

void CMMsgBox::DrawInf(IAwsGc* pGc, const CEspRect& rect)
{
	pGc->SetTextColor(m_oTextColor);

	pGc->SetTextAlignment(AWS_TAM_Mid);

	m_oFont.CreateFont(0, m_nFontSize);
	pGc->UseFont(m_oFont);
	const CEspSize* size = pGc->GetTextSize(m_strText);
	CEspRect rt = rect;
	rt.m_ptLT.m_nY = rt.m_ptLT.m_nY + (rect.GetSize()->m_nHeight - size->m_nHeight) / 2;

	pGc->DrawText(m_strText, rt);
	pGc->DiscardFont();
}

void CMMsgBox::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();

	if ( ESP_NULL != pGc )
	{
		// 画背景
		DrawBK(pGc, rect);

		// 画信息
		DrawInf(pGc, rect);
	}

	CAwsContainer::OnDraw(rect);
}

bool CMMsgBox::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	if ( AWS_SysCmd_LeftMenuClick == nCmdID )
	{
		PumpCommand(m_nWndID, AWS_SysCmd_MsgBox_OK);
		return true;
	}

	return false;
}

void CMMsgBox::OnLeftMenu()
{
	DestroyPopWnd();

	switch ( m_eType )
	{
	case AWS_MBT_OK_Cancel:
		PumpCommand(m_nWndID, AWS_SysCmd_MsgBox_OK);
		break;

	case AWS_MBT_OK:
		PumpCommand(m_nWndID, AWS_SysCmd_MsgBox_OK);
		break;
	}
}

void CMMsgBox::OnRightMenu()
{
	switch ( m_eType )
	{
	case AWS_MBT_OK_Cancel:
		DestroyPopWnd();
		PumpCommand(m_nWndID, AWS_SysCmd_MsgBox_Cancel);
		break;
	}
}

bool CMMsgBox::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	if ( AWS_Key_Up == type )
	{
		switch ( code )
		{
		case AWS_KeyCode_LeftMenu:
			OnLeftMenu();
			return true;

		case AWS_KeyCode_RightMenu:
			OnRightMenu();
			return true;
		}
	}

	if ( AWS_Key == type )
	{
		switch ( code )
		{
		case AWS_KeyCode_OK:
			return OnKey(AWS_Key_Up, AWS_KeyCode_LeftMenu);
		}
	}

	return true;
//	return CAwsContainer::OnKey(type, code);
}
