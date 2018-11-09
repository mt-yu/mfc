
// calcDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calc.h"
#include "calcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcalcDlg 对话框



CcalcDlg::CcalcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcalcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CcalcDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CcalcDlg 消息处理程序

BOOL CcalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_OPER);
	pCombo->AddString(_T("+"));
	pCombo->AddString(_T("-"));
	pCombo->AddString(_T("*"));
	pCombo->AddString(_T("/"));
	pCombo->AddString(_T("%"));
	pCombo->SetCurSel(0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalcDlg::OnPaint()
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
HCURSOR CcalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalcDlg::OnBnClickedOk()
{
	//获取对话框中的值
	CString szOper, str;
	GetDlgItemText(IDC_OPER, szOper);

	GetDlgItemText(IDC_LEFT, str);
	double fLeft = _tstof(str);
	
	GetDlgItemText(IDC_RIGHT, str);
	double fRight = _tstof(str);


	//根据对应的值进行相应的计算
	switch (szOper[0]) //switch 不能比较字符串，必须能转换为整数
	{
	case _T('+'):
		str.Format(_T("%lf"), fLeft + fRight);
		break;
	case _T('-'):
		str.Format(_T("%lf"), fLeft - fRight);
		break;
	case _T('*'):
		str.Format(_T("%lf"), fLeft * fRight);
		break;
	case _T('/'):
		if (fRight == 0.0)
		{
			str = _T("除数不能为0");
		}
		else
			str.Format(_T("%lf"), fLeft / fRight);
		break;
	case _T('%'):
		str = _T("该功能暂时不支持");
		//str.Format(_T("%lf"), (int)fLeft % (int)fRight);
		break;
	}

	SetDlgItemText(IDC_RESULT, str);
}
