/******************************************************************************
* FileName		       : BSelectBox.cpp
* Description          : implementation of the CBSelectBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BSelectBox.h"
#include "IAwsGc.h"

CBSelectBox::CBSelectBox(int nMaxItemCount)
{
	m_nMaxItemCount = nMaxItemCount;
	m_nItemCount = 0;
	m_nCurItemIndex = 0;

	m_pItemData = new CAwsString[m_nMaxItemCount];

	m_nDrawItemCount = 0;
	m_nDrawItemStartIndex = 0;

	m_oItemSize.m_nWidth = 30;
	m_oItemSize.m_nHeight = 20;

	m_nLeftMargin = 10;
	m_nRightMargin = 10;
	m_nBorderWidth = 1;

	CAwsRgb rgbBorder(123, 123, 123), rgbFocusBorder(255, 255, 255), rgbText(0, 0, 0), rgbFocusText(255, 0, 0), rgbBK(100, 100, 100), rgbArrow(0, 0, 0);
	m_oBorderColor = rgbBorder;
	m_oFocusBorderColor = rgbFocusBorder;
	m_oTextColor = rgbText;
	m_oFocusTextColor = rgbFocusText;
	m_oBKColor = rgbBK;
	m_oArrowColor = rgbArrow;

	m_nFontSize = 12;

	m_bIsSetImageSelectBK = false;
}

CBSelectBox::~CBSelectBox()
{
	delete []m_pItemData;
}

void CBSelectBox::AddItem(const CAwsString& strText)
{
	if ( m_nItemCount < m_nMaxItemCount )
	{
		m_pItemData[m_nItemCount++] = strText;
	}
}

void CBSelectBox::AddItemEnd()
{
	CEspSize size = *GetSize();

	// 计算最多能Draw多少个
	m_nDrawItemCount = (size.m_nWidth - m_nLeftMargin - m_nRightMargin) / m_oItemSize.m_nWidth;
}

void CBSelectBox::SetSelectImage(const CAwsImage& imageSelectBK, const CAwsImage& imageMask)
{
	m_oImageSelectBK = imageSelectBK;
	m_oImageMask = imageMask;

	m_bIsSetImageSelectBK = true;
}

void CBSelectBox::DrawBorder(IAwsGc* pGc, const CEspRect& rect)
{
	if ( m_bIsFocus )
		pGc->SetPenColor(m_oFocusBorderColor);
	else
		 pGc->SetPenColor(m_oBorderColor);
	pGc->DrawRect(rect);
}

void CBSelectBox::DrawBK(IAwsGc* pGc, const CEspRect& rect)
{
	pGc->SetPenColor(m_oBKColor);
	pGc->SetBrushColor(m_oBKColor);
	pGc->DrawFillRect(rect);
}

void CBSelectBox::DrawLeftArrow(IAwsGc* pGc, const CEspRect& rect, bool bIsDrawArrow)
{
	if ( bIsDrawArrow )
	{
		// 画左箭头
		CEspPoint ptStart, ptEnd;
		ptStart.m_nX = rect.m_ptLT.m_nX + (m_nLeftMargin - 4) / 2;
		ptStart.m_nY = (rect.m_ptLT.m_nY + rect.m_ptRB.m_nY) / 2;
		ptEnd.m_nX = ptStart.m_nX;
		ptEnd.m_nY = ptStart.m_nY + 1;
		pGc->SetPenColor(m_oArrowColor);
		int i;
		for ( i = 0; i < 4; ++i )
		{
			pGc->DrawLine(ptStart, ptEnd);
			ptStart.m_nX += 1;
			ptStart.m_nY -= 1;

			ptEnd.m_nX = ptStart.m_nX;
			ptEnd.m_nY += 1;
		}
	}
}

void CBSelectBox::DrawRightArrow(IAwsGc* pGc, const CEspRect& rect, bool bIsDrawArrow)
{
	if ( bIsDrawArrow )
	{
		// 画右箭头
		CEspPoint ptStart, ptEnd;
		ptStart.m_nX = rect.m_ptRB.m_nX - m_nRightMargin + (m_nRightMargin - 4) / 2;
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
}

void CBSelectBox::DrawItem(IAwsGc* pGc, const CEspRect& rect, int nItemIndex, bool bIsSelect)
{
	if ( bIsSelect )
	{
		if ( m_bIsSetImageSelectBK )
		{
			// 设置选中的背景
			pGc->DrawImage(rect.m_ptLT, m_oImageSelectBK, &m_oImageMask);
		}
		pGc->SetTextColor(m_oFocusTextColor);
	}
	else
	{
		pGc->SetTextColor(m_oTextColor);
	}

	pGc->SetTextAlignment(AWS_TAM_Mid);

	m_oFont.CreateFont(0, m_nFontSize);
	pGc->UseFont(m_oFont);
	const CEspSize* size = pGc->GetTextSize(m_pItemData[nItemIndex]);
	CEspRect rt = rect;
	rt.m_ptLT.m_nY = rt.m_ptLT.m_nY + (rect.GetSize()->m_nHeight - size->m_nHeight) / 2;

	pGc->DrawText(m_pItemData[nItemIndex], rt);
	pGc->DiscardFont();
}

void CBSelectBox::OnFocus(bool bIsFocus)
{
	CAwsWindow::OnFocus(bIsFocus);

	Invalide();
}

void CBSelectBox::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();
	CEspRect rt, rtTemp;

	CEspSize size = *GetSize();
	rt.m_ptRB.m_nY = size.m_nHeight;
	// 画背景
	if ( !m_bIsBKTransparent )
	{
		CEspRect rtTemp(0, 0, size.m_nWidth, size.m_nHeight);
		DrawBorder(pGc, rtTemp);

		rtTemp = rect;
		rtTemp.m_ptLT.m_nY += m_nBorderWidth;
		rtTemp.m_ptRB.m_nY -= m_nBorderWidth;

		if ( rect.m_ptLT.m_nX == 0 )
			rtTemp.m_ptLT.m_nX = m_nBorderWidth;
		if ( rect.m_ptRB.m_nX == size.m_nWidth )
			rtTemp.m_ptRB.m_nX -= m_nBorderWidth;
		DrawBK(pGc, rtTemp);
	}

	// 画左边箭头
	rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nLeftMargin;

	if ( rect.InterRect(rt, rtTemp) )
	{
		if ( m_nCurItemIndex > 0 )
		{
			DrawLeftArrow(pGc, rt, true);
		}
		else
		{
			DrawLeftArrow(pGc, rt, false);
		}
	}

	rt.m_ptLT.m_nX = rt.m_ptRB.m_nX;
	rt.m_ptRB.m_nX += m_oItemSize.m_nWidth;
	// 画Item
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

		rt.m_ptLT.m_nX += m_oItemSize.m_nWidth;
		rt.m_ptRB.m_nX += m_oItemSize.m_nWidth;
	}

	//  画右边箭头
	if ( rect.InterRect(rt, rtTemp) )
	{
		if ( m_nCurItemIndex < m_nItemCount - 1 )
		{
			rt.m_ptRB.m_nX = rect.m_ptRB.m_nX;
			DrawRightArrow(pGc, rt, true);
		}
		else
		{
			DrawRightArrow(pGc, rt, false);
		}
	}
}

bool CBSelectBox::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	CEspRect rt;
	rt.m_ptLT.m_nY = 0;
	rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_oItemSize.m_nHeight;

	if ( AWS_Key == type )
	{
		switch ( code )
		{
		case AWS_KeyCode_LeftArrow:
			if ( m_nCurItemIndex > 0 )
			{
				--m_nCurItemIndex;
				if ( m_nItemCount - 2 == m_nCurItemIndex )
				{
					// 显示右箭头
					rt.m_ptRB.m_nX = GetSize()->m_nWidth;
					rt.m_ptLT.m_nX = rt.m_ptRB.m_nX - m_nRightMargin;
					rt.m_ptLT.m_nY = 0;
					rt.m_ptRB.m_nY = GetSize()->m_nHeight;
					InvalideRect(rt);
				}

				if ( m_nCurItemIndex < m_nDrawItemStartIndex )
				{
					m_nDrawItemStartIndex = m_nCurItemIndex;
					// 全都要移动
					Invalide();
				}
				else
				{
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_oItemSize.m_nHeight;
					// 只需要移动两个
					rt.m_ptLT.m_nX = m_nLeftMargin + (m_nCurItemIndex - m_nDrawItemStartIndex) * m_oItemSize.m_nWidth;
					rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_oItemSize.m_nWidth * 2;
					InvalideRect(rt);
				}

				if ( 0 == m_nCurItemIndex )
				{
					// 关闭左箭头显示
					rt.m_ptLT.m_nX = 0;
					rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nLeftMargin;
					rt.m_ptLT.m_nY = 0;
					rt.m_ptRB.m_nY = GetSize()->m_nHeight;
					InvalideRect(rt);
				}

				PumpCommand(m_nWndID, AWS_SysCmd_SelectBoxFocusItemChange, m_nCurItemIndex);
			}
			return true;

		case AWS_KeyCode_RightArrow:
			if ( m_nCurItemIndex < m_nItemCount - 1 )
			{
				++m_nCurItemIndex;

				if ( 1 == m_nCurItemIndex )
				{
					// 显示左箭头
					rt.m_ptLT.m_nX = 0;
					rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nLeftMargin;
					rt.m_ptLT.m_nY = 0;
					rt.m_ptRB.m_nY = GetSize()->m_nHeight;
					InvalideRect(rt);
				}

				if ( m_nCurItemIndex - m_nDrawItemStartIndex >= m_nDrawItemCount )
				{
					++m_nDrawItemStartIndex;
					Invalide();
				}
				else
				{
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_oItemSize.m_nHeight;
					// 只需要移动两个
					rt.m_ptLT.m_nX = m_nLeftMargin + (m_nCurItemIndex - 1 - m_nDrawItemStartIndex) * m_oItemSize.m_nWidth;
					rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_oItemSize.m_nWidth * 2;
					InvalideRect(rt);
				}

				if ( m_nItemCount - 1 == m_nCurItemIndex )
				{
					// 关闭显示右箭头
					rt.m_ptRB.m_nX = GetSize()->m_nWidth;
					rt.m_ptLT.m_nX = rt.m_ptRB.m_nX - m_nRightMargin;
					rt.m_ptLT.m_nY = 0;
					rt.m_ptRB.m_nY = GetSize()->m_nHeight;
					InvalideRect(rt);
				}

				PumpCommand(m_nWndID, AWS_SysCmd_SelectBoxFocusItemChange, m_nCurItemIndex);
			}
			return true;

		case AWS_KeyCode_OK:
			PumpCommand(m_nWndID, AWS_SysCmd_SelectBoxCmd, m_nCurItemIndex);
			return true;
		}
	}

	return CAwsWindow::OnKey(type, code);
}
