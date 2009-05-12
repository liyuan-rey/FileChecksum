#if !defined(AFX_PAGESETTING_H__FFB3CBEB_F7C6_4FC0_A65A_224762D989B7__INCLUDED_)
#define AFX_PAGESETTING_H__FFB3CBEB_F7C6_4FC0_A65A_224762D989B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageSetting.h : header file
//

#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// CPageSetting dialog

class CPageSetting : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageSetting)

// Construction
public:
	CPageSetting();
	~CPageSetting();

// Dialog Data
	//{{AFX_DATA(CPageSetting)
	enum { IDD = IDD_PROPPAGE_SETTING };
	CButton	m_btnBackup;
	CEdit	m_edtCustom;
	CString	m_szFileName;
	int		m_nOperation;
	CString	m_szAddress;
	CString	m_szChecksum;
	DWORD	m_dwCheckValue;
	CString	m_szCurrentSum;
	DWORD	m_dwCurrentValue;
	CString	m_szPreview;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPageSetting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void Switch(void);
	// Generated message map functions
	//{{AFX_MSG(CPageSetting)
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESETTING_H__FFB3CBEB_F7C6_4FC0_A65A_224762D989B7__INCLUDED_)
