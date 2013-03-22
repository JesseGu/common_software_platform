/******************************************************************************
* FileName		       : AwsWindow.h
* Description          : interface for the CAwsWindow class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _AWSWINDOW_H__2009_10_09_
#define _AWSWINDOW_H__2009_10_09_

#include "Aws.h"

class CAwsUi;
class IAwsGc;

// 所有窗口的基类
class CAwsWindow
{
public:
	CAwsWindow();
	virtual ~CAwsWindow() {}

	// 创建窗口
	void Create(CAwsWindow* pParent, const CEspRect& rect, int nID = 0, bool bIsVisible = true);

	const CEspPoint& GetOrigin() { return m_tOrigin; }

	void SetUi(CAwsUi* pUi) { m_pUi = pUi; }
	CAwsUi* GetUi();

	const CEspRect& GetRect() { return m_tRect; }
	const CEspSize* GetSize() { return m_tRect.GetSize(); }

	CAwsWindow* GetParent() { return m_pParent; }

	bool IsVisible() { return m_bIsVisible; }

	int GetWndID() { return m_nWndID; }

	// 相对父窗口移动
	void MoveTo(const CEspRect& rect, bool bIsReDraw = true);

	void Invalide();
	virtual void InvalideRect(const CEspRect& rect);

	void SetVisible(bool bIsVisible, bool bIsReDraw = true);

	// 把相对父窗口的坐标转换坐标为相对自己窗口的坐标
	void ConvertCoordinate(CEspRect& rect);

	bool StartTimer(int nTimer);
	void EndTimer();

	// 产生命令消息，并立马执行该消息
	void PumpCommand(int nWndID, int nCmdID, int nParam1 = 0, int nParam2 = 0);
	// 产生消息，将消息存放在队列中，待下一时刻执行
	void PostCommand(int nWndID, int nCmdID, int nParam1 = 0, int nParam2 = 0);

	virtual CAwsWindow* GetFocusSubWnd() { return ESP_NULL; }

	void SetBKTransparent(bool bIsTransparent) { m_bIsBKTransparent = bIsTransparent; }

	void Draw(const CEspRect& rect);

public:
	virtual void OnDraw(const CEspRect& rect) {}
	virtual bool OnKey(AWS_KeyType type, AWS_KeyCode code) { return false; }
	virtual void OnSize(const CEspSize& size, bool bIsRedraw = true) {}
	virtual void OnFocus(bool bIsFocus);
	virtual void OnTimer() {}
	virtual void OnImeChar(short nChar) {}

	// 返回true表示已经处理了该消息，没有返回false表示没有处理该消息
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2) { return false; }

protected:
	// 在此做初始化工作
	virtual void OnCreate() {}

	IAwsGc* GetGc();

protected:
	CAwsWindow*	m_pParent;		// 父窗口
	IAwsGc*		m_pGc;			// GC
	CAwsUi*		m_pUi;			// Ui

	CEspRect	m_tRect;		// 相对父窗口的位置
	CEspPoint	m_tOrigin;		// 相对屏幕起始点的坐标原点

	int			m_nWndID;		// 窗口ID
	bool		m_bIsVisible;
	bool		m_bIsFocus;

	bool	m_bIsBKTransparent;	// 窗口是否透明
};

#endif /* _AWSWINDOW_H__2009_10_09_ */
