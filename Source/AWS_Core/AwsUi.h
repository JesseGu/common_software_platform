/******************************************************************************
* FileName		       : AwsUi.h
* Description          : interface for the CAwsUi class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _AWSUI_H__2009_10_09_
#define _AWSUI_H__2009_10_09_

#include "Aws.h"

class IAwsGc;
class CAwsWindow;
class CAwsContainer;
class CSpxApp;

enum
{
	MAX_TIMERDATA = 5,
	MAX_POSTCOMMAND = 10
};

class CAwsUi
{
public:
	CAwsUi(int nMaxTopWndCount = 3);
	virtual ~CAwsUi();

public:
	// 公共接口，用于目标平台调用，
	// 由子类重写，创建顶层窗口加入到Ui
	void Init(const CEspSize& sizeScreen);
	void SetApp(CSpxApp* pApp) { m_pApp = pApp; }

	// 当目标平台发生如下事件时调用这些函数
	void OnDraw(const CEspRect& rect);
	void OnKey(AWS_KeyType type, AWS_KeyCode code);
	void OnSize(const CEspSize& size, bool bIsRedraw = true);
	void OnFocus(bool bIsFocus);
	void OnTimer(int nTimerID);
	void OnImeChar(short nChar);

public:
	CSpxApp* GetApp() { return m_pApp; }

	// 获得屏幕大小
	CEspSize& GetScreenSize(){ return m_tScreenSize; }

	// 设置系统Gc
	void SetSysGc(IAwsGc* pGc){ m_pSysGc = pGc; }
	// 获取系统Gc
	IAwsGc* GetSysGc(){ return m_pSysGc; }

	// 获取当前顶层窗口
	CAwsWindow* GetCurTopWnd(){ return m_pCurTopWnd; }

	bool StartTimer(CAwsWindow* pWnd, int nTimes);
	void EndTimer(CAwsWindow* pWnd);

	void CommandRouter(int nWndID, int nCmdID, int nParam1, int nParam2);
	bool AddPostCommand(int nWndID, int nCmdID, int nParam1, int nParam2);

	// 在目标平台上实现
	virtual void ActiveIME() {}
	virtual void InactiveIME() {}
	virtual void ExitSys() {}

protected:
	// 在目标平台上实现
	virtual void Timer(int nTimerID, int nTime) {}
	virtual void KillTimer(int nTimerID) {}

public:
	bool AddWndToStack(CAwsWindow* pWnd);
	void RemoveWndFromStack(CAwsWindow* pWnd);
	void RemoveWndFromTopStack();
	void SetTopWnd(CAwsContainer* pWnd);

private:
	void PostCommandRouter();
	void ClearWnd(CAwsWindow* pWnd);

protected:
	CAwsWindow*		m_pCurTopWnd;		// 当前的顶层窗口
	CAwsWindow**	m_pTopWndData;		// 顶层窗口数据
	int				m_nCurTopWndCount;	// 当前窗口个数
	int				m_nMaxTopWndCount;	// 最大支持窗口个数

	// 有效屏幕的大小
	CEspSize	m_tScreenSize;

	// 用于绘制的系统GC
	IAwsGc*	m_pSysGc;

	// 定时器相关的数据
	struct TTimerData
	{
		CAwsWindow* m_pWnd;
		int			m_nTime;
	};
	TTimerData	m_tTimerData[MAX_TIMERDATA];

	// 命令数据
	struct TCommand
	{
		int m_nWndID;	// 发送消息的窗口句柄
		int m_nCmdID;	// 发送的命令
		int m_nParam1;	// 第一个参数
		int m_nParam2;	// 第二个参数
	};
	TCommand	m_tPostCommands[MAX_POSTCOMMAND];
	int			m_nCommandCount;

	// 应用程序类
	CSpxApp*	m_pApp;
};

#endif /* _AWSUI_H__2009_10_09_ */
