#pragma once
#include <windows.h>

class WinHwnd{
protected:
	HWND hwnd;
public:
	WinHwnd();
	~WinHwnd(void);
	HWND create(HINSTANCE hInstance, LPCTSTR ClsName, LPCTSTR WndName, HWND hwn = NULL, DWORD DStyle= WS_OVERLAPPEDWINDOW, DWORD DXStyle = 0L, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int nWidth = CW_USEDEFAULT, int nHeight = CW_USEDEFAULT);
	BOOL show(int nCmdShow = SW_SHOWNORMAL);
	HWND oprator();
};

