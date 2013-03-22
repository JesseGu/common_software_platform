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

// ���д��ڵĻ���
class CAwsWindow
{
public:
	CAwsWindow();
	virtual ~CAwsWindow() {}

	// ��������
	void Create(CAwsWindow* pParent, const CEspRect& rect, int nID = 0, bool bIsVisible = true);

	const CEspPoint& GetOrigin() { return m_tOrigin; }

	void SetUi(CAwsUi* pUi) { m_pUi = pUi; }
	CAwsUi* GetUi();

	const CEspRect& GetRect() { return m_tRect; }
	const CEspSize* GetSize() { return m_tRect.GetSize(); }

	CAwsWindow* GetParent() { return m_pParent; }

	bool IsVisible() { return m_bIsVisible; }

	int GetWndID() { return m_nWndID; }

	// ��Ը������ƶ�
	void MoveTo(const CEspRect& rect, bool bIsReDraw = true);

	void Invalide();
	virtual void InvalideRect(const CEspRect& rect);

	void SetVisible(bool bIsVisible, bool bIsReDraw = true);

	// ����Ը����ڵ�����ת������Ϊ����Լ����ڵ�����
	void ConvertCoordinate(CEspRect& rect);

	bool StartTimer(int nTimer);
	void EndTimer();

	// ����������Ϣ��������ִ�и���Ϣ
	void PumpCommand(int nWndID, int nCmdID, int nParam1 = 0, int nParam2 = 0);
	// ������Ϣ������Ϣ����ڶ����У�����һʱ��ִ��
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

	// ����true��ʾ�Ѿ������˸���Ϣ��û�з���false��ʾû�д������Ϣ
	virtual bool OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2) { return false; }

protected:
	// �ڴ�����ʼ������
	virtual void OnCreate() {}

	IAwsGc* GetGc();

protected:
	CAwsWindow*	m_pParent;		// ������
	IAwsGc*		m_pGc;			// GC
	CAwsUi*		m_pUi;			// Ui

	CEspRect	m_tRect;		// ��Ը����ڵ�λ��
	CEspPoint	m_tOrigin;		// �����Ļ��ʼ�������ԭ��

	int			m_nWndID;		// ����ID
	bool		m_bIsVisible;
	bool		m_bIsFocus;

	bool	m_bIsBKTransparent;	// �����Ƿ�͸��
};

#endif /* _AWSWINDOW_H__2009_10_09_ */
