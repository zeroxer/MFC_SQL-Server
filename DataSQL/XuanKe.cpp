// XuanKe.cpp : implementation file
//

#include "stdafx.h"
#include "DataSQL.h"
#include "XuanKe.h"
#include "afxdialogex.h"
#include "afxdb.h"
#include "mianMenu.h"

// CXuanKe dialog

IMPLEMENT_DYNAMIC(CXuanKe, CDialogEx)

CXuanKe::CXuanKe(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_XUANKE, pParent)
{

}

CXuanKe::~CXuanKe()
{
}

void CXuanKe::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CXuanKe, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CXuanKe::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CXuanKe::OnBnClickedOk)
END_MESSAGE_MAP()


// CXuanKe message handlers


void CXuanKe::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	mianMenu dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
}


void CXuanKe::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString sid;
	CString cid;
	CString grade;
	CString name;
	CString age;
	CString major;
	CString option;
	CString value;
	CString str1;
	CString str2;
	GetDlgItemText(IDC_SID, sid);
	GetDlgItemText(IDC_CID, cid);
	

	CDatabase db;
	CString str;
	if (sid != ""&&cid != "")
	{
		str.Format(_T("SELECT GRADE FROM StuClass WHERE SNO='%s' and CNO = '%s'"), sid,cid);
		//str2.Format(_T("SELECT * FROM StuInfo WHERE %s='%s'"), str1, value);
		db.Open(_T("studentinfor"));
		CRecordset rect(&db);
		rect.Open(CRecordset::forwardOnly, str, CRecordset::readOnly);
		//查询记录是否存在 
		if (rect.GetRecordCount()>0)
		{
			short int i = 0;

			rect.GetFieldValue(i++, grade);

			SetDlgItemText(IDC_GRADE, grade);
		
			rect.Close();

		}
		else {
			MessageBox(_T("对不起,要查询的信息不存在"));
			CDialogEx::OnOK();
			CXuanKe dlg;
			dlg.DoModal();
			CDialogEx::OnOK();
		}
	}
	else
	{
		MessageBox(_T("要查询的信息不能为空！"));
	}
}
