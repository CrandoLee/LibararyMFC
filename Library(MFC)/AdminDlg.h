#pragma once
#include "AddBookDlg.h"
#include "QueryBookDlg.h"
// AdminDlg �Ի���

class AdminDlg : public CDialog
{
	DECLARE_DYNAMIC(AdminDlg)

public:
	AdminDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AdminDlg();
	bool m_bIsShow;
// �Ի�������
	enum { IDD = IDD_ADMINDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg LRESULT  OnChangeState(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCancel();
	afx_msg void OnAddBook();

	afx_msg void OnQueryBook();
};
