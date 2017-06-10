
// Shapesv7Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Shapesv7.h"
#include "Shapesv7Dlg.h"
#include "afxdialogex.h"
#include "pShapes.h"

#include <sstream>
#include <string>
#include <vector>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CShapesv7Dlg dialog



CShapesv7Dlg::CShapesv7Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHAPESV7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShapesv7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CShapesv7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_CBN_SELCHANGE(IDC_COMBO1, &CShapesv7Dlg::OnCbnSelchangeCombo1)
  ON_BN_CLICKED(IDOK, &CShapesv7Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CShapesv7Dlg message handlers

BOOL CShapesv7Dlg::OnInitDialog()
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
  CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
  pCombo->InsertString(0, _T("Square"));
  pCombo->InsertString(1, _T("Rectangle"));
  pCombo->InsertString(2, _T("Circle"));
  pCombo->InsertString(3, _T("Triangle"));
  pCombo->InsertString(4, _T("Cube"));
  pCombo->InsertString(5, _T("Box"));
  pCombo->InsertString(6, _T("Cylinder"));
  pCombo->InsertString(7, _T("Prism"));
  pCombo->SetCurSel(-1);

  CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC4));
  pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
  HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
    MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
  pPicture->SetBitmap(hb);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShapesv7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShapesv7Dlg::OnPaint()
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
HCURSOR CShapesv7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CShapesv7Dlg::oneBox(CEdit*& pEdit1, CEdit*& pEdit2, CEdit*& pEdit3)
{
  pEdit1->SetReadOnly(FALSE);
  pEdit2->SetWindowText(CString(_T("")));
  pEdit2->SetReadOnly(TRUE);
  pEdit3->SetWindowText(CString(_T("")));
  pEdit3->SetReadOnly(TRUE);
  
}

void CShapesv7Dlg::twoBoxes(CEdit*& pEdit1, CEdit*& pEdit2, CEdit*& pEdit3)
{
  pEdit1->SetReadOnly(FALSE);
  pEdit2->SetReadOnly(FALSE);
  pEdit3->SetWindowText(CString(_T("")));
  pEdit3->SetReadOnly(TRUE);
}

void CShapesv7Dlg::threeBoxes(CEdit*& pEdit1, CEdit*& pEdit2, CEdit*& pEdit3)
{
  pEdit1->SetReadOnly(FALSE);
  pEdit2->SetReadOnly(FALSE);
  pEdit3->SetReadOnly(FALSE);
}

