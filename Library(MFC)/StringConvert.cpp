#include "stdafx.h"
#include "StringConvert.h"


StringConvert::StringConvert()
{
}


StringConvert::~StringConvert()
{
}


BOOL StringConvert::StringToWString(string &str, wstring &wstr)
{
	int nLen = (int)str.length();
	wstr.resize(nLen, L' ');

	int nResult = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)str.c_str(), nLen, (LPWSTR)wstr.c_str(), nLen);

	if (nResult == 0)
	{
		return FALSE;
	}

	return TRUE;
}

//wstring���ֽڲ�Ϊ0������FALSE
BOOL StringConvert::WStringToString(wstring &wstr, string &str)
{
	int nLen = (int)wstr.length();
	str.resize(nLen, ' ');

	int nResult = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wstr.c_str(), nLen, (LPSTR)str.c_str(), nLen, NULL, NULL);

	if (nResult == 0)
	{
		return FALSE;
	}

	return TRUE;
}