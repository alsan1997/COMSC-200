// Lab 13, GeometryHomework7Dlg.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Microsoft Visual Studio 2013
// Compiler(s) used: Microsoft Visual Studio 2013

// GeometryHomework7Dlg.cpp : implementation file


#include "stdafx.h"
#include "GeometryHomework7.h"
#include "GeometryHomework7Dlg.h"
#include "GeometryHomework.h"
#include "afxdialogex.h"

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


// CGeometryHomework7Dlg dialog



CGeometryHomework7Dlg::CGeometryHomework7Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGeometryHomework7Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGeometryHomework7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGeometryHomework7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO5, &CGeometryHomework7Dlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDOK, &CGeometryHomework7Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO2, &CGeometryHomework7Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO1, &CGeometryHomework7Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &CGeometryHomework7Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CGeometryHomework7Dlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO6, &CGeometryHomework7Dlg::OnBnClickedRadio6)
END_MESSAGE_MAP()


// CGeometryHomework7Dlg message handlers

BOOL CGeometryHomework7Dlg::OnInitDialog()
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
	CButton* pRadio1 = (CButton*)GetDlgItem(IDC_RADIO1);
	pRadio1->SetCheck(BST_CHECKED);

	CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
	CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
	CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);
	pEdit2->ShowWindow(SW_HIDE);
	pEdit3->ShowWindow(SW_HIDE);
	pStatic2->ShowWindow(SW_HIDE);
	pStatic3->ShowWindow(SW_HIDE);

	CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
	pStatic1->SetWindowText(CString(_T("Side")));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGeometryHomework7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGeometryHomework7Dlg::OnPaint()
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
HCURSOR CGeometryHomework7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGeometryHomework7Dlg::OnBnClickedOk()
{
  // TODO: Add your control notification handler code here
  ostringstream sout;
  const char* token[4] = {0, 0, 0, 0};

  CButton* pRadio1 = (CButton*)GetDlgItem(IDC_RADIO1);
  int c1 = pRadio1->GetCheck(); // BST_UNCHECKED for unselected, BST_CHECKED for selected  
  CButton* pRadio2 = (CButton*)GetDlgItem(IDC_RADIO2);
  int c2 = pRadio2->GetCheck(); // BST_UNCHECKED for unselected, BST_CHECKED for selected
  CButton* pRadio3 = (CButton*)GetDlgItem(IDC_RADIO3);
  int c3 = pRadio3->GetCheck(); // BST_UNCHECKED for unselected, BST_CHECKED for selected
  CButton* pRadio4 = (CButton*)GetDlgItem(IDC_RADIO4);
  int c4 = pRadio4->GetCheck(); // BST_UNCHECKED for unselected, BST_CHECKED for selected
  CButton* pRadio5 = (CButton*)GetDlgItem(IDC_RADIO5);
  int c5 = pRadio5->GetCheck(); // BST_UNCHECKED for unselected, BST_CHECKED for selected
  CButton* pRadio6 = (CButton*)GetDlgItem(IDC_RADIO6);
  int c6 = pRadio6->GetCheck(); // BST_UNCHECKED for unselected, BST_CHECKED for selected

  CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
  CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
  CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);

  CString edit1;
  pEdit1->GetWindowText(edit1);

  CString edit2;
  pEdit2->GetWindowText(edit2);

  CString edit3;
  pEdit3->GetWindowText(edit3);

  if(c1 == BST_CHECKED)
  {
	CEdit* result = (CEdit*)GetDlgItem(IDC_EDIT4);

	string s1 = CStringA(edit1);
	token[1] = s1.c_str();

    Square s(token);
	sout << &s;

	result->SetWindowText(CString(sout.str().c_str()));
  }
  
  if(c2 == BST_CHECKED)
  {
    CEdit* result = (CEdit*)GetDlgItem(IDC_EDIT4);

    string s1 = CStringA(edit1);
    token[1] = s1.c_str();

    string s2 = CStringA(edit2);
    token[2] = s2.c_str();

	comsc::Rectangle r(token);
	sout << &r;

    result->SetWindowText(CString(sout.str().c_str()));
  }

  if(c3 == BST_CHECKED)
  {
	CEdit* result = (CEdit*)GetDlgItem(IDC_EDIT4);

	string s1 = CStringA(edit1);
	token[1] = s1.c_str();

	Circle c(token);
	sout << &c;

	result->SetWindowText(CString(sout.str().c_str()));
  }

  if(c4 == BST_CHECKED)
  {
    CEdit* result = (CEdit*)GetDlgItem(IDC_EDIT4);

	string s1 = CStringA(edit1);
	token[1] = s1.c_str();

	Cube cu(token);
	sout << &cu;

	result->SetWindowText(CString(sout.str().c_str()));
  }

  if(c5 == BST_CHECKED)
  {
    CEdit* result = (CEdit*)GetDlgItem(IDC_EDIT4);

    string s1 = CStringA(edit1);
    token[1] = s1.c_str();

	string s2 = CStringA(edit2);
	token[2] = s2.c_str();

	string s3 = CStringA(edit3);
	token[3] = s3.c_str();

	Prism p(token);
	sout << &p;

    result->SetWindowText(CString(sout.str().c_str()));
  }

  if(c6 == BST_CHECKED)
  {
	CEdit* result = (CEdit*)GetDlgItem(IDC_EDIT4);

    string s1 = CStringA(edit1);
    token[1] = s1.c_str();

    string s2 = CStringA(edit2);
    token[2] = s2.c_str();

	Cylinder cl(token);
	sout << &cl;

    result->SetWindowText(CString(sout.str().c_str()));
  }
}

