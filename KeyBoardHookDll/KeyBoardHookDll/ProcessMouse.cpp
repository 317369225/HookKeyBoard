#include "stdafx.h"
#include "ProcessMouse.h"
#include "global.h"

//�ϴ������ָ�Ĵ��ھ�� 
HWND g_hPrevTarWnd = NULL;
//��ʾĿ�괰�ڱ���༭��ľ�� 
HWND g_hDisplayWnd = NULL; 

LRESULT CALLBACK LauncherMouseHookEx(int nCode,WPARAM wParam,LPARAM lParam)
{
	if (g_mouseHookExCB != NULL)
	{
		g_mouseHookExCB(nCode, wParam, lParam);
	}

	return CallNextHookEx(g_mouseHookEx, nCode, wParam, lParam); //�ص�
}
