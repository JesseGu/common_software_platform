
#include "stdafx.h"
#include "EWndGc.h"
#include "EWndString.h"

const VTab_IAwsGc g_tVTab_CEWndGc_IAwsGc = {CEWndGc_SetOrigin_CAwsPoint1p, CEWndGc_SetPenWidth_i0p, CEWndGc_SetPenColor_CAwsRgb1p, CEWndGc_SetBrushColor_CAwsRgb1p, CEWndGc_DrawLine_CAwsPoint1p_CAwsPoint1p, CEWndGc_DrawRect_CAwsRect1p, CEWndGc_DrawFillRect_CAwsRect1p, CEWndGc_DrawEllipse_CAwsRect1p, CEWndGc_SetTextColor_CAwsRgb1p, CEWndGc_SetTextBKColor_CAwsRgb1p, CEWndGc_SetTextBKMode_0p, CEWndGc_SetTextAlignment_0p, CEWndGc_DrawText_CAwsString1p_CAwsRect1p, CEWndGc_GetTextSize_CAwsString1p, CEWndGc_UseFont_CAwsFont1p, CEWndGc_DiscardFont, CEWndGc_DrawImage_CAwsPoint1p_CAwsImage1p_CAwsImage1p, CEWndGc_SetClipRect_CAwsRect1p, CEWndGc_ResetClipRect };

void CEWndGc_CInit(CEWndGc* pThis)
{
	pThis->m_oBaseAwsGc.m_pVTab = &g_tVTab_CEWndGc_IAwsGc;

	CAwsRgb_CInit_i0p_i0p_i0p(&pThis->m_tPenColor, 0, 0, 0);
	CAwsRgb_CInit_i0p_i0p_i0p(&pThis->m_tBrushColor, 0, 0, 0);
	CEspSize_CInit_i0p_i0p(&pThis->m_oSize, 0, 0);

	pThis->m_hDC = NULL;
	pThis->m_nPenWidth = 1;

	pThis->m_hInst = NULL;

	pThis->m_hPen = NULL;
	pThis->m_hBrush = NULL;
	pThis->m_hFont = NULL;

	pThis->m_hBitmap = NULL;

	pThis->m_nTextAlignment = DT_LEFT | DT_VCENTER;

	pThis->m_hMemDC = NULL;
	pThis->m_hMemBitmap = NULL;
	pThis->m_hMemDC1 = NULL;
	pThis->m_hMemBitmap1 = NULL;
}

void CEWndGc_DUninit(CEWndGc* pThis)
{
	DeleteObject(pThis->m_hPen);
	DeleteObject(pThis->m_hBrush);
}

void CEWndGc_SetDC(CEWndGc* pThis, HDC hDC)
{
	pThis->m_hDC = hDC;
}

void CEWndGc_SetInst(CEWndGc* pThis, HINSTANCE hInst)
{
	pThis->m_hInst = hInst;
}

void CEWndGc_SetOrigin_CAwsPoint1p(IAwsGc* this, CEspPoint * pt)
{
	CEWndGc* pThis = (CEWndGc*)this;

	pThis->m_tOrigin = *pt;
}

void CEWndGc_SetPenWidth_i0p(IAwsGc* this, int nPixels)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		pThis->m_nPenWidth = nPixels;
		DeleteObject(pThis->m_hPen);
		pThis->m_hPen = CreatePen(PS_SOLID, pThis->m_nPenWidth, pThis->m_tPenColor.m_nValue);
		SelectObject(pThis->m_hDC, pThis->m_hPen);
	}
}

void CEWndGc_SetPenColor_CAwsRgb1p(IAwsGc* this, const CAwsRgb * color)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( ESP_NULL != pThis->m_hDC )
	{
		pThis->m_tPenColor = *color;
		DeleteObject(pThis->m_hPen);
		pThis->m_hPen = CreatePen(PS_SOLID, pThis->m_nPenWidth, pThis->m_tPenColor.m_nValue);
		SelectObject(pThis->m_hDC, pThis->m_hPen);
	}
}

