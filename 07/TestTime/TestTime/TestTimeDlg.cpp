
// TestTimeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestTime.h"
#include "TestTimeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestTimeDlg 对话框



CTestTimeDlg::CTestTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTTIME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestTimeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GET_TIME, &CTestTimeDlg::OnBnClickedGetTime)
	ON_BN_CLICKED(IDC_GET_TIME2, &CTestTimeDlg::OnBnClickedGetTime2)
	ON_BN_CLICKED(IDC_MK_TIME, &CTestTimeDlg::OnBnClickedMkTime)
	ON_BN_CLICKED(IDC_MK_TIME2, &CTestTimeDlg::OnBnClickedMkTime2)
	ON_BN_CLICKED(IDC_MK_TIME3, &CTestTimeDlg::OnBnClickedMkTime3)
END_MESSAGE_MAP()


// CTestTimeDlg 消息处理程序

BOOL CTestTimeDlg::OnInitDialog()
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

void CTestTimeDlg::OnPaint()
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
HCURSOR CTestTimeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestTimeDlg::OnBnClickedGetTime()
{
	/*
		C语言方法获取时间
	*/
	time_t tt = time(NULL);
	struct tm tms;
	errno_t nErr = localtime_s(&tms, &tt);
	CString str;
	str.Format(_T("%d年%d月%d日 %d:%d:%d"),tms.tm_year+1900, tms.tm_mon, tms.tm_mday,
		tms.tm_hour, tms.tm_min, tms.tm_sec);
	AfxMessageBox(str);


}


void CTestTimeDlg::OnBnClickedGetTime2()
{
	/*
		C++类方法获取时间
	*/
	CTime t = CTime::GetCurrentTime();//返回表示当前时间的 CTime 对象。
	CString str;
	str.Format(_T("%d年%d月%d日 %d:%d:%d"), t.GetYear(), t.GetMonth(), t.GetDay(),
		t.GetHour(), t.GetMinute(), t.GetSecond());
	AfxMessageBox(str);

}


void CTestTimeDlg::OnBnClickedMkTime()
{
	/*
		C语言方法存放时间
	*/
	tm tms = { 15, 50, 9, 25, 10 - 1, 2018 - 1900 };
	time_t tt = mktime(&tms);

}


void CTestTimeDlg::OnBnClickedMkTime2()
{
	//CTime t(2015, 10, 25, 9, 56, 55);

	CTime t(GetDlgItemInt(IDC_YEAR), GetDlgItemInt(IDC_MONTH), GetDlgItemInt(IDC_DAY), GetDlgItemInt(IDC_HOUR), GetDlgItemInt(IDC_MIN), GetDlgItemInt(IDC_SEC));

	CString str;
	str.Format(_T("%d年%d月%d日 %d:%d:%d"), t.GetYear(), t.GetMonth(), t.GetDay(),
		t.GetHour(), t.GetMinute(), t.GetSecond());
	AfxMessageBox(str);
	
}


void CTestTimeDlg::OnBnClickedMkTime3()
{
	CMyTime time = CMyTime::GetCurrentTime();
	CMyTime t(GetDlgItemInt(IDC_YEAR), GetDlgItemInt(IDC_MONTH), GetDlgItemInt(IDC_DAY), GetDlgItemInt(IDC_HOUR), GetDlgItemInt(IDC_MIN), GetDlgItemInt(IDC_SEC));

	CString str;
	str.Format(_T("%d年%d月%d日 %d:%d:%d"), t.GetYear(), t.GetMonth(), t.GetDay(),
		t.GetHour(), t.GetMinute(), t.GetSecond());
	AfxMessageBox(str);
}
