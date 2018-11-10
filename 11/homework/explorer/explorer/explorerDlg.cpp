
// explorerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "explorer.h"
#include "explorerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CexplorerDlg 对话框



CexplorerDlg::CexplorerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXPLORER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CexplorerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CexplorerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CexplorerDlg 消息处理程序

/*
	信息包括文件名、类型(目录的类型是文件夹)、大小、修改日期等
*/

BOOL CexplorerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	/*插入列表标题*/
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST);
	pList->InsertColumn(0, _T("文件名"), 0, 160);
	pList->InsertColumn(1, _T("类型"), 0, 120);
	pList->InsertColumn(2, _T("大小"), 0, 120);
	pList->InsertColumn(3, _T("修改日期"), 0, 120);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CexplorerDlg::OnPaint()
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
HCURSOR CexplorerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#include <io.h>
#include <AtlBase.h>
void CexplorerDlg::OnOK()
{
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST);
	/*直接使用宽字符串 即可以不用进行字符串的转换*/
	struct _wfinddata_t c_file;
	intptr_t hFile;
	CString szAddr;
	GetDlgItemText(IDC_ADDR, szAddr);

	/*清理下列表*/
	pList->DeleteAllItems();
	
	if ((hFile = _wfindfirst(szAddr + _T("*.*"), &c_file)) == -1L)
		return;
	int i = 0;
	USES_CONVERSION;// 或者使用_bstr_t 类进行转换
	// 混合 | , 判断使用 if(c_file.attrib & _A_HIDDEN) , 删除属性 c_file.attrib =~_A_HIDDEN
	CString str;
	do
	{
		if (!(c_file.attrib & _A_HIDDEN))
		{
			pList->InsertItem(i, c_file.name);
			if (c_file.attrib & _A_SUBDIR)
				pList->SetItemText(i, 1, _T("文件夹"));
			else
			{
				//找出文件的后缀名
				str = c_file.name;
				int n = str.ReverseFind(_T('.'));
				if (n > 0)
					pList->SetItemText(i, 1, str.Mid(n+1) + _T(" 文件"));

				//文件大小 用进1 的方法 显示为KB
				str.Format(_T("%d"), (c_file.size+1023)/1024);
				pList->SetItemText(i, 2, str + _T(" KB"));

				COleDateTime time(c_file.time_write);
				str.Format(_T("%d/%d/%d %d:%d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute());
				pList->SetItemText(i, 3, str);

			}
			i++;
		}
			

		
	} while (_wfindnext(hFile, &c_file) == 0);


	/*窄字符串的使用 注意取出文件名的时候要进行字符串的转换*/
	//CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST);
	//struct _finddata_t c_file;
	//intptr_t hFile;
	//if ((hFile = _findfirst("C:\\*.*", &c_file)) == -1L)
	//	return;
	//int i = 0;
	//USES_CONVERSION;// 或者使用_bstr_t 类进行转换
	//// 混合 | , 判断使用 if(c_file.attrib & _A_HIDDEN) , 删除属性 c_file.attrib =~_A_HIDDEN
	//do
	//{
	//	if(!(c_file.attrib & _A_HIDDEN))
	//		pList->InsertItem(i++, A2T(c_file.name));

	//	
	//} while (_findnext(hFile, &c_file) == 0);

	//关闭查找句柄
	_findclose(hFile);

}
