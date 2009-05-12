// Checksum.cpp : Implementation of CFileChecksumApp and DLL registration.

#include "stdafx.h"
#include "FileChecksum.h"
#include "Checksum.h"

#include <atlconv.h>  // for ATL string conversion macros
#include "DlgMain.h"

/////////////////////////////////////////////////////////////////////////////
//

CChecksum::CChecksum()
{
	m_hBitmap = LoadBitmap ( _Module.GetModuleInstance(),
		MAKEINTRESOURCE(IDI_MENUBMP) );
}

STDMETHODIMP CChecksum::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IChecksum,
	};
	
	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

HRESULT CChecksum::Initialize (
							   LPCITEMIDLIST pidlFolder,
							   LPDATAOBJECT pDataObj,
							   HKEY hProgID )
{
	FORMATETC fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	STGMEDIUM stg = { TYMED_HGLOBAL };
	HDROP	  hDrop;
	
	// Look for CF_HDROP data in the data object.
	if ( FAILED( pDataObj->GetData ( &fmt, &stg )))
	{
		// Nope! Return an "invalid argument" error back to Explorer.
		return E_INVALIDARG;
	}
	
	// Get a pointer to the actual data.
	hDrop = (HDROP) GlobalLock ( stg.hGlobal );
	
	// Make sure it worked.
	if ( NULL == hDrop )
	{
		return E_INVALIDARG;
	}
	
	// Sanity check – make sure there is at least one filename.
	UINT uNumFiles = DragQueryFile ( hDrop, 0xFFFFFFFF, NULL, 0 );
	
	if ( 0 == uNumFiles )
	{
		GlobalUnlock ( stg.hGlobal );
		ReleaseStgMedium ( &stg );
		return E_INVALIDARG;
	}
	
	HRESULT hr = S_OK;
	
	// Get the name of the first file and store it in our member variable m_szFile.
	if ( 0 == DragQueryFile ( hDrop, 0, m_szFile, MAX_PATH ))
	{
		hr = E_INVALIDARG;
	}
	
	GlobalUnlock ( stg.hGlobal );
	ReleaseStgMedium ( &stg );
	
	return hr;
}

HRESULT CChecksum::QueryContextMenu (
									 HMENU hmenu,
									 UINT  uMenuIndex, 
									 UINT  uidFirstCmd,
									 UINT  uidLastCmd,
									 UINT  uFlags )
{
	// If the flags include CMF_DEFAULTONLY then we shouldn't do anything.
	if ( uFlags & CMF_DEFAULTONLY )
	{
		return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, 0 );
	}
	
	InsertMenu ( hmenu, uMenuIndex, MF_STRING | MF_BYPOSITION, uidFirstCmd, _T("校验信息...") );
	
	if ( NULL != m_hBitmap )
	{
		SetMenuItemBitmaps ( hmenu, uMenuIndex, MF_BYPOSITION, m_hBitmap, NULL );
	}
	
	return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, 1 );
}

HRESULT CChecksum::GetCommandString (
									 UINT idCmd,
									 UINT uFlags,
									 UINT *pwReserved,
									 LPSTR pszName,
									 UINT cchMax )
{
	USES_CONVERSION;
	
	// Check idCmd, it must be 0 since we have only one menu item.
	if ( 0 != idCmd )
		return E_INVALIDARG;
	
	// If Explorer is asking for a help string, copy our string into the
	// supplied buffer.
	if ( uFlags & GCS_HELPTEXT )
	{
		LPCTSTR szText = _T("查看 / 添加可执行文件校验和信息");
		
		if ( uFlags & GCS_UNICODE )
		{
			// We need to cast pszName to a Unicode string, and then use the
			// Unicode string copy API.
			lstrcpynW ( (LPWSTR) pszName, T2CW(szText), cchMax );
		}
		else
		{
			// Use the ANSI string copy API to return the help string.
			lstrcpynA ( pszName, T2CA(szText), cchMax );
		}
		
		return S_OK;
	}
	
	return E_INVALIDARG;
}

HRESULT CChecksum::InvokeCommand ( LPCMINVOKECOMMANDINFO pCmdInfo )
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));	// init MFC
	
	// If lpVerb really points to a string, ignore this function call and bail out.
	if ( 0 != HIWORD( pCmdInfo->lpVerb ))
		return E_INVALIDARG;
	
	// Get the command index - the only valid one is 0.
	switch ( LOWORD( pCmdInfo->lpVerb ))
	{
	case 0:
		{
			try
			{
			CDlgMain dlg;
			dlg.SetFile(m_szFile);
			dlg.DoModal();
//			dlg.Create(CDlgMain::IDD);
//			dlg.ShowWindow(TRUE);
			}
			catch(...)
			{
				MessageBox(NULL, _T("有错误发生!"), _T("Checksum"), MB_ICONERROR | MB_OK);
			}

			return S_OK;
		}
		break;
		
	default:
		return E_INVALIDARG;
		break;
	}
}
