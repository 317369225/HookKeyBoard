#include "stdafx.h"
#include "ProcessMouse.h"
#include "global.h"

//上次鼠标所指的窗口句柄 
HWND g_hPrevTarWnd = NULL;
//显示目标窗口标题编辑框的句柄 
HWND g_hDisplayWnd = NULL; 

LRESULT CALLBACK LauncherMouseHookEx(int nCode,WPARAM wParam,LPARAM lParam)
{
	if (g_mouseHookExCB != NULL)
	{
		g_mouseHookExCB(nCode, wParam, lParam);
	}

	return CallNextHookEx(g_mouseHookEx, nCode, wParam, lParam); //回调
}
