// SqlOut.cpp : 实现文件
//

#include "stdafx.h"
#include "DataSQL.h"
#include "SqlOut.h"
#include "afxdialogex.h"


// CSqlOut 对话框

IMPLEMENT_DYNAMIC(CSqlOut, CDialogEx)

CSqlOut::CSqlOut(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSqlOut::IDD, pParent)
{

}

CSqlOut::~CSqlOut()
{
}

void CSqlOut::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSqlOut, CDialogEx)
END_MESSAGE_MAP()


// CSqlOut 消息处理程序
