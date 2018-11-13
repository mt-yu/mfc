
// explorerDlg.h : 头文件
//

#pragma once


// CexplorerDlg 对话框
class CexplorerDlg : public CDialogEx
{

	//inline static BOOL IsHidden(const CFileFind &ff)
	//{
	//	if (ff.IsHidden())
	//		return TRUE;
	//	else if (ff.IsDots())
	//		return TRUE;
	//	else
	//		return FALSE;
	//}


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
