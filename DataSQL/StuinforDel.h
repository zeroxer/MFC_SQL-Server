#pragma once


// CStuinforDel 对话框

class CStuinforDel : public CDialogEx
{
	DECLARE_DYNAMIC(CStuinforDel)

public:
	CStuinforDel(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStuinforDel();

// 对话框数据
	enum { IDD = IDD_STU_DEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
