#pragma once


// CSqlOut 对话框

class CSqlOut : public CDialogEx
{
	DECLARE_DYNAMIC(CSqlOut)

public:
	CSqlOut(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSqlOut();

// 对话框数据
	enum { IDD = IDD_SQL_EXE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
