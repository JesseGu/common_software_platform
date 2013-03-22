// AwsDemo_C.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

#include "EScreen.h"
#include "MyApp.h"
#include "EMyui.h"
#include "Win32Os.h"

#define MAX_LOADSTRING 100
#define UM_SETFOCUS (WM_USER + 100)

typedef struct tagCKeyButton CKeyButton;

typedef enum tagEButtonID EButtonID;
enum tagEButtonID
{
	BID_LeftMenu = 1,
	BID_RightMenu,
	BID_Left,
	BID_Right,
	BID_Up,
	BID_Down,
	BID_Enter,
	BID_Zero,
	BID_One,
	BID_Two,
	BID_Three,
	BID_Four,
	BID_Five,
	BID_Six,
	BID_Seven,
	BID_Eight,
	BID_Nine,
	BID_Star,
	BID_Well,
};

struct tagCKeyButton
{
	HWND	m_hLeftMenu;
	HWND	m_hRightMenu;
	HWND	m_hLeft;
	HWND	m_hRight;
	HWND	m_hUp;
	HWND	m_hDown;
	HWND	m_hEnter;
	HWND	m_hZero;
	HWND	m_hOne;
	HWND	m_hTwo;
	HWND	m_hThree;
	HWND	m_hFour;
	HWND	m_hFive;
	HWND	m_hSix;
	HWND	m_hSeven;
	HWND	m_hEight;
	HWND	m_hNine;
	HWND	m_hStar;
	HWND	m_hWell;
};


CKeyButton	g_oKeyButtons;

// Global Variables:
HINSTANCE g_hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

CEScreen	g_oEScreen;
CMyApp		g_oApp;
CEMyUi		g_oMyUi;
CWin32Os	g_oOs;

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// 调用屏幕的初始化函数
	CEScreen_CInit(&g_oEScreen);
	CMyApp_CInit(&g_oApp);
	CEMyUi_CInit(&g_oMyUi);
	CWin32Os_CInit(&g_oOs);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_AWSDEMO_C, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_AWSDEMO_C);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	CWin32Os_DUninit(&g_oOs);
	CEMyUi_DUninit(&g_oMyUi.m_oBaseAwsUi, NULL);
	CMyApp_DUninit_i1p(&g_oApp.m_oBase_CSpxApp, NULL);
	CEScreen_DUninit(&g_oEScreen);

	return msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_AWSDEMO_C);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW);
	wcex.lpszMenuName	= NULL;//(LPCSTR)IDC_AWSDEMO_C;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   g_hInst = hInstance;

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
      300, 100, 320, 621, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void OnCreate(HWND hWnd)
{
	RECT rt, rect;
	CEspSize sizeScreen;
	CEScreen_SetUi(&g_oEScreen, &g_oMyUi);

	// 创建屏幕
	rt.left = 38;
	rt.top = 20;
	rt.right = rt.left + 240;
	rt.bottom = rt.top + 320;
	CEScreen_Create(&g_oEScreen, "", rt, hWnd, g_hInst);

	CEMyUi_SetScreen(&g_oMyUi, g_oEScreen.m_hWnd);

	rect = rt;
	rect.left = rect.top = 0;
	rect.right = rt.right - rt.left;
	rect.bottom = rt.bottom - rt.top;

	sizeScreen.m_nWidth = rect.right;
	sizeScreen.m_nHeight = rect.bottom;

	CAwsUi_Init_CEspSize1p(&g_oMyUi.m_oBaseAwsUi, &sizeScreen);
	CSpxApp_Init_CAwsUi1p_COs1p(&g_oApp.m_oBase_CSpxApp, &g_oMyUi.m_oBaseAwsUi, &g_oOs.m_oBase_Os);


	// 创建按键
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "左菜单", WS_CHILD | WS_VISIBLE, 48, 350, 60, 20, hWnd, (HMENU)BID_LeftMenu, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "右菜单", WS_CHILD | WS_VISIBLE, 205, 350, 60, 20, hWnd, (HMENU)BID_RightMenu, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "上", WS_CHILD | WS_VISIBLE, 125, 360, 60, 20, hWnd, (HMENU)BID_Up, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "确认", WS_CHILD | WS_VISIBLE, 125, 390, 60, 20, hWnd, (HMENU)BID_Enter, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "下", WS_CHILD | WS_VISIBLE, 125, 420, 60, 20, hWnd, (HMENU)BID_Down, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "左", WS_CHILD | WS_VISIBLE, 55, 390, 60, 20, hWnd, (HMENU)BID_Left, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "右", WS_CHILD | WS_VISIBLE, 195, 390, 60, 20, hWnd, (HMENU)BID_Right, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "1", WS_CHILD | WS_VISIBLE, 48, 455, 60, 20, hWnd, (HMENU)BID_One, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "2", WS_CHILD | WS_VISIBLE, 125, 455, 60, 20, hWnd, (HMENU)BID_Two, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "3", WS_CHILD | WS_VISIBLE, 200, 455, 60, 20, hWnd, (HMENU)BID_Three, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "4", WS_CHILD | WS_VISIBLE, 48, 485, 60, 20, hWnd, (HMENU)BID_Four, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "5", WS_CHILD | WS_VISIBLE, 125, 485, 60, 20, hWnd, (HMENU)BID_Five, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "6", WS_CHILD | WS_VISIBLE, 200, 485, 60, 20, hWnd, (HMENU)BID_Six, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "7", WS_CHILD | WS_VISIBLE, 48, 515, 60, 20, hWnd, (HMENU)BID_Seven, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "8", WS_CHILD | WS_VISIBLE, 125, 515, 60, 20, hWnd, (HMENU)BID_Eight, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "9", WS_CHILD | WS_VISIBLE, 200, 515, 60, 20, hWnd, (HMENU)BID_Nine, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "*", WS_CHILD | WS_VISIBLE, 48, 545, 60, 20, hWnd, (HMENU)BID_Star, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "0", WS_CHILD | WS_VISIBLE, 125, 545, 60, 20, hWnd, (HMENU)BID_Zero, g_hInst, NULL);
	g_oKeyButtons.m_hLeftMenu = CreateWindow("button", "#", WS_CHILD | WS_VISIBLE, 200, 545, 60, 20, hWnd, (HMENU)BID_Well, g_hInst, NULL);

	PostMessage(hWnd, UM_SETFOCUS, 0, 0);
}

