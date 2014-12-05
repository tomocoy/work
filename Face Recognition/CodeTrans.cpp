#include "stdafx.h"
#include "CodeTrans.h"


CCodeTrans::CCodeTrans()
{
}


CCodeTrans::~CCodeTrans()
{
}

CStringW CCodeTrans::ANSIToUnicode(const char* ansiText)
{
	if (!ansiText)
	{
		return NULL;
	}

	int unicodeLen = ::MultiByteToWideChar(CP_ACP,
		0,
		ansiText,
		-1,
		NULL,
		0);
	wchar_t * pUnicode = new wchar_t[unicodeLen + 1];
	if (!pUnicode)
	{
		return NULL;
	}
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP,
		0,
		ansiText,
		-1,
		(LPWSTR)pUnicode,
		unicodeLen);
	CStringW strText = pUnicode;
	delete []pUnicode;

	return strText;
}

CStringA CCodeTrans::UnicodeToANSI(const TCHAR * unicodeText)
{
	if (!unicodeText)
	{
		return NULL;
	}

	// wide char to multi char
	int iTextLen = WideCharToMultiByte(CP_ACP,
		0,
		unicodeText,
		-1,
		NULL,
		0,
		NULL,
		NULL);
	char *pElementText = new char[iTextLen + 1];
	if (!pElementText)
	{
		return NULL;
	}
	memset((void*)pElementText, 0, sizeof(char) * (iTextLen + 1));
	::WideCharToMultiByte(CP_ACP,
		0,
		unicodeText,
		-1,
		pElementText,
		iTextLen,
		NULL,
		NULL);
	CStringA strText = pElementText;
	delete []pElementText;

	return strText;
}

CStringW CCodeTrans::UTF8ToUnicode(const char* utf8Text)
{
	if (!utf8Text)
	{
		return NULL;
	}

	int unicodeLen = ::MultiByteToWideChar(CP_UTF8,
		0,
		utf8Text,
		-1,
		NULL,
		0);
	wchar_t *pUnicode = new  wchar_t[unicodeLen + 1];
	if (!pUnicode)
	{
		return NULL;
	}
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_UTF8,
		0,
		utf8Text,
		-1,
		(LPWSTR)pUnicode,
		unicodeLen);
	CStringW strText = (wchar_t*)pUnicode;
	delete []pUnicode;

	return strText;
}

CStringA CCodeTrans::UnicodeToUTF8(const TCHAR* unicodeText)
{
	if (!unicodeText)
	{
		return NULL;
	}
	// wide char to multi char
	int iTextLen = WideCharToMultiByte(CP_UTF8,
		0,
		unicodeText,
		-1,
		NULL,
		0,
		NULL,
		NULL);
	char *pElementText = new char[iTextLen + 1];
	if (!pElementText)
	{
		return NULL;
	}
	memset((void*)pElementText, 0, sizeof(char) * (iTextLen + 1));
	::WideCharToMultiByte(CP_UTF8,
		0,
		unicodeText,
		-1,
		pElementText,
		iTextLen,
		NULL,
		NULL);
	CStringA strText = pElementText;
	delete []pElementText;

	return strText;
}
