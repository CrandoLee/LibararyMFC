#pragma once
#include "afxwin.h"
#include "StringConvert.h"
#include "Book.h"
#include "DBUtil.h"
#include "TimeUtil.h"
// AddBookDlg �Ի���

class AddBookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddBookDlg)

public:
	AddBookDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddBookDlg();
	HWND m_parentHwnd;
	StringConvert m_stringConvert;
// �Ի�������
	enum { IDD = IDD_ADDBOOKDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCancel();
	afx_msg void OnAddBook();
	CEdit m_cEditBookName;
	CEdit m_cEditAuthor;
	CEdit m_cEditISBN;
	CEdit m_cEditPublish;
	CEdit m_cEditNumber;
	virtual void OnOK();
};