void CEWndGc_SetBrushColor_CAwsRgb1p(IAwsGc* this, const CAwsRgb * color)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( ESP_NULL != pThis->m_hDC )
	{
		pThis->m_tBrushColor = *color;
		DeleteObject(pThis->m_hBrush);
		pThis->m_hBrush = CreateSolidBrush(pThis->m_tBrushColor.m_nValue);
		SelectObject(pThis->m_hDC, pThis->m_hBrush);
	}
}

void CEWndGc_DrawLine_CAwsPoint1p_CAwsPoint1p(IAwsGc* this, const CEspPoint * ptStart, const CEspPoint * ptEnd)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		POINT pt;
		CEspPoint start = *ptStart, end = *ptEnd;
		CEspPoint_Operator_AddEqu_CEspPoint1p(&start, &pThis->m_tOrigin);
//		start += pThis->m_tOrigin;
		pt.x = start.m_nX;
		pt.y = start.m_nY;
		MoveToEx(pThis->m_hDC, pt.x, pt.y, NULL);
		
		CEspPoint_Operator_AddEqu_CEspPoint1p(&end, &pThis->m_tOrigin);
//		end += pThis->m_tOrigin;
		pt.x = end.m_nX;
		pt.y = end.m_nY;
		LineTo(pThis->m_hDC, pt.x, pt.y);
	}
}

void CEWndGc_DrawRect_CAwsRect1p(IAwsGc* this, const CEspRect * rect)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		// 坐标转换
		CEspRect rt = *rect;
		CEspPoint_Operator_AddEqu_CEspPoint1p(&rt.m_ptLT, &pThis->m_tOrigin);
		CEspPoint_Operator_AddEqu_CEspPoint1p(&rt.m_ptRB, &pThis->m_tOrigin);
//		rt.m_ptLT += pThis->m_tOrigin;
//		rt.m_ptRB += pThis->m_tOrigin;
		
		{
			HGDIOBJ hObject = GetStockObject(NULL_BRUSH);
			HGDIOBJ hOldObj = NULL;
			hOldObj = SelectObject(pThis->m_hDC, hObject);

//			SelectObject(pThis->m_hDC, NULL_BRUSH);
		}

		Rectangle(pThis->m_hDC, rt.m_ptLT.m_nX, rt.m_ptLT.m_nY, rt.m_ptRB.m_nX, rt.m_ptRB.m_nY);
	}
}

void CEWndGc_DrawFillRect_CAwsRect1p(IAwsGc* this, const CEspRect * rect)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		// 坐标转换
		CEspRect rt = *rect;
		CEspPoint_Operator_AddEqu_CEspPoint1p(&rt.m_ptLT, &pThis->m_tOrigin);
		CEspPoint_Operator_AddEqu_CEspPoint1p(&rt.m_ptRB, &pThis->m_tOrigin);
//		rt.m_ptLT += pThis->m_tOrigin;
//		rt.m_ptRB += pThis->m_tOrigin;
		
		Rectangle(pThis->m_hDC, rt.m_ptLT.m_nX, rt.m_ptLT.m_nY, rt.m_ptRB.m_nX, rt.m_ptRB.m_nY);
	}
}

void CEWndGc_DrawEllipse_CAwsRect1p(IAwsGc* this, const CEspRect * rect)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		// 坐标转换
		CEspRect rt = *rect;
		CEspPoint_Operator_AddEqu_CEspPoint1p(&rt.m_ptLT, &pThis->m_tOrigin);
		CEspPoint_Operator_AddEqu_CEspPoint1p(&rt.m_ptRB, &pThis->m_tOrigin);
//		rt.m_ptLT += pThis->m_tOrigin;
//		rt.m_ptRB += pThis->m_tOrigin;

		Ellipse(pThis->m_hDC, rt.m_ptLT.m_nX, rt.m_ptLT.m_nY, rt.m_ptRB.m_nX, rt.m_ptRB.m_nY);
	}
}

