#pragma once
#include <Windows.h>
typedef enum _OFFLINE_STORE_CREATION_PARAMETERS_FLAGS
{
    OFFLINE_STORE_CREATION_PARAMETERS_FLAG_FAKE_ONLINE = 0x4,
    OFFLINE_STORE_CREATION_PARAMETERS_FLAG_APPLY_NO_KTM = 0x10,
} OFFLINE_STORE_CREATION_PARAMETERS_FLAGS;
typedef struct _OFFLINE_STORE_CREATION_PARAMETERS
{
    SIZE_T cbSize;
    DWORD dwFlags;
    LPCWSTR pszHostSystemDrivePath;
    LPCWSTR pszHostWindowsDirectoryPath;
    LPCWSTR pszTargetWindowsDirectoryPath;
    LPCWSTR pszHostRegistryMachineSoftwarePath;
    LPCWSTR pszHostRegistryMachineSystemPath;
    LPCWSTR pszHostRegistryMachineSecurityPath;
    LPCWSTR pszHostRegistryMachineSAMPath;
    LPCWSTR pszHostRegistryMachineComponentsPath;
    LPCWSTR pszHostRegistryUserDotDefaultPath;
    LPCWSTR pszHostRegistryDefaultUserPath;
    ULONG ulProcessorArchitecture;
    LPCWSTR pszHostRegistryMachineOfflineSchemaPath;
} OFFLINE_STORE_CREATION_PARAMETERS, *POFFLINE_STORE_CREATION_PARAMETERS;
typedef struct _OFFLINE_STORE_CREATION_PARAMETERS_EX : _OFFLINE_STORE_CREATION_PARAMETERS
{
    LPCWSTR pszExternalServicingDirectory;
    LPCWSTR pszHostRegistryMachineDriversPath;
    LPCWSTR pszHostRegistryBcdPath;
    LPCWSTR pszHostRegistryExternalServicingPath;
} OFFLINE_STORE_CREATION_PARAMETERS_EX, *POFFLINE_STORE_CREATION_PARAMETERS_EX;

typedef HRESULT(WINAPI* PCREATE_NEW_OFFLINE_STORE_FUNCTION)(
    DWORD dwFlags,
    const OFFLINE_STORE_CREATION_PARAMETERS* pParameters,
    const GUID* riid,
    IUnknown** ppStore,
    PDWORD pdwDisposition);
typedef HRESULT(WINAPI* POPEN_EXISTING_OFFLINE_STORE_FUNCTION)(
    DWORD dwFlags,
    const _OFFLINE_STORE_CREATION_PARAMETERS* pParameters,
    const GUID* riid,
    IUnknown** ppStore,
    PDWORD pdwDisposition);
typedef HRESULT(WINAPI* PCREATE_NEW_PSEUDO_WINDOWS_FUNCTION)(
    DWORD dwFlags,
    LPCWSTR pszRootDirectory,
    LPCWSTR pszRootKey,
    _OFFLINE_STORE_CREATION_PARAMETERS* pParameters);
typedef HRESULT(WINAPI* PCREATE_NEW_PSEUDO_WINDOWS_EX_FUNCTION)(
    DWORD dwFlags,
    LPCWSTR pszRootDirectory,
    LPCWSTR pszRootKey,
    _OFFLINE_STORE_CREATION_PARAMETERS* pParameters,
    PVOID* ppvRootkey);  // Supposed to be Windows::Rtl::IRtlKey**
typedef HRESULT(WINAPI* PCREATE_NEW_WINDOWS_FUNCTION)(
    DWORD dwFlags,
    LPCWSTR pszSystemDrive,
    _OFFLINE_STORE_CREATION_PARAMETERS* pParameters,
    PVOID* ppvKeys, // Supposed to be Windows::WCP::COM::CRegistryKeys **
    PDWORD pdwDisposition);
typedef HRESULT(WINAPI* PDISMOUNT_REGISTRY_HIVES_FUNCTION)(
    PVOID pvKeys); // Supposed to be Windows::WCP::COM::CRegistryKeys **
typedef HRESULT(WINAPI* PWCP_INITIALIZE_FUNCTION)(
    PVOID* InitCookie);
typedef HRESULT(WINAPI* PWCP_SHUTDOWN_FUNCTION)(
    PVOID InitCookie);
typedef HRESULT(WINAPI* PSET_ISOLATION_MALLOC_FUNCTION)(
    IMalloc* alloc);
