// PageSetting.cpp : implementation file
//

#include "stdafx.h"
#include "filechecksum.h"
#include "PageSetting.h"

#include "DlgMain.h"
#include <Imagehlp.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageSetting property page

IMPLEMENT_DYNCREATE(CPageSetting, CPropertyPage)

CPageSetting::CPageSetting() : CPropertyPage(CPageSetting::IDD)
{
	//{{AFX_DATA_INIT(CPageSetting)
	m_szFileName = _T("");
	m_nOperation = 0;
	m_szAddress = _T("");
	m_szChecksum = _T("");
	m_dwCheckValue = 0;
	m_szCurrentSum = _T("");
	m_dwCurrentValue = 0;
	m_szPreview = _T("");
	//}}AFX_DATA_INIT
}

CPageSetting::~CPageSetting()
{
}

void CPageSetting::DoDataExchange(CDataExchange *pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageSetting)
	DDX_Control(pDX, IDC_BACKUP, m_btnBackup);
	DDX_Control(pDX, IDC_CUSTOM, m_edtCustom);
	DDX_Text(pDX, IDC_FILENAME, m_szFileName);
	DDX_Radio(pDX, IDC_RADIO1, m_nOperation);
	DDX_Text(pDX, IDC_ADDRESS, m_szAddress);
	DDX_Text(pDX, IDC_CHECKSUM, m_szChecksum);
	DDX_Text(pDX, IDC_CHECKVALUE, m_dwCheckValue);
	DDX_Text(pDX, IDC_CURRENTSUM, m_szCurrentSum);
	DDX_Text(pDX, IDC_CURRENTVALUE, m_dwCurrentValue);
	DDX_Text(pDX, IDC_PREVIEW, m_szPreview);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPageSetting, CPropertyPage)
//{{AFX_MSG_MAP(CPageSetting)
ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageSetting message handlers

BOOL CPageSetting::OnInitDialog()
{
	m_szFileName = ((CDlgMain *)GetParent())->GetFile();
	DWORD dwRet = MapFileAndCheckSum(m_szFileName.GetBuffer(0), &m_dwCurrentValue, &m_dwCheckValue);

	switch (dwRet)
	{
	case CHECKSUM_SUCCESS:
		m_szAddress = _T("0x0000E5D8");
		break;

	case CHECKSUM_OPEN_FAILURE:
		m_szAddress = _T("错误:无法打开文件!");
		break;

	case CHECKSUM_MAP_FAILURE:
		m_szAddress = _T("错误:无法映射文件!");
		break;

	case CHECKSUM_MAPVIEW_FAILURE:
		m_szAddress = _T("错误:无法映射文件的视!");
		break;

	case CHECKSUM_UNICODE_FAILURE:
		m_szAddress = _T("错误:无法转换文件名为 Unicode !");
		break;

	default:
		m_szAddress = _T("错误:未知错误!");
	}

	m_szFileName.ReleaseBuffer();

	CPropertyPage::OnInitDialog();

	// TODO: Add extra initialization here

	return TRUE; // return TRUE unless you set the focus to a control
				 // EXCEPTION: OCX Property Pages should return FALSE
}

void CPageSetting::OnRadio1()
{
	// TODO: Add your control notification handler code here
	Switch();
}

void CPageSetting::OnRadio2()
{
	// TODO: Add your control notification handler code here
	Switch();
}

void CPageSetting::OnRadio3()
{
	// TODO: Add your control notification handler code here
	Switch();
}

void CPageSetting::Switch()
{
	int nPreValue = m_nOperation;
	UpdateData(TRUE);
	if (m_nOperation == nPreValue)
		return;

	m_btnBackup.EnableWindow(m_nOperation ? TRUE : FALSE);
	m_edtCustom.EnableWindow(m_nOperation == 2 ? TRUE : FALSE);

	UpdateData(FALSE);
}
