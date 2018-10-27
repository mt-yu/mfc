#include <windows.h>
#include "resource.h"
#include <tchar.h>
//hInstance:资源总管


//消息回调函数
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		MessageBox(hwndDlg, _T("关闭"), _T("提示"), 0);
		return FALSE;//true代表系统不用关闭了， FALSE代表系统继续关闭
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hwndDlg, IDCANCEL);
			return TRUE;
		case IDC_SEND:
			SendMessage(hwndDlg, WM_CLOSE, 0, 0);
			return TRUE;

		}
	break;
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{//MessageBox FindWindow
	DialogBox(hInstance, (LPCTSTR) IDD_MAIN_DLG, NULL, DialogProc);
	return 0;
}