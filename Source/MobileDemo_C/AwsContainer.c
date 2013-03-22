/******************************************************************************
* FileName		       : AwsContainer.cpp
* Description          : implementation of the CAwsContainer class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "AwsContainer.h"
const VTab_CAwsWindow g_tVTab_CAwsContainer_CAwsWindow = {CAwsContainer_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsContainer_GetFocusSubWnd, CAwsContainer_OnDraw_CEspRect1p, CAwsContainer_OnKey_0p_0p, CAwsContainer_OnSize_CEspSize1p_i0p, CAwsContainer_OnFocus_i0p, CAwsContainer_OnTimer, CAwsContainer_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CAwsContainer_OnCreate};
CAwsWindow * CAwsContainer_GetFocusSubWnd(CAwsWindow* this) {

	CAwsContainer* pThis = (CAwsContainer*)this;{ return pThis->m_pFocusWnd; }
} 

const VTab_CAwsWindow g_tVTab_CAwsWindow_CAwsWindow = {CAwsWindow_DUninit_i1p, CAwsWindow_InvalideRect_CEspRect1p, CAwsWindow_GetFocusSubWnd, CAwsWindow_OnDraw_CEspRect1p, CAwsWindow_OnKey_0p_0p, CAwsWindow_OnSize_CEspSize1p_i0p, CAwsWindow_OnFocus_i0p, CAwsWindow_OnTimer, CAwsWindow_OnImeChar_s0p, CAwsWindow_OnCommand_i0p_i0p_i0p_i0p, CAwsWindow_OnCreate};
void CAwsWindow_OnCreate(CAwsWindow* pThis) { } 

int CAwsWindow_OnCommand_i0p_i0p_i0p_i0p(CAwsWindow* pThis, int nWndID,int nCmdID,int nParam1,int nParam2) { return 0; } 

void CAwsWindow_OnImeChar_s0p(CAwsWindow* pThis, short nChar) { } 

void CAwsWindow_OnTimer(CAwsWindow* pThis) { } 

void CAwsWindow_OnSize_CEspSize1p_i0p(CAwsWindow* pThis, const CEspSize * size,int bIsRedraw) { } 

int CAwsWindow_OnKey_0p_0p(CAwsWindow* pThis, AWS_KeyType type,AWS_KeyCode code) { return 0; } 

void CAwsWindow_OnDraw_CEspRect1p(CAwsWindow* pThis, const CEspRect * rect) { } 

void CAwsWindow_SetBKTransparent_i0p(CAwsWindow* pThis, int bIsTransparent) { pThis->m_bIsBKTransparent=bIsTransparent; } 

CAwsWindow * CAwsWindow_GetFocusSubWnd(CAwsWindow* pThis) { return ESP_NULL; } 

int CAwsWindow_GetWndID(CAwsWindow* pThis) { return pThis->m_nWndID; } 

int CAwsWindow_IsVisible(CAwsWindow* pThis) { return pThis->m_bIsVisible; } 

CAwsWindow * CAwsWindow_GetParent(CAwsWindow* pThis) { return pThis->m_pParent; } 

const CEspSize * CAwsWindow_GetSize(CAwsWindow* pThis) { return CEspRect_GetSize(&(pThis->m_tRect)); } 

const CEspRect * CAwsWindow_GetRect(CAwsWindow* pThis) { return &(pThis->m_tRect); } 

void CAwsWindow_SetUi_CAwsUi1p(CAwsWindow* pThis, CAwsUi *  pUi) { pThis->m_pUi=pUi; } 

const CEspPoint * CAwsWindow_GetOrigin(CAwsWindow* pThis) { return &(pThis->m_tOrigin); } 

 void CAwsWindow_DUninit_i1p(CAwsWindow* pThis, int * pOffset) { } 

#include "IAwsGc.h"

void CAwsContainer_CInit_i0p(CAwsContainer* pThis, int nMaxSubWndCount)
{

CAwsWindow_CInit(&(pThis->m_oBase_CAwsWindow));
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsContainer_CAwsWindow;
{
	if(nMaxSubWndCount>0){
		pThis->m_pSubWndData=(CAwsWindow * (*))malloc(sizeof(CAwsWindow * )*nMaxSubWndCount);}
	else
		{pThis->m_pSubWndData=ESP_NULL;}
	pThis->m_nSubWndCount=0;
	pThis->m_nMaxSubWndCount=nMaxSubWndCount;

	if(nMaxSubWndCount>0){
		pThis->m_pFocusWndData=(CAwsWindow * (*))malloc(sizeof(CAwsWindow * )*nMaxSubWndCount);}
	else
		{pThis->m_pFocusWndData=ESP_NULL;}
	pThis->m_nFocusWndCount=0;
	pThis->m_nFocusWndIndex=0;
	pThis->m_pFocusWnd=ESP_NULL;

	pThis->m_nPopWndCount=0;
}
}

void CAwsContainer_DUninit_i1p(CAwsWindow* this, int * pOffset)
{

	CAwsContainer* pThis = (CAwsContainer*)this;
	pThis->m_oBase_CAwsWindow.m_pVTab = &g_tVTab_CAwsWindow_CAwsWindow;
	CAwsWindow_DUninit_i1p(&(pThis->m_oBase_CAwsWindow), 0);
	if ( 0 != pOffset ) *pOffset = (int)(&(((CAwsContainer*)0)->m_oBase_CAwsWindow));
{
	int i;
	for(i=0;i<pThis->m_nSubWndCount;++i){
		{int nOffset = 0;(pThis->m_pSubWndData[i])->m_pVTab->m_pDUninit_i1p(pThis->m_pSubWndData[i], &nOffset);free((void*)((int)(pThis->m_pSubWndData[i]) - nOffset));};}

	free(pThis->m_pSubWndData);;
	free(pThis->m_pFocusWndData);;
}
}

void CAwsContainer_OnCreate(CAwsWindow* this)
{

	CAwsContainer* pThis = (CAwsContainer*)this;{
	// ����ӿؼ�
}
}

CAwsWindow * CAwsContainer_GetWndFromID_i0p(CAwsContainer* pThis, int nWndID)
{
	CAwsWindow *  pWnd=ESP_NULL;

	if(nWndID>0){
	{
		int i;
		for(i=0;i<pThis->m_nSubWndCount;++i){
		{
			if(nWndID==CAwsWindow_GetWndID(pThis->m_pSubWndData[i])){
			{
				pWnd=pThis->m_pSubWndData[i];
				break;
			}}
		}}
	}}

	return pWnd;
}

void CAwsContainer_SetFocus_CAwsWindow1p(CAwsContainer* pThis, CAwsWindow *  pSubWnd)
{
	if(ESP_NULL!=pSubWnd){
	{
		int i;
		for(i=0;i<pThis->m_nFocusWndCount;++i){
		{
			if(pThis->m_pFocusWndData[i]==pSubWnd){
				break;}
		}}

		if(i<pThis->m_nFocusWndCount){
		{
			// �ҵ�
			if(ESP_NULL!=pThis->m_pFocusWnd){
			{
				pThis->m_pFocusWnd->m_pVTab->m_pOnFocus_i0p(pThis->m_pFocusWnd,0);
			}}
			pThis->m_pFocusWnd=pSubWnd;
			pThis->m_nFocusWndIndex=i;
			pThis->m_pFocusWnd->m_pVTab->m_pOnFocus_i0p(pThis->m_pFocusWnd,1);
		}}
	}}
}

void CAwsContainer_PopWnd_CAwsWindow1p_CEspRect1p_i0p(CAwsContainer* pThis, CAwsWindow *  pWnd,const CEspRect * rect,int nWndID)
{
	// �ҵ����㴰�ڣ��ڶ��㴰���е�������ʽ����
	CAwsContainer *  pParent=(CAwsContainer*)((char*)CAwsWindow_GetParent(&(pThis->m_oBase_CAwsWindow))-(int)(&(((CAwsContainer*)0)->m_oBase_CAwsWindow)));
	if(ESP_NULL!=pParent){
	{
		CAwsContainer_PopWnd_CAwsWindow1p_CEspRect1p_i0p(pParent,pWnd,rect,nWndID);
	}}
	else
	{{
		// �ɶ���Ĵ��ڵ���
		CAwsWindow_Create_CAwsWindow1p_CEspRect1p_i0p_i0p(pWnd,&((pThis)->m_oBase_CAwsWindow),rect,nWndID,1);

		if(CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(pThis,pWnd,0)){
		{
			if(0==pThis->m_nPopWndCount&&ESP_NULL!=pThis->m_pFocusWnd){
			{
				// ���㴰��ʧȥ����
				pThis->m_pFocusWnd->m_pVTab->m_pOnFocus_i0p(pThis->m_pFocusWnd,0);
			}}

			++pThis->m_nPopWndCount;

			// ������ʽ����
			CAwsWindow_Invalide(pWnd);
		}}
		else
		{{
			// ʧ����
			{int nOffset = 0;(pWnd)->m_pVTab->m_pDUninit_i1p(pWnd, &nOffset);free((void*)((int)(pWnd) - nOffset));};
		}}
	}}
}

// ע��Pop���ڶ�λ�����ϲ�
void CAwsContainer_DestroyPopWnd_i0p(CAwsContainer* pThis, int nCount)
{
	// �ҵ����㴰��
	if(nCount>0){
	{
		CAwsContainer *  pParent=(CAwsContainer*)((char*)CAwsWindow_GetParent(&(pThis->m_oBase_CAwsWindow))-(int)(&(((CAwsContainer*)0)->m_oBase_CAwsWindow)));
		if(ESP_NULL!=pParent){
		{
			CAwsContainer_DestroyPopWnd_i0p(pParent,nCount);
		}}
		else if(pThis->m_nPopWndCount>0){
		{
			if(nCount>pThis->m_nPopWndCount){
				nCount=pThis->m_nPopWndCount;}

			while(nCount>0){
			{
				--pThis->m_nPopWndCount;

				CAwsContainer_DeleteWindow_CAwsWindow1p_i0p(pThis,pThis->m_pSubWndData[pThis->m_nSubWndCount-1],1);

				--nCount;
			}}

			if(0==pThis->m_nPopWndCount&&ESP_NULL!=pThis->m_pFocusWnd){
			{
				// ���㴰�����»�ý���
				pThis->m_pFocusWnd->m_pVTab->m_pOnFocus_i0p(pThis->m_pFocusWnd,1);
			}}
		}}
	}}
}

// ɾ��һ������
void CAwsContainer_DeleteWindow_CAwsWindow1p_i0p(CAwsContainer* pThis, CAwsWindow *  pWnd,int bIsRedraw)
{
	if(ESP_NULL!=pWnd){
	{
		CAwsContainer *  pParent=(CAwsContainer*)((char*)CAwsWindow_GetParent(pWnd)-(int)(&(((CAwsContainer*)0)->m_oBase_CAwsWindow)));

		if(ESP_NULL!=pParent){
		{
			int i,j;
			for(i=0;i<pParent->m_nSubWndCount;++i){
			{
				if(pWnd==pParent->m_pSubWndData[i]){
				{
					// �ҵ������Ӵ������Ƴ��ô���
					for(j=i;j<pParent->m_nSubWndCount-1;++j){
						pParent->m_pSubWndData[j]=pParent->m_pSubWndData[j+1];}
					--pParent->m_nSubWndCount;

					// ��Focus�������Ƴ�
					{int ii,jj;
					for(ii=0;ii<pParent->m_nFocusWndCount;++ii){
					{
						if(pWnd==pParent->m_pFocusWndData[ii]){
						{
							// �ҵ�
							for(jj=ii;jj<pParent->m_nFocusWndCount;++jj){
								pParent->m_pFocusWndData[jj]=pParent->m_pFocusWndData[jj+1];}
							--pParent->m_nFocusWndCount;

							// ���㴰�ڵ��л�����һ�����㴰���Զ���ȡ����
							if(pParent->m_nFocusWndIndex>=pParent->m_nFocusWndCount){
							{
								if(pParent->m_nFocusWndCount>0){
								{
									pParent->m_nFocusWndIndex=pParent->m_nFocusWndCount-1;
									pParent->m_pFocusWnd=pParent->m_pFocusWndData[pParent->m_nFocusWndIndex];
								}}
								else
								{{
									pParent->m_nFocusWndIndex=0;
									pParent->m_pFocusWnd=ESP_NULL;
								}}
							}}
							break;
						}}
					}}
					break;
				}}}
			}}
		}}

		if(bIsRedraw&&ESP_NULL!=pParent){
		{
			pThis->m_oBase_CAwsWindow.m_pVTab->m_pInvalideRect_CEspRect1p(&(pThis->m_oBase_CAwsWindow),CAwsWindow_GetRect(pWnd));
		}}
		// ����ϵͳ�ں��ʵ�ʱ�򽫸ô���ɾ������
		CAwsWindow_PostCommand_i0p_i0p_i0p_i0p(&(pThis->m_oBase_CAwsWindow),pThis->m_oBase_CAwsWindow.m_nWndID,AWS_SysCmd_DeleteWnd,(int)pWnd,0);
	}}
}

int CAwsContainer_AddSubWnd_CAwsWindow1p_i0p(CAwsContainer* pThis, CAwsWindow *  pWnd,int bIsNeedFocus)
{
	int bRet=1;

	if(ESP_NULL!=pWnd&&pThis->m_nSubWndCount<pThis->m_nMaxSubWndCount){
	{
		pThis->m_pSubWndData[pThis->m_nSubWndCount++]=pWnd;

		if(bIsNeedFocus){
		{
			pThis->m_pFocusWndData[pThis->m_nFocusWndCount++]=pWnd;

			// �ı佹�㴰��
			pThis->m_nFocusWndIndex=pThis->m_nFocusWndCount-1;
			pThis->m_pFocusWnd=pWnd;
		}}
	}}
	else
	{{
		bRet=0;
	}}

	return bRet;
}

void CAwsContainer_OnDraw_CEspRect1p(CAwsWindow* this, const CEspRect * rect)
{

	CAwsContainer* pThis = (CAwsContainer*)this;{
	// ��������Ļ��ƺ���
	IAwsGc *  pGc=CAwsWindow_GetGc(&(pThis->m_oBase_CAwsWindow));

	if(pThis->m_nSubWndCount>0){
	{
		int i;
		for(i=0;i<pThis->m_nSubWndCount;++i){
		{
			if(CAwsWindow_IsVisible(pThis->m_pSubWndData[i])){
			{
				// �ؼ����ػ������н���ͻ�
				CEspRect rt;
				CEspRect_CInit(&(rt));
if(CEspRect_InterRect_CEspRect1p_CEspRect1p(rect,CAwsWindow_GetRect(pThis->m_pSubWndData[i]),&(rt))){
				{
					// ת������
					CAwsWindow_ConvertCoordinate_CEspRect1p(pThis->m_pSubWndData[i],&(rt));
					pThis->m_pSubWndData[i]->m_pVTab->m_pOnDraw_CEspRect1p(pThis->m_pSubWndData[i],&(rt));
				}}
			}}
		}}
	}}
}
}

int CAwsContainer_OnKey_0p_0p(CAwsWindow* this, AWS_KeyType type,AWS_KeyCode code)
{

	CAwsContainer* pThis = (CAwsContainer*)this;{
	int bRet=0;

	// ���Ƚ���Ϣ��������ĵ���ʽ���ڣ�������ʽ����û�����������ӿؼ�����Ѱ���㴰��
	if(pThis->m_nPopWndCount>0){
	{
		bRet=pThis->m_pSubWndData[pThis->m_nSubWndCount-1]->m_pVTab->m_pOnKey_0p_0p(pThis->m_pSubWndData[pThis->m_nSubWndCount-1],type,code);
	}}

	if(!bRet&&pThis->m_nFocusWndCount>0){
	{
		// ֪ͨ�ӽ��㴰��
		bRet=pThis->m_pFocusWnd->m_pVTab->m_pOnKey_0p_0p(pThis->m_pFocusWnd,type,code);
	}}

	return bRet;
}
}

void CAwsContainer_OnSize_CEspSize1p_i0p(CAwsWindow* this, const CEspSize * size,int bIsRedraw)
{

	CAwsContainer* pThis = (CAwsContainer*)this;{
	CAwsWindow_OnSize_CEspSize1p_i0p(&(pThis->m_oBase_CAwsWindow),size,bIsRedraw);

	if(pThis->m_nSubWndCount>0){
	{
		int i;
		for(i=0;i<pThis->m_nSubWndCount;++i){
		{
			// Ĭ�ϵ�OnSize�����У��ӿؼ��п��ܻᳬ����Size�ķ�Χ
			CEspRect rect=*(CAwsWindow_GetRect(pThis->m_pSubWndData[i]));
			if(rect.m_ptRB.m_nX<=size->m_nWidth&&rect.m_ptRB.m_nY<=size->m_nHeight){
				CAwsWindow_MoveTo_CEspRect1p_i0p(pThis->m_pSubWndData[i],CAwsWindow_GetRect(pThis->m_pSubWndData[i]),bIsRedraw);}
		}}
	}}
}
}

void CAwsContainer_OnFocus_i0p(CAwsWindow* this, int bIsFocus)
{

	CAwsContainer* pThis = (CAwsContainer*)this;{
	CAwsWindow_OnFocus_i0p(&(pThis->m_oBase_CAwsWindow),bIsFocus);

	// ֪ͨ�ӽ��㴰��
	if(pThis->m_nFocusWndCount>0){
	{
		pThis->m_pFocusWnd=pThis->m_pFocusWndData[pThis->m_nFocusWndIndex];
		pThis->m_pFocusWnd->m_pVTab->m_pOnFocus_i0p(pThis->m_pFocusWnd,bIsFocus);
	}}
}
}

void CAwsContainer_OnTimer(CAwsWindow* this)
{

	CAwsContainer* pThis = (CAwsContainer*)this;{
	CAwsWindow_OnTimer(&(pThis->m_oBase_CAwsWindow));

	// ֪ͨ�ӽ��㴰��
	if(pThis->m_nFocusWndCount>0){
	{
		pThis->m_pFocusWnd->m_pVTab->m_pOnTimer(pThis->m_pFocusWnd);
	}}
}
}

void CAwsContainer_OnImeChar_s0p(CAwsWindow* this, short nChar)
{

	CAwsContainer* pThis = (CAwsContainer*)this;{
	// ֪ͨ�ӽ��㴰��
	if(pThis->m_nFocusWndCount>0){
	{
		pThis->m_pFocusWnd->m_pVTab->m_pOnImeChar_s0p(pThis->m_pFocusWnd,nChar);
	}}
}
}

void CAwsContainer_PreFocusWnd(CAwsContainer* pThis)
{
	if(pThis->m_nFocusWndCount>0){
	{
		if(0==pThis->m_nFocusWndIndex){
		{
			pThis->m_nFocusWndIndex=pThis->m_nFocusWndCount-1;
		}}
		else
		{{
			--pThis->m_nFocusWndIndex;
		}}

		pThis->m_pFocusWnd->m_pVTab->m_pOnFocus_i0p(pThis->m_pFocusWnd,0);
		pThis->m_pFocusWnd=pThis->m_pFocusWndData[pThis->m_nFocusWndIndex];
		pThis->m_pFocusWnd->m_pVTab->m_pOnFocus_i0p(pThis->m_pFocusWnd,1);
	}}
}

void CAwsContainer_NextFocusWnd(CAwsContainer* pThis)
{
	if(pThis->m_nFocusWndCount>0){
	{
		if(pThis->m_nFocusWndCount-1==pThis->m_nFocusWndIndex){
		{
			pThis->m_nFocusWndIndex=0;
		}}
		else
		{{
			++pThis->m_nFocusWndIndex;
		}}

		pThis->m_pFocusWnd->m_pVTab->m_pOnFocus_i0p(pThis->m_pFocusWnd,0);
		pThis->m_pFocusWnd=pThis->m_pFocusWndData[pThis->m_nFocusWndIndex];
		pThis->m_pFocusWnd->m_pVTab->m_pOnFocus_i0p(pThis->m_pFocusWnd,1);
	}}
}
