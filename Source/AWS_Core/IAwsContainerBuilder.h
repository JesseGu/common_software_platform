/******************************************************************************
* FileName		       : IAwsContainerBuilder.h
* Description          : interface of the IAwsContainerBuilder
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng(@NJUST)
* weibo http://weibo.com/gujicheng197
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _IAWSCONTROLLERBUILDER_H_2009_10_09_
#define _IAWSCONTROLLERBUILDER_H_2009_10_09_

class CAwsContainer;
class CAwsWindow;
class CEspRect;

class IAwsContainerBuilder
{
public:
	virtual CAwsContainer* Build(CAwsWindow* pParent, const CEspRect& rect) = 0;
};

#endif /* _IAWSCONTROLLERBUILDER_H_2009_10_09_ */
