#include "stdafx.h"
#include "MouseProcess.h"

//上次鼠标所指的窗口句柄 
HWND g_hPrevTarWnd = NULL;
//显示目标窗口标题编辑框的句柄 
HWND g_hDisplayWnd = NULL; 

void ProcessMouseHookInfo( int nCode,WPARAM wParam,LPARAM lParam )
{
	LPMOUSEHOOKSTRUCT pMouseHook = (MOUSEHOOKSTRUCT FAR *)lParam; 
	if (nCode >= 0) 
	{ 
		HWND glhTargetWnd = ::WindowFromPoint(pMouseHook->pt); 
		if ((glhTargetWnd != g_hPrevTarWnd) && (NULL != glhTargetWnd)) 
		{ 
			//取目标窗口标题 
			char szCaption[256]; 
			GetWindowText(glhTargetWnd,szCaption,100); 
			CString strText;
			strText.Format("\n窗口：%s,坐标：%d,%d", szCaption, pMouseHook->pt.x, pMouseHook->pt.y);
			WriteMouseHookInfoToFile(strText);

			if(IsWindow(g_hDisplayWnd)) 
			{ 
				SendMessage(g_hDisplayWnd,WM_SETTEXT,0, (LPARAM)(LPCTSTR)szCaption); 
			} 
			g_hPrevTarWnd=glhTargetWnd;//保存目标窗口 
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