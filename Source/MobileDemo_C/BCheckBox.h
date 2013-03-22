/******************************************************************************
* FileName		       : BCheckBox.h
* Description          : interface for the CBCheckBox class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#ifndef _BCHECKBOX_H__2009_10_09_
#define _BCHECKBOX_H__2009_10_09_

#include "BImageButton.h"

typedef struct tagCBCheckBox CBCheckBox;

// 类声明
struct tagCBCheckBox
{
	CBImageButton m_oBase_CBImageButton;

	int m_bIsSelect;
	CAwsRgb m_oBorderColor;
	CAwsRgb m_oFocusBorderColor;
	CAwsRgb m_oBKColor;
	CAwsRgb m_oSelectColor;
	CAwsImage m_oImage;
	CAwsImage m_oImageFocus;
	CAwsImage m_oImageSel;
	CAwsImage m_oImageSelFocus;
	CAwsImage m_oImageMask;
};

// 成员函数声明
void CBCheckBox_DrawIcon_IAwsGc1p_CEspRect1p(CBImageButton* this, IAwsGc *  pGc, const CEspRect * rect);
void CBCheckBox_OnClick(CBButton* this);
void CBCheckBox_DUninit_i1p(CAwsWindow* this, int* pOffset);
void CBCheckBox_CInit(CBCheckBox* pThis);
void CBCheckBox_SetSelected_i0p(CBCheckBox* pThis, int bIsSelect);
int CBCheckBox_IsSelected(CBCheckBox* pThis);
void CBCheckBox_SetBorderColor_CAwsRgb1p(CBCheckBox* pThis, const CAwsRgb * color);
void CBCheckBox_SetFocusBorderColor_CAwsRgb1p(CBCheckBox* pThis, const CAwsRgb * color);
void CBCheckBox_SetBKColor_CAwsRgb1p(CBCheckBox* pThis, const CAwsRgb * color);
void CBCheckBox_SetSelectColor_CAwsRgb1p(CBCheckBox* pThis, const CAwsRgb * color);
void CBCheckBox_SetImage_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p_CAwsImage1p(CBCheckBox* pThis, const CAwsImage * image, const CAwsImage * imageFocus, const CAwsImage * imageSel, const CAwsImage * imageSelFocus, const CAwsImage * imageMask);

// 虚函数表的声明
extern const VTab_CBImageButton g_tVTab_CBCheckBox_CBImageButton;
extern const VTab_CBButton g_tVTab_CBCheckBox_CBButton;
extern const VTab_CAwsWindow g_tVTab_CBCheckBox_CAwsWindow;


#endif /* _BCHECKBOX_H__2009_10_09_ */
