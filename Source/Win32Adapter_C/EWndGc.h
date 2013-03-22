
#ifndef __EWNDGC_2011_03_06_H__
#define __EWNDGC_2011_03_06_H__

#include "IAwsGc.h"

typedef struct tagCEWndGc CEWndGc;

struct tagCEWndGc
{
	IAwsGc		m_oBaseAwsGc;

	HDC			m_hDC;
	HINSTANCE	m_hInst;

	CEspPoint	m_tOrigin;

	int			m_nPenWidth;
	CAwsRgb		m_tPenColor;
	CAwsRgb		m_tBrushColor;

	HPEN		m_hPen;
	HBRUSH		m_hBrush;
	HFONT		m_hFont;

	HBITMAP		m_hBitmap;

	UINT		m_nTextAlignment;

	// 用于加掩码图片的显示
	HDC			m_hMemDC;
	HBITMAP		m_hMemBitmap;
	HDC			m_hMemDC1;
	HBITMAP		m_hMemBitmap1;

	CEspSize	m_oSize;
};

void CEWndGc_CInit(CEWndGc* pThis);
void CEWndGc_DUninit(CEWndGc* pThis);
void CEWndGc_SetDC(CEWndGc* pThis, HDC hDC);
void CEWndGc_SetInst(CEWndGc* pThis, HINSTANCE hInst);

void CEWndGc_SetOrigin_CAwsPoint1p(IAwsGc* this, CEspPoint * pt);
void CEWndGc_SetPenWidth_i0p(IAwsGc* this, int nPixels);
void CEWndGc_SetPenColor_CAwsRgb1p(IAwsGc* this, const CAwsRgb * color);
void CEWndGc_SetBrushColor_CAwsRgb1p(IAwsGc* this, const CAwsRgb * color);
void CEWndGc_DrawLine_CAwsPoint1p_CAwsPoint1p(IAwsGc* this, const CEspPoint * ptStart, const CEspPoint * ptEnd);
void CEWndGc_DrawRect_CAwsRect1p(IAwsGc* this, const CEspRect * rect);
void CEWndGc_DrawFillRect_CAwsRect1p(IAwsGc* this, const CEspRect * rect);
void CEWndGc_DrawEllipse_CAwsRect1p(IAwsGc* this, const CEspRect * rect);
void CEWndGc_SetTextColor_CAwsRgb1p(IAwsGc* this, const CAwsRgb * color);
void CEWndGc_SetTextBKColor_CAwsRgb1p(IAwsGc* this, const CAwsRgb * color);
void CEWndGc_SetTextBKMode_0p(IAwsGc* this, AWS_TextShowMode mode);
void CEWndGc_SetTextAlignment_0p(IAwsGc* this, AWS_TextAlignMode mode);
void CEWndGc_DrawText_CAwsString1p_CAwsRect1p(IAwsGc* this, const CAwsString * strText, const CEspRect * rect);
const CEspSize *  CEWndGc_GetTextSize_CAwsString1p(IAwsGc* this, const CAwsString * strText);
void CEWndGc_UseFont_CAwsFont1p(IAwsGc* this, const CAwsFont * font);
void CEWndGc_DiscardFont(IAwsGc* this);
void CEWndGc_DrawImage_CAwsPoint1p_CAwsImage1p_CAwsImage1p(IAwsGc* this, const CEspPoint * pt, const CAwsImage * image, const CAwsImage *  pMaskImage);
void CEWndGc_SetClipRect_CAwsRect1p(IAwsGc* this, const CEspRect * rect);
void CEWndGc_ResetClipRect(IAwsGc* this);

// 虚函数表的声明
extern const VTab_IAwsGc g_tVTab_CEWndGc_IAwsGc;

#endif /*__EWNDGC_2011_03_06_H__*/
