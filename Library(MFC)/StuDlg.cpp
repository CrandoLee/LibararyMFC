// StuDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "StuDlg.h"
#include "afxdialogex.h"


// StuDlg �Ի���

IMPLEMENT_DYNAMIC(StuDlg, CDialogEx)

StuDlg::StuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(StuDlg::IDD, pParent)
{

}

StuDlg::~StuDlg()
{
}

void StuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StuDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON6, &StuDlg::OnLogout)
END_MESSAGE_MAP()


// StuDlg ��Ϣ�������


void StuDlg::OnCancel()
{
	
	exit(0);
}

//�˳���¼
void StuDlg::OnLogout()
{
	OnCancel();
}
