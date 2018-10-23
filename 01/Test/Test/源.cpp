#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR loCmd, int nCmdShow)
{
	//HWND hwnd = FindWindow(NULL, "翻译.txt -记事本");
	//HWND hwnd = FindWindow("MozillaWindowClass", NULL);
	int nRet = MessageBox(NULL, "这是我的第一个Windows软件！", "温馨提示：", MB_YESNOCANCEL);
	switch (nRet)
	{
	case IDYES:
		MessageBox(NULL, "你点击的是YES", "结果:", MB_OK);
		break;
	case IDNO:
		MessageBox(NULL, "你点击的是NO", "结果:", MB_OK);
		break;
	case IDCANCEL:
		MessageBox(NULL, "你点击的是CANCEL", "结果:", MB_OK);
		break;
	default:
		break;
	}
	return 0;
}