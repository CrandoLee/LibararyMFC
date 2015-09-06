#pragma once
#include "QueryBookDlg.h"
#include "BorrowBookDlg.h"
#include "User.h"
// StuDlg �Ի���

class StuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StuDlg)

public:
	StuDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StuDlg();
	bool m_bIsShow;
	User m_user;
// �Ի�������
	enum { IDD = IDD_STUDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg LRESULT  OnChangeState(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
public:
	afx_msg void OnLogout();
	afx_msg void OnQueryBook();
	afx_msg void OnBorrowBook();
};
