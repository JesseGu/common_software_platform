/******************************************************************************
* FileName		       : BScrollBar.h
* Description          : interface for the CBScrollBar class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BSCROLLBAR_H_2009_10_09_
#define _BSCROLLBAR_H_2009_10_09_

#include "AwsWindow.h"

// �������ķ���
enum ESBDir
{
	ESB_Vertical,
	ESB_Horizontal
};

class CBScrollBar : public CAwsWindow
{
public:
	CBScrollBar();

	void SetDirection(ESBDir dir)
	{
		m_eDir = dir;
	}

	void SetTotalLength(int nTotal);
	void SetCurPos(int nCur);

public:
	virtual void OnDraw(const CEspRect& rect);

protected:
	virtual void DrawBK(IAwsGc* pGc, const CEspRect& rect);
	virtual void DrawBlock(IAwsGc* pGc, const CEspRect& rect);

protected:
	ESBDir	m_eDir;

	int		m_nTotalLength;		// �ܹ�����
	int		m_nCurPos;			// ��ǰ����λ��

	int		m_nMinBlockDim;		// ������С�ߴ�
	int		m_nCurBlockDim;		// ��ǰ����ߴ�
	int		m_nMaxScrolldis;	// ���һ�λ�������
	float	m_fCurScrolldis;	// ��ǰһ�λ�������

	CAwsRgb	m_oBlockColor;
	CAwsRgb	m_oBKColor;
};

#endif /* _BSCROLLBAR_H_2009_10_09_ */
