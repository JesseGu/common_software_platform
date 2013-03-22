// MyContainer.cpp: implementation of the CMyContainer class.
//
//////////////////////////////////////////////////////////////////////

#include "SpxSysDefine.h"
#include "MVCUserDefine.h"
#include "MyContainer.h"
#include "AwsUi.h"

const VTab_CAwsWindow g_tVTab_CMyContainer_CAwsWindow = {CMyContainer_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CMyContainer_OnDraw_CEspRect1p, CMyContainer_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CMyContainer_OnCreate};
void CMyContainer_CInit(CMyContainer* pThis)
{
CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),10);
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CMyContainer_CAwsWindow;
}

void CMyContainer_DUninit_i1p(CAwsWindow* this, int* pOffset)
{
	CMyContainer* pThis=(CMyContainer*)this;
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsContainer_DUninit_i1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CMyContainer*)0)->m_oBase_CAwsContainer.m_oBase_CAwsWindow));
}

void CMyContainer_CInit_i0p(CMyContainer* pThis, int nMaxSubWndCount) {

CAwsContainer_CInit_i0p(&(pThis->m_oBase_CAwsContainer),nMaxSubWndCount);
	pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CMyContainer_CAwsWindow;
{
}
}

void CMyContainer_OnCreate(CAwsWindow* this)
{

	CMyContainer* pThis = (CMyContainer*)this;{
	CAwsString str;
	CEspRect rtButton1,rtButton2; 
	CEspRect rtLabel1,rtLabel2,rtLabel3,rtLabel4;

	{CBButton(*pHeapObj_1)=(CBButton(*))malloc(sizeof(CBButton));
CBButton_CInit(pHeapObj_1);
{CAwsString_CInit_i0p(&(str),100);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtButton1,40,50,100,70);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtButton2,120,50,180,70);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtLabel1,40,80,140,100);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtLabel2,140,80,240,100);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtLabel3,40,120,140,140);
CEspRect_CInit_i0p_i0p_i0p_i0p(&rtLabel4,140,120,240,140);
pThis->m_pM1Button=pHeapObj_1;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pM1Button->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtButton1),EMCID_Model1Button,1);
	CAwsString_LoadString_i0p(&(str),EMSID_Model1Button);
	CBButton_SetText_CAwsString1p(pThis->m_pM1Button,&(str));
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pM1Button)->m_oBase_CAwsWindow),1);

	{CBButton(*pHeapObj_2)=(CBButton(*))malloc(sizeof(CBButton));
CBButton_CInit(pHeapObj_2);
{pThis->m_pM2Button=pHeapObj_2;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pM2Button->m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtButton2),EMCID_Model2Button,1);
	CAwsString_LoadString_i0p(&(str),EMSID_Model2Button);
	CBButton_SetText_CAwsString1p(pThis->m_pM2Button,&(str));
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pM2Button)->m_oBase_CAwsWindow),1);

	{CModel1Observer1(*pHeapObj_3)=(CModel1Observer1(*))malloc(sizeof(CModel1Observer1));
CModel1Observer1_CInit(pHeapObj_3);
{pThis->m_pM1O1Label=pHeapObj_3;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pM1O1Label->m_oBase_CBLabel.m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtLabel1),EMSID_Model1Observer1Label,1);
	CAwsString_LoadString_i0p(&(str),EMSID_Model1Data1);
	CBLabel_SetText_CAwsString1p_i0p(&(pThis->m_pM1O1Label->m_oBase_CBLabel),&(str),0);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pM1O1Label)->m_oBase_CBLabel.m_oBase_CAwsWindow),0);

	{CModel1Observer2(*pHeapObj_4)=(CModel1Observer2(*))malloc(sizeof(CModel1Observer2));
CModel1Observer2_CInit(pHeapObj_4);
{pThis->m_pM1O2Label=pHeapObj_4;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pM1O2Label->m_oBase_CBLabel.m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtLabel2),EMSID_Model1Observer2Label,1);
	CAwsString_LoadString_i0p(&(str),EMSID_Model1Data1);
	CBLabel_SetText_CAwsString1p_i0p(&(pThis->m_pM1O2Label->m_oBase_CBLabel),&(str),0);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pM1O2Label)->m_oBase_CBLabel.m_oBase_CAwsWindow),0);

	{CModel2Observer1(*pHeapObj_5)=(CModel2Observer1(*))malloc(sizeof(CModel2Observer1));
CModel2Observer1_CInit(pHeapObj_5);
{pThis->m_pM2O1Label=pHeapObj_5;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pM2O1Label->m_oBase_CBLabel.m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtLabel3),EMSID_Model2Observer1Label,1);
	CAwsString_LoadString_i0p(&(str),EMSID_Model2Data1);
	CBLabel_SetText_CAwsString1p_i0p(&(pThis->m_pM2O1Label->m_oBase_CBLabel),&(str),0);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pM2O1Label)->m_oBase_CBLabel.m_oBase_CAwsWindow),0);

	{CModel2Observer2(*pHeapObj_6)=(CModel2Observer2(*))malloc(sizeof(CModel2Observer2));
CModel2Observer2_CInit(pHeapObj_6);
{pThis->m_pM2O2Label=pHeapObj_6;
	CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(&(pThis->m_pM2O2Label->m_oBase_CBLabel.m_oBase_CAwsWindow),&((pThis)->m_oBase_CAwsContainer.m_oBase_CAwsWindow),&(rtLabel4),EMSID_Model2Observer2Label,1);
	CAwsString_LoadString_i0p(&(str),EMSID_Model2Data1);
	CBLabel_SetText_CAwsString1p_i0p(&(pThis->m_pM2O2Label->m_oBase_CBLabel),&(str),0);
	CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(&(pThis->m_oBase_CAwsContainer),&((pThis->m_pM2O2Label)->m_oBase_CBLabel.m_oBase_CAwsWindow),0);

	// 将观察者注册给对应的模型
	CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,SPX_SysCmd_RegisterObserver,(int)(ISpxObserver*)((char*)pThis->m_pM1O1Label+(int)(&(((CModel1Observer1*)0)->m_oBase_ISpxObserver))),0);
	CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,SPX_SysCmd_RegisterObserver,(int)(ISpxObserver*)((char*)pThis->m_pM1O2Label+(int)(&(((CModel1Observer2*)0)->m_oBase_ISpxObserver))),0);
	CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,SPX_SysCmd_RegisterObserver,(int)(ISpxObserver*)((char*)pThis->m_pM2O1Label+(int)(&(((CModel2Observer1*)0)->m_oBase_ISpxObserver))),0);
	CAwsWindow_PumpCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow.m_nWndID,SPX_SysCmd_RegisterObserver,(int)(ISpxObserver*)((char*)pThis->m_pM2O2Label+(int)(&(((CModel2Observer2*)0)->m_oBase_ISpxObserver))),0);
}}}}}}}}}}}}CAwsString_DUninit_i1p(&(str), 0);
}
}

int CMyContainer_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CMyContainer* pThis = (CMyContainer*)this;{
	int bRet=CAwsContainer_OnKey_0p_0p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),type,code);

	if(!bRet){
	{
		if(AWS_Key==type){
		{
			switch(code)
			{
			case AWS_KeyCode_LeftArrow:
				CAwsContainer_PreFocusWnd(&(pThis->m_oBase_CAwsContainer));
				bRet=1;
				break;

			case AWS_KeyCode_RightArrow:
				CAwsContainer_NextFocusWnd(&(pThis->m_oBase_CAwsContainer));
				bRet=1;
				break;

			case AWS_KeyCode_RightMenu:
				CAwsWindow_GetUi(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow))->m_pVTab->m_pExitSys(CAwsWindow_GetUi(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow)));
				break;
			}
		}}
	}}

	return bRet;
}
}

void CMyContainer_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CMyContainer* pThis = (CMyContainer*)this;{
	CAwsContainer_OnDraw_CEspRect1p(&(pThis->m_oBase_CAwsContainer.m_oBase_CAwsWindow),rect);
}
}
