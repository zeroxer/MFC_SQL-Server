#pragma once


// CTableChange 对话框

class CTableChange : public CDialogEx
{
	DECLARE_DYNAMIC(CTableChange)

public:
	CTableChange(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTableChange();

// 对话框数据
	enum { IDD = IDD_TABLE_CHANGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeValueChange();
};
