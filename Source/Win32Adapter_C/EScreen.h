
#ifndef __ESCREEN_H_2011_03_05__
#define __ESCREEN_H_2011_03_05__

#include "EMyui.h"
#include "EWndGc.h"
#include "SpxApp.h"

typedef struct tagCEScreen CEScreen;

struct tagCEScreen
{
	CEMyUi*		m_pMyUi;
	CEWndGc		m_oWndGc;

	HWND		m_hWnd;
	HINSTANCE	m_hInst;

	int			m_bIsFirstKeyDown;
	int			m_bNoChar;
};

void CEScreen_SetUi(CEScreen* pThis, CEMyUi* pMyUi);

void CEScreen_CInit(CEScreen* pThis);
void CEScreen_DUninit(CEScreen* pThis);
int CEScreen_Create(CEScreen* pThis, LPCTSTR lpszWindowName, const RECT rect, HWND hwndFather, HINSTANCE hInst);
ATOM CEScreen_RegisterClass(CEScreen* pThis);

void CEScreen_Key(CEScreen* pThis, AWS_KeyType type, AWS_KeyCode code);

LRESULT CALLBACK CEScreen_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

void CEScreen_OnPaint(CEScreen* pThis);
void CEScreen_OnSize(CEScreen* pThis, UINT nType, int cx, int cy);
void CEScreen_OnSetFocus(CEScreen* pThis, HWND hLoseFocus);
void CEScreen_OnKillFocus(CEScreen* pThis, HWND hGetFocus);
void CEScreen_OnKeyDown(CEScreen* pThis, int nVirKey, int nKeyData);
void CEScreen_OnKeyUp(CEScreen* pThis, int nVirKey, int nKeyData);
void CEScreen_OnTimer(CEScreen* pThis, int nTimeEvent);
void CEScreen_OnImeChar(CEScreen* pThis, WPARAM wParam, LPARAM lParam);
void CEScreen_OnChar(CEScreen* pThis, int nCharCode, int nKeyData);

#endif /* __ESCREEN_H_2011_03_05__ */
