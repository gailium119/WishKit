#pragma once
#include <Windows.h>

// Cbs States
typedef enum _CbsState
{
    CbsStateDefault = 0x1000,
    CbsStateCancel = 0x1005,
    CbsStateAbsent = 0x0,
    CbsStateUninstallPending = 0x5,
    CbsStateResolving = 0x10,
    CbsStateResolved = 0x20,
    CbsStateStaging = 0x30,
    CbsStateStaged = 0x40,
    CbsStateSuperseded = 0x50,
    CbsStateInstallPending = 0x60,
    CbsStatePartiallyInstalled = 0x65,
    CbsStateInstalled = 0x70,
    CbsStatePermanent = 0x80,
    CbsStateInvalidResolved = 0xFFFFFFE0,
    CbsStateInvalidStaged = 0xFFFFFFC0,
    CbsStateInvalidInstalled = 0xFFFFFF90,
    CbsStateInvalidPermanent = 0xFFFFFF80,
    CbsStateDetect = 0x1004,
} CbsState;

//Update Selection
typedef enum _UpdateSelection
{
    SelectionUnknown = 0xFFFFFFFF,
    SelectionOn = 0x1,
    SelectionOff = 0x0,
    SelectionDefault = 0xFF,
    SelectionCancel = 0x3E7,
} UpdateSelection;

//Package Type
typedef enum _CbsPackageType
{
    CbsPackageTypeUnknown = 0xFFFFFFFE,
    CbsPackageTypeExisting = 0xFFFFFFFF,
    CbsPackageTypeCabinet = 0x0,
    CbsPackageTypeExpanded = 0x1,
    CbsPackageTypeManifest = 0x2,
    CbsPackageTypeXmlString = 0x3,
    CbsPackageTypeExpandedWithMum = 0x4,
    CbsPackageTypeIdentity = 0x5,
} CbsPackageType;

//Required Action
typedef enum _CbsRequiredAction
{
    CbsRequiredActionNone = 0x0,
    CbsRequiredActionShutdown = 0x1,
} CbsRequiredAction;

//Session Property
typedef enum _CbsSessionProperty
{
    CbsSessionPropertyMin = 0x0,
    CbsSessionPropertyRebootRequired = 0x1,
    CbsSessionPropertyExtendedError = 0x2,
    CbsSessionPropertyUnserviceable = 0x3,
    CbsSessionPropertyCompressionEnabled = 0x4,
    CbsSessionPropertyReport = 0x5,
    CbsSessionPropertyStoreMarkedCorrupt = 0x6,
    CbsSessionPropertyInRepairOperation = 0x7,
    CbsSessionPropertyWinSxSVolatileSize = 0x8,
    CbsSessionPropertyWinSxSNonVolatileSize = 0x9,
    CbsSessionPropertyWinSxSSharedWithWindowsSize = 0xA,
    CbsSessionPropertyWinSxSAccordingToExplorerSize = 0xB,
    CbsSessionPropertyLastScavengeDateTime = 0xC,
    CbsSessionPropertySupersededPackageCount = 0xD,
    CbsSessionPropertyComponentCleanupRecommended = 0xE,
    CbsSessionPropertyOperationCompletionTime = 0xF,
    CbsSessionPropertyInternalStagingSize = 0x10,
    CbsSessionPropertyInstallSize = 0x11,
    CbsSessionPropertyExternalStagingSize = 0x12,
    CbsSessionPropertyMax = 0x13,
} CbsSessionProperty;

