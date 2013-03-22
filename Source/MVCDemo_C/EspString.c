/******************************************************************************
* FileName		       : AwsString.cpp
* Description          : implementation of the CAwsString class
* Author               : Jesse Gu
* Date Of Creation     : 2009-10-09

*------------------------------------------------------------------------------
* Copyright (C) 2009 Gu Jicheng
*------------------------------------------------------------------------------
******************************************************************************/

#include "EspString.h"
#include "EspPubClass.h"
#include "EspSysDefine.h"

void CAwsString_CInit_i0p(CAwsString* pThis, int nMaxCharCB)
{
	// 默认的串ID为-1
	pThis->m_nStrID=-1;

	pThis->m_eCharType=CharType_DBCS;

	pThis->m_pCharData=ESP_NULL;
	pThis->m_nCharCount=0;
	pThis->m_nCharCB=0;

	pThis->m_nMaxCharCB=nMaxCharCB;
}

void CAwsString_DUninit_i1p(CAwsString* pThis, int * pOffset)
{
	free(pThis->m_pCharData);;
}

void CAwsString_SetCharType_0p(CAwsString* pThis, ECharType type)
{
	pThis->m_eCharType=type;
}

void CAwsString_SetData_c1p_i0p(CAwsString* pThis, const char *  pData,int nCharCB)
{
	pThis->m_nCharCount=0;
	{int i;

	if(ESP_NULL==pThis->m_pCharData){
	{
		CAwsString_CreateStr(pThis);
	}}

	switch(pThis->m_eCharType)
	{
	case CharType_DBCS:
		for(i=0;i<nCharCB;++i){
		{
			pThis->m_pCharData[i]=pData[i];
			if(((unsigned char)pData[i])>0x7f){
			{
				// 双字节
				++i;
				pThis->m_pCharData[i]=pData[i];
			}}
			++pThis->m_nCharCount;
		}}
		pThis->m_pCharData[i]=0;
		break;

	case CharType_UNICODE:
		for(i=0;i<nCharCB;++i){
		{
			pThis->m_pCharData[i]=pData[i];
			++i;
			pThis->m_pCharData[i]=pData[i];
			++pThis->m_nCharCount;
		}}
		break;
	}

	pThis->m_nCharCB=nCharCB;
}}

int CAwsString_RemoveChar_i0p(CAwsString* pThis, int nIndex)
{
	if(nIndex>=0){
	{
		int nPos=CAwsString_GetBytePosFromCharIndex_i0p(pThis,nIndex);

		int nStep=1;
		if(pThis->m_pCharData[nPos]<0){
		{
			nStep=2;
			// 双字节
		}}

		// 往前移动
		{int i;
		for(i=nPos;i<pThis->m_nCharCB-nStep;++i){
			pThis->m_pCharData[i]=pThis->m_pCharData[i+nStep];}

		pThis->m_pCharData[i]=0;

		--pThis->m_nCharCount;
		pThis->m_nCharCB-=nStep;
		return 1;
	}}}

	return 0;
}

int CAwsString_AddCharToEnd_s0p(CAwsString* pThis, short nChar)
{
	int bRet=0;

	int nBytes=1;

	switch(pThis->m_eCharType)
	{
	case CharType_DBCS:
		if(((unsigned char)nChar)>0x7f){
		{
			// 是双字节
			nBytes=2;
		}}

		if(pThis->m_nCharCB+nBytes<=pThis->m_nMaxCharCB){
		{
			// 填充字符
			pThis->m_pCharData[pThis->m_nCharCB++]=*((char*)(&nChar));
			if(nBytes>1){
			{
				char *  p=(char*)(&nChar);
				pThis->m_pCharData[pThis->m_nCharCB++]=*(++p);
			}}

			pThis->m_pCharData[pThis->m_nCharCB]=0;
			++pThis->m_nCharCount;

			bRet=1;
		}}

		break;

	case CharType_UNICODE:
		// 填充字符
		{short *  p=(short*)(pThis->m_pCharData+pThis->m_nCharCount*2);
		*p=nChar;

		pThis->m_nCharCB+=2;
		break;
	}}

	return bRet;
}

