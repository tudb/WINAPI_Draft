//---------------------------------------------------------------------------
#include <windows.h>
#include "resource.h"

//---------------------------------------------------------------------------
LRESULT CALLBACK WndProcedure(HWND hWnd, UINT uMsg,
			      WPARAM wParam, LPARAM lParam);
//---------------------------------------------------------------------------
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
	MSG        Msg;
	HWND       hWnd;
	WNDCLASSEX WndClsEx;
        LPCTSTR ClsName = L"ResFund";
   	LPCTSTR WndName = L"Resources Fundamentals";

	// Create the application window
	WndClsEx.cbSize        = sizeof(WNDCLASSEX);
	WndClsEx.style         = CS_HREDRAW | CS_VREDRAW;
	WndClsEx.lpfnWndProc   = WndProcedure;
	WndClsEx.cbClsExtra    = 0;
	WndClsEx.cbWndExtra    = 0;
	WndClsEx.hIcon         = LoadIcon(hInstance,
					  MAKEINTRESOURCE(IDI_RESFUND2));
	WndClsEx.hCursor       = LoadCursor(NULL, IDC_ARROW);
	WndClsEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClsEx.lpszMenuName  = NULL;
	WndClsEx.lpszClassName = ClsName;
	WndClsEx.hInstance     = hInstance;
	WndClsEx.hIconSm       = LoadIcon(hInstance,
					  MAKEINTRESOURCE(IDI_RESFUND2));

	// Register the application
	RegisterClassEx(&WndClsEx);

	// Create the window object
	hWnd = CreateWindowEx(0,
                          ClsName,
                          WndName,
               			  WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
               			  CW_USEDEFAULT,
                          CW_USEDEFAULT,
               			  CW_USEDEFAULT,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);
	
	// Find out if the window was created
	if( !hWnd ) // If the window was not created,
		return FALSE; // stop the application

	// Display the window to the user
	ShowWindow(hWnd, nCmdShow);// SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	// Decode and treat the messages
	// as long as the application is running
	while( GetMessage(&Msg, NULL, 0, 0) )
	{
             TranslateMessage(&Msg);
             DispatchMessage(&Msg);
	}

//	return Msg.wParam;
    return 0;
}
//---------------------------------------------------------------------------
LRESULT CALLBACK WndProcedure(HWND hWnd, UINT Msg,
			   WPARAM wParam, LPARAM lParam)
{
    switch(Msg)
    {
    case WM_DESTROY:
        PostQuitMessage(WM_QUIT);
        break;
    default:
        // Process the left-over messages
        return DefWindowProc(hWnd, Msg, wParam, lParam);
    }
    // If something was not done, let it go
    return 0;
}
//---------------------------------------------------------------------------