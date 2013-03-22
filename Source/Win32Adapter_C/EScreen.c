
#include "StdAfx.h"
#include "EScreen.h"

CEScreen* g_pThis = NULL;

void CEScreen_CInit(CEScreen* pThis)
{
	CEWndGc_CInit(&pThis->m_oWndGc);

	pThis->m_pMyUi = NULL;
	pThis->m_hWnd = NULL;
	pThis->m_hInst = NULL;

	pThis->m_bIsFirstKeyDown = 1;
	pThis->m_bNoChar = 0;

	g_pThis = pThis;
}

void CEScreen_DUninit(CEScreen* pThis)
{
	CEWndGc_DUninit(&pThis->m_oWndGc);
}

void CEScreen_SetUi(CEScreen* pThis, CEMyUi* pMyUi)
{
	pThis->m_pMyUi = pMyUi;
	CEMyUi_SetScreen(pThis->m_pMyUi, pThis->m_hWnd);
}

int CEScreen_Create(CEScreen* pThis, LPCTSTR lpszWindowName, const RECT rect, HWND wndFather, HINSTANCE hInst)
{
	pThis->m_hInst = hInst;

	CEScreen_RegisterClass(pThis);

	// 创建窗口
	pThis->m_hWnd = CreateWindow("EScreen", "", WS_CHILDWINDOW | WS_VISIBLE | WS_OVERLAPPED | WS_CLIPCHILDREN,
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, wndFather, NULL, hInst, NULL);

	{
		HDC hDc = GetDC(pThis->m_hWnd);

		CEWndGc_SetDC(&pThis->m_oWndGc, hDc);
		CEWndGc_SetInst(&pThis->m_oWndGc, pThis->m_hInst);

		// 设置系统Gc
		CAwsUi_SetSysGc_IAwsGc1p(&pThis->m_pMyUi->m_oBaseAwsUi, &pThis->m_oWndGc.m_oBaseAwsGc);
	}

	return 1;
}

void CEScreen_OnPaint(CEScreen* pThis)
{
	PAINTSTRUCT ps;
	HDC hDC = BeginPaint(pThis->m_hWnd, &ps);
	RECT rt;
	RECT rect = { 0 };
	CEspRect ert;

	CEspRect_CInit(&ert);

	GetWindowRect(pThis->m_hWnd, &rt);
	rect.right = rt.right - rt.left;
	rect.bottom = rt.bottom - rt.top;

	SetBkColor(hDC, RGB(255, 255, 255));
	ExtTextOut(hDC, 0, 0, ETO_OPAQUE, &rect, NULL, 0, NULL);

	//	dc.SetROP2(R2_WHITE);
	ert.m_ptRB.m_nX = rect.right;
	ert.m_ptRB.m_nY = rect.bottom;

	CAwsUi_OnDraw_CEspRect1p(&pThis->m_pMyUi->m_oBaseAwsUi, &ert);

	EndPaint(pThis->m_hWnd, &ps);
}

void CEScreen_Key(CEScreen* pThis, AWS_KeyType type, AWS_KeyCode code)
{
	CAwsUi_OnKey_0p_0p(&pThis->m_pMyUi->m_oBaseAwsUi, type, code);
}

void CEScreen_OnSize(CEScreen* pThis, UINT nType, int cx, int cy)
{
	CEspSize size;
	size.m_nWidth = cx;
	size.m_nHeight = cy;

	CAwsUi_OnSize_CEspSize1p_i0p(&pThis->m_pMyUi->m_oBaseAwsUi, &size, 1);
}

void CEScreen_OnSetFocus(CEScreen* pThis, HWND hloseFocus)
{
	CAwsUi_OnFocus_i0p(&pThis->m_pMyUi->m_oBaseAwsUi, 1);
}

void CEScreen_OnKillFocus(CEScreen* pThis, HWND hGetFocus)
{
	CAwsUi_OnFocus_i0p(&pThis->m_pMyUi->m_oBaseAwsUi, 0);
}

