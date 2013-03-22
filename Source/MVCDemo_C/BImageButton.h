/******************************************************************************
* FileName		       : BImageButton.h
* Description          : interface for the CBImageButton class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BIMAGEBUTTON_H_2009_10_09_
#define _BIMAGEBUTTON_H_2009_10_09_

#include "BButton.h"

typedef enum tagMIB_ShowMode MIB_ShowMode;
enum tagMIB_ShowMode
{
	MIBMode_IconLeft,
	MIBMode_IconTop
};


typedef struct tagCBImageButton CBImageButton;

// 虚函数表
typedef void(*PVCBImageButton_DrawIcon_IAwsGc1p_CEspRect1p)(CBImageButton* pThis, IAwsGc *  pGc, const CEspRect * rect);
typedef struct tagVTab_CBImageButton VTab_CBImageButton;
struct tagVTab_CBImageButton
{
	PVCBImageButton_DrawIcon_IAwsGc1p_CEspRect1p	m_pDrawIcon_IAwsGc1p_CEspRect1p;
};

// 类声明
struct tagCBImageButton
{
	CBButton m_oBase_CBButton;

	CEspSize m_nIconSize;
	MIB_ShowMode m_eMode;
	CAwsImage m_oImage;
	CAwsImage m_oImageMask;
	const VTab_CBImageButton*	m_pVTab;
};

// 成员函数声明
void CBImageButton_DrawIcon_IAwsGc1p_CEspRect1p(CBImageButton* pThis, IAwsGc *  pGc, const CEspRect * rect);
void CBImageButton_DrawInf_IAwsGc1p_CEspRect1p(CBButton* this, IAwsGc *  pGc, const CEspRect * rect);
void CBImageButton_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CBImageButton_CInit(CBImageButton* pThis);
void CBImageButton_SetMode_0p(CBImageButton* pThis, MIB_ShowMode mode);
void CBImageButton_SetIconSize_CEspSize1p(CBImageButton* pThis, const CEspSize * size);
void CBImageButton_SetImage_CAwsImage1p_CAwsImage1p(CBImageButton* pThis, const CAwsImage * image, const CAwsImage * imageMask);

// 虚函数表的声明
extern const VTab_CBImageButton g_tVTab_CBImageButton_CBImageButton;
extern const VTab_CBButton g_tVTab_CBImageButton_CBButton;
extern const VTab_CAwsWindow g_tVTab_CBImageButton_CAwsWindow;


#endif /* _BIMAGEBUTTON_H_2009_10_09_ */
