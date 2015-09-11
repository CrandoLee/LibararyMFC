#pragma once
#include "afxcmn.h"
#include "DBUtil.h"
#include "User.h"
#include "StringConvert.h"

// UserListDlg �Ի���

class UserListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UserListDlg)

public:
	UserListDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UserListDlg();

// �Ի�������
	enum { IDD = IDD_USERLISTDLG };
	HWND m_parentHwnd;
	StringConvert m_stringConvert;
	DBUtil m_dbUtil;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	CListCtrl m_cListUser;
	virtual void OnOK();
};
