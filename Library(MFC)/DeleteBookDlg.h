#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "DBUtil.h"
#include "StringConvert.h"

// DeleteBookDlg �Ի���

class DeleteBookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteBookDlg)

public:
	DeleteBookDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DeleteBookDlg();
	StringConvert m_stringConvert;
	HWND m_parentHwnd;
	DBUtil m_DbUtil;
// �Ի�������
	enum { IDD = IDD_DELBOOKDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnQuery();
	CEdit m_cEditId;
	CListCtrl m_cListCtrl;
	afx_msg void OnDelete();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
};
