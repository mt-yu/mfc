
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
	//将配置文件保存到注册表中 （不加这行则数据会保存到m_pszProfileName的路径中）
	SetRegistryKey(_T("NotePad"));

	// win10 下无法写入ini 时只能用这个 设置配置文件保存的路径
	free((LPTSTR)m_pszProfileName);
	m_pszProfileName = (LPCTSTR)malloc(256);
	sizeof(*m_pszProfileName);
	_tcscpy_s((LPTSTR)m_pszProfileName,128, _T("./notepad.ini"));


	CNotepadDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();	//EndDialog(n) 中 n 是什么Domodal就传出什么 用于结果的判断

	return FALSE;
}



int CNotepadApp::ExitInstance()
{
	// TODO: 在此添加专用代码和/或调用基类

	return CWinApp::ExitInstance();
}
