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
END_MESSAGE_MAP()


// AdminDlg ��Ϣ�������

//�˳���¼
void AdminDlg::OnCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}
