/******************************************************************************
* FileName		       : AwsContainer.h
* Description          : interface for the CAwsContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _AWSCONTAINER_H__2009_10_09_
#define _AWSCONTAINER_H__2009_10_09_

#include "AwsWindow.h"

// 所有容器窗口的基类
class CAwsContainer : public CAwsWindow
{
public:
	CAwsContainer(int nMaxSubWndCount = 10);
	virtual ~CAwsContainer();

	// 弹出式窗口处理
	void PopWnd(CAwsWindow* pWnd, const CEspRect& rect, int nWndID = 0);
	// 删除弹出式窗口
	void DestroyPopWnd(int nCount = 1);

	virtual CAwsWindow* GetFocusSubWnd() { return m_pFocusWnd; }

	CAwsWindow* GetWndFromID(int nWndID);

	void SetFocus(CAwsWindow* pSubWnd);

	// 删除一般窗口
	void DeleteWindow(CAwsWindow* pWnd, bool bIsRedraw = true);

public:
	virtual void OnDraw(const CEspRect& rect);
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code);
	virtual void OnSize(const CEspSize& size, bool bIsRedraw = true);
	virtual void OnFocus(bool bIsFocus);
	virtual void OnTimer();
	virtual void OnImeChar(short nChar);

protected:
	virtual void OnCreate();

protected:
	// 子控件处理
	bool AddSubWnd(CAwsWindow* pWnd, bool bIsNeedFocus = false);
	void PreFocusWnd();
	void NextFocusWnd();

protected:
	// 所有子窗口的记录
	CAwsWindow**	m_pSubWndData;
	int				m_nSubWndCount;
	int				m_nMaxSubWndCount;

	// Focus窗口用于记录子窗口获得Focus的顺序，默认最后加入的窗口获得当前Focus
	CAwsWindow**	m_pFocusWndData;
	int				m_nFocusWndCount;
	int				m_nFocusWndIndex;
	CAwsWindow*		m_pFocusWnd;

	// 弹出式窗口个数
	int				m_nPopWndCount;
};

#endif /* _AWSCONTAINER_H__2009_10_09_ */
