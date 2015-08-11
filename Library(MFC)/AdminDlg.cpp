// AdminDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "AdminDlg.h"
#include "afxdialogex.h"


// AdminDlg �Ի���

IMPLEMENT_DYNAMIC(AdminDlg, CDialog)

AdminDlg::AdminDlg(CWnd* pParent /*=NULL*/)
	: CDialog(AdminDlg::IDD, pParent)
{

}

AdminDlg::~AdminDlg()
{
}

void AdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AdminDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON8, &AdminDlg::OnCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &AdminDlg::OnAddBook)
END_MESSAGE_MAP()


// AdminDlg ��Ϣ�������

//�˳���¼
void AdminDlg::OnCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}


void AdminDlg::OnAddBook()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	AddBookDlg* addBoolDlg = new AddBookDlg();
	addBoolDlg->Create(IDD_ADDBOOKDLG);
	addBoolDlg->ShowWindow(true);
	this->ShowWindow(false);
}
