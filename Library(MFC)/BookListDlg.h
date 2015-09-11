#pragma once
#include "afxcmn.h"
#include "DBUtil.h"
#include "StringConvert.h"
// BookListDlg �Ի���

class BookListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BookListDlg)

public:
	BookListDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BookListDlg();
	HWND m_parentHwnd;
	DBUtil m_dbUtil;
	StringConvert m_stringConvert;
// �Ի�������
	enum { IDD = IDD_BOOKLISTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_cListCtrl;
	virtual void OnOK();
};
