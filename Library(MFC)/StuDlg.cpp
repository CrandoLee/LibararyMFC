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
	ON_BN_CLICKED(IDC_BUTTON1, &StuDlg::OnQueryBook)
	ON_BN_CLICKED(IDC_BUTTON2, &StuDlg::OnBorrowBook)
	ON_MESSAGE(WM_CHANEG_STATE,&StuDlg::OnChangeState)
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

afx_msg LRESULT  StuDlg::OnChangeState(WPARAM wParam, LPARAM lParam)
{
	if (m_bIsShow == false)
	{
		m_bIsShow = true;
		this->ShowWindow(true);
	}
	return true;
}

void StuDlg::OnQueryBook()
{
	QueryBookDlg *queryBookDlg = new QueryBookDlg();
	queryBookDlg->m_parentHwnd = this->GetSafeHwnd();
	queryBookDlg->Create(IDD_QUERYDLG);
	queryBookDlg->ShowWindow(true);
	this->ShowWindow(false);
	m_bIsShow = false;

}


void StuDlg::OnBorrowBook()
{
	BorrowBookDlg *borrowBookDlg = new BorrowBookDlg();
	borrowBookDlg->m_parentHwnd = this->GetSafeHwnd();
	borrowBookDlg->Create(IDD_BORROWDLG);
	borrowBookDlg->ShowWindow(true);
	this->ShowWindow(false);
	m_bIsShow = false;
}
