// EScreen.cpp : implementation file
//

#include "stdafx.h"

#include "EScreen.h"
#include "EMyui.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include <Winuser.h>
/////////////////////////////////////////////////////////////////////////////
// CEScreen

CEScreen::CEScreen()
{
	m_pMyUi = NULL;
	m_bIsFirstKeyDown = true;
	m_bNoChar = false;
}

BEGIN_MESSAGE_MAP(CEScreen, CWnd)
	//{{AFX_MSG_MAP(CEScreen)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_IME_CHAR, OnImeChar)
END_MESSAGE_MAP()

CString CEScreen::m_strClassName = _T("");

BOOL CEScreen::RegisterClass()
{
	if ( _T("") == m_strClassName )
	{
		m_strClassName = AfxRegisterWndClass(CS_OWNDC | CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW);
		if ( _T("") == m_strClassName )
		{
			return FALSE;
		}
	}

	return TRUE;
}

void CEScreen::SetUi(CEMyUi* pMyUi)
{
	m_pMyUi = pMyUi;
	m_pMyUi->SetScreen(this);
}

BOOL CEScreen::Create(LPCTSTR lpszWindowName, const RECT& rect, CWnd* pParentWnd)
{
	if ( !RegisterClass() )
	{
		return FALSE;
	}

	BOOL bRet = CWnd::CreateEx(0, m_strClassName, lpszWindowName, WS_CHILDWINDOW | WS_VISIBLE | WS_OVERLAPPED | WS_CLIPCHILDREN, 
		rect, pParentWnd, 0, NULL);

	CDC* pDc = GetDC();
	m_oWndGc.SetDC(pDc);

	// ÉèÖÃÏµÍ³Gc
	m_pMyUi->SetSysGc(&m_oWndGc);

	return bRet;
}

void CEScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here

	// Do not call CWnd::OnPaint() for painting messages
	RECT rt;
	GetWindowRect(&rt);
	RECT rect = { 0 };
	rect.right = rt.right - rt.left;
	rect.bottom = rt.bottom - rt.top;

	dc.FillSolidRect(&rect, RGB(255, 255, 255));
//	dc.SetROP2(R2_WHITE);
	CEspRect ert;
	ert.m_ptRB.m_nX = rect.right;
	ert.m_ptRB.m_nY = rect.bottom;

	TRACE0("screen paint\n");
	m_pMyUi->OnDraw(ert);
}

void CEScreen::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	CEspSize size;
	size.m_nWidth = cx;
	size.m_nHeight = cy;
	if ( NULL != m_pMyUi )
		m_pMyUi->OnSize(size);
}

void CEScreen::Key(AWS_KeyType type, AWS_KeyCode code)
{
	if ( NULL != m_pMyUi )
		m_pMyUi->OnKey(type, code);
}

