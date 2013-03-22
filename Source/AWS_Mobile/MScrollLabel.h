/******************************************************************************
* FileName		       : MScrollLabel.h
* Description          : interface for the CMScrollLabel class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _MSCROLLLABEL_H_2009_10_09_
#define _MSCROLLLABEL_H_2009_10_09_

#include "BLabel.h"

class CMScrollLabel : public CBLabel
{
public:
	CMScrollLabel();

	void StartScroll(int nCount);
	void EndScroll();

	void SetTimers(int nTimers) { m_nTimes = nTimers; }

	bool IsStartScroll() { return m_nScrollCount > 0 ? true : false; }

public:
	virtual void OnTimer();

protected:
	virtual void OnCreate();

protected:
	virtual void DrawText(IAwsGc* pGc, const CEspRect& rect);

protected:
	int		m_nScrollCount;	// һ���������Ĵ���
	int		m_nCurCount;	// ��ǰ�����Ĵ���

	int		m_nMoveLength;	// �Ѿ��ƶ��ĳ��ȣ���Ϊ��ֵ
	int		m_nMoveStep;	// �ƶ�һ���ĳ���
	int		m_nTextLen;		// �ı�����

	CEspSize	m_oSizeWnd;

	int		m_nTimes;
};

#endif /* _MSCROLLLABEL_H_2009_10_09_ */
