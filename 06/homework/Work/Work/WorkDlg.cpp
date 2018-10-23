
// WorkDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Work.h"
#include "WorkDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWorkDlg 对话框



CWorkDlg::CWorkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWorkDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWorkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWorkDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CWorkDlg::OnBnClickedCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CWorkDlg::OnLvnItemchangedList1)

	//消息（ID， 函数）
	ON_BN_CLICKED(IDC_btnAdd, &CWorkDlg::OnBnClickedbtnadd)
	ON_BN_CLICKED(IDC_btnDel, &CWorkDlg::OnBnClickedbtndel)
	ON_BN_CLICKED(IDC_btnLoad, &CWorkDlg::OnBnClickedbtnload)
	ON_BN_CLICKED(IDC_btnSave, &CWorkDlg::OnBnClickedbtnsave)
END_MESSAGE_MAP()


// CWorkDlg 消息处理程序

BOOL CWorkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//打开界面之前的初始化

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	/*	一下方法为绑定到对应的list对象上。
		CListCtrl	list;
		list.InsertColumn(0, _T("工号"),LVCFMT_LEFT,100);
	*/

	CListCtrl *pList = (CListCtrl *) GetDlgItem(IDC_LIST1);
	pList->InsertColumn(0, _T("工号"), LVCFMT_LEFT, 100);	//插入字段名(列，内容，对齐，长度)
	pList->InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 150);
	pList->InsertColumn(2, _T("工资"), LVCFMT_LEFT, 150);
	pList->InsertColumn(3, _T("日期"), LVCFMT_LEFT, 200);
	//设置列表背景颜色
	pList->SetBkColor(RGB(205, 226, 252));	
	pList->SetTextColor(RGB(0, 0, 255));
	pList->SetTextBkColor(RGB(205, 226, 252));
	
	// 添加扩展风格，如打勾
	pList->SetExtendedStyle(LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT); 


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CWorkDlg::OnPaint()
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
HCURSOR CWorkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWorkDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CWorkDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
}


// 检查号码是否存在, 返回flase代表可插入，返回true代表不可以插入
bool CWorkDlg::CheckNumber(LPCTSTR szNumber)
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);
	int i = 0, nCount = pList->GetItemCount();

	while (i < nCount)
	{
		if (pList->GetItemText(i, 0) == szNumber)
		{
			AfxMessageBox(_T("该号码已存在，请重新输入！"));
			this->SetFocus();
			//SetDlgItemText(IDC_EDIT2, NULL);
			return true;
		}
		++i;
	}
	return false;
}


void CWorkDlg::OnBnClickedbtnadd()
{
	// 排除重复工号的功能，当重复的工号禁止插入（已存在！） 需要实现

	CString str;
	GetDlgItemText(IDC_EDIT1, str);

	if (CheckNumber(str))
		return;
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);
	int i = pList->GetItemCount();

	GetDlgItemText(IDC_EDIT1, str);	//获取IDC_EDIT1 中输入的文字给str
	pList->InsertItem(i, str);
	GetDlgItemText(IDC_EDIT2, str);
	pList->SetItemText(i, 1, str);
	GetDlgItemText(IDC_EDIT3, str);
	pList->SetItemText(i, 2, str);
	GetDlgItemText(IDC_DATE, str);
	pList->SetItemText(i, 3, str);


}




/*

//多选标志

GetSelectedCount()
GetNextSelectdItem()
GetFirstSelectedItemPosition()


if (!pList->GetSelectedCount())
{
AfxMessageBox(_T("请选中一行再删除！"));
return;
}
*/

void CWorkDlg::OnBnClickedbtndel()
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);

	//单选标志
	int nSel = pList->GetSelectionMark();
	if (nSel < 0)
	{
		AfxMessageBox(_T("请选中一行再删除！"));
		return;
	}
	
	CString str = pList->GetItemText(nSel, 0);

	if (AfxMessageBox(_T("你确定要删除 ") + str + _T(" 吗？"), MB_YESNO) == IDYES)
		pList->DeleteItem(nSel);

}


void CWorkDlg::OnBnClickedbtnload()
{

}


void CWorkDlg::OnBnClickedbtnsave()
{
	CFile file;
	if (!file.Open(_T("./Worker.dat"), CFile::modeCreate | CFile::modeWrite))
	{
		AfxMessageBox(_T("保存文件时候失败！"));
		return;
	}


	//file.Write();

	file.Close();

}



