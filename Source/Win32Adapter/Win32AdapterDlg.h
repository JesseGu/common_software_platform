// AwsDemoDlg.h : header file
//

#if !defined(AFX_AWSDEMODLG_H__73C7DFF0_1ADA_4C8F_9211_C6A81E891018__INCLUDED_)
#define AFX_AWSDEMODLG_H__73C7DFF0_1ADA_4C8F_9211_C6A81E891018__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EScreen.h"
#include "EMyui.h"
#include "MyApp.h"
#include "Win32Os.h"

/////////////////////////////////////////////////////////////////////////////
// CAwsDemoDlg dialog

class CWin32AdapterDlg : public CDialog
{
// Construction
public:
	CWin32AdapterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAwsDemoDlg)
	enum { IDD = IDD_AWSDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAwsDemoDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	CEScreen	m_oEScreen;
	CEMyUi		m_oMyUi;
	CWin32Os	m_oOs;

	CMyApp		m_oApp;

	// Generated message map functions
	//{{AFX_MSG(CAwsDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLeftmenu();
	afx_msg void OnRightmenu();
	afx_msg void OnUp();
	afx_msg void OnLeft();
	afx_msg void OnButton4();
	afx_msg void OnRight();
	afx_msg void OnDown();
	afx_msg void OnOne();
	afx_msg void OnTwo();
	afx_msg void OnThree();
	afx_msg void OnFour();
	afx_msg void OnFive();
	afx_msg void OnSix();
	afx_msg void OnSeven();
	afx_msg void OnEight();
	afx_msg void OnNine();
	afx_msg void OnStar();
	afx_msg void OnZero();
	afx_msg void OnWell();
	afx_msg void OnEnter();
	//}}AFX_MSG
	afx_msg LRESULT OnScreenFocus(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AWSDEMODLG_H__73C7DFF0_1ADA_4C8F_9211_C6A81E891018__INCLUDED_)