void CEWndGc_SetTextColor_CAwsRgb1p(IAwsGc* this, const CAwsRgb * color)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		SetTextColor(pThis->m_hDC, color->m_nValue);
	}
}

void CEWndGc_SetTextBKColor_CAwsRgb1p(IAwsGc* this, const CAwsRgb * color)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		SetBkColor(pThis->m_hDC, color->m_nValue);
	}
}

void CEWndGc_SetTextBKMode_0p(IAwsGc* this, AWS_TextShowMode mode)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
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

		SetBkMode(pThis->m_hDC, nMode);
	}
}

void CEWndGc_SetTextAlignment_0p(IAwsGc* this, AWS_TextAlignMode mode)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		switch ( mode )
		{
		case AWS_TAM_Left:
			pThis->m_nTextAlignment = DT_LEFT | DT_VCENTER;
			break;
			
		case AWS_TAM_Mid:
			pThis->m_nTextAlignment = DT_CENTER | DT_VCENTER;
			break;
			
		case AWS_TAM_Right:
			pThis->m_nTextAlignment = DT_RIGHT | DT_VCENTER;
			break;
		}
	}

}

void CEWndGc_DrawText_CAwsString1p_CAwsRect1p(IAwsGc* this, const CAwsString * strText, const CEspRect * rect)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		RECT rt;
		int nID;
		// 坐标转换
		rt.left = rect->m_ptLT.m_nX + pThis->m_tOrigin.m_nX;
		rt.top = rect->m_ptLT.m_nY + pThis->m_tOrigin.m_nY;
		rt.right = rect->m_ptRB.m_nX + pThis->m_tOrigin.m_nX;
		rt.bottom = rect->m_ptRB.m_nY + pThis->m_tOrigin.m_nY;

		// 加载字符串,并绘制
		nID = CAwsString_GetStrID(strText);
		if ( nID > -1 )
		{
			DrawText(pThis->m_hDC, g_str[nID], -1, &rt, pThis->m_nTextAlignment);
		}
		else
		{
			DrawText(pThis->m_hDC, CAwsString_GetStringData(strText), -1, &rt, pThis->m_nTextAlignment);
		}
	}
}

const CEspSize *  CEWndGc_GetTextSize_CAwsString1p(IAwsGc* this, const CAwsString * strText)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		SIZE size;
		int nID = CAwsString_GetStrID(strText);
		if ( nID > -1 )
		{
			GetTextExtentPoint32(pThis->m_hDC, g_str[CAwsString_GetStrID(strText)], strlen(g_str[CAwsString_GetStrID(strText)]), &size);
		}
		else
		{
			GetTextExtentPoint32(pThis->m_hDC, CAwsString_GetStringData(strText), strlen(CAwsString_GetStringData(strText)), &size);
		}

		pThis->m_oSize.m_nWidth = size.cx;
		pThis->m_oSize.m_nHeight = size.cy;
		return &pThis->m_oSize;//CAwsSize(size.cx, size.cy);
	}

	return NULL;
}

void CEWndGc_UseFont_CAwsFont1p(IAwsGc* this, const CAwsFont * font)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		int nFontID = CAwsFont_GetFontID(font);
		int nSize = CAwsFont_GetFontSize(font);

		// 字体转换
		LOGFONT lf = {0};
		_tcscpy(lf.lfFaceName, _T("宋体"));
		lf.lfHeight = nSize;
		lf.lfWeight = 400;

		DeleteObject(pThis->m_hFont);
		pThis->m_hFont = CreateFontIndirect(&lf);

		SelectObject(pThis->m_hDC, pThis->m_hFont);
	}
}

void CEWndGc_DiscardFont(IAwsGc* this)
{
	CEWndGc* pThis = (CEWndGc*)this;
	
}