void CShapesv7Dlg::calculate()
{
  ostringstream sout;
  vector<string> tokens;
  CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));  // 1-3: text inputs
  CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
  CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
  CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));  // 4: output box
  CEdit* pEdit5 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT5));  // 5-7: text labels
  CEdit* pEdit6 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT6));
  CEdit* pEdit7 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT7));

  CString mEdit1;
  CString mEdit2;
  CString mEdit3;

  CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
  int n = pCombo->GetCurSel();
  switch (n)
  {
    case 0: 
    {
      tokens.push_back("Square");
      oneBox(pEdit1, pEdit2, pEdit3);
      pEdit5->SetWindowText(CString(_T("Side")));
      pEdit6->SetWindowText(CString(_T("")));
      pEdit7->SetWindowText(CString(_T("")));

      pEdit1->GetWindowText(mEdit1);
      string side = CStringA(mEdit1);
      tokens.push_back(side);

      Square sq(tokens);
      sq.output(sout);
      break;
    }
    case 1:
    {
      tokens.push_back("Rectangle");
      twoBoxes(pEdit1, pEdit2, pEdit3);
      pEdit5->SetWindowText(CString(_T("Length")));
      pEdit6->SetWindowText(CString(_T("Width")));
      pEdit7->SetWindowText(CString(_T("")));

      pEdit1->GetWindowText(mEdit1);
      pEdit2->GetWindowText(mEdit2);
      string length = CStringA(mEdit1);
      string width = CStringA(mEdit2);
      tokens.push_back(length);
      tokens.push_back(width);

      comsc::Rectangle re(tokens);
      re.output(sout);
      break;
    }
    case 2:
    {
      tokens.push_back("Circle");
      oneBox(pEdit1, pEdit2, pEdit3);
      pEdit5->SetWindowText(CString(_T("Radius")));
      pEdit6->SetWindowText(CString(_T("")));
      pEdit7->SetWindowText(CString(_T("")));

      pEdit1->GetWindowText(mEdit1);
      string radius = CStringA(mEdit1);
      tokens.push_back(radius);

      Circle cr(tokens);
      cr.output(sout);
      break;
    }
    case 3:
    {
      tokens.push_back("Triangle");
      oneBox(pEdit1, pEdit2, pEdit3);
      pEdit5->SetWindowText(CString(_T("Side")));
      pEdit6->SetWindowText(CString(_T("")));
      pEdit7->SetWindowText(CString(_T("")));

      pEdit1->GetWindowText(mEdit1);
      string side = CStringA(mEdit1);
      tokens.push_back(side);

      Triangle tr(tokens);
      tr.output(sout);
      break;
    }
    case 4:
    {
      tokens.push_back("Cube");
      oneBox(pEdit1, pEdit2, pEdit3);
      pEdit5->SetWindowText(CString(_T("Side")));
      pEdit6->SetWindowText(CString(_T("")));
      pEdit7->SetWindowText(CString(_T("")));

      pEdit1->GetWindowText(mEdit1);
      string side = CStringA(mEdit1);
      tokens.push_back(side);

      Cube cu(tokens);
      cu.output(sout);
      break;
    }
    case 5:
    {
      tokens.push_back("Box");
      threeBoxes(pEdit1, pEdit2, pEdit3);
      pEdit5->SetWindowText(CString(_T("Length")));
      pEdit6->SetWindowText(CString(_T("Width")));
      pEdit7->SetWindowText(CString(_T("Height")));

      pEdit1->GetWindowText(mEdit1);
      pEdit2->GetWindowText(mEdit2);
      pEdit3->GetWindowText(mEdit3);
      string length = CStringA(mEdit1);
      string width = CStringA(mEdit2);
      string height = CStringA(mEdit3);
      tokens.push_back((string)CStringA(mEdit1));
      tokens.push_back((string)CStringA(mEdit2));
      tokens.push_back((string)CStringA(mEdit3));

      Box bx(tokens);
      bx.output(sout);
      break;
    }
    case 6:
    {
      tokens.push_back("Cylinder");
      twoBoxes(pEdit1, pEdit2, pEdit3);
      pEdit5->SetWindowText(CString(_T("Radius")));
      pEdit6->SetWindowText(CString(_T("Height")));
      pEdit7->SetWindowText(CString(_T("")));

      pEdit1->GetWindowText(mEdit1);
      pEdit2->GetWindowText(mEdit2);
      string radius = CStringA(mEdit1);
      string height = CStringA(mEdit2);
      tokens.push_back(radius);
      tokens.push_back(height);

      Cylinder cy(tokens);
      cy.output(sout);
      break;
    }
    case 7:
    {
      tokens.push_back("Prism");
      twoBoxes(pEdit1, pEdit2, pEdit3);
      pEdit5->SetWindowText(CString(_T("Side")));
      pEdit6->SetWindowText(CString(_T("Height")));
      pEdit7->SetWindowText(CString(_T("")));

      pEdit1->GetWindowText(mEdit1);
      pEdit2->GetWindowText(mEdit2);
      string side = CStringA(mEdit1);
      string height = CStringA(mEdit2);
      tokens.push_back(side);
      tokens.push_back(height);

      Prism pr(tokens);
      pr.output(sout);
      break;
    }
  }
  pEdit4->SetWindowText(CString(sout.str().c_str()));
}
void CShapesv7Dlg::OnCbnSelchangeCombo1()
{
  calculate();
}


void CShapesv7Dlg::OnBnClickedOk()
{
  calculate();
}
