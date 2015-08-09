
// LibraryDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "User.h"
#include "Manager.h"
#include "DBUtil.h"
#include "StringConvert.h"
#include "AdminDlg.h"
// CLibraryDlg �Ի���
class CLibraryDlg : public CDialogEx
{
// ����
public:
	CLibraryDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LIBRARYMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBtnCancel();
	afx_msg void OnBtnSubmit();
	CEdit m_cEditName;
	CEdit m_cEditPass;
};
