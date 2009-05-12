#if !defined(AFX_PAGEINFO_H__0C1F7B1E_DF96_444F_8918_A50447636BE0__INCLUDED_)
#define AFX_PAGEINFO_H__0C1F7B1E_DF96_444F_8918_A50447636BE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageInfo.h : header file
//

#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// CPageInfo dialog

class CPageInfo : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageInfo)

// Construction
public:
	CPageInfo();
	~CPageInfo();

// Dialog Data
	//{{AFX_DATA(CPageInfo)
	enum { IDD = IDD_PROPPAGE_INFO };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPageInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPageInfo)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEINFO_H__0C1F7B1E_DF96_444F_8918_A50447636BE0__INCLUDED_)
