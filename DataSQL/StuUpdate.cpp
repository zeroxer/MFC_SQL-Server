// StuUpdate.cpp : 实现文件
//

#include "stdafx.h"
#include "DataSQL.h"
#include "StuUpdate.h"
#include "afxdialogex.h"
#include "afxdb.h"
#include "mianMenu.h"

// CStuUpdate 对话框

IMPLEMENT_DYNAMIC(CStuUpdate, CDialogEx)

CStuUpdate::CStuUpdate(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStuUpdate::IDD, pParent)
{

}

CStuUpdate::~CStuUpdate()
{
}

void CStuUpdate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStuUpdate, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStuUpdate::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_OPTION, &CStuUpdate::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_NAME_STU, &CStuUpdate::OnEnChangeNameStu)
	ON_BN_CLICKED(IDCANCEL, &CStuUpdate::OnBnClickedCancel)
END_MESSAGE_MAP()


// CStuUpdate 消息处理程序


void CStuUpdate::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CString id;
	CString option;
	CString str1;
	CString str2;
	GetDlgItemText(IDC_ID, id);
	GetDlgItemText(IDC_OPTION, option);
	GetDlgItemText(IDC_VALUE, str2);
	if (id==""||option==""||str2=="")
	{
		MessageBox(_T("输入无效！请重新输入"));
		CDialogEx::OnOK();
		CStuUpdate dlg;
		dlg.DoModal();
		CDialogEx::OnOK();
	}
	else
	{
		if (option == "姓名")
		{
			str1 = "SNAME";
		}
		else if (option == "年龄")
		{
			str1 = "SAGE";
		}
		else if (option == "专业")
		{
			str1 = "SDEPT";
		}

		CDatabase db;
		CString str;
		str.Format(_T("UPDATE StuInfo SET %s = '%s' WHERE SNO='%s'"), str1, str2, id);

		//判断该记录是否存在 
		str2.Format(_T("SELECT * FROM StuInfo WHERE SNO='%s'"), id);
		db.Open(_T("studentinfor"));
		CRecordset rec(&db);
		rec.Open(CRecordset::forwardOnly, str2, CRecordset::readOnly);
		//查询记录是否存在 
		if (rec.GetRecordCount() > 0)
		{
			rec.Close();
			db.ExecuteSQL(str);
			MessageBox(_T("修改数据成功"));

			CDialogEx::OnOK();
			CStuUpdate dlg;
			dlg.DoModal();
			CDialogEx::OnOK();

		}
		else {
			MessageBox(_T("对不起,要修改的学生信息不存在"));
			CDialogEx::OnOK();
			CStuUpdate dlg;
			dlg.DoModal();
			CDialogEx::OnOK();
		}
	}
}


void CStuUpdate::OnCbnSelchangeCombo1()
{

	// TODO:  在此添加控件通知处理程序代码
}


void CStuUpdate::OnEnChangeNameStu()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CStuUpdate::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	mianMenu dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
	CDialogEx::OnCancel();
}
