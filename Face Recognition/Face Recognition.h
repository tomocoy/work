
// Face Recognition.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFaceRecognitionApp: 
// �йش����ʵ�֣������ Face Recognition.cpp
//

class CFaceRecognitionApp : public CWinApp
{
public:
	CFaceRecognitionApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFaceRecognitionApp theApp;