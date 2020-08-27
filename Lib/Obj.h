// Obj.h : Declaration of the CObj

#pragma once
#include "resource.h"       // main symbols



#include "Lib_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CObj

class ATL_NO_VTABLE CObj :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CObj, &CLSID_Obj>,
	public IDispatchImpl<IObj, &IID_IObj, &LIBID_LibLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CObj()
	{
		m_pUnkMarshaler = nullptr;
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CObj)
	COM_INTERFACE_ENTRY(IObj)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	HRESULT FinalConstruct()
	{
		return CoCreateFreeThreadedMarshaler(
			GetControllingUnknown(), &m_pUnkMarshaler.p);
	}

	void FinalRelease()
	{
		m_pUnkMarshaler.Release();
	}

	CComPtr<IUnknown> m_pUnkMarshaler;

// IObj
	IFACEMETHOD(Add)(LONG A, LONG B, LONG* C) override
	{
		WCHAR Text[128];
		swprintf_s(Text, L"%hs(%d): %hs: this 0x%p, A %d, B %d\n", __FILE__, __LINE__, __FUNCTION__, this, A, B);
		OutputDebugStringW(Text);
		if(!C)
			return E_POINTER;
		*C = A + B;
		return S_OK;
	}
};

OBJECT_ENTRY_AUTO(__uuidof(Obj), CObj)
