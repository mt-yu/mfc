#include "App.h"
#include "resource.h"
#include <afxdialogex.h>
CApp theApp;

BOOL CApp::InitInstance()
{//作为启动函数
	//MessageBox(NULL, "我的模拟MFC程序开发", "温馨提示：", MB_OK);
	
	//DialogBox()
	CDialogEx dlg(IDD_MAIN_DLG);
	dlg.DoModal();	//MFC弹出对话框的函数


	return 0;
}

CApp::CApp()
{
}

CApp::~CApp()
{
}
