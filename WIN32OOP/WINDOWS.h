#pragma once
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

class WINDOWS{
protected:
	WNDCLASSEX winclass;
public:
	WINDOWS();
	WINDOWS(HINSTANCE hInstance, LPCTSTR ClsName,  WNDPROC WndPrc, LPCTSTR MenuName = NULL);
	~WINDOWS(void);
	void registerwindows();
};

