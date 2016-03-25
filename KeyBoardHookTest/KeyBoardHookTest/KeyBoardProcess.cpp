#include "stdafx.h"
#include "KeyBoardProcess.h"

void ProcessKeyBoardInfo( int nCode,WPARAM wParam,LPARAM lParam )
{
	KBDLLHOOKSTRUCT *Key_Info = (KBDLLHOOKSTRUCT*)lParam;
	if (HC_ACTION == nCode)
	{
		//if (WM_KEYDOWN == wParam || WM_SYSKEYDOWN)
		if (WM_KEYUP == wParam || WM_SYSKEYUP)  //Èç¹û°´¼üÎªÌ§Æð×´Ì¬
		{
			CString strText;
			strText.Format("8x%xÌ§Æð", Key_Info->vkCode);
			AfxMessageBox(strText);
			/*
			WriteVCodeToFile(Key_Info->vkCode);
			if (Key_Info->vkCode == VK_LWIN || Key_Info->vkCode == VK_RWIN) //ÆÁ±Ö WIN(×óÓÒ) ¼ü
			{
				return TRUE; 
			}
			if (Key_Info->vkCode == 0x4D && ((GetKeyState(VK_LWIN) & 0x8000) || 
				(GetKeyState(VK_LWIN) & 0x8000))) //ÆÁ±Ö WIN+D ×éºÏ¼ü(×óÓÒ)
			{
				return TRUE;
			}
			if (Key_Info->vkCode == 0x44 && ((GetKeyState(VK_LWIN) & 0x8000) ||
				(GetKeyState(VK_LWIN) & 0x8000)))  //ÆÁ±Ö WIN+M ×éºÏ¼ü(×óÓÒ)
			{ 
				return TRUE;
			}
			if (Key_Info->vkCode == 0x1b && GetKeyState(VK_CONTROL) & 0x8000) //ÆÁ±Ö CTRL + ESC ×éºÏ¼ü
			{
				return TRUE;
			}
			if (Key_Info->vkCode == VK_TAB && Key_Info->flags & LLKHF_ALTDOWN) //ÆÁ±Ö ATL + TAB ×éºÏ¼ü
			{
				return TRUE;
			}
			if (Key_Info->vkCode == VK_ESCAPE && Key_Info->flags & LLKHF_ALTDOWN) //ÆÁ±Ö ATL + ESC ×éºÏ¼ü
			{
				return TRUE;
			}
			*/
		}

	}
}