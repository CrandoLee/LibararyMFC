#pragma once
#include "afxcmn.h"
#include <vector>
#include "BorrowRecord.h"
#include "DBUtil.h"
#include "Book.h"
#include "User.h"
#include "StringConvert.h"
using namespace std;
// BorrowRecordDlg �Ի���

class BorrowRecordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BorrowRecordDlg)

public:
	BorrowRecordDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BorrowRecordDlg();
	HWND m_parentHwnd;
	DBUtil m_dbUtil;
	StringConvert m_stringConvert;
// �Ի�������
	enum { IDD = IDD_BORROWRECORDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_cListCtrl;
};
