#include <windows.h>
#include <stdio.h>
#include "resource.h"


//hInstance:资源总管

//自定义的一个获取小数的函数，类库中默认不带 （通过atof实现将文字转换为浮点数）
double GetDlgItemDouble(HWND hwnd, UINT nID)
{
	char s[256];
	GetDlgItemText(hwnd, nID, s, sizeof(s));
		
	return  atof(s); //将字符串转换成浮点数
}
// 通过sprintf()实现将浮点数，转换为文字 
void SetDlgItemDouble(HWND hwnd, UINT nID, double db)
{
	char s[256];
	sprintf(s,"%.2lf", db);
	SetDlgItemText(hwnd, nID, s);
}
//窗口居中函数
void OnInitDialog(HWND hwndDlg)
{
	RECT rect;
	GetWindowRect(hwndDlg, &rect);	//获取指定窗口的边界矩形的维数（左上右下）
	int cx = GetSystemMetrics(SM_CXFULLSCREEN);	//获取全屏窗口的宽度单位为像素
	int cy = GetSystemMetrics(SM_CYFULLSCREEN);	// 注意SM_CYSCREEN与FULLSCREEN（屏幕）是不同的 
	//屏幕的 （cx - 窗口宽度 ）/2

	int x = (cx - rect.right) / 2;
	int y = (cy - rect.bottom) / 2;
	MoveWindow(hwndDlg, x, y, rect.right, rect.bottom, FALSE);

}

void OnCalc(HWND hwndDlg)
{
	//OnCalc(hwndDlg);
	//+
	//定义一个系统的结构体， 还有 SIZE , RECTL
	POINT pt;
	double nLeft = GetDlgItemDouble(hwndDlg, IDC_LEFT1);
	double nRight = GetDlgItemDouble(hwndDlg, IDC_RIGHT1);
	double nResult = nRight + nLeft;
	SetDlgItemDouble(hwndDlg, IDC_RESTUL1, nResult);
	//-
	nLeft = GetDlgItemDouble(hwndDlg, IDC_LEFT2);
	nRight = GetDlgItemDouble(hwndDlg, IDC_RIGHT2);
	nResult = nRight - nLeft;
	SetDlgItemDouble(hwndDlg, IDC_RESTUL2, nResult);
	//*
	nLeft = GetDlgItemDouble(hwndDlg, IDC_LEFT3);
	nRight = GetDlgItemDouble(hwndDlg, IDC_RIGHT3);
	nResult = nRight * nLeft;
	SetDlgItemDouble(hwndDlg, IDC_RESTUL3, nResult);
	// /
	nLeft = GetDlgItemDouble(hwndDlg, IDC_LEFT4);
	nRight = GetDlgItemDouble(hwndDlg, IDC_RIGHT4);
	if (nRight != 0)
	{
		nResult = nLeft / nRight;
		SetDlgItemDouble(hwndDlg, IDC_RESTUL4, nResult);
	}
	else
		SetDlgItemText(hwndDlg, IDC_RESTUL4, "除数不能为0");
}
// 登录判断函数
void OnLogin(HWND hwndDlg)
{
	char sName[32], sPass[32];
	GetDlgItemText(hwndDlg, IDC_NAME, sName, sizeof(sName));
	GetDlgItemText(hwndDlg, IDC_PASSWD, sPass, sizeof(sPass));

	if (strcmp(sName, "admin") || strcmp(sPass, "123456"))
	{
		MessageBox(hwndDlg, "用户名或密码错误请重新输入", "错误！", MB_OK);
		return ;
	}
	
	EndDialog(hwndDlg, IDOK);
	
}

//登录界面回调函数
INT_PTR CALLBACK logProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{

	case WM_SETCURSOR:	//移动鼠标到对应位置 会出现提示
		if ((HWND)wParam == GetDlgItem(hwndDlg, IDC_NAME))
			SetDlgItemText(hwndDlg, IDC_STATUS, "请在此处输入账号");
		if ((HWND)wParam == GetDlgItem(hwndDlg, IDC_PASSWD))
			SetDlgItemText(hwndDlg, IDC_STATUS, "请在此处输入密码");
		return TRUE;
	case WM_INITDIALOG:
		OnInitDialog(hwndDlg);
	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hwndDlg, IDCANCEL);
			return TRUE;
		}
		if (LOWORD(wParam) == IDOK)
		{

			OnLogin(hwndDlg);
			return TRUE;
		}
	default:
		break;
	}
	return FALSE;
}
//主窗口消息回调函数
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:	//对话框初始化函数
	{
		OnInitDialog(hwndDlg);
		return TRUE;
	}
	case WM_COMMAND:	//命令消息
		if (LOWORD(wParam) == IDOK)
		{
			OnCalc(hwndDlg);
			return TRUE;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hwndDlg, IDCANCEL);
			return TRUE;
			// MessageBox(hwndDlg, "你点击了Cancel", "临时", 0);
		}
		if (LOWORD(wParam) == ID_EXIT)
		{
			EndDialog(hwndDlg, ID_EXIT);
			return TRUE;
		}

		break;
	}
	return FALSE;	//FALSE代表缺省处理
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{//MessageBox FindWindow

	if(DialogBox(hInstance, (LPCTSTR) IDD_LOGIN_DLG, NULL, logProc) == IDCANCEL)
		return 0;
		
	DialogBox(hInstance, (LPCTSTR) IDD_MAIN_DLG, NULL, DialogProc);
	return 0;
}