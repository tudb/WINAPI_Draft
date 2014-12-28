#pragma once


// Dialog dialog

class Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(Dialog)

public:
	Dialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~Dialog();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
