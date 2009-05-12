#if !defined(AFX_PAGEABOUT_H__C1219687_50FD_44DD_A0E9_846CE507AA50__INCLUDED_)
#define AFX_PAGEABOUT_H__C1219687_50FD_44DD_A0E9_846CE507AA50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageAbout.h : header file
//

#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// CPageAbout dialog

class CPageAbout : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageAbout)

// Construction
public:
	CPageAbout();
	~CPageAbout();

// Dialog Data
	//{{AFX_DATA(CPageAbout)
	enum { IDD = IDD_PROPPAGE_ABOUT };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPageAbout)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPageAbout)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEABOUT_H__C1219687_50FD_44DD_A0E9_846CE507AA50__INCLUDED_)
