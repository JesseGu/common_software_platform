/******************************************************************************
* FileName		       : BEdit.cpp
* Description          : implementation of the CBEdit class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BEdit.h"
#include "AwsUi.h"
#include "IAwsGc.h"

CBEdit::CBEdit()
{
	CAwsRgb rgbBorder(0, 0, 0), rgbFocus(255, 0, 0), rgbBK(255, 255, 255), rgbCaret(0, 0, 0), rgbText(0, 0, 0);
	m_oBorderColor = rgbBorder;
	m_oFocusBorderColor = rgbFocus;
	m_oBKColor = rgbBK;
	m_oCaretColor = rgbCaret;
	m_oTextColor = rgbText;

	m_oCaretPos.m_nX = 3;
	m_oCaretPos.m_nY = 3;

	m_bCaretIsVisible = false;
	m_oCaretSize.m_nWidth = 1;
	m_oCaretSize.m_nHeight = 14;
	m_nCaretCharIndex = -1;

	m_bCaretIsShow = false;
	m_nCaretInterval = 500;

	m_nStartDrawCharIndex = 0;

	m_nFontSize = 12;
}

void CBEdit::SetDefaultString(const CAwsString& str)
{
	m_strText.SetData(str.GetStringData(), str.GetByteCount());
}

void CBEdit::ShowCaret()
{
	if ( !m_bCaretIsShow )
	{
		m_bCaretIsShow = true;
		StartTimer(m_nCaretInterval);
	}
}

void CBEdit::HideCaret()
{
	if ( m_bCaretIsShow )
	{
		m_bCaretIsShow = false;
		EndTimer();

		m_bCaretIsVisible = false;
		CEspRect rt;
		rt.m_ptLT = m_oCaretPos;
		rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_oCaretSize.m_nWidth;
		rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_oCaretSize.m_nHeight;
		InvalideRect(rt);
	}
}

void CBEdit::OnTimer()
{
	if ( m_bIsFocus && m_bCaretIsShow )
	{
		m_bCaretIsVisible = !m_bCaretIsVisible;

		CEspRect rt;
		rt.m_ptLT = m_oCaretPos;
		rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_oCaretSize.m_nWidth;
		rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_oCaretSize.m_nHeight;
		InvalideRect(rt);
	}
}

bool CBEdit::RightMoveOneChar()
{
	int nCount = m_strText.GetCharCount();
	if ( m_nCaretCharIndex < nCount - 1 )
	{
		CAwsString strSub;
		m_strText.GetSubString(strSub, m_nCaretCharIndex + 1, m_nCaretCharIndex + 2);

		// 获得字符的宽度
		IAwsGc* pGc = GetGc();
		m_oFont.CreateFont(0, m_nFontSize);
		pGc->UseFont(m_oFont);
		const CEspSize* size = pGc->GetTextSize(strSub);
		int nWidth = size->m_nWidth;

		// 确认移动
		m_oCaretPos.m_nX += nWidth;
		if ( m_oCaretPos.m_nX < GetSize()->m_nWidth - 2 )
		{
		}
		else
		{
			// 否则整体向左移动3个字符，改变
			CAwsString strSub;
			m_strText.GetSubString(strSub, m_nStartDrawCharIndex, m_nStartDrawCharIndex + 3);

			// 获得字符的宽度
			IAwsGc* pGc = GetGc();
			m_oFont.CreateFont(0, m_nFontSize);
			pGc->UseFont(m_oFont);
			const CEspSize* size = pGc->GetTextSize(strSub);
			int nWidth = size->m_nWidth;

			m_oCaretPos.m_nX -= nWidth;

			m_nStartDrawCharIndex += 3;
		}

		++m_nCaretCharIndex;

		return true;
	}

	return false;
}

bool CBEdit::LeftMoveOneChar()
{
	if ( m_nCaretCharIndex >= 0 )
	{
		CAwsString strSub;
		m_strText.GetSubString(strSub, m_nCaretCharIndex, m_nCaretCharIndex + 1);

		// 获得字符的宽度
		IAwsGc* pGc = GetGc();
		m_oFont.CreateFont(0, m_nFontSize);
		pGc->UseFont(m_oFont);
		const CEspSize* size = pGc->GetTextSize(strSub);
		int nWidth = size->m_nWidth;

		// 确认移动
		m_oCaretPos.m_nX -= nWidth;
		if ( m_oCaretPos.m_nX > 5 )
		{
		}
		else
		{
			// 否则整体向右移动3个字符，有可能少于3个字符
			CAwsString strSub;
			int nMoveCharCount = 3;
			int nStartIndex = m_nStartDrawCharIndex - 3;
			int nEndIndex = m_nStartDrawCharIndex;

			if ( nStartIndex < 0 )
			{
				nStartIndex = 0;
				nMoveCharCount = nEndIndex - nStartIndex;
			}

			m_strText.GetSubString(strSub, nStartIndex, nEndIndex);

			// 获得字符的宽度
			IAwsGc* pGc = GetGc();
			m_oFont.CreateFont(0, m_nFontSize);
			pGc->UseFont(m_oFont);
			const CEspSize* size = pGc->GetTextSize(strSub);
			int nWidth = size->m_nWidth;

			m_oCaretPos.m_nX += nWidth;

			m_nStartDrawCharIndex -= nMoveCharCount;
		}

		--m_nCaretCharIndex;

		return true;
	}

	return false;
}

void CBEdit::DeleteOneChar()
{
	// 删除一个字符
	int n = m_nCaretCharIndex;
	if ( LeftMoveOneChar())
	{
		if ( m_strText.RemoveChar(n) )
		{
			Invalide();
		}
	}
}

void CBEdit::OnImeChar(short nChar)
{
	// 插入字符到字符串
	if ( m_strText.AddChar(nChar, m_nCaretCharIndex + 1) )
	{
		// 插入符右移一个字符
		RightMoveOneChar();

		Invalide();
	}
}

void CBEdit::OnFocus(bool bIsFocus)
{
	CAwsWindow::OnFocus(bIsFocus);

	if ( m_bIsFocus )
	{
		// 激活输入法
		GetUi()->ActiveIME();

		// 显示插入符
		ShowCaret();
	}
	else
	{
		// 关闭输入法
		GetUi()->InactiveIME();

		// 隐藏插入符
		HideCaret();
	}

	Invalide();
}

bool CBEdit::OnKey(AWS_KeyType type, AWS_KeyCode code)
{
	if ( AWS_Key == type )
	{
		switch ( code )
		{
		case AWS_KeyCode_LeftArrow:
			if ( LeftMoveOneChar() )
				Invalide();
			return true;

		case AWS_KeyCode_RightArrow:
			if ( RightMoveOneChar() )
				Invalide();
			return true;

		case AWS_KeyCode_Delete:
			DeleteOneChar();
			return true;
		}
	}

	return CAwsWindow::OnKey(type, code);
}

void CBEdit::DrawBK(IAwsGc* pGc, const CEspRect& rect)
{
	pGc->SetPenColor(m_oBKColor);
	pGc->SetBrushColor(m_oBKColor);
	pGc->DrawFillRect(rect);
}

void CBEdit::OnDraw(const CEspRect& rect)
{
	IAwsGc* pGc = GetGc();
	CEspSize size = *GetSize();
	CEspRect rt, rtTemp;

	// 用背景填充区域
	DrawBK(pGc, rect);

	// 绘制边框
	if ( 0 == rect.m_ptLT.m_nX || 0 == rect.m_ptLT.m_nY || size.m_nWidth == rect.m_ptRB.m_nX || size.m_nHeight == rect.m_ptRB.m_nY )
	{
		if ( m_bIsFocus )
		{
			pGc->SetPenColor(m_oFocusBorderColor);
		}
		else
		{
			pGc->SetPenColor(m_oBorderColor);
		}
		CEspRect rtTemp(0, 0, size.m_nWidth, size.m_nHeight);
		pGc->DrawRect(rtTemp);
	}

	// 绘制文字
//	rt = rect;
	rt.m_ptLT.m_nX = 3;
	rt.m_ptLT.m_nY = 3;
	rt.m_ptRB.m_nX = size.m_nWidth - 2;
	rt.m_ptRB.m_nY = size.m_nHeight - 2;
	pGc->SetTextColor(m_oTextColor);
	pGc->SetTextAlignment(AWS_TAM_Left);
	m_oFont.CreateFont(0, m_nFontSize);
	pGc->UseFont(m_oFont);

//	CAwsString strSub;
	m_strDrawText.Reset();
	m_strText.GetSubString(m_strDrawText, m_nStartDrawCharIndex, -1);
	pGc->DrawText(m_strDrawText, rt);

	pGc->DiscardFont();

	// 绘制插入符
	rt.m_ptLT = m_oCaretPos;
	rt.m_ptRB.m_nX = rt.m_ptLT.m_nX + m_oCaretSize.m_nWidth;
	rt.m_ptRB.m_nY = rt.m_ptLT.m_nY + m_oCaretSize.m_nHeight;
	if ( rect.InterRect(rt, rtTemp) )
	{
		if ( m_bCaretIsVisible )
		{
			pGc->SetPenColor(m_oCaretColor);
			pGc->SetBrushColor(m_oCaretColor);

			pGc->DrawFillRect(rt);
		}
	}
}
