
// NotepadDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Notepad.h"
#include "NotepadDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNotepadDlg 对话框



CNotepadDlg::CNotepadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NOTEPAD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNotepadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNotepadDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_APP_EXIT, &CNotepadDlg::OnAppExit)
	ON_WM_DROPFILES()
	ON_COMMAND(ID_APP_ABOUT, &CNotepadDlg::OnAppAbout)
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_EDIT_CLEAR, &CNotepadDlg::OnEditClear)
	ON_COMMAND(ID_EDIT_COPY, &CNotepadDlg::OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, &CNotepadDlg::OnEditCut)
	ON_COMMAND(ID_EDIT_DATA, &CNotepadDlg::OnEditData)
	ON_COMMAND(ID_EDIT_FIND, &CNotepadDlg::OnEditFind)
	ON_COMMAND(ID_EDIT_FINDNEXT, &CNotepadDlg::OnEditFindnext)
	ON_COMMAND(ID_EDIT_GO, &CNotepadDlg::OnEditGo)
	ON_COMMAND(ID_EDIT_PASTE, &CNotepadDlg::OnEditPaste)
	ON_COMMAND(ID_EDIT_REPLACE, &CNotepadDlg::OnEditReplace)
	ON_COMMAND(ID_EDIT_UNDO, &CNotepadDlg::OnEditUndo)
	ON_COMMAND(ID_EDIT_SELECT_ALL, &CNotepadDlg::OnEditSelectAll)
	ON_WM_DESTROY()
	ON_COMMAND(ID_FORMAT_FONT, &CNotepadDlg::OnFormatFont)
	ON_COMMAND(ID_FILE_CLOSE, &CNotepadDlg::OnFileClose)
	ON_COMMAND(ID_FILE_NEW, &CNotepadDlg::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CNotepadDlg::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CNotepadDlg::OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, &CNotepadDlg::OnFileSaveAs)
END_MESSAGE_MAP()


// CNotepadDlg 消息处理程序

BOOL CNotepadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//加载快捷键  loadAccelerators() 函数用于加载指定的快捷键 表

	m_pTest = new char[29];
	CRect rect;
	
	rect.left = theApp.GetProfileInt(_T("RECT"), _T("LEFT"), 0);
	rect.right = theApp.GetProfileInt(_T("RECT"), _T("RIGHT"), 0);
	rect.bottom = theApp.GetProfileInt(_T("RECT"), _T("BOTTOM"), 0);
	rect.top = theApp.GetProfileInt(_T("RECT"), _T("TOP"), 0);
	MoveWindow(rect, false);

	LOGFONT lf;
	LPBYTE pData = NULL;
	UINT nSize = sizeof(LOGFONT);
	theApp.GetProfileBinary(_T("SETING"), _T("Font"), &pData, &nSize);
	m_font.CreateFontIndirect((LOGFONT*)pData);
	delete[] pData;		//需要手动释放该段内存
	GetDlgItem(IDC_TEXT)->SetFont(&m_font, FALSE);
	CString str = theApp.GetProfileString(_T("SETING"), _T("CAPTION"));
	SetWindowText(str);

	CWnd *p = GetDlgItem(IDC_TEXT);
	if (p)
	{
		CRect rect;
		GetClientRect(rect);
		p->MoveWindow(rect);
	}





	HACCEL m_hAcc = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAIN));

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

void CNotepadDlg::OnPaint()
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
HCURSOR CNotepadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNotepadDlg::OnOK()
{
	//ID_APP_EXIT
	//CDialogEx::OnOK();
}


void CNotepadDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnCancel();
}


void CNotepadDlg::OnAppExit()
{
	EndDialog(ID_APP_EXIT);
}


void CNotepadDlg::ReadAnsi(CFile& file)
{
	file.Seek(0, CFile::begin);
	char buff[1024];
	CString str;
	UINT nRet = 0; //三种文件: ANSI(没有文件头) Unicode UTF-8（有文件头）
	while (nRet = file.Read(buff, sizeof(buff) - 1))
	{
		buff[nRet] = _T('\0');
		str += buff;
	}

	SetDlgItemText(IDC_TEXT, str);
}


void CNotepadDlg::ReadUnicode(CFile& file)
{
	file.Seek(2, CFile::begin);
	LONGLONG nLen = file.GetLength();		//获取文件长度
	TCHAR *p = new TCHAR[nLen / 2 + 1];
	nLen = file.Read(p, nLen);
	p[nLen/2] = _T('\0');
	SetDlgItemText(IDC_TEXT, p);
	delete[]p;
}


void CNotepadDlg::ReadUTF_8(CFile& file)
{
	
	file.Seek(3, CFile::begin);
	LONGLONG nLen =file.GetLength();		//获取文件长度
	char *p = new char[nLen + 1];
	nLen = file.Read(p, nLen);
	p[nLen] = '\0';
	TCHAR *pText = new TCHAR[nLen / 2 + 2];

	nLen = MultiByteToWideChar(CP_UTF8, NULL, p, -1, pText, nLen/2+2);

	SetDlgItemText(IDC_TEXT, pText);
	delete []p;
	delete []pText;
}


