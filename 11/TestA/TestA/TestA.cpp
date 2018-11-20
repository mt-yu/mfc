
// TestA.cpp: 定义应用程序的类行为。
//

#include "stdafx.h"
#include "TestA.h"
#include "TestADlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestAApp

BEGIN_MESSAGE_MAP(CTestAApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTestAApp 构造

CTestAApp::CTestAApp() //: CWinApp(_T("温馨提示："))
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的 CTestAApp 对象

CTestAApp theApp;


// CTestAApp 初始化

BOOL CTestAApp::InitInstance()
{

	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	AfxMessageBox(_T("Test"));
	CTestADlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	
	return FALSE;
}

