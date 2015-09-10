#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <vector>
#include "DBUtil.h"
#include "StringConvert.h"
#include "TimeUtil.h"
#include "BorrowRecord.h"
#include "User.h"

// ReturnBookDlg �Ի���
using namespace std;
class ReturnBookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ReturnBookDlg)

public:
	ReturnBookDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ReturnBookDlg();
	HWND m_parentHwnd;
	User m_user;
	DBUtil m_dbUtil;
	StringConvert m_stringConvert;
	vector<BorrowRecord> m_vecBorrowRecords;
// �Ի�������
	enum { IDD = IDD_RETURNBOOKDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_cListCtrl;
	CEdit m_cEditID;
	afx_msg void OnReturnBook();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
};
