#pragma once
#include "afxwin.h"
#include "User.h"
#include "DBUtil.h"
#include "StringConvert.h"

// AddUserDlg �Ի���

class AddUserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddUserDlg)

public:
	AddUserDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddUserDlg();
	HWND m_parentHwnd;
	StringConvert m_stringConvert;
	DBUtil m_dbUtil;
// �Ի�������
	enum { IDD = IDD_ADDUSERDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
public:
	afx_msg void OnBtnCancel();
	virtual BOOL OnInitDialog();
	CEdit m_cEditName;
	CEdit m_cEditPassword;
	CComboBox m_cCombType;
	afx_msg void OnSaveUser();
	virtual void OnOK();
};
