#pragma once


// CStuQuery 对话框

class CStuQuery : public CDialogEx
{
	DECLARE_DYNAMIC(CStuQuery)

public:
	CStuQuery(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStuQuery();

// 对话框数据
	enum { IDD = IDD_STU_QUERY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
