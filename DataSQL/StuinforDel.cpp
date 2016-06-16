// StuinforDel.cpp : 实现文件
//

#include "stdafx.h"
#include "DataSQL.h"
#include "StuinforDel.h"
#include "afxdialogex.h"
#include "afxdb.h"
#include "mianMenu.h"

// CStuinforDel 对话框

IMPLEMENT_DYNAMIC(CStuinforDel, CDialogEx)

CStuinforDel::CStuinforDel(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStuinforDel::IDD, pParent)
{

}

CStuinforDel::~CStuinforDel()
{
}

void CStuinforDel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStuinforDel, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStuinforDel::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CStuinforDel::OnBnClickedCancel)
END_MESSAGE_MAP()


// CStuinforDel 消息处理程序


void CStuinforDel::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CString id;
	GetDlgItemText(IDC_ID, id);
	CDatabase db;
	CString str1; 
	str1.Format(_T("DELETE FROM StuInfo WHERE SNO='%s'"), id);
	CString str2; 
	//判断该记录是否存在 
	str2.Format(_T("SELECT * FROM StuInfo WHERE SNO='%s'"),id);
	db.Open(_T("studentinfor"));
	CRecordset rec(&db); 
	rec.Open(CRecordset::forwardOnly,str2 , CRecordset::readOnly);
	//查询记录是否存在 
	if(rec.GetRecordCount()>0) 
	{ 
		rec.Close();
		db.ExecuteSQL(str1);
		MessageBox(_T("删除数据成功"));
		//MessageBox(str1, NULL, MB_OK | MB_ICONINFORMATION);
		CDialogEx::OnOK();
		CStuinforDel dlg;
		dlg.DoModal();
		CDialogEx::OnOK();
		
	}
	else { 
		 MessageBox(_T("对不起,要删除的学生信息不存在"));
		 CDialogEx::OnOK();
		 CStuinforDel dlg;
		 dlg.DoModal();
		 CDialogEx::OnOK();
 }
}


void CStuinforDel::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	mianMenu dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
	
}
