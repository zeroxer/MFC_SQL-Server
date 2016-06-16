// addstuinfo.cpp : 实现文件
//

#include "stdafx.h"
#include "DataSQL.h"
#include "DataSQLDlg.h"
#include "addstuinfo.h"
#include "afxdialogex.h"
#include "mianMenu.h"
#include "afxdb.h"


// addstuinfo 对话框

IMPLEMENT_DYNAMIC(addstuinfo, CDialogEx)

addstuinfo::addstuinfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(addstuinfo::IDD, pParent)
{

}

addstuinfo::~addstuinfo()
{
}

void addstuinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(addstuinfo, CDialogEx)
	ON_BN_CLICKED(IDOK, &addstuinfo::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &addstuinfo::OnBnClickedCancel)
END_MESSAGE_MAP()


// addstuinfo 消息处理程序


void addstuinfo::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码

	CString id = NULL, name = NULL, age = NULL, major = NULL;
	GetDlgItemText(IDC_ID_STU, id);
	GetDlgItemText(IDC_NAME_STU, name);
	GetDlgItemText(IDC_AGE_STU, age);
	GetDlgItemText(IDC_MAJOR_STU, major);
	CString str;
	CString str2;
	CDatabase db;
	if (id != "" || name != "" || age != "" || major != "")
	{
		try
		{
			str.Format(_T("INSERT INTO StuInfo(SNO,SNAME,SAGE,SDEPT) values('%s','%s','%s','%s')"), id, name, age, major);
			str2.Format(_T("SELECT * FROM StuInfo WHERE SNO='%s'"), id);
			db.Open(_T("studentinfor"));
			CRecordset rec(&db);
			rec.Open(CRecordset::forwardOnly, str2, CRecordset::readOnly);
			if (rec.GetRecordCount()>0)
				//如果记录集中的个数不为0,说明该学生信息已存在,(以学号为主键) 
			{
				MessageBox(_T("对不起,要添加的学生信息已存在"));
				return;
			}
			else
			{
			rec.Close();
			db.ExecuteSQL(str);
			str.Format(_T("添加[%s]成功！"), name);
			//MessageBox(str, NULL, MB_OK | MB_ICONINFORMATION);
			MessageBox(str);
			CDialogEx::OnCancel();
			addstuinfo dlg;
			dlg.DoModal();
			CDialogEx::OnCancel();
			}

		}
		catch (CDBException *e)
		{
			AfxMessageBox(e->m_strError);
			return;
		}
	}
	else
	{
		str.Format(_T("请输入有效数据！"));
		//MessageBox(str, NULL, MB_OK | MB_ICONINFORMATION);
		CDialogEx::OnCancel();
		addstuinfo dlg;
		dlg.DoModal();
	}


}


void addstuinfo::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	mianMenu dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
}
