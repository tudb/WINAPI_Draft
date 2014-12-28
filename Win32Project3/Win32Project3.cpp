// Win32Project3.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32Project3.h"

HINSTANCE hIns;

LRESULT CALLBACK winProc(HWND, UINT, WPARAM, LPARAM);

/*INT_PTR CALLBACK Name(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lpRam){
	int hi;
	int lo;
	switch(msg){
		case WM_INITDIALOG:
			MessageBox(hwnd, TEXT("Name: John Edison.Do you know?"), TEXT("I'm a student"), 0);
			return (INT_PTR)true;
		case WM_COMMAND:
			lo = LOWORD(wParam);
			return (INT_PTR)true;
	}
	return (INT_PTR)false;
}
*/ 

INT_PTR CALLBACK Author(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	int hi;
	int lo;
	switch(msg){
	case WM_INITDIALOG:
		return (INT_PTR)true;
	case WM_COMMAND:
		hi = HIWORD(wParam);
		lo = LOWORD(wParam);
		switch (lo){
		case IDOK:
		case IDCANCEL:
			SendMessage(hwnd, WM_SETTEXT, 0, LPARAM(("CHANGED")));
			EndDialog(hwnd, lo);
			return (INT_PTR)true;
		}
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return (INT_PTR)false;
}

INT_PTR CALLBACK About(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	int lo;
	lo = LOWORD(wParam);
	switch(msg){
		case WM_INITDIALOG:
			return (INT_PTR)true;
		case WM_COMMAND :
			switch(lo){
			case IDOK:
			case IDCANCEL:
					EndDialog(hwnd, lo);
					return (INT_PTR)true;
				}
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}
	return (INT_PTR)false;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow){
	HWND hwnd;
	MSG msg;
	hIns = hInstance;
	LPCTSTR ClsName = TEXT("ClassName");
   	LPCTSTR WndName =  TEXT("WindowName of Window");
	WNDCLASSEX winclass;
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style			= CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc	= winProc;
	winclass.cbClsExtra		= 0;
	winclass.cbWndExtra		= 0;
	winclass.hInstance		= hInstance;
	winclass.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT3));
	winclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	winclass.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32PROJECT3);
	winclass.lpszClassName	= ClsName;
	winclass.hIconSm		= LoadIcon(winclass.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	RegisterClassEx(&winclass);
	hwnd = CreateWindow(ClsName, WndName, WS_OVERLAPPEDWINDOW | WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, CW_USEDEFAULT, 0,CW_USEDEFAULT,0, NULL,NULL, hInstance, NULL);
	if (!hwnd) return 0;
	ShowWindow(hwnd , iCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return true;
}

LRESULT CALLBACK winProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	int loParam;
	int hiParam;
	PAINTSTRUCT ps;
	HMENU hMenu;
	switch(msg){
	case WM_CREATE:
		hMenu = GetSystemMenu(hwnd, FALSE);
		RemoveMenu(hMenu, 3, MF_BYPOSITION);
		return 0;
	case WM_COMMAND:
		loParam = LOWORD(wParam);
		hiParam = HIWORD(wParam);
		switch(loParam){
		case IDM_ABOUT:
			DialogBox(hIns, MAKEINTRESOURCE(IDD_ABOUTBOX), hwnd, About);
		break;
		case ID_AUTHOR_AGE:
			DialogBox(hIns, MAKEINTRESOURCE(IDD_DIALOGAUTHOR) , hwnd, Author);
			break;
		case ID_AUTHOR_NAME :
			MessageBox(hwnd, TEXT("Name: John Edison.Do you know?"), TEXT("I'm a student"), 0);
			break;
		}
		break;
	case WM_PAINT:
		BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}



