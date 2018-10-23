
// Calc.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "Calc.h"
#include "CalcDlg.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalcApp

BEGIN_MESSAGE_MAP(CCalcApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCalcApp 构造

CCalcApp::CCalcApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CCalcApp 对象

CCalcApp theApp;


// CCalcApp 初始化
// 一、启动关键技术
BOOL CCalcApp::InitInstance()	//winmain()相当于
{
	CLoginDlg logdlg;
	if (IDCANCEL == logdlg.DoModal())
		return FALSE;
	CCalcDlg dlg;
	INT_PTR nResponse = dlg.DoModal();
	return FALSE;
}