void CGeometryHomework7Dlg::OnBnClickedRadio1()
{
  CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
  CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
  CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
  CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
  CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);

  pEdit2->ShowWindow(SW_HIDE);
  pEdit3->ShowWindow(SW_HIDE);
  pStatic2->ShowWindow(SW_HIDE);
  pStatic3->ShowWindow(SW_HIDE);

  CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
  pStatic1->SetWindowText(CString(_T("Side")));

  pEdit1->SetWindowText(CString(_T("")));
}

void CGeometryHomework7Dlg::OnBnClickedRadio2()
{
  // TODO: Add your control notification handler code here
  CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
  CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
  CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
  CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
  CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);

  pEdit1->SetWindowText(CString(_T("")));
  pEdit2->ShowWindow(SW_SHOW);
  pEdit2->SetWindowText(CString(_T("")));
  pEdit3->ShowWindow(SW_HIDE);
  pStatic2->ShowWindow(SW_SHOW);
  pStatic3->ShowWindow(SW_HIDE);

  CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
  pStatic1->SetWindowText(CString(_T("Length")));
  pStatic2->SetWindowText(CString(_T("Width")));
}

void CGeometryHomework7Dlg::OnBnClickedRadio3()
{
  // TODO: Add your control notification handler code here
  CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
  CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
  CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
  CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
  CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);

  pEdit1->SetWindowText(CString(_T("")));
  pEdit2->ShowWindow(SW_HIDE);
  pEdit3->ShowWindow(SW_HIDE);
  pStatic2->ShowWindow(SW_HIDE);
  pStatic3->ShowWindow(SW_HIDE);

  CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
  pStatic1->SetWindowText(CString(_T("Radius")));
}

void CGeometryHomework7Dlg::OnBnClickedRadio4()
{
  // TODO: Add your control notification handler code here
  CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
  CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
  CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
  CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
  CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);

  pEdit1->SetWindowText(CString(_T("")));
  pEdit2->ShowWindow(SW_HIDE);
  pEdit3->ShowWindow(SW_HIDE);
  pStatic2->ShowWindow(SW_HIDE);
  pStatic3->ShowWindow(SW_HIDE);

  CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
  pStatic1->SetWindowText(CString(_T("Side")));
}


void CGeometryHomework7Dlg::OnBnClickedRadio5()
{
  // TODO: Add your control notification handler code here
  CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
  CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
  CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
  CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
  CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);

  pEdit1->SetWindowText(CString(_T("")));
  pEdit2->ShowWindow(SW_SHOW);
  pEdit2->SetWindowText(CString(_T("")));
  pEdit3->ShowWindow(SW_SHOW);
  pEdit3->SetWindowText(CString(_T("")));
  pStatic2->ShowWindow(SW_SHOW);
  pStatic3->ShowWindow(SW_SHOW);

  CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
  pStatic1->SetWindowText(CString(_T("Length")));
  pStatic2->SetWindowText(CString(_T("Width")));
}

void CGeometryHomework7Dlg::OnBnClickedRadio6()
{
  // TODO: Add your control notification handler code here
  CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
  CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
  CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
  CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
  CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);

  pEdit1->SetWindowText(CString(_T("")));
  pEdit2->ShowWindow(SW_SHOW);
  pEdit2->SetWindowText(CString(_T("")));
  pEdit3->ShowWindow(SW_HIDE);
  pStatic2->ShowWindow(SW_SHOW);
  pStatic3->ShowWindow(SW_HIDE);

  CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
  pStatic1->SetWindowText(CString(_T("Radius")));

  pStatic2->SetWindowText(CString(_T("Height")));
}
