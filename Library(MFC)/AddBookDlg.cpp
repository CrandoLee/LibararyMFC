// AddBookDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "AddBookDlg.h"
#include "afxdialogex.h"


// AddBookDlg �Ի���

IMPLEMENT_DYNAMIC(AddBookDlg, CDialogEx)

AddBookDlg::AddBookDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddBookDlg::IDD, pParent)
{

}

AddBookDlg::~AddBookDlg()
{
}

void AddBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddBookDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &AddBookDlg::OnCancel)
END_MESSAGE_MAP()


// AddBookDlg ��Ϣ�������


void AddBookDlg::OnCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
	//SendMessage()
}
