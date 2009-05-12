// PageInfo.cpp : implementation file
//

#include "stdafx.h"
#include "filechecksum.h"
#include "PageInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageInfo property page

IMPLEMENT_DYNCREATE(CPageInfo, CPropertyPage)

CPageInfo::CPageInfo() : CPropertyPage(CPageInfo::IDD)
{
	//{{AFX_DATA_INIT(CPageInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPageInfo::~CPageInfo()
{
}

void CPageInfo::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageInfo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageInfo, CPropertyPage)
	//{{AFX_MSG_MAP(CPageInfo)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageInfo message handlers