//Session Option
typedef enum _CbsSessionOption
{
    CbsSessionOptionPerUser = 0x1,
    CbsSessionOptionNoShutdown = 0x10,
    CbsSessionOptionNoReboot = 0x20,
    CbsSessionOptionForceReboot = 0x40,
    CbsSessionOptionOpenExistingSession = 0x80,
    CbsSessionOptionRetryOnPendingVictim = 0x100,
    CbsSessionOptionAsynchronousFinalize = 0x200,
    CbsSessionOptionSynchronousScavenge = 0x400,
    CbsSessionOptionCancelAllPendingSession = 0x800,
    CbsSessionOptionEnableCompression = 0x1000,
    CbsSessionOptionDisableCompression = 0x2000,
    CbsSessionOptionDetectStoreCorruption = 0x4000,
    CbsSessionOptionRepairStoreCorruption = 0x8000,
    CbsSessionOptionNoPend = 0x10000,
    CbsSessionOptionUseLocalSourcesOnlyOnMissingPayload = 0x20000,
    CbsSessionOptionUseWindowsUpdateOnMissingPayload = 0x40000,
    CbsSessionOptionRetry = 0x80000,
    CbsSessionOptionReportStackStatus = 0x100000,
    CbsSessionOptionAnticipatePreshutdownNeeded = 0x200000,
    CbsSessionOptionSynchronousCleanup = 0x400000,
    CbsSessionOptionAsynchronousCleanup = 0x800000,
    CbsSessionOptionAllowPartialInstall = 0x1000000,
    CbsSessionOptionDelayExecutionIfPendRequired = 0x2000000,
    CbsSessionOptionUseRestartManager = 0x4000000,
    CbsSessionOptionAnalyzeStore = 0x8000000,
    CbsSessionOptionResetBaseImage = 0x10000000,
    CbsSessionOptionAllowObserver = 0x40000000,
} CbsSessionOption;

//Enhanced Session Option
typedef enum _CbsSessionEnhancedOption
{
    CbsSessionEnhancedOptionPostponeOnlineActions = 0x1,
    CbsSessionEnhancedOptionProcessOnlinePendingActions = 0x2,
    CbsSessionEnhancedOptionDisableKTM = 0x4,
    CbsSessionEnhancedOptionHardlinkAlternativeStoreFiles = 0x8,
    CbsSessionEnhancedOptionPlatformNoPnPSupport = 0x10,
    CbsSessionEnhancedOptionMobileResetWindows = 0x20,
    CbsSessionEnhancedOptionIgnoreCatalogs = 0x40,
    CbsSessionEnhancedOptionMobileStore = 0x80,
    CbsSessionEnhancedOptionPrestagingCleanup = 0x100,
    CbsSessionEnhancedOptionUseDeconstructedDrivers = 0x200,
    CbsSessionEnhancedOptionSkipScavenge = 0x400,
    CbsSessionEnhancedOptionDetectFullStoreCorruption = 0x800,
    CbsSessionEnhancedOptionRepairFullStoreCorruption = 0x1000,
    CbsSessionEnhancedOptionPackageEnumerationOnly = 0x2000,
    CbsSessionEnhancedOptionIdempotentStaging = 0x4000,
    CbsSessionEnhancedOptionInstallFromIdempotentStaging = 0x8000,
} CbsSessionEnhancedOption;

//Session State
typedef enum _CbsSessionState
{
    CbsSessionStateUnknown = 0x0,
    CbsSessionStateReady = 0x10,
    CbsSessionStateQueued = 0x20,
    CbsSessionStateStart = 0x30,
    CbsSessionStatePlanned = 0x40,
    CbsSessionStateResolved = 0x50,
    CbsSessionStateStaged = 0x60,
    CbsSessionStateDelayedToSystemShutdown = 0x65,
    CbsSessionStateInstalled = 0x70,
    CbsSessionStatePended = 0x80,
    CbsSessionStateShutDownStart = 0x90,
    CbsSessionStateShutDownFinish = 0xA0,
    CbsSessionStateStartup = 0xB0,
    CbsSessionStateStartupFinish = 0xC0,
    CbsSessionStateComplete = 0xD0,
    CbsSessionStateInterrupted = 0xE0,
    CbsSessionStateCancelled = 0xE8,
    CbsSessionStateCorrupted = 0xF0,
    CbsSessionStateMarkedForRetry = 0x100,
} CbsSessionState;

//Operation Type
typedef enum _CbsOperationType
{
    CbsOperationDefault = 0x0,
    CbsOperationFeatureOnDemand = 0x1,
    CbsOperationAutomaticCorruptionRepair = 0x2,
} CbsOperationType;

typedef enum _CbsApplicability
{
    CbsApplicabilityNotApplicable = 0x1,
    CbsApplicabilityNeedsParent = 0x2,
    CbsApplicabilityApplicable = 0x4,
    CbsApplicabilityApplicableAll = 0x7,
} CbsApplicability;

