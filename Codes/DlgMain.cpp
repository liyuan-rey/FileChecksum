// DlgMain.cpp : implementation file
//

#include "stdafx.h"
#include "filechecksum.h"
#include "DlgMain.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMain dialog

CDlgMain::CDlgMain(CWnd *pParent /*=NULL*/)
	: CDialog(CDlgMain::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMain)
	//}}AFX_DATA_INIT

	m_pPageSetting = NULL;
	m_pPageInfo = NULL;
	m_pPageAbout = NULL;
	m_pPrevPage = NULL;
}

void CDlgMain::DoDataExchange(CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMain)
	DDX_Control(pDX, IDC_PREV, m_btnPrev);
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDHELP, m_btnHelp);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgMain, CDialog)
//{{AFX_MSG_MAP(CDlgMain)
ON_WM_DESTROY()
ON_BN_CLICKED(IDC_PREV, OnPrev)
ON_BN_CLICKED(IDOK, OnOk)
ON_BN_CLICKED(IDHELP, OnHelp)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMain message handlers

BOOL CDlgMain::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	ModifyStyleEx(0, WS_EX_CONTROLPARENT);

	m_pPageSetting = new CPageSetting;
	m_pPageInfo = new CPageInfo;
	m_pPageAbout = new CPageAbout;

	if (m_pPageSetting == NULL || m_pPageInfo == NULL || m_pPageAbout == NULL)
		return FALSE;

	if (!m_pPageSetting->Create(CPageSetting::IDD, this) || !m_pPageInfo->Create(CPageInfo::IDD, this) || !m_pPageAbout->Create(CPageAbout::IDD, this))
	{
		SafeFreeMem(m_pPageSetting);
		SafeFreeMem(m_pPageInfo);
		SafeFreeMem(m_pPageAbout);

		return FALSE;
	}

	CRect rect;
	CWnd *pWnd = GetDlgItem(IDC_PLACEHOLDER);
	ASSERT(pWnd != NULL);
	ASSERT(IsWindow(pWnd->m_hWnd) != FALSE);
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);

	m_pPageSetting->SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(),
								 SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE);
	m_pPageSetting->EnableWindow(TRUE);

	m_pPageInfo->SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(),
							  SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE);
	m_pPageInfo->EnableWindow(FALSE);

	m_pPageAbout->SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(),
							   SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE);
	m_pPageAbout->EnableWindow(FALSE);

	m_pPageSetting->ShowWindow(SW_SHOW);
	m_pPageSetting->SetFocus();

	return FALSE; // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMain::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: Add your message handler code here
	m_pPageSetting->DestroyWindow();
	m_pPageInfo->DestroyWindow();
	m_pPageAbout->DestroyWindow();

	SafeFreeMem(m_pPageSetting);
	SafeFreeMem(m_pPageInfo);
	SafeFreeMem(m_pPageAbout);
}

CWnd *CDlgMain::GetVisibleWnd()
{
	if (m_pPageSetting->IsWindowVisible())
		return m_pPageSetting;

	if (m_pPageInfo->IsWindowVisible())
		return m_pPageInfo;

	if (m_pPageAbout->IsWindowVisible())
		return m_pPageAbout;

	return NULL;

	//	return m_pPageSetting->IsWindowVisible() ? \
//		m_pPageSetting : m_pPageInfo->IsWindowVisible() ? \
//		m_pPageInfo : m_pPageAbout->IsWindowVisible() ? m_pPageAbout : NULL;
}

BOOL CDlgMain::SwitchPage(CWnd *pWndToShow)
{
	if (pWndToShow->IsWindowVisible())
		return FALSE;

	CWnd *pVisibleWnd = GetVisibleWnd();

	if (pVisibleWnd)
	{
		pVisibleWnd->ShowWindow(SW_HIDE);
		pVisibleWnd->EnableWindow(FALSE);
	}

	pWndToShow->EnableWindow(TRUE);
	pWndToShow->ShowWindow(SW_SHOW);
	pWndToShow->InvalidateRect(NULL);
	pWndToShow->UpdateWindow();
	pWndToShow->SetActiveWindow();

	return TRUE;
}

void CDlgMain::OnCancel()
{
	// TODO: Add extra cleanup here

	//CDialog::OnCancel();
}

void CDlgMain::OnPrev()
{
	// TODO: Add your control notification handler code here
	CWnd *pWndVisible = GetVisibleWnd();

	if (pWndVisible->IsKindOf(RUNTIME_CLASS(CPageInfo)))
	{
		m_btnPrev.ShowWindow(FALSE);
		m_btnOK.SetWindowText(_T("下一步(&N)"));

		m_pPrevPage = m_pPageInfo;
		SwitchPage(m_pPageSetting);
	}
}

void CDlgMain::OnOk()
{
	// TODO: Add your control notification handler code here
	CWnd *pWndVisible = GetVisibleWnd();

	if (pWndVisible->IsKindOf(RUNTIME_CLASS(CPageSetting)))
	{
		// Do some job
		// ...

		m_btnPrev.ShowWindow(TRUE);
		m_btnOK.SetWindowText(_T("完成(&F)"));

		m_pPrevPage = m_pPageSetting;
		SwitchPage(m_pPageInfo);

		return;
	}

	if (pWndVisible->IsKindOf(RUNTIME_CLASS(CPageInfo)))
		CDialog::OnOK();
}

void CDlgMain::OnHelp()
{
	// TODO: Add your control notification handler code here
	CWnd *pWndVisible = GetVisibleWnd();

	if (pWndVisible->IsKindOf(RUNTIME_CLASS(CPageAbout)))
	{
		m_btnPrev.EnableWindow(TRUE);
		m_btnOK.EnableWindow(TRUE);

		m_btnHelp.SetWindowText(_T("帮助(&H)"));

		SwitchPage(m_pPrevPage);
		m_pPrevPage = m_pPageAbout;
	}
	else
	{
		m_btnPrev.EnableWindow(FALSE);
		m_btnOK.EnableWindow(FALSE);

		m_btnHelp.SetWindowText(_T("<<返回(&R)"));

		m_pPrevPage = pWndVisible;
		SwitchPage(m_pPageAbout);
	}
}

void CDlgMain::SetFile(const TCHAR *szFileName)
{
	ASSERT(MAX_PATH >= (sizeof(szFileName) / sizeof(TCHAR)));
	lstrcpyn(m_szFileName, szFileName, MAX_PATH);
}

CString CDlgMain::GetFile()
{
	return CString(m_szFileName);
}
