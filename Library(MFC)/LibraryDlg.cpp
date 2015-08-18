
// LibraryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "LibraryDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLibraryDlg �Ի���



CLibraryDlg::CLibraryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLibraryDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLibraryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_cEditName);
	DDX_Control(pDX, IDC_EDIT2, m_cEditPass);
}

BEGIN_MESSAGE_MAP(CLibraryDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CLibraryDlg::OnBtnCancel)
	ON_BN_CLICKED(IDOK, &CLibraryDlg::OnBtnSubmit)
END_MESSAGE_MAP()


// CLibraryDlg ��Ϣ�������

BOOL CLibraryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CLibraryDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLibraryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLibraryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLibraryDlg::OnBtnCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CLibraryDlg::OnBtnSubmit()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//AfxMessageBox(_T("sdas"));
	char chName[32] = { 0 };
	CString cstrName;
	m_cEditName.GetWindowText(cstrName);
	CString cstrPass;
	m_cEditPass.GetWindowText(cstrPass);
	DBUtil dbUtil;
	if (!dbUtil.OpenDB())
	{
		MessageBox(_T("����"), _T("�������ݿ�ʧ��"), MB_ICONWARNING | MB_OK);
		return;
	}
	StringConvert stringCovert;

	string strName;
	wstring wstrName = cstrName.GetString();
	strName = stringCovert.ws2s(wstrName);

	string strPass;
	wstring wstrPass = cstrPass.GetString();
	strPass = stringCovert.ws2s(wstrPass);

 	User user = dbUtil.ReadUser(strName, strPass);

	if (user.m_nRole == 0)
	{
		//��¼�û�Ϊ����Ա
		AdminDlg* adminDlg = new AdminDlg();
		adminDlg->Create(IDD_ADMINDLG);
		adminDlg->m_bIsShow = true;
		adminDlg->ShowWindow(true);
		this->ShowWindow(false);
	}
	else if (user.m_nRole == 1)
	{
		//��½�û�Ϊ��ͨѧ��
	}
	else
	{
		MessageBox(_T("�û������������"), _T("����"), MB_ICONWARNING | MB_OK);
		return;
	}
}
