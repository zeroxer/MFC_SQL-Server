#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CSqlExe 对话框

class CSqlExe : public CDialogEx
{
	DECLARE_DYNAMIC(CSqlExe)

public:
	CSqlExe(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSqlExe();

// 对话框数据
	enum { IDD = IDD_SQL_EXE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedchaxun();
	afx_msg void OnLbnSelchangeListOut();
	CListCtrl myList;
	afx_msg void OnLvnItemchangedListOut(NMHDR *pNMHDR, LRESULT *pResult);
};
