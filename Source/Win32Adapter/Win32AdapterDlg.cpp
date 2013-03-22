// AwsDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Win32Adapter.h"
#include "Win32AdapterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

#define UM_SETFOCUS (WM_USER + 100)


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAwsDemoDlg dialog

CWin32AdapterDlg::CWin32AdapterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWin32AdapterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAwsDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWin32AdapterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAwsDemoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWin32AdapterDlg, CDialog)
	//{{AFX_MSG_MAP(CAwsDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_LEFTMENU, OnLeftmenu)
	ON_BN_CLICKED(IDC_RIGHTMENU, OnRightmenu)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_LEFT, OnLeft)
//	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_RIGHT, OnRight)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_ONE, OnOne)
	ON_BN_CLICKED(IDC_TWO, OnTwo)
	ON_BN_CLICKED(IDC_THREE, OnThree)
	ON_BN_CLICKED(IDC_FOUR, OnFour)
	ON_BN_CLICKED(IDC_FIVE, OnFive)
	ON_BN_CLICKED(IDC_SIX, OnSix)
	ON_BN_CLICKED(IDC_SEVEN, OnSeven)
	ON_BN_CLICKED(IDC_EIGHT, OnEight)
	ON_BN_CLICKED(IDC_NINE, OnNine)
	ON_BN_CLICKED(IDC_STAR, OnStar)
	ON_BN_CLICKED(IDC_ZERO, OnZero)
	ON_BN_CLICKED(IDC_WELL, OnWell)
	ON_BN_CLICKED(IDC_ENTER, OnEnter)
	//}}AFX_MSG_MAP
	ON_MESSAGE(UM_SETFOCUS, OnScreenFocus)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAwsDemoDlg message handlers

LRESULT CWin32AdapterDlg::OnScreenFocus(WPARAM wParam, LPARAM lParam)
{
	m_oEScreen.SetFocus();
	return 0;
}

BOOL CWin32AdapterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	AfxGetInstanceHandle();

	m_oEScreen.SetUi(&m_oMyUi);

	RECT rt;
	rt.left = 38;
	rt.top = 20;
	rt.right = rt.left + 240;
	rt.bottom = rt.top + 320;
	BOOL bRet = m_oEScreen.Create(_T(""), rt, this);

	RECT rect = rt;
	rect.left = rect.top = 0;
	rect.right = rt.right - rt.left;
	rect.bottom = rt.bottom - rt.top;

	// 在此调用初始化代码
	CEspSize sizeScreen;
	sizeScreen.m_nWidth = rect.right;
	sizeScreen.m_nHeight = rect.bottom;

	m_oMyUi.Init(sizeScreen);
	m_oApp.Init(&m_oMyUi, &m_oOs);

	PostMessage(UM_SETFOCUS);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWin32AdapterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWin32AdapterDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWin32AdapterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWin32AdapterDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	

	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CWin32AdapterDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	/*
	CDC* pDc = GetDC();

	pDc->Rectangle(CRect(250, 10, 250, 14));

	CPen	m_oPen;
	CBrush	m_oBrush;
	m_oPen.DeleteObject();
	m_oPen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	pDc->SelectObject(m_oPen);
	m_oBrush.DeleteObject();
	m_oBrush.CreateSolidBrush(RGB(255, 0, 0));
	pDc->SelectObject(m_oBrush);
//	pDc->Ellipse(CRect(250, 10, 270, 30));

	m_oBitMap.LoadBitmap(IDB_MAINMASK);
	m_oMemDC.CreateCompatibleDC(pDc);
	m_oMemDC.SelectObject(&m_oBitMap);
	pDc->BitBlt(300, 20, 40, 40, &m_oMemDC, 0, 0, MERGEPAINT);

	m_oBitMap1.LoadBitmap(IDB_MAIN1);
	m_oMemDC1.CreateCompatibleDC(pDc);
	m_oMemDC1.SelectObject(&m_oBitMap1);
	m_oMemDC1.BitBlt(0, 0, 40, 40, &m_oMemDC, 0, 0, SRCPAINT);

	pDc->BitBlt(300, 20, 40, 40, &m_oMemDC1, 0, 0, SRCAND);

	m_oMemDC.DeleteDC();
	m_oMemDC1.DeleteDC();
	m_oBitMap.DeleteObject();
	m_oBitMap1.DeleteObject();
*/
	CDialog::OnLButtonDown(nFlags, point);
}

void CWin32AdapterDlg::OnLeftmenu() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_LeftMenu);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_LeftMenu);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_LeftMenu);
}

void CWin32AdapterDlg::OnRightmenu() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_RightMenu);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_RightMenu);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_RightMenu);
}

void CWin32AdapterDlg::OnUp() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_UpArrow);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_UpArrow);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_UpArrow);
}

void CWin32AdapterDlg::OnDown() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_DownArrow);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_DownArrow);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_DownArrow);
}

void CWin32AdapterDlg::OnLeft() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_LeftArrow);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_LeftArrow);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_LeftArrow);
}

void CWin32AdapterDlg::OnRight() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_RightArrow);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_RightArrow);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_RightArrow);
}

void CWin32AdapterDlg::OnEnter() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_OK);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_OK);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_OK);
}

void CWin32AdapterDlg::OnOne() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_1);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_1);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_1);
}

void CWin32AdapterDlg::OnTwo() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_2);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_2);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_2);
}

void CWin32AdapterDlg::OnThree() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_3);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_3);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_3);
}

void CWin32AdapterDlg::OnFour() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_4);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_4);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_4);
}

void CWin32AdapterDlg::OnFive() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_5);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_5);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_5);
}

void CWin32AdapterDlg::OnSix() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_6);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_6);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_6);
}

void CWin32AdapterDlg::OnSeven() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_7);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_7);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_7);
}

void CWin32AdapterDlg::OnEight() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_8);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_8);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_8);
}

void CWin32AdapterDlg::OnNine() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_9);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_9);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_9);
}

void CWin32AdapterDlg::OnStar() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_Star);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_Star);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_Star);
}

void CWin32AdapterDlg::OnZero() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_0);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_0);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_0);
}

void CWin32AdapterDlg::OnWell() 
{
	// TODO: Add your control notification handler code here

	m_oEScreen.Key(AWS_Key_Down, AWS_KeyCode_Well);
	m_oEScreen.Key(AWS_Key, AWS_KeyCode_Well);
	m_oEScreen.Key(AWS_Key_Up, AWS_KeyCode_Well);
}

BOOL CWin32AdapterDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class

	if ( pMsg->message == WM_KEYDOWN )
	{
		if ( pMsg->wParam == '\r' || pMsg->wParam == VK_TAB || pMsg->wParam == VK_LEFT || pMsg->wParam == VK_RIGHT || pMsg->wParam == VK_UP || pMsg->wParam == VK_DOWN )
		{
			// 禁止回车退出
			return true;
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}
