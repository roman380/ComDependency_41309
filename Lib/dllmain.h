// dllmain.h : Declaration of module class.

class CLibModule : public ATL::CAtlDllModuleT< CLibModule >
{
public :
	DECLARE_LIBID(LIBID_LibLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_LIB, "{3b6fbd23-f8ba-474c-aaee-a2456c9b6ddf}")
};

extern class CLibModule _AtlModule;
