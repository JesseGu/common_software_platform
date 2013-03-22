/******************************************************************************
* FileName		       : BTitleBar.cpp
* Description          : implementation of the CBTitleBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BTitleBar.h"
#include "IAwsGc.h"
#include "AwsUi.h"

CBTitleBar::CBTitleBar(int nTitleBarHeight)
{
	m_nTitleBarHeight = nTitleBarHeight;

	m_nFontSize = 12;

	CAwsRgb rgbText(255, 255, 255), rgbBK(0, 233, 216);
	m_oTextColor = rgbText;
	m_oBKColor = rgbBK;

	m_bIsSetBKImage = false;

	m_nLeftMargin = 3;
}

void CBTitleBar::OnCreate()
{
	// 重新设置菜单条的大小
	CEspSize size = GetUi()->GetScreenSize();
	m_tRect.m_ptLT.m_nX = 0;
	m_tRect.m_ptLT.m_nY = 0;
	m_tRect.m_ptRB.m_nX = size.m_nWidth;
	m_tRect.m_ptRB.m_nY = m_nTitleBarHeight;
	m_tOrigin = m_tRect.m_ptLT;
}

void CBTitleBar::SetIcon(const CAwsImage& icon, const CEspSize& size, const CAwsImage* pIconMask)
{
	m_oIconImage = icon;
	m_oIconSize = size;
	if ( ESP_NULL != pIconMask )
	{
		m_oIconMask = *pIconMask;
	}
}

void CBTitleBar::SetCaption(const CAwsString& strText)
{
	m_oStrCaption = strText;
	Invalide();
}

void CBTitleBar::SetBKImage(const CAwsImage& imageBK, const CEspSize& sizeImage)
{
	m_oBKImage = imageBK;
	m_oBKImageSize = sizeImage;

	m_bIsSetBKImage = true;
}

void CBTitleBar::DrawBackground(IAwsGc* pGc, const CEspRect& rect)
{
	CEspSize size = *rect.GetSize();
	CEspRect rt = rect;
	if ( m_bIsSetBKImage )
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
		pGc->SetPenColor(m_oBKColor);
		pGc->SetBrushColor(m_oBKColor);
		pGc->DrawFillRect(rect);
	}
}

bool CBTitleBar::DrawIcon(IAwsGc* pGc, const CEspRect& rect, CEspSize& sizeIcon)
{
	bool bRet = false;
	if ( m_oIconImage.GetID() > 0 )
	{
		// 画图标

		CEspPoint pt = rect.m_ptLT;
		pt.m_nY += (GetSize()->m_nHeight - m_oIconSize.m_nHeight) / 2;

		pGc->DrawImage(pt, m_oIconImage, &m_oIconMask);
		sizeIcon = m_oIconSize;
		bRet = true;
	}

	return bRet;
}

void CBTitleBar::DrawText(IAwsGc* pGc, const CEspRect& rect)
{
	CEspRect rt = rect;
	pGc->SetTextColor(m_oTextColor);
	pGc->SetTextAlignment(AWS_TAM_Left);
	pGc->SetTextBKMode(AWS_TSM_Transparent);

	m_oFont.CreateFont(0, m_nFontSize);
	pGc->UseFont(m_oFont);
	const CEspSize* size = pGc->GetTextSize(m_oStrCaption);
	rt.m_ptLT.m_nY = rt.m_ptLT.m_nY + (GetSize()->m_nHeight - size->m_nHeight) / 2;
	pGc->DrawText(m_oStrCaption, rt);
}

void CBTitleBar::OnDraw(const CEspRect& rect)
{
	// 画背景
	IAwsGc* pGc = GetGc();

//	TRACE("titlebar draw, X(%d),Y(%d), Width(%d), Height(%d)\n", rect.m_ptLT.m_nX, rect.m_ptLT.m_nY, rect.GetSize()->m_nWidth, rect.GetSize()->m_nHeight);

	if ( ESP_NULL != pGc )
	{
		DrawBackground(pGc, rect);

		CEspRect rt = rect;
		rt.m_ptLT.m_nX += m_nLeftMargin;

		CEspSize sizeIcon;
		if ( DrawIcon(pGc, rt, sizeIcon) )
		{
			rt.m_ptLT.m_nX += sizeIcon.m_nWidth;
		}

		DrawText(pGc, rt);
	}
}
