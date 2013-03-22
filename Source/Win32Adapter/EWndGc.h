// EWndGc.h: interface for the CEWndGc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EWNDGC_H__AB10743B_4AF1_418E_BE03_A4E090933F94__INCLUDED_)
#define AFX_EWNDGC_H__AB10743B_4AF1_418E_BE03_A4E090933F94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IAwsGc.h"
#include "EspString.h"
class CDC;

// 与具体平台相关的Gc，需要实现
class CEWndGc : public IAwsGc
{
public:
	CEWndGc();
	virtual ~CEWndGc();

	void SetDC(CDC* pDC)
	{
		m_pDC = pDC;
	}

public:
	virtual void SetOrigin(CEspPoint& pt);

	virtual void SetPenWidth(int nPixels);
	virtual void SetPenColor(const CAwsRgb& color);
	virtual void SetBrushColor(const CAwsRgb& color);
	virtual void DrawLine(const CEspPoint& ptStart, const CEspPoint& ptEnd);
	virtual void DrawRect(const CEspRect& rect);
	virtual void DrawFillRect(const CEspRect& rect);

	virtual void DrawEllipse(const CEspRect& rect);

	virtual void SetTextColor(const CAwsRgb& color);
	virtual void SetTextBKColor(const CAwsRgb& color);
	virtual void SetTextBKMode(AWS_TextShowMode mode);
	virtual void SetTextAlignment(AWS_TextAlignMode mode);
	virtual void DrawText(const CAwsString& strText, const CEspRect& rect);

	virtual const CEspSize* GetTextSize(const CAwsString& strText);

	virtual void UseFont(const CAwsFont& font);
	virtual void DiscardFont();

	virtual void DrawImage(const CEspPoint& pt, const CAwsImage& image, const CAwsImage* pMaskImage = ESP_NULL);

	virtual void SetClipRect(const CEspRect& rect);
	virtual void ResetClipRect();

private:
	CDC*	m_pDC;
	CEspPoint	m_tOrigin;

	int		m_nPenWidth;
	CAwsRgb	m_tPenColor;
	CAwsRgb	m_tBrushColor;

	CPen	m_oPen;
	CBrush	m_oBrush;
	CFont	m_oFont;

	CBitmap	m_oBitmap;

	UINT	m_nTextAlignment;

	// 用于加掩码图片的显示
	CDC		m_oMemDC;
	CBitmap	m_oBitMap;
	CDC		m_oMemDC1;
	CBitmap	m_oBitMap1;

	CEspSize	m_oSize;
};

#endif // !defined(AFX_EWNDGC_H__AB10743B_4AF1_418E_BE03_A4E090933F94__INCLUDED_)
