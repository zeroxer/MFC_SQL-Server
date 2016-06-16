// AddClass.cpp : 实现文件
//

#include "stdafx.h"
#include "DataSQL.h"
#include "AddClass.h"
#include "afxdialogex.h"
#include "mianMenu.h"
#include "afxdb.h"


// CAddClass 对话框

IMPLEMENT_DYNAMIC(CAddClass, CDialogEx)

CAddClass::CAddClass(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddClass::IDD, pParent)
{

}

CAddClass::~CAddClass()
{
}

void CAddClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddClass, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddClass::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CAddClass::OnBnClickedCancel)
END_MESSAGE_MAP()


// CAddClass 消息处理程序


void CAddClass::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CString id = NULL, name = NULL, teacher= NULL;
	GetDlgItemText(IDC_CLASS_ID, id);
	GetDlgItemText(IDC_CLASS_NAME, name);
	GetDlgItemText(IDC_CLASS_TEACHER, teacher);
	CString str;
	CString str2;
	CDatabase db;
	if ((id != "" )&& (name != "" )&&( teacher != ""))
	{
		try
		{
			str.Format(_T("INSERT INTO Class(CNO,CNAME,TEACHER) values('%s','%s','%s')"), id, name, teacher);
			str2.Format(_T("SELECT * FROM Class WHERE CNO='%s'"), id);
			db.Open(_T("studentinfor"));
			CRecordset rec(&db);
			rec.Open(CRecordset::forwardOnly, str2, CRecordset::readOnly);
			if (rec.GetRecordCount()>0)
				//如果记录集中的个数不为0,说明该学生信息已存在,(以学号为主键) 
			{
				MessageBox(_T("对不起,要添加的课程信息已存在"));
				return;
			}
			else
			{
				rec.Close();
				db.ExecuteSQL(str);
				str.Format(_T("添加课程[%s]成功！"), name);
				MessageBox(str);
				CDialogEx::OnCancel();
				CAddClass dlg;
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
		MessageBox(str, NULL, MB_OK | MB_ICONINFORMATION);
		CDialogEx::OnCancel();
		CAddClass dlg;
		dlg.DoModal();
	}

	CDialogEx::OnOK();
}


void CAddClass::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	mianMenu dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
	CDialogEx::OnCancel();
}
