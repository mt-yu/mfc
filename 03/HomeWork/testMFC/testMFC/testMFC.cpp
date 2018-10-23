
// testMFC.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "testMFC.h"
#include "testMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestMFCApp

BEGIN_MESSAGE_MAP(CtestMFCApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CtestMFCApp 构造

CtestMFCApp::CtestMFCApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CtestMFCApp 对象

CtestMFCApp theApp;


// CtestMFCApp 初始化

BOOL CtestMFCApp::InitInstance()
{

	CtestMFCDlg dlg;
	INT_PTR nResponse = dlg.DoModal();
	DWORD dwError = GetLastError();

	return FALSE;
}

