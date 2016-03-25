// HookDll.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "HookDll.h"
#include "KeyBoardProcess.h"
#include "global.h"
#include "ProcessMouse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CHookDllApp

BEGIN_MESSAGE_MAP(CHookDllApp, CWinApp)
END_MESSAGE_MAP()


// CHookDllApp ����

CHookDllApp::CHookDllApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CHookDllApp ����

CHookDllApp theApp;

// CHookDllApp ��ʼ��

BOOL CHookDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

int WINAPI InstallKeyBoardHookEx()
{
	g_hookex = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)LauncherKeyBoardHookEx, //��װ�ͼ����̹���
		GetModuleHandle("hotkey"), 0);
	if (NULL == g_hookex)
	{
		MessageBox(NULL, "��װ���̹��ӳ��� !", "error", MB_ICONSTOP);
		return -1;
	}
	return 0;
}

int WINAPI UnInstallKeyBoardHookEx()
{
	UnhookWindowsHookEx(g_hookex); //ж�ع���
	return 0;
}

int WINAPI InstallMouseHookEx()
{
	g_mouseHookEx = SetWindowsHookEx(WH_MOUSE_LL, (HOOKPROC)LauncherMouseHookEx, //��װ�ͼ����̹���
		GetModuleHandle("hotkey"), 0);
	if (NULL == g_mouseHookEx)
	{
		MessageBox(NULL, "��װ��깳�ӳ��� !", "error", MB_ICONSTOP);
		return -1;
	}
	return 0;
}

int WINAPI UnInstallMouseHookEx()
{
	if (g_mouseHookEx != NULL)
	{
		UnhookWindowsHookEx(g_mouseHookEx);
	}
	return 0;
}

int WINAPI SetKeyBoardHookExCallBack( KeyBoardHookExCallBack keyBoardHookExCB )
{
	g_keyBoardHookExCB = keyBoardHookExCB;
	return 0;
}

int WINAPI SetMouseHookExCallBack( MouseHookExCallBack mouseHookExCB )
{
	g_mouseHookExCB = mouseHookExCB;
	return 0;
}
