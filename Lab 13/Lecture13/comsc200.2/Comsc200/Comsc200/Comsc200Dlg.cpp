
// Comsc200Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Comsc200.h"
#include "Comsc200Dlg.h"
#include "afxdialogex.h"

#include <sstream>
using std::ostringstream; 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CComsc200Dlg dialog



CComsc200Dlg::CComsc200Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CComsc200Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComsc200Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CComsc200Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED(IDOK, &CComsc200Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CComsc200Dlg message handlers

BOOL CComsc200Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
  CButton* pCheck1 = (CButton*)GetDlgItem(IDC_CHECK1);
  pCheck1->SetCheck(BST_CHECKED);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CComsc200Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CComsc200Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CComsc200Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CComsc200Dlg::OnBnClickedOk()
{
  CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1); 
  CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2); 
  CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3); 

  CString edit1;
  pEdit1->GetWindowText(edit1);
  double dim1 = _ttof(edit1);

  CString edit2;
  pEdit2->GetWindowText(edit2);
  double dim2 = _ttof(edit2);

  CString edit3;
  pEdit3->GetWindowText(edit3);
  double dim3 = _ttof(edit3);

  CButton* pCheck1 = (CButton*)GetDlgItem(IDC_CHECK1);
  int c1 = pCheck1->GetCheck(); // BST_UNCHECKED for unselected, BST_CHECKED for selected
  CButton* pCheck2 = (CButton*)GetDlgItem(IDC_CHECK2);
  int c2 = pCheck2->GetCheck(); // BST_UNCHECKED for unselected, BST_CHECKED for selected

  double volume;
  if (c1 == BST_CHECKED) volume = dim1 * dim1 * dim1; 
  else if (c2 == BST_CHECKED) volume = dim1 * dim2 * dim3; 

  ostringstream sout;
  sout << "Volume = " << volume;

  CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
  if (c1 == BST_CHECKED) pStatic4->SetWindowText(CString(_T("Cube")));
  else if (c2 == BST_CHECKED)  pStatic4->SetWindowText(CString(_T("Prism")));
  CEdit* result = (CEdit*)GetDlgItem(IDC_EDIT4);
  //result->SetWindowText(CString(_T("Hello"))); 
  result->SetWindowText(CString(sout.str().c_str()));
}