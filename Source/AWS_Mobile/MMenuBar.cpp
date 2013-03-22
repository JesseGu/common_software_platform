/******************************************************************************
* FileName		       : MMenuBar.cpp
* Description          : implementation of the CMMenuBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "MMenuBar.h"
#include "BLabel.h"
#include "IAwsGc.h"
#include "AwsUi.h"

CMMenuBar::CMMenuBar(int nMenuBarHeight, CAwsWindow* pMidCtrl)
{
	m_nMenuBarHeight = nMenuBarHeight;

	m_pLeftBar = ESP_NULL;
	m_pRightBar = ESP_NULL;

	m_nBarUnitWidth = 40;

	m_pMidCtrl = pMidCtrl;

	CAwsRgb rgbBack(236, 233, 0), rgbBorder(0, 0, 0), rgbText(255, 255, 255);
	m_oBackColor = rgbBack;
	m_oBorderColor = rgbBorder;
	m_oTextColor = rgbText;

	m_nFontSize = 14;

	m_bIsSetImage = false;
}

void CMMenuBar::OnCreate()
{
	// 重新设置菜单条的大小
	CEspSize size = GetUi()->GetScreenSize();
	m_tRect.m_ptLT.m_nX = 0;
	m_tRect.m_ptLT.m_nY = size.m_nHeight - m_nMenuBarHeight;
	m_tRect.m_ptRB.m_nX = m_tRect.m_ptLT.m_nX + size.m_nWidth;
	m_tRect.m_ptRB.m_nY = size.m_nHeight;
	m_tOrigin = m_tRect.m_ptLT;

	CAwsString strText;
	CEspRect rt(1, 1 + 3, m_nBarUnitWidth + 1, m_tRect.GetSize()->m_nHeight - 1 - 3);

	m_pLeftBar = new CBLabel;
	m_pLeftBar->Create(this, rt);
	m_pLeftBar->SetTextColor(m_oTextColor);
	m_pLeftBar->SetTextAlignment(AWS_TAM_Left);
	m_pLeftBar->SetTextSize(m_nFontSize);
	m_pLeftBar->SetBKTransparent(true);
	strText.LoadString(1);
	m_pLeftBar->SetText(strText);
	AddSubWnd(m_pLeftBar);

	if ( ESP_NULL != m_pMidCtrl )
	{
		CEspRect rt(m_nBarUnitWidth, 0, m_tRect.m_ptRB.m_nY - m_nBarUnitWidth, m_tRect.m_ptRB.m_nY);
		m_pMidCtrl->Create(this, rt);
		AddSubWnd(m_pMidCtrl);
	}

	CEspRect rect(m_tRect.GetSize()->m_nWidth - m_nBarUnitWidth - 1, 1 + 3, m_tRect.GetSize()->m_nWidth - 1, m_tRect.GetSize()->m_nHeight - 1 - 3);
	m_pRightBar = new CBLabel;
	m_pRightBar->Create(this, rect);
	m_pRightBar->SetTextColor(m_oTextColor);
	m_pRightBar->SetTextAlignment(AWS_TAM_Right);
	m_pRightBar->SetBKTransparent(true);
	m_pRightBar->SetTextSize(m_nFontSize);
	strText.LoadString(2);
	m_pRightBar->SetText(strText);
	AddSubWnd(m_pRightBar);
}

void CMMenuBar::SetMidCtrl(CAwsWindow* pMidCtrl)
{
}

void CMMenuBar::SetBKImage(const CAwsImage& imageBK, const CEspSize& sizeIamge)
{
	m_oBKImage = imageBK;
	m_oBKImageSize = sizeIamge;
	m_bIsSetImage = true;
}

void CMMenuBar::SetLeftMenuText(const CAwsString& strText, bool bIsRedraw /*= true*/)
{
	m_pLeftBar->SetText(strText);
	if ( bIsRedraw )
		InvalideRect(m_pLeftBar->GetRect());
}

void CMMenuBar::SetRightMenuText(const CAwsString& strText, bool bIsRedraw /*= true*/)
{
	m_pRightBar->SetText(strText);
	if ( bIsRedraw )
		InvalideRect(m_pRightBar->GetRect());
}

void CMMenuBar::DrawBK(IAwsGc* pGc, const CEspRect& rect)
{
	CEspSize size = *rect.GetSize();
	CEspRect rt = rect;

	if ( m_bIsSetImage )
	{
		rt.m_ptLT.m_nY = 0;
		int i, nCount = size.m_nWidth / m_oBKImageSize.m_nWidth + (size.m_nWidth % m_oBKImageSize.m_nWidth > 0 ? 1 : 0);
		for ( i = 0; i < nCount; ++i )
		{
			pGc->DrawImage(rt.m_ptLT, m_oBKImage);
			rt.m_ptLT.m_nX += m_oBKImageSize.m_nWidth;
		}
	}
	else
	{
		if ( rect.GetSize()->m_nWidth == GetSize()->m_nWidth )
		{
			pGc->SetPenColor(m_oBorderColor);
			pGc->SetBrushColor(m_oBackColor);
			pGc->DrawFillRect(rt);
		}
		else
		{
			pGc->SetPenColor(m_oBackColor);
			pGc->SetBrushColor(m_oBackColor);
			pGc->DrawFillRect(rt);
		}
	}
}

void CMMenuBar::OnDraw(const CEspRect& rect)
{
//	TRACE("menubar draw, X(%d),Y(%d), Width(%d), Height(%d)\n", rect.m_ptLT.m_nX, rect.m_ptLT.m_nY, rect.GetSize()->m_nWidth, rect.GetSize()->m_nHeight);

	// 画背景
	IAwsGc* pGc = GetGc();

	if ( ESP_NULL != pGc )
	{
		DrawBK(pGc, rect);

		// 调用父类的绘制函数
		CAwsContainer::OnDraw(rect);
	}
}
