#include "WINDOWS.h"
#include "WinHwnd.h"
#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPrevInstance, LPSTR lpCmdLine , int nCmdShow){
	MSG msg;
	LPCTSTR ClsName = TEXT("WINDOWS from WINMAIN");
	LPCTSTR WndName = TEXT("WINDOWS NAME WINMAIN");
	WINDOWS winclass(hInstance, ClsName, WndProc);
	winclass.registerwindows();
	WinHwnd hwndClass;
	hwndClass.create(hInstance, ClsName, WndName);
	hwndClass.show();
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	switch(msg){
	case WM_PAINT:
		PAINTSTRUCT ps;
		BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}