#pragma once


// StuDlg �Ի���

class StuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StuDlg)

public:
	StuDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StuDlg();
	bool m_bIsShow;
// �Ի�������
	enum { IDD = IDD_STUDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
public:
	afx_msg void OnLogout();
};
