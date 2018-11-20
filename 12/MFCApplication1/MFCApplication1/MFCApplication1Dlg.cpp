
// MFCApplication1Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Connect, &CMFCApplication1Dlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_IMAGE, &CMFCApplication1Dlg::OnBnClickedImage)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedConnect()
{
	//光标等待 的两种方法
	CWaitCursor cwcur;	//构造时忙， 析构时恢复
	Sleep(3000);

	//theApp.DoWaitCursor(1);
	//Sleep(3000);
	//theApp.DoWaitCursor(0);
}


void CMFCApplication1Dlg::OnOK()
{
	CWnd *p = GetFocus();
	if (!p)
		return;
	int nID = p->GetDlgCtrlID();
	if (nID <= IDC_START || nID > IDC_END)
		//GetDlgItem(IDC_END)->SetFocus();
		GotoDlgCtrl(GetDlgItem(IDC_END));	//与SetFocus()类似
	else
		PrevDlgCtrl();

}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	//CColorDialog dlg(0, 0, GetDesktopWindow());// 不附着于之前的窗口

	//COLORREF C = RGB(255, 255, 0);

	CColorDialog dlg(m_colBack);
	if (dlg.DoModal() == IDCANCEL)
		return;

	//获取到设置的颜色
	m_colBack = dlg.GetColor();
	// 设置背景颜色
	SetBackgroundColor(m_colBack);

	//TRACE(_T("RGB value of the selected color - red = %u, ")
	//	_T("green = %u, blue = %u\n"),
	//	GetRValue(color), GetGValue(color), GetBValue(color));

}


void CMFCApplication1Dlg::OnBnClickedImage()
{
	SetBackgroundImage(IDB_BITMAP1, BACKGR_TOPLEFT);
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	CFontDialog dlg;
	dlg.DoModal();
}
