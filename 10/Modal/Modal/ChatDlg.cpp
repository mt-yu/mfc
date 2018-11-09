// ChatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Modal.h"
#include "ChatDlg.h"
#include "afxdialogex.h"


// CChatDlg 对话框

IMPLEMENT_DYNAMIC(CChatDlg, CDialogEx)

CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHAT_DLG, pParent)
{

}

CChatDlg::~CChatDlg()
{
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChatDlg, CDialogEx)
	ON_BN_CLICKED(IDC_TEST, &CChatDlg::OnBnClickedTest)
END_MESSAGE_MAP()


// CChatDlg 消息处理程序


void CChatDlg::OnBnClickedTest()
{
	// TODO: 在此添加控件通知处理程序代码
	CWnd *p1 = AfxGetMainWnd();
	CWnd *p2 = theApp.m_pMainWnd;
}
