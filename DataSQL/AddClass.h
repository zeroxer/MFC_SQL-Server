#pragma once


// CAddClass 对话框

class CAddClass : public CDialogEx
{
	DECLARE_DYNAMIC(CAddClass)

public:
	CAddClass(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddClass();

// 对话框数据
	enum { IDD = IDD_ADD_CLASS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
