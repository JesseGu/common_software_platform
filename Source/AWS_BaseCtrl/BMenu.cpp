/******************************************************************************
* FileName		       : BMenu.cpp
* Description          : implementation of the CBMenu class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BMenu.h"
#include "IAwsGc.h"

CBMenu::CBMenu(CAwsWindow* pWnd, int nMaxItemCount, int nPopedMenu, bool bIsSubMenu)
{
	m_pParent = pWnd;

	m_nItemCount = 0;
	m_nFocusItemIndex = 0;
	m_nDrawItemCount = 0;
	m_nDrawItemStartIndex = 0;

	m_nMaxItemCount = nMaxItemCount;

	m_nMaxShowItemCount = 10;
	m_nFullBorderPixel = 1;
	m_nTBBorderHeight = 12;
	m_nItemHeight = 23;
	m_nMenuWidth = 82;
	m_nItemLeftMargin = 5;
	m_nItemRightMargin = 10;

	m_nFontSize = 12;

	m_pItemData = new TItemData[m_nMaxItemCount];

	CAwsRgb rgbFocusText(255, 255, 255), rgbText(173, 154, 132), rgbFocusBK(24, 24, 20), rgbBK(62, 59, 53), rgbBorder(101, 99, 94), rgbArrow(255, 255, 255);
	m_oFocusTextColor = rgbFocusText;
	m_oTextColor = rgbText;
	m_oFocusBKColor = rgbFocusBK;
	m_oBKColor = rgbBK;
	m_oBorderColor = rgbBorder;
	m_oArrowColor = rgbArrow;

	m_bIsSubMenu = bIsSubMenu;

	m_bIsPopupOnly = false;

	m_nPopMenuCount = nPopedMenu + 1;
}

CBMenu::~CBMenu()
{
	delete []m_pItemData;
	m_pItemData = ESP_NULL;
}

void CBMenu::OnCreate()
{
	// 在此改写属性
}

bool CBMenu::AddItem(const CAwsString& strText, int nSubMenuID)
{
	bool bRet = false;

	if ( m_nItemCount < m_nMaxItemCount )
	{
		m_pItemData[m_nItemCount].m_strText = strText;
		m_pItemData[m_nItemCount++].m_nSubMenuID = nSubMenuID;

		IAwsGc* pGc = GetGc();
		m_oFont.CreateFont(0, m_nFontSize);
		pGc->UseFont(m_oFont);
		const CEspSize* size = pGc->GetTextSize(strText);
		if ( size->m_nWidth > m_oMaxTextSize.m_nWidth )
			m_oMaxTextSize.m_nWidth = size->m_nWidth;

		if ( size->m_nHeight > m_oMaxTextSize.m_nHeight )
			m_oMaxTextSize.m_nHeight = size->m_nHeight;

		bRet = true;
	}

	return bRet;
}

void CBMenu::AddItemEnd()
{
	if ( m_nItemCount >= m_nMaxShowItemCount )
		m_nDrawItemCount = m_nMaxShowItemCount;
	else
		m_nDrawItemCount = m_nItemCount;

	// 调整窗口宽度
	if ( m_oMaxTextSize.m_nWidth + m_nItemLeftMargin + m_nItemRightMargin + m_nFullBorderPixel* 2 > m_nMenuWidth )
		m_nMenuWidth = m_oMaxTextSize.m_nWidth + m_nItemLeftMargin + m_nItemRightMargin + m_nFullBorderPixel* 2;

	// 算出菜单所占宽和高
	CEspSize size (m_nMenuWidth, m_nFullBorderPixel* 2 + m_nTBBorderHeight * 2 + m_nItemHeight * m_nDrawItemCount);
	m_tSize = size;
}

void CBMenu::DrawFullBorder(IAwsGc* pGc, const CEspRect& rect)
{
	if ( m_nFullBorderPixel > 0 )
	{
		pGc->SetPenColor(m_oBorderColor);
		pGc->DrawRect(rect);
	}
}

void CBMenu::DrawTopBorder(IAwsGc* pGc, const CEspRect& rect, bool bIsScroll)
{
	// 画背景
	pGc->SetPenColor(m_oBKColor);
	pGc->SetBrushColor(m_oBKColor);
	pGc->DrawFillRect(rect);

	if ( bIsScroll )
	{
		// 画上箭头
		CEspPoint ptStart, ptEnd;
		ptStart.m_nX = (rect.m_ptLT.m_nX + rect.m_ptRB.m_nX) / 2;
		ptStart.m_nY = rect.m_ptLT.m_nY + (rect.GetSize()->m_nHeight - 7) / 2;
		ptEnd.m_nX = ptStart.m_nX + 1;
		ptEnd.m_nY = ptStart.m_nY;
		pGc->SetPenColor(m_oArrowColor);
		int i;
		for ( i = 0; i < 4; ++i )
		{
			pGc->DrawLine(ptStart, ptEnd);
			ptStart.m_nX -= 1;
			ptStart.m_nY += 1;

			ptEnd.m_nX += 1;
			ptEnd.m_nY = ptStart.m_nY;
		}
	}
}

void CBMenu::DrawBottomBorder(IAwsGc* pGc, const CEspRect& rect, bool bIsScroll)
{
	// 画背景
	pGc->SetPenColor(m_oBKColor);
	pGc->SetBrushColor(m_oBKColor);
	pGc->DrawFillRect(rect);

	if ( bIsScroll )
	{
		// 画下箭头
		CEspPoint ptStart, ptEnd;
		ptStart.m_nX = (rect.m_ptLT.m_nX + rect.m_ptRB.m_nX) / 2 - 3;
		ptStart.m_nY = rect.m_ptLT.m_nY + (rect.GetSize()->m_nHeight - 7) / 2;
		ptEnd.m_nX = ptStart.m_nX + 7;
		ptEnd.m_nY = ptStart.m_nY;
		pGc->SetPenColor(m_oArrowColor);
		int i;
		for ( i = 0; i < 4; ++i )
		{
			pGc->DrawLine(ptStart, ptEnd);
			ptStart.m_nX += 1;
			ptStart.m_nY += 1;

			ptEnd.m_nX -= 1;
			ptEnd.m_nY = ptStart.m_nY;
		}
	}
}

void CBMenu::DrawItem(IAwsGc* pGc, const CEspRect& rect, int nIndex, bool bIsSelected, bool bIsSubMenu)
{
	if ( bIsSelected )
	{
		pGc->SetTextColor(m_oFocusTextColor);
		pGc->SetPenColor(m_oFocusBKColor);
		pGc->SetBrushColor(m_oFocusBKColor);
	}
	else
	{
		pGc->SetTextColor(m_oTextColor);
		pGc->SetPenColor(m_oBKColor);
		pGc->SetBrushColor(m_oBKColor);
	}
	pGc->DrawFillRect(rect);

	if ( bIsSubMenu )
	{
		// 画右箭头
		CEspPoint ptStart, ptEnd;
		ptStart.m_nX = rect.m_ptRB.m_nX - m_nItemRightMargin + (m_nItemRightMargin - 4) / 2;
		ptStart.m_nY = (rect.m_ptLT.m_nY + rect.m_ptRB.m_nY) / 2 - 3;
		ptEnd.m_nX = ptStart.m_nX;
		ptEnd.m_nY = ptStart.m_nY + 7;
		pGc->SetPenColor(m_oArrowColor);
		int i;
		for ( i = 0; i < 4; ++i )
		{
			pGc->DrawLine(ptStart, ptEnd);
			ptStart.m_nX += 1;
			ptStart.m_nY += 1;

			ptEnd.m_nX = ptStart.m_nX;
			ptEnd.m_nY -= 1;
		}
	}

	CEspRect rt;
	rt.m_ptLT.m_nX = rect.m_ptLT.m_nX + m_nItemLeftMargin;
	rt.m_ptLT.m_nY = rect.m_ptLT.m_nY + (m_nItemHeight - m_oMaxTextSize.m_nHeight) / 2;
	rt.m_ptRB.m_nX = rect.m_ptRB.m_nX - m_nItemRightMargin;
	rt.m_ptRB.m_nY = rect.m_ptLT.m_nY + m_nItemHeight;
	pGc->SetTextAlignment(AWS_TAM_Left);

	m_oFont.CreateFont(0, m_nFontSize);
	pGc->UseFont(m_oFont);
	pGc->DrawText(m_pItemData[nIndex].m_strText, rt);
	pGc->DiscardFont();
}

void CBMenu::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();
	CEspRect rt, rtTemp;

	if ( ESP_NULL != pGc )
	{
		// 画全边框
		DrawFullBorder(pGc, rect);

		// 画上边框
		rt.m_ptLT.m_nX = m_nFullBorderPixel;
		rt.m_ptLT.m_nY = m_nFullBorderPixel;
		rt.m_ptRB.m_nX = m_nMenuWidth - m_nFullBorderPixel;
		rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nTBBorderHeight;

		if ( rect.InterRect(rt, rtTemp) )
		{
			if ( m_nItemCount > m_nMaxShowItemCount )
			{
				DrawTopBorder(pGc, rt, true);
			}
			else
			{
				DrawTopBorder(pGc, rt, false);
			}
		}
		rt.m_ptLT.m_nY = rt.m_ptRB.m_nY;

		// 画中间Item
		rt.m_ptRB.m_nY += m_nItemHeight;
		int i;
		for ( i = 0; i < m_nDrawItemCount; ++i )
		{
			if ( rect.InterRect(rt, rtTemp) )
			{
				if ( m_nFocusItemIndex == i + m_nDrawItemStartIndex )
				{
					// 选中
					if ( m_pItemData[i + m_nDrawItemStartIndex].m_nSubMenuID > 0 )
						DrawItem(pGc, rt, i + m_nDrawItemStartIndex, true, true);
					else
						DrawItem(pGc, rt, i + m_nDrawItemStartIndex, true, false);
				}
				else
				{
					// 没选中
					if ( m_pItemData[i + m_nDrawItemStartIndex].m_nSubMenuID > 0 )
						DrawItem(pGc, rt, i + m_nDrawItemStartIndex, false, true);
					else
						DrawItem(pGc, rt, i + m_nDrawItemStartIndex, false, false);
				}
			}

			rt.m_ptLT.m_nY += m_nItemHeight;
			rt.m_ptRB.m_nY += m_nItemHeight;
		}

		// 画下边框
		rt.m_ptRB.m_nY += m_nTBBorderHeight - m_nItemHeight;

		if ( rect.InterRect(rt, rtTemp) )
		{
			if ( m_nItemCount > m_nMaxShowItemCount )
			{
				DrawBottomBorder(pGc, rt, true);
			}
			else
			{
				DrawBottomBorder(pGc, rt, false);
			}
		}
	}
}

bool CBMenu::GetItemRectFromIndex(int nIndex, CEspRect& rect)
{
	bool bRet = false;
	int n = nIndex - m_nDrawItemStartIndex;

	if ( n < m_nMaxShowItemCount )
	{
		rect.m_ptLT.m_nX = m_nFullBorderPixel;
		rect.m_ptRB.m_nX = m_nMenuWidth - m_nFullBorderPixel;

		rect.m_ptLT.m_nY = m_nFullBorderPixel + m_nTBBorderHeight + n * m_nItemHeight;
		rect.m_ptRB.m_nY = rect.m_ptLT.m_nY + m_nItemHeight;

		bRet = true;
	}

	return bRet;
}

bool CBMenu::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	CEspRect rt;
	rt.m_ptLT.m_nX = m_nFullBorderPixel;
	rt.m_ptRB.m_nX = m_nMenuWidth - m_nFullBorderPixel;
	if ( AWS_Key == type )
	{
		switch ( code )
		{
		case AWS_KeyCode_UpArrow:
			if ( m_nFocusItemIndex > 0 )
			{
				--m_nFocusItemIndex;
				if ( m_nFocusItemIndex < m_nDrawItemStartIndex )
				{
					m_nDrawItemStartIndex = m_nFocusItemIndex;
					// 全都要移动
					rt.m_ptLT.m_nY = m_nFullBorderPixel + m_nTBBorderHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nDrawItemCount * m_nItemHeight;
					InvalideRect(rt);
				}
				else
				{
					// 只需要移动两个
					rt.m_ptLT.m_nY = m_nFullBorderPixel + m_nTBBorderHeight + (m_nFocusItemIndex - m_nDrawItemStartIndex) * m_nItemHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nItemHeight * 2;
					InvalideRect(rt);
				}
			}
			else
			{
				m_nFocusItemIndex = m_nItemCount - 1;
				int n = m_nItemCount - m_nDrawItemCount;

				if ( n != m_nDrawItemStartIndex )
				{
					// 全都要移动
					m_nDrawItemStartIndex = n;

					rt.m_ptLT.m_nY = m_nFullBorderPixel + m_nTBBorderHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nDrawItemCount * m_nItemHeight;
					InvalideRect(rt);
				}
				else
				{
					// 只需要移动两个
					rt.m_ptLT.m_nY = m_nFullBorderPixel + m_nTBBorderHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nItemHeight;
					InvalideRect(rt);

					rt.m_ptLT.m_nY = m_nFullBorderPixel + m_nTBBorderHeight + (m_nDrawItemCount - 1) * m_nItemHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nItemHeight;
					InvalideRect(rt);
				}
			}
			return true;

		case AWS_KeyCode_DownArrow:
			if ( m_nFocusItemIndex < m_nItemCount - 1 )
			{
				++m_nFocusItemIndex;
				if ( m_nFocusItemIndex - m_nDrawItemStartIndex >= m_nDrawItemCount )
				{
					++m_nDrawItemStartIndex;

					rt.m_ptLT.m_nY = m_nFullBorderPixel + m_nTBBorderHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nDrawItemCount * m_nItemHeight;
					InvalideRect(rt);
				}
				else
				{
					// 只需要移动两个
					rt.m_ptLT.m_nY = m_nFullBorderPixel + m_nTBBorderHeight + (m_nFocusItemIndex -1 - m_nDrawItemStartIndex) * m_nItemHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nItemHeight * 2;
					InvalideRect(rt);
				}
			}
			else
			{
				int n = m_nDrawItemStartIndex;
				m_nFocusItemIndex = 0;
				m_nDrawItemStartIndex = 0;

				if ( 0 != n )
				{
					rt.m_ptLT.m_nY = m_nFullBorderPixel + m_nTBBorderHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nDrawItemCount * m_nItemHeight;
					InvalideRect(rt);
				}
				else
				{
					// 只需要移动两个
					rt.m_ptLT.m_nY = m_nFullBorderPixel + m_nTBBorderHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nItemHeight;
					InvalideRect(rt);

					rt.m_ptLT.m_nY = m_nFullBorderPixel + m_nTBBorderHeight + (m_nDrawItemCount - 1) * m_nItemHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nItemHeight;
					InvalideRect(rt);
				}
			}
			return true;

		case AWS_KeyCode_LeftArrow:
			if ( m_bIsSubMenu )
			{
				// 销毁自己
				DestroyPopWnd();
			}
			return true;

		case AWS_KeyCode_RightArrow:
			if ( m_pItemData[m_nFocusItemIndex].m_nSubMenuID > 0 )
			{
				CEspPoint ptLT;
				ptLT.m_nX = m_tRect.m_ptLT.m_nX + m_nMenuWidth;
				ptLT.m_nY = m_tRect.m_ptLT.m_nY + m_nItemHeight * (m_nFocusItemIndex - m_nDrawItemStartIndex);
				PumpCommand(m_nWndID, AWS_SysCmd_PopMenu, m_pItemData[m_nFocusItemIndex].m_nSubMenuID, (int)(&ptLT));
			}
			return true;

		case AWS_KeyCode_OK:
			if ( m_pItemData[m_nFocusItemIndex].m_nSubMenuID > 0 )
			{
				return OnKey(type, AWS_KeyCode_RightArrow);
			}
			else
			{
				PostCommand(m_nWndID, AWS_SysCmd_MenuCmd, m_nFocusItemIndex);
				PumpCommand(m_nWndID, AWS_SysCmd_MenuDestroy);

				// 销毁所有弹出式菜单
				DestroyPopWnd(m_nPopMenuCount);
				return true;
			}
		}
	}

	if ( AWS_Key_Up == type )
	{
		if ( !m_bIsPopupOnly )
		{
			switch ( code )
			{
			case AWS_KeyCode_LeftMenu:
				return OnKey(AWS_Key, AWS_KeyCode_OK);

			case AWS_KeyCode_RightMenu:
				// 销毁所有弹出式菜单
				PumpCommand(m_nWndID, AWS_SysCmd_MenuDestroy);
				DestroyPopWnd(m_nPopMenuCount);
				return true;
			}
		}

		if ( code >= AWS_KeyCode_1  && code <= AWS_KeyCode_9 )
		{
			int nIndex = code - AWS_KeyCode_1;
			if ( nIndex < m_nItemCount )
			{
				// 重绘前focus窗口
				int n = m_nFocusItemIndex;
				CEspRect rect;
				m_nFocusItemIndex = nIndex;
				if ( GetItemRectFromIndex(n, rect) )
					InvalideRect(rect);
				if ( GetItemRectFromIndex(m_nFocusItemIndex, rect) )
					InvalideRect(rect);
				
				return OnKey(AWS_Key, AWS_KeyCode_OK);
			}
		}
	}

	if ( m_bIsPopupOnly )
		return CAwsContainer::OnKey(type, code);
	else
		return true;
}
