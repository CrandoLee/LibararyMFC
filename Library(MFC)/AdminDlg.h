#pragma once


// AdminDlg �Ի���

class AdminDlg : public CDialog
{
	DECLARE_DYNAMIC(AdminDlg)

public:
	AdminDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AdminDlg();

// �Ի�������
	enum { IDD = IDD_ADMINDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCancel();
};
