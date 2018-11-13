
// explorerDlg.h : 头文件
//

#pragma once


// CexplorerDlg 对话框
class CexplorerDlg : public CDialogEx
{

	inline static BOOL IsHidden(const WIN32_FIND_DATA &c_file)
	{
		if (c_file.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
			return TRUE;
		else if (!_tcscmp(c_file.cFileName, _T(".")))	//strcmp 只支持char 类型的  所以使用_tcscmp 类型的比较函数
			return TRUE;
		else if (!_tcscmp(c_file.cFileName, _T("..")))
			return TRUE;
		else
			return FALSE;
	}


	static LPCTSTR  m_weeks[];
// 构造
public:
	CexplorerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXPLORER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
};