typedef enum _CbsSelectability
{
    CbsSelectabilityNone = 0x1,
    CbsSelectabilityOnOff = 0x2,
    CbsSelectabilityAccept = 0x4,
    CbsSelectabilityPrompt = 0x8,
    CbsSelectabilityConfig = 0x10,
    CbsSelectabilityAll = 0x1F,
} CbsSelectability;
typedef enum _CbsInstallState
{
    CbsInstallStateDefault = 0xFFFFFFF0,
    CbsInstallStateSuperseded = 0xFFFFFFEF,
    CbsInstallStateCancel = 0xFFFFFFEE,
    CbsInstallStatePartiallyInstalled = 0xFFFFFFED,
    CbsInstallStateAbsent = 0x0,
    CbsInstallStateResolving = 0x1,
    CbsInstallStateResolved = 0x2,
    CbsInstallStateStaging = 0x3,
    CbsInstallStateStaged = 0x4,
    CbsInstallStateUninstallRequested = 0x5,
    CbsInstallStateInstallRequested = 0x6,
    CbsInstallStateInstalled = 0x7,
    CbsInstallStatePermanent = 0x8,
    CbsInvalidStateResolved = 0xFFFFFFFE,
    CbsInvalidStateStaged = 0xFFFFFFFC,
    CbsInvalidStateInstalled = 0xFFFFFFF9,
    CbsInvalidStatePermanent = 0xFFFFFFF8,
} CbsInstallState;

typedef enum _CbsPackageProperty
{
    CbsPackagePropertyMin = 0x0,
    CbsPackagePropertyIdentityString = 0x1,
    CbsPackagePropertyDisplayName = 0x2,
    CbsPackagePropertyDescription = 0x3,
    CbsPackagePropertyRestart = 0x4,
    CbsPackagePropertyPsfName = 0x5,
    CbsPackagePropertyHidden = 0x6,
    CbsPackagePropertyKeyword = 0x7,
    CbsPackagePropertyReleaseType = 0x8,
    CbsPackagePropertyProductName = 0x9,
    CbsPackagePropertyProductVersion = 0xA,
    CbsPackagePropertyPermanence = 0xB,
    CbsPackagePropertyCompany = 0xC,
    CbsPackagePropertyCopyright = 0xD,
    CbsPackagePropertySupportInformation = 0xE,
    CbsPackagePropertyCreationTimeStamp = 0xF,
    CbsPackagePropertyLastUpdateTimeStamp = 0x10,
    CbsPackagePropertyInstallTimeStamp = 0x11,
    CbsPackagePropertyInstallPackageName = 0x12,
    CbsPackagePropertyInstallLocation = 0x13,
    CbsPackagePropertyInstallClient = 0x14,
    CbsPackagePropertyInstallUserName = 0x15,
    CbsPackagePropertyExtendedError = 0x16,
    CbsPackagePropertyPended = 0x17,
    CbsPackagePropertyHotpatch = 0x18,
    CbsPackagePropertyExclusive = 0x19,
    CbsPackagePropertyAllowedOffline = 0x1A,
    CbsPackagePropertyCompletelyOfflineCapable = 0x1B,
    CbsPackagePropertyScavengeSequence = 0x1C,
    CbsPackagePropertyPackageSize = 0x1D,
    CbsPackagePropertySupersededTime = 0x1E,
    CbsPackagePropertyStackUpdate = 0x1F,
    CbsPackagePropertyReleaseQuality = 0x20,
    CbsPackagePropertyTargetPartition = 0x21,
    CbsPackagePropertyBinaryPartition = 0x22,
    CbsPackagePropertyCapabilityIdentity = 0x23,
    CbsPackagePropertyInternalStagingSizeWithExternalStorage = 0x24,
    CbsPackagePropertyInternalStagingSizeWithoutExternalStorage = 0x25,
    CbsPackagePropertyInstallSizeWithExternalStorage = 0x26,
    CbsPackagePropertyInstallSizeWithoutExternalStorage = 0x27,
    CbsPackagePropertyExternalStagingSize = 0x28,
    CbsPackagePropertyFeatureFMID = 0x29,
    CbsPackagePropertyFeatureGroup = 0x2A,
    CbsPackagePropertyPermanentUntilReset = 0x2B,
    CbsPackagePropertyMax = 0x2C,
} CbsPackageProperty;
typedef enum _CbsResourceType
{
    CbsResourceTypeFile = 0x1,
    CbsResourceTypeService = 0x2,
    CbsResourceTypeProcess = 0x3,
} CbsResourceType;
typedef enum _CbsCardinality
{
    CbsCardinalityNone = 0x0,
    CbsCardinalityOne = 0x1,
    CbsCardinalitySome = 0x2,
    CbsCardinalityAny = 0x3,
} CbsCardinality;
typedef enum _CbsUpdateProperty
{
    CbsUpdatePropertyName = 0x1,
    CbsUpdatePropertyDisplayName = 0x2,
    CbsUpdatePropertyDescription = 0x3,
    CbsUpdatePropertyDisplayFile = 0x4,
    CbsUpdatePropertyRestart = 0x5,
    CbsUpdatePropertyPsfName = 0x6,
    CbsUpdatePropertyDownloadSize = 0x7,
    CbsUpdatePropertySetMembership = 0x8,
} CbsUpdateProperty;
typedef enum _CbsOperationStage
{
    CbsOperationStageWaiting = 0x1,
    CbsOperationStageDownloading = 0x5,
    CbsOperationStageExtraction = 0x9,
    CbsOperationStagePlanning = 0xA,
    CbsOperationStageResolving = 0x14,
    CbsOperationStageStaging = 0x1E,
    CbsOperationStageInstalling = 0x32,
} CbsOperationStage;

