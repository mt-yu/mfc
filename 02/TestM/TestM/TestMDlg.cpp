
// TestMDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestM.h"
#include "TestMDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMDlg 对话框



CTestMDlg::CTestMDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
// 消息映射机制， 消息的种类和对应的窗口ID关联到一个成员函数上
/* ******************************** */
BEGIN_MESSAGE_MAP(CTestMDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &CTestMDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DEC, &CTestMDlg::OnBnClickedDec)
END_MESSAGE_MAP()


// CTestMDlg 消息处理程序

BOOL CTestMDlg::OnInitDialog()
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

void CTestMDlg::OnPaint()
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
HCURSOR CTestMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestMDlg::OnBnClickedAdd()
{
	int nLeft = GetDlgItemInt(IDC_LEFT1);
	int nRight = GetDlgItemInt(IDC_RIGHT1);

	SetDlgItemInt(IDC_RESULT1, nLeft + nRight);
	// TODO: 在此添加控件通知处理程序代码

}


void CTestMDlg::OnBnClickedDec()
{
	// TODO: 在此添加控件通知处理程序代码
}
