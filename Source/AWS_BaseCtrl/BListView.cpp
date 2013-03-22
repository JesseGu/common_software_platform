/******************************************************************************
* FileName		       : BListView.cpp
* Description          : implementation of the CBListView class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BListView.h"
#include "BScrollBar.h"
#include "IAwsGc.h"

CBListView::CBListView(int nMaxItemCount)
{
	m_eShowMode = LVShowMode_Icon;

	m_nMaxItemCount = nMaxItemCount;
	m_pLVData = new TLVData[m_nMaxItemCount];
	m_nItemCount = 0;
	m_nCurItemIndex = 0;

	m_nDrawItemStartIndex = 0;
	m_nWidthDrawItemCount = 0;
	m_nHeightDrawItemCount = 0;

	m_oListModeItemSize.m_nHeight = 45;
	m_oIconModeItemSize.m_nWidth = 77;
	m_oIconModeItemSize.m_nHeight = 67;
	m_oSmallIconSize.m_nHeight = 39;
	m_oSmallIconSize.m_nWidth = 40;
	m_oBigIconSize.m_nHeight = 39;
	m_oBigIconSize.m_nWidth = 40;

	m_nListIconTextMargin = 5;

	m_nLRBorderWidth = 1;
	m_nTBBorderHeight = 1;
	m_nLeftMargin = 0;
	m_nRightMargin = 0;
	m_nTopMargin = 0;
	m_nBottomMargin = 0;

	m_nFontSize = 12;

	m_pScrollBar = ESP_NULL;
	m_nScrollBarWidth = 5;
	m_nScrollLength = 0;
	m_nScrollPos = 0;

	CAwsRgb rgbBorder(32, 28, 16), rgbItemSelectBK(0, 0, 255), rgbItemBK(32, 28, 16), rgbText(181, 181, 181), rgbSelectText(255, 255, 255), rgbBK(32, 28, 16);
	m_oBorderColor = rgbBorder;
	m_oItemSelectBKColor = rgbItemSelectBK;
	m_oItemBKColor = rgbItemBK;
	m_oTextColor = rgbText;
	m_oSelectTextColor = rgbSelectText;
	m_oBKColor = rgbBK;
}

CBListView::~CBListView()
{
	delete []m_pLVData;
}

void CBListView::OnCreate()
{
	// 创建滚动条
	CEspRect rt;
	CEspSize size = *GetSize();
	rt.m_ptLT.m_nX = size.m_nWidth - m_nScrollBarWidth - m_nLRBorderWidth;
	rt.m_ptLT.m_nY =  m_nTBBorderHeight;
	rt.m_ptRB.m_nX = size.m_nWidth - m_nLRBorderWidth;
	rt.m_ptRB.m_nY = size.m_nHeight - m_nTBBorderHeight;
	m_pScrollBar = new CBScrollBar;
	m_pScrollBar->Create(this, rt);
	AddSubWnd(m_pScrollBar, false);
}

void CBListView::AddItem(const CAwsString& strText, const CAwsImage& iconSmall, const CAwsImage& iconBig, const CAwsImage* pSmallMask, const CAwsImage* pBigMask, bool bIsEnd)
{
	if ( m_nItemCount < m_nMaxItemCount )
	{
		m_pLVData[m_nItemCount].m_oText = strText;
		m_pLVData[m_nItemCount].m_oSmallIcon = iconSmall;
		m_pLVData[m_nItemCount].m_oBigIcon = iconBig;
		if ( ESP_NULL != pSmallMask )
		{
			m_pLVData[m_nItemCount].m_oSmallMask = *pSmallMask;
		}
		if ( ESP_NULL != pBigMask )
		{
			m_pLVData[m_nItemCount].m_oBigMask = *pBigMask;
		}
		++m_nItemCount;

		if ( bIsEnd )
		{
			// 计算显示参数
			CalcShowParam();
		}
	}
}

void CBListView::RemoveItem(int nItemIndex)
{
	if ( nItemIndex < m_nItemCount )
	{
		int i;
		for ( i = nItemIndex; i < m_nItemCount - 1; ++i )
		{
			m_pLVData[i] = m_pLVData[i + 1];
		}

		--m_nItemCount;

		if ( m_nCurItemIndex > nItemIndex )
		{
			--m_nCurItemIndex;
		}
		else if ( m_nCurItemIndex == nItemIndex && m_nItemCount == m_nCurItemIndex)
		{
			// 是最后一个
			--m_nCurItemIndex;
		}

		CalcShowParam();
		m_pScrollBar->SetCurPos(m_nScrollPos);
		Invalide();
	}
}

int CBListView::GetDrawStartIndexFromCurIndex(int nIndex)
{
	int nItemsPerPage = (m_nWidthDrawItemCount * m_nHeightDrawItemCount);
	int n = m_nCurItemIndex;
	m_nDrawItemStartIndex = 0;
	m_nScrollPos = 0;

	while ( n >= nItemsPerPage )
	{
		n -= m_nWidthDrawItemCount;
		m_nDrawItemStartIndex += m_nWidthDrawItemCount;

		++m_nScrollPos;
	}

	return m_nDrawItemStartIndex;
}

void CBListView::SetShowMode(LV_ShowMode mode)
{
	if ( m_eShowMode != mode )
	{
		m_eShowMode = mode;

		// 改变显示模式
		CalcShowParam();

		// 修改m_nDrawItemStartIndex
		m_nDrawItemStartIndex = GetDrawStartIndexFromCurIndex(m_nCurItemIndex);
		m_pScrollBar->SetCurPos(m_nScrollPos);

		Invalide();
	}
}

void CBListView::RegulateParam()
{
	CEspSize sizeWnd = *GetSize();
	m_oListModeItemSize.m_nWidth = sizeWnd.m_nWidth - m_nLRBorderWidth * 2 - m_nScrollBarWidth;

	switch ( m_eShowMode )
	{
	case LVShowMode_List:
		{
			m_nWidthDrawItemCount = 1;
			m_nHeightDrawItemCount = (sizeWnd.m_nHeight - m_nTBBorderHeight * 2) / m_oListModeItemSize.m_nHeight;

			m_oDrawItemSize = m_oListModeItemSize;
		}
		break;

	case LVShowMode_Icon:
		{
			m_nWidthDrawItemCount = (sizeWnd.m_nWidth - m_nLRBorderWidth * 2) / m_oIconModeItemSize.m_nWidth;
			m_nHeightDrawItemCount = (sizeWnd.m_nHeight - m_nTBBorderHeight * 2) / m_oIconModeItemSize.m_nHeight;

			m_oDrawItemSize = m_oIconModeItemSize;
		}
		break;
	}
	int n = m_nItemCount / m_nWidthDrawItemCount + (m_nItemCount % m_nWidthDrawItemCount > 0 ? 1 : 0);
	if ( m_nHeightDrawItemCount > n )
	{
		m_nHeightDrawItemCount = n;
	}

	int nRemainWidth = (sizeWnd.m_nWidth - m_nLRBorderWidth * 2 - m_nScrollBarWidth) % m_oDrawItemSize.m_nWidth;
	int nRemainHeight = (sizeWnd.m_nHeight - m_nTBBorderHeight * 2) % m_oDrawItemSize.m_nHeight;
	m_nLeftMargin = nRemainWidth / 2 + nRemainWidth % 2;
	m_nRightMargin = nRemainWidth / 2;
	m_nTopMargin = nRemainHeight / 2;
	m_nBottomMargin = nRemainHeight / 2 + nRemainHeight % 2;
}

void CBListView::CalcShowParam()
{
//	CEspSize sizeWnd = *GetSize();

	RegulateParam();

	// 设置滚动条参数
	if ( m_nWidthDrawItemCount * m_nHeightDrawItemCount < m_nItemCount )
	{
		m_nScrollLength = (m_nItemCount / m_nWidthDrawItemCount + ((m_nItemCount % m_nWidthDrawItemCount) > 0 ? 1 : 0) ) - m_nHeightDrawItemCount + 1;
		m_pScrollBar->SetTotalLength(m_nScrollLength);
		m_pScrollBar->SetVisible(true);
	}
	else
	{
		// 不用显示滚动条
		m_pScrollBar->SetVisible(false);
	}
}

void CBListView::DrawBorder(IAwsGc* pGc, const CEspRect& rect)
{
	pGc->SetPenColor(m_oBorderColor);
	pGc->DrawRect(rect);
}

void CBListView::DrawBK(IAwsGc* pGc, const CEspRect& rect)
{
	pGc->SetPenColor(m_oBKColor);
	pGc->SetBrushColor(m_oBKColor);
	pGc->DrawFillRect(rect);
}

void CBListView::DrawItem(IAwsGc* pGc, const CEspRect& rect, int nIndex, bool bIsSelected)
{
	// 画背景
	if ( bIsSelected )
	{
		pGc->SetPenColor(m_oItemSelectBKColor);
		pGc->SetBrushColor(m_oItemSelectBKColor);
		pGc->SetTextColor(m_oSelectTextColor);
	}
	else
	{
		pGc->SetPenColor(m_oItemBKColor);
		pGc->SetBrushColor(m_oItemBKColor);
		pGc->SetTextColor(m_oTextColor);
	}
	pGc->DrawFillRect(rect);

	const CEspSize* sizeText = pGc->GetTextSize(m_pLVData[nIndex].m_oText);
	CEspRect rt = rect;
	m_oFont.CreateFont(0, m_nFontSize);
	pGc->UseFont(m_oFont);

	switch ( m_eShowMode )
	{
	case LVShowMode_List:
		{
			// 先在左边画小图标，再在紧接着的地方画字
			rt.m_ptLT.m_nY = rect.m_ptLT.m_nY + (m_oDrawItemSize.m_nHeight - m_oSmallIconSize.m_nHeight) / 2;

			pGc->DrawImage(rt.m_ptLT, m_pLVData[nIndex].m_oSmallIcon, &m_pLVData[nIndex].m_oSmallMask);

			rt.m_ptLT.m_nX = rt.m_ptLT.m_nX + m_oSmallIconSize.m_nWidth + m_nListIconTextMargin;
			rt.m_ptLT.m_nY = rect.m_ptLT.m_nY + (m_oDrawItemSize.m_nHeight - sizeText->m_nHeight) / 2;
			pGc->SetTextAlignment(AWS_TAM_Left);
			pGc->DrawText(m_pLVData[nIndex].m_oText, rt);
		}
		break;

	case LVShowMode_Icon:
		{
			// 现在上面画大图标，再在下面画字
			rt.m_ptLT.m_nX = rect.m_ptLT.m_nX + (m_oDrawItemSize.m_nWidth - m_oBigIconSize.m_nWidth) / 2;
			rt.m_ptLT.m_nY = rect.m_ptLT.m_nY + (m_oDrawItemSize.m_nHeight - m_oBigIconSize.m_nHeight - sizeText->m_nHeight) / 2 ;

			pGc->DrawImage(rt.m_ptLT, m_pLVData[nIndex].m_oBigIcon, &m_pLVData[nIndex].m_oBigMask);

			rt.m_ptLT.m_nX = rect.m_ptLT.m_nX;
			rt.m_ptLT.m_nY = rt.m_ptLT.m_nY + m_oBigIconSize.m_nHeight;
			pGc->SetTextAlignment(AWS_TAM_Mid);
			pGc->DrawText(m_pLVData[nIndex].m_oText, rt);
		}
		break;
	}

	pGc->DiscardFont();
}

void CBListView::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();
	CEspRect rt, rtTemp;

	if ( ESP_NULL != pGc )
	{
		CEspSize sizeWnd = *GetSize();
		CEspRect rt(0, 0, sizeWnd.m_nWidth, sizeWnd.m_nHeight);

		// 画全边框
		if ( !m_bIsBKTransparent )
			DrawBorder(pGc, rt);

		// 是否有背景需要画
		{
			// 上
			CEspRect rtWnd(0, 0, sizeWnd.m_nWidth, sizeWnd.m_nHeight);
			rt.m_ptLT.m_nX = rtWnd.m_ptLT.m_nX + m_nLRBorderWidth;
			rt.m_ptLT.m_nY = rtWnd.m_ptLT.m_nY + m_nTBBorderHeight;
			rt.m_ptRB.m_nX = rtWnd.m_ptRB.m_nX - m_nLRBorderWidth;
			rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nTopMargin;
			if ( rect.InterRect(rt, rtTemp) )
			{
				DrawBK(pGc, rt);
			}

			// 下
			rt.m_ptLT.m_nY = rtWnd.m_ptRB.m_nY - m_nTBBorderHeight - m_nBottomMargin;
			rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nBottomMargin;
			if ( rect.InterRect(rt, rtTemp) )
			{
				DrawBK(pGc, rt);
			}

			// 左
			rt.m_ptLT.m_nY = rtWnd.m_ptLT.m_nY + m_nTBBorderHeight + m_nTopMargin;
			rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nLeftMargin;
			rt.m_ptRB.m_nY = rtWnd.m_ptRB.m_nY - m_nTBBorderHeight - m_nBottomMargin;
			if ( rect.InterRect(rt, rtTemp) )
			{
				DrawBK(pGc, rt);
			}

			// 右
			rt.m_ptLT.m_nX = rtWnd.m_ptRB.m_nX - m_nLRBorderWidth - m_nRightMargin - m_nScrollBarWidth;
			rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nRightMargin;
			if ( rect.InterRect(rt, rtTemp) )
			{
				DrawBK(pGc, rt);
			}
		}

		// 画中间Item
		rt.m_ptLT.m_nY = m_nTBBorderHeight + m_nTopMargin;
		int i, j;
		for ( i = 0; i < m_nHeightDrawItemCount; ++i )
		{
			rt.m_ptLT.m_nX = m_nLRBorderWidth + m_nLeftMargin;
			rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_oDrawItemSize.m_nHeight;

			for ( j = 0; j < m_nWidthDrawItemCount; ++j )
			{
				int nIndex = i * m_nWidthDrawItemCount + j + m_nDrawItemStartIndex;
				rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_oDrawItemSize.m_nWidth;

				if ( rect.InterRect(rt, rtTemp) )
				{
					if ( nIndex >= m_nItemCount )
					{
						// 画背景
						DrawBK(pGc, rt);
					}
					else
					{
						if ( m_nCurItemIndex == nIndex )
						{
							// 选中
							DrawItem(pGc, rt, nIndex, true);
						}
						else
						{
							// 没选中
							DrawItem(pGc, rt, nIndex, false);
						}
					}
				}

				rt.m_ptLT.m_nX += m_oDrawItemSize.m_nWidth;
			}

			rt.m_ptLT.m_nY += m_oDrawItemSize.m_nHeight;
		}
	}

	CAwsContainer::OnDraw(rect);
}

void CBListView::GetItemRectFromIndex(int nIndex, CEspRect& rect)
{
	int n = nIndex - m_nDrawItemStartIndex;

	int nRow = n / m_nWidthDrawItemCount;
	int nCol = n % m_nWidthDrawItemCount;

	rect.m_ptLT.m_nX = m_nLRBorderWidth + m_nLeftMargin + nCol * m_oDrawItemSize.m_nWidth;
	rect.m_ptLT.m_nY = m_nTBBorderHeight + m_nTopMargin + nRow * m_oDrawItemSize.m_nHeight;
	rect.m_ptRB.m_nX = rect.m_ptLT.m_nX + m_oDrawItemSize.m_nWidth;
	rect.m_ptRB.m_nY = rect.m_ptLT.m_nY + m_oDrawItemSize.m_nHeight;
}

bool CBListView::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	CEspRect rt;

	if ( AWS_Key == type )
	{
		switch ( code )
		{
		case AWS_KeyCode_UpArrow:
			{
				int n = (m_nCurItemIndex - m_nDrawItemStartIndex) / m_nWidthDrawItemCount;
				if ( n > 0 )
				{
					// 只需调整CurItem索引到上一行
					n = m_nCurItemIndex;
					m_nCurItemIndex -= m_nWidthDrawItemCount;

					// 重绘先前焦点Item
					GetItemRectFromIndex(n, rt);
					InvalideRect(rt);

					// 重绘当前焦点Item
					GetItemRectFromIndex(m_nCurItemIndex, rt);
					InvalideRect(rt);
				}
				else
				{
					if ( m_nDrawItemStartIndex > 0 )
					{
						// 整体向上更新一行
						m_nDrawItemStartIndex -= m_nWidthDrawItemCount;
						m_nCurItemIndex -= m_nWidthDrawItemCount;

						rt.m_ptLT.m_nX = m_nLRBorderWidth + m_nLeftMargin;
						rt.m_ptLT.m_nY = m_nTBBorderHeight + m_nTopMargin;
						rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nWidthDrawItemCount * m_oDrawItemSize.m_nWidth;
						rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nHeightDrawItemCount * m_oDrawItemSize.m_nHeight;
						InvalideRect(rt);

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
						// 需要跳跃，跳到对应列的最后一个，如果没有，则跳到最后一个Item
						n = m_nCurItemIndex;
						m_nCurItemIndex += m_nWidthDrawItemCount * ((m_nItemCount - 1) / m_nWidthDrawItemCount);
						if ( m_nCurItemIndex >= m_nItemCount )
						{
							m_nCurItemIndex = m_nItemCount - 1;
						}

						// 看看m_nDrawItemStartIndex是否有变化
						if ( (m_nCurItemIndex - m_nDrawItemStartIndex) / m_nWidthDrawItemCount < m_nHeightDrawItemCount )
						{
							// m_nDrawItemStartIndex没变化，只需更新两个Item
							GetItemRectFromIndex(n, rt);
							InvalideRect(rt);

							GetItemRectFromIndex(m_nCurItemIndex, rt);
							InvalideRect(rt);
						}
						else
						{
							// 改变DrawStart
							m_nDrawItemStartIndex = m_nCurItemIndex - (m_nCurItemIndex) % m_nWidthDrawItemCount - (m_nHeightDrawItemCount - 1) * m_nWidthDrawItemCount;

							// 更新所有Item
							rt.m_ptLT.m_nX = m_nLRBorderWidth + m_nLeftMargin;
							rt.m_ptLT.m_nY = m_nTBBorderHeight + m_nTopMargin;
							rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nWidthDrawItemCount * m_oDrawItemSize.m_nWidth;
							rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nHeightDrawItemCount * m_oDrawItemSize.m_nHeight;
							InvalideRect(rt);

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
					}
				}
			}
			return true;

		case AWS_KeyCode_DownArrow:
			{
				int n = (m_nCurItemIndex + m_nWidthDrawItemCount - m_nDrawItemStartIndex) / m_nWidthDrawItemCount;
				if ( n < m_nHeightDrawItemCount )
				{
					// 只需调整CurItem索引到下一行
					n = m_nCurItemIndex;
					if ( m_nCurItemIndex + m_nWidthDrawItemCount > m_nItemCount - 1)
					{
						m_nCurItemIndex = m_nItemCount - 1;
					}
					else
					{
						m_nCurItemIndex += m_nWidthDrawItemCount;
					}

					// 重绘先前焦点Item
					GetItemRectFromIndex(n, rt);
					InvalideRect(rt);

					// 重绘当前焦点Item
					GetItemRectFromIndex(m_nCurItemIndex, rt);
					InvalideRect(rt);
				}
				else
				{
					n = m_nCurItemIndex;
					if ( m_nCurItemIndex + m_nWidthDrawItemCount < m_nItemCount )
					{
						m_nCurItemIndex += m_nWidthDrawItemCount;
						// 整体向下更新一行
						m_nDrawItemStartIndex += m_nWidthDrawItemCount;

						rt.m_ptLT.m_nX = m_nLRBorderWidth + m_nLeftMargin;
						rt.m_ptLT.m_nY = m_nTBBorderHeight + m_nTopMargin;
						rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nWidthDrawItemCount * m_oDrawItemSize.m_nWidth;
						rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nHeightDrawItemCount * m_oDrawItemSize.m_nHeight;
						InvalideRect(rt);

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
						// 看最后一个和当前是否在同一行，如果在同一行则转到最后，否则跳到对应的最开头
						if ( (m_nItemCount - 1) / m_nWidthDrawItemCount > m_nCurItemIndex / m_nWidthDrawItemCount )
						{
							// 转到最后
							m_nDrawItemStartIndex += m_nWidthDrawItemCount;
							m_nCurItemIndex = m_nItemCount - 1;

							rt.m_ptLT.m_nX = m_nLRBorderWidth + m_nLeftMargin;
							rt.m_ptLT.m_nY = m_nTBBorderHeight + m_nTopMargin;
							rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nWidthDrawItemCount * m_oDrawItemSize.m_nWidth;
							rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nHeightDrawItemCount * m_oDrawItemSize.m_nHeight;
							InvalideRect(rt);

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
							// 跳到对应的最开头
							if ( m_nItemCount <= m_nWidthDrawItemCount * m_nHeightDrawItemCount )
							{
								m_nCurItemIndex = n % m_nWidthDrawItemCount;
								// 只需要更新两个
								GetItemRectFromIndex(n, rt);
								InvalideRect(rt);

								GetItemRectFromIndex(m_nCurItemIndex, rt);
								InvalideRect(rt);
							}
							else
							{
								// 全部更新
								m_nDrawItemStartIndex = 0;
								m_nCurItemIndex = n % m_nWidthDrawItemCount;

								rt.m_ptLT.m_nX = m_nLRBorderWidth + m_nLeftMargin;
								rt.m_ptLT.m_nY = m_nTBBorderHeight + m_nTopMargin;
								rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nWidthDrawItemCount * m_oDrawItemSize.m_nWidth;
								rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nHeightDrawItemCount * m_oDrawItemSize.m_nHeight;
								InvalideRect(rt);

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
						}
					}
				}
			}
			return true;

		case AWS_KeyCode_LeftArrow:
			if ( m_nCurItemIndex > m_nDrawItemStartIndex )
			{
				// 只需更新显示两个
				--m_nCurItemIndex;
				GetItemRectFromIndex(m_nCurItemIndex + 1, rt);
				InvalideRect(rt);

				GetItemRectFromIndex(m_nCurItemIndex, rt);
				InvalideRect(rt);
			}
			else
			{
				if ( 0 == m_nCurItemIndex )
				{
					m_nCurItemIndex = m_nItemCount - 1;

					// 如果一屏幕可以显示所有的Item，则只需要更新显示两个；如果一屏幕显示不下，则需要全部更新
					if ( m_nHeightDrawItemCount * m_nWidthDrawItemCount >= m_nItemCount )
					{
						GetItemRectFromIndex(0, rt);
						InvalideRect(rt);

						GetItemRectFromIndex(m_nCurItemIndex, rt);
						InvalideRect(rt);						
					}
					else
					{
						// 改变DrawStart
						m_nDrawItemStartIndex = m_nCurItemIndex - (m_nItemCount - 1) % m_nWidthDrawItemCount - (m_nHeightDrawItemCount - 1) * m_nWidthDrawItemCount;

						rt.m_ptLT.m_nX = m_nLRBorderWidth + m_nLeftMargin;
						rt.m_ptLT.m_nY = m_nTBBorderHeight + m_nTopMargin;
						rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nWidthDrawItemCount * m_oDrawItemSize.m_nWidth;
						rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nHeightDrawItemCount * m_oDrawItemSize.m_nHeight;
						InvalideRect(rt);

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
				}
				else
				{
					// 全部更新
					m_nDrawItemStartIndex -= m_nWidthDrawItemCount;
					--m_nCurItemIndex;

					rt.m_ptLT.m_nX = m_nLRBorderWidth + m_nLeftMargin;
					rt.m_ptLT.m_nY = m_nTBBorderHeight + m_nTopMargin;
					rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nWidthDrawItemCount * m_oDrawItemSize.m_nWidth;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nHeightDrawItemCount * m_oDrawItemSize.m_nHeight;
					InvalideRect(rt);

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
			}
			return true;

		case AWS_KeyCode_RightArrow:
			{
				int n = m_nDrawItemStartIndex + m_nWidthDrawItemCount * m_nHeightDrawItemCount;
				if ( n > m_nItemCount )
				{
					n = m_nItemCount;
				}
				if ( m_nCurItemIndex < n - 1)
				{
					// 只需更新显示两个
					++m_nCurItemIndex;
					GetItemRectFromIndex(m_nCurItemIndex - 1, rt);
					InvalideRect(rt);

					GetItemRectFromIndex(m_nCurItemIndex, rt);
					InvalideRect(rt);
				}
				else
				{
					if ( m_nItemCount - 1 == m_nCurItemIndex )
					{
						m_nCurItemIndex = 0;

						// 如果一屏幕可以显示所有的Item，则只需要更新显示两个；如果一屏幕显示不下，则需要全部更新
						if ( m_nHeightDrawItemCount * m_nWidthDrawItemCount >= m_nItemCount )
						{
							GetItemRectFromIndex(m_nItemCount - 1, rt);
							InvalideRect(rt);

							GetItemRectFromIndex(m_nCurItemIndex, rt);
							InvalideRect(rt);						
						}
						else
						{
							m_nDrawItemStartIndex = 0;

							rt.m_ptLT.m_nX = m_nLRBorderWidth + m_nLeftMargin;
							rt.m_ptLT.m_nY = m_nTBBorderHeight + m_nTopMargin;
							rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nWidthDrawItemCount * m_oDrawItemSize.m_nWidth;
							rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nHeightDrawItemCount * m_oDrawItemSize.m_nHeight;
							InvalideRect(rt);

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
					}
					else
					{
						// 全部更新
						m_nDrawItemStartIndex += m_nWidthDrawItemCount;
						++m_nCurItemIndex;

						rt.m_ptLT.m_nX = m_nLRBorderWidth + m_nLeftMargin;
						rt.m_ptLT.m_nY = m_nTBBorderHeight + m_nTopMargin;
						rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nWidthDrawItemCount * m_oDrawItemSize.m_nWidth;
						rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nHeightDrawItemCount * m_oDrawItemSize.m_nHeight;
						InvalideRect(rt);

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
				}

			}
			return true;

		case AWS_KeyCode_OK:
			PumpCommand(m_nWndID, AWS_SysCmd_ListViewCmd, m_nCurItemIndex);
			return true;
		}
	}

	if ( AWS_Key_Up == type )
	{
		// 响应0-9、*、#的对应
		if ( code >= AWS_KeyCode_1  && code <= AWS_KeyCode_Well )
		{
			int nIndex = code - AWS_KeyCode_1;
			if ( nIndex < m_nItemCount )
			{
				// 重绘前focus窗口
				int n = m_nCurItemIndex;
				CEspRect rect;
				m_nCurItemIndex = nIndex;

				if ( m_nCurItemIndex >= m_nDrawItemStartIndex && (m_nCurItemIndex - m_nDrawItemStartIndex) < m_nWidthDrawItemCount * m_nHeightDrawItemCount - 1 )
				{
					GetItemRectFromIndex(n, rect);
					InvalideRect(rect);

					GetItemRectFromIndex(m_nCurItemIndex, rect);
					InvalideRect(rect);
				}
				else
				{
					m_nDrawItemStartIndex = 0;

					rt.m_ptLT.m_nX = m_nLRBorderWidth + m_nLeftMargin;
					rt.m_ptLT.m_nY = m_nTBBorderHeight + m_nTopMargin;
					rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_nWidthDrawItemCount * m_oDrawItemSize.m_nWidth;
					rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_nHeightDrawItemCount * m_oDrawItemSize.m_nHeight;
					InvalideRect(rt);

					m_nScrollPos = 0;
					m_pScrollBar->SetCurPos(m_nScrollPos);
				}

				return OnKey(AWS_Key, AWS_KeyCode_OK);
			}
		}
	}

	return CAwsContainer::OnKey(type, code);
}

void CBListView::OnSize(const CEspSize& size, bool bIsRedraw /*= true*/)
{
	CAwsContainer::OnSize(size, bIsRedraw);

	if ( ESP_NULL != m_pScrollBar )
	{
		CEspRect rt;
		rt.m_ptLT.m_nX = size.m_nWidth - m_nScrollBarWidth - m_nLRBorderWidth;
		rt.m_ptLT.m_nY =  m_nTBBorderHeight;
		rt.m_ptRB.m_nX = size.m_nWidth - m_nLRBorderWidth;
		rt.m_ptRB.m_nY = size.m_nHeight - m_nTBBorderHeight;

		m_pScrollBar->MoveTo(rt, bIsRedraw);
	}
}
