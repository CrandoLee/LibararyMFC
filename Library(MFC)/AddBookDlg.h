#pragma once


// AddBookDlg �Ի���

class AddBookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddBookDlg)

public:
	AddBookDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddBookDlg();
	HWND m_parentHwnd;
// �Ի�������
	enum { IDD = IDD_ADDBOOKDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCancel();
};
