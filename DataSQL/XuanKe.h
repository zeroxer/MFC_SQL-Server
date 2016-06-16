#pragma once


// CXuanKe dialog

class CXuanKe : public CDialogEx
{
	DECLARE_DYNAMIC(CXuanKe)

public:
	CXuanKe(CWnd* pParent = NULL);   // standard constructor
	virtual ~CXuanKe();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XUANKE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