typedef enum _CbsOnDemandSourceEnum
{
    CbsOnDemandSourcePackageStore = 0x1,
    CbsOnDemandSourceLocalSource = 0x2,
    CbsOnDemandSourceCloud = 0x4,
} CbsOnDemandSourceEnum;

typedef enum tagCBS_PACKAGE_ENCRYPTION_ENUM
{
    CBS_PACKAGE_ENCRYPTION_NONE = 0x0,
    CBS_PACKAGE_ENCRYPTION_PER_FILE = 0x1,
    CBS_PACKAGE_ENCRYPTION_MAX_ENUM = 0x2,
} CBS_PACKAGE_ENCRYPTION_ENUM;



typedef struct tagCbsPackageDecryptionData
{
    UINT cbDecryptionData;
    PBYTE pDecryptionData;
} CbsPackageDecryptionData;

typedef enum tagLOG_SETUPLOG_SEVERITY
{
    LOG_ASSERT = 0x0,
    LOG_FATAL_ERROR = 0x1000000,
    LOG_ERROR = 0x2000000,
    LOG_WARNING = 0x3000000,
    LOG_INFO = 0x4000000,
    LOG_STATUS = 0x5000000,
    LOG_ALWAYS = 0x9000000,
    DBG_ASSERT = 0x65000000,
    DBG_INFO = 0x67000000,
    DBG_VERBOSE = 0x68000000,
    DBG_WARNING = 0x6A000000,
    DBG_ERROR = 0x6B000000,
    DBG_TRACE = 0x70000000,
} LOG_SETUPLOG_SEVERITY;

typedef enum _CbsActivityType
{
    CbsActivityPackage = 0x1,
    CbsActivityUpdate = 0x2,
    CbsActivityCapability = 0x3,
} CbsActivityType;

typedef struct _CbsActivity
{
    PWSTR objectName;
    CbsActivityType objectType;
    CbsInstallState targetState;
    PWSTR displayName;
    PWSTR description;
} CbsActivity;

//WDS funcarea macros
#define WDS_FUNCAREA_DPX 0x10000
#define WDS_FUNCAREA_CSI 0x18000
#define WDS_FUNCAREA_CBS 0x20000
#define WDS_FUNCAREA_SXS 0x28000
#define WDS_FUNCAREA_CMI 0x30000
#define WDS_FUNCAREA_DEPLOY 0x40000
#define WDS_FUNCAREA_DU 0x50000
#define WDS_FUNCAREA_IBS 0x60000
#define WDS_FUNCAREA_IBSLIB 0x64000
#define WDS_FUNCAREA_DIAG 0x70000
#define WDS_FUNCAREA_DIAGER 0x74000
#define WDS_FUNCAREA_MIG 0x80000
#define WDS_FUNCAREA_HWARE 0x84000
#define WDS_FUNCAREA_MIGUI 0x88000
#define WDS_FUNCAREA_UI 0xA0000
#define WDS_FUNCAREA_CONX 0xA4000
#define WDS_FUNCAREA_MOUPG 0xA8000
#define WDS_FUNCAREA_WDS 0xB0000
#define WDS_FUNCAREA_DISM 0xB8000
#define WDS_FUNCAREA_PANTHR 0x90000
#define WDS_FUNCAREA_WINPE 0xC0000
#define WDS_FUNCAREA_SP 0xC8000
#define WDS_FUNCAREA_LIB 0xD0000
#define WDS_FUNCAREA_TOOL 0xE0000
#define WDS_FUNCAREA_SYSPRP 0xF0000