typedef HRESULT(WINAPI* PGET_APPID_AUTHORITY_FUNCTION)(
    IAppIdAuthority** ppIAppIdAuthority);
typedef HRESULT(WINAPI* PGET_IDENTITY_AUTHORITY_FUNCTION)(
    IIdentityAuthority** ppIIdentityAuthority);
typedef HRESULT(WINAPI* PGET_SYSTEM_STORE_FUNCTION)(
    DWORD dwFlags,
    REFIID riid,
    IUnknown** ppIStore);
typedef HRESULT(WINAPI* POPEN_EXISTING_OFFLINE_STORE_FUNCTION)(
    DWORD dwFlags,
    const POFFLINE_STORE_CREATION_PARAMETERS pParameters,
    REFIID riid,
    IUnknown** ppStore,
    PDWORD pdwDisposition);
typedef HRESULT(WINAPI* PPARSE_MANIFEST_FUNCTION)(
    LPCWSTR pszManifestPath,
    IManifestParseErrorCallback* pIManifestParseErrorCallback,
    REFIID riid,
    IUnknown** ppManifest);
typedef HRESULT(WINAPI* PWCP_DLL_DEBUG_ENTRYPOINT_FUNCTION)(
    UINT __formal,
    LPCVOID Operations);
typedef HRESULT(WINAPI* PFREEANDZERO_CSI_BROKEN_COMPONENT_FUNCTION)(
    UINT celt,
    CSI_BROKEN_COMPONENT* rgElements);
typedef HRESULT(WINAPI* PINITIALIZE_CSI_BROKEN_COMPONENT_FUNCTION)(
    UINT celt,
    CSI_BROKEN_COMPONENT* rgElements);
typedef HRESULT(WINAPI* PFREEANDZERO_CSI_REPAIRED_COMPONENT_FUNCTION)(
    UINT celt,
    CSI_REPAIRED_COMPONENT* rgElements);
typedef HRESULT(WINAPI* PINITIALIZE_CSI_REPAIRED_COMPONENT_FUNCTION)(
    UINT celt,
    CSI_REPAIRED_COMPONENT* rgElements);
