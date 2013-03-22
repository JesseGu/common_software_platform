#if !defined(AFX_ESCREEN_H__61DF794D_05EE_42EE_8363_131C91CB36FF__INCLUDED_)
#define AFX_ESCREEN_H__61DF794D_05EE_42EE_8363_131C91CB36FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EScreen.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEScreen window
#include "EWndGc.h"

class CEMyUi;

class CEScreen : public CWnd
{
// Construction
public:
	CEScreen();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEScreen)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:

	// Generated message map functions
protected:
	//{{AFX_MSG(CEScreen)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	afx_msg LRESULT OnImeChar(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL Create(LPCTSTR lpszWindowName, const RECT& rect, CWnd* pParentWnd);

	void Key(AWS_KeyType type, AWS_KeyCode code);

	void SetUi(CEMyUi* pMyUi);

protected:
	static BOOL RegisterClass();

protected:
	static CString	m_strClassName;

private:
	CEMyUi* m_pMyUi;
	CEWndGc m_oWndGc;

	bool	m_bIsFirstKeyDown;
	bool	m_bNoChar;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ESCREEN_H__61DF794D_05EE_42EE_8363_131C91CB36FF__INCLUDED_)
