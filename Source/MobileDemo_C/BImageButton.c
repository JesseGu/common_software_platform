/******************************************************************************
* FileName		       : BImageButton.cpp
* Description          : implementation of the CBImageButton class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "BImageButton.h"
#include "IAwsGc.h"

void CBImageButton_CInit(CBImageButton* pThis)
{

CBButton_CInit(&(pThis->m_oBase_CBButton));
CEspSize_CInit_i0p_i0p(&(pThis->m_nIconSize),0,0);
CAwsImage_CInit(&(pThis->m_oImage));
CAwsImage_CInit(&(pThis->m_oImageMask));
	pThis->m_pVTab = &g_tVTab_CBImageButton_CBImageButton;
	pThis->m_oBase_CBButton.m_pVTab = &g_tVTab_CBImageButton_CBButton;
	pThis->m_oBase_CBButton.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CBImageButton_CAwsWindow;
{
	pThis->m_eMode=MIBMode_IconLeft;

	pThis->m_nIconSize.m_nWidth=12;
	pThis->m_nIconSize.m_nHeight=12;
}
}

void CBImageButton_SetImage_CAwsImage1p_CAwsImage1p(CBImageButton* pThis, const CAwsImage * image,const CAwsImage * imageMask)
{
	pThis->m_oImage=*image;
	pThis->m_oImageMask=*imageMask;
}

void CBImageButton_DrawIcon_IAwsGc1p_CEspRect1p(CBImageButton* pThis, IAwsGc *  pGc,const CEspRect * rect)
{
	if(CAwsImage_GetID(&(pThis->m_oImage))>0){
	{
		pGc->m_pVTab->m_pDrawImage_CEspPoint1p_CAwsImage1p_CAwsImage1p(pGc,&(rect->m_ptLT),&(pThis->m_oImage),&pThis->m_oImageMask);
	}}
}

void CBImageButton_DrawInf_IAwsGc1p_CEspRect1p(CBButton* this, IAwsGc *  pGc,const CEspRect * rect)
{

	CBImageButton* pThis = (CBImageButton*)this;{
	CEspRect rt;
	CEspRect rtText=*(rect);

	CEspRect_CInit(&(rt));
switch(pThis->m_eMode)
	{
	case MIBMode_IconLeft:
		{
			rt.m_ptLT.m_nX=rect->m_ptLT.m_nX;
			rt.m_ptLT.m_nY=(CEspRect_GetSize(rect)->m_nHeight-pThis->m_nIconSize.m_nHeight)/2;
			rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nIconSize.m_nWidth;
			rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nIconSize.m_nHeight;

			rtText.m_ptLT.m_nX+=pThis->m_nIconSize.m_nWidth+2;
		}
		break;

	case MIBMode_IconTop:
		{
			rt.m_ptLT.m_nX=rect->m_ptLT.m_nX+(CEspRect_GetSize(rect)->m_nWidth-pThis->m_nIconSize.m_nWidth)/2;
			rt.m_ptLT.m_nY=rect->m_ptLT.m_nY;
			rt.m_ptRB.m_nX=rt.m_ptLT.m_nX+pThis->m_nIconSize.m_nWidth;
			rt.m_ptRB.m_nY=rt.m_ptLT.m_nY+pThis->m_nIconSize.m_nHeight;

			rtText.m_ptLT.m_nY+=pThis->m_nIconSize.m_nHeight+2;
		}
		break;
	}

	pThis->m_pVTab->m_pDrawIcon_IAwsGc1p_CEspRect1p(pThis,pGc,&(rt));

	pThis->m_oBase_CBButton.m_pVTab->m_pDrawText_IAwsGc1p_CEspRect1p(&(pThis->m_oBase_CBButton),pGc,&(rtText));

}
}
