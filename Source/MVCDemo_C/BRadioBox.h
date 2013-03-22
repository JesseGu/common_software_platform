/******************************************************************************
* FileName		       : BRadioBox.h
* Description          : interface for the CBRadioBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BRADIOBOX_H_2009_10_09_
#define _BRADIOBOX_H_2009_10_09_

#include "BImageButton.h"

typedef struct tagCBRadioBox CBRadioBox;

// 类声明
struct tagCBRadioBox
{
	CBImageButton m_oBase_CBImageButton;

	int m_bIsSelect;
	CAwsRgb m_oBorderColor;
	CAwsRgb m_oFocusBorderColor;
	CAwsRgb m_oBKColor;
	CAwsRgb m_oSelectColor;
	int m_nSelectDim;
	CAwsImage m_oImage;
	CAwsImage m_oImageFocus;
	CAwsImage m_oImageSel;
	CAwsImage m_oImageSelFocus;
	CAwsImage m_oImageMask;
};

// 成员函数声明
void CBRadioBox_DrawIcon_IAwsGc1p_CEspRect1p(CBImageButton* this, IAwsGc *  pGc, const CEspRect * rect);
void CBRadioBox_OnClick(CBButton* this);
void CBRadioBox_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CBRadioBox_CInit(CBRadioBox* pThis);
void CBRadioBox_SetSelected_i0p(CBRadioBox* pThis, int bIsSelect);
int CBRadioBox_IsSelected(CBRadioBox* pThis);
void CBRadioBox_SetBorderColor_CAwsRgb1p(CBRadioBox* pThis, CAwsRgb * color);
void CBRadioBox_SetFocusBorderColor_CAwsRgb1p(CBRadioBox* pThis, CAwsRgb * color);
void CBRadioBox_SetBKColor_CAwsRgb1p(CBRadioBox* pThis, CAwsRgb * color);
void CBRadioBox_SetSelectColor_CAwsRgb1p(CBRadioBox* pThis, CAwsRgb * color);
void CBRadioBox_SetImage_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p(CBRadioBox* pThis, const CAwsImage * image, const CAwsImage * imageFocus, const CAwsImage * imageSel, const CAwsImage * imageSelFocus, const CAwsImage * imageMask);

// 虚函数表的声明
extern const VTab_CBImageButton g_tVTab_CBRadioBox_CBImageButton;
extern const VTab_CBButton g_tVTab_CBRadioBox_CBButton;
extern const VTab_CAwsWindow g_tVTab_CBRadioBox_CAwsWindow;


#endif /* _BRADIOBOX_H_2009_10_09_ */