void CEWndGc_DrawImage_CAwsPoint1p_CAwsImage1p_CAwsImage1p(IAwsGc* this, const CEspPoint * pt, const CAwsImage * image, const CAwsImage *  pMaskImage)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		BITMAP bm;
		SIZE size;
		POINT ptLT;
		CEspPoint pp = *pt;

		// 加载图像
		DeleteObject(pThis->m_hBitmap);
		pThis->m_hBitmap = LoadBitmap(pThis->m_hInst, MAKEINTRESOURCE(CAwsImage_GetID(image)));
//		pThis->m_hBitmap = LoadBitmap(pThis->m_hInst, CAwsImage_GetID(image));

		GetObject(pThis->m_hBitmap, sizeof(BITMAP), &bm);
//		GetBitmap(pThis->m_hBitmap, &bm);
		size.cx = bm.bmWidth;
		size.cy = bm.bmHeight;

		CEspPoint_Operator_AddEqu_CEspPoint1p(&pp, &pThis->m_tOrigin);
//		pp += pThis->m_tOrigin;
		ptLT.x = pp.m_nX;
		ptLT.y = pp.m_nY;

		if ( ESP_NULL == pMaskImage || 0 == CAwsImage_GetID(pMaskImage) )
		{
			DrawState(pThis->m_hDC, NULL, NULL, (LPARAM)pThis->m_hBitmap, 0, ptLT.x, ptLT.y, size.cx, size.cy, DST_BITMAP);
		}
		else
		{
			// 加上图片掩码
			pThis->m_hMemBitmap = LoadBitmap(pThis->m_hInst, MAKEINTRESOURCE(CAwsImage_GetID(pMaskImage)));
			pThis->m_hMemDC = CreateCompatibleDC(pThis->m_hDC);
			SelectObject(pThis->m_hMemDC, pThis->m_hMemBitmap);
			BitBlt(pThis->m_hDC, ptLT.x, ptLT.y, size.cx, size.cy, pThis->m_hMemDC, 0, 0, MERGEPAINT);

			pThis->m_hMemBitmap1 = LoadBitmap(pThis->m_hInst, MAKEINTRESOURCE(CAwsImage_GetID(image)));
			pThis->m_hMemDC1 = CreateCompatibleDC(pThis->m_hDC);
			SelectObject(pThis->m_hMemDC1, pThis->m_hMemBitmap1);
			BitBlt(pThis->m_hMemDC1, 0, 0, size.cx, size.cy, pThis->m_hMemDC, 0, 0, SRCPAINT);

			BitBlt(pThis->m_hDC, ptLT.x, ptLT.y, size.cx, size.cy, pThis->m_hMemDC1, 0, 0, SRCAND);

			DeleteDC(pThis->m_hMemDC);
			DeleteDC(pThis->m_hMemDC1);

			DeleteObject(pThis->m_hMemBitmap);
			DeleteObject(pThis->m_hMemBitmap1);
		}
	}
}

void CEWndGc_SetClipRect_CAwsRect1p(IAwsGc* this, const CEspRect * rect)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		CEspRect rt = *rect;
		HRGN  hRgn;
		int n;

		CEspPoint_Operator_AddEqu_CEspPoint1p(&rt.m_ptLT, &pThis->m_tOrigin);
		CEspPoint_Operator_AddEqu_CEspPoint1p(&rt.m_ptRB, &pThis->m_tOrigin);
//		rt.m_ptLT += pThis->m_tOrigin;
//		rt.m_ptRB += pThis->m_tOrigin;

		hRgn = CreateRectRgn(rt.m_ptLT.m_nX, rt.m_ptLT.m_nY, rt.m_ptRB.m_nX, rt.m_ptRB.m_nY);
		n = SelectClipRgn(pThis->m_hDC, hRgn);
	}
}

void CEWndGc_ResetClipRect(IAwsGc* this)
{
	CEWndGc* pThis = (CEWndGc*)this;

	if ( NULL != pThis->m_hDC )
	{
		SelectClipRgn(pThis->m_hDC, NULL);
	}
}
