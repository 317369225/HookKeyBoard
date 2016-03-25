// HookDll.cpp : 定义 DLL 的初始化例程。
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
//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CHookDllApp

BEGIN_MESSAGE_MAP(CHookDllApp, CWinApp)
END_MESSAGE_MAP()


// CHookDllApp 构造

CHookDllApp::CHookDllApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CHookDllApp 对象

CHookDllApp theApp;

// CHookDllApp 初始化

BOOL CHookDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

int WINAPI InstallKeyBoardHookEx()
{
	g_hookex = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)LauncherKeyBoardHookEx, //安装低级键盘钩子
		GetModuleHandle("hotkey"), 0);
	if (NULL == g_hookex)
	{
		MessageBox(NULL, "安装键盘钩子出错 !", "error", MB_ICONSTOP);
		return -1;
	}
	return 0;
}

int WINAPI UnInstallKeyBoardHookEx()
{
	UnhookWindowsHookEx(g_hookex); //卸载钩子
	return 0;
}

int WINAPI InstallMouseHookEx()
{
	g_mouseHookEx = SetWindowsHookEx(WH_MOUSE_LL, (HOOKPROC)LauncherMouseHookEx, //安装低级键盘钩子
		GetModuleHandle("hotkey"), 0);
	if (NULL == g_mouseHookEx)
	{
		MessageBox(NULL, "安装鼠标钩子出错 !", "error", MB_ICONSTOP);
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
