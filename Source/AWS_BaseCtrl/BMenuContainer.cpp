/******************************************************************************
* FileName		       : BMenuContainer.cpp
* Description          : implementation of the CBMenuContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2011-03-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#include "BMenuContainer.h"

CBMenuContainer::CBMenuContainer(int nMaxSubWndCount) : CAwsContainer(nMaxSubWndCount)
{
}

bool CBMenuContainer::OnCommand(int nWndID, int nCmdID, int nParam1, int nParam2)
{
	bool bRet = true;

	switch ( nCmdID )
	{
	case AWS_SysCmd_PopMenu:
		PopMenu(nParam1, *((CEspPoint*)nParam2));
		break;

	default:
		bRet = false;
	}
	
	return bRet;
}
