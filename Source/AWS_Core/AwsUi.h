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
	// �����ӿڣ�����Ŀ��ƽ̨���ã�
	// ��������д���������㴰�ڼ��뵽Ui
	void Init(const CEspSize& sizeScreen);
	void SetApp(CSpxApp* pApp) { m_pApp = pApp; }

	// ��Ŀ��ƽ̨���������¼�ʱ������Щ����
	void OnDraw(const CEspRect& rect);
	void OnKey(AWS_KeyType type, AWS_KeyCode code);
	void OnSize(const CEspSize& size, bool bIsRedraw = true);
	void OnFocus(bool bIsFocus);
	void OnTimer(int nTimerID);
	void OnImeChar(short nChar);

public:
	CSpxApp* GetApp() { return m_pApp; }

	// �����Ļ��С
	CEspSize& GetScreenSize(){ return m_tScreenSize; }

	// ����ϵͳGc
	void SetSysGc(IAwsGc* pGc){ m_pSysGc = pGc; }
	// ��ȡϵͳGc
	IAwsGc* GetSysGc(){ return m_pSysGc; }

	// ��ȡ��ǰ���㴰��
	CAwsWindow* GetCurTopWnd(){ return m_pCurTopWnd; }

	bool StartTimer(CAwsWindow* pWnd, int nTimes);
	void EndTimer(CAwsWindow* pWnd);

	void CommandRouter(int nWndID, int nCmdID, int nParam1, int nParam2);
	bool AddPostCommand(int nWndID, int nCmdID, int nParam1, int nParam2);

	// ��Ŀ��ƽ̨��ʵ��
	virtual void ActiveIME() {}
	virtual void InactiveIME() {}
	virtual void ExitSys() {}

protected:
	// ��Ŀ��ƽ̨��ʵ��
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
	CAwsWindow*		m_pCurTopWnd;		// ��ǰ�Ķ��㴰��
	CAwsWindow**	m_pTopWndData;		// ���㴰������
	int				m_nCurTopWndCount;	// ��ǰ���ڸ���
	int				m_nMaxTopWndCount;	// ���֧�ִ��ڸ���

	// ��Ч��Ļ�Ĵ�С
	CEspSize	m_tScreenSize;

	// ���ڻ��Ƶ�ϵͳGC
	IAwsGc*	m_pSysGc;

	// ��ʱ����ص�����
	struct TTimerData
	{
		CAwsWindow* m_pWnd;
		int			m_nTime;
	};
	TTimerData	m_tTimerData[MAX_TIMERDATA];

	// ��������
	struct TCommand
	{
		int m_nWndID;	// ������Ϣ�Ĵ��ھ��
		int m_nCmdID;	// ���͵�����
		int m_nParam1;	// ��һ������
		int m_nParam2;	// �ڶ�������
	};
	TCommand	m_tPostCommands[MAX_POSTCOMMAND];
	int			m_nCommandCount;

	// Ӧ�ó�����
	CSpxApp*	m_pApp;
};

#endif /* _AWSUI_H__2009_10_09_ */