// 在第nIndex个字符处插入(从0开始)
int CAwsString_AddChar_s0p_i0p(CAwsString* pThis, short nChar,int nIndex)
{
	int bRet=0;

	if(ESP_NULL==pThis->m_pCharData){
		CAwsString_CreateStr(pThis);}

	if(nIndex<=pThis->m_nCharCount){
	{
		int i;
		int nPos=0;
		int nBytes=1;
		switch(pThis->m_eCharType)
		{
		case CharType_DBCS:
			for(i=0;i<nIndex;++i){
			{
				if(pThis->m_pCharData[nPos]>0){
				{
					// 是单字节
					++nPos;
				}}
				else
				{{
					// 双字节
					nPos+=2;
				}}
			}}

			if(((unsigned char)nChar)>0x7f){
			{
				// 是双字节
				nBytes=2;
			}}

			if(pThis->m_nCharCB+nBytes<=pThis->m_nMaxCharCB){
			{
				// 把后面的往后移动
				for(i=pThis->m_nCharCB-1;i>=nPos;--i){
				{
					pThis->m_pCharData[i+nBytes]=pThis->m_pCharData[i];
				}}

				// 填充字符
				if(nBytes>1){
				{
					char *  p=(char*)(&nChar);
					pThis->m_pCharData[nPos++]=*(++p);
				}}
				pThis->m_pCharData[nPos++]=*((char*)(&nChar));

				pThis->m_nCharCB+=nBytes;
				++pThis->m_nCharCount;
				pThis->m_pCharData[pThis->m_nCharCB]=0;

				bRet=1;
			}}

			break;

		case CharType_UNICODE:
			nBytes=2;

			// 把后面的往后移动
			for(i=nIndex*2;i<pThis->m_nCharCount*2;++i){
			{
				pThis->m_pCharData[i+nBytes]=pThis->m_pCharData[i];
			}}

			// 填充字符
			{short *  p=(short*)(pThis->m_pCharData+nIndex*2);
			*p=nChar;
			break;
		}}
	}}

	return bRet;
}

int CAwsString_AddString_CAwsString1p_i0p(CAwsString* pThis, const CAwsString * str,int nIndex)
{
	return 1;
}

// 字符左边的位置
int CAwsString_GetBytePosFromCharIndex_i0p(CAwsString* pThis, int nIndex)
{
	int nRet=-1;

	if(-1==nIndex){
		nIndex=pThis->m_nCharCount;}

	switch(pThis->m_eCharType)
	{
	case CharType_DBCS:
		{
			int i;
			nRet=0;
			for(i=0;i<nIndex;++i){
			{
				if(pThis->m_pCharData[nRet]>0){
				{
					// 是单字节
					++nRet;
				}}
				else
				{{
					// 双字节
					nRet+=2;
				}}
			}}
		}
		break;
	}

	return nRet;
}

int CAwsString_GetSubString_CAwsString1p_i0p_i0p(CAwsString* pThis, CAwsString * strSub,int nStartIndex,int nEndIndex)
{
	if((ESP_NULL!=pThis->m_pCharData)&&(nStartIndex<pThis->m_nCharCount)){
	{
		int nStartPos=CAwsString_GetBytePosFromCharIndex_i0p(pThis,nStartIndex);
		int nEndPos=CAwsString_GetBytePosFromCharIndex_i0p(pThis,nEndIndex);
		CAwsString_SetData_c1p_i0p(strSub,pThis->m_pCharData+nStartPos,nEndPos-nStartPos);

		return 1;
	}}

	return 0;
}

void CAwsString_Reset(CAwsString* pThis)
{
	if(ESP_NULL!=pThis->m_pCharData){
	{
		pThis->m_nCharCount=0;
		pThis->m_nCharCB=0;

		pThis->m_pCharData[0]=0;
	}}
}

int CAwsString_CreateStr(CAwsString* pThis)
{
	int bRet=0;

	if(ESP_NULL==pThis->m_pCharData){
	{
		switch(pThis->m_eCharType)
		{
		case CharType_DBCS:
			pThis->m_pCharData=(char(*))malloc(sizeof(char)*pThis->m_nMaxCharCB+1);
			break;

		case CharType_UNICODE:
			pThis->m_pCharData=(char*)((short(*))malloc(sizeof(short)*pThis->m_nMaxCharCB+1));
			break;
		}

		if(ESP_NULL!=pThis->m_pCharData){
		{
			pThis->m_nCharCount=0;
			bRet=1;

			{int i;
			for(i=0;i<pThis->m_nMaxCharCB+1;++i){
				pThis->m_pCharData[i]=0;}
		}}}
	}}

	return bRet;
}
