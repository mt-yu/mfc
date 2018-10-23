
// TestM.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "TestM.h"
#include "TestMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMApp

BEGIN_MESSAGE_MAP(CTestMApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTestMApp 构造

CTestMApp::CTestMApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CTestMApp 对象

CTestMApp theApp;


// CTestMApp 初始化

BOOL CTestMApp::InitInstance()
{
	CTestMDlg dlg;

	INT_PTR nResponse = dlg.DoModal();

	return FALSE;
}

