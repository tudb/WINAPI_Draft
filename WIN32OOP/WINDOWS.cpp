#include "WINDOWS.h"
#include "resource.h"


WINDOWS::WINDOWS(){
}

WINDOWS::WINDOWS(HINSTANCE hInstance, LPCTSTR ClsName,  WNDPROC WndPrc, LPCTSTR MenuName ){
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	winclass.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON1));
	winclass.hInstance = hInstance;
	winclass.lpszClassName = ClsName;
	winclass.lpszMenuName = MenuName;
	winclass.style = CS_HREDRAW | CS_VREDRAW;
	winclass.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON1));
}


WINDOWS::~WINDOWS(void)
{
}

void WINDOWS::registerwindows(){
	RegisterClassEx(&winclass);
}