#include "stdafx.h"
#include "MouseProcess.h"

//�ϴ������ָ�Ĵ��ھ�� 
HWND g_hPrevTarWnd = NULL;
//��ʾĿ�괰�ڱ���༭��ľ�� 
HWND g_hDisplayWnd = NULL; 

void ProcessMouseHookInfo( int nCode,WPARAM wParam,LPARAM lParam )
{
	LPMOUSEHOOKSTRUCT pMouseHook = (MOUSEHOOKSTRUCT FAR *)lParam; 
	if (nCode >= 0) 
	{ 
		HWND glhTargetWnd = ::WindowFromPoint(pMouseHook->pt); 
		if ((glhTargetWnd != g_hPrevTarWnd) && (NULL != glhTargetWnd)) 
		{ 
			//ȡĿ�괰�ڱ��� 
			char szCaption[256]; 
			GetWindowText(glhTargetWnd,szCaption,100); 
			CString strText;
			strText.Format("\n���ڣ�%s,���꣺%d,%d", szCaption, pMouseHook->pt.x, pMouseHook->pt.y);
			WriteMouseHookInfoToFile(strText);

			if(IsWindow(g_hDisplayWnd)) 
			{ 
				SendMessage(g_hDisplayWnd,WM_SETTEXT,0, (LPARAM)(LPCTSTR)szCaption); 
			} 
			g_hPrevTarWnd=glhTargetWnd;//����Ŀ�괰�� 
		} 
	} 
}

void WriteMouseHookInfoToFile(CString strText)
{
	CTime tm = CTime::GetCurrentTime();
	CString name;
	name.Format("mouse_%d_%d.log", tm.GetMonth(), tm.GetDay());
	CFile file;
	if (!file.Open(name, CFile::modeReadWrite))
	{
		file.Open(name, CFile::modeCreate|CFile::modeReadWrite);
	}
	file.SeekToEnd();
	file.Write(strText.GetBuffer(), strText.GetLength());
	file.Close();
}