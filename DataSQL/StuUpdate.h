#pragma once


// CStuUpdate 对话框

class CStuUpdate : public CDialogEx
{
	DECLARE_DYNAMIC(CStuUpdate)

public:
	CStuUpdate(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStuUpdate();

// 对话框数据
	enum { IDD = IDD_STUUPDATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnEnChangeNameStu();
	afx_msg void OnBnClickedCancel();
};