void CEScreen::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default

	AWS_KeyCode code = AWS_KeyCode_Null;

	switch ( nChar )
	{
	case VK_BACK:
		code = AWS_KeyCode_Delete;
		break;

	case '0':
		code = AWS_KeyCode_0;
		break;

	case '1':
		code = AWS_KeyCode_1;
		break;

	case '2':
		code = AWS_KeyCode_2;
		break;

	case '3':
		code = AWS_KeyCode_3;
		break;

	case '4':
		code = AWS_KeyCode_4;
		break;

	case '5':
		code = AWS_KeyCode_5;
		break;

	case '6':
		code = AWS_KeyCode_6;
		break;

	case '7':
		code = AWS_KeyCode_7;
		break;

	case '8':
		code = AWS_KeyCode_8;
		break;

	case '9':
		code = AWS_KeyCode_9;
		break;

	case VK_NUMPAD0:
		break;

	case VK_NUMPAD1:
		break;

	case VK_NUMPAD2:
		code = AWS_KeyCode_DownArrow;
		break;

	case VK_NUMPAD3:
		break;

	case VK_NUMPAD4:
		code = AWS_KeyCode_LeftArrow;
		break;

	case VK_NUMPAD5:
		code = AWS_KeyCode_OK;
		break;

	case VK_NUMPAD6:
		code = AWS_KeyCode_RightArrow;
		break;

	case VK_NUMPAD7:
		code = AWS_KeyCode_LeftMenu;
		break;

	case VK_NUMPAD8:
		code = AWS_KeyCode_UpArrow;
		break;

	case VK_NUMPAD9:
		code = AWS_KeyCode_RightMenu;
		break;

	case VK_DECIMAL:
		code = AWS_KeyCode_Delete;
		break;
	}

	if ( nChar >= VK_NUMPAD0 && nChar <= VK_DIVIDE )
		m_bNoChar = true;

	if ( AWS_KeyCode_Null != code && NULL != m_pMyUi )
	{
		if ( m_bIsFirstKeyDown )
		{
			m_pMyUi->OnKey(AWS_Key_Down, code);
			m_pMyUi->OnKey(AWS_Key, code);
			m_bIsFirstKeyDown = false;
		}
		else
		{
			m_pMyUi->OnKey(AWS_Key, code);
		}
	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CEScreen::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default

	AWS_KeyCode code = AWS_KeyCode_Null;

	switch ( nChar )
	{
	case VK_BACK:
		code = AWS_KeyCode_Delete;
		break;
		
	case '0':
		code = AWS_KeyCode_0;
		break;

	case '1':
		code = AWS_KeyCode_1;
		break;

	case '2':
		code = AWS_KeyCode_2;
		break;

	case '3':
		code = AWS_KeyCode_3;
		break;

	case '4':
		code = AWS_KeyCode_4;
		break;

	case '5':
		code = AWS_KeyCode_5;
		break;

	case '6':
		code = AWS_KeyCode_6;
		break;

	case '7':
		code = AWS_KeyCode_7;
		break;

	case '8':
		code = AWS_KeyCode_8;
		break;

	case '9':
		code = AWS_KeyCode_9;
		break;

	case VK_NUMPAD2:
		code = AWS_KeyCode_DownArrow;
		break;

	case VK_NUMPAD4:
		code = AWS_KeyCode_LeftArrow;
		break;

	case VK_NUMPAD5:
		code = AWS_KeyCode_OK;
		break;

	case VK_NUMPAD6:
		code = AWS_KeyCode_RightArrow;
		break;

	case VK_NUMPAD7:
		code = AWS_KeyCode_LeftMenu;
		break;

	case VK_NUMPAD8:
		code = AWS_KeyCode_UpArrow;
		break;

	case VK_NUMPAD9:
		code = AWS_KeyCode_RightMenu;
		break;

	case VK_DECIMAL:
		code = AWS_KeyCode_Delete;
		break;
	}

	if ( AWS_KeyCode_Null != code && NULL != m_pMyUi )
	{
		m_pMyUi->OnKey(AWS_Key_Up, code);
		m_bIsFirstKeyDown = true;
	}

	CWnd::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CEScreen::OnSetFocus(CWnd* pOldWnd) 
{
	CWnd::OnSetFocus(pOldWnd);

	// TODO: Add your message handler code here
	TRACE("Screen On Focus\r\n");
	if ( NULL != m_pMyUi )
		m_pMyUi->OnFocus(true);
}

void CEScreen::OnKillFocus(CWnd* pNewWnd) 
{
	CWnd::OnKillFocus(pNewWnd);

	// TODO: Add your message handler code here

	TRACE("Screen Kill Focus\r\n");
//	m_pMyUi->OnFocus(false);
}

void CEScreen::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetFocus();

	CWnd::OnLButtonDown(nFlags, point);
}

void CEScreen::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CWnd::OnLButtonUp(nFlags, point);
}

void CEScreen::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	if ( NULL != m_pMyUi )
		m_pMyUi->OnTimer(nIDEvent);

	CWnd::OnTimer(nIDEvent);
}

LRESULT CEScreen::OnImeChar(WPARAM wParam, LPARAM lParam)
{
	if ( NULL != m_pMyUi )
		m_pMyUi->OnImeChar((short)wParam);

	return 1;
}

void CEScreen::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default	

	if ( !m_bNoChar )
	{
		if ( nChar > VK_HELP && NULL != m_pMyUi )
			m_pMyUi->OnImeChar(nChar);
	}
	else
	{
		m_bNoChar = false;
	}
	CWnd::OnChar(nChar, nRepCnt, nFlags);
}

BOOL CEScreen::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class

	if ( pMsg->message == WM_CHAR )
	{
		OnChar(pMsg->wParam, 1, 0);
	}

	return CWnd::PreTranslateMessage(pMsg);
}
