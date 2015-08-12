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
	DDX_Control(pDX, IDC_EDIT1, m_cEditBookName);
	DDX_Control(pDX, IDC_EDIT2, m_cEditAuthor);
	DDX_Control(pDX, IDC_EDIT3, m_cEditISBN);
	DDX_Control(pDX, IDC_EDIT4, m_cEditPublish);
	DDX_Control(pDX, IDC_EDIT5, m_cEditNumber);
}


BEGIN_MESSAGE_MAP(AddBookDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &AddBookDlg::OnCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &AddBookDlg::OnAddBook)
END_MESSAGE_MAP()


// AddBookDlg ��Ϣ�������


void AddBookDlg::OnCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	::SendMessage(m_parentHwnd,WM_CHANEG_STATE, NULL, NULL);
	OnOK();
	
}

//�����鼮
void AddBookDlg::OnAddBook()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	wchar_t szName[32] = { 0 };
	m_cEditBookName.GetWindowText(szName, 32);
	wchar_t szAuthor[32] = { 0 };
	m_cEditAuthor.GetWindowText(szAuthor, 32);
	wchar_t szISBN[32] = { 0 };
	m_cEditISBN.GetWindowText(szISBN, 32);
	wchar_t szPublish[32] = { 0 };
	m_cEditPublish.GetWindowText(szPublish, 32);
	wchar_t szNumber[4] = { 0 };
	m_cEditNumber.GetWindowText(szNumber, 4);

	wstring wstrName = szName;
	wstring wstrAuthor = szAuthor;
	wstring wstrISBN = szISBN;
	wstring wstrPublish = szPublish;
	wstring wstrNumber = szNumber;

	string strName;
	string strAuthor;
	string strISBN;
	string strPubish;
	string strNum;
	m_stringConvert.WStringToString(wstrName, strName);
	m_stringConvert.WStringToString(wstrAuthor, strAuthor);
	m_stringConvert.WStringToString(wstrISBN, strISBN);
	m_stringConvert.WStringToString(wstrPublish, strPubish);
	m_stringConvert.WStringToString(wstrNumber, strNum);

	char szTime[64] = { 0 };
	time_t lt;
	lt = time(NULL);
	TimeUtil timeUtil;
	timeUtil.TimeToString(lt, szTime);


	Book book;
	book.SetBookName(strName);
	book.SetAuthor(strAuthor);
	book.SetISBN(strISBN);
	book.SetPub(strPubish);
	book.SetInDate(szTime);
	book.SetTotalNum(atoi(strNum.c_str()));
	book.SetLeftNum(atoi(strNum.c_str()));

	DBUtil dbUtil;
	dbUtil.OpenDB();
	dbUtil.AddBook(book);

	MessageBox(_T("��ӳɹ�"), _T("��Ϣ"), MB_ICONINFORMATION | MB_OK);
	::SendMessage(m_parentHwnd, WM_CHANEG_STATE, NULL, NULL);
	OnOK();
	DestroyWindow();
}
