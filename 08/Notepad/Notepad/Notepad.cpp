
// Notepad.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "Notepad.h"
#include "NotepadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNotepadApp

BEGIN_MESSAGE_MAP(CNotepadApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CNotepadApp 构造

CNotepadApp::CNotepadApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CNotepadApp 对象

CNotepadApp theApp;


// CNotepadApp 初始化

BOOL CNotepadApp::InitInstance()
{

	CNotepadDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();	//EndDialog(n) 中 n 是什么Domodal就传出什么 用于结果的判断

	return FALSE;
}

