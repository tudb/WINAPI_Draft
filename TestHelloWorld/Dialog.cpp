// Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog.h"
#include "afxdialogex.h"


// Dialog dialog

IMPLEMENT_DYNAMIC(Dialog, CDialogEx)

Dialog::Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dialog::IDD, pParent)
{

}

Dialog::~Dialog()
{
}

void Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dialog, CDialogEx)
END_MESSAGE_MAP()


// Dialog message handlers
