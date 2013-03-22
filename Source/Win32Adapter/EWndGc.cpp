// EWndGc.cpp: implementation of the CEWndGc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EWndGc.h"

#include "EWndString.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEWndGc::CEWndGc()
{
	m_pDC = NULL;

	m_nTextAlignment = DT_LEFT | DT_VCENTER;

	m_nPenWidth = 1;
}

CEWndGc::~CEWndGc()
{
	m_oPen.DeleteObject();
	m_oBrush.DeleteObject();
}

void CEWndGc::SetOrigin(CEspPoint& pt)
{
	m_tOrigin = pt;
}

void CEWndGc::SetPenWidth(int nPixels)
{
	if ( ESP_NULL != m_pDC )
	{
		m_nPenWidth = nPixels;
		m_oPen.DeleteObject();
		m_oPen.CreatePen(PS_SOLID, m_nPenWidth, m_tPenColor.m_nValue);
		m_pDC->SelectObject(m_oPen);
	}
}

void CEWndGc::SetPenColor(const CAwsRgb& color)
{
	if ( ESP_NULL != m_pDC )
	{
		m_tPenColor = color;
		m_oPen.DeleteObject();
		m_oPen.CreatePen(PS_SOLID, m_nPenWidth, m_tPenColor.m_nValue);
		m_pDC->SelectObject(m_oPen);
	}
}

void CEWndGc::SetBrushColor(const CAwsRgb& color)
{
	if ( ESP_NULL != m_pDC )
	{
		m_tBrushColor = color;
		m_oBrush.DeleteObject();
		m_oBrush.CreateSolidBrush(m_tBrushColor.m_nValue);
		m_pDC->SelectObject(m_oBrush);
	}
}

void CEWndGc::DrawLine(const CEspPoint& ptStart, const CEspPoint& ptEnd)
{
	if ( NULL != m_pDC )
	{
		POINT pt;
		CEspPoint start = ptStart, end = ptEnd;
		start += m_tOrigin;
		pt.x = start.m_nX;
		pt.y = start.m_nY;
		m_pDC->MoveTo(pt);

		end += m_tOrigin;
		pt.x = end.m_nX;
		pt.y = end.m_nY;
		m_pDC->LineTo(pt);
	}
}

void CEWndGc::DrawRect(const CEspRect& rect)
{
	if ( NULL != m_pDC )
	{
		// 坐标转换
		CEspRect rt = rect;
		rt.m_ptLT += m_tOrigin;
		rt.m_ptRB += m_tOrigin;

		m_pDC->SelectStockObject(NULL_BRUSH);
		m_pDC->Rectangle(rt.m_ptLT.m_nX, rt.m_ptLT.m_nY, rt.m_ptRB.m_nX, rt.m_ptRB.m_nY);
	}
}

void CEWndGc::DrawFillRect(const CEspRect& rect)
{
	if ( NULL != m_pDC )
	{
		// 坐标转换
		CEspRect rt = rect;
		rt.m_ptLT += m_tOrigin;
		rt.m_ptRB += m_tOrigin;

		m_pDC->Rectangle(rt.m_ptLT.m_nX, rt.m_ptLT.m_nY, rt.m_ptRB.m_nX, rt.m_ptRB.m_nY);
	}
}

void CEWndGc::DrawEllipse(const CEspRect& rect)
{
	if ( NULL != m_pDC )
	{
		// 坐标转换
		CEspRect rt = rect;
		rt.m_ptLT += m_tOrigin;
		rt.m_ptRB += m_tOrigin;

		m_pDC->Ellipse(rt.m_ptLT.m_nX, rt.m_ptLT.m_nY, rt.m_ptRB.m_nX, rt.m_ptRB.m_nY);
	}
}

void CEWndGc::SetTextColor(const CAwsRgb& color)
{
	if ( NULL != m_pDC )
	{
		m_pDC->SetTextColor(color.m_nValue);
	}
}

void CEWndGc::SetTextBKColor(const CAwsRgb& color)
{
	if ( NULL != m_pDC )
	{
		m_pDC->SetBkColor(color.m_nValue);
	}
}

void CEWndGc::SetTextBKMode(AWS_TextShowMode mode)
{
	if ( NULL != m_pDC )
	{
		int nMode = 0;
		switch ( mode )
		{
		case AWS_TSM_Transparent:
			nMode = TRANSPARENT;
			break;

		case AWS_TSM_Opaque:
			nMode = OPAQUE;
			break;
		}

		m_pDC->SetBkMode(nMode);
	}
}

void CEWndGc::SetTextAlignment(AWS_TextAlignMode mode)
{
	if ( NULL != m_pDC )
	{
		switch ( mode )
		{
		case AWS_TAM_Left:
			m_nTextAlignment = DT_LEFT | DT_VCENTER;
			break;

		case AWS_TAM_Mid:
			m_nTextAlignment = DT_CENTER | DT_VCENTER;
			break;

		case AWS_TAM_Right:
			m_nTextAlignment = DT_RIGHT | DT_VCENTER;
			break;
		}
	}
}

