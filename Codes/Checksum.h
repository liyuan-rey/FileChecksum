// Checksum.h: Definition of the CChecksum class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHECKSUM_H__5711A25C_6E45_4158_B7AE_BA05551313FB__INCLUDED_)
#define AFX_CHECKSUM_H__5711A25C_6E45_4158_B7AE_BA05551313FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

#include <shlobj.h>
#include <comdef.h>

/////////////////////////////////////////////////////////////////////////////
// CChecksum

class CChecksum : 
	public IDispatchImpl<IChecksum, &IID_IChecksum, &LIBID_FILECHECKSUMLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CChecksum,&CLSID_Checksum>,
	public IShellExtInit,
	public IContextMenu
{
public:
	CChecksum();

BEGIN_COM_MAP(CChecksum)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IChecksum)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IContextMenu)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CChecksum) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_Checksum)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IChecksum
public:
	// IShellExtInit
	STDMETHOD(Initialize)(LPCITEMIDLIST, LPDATAOBJECT, HKEY);

	// IContextMenu
	STDMETHOD(GetCommandString)(UINT, UINT, UINT*, LPSTR, UINT);
	STDMETHOD(InvokeCommand)(LPCMINVOKECOMMANDINFO);
	STDMETHOD(QueryContextMenu)(HMENU, UINT, UINT, UINT, UINT);

protected:
	HBITMAP     m_hBitmap;
	TCHAR		m_szFile[MAX_PATH];
};

#endif // !defined(AFX_CHECKSUM_H__5711A25C_6E45_4158_B7AE_BA05551313FB__INCLUDED_)