//启动Acccept Files= True 拖放文件后进入该消息
void CNotepadDlg::OnDropFiles(HDROP hDropInfo)
{
	CDialogEx::OnDropFiles(hDropInfo);
	TCHAR sFile[256];
	int nCount = DragQueryFile(hDropInfo, 0, sFile, _countof(sFile));
	CFile file;// 打开的一般可能是非unicode ， 而你的界面是unicode
	//SetDlgItemInt(...)
	if (!file.Open(sFile, CFile::modeRead))
	{
		AfxMessageBox(_T("打开文件时失败"));
		return;
	}
	if(file.Read(sFile, 2) == 2)
	{	
		switch (sFile[0])
		{
		case 0xBBEF:
			//if (sFile)
			ReadUTF_8(file);
			return;
		case 0xFEFF:
			ReadUnicode(file);
			return;	
		}
		
	}
	ReadAnsi(file);
	
}
/*  多文档的文件拖入  类似photoshop 拖入多文档一次打开
//DragQueryFile()检索从成功的拖放操作中拖放的文件的名称
TCHAR sFile[256];
//sizeof(sFile);

// nCount 为总拖入文件的数量
int nCount = DragQueryFile(hDropInfo, -1, NULL, 0);
int i = 0;

while (i < nCount)
{
// 得到多个拖入文件的文件名
DragQueryFile(hDropInfo, i, sFile, _countof(sFile));
++i;
}
*/

void CNotepadDlg::OnAppAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
	
}


void CNotepadDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	//获得这个控件
	//CWnd *p = GetDlgItem(IDC_TEXT);
	CEdit *p;
	p = (CEdit*)GetDlgItem(IDC_TEXT);
	if (p)
	{
		CRect rect;
		GetClientRect(rect);
		//更改位置和尺寸
		p->MoveWindow(rect);
		//强制转换为派生CEdit类
	}

}

//系统关闭消息
void CNotepadDlg::OnClose()
{
	EndDialog(IDCANCEL);
	//CDialogEx::OnClose();
}


void CNotepadDlg::OnEditClear()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->Clear();

}


void CNotepadDlg::OnEditCopy()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->Copy();
}


void CNotepadDlg::OnEditCut()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->Cut();
}

/*插入日期函数*/
void CNotepadDlg::OnEditData()
{
	COleDateTime time = COleDateTime::GetCurrentTime();
	CString str = time.Format(_T("%H:%M %Y/%m/%d %W"));

	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->ReplaceSel(str, 1);
	//SetDlgItemText(IDC_TEXT, str);
}


void CNotepadDlg::OnEditFind()
{
	// TODO: 在此添加命令处理程序代码
}


void CNotepadDlg::OnEditFindnext()
{
	// TODO: 在此添加命令处理程序代码
}


void CNotepadDlg::OnEditGo()
{
	// TODO: 在此添加命令处理程序代码
}


void CNotepadDlg::OnEditPaste()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->Paste();
}


void CNotepadDlg::OnEditReplace()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
}


void CNotepadDlg::OnEditUndo()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->Undo();
}


void CNotepadDlg::OnEditSelectAll()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->SetSel(0, -1);
}


BOOL CNotepadDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (WM_KEYFIRST <= pMsg->message&&pMsg->message <= WM_KEYLAST)

	{

		HACCEL hAccel = m_hAcc;

		if (hAccel && ::TranslateAccelerator(m_hWnd, hAccel, pMsg))

			return TRUE;

	}
	return CDialogEx::PreTranslateMessage(pMsg);
}



// 用于退出时记录数据
void CNotepadDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	CRect rect;
	GetWindowRect(&rect);
	// ini 配置文件的写入
							// 节点   等号左边     等号右边
	theApp.WriteProfileInt(_T("RECT"), _T("LEFT"), rect.left);
	theApp.WriteProfileInt(_T("RECT"), _T("RIGHT"), rect.right);
	theApp.WriteProfileInt(_T("RECT"), _T("BOTTOM"), rect.bottom);
	theApp.WriteProfileInt(_T("RECT"), _T("TOP"), rect.top);
	//theApp.WriteProfileString(_T("SETING"), _T("CAPTION"), _T("我的记事本"));

	if (m_font.GetSafeHandle())
	{
		LOGFONT lf;
		m_font.GetLogFont(&lf);
		theApp.WriteProfileBinary(_T("SETING"), _T("Font"), (LPBYTE)&lf, sizeof(lf));
	}
	//将结构体保存到.Ini 或 注册表

	delete[] m_pTest;
}


void CNotepadDlg::OnFormatFont()
{
	LOGFONT lf;

	CFont *pFont = GetFont();

	if (m_font.GetSafeHandle())
		//m_font.GetLogFont(&lf);
		pFont = &m_font;	//指向上次设置的
	else
	{
		pFont = GetFont();	//获取本对话框CWnd::GetFont
	}
	
	pFont->GetLogFont(&lf);
	CFontDialog dlg(&lf);
	if (dlg.DoModal() == IDCANCEL)
		return;

	m_font.DeleteObject();

	dlg.GetCurrentFont(&lf);
	m_font.CreateFontIndirect(&lf);

	GetDlgItem(IDC_TEXT)->SetFont(&m_font);


}


void CNotepadDlg::OnFileClose()
{

}


void CNotepadDlg::OnFileNew()
{

}


void CNotepadDlg::OnFileOpen()
{

	//过滤器
	LPCTSTR szFilter= _T("Text Files (*.txt)|*.txt|")
					  _T("All Files (*.*)|*.*||");



	CFileDialog dlg(TRUE, _T("txt"), NULL, OFN_ALLOWMULTISELECT, szFilter, this);
	if (dlg.DoModal() == IDCANCEL)
		return;
	CString szFile = dlg.GetPathName();
	CFile file;
	//file.Open(szFile);
}


void CNotepadDlg::OnFileSave()
{

}


void CNotepadDlg::OnFileSaveAs()
{

}


void CNotepadDlg::LoadFile(LPCTSTR sFile)
{
	// TODO: 在此处添加实现代码.
}
