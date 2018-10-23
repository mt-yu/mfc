#include <windows.h>
#include "resource.h"
//hInstance:资源总管


//消息回调函数
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:	//命令消息
		if (LOWORD(wParam) == IDOK)
		{
			int nLeft = GetDlgItemInt(hwndDlg, IDC_LEFT, NULL, TRUE);
			int nRight = GetDlgItemInt(hwndDlg, IDC_RIGHT, NULL, TRUE);
			int nResult = nRight + nLeft;
			SetDlgItemInt(hwndDlg, IDC_RESTUL, nResult, TRUE);
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hwndDlg, IDCANCEL);
			// MessageBox(hwndDlg, "你点击了Cancel", "临时", 0);
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