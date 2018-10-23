
// testMFCDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "testMFC.h"
#include "testMFCDlg.h"
#include "afxdialogex.h"

#include <stdio.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestMFCDlg 对话框



CtestMFCDlg::CtestMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtestMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CtestMFCDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CtestMFCDlg 消息处理程序

BOOL CtestMFCDlg::OnInitDialog()
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

void CtestMFCDlg::OnPaint()
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
HCURSOR CtestMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//CDialogEx::OnOK();
void CtestMFCDlg::OnBnClickedOk()
{

	// TODO: 在此添加控件通知处理程序代码
	/*c格式  栈区*/
	//char s[200];
	//GetDlgItemText(IDC_LEFT1, s, sizeof(s));

	/*C++模式  堆区*/
	CString str;
	GetDlgItemText(IDC_LEFT1, str);
	double fLeft = atof(str);
	GetDlgItemText(IDC_RIGHT1, str);
	double fRight = atof(str);
	
	/*C方法*/

	//char s[200];
	//sprintf_s(s,sizeof(s), "%.2lf", fRight + fLeft);
	//SetDlgItemText(IDC_RESTUL1, s);

	/*C++方法*/
	str.Format("%.2lf", fLeft + fRight);
	SetDlgItemText(IDC_RESTUL1, str);

	/* - */
	GetDlgItemText(IDC_LEFT2, str);
	fLeft = atof(str);
	GetDlgItemText(IDC_RIGHT2, str);
	fRight = atof(str);
	str.Format("%.2lf", fLeft - fRight);
	SetDlgItemText(IDC_RESTUL2, str);

	/* * */
	GetDlgItemText(IDC_LEFT3, str);
	fLeft = atof(str);
	GetDlgItemText(IDC_RIGHT3, str);
	fRight = atof(str);
	str.Format("%.2lf", fLeft * fRight);
	SetDlgItemText(IDC_RESTUL3, str);

	/* / */
	GetDlgItemText(IDC_LEFT4, str);
	fLeft = atof(str);
	GetDlgItemText(IDC_RIGHT4, str);
	fRight = atof(str);
	if (fRight == 0)
	{
		SetDlgItemText(IDC_RESTUL4, "被除数不能为0");
	}
	else
	{
		str.Format("%.2lf", fLeft / fRight);
		SetDlgItemText(IDC_RESTUL4, str);
	}

}