void CEScreen_OnKeyDown(CEScreen* pThis, int nVirKey, int nKeyData)
{
	AWS_KeyCode code = AWS_KeyCode_Null;

	switch ( nVirKey )
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

	if ( nVirKey >= VK_NUMPAD0 && nVirKey <= VK_DIVIDE )
		pThis->m_bNoChar = 1;

	if ( AWS_KeyCode_Null != code )
	{
		if ( pThis->m_bIsFirstKeyDown )
		{
			CAwsUi_OnKey_0p_0p(&pThis->m_pMyUi->m_oBaseAwsUi, AWS_Key_Down, code);
			CAwsUi_OnKey_0p_0p(&pThis->m_pMyUi->m_oBaseAwsUi, AWS_Key, code);
			pThis->m_bIsFirstKeyDown = 0;
		}
		else
		{
			CAwsUi_OnKey_0p_0p(&pThis->m_pMyUi->m_oBaseAwsUi, AWS_Key, code);
		}
	}
}

void CEScreen_OnKeyUp(CEScreen* pThis, int nVirKey, int nKeyData)
{
	AWS_KeyCode code = AWS_KeyCode_Null;
	
	switch ( nVirKey )
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
	
	if ( AWS_KeyCode_Null != code )
	{
		CAwsUi_OnKey_0p_0p(&pThis->m_pMyUi->m_oBaseAwsUi, AWS_Key_Up, code);
		pThis->m_bIsFirstKeyDown = 1;
	}
}

void CEScreen_OnTimer(CEScreen* pThis, int nTimeEvent)
{
	CAwsUi_OnTimer_i0p(&pThis->m_pMyUi->m_oBaseAwsUi, nTimeEvent);
}

void CEScreen_OnImeChar(CEScreen* pThis, WPARAM wParam, LPARAM lParam)
{
	CAwsUi_OnImeChar_s0p(&pThis->m_pMyUi->m_oBaseAwsUi, (short)wParam);
}

void CEScreen_OnChar(CEScreen* pThis, int nCharCode, int nKeyData)
{
	if ( !pThis->m_bNoChar )
	{
		if ( nCharCode > VK_HELP )
			CAwsUi_OnImeChar_s0p(&pThis->m_pMyUi->m_oBaseAwsUi, (short)nCharCode);
	}
	else
	{
		pThis->m_bNoChar = 0;
	}
}

LRESULT CALLBACK CEScreen_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
//	HDC hdc;

	switch (message) 
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam); 
		wmEvent = HIWORD(wParam); 
		// Parse the menu selections:
		switch (wmId)
		{
//		case IDM_ABOUT:
//			DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
//			break;
//		case IDM_EXIT:
//			DestroyWindow(hWnd);
//			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	case WM_PAINT:
		CEScreen_OnPaint(g_pThis);
		break;

	case WM_SIZE:
		CEScreen_OnSize(g_pThis, wParam, LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_SETFOCUS:
		CEScreen_OnSetFocus(g_pThis, (HWND)wParam);
		break;

	case WM_KILLFOCUS:
//		CEScreen_OnKillFocus(g_pThis, (HWND)wParam);
		break;

	case WM_KEYDOWN:
		CEScreen_OnKeyDown(g_pThis, (int)wParam, (int)lParam);
		break;

	case WM_KEYUP:
		CEScreen_OnKeyUp(g_pThis, (int)wParam, (int)lParam);
		break;

	case WM_LBUTTONDOWN:
		SetFocus(g_pThis->m_hWnd);
		break;

	case WM_TIMER:
		CEScreen_OnTimer(g_pThis, (int)wParam);
		break;

	case WM_IME_CHAR:
		CEScreen_OnImeChar(g_pThis, wParam, lParam);
		break;

	case WM_CHAR:
		CEScreen_OnChar(g_pThis, (int)wParam, (int)lParam);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

ATOM CEScreen_RegisterClass(CEScreen* pThis)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_OWNDC | CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)CEScreen_WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= pThis->m_hInst;
	wcex.hIcon			= NULL;//LoadIcon(hInstance, (LPCTSTR)IDI_AWSDEMO_C);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_GRAYTEXT);
	wcex.lpszMenuName	= "";//(LPCSTR)IDC_AWSDEMO_C;
	wcex.lpszClassName	= "EScreen";
	wcex.hIconSm		= NULL;//LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}