typedef enum
{
    CREATE_NEW_OFFLINE_STORE_FLAGS_NO_MANIFEST_CACHING = 0x1,
} CREATE_NEW_OFFLINE_STORE_FLAGS;
typedef enum
{
    CREATE_NEW_WINDOWS_DISABLE_COMPONENT_BACKUPS = 0x1,
    CREATE_NEW_WINDOWS_DISABLE_SMI = 0x2,
    CREATE_NEW_WINDOWS_DISABLE_MANIFEST_CACHE = 0x4,
    CREATE_NEW_WINDOWS_SINGLE_RESOURCE_OWNERSHIP = 0x8,
    CREATE_NEW_WINDOWS_MOBILE_STORE = 0x20,
    CREATE_NEW_WINDOWS_IS_ONE_CORE = 0x40,
} CREATE_NEW_WINDOWS_FLAGS;
typedef enum
{
    OPEN_EXISTING_OFFLINE_STORE_FLAGS_NO_MANIFEST_CACHING = 0x1,
} OPEN_EXISTING_OFFLINE_STORE_FLAGS;
typedef enum
{
    CREATE_NEW_PSEUDO_WINDOWS_FLAG_PICK_A_LOCATION = 0x1,
    CREATE_NEW_PSEUDO_WINDOWS_FLAG_WINPE_LAYOUT = 0x2,
    CREATE_NEW_PSEUDO_WINDOWS_FLAG_PICK_REG_ROOT = 0x4,
    CREATE_NEW_PSEUDO_WINDOWS_FLAG_USE_EXT_STORAGE = 0x8,
    CREATE_NEW_PSEUDO_WINDOWS_FLAG_KEEP_EXISTING = 0x10,
} CREATE_NEW_PSEUDO_WINDOWS_FLAGS;
typedef enum
{
    CREATE_NEW_WINDOWS_VERSION = 0x1,
} CREATE_NEW_WINDOWS_FLAGS2;
typedef struct _IDENTITY_ATTRIBUTE
{
    LPCWSTR pszNamespace;
    LPCWSTR pszName;
    LPCWSTR pszValue;
} IDENTITY_ATTRIBUTE;
MIDL_INTERFACE("9cdaae75-246e-4b00-a26d-b9aec137a3eb")
IEnumIDENTITY_ATTRIBUTE : public IUnknown
{
public:
      virtual HRESULT STDMETHODCALLTYPE Next(SIZE_T, IDENTITY_ATTRIBUTE*, PSIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE CurrentIntoBuffer(SIZE_T, PBYTE, PSIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE Skip(SIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE Reset() = 0;
      virtual HRESULT STDMETHODCALLTYPE Clone(IEnumIDENTITY_ATTRIBUTE**) = 0;
      virtual HRESULT STDMETHODCALLTYPE CurrentSize(PSIZE_T) = 0;
};

MIDL_INTERFACE("587bf538-4d90-4a3c-9ef1-58a200a8a9e7")
IDefinitionIdentity : public IUnknown
{
public:
      virtual HRESULT STDMETHODCALLTYPE GetAttribute(LPCWSTR, LPCWSTR, LPWSTR) = 0;
      virtual HRESULT STDMETHODCALLTYPE SetAttribute(LPCWSTR, LPCWSTR, LPCWSTR) = 0;
      virtual HRESULT STDMETHODCALLTYPE EnumAttributes(IEnumIDENTITY_ATTRIBUTE**) = 0;
      virtual HRESULT STDMETHODCALLTYPE Clone(SIZE_T, const IDENTITY_ATTRIBUTE*, IDefinitionIdentity**) = 0;
};

typedef struct _CSI_BROKEN_COMPONENT
{
    DWORD dwFlags;
    IDefinitionIdentity* pIDefinitionIdentity;
    PVOID pvReserved;
} CSI_BROKEN_COMPONENT;

typedef struct _CSI_REPAIRED_COMPONENT
{
    DWORD dwFlags;
    IDefinitionIdentity* pIDefinitionIdentity;
    PVOID pvReserved;

} CSI_REPAIRED_COMPONENT;

MIDL_INTERFACE("d91e12d8-98ed-47fa-9936-39421283d59b")
IDefinitionAppId : public IUnknown
{
public:
      virtual HRESULT STDMETHODCALLTYPE get_SubscriptionId(PWSTR*) = 0;
      virtual HRESULT STDMETHODCALLTYPE put_SubscriptionId(LPCWSTR) = 0;
      virtual HRESULT STDMETHODCALLTYPE get_Codebase(PWSTR*) = 0;
      virtual HRESULT STDMETHODCALLTYPE put_Codebase(LPCWSTR) = 0;
      virtual HRESULT STDMETHODCALLTYPE EnumAppPath(IEnumDefinitionIdentity**) = 0;
      virtual HRESULT STDMETHODCALLTYPE SetAppPath(SIZE_T, IDefinitionIdentity**) = 0;
};
MIDL_INTERFACE("f3549d9c-fc73-4793-9c00-1cd204254c0c")
IEnumDefinitionIdentity : public IUnknown
{
public:
      virtual HRESULT STDMETHODCALLTYPE Next(SIZE_T, IDefinitionIdentity**, PSIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE Skip(SIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE Reset() = 0;
      virtual HRESULT STDMETHODCALLTYPE Clone(IEnumDefinitionIdentity**) = 0;
};
MIDL_INTERFACE("054f0bef-9e45-4363-8f5a-2f8e142d9a3b")
IReferenceAppId : public IUnknown
{
public:
      virtual HRESULT STDMETHODCALLTYPE get_SubscriptionId(PWSTR*) = 0;
      virtual HRESULT STDMETHODCALLTYPE put_SubscriptionId(LPCWSTR) = 0;
      virtual HRESULT STDMETHODCALLTYPE get_Codebase(PWSTR*) = 0;
      virtual HRESULT STDMETHODCALLTYPE put_Codebase(LPCWSTR) = 0;
      virtual HRESULT STDMETHODCALLTYPE EnumAppPath(IEnumReferenceIdentity**) = 0;
};
MIDL_INTERFACE("6eaf5ace-7917-4f3c-b129-e046a9704766")
IReferenceIdentity : public IUnknown
{
public:
      virtual HRESULT STDMETHODCALLTYPE GetAttribute(LPCWSTR, LPCWSTR, PWSTR*) = 0;
      virtual HRESULT STDMETHODCALLTYPE SetAttribute(LPCWSTR, LPCWSTR, LPCWSTR) = 0;
      virtual HRESULT STDMETHODCALLTYPE EnumAttributes(IEnumIDENTITY_ATTRIBUTE**) = 0;
      virtual HRESULT STDMETHODCALLTYPE Clone(SIZE_T, const _IDENTITY_ATTRIBUTE*, IReferenceIdentity**) = 0;
};

MIDL_INTERFACE("b30352cf-23da-4577-9b3f-b4e6573be53b")
IEnumReferenceIdentity : public IUnknown
{
public:
      virtual HRESULT STDMETHODCALLTYPE Next(SIZE_T, IReferenceIdentity**, PSIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE Skip(SIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE Reset() = 0;
      virtual HRESULT STDMETHODCALLTYPE Clone(IEnumReferenceIdentity**) = 0;
};

MIDL_INTERFACE("261a6983-c35d-4d0d-aa5b-7867259e77bc")
IAppIdAuthority : public IUnknown
{
public:
      virtual HRESULT STDMETHODCALLTYPE TextToDefinition(DWORD, LPCWSTR, IDefinitionAppId**) = 0;
      virtual HRESULT STDMETHODCALLTYPE TextToReference(DWORD, LPCWSTR, IReferenceAppId**) = 0;
      virtual HRESULT STDMETHODCALLTYPE DefinitionToText(DWORD, IDefinitionAppId*, PWSTR*) = 0;
      virtual HRESULT STDMETHODCALLTYPE ReferenceToText(DWORD, IReferenceAppId*, PWSTR*) = 0;
      virtual HRESULT STDMETHODCALLTYPE AreDefinitionsEqual(DWORD, IDefinitionAppId*, IDefinitionAppId*, PINT) = 0;
      virtual HRESULT STDMETHODCALLTYPE AreReferencesEqual(DWORD, IReferenceAppId*, IReferenceAppId*, PINT) = 0;
      virtual HRESULT STDMETHODCALLTYPE AreTextualDefinitionsEqual(DWORD, LPCWSTR, LPCWSTR, PINT) = 0;
      virtual HRESULT STDMETHODCALLTYPE AreTextualReferencesEqual(DWORD, LPCWSTR, LPCWSTR, PINT) = 0;
      virtual HRESULT STDMETHODCALLTYPE DoesDefinitionMatchReference(DWORD, IDefinitionAppId*, IReferenceAppId*, PINT) = 0;
      virtual HRESULT STDMETHODCALLTYPE DoesTextualDefinitionMatchTextualReference(DWORD, LPCWSTR, LPCWSTR, PINT) = 0;
      virtual HRESULT STDMETHODCALLTYPE HashReference(DWORD, IReferenceAppId*, PSIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE HashDefinition(DWORD, IDefinitionAppId*, PSIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE GenerateDefinitionKey(DWORD, IDefinitionAppId*, PWSTR*) = 0;
      virtual HRESULT STDMETHODCALLTYPE GenerateReferenceKey(DWORD, IReferenceAppId*, PWSTR*) = 0;
      virtual HRESULT STDMETHODCALLTYPE CreateDefinition(IDefinitionAppId**) = 0;
      virtual HRESULT STDMETHODCALLTYPE CreateReference(IReferenceAppId**) = 0;
};

MIDL_INTERFACE("261a6983-c35d-4d0d-aa5b-7867259e77bc")
IIdentityAuthority : public IUnknown
{
public:
      virtual HRESULT STDMETHODCALLTYPE TextToDefinition(DWORD, LPCWSTR, IDefinitionIdentity**) = 0;
      virtual HRESULT STDMETHODCALLTYPE TextToReference(DWORD, LPCWSTR, IReferenceIdentity**) = 0;
      virtual HRESULT STDMETHODCALLTYPE DefinitionToText(DWORD, IDefinitionIdentity*, PWSTR*) = 0;
      virtual HRESULT STDMETHODCALLTYPE DefinitionToTextBuffer(DWORD, IDefinitionIdentity*, SIZE_T, PWSTR, PSIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE ReferenceToText(DWORD, IReferenceIdentity*, PWSTR*) = 0;
      virtual HRESULT STDMETHODCALLTYPE ReferenceToTextBuffer(DWORD, IReferenceIdentity*, SIZE_T, PWSTR, PSIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE AreDefinitionsEqual(DWORD, IDefinitionIdentity*, IDefinitionIdentity*, PINT) = 0;
      virtual HRESULT STDMETHODCALLTYPE AreReferencesEqual(DWORD, IReferenceIdentity*, IReferenceIdentity*, PINT) = 0;
      virtual HRESULT STDMETHODCALLTYPE AreTextualDefinitionsEqual(DWORD, LPCWSTR, LPCWSTR, PINT) = 0;
      virtual HRESULT STDMETHODCALLTYPE AreTextualReferencesEqual(DWORD, LPCWSTR, LPCWSTR, PINT) = 0;
      virtual HRESULT STDMETHODCALLTYPE DoesDefinitionMatchReference(DWORD, IDefinitionIdentity*, IReferenceIdentity*, PINT) = 0;
      virtual HRESULT STDMETHODCALLTYPE DoesTextualDefinitionMatchTextualReference(DWORD, LPCWSTR, LPCWSTR, PINT) = 0;
      virtual HRESULT STDMETHODCALLTYPE HashReference(DWORD, IReferenceIdentity*, PSIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE HashDefinition(DWORD, IDefinitionIdentity*, PSIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE GenerateDefinitionKey(DWORD, IDefinitionIdentity*, PWSTR*) = 0;
      virtual HRESULT STDMETHODCALLTYPE GenerateReferenceKey(DWORD, IReferenceIdentity*, PWSTR*) = 0;
      virtual HRESULT STDMETHODCALLTYPE CreateDefinition(IDefinitionIdentity**) = 0;
      virtual HRESULT STDMETHODCALLTYPE CreateReference(IReferenceIdentity**) = 0;
      virtual HRESULT STDMETHODCALLTYPE DefinitionToTextBufferLength(DWORD, IDefinitionIdentity*, PSIZE_T) = 0;
      virtual HRESULT STDMETHODCALLTYPE ReferenceToTextBufferLength(DWORD, IReferenceIdentity*, PSIZE_T) = 0;
};
MIDL_INTERFACE("ace1b703-1aac-4956-ab87-90cac8b93ce6")
IManifestParseErrorCallback : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE OnError(ULONG,ULONG,ULONG, HRESULT, LPCWSTR, SIZE_T, LPCWSTR*) = 0;
};

struct CWcpDll
{
private:
    HINSTANCE m_hDll = 0;
    PVOID m_InitCookie = 0;
public:
    PWCP_SHUTDOWN_FUNCTION m_pWcpShutdown = 0;
    PDISMOUNT_REGISTRY_HIVES_FUNCTION m_pDismountRegistryHives = 0;
    PCREATE_NEW_OFFLINE_STORE_FUNCTION m_pCreateNewOfflineStore = 0;
    PCREATE_NEW_WINDOWS_FUNCTION m_pCreateNewWindows = 0;
    PCREATE_NEW_PSEUDO_WINDOWS_FUNCTION m_pCreateNewPseudoWindows = 0;
    PCREATE_NEW_PSEUDO_WINDOWS_EX_FUNCTION m_pCreateNewPseudoWindowsEx = 0;
    PGET_APPID_AUTHORITY_FUNCTION m_pGetAppIdAuthority = 0;
    PGET_IDENTITY_AUTHORITY_FUNCTION m_pGetIdentityAuthority = 0;
    PGET_SYSTEM_STORE_FUNCTION m_pGetSystemStore = 0;
    POPEN_EXISTING_OFFLINE_STORE_FUNCTION m_pOpenExistingOfflineStore = 0;
    PPARSE_MANIFEST_FUNCTION m_pParseManifest = 0;
    PSET_ISOLATION_MALLOC_FUNCTION m_pSetIsolationIMalloc = 0;
    PWCP_DLL_DEBUG_ENTRYPOINT_FUNCTION m_pRtlWcpDllDebugEntrypoint = 0;
    PFREEANDZERO_CSI_BROKEN_COMPONENT_FUNCTION m_pFreeAndZeroCSI_BROKEN_COMPONENT = 0;
    PINITIALIZE_CSI_BROKEN_COMPONENT_FUNCTION m_pInitializeCSI_BROKEN_COMPONENT = 0;
    PFREEANDZERO_CSI_REPAIRED_COMPONENT_FUNCTION m_pFreeAndZeroCSI_REPAIRED_COMPONENT = 0;
    PINITIALIZE_CSI_REPAIRED_COMPONENT_FUNCTION m_pInitializeCSI_REPAIRED_COMPONENT = 0;
};
