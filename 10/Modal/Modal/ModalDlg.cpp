
// ModalDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Modal.h"
#include "ModalDlg.h"
#include "afxdialogex.h"


#include "ChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModalDlg 对话框



CModalDlg::CModalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MODAL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CModalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CModalDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_CHAT, &CModalDlg::OnBnClickedChat)
END_MESSAGE_MAP()


// CModalDlg 消息处理程序

BOOL CModalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CModalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CModalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CModalDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CModalDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnCancel();
}


void CModalDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(MessageBox(_T("确定要退出？"),_T("温馨提示"),MB_YESNO) == IDYES)
		EndDialog(IDCANCEL);
	//CDialogEx::OnClose();
}


//CChatDlg dlg;
//void CModalDlg::OnBnClickedChat()
//{//单例模式
//
//	//dlg.DoModal();	//模式对话框弹出
//
//	if (!dlg.m_hWnd)	//判断是否重复创建
//	{
//		dlg.Create(IDD_CHAT_DLG); //创建无模式对话框
//	}
//	dlg.ShowWindow(SW_SHOW);
//
//}

void CModalDlg::OnBnClickedChat()
{//多例模式
	CChatDlg *pdlg = new CChatDlg;
	pdlg->Create(IDD_CHAT_DLG, CWnd::GetDesktopWindow());
	//pdlg->ShowWindow(SW_SHOW);

}
