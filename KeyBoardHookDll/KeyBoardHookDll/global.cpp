#include "stdafx.h"
#include "global.h"

HHOOK g_hook = NULL;
HHOOK g_hookex = NULL;
HHOOK g_mouseHookEx = NULL;

KeyBoardHookExCallBack g_keyBoardHookExCB = NULL;
MouseHookExCallBack g_mouseHookExCB = NULL;