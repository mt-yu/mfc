#include <Windows.h>
#include<stdio.h>
#include "resource.h"
#define _CRT_SECURE_NO_WARNINGS

INT_PTR WINAPI msgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:		//对话框显示之前弹出的准备工作
		SetWindowText(hWnd, "消息测试");
		//MessageBox(hWnd, "创建", "测试", MB_OK);
		break;
	case WM_CLOSE:	//系统关闭消息
		EndDialog(hWnd, IDCANCEL);
		//MessageBox(hWnd, "系统关闭", "测试", MB_OK);
		break;
	case WM_LBUTTONDOWN:	//按下左键
	{	//MessageBox(hWnd, "左键按下","测试",MB_OK);
		short x = LOWORD(lParam);
		short y = HIWORD(lParam);
		char s[256];
		sprintf(s, "左键点击了: x=%d, y=%d", x, y);
		SetWindowText(hWnd,s);
	}
		break;
	case WM_RBUTTONDOWN:		//鼠标右键点击
	{	//MessageBox(hWnd, "右键按下","测试", MB_OK);
		short x = LOWORD(lParam);
		short y = HIWORD(lParam);
		char s[256];
		sprintf(s, "右键点击了: x=%d, y=%d", x, y);
		SetWindowText(hWnd, s);
	}
		break;
	case WM_MOUSEMOVE:	//鼠标移动	
	{
		//lParam 的低位存放x坐标，高位存放y坐标
		short x = LOWORD(lParam);
		short y = HIWORD(lParam);
		char s[256];
		sprintf(s, "鼠标移动: x=%d, y=%d wParam = %d", x, y, wParam);

		if (wParam == MK_LBUTTON)	//判断是否按下左键
			strcat(s, "按下左键");
		if (wParam == MK_RBUTTON)	//判断是否按下右键
			strcat(s, "按下右键");
		if (wParam & MK_MBUTTON)	//判断是否按下中键
			strcat(s, "按下中键");	

		SetWindowText(hWnd, s);
	}
		break;
	}

	return FALSE;
}

int WINAPI WinMain(HINSTANCE hIstance, HINSTANCE hPrev, LPSTR lpCmd, int nShow)
{

	DialogBox(hIstance, (LPCSTR)IDD_MSG_DLG, NULL, msgProc);

	return 0;
}