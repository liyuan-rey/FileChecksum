#if !defined(AFX_DLGMAIN_H__7134DB24_0BC3_4B28_88DA_FE7FD6137568__INCLUDED_)
#define AFX_DLGMAIN_H__7134DB24_0BC3_4B28_88DA_FE7FD6137568__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMain.h : header file
//

#include "resource.h"

#include "PageSetting.h"
#include "PageInfo.h"
#include "PageAbout.h"

#define SafeFreeMem(p) if(p){delete p; p = NULL;}
	
/////////////////////////////////////////////////////////////////////////////
// CDlgMain dialog

class CDlgMain : public CDialog
{
// Construction
public:
	CString GetFile();
	void SetFile(const TCHAR* szFileName);
	CDlgMain(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgMain)
	enum { IDD = IDD_DIALOG_MAIN };
	CButton	m_btnHelp;
	CButton	m_btnOK;
	CButton	m_btnPrev;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMain)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	TCHAR m_szFileName[MAX_PATH];
	CWnd* m_pPrevPage;
	BOOL SwitchPage(CWnd* pWndToShow);
	CWnd * GetVisibleWnd(void);
	CPageSetting * m_pPageSetting;
	CPageInfo * m_pPageInfo;
	CPageAbout * m_pPageAbout;

	// Generated message map functions
	//{{AFX_MSG(CDlgMain)
	afx_msg void OnPrev();
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	virtual void OnCancel();
	afx_msg void OnOk();
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMAIN_H__7134DB24_0BC3_4B28_88DA_FE7FD6137568__INCLUDED_)