void CEWndGc::DrawText(const CAwsString& strText, const CEspRect& rect)
{
	if ( NULL != m_pDC )
	{
		RECT rt;
		// 坐标转换
		rt.left = rect.m_ptLT.m_nX + m_tOrigin.m_nX;
		rt.top = rect.m_ptLT.m_nY + m_tOrigin.m_nY;
		rt.right = rect.m_ptRB.m_nX + m_tOrigin.m_nX;
		rt.bottom = rect.m_ptRB.m_nY + m_tOrigin.m_nY;

		// 加载字符串,并绘制
		int nID = strText.GetStrID();
		if ( nID > -1 )
		{
			m_pDC->DrawText(g_str[nID], &rt, m_nTextAlignment);
		}
		else
		{
			m_pDC->DrawText(strText.GetStringData(), &rt, m_nTextAlignment);
		}
	}
}

const CEspSize* CEWndGc::GetTextSize(const CAwsString& strText)
{
	if ( NULL != m_pDC )
	{
		CSize size;
		int nID = strText.GetStrID();
		if ( nID > -1 )
		{
			size = m_pDC->GetTextExtent(g_str[strText.GetStrID()]);
		}
		else
		{
			size = m_pDC->GetTextExtent(strText.GetStringData());
		}

		m_oSize.m_nWidth = size.cx;
		m_oSize.m_nHeight = size.cy;
		return &m_oSize;//CAwsSize(size.cx, size.cy);
	}

	return NULL;
}

void CEWndGc::UseFont(const CAwsFont& font)
{
	if ( NULL != m_pDC )
	{
		int nFontID = font.GetFontID();
		int nSize = font.GetFontSize();

		// 字体转换
		LOGFONT lf = {0};
		_tcscpy(lf.lfFaceName, _T("宋体"));
		lf.lfHeight = nSize;
		lf.lfWeight = 400;

		m_oFont.DeleteObject();
		m_oFont.CreateFontIndirect(&lf);

		m_pDC->SelectObject(m_oFont);
	}
}

void CEWndGc::DiscardFont()
{
}

void CEWndGc::DrawImage(const CEspPoint& pt, const CAwsImage& image, const CAwsImage* pMaskImage)
{
	if ( NULL != m_pDC )
	{
		// 加载图像
		m_oBitmap.DeleteObject();
		m_oBitmap.LoadBitmap(image.GetID());
		BITMAP bm;
		CSize size;
		m_oBitmap.GetBitmap(&bm);
		size.cx = bm.bmWidth;
		size.cy = bm.bmHeight;

		POINT ptLT;
		CEspPoint pp = pt;
		pp += m_tOrigin;
		ptLT.x = pp.m_nX;
		ptLT.y = pp.m_nY;

		if ( ESP_NULL == pMaskImage || 0 == pMaskImage->GetID() )
		{
			m_pDC->DrawState(ptLT, size, m_oBitmap, DST_BITMAP);
		}
		else
		{
			// 加上图片掩码
			m_oBitMap.LoadBitmap(pMaskImage->GetID());
			m_oMemDC.CreateCompatibleDC(m_pDC);
			m_oMemDC.SelectObject(&m_oBitMap);
			m_pDC->BitBlt(ptLT.x, ptLT.y, size.cx, size.cy, &m_oMemDC, 0, 0, MERGEPAINT);

			m_oBitMap1.LoadBitmap(image.GetID());
			m_oMemDC1.CreateCompatibleDC(m_pDC);
			m_oMemDC1.SelectObject(&m_oBitMap1);
			m_oMemDC1.BitBlt(0, 0, size.cx, size.cy, &m_oMemDC, 0, 0, SRCPAINT);

			m_pDC->BitBlt(ptLT.x, ptLT.y, size.cx, size.cy, &m_oMemDC1, 0, 0, SRCAND);

			m_oMemDC.DeleteDC();
			m_oMemDC1.DeleteDC();

			m_oBitMap.DeleteObject();
			m_oBitMap1.DeleteObject();
		}
	}
}

void CEWndGc::SetClipRect(const CEspRect& rect)
{
	if ( NULL != m_pDC )
	{
		CEspRect rt = rect;
		rt.m_ptLT += m_tOrigin;
		rt.m_ptRB += m_tOrigin;

		CRgn rgn;
		rgn.CreateRectRgn(rt.m_ptLT.m_nX, rt.m_ptLT.m_nY, rt.m_ptRB.m_nX, rt.m_ptRB.m_nY);
		m_pDC->SelectClipRgn(&rgn);
	}
}

void CEWndGc::ResetClipRect()
{
	if ( NULL != m_pDC )
	{
		m_pDC->SelectClipRgn(NULL);
	}
}