MIDL_INTERFACE("75207391-23F2-4396-85F0-8FDB879ED0ED")
ICbsSession : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE Initialize(UINT, LPCWSTR, LPCWSTR, LPCWSTR) = 0;
    virtual HRESULT STDMETHODCALLTYPE Finalize(CbsRequiredAction*) = 0;
    virtual HRESULT STDMETHODCALLTYPE CreatePackage(UINT, CbsPackageType, LPCWSTR, LPCWSTR, IUnknown**) = 0;
    virtual HRESULT STDMETHODCALLTYPE OpenPackage(UINT, struct ICbsIdentity*, LPCWSTR, IUnknown**) = 0;
    virtual HRESULT STDMETHODCALLTYPE EnumeratePackages(UINT, struct IEnumCbsIdentity**) = 0;
    virtual HRESULT STDMETHODCALLTYPE CreateCbsIdentity(struct ICbsIdentity**) = 0;
};
MIDL_INTERFACE("75207392-23F2-4396-85F0-8FDB879ED0ED")
ICbsUIHandler : public IUnknown
{
public:
  virtual HRESULT STDMETHODCALLTYPE Initiate(struct IEnumCbsUpdate*, PINT) = 0;
  virtual HRESULT STDMETHODCALLTYPE Terminate() = 0;
  virtual HRESULT STDMETHODCALLTYPE Error(HRESULT, PCWSTR, PINT) = 0;
  virtual HRESULT STDMETHODCALLTYPE ResolveSource(PCWSTR, struct ICbsIdentity*, PCWSTR, PWSTR*, PINT) = 0;
  virtual HRESULT STDMETHODCALLTYPE Progress(CbsInstallState stIns, UINT curProg, UINT totProg, PINT) = 0;
  virtual HRESULT STDMETHODCALLTYPE EnteringStage(UINT, CbsOperationStage, INT, INT) = 0;
  virtual HRESULT STDMETHODCALLTYPE ProgressEx(CbsInstallState stIns, UINT curProg, UINT totProg, UINT, PINT) = 0;
};
MIDL_INTERFACE("75207393-23F2-4396-85F0-8FDB879ED0ED")
ICbsPackage : public IUnknown
{
public:
  virtual HRESULT STDMETHODCALLTYPE GetIdentity(struct ICbsIdentity**) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetProperty(CbsPackageProperty, PWSTR*) = 0;
  virtual HRESULT STDMETHODCALLTYPE EnumerateUpdates(CbsApplicability, CbsSelectability, struct IEnumCbsUpdate**) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetUpdate(LPCWSTR, struct ICbsUpdate**) = 0;
  virtual HRESULT STDMETHODCALLTYPE AddSource(LPCWSTR) = 0;
  virtual HRESULT STDMETHODCALLTYPE RemoveSource(LPCWSTR) = 0;
  virtual HRESULT STDMETHODCALLTYPE EnumerateSources(IEnumString**) = 0;
  virtual HRESULT STDMETHODCALLTYPE EvaluateApplicability(UINT, CbsInstallState*, CbsInstallState*) = 0;
  virtual HRESULT STDMETHODCALLTYPE InitiateChanges(UINT, CbsInstallState, IUnknown*) = 0;
  virtual HRESULT STDMETHODCALLTYPE Status(CbsInstallState*, HRESULT*) = 0;
  virtual HRESULT STDMETHODCALLTYPE ResourcesToCheck(CbsResourceType, IEnumString**) = 0;

};
MIDL_INTERFACE("75207394-23F2-4396-85F0-8FDB879ED0ED")
ICbsUpdate : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE GetProperty(CbsUpdateProperty, PWSTR*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetPackage(ICbsPackage**) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetParentUpdate(UINT, PWSTR*, PWSTR*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetCapability(CbsApplicability*, CbsSelectability*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDeclaredSet(UINT, PWSTR*, CbsCardinality*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetInstallState(CbsInstallState*, CbsInstallState*, CbsInstallState*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetInstallState(UINT, CbsInstallState) = 0;
};

MIDL_INTERFACE("75207395-23F2-4396-85F0-8FDB879ED0ED")
IEnumCbsUpdate : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Next(UINT, ICbsUpdate**, PUINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE Skip(UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE Reset() = 0;
    virtual HRESULT STDMETHODCALLTYPE Clone(IEnumCbsUpdate**) = 0;
};
MIDL_INTERFACE("75207396-23F2-4396-85F0-8FDB879ED0ED")
ICbsIdentity : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE Clear() = 0;
    virtual HRESULT STDMETHODCALLTYPE IsNull(PINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE IsEqual() = 0;
    virtual HRESULT STDMETHODCALLTYPE LoadFromAttributes(LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR) = 0;
    virtual HRESULT STDMETHODCALLTYPE LoadFromStringId(LPCWSTR) = 0;
    virtual HRESULT STDMETHODCALLTYPE SaveAsStringId(PWSTR*) = 0;
};
MIDL_INTERFACE("75207397-23F2-4396-85F0-8FDB879ED0ED")
IEnumCbsIdentity : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Next(UINT, ICbsIdentity**, PUINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE Skip(UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE Reset() = 0;
    virtual HRESULT STDMETHODCALLTYPE Clone(IEnumCbsIdentity**) = 0;
};

MIDL_INTERFACE("a454308d-1fc4-48e4-b6c0-2a9580804686")
IEnumCbsActivity : public IUnknown{
public:
    virtual HRESULT STDMETHODCALLTYPE Next(UINT, CbsActivity**, PUINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE Skip(UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE Reset() = 0;
    virtual HRESULT STDMETHODCALLTYPE Clone(IEnumCbsActivity**) = 0;

};

MIDL_INTERFACE("6943a742-8ae2-4eb1-8a07-747c5cfd3b9e")
IEnumCbsSession : public IUnknown{
public:
    virtual HRESULT STDMETHODCALLTYPE Next(UINT, struct ICbsSession9**, PUINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE Skip(UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE Reset() = 0;
    virtual HRESULT STDMETHODCALLTYPE Clone(IEnumCbsSession**) = 0;

};
MIDL_INTERFACE("b531e34e-a150-4b01-8d77-858e2f6cfe75")
ICbsFeaturePackage : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE GetProperty(CbsPackageProperty, PWSTR*) = 0;
};

MIDL_INTERFACE("d2f9f360-5bc7-4b1e-aad5-dd151733c7c8")
IEnumCbsFeaturePackage : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE Next(UINT, ICbsFeaturePackage**, PUINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE Skip(UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE Reset() = 0;
    virtual HRESULT STDMETHODCALLTYPE Clone(IEnumCbsFeaturePackage**) = 0;

};
MIDL_INTERFACE("96DB6347-01BB-42D8-B4A0-3D2EBA26FA56")
ICbsCapability : public ICbsPackage
{
public:
    virtual HRESULT STDMETHODCALLTYPE GetCapability(PWSTR*, PWSTR*, PWSTR*, PULONG, PULONG) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDependencies(struct IEnumCbsCapability**) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetSources(PUINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDownloadSize(PULONG) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetInstallSize(PULONG) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetInstallState(CbsInstallState*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetOwnerInformation(UINT, PINT, PUINT, PWSTR*) = 0;
};
MIDL_INTERFACE("9eeae39f-e52b-4f18-9c14-f827bb3baf0f")
ICbsCapability2 : public ICbsCapability
{
    virtual HRESULT STDMETHODCALLTYPE EnumerateFeaturePackages(IEnumCbsFeaturePackage**) = 0;
};
MIDL_INTERFACE("25F05277-E733-4455-80B7-FA9C2DC9E678")
IEnumCbsCapability : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE Next(UINT, ICbsCapability**, PUINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE Skip(UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE Reset() = 0;
    virtual HRESULT STDMETHODCALLTYPE Clone(IEnumCbsCapability**) = 0;

};
MIDL_INTERFACE("E3AFD5FD-3B03-453D-91CE-EBBDA9B8BEA1")
ICbsSessionObserverListener : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE NotifySessionChange(struct ICbsSession9*, CbsSessionState) = 0;
};

MIDL_INTERFACE("1C8ADB85-982E-47F9-999F-B0C3BF9D0449")
ICSIExternalTransformerExecutor : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Initialize(ULONG, UINT64, LPCWSTR, LPCWSTR, LPCWSTR) = 0;
    virtual HRESULT STDMETHODCALLTYPE Install(LPCWSTR, LPCWSTR) = 0;
    virtual HRESULT STDMETHODCALLTYPE Uninstall(LPCWSTR, LPCWSTR) = 0;
    virtual HRESULT STDMETHODCALLTYPE Commit(LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR) = 0;
};

MIDL_INTERFACE("DC95A094-EE0E-4974-9600-027D2321C2D4")
ICbsSession7 : public ICbsSession
{
public:
  virtual HRESULT STDMETHODCALLTYPE GetStatus(PUINT, CbsSessionState*, PINT, HRESULT*) = 0;
  virtual HRESULT STDMETHODCALLTYPE Resume(ICbsUIHandler*) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetSessionId(PWSTR*) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetProperty(CbsSessionProperty, PWSTR*) = 0;
  virtual HRESULT STDMETHODCALLTYPE AddPhaseBreak() = 0;
  virtual HRESULT STDMETHODCALLTYPE FinalizeEx(UINT, CbsRequiredAction*) = 0;

};

MIDL_INTERFACE("F568C899-AF4F-4EAA-B12A-B8E5F1B219DE")
ICbsSession8 : public ICbsSession7
{
public:
  virtual HRESULT STDMETHODCALLTYPE AddSource(UINT, LPCWSTR) = 0;
  virtual HRESULT STDMETHODCALLTYPE RegisterCbsUIHandler(ICbsUIHandler*) = 0;
};

MIDL_INTERFACE("9C7E3CF3-4C97-4D36-BDEB-E3093C228C22")
ICbsSession9 : public ICbsSession8
{
public:
  virtual HRESULT STDMETHODCALLTYPE CreateWindowsUpdatePackage(UINT, LPCWSTR, GUID, UINT, CbsPackageType, LPCWSTR, LPCWSTR, UINT, CbsPackageDecryptionData*, CBS_PACKAGE_ENCRYPTION_ENUM, IUnknown**) = 0;
  virtual HRESULT STDMETHODCALLTYPE EnumerateCapabilities(UINT, LPCWSTR, LPCWSTR, LPCWSTR, UINT, UINT, IEnumCbsCapability**) = 0;
  virtual HRESULT STDMETHODCALLTYPE InitializeEx(UINT, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR) = 0;
  virtual HRESULT STDMETHODCALLTYPE CreateExternalTransformerExecutor(ICSIExternalTransformerExecutor**) = 0;
  virtual HRESULT STDMETHODCALLTYPE ObserveSessions(UINT, ICbsSessionObserverListener*, IEnumCbsSession**) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetActivities(UINT, IEnumCbsActivity**) = 0;
  virtual HRESULT STDMETHODCALLTYPE SetEnhancedOptions(UINT) = 0;
};

MIDL_INTERFACE("F568C899-AF4F-4EAA-B12A-B8E5F1B219DE")
ICbsPrivateSession : public ICbsSession9
{
public:
  virtual PVOID STDMETHODCALLTYPE SetClientToken(PVOID) = 0;
};

MIDL_INTERFACE("fc2c7e52-df06-445e-8d83-ba125880ea0d")
ICbsPublicSession : public ICbsPrivateSession
{
public:
    virtual STDMETHODCALLTYPE ~ICbsPublicSession() = 0;
    virtual PVOID STDMETHODCALLTYPE InternalAddRef() = 0;
    virtual PVOID STDMETHODCALLTYPE InternalRelease() = 0;
    virtual HRESULT STDMETHODCALLTYPE ExtendedQueryInterface(REFIID, PVOID*) = 0;
};
