#include "WinHwnd.h"


WinHwnd::WinHwnd(void){
}


WinHwnd::~WinHwnd(void){
}

HWND WinHwnd::create(HINSTANCE hInstance, LPCTSTR ClsName, LPCTSTR WndName, HWND hwn, DWORD DStyle, DWORD DXStyle, int x, int y , int nWidth , int nHeight){
	hwnd = CreateWindow(ClsName, WndName, DStyle, x, y, nWidth, nHeight, hwn, NULL, hInstance, NULL);
	if (!hwnd) return hwnd;
	return NULL;
}

BOOL WinHwnd::show(int nCmdShow){
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	return TRUE;
}

HWND WinHwnd::oprator(){
	return hwnd;
}
