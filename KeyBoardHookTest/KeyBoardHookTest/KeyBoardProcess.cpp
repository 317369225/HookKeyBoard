#include "stdafx.h"
#include "KeyBoardProcess.h"

void ProcessKeyBoardInfo( int nCode,WPARAM wParam,LPARAM lParam )
{
	KBDLLHOOKSTRUCT *Key_Info = (KBDLLHOOKSTRUCT*)lParam;
	if (HC_ACTION == nCode)
	{
		//if (WM_KEYDOWN == wParam || WM_SYSKEYDOWN)
		if (WM_KEYUP == wParam || WM_SYSKEYUP)  //�������Ϊ̧��״̬
		{
			CString strText;
			strText.Format("8x%x̧��", Key_Info->vkCode);
			AfxMessageBox(strText);
			/*
			WriteVCodeToFile(Key_Info->vkCode);
			if (Key_Info->vkCode == VK_LWIN || Key_Info->vkCode == VK_RWIN) //���� WIN(����) ��
			{
				return TRUE; 
			}
			if (Key_Info->vkCode == 0x4D && ((GetKeyState(VK_LWIN) & 0x8000) || 
				(GetKeyState(VK_LWIN) & 0x8000))) //���� WIN+D ��ϼ�(����)
			{
				return TRUE;
			}
			if (Key_Info->vkCode == 0x44 && ((GetKeyState(VK_LWIN) & 0x8000) ||
				(GetKeyState(VK_LWIN) & 0x8000)))  //���� WIN+M ��ϼ�(����)
			{ 
				return TRUE;
			}
			if (Key_Info->vkCode == 0x1b && GetKeyState(VK_CONTROL) & 0x8000) //���� CTRL + ESC ��ϼ�
			{
				return TRUE;
			}
			if (Key_Info->vkCode == VK_TAB && Key_Info->flags & LLKHF_ALTDOWN) //���� ATL + TAB ��ϼ�
			{
				return TRUE;
			}
			if (Key_Info->vkCode == VK_ESCAPE && Key_Info->flags & LLKHF_ALTDOWN) //���� ATL + ESC ��ϼ�
			{
				return TRUE;
			}
			*/
		}

	}
}