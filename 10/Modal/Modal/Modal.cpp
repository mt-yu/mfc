
// Modal.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "Modal.h"
#include "ModalDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModalApp

BEGIN_MESSAGE_MAP(CModalApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CModalApp 构造

CModalApp::CModalApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CModalApp 对象

CModalApp theApp;


// CModalApp 初始化

BOOL CModalApp::InitInstance()
{

	AfxSocketInit();
	AfxInitRichEdit();	//使用richedit时必须调用该函数。
	CModalDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	return FALSE;
}
