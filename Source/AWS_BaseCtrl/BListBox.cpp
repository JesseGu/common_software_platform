/******************************************************************************
* FileName		       : BListBox.cpp
* Description          : implementation of the CBListBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BListBox.h"
#include "IAwsGc.h"
#include "BScrollBar.h"

CBListBox::CBListBox(int nMaxItemCount)
{
	m_nMaxItemCount = nMaxItemCount;
	m_nItemCount = 0;
	m_nCurItemIndex = 0;
	m_pItemData = new CAwsString[m_nMaxItemCount];

	m_pScrollBar = ESP_NULL;
	m_nScrollLength = 0;
	m_nScrollPos = 0;

	m_nItemHeight = 20;

	m_nBorderPixels = 1;

	CAwsRgb rgbBorder(123, 123, 123), rgbSelectBorder(255, 255, 255), rgbSelectBK(0, 0, 255), rgbBK(65, 65, 65), rgbText(0, 0, 0), rgbSelectText(255, 255, 255);

	m_oBorderColor = rgbBorder;
	m_oSelectBorderColor = rgbSelectBorder;
	m_oSelectBKColor = rgbSelectBK;
	m_oBKColor = rgbBK;
	m_oTextColor = rgbText;
	m_oSelectTextColor = rgbSelectText;

	m_nDrawItemCount = 0;
	m_nDrawItemStartIndex = 0;
	m_nItemLeftMargin = 5;
	m_nScrollBarWidth = 5;

	m_nFontSize = 12;
}

CBListBox::~CBListBox()
{
	delete []m_pItemData;
	m_pItemData = ESP_NULL;
}

void CBListBox::AddItem(const CAwsString& strText)
{
	if ( m_nItemCount < m_nMaxItemCount )
	{
		m_pItemData[m_nItemCount++] = strText;
	}
}

void CBListBox::AddItemEnd()
{
	// 计算是否需要显示滚动条

	CEspSize size = *GetSize();

	// 计算最多能Draw多少个
	m_nDrawItemCount = (size.m_nHeight - m_nBorderPixels * 2) / m_nItemHeight;

	if ( m_nDrawItemCount < m_nItemCount )
	{
		m_nScrollLength = m_nItemCount - m_nDrawItemCount + 1;
		m_pScrollBar->SetTotalLength(m_nScrollLength);
	}
	else
	{
		m_nDrawItemCount = m_nItemCount;
		m_pScrollBar->SetVisible(false);
	}
}

void CBListBox::OnCreate()
{
	// 创建滚动条
	CEspRect rt;
	CEspSize size = *GetSize();
	rt.m_ptLT.m_nX = size.m_nWidth - m_nScrollBarWidth - m_nBorderPixels;
	rt.m_ptLT.m_nY =  m_nBorderPixels;
	rt.m_ptRB.m_nX = size.m_nWidth - m_nBorderPixels;
	rt.m_ptRB.m_nY = size.m_nHeight - m_nBorderPixels;
	m_pScrollBar = new CBScrollBar;
	m_pScrollBar->Create(this, rt);
	AddSubWnd(m_pScrollBar, false);
}

void CBListBox::DrawBorder(IAwsGc* pGc, const CEspRect& rect)
{
	if ( m_nBorderPixels > 0 )
	{
		if ( m_bIsFocus )
			pGc->SetPenColor(m_oSelectBorderColor);
		else
			pGc->SetPenColor(m_oBorderColor);

		pGc->DrawRect(rect);
	}
}

void CBListBox::DrawItem(IAwsGc* pGc, const CEspRect& rect, int nIndex, bool bIsSelected)
{
	// 画背景
	if ( bIsSelected )
	{
		pGc->SetPenColor(m_oBorderColor);
		pGc->SetBrushColor(m_oSelectBKColor);
		pGc->SetTextColor(m_oSelectTextColor);
	}
	else
	{
		pGc->SetPenColor(m_oBorderColor);
		pGc->SetBrushColor(m_oBKColor);
		pGc->SetTextColor(m_oTextColor);
	}
	pGc->DrawFillRect(rect);

	pGc->SetTextAlignment(AWS_TAM_Left);

	m_oFont.CreateFont(0, m_nFontSize);
	pGc->UseFont(m_oFont);
	const CEspSize* size = pGc->GetTextSize(m_pItemData[nIndex]);
	CEspRect rt = rect;
	rt.m_ptLT.m_nX = rt.m_ptLT.m_nX + m_nItemLeftMargin;
	rt.m_ptLT.m_nY = rt.m_ptLT.m_nY + (m_nItemHeight - size->m_nHeight) / 2;

	pGc->DrawText(m_pItemData[nIndex], rt);
	pGc->DiscardFont();
}

void CBListBox::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();
	CEspRect rt, rtTemp;

	CEspSize size = *GetSize();

	if ( ESP_NULL != pGc )
	{
		CEspRect rt(0, 0, size.m_nWidth, size.m_nHeight);

		// 画全边框
		if ( !m_bIsBKTransparent )
			DrawBorder(pGc, rt);

		// 画中间Item
		rt.m_ptLT.m_nX = m_nBorderPixels;
		rt.m_ptLT.m_nY = m_nBorderPixels;
		rt.m_ptRB.m_nX = size.m_nWidth - m_nBorderPixels - m_pScrollBar->GetSize()->m_nWidth;
		rt.m_ptRB.m_nY = rt.m_ptLT.m_nX + m_nItemHeight;
		int i;
		for ( i = 0; i < m_nDrawItemCount; ++i )
		{
			if ( rect.InterRect(rt, rtTemp) )
			{
				if ( m_nCurItemIndex == i + m_nDrawItemStartIndex )
				{
					// 选中
					DrawItem(pGc, rt, i + m_nDrawItemStartIndex, true);
				}
				else
				{
					// 没选中
					DrawItem(pGc, rt, i + m_nDrawItemStartIndex, false);
				}
			}

			rt.m_ptLT.m_nY += m_nItemHeight;
			rt.m_ptRB.m_nY += m_nItemHeight;
		}
	}

	CAwsContainer::OnDraw(rect);
}

void CBListBox::OnFocus(bool bIsFocus)
{
	CAwsContainer::OnFocus(bIsFocus);

	Invalide();
}

bool CBListBox::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	CEspRect rt;
	rt.m_ptLT.m_nX = m_nBorderPixels;
	rt.m_ptRB.m_nX = GetSize()->m_nWidth - m_nBorderPixels - m_pScrollBar->GetSize()->m_nWidth;

	if ( AWS_Key == type )
	{
		switch ( code )
		{
		case AWS_KeyCode_UpArrow:
			if ( m_nCurItemIndex > 0 )
			{
				--m_nCurItemIndex;
				if ( m_nCurItemIndex < m_nDrawItemStartIndex )
				{
					m_nDrawItemStartIndex = m_nCurItemIndex;
					// 全都要移动
					Invalide();
					if ( 0 == m_nScrollPos )
					{
						m_nScrollPos = m_nScrollLength - 1;
					}
					else
					{
						--m_nScrollPos;
					}
					m_pScrollBar->SetCurPos(m_nScrollPos);
				}
				else
				{
					// 只需要移动两个
					rt.m_ptLT.m_nY = m_nBorderPixels + (m_nCurItemIndex - m_nDrawItemStartIndex) * m_nItemHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nItemHeight * 2;
					InvalideRect(rt);
				}
			}
			else
			{
				m_nCurItemIndex = m_nItemCount - 1;
				int n = m_nItemCount - m_nDrawItemCount;

				if ( n != m_nDrawItemStartIndex )
				{
					// 全都要移动
					m_nDrawItemStartIndex = n;
					Invalide();
					if ( 0 == m_nScrollPos )
					{
						m_nScrollPos = m_nScrollLength - 1;
					}
					else
					{
						--m_nScrollPos;
					}
					m_pScrollBar->SetCurPos(m_nScrollPos);
				}
				else
				{
					// 只需要移动两个
					rt.m_ptLT.m_nY = m_nBorderPixels;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nItemHeight;
					InvalideRect(rt);

					rt.m_ptLT.m_nY = m_nBorderPixels + (m_nDrawItemCount - 1) * m_nItemHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nItemHeight;
					InvalideRect(rt);
				}
			}

			return true;

		case AWS_KeyCode_DownArrow:
			if ( m_nCurItemIndex < m_nItemCount - 1 )
			{
				++m_nCurItemIndex;
				if ( m_nCurItemIndex - m_nDrawItemStartIndex >= m_nDrawItemCount )
				{
					++m_nDrawItemStartIndex;
					Invalide();
					if ( m_nScrollPos + 1 < m_nScrollLength )
					{
						++m_nScrollPos;
					}
					else
					{
						m_nScrollPos = 0;
					}
					m_pScrollBar->SetCurPos(m_nScrollPos);
				}
				else
				{
					// 只需要移动两个
					rt.m_ptLT.m_nY = m_nBorderPixels + (m_nCurItemIndex -1 - m_nDrawItemStartIndex) * m_nItemHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nItemHeight * 2;
					InvalideRect(rt);
				}
			}
			else
			{
				int n = m_nDrawItemStartIndex;
				m_nCurItemIndex = 0;
				m_nDrawItemStartIndex = 0;

				if ( 0 != n )
				{
					Invalide();
					if ( m_nScrollPos + 1 < m_nScrollLength )
					{
						++m_nScrollPos;
					}
					else
					{
						m_nScrollPos = 0;
					}
					m_pScrollBar->SetCurPos(m_nScrollPos);
				}
				else
				{
					// 只需要移动两个
					rt.m_ptLT.m_nY = m_nBorderPixels;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nItemHeight;
					InvalideRect(rt);

					rt.m_ptLT.m_nY = m_nBorderPixels + (m_nDrawItemCount - 1) * m_nItemHeight;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nItemHeight;
					InvalideRect(rt);
				}
			}
			return true;

		case AWS_KeyCode_OK:
			PumpCommand(m_nWndID, AWS_SysCmd_ListBoxCmd, m_nCurItemIndex);
			return true;
		}
	}

	return CAwsWindow::OnKey(type, code);
}
