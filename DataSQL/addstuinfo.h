#pragma once


// addstuinfo 对话框

class addstuinfo : public CDialogEx
{
	DECLARE_DYNAMIC(addstuinfo)

public:
	addstuinfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~addstuinfo();

// 对话框数据
	enum { IDD = IDD_ADD_STU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
