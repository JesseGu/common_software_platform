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

// 滚动条的方向
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

	int		m_nTotalLength;		// 总共滑距
	int		m_nCurPos;			// 当前所处位置

	int		m_nMinBlockDim;		// 滑块最小尺寸
	int		m_nCurBlockDim;		// 当前滑块尺寸
	int		m_nMaxScrolldis;	// 最大一次滑动距离
	float	m_fCurScrolldis;	// 当前一次滑动距离

	CAwsRgb	m_oBlockColor;
	CAwsRgb	m_oBKColor;
};

#endif /* _BSCROLLBAR_H_2009_10_09_ */
