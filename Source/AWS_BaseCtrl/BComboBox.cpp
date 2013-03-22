/******************************************************************************
* FileName		       : BComboBox.cpp
* Description          : implementation of the CBComboBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BComboBox.h"
#include "IAwsGc.h"
#include "BMenu.h"

CBComboBox::CBComboBox(int nMaxItemCount)
{
	m_nMaxItemCount = nMaxItemCount;
	m_nItemCount = 0;
	m_nCurItemIndex = 0;
	m_pItemData = new CAwsString[m_nMaxItemCount];

	m_nItemHeight = 20;

	m_nBorderWidth = 1;
	
	m_oIconSize.m_nWidth = 16;
	m_oIconSize.m_nHeight = 17;
	m_nLeftMargin = 3;
	m_nRightMargin = 1;

	CAwsRgb rgbBorder(123, 123, 123), rgbFocusBorder(255, 255, 255), rgbBK(67, 67, 67), rgbFocusBK(67, 67, 67), rgbText(168,155,131), rgbFocusText(255, 255, 255);
	m_oBorderColor = rgbBorder;
	m_oFocusBorderColor = rgbFocusBorder;
	m_oBKColor = rgbBK;
	m_oFocusBKColor = rgbFocusBK;
	m_oTextColor = rgbText;
	m_oFocusTextColor = rgbFocusText;

	m_nFontSize = 12;
}

CBComboBox::~CBComboBox()
{
	delete []m_pItemData;
	m_pItemData = ESP_NULL;
}

void CBComboBox::OnCreate()
{
}

void CBComboBox::AddItem(const CAwsString& strText)
{
	if ( m_nItemCount < m_nMaxItemCount )
	{
		m_pItemData[m_nItemCount++] = strText;
	}
}

void CBComboBox::SetIcon(const CAwsImage& icon, const CAwsImage& iconMask)
{
	m_oIcon = icon;
	m_oIconMask = iconMask;
}

bool CBComboBox::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	if ( AWS_ComboBox_PopupWnd == nWndID && AWS_SysCmd_MenuCmd == nCmdID )
	{
		PumpCommand(m_nWndID, AWS_SysCmd_ComboBoxItemChange, nParam1);
		m_nCurItemIndex = nParam1;

		// 弹出式菜单已经销毁了
		return true;
	}

	return CAwsContainer::OnCommand(nWndID, nCmdID, nParam1, nParam2);
}

void CBComboBox::OnFocus(bool bIsFocus)
{
	CAwsContainer::OnFocus(bIsFocus);

	if ( !bIsFocus )
	{
		// 销毁该弹出式窗口
		DestroyPopWnd();
	}

	Invalide();
}

void CBComboBox::AdjustMenuPos(CBMenu* pMenu, CEspRect& rect)
{
	// 首先看从下面弹出是否够，如果够的画就从下面弹出，不够就从上面弹出(不应该超过父窗口的范围)
	CEspSize sizeMenu = pMenu->GetMenuSize();
	CEspSize sizeParent = *m_pParent->GetSize();

	CEspRect rt;
	rt.m_ptLT.m_nX = rect.m_ptLT.m_nX;
	rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + sizeMenu.m_nWidth;

	if ( rect.m_ptRB.m_nY + sizeMenu.m_nHeight <= sizeParent.m_nHeight )
	{
		// 在下面画
		rt.m_ptLT.m_nY = rect.m_ptRB.m_nY;
		rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + sizeMenu.m_nHeight;
	}
	else
	{
		// 在上面画
		rt.m_ptRB.m_nY = rect.m_ptLT.m_nY;
		rt.m_ptLT.m_nY = rt.m_ptRB.m_nY - sizeMenu.m_nHeight;
	}

	CEspPoint pt = m_pParent->GetOrigin();
	rt.m_ptLT += pt;
	rt.m_ptRB += pt;

	rect = rt;
}

bool CBComboBox::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	if ( AWS_Key == type )
	{
		switch ( code )
		{
		case AWS_KeyCode_OK:
			{
				// 弹出菜单，供选择
				CBMenu* pMenu = new CBMenu(this);
				pMenu->SetTBBorderHeight(0);
				pMenu->SetItemLeftMargin(2);
				pMenu->SetItemRightMargin(0);
				pMenu->SetDefaultItemHeight(18);
				pMenu->SetDefaultItemWidth(GetSize()->m_nWidth);
				pMenu->SetPopupOnly(true);

				int i;
				for ( i = 0; i < m_nItemCount; ++i )
				{
					pMenu->AddItem(m_pItemData[i]);
				}
				pMenu->AddItemEnd();

				CEspRect rect = GetRect();
				AdjustMenuPos(pMenu, rect);
				PopWnd(pMenu, rect, AWS_ComboBox_PopupWnd);
			}
			return true;
		}
	}

	return CAwsContainer::OnKey(type, code);
}

void CBComboBox::DrawBK(IAwsGc* pGc, const CEspRect& rect)
{
	if ( m_bIsFocus )
	{
		pGc->SetPenColor(m_oFocusBorderColor);
		pGc->SetBrushColor(m_oFocusBKColor);
	}
	else
	{
		pGc->SetPenColor(m_oBorderColor);
		pGc->SetBrushColor(m_oBKColor);
	}

	pGc->DrawFillRect(rect);
}

void CBComboBox::DrawText(IAwsGc* pGc, const CEspRect& rect)
{
	if ( m_bIsFocus )
	{
		pGc->SetTextColor(m_oFocusTextColor);
	}
	else
	{
		pGc->SetTextColor(m_oTextColor);
	}

	pGc->SetTextAlignment(AWS_TAM_Left);

	m_oFont.CreateFont(0, m_nFontSize);
	pGc->UseFont(m_oFont);
	const CEspSize* size = pGc->GetTextSize(m_pItemData[m_nCurItemIndex]);
	CEspRect rt = rect;
	const CEspSize sizeDraw = *rect.GetSize();
	rt.m_ptLT.m_nY = rt.m_ptLT.m_nY + (sizeDraw.m_nHeight - size->m_nHeight) / 2;

	pGc->DrawText(m_pItemData[m_nCurItemIndex], rt);
	pGc->DiscardFont();
}

void CBComboBox::DrawIcon(IAwsGc* pGc, const CEspRect& rect)
{
	if ( m_oIcon.GetID() > 0 )
	{
		pGc->DrawImage(rect.m_ptLT, m_oIcon, &m_oIconMask);
	}
	else
	{
		// 自己绘制
		CEspRect rt = rect;
		CEspSize size = *rect.GetSize();
		// 画边框
		CAwsRgb rgbPen1(49, 52, 49);
		pGc->SetPenColor(rgbPen1);
		pGc->DrawRect(rt);

		// 画底色
		rt.m_ptLT.m_nX += 1;
		rt.m_ptLT.m_nY += 1;
		rt.m_ptRB.m_nX -= 1;
		rt.m_ptRB.m_nY -= size.m_nHeight / 2;
		CAwsRgb rgbPen2(123, 123, 123);
		pGc->SetPenColor(rgbPen2);
		pGc->SetBrushColor(rgbPen2);
		pGc->DrawFillRect(rt);
		rt.m_ptLT.m_nY = rt.m_ptRB.m_nY;
		rt.m_ptRB.m_nY = rect.m_ptRB.m_nY - 1;
		CAwsRgb rgbPen3(0, 0, 0);
		pGc->SetPenColor(rgbPen3);
		pGc->SetBrushColor(rgbPen3);
		pGc->DrawFillRect(rt);

		// 画小三角
		CAwsRgb rgbPen4(255, 255, 255);
		pGc->SetPenColor(rgbPen4);
		CEspPoint ptStart, ptEnd;
		ptStart.m_nX = rect.m_ptLT.m_nX + (size.m_nWidth - 5) / 2;
		ptStart.m_nY = rect.m_ptLT.m_nY + (size.m_nHeight - 3) / 2;
		ptEnd.m_nX = ptStart.m_nX + 5;
		ptEnd.m_nY = ptStart.m_nY;
		int i;
		for ( i = 0; i < 3; ++i )
		{
			pGc->DrawLine(ptStart, ptEnd);
			ptStart.m_nX += 1;
			ptStart.m_nY += 1;
			ptEnd.m_nX -= 1;
			ptEnd.m_nY = ptStart.m_nY;
		}
	}
}

void CBComboBox::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();

	if ( ESP_NULL != pGc )
	{
		// 画背景
		CEspRect rt;
		CEspSize sizeWnd = *GetSize();
		rt.m_ptRB.m_nX = sizeWnd.m_nWidth;
		rt.m_ptRB.m_nY = sizeWnd.m_nHeight;
		DrawBK(pGc, rt);

		// 画文字
		rt.m_ptLT.m_nX = m_nLeftMargin + m_nBorderWidth;
		rt.m_ptLT.m_nY = m_nBorderWidth;
		rt.m_ptRB.m_nX = rt.m_ptRB.m_nX - m_nBorderWidth - m_nRightMargin - m_oIconSize.m_nWidth;
		rt.m_ptRB.m_nY -= m_nBorderWidth;
		DrawText(pGc, rt);

		// 画右边图标
		rt.m_ptLT.m_nX = rt.m_ptRB.m_nX;
		rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_oIconSize.m_nWidth;
		rt.m_ptLT.m_nY = (sizeWnd.m_nHeight - m_oIconSize.m_nHeight) / 2;
		rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_oIconSize.m_nHeight;
		DrawIcon(pGc, rt);
	}

	CAwsContainer::OnDraw(rect);
}
