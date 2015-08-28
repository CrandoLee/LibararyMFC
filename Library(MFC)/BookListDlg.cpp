// BookListDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "BookListDlg.h"
#include "afxdialogex.h"


// BookListDlg �Ի���

IMPLEMENT_DYNAMIC(BookListDlg, CDialogEx)

BookListDlg::BookListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(BookListDlg::IDD, pParent)
{

}

BookListDlg::~BookListDlg()
{
}

void BookListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_cListCtrl);
}


BEGIN_MESSAGE_MAP(BookListDlg, CDialogEx)
END_MESSAGE_MAP()


// BookListDlg ��Ϣ�������


void BookListDlg::OnCancel()
{
	::SendMessage(m_parentHwnd, WM_CHANEG_STATE, NULL, NULL);
	CDialogEx::OnCancel();
}



BOOL BookListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_cListCtrl.InsertColumn(0, _T("���"), LVCFMT_LEFT, 80);
	m_cListCtrl.InsertColumn(1, _T("����"), LVCFMT_LEFT, 100);
	m_cListCtrl.InsertColumn(2, _T("����"), LVCFMT_LEFT, 80);
	m_cListCtrl.InsertColumn(3, _T("ISBN"), LVCFMT_LEFT, 80);
	m_cListCtrl.InsertColumn(4, _T("������"), LVCFMT_LEFT, 80);
	m_cListCtrl.InsertColumn(5, _T("���"), LVCFMT_LEFT, 78);
	m_cListCtrl.InsertColumn(6, _T("����"), LVCFMT_LEFT, 79);

	//��ȡ�鼮
	vector<Book> books;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	m_dbUtil.SelectAllBook(books);
	vector<Book>::iterator vecIter;
	int i = 0, j = 0;
	int number = m_cListCtrl.GetItemCount();
	wstring wstrTemp;
	for (vecIter = books.begin(); vecIter != books.end(); vecIter++)
	{
		wchar_t chId[4] = { 0 };
		wsprintf(chId, _T("%d"), i + 1);
		m_cListCtrl.InsertItem(i, chId);
		m_cListCtrl.SetItemText(i, j++, chId);
		wstrTemp = m_stringConvert.s2ws(vecIter->GetBookName());
		m_cListCtrl.SetItemText(i, j++, wstrTemp.c_str());
		wstrTemp = m_stringConvert.s2ws(vecIter->GetAuthor());
		m_cListCtrl.SetItemText(i, j++, wstrTemp.c_str());
		wstrTemp = m_stringConvert.s2ws(vecIter->GetISBN());
		m_cListCtrl.SetItemText(i, j++, wstrTemp.c_str());
		wstrTemp = m_stringConvert.s2ws(vecIter->GetPub());
		m_cListCtrl.SetItemText(i, j++, wstrTemp.c_str());
		wchar_t wstrTotal[4] = { 0 };
		wsprintf(wstrTotal, _T("%d"), vecIter->GetTotalNum());
		m_cListCtrl.SetItemText(i, j++, wstrTotal);
		wchar_t wstrLeft[4] = { 0 };
		wsprintf(wstrLeft, _T("%d"), vecIter->GetLeftNum());
		m_cListCtrl.SetItemText(i, j++, wstrLeft);
		i++;
		j = 0;
	}



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
