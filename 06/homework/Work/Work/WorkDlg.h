
// WorkDlg.h : 头文件
//

#pragma once


// CWorkDlg 对话框
class CWorkDlg : public CDialogEx
{
// 构造
public:
	CWorkDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_WORK_DIALOG };

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
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedbtnadd();
	afx_msg void OnBnClickedbtndel();
	afx_msg void OnBnClickedbtnload();
	afx_msg void OnBnClickedbtnsave();
	// 检查号码是否存在
	bool CheckNumber(LPCTSTR szNumber);
};
