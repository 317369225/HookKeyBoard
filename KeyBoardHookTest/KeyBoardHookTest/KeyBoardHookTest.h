
// KeyBoardHookTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CKeyBoardHookTestApp:
// �йش����ʵ�֣������ KeyBoardHookTest.cpp
//

class CKeyBoardHookTestApp : public CWinAppEx
{
public:
	CKeyBoardHookTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CKeyBoardHookTestApp theApp;