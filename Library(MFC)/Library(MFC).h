
// Library(MFC).h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLibraryMFCApp: 
// �йش����ʵ�֣������ Library(MFC).cpp
//

class CLibraryMFCApp : public CWinApp
{
public:
	CLibraryMFCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLibraryMFCApp theApp;