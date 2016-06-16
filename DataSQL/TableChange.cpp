// TableChange.cpp : 实现文件
//

#include "stdafx.h"
#include "DataSQL.h"
#include "TableChange.h"
#include "afxdialogex.h"
#include "mianmenu.h"
#include "afxdb.h"

// CTableChange 对话框

IMPLEMENT_DYNAMIC(CTableChange, CDialogEx)

CTableChange::CTableChange(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTableChange::IDD, pParent)
{

}

CTableChange::~CTableChange()
{
}

void CTableChange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTableChange, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CTableChange::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CTableChange::OnBnClickedOk)
	//ON_EN_CHANGE(IDC_VALUE_CHANGE, &CTableChange::OnEnChangeValueChange)
END_MESSAGE_MAP()


// CTableChange 消息处理程序


void CTableChange::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	mianMenu dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
}


void CTableChange::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CString option;
	CString value;
	CDatabase db;
	CString str;
	GetDlgItemText(IDC_OPTION_CHANGE, option);
	GetDlgItemText(IDC_VALUE_CHANGE, value);
	if (value != "")
	{
		if (option == "添加")
		{
			try
			{
				str.Format(_T("ALTER TABLE Class ADD %s nchar(20)"), value);
				db.Open(_T("studentinfor"));
				db.ExecuteSQL(str);
				str.Format(_T("添加[%s]列成功！"), value);
				MessageBox(str);
			}
			catch (CDBException* e)
			{
				MessageBox(_T("添加失败!参数已存在"));
			}
		}
		else if (option == "删除")
		{
			str.Format(_T("ALTER TABLE Class DROP COLUMN %s"), value);
			db.Open(_T("studentinfor"));
			try
			{
				db.ExecuteSQL(str);
				str.Format(_T("删除[%s]列成功！"), value);
				MessageBox(str);
			}
			catch (CDBException* e)
			{
				MessageBox(_T("删除失败!目标列不存在"));
			}
		}
		else
		{
			MessageBox(_T("请选择操作"));
		}
	}
	else
	{
		MessageBox(_T("请填写参数"));
	}
		CTableChange dlg;
		dlg.DoModal();
		CDialogEx::OnOK();
}


/*void CTableChange::OnEnChangeValueChange()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
*/