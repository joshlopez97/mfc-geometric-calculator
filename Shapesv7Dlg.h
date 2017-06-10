
// Shapesv7Dlg.h : header file
//

#pragma once


// CShapesv7Dlg dialog
class CShapesv7Dlg : public CDialogEx
{
// Construction
public:
	CShapesv7Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHAPESV7_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

  void oneBox(CEdit*&, CEdit*&, CEdit*&);
  void twoBoxes(CEdit*&, CEdit*&, CEdit*&);
  void threeBoxes(CEdit*&, CEdit*&, CEdit*&);
  void calculate();
public:
  afx_msg void OnCbnSelchangeCombo1();
  afx_msg void OnBnClickedOk();
};
