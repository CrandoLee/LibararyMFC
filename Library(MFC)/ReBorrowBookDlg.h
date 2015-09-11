#pragma once
#include <vector>
#include "DBUtil.h"
#include "StringConvert.h"
#include "TimeUtil.h"
#include "BorrowRecord.h"
#include "User.h"
#include "afxcmn.h"
#include "afxwin.h"

// ReBorrowBookDlg �Ի���

class ReBorrowBookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ReBorrowBookDlg)

public:
	ReBorrowBookDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ReBorrowBookDlg();
	HWND m_parentHwnd;
	User m_user;
	DBUtil m_dbUtil;
	StringConvert m_stringConvert;
	vector<BorrowRecord> m_vecBorrowRecords;
// �Ի�������
	enum { IDD = IDD_REBORROWBOOKDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_cListCtrl;
	CEdit m_cEditID;
	afx_msg void OnReborrow();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
};
