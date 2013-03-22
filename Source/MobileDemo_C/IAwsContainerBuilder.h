/******************************************************************************
* FileName		       : IAwsContainerBuilder.h
* Description          : interface of the IAwsContainerBuilder
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _IAWSCONTROLLERBUILDER_H_2009_10_09_
#define _IAWSCONTROLLERBUILDER_H_2009_10_09_

typedef struct tagCAwsContainer CAwsContainer;

typedef struct tagCAwsWindow CAwsWindow;

typedef struct tagCEspRect CEspRect;


typedef struct tagIAwsContainerBuilder IAwsContainerBuilder;

// 虚函数表
typedef CAwsContainer * (*PVIAwsContainerBuilder_Build_CAwsWindow1p_CEspRect1p)(IAwsContainerBuilder* pThis, CAwsWindow *  pParent, const CEspRect * rect);
typedef struct tagVTab_IAwsContainerBuilder VTab_IAwsContainerBuilder;
struct tagVTab_IAwsContainerBuilder
{
	PVIAwsContainerBuilder_Build_CAwsWindow1p_CEspRect1p	m_pBuild_CAwsWindow1p_CEspRect1p;
};

// 类声明
struct tagIAwsContainerBuilder
{
	const VTab_IAwsContainerBuilder*	m_pVTab;
};

// 成员函数声明
CAwsContainer *  IAwsContainerBuilder_Build_CAwsWindow1p_CEspRect1p(IAwsContainerBuilder* pThis, CAwsWindow *  pParent, const CEspRect * rect);

// 虚函数表的声明
extern const VTab_IAwsContainerBuilder g_tVTab_IAwsContainerBuilder_IAwsContainerBuilder;


#endif /* _IAWSCONTROLLERBUILDER_H_2009_10_09_ */
