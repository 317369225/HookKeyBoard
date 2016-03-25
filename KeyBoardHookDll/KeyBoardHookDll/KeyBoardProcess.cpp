#include "stdafx.h"
#include "KeyBoardProcess.h"
#include "global.h"

LRESULT CALLBACK LauncherKeyBoardHookEx(int nCode,WPARAM wParam,LPARAM lParam)
{
	if (g_keyBoardHookExCB != NULL)
	{
		g_keyBoardHookExCB(nCode, wParam, lParam);
	}

	return CallNextHookEx(g_hookex, nCode, wParam, lParam); //»Øµ÷
}