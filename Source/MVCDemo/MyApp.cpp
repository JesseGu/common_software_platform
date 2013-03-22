// MyApp.cpp: implementation of the CMyApp class.
//
//////////////////////////////////////////////////////////////////////

#include "MyApp.h"

#include "MyController1.h"
#include "MyController2.h"
#include "MyContainer.h"

CMyApp::CMyApp() : CSpxApp(2)
{
	// 添加控制器
	AddController(new CMyController1());
	AddController(new CMyController2());
}

void CMyApp::OnInit(const CEspSize& sizeScreen)
{
	// 创建主容器
	CAwsContainer* pContainer = new CMyContainer(10);
	CEspRect rect;
	rect.m_ptRB.m_nX = sizeScreen.m_nWidth;
	rect.m_ptRB.m_nY = sizeScreen.m_nHeight;

	pContainer->SetUi(m_pUi);
	pContainer->Create(ESP_NULL, rect);
	m_pUi->AddWndToStack(pContainer);

	m_pUi->SetTopWnd(pContainer);
}
