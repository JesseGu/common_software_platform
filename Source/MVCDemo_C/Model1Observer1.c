// Model1Observer1.cpp: implementation of the CModel1Observer1 class.
//
//////////////////////////////////////////////////////////////////////

#include "Model1Observer1.h"
const VTab_ISpxObserver g_tVTab_CModel1Observer1_ISpxObserver = {CModel1Observer1_UpdateData_CSpxModel1p, CModel1Observer1_GetObserverID};
const VTab_CAwsWindow g_tVTab_CModel1Observer1_CAwsWindow = {CModel1Observer1_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CBLabel_OnDraw_CEspRect1p, CAwsWindow_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CAwsWindow_OnFocus_i0p, CAwsWindow_OnTimer, CAwsWindow_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CAwsWindow_OnCreate};
void CModel1Observer1_CInit(CModel1Observer1* pThis)
{
CBLabel_CInit(&(pThis->m_oBase_CBLabel));

	pThis->m_oBase_ISpxObserver.m_pVTab = &g_tVTab_CModel1Observer1_ISpxObserver;
	pThis->m_oBase_CBLabel.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CModel1Observer1_CAwsWindow;
}

void CModel1Observer1_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CModel1Observer1* pThis=(CModel1Observer1*)this;
	pThis->m_oBase_CBLabel.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CBLabel_DUninit_i1p(&(pThis->m_oBase_CBLabel.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CModel1Observer1*)0)->m_oBase_CBLabel.m_oBase_CAwsWindow));
}

int CModel1Observer1_GetObserverID(ISpxObserver* this) {

	CModel1Observer1* pThis = (CModel1Observer1*)((char*)this-(int)(&(((CModel1Observer1*)0)->m_oBase_ISpxObserver)));{ return pThis->m_oBase_CBLabel.m_oBase_CAwsWindow.m_nWndID; }
} 

#include "MyModel1.h"
const VTab_CSpxModel g_tVTab_CMyModel1_CSpxModel = {CMyModel1_DUninit_i1p};
void CMyModel1_DUninit_i1p(CSpxModel* this, int* pOffset)
{
	CMyModel1* pThis=(CMyModel1*)this;
	pThis->m_oBase_CSpxModel.m_pVTab = &g_tVTab_CSpxModel_CSpxModel;
	CSpxModel_DUninit_i1p(&(pThis->m_oBase_CSpxModel), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMyModel1*)0)->m_oBase_CSpxModel));
}

int CMyModel1_GetData(CMyModel1* pThis) { return pThis->m_nData; } 


void CModel1Observer1_UpdateData_CSpxModel1p(ISpxObserver* this, CSpxModel *  pModel)
{

	CModel1Observer1* pThis = (CModel1Observer1*)((char*)this-(int)(&(((CModel1Observer1*)0)->m_oBase_ISpxObserver)));{
	CAwsString str;
	CAwsString_CInit_i0p(&(str),100);
CAwsString_LoadString_i0p(&(str),CMyModel1_GetData(((CMyModel1*)((char*)pModel-(int)(&(((CMyModel1*)0)->m_oBase_CSpxModel))))));

	CBLabel_SetText_CAwsString1p_i0p(&(pThis->m_oBase_CBLabel),&(str),1);
CAwsString_DUninit_i1p(&(str), 0);
}
}
