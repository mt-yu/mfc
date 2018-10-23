// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Calc.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGIN_DLG, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_STATUS, &CLoginDlg::OnEnChangeStatus)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnBnClickedOk()
{
	CString szName, szPass;
	GetDlgItemText(IDC_NAME, szName);
	GetDlgItemText(IDC_PASSWD, szPass);

	if (szName != "admin" || szPass != "123456")
	{
		AfxMessageBox(L"用户名或者密码错误，请重新输入！");
		return;
	}

	CDialogEx::OnOK();
}


void CLoginDlg::OnEnChangeStatus()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	CString szName;
	GetDlgItemText(IDC_NAME, szName);
	SetDlgItemText(IDC_STATUS, szName);
	// TODO:  在此添加控件通知处理程序代码
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CTime time = CTime::GetCurrentTime();
	CString str;
	str.Format(_T("%02d年%02d月%02d日 %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
	SetDlgItemText(IDC_STATIC3, str);
	SetTimer(1, 1000, NULL);	//设置定时器1 每隔1秒中进一次中断


	return TRUE; 
}


void CLoginDlg::OnTimer(UINT_PTR nIDEvent)		//定时
{
	CTime time = CTime::GetCurrentTime();
	CString str;
	str.Format(_T("%02d年%02d月%02d日 %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
	SetDlgItemText(IDC_STATIC3, str);
	CDialogEx::OnTimer(nIDEvent);
}
