#pragma once
class CCodeTrans
{
public:
	CCodeTrans();
	~CCodeTrans();

	CStringW ANSIToUnicode(const char* ansiText);
	CStringA UnicodeToANSI(const TCHAR * unicodeText);

	CStringW UTF8ToUnicode(const char* utf8Text);
	CStringA UnicodeToUTF8(const TCHAR* unicodeText);
};

