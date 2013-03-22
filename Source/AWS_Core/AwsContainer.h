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

// �����������ڵĻ���
class CAwsContainer : public CAwsWindow
{
public:
	CAwsContainer(int nMaxSubWndCount = 10);
	virtual ~CAwsContainer();

	// ����ʽ���ڴ���
	void PopWnd(CAwsWindow* pWnd, const CEspRect& rect, int nWndID = 0);
	// ɾ������ʽ����
	void DestroyPopWnd(int nCount = 1);

	virtual CAwsWindow* GetFocusSubWnd() { return m_pFocusWnd; }

	CAwsWindow* GetWndFromID(int nWndID);

	void SetFocus(CAwsWindow* pSubWnd);

	// ɾ��һ�㴰��
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
	// �ӿؼ�����
	bool AddSubWnd(CAwsWindow* pWnd, bool bIsNeedFocus = false);
	void PreFocusWnd();
	void NextFocusWnd();

protected:
	// �����Ӵ��ڵļ�¼
	CAwsWindow**	m_pSubWndData;
	int				m_nSubWndCount;
	int				m_nMaxSubWndCount;

	// Focus�������ڼ�¼�Ӵ��ڻ��Focus��˳��Ĭ��������Ĵ��ڻ�õ�ǰFocus
	CAwsWindow**	m_pFocusWndData;
	int				m_nFocusWndCount;
	int				m_nFocusWndIndex;
	CAwsWindow*		m_pFocusWnd;

	// ����ʽ���ڸ���
	int				m_nPopWndCount;
};

#endif /* _AWSCONTAINER_H__2009_10_09_ */