void OnCommand(int nCmd)
{
	switch ( nCmd )
	{
	case BID_LeftMenu:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_LeftMenu);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_LeftMenu);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_LeftMenu);
		break;
	case BID_RightMenu:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_RightMenu);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_RightMenu);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_RightMenu);
		break;
	case BID_Left:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_LeftArrow);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_LeftArrow);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_LeftArrow);
		break;
	case BID_Right:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_RightArrow);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_RightArrow);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_RightArrow);
		break;
	case BID_Up:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_UpArrow);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_UpArrow);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_UpArrow);
		break;
	case BID_Down:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_DownArrow);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_DownArrow);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_DownArrow);
		break;
	case BID_Enter:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_OK);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_OK);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_OK);
		break;
	case BID_Zero:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_0);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_0);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_0);
		break;
	case BID_One:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_1);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_1);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_1);
		break;
	case BID_Two:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_2);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_2);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_2);
		break;
	case BID_Three:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_3);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_3);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_3);
		break;
	case BID_Four:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_4);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_4);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_4);
		break;
	case BID_Five:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_5);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_5);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_5);
		break;
	case BID_Six:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_6);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_6);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_6);
		break;
	case BID_Seven:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_7);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_7);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_7);
		break;
	case BID_Eight:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_8);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_8);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_8);
		break;
	case BID_Nine:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_9);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_9);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_9);
		break;
	case BID_Star:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_Star);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_Star);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_Star);
		break;
	case BID_Well:
		CEScreen_Key(&g_oEScreen, AWS_Key_Down, AWS_KeyCode_Well);
		CEScreen_Key(&g_oEScreen, AWS_Key, AWS_KeyCode_Well);
		CEScreen_Key(&g_oEScreen, AWS_Key_Up, AWS_KeyCode_Well);
		break;
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(g_hInst, IDS_HELLO, szHello, MAX_LOADSTRING);

	switch (message) 
	{
	case WM_CREATE:
		OnCreate(hWnd);
		break;

	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		OnCommand(wmId);

		switch (wmId)
		{
			case IDM_ABOUT:
			   DialogBox(g_hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
			   break;
			case IDM_EXIT:
			   DestroyWindow(hWnd);
			   break;
			default:
			   return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;

	case UM_SETFOCUS:
		SetFocus(g_oEScreen.m_hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
			return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}

    return FALSE;
}
