typedef struct CMcpxCore::AllocateApuMemory::__l2::__unnamed
{
   unsigned long Size;
   unsigned long Alignment;
} CMcpxCore::AllocateApuMemory::__l2::__unnamed;

typedef struct CMcpxAPU::RemoveIdleVoice::__l2::__unnamed
{
   unsigned long TVL;
   unsigned long CVL;
   unsigned long NVL;
} CMcpxAPU::RemoveIdleVoice::__l2::__unnamed;

typedef struct CSensaura3d
{
   union {
   void * m_pfnGetFilterPair;
   (type???) GetHRTFFilterPair;
   (type???) GetFullHRTFFilterPair;
   (type???) GetLiteHRTFFilterPair;
   };
} CSensaura3d;

typedef struct CAutoFpState
{
   union {
   class CFpState m_fps;
   (type???) public: __thiscall CAutoFpState::CAutoFpState(void);
   (type???) public: __thiscall CAutoFpState::~CAutoFpState(void);
   (type???) __vecDelDtor;
   };
} CAutoFpState;

typedef struct MCP1_PRD
{
   unsigned long uAddr;
   MCP1_PRD::__unnamed Control;
} MCP1_PRD;

typedef union MCP1_PRD::__unnamed
{
   union {
   unsigned long Length;
   unsigned long ContSize;
   unsigned long Samples;
   unsigned long Stereo;
   unsigned long Owner;
   unsigned long Intr;
   unsigned long uValue;
   };
} MCP1_PRD::__unnamed;

typedef struct CList<_SGEHEAPRUNMARKER>
{
   union {
   (type???) operator new;
   (type???) operator new[];
   (type???) operator delete;
   (type???) operator delete[];
   _SGEHEAPRUNMARKER * m_pHead;
   };
   _SGEHEAPRUNMARKER * m_pTail;
   union {
   (type???) public: __thiscall CMcpxDspImage::CMcpxDspImage(void);
   (type???) public: void __thiscall CList<struct _SGEHEAPRUNMARKER>::AddNode(struct _SGEHEAPRUNMARKER *);
   (type???) public: void __thiscall CList<struct _SGEHEAPRUNMARKER>::InsertNode(struct _SGEHEAPRUNMARKER *,struct _SGEHEAPRUNMARKER *);
   (type???) public: void __thiscall CList<struct _SGEHEAPRUNMARKER>::RemoveNode(struct _SGEHEAPRUNMARKER *);
   (type???) Reset;
   (type???) public: void * __thiscall CMcpxDspImage::GetLoader(void);
   (type???) GetListTail;
   };
} CList<_SGEHEAPRUNMARKER>;

typedef struct CHeap<_SGEHEAPRUNMARKER>
{
   union {
   (type???) ;
   (type???) operator new;
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   unsigned long Padding5;
   };
   class CList<_SGEHEAPRUNMARKER> m_lstFree;
   class CList<_SGEHEAPRUNMARKER> m_lstAllocated;
   short m_wFreeElementCount;
   unsigned char Padding9;
   unsigned char Padding10;
   class CList<_SGEHEAPRUNMARKER> m_lstMarkers;
   _SGEHEAPRUNMARKER * m_paMarkers;
   union {
   (type???) CHeap<_SGEHEAPRUNMARKER>;
   (type???) public: __thiscall CHeap<struct _SGEHEAPRUNMARKER>::CHeap<struct _SGEHEAPRUNMARKER>(void);
   (type???) public: virtual __thiscall CHeap<struct _SGEHEAPRUNMARKER>::~CHeap<struct _SGEHEAPRUNMARKER>(void);
   (type???) public: virtual long __thiscall CHeap<struct _SGEHEAPRUNMARKER>::Initialize(unsigned short);
   (type???) public: virtual struct _SGEHEAPRUNMARKER * __thiscall CHeap<struct _SGEHEAPRUNMARKER>::Alloc(unsigned short);
   (type???) public: virtual void __thiscall CHeap<struct _SGEHEAPRUNMARKER>::Free(struct _SGEHEAPRUNMARKER *);
   (type???) private: virtual struct _SGEHEAPRUNMARKER * __thiscall CHeap<struct _SGEHEAPRUNMARKER>::CoalesceRuns(struct _SGEHEAPRUNMARKER *,struct _SGEHEAPRUNMARKER *);
   (type???) __local_vftable_ctor_closure;
   (type???) __vecDelDtor;
   };
} CHeap<_SGEHEAPRUNMARKER>;

typedef union R_FE_CONTROL
{
   union {
   unsigned long NotifyISO;
   unsigned long ReadISO;
   unsigned long WriteISO;
   unsigned long TrapOnNotifier;
   unsigned long Lock;
   unsigned long Mode;
   unsigned long TrapReason;
   unsigned long PIOClass;
   unsigned long EnableLock;
   unsigned long MethodOrigin;
   unsigned long ValidSESSL;
   unsigned long ValidSESGE;
   unsigned long ValidGPSGE;
   unsigned long uValue;
   };
} R_FE_CONTROL;

typedef struct CFpState
{
   union {
   unsigned long m_dwRefCount;
   _KFLOATING_SAVE m_fps;
   (type???) public: void __thiscall CFpState::Save(void);
   (type???) public: void __thiscall CFpState::Restore(void);
   };
} CFpState;

typedef struct CAutoIrql
{
   union {
   class CIrql m_irql;
   (type???) public: __thiscall CAutoIrql::CAutoIrql(void);
   (type???) public: __thiscall CAutoIrql::~CAutoIrql(void);
   (type???) __vecDelDtor;
   };
} CAutoIrql;

typedef struct CDirectSoundStream
{
   union {
   (type???) IDirectSoundStream;
   unsigned long Padding1;
   };
   (type???) CDirectSoundVoice;
   union {
   (type???) operator new;
   (type???) operator new[];
   (type???) operator delete;
   (type???) operator delete[];
   unsigned long Padding7;
   };
   unsigned long Padding8;
   unsigned long Padding9;
   unsigned long Padding10;
   unsigned long Padding11;
   unsigned long Padding12;
   unsigned long Padding13;
   unsigned long Padding14;
   class CDirectSoundStreamSettings * m_pSettings;
   class CMcpxStream * m_pStream;
   union {
   (type???) CDirectSoundStream;
   (type???) CDirectSoundStream;
   (type???) ~CDirectSoundStream;
   (type???) Initialize;
   (type???) AddRef;
   (type???) Release;
   (type???) GetInfo;
   (type???) GetStatus;
   (type???) Process;
   (type???) Discontinuity;
   (type???) Flush;
   (type???) SetFrequency;
   (type???) SetPitch;
   (type???) SetVolume;
   (type???) Pause;
   (type???) SetLFO;
   (type???) SetEG;
   (type???) SetFilter;
   (type???) SetHeadroom;
   (type???) SetOutputBuffer;
   (type???) SetMixBins;
   (type???) SetMixBinVolumes;
   (type???) SetAllParameters;
   (type???) SetConeAngles;
   (type???) SetConeOrientation;
   (type???) SetConeOutsideVolume;
   (type???) SetMaxDistance;
   (type???) SetMinDistance;
   (type???) SetMode;
   (type???) SetPosition;
   (type???) SetVelocity;
   (type???) SetI3DL2Source;
   (type???) __vecDelDtor;
   };
} CDirectSoundStream;

typedef union R_SE_CONTROL
{
   union {
   unsigned long ReadISO;
   unsigned long WriteISO;
   unsigned long SampleReadISO;
   unsigned long GSCUpdate;
   unsigned long DeltaWarn;
   unsigned long Retriggered;
   unsigned long DeltaPanic;
   unsigned long uValue;
   };
} R_SE_CONTROL;

typedef struct CMcpxDspScratchQ
{
   union {
   (type???) operator new;
   (type???) operator new[];
   (type???) operator delete;
   (type???) operator delete[];
   (type???) CMcpxDspScratchQ;
   (type???) Start;
   (type???) Stop;
   (type???) Read;
   (type???) Write;
   (type???) GetSize;
   (type???) GetOffset;
   (type???) GetAvailableSlots;
   (type???) Incr;
   unsigned long m_uBaseOffset;
   };
   unsigned long m_uRegOffset;
   _MCPX_DSP_MBOX m_MailBox;
   class CMcpxCore * m_pApu;
   class CMcpxDspScratchDma * m_pScratchDma;
   unsigned long m_uStartFlag;
   unsigned char m_uWrapIndex;
} CMcpxDspScratchQ;

typedef struct _DSFX_CROSSTALK_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[4];
   unsigned long dwOutMixbinPtrs[4];
} DSFX_CROSSTALK_STATE;

typedef union R_GP_CONTROL
{
   union {
   unsigned long Idle;
   unsigned long Stopped;
   unsigned long EnableStop;
   unsigned long IntrNotify;
   unsigned long uValue;
   };
} R_GP_CONTROL;

typedef union _MCPX_DSP_MBOX
{
   union {
   _MCPX_DSP_MBOX::__unnamed Ptr;
   short uVal;
   };
} MCPX_DSP_MBOX;

typedef struct _MCPX_DSP_MBOX::__unnamed
{
   unsigned char write;
   unsigned char read;
} MCPX_DSP_MBOX::__unnamed;

typedef struct MCPX_PACKET_CONTEXT
{
   _LIST_ENTRY leListEntry;
   _XMEDIAPACKET xmpPacket;
   unsigned long dwCompletedSize;
   unsigned long dwStatus;
   __int64 rtTimestamp;
} MCPX_PACKET_CONTEXT;

typedef struct CMcpxStream
{
   union {
   (type???) CMcpxVoiceClient;
   (type???) operator new;
   (type???) operator new[];
   (type???) operator delete;
   (type???) operator delete[];
   unsigned long Padding5;
   };
   unsigned long Padding6;
   unsigned long Padding7;
   unsigned long Padding8;
   unsigned long Padding9;
   unsigned long Padding10;
   unsigned long Padding11;
   unsigned long Padding12;
   unsigned long Padding13;
   unsigned long Padding14;
   unsigned long Padding15;
   unsigned long Padding16;
   unsigned long Padding17;
   unsigned long Padding18;
   unsigned long Padding19;
   unsigned long Padding20;
   unsigned long Padding21;
   unsigned long Padding22;
   unsigned long Padding23;
   unsigned long Padding24;
   unsigned long Padding25;
   unsigned long Padding26;
   unsigned long Padding27;
   unsigned long Padding28;
   unsigned long Padding29;
   unsigned long Padding30;
   unsigned long Padding31;
   unsigned long Padding32;
   unsigned long Padding33;
   unsigned long Padding34;
   unsigned long Padding35;
   unsigned long Padding36;
   unsigned long Padding37;
   unsigned long Padding38;
   unsigned long Padding39;
   unsigned long Padding40;
   unsigned long Padding41;
   unsigned long Padding42;
   unsigned long Padding43;
   unsigned long Padding44;
   unsigned long Padding45;
   unsigned long Padding46;
   unsigned long Padding47;
   unsigned long Padding48;
   unsigned long Padding49;
   unsigned long Padding50;
   unsigned long Padding51;
   unsigned long Padding52;
   unsigned long Padding53;
   unsigned long Padding54;
   unsigned long Padding55;
   unsigned long Padding56;
   unsigned long Padding57;
   unsigned long Padding58;
   unsigned long Padding59;
   unsigned long Padding60;
   unsigned long Padding61;
   unsigned long Padding62;
   unsigned long Padding63;
   unsigned long Padding64;
   unsigned long Padding65;
   unsigned long Padding66;
   unsigned long Padding67;
   unsigned long Padding68;
   unsigned long Padding69;
   unsigned long Padding70;
   unsigned long Padding71;
   unsigned long Padding72;
   unsigned long Padding73;
   unsigned long Padding74;
   unsigned long Padding75;
   unsigned long Padding76;
   unsigned long Padding77;
   unsigned long Padding78;
   unsigned long Padding79;
   unsigned long Padding80;
   unsigned long Padding81;
   unsigned long Padding82;
   unsigned long Padding83;
   unsigned long Padding84;
   unsigned long Padding85;
   unsigned long Padding86;
   class CDirectSoundStreamSettings * m_pSettings;
   VADSTREAMEVENTSINK m_EventSink;
   void * m_pvEventContext;
   unsigned long m_dwPrdControl;
   MCPX_SSL_DESC m_aSslDesc[2];
   _LIST_ENTRY m_lstPending;
   _LIST_ENTRY m_lstAvailable;
   _LIST_ENTRY m_lstCompleted;
   MCPX_PACKET_CONTEXT * m_paPacketContexts;
   MCPX_PACKET_CONTEXT * m_pWorkingPacket;
   unsigned long m_dwWorkingPacketOffset;
   unsigned long Padding98;
   MCPX_DEFERRED_COMMAND m_aDeferredCommands[3];
   unsigned long m_dwFirstMappedSslIndex;
   unsigned long m_dwMappedSslCount;
   union {
   (type???) CMcpxStream;
   (type???) CMcpxStream;
   (type???) ~CMcpxStream;
   (type???) Initialize;
   (type???) Pause;
   (type???) IsPlaying;
   (type???) HasPendingData;
   (type???) IsReady;
   (type???) GetLowWatermark;
   (type???) SubmitPacket;
   (type???) Discontinuity;
   (type???) Flush;
   (type???) AllocateStreamResources;
   (type???) ReleaseStreamResources;
   (type???) Process;
   (type???) MapPackets;
   (type???) MapPacket;
   (type???) CommitSSL;
   (type???) CompleteSSL;
   (type???) GetSSLBase;
   (type???) CompletePackets;
   (type???) CompleteDeferredPackets;
   (type???) CompletePacket;
   (type???) ServiceVoiceInterrupt;
   (type???) ScheduleDeferredCommand;
   (type???) RemoveDeferredCommand;
   (type???) ServiceDeferredCommand;
   (type???) OnEndOfStream;
   (type???) __vecDelDtor;
   };
} CMcpxStream;

typedef struct VADSTREAMEVENTSINK
{
   void * OnPacketCompletion;
} VADSTREAMEVENTSINK;

typedef struct CDirectSoundStreamSettings
{
   union {
   (type???) CDirectSoundVoiceSettings;
   (type???) operator new;
   (type???) operator new[];
   (type???) operator delete;
   (type???) operator delete[];
   unsigned long Padding5;
   };
   unsigned long Padding6;
   unsigned long Padding7;
   unsigned long Padding8;
   unsigned long Padding9;
   unsigned long Padding10;
   unsigned long Padding11;
   unsigned long Padding12;
   unsigned long Padding13;
   unsigned long Padding14;
   unsigned long Padding15;
   unsigned long Padding16;
   unsigned long Padding17;
   unsigned long Padding18;
   unsigned long Padding19;
   unsigned long Padding20;
   unsigned long Padding21;
   unsigned long Padding22;
   unsigned long m_dwMaxAttachedPackets;
   void * m_pfnCallback;
   void * m_pvContext;
   union {
   (type???) CDirectSoundStreamSettings;
   (type???) CDirectSoundStreamSettings;
   (type???) ~CDirectSoundStreamSettings;
   (type???) Initialize;
   (type???) __local_vftable_ctor_closure;
   (type???) __vecDelDtor;
   };
} CDirectSoundStreamSettings;

typedef struct CMcpxEPDspManager
{
   union {
   (type???) operator new;
   (type???) operator new[];
   (type???) operator delete;
   (type???) operator delete[];
   (type???) CMcpxEPDspManager;
   (type???) ~CMcpxEPDspManager;
   (type???) Initialize;
   (type???) AC3SetAnalogOutput;
   (type???) AC3SetDigitalOutput;
   (type???) GetScratchSpaceAddr;
   (type???) GetDolbyConfigTable;
   (type???) AC3GetTotalScratchSize;
   (type???) AC3GetSuperExec;
   (type???) AC3GetLoader;
   (type???) AC3GetProgram;
   (type???) AC3GetInitialConfigTable;
   (type???) AC3GetLoaderTableBase;
   (type???) AC3GetProgramBase;
   (type???) AC3GetMaxPrograms;
   (type???) AC3GetHeapSize;
   (type???) AC3StartGpInput;
   class CMcpxDspScratchDma * m_pScratchDma;
   };
   class CMcpxCore * m_pApu;
   class CMcpxGPDspManager * m_pGlobalProc;
   unsigned char * m_pConfigTable;
   (type???) __vecDelDtor;
} CMcpxEPDspManager;

typedef struct DSP_CONTROL
{
   WORD0 w0;
   WORD1 w1;
   WORD2 w2;
   WORD3 w3;
} DSP_CONTROL;

typedef struct WORD3::__unnamed
{
   union {
   unsigned long dspStart;
   unsigned long nul;
   };
} WORD3::__unnamed;

typedef union WORD3
{
   union {
   WORD3::__unnamed field;
   unsigned long uValue;
   };
} WORD3;

typedef struct WORD1::__unnamed
{
   union {
   unsigned long interleave;
   unsigned long dspToSys;
   unsigned long IOC;
   unsigned long smOffWrBack;
   unsigned long smBufId;
   unsigned long iso;
   unsigned long smDataFormat;
   unsigned long increment;
   };
} WORD1::__unnamed;

typedef union WORD1
{
   union {
   WORD1::__unnamed field;
   unsigned long uValue;
   };
} WORD1;

typedef struct WORD0::__unnamed
{
   union {
   unsigned long nextCommand;
   unsigned long EOL;
   };
} WORD0::__unnamed;

typedef union WORD0
{
   union {
   WORD0::__unnamed field;
   unsigned long uValue;
   };
} WORD0;

typedef union WORD2
{
   union {
   WORD2::__unnamed field;
   unsigned long uValue;
   };
} WORD2;

typedef struct WORD2::__unnamed
{
   union {
   unsigned long count0;
   unsigned long count1;
   };
} WORD2::__unnamed;

typedef union R_GPDMA_CONFIG
{
   union {
   unsigned long Start;
   unsigned long Ready;
   unsigned long ReqIOC;
   unsigned long ReqEOL;
   unsigned long ReqErr;
   unsigned long uValue;
   };
} R_GPDMA_CONFIG;

typedef struct FIRFILTER8
{
   unsigned char Coeff[31];
   unsigned char Delay;
} FIRFILTER8;

typedef struct CAutoLock
{
   union {
   int m_fLocked;
   (type???) public: __thiscall CAutoLock::CAutoLock(void);
   (type???) public: __thiscall CAutoLock::~CAutoLock(void);
   (type???) __vecDelDtor;
   };
} CAutoLock;

typedef struct DOLBY_CONFIG_TABLE
{
   unsigned long table_size;
   unsigned long do_surround_encode;
   unsigned long do_game_encode;
   unsigned long do_downmix_encode;
   unsigned long pcm_sample_rate_code;
   unsigned long input_ch_config;
   unsigned long lfe_present;
   unsigned long ac3_dialnorm;
   unsigned long ac3_bandwidth;
   unsigned long channel_lpf_enabled;
   unsigned long lfe_lpf_enabled;
   unsigned long dc_hpf_enabled;
   unsigned long dynrng_exists;
   unsigned long ac3_dynrng_code;
   unsigned long compr_exists;
   unsigned long ac3_compr_code;
   unsigned long surround_gain_enabled;
   unsigned long surround_gain;
   unsigned long surround_mode;
   unsigned long reserved_1;
   unsigned long reserved_2;
   unsigned long reserved_3;
   unsigned long reserved_4;
   unsigned long reserved_5;
} DOLBY_CONFIG_TABLE;

typedef struct _MCPX_HW_NOTIFICATION
{
   unsigned long GSCNT;
   unsigned long CurrentOffset;
   unsigned long Zero;
   unsigned char Res0;
   unsigned char SamplesAvailable;
   unsigned char EnvelopeActive;
   unsigned char Status;
} MCPX_HW_NOTIFICATION;

typedef struct HOST_TO_DSP_COMMANDBLOCK
{
   unsigned long dwOffset;
   unsigned long dwCodeLength;
   unsigned long dwStateOffset;
   unsigned long dwStateLength;
   unsigned long dwCommandFlags;
   unsigned long dwDspStatus;
} HOST_TO_DSP_COMMANDBLOCK;

typedef struct CMcpxDspImage
{
   union {
   (type???) public: static void * __cdecl CMcpxGPDspManager::operator new(unsigned int);
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   (type???) public: __thiscall CMcpxDspImage::CMcpxDspImage(void);
   (type???) public: void __thiscall CMcpxDspImage::Initialize(void);
   (type???) public: void * __thiscall CMcpxDspImage::GetLoader(void);
   (type???) public: unsigned long __thiscall CMcpxDspImage::GetLoaderSize(void);
   void * m_pLoader;
   };
   unsigned long m_uLoaderSize;
} CMcpxDspImage;

typedef struct CMcpxDspScratchDma
{
   union {
   (type???) public: static void * __cdecl CMcpxGPDspManager::operator new(unsigned int);
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   (type???) public: __thiscall CMcpxDspScratchDma::CMcpxDspScratchDma(class CMcpxCore *,int);
   (type???) public: __thiscall CMcpxDspScratchDma::~CMcpxDspScratchDma(void);
   (type???) public: void __thiscall CMcpxDspScratchDma::Initialize(unsigned long);
   (type???) public: void __thiscall CMcpxDspScratchDma::Copy(unsigned long,void *,unsigned long);
   (type???) Put;
   (type???) AddPages;
   (type???) GetScratchTableLinAddr;
   (type???) GetScratchSpaceLinAddr;
   (type???) GetFxScratchSpaceLinAddr;
   (type???) GetScratchSpacePhysAddr;
   (type???) GetScratchSpaceSize;
   (type???) AdjustFxScratch;
   unsigned long m_dwMaxPages;
   };
   unsigned long m_dwReservedPages;
   int m_fGpScratch;
   MCPX_ALLOC_CONTEXT * m_pSGETableContext;
   MCPX_ALLOC_CONTEXT * m_pDmaBufferContext;
   MCPX_ALLOC_CONTEXT m_ctxFxScratch;
   class CMcpxCore * m_pApu;
   unsigned long m_uRegOffsetValidPages;
   (type???) __vecDelDtor;
} CMcpxDspScratchDma;

typedef struct CMcpxGPDspManager
{
   union {
   (type???) public: static void * __cdecl CMcpxGPDspManager::operator new(unsigned int);
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   (type???) public: __thiscall CMcpxGPDspManager::CMcpxGPDspManager(class CMcpxCore *);
   (type???) public: __thiscall CMcpxGPDspManager::~CMcpxGPDspManager(void);
   (type???) public: void __thiscall CMcpxGPDspManager::Initialize(void);
   (type???) GetScratchPage;
   (type???) AC3SetOutputBuffer;
   (type???) SetMultipassBuffer;
   (type???) DownloadEffectsImage;
   (type???) SetEffectData;
   (type???) GetEffectData;
   (type???) GetEffectMap;
   (type???) CommitChanges;
   (type???) RestoreCommandBlock;
   (type???) GetScratchDma;
   (type???) ParseEffectImageInfo;
   class CMcpxCore * m_pApu;
   };
   unsigned long m_uAC3BufferOffset;
   unsigned long m_uMultipassBufferOffset;
   class CMcpxDspScratchDma * m_pScratchDma;
   class CMcpxDspImage * m_pDspImage;
   unsigned long m_uPMemOffset;
   unsigned long m_uPMemMaxSize;
   unsigned long m_dwCurrentLowestScratchOffset;
   unsigned long m_dwStateSizeToCommit;
   _DSEFFECTIMAGEDESC * m_pFxDescriptor;
   HOST_TO_DSP_COMMANDBLOCK m_InitialCmdBlock;
   (type???) __vecDelDtor;
} CMcpxGPDspManager;

typedef struct CMcpxCore
{
   union {
   (type???) ;
   (type???) operator new;
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   const unsigned long m_adwGPOutputBufferSizes[1];
   const unsigned long m_adwEPOutputBufferSizes[2];
   };
   MCPX_ALLOC_CONTEXT m_ctxMemory[16];
   class CDirectSoundSettings * m_pSettings;
   class CMcpxGPDspManager * m_pGpDspManager;
   class CAc97Device m_Ac97;
   union {
   (type???) CMcpxCore;
   (type???) public: __thiscall CMcpxCore::CMcpxCore(void);
   (type???) public: virtual __thiscall CMcpxCore::~CMcpxCore(void);
   (type???) public: long __thiscall CMcpxCore::Initialize(class CDirectSoundSettings *,int);
   (type???) public: int __thiscall CMcpxCore::IdleVoiceProcessor(int);
   (type???) public: static unsigned long __stdcall CMcpxCore::GetPhysicalMemoryProperties(void *,unsigned long,unsigned long *,unsigned long *);
   (type???) public: static unsigned long __stdcall CMcpxCore::MapTransfer(void * *,unsigned long *,unsigned long *);
   (type???) public: static long __stdcall CMcpxCore::AllocateContext(struct MCPX_ALLOC_CONTEXT *,unsigned long,unsigned long,unsigned long);
   (type???) public: struct _MCPX_HW_NOTIFICATION volatile * __thiscall CMcpxCore::GetNotifier(unsigned long);
   (type???) public: int __thiscall CMcpxCore::GetNotifierStatus(unsigned long,int);
   (type???) public: void __thiscall CMcpxCore::SetNotifierStatus(unsigned long,int);
   (type???) public: static unsigned long __stdcall CMcpxCore::GetVoiceNotifierIndex(unsigned long,unsigned long);
   (type???) protected: void __thiscall CMcpxCore::Reset(int);
   (type???) protected: void __thiscall CMcpxCore::SetInterruptState(int);
   (type???) protected: void __thiscall CMcpxCore::SetPrivLockState(int);
   (type???) protected: void __thiscall CMcpxCore::SetFrontEndState(enum MCPX_FE_STATE);
   (type???) protected: void __thiscall CMcpxCore::SetSetupEngineState(enum MCPX_SE_STATE);
   (type???) protected: void __thiscall CMcpxCore::ResetGlobalCounters(void);
   (type???) protected: long __thiscall CMcpxCore::AllocateApuMemory(void);
   (type???) protected: void __thiscall CMcpxCore::SetupFrontEndProcessor(void);
   (type???) protected: void __thiscall CMcpxCore::SetupVoiceProcessor(void);
   (type???) protected: void __thiscall CMcpxCore::SetupGlobalProcessor(int);
   (type???) protected: long __thiscall CMcpxCore::SetupAc97(void);
   (type???) __local_vftable_ctor_closure;
   (type???) __vecDelDtor;
   };
} CMcpxCore;

typedef struct MCPX_SSL_DESC
{
   _LIST_ENTRY lstPackets;
   unsigned long dwPrdCount;
   unsigned long dwBytesMapped;
} MCPX_SSL_DESC;

typedef struct CRefCount
{
   union {
   (type???) ;
   (type???) operator new;
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   unsigned long Padding5;
   };
   unsigned long m_ulRefCount;
   union {
   (type???) CRefCount;
   (type???) public: __thiscall CRefCount::CRefCount(unsigned long);
   (type???) public: virtual __thiscall CRefCount::~CRefCount(void);
   (type???) public: virtual unsigned long __stdcall CRefCount::AddRef(void);
   (type???) public: virtual unsigned long __stdcall CRefCount::Release(void);
   (type???) __dflt_ctor_closure;
   (type???) __local_vftable_ctor_closure;
   (type???) __vecDelDtor;
   };
} CRefCount;

typedef struct MCPX_ALLOC_CONTEXT
{
   void * VirtualAddress;
   unsigned long PhysicalAddress;
   unsigned long Size;
} MCPX_ALLOC_CONTEXT;

typedef struct MCPX_VOICE_VOLUME
{
   unsigned long TarVOLA[3];
   unsigned long TarVOLB[3];
   unsigned long TarVOLC[3];
} MCPX_VOICE_VOLUME;

typedef union R_GP_RESET
{
   union {
   unsigned long Global;
   unsigned long DSP;
   unsigned long NMI;
   unsigned long Abort;
   unsigned long uValue;
   };
} R_GP_RESET;

typedef struct CIrql
{
   int m_fRaised;
   unsigned char m_irql;
   union {
   (type???) public: void __thiscall CIrql::Raise(void);
   (type???) public: void __thiscall CIrql::Lower(void);
   };
} CIrql;

typedef struct ACIPRD
{
   unsigned long dwPhysicalAddress;
   union {
   unsigned long wLength;
   unsigned long wReserved;
   int fBufferUnderrunPolicy;
   int fInterruptOnCompletion;
   };
} ACIPRD;

typedef struct CAc97Channel
{
   union {
   (type???) public: static void * __cdecl CMcpxGPDspManager::operator new(unsigned int);
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   const unsigned long m_adwRegisterOffsets[2];
   const unsigned long m_dwSilenceSize;
   const int m_nChannelType;
   };
   unsigned long m_dwPosition;
   class CAc97Device * m_pDevice;
   unsigned long m_dwFlags;
   void * m_pfnCallback;
   void * m_pvCallbackContext;
   ACIPRD * m_pPrdl;
   unsigned long m_dwPrdlAddress;
   void * m_pvSilence;
   unsigned char m_bPrdCount;
   unsigned char m_bCurrentPrd;
   unsigned char Padding17;
   unsigned char Padding18;
   unsigned long m_dwMode;
   unsigned long m_dwLastPosition;
   union {
   (type???) public: __thiscall CAc97Channel::CAc97Channel(class CAc97Device *,enum AC97CHANNELTYPE);
   (type???) public: __thiscall CAc97Channel::~CAc97Channel(void);
   (type???) public: long __thiscall CAc97Channel::Initialize(unsigned long,void (__stdcall*)(void *),void *);
   (type???) public: void __thiscall CAc97Channel::Terminate(void);
   (type???) Release;
   (type???) GetFreePacketCount;
   (type???) public: void __thiscall CAc97Channel::AttachPacket(unsigned long,unsigned long);
   (type???) AttachPacket;
   (type???) AttachBuffer;
   (type???) AttachBuffer;
   (type???) public: void __thiscall CAc97Channel::Run(unsigned long);
   (type???) public: void __thiscall CAc97Channel::Pause(void);
   (type???) public: void __thiscall CAc97Channel::Flush(int);
   (type???) Discontinuity;
   (type???) public: void __thiscall CAc97Channel::Reset(void);
   (type???) GetPosition;
   (type???) public: void __thiscall CAc97Channel::SetMode(unsigned long);
   (type???) protected: void __thiscall CAc97Channel::SetPosition(unsigned long);
   (type???) protected: void __thiscall CAc97Channel::ServiceInterrupt(void);
   (type???) protected: void __thiscall CAc97Channel::SetPrdIndeces(unsigned char,unsigned char,int,int);
   (type???) protected: unsigned char __thiscall CAc97Channel::PeekAciRegister8(unsigned long);
   (type???) protected: void __thiscall CAc97Channel::PokeAciRegister8(unsigned long,unsigned char);
   (type???) protected: unsigned short __thiscall CAc97Channel::PeekAciRegister16(unsigned long);
   (type???) protected: void __thiscall CAc97Channel::PokeAciRegister16(unsigned long,unsigned short);
   (type???) PeekAciRegister32;
   (type???) protected: void __thiscall CAc97Channel::PokeAciRegister32(unsigned long,unsigned long);
   (type???) __vecDelDtor;
   };
} CAc97Channel;

typedef struct CAc97Device
{
   union {
   (type???) operator new;
   (type???) operator new[];
   (type???) operator delete;
   (type???) operator delete[];
   const tWAVEFORMATEX m_wfxFormat;
   const unsigned long m_dwAc97RegisterBase;
   const unsigned long m_dwAciRegisterBase;
   class CAc97Device * m_pDevice;
   class CAc97Channel * m_apChannels[2];
   };
   unsigned long m_dwFlags;
   _KINTERRUPT m_Interrupt;
   _HAL_SHUTDOWN_REGISTRATION m_HalShutdownData;
   _KDPC m_dpc;
   unsigned char m_abPendingBufferCompletions[2] m_abPendingBufferCompletions[2];
   union {
   (type???) public: __thiscall CAc97Device::CAc97Device(void);
   (type???) public: __thiscall CAc97Device::~CAc97Device(void);
   (type???) public: long __thiscall CAc97Device::Initialize(unsigned long);
   (type???) public: void __thiscall CAc97Device::Terminate(void);
   (type???) public: long __thiscall CAc97Device::CreateChannel(enum AC97CHANNELTYPE,class CAc97Channel * *);
   (type???) ReleaseChannel;
   (type???) public: void __thiscall CAc97Device::ReleaseChannel(enum AC97CHANNELTYPE);
   (type???) protected: int __thiscall CAc97Device::CodecReady(void);
   (type???) protected: long __thiscall CAc97Device::PowerUp(void);
   (type???) protected: unsigned long __thiscall CAc97Device::ServiceAciInterrupt(void);
   (type???) protected: void __thiscall CAc97Device::ServiceAciInterruptDpc(void);
   (type???) protected: void __thiscall CAc97Device::SynchronizeAciInterrupt(void);
   (type???) protected: unsigned long __thiscall CAc97Device::GetInterruptStatus(void);
   (type???) protected: static int __stdcall CAc97Device::AcquireCodecSemaphore(void);
   (type???) protected: static unsigned char __stdcall CAc97Device::PeekRegister8(unsigned long);
   (type???) protected: static void __stdcall CAc97Device::PokeRegister8(unsigned long,unsigned char);
   (type???) protected: static unsigned short __stdcall CAc97Device::PeekRegister16(unsigned long);
   (type???) protected: static void __stdcall CAc97Device::PokeRegister16(unsigned long,unsigned short);
   (type???) protected: static unsigned long __stdcall CAc97Device::PeekRegister32(unsigned long);
   (type???) protected: static void __stdcall CAc97Device::PokeRegister32(unsigned long,unsigned long);
   (type???) protected: static unsigned char __stdcall CAc97Device::PeekAciRegister8(unsigned long);
   (type???) protected: static void __stdcall CAc97Device::PokeAciRegister8(unsigned long,unsigned char);
   (type???) protected: static unsigned short __stdcall CAc97Device::PeekAciRegister16(unsigned long);
   (type???) protected: static void __stdcall CAc97Device::PokeAciRegister16(unsigned long,unsigned short);
   (type???) protected: static unsigned long __stdcall CAc97Device::PeekAciRegister32(unsigned long);
   (type???) protected: static void __stdcall CAc97Device::PokeAciRegister32(unsigned long,unsigned long);
   (type???) PeekAc97Register;
   (type???) protected: static int __stdcall CAc97Device::PokeAc97Register(enum AC97REGISTER,unsigned short);
   (type???) VerifyPokeAc97Register;
   (type???) protected: static void __stdcall CAc97Device::WaitRegisterRetry(void);
   (type???) private: static unsigned char __stdcall CAc97Device::AciInterruptServiceRoutine(struct _KINTERRUPT *,void *);
   (type???) private: static void __stdcall CAc97Device::AciInterruptDpcHandler(struct _KDPC *,void *,void *,void *);
   (type???) private: static void __stdcall CAc97Device::AciShutdownNotifier(struct _HAL_SHUTDOWN_REGISTRATION *);
   (type???) private: static unsigned char __stdcall CAc97Device::AciSynchronizationRoutine(void *);
   (type???) __vecDelDtor;
   };
} CAc97Device;

typedef struct CDirectSoundVoice
{
   union {
   (type???) CRefCount;
   (type???) operator new;
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   unsigned long Padding5;
   };
   unsigned long Padding6;
   class CDirectSoundVoice * pPrev;
   class CDirectSoundVoice * pNext;
   class CDirectSound * m_pDirectSound;
   class CMcpxVoiceClient * m_pVoice;
   class CDirectSoundVoiceSettings * m_pSettings;
   union {
   (type???) CDirectSoundVoice;
   (type???) public: __thiscall CDirectSoundVoice::CDirectSoundVoice(class CDirectSound *);
   (type???) public: virtual __thiscall CDirectSoundVoice::~CDirectSoundVoice(void);
   (type???) public: void __stdcall CDirectSoundVoice::Initialize(class CMcpxVoiceClient *,class CDirectSoundVoiceSettings *);
   (type???) public: long __stdcall CDirectSoundVoice::SetVolume(long);
   (type???) SetFrequency;
   (type???) public: long __stdcall CDirectSoundVoice::SetPitch(long);
   (type???) SetLFO;
   (type???) public: long __stdcall CDirectSoundVoice::SetEG(struct _DSENVELOPEDESC const *);
   (type???) public: long __stdcall CDirectSoundVoice::SetFilter(struct _DSFILTERDESC const *);
   (type???) SetHeadroom;
   (type???) SetOutputBuffer;
   (type???) SetMixBins;
   (type???) public: long __stdcall CDirectSoundVoice::SetMixBinVolumes(unsigned long,long const *);
   (type???) SetAllParameters;
   (type???) SetConeAngles;
   (type???) SetConeOrientation;
   (type???) SetConeOutsideVolume;
   (type???) SetMaxDistance;
   (type???) SetMinDistance;
   (type???) SetMode;
   (type???) SetPosition;
   (type???) SetVelocity;
   (type???) SetI3DL2Source;
   (type???) __vecDelDtor;
   };
} CDirectSoundVoice;

typedef struct CList<CDirectSoundVoice>
{
   union {
   (type???) operator new;
   (type???) operator new[];
   (type???) operator delete;
   (type???) operator delete[];
   class CDirectSoundVoice * m_pHead;
   };
   class CDirectSoundVoice * m_pTail;
   union {
   (type???) public: __thiscall CMcpxDspImage::CMcpxDspImage(void);
   (type???) public: void __thiscall CList<class CDirectSoundVoice>::AddNode(class CDirectSoundVoice *);
   (type???) public: void __thiscall CList<class CDirectSoundVoice>::InsertNode(class CDirectSoundVoice *,class CDirectSoundVoice *);
   (type???) public: void __thiscall CList<class CDirectSoundVoice>::RemoveNode(class CDirectSoundVoice *);
   (type???) Reset;
   (type???) GetListHead;
   (type???) GetListTail;
   };
} CList<CDirectSoundVoice>;

typedef union R_INTR
{
   union {
   unsigned long General;
   unsigned long DeltaWarning;
   unsigned long RetriggerEvent;
   unsigned long DeltaPanic;
   unsigned long FETrap;
   unsigned long FENotify;
   unsigned long FEVoice;
   unsigned long FEMethodOverFlow;
   unsigned long GPMailbox;
   unsigned long GPNotify;
   unsigned long EPMailbox;
   unsigned long EPNotify;
   unsigned long uValue;
   };
} R_INTR;

typedef struct DSFX_I3DL2SOURCE_PARAMS
{
   long lDirect;
   long lDirectHF;
   long lSource;
   long lSourceHF;
   int nDirectIir;
   int nReverbIir;
} DSFX_I3DL2SOURCE_PARAMS;

typedef struct MCPX_3DVOICE_DATA
{
   _D3DVECTOR vNormP;
   _D3DVECTOR vPDot;
   double fAbsP;
   float fAzimuth;
   float fElevation;
   float fThetaS;
   long lDistanceVolume;
   long lConeVolume;
   long lFrontVolume;
   long lRearVolume;
   float fDoppler;
} MCPX_3DVOICE_DATA;

typedef struct MCPX_DEFERRED_COMMAND
{
   _LIST_ENTRY leListEntry;
   unsigned long dwFlags;
   unsigned long Padding2;
   __int64 rtTimestamp;
   class CMcpxVoiceClient * pVoice;
   unsigned long dwCommand;
   unsigned long dwContext;
} MCPX_DEFERRED_COMMAND;

typedef struct _SGEHEAPRUNMARKER
{
   _SGEHEAPRUNMARKER * pPrev;
   _SGEHEAPRUNMARKER * pNext;
   unsigned char bRefCount;
   unsigned char Padding3;
   unsigned char Padding4;
   unsigned char Padding5;
   void * pvBufferBase;
   short wElement;
   short wLength;
} SGEHEAPRUNMARKER;

typedef struct VADBUFFEREVENTSINK
{
   void * OnPositionDelta;
   void * OnStop;
} VADBUFFEREVENTSINK;

typedef struct CMcpxBuffer
{
   union {
   (type???) CMcpxVoiceClient;
   (type???) public: static void * __cdecl CMcpxGPDspManager::operator new(unsigned int);
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   unsigned long Padding5;
   };
   unsigned long Padding6;
   unsigned long Padding7;
   unsigned long Padding8;
   unsigned long Padding9;
   unsigned long Padding10;
   unsigned long Padding11;
   unsigned long Padding12;
   unsigned long Padding13;
   unsigned long Padding14;
   unsigned long Padding15;
   unsigned long Padding16;
   unsigned long Padding17;
   unsigned long Padding18;
   unsigned long Padding19;
   unsigned long Padding20;
   unsigned long Padding21;
   unsigned long Padding22;
   unsigned long Padding23;
   unsigned long Padding24;
   unsigned long Padding25;
   unsigned long Padding26;
   unsigned long Padding27;
   unsigned long Padding28;
   unsigned long Padding29;
   unsigned long Padding30;
   unsigned long Padding31;
   unsigned long Padding32;
   unsigned long Padding33;
   unsigned long Padding34;
   unsigned long Padding35;
   unsigned long Padding36;
   unsigned long Padding37;
   unsigned long Padding38;
   unsigned long Padding39;
   unsigned long Padding40;
   unsigned long Padding41;
   unsigned long Padding42;
   unsigned long Padding43;
   unsigned long Padding44;
   unsigned long Padding45;
   unsigned long Padding46;
   unsigned long Padding47;
   unsigned long Padding48;
   unsigned long Padding49;
   unsigned long Padding50;
   unsigned long Padding51;
   unsigned long Padding52;
   unsigned long Padding53;
   unsigned long Padding54;
   unsigned long Padding55;
   unsigned long Padding56;
   unsigned long Padding57;
   unsigned long Padding58;
   unsigned long Padding59;
   unsigned long Padding60;
   unsigned long Padding61;
   unsigned long Padding62;
   unsigned long Padding63;
   unsigned long Padding64;
   unsigned long Padding65;
   unsigned long Padding66;
   unsigned long Padding67;
   unsigned long Padding68;
   unsigned long Padding69;
   unsigned long Padding70;
   unsigned long Padding71;
   unsigned long Padding72;
   unsigned long Padding73;
   unsigned long Padding74;
   unsigned long Padding75;
   unsigned long Padding76;
   unsigned long Padding77;
   unsigned long Padding78;
   unsigned long Padding79;
   unsigned long Padding80;
   unsigned long Padding81;
   unsigned long Padding82;
   unsigned long Padding83;
   unsigned long Padding84;
   unsigned long Padding85;
   unsigned long Padding86;
   class CDirectSoundBufferSettings * m_pSettings;
   VADBUFFEREVENTSINK m_EventSink;
   void * m_pvEventContext;
   _SGEHEAPRUNMARKER * m_pSgeHeapEntry;
   unsigned long Padding91;
   MCPX_DEFERRED_COMMAND m_aDeferredCommands[5];
   unsigned long m_dwCachedPlayCursor;
   union {
   (type???) CMcpxBuffer;
   (type???) public: __thiscall CMcpxBuffer::CMcpxBuffer(class CMcpxAPU *);
   (type???) public: virtual __thiscall CMcpxBuffer::~CMcpxBuffer(void);
   (type???) public: long __thiscall CMcpxBuffer::Initialize(class CDirectSoundBufferSettings *,struct VADBUFFEREVENTSINK const &,void *);
   (type???) public: long __thiscall CMcpxBuffer::Play(int);
   (type???) public: long __thiscall CMcpxBuffer::Play(__int64,int);
   (type???) public: long __thiscall CMcpxBuffer::Stop(void);
   (type???) public: long __thiscall CMcpxBuffer::Stop(__int64);
   (type???) public: long __thiscall CMcpxBuffer::NoteOff(int);
   (type???) public: long __thiscall CMcpxBuffer::NoteOff(__int64,int);
   (type???) public: long __thiscall CMcpxBuffer::GetStatus(unsigned long *);
   (type???) public: long __thiscall CMcpxBuffer::SetBufferData(void);
   (type???) public: long __thiscall CMcpxBuffer::ReleaseBufferData(void);
   (type???) public: long __thiscall CMcpxBuffer::SetLoopRegion(void);
   (type???) public: long __thiscall CMcpxBuffer::GetCurrentPosition(unsigned long *,unsigned long *);
   (type???) public: long __thiscall CMcpxBuffer::SetCurrentPosition(unsigned long);
   (type???) protected: long __thiscall CMcpxBuffer::AllocateBufferResources(void);
   (type???) protected: void __thiscall CMcpxBuffer::ReleaseBufferResources(void);
   (type???) protected: long __thiscall CMcpxBuffer::MapInputBuffer(void);
   (type???) protected: void __thiscall CMcpxBuffer::MapEffectsBuffer(void);
   (type???) protected: void __thiscall CMcpxBuffer::MapBuffer(unsigned long,void *,unsigned long);
   (type???) protected: void __thiscall CMcpxBuffer::UnmapBuffer(void);
   (type???) protected: int __thiscall CMcpxBuffer::ScheduleDeferredCommand(unsigned long,__int64,unsigned long);
   (type???) protected: void __thiscall CMcpxBuffer::RemoveDeferredCommand(unsigned long);
   (type???) protected: virtual void __thiscall CMcpxBuffer::ServiceDeferredCommand(unsigned long,unsigned long);
   (type???) protected: void __thiscall CMcpxBuffer::OnPositionDelta(void);
   (type???) protected: virtual int __thiscall CMcpxBuffer::ServiceVoiceInterrupt(void);
   (type???) __vecDelDtor;
   };
} CMcpxBuffer;

typedef struct CDirectSoundBufferSettings
{
   union {
   (type???) CDirectSoundVoiceSettings;
   (type???) public: static void * __cdecl CMcpxGPDspManager::operator new(unsigned int);
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   unsigned long Padding5;
   };
   unsigned long Padding6;
   unsigned long Padding7;
   unsigned long Padding8;
   unsigned long Padding9;
   unsigned long Padding10;
   unsigned long Padding11;
   unsigned long Padding12;
   unsigned long Padding13;
   unsigned long Padding14;
   unsigned long Padding15;
   unsigned long Padding16;
   unsigned long Padding17;
   unsigned long Padding18;
   unsigned long Padding19;
   unsigned long Padding20;
   unsigned long Padding21;
   unsigned long Padding22;
   void * m_pvBufferData;
   unsigned long m_dwBufferSize;
   unsigned long m_dwLoopStart;
   unsigned long m_dwLoopLength;
   unsigned long m_dwInputMixBinMask;
   union {
   (type???) CDirectSoundBufferSettings;
   (type???) public: __thiscall CDirectSoundBufferSettings::CDirectSoundBufferSettings(void);
   (type???) public: virtual __thiscall CDirectSoundBufferSettings::~CDirectSoundBufferSettings(void);
   (type???) public: long __thiscall CDirectSoundBufferSettings::Initialize(class CDirectSoundSettings *,struct _DSBUFFERDESC const *);
   (type???) public: long __thiscall CDirectSoundBufferSettings::SetBufferData(void *,unsigned long);
   (type???) public: void __thiscall CDirectSoundBufferSettings::SetLoopRegion(unsigned long,unsigned long);
   (type???) __local_vftable_ctor_closure;
   (type???) __vecDelDtor;
   };
} CDirectSoundBufferSettings;

typedef struct CDirectSoundBuffer
{
   (type???) IDirectSoundBuffer;
   union {
   (type???) CDirectSoundVoice;
   (type???) public: static void * __cdecl CMcpxGPDspManager::operator new(unsigned int);
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   unsigned long Padding6;
   };
   unsigned long Padding7;
   unsigned long Padding8;
   unsigned long Padding9;
   unsigned long Padding10;
   unsigned long Padding11;
   unsigned long Padding12;
   class CDirectSoundBufferSettings * m_pSettings;
   class CMcpxBuffer * m_pBuffer;
   _DSBPOSITIONNOTIFY * m_paNotifies;
   unsigned long m_dwNotifyCount;
   unsigned long m_dwLastNotifyPosition;
   union {
   (type???) CDirectSoundBuffer;
   (type???) public: __thiscall CDirectSoundBuffer::CDirectSoundBuffer(class CDirectSound *);
   (type???) public: virtual __thiscall CDirectSoundBuffer::~CDirectSoundBuffer(void);
   (type???) public: long __stdcall CDirectSoundBuffer::Initialize(struct _DSBUFFERDESC const *);
   (type???) public: virtual unsigned long __stdcall CDirectSoundBuffer::AddRef(void);
   (type???) public: virtual unsigned long __stdcall CDirectSoundBuffer::Release(void);
   (type???) public: long __stdcall CDirectSoundBuffer::Play(unsigned long,unsigned long,unsigned long);
   (type???) public: long __stdcall CDirectSoundBuffer::PlayEx(__int64,unsigned long);
   (type???) Stop;
   (type???) public: long __stdcall CDirectSoundBuffer::StopEx(__int64,unsigned long);
   (type???) public: long __stdcall CDirectSoundBuffer::SetLoopRegion(unsigned long,unsigned long);
   (type???) public: long __stdcall CDirectSoundBuffer::GetStatus(unsigned long *);
   (type???) GetCurrentPosition;
   (type???) public: long __stdcall CDirectSoundBuffer::SetCurrentPosition(unsigned long);
   (type???) public: long __stdcall CDirectSoundBuffer::SetBufferData(void *,unsigned long);
   (type???) Lock;
   (type???) SetFrequency;
   (type???) public: long __stdcall CDirectSoundBuffer::SetVolume(long);
   (type???) public: long __stdcall CDirectSoundBuffer::SetPitch(long);
   (type???) SetLFO;
   (type???) public: long __stdcall CDirectSoundBuffer::SetEG(struct _DSENVELOPEDESC const *);
   (type???) public: long __stdcall CDirectSoundBuffer::SetFilter(struct _DSFILTERDESC const *);
   (type???) SetHeadroom;
   (type???) SetOutputBuffer;
   (type???) SetMixBins;
   (type???) public: long __stdcall CDirectSoundBuffer::SetMixBinVolumes(unsigned long,long const *);
   (type???) SetAllParameters;
   (type???) SetConeAngles;
   (type???) SetConeOrientation;
   (type???) SetConeOutsideVolume;
   (type???) SetMaxDistance;
   (type???) SetMinDistance;
   (type???) SetMode;
   (type???) SetPosition;
   (type???) SetVelocity;
   (type???) SetI3DL2Source;
   (type???) SetNotificationPositions;
   (type???) protected: void __stdcall CDirectSoundBuffer::NotifyPosition(unsigned long,unsigned long);
   (type???) protected: void __stdcall CDirectSoundBuffer::NotifyStop(void);
   (type???) protected: void __stdcall CDirectSoundBuffer::OnPositionDelta(unsigned long);
   (type???) protected: static void __stdcall CDirectSoundBuffer::OnPositionDeltaStatic(unsigned long,void *);
   (type???) protected: void __stdcall CDirectSoundBuffer::OnStop(void);
   (type???) protected: static void __stdcall CDirectSoundBuffer::OnStopStatic(void *);
   (type???) SortNotifies;
   (type???) SwapNotifies;
   (type???) __vecDelDtor;
   };
} CDirectSoundBuffer;

typedef struct CDirectSoundVoiceSettings
{
   union {
   (type???) CRefCount;
   (type???) operator new;
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   const tWAVEFORMATEX m_wfxMixDest;
   };
   class CDirectSoundSettings * m_pGlobalSettings;
   unsigned long m_dwFlags;
   tWAVEFORMATEX * m_pwfxFormat;
   long m_lPitch;
   long m_lVolume;
   unsigned long m_dwHeadroom;
   unsigned long m_dwMixBinMask;
   long m_alMixBinVolumes[8];
   class CDirectSoundBuffer * m_pMixinBuffer;
   union {
   (type???) CDirectSoundVoiceSettings;
   (type???) public: __thiscall CDirectSoundVoiceSettings::CDirectSoundVoiceSettings(void);
   (type???) public: virtual __thiscall CDirectSoundVoiceSettings::~CDirectSoundVoiceSettings(void);
   (type???) public: long __thiscall CDirectSoundVoiceSettings::Initialize(class CDirectSoundSettings *,unsigned long,struct tWAVEFORMATEX const *,unsigned long);
   (type???) public: void __thiscall CDirectSoundVoiceSettings::SetVolume(long);
   (type???) SetHeadroom;
   (type???) public: void __thiscall CDirectSoundVoiceSettings::SetMixBins(unsigned long);
   (type???) public: void __thiscall CDirectSoundVoiceSettings::SetOutputBuffer(class CDirectSoundBuffer *);
   (type???) __local_vftable_ctor_closure;
   (type???) __vecDelDtor;
   };
} CDirectSoundVoiceSettings;

typedef struct MCPX_VOICE_REGCACHE
{
   unsigned long CfgFMT;
   unsigned long CfgMISC;
   unsigned long CfgENV0;
   unsigned long CfgENVA;
   unsigned long CfgENV1;
   unsigned long CfgENVF;
   unsigned long CfgLFODLY;
   unsigned long LFOENV;
   unsigned long LFOMOD;
   unsigned long TarFCA;
   unsigned long TarFCB;
   unsigned long VoiceOn;
} MCPX_VOICE_REGCACHE;

typedef struct CMcpxVoiceClient
{
   union {
   (type???) CRefCount;
   unsigned long Padding1;
   };
   unsigned long Padding2;
   volatile unsigned long m_dwStatus;
   class CMcpxAPU * m_pMcpxApu;
   void * m_ahVoices[3];
   _DS3DBUFFER m_3dBuffer;
   _DSI3DL2BUFFER m_I3dl2Buffer;
   unsigned long m_dw3dParameterMask;
   MCPX_VOICE_REGCACHE m_RegCache;
   _LIST_ENTRY m_lstSourceVoices;
   _LIST_ENTRY m_leActiveVoice;
   _LIST_ENTRY m_lePendingInactiveVoice;
   _LIST_ENTRY m_le3dVoice;
   _LIST_ENTRY m_leSourceVoice;
   unsigned char m_bVoiceList;
   unsigned char Padding16;
   unsigned char Padding17;
   unsigned char Padding18;
   class CDirectSoundVoiceSettings * m_pSettings;
   unsigned long Padding20;
   MCPX_3DVOICE_DATA m_3dData;
   DSFX_I3DL2SOURCE_PARAMS m_I3dl2Data;
   unsigned char m_bAvailable3dFilter;
   union {
   (type???) CMcpxVoiceClient;
   (type???) public: __thiscall CMcpxVoiceClient::CMcpxVoiceClient(class CMcpxAPU *);
   (type???) public: virtual __thiscall CMcpxVoiceClient::~CMcpxVoiceClient(void);
   (type???) public: long __thiscall CMcpxVoiceClient::Initialize(class CDirectSoundVoiceSettings *,int);
   (type???) SetMixBins;
   (type???) public: long __thiscall CMcpxVoiceClient::SetVolume(void);
   (type???) public: long __thiscall CMcpxVoiceClient::SetMixBinVolumes(void);
   (type???) public: long __thiscall CMcpxVoiceClient::SetPitch(void);
   (type???) SetLFO;
   (type???) public: long __thiscall CMcpxVoiceClient::SetEG(struct _DSENVELOPEDESC const *);
   (type???) public: long __thiscall CMcpxVoiceClient::SetFilter(struct _DSFILTERDESC const *);
   (type???) SetHeadroom;
   (type???) ConnectVoice;
   (type???) public: long __thiscall CMcpxVoiceClient::DisconnectVoice(void);
   (type???) public: virtual void __thiscall CMcpxVoiceClient::ActivateVoice(void);
   (type???) public: virtual void __thiscall CMcpxVoiceClient::DeactivateVoice(int,int);
   (type???) protected: void __thiscall CMcpxVoiceClient::ReleaseVoice(void);
   (type???) protected: void __thiscall CMcpxVoiceClient::PauseVoice(unsigned long);
   (type???) protected: void __thiscall CMcpxVoiceClient::WaitForVoiceOff(void);
   (type???) protected: void __thiscall CMcpxVoiceClient::ConvertMixBinValues(unsigned long *,unsigned long *);
   (type???) protected: void __thiscall CMcpxVoiceClient::ConvertVolumeValues(struct MCPX_VOICE_VOLUME *);
   (type???) protected: void __thiscall CMcpxVoiceClient::ConvertPitchValue(unsigned long *);
   (type???) protected: unsigned long __thiscall CMcpxVoiceClient::GetVoiceCfgFMT(unsigned long);
   (type???) protected: long __thiscall CMcpxVoiceClient::AllocateVoiceResources(void);
   (type???) protected: void __thiscall CMcpxVoiceClient::ReleaseVoiceResources(void);
   (type???) protected: unsigned long __thiscall CMcpxVoiceClient::GetHwVoiceCount(void);
   (type???) protected: unsigned long __thiscall CMcpxVoiceClient::BytesToSamples(unsigned long);
   (type???) protected: unsigned long __thiscall CMcpxVoiceClient::SamplesToBytes(unsigned long);
   (type???) GetNotifier;
   (type???) protected: int __thiscall CMcpxVoiceClient::GetNotifierStatus(unsigned long,int);
   (type???) protected: void __thiscall CMcpxVoiceClient::SetNotifierStatus(unsigned long,int);
   (type???) protected: unsigned long __thiscall CMcpxVoiceClient::GetSSLPosition(void);
   (type???) protected: class CMcpxBuffer * __thiscall CMcpxVoiceClient::GetSubMixDestination(void);
   (type???) ServiceVoiceInterrupt;
   (type???) ServiceDeferredCommand;
   (type???) SetLFOA;
   (type???) SetLFOF;
   (type???) private: void __thiscall CMcpxVoiceClient::SetENVA(struct _DSENVELOPEDESC const *);
   (type???) private: void __thiscall CMcpxVoiceClient::SetENVF(struct _DSENVELOPEDESC const *);
   (type???) __vecDelDtor;
   };
} CMcpxVoiceClient;

typedef struct CMcpxBufferSgeHeap
{
   union {
   (type???) CHeap<_SGEHEAPRUNMARKER>;
   (type???) operator new;
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   (type???) CMcpxBufferSgeHeap;
   (type???) public: __thiscall CMcpxBufferSgeHeap::CMcpxBufferSgeHeap(void);
   (type???) public: virtual __thiscall CMcpxBufferSgeHeap::~CMcpxBufferSgeHeap(void);
   (type???) public: virtual long __thiscall CMcpxBufferSgeHeap::Initialize(unsigned short);
   (type???) public: virtual struct _SGEHEAPRUNMARKER * __thiscall CMcpxBufferSgeHeap::Alloc(void *,unsigned long);
   (type???) public: virtual void __thiscall CMcpxBufferSgeHeap::Free(struct _SGEHEAPRUNMARKER *);
   (type???) GetFreeElementCount;
   (type???) __local_vftable_ctor_closure;
   (type???) __vecDelDtor;
   };
} CMcpxBufferSgeHeap;

typedef struct CMcpxAPU
{
   union {
   (type???) CRefCount;
   unsigned long Padding1;
   };
   unsigned long Padding2;
   (type???) CMcpxCore;
   union {
   (type???) public: static void * __cdecl CMcpxGPDspManager::operator new(unsigned int);
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   unsigned long Padding8;
   };
   unsigned long Padding9;
   unsigned long Padding10;
   unsigned long Padding11;
   unsigned long Padding12;
   unsigned long Padding13;
   unsigned long Padding14;
   unsigned long Padding15;
   unsigned long Padding16;
   unsigned long Padding17;
   unsigned long Padding18;
   unsigned long Padding19;
   unsigned long Padding20;
   unsigned long Padding21;
   unsigned long Padding22;
   unsigned long Padding23;
   unsigned long Padding24;
   unsigned long Padding25;
   unsigned long Padding26;
   unsigned long Padding27;
   unsigned long Padding28;
   unsigned long Padding29;
   unsigned long Padding30;
   unsigned long Padding31;
   unsigned long Padding32;
   unsigned long Padding33;
   unsigned long Padding34;
   unsigned long Padding35;
   unsigned long Padding36;
   unsigned long Padding37;
   unsigned long Padding38;
   unsigned long Padding39;
   unsigned long Padding40;
   unsigned long Padding41;
   unsigned long Padding42;
   unsigned long Padding43;
   unsigned long Padding44;
   unsigned long Padding45;
   unsigned long Padding46;
   unsigned long Padding47;
   unsigned long Padding48;
   unsigned long Padding49;
   unsigned long Padding50;
   unsigned long Padding51;
   unsigned long Padding52;
   unsigned long Padding53;
   unsigned long Padding54;
   unsigned long Padding55;
   unsigned long Padding56;
   unsigned long Padding57;
   unsigned long Padding58;
   unsigned long Padding59;
   unsigned long Padding60;
   unsigned long Padding61;
   unsigned long Padding62;
   unsigned long Padding63;
   unsigned long Padding64;
   unsigned long Padding65;
   unsigned long Padding66;
   unsigned long Padding67;
   unsigned long Padding68;
   unsigned long Padding69;
   unsigned long Padding70;
   unsigned long Padding71;
   unsigned long Padding72;
   unsigned long Padding73;
   unsigned long Padding74;
   unsigned long Padding75;
   short m_wFree2dVoiceCount;
   short m_wFree3dVoiceCount;
   _LIST_ENTRY m_lst3dVoices;
   class CMcpxBufferSgeHeap m_SgeHeap;
   _DS3DLISTENER m_3dListener;
   _DSI3DL2LISTENER m_I3dl2Listener;
   unsigned long m_dw3dParameterMask;
   D3DXVECTOR3 m_v3dNormalizedOrientation;
   unsigned long m_dwState;
   volatile unsigned long m_dwVoiceMapLock;
   class CMcpxVoiceClient * m_apVoiceMap[256];
   _LIST_ENTRY m_alstActiveVoices[3];
   _LIST_ENTRY m_lstPendingInactiveVoices;
   R_INTR m_arInterruptStatus[2];
   _KDPC m_dpcInterrupt;
   _KINTERRUPT m_Interrupt;
   _KTIMER m_tmrDeferredCommandsHigh;
   _KDPC m_dpcDeferredCommandsHigh;
   _LIST_ENTRY m_lstDeferredCommandsHigh;
   MCPX_DEFERRED_COMMAND * m_apDeferredCommandsLow[512];
   _HAL_SHUTDOWN_REGISTRATION m_HalShutdownData;
   union {
   (type???) CMcpxAPU;
   (type???) public: __thiscall CMcpxAPU::CMcpxAPU(void);
   (type???) public: virtual __thiscall CMcpxAPU::~CMcpxAPU(void);
   (type???) public: long __thiscall CMcpxAPU::Initialize(class CDirectSoundSettings *);
   (type???) GetCaps;
   (type???) public: long __thiscall CMcpxAPU::CreateBuffer(class CDirectSoundBufferSettings *,struct VADBUFFEREVENTSINK const &,void *,class CMcpxBuffer * *);
   (type???) CreateStream;
   (type???) Set3dParameters;
   (type???) Set3dDistanceFactor;
   (type???) Set3dDopplerFactor;
   (type???) Set3dRolloffFactor;
   (type???) Set3dOrientation;
   (type???) Set3dPosition;
   (type???) Set3dVelocity;
   (type???) SetI3DL2Listener;
   (type???) CommitDeferred3dSettings;
   (type???) DownloadEffectsImage;
   (type???) SetEffectData;
   (type???) GetEffectData;
   (type???) CommitEffectData;
   (type???) GetFormat;
   (type???) public: long __thiscall CMcpxAPU::SetHRTFHeadroom(unsigned long);
   (type???) public: long __thiscall CMcpxAPU::SetMixBinHeadroom(unsigned long,unsigned long);
   (type???) SetSpeakerConfig;
   (type???) public: long __thiscall CMcpxAPU::AllocateVoices(class CMcpxVoiceClient *);
   (type???) public: void __thiscall CMcpxAPU::FreeVoices(class CMcpxVoiceClient *);
   (type???) public: void __thiscall CMcpxAPU::GetAntecedentVoice(class CMcpxVoiceClient *,unsigned long *,class CMcpxVoiceClient * *);
   (type???) public: void __thiscall CMcpxAPU::ActivateVoice(class CMcpxVoiceClient *,class CMcpxVoiceClient *,unsigned long);
   (type???) public: void __thiscall CMcpxAPU::BlockIdleHandler(void);
   (type???) public: void __thiscall CMcpxAPU::UnblockIdleHandler(void);
   (type???) public: int __thiscall CMcpxAPU::ScheduleDeferredCommand(struct MCPX_DEFERRED_COMMAND *);
   (type???) public: void __thiscall CMcpxAPU::RemoveDeferredCommand(struct MCPX_DEFERRED_COMMAND *);
   (type???) DoWork;
   (type???) AllocateVoice;
   (type???) FreeVoice;
   (type???) protected: void __thiscall CMcpxAPU::Terminate(void);
   (type???) protected: int __thiscall CMcpxAPU::ServiceApuInterrupt(void);
   (type???) protected: void __thiscall CMcpxAPU::ServiceApuInterruptDpc(void);
   (type???) protected: void __thiscall CMcpxAPU::ServiceVoiceInterrupt(void);
   (type???) protected: void __thiscall CMcpxAPU::WaitForMagicWrite(void);
   (type???) protected: void __thiscall CMcpxAPU::HandleFETrap(void);
   (type???) protected: void __thiscall CMcpxAPU::HandleDeltaPanic(void);
   (type???) protected: void __thiscall CMcpxAPU::HandleSoftwareMethod(unsigned long,unsigned long);
   (type???) protected: void __thiscall CMcpxAPU::HandleIdleVoice(unsigned long);
   (type???) protected: void __thiscall CMcpxAPU::RemoveIdleVoice(class CMcpxVoiceClient *);
   (type???) protected: void __thiscall CMcpxAPU::RemoveIdleVoice(unsigned long);
   (type???) Commit3dSettings;
   (type???) protected: int __thiscall CMcpxAPU::ScheduleDeferredCommandHigh(struct MCPX_DEFERRED_COMMAND *);
   (type???) protected: int __thiscall CMcpxAPU::ScheduleDeferredCommandLow(struct MCPX_DEFERRED_COMMAND *);
   (type???) protected: void __thiscall CMcpxAPU::ServiceDeferredCommandsHigh(void);
   (type???) ServiceDeferredCommandsLow;
   (type???) protected: void __thiscall CMcpxAPU::RemoveDeferredCommandHigh(struct MCPX_DEFERRED_COMMAND *);
   (type???) protected: void __thiscall CMcpxAPU::RemoveDeferredCommandLow(struct MCPX_DEFERRED_COMMAND *);
   (type???) private: static unsigned char __stdcall CMcpxAPU::ApuInterruptServiceRoutine(struct _KINTERRUPT *,void *);
   (type???) private: static void __stdcall CMcpxAPU::ApuInterruptDpcRoutine(struct _KDPC *,void *,void *,void *);
   (type???) private: static unsigned char __stdcall CMcpxAPU::SynchronizeWithIsr(void *);
   (type???) private: static void __stdcall CMcpxAPU::DeferredCommandDpcRoutine(struct _KDPC *,void *,void *,void *);
   (type???) private: static void __stdcall CMcpxAPU::ApuShutdownNotifier(struct _HAL_SHUTDOWN_REGISTRATION *);
   (type???) __local_vftable_ctor_closure;
   (type???) __vecDelDtor;
   };
} CMcpxAPU;

typedef struct CDirectSoundSettings
{
   union {
   (type???) CRefCount;
   (type???) public: static void * __cdecl CMcpxGPDspManager::operator new(unsigned int);
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   unsigned long Padding5;
   };
   unsigned long Padding6;
   unsigned long m_dwSpeakerConfig;
   _DSEFFECTIMAGELOC m_EffectLocations;
   union {
   (type???) CDirectSoundSettings;
   (type???) public: __thiscall CDirectSoundSettings::CDirectSoundSettings(void);
   (type???) public: virtual __thiscall CDirectSoundSettings::~CDirectSoundSettings(void);
   (type???) public: void __thiscall CDirectSoundSettings::SetEffectImageLocations(struct _DSEFFECTIMAGELOC const *);
   (type???) __local_vftable_ctor_closure;
   (type???) __vecDelDtor;
   };
} CDirectSoundSettings;

typedef struct CDirectSound
{
   (type???) IDirectSound;
   union {
   (type???) CRefCount;
   (type???) public: static void * __cdecl CMcpxGPDspManager::operator new(unsigned int);
   (type???) operator new[];
   (type???) public: static void __cdecl CAc97Channel::operator delete(void *);
   (type???) operator delete[];
   class CDirectSound * m_pDirectSound;
   };
   unsigned long Padding7;
   class CDirectSoundSettings * m_pSettings;
   class CMcpxAPU * m_pDevice;
   class CList<CDirectSoundVoice> m_lstVoices;
   IDirectSoundBuffer * m_apKeepAliveBuffers[1];
   union {
   (type???) CDirectSound;
   (type???) public: __thiscall CDirectSound::CDirectSound(void);
   (type???) public: virtual __thiscall CDirectSound::~CDirectSound(void);
   (type???) public: long __stdcall CDirectSound::Initialize(void);
   (type???) public: virtual unsigned long __stdcall CDirectSoundBuffer::AddRef(void);
   (type???) public: virtual unsigned long __stdcall CDirectSound::Release(void);
   (type???) GetCaps;
   (type???) public: long __stdcall CDirectSound::CreateSoundBuffer(struct _DSBUFFERDESC const *,struct IDirectSoundBuffer * *,struct IUnknown *);
   (type???) CreateSoundStream;
   (type???) GetSpeakerConfig;
   (type???) DownloadEffectsImage;
   (type???) GetEffectData;
   (type???) SetEffectData;
   (type???) CommitEffectData;
   (type???) EnableHeadphones;
   (type???) SetMixBinHeadroom;
   (type???) SetAllParameters;
   (type???) SetDistanceFactor;
   (type???) SetDopplerFactor;
   (type???) SetOrientation;
   (type???) SetPosition;
   (type???) SetRolloffFactor;
   (type???) SetVelocity;
   (type???) SetI3DL2Listener;
   (type???) CommitDeferredSettings;
   (type???) GetTime;
   (type???) DoWork;
   (type???) __local_vftable_ctor_closure;
   (type???) __vecDelDtor;
   };
} CDirectSound;

typedef struct XGRAPHICS::XGInternalSwizzler<unsigned long>
{
   union {
   (type???) public: static void __stdcall XGRAPHICS::XGInternalSwizzler<unsigned long>::Swizzle1x1Column(struct XGRAPHICS::XGINTERNALSWIZZLE *);
   (type???) Unswizzle1x1Column;
   (type???) public: static void __stdcall XGRAPHICS::XGInternalSwizzler<unsigned long>::Swizzle2x1(struct XGRAPHICS::XGINTERNALSWIZZLE *);
   (type???) Unswizzle2x1;
   };
} XGRAPHICS::XGInternalSwizzler<unsigned long>;

typedef struct XGRAPHICS::XGInternalSwizzler<unsigned char>
{
   union {
   (type???) public: static void __stdcall XGRAPHICS::XGInternalSwizzler<unsigned char>::Swizzle1x1Column(struct XGRAPHICS::XGINTERNALSWIZZLE *);
   (type???) Unswizzle1x1Column;
   (type???) Swizzle2x1;
   (type???) Unswizzle2x1;
   };
} XGRAPHICS::XGInternalSwizzler<unsigned char>;

typedef struct XGRAPHICS::XGInternalSwizzler<__int64>
{
   union {
   (type???) Swizzle1x1Column;
   (type???) Unswizzle1x1Column;
   (type???) public: static void __stdcall XGRAPHICS::XGInternalSwizzler<__int64>::Swizzle2x1(struct XGRAPHICS::XGINTERNALSWIZZLE *);
   (type???) Unswizzle2x1;
   };
} XGRAPHICS::XGInternalSwizzler<__int64>;

typedef struct XGRAPHICS::XGINTERNALSWIZZLE
{
   const void * pSource;
   unsigned long Pitch;
   unsigned long SLeft;
   unsigned long STop;
   unsigned long RWidth;
   unsigned long RHeight;
   void * pDest;
   unsigned long Width;
   unsigned long Height;
   unsigned long DTop;
   unsigned long DLeft;
   int xOff;
   int yOff;
   int uWidth;
   int uHeight;
   int bpp;
   class Swizzler swiz;
   unsigned long mask[2];
   (type???) XGINTERNALSWIZZLE;
} XGRAPHICS::XGINTERNALSWIZZLE;

typedef struct XGRAPHICS::XGInternalSwizzler<unsigned short>
{
   union {
   (type???) public: static void __stdcall XGRAPHICS::XGInternalSwizzler<unsigned short>::Swizzle1x1Column(struct XGRAPHICS::XGINTERNALSWIZZLE *);
   (type???) Unswizzle1x1Column;
   (type???) public: static void __stdcall XGRAPHICS::XGInternalSwizzler<unsigned short>::Swizzle2x1(struct XGRAPHICS::XGINTERNALSWIZZLE *);
   (type???) Unswizzle2x1;
   };
} XGRAPHICS::XGInternalSwizzler<unsigned short>;

typedef struct _XGPOINT3D
{
   unsigned long u;
   unsigned long v;
   unsigned long w;
} XGPOINT3D;

typedef struct D3DK::PERFFIXEDPOINT
{
   union {
   (type???) PERFFIXEDPOINT;
   unsigned long IntPart;
   };
   unsigned long DecPart;
} D3DK::PERFFIXEDPOINT;

typedef struct D3DK::__unnamed
{
   unsigned long State;
   const char * Name;
} D3DK::__unnamed;

typedef struct D3DK::D3DPERF_PROFDATA
{
   int Sampling;
} D3DK::D3DPERF_PROFDATA;

typedef struct D3DK::_userstateentry
{
   int Enum;
   unsigned long Value;
} D3DK::_userstateentry;

typedef struct D3DK::_regval
{
   short a;
   short r;
   short g;
   short b;
} D3DK::_regval;

typedef struct D3DK::_capture
{
   unsigned long dwPreColor;
   unsigned long dwPreDepth;
   unsigned long dwCombinerCount;
   D3DK::_regval v0[9];
   D3DK::_regval v1[9];
   D3DK::_regval t0[9];
   D3DK::_regval t1[9];
   D3DK::_regval t2[9];
   D3DK::_regval t3[9];
   D3DK::_regval c0[9];
   D3DK::_regval c1[9];
   D3DK::_regval r0[9];
   D3DK::_regval r1[9];
   D3DK::_regval fog;
   D3DK::_regval sum;
   D3DK::_regval prod;
   unsigned long dwPostColor;
   unsigned long dwPostDepth;
} D3DK::_capture;

typedef struct D3DK::DebugSnapshot
{
   union {
   (type???) public: void __thiscall D3DK::DebugSnapshot::BeginSnapshot(unsigned long,unsigned long);
   (type???) public: void __thiscall D3DK::DebugSnapshot::GetColorAndDepth(unsigned long *,unsigned long *);
   (type???) public: void __thiscall D3DK::DebugSnapshot::SetColorAndDepth(unsigned long,unsigned long);
   (type???) public: void __thiscall D3DK::DebugSnapshot::EndSnapshot(void);
   (type???) public: long __thiscall D3DK::DebugSnapshot::HandleDrawVertices(void);
   (type???) public: long __thiscall D3DK::DebugSnapshot::DrawVertices(void);
   (type???) public: void __thiscall D3DK::DebugSnapshot::GetStageData(unsigned int);
   (type???) public: void __thiscall D3DK::DebugSnapshot::GetRegister(unsigned long,unsigned int);
   (type???) public: void __thiscall D3DK::DebugSnapshot::SaveUserState(void);
   (type???) public: void __thiscall D3DK::DebugSnapshot::RestoreUserState(void);
   (type???) public: void __thiscall D3DK::DebugSnapshot::SetPassThroughState(void);
   (type???) WriteCapture;
   (type???) public: void __thiscall D3DK::DebugSnapshot::DumpImage(void);
   (type???) public: void __thiscall D3DK::DebugSnapshot::WriteColor24(unsigned long);
   unsigned long DrawVertType;
   };
   int PrimitiveType;
   int VertexCount;
   const void * pIndexData;
   const void * pVertexStreamZeroData;
   int VertexStreamZeroStride;
   int StartVertex;
   unsigned long dwCaptureCount;
   unsigned long dwX;
   unsigned long dwY;
   D3DSurface * pBackBuffer;
   D3DSurface * pDepthBuffer;
   D3DK::_capture cpt;
   unsigned long dwXScale;
   unsigned long dwYScale;
   D3DK::_userstateentry UserState[50];
   unsigned long UserStateCount;
   unsigned long dwScissorRectCount;
   _D3DRECT ScissorRects[8];
   int bScissorExclusive;
} D3DK::DebugSnapshot;

typedef struct D3DK::PrivateDataNode
{
   D3DK::PrivateDataNode * pNext;
   void * pObject;
   _GUID guid;
   unsigned long size;
   unsigned long flags;
   union {
   IUnknown * pUnknown;
   unsigned char Data[1];
   };
} D3DK::PrivateDataNode;

typedef struct D3DK::AntiAliasedSavedState
{
   D3DSurface * pRenderTarget;
   D3DSurface * pZBuffer;
   D3DBaseTexture * pTexture;
   D3DK::PixelShader * pPixelShader;
   unsigned long VertexShaderHandle;
   _D3DVIEWPORT8 Viewport;
   unsigned long Stage1ColorOp;
   unsigned long PSTextureModes;
   unsigned long RenderState[16];
   unsigned long TextureState[11];
   unsigned long PixelShaderState[57];
   unsigned long VertexShaders[48];
   D3DTexture SrcTexture;
} D3DK::AntiAliasedSavedState;

typedef struct D3DK::D3DK::CMiniport
{
   void * m_RegisterBase;
   unsigned long m_PresentationInterval;
   unsigned long m_SurfacePitch;
   unsigned long m_DisplayMode;
   unsigned long m_Format;
   void * m_InstMem;
   _KINTERRUPT m_InterruptObject;
   _KDPC m_Dpc;
   int m_InterruptsEnabled;
   D3DK::D3DK::CMiniport::GENERALINFO m_GenInfo;
   D3DK::D3DK::CMiniport::DACINFO m_DacInfo;
   D3DK::D3DK::CMiniport::HALINFO m_HalInfo;
   D3DK::D3DK::CMiniport::VIDEOMODETIMING m_VideoModeTiming;
   unsigned long m_VideoModeDepth;
   unsigned long m_FreeInstAddr;
   _HAL_SHUTDOWN_REGISTRATION m_ShutdownRegistration;
   D3DK::D3DK::CMiniport::VBLANKFLIPS m_VBlankFlips[5];
   unsigned long m_VBlankFlipNext;
   unsigned long m_VBlankQueueNext;
   void * m_pVerticalBlankCallback;
   _KEVENT m_VerticalBlankEvent;
   _KEVENT m_BusyBlockEvent;
   unsigned long m_CurrentAvInfo;
   int m_FirstFlip;
   volatile unsigned long m_VBlankFlipCount;
   _D3DGAMMARAMP m_GammaRamp[2];
   int m_GammaUpdated[2];
   unsigned long m_GammaCurrentIndex;
   volatile unsigned long m_VBlankCount;
   unsigned long m_OverlayVBlank;
   unsigned long m_DebugRegister[11];
   unsigned long m_PusherGetRunSize;
   union {
   (type???) InitHardware;
   (type???) GetPresentFlagsFromAvInfo;
   (type???) GetDisplayCapabilities;
   (type???) SetVideoMode;
   (type???) InitDMAChannel;
   (type???) BindToChannel;
   (type???) CreateGrObject;
   (type???) CreateCtxDmaObject;
   (type???) SetDmaRange;
   (type???) CreateTile;
   (type???) DestroyTile;
   (type???) ShutdownEngines;
   (type???) DacProgramGammaRamp;
   (type???) IsFlipPending;
   (type???) DacProgramVideoStart;
   (type???) DisableInterrupts;
   (type???) EnableInterrupts;
   (type???) GetRefreshRate;
   (type???) Isr;
   (type???) Dpc;
   (type???) ShutdownNotification;
   (type???) TilingUpdateIdle;
   (type???) FixupPushBuffer;
   (type???) InitEngines;
   (type???) LoadEngines;
   (type???) MapRegisters;
   (type???) GetGeneralInfo;
   (type???) InitGammaRamp;
   (type???) SoftwareMethod;
   (type???) SetupPaletteAndGamma;
   (type???) ReserveInstMem;
   (type???) GetAddressInfo;
   (type???) ServiceGrInterrupt;
   (type???) VBlank;
   (type???) ServiceFifoInterrupt;
   (type???) ServiceMediaPortInterrupt;
   (type???) ServiceVideoInterrupt;
   (type???) HalMcControlInit;
   (type???) HalFbControlInit;
   (type???) HalVideoControlInit;
   (type???) HalMpControlInit;
   (type???) HalGrControlInit;
   (type???) HalGrControlLoad;
   (type???) HalGrIdle;
   (type???) HalGrLoadChannelContext;
   (type???) HalGrUnloadChannelContext;
   (type???) HalGrInitObjectContext;
   (type???) HalGrInit3d;
   (type???) HalFifoControlInit;
   (type???) HalFifoControlLoad;
   (type???) HalFifoContextSwitch;
   (type???) HalFifoAllocDMA;
   (type???) HalFifoHashAdd;
   (type???) HalDacControlInit;
   (type???) HalDacLoad;
   (type???) HalDacUnload;
   (type???) HalDacProgramMClk;
   (type???) HalDacProgramNVClk;
   (type???) HalDacProgramPClk;
   (type???) DumpClocks;
   (type???) GrDone;
   (type???) TmrDelay;
   (type???) UnlockCRTC;
   (type???) RestoreCRTCLock;
   (type???) ReadCRTCLock;
   (type???) IsOddField;
   };
} D3DK::D3DK::CMiniport;

typedef struct D3DK::D3DK::CMiniport::PUSHBUFFERFIXUPINFO
{
   unsigned long * pFixup;
   unsigned char * pStart;
   unsigned long ReturnOffset;
   unsigned long * ReturnAddress;
} D3DK::D3DK::CMiniport::PUSHBUFFERFIXUPINFO;

typedef struct D3DK::D3DK::CMiniport::VBLANKFLIPS
{
   int Pending;
   unsigned long Offset;
} D3DK::D3DK::CMiniport::VBLANKFLIPS;

typedef struct D3DK::D3DK::CMiniport::OBJECTINFO
{
   unsigned long Handle;
   short SubChannel;
   short Engine;
   unsigned long ClassNum;
   unsigned long Instance;
   (type???) Init;
} D3DK::D3DK::CMiniport::OBJECTINFO;

typedef struct D3DK::D3DK::CMiniport::HW_HASHENTRY
{
   unsigned long ht_ObjectHandle;
   unsigned long ht_Context;
} D3DK::D3DK::CMiniport::HW_HASHENTRY;

typedef struct D3DK::D3DK::CMiniport::VIDEOMODETIMING
{
   unsigned long HorizontalVisible;
   unsigned long VerticalVisible;
   unsigned long Refresh;
   unsigned long HorizontalTotal;
   unsigned long HorizontalBlankStart;
   unsigned long HorizontalRetraceStart;
   unsigned long HorizontalRetraceEnd;
   unsigned long HorizontalBlankEnd;
   unsigned long VerticalTotal;
   unsigned long VerticalBlankStart;
   unsigned long VerticalRetraceStart;
   unsigned long VerticalRetraceEnd;
   unsigned long VerticalBlankEnd;
   unsigned long PixelClock;
   unsigned long HorizontalSyncPolarity;
   unsigned long VerticalSyncPolarity;
} D3DK::D3DK::CMiniport::VIDEOMODETIMING;

typedef struct D3DK::D3DK::CMiniport::HALINFO
{
   long FifoChID;
   unsigned long FifoMode;
   int FifoInUse;
   unsigned long FifoInstance;
   unsigned long FifoAllocCount;
   long FifoCacheDepth;
   unsigned long FifoObjectCount;
   unsigned long FifoIntrEn0;
   unsigned long FifoRetryCount;
   unsigned long FifoUserBase;
   unsigned long FifoContextAddr1;
   unsigned long FifoContextAddr2;
   unsigned long HashTableAddr;
   unsigned long GrChID;
   unsigned long GrCtxTable[2];
   unsigned long GrCtxTableBase;
   unsigned long GrCurrentObjects3d[2];
   unsigned long FbSave0;
   unsigned long FbSave1;
   unsigned long McSave;
   unsigned long McSaveIntrEn0;
} D3DK::D3DK::CMiniport::HALINFO;

typedef struct D3DK::D3DK::CMiniport::DACINFO
{
   unsigned long MClk;
   unsigned long VClk;
   unsigned long NVClk;
   unsigned long MPllM;
   unsigned long MPllN;
   unsigned long MPllO;
   unsigned long MPllP;
   unsigned long VPllM;
   unsigned long VPllN;
   unsigned long VPllO;
   unsigned long VPllP;
   unsigned long NVPllM;
   unsigned long NVPllN;
   unsigned long NVPllO;
   unsigned long NVPllP;
} D3DK::D3DK::CMiniport::DACINFO;

typedef struct D3DK::D3DK::CMiniport::GENERALINFO
{
   unsigned long ChipId;
   unsigned long VideoRamSize;
   unsigned long VideoRamType;
   unsigned long ChipIntrEn0;
   unsigned long MpVIPSlavePresent;
   unsigned long CrystalFreq;
   unsigned long MaskRevision;
} D3DK::D3DK::CMiniport::GENERALINFO;

typedef struct _FILTER_TABLES
{
   unsigned long BandpassChromaTable[3] BandpassChromaTable[5];
   unsigned long Padding1;
   unsigned long Padding2;
   unsigned long Padding3;
   unsigned long Padding4;
   unsigned long Padding5;
   unsigned long Padding6;
   unsigned long Padding7;
   unsigned long Padding8;
   unsigned long Padding9;
   unsigned long Padding10;
   unsigned long BasebandChromaTable[2] BasebandChromaTable[10];
   unsigned long Padding12;
   unsigned long Padding13;
   unsigned long Padding14;
   unsigned long Padding15;
   unsigned long Padding16;
   unsigned long Padding17;
   unsigned long Padding18;
   unsigned long Padding19;
   unsigned long Padding20;
   unsigned long Padding21;
   unsigned long ComponentChromaTable[8] ComponentChromaTable[10];
   unsigned long Padding23;
   unsigned long Padding24;
   unsigned long Padding25;
   unsigned long Padding26;
   unsigned long Padding27;
   unsigned long Padding28;
   unsigned long Padding29;
   unsigned long Padding30;
   unsigned long Padding31;
   unsigned long Padding32;
   unsigned long Padding33;
   unsigned long Padding34;
   unsigned long Padding35;
   unsigned long Padding36;
   unsigned long Padding37;
   unsigned long Padding38;
   unsigned long Padding39;
   unsigned long Padding40;
   unsigned long Padding41;
   unsigned long Padding42;
   unsigned long Padding43;
   unsigned long Padding44;
   unsigned long Padding45;
   unsigned long Padding46;
   unsigned long Padding47;
   unsigned long Padding48;
   unsigned long Padding49;
   unsigned long Padding50;
   unsigned long Padding51;
   unsigned long Padding52;
   unsigned long Padding53;
   unsigned long Padding54;
   unsigned long Padding55;
   unsigned long Padding56;
   unsigned long Padding57;
   unsigned long Padding58;
   unsigned long Padding59;
   unsigned long Padding60;
   unsigned long Padding61;
   unsigned long Padding62;
   unsigned long Padding63;
   unsigned long Padding64;
   unsigned long Padding65;
   unsigned long Padding66;
   unsigned long Padding67;
   unsigned long Padding68;
   unsigned long Padding69;
   unsigned long Padding70;
   unsigned long Padding71;
   unsigned long Padding72;
   unsigned long Padding73;
   unsigned long Padding74;
   unsigned long Padding75;
   unsigned long Padding76;
   unsigned long Padding77;
   unsigned long Padding78;
   unsigned long Padding79;
   unsigned long Padding80;
   unsigned long Padding81;
   unsigned long Padding82;
   unsigned long Padding83;
   unsigned long Padding84;
   unsigned long Padding85;
   unsigned long Padding86;
   unsigned long Padding87;
   unsigned long Padding88;
   unsigned long Padding89;
   unsigned long Padding90;
   unsigned long Padding91;
   unsigned long Padding92;
   unsigned long ComponentLumaTable[8] ComponentLumaTable[16];
   unsigned long Padding94;
   unsigned long Padding95;
   unsigned long Padding96;
   unsigned long Padding97;
   unsigned long Padding98;
   unsigned long Padding99;
   unsigned long Padding100;
   unsigned long Padding101;
   unsigned long Padding102;
   unsigned long Padding103;
   unsigned long Padding104;
   unsigned long Padding105;
   unsigned long Padding106;
   unsigned long Padding107;
   unsigned long Padding108;
   unsigned long Padding109;
   unsigned long Padding110;
   unsigned long Padding111;
   unsigned long Padding112;
   unsigned long Padding113;
   unsigned long Padding114;
   unsigned long Padding115;
   unsigned long Padding116;
   unsigned long Padding117;
   unsigned long Padding118;
   unsigned long Padding119;
   unsigned long Padding120;
   unsigned long Padding121;
   unsigned long Padding122;
   unsigned long Padding123;
   unsigned long Padding124;
   unsigned long Padding125;
   unsigned long Padding126;
   unsigned long Padding127;
   unsigned long Padding128;
   unsigned long Padding129;
   unsigned long Padding130;
   unsigned long Padding131;
   unsigned long Padding132;
   unsigned long Padding133;
   unsigned long Padding134;
   unsigned long Padding135;
   unsigned long Padding136;
   unsigned long Padding137;
   unsigned long Padding138;
   unsigned long Padding139;
   unsigned long Padding140;
   unsigned long Padding141;
   unsigned long Padding142;
   unsigned long Padding143;
   unsigned long Padding144;
   unsigned long Padding145;
   unsigned long Padding146;
   unsigned long Padding147;
   unsigned long Padding148;
   unsigned long Padding149;
   unsigned long Padding150;
   unsigned long Padding151;
   unsigned long Padding152;
   unsigned long Padding153;
   unsigned long Padding154;
   unsigned long Padding155;
   unsigned long Padding156;
   unsigned long Padding157;
   unsigned long Padding158;
   unsigned long Padding159;
   unsigned long Padding160;
   unsigned long Padding161;
   unsigned long Padding162;
   unsigned long Padding163;
   unsigned long Padding164;
   unsigned long Padding165;
   unsigned long Padding166;
   unsigned long Padding167;
   unsigned long Padding168;
   unsigned long Padding169;
   unsigned long Padding170;
   unsigned long Padding171;
   unsigned long Padding172;
   unsigned long Padding173;
   unsigned long Padding174;
   unsigned long Padding175;
   unsigned long Padding176;
   unsigned long Padding177;
   unsigned long Padding178;
   unsigned long Padding179;
   unsigned long Padding180;
   unsigned long Padding181;
   unsigned long Padding182;
   unsigned long Padding183;
   unsigned long Padding184;
   unsigned long Padding185;
   unsigned long Padding186;
   unsigned long Padding187;
   unsigned long Padding188;
   unsigned long Padding189;
   unsigned long Padding190;
   unsigned long Padding191;
   unsigned long Padding192;
   unsigned long Padding193;
   unsigned long Padding194;
   unsigned long Padding195;
   unsigned long Padding196;
   unsigned long Padding197;
   unsigned long Padding198;
   unsigned long Padding199;
   unsigned long Padding200;
   unsigned long Padding201;
   unsigned long Padding202;
   unsigned long Padding203;
   unsigned long Padding204;
   unsigned long Padding205;
   unsigned long CompositeLumaTable[16] CompositeLumaTable[32];
} FILTER_TABLES;

typedef struct _TheVerts
{
   float x;
   float y;
   float z;
   float w;
   float u;
   float v;
} TheVerts;

typedef struct SinCosPair
{
   float fCos;
   float fSin;
} SinCosPair;

typedef struct _D3DPERF
{
   __int64 m_TSCLastResetVal;
   __int64 m_TSCLastPresentVal;
   _D3DWAITINFO m_FrameTimeMin;
   _D3DWAITINFO m_FrameTimeMax;
   unsigned long m_BreakCount;
   int m_Breakperfctr;
   unsigned long * m_pPutLocationAtReset;
   unsigned long Padding7;
   __int64 m_PushBufferEndDwordsSkipped;
   unsigned long m_FrameRateIntervalTime;
   unsigned long m_dwDumpFPSInfoMask;
   void * m_pfnDumpFrameRateInfoHandler;
   unsigned long m_DumpWaitCycleTimesThreshold;
   void * m_pfnCycleThresholdHandler;
   int m_SetRenderStateOverridesOnReset;
   unsigned long m_ProfileSamples;
   unsigned long Padding16;
   __int64 m_TSCProfileStartTime;
   short m_ProfileData[105000];
   unsigned long m_ProfileBusyCounts[3];
   _D3DOVERRIDERENDERSTATE m_RenderStateOverrides[144];
   _D3DWAITINFO m_PerformanceCounters[30];
   unsigned long m_APICounters[235];
   unsigned long m_RenderStateCounters[144];
   unsigned long m_TextureStateCounters[32];
} D3DPERF;

typedef struct _D3DOVERRIDERENDERSTATE
{
   int Override;
   unsigned long Value;
} D3DOVERRIDERENDERSTATE;

typedef struct _D3DWAITINFO
{
   unsigned long Count;
   unsigned long Padding1;
   __int64 Cycles;
} D3DWAITINFO;

typedef struct VBlob::render::__l2::_decalvert
{
   _D3DVECTOR p;
   float u;
   float v;
} VBlob::render::__l2::_decalvert;

typedef struct VBlobConstantVertex
{
   _D3DVECTOR unit_sphere_normal;
} VBlobConstantVertex;

typedef struct VBlobChangingVertex
{
   D3DVECTOR4 normal;
} VBlobChangingVertex;

typedef struct BumpStream
{
   float u;
   float v;
   _D3DVECTOR s;
   _D3DVECTOR t;
   _D3DVECTOR n;
} BumpStream;

typedef struct PhongStream
{
   _D3DVECTOR s;
   _D3DVECTOR t;
   _D3DVECTOR n;
} PhongStream;

typedef struct PosAnimSeq
{
   char posIds[90];
} PosAnimSeq;

typedef struct RotAnimSeq
{
   char quatIds[90];
} RotAnimSeq;

typedef struct xbl_vertex
{
   float x;
   float y;
   float z;
   float u0;
   float v0;
} xbl_vertex;

typedef struct xbt_vertex
{
   float x;
   float y;
   float z;
} xbt_vertex;

typedef struct GreenFogVertexBuffer
{
   _D3DVECTOR pos;
   float tu0;
   float tv0;
   float tu1;
   float tv1;
} GreenFogVertexBuffer;

typedef struct BaseStream
{
   _D3DVECTOR p;
} BaseStream;

typedef struct XGBuffer
{
   unsigned long refCount;
   void * pData;
   unsigned long size;
   union {
   (type???) AddRef;
   (type???) Release;
   (type???) GetBufferPointer;
   (type???) GetBufferSize;
   };
} XGBuffer;

typedef union __m64
{
   union {
   __int64 m64_u64;
   float m64_f32[2];
   char m64_i8[8];
   short m64_i16[4];
   int m64_i32[2];
   __int64 m64_i64;
   unsigned char m64_u8[8];
   short m64_u16[4];
   int m64_u32[2];
   };
} _m64;

typedef struct Swizzler
{
   unsigned long m_Width;
   unsigned long m_Height;
   unsigned long m_Depth;
   unsigned long m_MaskU;
   unsigned long m_MaskV;
   unsigned long m_MaskW;
   unsigned long m_u;
   unsigned long m_v;
   unsigned long m_w;
   union {
   (type???) Swizzler;
   (type???) public: __thiscall Swizzler::Swizzler(void);
   (type???) public: void __thiscall Swizzler::Init(unsigned long,unsigned long,unsigned long);
   (type???) public: unsigned long __thiscall Swizzler::SwizzleU(unsigned long);
   (type???) public: unsigned long __thiscall Swizzler::SwizzleV(unsigned long);
   (type???) SwizzleW;
   (type???) Swizzle;
   (type???) UnswizzleU;
   (type???) UnswizzleV;
   (type???) UnswizzleW;
   (type???) SetU;
   (type???) SetV;
   (type???) SetW;
   (type???) AddU;
   (type???) AddV;
   (type???) AddW;
   (type???) SubU;
   (type???) SubV;
   (type???) SubW;
   (type???) IncU;
   (type???) IncV;
   (type???) IncW;
   (type???) DecU;
   (type???) DecV;
   (type???) DecW;
   (type???) Get2D;
   (type???) Get3D;
   };
} Swizzler;

typedef struct __m128
{
   float m128_f32[4];
} _m128;

typedef struct SphereInst
{
   short tx;
   short ty;
   short tz;
   char idVersion;
   char idPosAnim;
   char idRotAnim;
   unsigned char Padding6;
   unsigned char Padding7;
   unsigned char Padding8;
   float fRad;
} SphereInst;

typedef struct SurfOfRevVers
{
   SurfOfRevPt pts[19];
   float ax;
   float ay;
   float az;
   float px;
   float py;
   float pz;
   char nSegs;
   char nPts;
} SurfOfRevVers;

typedef struct CylinderInst
{
   char idQuat;
   unsigned char Padding1;
   short tx;
   short ty;
   short tz;
   char idVersion;
   char idPosAnim;
   char idRotAnim;
   unsigned char Padding8;
   float fRad;
   float fHalfHeight;
} CylinderInst;

typedef struct SurfOfRevInst
{
   char idQuat;
   unsigned char Padding1;
   short tx;
   short ty;
   short tz;
   char idVersion;
   char idPosAnim;
   char idRotAnim;
} SurfOfRevInst;

typedef struct BoxInst
{
   char idQuat;
   unsigned char Padding1;
   short tx;
   short ty;
   short tz;
   char idVersion;
   char idPosAnim;
   char idRotAnim;
   unsigned char Padding8;
   float fLen;
   float fHeight;
   float fWidth;
} BoxInst;

typedef struct SphereVers
{
   char nSegs;
} SphereVers;

typedef struct ConeVers
{
   float fRad1;
   float fRad2;
   float fHeight;
   char nHeightSeg;
   char nSides;
} ConeVers;

typedef struct TorusVers
{
   float fRatio;
   char nSegs;
   char nSides;
} TorusVers;

typedef struct CylinderVers
{
   char nHeightSeg;
   char nSides;
} CylinderVers;

typedef struct TorusInst
{
   char idQuat;
   unsigned char Padding1;
   short tx;
   short ty;
   short tz;
   char idVersion;
   char idPosAnim;
   char idRotAnim;
   unsigned char Padding8;
   float fRad1;
} TorusInst;

typedef struct ConeInst
{
   char idQuat;
   unsigned char Padding1;
   short tx;
   short ty;
   short tz;
   char idVersion;
   char idPosAnim;
   char idRotAnim;
} ConeInst;

typedef struct SurfOfRevPt
{
   float x;
   float y;
   float z;
   char flags;
} SurfOfRevPt;

typedef struct GreenFog
{
   union {
   (type???) public: void __thiscall GreenFog::Init(void);
   (type???) UnInit;
   (type???) public: void __thiscall GreenFog::create(void);
   (type???) public: void __thiscall GreenFog::destroy(void);
   (type???) public: void __thiscall GreenFog::advanceTime(float,float);
   (type???) public: void __thiscall GreenFog::render(bool);
   (type???) public: void __thiscall GreenFog::restart(void);
   (type???) borrowScreenQuad;
   int __unnamed;
   D3DVertexBuffer * pQuadVB;
   };
   D3DVertexBuffer * pIntensityQuadVB;
   D3DTexture * pPlasmaTexture[3];
   D3DTexture * pIntensityTextureR;
   D3DTexture * pIntensityTextureU;
   D3DSurface * pIntensityZ;
   unsigned long dwFogPShader;
   unsigned long dwFogVShader;
   (type???) protected: void __thiscall GreenFog::renderIntensityTexture(void);
} GreenFog;

typedef struct CameraController
{
   union {
   CamControlNodeData svCameraListData[0];
   CamControlNode svCameraList[0];
   int __unnamed;
   CamControlNode finishNodes[8];
   };
   _D3DMATRIX xfSlash;
   _D3DVECTOR ptSlashCenter;
   _D3DVECTOR ptFinalLookAt;
   int numNodes;
   int numPaths;
   int curPathNum;
   int curStartNode;
   int curNumNodes;
   int curVariableNodes;
   float fCameraLookatInterpStart;
   float fOOCameraLookatInterpDelta;
   union {
   (type???) getNode;
   (type???) protected: struct CamControlNode * __thiscall CameraController::getNode(int);
   (type???) public: void __thiscall CameraController::Init(void);
   (type???) UnInit;
   (type???) buttonPressed;
   (type???) public: void __thiscall CameraController::pickPath(int);
   (type???) public: void __thiscall CameraController::getPosition(float,struct _D3DVECTOR *,struct _D3DVECTOR *,bool *,bool *);
   (type???) getSlashTransform;
   };
} CameraController;

typedef struct VBloblet
{
   union {
   (type???) Init;
   (type???) UnInit;
   (type???) set;
   float fRadius;
   };
   _D3DVECTOR vPosition;
   bool bFarSide;
   unsigned char Padding6;
   unsigned char Padding7;
   unsigned char Padding8;
   _D3DVECTOR vDirection;
   float fStartTime;
   float fTimeMultiple;
   float fMaxDist;
   float fCurDist;
   float fWobble;
   float fWobbleDirection;
   (type???) public: bool __thiscall VBloblet::update(float,float);
} VBloblet;

typedef struct VBlobBump
{
   union {
   (type???) Init;
   (type???) UnInit;
   (type???) set;
   float fRadius;
   };
   float fRadius2;
   float fOORadius2;
   float fMagnitude;
   _D3DVECTOR vPosition;
   int facesOfInterest;
   union {
   (type???) public: bool __thiscall VBlobBump::create(float,class VBloblet *);
   (type???) public: bool __thiscall VBlobBump::update(float,float,class VBloblet *);
   unsigned long Padding11;
   };
   unsigned long Padding12;
   unsigned long Padding13;
   unsigned long Padding14;
   unsigned long Padding15;
   unsigned long Padding16;
   unsigned long Padding17;
   unsigned long Padding18;
   _D3DVECTOR vDirection;
   float fStartTime;
   float fTimeMul;
   float fMaxMagnitude;
   class VBloblet * pMyBloblet;
   bool bStillAttachedToBloblet;
   (type???) protected: void __thiscall VBlobBump::recalculateFacesOfInterest(void);
} VBlobBump;

typedef struct VBlob
{
   D3DVertexBuffer * m_pBlobletVB;
   D3DIndexBuffer * m_pBlobletIB;
   D3DVertexBuffer * pHaloQuadVB;
   D3DVertexBuffer * m_pBlobVBConst;
   D3DVertexBuffer * m_pBlobVBChangingR;
   D3DVertexBuffer * m_pBlobVBChangingU;
   D3DIndexBuffer * m_pBlobIB;
   _D3DVECTOR * m_pUnitSphereNormals;
   unsigned long m_dwNumVertices;
   unsigned long m_dwNumBlobletVertices;
   unsigned long m_dwNumIndices;
   unsigned long m_dwNumBlobletIndices;
   int m_NumVertsPerFace;
   unsigned long m_dwVShaderBlob;
   unsigned long m_dwVShaderBloblet;
   unsigned long m_dwPShaderBlob;
   unsigned long m_dwPShaderBloblet;
   D3DVECTOR4 m_BlobColor;
   _D3DVECTOR m_Pos;
   _D3DVECTOR m_Scale;
   float m_fRadius;
   int __unnamed;
   unsigned long Padding22;
   unsigned long Padding23;
   unsigned long Padding24;
   unsigned long Padding25;
   unsigned long Padding26;
   unsigned long Padding27;
   unsigned long Padding28;
   unsigned long Padding29;
   unsigned long Padding30;
   unsigned long Padding31;
   unsigned long Padding32;
   unsigned long Padding33;
   unsigned long Padding34;
   unsigned long Padding35;
   unsigned long Padding36;
   unsigned long Padding37;
   unsigned long Padding38;
   unsigned long Padding39;
   unsigned long Padding40;
   unsigned long Padding41;
   unsigned long Padding42;
   unsigned long Padding43;
   unsigned long Padding44;
   unsigned long Padding45;
   unsigned long Padding46;
   unsigned long Padding47;
   unsigned long Padding48;
   class VBlobBump m_BlobBumps[32];
   int m_NumBlobBumps;
   int __unnamed;
   unsigned long Padding52;
   unsigned long Padding53;
   unsigned long Padding54;
   unsigned long Padding55;
   unsigned long Padding56;
   unsigned long Padding57;
   unsigned long Padding58;
   unsigned long Padding59;
   unsigned long Padding60;
   unsigned long Padding61;
   unsigned long Padding62;
   unsigned long Padding63;
   unsigned long Padding64;
   unsigned long Padding65;
   unsigned long Padding66;
   unsigned long Padding67;
   unsigned long Padding68;
   unsigned long Padding69;
   unsigned long Padding70;
   unsigned long Padding71;
   unsigned long Padding72;
   unsigned long Padding73;
   unsigned long Padding74;
   unsigned long Padding75;
   unsigned long Padding76;
   unsigned long Padding77;
   unsigned long Padding78;
   unsigned long Padding79;
   unsigned long Padding80;
   unsigned long Padding81;
   unsigned long Padding82;
   unsigned long Padding83;
   unsigned long Padding84;
   unsigned long Padding85;
   unsigned long Padding86;
   unsigned long Padding87;
   unsigned long Padding88;
   unsigned long Padding89;
   unsigned long Padding90;
   unsigned long Padding91;
   unsigned long Padding92;
   unsigned long Padding93;
   unsigned long Padding94;
   unsigned long Padding95;
   unsigned long Padding96;
   unsigned long Padding97;
   unsigned long Padding98;
   unsigned long Padding99;
   unsigned long Padding100;
   unsigned long Padding101;
   unsigned long Padding102;
   unsigned long Padding103;
   unsigned long Padding104;
   unsigned long Padding105;
   unsigned long Padding106;
   unsigned long Padding107;
   unsigned long Padding108;
   unsigned long Padding109;
   unsigned long Padding110;
   unsigned long Padding111;
   unsigned long Padding112;
   unsigned long Padding113;
   unsigned long Padding114;
   unsigned long Padding115;
   unsigned long Padding116;
   unsigned long Padding117;
   unsigned long Padding118;
   unsigned long Padding119;
   unsigned long Padding120;
   unsigned long Padding121;
   unsigned long Padding122;
   unsigned long Padding123;
   unsigned long Padding124;
   unsigned long Padding125;
   unsigned long Padding126;
   unsigned long Padding127;
   unsigned long Padding128;
   unsigned long Padding129;
   unsigned long Padding130;
   unsigned long Padding131;
   unsigned long Padding132;
   unsigned long Padding133;
   unsigned long Padding134;
   unsigned long Padding135;
   unsigned long Padding136;
   unsigned long Padding137;
   unsigned long Padding138;
   unsigned long Padding139;
   unsigned long Padding140;
   unsigned long Padding141;
   unsigned long Padding142;
   unsigned long Padding143;
   unsigned long Padding144;
   unsigned long Padding145;
   unsigned long Padding146;
   unsigned long Padding147;
   unsigned long Padding148;
   unsigned long Padding149;
   unsigned long Padding150;
   unsigned long Padding151;
   unsigned long Padding152;
   unsigned long Padding153;
   unsigned long Padding154;
   unsigned long Padding155;
   unsigned long Padding156;
   unsigned long Padding157;
   unsigned long Padding158;
   unsigned long Padding159;
   unsigned long Padding160;
   unsigned long Padding161;
   unsigned long Padding162;
   unsigned long Padding163;
   unsigned long Padding164;
   unsigned long Padding165;
   unsigned long Padding166;
   unsigned long Padding167;
   unsigned long Padding168;
   unsigned long Padding169;
   unsigned long Padding170;
   unsigned long Padding171;
   unsigned long Padding172;
   unsigned long Padding173;
   unsigned long Padding174;
   unsigned long Padding175;
   unsigned long Padding176;
   unsigned long Padding177;
   unsigned long Padding178;
   unsigned long Padding179;
   unsigned long Padding180;
   unsigned long Padding181;
   unsigned long Padding182;
   unsigned long Padding183;
   unsigned long Padding184;
   unsigned long Padding185;
   unsigned long Padding186;
   unsigned long Padding187;
   unsigned long Padding188;
   unsigned long Padding189;
   unsigned long Padding190;
   unsigned long Padding191;
   unsigned long Padding192;
   unsigned long Padding193;
   unsigned long Padding194;
   unsigned long Padding195;
   unsigned long Padding196;
   unsigned long Padding197;
   unsigned long Padding198;
   unsigned long Padding199;
   unsigned long Padding200;
   unsigned long Padding201;
   unsigned long Padding202;
   unsigned long Padding203;
   unsigned long Padding204;
   unsigned long Padding205;
   unsigned long Padding206;
   unsigned long Padding207;
   unsigned long Padding208;
   unsigned long Padding209;
   unsigned long Padding210;
   unsigned long Padding211;
   unsigned long Padding212;
   unsigned long Padding213;
   unsigned long Padding214;
   unsigned long Padding215;
   unsigned long Padding216;
   unsigned long Padding217;
   unsigned long Padding218;
   unsigned long Padding219;
   unsigned long Padding220;
   unsigned long Padding221;
   unsigned long Padding222;
   unsigned long Padding223;
   unsigned long Padding224;
   unsigned long Padding225;
   unsigned long Padding226;
   unsigned long Padding227;
   unsigned long Padding228;
   unsigned long Padding229;
   unsigned long Padding230;
   unsigned long Padding231;
   unsigned long Padding232;
   unsigned long Padding233;
   unsigned long Padding234;
   unsigned long Padding235;
   unsigned long Padding236;
   unsigned long Padding237;
   unsigned long Padding238;
   unsigned long Padding239;
   unsigned long Padding240;
   unsigned long Padding241;
   unsigned long Padding242;
   unsigned long Padding243;
   unsigned long Padding244;
   unsigned long Padding245;
   unsigned long Padding246;
   unsigned long Padding247;
   unsigned long Padding248;
   unsigned long Padding249;
   unsigned long Padding250;
   unsigned long Padding251;
   unsigned long Padding252;
   unsigned long Padding253;
   unsigned long Padding254;
   unsigned long Padding255;
   unsigned long Padding256;
   unsigned long Padding257;
   unsigned long Padding258;
   unsigned long Padding259;
   unsigned long Padding260;
   unsigned long Padding261;
   unsigned long Padding262;
   unsigned long Padding263;
   unsigned long Padding264;
   unsigned long Padding265;
   unsigned long Padding266;
   unsigned long Padding267;
   unsigned long Padding268;
   unsigned long Padding269;
   unsigned long Padding270;
   unsigned long Padding271;
   unsigned long Padding272;
   unsigned long Padding273;
   unsigned long Padding274;
   unsigned long Padding275;
   unsigned long Padding276;
   unsigned long Padding277;
   unsigned long Padding278;
   unsigned long Padding279;
   unsigned long Padding280;
   unsigned long Padding281;
   unsigned long Padding282;
   unsigned long Padding283;
   unsigned long Padding284;
   unsigned long Padding285;
   unsigned long Padding286;
   unsigned long Padding287;
   unsigned long Padding288;
   unsigned long Padding289;
   unsigned long Padding290;
   unsigned long Padding291;
   unsigned long Padding292;
   unsigned long Padding293;
   unsigned long Padding294;
   unsigned long Padding295;
   unsigned long Padding296;
   unsigned long Padding297;
   unsigned long Padding298;
   unsigned long Padding299;
   unsigned long Padding300;
   unsigned long Padding301;
   unsigned long Padding302;
   unsigned long Padding303;
   unsigned long Padding304;
   unsigned long Padding305;
   unsigned long Padding306;
   unsigned long Padding307;
   unsigned long Padding308;
   unsigned long Padding309;
   unsigned long Padding310;
   unsigned long Padding311;
   unsigned long Padding312;
   unsigned long Padding313;
   unsigned long Padding314;
   unsigned long Padding315;
   unsigned long Padding316;
   unsigned long Padding317;
   unsigned long Padding318;
   unsigned long Padding319;
   unsigned long Padding320;
   unsigned long Padding321;
   unsigned long Padding322;
   unsigned long Padding323;
   unsigned long Padding324;
   unsigned long Padding325;
   unsigned long Padding326;
   unsigned long Padding327;
   unsigned long Padding328;
   unsigned long Padding329;
   unsigned long Padding330;
   unsigned long Padding331;
   unsigned long Padding332;
   unsigned long Padding333;
   unsigned long Padding334;
   unsigned long Padding335;
   unsigned long Padding336;
   unsigned long Padding337;
   unsigned long Padding338;
   unsigned long Padding339;
   unsigned long Padding340;
   unsigned long Padding341;
   unsigned long Padding342;
   unsigned long Padding343;
   unsigned long Padding344;
   unsigned long Padding345;
   unsigned long Padding346;
   unsigned long Padding347;
   unsigned long Padding348;
   unsigned long Padding349;
   unsigned long Padding350;
   unsigned long Padding351;
   unsigned long Padding352;
   unsigned long Padding353;
   unsigned long Padding354;
   unsigned long Padding355;
   unsigned long Padding356;
   unsigned long Padding357;
   unsigned long Padding358;
   unsigned long Padding359;
   unsigned long Padding360;
   unsigned long Padding361;
   unsigned long Padding362;
   unsigned long Padding363;
   unsigned long Padding364;
   unsigned long Padding365;
   unsigned long Padding366;
   unsigned long Padding367;
   unsigned long Padding368;
   unsigned long Padding369;
   unsigned long Padding370;
   unsigned long Padding371;
   unsigned long Padding372;
   unsigned long Padding373;
   unsigned long Padding374;
   unsigned long Padding375;
   unsigned long Padding376;
   unsigned long Padding377;
   unsigned long Padding378;
   unsigned long Padding379;
   unsigned long Padding380;
   unsigned long Padding381;
   unsigned long Padding382;
   unsigned long Padding383;
   unsigned long Padding384;
   unsigned long Padding385;
   unsigned long Padding386;
   unsigned long Padding387;
   unsigned long Padding388;
   unsigned long Padding389;
   unsigned long Padding390;
   unsigned long Padding391;
   unsigned long Padding392;
   unsigned long Padding393;
   unsigned long Padding394;
   unsigned long Padding395;
   unsigned long Padding396;
   unsigned long Padding397;
   unsigned long Padding398;
   unsigned long Padding399;
   unsigned long Padding400;
   unsigned long Padding401;
   unsigned long Padding402;
   unsigned long Padding403;
   unsigned long Padding404;
   unsigned long Padding405;
   unsigned long Padding406;
   unsigned long Padding407;
   unsigned long Padding408;
   unsigned long Padding409;
   unsigned long Padding410;
   unsigned long Padding411;
   unsigned long Padding412;
   unsigned long Padding413;
   unsigned long Padding414;
   unsigned long Padding415;
   unsigned long Padding416;
   unsigned long Padding417;
   unsigned long Padding418;
   unsigned long Padding419;
   unsigned long Padding420;
   unsigned long Padding421;
   unsigned long Padding422;
   unsigned long Padding423;
   unsigned long Padding424;
   unsigned long Padding425;
   unsigned long Padding426;
   unsigned long Padding427;
   unsigned long Padding428;
   unsigned long Padding429;
   unsigned long Padding430;
   unsigned long Padding431;
   unsigned long Padding432;
   unsigned long Padding433;
   unsigned long Padding434;
   unsigned long Padding435;
   unsigned long Padding436;
   unsigned long Padding437;
   unsigned long Padding438;
   unsigned long Padding439;
   unsigned long Padding440;
   unsigned long Padding441;
   unsigned long Padding442;
   unsigned long Padding443;
   unsigned long Padding444;
   unsigned long Padding445;
   unsigned long Padding446;
   unsigned long Padding447;
   unsigned long Padding448;
   unsigned long Padding449;
   unsigned long Padding450;
   unsigned long Padding451;
   unsigned long Padding452;
   unsigned long Padding453;
   unsigned long Padding454;
   unsigned long Padding455;
   unsigned long Padding456;
   unsigned long Padding457;
   unsigned long Padding458;
   unsigned long Padding459;
   unsigned long Padding460;
   unsigned long Padding461;
   unsigned long Padding462;
   unsigned long Padding463;
   unsigned long Padding464;
   unsigned long Padding465;
   unsigned long Padding466;
   unsigned long Padding467;
   unsigned long Padding468;
   unsigned long Padding469;
   unsigned long Padding470;
   unsigned long Padding471;
   unsigned long Padding472;
   unsigned long Padding473;
   unsigned long Padding474;
   unsigned long Padding475;
   unsigned long Padding476;
   unsigned long Padding477;
   unsigned long Padding478;
   unsigned long Padding479;
   unsigned long Padding480;
   unsigned long Padding481;
   unsigned long Padding482;
   unsigned long Padding483;
   unsigned long Padding484;
   unsigned long Padding485;
   unsigned long Padding486;
   unsigned long Padding487;
   unsigned long Padding488;
   unsigned long Padding489;
   unsigned long Padding490;
   unsigned long Padding491;
   unsigned long Padding492;
   unsigned long Padding493;
   unsigned long Padding494;
   unsigned long Padding495;
   unsigned long Padding496;
   unsigned long Padding497;
   unsigned long Padding498;
   unsigned long Padding499;
   unsigned long Padding500;
   unsigned long Padding501;
   unsigned long Padding502;
   unsigned long Padding503;
   unsigned long Padding504;
   unsigned long Padding505;
   unsigned long Padding506;
   unsigned long Padding507;
   unsigned long Padding508;
   unsigned long Padding509;
   unsigned long Padding510;
   unsigned long Padding511;
   unsigned long Padding512;
   unsigned long Padding513;
   unsigned long Padding514;
   unsigned long Padding515;
   unsigned long Padding516;
   unsigned long Padding517;
   unsigned long Padding518;
   unsigned long Padding519;
   unsigned long Padding520;
   unsigned long Padding521;
   unsigned long Padding522;
   unsigned long Padding523;
   unsigned long Padding524;
   unsigned long Padding525;
   unsigned long Padding526;
   unsigned long Padding527;
   unsigned long Padding528;
   unsigned long Padding529;
   unsigned long Padding530;
   unsigned long Padding531;
   unsigned long Padding532;
   unsigned long Padding533;
   unsigned long Padding534;
   unsigned long Padding535;
   unsigned long Padding536;
   unsigned long Padding537;
   unsigned long Padding538;
   unsigned long Padding539;
   unsigned long Padding540;
   unsigned long Padding541;
   unsigned long Padding542;
   unsigned long Padding543;
   unsigned long Padding544;
   unsigned long Padding545;
   unsigned long Padding546;
   unsigned long Padding547;
   unsigned long Padding548;
   unsigned long Padding549;
   unsigned long Padding550;
   unsigned long Padding551;
   unsigned long Padding552;
   unsigned long Padding553;
   unsigned long Padding554;
   unsigned long Padding555;
   unsigned long Padding556;
   unsigned long Padding557;
   unsigned long Padding558;
   unsigned long Padding559;
   unsigned long Padding560;
   unsigned long Padding561;
   unsigned long Padding562;
   unsigned long Padding563;
   unsigned long Padding564;
   unsigned long Padding565;
   unsigned long Padding566;
   unsigned long Padding567;
   unsigned long Padding568;
   unsigned long Padding569;
   unsigned long Padding570;
   unsigned long Padding571;
   unsigned long Padding572;
   unsigned long Padding573;
   unsigned long Padding574;
   unsigned long Padding575;
   unsigned long Padding576;
   unsigned long Padding577;
   unsigned long Padding578;
   unsigned long Padding579;
   unsigned long Padding580;
   unsigned long Padding581;
   unsigned long Padding582;
   unsigned long Padding583;
   unsigned long Padding584;
   unsigned long Padding585;
   unsigned long Padding586;
   unsigned long Padding587;
   unsigned long Padding588;
   unsigned long Padding589;
   unsigned long Padding590;
   unsigned long Padding591;
   class VBloblet m_Bloblets[8];
   int m_NumBloblets;
   union {
   class QRand m_QRand;
   (type???) protected: static bool __stdcall VBlob::generateUnitSphere(int,struct D3DVertexBuffer * *,struct D3DIndexBuffer * *,struct _D3DVECTOR * *,unsigned long *,unsigned long *);
   (type???) protected: void __thiscall VBlob::prepareChangingVertices(void);
   (type???) protected: void __thiscall VBlob::zeroChangingVertices(void);
   (type???) swapChangingVertices;
   (type???) public: void __thiscall VBlob::Init(void);
   (type???) UnInit;
   (type???) public: void __thiscall VBlob::create(void);
   (type???) public: void __thiscall VBlob::destroy(void);
   (type???) public: void __thiscall VBlob::render(void);
   (type???) public: void __thiscall VBlob::advanceTime(float,float);
   (type???) public: void __thiscall VBlob::restart(void);
   (type???) getRadius;
   (type???) getCenter;
   (type???) public: void __thiscall VBlob::getLightForPosition(struct _D3DVECTOR *,float *,struct _D3DVECTOR);
   (type???) public: static float __stdcall VBlob::fRand01(void);
   (type???) public: static float __stdcall VBlob::fRand11(void);
   };
} VBlob;

typedef struct PrimitiveInstanceRecord
{
   short idxVersion;
   short idxPosAnim;
   short idxRotAnim;
   unsigned char Padding3;
   unsigned char Padding4;
   _D3DMATRIX matOffset;
   _D3DMATRIX matInvOffset;
   _D3DMATRIX matScale;
   D3DVECTOR4 vObjScale;
   _D3DMATRIX matScaleOffset;
   bool bHiZ;
} PrimitiveInstanceRecord;

typedef struct PrimitiveVersionRecord
{
   unsigned long dwVertexStart;
   unsigned long dwVertexCount;
   unsigned long dwIndexStart;
   unsigned long dwPrimCount;
   unsigned long dwIndexCount;
   unsigned long dwParameter;
} PrimitiveVersionRecord;

typedef struct PrimitiveSet
{
   D3DVertexBuffer * pBaseStream;
   D3DVertexBuffer * pExtraStream;
   D3DIndexBuffer * pIB;
   PrimitiveVersionRecord * aVersRecs;
   int nVersions;
   PrimitiveInstanceRecord * aInstRecs;
   int nInstances;
   int d3dType;
   D3DTexture * pNormalMap;
   D3DCubeTexture * pCubeMap;
   D3DVECTOR4 vAmbient;
   D3DVECTOR4 vDiffuse;
   D3DVECTOR4 vSpecular;
   unsigned long dwPShader;
   unsigned long dwVShader;
   int shaderType;
   int primitiveType;
   bool bHiZ;
   union {
   (type???) private: void __thiscall PrimitiveSet::createSphereVersion(struct SphereVers const *,unsigned char *,unsigned char *,unsigned short *,int,int);
   (type???) private: void __thiscall PrimitiveSet::createCylinderVersion(struct CylinderVers const *,unsigned char *,unsigned char *,unsigned short *,int,int);
   (type???) private: void __thiscall PrimitiveSet::createConeVersion(struct ConeVers const *,unsigned char *,unsigned char *,unsigned short *,int,int);
   (type???) private: void __thiscall PrimitiveSet::createBoxVersion(unsigned char *,unsigned char *,unsigned short *,int);
   (type???) private: void __thiscall PrimitiveSet::createTorusVersion(struct TorusVers const *,unsigned char *,unsigned char *,unsigned short *,int,int);
   (type???) private: void __thiscall PrimitiveSet::createSurfOfRevVersion(struct SurfOfRevVers const *,unsigned char *,unsigned char *,unsigned short *,int,int);
   (type???) private: void __thiscall PrimitiveSet::initSphereInstance(struct SphereInst const *,int);
   (type???) private: void __thiscall PrimitiveSet::initCylinderInstance(struct CylinderInst const *,int);
   (type???) private: void __thiscall PrimitiveSet::initConeInstance(struct ConeInst const *,int);
   (type???) private: void __thiscall PrimitiveSet::initBoxInstance(struct BoxInst const *,int);
   (type???) private: void __thiscall PrimitiveSet::initTorusInstance(struct TorusInst const *,int);
   (type???) private: void __thiscall PrimitiveSet::initConeInstance(struct ConeInst const *,int);
   (type???) private: void __thiscall PrimitiveSet::initSphereVersion(struct SphereVers const *,int,int);
   (type???) private: void __thiscall PrimitiveSet::initCylinderVersion(struct CylinderVers const *,int,int);
   (type???) private: void __thiscall PrimitiveSet::initConeVersion(struct ConeVers const *,int,int);
   (type???) private: void __thiscall PrimitiveSet::initBoxVersion(int);
   (type???) private: void __thiscall PrimitiveSet::initTorusVersion(struct TorusVers const *,int,int);
   (type???) private: void __thiscall PrimitiveSet::initSurfOfRevVersion(struct SurfOfRevVers const *,int,int);
   (type???) public: void __thiscall PrimitiveSet::Init(void);
   (type???) public: void __thiscall PrimitiveSet::UnInit(void);
   (type???) public: void __thiscall PrimitiveSet::render(struct _D3DLIGHT8 const &,bool);
   (type???) public: void __thiscall PrimitiveSet::renderZ(void);
   (type???) public: void __thiscall PrimitiveSet::renderShadowMap(bool);
   (type???) public: void __thiscall PrimitiveSet::create(void const *,int,void const *,int,int,enum ShaderTypes,enum PrimitiveTypes,struct D3DTexture *,struct D3DCubeTexture *);
   };
} PrimitiveSet;

typedef struct SceneRenderer
{
   class PrimitiveSet * pSetHiDet[6];
   class PrimitiveSet * pSetLoDet[6];
   D3DSurface * pSBufTarget;
   D3DSurface * pRenderTarget;
   D3DSurface * pZBuffer;
   D3DSurface fakeTarget;
   float fZOffset;
   float fZSlopeScale;
   bool bUseLoDetail;
   union {
   (type???) protected: struct D3DVECTOR4 * __thiscall SceneRenderer::decompressQuats(short *,unsigned long *,int);
   (type???) protected: struct _D3DVECTOR * __thiscall SceneRenderer::decompressVecs(short *,int);
   (type???) protected: short * __thiscall SceneRenderer::decompressIndices(char *,int);
   (type???) protected: void __thiscall SceneRenderer::updateSBuffer(bool);
   (type???) protected: void __thiscall SceneRenderer::createSceneGeometry(class PrimitiveSet * *,int);
   unsigned long Padding14;
   };
   unsigned long Padding15;
   unsigned long Padding16;
   unsigned long Padding17;
   unsigned long Padding18;
   unsigned long Padding19;
   unsigned long Padding20;
   unsigned long Padding21;
   unsigned long Padding22;
   unsigned long Padding23;
   unsigned long Padding24;
   unsigned long Padding25;
   unsigned long Padding26;
   unsigned long Padding27;
   unsigned long Padding28;
   unsigned long Padding29;
   unsigned long Padding30;
   unsigned long Padding31;
   unsigned long Padding32;
   unsigned long Padding33;
   unsigned long Padding34;
   unsigned long Padding35;
   unsigned long Padding36;
   unsigned long Padding37;
   D3DVECTOR4 * pQuats;
   short * pQuatIdSeq[29];
   _D3DVECTOR * pPos;
   short * pPosIdSeq[32];
   D3DTexture * pSBufDepthHi;
   D3DTexture * pSBufDepthLo;
   _D3DMATRIX matWTSHi;
   _D3DMATRIX matWTSLo;
   _D3DMATRIX * pRotAnims;
   int nRotAnims;
   _D3DVECTOR * pPosAnims;
   int nPosAnims;
   union {
   (type???) public: void __thiscall SceneRenderer::create(void);
   (type???) public: void __thiscall SceneRenderer::destroy(void);
   (type???) public: void __thiscall SceneRenderer::render(bool,bool);
   (type???) public: void __thiscall SceneRenderer::renderZ(void);
   (type???) public: void __thiscall SceneRenderer::advanceTime(float,float);
   (type???) public: void __thiscall SceneRenderer::updateShadows(void);
   };
} SceneRenderer;

typedef struct D3DVECTOR4
{
   union {
   (type???) _D3DVECTOR;
   unsigned long Padding1;
   };
   unsigned long Padding2;
   unsigned long Padding3;
   float w;
} D3DVECTOR4;

typedef struct Camera
{
   D3DVECTOR4 clipPlanes[4];
   bool bClipPlanesSet;
   unsigned char Padding2;
   unsigned char Padding3;
   unsigned char Padding4;
   float fNearPlane;
   float fFarPlane;
   float fAspectRatio;
   bool bWTPValid;
   unsigned char Padding9;
   unsigned char Padding10;
   unsigned char Padding11;
   float fTime;
   _D3DVECTOR vPos;
   _D3DVECTOR vLook;
   _D3DVECTOR vUp;
   _D3DMATRIX matWTP;
   _D3DMATRIX matCTW;
   _D3DMATRIX matWTC;
   _D3DMATRIX matProj;
   union {
   (type???) public: void __thiscall Camera::Init(void);
   (type???) UnInit;
   (type???) public: void __thiscall Camera::lookAt(struct _D3DVECTOR const &,struct _D3DVECTOR const &,struct _D3DVECTOR const &);
   (type???) public: void __thiscall Camera::setProjection(float,float,float,float);
   (type???) setCTW;
   (type???) public: void __thiscall Camera::setWTC(struct _D3DMATRIX const &);
   (type???) translate;
   (type???) sphereVisCheck;
   (type???) updateClipPlanes;
   (type???) getPixelScaleForZ;
   (type???) public: struct _D3DMATRIX & __thiscall Camera::getWTP(void);
   (type???) getCameraPos;
   (type???) getCameraLook;
   (type???) getFarPlane;
   (type???) getAspectRatio;
   };
} Camera;

typedef struct Renderer
{
   Direct3D * pD3D8;
   D3DDevice * pD3DDev8;
   _D3DPRESENT_PARAMETERS_ d3dPresentParams;
   union {
   (type???) public: void __thiscall Renderer::Init(void);
   (type???) UnInit;
   (type???) public: bool __thiscall Renderer::init(int,int);
   (type???) public: void __thiscall Renderer::shutdown(void);
   };
} Renderer;

typedef struct QRand
{
   union {
   int seed;
   (type???) Init;
   (type???) SetSeed;
   (type???) public: int __thiscall QRand::Rand(void);
   (type???) public: int __thiscall QRand::Rand(int);
   };
} QRand;

typedef struct LogoRenderer
{
   D3DVertexBuffer * pLipVB;
   short * pLipIndices;
   unsigned long nLipVerts;
   unsigned long nLipIndices;
   D3DTexture * pLipTex;
   D3DVertexBuffer * pSurfaceVB;
   short * pSurfaceIndices;
   unsigned long nSurfaceVerts;
   unsigned long nSurfaceIndices;
   D3DTexture * pSurfaceTex;
   D3DVertexBuffer * pSurfaceTopVB;
   short * pSurfaceTopIndices;
   unsigned long nSurfaceTopVerts;
   unsigned long nSurfaceTopIndices;
   D3DTexture * pSurfaceTopTex;
   D3DVertexBuffer * pInteriorVB;
   short * pInteriorIndices;
   unsigned long nInteriorVerts;
   unsigned long nInteriorIndices;
   bool bRenderText;
   unsigned char Padding20;
   unsigned char Padding21;
   unsigned char Padding22;
   D3DVertexBuffer * pText_VB;
   short * pText_Indices;
   unsigned long nText_Verts;
   unsigned long nText_Indices;
   _D3DMATRIX matText_Anim;
   D3DVertexBuffer * pSlashTM_VB;
   short * pSlashTM_Indices;
   unsigned long nSlashTM_Verts;
   unsigned long nSlashTM_Indices;
   D3DVertexBuffer * pTextTM_VB;
   short * pTextTM_Indices;
   unsigned long nTextTM_Verts;
   unsigned long nTextTM_Indices;
   D3DTexture * pTMTex;
   float fTMAlpha;
   unsigned long dwInteriorPShader;
   unsigned long dwInteriorVShader;
   union {
   (type???) private: void __thiscall LogoRenderer::createSlash(void);
   (type???) private: void __thiscall LogoRenderer::createText(void);
   (type???) private: void __thiscall LogoRenderer::createTMs(void);
   unsigned long Padding43;
   };
   unsigned long Padding44;
   unsigned long Padding45;
   unsigned long Padding46;
   unsigned long Padding47;
   unsigned long Padding48;
   unsigned long Padding49;
   unsigned long Padding50;
   unsigned long Padding51;
   unsigned long Padding52;
   unsigned long Padding53;
   unsigned long Padding54;
   unsigned long Padding55;
   unsigned long Padding56;
   unsigned long Padding57;
   unsigned long Padding58;
   unsigned long Padding59;
   unsigned long Padding60;
   unsigned long Padding61;
   unsigned long Padding62;
   unsigned long Padding63;
   unsigned long Padding64;
   unsigned long Padding65;
   unsigned long Padding66;
   unsigned long Padding67;
   unsigned long Padding68;
   unsigned long Padding69;
   unsigned long Padding70;
   unsigned long Padding71;
   unsigned long Padding72;
   unsigned long Padding73;
   unsigned long Padding74;
   unsigned long Padding75;
   unsigned long Padding76;
   unsigned long Padding77;
   unsigned long Padding78;
   unsigned long Padding79;
   unsigned long Padding80;
   unsigned long Padding81;
   unsigned long Padding82;
   unsigned long Padding83;
   unsigned long Padding84;
   unsigned long Padding85;
   unsigned long Padding86;
   unsigned long Padding87;
   unsigned long Padding88;
   unsigned long Padding89;
   unsigned long Padding90;
   unsigned long Padding91;
   unsigned long Padding92;
   unsigned long Padding93;
   unsigned long Padding94;
   D3DTexture * pSlashTexture;
   bool bHasWordmark;
   union {
   (type???) private: void __thiscall LogoRenderer::createSlashSurface(void);
   unsigned long Padding98;
   };
   unsigned long Padding99;
   unsigned long Padding100;
   unsigned long Padding101;
   unsigned long Padding102;
   unsigned long Padding103;
   unsigned long Padding104;
   unsigned long Padding105;
   unsigned long Padding106;
   unsigned long Padding107;
   unsigned long Padding108;
   unsigned long Padding109;
   unsigned long Padding110;
   unsigned long Padding111;
   unsigned long Padding112;
   unsigned long Padding113;
   unsigned long Padding114;
   unsigned long Padding115;
   unsigned long Padding116;
   unsigned long Padding117;
   unsigned long Padding118;
   unsigned long Padding119;
   unsigned long Padding120;
   unsigned long Padding121;
   unsigned long Padding122;
   unsigned long Padding123;
   unsigned long Padding124;
   unsigned long Padding125;
   unsigned long Padding126;
   unsigned long Padding127;
   unsigned long Padding128;
   unsigned long Padding129;
   unsigned long Padding130;
   unsigned long Padding131;
   unsigned long Padding132;
   unsigned long Padding133;
   unsigned long Padding134;
   unsigned long Padding135;
   unsigned long Padding136;
   unsigned long Padding137;
   unsigned long Padding138;
   unsigned long Padding139;
   unsigned long Padding140;
   unsigned long Padding141;
   unsigned long Padding142;
   unsigned long Padding143;
   unsigned long Padding144;
   unsigned long Padding145;
   unsigned long Padding146;
   unsigned long Padding147;
   unsigned long Padding148;
   unsigned long Padding149;
   unsigned long Padding150;
   unsigned long Padding151;
   short * indices_xboxlogolip_0;
   float * verts_xboxlogolip_0;
   short * indices_xboxlogosurface_0;
   float * verts_xboxlogosurface_0;
   short * indices_xboxlogosurfacetop_0;
   float * verts_xboxlogosurfacetop_0;
   short * indices_xboxlogointerior_0;
   float * verts_xboxlogointerior_0;
   short * indices_tm_wordmark_0;
   float * verts_tm_wordmark_0;
   short * indices_tm_slash_0;
   float * verts_tm_slash_0;
   short * indices_text_0;
   float * verts_text_0;
   union {
   (type???) private: void __thiscall LogoRenderer::decompressData(void);
   (type???) private: float * __thiscall LogoRenderer::decompressPosData(short *,int,float,float);
   (type???) private: float * __thiscall LogoRenderer::decompressPosTexData(short *,int,float,float,float,float);
   (type???) private: unsigned short * __thiscall LogoRenderer::decompressIndexData(char *,int);
   (type???) public: void __thiscall LogoRenderer::create(void);
   (type???) public: void __thiscall LogoRenderer::destroy(void);
   (type???) public: void __thiscall LogoRenderer::advanceTime(float,float);
   (type???) public: void __thiscall LogoRenderer::render(struct _D3DMATRIX const &,bool);
   };
} LogoRenderer;

typedef struct ZShield
{
   D3DVertexBuffer * m_pShieldVB;
   D3DIndexBuffer * m_pShieldIB;
   unsigned long m_dwNumVertices;
   unsigned long m_dwNumIndices;
   _D3DMATRIX m_CurMatrix;
   float m_Speed;
   float m_Theta;
   union {
   (type???) Init;
   (type???) UnInit;
   (type???) create;
   (type???) destroy;
   (type???) render;
   (type???) advanceTime;
   (type???) restart;
   };
} ZShield;

typedef struct Shield
{
   _D3DMATRIX m_CurOTPMatrix;
   _D3DMATRIX m_CurMatrix;
   _D3DVECTOR m_CurCenter;
   _D3DVECTOR m_ObjectCenter;
   _D3DMATRIX m_StartRotation;
   _D3DVECTOR m_RotationDir;
   float m_ThetaZero;
   float m_Speed;
   float m_RadiusScale;
   union {
   _D3DVECTOR ms_Pos;
   (type???) Init;
   (type???) UnInit;
   (type???) create;
   (type???) destroy;
   (type???) render;
   (type???) advanceTime;
   (type???) restart;
   (type???) getCenter;
   (type???) setRadiusScale;
   (type???) getRadiusScale;
   (type???) getSpeed;
   (type???) getObjectToWorldMatrix;
   (type???) sSetCenter;
   };
} Shield;

typedef struct ShieldMgr
{
   union {
   int __unnamed;
   int __unnamed;
   class Shield m_Shields[3];
   };
   class ZShield m_ZShields[5];
   int m_NumShields;
   int m_NumZShields;
   union {
   (type???) restartShields;
   unsigned long Padding7;
   };
   unsigned long Padding8;
   unsigned long Padding9;
   unsigned long Padding10;
   unsigned long Padding11;
   unsigned long Padding12;
   unsigned long Padding13;
   unsigned long Padding14;
   unsigned long Padding15;
   unsigned long Padding16;
   unsigned long Padding17;
   unsigned long Padding18;
   unsigned long Padding19;
   unsigned long Padding20;
   unsigned long Padding21;
   unsigned long Padding22;
   unsigned long Padding23;
   unsigned long Padding24;
   unsigned long Padding25;
   unsigned long Padding26;
   unsigned long Padding27;
   unsigned long Padding28;
   unsigned long Padding29;
   unsigned long Padding30;
   unsigned long Padding31;
   unsigned long Padding32;
   unsigned long Padding33;
   unsigned long Padding34;
   unsigned long Padding35;
   unsigned long Padding36;
   unsigned long Padding37;
   unsigned long Padding38;
   unsigned long Padding39;
   unsigned long Padding40;
   unsigned long Padding41;
   unsigned long Padding42;
   unsigned long Padding43;
   unsigned long Padding44;
   unsigned long Padding45;
   unsigned long Padding46;
   unsigned long Padding47;
   unsigned long Padding48;
   unsigned long Padding49;
   unsigned long Padding50;
   unsigned long Padding51;
   unsigned long Padding52;
   unsigned long Padding53;
   unsigned long Padding54;
   unsigned long Padding55;
   unsigned long Padding56;
   unsigned long Padding57;
   unsigned long Padding58;
   unsigned long Padding59;
   unsigned long Padding60;
   unsigned long Padding61;
   unsigned long Padding62;
   unsigned long Padding63;
   unsigned long Padding64;
   unsigned long Padding65;
   unsigned long Padding66;
   unsigned long Padding67;
   unsigned long Padding68;
   unsigned long Padding69;
   unsigned long Padding70;
   unsigned long Padding71;
   unsigned long Padding72;
   unsigned long Padding73;
   unsigned long Padding74;
   unsigned long Padding75;
   unsigned long Padding76;
   unsigned long Padding77;
   unsigned long Padding78;
   unsigned long Padding79;
   unsigned long Padding80;
   unsigned long Padding81;
   unsigned long Padding82;
   unsigned long Padding83;
   unsigned long Padding84;
   unsigned long Padding85;
   unsigned long Padding86;
   unsigned long Padding87;
   unsigned long Padding88;
   unsigned long Padding89;
   unsigned long Padding90;
   unsigned long Padding91;
   unsigned long Padding92;
   unsigned long Padding93;
   unsigned long Padding94;
   unsigned long Padding95;
   unsigned long Padding96;
   unsigned long Padding97;
   unsigned long Padding98;
   unsigned long Padding99;
   unsigned long Padding100;
   unsigned long Padding101;
   unsigned long Padding102;
   unsigned long Padding103;
   unsigned long Padding104;
   unsigned long Padding105;
   unsigned long Padding106;
   unsigned long Padding107;
   unsigned long Padding108;
   unsigned long Padding109;
   unsigned long Padding110;
   unsigned long Padding111;
   unsigned long Padding112;
   unsigned long Padding113;
   unsigned long Padding114;
   unsigned long Padding115;
   unsigned long Padding116;
   unsigned long Padding117;
   unsigned long Padding118;
   unsigned long Padding119;
   unsigned long Padding120;
   unsigned long Padding121;
   unsigned long Padding122;
   unsigned long Padding123;
   unsigned long Padding124;
   unsigned long Padding125;
   unsigned long Padding126;
   unsigned long Padding127;
   unsigned long Padding128;
   unsigned long Padding129;
   unsigned long Padding130;
   unsigned long Padding131;
   unsigned long Padding132;
   unsigned long Padding133;
   unsigned long Padding134;
   unsigned long Padding135;
   unsigned long Padding136;
   unsigned long Padding137;
   unsigned long Padding138;
   unsigned long Padding139;
   unsigned long Padding140;
   unsigned long Padding141;
   unsigned long Padding142;
   unsigned long Padding143;
   unsigned long Padding144;
   unsigned long Padding145;
   unsigned long Padding146;
   unsigned long Padding147;
   unsigned long Padding148;
   unsigned long Padding149;
   unsigned long Padding150;
   unsigned long Padding151;
   unsigned long Padding152;
   unsigned long Padding153;
   unsigned long Padding154;
   unsigned long Padding155;
   unsigned long Padding156;
   unsigned long Padding157;
   unsigned long Padding158;
   unsigned long Padding159;
   unsigned long Padding160;
   unsigned long Padding161;
   unsigned long Padding162;
   unsigned long Padding163;
   unsigned long Padding164;
   unsigned long Padding165;
   unsigned long Padding166;
   unsigned long Padding167;
   unsigned long Padding168;
   unsigned long Padding169;
   unsigned long Padding170;
   unsigned long Padding171;
   unsigned long Padding172;
   unsigned long Padding173;
   unsigned long Padding174;
   unsigned long Padding175;
   unsigned long Padding176;
   unsigned long Padding177;
   unsigned long Padding178;
   unsigned long Padding179;
   unsigned long Padding180;
   unsigned long Padding181;
   unsigned long Padding182;
   unsigned long Padding183;
   unsigned long Padding184;
   unsigned long Padding185;
   unsigned long Padding186;
   unsigned long Padding187;
   unsigned long Padding188;
   unsigned long Padding189;
   unsigned long Padding190;
   unsigned long Padding191;
   unsigned long Padding192;
   unsigned long Padding193;
   unsigned long Padding194;
   unsigned long Padding195;
   unsigned long Padding196;
   unsigned long Padding197;
   unsigned long Padding198;
   unsigned long Padding199;
   unsigned long Padding200;
   unsigned long Padding201;
   unsigned long Padding202;
   unsigned long Padding203;
   unsigned long Padding204;
   unsigned long Padding205;
   unsigned long Padding206;
   unsigned long Padding207;
   unsigned long Padding208;
   unsigned long Padding209;
   unsigned long Padding210;
   unsigned long Padding211;
   unsigned long Padding212;
   unsigned long Padding213;
   unsigned long Padding214;
   unsigned long Padding215;
   unsigned long Padding216;
   unsigned long Padding217;
   unsigned long Padding218;
   unsigned long Padding219;
   unsigned long Padding220;
   unsigned long Padding221;
   unsigned long Padding222;
   unsigned long Padding223;
   unsigned long Padding224;
   unsigned long Padding225;
   unsigned long Padding226;
   unsigned long Padding227;
   unsigned long Padding228;
   unsigned long Padding229;
   unsigned long Padding230;
   unsigned long Padding231;
   unsigned long Padding232;
   unsigned long Padding233;
   unsigned long Padding234;
   unsigned long Padding235;
   unsigned long Padding236;
   unsigned long Padding237;
   unsigned long Padding238;
   unsigned long Padding239;
   unsigned long Padding240;
   unsigned long Padding241;
   unsigned long Padding242;
   unsigned long Padding243;
   unsigned long Padding244;
   unsigned long Padding245;
   unsigned long Padding246;
   unsigned long Padding247;
   unsigned long Padding248;
   unsigned long Padding249;
   unsigned long Padding250;
   unsigned long Padding251;
   unsigned long Padding252;
   unsigned long Padding253;
   unsigned long Padding254;
   unsigned long Padding255;
   unsigned long Padding256;
   unsigned long Padding257;
   unsigned long Padding258;
   unsigned long Padding259;
   unsigned long Padding260;
   unsigned long Padding261;
   unsigned long Padding262;
   unsigned long Padding263;
   unsigned long Padding264;
   unsigned long Padding265;
   unsigned long Padding266;
   unsigned long Padding267;
   unsigned long Padding268;
   unsigned long Padding269;
   unsigned long Padding270;
   unsigned long Padding271;
   unsigned long Padding272;
   unsigned long Padding273;
   unsigned long Padding274;
   unsigned long Padding275;
   unsigned long Padding276;
   unsigned long Padding277;
   unsigned long Padding278;
   unsigned long Padding279;
   unsigned long Padding280;
   unsigned long Padding281;
   unsigned long Padding282;
   unsigned long Padding283;
   unsigned long Padding284;
   unsigned long Padding285;
   unsigned long Padding286;
   unsigned long Padding287;
   unsigned long Padding288;
   unsigned long Padding289;
   unsigned long Padding290;
   unsigned long Padding291;
   unsigned long Padding292;
   unsigned long Padding293;
   unsigned long Padding294;
   unsigned long Padding295;
   unsigned long Padding296;
   unsigned long Padding297;
   unsigned long Padding298;
   D3DVertexBuffer * m_pShieldVB;
   D3DIndexBuffer * m_pShieldIB;
   unsigned long m_dwNumVertices;
   unsigned long m_dwNumIndices;
   unsigned long m_dwVShader;
   unsigned long m_dwPShader;
   _D3DVECTOR m_Pos;
   float m_RadiusScale;
   float m_MidRadius;
   union {
   (type???) Init;
   (type???) UnInit;
   (type???) create;
   (type???) destroy;
   (type???) advanceTime;
   (type???) render;
   (type???) restart;
   };
} ShieldMgr;

typedef struct XBoxStartupApp
{
   int nWidth;
   int nHeight;
   bool bPaused;
   bool bActive;
   bool bLoop;
   bool bCameraUnderControl;
   bool bUserControlledIntensity;
   bool bRenderGeom;
   bool bRenderSlash;
   unsigned char Padding9;
   float fTimeElapsed;
   float fJogDeltaTime;
   float fIIDT;
   float fBaseBlobIntensity;
   float fBlobIntensity;
   float fSmoothedBlobIntensity;
   unsigned long dwLastTick;
   unsigned long dwLastFramecountTick;
   int __unnamed;
   unsigned long Padding19;
   unsigned long Padding20;
   unsigned long Padding21;
   unsigned long Padding22;
   unsigned long Padding23;
   unsigned long Padding24;
   unsigned long Padding25;
   unsigned long Padding26;
   unsigned long Padding27;
   unsigned long Padding28;
   unsigned long Padding29;
   _D3DVECTOR vPulses[12];
   union {
   (type???) private: void __thiscall XBoxStartupApp::initIntensityPulses(void);
   (type???) private: float __thiscall XBoxStartupApp::sumIntensityPulses(float);
   (type???) private: void __thiscall XBoxStartupApp::process(void);
   (type???) private: void __thiscall XBoxStartupApp::drawFrame(void);
   (type???) private: void __thiscall XBoxStartupApp::advanceTime(float,float);
   unsigned long Padding36;
   };
   unsigned long Padding37;
   unsigned long Padding38;
   unsigned long Padding39;
   unsigned long Padding40;
   unsigned long Padding41;
   unsigned long Padding42;
   unsigned long Padding43;
   unsigned long Padding44;
   unsigned long Padding45;
   unsigned long Padding46;
   unsigned long Padding47;
   unsigned long Padding48;
   unsigned long Padding49;
   unsigned long Padding50;
   unsigned long Padding51;
   unsigned long Padding52;
   unsigned long Padding53;
   unsigned long Padding54;
   unsigned long Padding55;
   unsigned long Padding56;
   unsigned long Padding57;
   unsigned long Padding58;
   unsigned long Padding59;
   unsigned long Padding60;
   unsigned long Padding61;
   unsigned long Padding62;
   unsigned long Padding63;
   unsigned long Padding64;
   unsigned long Padding65;
   unsigned long Padding66;
   unsigned long Padding67;
   unsigned long Padding68;
   unsigned long Padding69;
   unsigned long Padding70;
   unsigned long Padding71;
   unsigned long Padding72;
   unsigned long Padding73;
   unsigned long Padding74;
   unsigned long Padding75;
   unsigned long Padding76;
   unsigned long Padding77;
   unsigned long Padding78;
   unsigned long Padding79;
   unsigned long Padding80;
   unsigned long Padding81;
   unsigned long Padding82;
   unsigned long Padding83;
   class ShieldMgr shieldMgr;
   class LogoRenderer logoGeom;
   class QRand qrand;
   float fCamRad;
   float fSavedCamRad;
   float fCamTheta;
   float fSavedCamTheta;
   float fCamPhi;
   float fSavedCamPhi;
   float fCamRadBlob;
   class Renderer theRenderer;
   class Camera theCamera;
   _D3DLIGHT8 blobLight;
   _D3DLIGHT8 moodLight;
   D3DCubeTexture * pNormalCubeMapLoRes;
   D3DCubeTexture * pNormalCubeMapHiRes;
   D3DCubeTexture * pStaticReflectionCubeMap;
   D3DTexture * pRoughBumpMap;
   D3DTexture * pGlowMap;
   unsigned long dwPShader[4];
   unsigned long dwVShader[4];
   class SceneRenderer sceneGeom;
   class VBlob vblob;
   class CameraController camController;
   class GreenFog greenFog;
   int nBootCount;
   int appSpeedId;
   bool bSceneShadowsOn;
   bool bFogOn;
   bool bWideScreen;
   union {
   (type???) public: void __thiscall XBoxStartupApp::Construct(void);
   (type???) Destruct;
   (type???) public: bool __thiscall XBoxStartupApp::init(int,int);
   (type???) public: void __thiscall XBoxStartupApp::shutdown(void);
   (type???) public: int __thiscall XBoxStartupApp::run(void);
   (type???) pause;
   (type???) activate;
   (type???) public: unsigned long __thiscall XBoxStartupApp::loadVertexShader(unsigned char const *,unsigned long const *);
   (type???) public: unsigned long __thiscall XBoxStartupApp::loadPixelShader(unsigned char const *);
   (type???) getElapsedTime;
   (type???) getBaseBlobIntensity;
   (type???) getBlobIntensity;
   (type???) getPulseIntensity;
   (type???) getSmoothedBlobIntensity;
   (type???) getIIDT;
   (type???) getCameraRadiusFromBlob;
   (type???) getCameraRadius;
   (type???) getCameraTheta;
   (type???) getCameraPhi;
   (type???) getShieldMgr;
   (type???) public: float __thiscall XBoxStartupApp::fRand01(void);
   (type???) public: float __thiscall XBoxStartupApp::fRand11(void);
   (type???) rand;
   };
} XBoxStartupApp;

typedef struct CamControlNode
{
   float fTime;
   _D3DVECTOR ptPosition;
   _D3DVECTOR vecVelocity;
   _D3DVECTOR vecLookAt;
   _D3DVECTOR vecLookAtW;
   float tension;
   float bias;
} CamControlNode;

typedef struct CamControlNodeData
{
   unsigned char ucTime;
   signed char scTension;
   signed char scBias;
   unsigned char Padding3;
   _D3DVECTOR ptPosition;
   _D3DVECTOR vecLookAt;
} CamControlNodeData;

typedef struct fifo
{
   unsigned char fifo_read;
   unsigned char fifo_write;
   unsigned char data[16];
} fifo;

typedef struct sound
{
   const unsigned char type;
   const unsigned char priority;
   const short track_map;
   const short * * tbl_ptr;
} sound;

typedef union UNNAMED_TAG_4F539D5
{
   union {
   unsigned char * c;
   short * i;
   };
} UNNAMED_TAG_4F539D5;

typedef struct DSPpatch
{
   short * Start;
   short Length;
   short LoopStart;
   short LoopLength;
   short LoopEnable;
   _DSENVELOPEDESC * lpAmpEnvelope;
   _DSENVELOPEDESC * lpMultiEnvelope;
} DSPpatch;

typedef struct process
{
   process * next;
   process * prev;
   UNNAMED_TAG_308D6CD mem_ptr;
   short timer;
   short prev_timer;
   short function;
   unsigned char level;
   unsigned char hard_channel;
   unsigned char type;
   unsigned char Padding9;
   short data1;
   short data2;
} process;

typedef struct track_info
{
   short patch;
   char pan;
   unsigned char volume;
   unsigned char lfo_sens;
   unsigned char Padding4;
   short pitch;
   short loop_counter[4];
   short * loop_addr[4];
   unsigned char loop_level;
   unsigned char Padding9;
   unsigned char Padding10;
   unsigned char Padding11;
   short * mux_addr[3];
   unsigned char mux_level;
   unsigned char Padding14;
   short transpose;
   short filtercutoff;
   short filterres;
} track_info;

typedef struct _DES3TABLE
{
   _destable keytab1;
   _destable keytab2;
   _destable keytab3;
} DES3TABLE;

typedef struct _destable
{
   unsigned long keytab[2] keytab[16];
} destable;

typedef struct BenalohData
{
   unsigned long N;
   unsigned long * M;
   unsigned long * U;
   unsigned long * V;
   unsigned long * product;
} BenalohData;

typedef struct BSAFE_KEY_PARTS
{
   unsigned char * modulus;
   unsigned char * prvexp;
   unsigned char * prime1;
   unsigned char * prime2;
   unsigned char * exp1;
   unsigned char * exp2;
   unsigned char * coef;
   unsigned char * invmod;
   unsigned char * invpr1;
   unsigned char * invpr2;
} BSAFE_KEY_PARTS;

typedef struct BSAFE_PUB_KEY
{
   unsigned long magic;
   unsigned long keylen;
   unsigned long bitlen;
   unsigned long datalen;
   unsigned long pubexp;
} BSAFE_PUB_KEY;

typedef struct BSAFE_PRV_KEY
{
   unsigned long magic;
   unsigned long keylen;
   unsigned long bitlen;
   unsigned long datalen;
   unsigned long pubexp;
} BSAFE_PRV_KEY;

typedef struct _XBEIMAGE_HEADER
{
   unsigned long Signature;
   unsigned char EncryptedDigest[256];
   void * BaseAddress;
   unsigned long SizeOfHeaders;
   unsigned long SizeOfImage;
   unsigned long SizeOfImageHeader;
   unsigned long TimeDateStamp;
   _XBEIMAGE_CERTIFICATE * Certificate;
   unsigned long NumberOfSections;
   _XBEIMAGE_SECTION * SectionHeaders;
   unsigned long InitFlags;
   void * AddressOfEntryPoint;
   _IMAGE_TLS_DIRECTORY32 * TlsDirectory;
   unsigned long SizeOfStackCommit;
   unsigned long SizeOfHeapReserve;
   unsigned long SizeOfHeapCommit;
   void * NtBaseOfDll;
   unsigned long NtSizeOfImage;
   unsigned long NtCheckSum;
   unsigned long NtTimeDateStamp;
   unsigned char * DebugPathName;
   unsigned char * DebugFileName;
   short * DebugUnicodeFileName;
   _IMAGE_THUNK_DATA32 * XboxKernelThunkData;
   _XBEIMAGE_IMPORT_DESCRIPTOR * ImportDirectory;
   unsigned long NumberOfLibraryVersions;
   _XBEIMAGE_LIBRARY_VERSION * LibraryVersions;
   _XBEIMAGE_LIBRARY_VERSION * XboxKernelLibraryVersion;
   _XBEIMAGE_LIBRARY_VERSION * XapiLibraryVersion;
   void * MicrosoftLogo;
   unsigned long SizeOfMicrosoftLogo;
   _XBEIMAGE_LIBRARY_VERSION * LibraryFeatures;
   unsigned long NumberOfLibraryFeatures;
   void * CodeViewDebugInfo;
} XBEIMAGE_HEADER;

typedef struct _XBEIMAGE_LIBRARY_VERSION
{
   unsigned char LibraryName[8];
   short MajorVersion;
   short MinorVersion;
   short BuildVersion;
   union {
   short QFEVersion;
   short Unused;
   short LibFeature;
   short XBEVersion;
   short ApprovedLibrary;
   short DebugBuild;
   };
} XBEIMAGE_LIBRARY_VERSION;

typedef struct _XBEIMAGE_IMPORT_DESCRIPTOR
{
   _IMAGE_THUNK_DATA32 * ImageThunkData;
   short * ImageName;
} XBEIMAGE_IMPORT_DESCRIPTOR;

typedef struct _XBEIMAGE_SECTION
{
   unsigned long SectionFlags;
   unsigned long VirtualAddress;
   unsigned long VirtualSize;
   unsigned long PointerToRawData;
   unsigned long SizeOfRawData;
   unsigned char * SectionName;
   unsigned long SectionReferenceCount;
   short * HeadSharedPageReferenceCount;
   short * TailSharedPageReferenceCount;
   unsigned char SectionDigest[20];
} XBEIMAGE_SECTION;

typedef struct _XBEIMAGE_CERTIFICATE
{
   unsigned long SizeOfCertificate;
   unsigned long TimeDateStamp;
   unsigned long TitleID;
   short TitleName[40];
   unsigned long AlternateTitleIDs[16];
   unsigned long AllowedMediaTypes;
   unsigned long GameRegion;
   unsigned long GameRatings;
   unsigned long DiskNumber;
   unsigned long Version;
   unsigned char LANKey[16];
   unsigned char SignatureKey[16];
   unsigned char AlternateSignatureKeys[16] AlternateSignatureKeys[16];
   unsigned long Padding13;
   unsigned long Padding14;
   unsigned long Padding15;
   unsigned long Padding16;
   unsigned long Padding17;
   unsigned long Padding18;
   unsigned long Padding19;
   unsigned long Padding20;
   unsigned long Padding21;
   unsigned long Padding22;
   unsigned long Padding23;
   unsigned long Padding24;
   unsigned long Padding25;
   unsigned long Padding26;
   unsigned long Padding27;
   unsigned long Padding28;
   unsigned long Padding29;
   unsigned long Padding30;
   unsigned long Padding31;
   unsigned long Padding32;
   unsigned long Padding33;
   unsigned long Padding34;
   unsigned long Padding35;
   unsigned long Padding36;
   unsigned long Padding37;
   unsigned long Padding38;
   unsigned long Padding39;
   unsigned long Padding40;
   unsigned long Padding41;
   unsigned long Padding42;
   unsigned long Padding43;
   unsigned long Padding44;
   unsigned long Padding45;
   unsigned long Padding46;
   unsigned long Padding47;
   unsigned long Padding48;
   unsigned long Padding49;
   unsigned long Padding50;
   unsigned long Padding51;
   unsigned long Padding52;
   unsigned long Padding53;
   unsigned long Padding54;
   unsigned long Padding55;
   unsigned long Padding56;
   unsigned long Padding57;
   unsigned long Padding58;
   unsigned long Padding59;
   unsigned long Padding60;
   unsigned long Padding61;
   unsigned long Padding62;
   unsigned long Padding63;
   unsigned long Padding64;
   unsigned long Padding65;
   unsigned long Padding66;
   unsigned long Padding67;
   unsigned long Padding68;
   unsigned long Padding69;
   unsigned long Padding70;
   unsigned long Padding71;
   unsigned long Padding72;
   unsigned long OriginalSizeOfCertificate;
   unsigned long OnlineServiceName;
   unsigned long RuntimeSecurityFlags;
   unsigned char CodeEncryptionKey[16];
} XBEIMAGE_CERTIFICATE;

typedef struct UNNAMED_TAG_4FC8A20
{
   unsigned long LowPart;
   unsigned long HighPart;
} UNNAMED_TAG_4FC8A20;

typedef struct _EXCEPTION_REGISTRATION_COMMON
{
   unsigned long scopetable;
   unsigned long trylevel;
} EXCEPTION_REGISTRATION_COMMON;

typedef struct _C9_EXCEPTION_REGISTRATION
{
   unsigned long scopetable;
   unsigned long trylevel;
} C9_EXCEPTION_REGISTRATION;

typedef struct _NLG_INFO
{
   unsigned long dwSig;
   unsigned long uoffDestination;
   unsigned long dwCode;
   unsigned long uoffFramePointer;
} NLG_INFO;

typedef struct _EXCEPTION_REGISTRATION
{
   unsigned long prev;
   unsigned long handler;
} EXCEPTION_REGISTRATION;

typedef struct _SCOPETABLE_ENTRY
{
   unsigned long enclosing_level;
   unsigned long filter;
   unsigned long specific_handler;
} SCOPETABLE_ENTRY;

typedef struct _JMP_BUF
{
   unsigned long saved_ebp;
   unsigned long saved_ebx;
   unsigned long saved_edi;
   unsigned long saved_esi;
   unsigned long saved_esp;
   unsigned long saved_return;
   unsigned long saved_xregistration;
   unsigned long saved_trylevel;
   unsigned long version_cookie;
   unsigned long unwind_func;
   unsigned long unwind_data;
} JMP_BUF;

typedef struct _count_string
{
   short Length;
   short MaximumLength;
   char * Buffer;
} count_string;

typedef union UNNAMED_TAG_5D4302B
{
   union {
   char * sz;
   short * wz;
   };
} UNNAMED_TAG_5D4302B;

typedef union UNNAMED_TAG_56F3F08
{
   char sz[512];
} UNNAMED_TAG_56F3F08;

typedef struct DOUBLE
{
   double x;
} DOUBLE;

typedef struct UNNAMED_TAG_5C0A42E
{
   unsigned long LowPart;
   long HighPart;
} UNNAMED_TAG_5C0A42E;

typedef struct UNNAMED_TAG_5D8BCE3
{
   unsigned long intr;
   unsigned long intr_mk;
   unsigned long swtr_cntl;
   unsigned long swtr_itc;
   unsigned char gap1[112];
   unsigned long tx_cntl;
   unsigned long tx_en;
   unsigned long tx_sta;
   unsigned long rx_cntl_0;
   unsigned long rx_cntl_1;
   unsigned long rx_en;
   unsigned long rx_sta;
   unsigned long bkoff_cntl;
   unsigned long tx_def;
   unsigned long rx_def;
   unsigned long uni0;
   unsigned long uni1;
   unsigned long mult0;
   unsigned long mult1;
   unsigned long mult_mk0;
   unsigned long mult_mk1;
   unsigned char gap2[64];
   unsigned long tx_dadr;
   unsigned long rx_dadr;
   unsigned long dlen;
   unsigned long tx_poll;
   unsigned long rx_poll;
   unsigned long tx_pcnt;
   unsigned long rx_pcnt;
   unsigned long tx_cur_dadr;
   unsigned long rx_cur_dadr;
   unsigned long tx_cur_prd0;
   unsigned long tx_cur_prd1;
   unsigned long rx_cur_prd0;
   unsigned long rx_cur_prd1;
   unsigned long tx_nxt_dadr;
   unsigned long rx_nxt_dadr;
   unsigned long tx_fifo_wm;
   unsigned long rx_fifo_wm;
   unsigned long mode;
   unsigned char gap3[56];
   unsigned long mintr;
   unsigned long mintr_mk;
   unsigned long mii_cs;
   unsigned long mii_tm;
   unsigned long mdio_adr;
   unsigned long mdio_data;
   unsigned char gap4[104];
   unsigned long pm_cntl;
   UNNAMED_TAG_3ACCFFA pmc_crc[5];
   unsigned long pmc_alias;
   unsigned long pmcsr_alias;
} UNNAMED_TAG_5D8BCE3;

typedef struct UNNAMED_TAG_B3EAE9
{
   unsigned long intr;
   unsigned long intr_mk;
   unsigned long swtr_cntl;
   unsigned long swtr_itc;
   unsigned char gap1[112];
   unsigned long tx_cntl;
   unsigned long tx_en;
   unsigned long tx_sta;
   unsigned long rx_cntl_0;
   unsigned long rx_cntl_1;
   unsigned long rx_en;
   unsigned long rx_sta;
   unsigned long bkoff_cntl;
   unsigned long tx_def;
   unsigned long rx_def;
   unsigned long uni0;
   unsigned long uni1;
   unsigned long mult0;
   unsigned long mult1;
   unsigned long mult_mk0;
   unsigned long mult_mk1;
   unsigned char gap2[64];
   unsigned long tx_dadr;
   unsigned long rx_dadr;
   unsigned long dlen;
   unsigned long tx_poll;
   unsigned long rx_poll;
   unsigned long tx_pcnt;
   unsigned long rx_pcnt;
   unsigned long tx_cur_dadr;
   unsigned long rx_cur_dadr;
   unsigned long tx_cur_prd0;
   unsigned long tx_cur_prd1;
   unsigned long rx_cur_prd0;
   unsigned long rx_cur_prd1;
   unsigned long tx_nxt_dadr;
   unsigned long rx_nxt_dadr;
   unsigned long tx_fifo_wm;
   unsigned long rx_fifo_wm;
   unsigned long mode;
   unsigned char gap3[56];
   unsigned long mintr;
   unsigned long mintr_mk;
   unsigned long mii_cs;
   unsigned long mii_tm;
   unsigned long mdio_adr;
   unsigned long mdio_data;
   unsigned char gap4[104];
   unsigned long pm_cntl;
   UNNAMED_TAG_BED97 pmc_crc[5];
   unsigned long pmc_alias;
   unsigned long pmcsr_alias;
} UNNAMED_TAG_B3EAE9;

typedef struct UNNAMED_TAG_68F8F4
{
   unsigned long crc;
   unsigned long mask0;
   unsigned long mask1;
   unsigned long mask2;
   unsigned long mask3;
} UNNAMED_TAG_68F8F4;

typedef struct _D3DVECTOR4
{
   float x;
   float y;
   float z;
   float w;
} D3DVECTOR4;

typedef struct _D3DVBLANKDATA
{
   unsigned long VBlank;
   unsigned long Swap;
   unsigned long Flags;
} D3DVBLANKDATA;

typedef struct _D3DSWAPDATA
{
   unsigned long Swap;
   unsigned long SwapVBlank;
   unsigned long MissedVBlanks;
   unsigned long TimeUntilSwapVBlank;
   unsigned long TimeBetweenSwapVBlanks;
} D3DSWAPDATA;

typedef struct _D3DCOPYRECTSTATE
{
   int ColorFormat;
   int Operation;
   int ColorKeyEnable;
   unsigned long ColorKeyValue;
   unsigned long BlendAlpha;
   unsigned long PremultAlpha;
   unsigned long ClippingPoint;
   unsigned long ClippingSize;
} D3DCOPYRECTSTATE;

typedef struct _D3DCOPYRECTROPSTATE
{
   unsigned long Rop;
   unsigned long Shape;
   unsigned long PatternSelect;
   unsigned long MonoColor0;
   unsigned long MonoColor1;
   unsigned long MonoPattern0;
   unsigned long MonoPattern1;
   const unsigned long * ColorPattern;
} D3DCOPYRECTROPSTATE;

typedef struct _D3DVERTEXATTRIBUTEFORMAT
{
   _D3DVERTEXSHADERINPUT Input[16];
} D3DVERTEXATTRIBUTEFORMAT;

typedef struct _D3DVERTEXSHADERINPUT
{
   unsigned long StreamIndex;
   unsigned long Offset;
   unsigned long Format;
   unsigned char TessType;
   unsigned char TessSource;
} D3DVERTEXSHADERINPUT;

typedef struct _VSD_IDENT_LOOKUP_TABLE
{
   unsigned char Ident[5];
   unsigned char IdentEnum;
} VSD_IDENT_LOOKUP_TABLE;

typedef union UNNAMED_TAG_4CA1841
{
   union {
   NSR_FID FileIdentifierDescriptor;
   unsigned char FileID[256];
   };
} UNNAMED_TAG_4CA1841;

typedef struct _UDF_DIRECTORY_MAPPING
{
   _UDF_VOLUME_EXTENSION * VolumeExtension;
   _IRP * Irp;
   _UDF_FCB * DirectoryFcb;
   unsigned long LogicalSectorNumber;
   unsigned long FileBytesRemaining;
   unsigned long CacheBytesRemaining;
   void * CacheBuffer;
   unsigned char * CurrentBuffer;
} UDF_DIRECTORY_MAPPING;

typedef struct _RUN_ENTRY
{
   unsigned long BaseCode;
   short RunLength;
   short CodeSize;
} RUN_ENTRY;

typedef struct _DISPATCHER_CONTEXT
{
   _EXCEPTION_REGISTRATION_RECORD * RegistrationPointer;
} DISPATCHER_CONTEXT;

typedef union UNNAMED_TAG_28CBB68
{
   union {
   void * WaitObjects[64];
   void * WaitObjectsSmall[9];
   };
   _KWAIT_BLOCK WaitBlocks[9];
} UNNAMED_TAG_28CBB68;

typedef struct _DPC_ENTRY
{
   _KDPC * Dpc;
   void * Routine;
   void * Context;
} DPC_ENTRY;

typedef struct KMOD
{
   unsigned char RmDisplaceOnly;
   unsigned char RmSib;
   unsigned char RmDisplace;
   unsigned char Disp;
} KMOD;

typedef union UNNAMED_TAG_4D74112
{
   union {
   _CONTROL_WORD Fcw;
   _FX_SAVE_AREA * Context;
   };
} UNNAMED_TAG_4D74112;

typedef struct FLOAT_SAVE
{
   unsigned char Flags;
   unsigned char Irql;
   unsigned char PreviousNpxIrql;
   unsigned char Spare[2];
   unsigned char Padding4;
   unsigned char Padding5;
   unsigned char Padding6;
   UNNAMED_TAG_46E7A48 u;
   unsigned long Cr0NpxState;
   _KTHREAD * Thread;
} FLOAT_SAVE;

typedef struct _CONTROL_WORD
{
   short ControlWord;
   unsigned char Padding1;
   unsigned char Padding2;
   unsigned long MXCsr;
} CONTROL_WORD;

typedef struct _OHCD_DEVICE_EXTENSION
{
   _OHCI_OPERATIONAL_REGISTERS * OperationalRegisters;
   unsigned long OperationalRegistersLength;
   _OHCI_HCCA * HCCA;
   _OHCD_ENDPOINT_SCHEDULE Schedule;
} OHCD_DEVICE_EXTENSION;

typedef struct _OHCD_ENDPOINT_SCHEDULE
{
   _OHCD_INTERRUPT_SCHEDULE_NODE InterruptSchedule[64];
   _OHCD_ENDPOINT * ControlHead;
   _OHCD_ENDPOINT * BulkHead;
   short BandwidthPeriodic;
   short BandwidthTotal;
} OHCD_ENDPOINT_SCHEDULE;

typedef struct _OHCD_INTERRUPT_SCHEDULE_NODE
{
   unsigned char RegisterHead;
   unsigned char Pad;
   short Bandwidth;
   short BandwidthChildren;
   short BandwidthParents;
   _OHCD_ENDPOINT * EndpointHead;
   _OHCD_ENDPOINT * EndpointTail;
} OHCD_INTERRUPT_SCHEDULE_NODE;

typedef struct _OHCI_OPERATIONAL_REGISTERS
{
   unsigned long HcRevision;
   _HC_CONTROL_REGISTER HcControl;
   _HC_COMMAND_STATUS HcCommandStatus;
   unsigned long HcInterruptStatus;
   unsigned long HcInterruptEnable;
   unsigned long HcInterruptDisable;
   unsigned long HcHCCA;
   unsigned long HcPeriodCurrentED;
   unsigned long HcControlHeadED;
   unsigned long HcControlCurrentED;
   unsigned long HcBulkHeadED;
   unsigned long HcBulkCurrentED;
   unsigned long HcDoneHead;
   _HC_FRAME_INTERVAL HcFmInterval;
   unsigned long HcFmRemaining;
   unsigned long HcFmNumber;
   unsigned long HcPeriodicStart;
   unsigned long HcLSThreshold;
   _HC_RH_DESCRIPTOR_A HcRhDescriptorA;
   _HC_RH_DESCRIPTOR_B HcRhDescriptorB;
   _HC_RH_STATUS HcRhStatus;
   _HC_RH_PORT_STATUS HcRhPortStatus[1];
} OHCI_OPERATIONAL_REGISTERS;

typedef union _HC_RH_PORT_STATUS
{
   union {
   unsigned long ul;
   short PortStatus;
   };
   short PortStatusChange;
} HC_RH_PORT_STATUS;

typedef union _HC_RH_STATUS
{
   union {
   unsigned long ul;
   short HubStatus;
   };
   short HubStatusChange;
} HC_RH_STATUS;

typedef union _HC_RH_DESCRIPTOR_B
{
   union {
   unsigned long ul;
   short DeviceRemovable;
   };
   short PortPowerControlMask;
} HC_RH_DESCRIPTOR_B;

typedef union _HC_RH_DESCRIPTOR_A
{
   union {
   unsigned long ul;
   unsigned char NumberDownstreamPorts;
   };
   union {
   unsigned char PowerSwitchingMode;
   unsigned char NoPowerSwitch;
   unsigned char DeviceType;
   unsigned char OverCurrentProtectionMode;
   unsigned char NoOverCurrentProtection;
   unsigned char ReservedBits;
   };
   unsigned char Reserved;
   unsigned char PowerOnToPowerGoodTime;
} HC_RH_DESCRIPTOR_A;

typedef union _HC_FRAME_INTERVAL
{
   union {
   unsigned long ul;
   unsigned long FrameInterval;
   unsigned long Reserved;
   unsigned long FullSpeedMaximumPacketSize;
   unsigned long FrameIntervalToggle;
   };
} HC_FRAME_INTERVAL;

typedef union _HC_COMMAND_STATUS
{
   union {
   unsigned long ul;
   unsigned long HostControllerReset;
   unsigned long ControlListFilled;
   unsigned long BulkListFilled;
   unsigned long OwnerShipChangeRequest;
   unsigned long Reserved;
   unsigned long SchedulingOverrunCount;
   unsigned long Reserved2;
   };
} HC_COMMAND_STATUS;

typedef union _HC_CONTROL_REGISTER
{
   union {
   unsigned long ul;
   unsigned long ControlBulkServiceRatio;
   unsigned long PeriodicListEnable;
   unsigned long IsochronousEnable;
   unsigned long ControlListEnable;
   unsigned long BulkListEnable;
   unsigned long HostControllerFunctionalState;
   unsigned long InterruptRouting;
   unsigned long RemoteWakeupConnected;
   unsigned long RemoteWakeupEnabled;
   unsigned long Reserved;
   };
} HC_CONTROL_REGISTER;

typedef struct _OHCI_HCCA
{
   unsigned long InterruptTable[32];
   short FrameNumber;
   short Pad1;
   unsigned long DoneHead;
   unsigned char Reserved[120];
} OHCI_HCCA;

typedef union _OHCI_ENDPOINT_CONTROL
{
   union {
   unsigned long ul;
   unsigned long FunctionAddress;
   unsigned long EndpointAddress;
   unsigned long Direction;
   unsigned long Speed;
   unsigned long Skip;
   unsigned long Format;
   unsigned long MaximumPacketSize;
   unsigned long FutureSoftwareUse;
   };
} OHCI_ENDPOINT_CONTROL;

typedef struct _OHCI_ENDPOINT_DESCRIPTOR
{
   _OHCI_ENDPOINT_CONTROL Control;
   unsigned long TailP;
   unsigned long HeadPHaltCarry;
   unsigned long NextED;
} OHCI_ENDPOINT_DESCRIPTOR;

typedef struct _OHCD_ENDPOINT
{
   _OHCI_ENDPOINT_DESCRIPTOR HcEndpointDescriptor;
   unsigned char Flags;
   unsigned char EndpointType;
   unsigned char ScheduleIndex;
   unsigned char PollingInterval;
   unsigned long PhysicalAddress;
   _OHCD_ENDPOINT * Next;
   unsigned long PauseFrame;
   unsigned char PendingPauseCount;
   unsigned char Padding;
   short Bandwidth;
   short TDInUseCount;
   unsigned char QueuedUrbCount;
   unsigned char ProgrammedUrbCount;
   void * PendingUrbHeadP;
   void * PendingUrbTailP;
} OHCD_ENDPOINT;

typedef struct _CPPORT
{
   unsigned char * Address;
   unsigned long Baud;
   short Flags;
   _TIME_FIELDS CarrierLostTime;
} CPPORT;

typedef struct _IMAGE_RUN3
{
   union {
   int fOne;
   int fTwo;
   int Size;
   int Intensity;
   };
} IMAGE_RUN3;

typedef struct _IMAGE_RUN2
{
   union {
   int fOne;
   int fTwo;
   int Size;
   int Intensity;
   };
} IMAGE_RUN2;

typedef struct _IMAGE_RUN1
{
   union {
   int fOne;
   int Size;
   int Intensity;
   };
} IMAGE_RUN1;

typedef struct TheVerts
{
   float x;
   float y;
   float z;
   float w;
   float u;
   float v;
} TheVerts;

typedef struct _DMREGISTERPERFCOUNTERPARAMBLOCK
{
   const char * szName;
   unsigned long dwType;
   void * pvArg;
} DMREGISTERPERFCOUNTERPARAMBLOCK;

typedef struct _DMINIT
{
   void * * DebugRoutine;
   _LIST_ENTRY * LoadedModuleList;
   unsigned long Flags;
   void * * ClockIntRoutine;
   void * * ProfIntRoutine;
   void * TellRoutine;
   void * * CtxSwapNotifyRoutine;
   void * XProfpDataPtr;
   _DMGD * D3DDriverData;
   _DMXAPI * XapiData;
   unsigned char * DisallowXbdm;
   void * HalStartProfileRoutine;
   void * HalStopProfileRoutine;
   void * HalProfileIntervalRoutine;
   void * * DpcDispatchNotifyRoutine;
   _DMDVD * NextDVDSample;
} DMINIT;

typedef struct _DMDVD
{
   _ULARGE_INTEGER Timestamp;
   union {
   unsigned long BlockCount;
   unsigned long LBA;
   unsigned long InProgress;
   unsigned long Parameters;
   };
   unsigned long ResponseTime;
} DMDVD;

typedef struct _DMXAPI
{
   unsigned char XapiStarted;
   unsigned char Padding1;
   unsigned char Padding2;
   unsigned char Padding3;
   unsigned long LastErrorTlsOff;
   unsigned long CurrentFiberTlsOff;
} DMXAPI;

typedef struct _DMGD
{
   volatile unsigned long * FrameCounter;
   unsigned long *volatile  FlipCounter;
   D3DSurface * Surface;
   void * * RegisterBase;
   void * PerfCounters;
   unsigned long *volatile  pdwOpcode;
   unsigned char * * ppSnapshotBuffer;
   void * D3DInternalsFunction;
   unsigned long DMGDVersion;
} DMGD;

typedef struct XProfpGlobals
{
   unsigned long * bufnext;
   unsigned long * bufend;
   unsigned long * bufnext_stopped;
   unsigned long * bufstart;
   unsigned long start_type;
   unsigned long start_param;
   long lock;
   long reserved;
} XProfpGlobals;

typedef struct _SMBUS_STATUS_BLOCK
{
   long Status;
   unsigned long DataValue;
   _KEVENT CompletionEvent;
} SMBUS_STATUS_BLOCK;

typedef struct _SETTING_ENTRY_INFO
{
   unsigned char Type;
   unsigned char Index;
   unsigned char Size;
   unsigned char Offset;
} SETTING_ENTRY_INFO;

typedef struct _ETIMER
{
   _KTIMER KeTimer;
   _KAPC TimerApc;
   _KDPC TimerDpc;
   _LIST_ENTRY ActiveTimerListEntry;
   long Period;
   unsigned char ApcAssociated;
} ETIMER;

typedef struct _OPEN_PACKET
{
   short Type;
   short Size;
   _FILE_OBJECT * FileObject;
   long FinalStatus;
   unsigned long Information;
   unsigned long ParseCheck;
   _FILE_OBJECT * RelatedFileObject;
   _LARGE_INTEGER AllocationSize;
   unsigned long CreateOptions;
   short FileAttributes;
   short ShareAccess;
   unsigned long Options;
   unsigned long Disposition;
   unsigned long DesiredAccess;
   _FILE_NETWORK_OPEN_INFORMATION * NetworkInformation;
   _DUMMY_FILE_OBJECT * LocalFileObject;
   unsigned char QueryOnly;
   unsigned char DeleteOnly;
} OPEN_PACKET;

typedef struct _DUMMY_FILE_OBJECT
{
   _OBJECT_HEADER ObjectHeader;
   char FileObjectBody[72];
} DUMMY_FILE_OBJECT;

typedef struct _IOP_MINI_COMPLETION_PACKET
{
   _LIST_ENTRY ListEntry;
   union {
   _IO_STACK_LOCATION * CurrentStackLocation;
   unsigned long PacketType;
   };
   void * KeyContext;
   void * ApcContext;
   long IoStatus;
   unsigned long IoStatusInformation;
} IOP_MINI_COMPLETION_PACKET;

typedef struct _ALPHA_PARTIAL_KPRCB
{
   short MinorVersion;
   short MajorVersion;
   unsigned long CurrentThread;
   unsigned long NextThread;
   unsigned long IdleThread;
   char Number;
   char Reserved;
   short BuildType;
   unsigned long SetMember;
   char CpuType;
   char CpuID;
   short CpuStep;
   unsigned long Padding12;
   _ALPHA_NT5_KPROCESSOR_STATE ProcessorState;
} ALPHA_PARTIAL_KPRCB;

typedef struct _IOSPACE_EX32
{
   unsigned long Address;
   unsigned long Length;
   unsigned long Data;
   unsigned long InterfaceType;
   unsigned long BusNumber;
   unsigned long AddressSpace;
} IOSPACE_EX32;

typedef union UNNAMED_TAG_1FAE4E2
{
   union {
   _DBGKD_PRINT_STRING PrintString;
   _DBGKD_GET_STRING GetString;
   };
} UNNAMED_TAG_1FAE4E2;

typedef struct _IOSPACE_EX
{
   unsigned long Address;
   unsigned long Length;
   unsigned long Data;
   unsigned long InterfaceType;
   unsigned long BusNumber;
   unsigned long AddressSpace;
} IOSPACE_EX;

typedef struct _IOSPACE32
{
   unsigned long Address;
   unsigned long Length;
   unsigned long Data;
} IOSPACE32;

typedef union UNNAMED_TAG_1EAF533
{
   union {
   _DBGKM_EXCEPTION Exception;
   _DBGKM_CREATE_THREAD CreateThread;
   _DBGKM_CREATE_PROCESS CreateProcessInfo;
   _DBGKM_EXIT_THREAD ExitThread;
   _DBGKM_EXIT_PROCESS ExitProcess;
   _DBGKM_LOAD_DLL LoadDll;
   _DBGKM_UNLOAD_DLL UnloadDll;
   };
} UNNAMED_TAG_1EAF533;

typedef struct _GET_TEB_ADDRESS
{
   __int64 Address;
} GET_TEB_ADDRESS;

typedef struct _DBGKD_GET_STRING
{
   unsigned long LengthOfPromptString;
   unsigned long LengthOfStringRead;
} DBGKD_GET_STRING;

typedef struct _WINDBG_EXTENSION_APIS64
{
   unsigned long nSize;
   void * lpOutputRoutine;
   void * lpGetExpressionRoutine;
   void * lpGetSymbolRoutine;
   void * lpDisasmRoutine;
   void * lpCheckControlCRoutine;
   void * lpReadProcessMemoryRoutine;
   void * lpWriteProcessMemoryRoutine;
   void * lpGetThreadContextRoutine;
   void * lpSetThreadContextRoutine;
   void * lpIoctlRoutine;
   void * lpStackTraceRoutine;
} WINDBG_EXTENSION_APIS64;

typedef struct _WINDBG_OLDKD_EXTENSION_APIS
{
   unsigned long nSize;
   void * lpOutputRoutine;
   void * lpGetExpressionRoutine;
   void * lpGetSymbolRoutine;
   void * lpDisasmRoutine;
   void * lpCheckControlCRoutine;
   void * lpReadVirtualMemRoutine;
   void * lpWriteVirtualMemRoutine;
   void * lpReadPhysicalMemRoutine;
   void * lpWritePhysicalMemRoutine;
} WINDBG_OLDKD_EXTENSION_APIS;

typedef struct _EXTSTACKTRACE32
{
   unsigned long FramePointer;
   unsigned long ProgramCounter;
   unsigned long ReturnAddress;
   unsigned long Args[4];
} EXTSTACKTRACE32;

typedef struct _KD_PACKET
{
   unsigned long PacketLeader;
   short PacketType;
   short ByteCount;
   unsigned long PacketId;
   unsigned long Checksum;
} KD_PACKET;

typedef struct _ALPHA_KEXCEPTION_FRAME
{
   __int64 IntRa;
   __int64 FltF2;
   __int64 FltF3;
   __int64 FltF4;
   __int64 FltF5;
   __int64 FltF6;
   __int64 FltF7;
   __int64 FltF8;
   __int64 FltF9;
   __int64 IntS0;
   __int64 IntS1;
   __int64 IntS2;
   __int64 IntS3;
   __int64 IntS4;
   __int64 IntS5;
   __int64 IntFp;
   __int64 SwapReturn;
   unsigned long Psr;
   unsigned long Fill[5];
} ALPHA_KEXCEPTION_FRAME;

typedef struct _ALPHA_NT5_KPROCESSOR_STATE
{
   _ALPHA_NT5_CONTEXT ContextFrame;
} ALPHA_NT5_KPROCESSOR_STATE;

typedef struct _KDDEBUGGER_DATA64
{
   _DBGKD_DEBUG_DATA_HEADER64 Header;
   __int64 KernBase;
   __int64 BreakpointWithStatus;
   __int64 SavedContext;
   short ThCallbackStack;
   short NextCallback;
   short FramePointer;
   short PaeEnabled;
   __int64 KiCallUserMode;
   __int64 KeUserCallbackDispatcher;
   __int64 PsLoadedModuleList;
   __int64 PsActiveProcessHead;
   __int64 PspCidTable;
   __int64 ExpSystemResourcesList;
   __int64 ExpPagedPoolDescriptor;
   __int64 ExpNumberOfPagedPools;
   __int64 KeTimeIncrement;
   __int64 KeBugCheckCallbackListHead;
   __int64 KiBugcheckData;
   __int64 IopErrorLogListHead;
   __int64 ObpRootDirectoryObject;
   __int64 ObpTypeObjectType;
   __int64 KeSystemTime;
   __int64 KeInterruptTime;
   __int64 KiTimerTableListHead;
   __int64 MmPfnDatabase;
   __int64 MmSystemPtesStart;
   __int64 MmSystemPtesEnd;
   __int64 MmSubsectionBase;
   __int64 MmNumberOfPagingFiles;
   __int64 MmLowestPhysicalPage;
   __int64 MmHighestPhysicalPage;
   __int64 MmNumberOfPhysicalPages;
   __int64 MmMaximumNonPagedPoolInBytes;
   __int64 MmNonPagedSystemStart;
   __int64 MmNonPagedPoolStart;
   __int64 MmNonPagedPoolEnd;
   __int64 MmPagedPoolStart;
   __int64 MmPagedPoolEnd;
   __int64 MmPagedPoolInformation;
   __int64 MmPageSize;
   __int64 MmSizeOfPagedPoolInBytes;
   __int64 MmAllocatedPagesByUsage;
   __int64 ObpObjectHandleTable;
   __int64 MmVadRoot;
   __int64 FscLruList;
   __int64 FscNumberOfCachePages;
   __int64 FscElementArray;
   __int64 MmExtendedCommit;
   __int64 MmZeroedPageListHead;
   __int64 MmFreePageListHead;
   __int64 MmStandbyPageListHead;
   __int64 MmModifiedPageListHead;
   __int64 MmModifiedNoWritePageListHead;
   __int64 MmAvailablePages;
   __int64 PoolTrackTableSize;
   __int64 PoolTrackTable;
   __int64 NonPagedPoolDescriptor;
   __int64 MmHighestUserAddress;
   __int64 MmSystemRangeStart;
   __int64 MmUserProbeAddress;
   __int64 KdPrintCircularBuffer;
   __int64 KdPrintCircularBufferEnd;
   __int64 KdPrintWritePointer;
   __int64 KdPrintRolloverCount;
   __int64 MmLoadedUserImageList;
} KDDEBUGGER_DATA64;

typedef struct _X86_KPCR
{
   _NT_TIB NtTib;
   unsigned long SelfPcr;
   unsigned long Prcb;
   unsigned char Irql;
   unsigned char Padding4;
   unsigned char Padding5;
   unsigned char Padding6;
   unsigned long IRR;
   unsigned long IrrActive;
   unsigned long IDR;
   unsigned long Reserved2;
   unsigned long IDT;
   unsigned long GDT;
   unsigned long TSS;
   short MajorVersion;
   short MinorVersion;
   unsigned long SetMember;
   unsigned long StallScaleFactor;
   unsigned char DebugActive;
   unsigned char Number;
   unsigned char VdmAlert;
   unsigned char Reserved[1];
   unsigned long KernelReserved[15];
   unsigned long SecondLevelCacheSize;
   unsigned long HalReserved[16];
   unsigned long InterruptMode;
   unsigned char Spare1;
   unsigned char Padding27;
   unsigned char Padding28;
   unsigned char Padding29;
   unsigned long KernelReserved2[17];
   _X86_PARTIAL_KPRCB PrcbData;
} X86_KPCR;

typedef struct _X86_DESCRIPTOR_TABLE_ENTRY
{
   unsigned long Selector;
   _X86_LDT_ENTRY Descriptor;
} X86_DESCRIPTOR_TABLE_ENTRY;

typedef union UNNAMED_TAG_44710E9
{
   union {
   _DBGKM_EXCEPTION Exception;
   _DBGUI_CREATE_THREAD CreateThread;
   _DBGUI_CREATE_PROCESS CreateProcessInfo;
   _DBGKM_EXIT_THREAD ExitThread;
   _DBGKM_EXIT_PROCESS ExitProcess;
   _DBGKM_LOAD_DLL LoadDll;
   _DBGKM_UNLOAD_DLL UnloadDll;
   };
} UNNAMED_TAG_44710E9;

typedef struct _DBGUI_CREATE_PROCESS
{
   void * HandleToProcess;
   void * HandleToThread;
   _DBGKM_CREATE_PROCESS NewProcess;
} DBGUI_CREATE_PROCESS;

typedef struct _IOSPACE64
{
   __int64 Address;
   unsigned long Length;
   unsigned long Data;
} IOSPACE64;

typedef struct _WINDBG_OLD_EXTENSION_APIS
{
   unsigned long nSize;
   void * lpOutputRoutine;
   void * lpGetExpressionRoutine;
   void * lpGetSymbolRoutine;
   void * lpDisasmRoutine;
   void * lpCheckControlCRoutine;
} WINDBG_OLD_EXTENSION_APIS;

typedef struct _DBGUI_CREATE_THREAD
{
   void * HandleToThread;
   _DBGKM_CREATE_THREAD NewThread;
} DBGUI_CREATE_THREAD;

typedef struct _AXP64_PARTIAL_KPRCB
{
   short MinorVersion;
   short MajorVersion;
   unsigned long Padding2;
   __int64 CurrentThread;
} AXP64_PARTIAL_KPRCB;

typedef struct _KDDEBUGGER_DATA32
{
   _DBGKD_DEBUG_DATA_HEADER32 Header;
   unsigned long KernBase;
   unsigned long BreakpointWithStatus;
   unsigned long SavedContext;
   short ThCallbackStack;
   short NextCallback;
   short FramePointer;
   short PaeEnabled;
   unsigned long KiCallUserMode;
   unsigned long KeUserCallbackDispatcher;
   unsigned long PsLoadedModuleList;
   unsigned long PsActiveProcessHead;
   unsigned long PspCidTable;
   unsigned long ExpSystemResourcesList;
   unsigned long ExpPagedPoolDescriptor;
   unsigned long ExpNumberOfPagedPools;
   unsigned long KeTimeIncrement;
   unsigned long KeBugCheckCallbackListHead;
   unsigned long KiBugcheckData;
   unsigned long IopErrorLogListHead;
   unsigned long ObpRootDirectoryObject;
   unsigned long ObpTypeObjectType;
   unsigned long KeSystemTime;
   unsigned long KeInterruptTime;
   unsigned long KiTimerTableListHead;
   unsigned long MmPfnDatabase;
   unsigned long MmSystemPtesStart;
   unsigned long MmSystemPtesEnd;
   unsigned long MmSubsectionBase;
   unsigned long MmNumberOfPagingFiles;
   unsigned long MmLowestPhysicalPage;
   unsigned long MmHighestPhysicalPage;
   unsigned long MmNumberOfPhysicalPages;
   unsigned long MmMaximumNonPagedPoolInBytes;
   unsigned long MmNonPagedSystemStart;
   unsigned long MmNonPagedPoolStart;
   unsigned long MmNonPagedPoolEnd;
   unsigned long MmPagedPoolStart;
   unsigned long MmPagedPoolEnd;
   unsigned long MmPagedPoolInformation;
   unsigned long MmPageSize;
   unsigned long MmSizeOfPagedPoolInBytes;
   unsigned long MmAllocatedPagesByUsage;
   unsigned long ObpObjectHandleTable;
   unsigned long MmVadRoot;
   unsigned long FscLruList;
   unsigned long FscNumberOfCachePages;
   unsigned long FscElementArray;
   unsigned long MmExtendedCommit;
   unsigned long MmZeroedPageListHead;
   unsigned long MmFreePageListHead;
   unsigned long MmStandbyPageListHead;
   unsigned long MmModifiedPageListHead;
   unsigned long MmModifiedNoWritePageListHead;
   unsigned long MmAvailablePages;
   unsigned long PoolTrackTableSize;
   unsigned long PoolTrackTable;
   unsigned long NonPagedPoolDescriptor;
   unsigned long MmHighestUserAddress;
   unsigned long MmSystemRangeStart;
   unsigned long MmUserProbeAddress;
   unsigned long KdPrintCircularBuffer;
   unsigned long KdPrintCircularBufferEnd;
   unsigned long KdPrintWritePointer;
   unsigned long KdPrintRolloverCount;
   unsigned long MmLoadedUserImageList;
} KDDEBUGGER_DATA32;

typedef struct DBGKD_INTERNAL_BREAKPOINT
{
   __int64 Addr;
   unsigned long Flags;
   unsigned long Calls;
   unsigned long CallsLastCheck;
   unsigned long MaxCallsPerPeriod;
   unsigned long MinInstructions;
   unsigned long MaxInstructions;
   unsigned long TotalInstructions;
   unsigned long Handle;
   void * Thread;
   unsigned long Padding10;
   __int64 ReturnAddress;
} DBGKD_INTERNAL_BREAKPOINT;

typedef struct _DBGKD_DEBUG_DATA_HEADER32
{
   LIST_ENTRY32 List;
   unsigned long OwnerTag;
   unsigned long Size;
} DBGKD_DEBUG_DATA_HEADER32;

typedef struct _PROCESSORINFO
{
   short Processor;
   short NumberProcessors;
} PROCESSORINFO;

typedef struct _GET_CURRENT_THREAD_ADDRESS
{
   unsigned long Processor;
   unsigned long Padding1;
   __int64 Address;
} GET_CURRENT_THREAD_ADDRESS;

typedef struct _DBGKD_MANIPULATE_STATE32
{
   unsigned long ApiNumber;
   short ProcessorLevel;
   short Processor;
   long ReturnStatus;
   UNNAMED_TAG_12A3415 u;
} DBGKD_MANIPULATE_STATE32;

typedef union UNNAMED_TAG_1BE956D
{
   union {
   _DBGKD_READ_MEMORY32 ReadMemory;
   _DBGKD_WRITE_MEMORY32 WriteMemory;
   _DBGKD_READ_MEMORY64 ReadMemory64;
   _DBGKD_WRITE_MEMORY64 WriteMemory64;
   _DBGKD_GET_CONTEXT GetContext;
   _DBGKD_SET_CONTEXT SetContext;
   _DBGKD_WRITE_BREAKPOINT32 WriteBreakPoint;
   _DBGKD_RESTORE_BREAKPOINT RestoreBreakPoint;
   _DBGKD_CONTINUE Continue;
   _DBGKD_CONTINUE2 Continue2;
   _DBGKD_READ_WRITE_IO32 ReadWriteIo;
   _DBGKD_READ_WRITE_IO_EXTENDED32 ReadWriteIoExtended;
   _DBGKD_QUERY_SPECIAL_CALLS QuerySpecialCalls;
   _DBGKD_SET_SPECIAL_CALL32 SetSpecialCall;
   _DBGKD_SET_INTERNAL_BREAKPOINT32 SetInternalBreakpoint;
   _DBGKD_GET_INTERNAL_BREAKPOINT32 GetInternalBreakpoint;
   _DBGKD_GET_VERSION32 GetVersion32;
   _DBGKD_BREAKPOINTEX BreakPointEx;
   _DBGKD_READ_WRITE_MSR ReadWriteMsr;
   _DBGKD_SEARCH_MEMORY SearchMemory;
   };
} UNNAMED_TAG_1BE956D;

typedef struct _DBGKD_READ_MEMORY32
{
   unsigned long TargetBaseAddress;
   unsigned long TransferCount;
   unsigned long ActualBytesRead;
} DBGKD_READ_MEMORY32;

typedef struct _FIELD_INFO
{
   unsigned char * fName;
   unsigned char * printName;
   unsigned long size;
   unsigned long fOptions;
   __int64 address;
   void * fieldCallBack;
} FIELD_INFO;

typedef struct _SYM_DUMP_PARAM
{
   unsigned long size;
   unsigned char * sName;
   unsigned long Options;
   unsigned long Padding3;
   __int64 addr;
   _FIELD_INFO * listLink;
   void * Context;
   void * CallbackRoutine;
   unsigned long nFields;
   _FIELD_INFO * Fields;
} SYM_DUMP_PARAM;

typedef struct _DBGSRV_APIMSG
{
   _PORT_MESSAGE h;
   int ApiNumber;
   long ReturnedStatus;
   void * ContinueKey;
} DBGSRV_APIMSG;

typedef struct _READCONTROLSPACE
{
   short Processor;
   unsigned char Padding1;
   unsigned char Padding2;
   unsigned long Address;
   unsigned long BufLen;
   unsigned char Buf[1];
} READCONTROLSPACE;

typedef struct _GETSETBUSDATA
{
   unsigned long BusDataType;
   unsigned long BusNumber;
   unsigned long SlotNumber;
   void * Buffer;
   unsigned long Offset;
   unsigned long Length;
} GETSETBUSDATA;

typedef struct _DBGKD_GET_INTERNAL_BREAKPOINT32
{
   unsigned long BreakpointAddress;
   unsigned long Flags;
   unsigned long Calls;
   unsigned long MaxCallsPerPeriod;
   unsigned long MinInstructions;
   unsigned long MaxInstructions;
   unsigned long TotalInstructions;
} DBGKD_GET_INTERNAL_BREAKPOINT32;

typedef struct _DBGUI_APIMSG
{
   _PORT_MESSAGE h;
   union {
   void * DbgStateChangeSemaphore;
   int ApiNumber;
   };
   long ReturnedStatus;
   UNNAMED_TAG_49EC0C2 u;
} DBGUI_APIMSG;

typedef union UNNAMED_TAG_2B8BBFC
{
   union {
   _DBGUI_CONTINUE Continue;
   _DBGUI_WAIT_STATE_CHANGE WaitStateChange;
   };
} UNNAMED_TAG_2B8BBFC;

typedef struct _DBGUI_WAIT_STATE_CHANGE
{
   int NewState;
   _CLIENT_ID AppClientId;
   UNNAMED_TAG_59DDB6F StateInfo;
} DBGUI_WAIT_STATE_CHANGE;

typedef struct _READ_WRITE_MSR
{
   unsigned long Msr;
   unsigned long Padding1;
   __int64 Value;
} READ_WRITE_MSR;

typedef struct _IA64_PARTIAL_KPRCB
{
   short MinorVersion;
   short MajorVersion;
   unsigned long Padding2;
   __int64 CurrentThread;
   __int64 NextThread;
   __int64 IdleThread;
   char Number;
   char Reserved;
   short BuildType;
   unsigned long SetMember;
   __int64 RestartBlock;
   __int64 PcrPage;
   unsigned long Spares1[4];
   __int64 SystemReserved[8];
   __int64 HalReserved[16];
   unsigned long DpcTime;
   unsigned long InterruptTime;
   unsigned long KernelTime;
   unsigned long UserTime;
   unsigned long InterruptCount;
   unsigned long DispatchInterruptCount;
   unsigned long ApcBypassCount;
   unsigned long DpcBypassCount;
   unsigned long Spare0[4];
   __int64 Spare1;
   __int64 Spare2;
   __int64 Spare3;
   volatile unsigned long IpiFrozen;
   unsigned long Padding28;
   _IA64_KPROCESSOR_STATE ProcessorState;
} IA64_PARTIAL_KPRCB;

typedef struct _IA64_KPROCESSOR_STATE
{
   _IA64_CONTEXT ContextFrame;
} IA64_KPROCESSOR_STATE;

typedef struct _X86_NT5_KPROCESSOR_STATE
{
   _X86_NT5_CONTEXT ContextFrame;
   _X86_KSPECIAL_REGISTERS SpecialRegisters;
} X86_NT5_KPROCESSOR_STATE;

typedef struct _WINDBG_EXTENSION_APIS32
{
   unsigned long nSize;
   void * lpOutputRoutine;
   void * lpGetExpressionRoutine;
   void * lpGetSymbolRoutine;
   void * lpDisasmRoutine;
   void * lpCheckControlCRoutine;
   void * lpReadProcessMemoryRoutine;
   void * lpWriteProcessMemoryRoutine;
   void * lpGetThreadContextRoutine;
   void * lpSetThreadContextRoutine;
   void * lpIoctlRoutine;
   void * lpStackTraceRoutine;
} WINDBG_EXTENSION_APIS32;

typedef struct _PHYSICAL
{
   __int64 Address;
   unsigned long BufLen;
   unsigned char Buf[1];
} PHYSICAL;

typedef struct _DBGKM_APIMSG
{
   _PORT_MESSAGE h;
   int ApiNumber;
   long ReturnedStatus;
   UNNAMED_TAG_51BC191 u;
} DBGKM_APIMSG;

typedef struct _IOSPACE_EX64
{
   __int64 Address;
   unsigned long Length;
   unsigned long Data;
   unsigned long InterfaceType;
   unsigned long BusNumber;
   unsigned long AddressSpace;
} IOSPACE_EX64;

typedef struct _DBGKD_WRITE_MEMORY32
{
   unsigned long TargetBaseAddress;
   unsigned long TransferCount;
   unsigned long ActualBytesWritten;
} DBGKD_WRITE_MEMORY32;

typedef struct _DBGKD_WAIT_STATE_CHANGE64_X86_NT5
{
   unsigned long NewState;
   short ProcessorLevel;
   short Processor;
   unsigned long NumberProcessors;
   unsigned long Padding4;
   __int64 Thread;
   __int64 ProgramCounter;
   UNNAMED_TAG_48C567E u;
   _DBGKD_CONTROL_REPORT ControlReport;
   _X86_NT5_CONTEXT Context;
} DBGKD_WAIT_STATE_CHANGE64_X86_NT5;

typedef struct _DBGKD_GET_VERSION32
{
   short MajorVersion;
   short MinorVersion;
   short ProtocolVersion;
   short Flags;
   unsigned long KernBase;
   unsigned long PsLoadedModuleList;
   short MachineType;
   short ThCallbackStack;
   short NextCallback;
   short FramePointer;
   unsigned long KiCallUserMode;
   unsigned long KeUserCallbackDispatcher;
   unsigned long BreakpointWithStatus;
   unsigned long DebuggerDataList;
} DBGKD_GET_VERSION32;

typedef struct _DBGKD_SET_INTERNAL_BREAKPOINT32
{
   unsigned long BreakpointAddress;
   unsigned long Flags;
} DBGKD_SET_INTERNAL_BREAKPOINT32;

typedef struct _X86_LDT_ENTRY
{
   short LimitLow;
   short BaseLow;
   UNNAMED_TAG_2A7B8DD HighWord;
} X86_LDT_ENTRY;

typedef struct _X86_PARTIAL_KPRCB
{
   short MinorVersion;
   short MajorVersion;
   unsigned long CurrentThread;
   unsigned long NextThread;
   unsigned long IdleThread;
   char Number;
   char Reserved;
   short BuildType;
   unsigned long SetMember;
   char CpuType;
   char CpuID;
   short CpuStep;
   _X86_KPROCESSOR_STATE ProcessorState;
} X86_PARTIAL_KPRCB;

typedef struct _DBGKD_WRITE_BREAKPOINT32
{
   unsigned long BreakPointAddress;
   unsigned long BreakPointHandle;
} DBGKD_WRITE_BREAKPOINT32;

typedef struct _X86_KTRAP_FRAME
{
   unsigned long DbgEbp;
   unsigned long DbgEip;
   unsigned long DbgArgMark;
   unsigned long DbgArgPointer;
   unsigned long TempSegCs;
   unsigned long TempEsp;
   unsigned long Dr0;
   unsigned long Dr1;
   unsigned long Dr2;
   unsigned long Dr3;
   unsigned long Dr6;
   unsigned long Dr7;
   unsigned long SegGs;
   unsigned long SegEs;
   unsigned long SegDs;
   unsigned long Edx;
   unsigned long Ecx;
   unsigned long Eax;
   unsigned long PreviousPreviousMode;
   unsigned long ExceptionList;
   unsigned long SegFs;
   unsigned long Edi;
   unsigned long Esi;
   unsigned long Ebx;
   unsigned long Ebp;
   unsigned long ErrCode;
   unsigned long Eip;
   unsigned long SegCs;
   unsigned long EFlags;
   unsigned long HardwareEsp;
   unsigned long HardwareSegSs;
   unsigned long V86Es;
   unsigned long V86Ds;
   unsigned long V86Fs;
   unsigned long V86Gs;
} X86_KTRAP_FRAME;

typedef struct _DBGKD_READ_WRITE_IO_EXTENDED32
{
   unsigned long DataSize;
   unsigned long InterfaceType;
   unsigned long BusNumber;
   unsigned long AddressSpace;
   unsigned long IoAddress;
   unsigned long DataValue;
} DBGKD_READ_WRITE_IO_EXTENDED32;

typedef struct _BREAKPOINT_ENTRY
{
   unsigned char Flags;
   unsigned char Content;
   unsigned char Padding2;
   unsigned char Padding3;
   void * Address;
} BREAKPOINT_ENTRY;

typedef struct _IA64_KTRAP_FRAME
{
   __int64 Reserved[10];
   _FLOAT128 FltT0;
   _FLOAT128 FltT1;
   _FLOAT128 FltT2;
   _FLOAT128 FltT3;
   _FLOAT128 FltT4;
   _FLOAT128 FltT5;
   _FLOAT128 FltT6;
   _FLOAT128 FltT7;
   _FLOAT128 FltT8;
   _FLOAT128 FltT9;
   __int64 IntGp;
   __int64 IntT0;
   __int64 IntT1;
   __int64 ApUNAT;
   __int64 ApCCV;
   __int64 ApDCR;
   __int64 Preds;
   __int64 IntV0;
   __int64 IntT2;
   __int64 IntT3;
   __int64 IntT4;
   __int64 IntSp;
   __int64 IntTeb;
   __int64 IntT5;
   __int64 IntT6;
   __int64 IntT7;
   __int64 IntT8;
   __int64 IntT9;
   __int64 IntT10;
   __int64 IntT11;
   __int64 IntT12;
   __int64 IntT13;
   __int64 IntT14;
   __int64 IntT15;
   __int64 IntT16;
   __int64 IntT17;
   __int64 IntT18;
   __int64 IntT19;
   __int64 IntT20;
   __int64 IntT21;
   __int64 IntT22;
   __int64 IntNats;
   __int64 BrRp;
   __int64 BrT0;
   __int64 BrT1;
   __int64 RsRSC;
   __int64 RsBSP;
   __int64 RsBSPSTORE;
   __int64 RsRNAT;
   __int64 RsPFS;
   __int64 StIPSR;
   __int64 StIIP;
   __int64 StIFS;
   __int64 StFPSR;
   __int64 StISR;
   __int64 StIFA;
   __int64 StIIPA;
   __int64 StIIM;
   __int64 StIHA;
   unsigned long OldIrql;
   unsigned long PreviousMode;
   __int64 TrapFrame;
   unsigned char ExceptionRecord[160];
   __int64 Handler;
   __int64 EOFMarker;
} IA64_KTRAP_FRAME;

typedef struct _READCONTROLSPACE32
{
   short Processor;
   unsigned char Padding1;
   unsigned char Padding2;
   unsigned long Address;
   unsigned long BufLen;
   unsigned char Buf[1];
} READCONTROLSPACE32;

typedef struct _READCONTROLSPACE64
{
   short Processor;
   unsigned char Padding1;
   unsigned char Padding2;
   unsigned char Padding3;
   unsigned char Padding4;
   unsigned char Padding5;
   unsigned char Padding6;
   __int64 Address;
   unsigned long BufLen;
   unsigned char Buf[1];
} READCONTROLSPACE64;

typedef struct _IOSPACE
{
   unsigned long Address;
   unsigned long Length;
   unsigned long Data;
} IOSPACE;

typedef struct _GET_SET_SYMPATH
{
   const char * Args;
   char * Result;
   int Length;
} GET_SET_SYMPATH;

typedef struct EXT_API_VERSION
{
   short MajorVersion;
   short MinorVersion;
   short Revision;
   short Reserved;
} EXT_API_VERSION;

typedef struct _DBGKD_SET_SPECIAL_CALL32
{
   unsigned long SpecialCall;
} DBGKD_SET_SPECIAL_CALL32;

typedef struct _DBGKD_DEBUG_IO
{
   unsigned long ApiNumber;
   short ProcessorLevel;
   short Processor;
   UNNAMED_TAG_442282C u;
} DBGKD_DEBUG_IO;

typedef struct _TRACE_DATA_SYM
{
   unsigned long SymMin;
   unsigned long SymMax;
} TRACE_DATA_SYM;

typedef struct _DBGKD_WAIT_STATE_CHANGE32
{
   unsigned long NewState;
   short ProcessorLevel;
   short Processor;
   unsigned long NumberProcessors;
   unsigned long Thread;
   unsigned long ProgramCounter;
   UNNAMED_TAG_21CB526 u;
   _DBGKD_CONTROL_REPORT ControlReport;
   _CONTEXT Context;
} DBGKD_WAIT_STATE_CHANGE32;

typedef struct _IA64_UNWIND_INFO
{
   short Version;
   short Flags;
   unsigned long DataLength;
} IA64_UNWIND_INFO;

typedef struct _CROSS_PLATFORM_WAIT_STATE_CHANGE64
{
   unsigned long NewState;
   short ProcessorLevel;
   short Processor;
   unsigned long NumberProcessors;
   unsigned long Padding4;
   __int64 Thread;
   __int64 ProgramCounter;
   UNNAMED_TAG_5B9303 u;
   _DBGKD_CONTROL_REPORT ControlReport;
   _CROSS_PLATFORM_CONTEXT Context;
} CROSS_PLATFORM_WAIT_STATE_CHANGE64;

typedef struct _DBGSS_APIMSG
{
   _PORT_MESSAGE h;
   int ApiNumber;
   long ReturnedStatus;
   _CLIENT_ID AppClientId;
   void * ContinueKey;
   UNNAMED_TAG_166D1DE u;
} DBGSS_APIMSG;

typedef union UNNAMED_TAG_F482B
{
   union {
   _DBGKM_EXCEPTION Exception;
   _DBGKM_CREATE_THREAD CreateThread;
   _DBGSS_CREATE_PROCESS CreateProcessInfo;
   _DBGKM_EXIT_THREAD ExitThread;
   _DBGKM_EXIT_PROCESS ExitProcess;
   _DBGKM_LOAD_DLL LoadDll;
   _DBGKM_UNLOAD_DLL UnloadDll;
   };
} UNNAMED_TAG_F482B;

typedef struct _DBGKM_LOAD_DLL
{
   void * FileHandle;
   void * BaseOfDll;
   unsigned long DebugInfoFileOffset;
   unsigned long DebugInfoSize;
} DBGKM_LOAD_DLL;

typedef struct _DBGKM_EXIT_THREAD
{
   long ExitStatus;
} DBGKM_EXIT_THREAD;

typedef struct _DBGSS_CREATE_PROCESS
{
   _CLIENT_ID DebugUiClientId;
   _DBGKM_CREATE_PROCESS NewProcess;
} DBGSS_CREATE_PROCESS;

typedef struct _X86PAE_HARDWARE_PDE
{
   union {
   __int64 Valid;
   __int64 Write;
   __int64 Owner;
   __int64 WriteThrough;
   __int64 CacheDisable;
   __int64 Accessed;
   __int64 Dirty;
   __int64 LargePage;
   __int64 Global;
   __int64 CopyOnWrite;
   __int64 Prototype;
   __int64 reserved0;
   __int64 PageFrameNumber;
   __int64 reserved1;
   unsigned long LowPart;
   };
   unsigned long HighPart;
   union {
   UNNAMED_TAG_5A3105D Large;
   __int64 QuadPart;
   };
} X86PAE_HARDWARE_PDE;

typedef struct UNNAMED_TAG_4C552B4
{
   union {
   __int64 Valid;
   __int64 Write;
   __int64 Owner;
   __int64 WriteThrough;
   __int64 CacheDisable;
   __int64 Accessed;
   __int64 Dirty;
   __int64 LargePage;
   __int64 Global;
   __int64 CopyOnWrite;
   __int64 Prototype;
   __int64 reserved0;
   __int64 reserved2;
   __int64 PageFrameNumber;
   __int64 reserved1;
   };
} UNNAMED_TAG_4C552B4;

typedef struct _IA64_KNONVOLATILE_CONTEXT_POINTERS
{
   _FLOAT128 * FltS0;
   _FLOAT128 * FltS1;
   _FLOAT128 * FltS2;
   _FLOAT128 * FltS3;
   _FLOAT128 * HighFloatingContext[10];
   _FLOAT128 * FltS4;
   _FLOAT128 * FltS5;
   _FLOAT128 * FltS6;
   _FLOAT128 * FltS7;
   _FLOAT128 * FltS8;
   _FLOAT128 * FltS9;
   _FLOAT128 * FltS10;
   _FLOAT128 * FltS11;
   _FLOAT128 * FltS12;
   _FLOAT128 * FltS13;
   _FLOAT128 * FltS14;
   _FLOAT128 * FltS15;
   _FLOAT128 * FltS16;
   _FLOAT128 * FltS17;
   _FLOAT128 * FltS18;
   _FLOAT128 * FltS19;
   __int64 * IntS0;
   __int64 * IntS1;
   __int64 * IntS2;
   __int64 * IntS3;
   __int64 * IntSp;
   __int64 * IntS0Nat;
   __int64 * IntS1Nat;
   __int64 * IntS2Nat;
   __int64 * IntS3Nat;
   __int64 * IntSpNat;
   __int64 * Preds;
   __int64 * BrRp;
   __int64 * BrS0;
   __int64 * BrS1;
   __int64 * BrS2;
   __int64 * BrS3;
   __int64 * BrS4;
   __int64 * ApUNAT;
   __int64 * ApLC;
   __int64 * ApEC;
   __int64 * RsPFS;
   __int64 * StFSR;
   __int64 * StFIR;
   __int64 * StFDR;
   __int64 * Cflag;
} IA64_KNONVOLATILE_CONTEXT_POINTERS;

typedef struct _DBGKM_UNLOAD_DLL
{
   void * BaseAddress;
} DBGKM_UNLOAD_DLL;

typedef struct UNNAMED_TAG_3ED869
{
   unsigned char SymbolNumber;
   char LevelChange;
   short Instructions;
} UNNAMED_TAG_3ED869;

typedef struct _DBGKM_EXIT_PROCESS
{
   long ExitStatus;
} DBGKM_EXIT_PROCESS;

typedef struct _CROSS_PLATFORM_WAIT_STATE_CHANGE32
{
   unsigned long NewState;
   short ProcessorLevel;
   short Processor;
   unsigned long NumberProcessors;
   unsigned long Thread;
   unsigned long ProgramCounter;
   UNNAMED_TAG_3C806DC u;
   _DBGKD_CONTROL_REPORT ControlReport;
   _CROSS_PLATFORM_CONTEXT Context;
} CROSS_PLATFORM_WAIT_STATE_CHANGE32;

typedef struct _IA64_CONTEXT
{
   unsigned long ContextFlags;
   unsigned long Fill1[3];
   __int64 DbI0;
   __int64 DbI1;
   __int64 DbI2;
   __int64 DbI3;
   __int64 DbI4;
   __int64 DbI5;
   __int64 DbI6;
   __int64 DbI7;
   __int64 DbD0;
   __int64 DbD1;
   __int64 DbD2;
   __int64 DbD3;
   __int64 DbD4;
   __int64 DbD5;
   __int64 DbD6;
   __int64 DbD7;
   _FLOAT128 FltS0;
   _FLOAT128 FltS1;
   _FLOAT128 FltS2;
   _FLOAT128 FltS3;
   _FLOAT128 FltT0;
   _FLOAT128 FltT1;
   _FLOAT128 FltT2;
   _FLOAT128 FltT3;
   _FLOAT128 FltT4;
   _FLOAT128 FltT5;
   _FLOAT128 FltT6;
   _FLOAT128 FltT7;
   _FLOAT128 FltT8;
   _FLOAT128 FltT9;
   _FLOAT128 FltS4;
   _FLOAT128 FltS5;
   _FLOAT128 FltS6;
   _FLOAT128 FltS7;
   _FLOAT128 FltS8;
   _FLOAT128 FltS9;
   _FLOAT128 FltS10;
   _FLOAT128 FltS11;
   _FLOAT128 FltS12;
   _FLOAT128 FltS13;
   _FLOAT128 FltS14;
   _FLOAT128 FltS15;
   _FLOAT128 FltS16;
   _FLOAT128 FltS17;
   _FLOAT128 FltS18;
   _FLOAT128 FltS19;
   _FLOAT128 FltF32;
   _FLOAT128 FltF33;
   _FLOAT128 FltF34;
   _FLOAT128 FltF35;
   _FLOAT128 FltF36;
   _FLOAT128 FltF37;
   _FLOAT128 FltF38;
   _FLOAT128 FltF39;
   _FLOAT128 FltF40;
   _FLOAT128 FltF41;
   _FLOAT128 FltF42;
   _FLOAT128 FltF43;
   _FLOAT128 FltF44;
   _FLOAT128 FltF45;
   _FLOAT128 FltF46;
   _FLOAT128 FltF47;
   _FLOAT128 FltF48;
   _FLOAT128 FltF49;
   _FLOAT128 FltF50;
   _FLOAT128 FltF51;
   _FLOAT128 FltF52;
   _FLOAT128 FltF53;
   _FLOAT128 FltF54;
   _FLOAT128 FltF55;
   _FLOAT128 FltF56;
   _FLOAT128 FltF57;
   _FLOAT128 FltF58;
   _FLOAT128 FltF59;
   _FLOAT128 FltF60;
   _FLOAT128 FltF61;
   _FLOAT128 FltF62;
   _FLOAT128 FltF63;
   _FLOAT128 FltF64;
   _FLOAT128 FltF65;
   _FLOAT128 FltF66;
   _FLOAT128 FltF67;
   _FLOAT128 FltF68;
   _FLOAT128 FltF69;
   _FLOAT128 FltF70;
   _FLOAT128 FltF71;
   _FLOAT128 FltF72;
   _FLOAT128 FltF73;
   _FLOAT128 FltF74;
   _FLOAT128 FltF75;
   _FLOAT128 FltF76;
   _FLOAT128 FltF77;
   _FLOAT128 FltF78;
   _FLOAT128 FltF79;
   _FLOAT128 FltF80;
   _FLOAT128 FltF81;
   _FLOAT128 FltF82;
   _FLOAT128 FltF83;
   _FLOAT128 FltF84;
   _FLOAT128 FltF85;
   _FLOAT128 FltF86;
   _FLOAT128 FltF87;
   _FLOAT128 FltF88;
   _FLOAT128 FltF89;
   _FLOAT128 FltF90;
   _FLOAT128 FltF91;
   _FLOAT128 FltF92;
   _FLOAT128 FltF93;
   _FLOAT128 FltF94;
   _FLOAT128 FltF95;
   _FLOAT128 FltF96;
   _FLOAT128 FltF97;
   _FLOAT128 FltF98;
   _FLOAT128 FltF99;
   _FLOAT128 FltF100;
   _FLOAT128 FltF101;
   _FLOAT128 FltF102;
   _FLOAT128 FltF103;
   _FLOAT128 FltF104;
   _FLOAT128 FltF105;
   _FLOAT128 FltF106;
   _FLOAT128 FltF107;
   _FLOAT128 FltF108;
   _FLOAT128 FltF109;
   _FLOAT128 FltF110;
   _FLOAT128 FltF111;
   _FLOAT128 FltF112;
   _FLOAT128 FltF113;
   _FLOAT128 FltF114;
   _FLOAT128 FltF115;
   _FLOAT128 FltF116;
   _FLOAT128 FltF117;
   _FLOAT128 FltF118;
   _FLOAT128 FltF119;
   _FLOAT128 FltF120;
   _FLOAT128 FltF121;
   _FLOAT128 FltF122;
   _FLOAT128 FltF123;
   _FLOAT128 FltF124;
   _FLOAT128 FltF125;
   _FLOAT128 FltF126;
   _FLOAT128 FltF127;
   __int64 StFPSR;
   __int64 IntGp;
   __int64 IntT0;
   __int64 IntT1;
   __int64 IntS0;
   __int64 IntS1;
   __int64 IntS2;
   __int64 IntS3;
   __int64 IntV0;
   __int64 IntT2;
   __int64 IntT3;
   __int64 IntT4;
   __int64 IntSp;
   __int64 IntTeb;
   __int64 IntT5;
   __int64 IntT6;
   __int64 IntT7;
   __int64 IntT8;
   __int64 IntT9;
   __int64 IntT10;
   __int64 IntT11;
   __int64 IntT12;
   __int64 IntT13;
   __int64 IntT14;
   __int64 IntT15;
   __int64 IntT16;
   __int64 IntT17;
   __int64 IntT18;
   __int64 IntT19;
   __int64 IntT20;
   __int64 IntT21;
   __int64 IntT22;
   __int64 IntNats;
   __int64 Preds;
   __int64 BrRp;
   __int64 BrS0;
   __int64 BrS1;
   __int64 BrS2;
   __int64 BrS3;
   __int64 BrS4;
   __int64 BrT0;
   __int64 BrT1;
   __int64 ApUNAT;
   __int64 ApLC;
   __int64 ApEC;
   __int64 ApCCV;
   __int64 ApDCR;
   __int64 RsPFS;
   __int64 RsBSP;
   __int64 RsBSPSTORE;
   __int64 RsRSC;
   __int64 RsRNAT;
   __int64 StIPSR;
   __int64 StIIP;
   __int64 StIFS;
   __int64 StFCR;
   __int64 Eflag;
   __int64 SegCSD;
   __int64 SegSSD;
   __int64 Cflag;
   __int64 StFSR;
   __int64 StFIR;
   __int64 StFDR;
   __int64 UNUSEDPACK;
} IA64_CONTEXT;

typedef struct _ALPHA_NT5_CONTEXT
{
   __int64 FltF0;
   __int64 FltF1;
   __int64 FltF2;
   __int64 FltF3;
   __int64 FltF4;
   __int64 FltF5;
   __int64 FltF6;
   __int64 FltF7;
   __int64 FltF8;
   __int64 FltF9;
   __int64 FltF10;
   __int64 FltF11;
   __int64 FltF12;
   __int64 FltF13;
   __int64 FltF14;
   __int64 FltF15;
   __int64 FltF16;
   __int64 FltF17;
   __int64 FltF18;
   __int64 FltF19;
   __int64 FltF20;
   __int64 FltF21;
   __int64 FltF22;
   __int64 FltF23;
   __int64 FltF24;
   __int64 FltF25;
   __int64 FltF26;
   __int64 FltF27;
   __int64 FltF28;
   __int64 FltF29;
   __int64 FltF30;
   __int64 FltF31;
   __int64 IntV0;
   __int64 IntT0;
   __int64 IntT1;
   __int64 IntT2;
   __int64 IntT3;
   __int64 IntT4;
   __int64 IntT5;
   __int64 IntT6;
   __int64 IntT7;
   __int64 IntS0;
   __int64 IntS1;
   __int64 IntS2;
   __int64 IntS3;
   __int64 IntS4;
   __int64 IntS5;
   __int64 IntFp;
   __int64 IntA0;
   __int64 IntA1;
   __int64 IntA2;
   __int64 IntA3;
   __int64 IntA4;
   __int64 IntA5;
   __int64 IntT8;
   __int64 IntT9;
   __int64 IntT10;
   __int64 IntT11;
   __int64 IntRa;
   __int64 IntT12;
   __int64 IntAt;
   __int64 IntGp;
   __int64 IntSp;
   __int64 IntZero;
   __int64 Fpcr;
   __int64 SoftFpcr;
   __int64 Fir;
   unsigned long Psr;
   unsigned long ContextFlags;
   unsigned long Fill[4];
} ALPHA_NT5_CONTEXT;

typedef struct _ALPHA_CONTEXT
{
   unsigned long FltF0;
   unsigned long FltF1;
   unsigned long FltF2;
   unsigned long FltF3;
   unsigned long FltF4;
   unsigned long FltF5;
   unsigned long FltF6;
   unsigned long FltF7;
   unsigned long FltF8;
   unsigned long FltF9;
   unsigned long FltF10;
   unsigned long FltF11;
   unsigned long FltF12;
   unsigned long FltF13;
   unsigned long FltF14;
   unsigned long FltF15;
   unsigned long FltF16;
   unsigned long FltF17;
   unsigned long FltF18;
   unsigned long FltF19;
   unsigned long FltF20;
   unsigned long FltF21;
   unsigned long FltF22;
   unsigned long FltF23;
   unsigned long FltF24;
   unsigned long FltF25;
   unsigned long FltF26;
   unsigned long FltF27;
   unsigned long FltF28;
   unsigned long FltF29;
   unsigned long FltF30;
   unsigned long FltF31;
   unsigned long IntV0;
   unsigned long IntT0;
   unsigned long IntT1;
   unsigned long IntT2;
   unsigned long IntT3;
   unsigned long IntT4;
   unsigned long IntT5;
   unsigned long IntT6;
   unsigned long IntT7;
   unsigned long IntS0;
   unsigned long IntS1;
   unsigned long IntS2;
   unsigned long IntS3;
   unsigned long IntS4;
   unsigned long IntS5;
   unsigned long IntFp;
   unsigned long IntA0;
   unsigned long IntA1;
   unsigned long IntA2;
   unsigned long IntA3;
   unsigned long IntA4;
   unsigned long IntA5;
   unsigned long IntT8;
   unsigned long IntT9;
   unsigned long IntT10;
   unsigned long IntT11;
   unsigned long IntRa;
   unsigned long IntT12;
   unsigned long IntAt;
   unsigned long IntGp;
   unsigned long IntSp;
   unsigned long IntZero;
   unsigned long Fpcr;
   unsigned long SoftFpcr;
   unsigned long Fir;
   unsigned long Psr;
   unsigned long ContextFlags;
   unsigned long HighFltF0;
   unsigned long HighFltF1;
   unsigned long HighFltF2;
   unsigned long HighFltF3;
   unsigned long HighFltF4;
   unsigned long HighFltF5;
   unsigned long HighFltF6;
   unsigned long HighFltF7;
   unsigned long HighFltF8;
   unsigned long HighFltF9;
   unsigned long HighFltF10;
   unsigned long HighFltF11;
   unsigned long HighFltF12;
   unsigned long HighFltF13;
   unsigned long HighFltF14;
   unsigned long HighFltF15;
   unsigned long HighFltF16;
   unsigned long HighFltF17;
   unsigned long HighFltF18;
   unsigned long HighFltF19;
   unsigned long HighFltF20;
   unsigned long HighFltF21;
   unsigned long HighFltF22;
   unsigned long HighFltF23;
   unsigned long HighFltF24;
   unsigned long HighFltF25;
   unsigned long HighFltF26;
   unsigned long HighFltF27;
   unsigned long HighFltF28;
   unsigned long HighFltF29;
   unsigned long HighFltF30;
   unsigned long HighFltF31;
   unsigned long HighIntV0;
   unsigned long HighIntT0;
   unsigned long HighIntT1;
   unsigned long HighIntT2;
   unsigned long HighIntT3;
   unsigned long HighIntT4;
   unsigned long HighIntT5;
   unsigned long HighIntT6;
   unsigned long HighIntT7;
   unsigned long HighIntS0;
   unsigned long HighIntS1;
   unsigned long HighIntS2;
   unsigned long HighIntS3;
   unsigned long HighIntS4;
   unsigned long HighIntS5;
   unsigned long HighIntFp;
   unsigned long HighIntA0;
   unsigned long HighIntA1;
   unsigned long HighIntA2;
   unsigned long HighIntA3;
   unsigned long HighIntA4;
   unsigned long HighIntA5;
   unsigned long HighIntT8;
   unsigned long HighIntT9;
   unsigned long HighIntT10;
   unsigned long HighIntT11;
   unsigned long HighIntRa;
   unsigned long HighIntT12;
   unsigned long HighIntAt;
   unsigned long HighIntGp;
   unsigned long HighIntSp;
   unsigned long HighIntZero;
   unsigned long HighFpcr;
   unsigned long HighSoftFpcr;
   unsigned long HighFir;
   double DoNotUseThisField;
   unsigned long HighFill[2];
} ALPHA_CONTEXT;

typedef struct _CROSS_PLATFORM_CONTEXT
{
   union {
   _X86_CONTEXT X86Context;
   _X86_NT5_CONTEXT X86Nt5Context;
   _ALPHA_CONTEXT AlphaContext;
   _ALPHA_NT5_CONTEXT AlphaNt5Context;
   _IA64_CONTEXT IA64Context;
   };
} CROSS_PLATFORM_CONTEXT;

typedef union UNNAMED_TAG_13B752E
{
   union {
   _DBGKM_EXCEPTION32 Exception;
   _DBGKD_LOAD_SYMBOLS32 LoadSymbols;
   };
} UNNAMED_TAG_13B752E;

typedef struct _DBGKD_LOAD_SYMBOLS32
{
   unsigned long PathNameLength;
   unsigned long BaseOfDll;
   unsigned long ProcessId;
   unsigned long CheckSum;
   unsigned long SizeOfImage;
   unsigned char UnloadSymbols;
} DBGKD_LOAD_SYMBOLS32;

typedef struct _DBGKM_EXCEPTION32
{
   _EXCEPTION_RECORD32 ExceptionRecord;
   unsigned long FirstChance;
} DBGKM_EXCEPTION32;

typedef struct _X86_NT5_CONTEXT
{
   unsigned long ContextFlags;
   unsigned long Dr0;
   unsigned long Dr1;
   unsigned long Dr2;
   unsigned long Dr3;
   unsigned long Dr6;
   unsigned long Dr7;
   _X86_FLOATING_SAVE_AREA FloatSave;
   unsigned long SegGs;
   unsigned long SegFs;
   unsigned long SegEs;
   unsigned long SegDs;
   unsigned long Edi;
   unsigned long Esi;
   unsigned long Ebx;
   unsigned long Edx;
   unsigned long Ecx;
   unsigned long Eax;
   unsigned long Ebp;
   unsigned long Eip;
   unsigned long SegCs;
   unsigned long EFlags;
   unsigned long Esp;
   unsigned long SegSs;
   unsigned char ExtendedRegisters[512];
} X86_NT5_CONTEXT;

typedef struct _EXTSTACKTRACE64
{
   __int64 FramePointer;
   __int64 ProgramCounter;
   __int64 ReturnAddress;
   __int64 Args[4];
} EXTSTACKTRACE64;

typedef struct _DBGKD_PRINT_STRING
{
   unsigned long LengthOfString;
} DBGKD_PRINT_STRING;

typedef struct _DBGKD_WAIT_STATE_CHANGE64
{
   unsigned long NewState;
   short ProcessorLevel;
   short Processor;
   unsigned long NumberProcessors;
   unsigned long Padding4;
   __int64 Thread;
   __int64 ProgramCounter;
   UNNAMED_TAG_1E28880 u;
   _DBGKD_CONTROL_REPORT ControlReport;
   _CONTEXT Context;
} DBGKD_WAIT_STATE_CHANGE64;

typedef union UNNAMED_TAG_80740B
{
   union {
   _DBGKM_EXCEPTION64 Exception;
   _DBGKD_LOAD_SYMBOLS64 LoadSymbols;
   };
} UNNAMED_TAG_80740B;

typedef struct _DBGKD_LOAD_SYMBOLS64
{
   unsigned long PathNameLength;
   unsigned long Padding1;
   __int64 BaseOfDll;
   __int64 ProcessId;
   unsigned long CheckSum;
   unsigned long SizeOfImage;
   unsigned char UnloadSymbols;
} DBGKD_LOAD_SYMBOLS64;

typedef struct _DBGKM_EXCEPTION
{
   _EXCEPTION_RECORD ExceptionRecord;
   unsigned long FirstChance;
} DBGKM_EXCEPTION;

typedef struct _X86PAE_HARDWARE_PTE
{
   union {
   __int64 Valid;
   __int64 Write;
   __int64 Owner;
   __int64 WriteThrough;
   __int64 CacheDisable;
   __int64 Accessed;
   __int64 Dirty;
   __int64 LargePage;
   __int64 Global;
   __int64 CopyOnWrite;
   __int64 Prototype;
   __int64 reserved0;
   __int64 PageFrameNumber;
   __int64 reserved1;
   unsigned long LowPart;
   };
   unsigned long HighPart;
} X86PAE_HARDWARE_PTE;

typedef struct _DBGKD_MANIPULATE_STATE64
{
   unsigned long ApiNumber;
   short ProcessorLevel;
   short Processor;
   long ReturnStatus;
   unsigned long Padding4;
   UNNAMED_TAG_5B78E47 u;
} DBGKD_MANIPULATE_STATE64;

typedef union UNNAMED_TAG_10B5C3D
{
   union {
   _DBGKD_READ_MEMORY64 ReadMemory;
   _DBGKD_WRITE_MEMORY64 WriteMemory;
   _DBGKD_GET_CONTEXT GetContext;
   _DBGKD_SET_CONTEXT SetContext;
   _DBGKD_WRITE_BREAKPOINT64 WriteBreakPoint;
   _DBGKD_RESTORE_BREAKPOINT RestoreBreakPoint;
   _DBGKD_CONTINUE Continue;
   _DBGKD_CONTINUE2 Continue2;
   _DBGKD_READ_WRITE_IO64 ReadWriteIo;
   _DBGKD_READ_WRITE_IO_EXTENDED64 ReadWriteIoExtended;
   _DBGKD_QUERY_SPECIAL_CALLS QuerySpecialCalls;
   _DBGKD_SET_SPECIAL_CALL64 SetSpecialCall;
   _DBGKD_SET_INTERNAL_BREAKPOINT64 SetInternalBreakpoint;
   _DBGKD_GET_INTERNAL_BREAKPOINT64 GetInternalBreakpoint;
   _DBGKD_GET_VERSION64 GetVersion64;
   _DBGKD_BREAKPOINTEX BreakPointEx;
   _DBGKD_READ_WRITE_MSR ReadWriteMsr;
   _DBGKD_SEARCH_MEMORY SearchMemory;
   _DBGKD_GET_SET_BUS_DATA GetSetBusData;
   };
} UNNAMED_TAG_10B5C3D;

typedef struct _DBGKD_READ_WRITE_MSR
{
   unsigned long Msr;
   unsigned long DataValueLow;
   unsigned long DataValueHigh;
} DBGKD_READ_WRITE_MSR;

typedef struct _DBGKD_BREAKPOINTEX
{
   unsigned long BreakPointCount;
   long ContinueStatus;
} DBGKD_BREAKPOINTEX;

typedef struct _DBGKD_GET_VERSION64
{
   short MajorVersion;
   short MinorVersion;
   short ProtocolVersion;
   short Flags;
   short MachineType;
   short Unused[3];
   __int64 KernBase;
   __int64 PsLoadedModuleList;
   __int64 DebuggerDataList;
} DBGKD_GET_VERSION64;

typedef struct _DBGKD_GET_INTERNAL_BREAKPOINT64
{
   __int64 BreakpointAddress;
   unsigned long Flags;
   unsigned long Calls;
   unsigned long MaxCallsPerPeriod;
   unsigned long MinInstructions;
   unsigned long MaxInstructions;
   unsigned long TotalInstructions;
} DBGKD_GET_INTERNAL_BREAKPOINT64;

typedef struct _DBGKD_SET_INTERNAL_BREAKPOINT64
{
   __int64 BreakpointAddress;
   unsigned long Flags;
} DBGKD_SET_INTERNAL_BREAKPOINT64;

typedef struct _DBGKD_SET_SPECIAL_CALL64
{
   __int64 SpecialCall;
} DBGKD_SET_SPECIAL_CALL64;

typedef struct _DBGKD_QUERY_SPECIAL_CALLS
{
   unsigned long NumberOfSpecialCalls;
} DBGKD_QUERY_SPECIAL_CALLS;

typedef struct _DBGKD_READ_WRITE_IO_EXTENDED64
{
   unsigned long DataSize;
   unsigned long InterfaceType;
   unsigned long BusNumber;
   unsigned long AddressSpace;
   __int64 IoAddress;
   unsigned long DataValue;
} DBGKD_READ_WRITE_IO_EXTENDED64;

typedef struct _DBGKD_CONTINUE2
{
   long ContinueStatus;
   _DBGKD_CONTROL_SET ControlSet;
} DBGKD_CONTINUE2;

typedef struct _DBGKD_RESTORE_BREAKPOINT
{
   unsigned long BreakPointHandle;
} DBGKD_RESTORE_BREAKPOINT;

typedef struct _DBGKD_SET_CONTEXT
{
   unsigned long ContextFlags;
} DBGKD_SET_CONTEXT;

typedef struct _DBGKD_GET_CONTEXT
{
   unsigned long Unused;
} DBGKD_GET_CONTEXT;

typedef struct _DBGKD_WRITE_MEMORY64
{
   __int64 TargetBaseAddress;
   unsigned long TransferCount;
   unsigned long ActualBytesWritten;
} DBGKD_WRITE_MEMORY64;

typedef struct _WINDBG_EXTENSION_APIS
{
   unsigned long nSize;
   void * lpOutputRoutine;
   void * lpGetExpressionRoutine;
   void * lpGetSymbolRoutine;
   void * lpDisasmRoutine;
   void * lpCheckControlCRoutine;
   void * lpReadProcessMemoryRoutine;
   void * lpWriteProcessMemoryRoutine;
   void * lpGetThreadContextRoutine;
   void * lpSetThreadContextRoutine;
   void * lpIoctlRoutine;
   void * lpStackTraceRoutine;
} WINDBG_EXTENSION_APIS;

typedef struct _EXTSTACKTRACE
{
   unsigned long FramePointer;
   unsigned long ProgramCounter;
   unsigned long ReturnAddress;
   unsigned long Args[4];
} EXTSTACKTRACE;

typedef struct _DBGKD_READ_WRITE_IO64
{
   __int64 IoAddress;
   unsigned long DataSize;
   unsigned long DataValue;
} DBGKD_READ_WRITE_IO64;

typedef struct _DBGKD_READ_MEMORY64
{
   __int64 TargetBaseAddress;
   unsigned long TransferCount;
   unsigned long ActualBytesRead;
} DBGKD_READ_MEMORY64;

typedef struct _GET_CURRENT_PROCESS_ADDRESS
{
   unsigned long Processor;
   unsigned long Padding1;
   __int64 CurrentThread;
   __int64 Address;
} GET_CURRENT_PROCESS_ADDRESS;

typedef struct _DBGUI_CONTINUE
{
   _CLIENT_ID AppClientId;
   long ContinueStatus;
} DBGUI_CONTINUE;

typedef struct _DBGKM_EXCEPTION64
{
   _EXCEPTION_RECORD64 ExceptionRecord;
   unsigned long FirstChance;
} DBGKM_EXCEPTION64;

typedef struct _X86_FLOATING_SAVE_AREA
{
   unsigned long ControlWord;
   unsigned long StatusWord;
   unsigned long TagWord;
   unsigned long ErrorOffset;
   unsigned long ErrorSelector;
   unsigned long DataOffset;
   unsigned long DataSelector;
   unsigned char RegisterArea[80];
   unsigned long Cr0NpxState;
} X86_FLOATING_SAVE_AREA;

typedef struct _X86_CONTEXT
{
   unsigned long ContextFlags;
   unsigned long Dr0;
   unsigned long Dr1;
   unsigned long Dr2;
   unsigned long Dr3;
   unsigned long Dr6;
   unsigned long Dr7;
   _X86_FLOATING_SAVE_AREA FloatSave;
   unsigned long SegGs;
   unsigned long SegFs;
   unsigned long SegEs;
   unsigned long SegDs;
   unsigned long Edi;
   unsigned long Esi;
   unsigned long Ebx;
   unsigned long Edx;
   unsigned long Ecx;
   unsigned long Eax;
   unsigned long Ebp;
   unsigned long Eip;
   unsigned long SegCs;
   unsigned long EFlags;
   unsigned long Esp;
   unsigned long SegSs;
} X86_CONTEXT;

typedef struct _X86_KPROCESSOR_STATE
{
   _X86_CONTEXT ContextFrame;
   _X86_KSPECIAL_REGISTERS SpecialRegisters;
} X86_KPROCESSOR_STATE;

typedef struct _PAE_ADDRESS
{
   union {
   unsigned long Offset;
   unsigned long Table;
   unsigned long Directory;
   unsigned long DirectoryPointer;
   UNNAMED_TAG_46945E8 LargeAddress;
   unsigned long DwordPart;
   };
} PAE_ADDRESS;

typedef struct UNNAMED_TAG_AED9A9
{
   union {
   unsigned long Offset;
   unsigned long Directory;
   unsigned long DirectoryPointer;
   };
} UNNAMED_TAG_AED9A9;

typedef struct _IA64_KSWITCH_FRAME
{
   __int64 SwitchPredicates;
   __int64 SwitchRp;
   __int64 SwitchPFS;
   __int64 SwitchFPSR;
   __int64 SwitchBsp;
   __int64 SwitchRnat;
   _IA64_KEXCEPTION_FRAME SwitchExceptionFrame;
} IA64_KSWITCH_FRAME;

typedef struct _IA64_KEXCEPTION_FRAME
{
   __int64 ApEC;
   __int64 ApLC;
   __int64 IntNats;
   __int64 IntS0;
   __int64 IntS1;
   __int64 IntS2;
   __int64 IntS3;
   __int64 BrS0;
   __int64 BrS1;
   __int64 BrS2;
   __int64 BrS3;
   __int64 BrS4;
   _FLOAT128 FltS0;
   _FLOAT128 FltS1;
   _FLOAT128 FltS2;
   _FLOAT128 FltS3;
   _FLOAT128 FltS4;
   _FLOAT128 FltS5;
   _FLOAT128 FltS6;
   _FLOAT128 FltS7;
   _FLOAT128 FltS8;
   _FLOAT128 FltS9;
   _FLOAT128 FltS10;
   _FLOAT128 FltS11;
   _FLOAT128 FltS12;
   _FLOAT128 FltS13;
   _FLOAT128 FltS14;
   _FLOAT128 FltS15;
   _FLOAT128 FltS16;
   _FLOAT128 FltS17;
   _FLOAT128 FltS18;
   _FLOAT128 FltS19;
} IA64_KEXCEPTION_FRAME;

typedef struct _IA64_KSPECIAL_REGISTERS
{
   __int64 KernelDbI0;
   __int64 KernelDbI1;
   __int64 KernelDbI2;
   __int64 KernelDbI3;
   __int64 KernelDbI4;
   __int64 KernelDbI5;
   __int64 KernelDbI6;
   __int64 KernelDbI7;
   __int64 KernelDbD0;
   __int64 KernelDbD1;
   __int64 KernelDbD2;
   __int64 KernelDbD3;
   __int64 KernelDbD4;
   __int64 KernelDbD5;
   __int64 KernelDbD6;
   __int64 KernelDbD7;
   __int64 KernelPfC0;
   __int64 KernelPfC1;
   __int64 KernelPfC2;
   __int64 KernelPfC3;
   __int64 KernelPfC4;
   __int64 KernelPfC5;
   __int64 KernelPfC6;
   __int64 KernelPfC7;
   __int64 KernelPfD0;
   __int64 KernelPfD1;
   __int64 KernelPfD2;
   __int64 KernelPfD3;
   __int64 KernelPfD4;
   __int64 KernelPfD5;
   __int64 KernelPfD6;
   __int64 KernelPfD7;
   __int64 IntH16;
   __int64 IntH17;
   __int64 IntH18;
   __int64 IntH19;
   __int64 IntH20;
   __int64 IntH21;
   __int64 IntH22;
   __int64 IntH23;
   __int64 IntH24;
   __int64 IntH25;
   __int64 IntH26;
   __int64 IntH27;
   __int64 IntH28;
   __int64 IntH29;
   __int64 IntH30;
   __int64 IntH31;
   __int64 ApCPUID0;
   __int64 ApCPUID1;
   __int64 ApCPUID2;
   __int64 ApCPUID3;
   __int64 ApCPUID4;
   __int64 ApCPUID5;
   __int64 ApCPUID6;
   __int64 ApCPUID7;
   __int64 ApKR0;
   __int64 ApKR1;
   __int64 ApKR2;
   __int64 ApKR3;
   __int64 ApKR4;
   __int64 ApKR5;
   __int64 ApKR6;
   __int64 ApKR7;
   __int64 ApITC;
   __int64 ApITM;
   __int64 ApIVA;
   __int64 ApPTA;
   __int64 ApGPTA;
   __int64 StISR;
   __int64 StIFA;
   __int64 StITIR;
   __int64 StIIPA;
   __int64 StIIM;
   __int64 StIHA;
   __int64 SaLID;
   __int64 SaIVR;
   __int64 SaTPR;
   __int64 SaEOI;
   __int64 SaIRR0;
   __int64 SaIRR1;
   __int64 SaIRR2;
   __int64 SaIRR3;
   __int64 SaITV;
   __int64 SaPMV;
   __int64 SaCMCV;
   __int64 SaLRR0;
   __int64 SaLRR1;
   __int64 Rr0;
   __int64 Rr1;
   __int64 Rr2;
   __int64 Rr3;
   __int64 Rr4;
   __int64 Rr5;
   __int64 Rr6;
   __int64 Rr7;
   __int64 Pkr0;
   __int64 Pkr1;
   __int64 Pkr2;
   __int64 Pkr3;
   __int64 Pkr4;
   __int64 Pkr5;
   __int64 Pkr6;
   __int64 Pkr7;
   __int64 Pkr8;
   __int64 Pkr9;
   __int64 Pkr10;
   __int64 Pkr11;
   __int64 Pkr12;
   __int64 Pkr13;
   __int64 Pkr14;
   __int64 Pkr15;
   __int64 TrI0;
   __int64 TrI1;
   __int64 TrI2;
   __int64 TrI3;
   __int64 TrI4;
   __int64 TrI5;
   __int64 TrI6;
   __int64 TrI7;
   __int64 TrD0;
   __int64 TrD1;
   __int64 TrD2;
   __int64 TrD3;
   __int64 TrD4;
   __int64 TrD5;
   __int64 TrD6;
   __int64 TrD7;
   __int64 SrMSR0;
   __int64 SrMSR1;
   __int64 SrMSR2;
   __int64 SrMSR3;
   __int64 SrMSR4;
   __int64 SrMSR5;
   __int64 SrMSR6;
   __int64 SrMSR7;
} IA64_KSPECIAL_REGISTERS;

typedef struct _IA64_THREAD
{
   _DISPATCHER_HEADER64 Header;
   LIST_ENTRY64 MutantListHead;
   __int64 InitialStack;
   __int64 StackLimit;
   __int64 InitialBStore;
   __int64 BStoreLimit;
   __int64 Teb;
   __int64 TlsArray;
   __int64 KernelStack;
   __int64 KernelBStore;
   unsigned char DebugActive;
   unsigned char State;
   unsigned char Alerted[2];
   unsigned char Iopl;
   unsigned char NpxState;
   char Saturation;
   char Priority;
   _KAPC_STATE64 ApcState;
} IA64_THREAD;

typedef struct _KAPC_STATE64
{
   LIST_ENTRY64 ApcListHead[2];
   __int64 Process;
   unsigned char KernelApcInProgress;
   unsigned char KernelApcPending;
   unsigned char UserApcPending;
} KAPC_STATE64;

typedef struct _DISPATCHER_HEADER64
{
   unsigned char Type;
   unsigned char Absolute;
   unsigned char Size;
   unsigned char Inserted;
   long SignalState;
   LIST_ENTRY64 WaitListHead;
} DISPATCHER_HEADER64;

typedef struct _AXP64_THREAD
{
   _DISPATCHER_HEADER64 Header;
   LIST_ENTRY64 MutantListHead;
   __int64 InitialStack;
   __int64 StackLimit;
   __int64 Teb;
   __int64 TlsArray;
   __int64 KernelStack;
   unsigned char DebugActive;
   unsigned char State;
   unsigned char Alerted[2];
   unsigned char Iopl;
   unsigned char NpxState;
   char Saturation;
   char Priority;
   _KAPC_STATE64 ApcState;
} AXP64_THREAD;

typedef struct _ALPHA_THREAD
{
   _DISPATCHER_HEADER32 Header;
   LIST_ENTRY32 MutantListHead;
   unsigned long InitialStack;
   unsigned long StackLimit;
   unsigned long Teb;
   unsigned long TlsArray;
   unsigned long KernelStack;
   unsigned char DebugActive;
   unsigned char State;
   unsigned char Alerted[2];
   unsigned char Iopl;
   unsigned char NpxState;
   char Saturation;
   char Priority;
   _KAPC_STATE32 ApcState;
} ALPHA_THREAD;

typedef struct _KAPC_STATE32
{
   LIST_ENTRY32 ApcListHead[2];
   unsigned long Process;
   unsigned char KernelApcInProgress;
   unsigned char KernelApcPending;
   unsigned char UserApcPending;
} KAPC_STATE32;

typedef struct _DISPATCHER_HEADER32
{
   unsigned char Type;
   unsigned char Absolute;
   unsigned char Size;
   unsigned char Inserted;
   long SignalState;
   LIST_ENTRY32 WaitListHead;
} DISPATCHER_HEADER32;

typedef struct _X86_THREAD
{
   _DISPATCHER_HEADER32 Header;
   LIST_ENTRY32 MutantListHead;
   unsigned long InitialStack;
   unsigned long StackLimit;
   unsigned long Teb;
   unsigned long TlsArray;
   unsigned long KernelStack;
   unsigned char DebugActive;
   unsigned char State;
   unsigned char Alerted[2];
   unsigned char Iopl;
   unsigned char NpxState;
   char Saturation;
   char Priority;
   _KAPC_STATE32 ApcState;
} X86_THREAD;

typedef struct _CROSS_PLATFORM_THREAD
{
   union {
   _X86_THREAD X86Thread;
   _ALPHA_THREAD AlphaThread;
   _AXP64_THREAD Axp64Thread;
   _IA64_THREAD IA64Thread;
   };
} CROSS_PLATFORM_THREAD;

typedef union _DBGKD_TRACE_DATA
{
   union {
   UNNAMED_TAG_3D5E325 s;
   unsigned long LongNumber;
   };
} DBGKD_TRACE_DATA;

typedef struct _X86_KSPECIAL_REGISTERS
{
   unsigned long Cr0;
   unsigned long Cr2;
   unsigned long Cr3;
   unsigned long Cr4;
   unsigned long KernelDr0;
   unsigned long KernelDr1;
   unsigned long KernelDr2;
   unsigned long KernelDr3;
   unsigned long KernelDr6;
   unsigned long KernelDr7;
   _X86_DESCRIPTOR Gdtr;
   _X86_DESCRIPTOR Idtr;
   short Tr;
   short Ldtr;
   unsigned long Reserved[6];
} X86_KSPECIAL_REGISTERS;

typedef struct _DBGKD_CONTINUE
{
   long ContinueStatus;
} DBGKD_CONTINUE;

typedef struct _DBGKD_READ_WRITE_IO32
{
   unsigned long DataSize;
   unsigned long IoAddress;
   unsigned long DataValue;
} DBGKD_READ_WRITE_IO32;

typedef struct _DBGKD_WRITE_BREAKPOINT64
{
   __int64 BreakPointAddress;
   unsigned long BreakPointHandle;
} DBGKD_WRITE_BREAKPOINT64;

typedef struct _DBGKD_GET_SET_BUS_DATA
{
   unsigned long BusDataType;
   unsigned long BusNumber;
   unsigned long SlotNumber;
   unsigned long Offset;
   unsigned long Length;
} DBGKD_GET_SET_BUS_DATA;

typedef struct _SEARCHMEMORY
{
   __int64 SearchAddress;
   __int64 SearchLength;
   __int64 FoundAddress;
   unsigned long PatternLength;
   void * Pattern;
} SEARCHMEMORY;

typedef struct _X86_DESCRIPTOR
{
   short Pad;
   short Limit;
   unsigned long Base;
} X86_DESCRIPTOR;

typedef struct _DBGKM_CREATE_THREAD
{
   unsigned long SubSystemKey;
   void * StartAddress;
} DBGKM_CREATE_THREAD;

typedef struct _DBGKM_CREATE_PROCESS
{
   unsigned long SubSystemKey;
   void * FileHandle;
   void * BaseOfImage;
   unsigned long DebugInfoFileOffset;
   unsigned long DebugInfoSize;
   _DBGKM_CREATE_THREAD InitialThread;
} DBGKM_CREATE_PROCESS;

typedef struct _DBGKD_SEARCH_MEMORY
{
   union {
   __int64 SearchAddress;
   __int64 FoundAddress;
   };
   __int64 SearchLength;
   unsigned long PatternLength;
} DBGKD_SEARCH_MEMORY;

typedef struct _POOL_DESCRIPTOR
{
   unsigned long RunningAllocs;
   unsigned long RunningDeAllocs;
   unsigned long TotalPages;
   unsigned long TotalBigPages;
   _LIST_ENTRY ListHeads[128];
} POOL_DESCRIPTOR;

typedef struct _LAUNCH_DATA_PAGE
{
   _LAUNCH_DATA_HEADER Header;
   unsigned char Pad[492];
   unsigned char LaunchData[3072];
} LAUNCH_DATA_PAGE;

typedef struct UNNAMED_TAG_35B4BB2
{
   union {
   unsigned long Valid;
   unsigned long OneEntry;
   unsigned long NextEntry;
   };
} UNNAMED_TAG_35B4BB2;

typedef struct _MMPFN
{
   union {
   unsigned long Long;
   _MMPTE Pte;
   _MMPFNFREE Free;
   UNNAMED_TAG_2971462 Busy;
   UNNAMED_TAG_4D6BDE0 FsCache;
   UNNAMED_TAG_40DA515 Directory;
   };
} MMPFN;

typedef struct UNNAMED_TAG_278888E
{
   union {
   unsigned long LockCount;
   unsigned long Busy;
   unsigned long NumberOfUsedPtes;
   unsigned long BusyType;
   };
} UNNAMED_TAG_278888E;

typedef struct UNNAMED_TAG_1125978
{
   union {
   unsigned long LockCount;
   unsigned long Busy;
   unsigned long ElementIndex;
   unsigned long BusyType;
   };
} UNNAMED_TAG_1125978;

typedef struct UNNAMED_TAG_4D8DE9A
{
   union {
   unsigned long LockCount;
   unsigned long Busy;
   unsigned long Reserved;
   unsigned long PteIndex;
   unsigned long BusyType;
   };
} UNNAMED_TAG_4D8DE9A;

typedef struct _POOL_LOOKASIDE_LIST
{
   _SLIST_HEADER ListHead;
   short Depth;
   short Padding;
   unsigned long TotalAllocates;
   unsigned long AllocateHits;
} POOL_LOOKASIDE_LIST;

typedef struct _POOL_HEADER
{
   unsigned char PreviousSize;
   unsigned char PoolIndex;
   unsigned char PoolType;
   unsigned char BlockSize;
   unsigned long Ulong1;
   unsigned long PoolTag;
} POOL_HEADER;

typedef struct _POOL_TRACKER_BIG_PAGES
{
   void * Va;
   unsigned long Key;
   unsigned long NumberOfPages;
} POOL_TRACKER_BIG_PAGES;

typedef struct _MMVAD
{
   unsigned long StartingVpn;
   unsigned long EndingVpn;
   _MMADDRESS_NODE * Parent;
   _MMADDRESS_NODE * LeftChild;
   _MMADDRESS_NODE * RightChild;
   unsigned long AllocationProtect;
} MMVAD;

typedef struct _XBOOT_PARAM
{
   unsigned long UncompressedKernelDataSize;
   unsigned long InitTableSize;
   unsigned long Signature;
   unsigned long CompressedKernelSize;
   unsigned char MainRomDigest[20];
} XBOOT_PARAM;

typedef struct _XDATA_SECTION_HEADER
{
   unsigned long SizeOfUninitializedData;
   unsigned long SizeOfInitializedData;
   unsigned long PointerToRawData;
   unsigned long VirtualAddress;
   unsigned long SizeOfAVTables;
} XDATA_SECTION_HEADER;

typedef struct _LZXBOX_BLOCK
{
   short CompressedSize;
   short UncompressedSize;
} LZXBOX_BLOCK;

typedef struct _LAUNCH_DATA_HEADER
{
   unsigned long dwLaunchDataType;
   unsigned long dwTitleId;
   char szLaunchPath[520];
   unsigned long dwFlags;
} LAUNCH_DATA_HEADER;

typedef struct _POOL_TRACKER_TABLE
{
   unsigned long Key;
   unsigned long NonPagedAllocs;
   unsigned long NonPagedFrees;
   unsigned long NonPagedBytes;
} POOL_TRACKER_TABLE;

typedef struct _POOL_BLOCK
{
   unsigned char Fill[32];
} POOL_BLOCK;

typedef struct _MMADDRESS_NODE
{
   unsigned long StartingVpn;
   unsigned long EndingVpn;
   _MMADDRESS_NODE * Parent;
   _MMADDRESS_NODE * LeftChild;
   _MMADDRESS_NODE * RightChild;
} MMADDRESS_NODE;

typedef struct _MMPTE
{
   union {
   unsigned long Long;
   _HARDWARE_PTE Hard;
   UNNAMED_TAG_4890AF4 List;
   };
} MMPTE;

typedef struct _MMPTERANGE
{
   _MMPTE HeadPte;
   _MMPTE * FirstCommittedPte;
   _MMPTE * LastCommittedPte;
   _MMPTE * LastReservedPte;
   unsigned long * AvailablePages;
   void * RemovePageRoutine;
} MMPTERANGE;

typedef struct _MMPFNFREE
{
   short PackedPfnFlink;
   short PackedPfnBlink;
} MMPFNFREE;

typedef struct _MMPFNREGION
{
   _MMPFNFREE FreePagesByColor[32];
   unsigned long AvailablePages;
} MMPFNREGION;

typedef struct _MMGLOBALDATA
{
   _MMPFNREGION * RetailPfnRegion;
   _MMPTERANGE * SystemPteRange;
   unsigned long * AvailablePages;
   unsigned long * AllocatedPagesByUsage;
   _RTL_CRITICAL_SECTION * AddressSpaceLock;
   _MMADDRESS_NODE * * VadRoot;
   _MMADDRESS_NODE * * VadHint;
   _MMADDRESS_NODE * * VadFreeHint;
} MMGLOBALDATA;

typedef struct _KAPC_RECORD
{
   void * NormalRoutine;
   void * NormalContext;
   void * SystemArgument1;
   void * SystemArgument2;
} KAPC_RECORD;

typedef union UNNAMED_TAG_43A2C74
{
   union {
   unsigned char value;
   UNNAMED_TAG_30DD8EA Fields;
   };
} UNNAMED_TAG_43A2C74;

typedef struct UNNAMED_TAG_308D6CD
{
   union {
   unsigned char Link;
   unsigned char Flag;
   unsigned char Reserved;
   unsigned char VendorUnique;
   };
} UNNAMED_TAG_308D6CD;

typedef union UNNAMED_TAG_3ACCFFA
{
   union {
   UNNAMED_TAG_4D0C28A bits;
   unsigned long AsULONG;
   };
} UNNAMED_TAG_3ACCFFA;

typedef struct UNNAMED_TAG_BED97
{
   union {
   unsigned long DeviceNumber;
   unsigned long FunctionNumber;
   unsigned long Reserved;
   };
} UNNAMED_TAG_BED97;

typedef struct _SCSI_PASS_THROUGH_DIRECT
{
   short Length;
   unsigned char ScsiStatus;
   unsigned char PathId;
   unsigned char TargetId;
   unsigned char Lun;
   unsigned char CdbLength;
   unsigned char SenseInfoLength;
   unsigned char DataIn;
   unsigned char Padding8;
   unsigned char Padding9;
   unsigned char Padding10;
   unsigned long DataTransferLength;
   unsigned long TimeOutValue;
   void * DataBuffer;
   unsigned long SenseInfoOffset;
   unsigned char Cdb[16];
} SCSI_PASS_THROUGH_DIRECT;

typedef struct _SCSI_PASS_THROUGH
{
   short Length;
   unsigned char ScsiStatus;
   unsigned char PathId;
   unsigned char TargetId;
   unsigned char Lun;
   unsigned char CdbLength;
   unsigned char SenseInfoLength;
   unsigned char DataIn;
   unsigned char Padding8;
   unsigned char Padding9;
   unsigned char Padding10;
   unsigned long DataTransferLength;
   unsigned long TimeOutValue;
   unsigned long DataBufferOffset;
   unsigned long SenseInfoOffset;
   unsigned char Cdb[16];
} SCSI_PASS_THROUGH;

typedef struct UNNAMED_TAG_46E7A48
{
   unsigned char Width;
} UNNAMED_TAG_46E7A48;

typedef struct UNNAMED_TAG_12A3415
{
   unsigned char TransferPeriod;
   unsigned char ReqAckOffset;
} UNNAMED_TAG_12A3415;

typedef struct UNNAMED_TAG_49EC0C2
{
   unsigned char Modifier[4];
} UNNAMED_TAG_49EC0C2;

typedef struct _POWER_CONDITION_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved;
   unsigned char PSBit;
   };
   unsigned char PageLength;
   unsigned char Reserved2;
   union {
   unsigned char Standby;
   unsigned char Idle;
   unsigned char Reserved3;
   };
   unsigned char IdleTimer[4];
   unsigned char StandbyTimer[4];
} POWER_CONDITION_PAGE;

typedef struct RC4_KEYSTRUCT
{
   unsigned char S[256];
   unsigned char i;
   unsigned char j;
} RC4_KEYSTRUCT;

typedef struct _MODE_PARM_READ_WRITE
{
   _MODE_PARAMETER_HEADER ParameterListHeader;
   _MODE_PARAMETER_BLOCK ParameterListBlock;
} MODE_PARM_READ_WRITE;

typedef struct UNNAMED_TAG_59DDB6F
{
   unsigned long Base;
   unsigned long Limit;
} UNNAMED_TAG_59DDB6F;

typedef struct _CDVD_CAPABILITIES_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved;
   unsigned char PSBit;
   };
   unsigned char PageLength;
   union {
   unsigned char CDRRead;
   unsigned char CDERead;
   unsigned char Method2;
   unsigned char DVDROMRead;
   unsigned char DVDRRead;
   unsigned char DVDRAMRead;
   unsigned char Reserved2;
   };
   union {
   unsigned char CDRWrite;
   unsigned char CDEWrite;
   unsigned char TestWrite;
   unsigned char Reserved3;
   unsigned char DVDRWrite;
   unsigned char DVDRAMWrite;
   unsigned char Reserved4;
   };
   union {
   unsigned char AudioPlay;
   unsigned char Composite;
   unsigned char DigitalPortOne;
   unsigned char DigitalPortTwo;
   unsigned char Mode2Form1;
   unsigned char Mode2Form2;
   unsigned char MultiSession;
   unsigned char Reserved5;
   };
   union {
   unsigned char CDDA;
   unsigned char CDDAAccurate;
   unsigned char RWSupported;
   unsigned char RWDeinterleaved;
   unsigned char C2Pointers;
   unsigned char ISRC;
   unsigned char UPC;
   unsigned char ReadBarCodeCapable;
   };
   union {
   unsigned char Lock;
   unsigned char LockState;
   unsigned char PreventJumper;
   unsigned char Eject;
   unsigned char Reserved6;
   unsigned char LoadingMechanismType;
   };
   union {
   unsigned char SeparateVolume;
   unsigned char SeperateChannelMute;
   unsigned char SupportsDiskPresent;
   unsigned char SWSlotSelection;
   unsigned char SideChangeCapable;
   unsigned char RWInLeadInReadable;
   unsigned char Reserved7;
   };
   unsigned char ObsoleteReserved[2];
   unsigned char NumberVolumeLevels[2];
   unsigned char BufferSize[2];
   unsigned char ObsoleteReserved2[2];
   unsigned char ObsoleteReserved3;
   union {
   unsigned char Reserved8;
   unsigned char BCK;
   unsigned char RCK;
   unsigned char LSBF;
   unsigned char Length;
   unsigned char Reserved9;
   };
   unsigned char ObsoleteReserved4[2];
   unsigned char CopyManagementRevision[2];
   unsigned char Reserved10[2];
} CDVD_CAPABILITIES_PAGE;

typedef union UNNAMED_TAG_51BC191
{
   union {
   UNNAMED_TAG_46AA5AA bits;
   unsigned long AsULONG;
   };
} UNNAMED_TAG_51BC191;

typedef struct UNNAMED_TAG_48C567E
{
   union {
   unsigned long Reserved1;
   unsigned long RegisterNumber;
   unsigned long FunctionNumber;
   unsigned long DeviceNumber;
   unsigned long BusNumber;
   unsigned long Reserved2;
   unsigned long Enable;
   };
} UNNAMED_TAG_48C567E;

typedef struct _READ_CAPACITY_DATA
{
   unsigned long LogicalBlockAddress;
   unsigned long BytesPerBlock;
} READ_CAPACITY_DATA;

typedef struct _DVDX2_AUTHENTICATION_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved;
   unsigned char PSBit;
   };
   unsigned char PageLength;
   unsigned char PartitionArea;
   unsigned char CDFValid;
   unsigned char Authentication;
   unsigned char DiscCategoryAndVersion;
   unsigned char DrivePhaseLevel;
   unsigned char ChallengeID;
   unsigned long ChallengeValue;
   unsigned long ResponseValue;
   unsigned long Reserved2;
} DVDX2_AUTHENTICATION_PAGE;

typedef struct _DVDX2_AUTHENTICATION
{
   _MODE_PARAMETER_HEADER10 Header;
   _DVDX2_AUTHENTICATION_PAGE AuthenticationPage;
} DVDX2_AUTHENTICATION;

typedef struct _IDE_CHANNEL_OBJECT
{
   void * InterruptRoutine;
   void * FinishIoRoutine;
   void * PollResetCompleteRoutine;
   void * TimeoutExpiredRoutine;
   void * StartPacketRoutine;
   void * StartNextPacketRoutine;
   unsigned char InterruptIrql;
   unsigned char ExpectingBusMasterInterrupt;
   unsigned char StartPacketBusy;
   unsigned char StartPacketRequested;
   unsigned char Timeout;
   unsigned char IoRetries;
   unsigned char MaximumIoRetries;
   unsigned char Padding13;
   _IRP * CurrentIrp;
   _KDEVICE_QUEUE DeviceQueue;
   unsigned long PhysicalRegionDescriptorTablePhysical;
   _KDPC TimerDpc;
   _KDPC FinishDpc;
   _KTIMER Timer;
   _KINTERRUPT InterruptObject;
} IDE_CHANNEL_OBJECT;

typedef struct _FORMATTED_CAPACITY_LIST
{
   unsigned char Reserved[3];
   unsigned char CapacityListLength;
   _FORMATTED_CAPACITY_DESCRIPTOR Descriptors[0];
} FORMATTED_CAPACITY_LIST;

typedef struct A_SHA_CTX
{
   unsigned long FinishFlag;
   unsigned char HashVal[20];
   unsigned long state[5];
   unsigned long count[2];
   unsigned char buffer[64];
} A_SHA_CTX;

typedef struct _CDVD_KEY_HEADER
{
   unsigned char DataLength[2];
   unsigned char Reserved[2];
   unsigned char Data[0];
} CDVD_KEY_HEADER;

typedef struct _XBOX_FACTORY_SETTINGS
{
   unsigned long Checksum;
   unsigned char SerialNumber[12];
   unsigned char EthernetAddr[6];
   unsigned char Reserved1[2];
   unsigned char OnlineKey[16];
   unsigned long AVRegion;
   unsigned long Reserved2;
} XBOX_FACTORY_SETTINGS;

typedef union _FOUR_BYTE
{
   unsigned char Byte0;
   unsigned char Byte1;
   unsigned char Byte2;
   unsigned char Byte3;
   unsigned long AsULong;
} FOUR_BYTE;

typedef struct _PCI_AGP_COMMAND
{
   union {
   unsigned long Rate;
   unsigned long Rsvd1;
   unsigned long FastWriteEnable;
   unsigned long FourGBEnable;
   unsigned long Rsvd2;
   unsigned long AGPEnable;
   unsigned long SBAEnable;
   unsigned long Rsvd3;
   unsigned long RequestQueueDepth;
   };
} PCI_AGP_COMMAND;

typedef struct _PCI_AGP_STATUS
{
   union {
   unsigned long Rate;
   unsigned long Rsvd1;
   unsigned long FastWrite;
   unsigned long FourGB;
   unsigned long Rsvd2;
   unsigned long SideBandAddressing;
   unsigned long Rsvd3;
   unsigned long RequestQueueDepthMaximum;
   };
} PCI_AGP_STATUS;

typedef struct _PCI_AGP_CAPABILITY
{
   _PCI_CAPABILITIES_HEADER Header;
   union {
   short Minor;
   short Major;
   short Rsvd1;
   };
   _PCI_AGP_STATUS AGPStatus;
   _PCI_AGP_COMMAND AGPCommand;
} PCI_AGP_CAPABILITY;

typedef struct _PCI_TYPE2_CSE_BITS
{
   UNNAMED_TAG_22116E6 u;
} PCI_TYPE2_CSE_BITS;

typedef union UNNAMED_TAG_2A7B8DD
{
   union {
   UNNAMED_TAG_40CEB5B bits;
   unsigned char AsUCHAR;
   };
} UNNAMED_TAG_2A7B8DD;

typedef struct UNNAMED_TAG_442282C
{
   union {
   unsigned char Enable;
   unsigned char FunctionNumber;
   unsigned char Key;
   };
} UNNAMED_TAG_442282C;

typedef struct _CDVD_TITLE_KEY_HEADER
{
   unsigned char DataLength[2];
   unsigned char Reserved1[1];
   union {
   unsigned char Reserved2;
   unsigned char CGMS;
   unsigned char CP_SEC;
   unsigned char CPM;
   unsigned char Zero;
   };
   _CDVD_KEY_DATA TitleKey;
} CDVD_TITLE_KEY_HEADER;

typedef struct _PCI_TYPE2_ADDRESS_BITS
{
   UNNAMED_TAG_1FF910B u;
} PCI_TYPE2_ADDRESS_BITS;

typedef union UNNAMED_TAG_21CB526
{
   union {
   UNNAMED_TAG_10F7DEC bits;
   short AsUSHORT;
   };
} UNNAMED_TAG_21CB526;

typedef struct UNNAMED_TAG_5B9303
{
   union {
   short RegisterNumber;
   short Agent;
   short AddressBase;
   };
} UNNAMED_TAG_5B9303;

typedef struct _DVD_COPY_PROTECT_KEY
{
   unsigned long KeyLength;
   unsigned long SessionId;
   int KeyType;
   unsigned long KeyFlags;
   UNNAMED_TAG_1CFCAD2 Parameters;
   unsigned char KeyData[0];
} DVD_COPY_PROTECT_KEY;

typedef union UNNAMED_TAG_166D1DE
{
   union {
   void * FileHandle;
   _LARGE_INTEGER TitleOffset;
   };
} UNNAMED_TAG_166D1DE;

typedef struct _PCI_TYPE1_CFG_BITS
{
   UNNAMED_TAG_47747A0 u;
} PCI_TYPE1_CFG_BITS;

typedef struct _XBOX_ENCRYPTED_SETTINGS
{
   unsigned char Checksum[20];
   unsigned char Confounder[8];
   unsigned char HDKey[16];
   unsigned long GameRegion;
} XBOX_ENCRYPTED_SETTINGS;

typedef struct _MECHANICAL_STATUS
{
   _MECHANICAL_STATUS_INFORMATION_HEADER MechanicalStatusHeader;
   _SLOT_TABLE_INFORMATION SlotTableInfo[1];
} MECHANICAL_STATUS;

typedef struct _READ_DVD_STRUCTURES_HEADER
{
   unsigned char Length[2];
   unsigned char Reserved[2];
   unsigned char Data[0];
} READ_DVD_STRUCTURES_HEADER;

typedef struct _MODE_DISCONNECT_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved;
   unsigned char PageSavable;
   };
   unsigned char PageLength;
   unsigned char BufferFullRatio;
   unsigned char BufferEmptyRatio;
   unsigned char BusInactivityLimit[2];
   unsigned char BusDisconnectTime[2];
   unsigned char BusConnectTime[2];
   unsigned char MaximumBurstSize[2];
   unsigned char DataTransferDisconnect;
   unsigned char Reserved2[3];
} MODE_DISCONNECT_PAGE;

typedef struct _CDVD_REPORT_AGID_DATA
{
   unsigned char Reserved1[3];
   union {
   unsigned char Reserved2;
   unsigned char AGID;
   };
} CDVD_REPORT_AGID_DATA;

typedef struct _STORAGE_SET_READ_AHEAD
{
   _LARGE_INTEGER TriggerAddress;
   _LARGE_INTEGER TargetAddress;
} STORAGE_SET_READ_AHEAD;

typedef struct CRYPTO_VECTOR
{
   void * pXcSHAInit;
   void * pXcSHAUpdate;
   void * pXcSHAFinal;
   void * pXcRC4Key;
   void * pXcRC4Crypt;
   void * pXcHMAC;
   void * pXcPKEncPublic;
   void * pXcPKDecPrivate;
   void * pXcPKGetKeyLen;
   void * pXcVerifyPKCS1Signature;
   void * pXcModExp;
   void * pXcDESKeyParity;
   void * pXcKeyTable;
   void * pXcBlockCrypt;
   void * pXcBlockCryptCBC;
   void * pXcCryptService;
} CRYPTO_VECTOR;

typedef struct _XBOX_HW_EE_SETTINGS
{
   unsigned char FbioDelay;
   unsigned char AddrDrv;
   unsigned char CTrim2;
   unsigned char EMRS;
   unsigned char ExtSlow[10];
   unsigned char Slow[10];
   unsigned char Typical[10];
   unsigned char Fast[10];
   unsigned char ExtFast[10];
} XBOX_HW_EE_SETTINGS;

typedef struct _AUDIO_OUTPUT
{
   unsigned char CodePage;
   unsigned char ParameterLength;
   unsigned char Immediate;
   unsigned char Reserved[2];
   unsigned char LbaFormat;
   unsigned char LogicalBlocksPerSecond[2];
   _PORT_OUTPUT PortOutput[4];
} AUDIO_OUTPUT;

typedef struct _DVD_SET_RPC_KEY
{
   unsigned char PreferredDriveRegionCode;
   unsigned char Reserved[3];
} DVD_SET_RPC_KEY;

typedef struct UNNAMED_TAG_5A3105D
{
   unsigned char Reserved;
   unsigned char M;
   unsigned char S;
   unsigned char F;
} UNNAMED_TAG_5A3105D;

typedef struct _MODE_PARAMETER_BLOCK
{
   unsigned char DensityCode;
   unsigned char NumberOfBlocks[3];
   unsigned char Reserved;
   unsigned char BlockLength[3];
} MODE_PARAMETER_BLOCK;

typedef struct _CDVD_INACTIVITY_TIMEOUT_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved;
   unsigned char PSBit;
   };
   unsigned char PageLength;
   unsigned char Reserved2[2];
   union {
   unsigned char SWPP;
   unsigned char DISP;
   unsigned char Reserved3;
   };
   unsigned char Reserved4;
   unsigned char GroupOneMinimumTimeout[2];
   unsigned char GroupTwoMinimumTimeout[2];
} CDVD_INACTIVITY_TIMEOUT_PAGE;

typedef struct _CDVD_REPORT_ASF_DATA
{
   unsigned char Reserved1[3];
   union {
   unsigned char Success;
   unsigned char Reserved2;
   };
} CDVD_REPORT_ASF_DATA;

typedef struct _CDVD_CHALLENGE_KEY_DATA
{
   unsigned char ChallengeKeyValue[10];
   unsigned char Reserved[2];
} CDVD_CHALLENGE_KEY_DATA;

typedef struct _PCI_PM_CAPABILITY
{
   _PCI_CAPABILITIES_HEADER Header;
   UNNAMED_TAG_1BC922B PMC;
   UNNAMED_TAG_C3E894 PMCSR;
   UNNAMED_TAG_5EE146 PMCSR_BSE;
   unsigned char Data;
} PCI_PM_CAPABILITY;

typedef union UNNAMED_TAG_3C806DC
{
   union {
   _PCI_PMCSR_BSE BridgeSupport;
   unsigned char AsUCHAR;
   };
} UNNAMED_TAG_3C806DC;

typedef struct _PCI_PMCSR_BSE
{
   union {
   unsigned char Rsvd1;
   unsigned char D3HotSupportsStopClock;
   unsigned char BusPowerClockControlEnabled;
   };
} PCI_PMCSR_BSE;

typedef union UNNAMED_TAG_1E28880
{
   union {
   _PCI_PMCSR ControlStatus;
   short AsUSHORT;
   };
} UNNAMED_TAG_1E28880;

typedef union UNNAMED_TAG_5B78E47
{
   union {
   _PCI_PMC Capabilities;
   short AsUSHORT;
   };
} UNNAMED_TAG_5B78E47;

typedef struct _DVD_COPYRIGHT_DESCRIPTOR
{
   unsigned char CopyrightProtectionType;
   unsigned char RegionManagementInformation;
   short Reserved;
} DVD_COPYRIGHT_DESCRIPTOR;

typedef struct _PCI_SLOT_NUMBER::__unnamed::__unnamed
{
   union {
   unsigned long DeviceNumber;
   unsigned long FunctionNumber;
   unsigned long Reserved;
   };
} PCI_SLOT_NUMBER::__unnamed::__unnamed;

typedef union _PCI_SLOT_NUMBER::__unnamed
{
   union {
   _PCI_SLOT_NUMBER::__unnamed::__unnamed bits;
   unsigned long AsULONG;
   };
} PCI_SLOT_NUMBER::__unnamed;

typedef struct _PCI_SLOT_NUMBER
{
   _PCI_SLOT_NUMBER::__unnamed u;
} PCI_SLOT_NUMBER;

typedef union _EXTENDED_ARGUMENTS
{
   union {
   UNNAMED_TAG_4226AB2 Modify;
   UNNAMED_TAG_49D3446 Synchronous;
   UNNAMED_TAG_5B49DAC Wide;
   };
} EXTENDED_ARGUMENTS;

typedef struct _SCSI_EXTENDED_MESSAGE
{
   unsigned char InitialMessageCode;
   unsigned char MessageLength;
   unsigned char MessageType;
   _EXTENDED_ARGUMENTS ExtendedArguments;
} SCSI_EXTENDED_MESSAGE;

typedef struct _TRACK_INFORMATION
{
   unsigned char Length[2];
   unsigned char TrackNumber;
   unsigned char SessionNumber;
   unsigned char Reserved1;
   union {
   unsigned char TrackMode;
   unsigned char Copy;
   unsigned char Damage;
   unsigned char Reserved2;
   };
   union {
   unsigned char DataMode;
   unsigned char FP;
   unsigned char Packet;
   unsigned char Blank;
   unsigned char RT;
   };
   union {
   unsigned char NWA_V;
   unsigned char Reserved3;
   };
   unsigned char TrackStartAddress[4];
   unsigned char NextWritableAddress[4];
   unsigned char FreeBlocks[4];
   unsigned char FixedPacketSize[4];
} TRACK_INFORMATION;

typedef struct _DATA_BLOCK_HEADER
{
   unsigned char DataMode;
   unsigned char Reserved[4];
   union {
   unsigned char LogicalBlockAddress[4];
   UNNAMED_TAG_5E5A1D MSF;
   };
} DATA_BLOCK_HEADER;

typedef struct _MODE_FLEXIBLE_DISK_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved;
   unsigned char PageSavable;
   };
   unsigned char PageLength;
   unsigned char TransferRate[2];
   unsigned char NumberOfHeads;
   unsigned char SectorsPerTrack;
   unsigned char BytesPerSector[2];
   unsigned char NumberOfCylinders[2];
   unsigned char StartWritePrecom[2];
   unsigned char StartReducedCurrent[2];
   unsigned char StepRate[2];
   unsigned char StepPluseWidth;
   unsigned char HeadSettleDelay[2];
   unsigned char MotorOnDelay;
   unsigned char MotorOffDelay;
   union {
   unsigned char Reserved2;
   unsigned char MotorOnAsserted;
   unsigned char StartSectorNumber;
   unsigned char TrueReadySignal;
   };
   union {
   unsigned char StepPlusePerCyclynder;
   unsigned char Reserved3;
   };
   unsigned char WriteCompenstation;
   unsigned char HeadLoadDelay;
   unsigned char HeadUnloadDelay;
   union {
   unsigned char Pin2Usage;
   unsigned char Pin34Usage;
   };
   union {
   unsigned char Pin1Usage;
   unsigned char Pin4Usage;
   };
   unsigned char MediumRotationRate[2];
   unsigned char Reserved4[2];
} MODE_FLEXIBLE_DISK_PAGE;

typedef struct _DVDX2_ADVANCED_DRIVE_CONTROL
{
   _MODE_PARAMETER_HEADER10 Header;
   _DVDX2_ADVANCED_DRIVE_CONTROL_PAGE AdvancedDriveControlPage;
} DVDX2_ADVANCED_DRIVE_CONTROL;

typedef struct _MODE_INFO_EXCEPTIONS
{
   union {
   unsigned char PageCode;
   unsigned char Reserved1;
   unsigned char PSBit;
   };
   unsigned char PageLength;
   union {
   unsigned char LogErr;
   unsigned char Reserved2;
   unsigned char Test;
   unsigned char Dexcpt;
   unsigned char Reserved3;
   unsigned char Perf;
   };
   union {
   unsigned char ReportMethod;
   unsigned char Reserved4;
   };
   unsigned char IntervalTimer[4];
   unsigned char ReportCount[4];
} MODE_INFO_EXCEPTIONS;

typedef struct _CDVD_KEY_DATA
{
   unsigned char Key[5];
   unsigned char Reserved[3];
} CDVD_KEY_DATA;

typedef struct _XBOX_USER_SETTINGS
{
   unsigned long Checksum;
   long TimeZoneBias;
   char TimeZoneStdName[4];
   char TimeZoneDltName[4];
   unsigned long Reserved1[2];
   _XBOX_TIMEZONE_DATE TimeZoneStdDate;
   _XBOX_TIMEZONE_DATE TimeZoneDltDate;
   unsigned long Reserved2[2];
   long TimeZoneStdBias;
   long TimeZoneDltBias;
   unsigned long Language;
   unsigned long VideoFlags;
   unsigned long AudioFlags;
   unsigned long ParentalControlGames;
   unsigned long ParentalControlPassword;
   unsigned long ParentalControlMovies;
   unsigned long OnlineIpAddress;
   unsigned long OnlineDnsAddress;
   unsigned long OnlineDefaultGatewayAddress;
   unsigned long OnlineSubnetMask;
   unsigned long MiscFlags;
   unsigned long DvdRegion;
} XBOX_USER_SETTINGS;

typedef struct _DVD_BCA_DESCRIPTOR
{
   unsigned char BCAInformation[0];
} DVD_BCA_DESCRIPTOR;

typedef struct _CDDA_OUTPUT_PORT
{
   union {
   unsigned char ChannelSelection;
   unsigned char Reserved;
   };
   unsigned char Volume;
} CDDA_OUTPUT_PORT;

typedef struct _CDAUDIO_CONTROL_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved;
   unsigned char PSBit;
   };
   unsigned char PageLength;
   union {
   unsigned char Reserved2;
   unsigned char StopOnTrackCrossing;
   unsigned char Immediate;
   unsigned char Reserved3;
   };
   unsigned char Reserved4[3];
   unsigned char Obsolete[2];
   _CDDA_OUTPUT_PORT CDDAOutputPorts[4];
} CDAUDIO_CONTROL_PAGE;

typedef union _TWO_BYTE
{
   unsigned char Byte0;
   unsigned char Byte1;
   short AsUShort;
} TWO_BYTE;

typedef struct _TAPE_POSITION_DATA
{
   union {
   unsigned char Reserved1;
   unsigned char BlockPositionUnsupported;
   unsigned char Reserved2;
   unsigned char EndOfPartition;
   unsigned char BeginningOfPartition;
   };
   unsigned char PartitionNumber;
   short Reserved3;
   unsigned char FirstBlock[4];
   unsigned char LastBlock[4];
   unsigned char Reserved4;
   unsigned char NumberOfBlocks[3];
   unsigned char NumberOfBytes[4];
} TAPE_POSITION_DATA;

typedef struct _MODE_PARAMETER_HEADER10
{
   unsigned char ModeDataLength[2];
   unsigned char MediumType;
   unsigned char DeviceSpecificParameter;
   unsigned char Reserved[2];
   unsigned char BlockDescriptorLength[2];
} MODE_PARAMETER_HEADER10;

typedef struct _SRB_IO_CONTROL
{
   unsigned long HeaderLength;
   unsigned char Signature[8];
   unsigned long Timeout;
   unsigned long ControlCode;
   unsigned long ReturnCode;
   unsigned long Length;
} SRB_IO_CONTROL;

typedef struct _READ_BLOCK_LIMITS
{
   unsigned char Reserved;
   unsigned char BlockMaximumSize[3];
   unsigned char BlockMinimumSize[2];
} READ_BLOCK_LIMITS;

typedef struct _NOTIFICATION_POWER_STATUS
{
   union {
   unsigned char PowerEvent;
   unsigned char Reserved;
   };
   unsigned char PowerStatus;
   unsigned char Reserved2[2];
} NOTIFICATION_POWER_STATUS;

typedef struct _DVD_ASF
{
   unsigned char Reserved0[3];
   union {
   unsigned char SuccessFlag;
   unsigned char Reserved1;
   };
} DVD_ASF;

typedef struct _SCSI_BUS_DATA
{
   unsigned char NumberOfLogicalUnits;
   unsigned char InitiatorBusId;
   unsigned char Padding2;
   unsigned char Padding3;
   unsigned long InquiryDataOffset;
} SCSI_BUS_DATA;

typedef struct _SCSI_ADAPTER_BUS_INFO
{
   unsigned char NumberOfBuses;
   unsigned char Padding1;
   unsigned char Padding2;
   unsigned char Padding3;
   _SCSI_BUS_DATA BusData[1];
} SCSI_ADAPTER_BUS_INFO;

typedef union UNNAMED_TAG_46945E8
{
   union {
   unsigned long AsULong;
   UNNAMED_TAG_2271310 b;
   };
} UNNAMED_TAG_46945E8;

typedef struct UNNAMED_TAG_3D5E325
{
   union {
   unsigned long AsUShort;
   unsigned long Reserved;
   unsigned long EndOfTable;
   };
} UNNAMED_TAG_3D5E325;

typedef struct _INQUIRYDATA
{
   union {
   unsigned char DeviceType;
   unsigned char DeviceTypeQualifier;
   };
   union {
   unsigned char DeviceTypeModifier;
   unsigned char RemovableMedia;
   };
   unsigned char Versions;
   union {
   unsigned char ResponseDataFormat;
   unsigned char HiSupport;
   unsigned char NormACA;
   unsigned char ReservedBit;
   unsigned char AERC;
   };
   unsigned char AdditionalLength;
   unsigned char Reserved[2];
   union {
   unsigned char SoftReset;
   unsigned char CommandQueue;
   unsigned char Reserved2;
   unsigned char LinkedCommands;
   unsigned char Synchronous;
   unsigned char Wide16Bit;
   unsigned char Wide32Bit;
   unsigned char RelativeAddressing;
   };
   unsigned char VendorId[8];
   unsigned char ProductId[16];
   unsigned char ProductRevisionLevel[4];
   unsigned char VendorSpecific[20];
   unsigned char Reserved3[40];
} INQUIRYDATA;

typedef struct _PCI_PMC
{
   union {
   unsigned char Version;
   unsigned char PMEClock;
   unsigned char Rsvd1;
   unsigned char DeviceSpecificInitialization;
   unsigned char Rsvd2;
   };
   _PM_SUPPORT Support;
} PCI_PMC;

typedef struct _PM_SUPPORT
{
   union {
   unsigned char Rsvd2;
   unsigned char D1;
   unsigned char D2;
   unsigned char PMED0;
   unsigned char PMED1;
   unsigned char PMED2;
   unsigned char PMED3Hot;
   unsigned char PMED3Cold;
   };
} PM_SUPPORT;

typedef struct _PCI_TYPE1_CFG_CYCLE_BITS
{
   UNNAMED_TAG_5CC3A82 u;
} PCI_TYPE1_CFG_CYCLE_BITS;

typedef union UNNAMED_TAG_40DA515
{
   union {
   UNNAMED_TAG_19998DD bits;
   unsigned long AsULONG;
   };
} UNNAMED_TAG_40DA515;

typedef struct UNNAMED_TAG_4D6BDE0
{
   union {
   unsigned long Reserved1;
   unsigned long RegisterNumber;
   unsigned long FunctionNumber;
   unsigned long DeviceNumber;
   unsigned long BusNumber;
   unsigned long Reserved2;
   };
} UNNAMED_TAG_4D6BDE0;

typedef struct _IDE_PCI_PHYSICAL_REGION_DESCRIPTOR
{
   unsigned long PhysicalAddress;
   UNNAMED_TAG_2A65C8D ByteCount;
} IDE_PCI_PHYSICAL_REGION_DESCRIPTOR;

typedef struct _DVD_DESCRIPTOR_HEADER
{
   short Length;
   unsigned char Reserved[2];
   unsigned char Data[0];
} DVD_DESCRIPTOR_HEADER;

typedef struct _EEPROM_LAYOUT
{
   unsigned char EncryptedSection[48];
   unsigned char FactorySection[48];
   unsigned char UserConfigSection[96];
   unsigned char HardwareConfigSection[54];
   unsigned char ThermalSensorCalibration[2];
   unsigned char Unused[2];
   unsigned char UEMInfo[4];
   unsigned char Reserved1[2];
} EEPROM_LAYOUT;

typedef struct _SCSI_INQUIRY_DATA
{
   unsigned char PathId;
   unsigned char TargetId;
   unsigned char Lun;
   unsigned char DeviceClaimed;
   unsigned long InquiryDataLength;
   unsigned long NextInquiryDataOffset;
   unsigned char InquiryData[1];
} SCSI_INQUIRY_DATA;

typedef struct DVD_READ_STRUCTURE
{
   _LARGE_INTEGER BlockByteOffset;
   int Format;
   unsigned long SessionId;
   unsigned char LayerNumber;
} DVD_READ_STRUCTURE;

typedef struct _SENSE_DATA
{
   union {
   unsigned char ErrorCode;
   unsigned char Valid;
   };
   unsigned char SegmentNumber;
   union {
   unsigned char SenseKey;
   unsigned char Reserved;
   unsigned char IncorrectLength;
   unsigned char EndOfMedia;
   unsigned char FileMark;
   };
   unsigned char Information[4];
   unsigned char AdditionalSenseLength;
   unsigned char CommandSpecificInformation[4];
   unsigned char AdditionalSenseCode;
   unsigned char AdditionalSenseCodeQualifier;
   unsigned char FieldReplaceableUnitCode;
   unsigned char SenseKeySpecific[3];
} SENSE_DATA;

typedef struct _PCI_COMMON_CONFIG
{
   short VendorID;
   short DeviceID;
   short Command;
   short Status;
   unsigned char RevisionID;
   unsigned char ProgIf;
   unsigned char SubClass;
   unsigned char BaseClass;
   unsigned char CacheLineSize;
   unsigned char LatencyTimer;
   unsigned char HeaderType;
   unsigned char BIST;
   UNNAMED_TAG_3587CAA u;
   unsigned char DeviceSpecific[192];
} PCI_COMMON_CONFIG;

typedef union UNNAMED_TAG_2971462
{
   union {
   _PCI_HEADER_TYPE_0 type0;
   _PCI_HEADER_TYPE_1 type1;
   _PCI_HEADER_TYPE_2 type2;
   };
} UNNAMED_TAG_2971462;

typedef struct _PCI_HEADER_TYPE_2
{
   unsigned long SocketRegistersBaseAddress;
   unsigned char CapabilitiesPtr;
   unsigned char Reserved;
   short SecondaryStatus;
   unsigned char PrimaryBus;
   unsigned char SecondaryBus;
   unsigned char SubordinateBus;
   unsigned char SecondaryLatency;
   UNNAMED_TAG_34CB153 Range[4];
   unsigned char InterruptLine;
   unsigned char InterruptPin;
   short BridgeControl;
} PCI_HEADER_TYPE_2;

typedef struct _PCI_HEADER_TYPE_1
{
   unsigned long BaseAddresses[2];
   unsigned char PrimaryBus;
   unsigned char SecondaryBus;
   unsigned char SubordinateBus;
   unsigned char SecondaryLatency;
   unsigned char IOBase;
   unsigned char IOLimit;
   short SecondaryStatus;
   short MemoryBase;
   short MemoryLimit;
   short PrefetchBase;
   short PrefetchLimit;
   unsigned long PrefetchBaseUpper32;
   unsigned long PrefetchLimitUpper32;
   short IOBaseUpper16;
   short IOLimitUpper16;
   unsigned char CapabilitiesPtr;
   unsigned char Reserved1[3];
   unsigned long ROMBaseAddress;
   unsigned char InterruptLine;
   unsigned char InterruptPin;
   short BridgeControl;
} PCI_HEADER_TYPE_1;

typedef struct _PCI_HEADER_TYPE_0
{
   unsigned long BaseAddresses[6];
   unsigned long CIS;
   short SubVendorID;
   short SubSystemID;
   unsigned long ROMBaseAddress;
   unsigned char CapabilitiesPtr;
   unsigned char Reserved1[3];
   unsigned long Reserved2;
   unsigned char InterruptLine;
   unsigned char InterruptPin;
   unsigned char MinimumGrant;
   unsigned char MaximumLatency;
} PCI_HEADER_TYPE_0;

typedef struct _MECHANICAL_STATUS_INFORMATION_HEADER
{
   union {
   unsigned char CurrentSlot;
   unsigned char ChangerState;
   unsigned char Fault;
   };
   union {
   unsigned char Reserved;
   unsigned char MechanismState;
   };
   unsigned char CurrentLogicalBlockAddress[3];
   unsigned char NumberAvailableSlots;
   unsigned char SlotTableLength[2];
} MECHANICAL_STATUS_INFORMATION_HEADER;

typedef struct _PCI_PMCSR
{
   union {
   short PowerState;
   short Rsvd1;
   short PMEEnable;
   short DataSelect;
   short DataScale;
   short PMEStatus;
   };
} PCI_PMCSR;

typedef union UNNAMED_TAG_4890AF4
{
   union {
   UNNAMED_TAG_1656B9 bits;
   unsigned long AsULONG;
   };
} UNNAMED_TAG_4890AF4;

typedef struct UNNAMED_TAG_30DD8EA
{
   union {
   unsigned long Reserved1;
   unsigned long RegisterNumber;
   unsigned long FunctionNumber;
   unsigned long Reserved2;
   };
} UNNAMED_TAG_30DD8EA;

typedef struct _XBOX_MTE_INFO
{
   unsigned long Signature;
   unsigned long OnlineKeyCRC;
   unsigned long HDKeyCRC;
} XBOX_MTE_INFO;

typedef struct _DVD_DISK_KEY_DESCRIPTOR
{
   unsigned char DiskKeyData[2048];
} DVD_DISK_KEY_DESCRIPTOR;

typedef struct _NOTIFICATION_BUSY_STATUS
{
   union {
   unsigned char DeviceBusyEvent;
   unsigned char Reserved;
   };
   unsigned char DeviceBusyStatus;
   unsigned char Time[2];
} NOTIFICATION_BUSY_STATUS;

typedef struct _NOTIFICATION_MEDIA_STATUS
{
   union {
   unsigned char MediaStatus;
   unsigned char Reserved;
   };
   unsigned char PowerStatus;
   unsigned char StartSlot;
   unsigned char EndSlot;
} NOTIFICATION_MEDIA_STATUS;

typedef struct _MODE_READ_RECOVERY_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved1;
   unsigned char PSBit;
   };
   unsigned char PageLength;
   union {
   unsigned char DCRBit;
   unsigned char DTEBit;
   unsigned char PERBit;
   unsigned char Reserved2;
   unsigned char RCBit;
   unsigned char TBBit;
   unsigned char Reserved3;
   };
   unsigned char ReadRetryCount;
   unsigned char Reserved4[4];
} MODE_READ_RECOVERY_PAGE;

typedef struct _MODE_FORMAT_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved;
   unsigned char PageSavable;
   };
   unsigned char PageLength;
   unsigned char TracksPerZone[2];
   unsigned char AlternateSectorsPerZone[2];
   unsigned char AlternateTracksPerZone[2];
   unsigned char AlternateTracksPerLogicalUnit[2];
   unsigned char SectorsPerTrack[2];
   unsigned char BytesPerPhysicalSector[2];
   unsigned char Interleave[2];
   unsigned char TrackSkewFactor[2];
   unsigned char CylinderSkewFactor[2];
   union {
   unsigned char Reserved2;
   unsigned char SurfaceFirst;
   unsigned char RemovableMedia;
   unsigned char HardSectorFormating;
   unsigned char SoftSectorFormating;
   };
   unsigned char Reserved3[3];
} MODE_FORMAT_PAGE;

typedef struct _MODE_PARAMETER_HEADER
{
   unsigned char ModeDataLength;
   unsigned char MediumType;
   unsigned char DeviceSpecificParameter;
   unsigned char BlockDescriptorLength;
} MODE_PARAMETER_HEADER;

typedef struct _DVDX2_HOST_CHALLENGE_RESPONSE_TABLE
{
   unsigned char Version;
   unsigned char NumberOfEntries;
   _DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY Entries[23];
} DVDX2_HOST_CHALLENGE_RESPONSE_TABLE;

typedef struct _DVDX2_CONTROL_DATA
{
   unsigned char Length[2];
   unsigned char Reserved[2];
   _DVD_LAYER_DESCRIPTOR LayerDescriptor;
   unsigned char Reserved2[15];
   unsigned char Reserved3[736];
   _DVDX2_HOST_CHALLENGE_RESPONSE_TABLE HostChallengeResponseTable;
   unsigned char Reserved4[32];
   _LARGE_INTEGER ContentSourceTimeStamp;
   unsigned char Reserved5[20];
   _GUID ContentSourceIdentifier;
   unsigned char Reserved6[83];
   unsigned char Features;
   _LARGE_INTEGER AuthoringTimeStamp;
   unsigned long TitleTimeDateStamp;
   unsigned char Reserved7[15];
   unsigned char AuthoringSystemType;
   _GUID AuthoringSystemIdentifier;
   unsigned char AuthoringHash[20];
   unsigned char AuthoringSignature[256];
   _LARGE_INTEGER MasteringTimeStamp;
   unsigned char Reserved8[19];
   unsigned char MasteringSystemType;
   _GUID MasteringSystemIdentifier;
   unsigned char MasteringHash[20];
   unsigned char MasteringSignature[64];
   unsigned char Reserved9;
} DVDX2_CONTROL_DATA;

typedef struct _DVD_RPC_KEY
{
   union {
   unsigned char UserResetsAvailable;
   unsigned char ManufacturerResetsAvailable;
   unsigned char TypeCode;
   };
   unsigned char RegionMask;
   unsigned char RpcScheme;
   unsigned char Reserved2[1];
} DVD_RPC_KEY;

typedef struct _IDE_MEDIA_BOARD_EXTENSION
{
   _DEVICE_OBJECT * DeviceObject;
   _PARTITION_INFORMATION PartitionInformation;
} IDE_MEDIA_BOARD_EXTENSION;

typedef struct _XBOX_UEM_INFO
{
   unsigned char LastCode;
   unsigned char Reserved1;
   short History;
} XBOX_UEM_INFO;

typedef struct _SCSI_ADDRESS
{
   unsigned long Length;
   unsigned char PortNumber;
   unsigned char PathId;
   unsigned char TargetId;
   unsigned char Lun;
} SCSI_ADDRESS;

typedef struct _PORT_OUTPUT
{
   unsigned char ChannelSelection;
   unsigned char Volume;
} PORT_OUTPUT;

typedef struct _PCI_TYPE0_CFG_CYCLE_BITS
{
   UNNAMED_TAG_3F30B8 u;
} PCI_TYPE0_CFG_CYCLE_BITS;

typedef union _CDB
{
   union {
   _CDB6GENERIC CDB6GENERIC;
   _CDB6GENERIC * PCDB6GENERIC;
   _CDB6READWRITE CDB6READWRITE;
   _CDB6READWRITE * PCDB6READWRITE;
   _CDB6INQUIRY CDB6INQUIRY;
   _CDB6INQUIRY * PCDB6INQUIRY;
   _CDB6VERIFY CDB6VERIFY;
   _CDB6VERIFY * PCDB6VERIFY;
   _CDB6FORMAT CDB6FORMAT;
   _CDB6FORMAT * PCDB6FORMAT;
   _CDB10 CDB10;
   _CDB10 * PCDB10;
   _CDB12 CDB12;
   _CDB12 * PCDB12;
   _PAUSE_RESUME PAUSE_RESUME;
   _PAUSE_RESUME * PPAUSE_RESUME;
   _READ_TOC READ_TOC;
   _READ_TOC * PREAD_TOC;
   _READ_DISK_INFORMATION READ_DISK_INFORMATION;
   _READ_DISK_INFORMATION * PREAD_DISK_INFORMATION;
   _READ_TRACK_INFORMATION READ_TRACK_INFORMATION;
   _READ_TRACK_INFORMATION * PREAD_TRACK_INFORMATION;
   _READ_HEADER READ_HEADER;
   _READ_HEADER * PREAD_HEADER;
   _PLAY_AUDIO PLAY_AUDIO;
   _PLAY_AUDIO * PPLAY_AUDIO;
   _PLAY_AUDIO_MSF PLAY_AUDIO_MSF;
   _PLAY_AUDIO_MSF * PPLAY_AUDIO_MSF;
   _PLAY_CD PLAY_CD;
   _PLAY_CD * PPLAY_CD;
   _SCAN_CD SCAN_CD;
   _SCAN_CD * PSCAN_CD;
   _STOP_PLAY_SCAN STOP_PLAY_SCAN;
   _STOP_PLAY_SCAN * PSTOP_PLAY_SCAN;
   _SUBCHANNEL SUBCHANNEL;
   _SUBCHANNEL * PSUBCHANNEL;
   _READ_CD READ_CD;
   _READ_CD * PREAD_CD;
   _READ_CD_MSF READ_CD_MSF;
   _READ_CD_MSF * PREAD_CD_MSF;
   _PLXTR_READ_CDDA PLXTR_READ_CDDA;
   _PLXTR_READ_CDDA * PPLXTR_READ_CDDA;
   _NEC_READ_CDDA NEC_READ_CDDA;
   _NEC_READ_CDDA * PNEC_READ_CDDA;
   _MODE_SENSE MODE_SENSE;
   _MODE_SENSE * PMODE_SENSE;
   _MODE_SENSE10 MODE_SENSE10;
   _MODE_SENSE10 * PMODE_SENSE10;
   _MODE_SELECT MODE_SELECT;
   _MODE_SELECT * PMODE_SELECT;
   _MODE_SELECT10 MODE_SELECT10;
   _MODE_SELECT10 * PMODE_SELECT10;
   _LOCATE LOCATE;
   _LOCATE * PLOCATE;
   _LOGSENSE LOGSENSE;
   _LOGSENSE * PLOGSENSE;
   _LOGSELECT LOGSELECT;
   _LOGSELECT * PLOGSELECT;
   _PRINT PRINT;
   _PRINT * PPRINT;
   _SEEK SEEK;
   _SEEK * PSEEK;
   _ERASE ERASE;
   _ERASE * PERASE;
   _START_STOP START_STOP;
   _START_STOP * PSTART_STOP;
   _MEDIA_REMOVAL MEDIA_REMOVAL;
   _MEDIA_REMOVAL * PMEDIA_REMOVAL;
   _SEEK_BLOCK SEEK_BLOCK;
   _SEEK_BLOCK * PSEEK_BLOCK;
   _REQUEST_BLOCK_ADDRESS REQUEST_BLOCK_ADDRESS;
   _REQUEST_BLOCK_ADDRESS * PREQUEST_BLOCK_ADDRESS;
   _PARTITION PARTITION;
   _PARTITION * PPARTITION;
   _WRITE_TAPE_MARKS WRITE_TAPE_MARKS;
   _WRITE_TAPE_MARKS * PWRITE_TAPE_MARKS;
   _SPACE_TAPE_MARKS SPACE_TAPE_MARKS;
   _SPACE_TAPE_MARKS * PSPACE_TAPE_MARKS;
   _READ_POSITION READ_POSITION;
   _READ_POSITION * PREAD_POSITION;
   _CDB6READWRITETAPE CDB6READWRITETAPE;
   _CDB6READWRITETAPE * PCDB6READWRITETAPE;
   _INIT_ELEMENT_STATUS INIT_ELEMENT_STATUS;
   _INIT_ELEMENT_STATUS * PINIT_ELEMENT_STATUS;
   _INITIALIZE_ELEMENT_RANGE INITIALIZE_ELEMENT_RANGE;
   _INITIALIZE_ELEMENT_RANGE * PINITIALIZE_ELEMENT_RANGE;
   _POSITION_TO_ELEMENT POSITION_TO_ELEMENT;
   _POSITION_TO_ELEMENT * PPOSITION_TO_ELEMENT;
   _MOVE_MEDIUM MOVE_MEDIUM;
   _MOVE_MEDIUM * PMOVE_MEDIUM;
   _EXCHANGE_MEDIUM EXCHANGE_MEDIUM;
   _EXCHANGE_MEDIUM * PEXCHANGE_MEDIUM;
   _READ_ELEMENT_STATUS READ_ELEMENT_STATUS;
   _READ_ELEMENT_STATUS * PREAD_ELEMENT_STATUS;
   _SEND_VOLUME_TAG SEND_VOLUME_TAG;
   _SEND_VOLUME_TAG * PSEND_VOLUME_TAG;
   _REQUEST_VOLUME_ELEMENT_ADDRESS REQUEST_VOLUME_ELEMENT_ADDRESS;
   _REQUEST_VOLUME_ELEMENT_ADDRESS * PREQUEST_VOLUME_ELEMENT_ADDRESS;
   _LOAD_UNLOAD LOAD_UNLOAD;
   _LOAD_UNLOAD * PLOAD_UNLOAD;
   _MECH_STATUS MECH_STATUS;
   _MECH_STATUS * PMECH_STATUS;
   _SYNCHRONIZE_CACHE10 SYNCHRONIZE_CACHE10;
   _SYNCHRONIZE_CACHE10 * PSYNCHRONIZE_CACHE10;
   _GET_EVENT_STATUS_NOTIFICATION GET_EVENT_STATUS_NOTIFICATION;
   _GET_EVENT_STATUS_NOTIFICATION * PGET_EVENT_STATUS_NOTIFICATION;
   _READ_DVD_STRUCTURE READ_DVD_STRUCTURE;
   _READ_DVD_STRUCTURE * PREAD_DVD_STRUCTURE;
   _SEND_KEY SEND_KEY;
   _SEND_KEY * PSEND_KEY;
   _REPORT_KEY REPORT_KEY;
   _REPORT_KEY * PREPORT_KEY;
   _SET_READ_AHEAD SET_READ_AHEAD;
   _SET_READ_AHEAD * PSET_READ_AHEAD;
   _READ_FORMATTED_CAPACITIES READ_FORMATTED_CAPACITIES;
   _READ_FORMATTED_CAPACITIES * PREAD_FORMATTED_CAPACITIES;
   _REPORT_LUNS REPORT_LUNS;
   _REPORT_LUNS * PREPORT_LUNS;
   unsigned long AsUlong[4];
   unsigned char AsByte[16];
   };
} CDB;

typedef struct _REPORT_LUNS
{
   unsigned char OperationCode;
   unsigned char Reserved1[5];
   unsigned char AllocationLength[4];
   unsigned char Reserved2[1];
   unsigned char Control;
} REPORT_LUNS;

typedef struct _READ_FORMATTED_CAPACITIES
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char Lun;
   };
   unsigned char Reserved2[5];
   unsigned char AllocationLength[2];
   unsigned char Control;
} READ_FORMATTED_CAPACITIES;

typedef struct _SET_READ_AHEAD
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char Lun;
   };
   unsigned char TriggerLBA[4];
   unsigned char ReadAheadLBA[4];
   unsigned char Reserved2;
   unsigned char Control;
} SET_READ_AHEAD;

typedef struct _REPORT_KEY
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char Lun;
   };
   unsigned char LogicalBlockAddress[4];
   unsigned char Reserved2[2];
   unsigned char AllocationLength[2];
   union {
   unsigned char KeyFormat;
   unsigned char AGID;
   };
   unsigned char Control;
} REPORT_KEY;

typedef struct _SEND_KEY
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char Lun;
   };
   unsigned char Reserved2[6];
   unsigned char ParameterListLength[2];
   union {
   unsigned char KeyFormat;
   unsigned char AGID;
   };
   unsigned char Control;
} SEND_KEY;

typedef struct _READ_DVD_STRUCTURE
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char Lun;
   };
   unsigned char RMDBlockNumber[4];
   unsigned char LayerNumber;
   unsigned char Format;
   unsigned char AllocationLength[2];
   union {
   unsigned char Reserved3;
   unsigned char AGID;
   };
   unsigned char Control;
} READ_DVD_STRUCTURE;

typedef struct _GET_EVENT_STATUS_NOTIFICATION
{
   unsigned char OperationCode;
   union {
   unsigned char Immediate;
   unsigned char Reserved;
   unsigned char Lun;
   };
   unsigned char Reserved2[2];
   unsigned char NotificationClassRequest;
   unsigned char Reserved3[2];
   unsigned char EventListLength[2];
   unsigned char Control;
} GET_EVENT_STATUS_NOTIFICATION;

typedef struct _SYNCHRONIZE_CACHE10
{
   unsigned char OperationCode;
   union {
   unsigned char RelAddr;
   unsigned char Immediate;
   unsigned char Reserved;
   unsigned char Lun;
   };
   unsigned char LogicalBlockAddress[4];
   unsigned char Reserved2;
   unsigned char BlockCount[2];
   unsigned char Control;
} SYNCHRONIZE_CACHE10;

typedef struct _MECH_STATUS
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved;
   unsigned char Lun;
   };
   unsigned char Reserved1[6];
   unsigned char AllocationLength[2];
   unsigned char Reserved2[1];
   unsigned char Control;
} MECH_STATUS;

typedef struct _LOAD_UNLOAD
{
   unsigned char OperationCode;
   union {
   unsigned char Immediate;
   unsigned char Reserved1;
   unsigned char Lun;
   };
   unsigned char Reserved2[2];
   union {
   unsigned char Start;
   unsigned char LoadEject;
   unsigned char Reserved3;
   };
   unsigned char Reserved4[3];
   unsigned char Slot;
   unsigned char Reserved5[3];
} LOAD_UNLOAD;

typedef struct _REQUEST_VOLUME_ELEMENT_ADDRESS
{
   unsigned char OperationCode;
   union {
   unsigned char ElementType;
   unsigned char VolTag;
   unsigned char LogicalUnitNumber;
   };
   unsigned char StartingElementAddress[2];
   unsigned char NumberElements[2];
   unsigned char Reserved1;
   unsigned char AllocationLength[3];
   unsigned char Reserved2;
   unsigned char Control;
} REQUEST_VOLUME_ELEMENT_ADDRESS;

typedef struct _SEND_VOLUME_TAG
{
   unsigned char OperationCode;
   union {
   unsigned char ElementType;
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char StartingElementAddress[2];
   unsigned char Reserved2;
   union {
   unsigned char ActionCode;
   unsigned char Reserved3;
   };
   unsigned char Reserved4[2];
   unsigned char ParameterListLength[2];
   unsigned char Reserved5;
   unsigned char Control;
} SEND_VOLUME_TAG;

typedef struct _READ_ELEMENT_STATUS
{
   unsigned char OperationCode;
   union {
   unsigned char ElementType;
   unsigned char VolTag;
   unsigned char LogicalUnitNumber;
   };
   unsigned char StartingElementAddress[2];
   unsigned char NumberOfElements[2];
   unsigned char Reserved1;
   unsigned char AllocationLength[3];
   unsigned char Reserved2;
   unsigned char Control;
} READ_ELEMENT_STATUS;

typedef struct _EXCHANGE_MEDIUM
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char TransportElementAddress[2];
   unsigned char SourceElementAddress[2];
   unsigned char Destination1ElementAddress[2];
   unsigned char Destination2ElementAddress[2];
   union {
   unsigned char Flip1;
   unsigned char Flip2;
   unsigned char Reserved3;
   };
   unsigned char Control;
} EXCHANGE_MEDIUM;

typedef struct _MOVE_MEDIUM
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char TransportElementAddress[2];
   unsigned char SourceElementAddress[2];
   unsigned char DestinationElementAddress[2];
   unsigned char Reserved2[2];
   union {
   unsigned char Flip;
   unsigned char Reserved3;
   };
   unsigned char Control;
} MOVE_MEDIUM;

typedef struct _POSITION_TO_ELEMENT
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char TransportElementAddress[2];
   unsigned char DestinationElementAddress[2];
   unsigned char Reserved2[2];
   union {
   unsigned char Flip;
   unsigned char Reserved3;
   };
   unsigned char Control;
} POSITION_TO_ELEMENT;

typedef struct _INITIALIZE_ELEMENT_RANGE
{
   unsigned char OperationCode;
   union {
   unsigned char Range;
   unsigned char Reserved1;
   unsigned char LogicalUnitNubmer;
   };
   unsigned char FirstElementAddress[2];
   unsigned char Reserved2[2];
   unsigned char NumberOfElements[2];
   unsigned char Reserved3;
   union {
   unsigned char Reserved4;
   unsigned char NoBarCode;
   };
} INITIALIZE_ELEMENT_RANGE;

typedef struct _INIT_ELEMENT_STATUS
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char LogicalUnitNubmer;
   };
   unsigned char Reserved2[3];
   union {
   unsigned char Reserved3;
   unsigned char NoBarCode;
   };
} INIT_ELEMENT_STATUS;

typedef struct _CDB6READWRITETAPE
{
   unsigned char OperationCode;
   union {
   unsigned char VendorSpecific;
   unsigned char Reserved;
   };
   unsigned char TransferLenMSB;
   unsigned char TransferLen;
   unsigned char TransferLenLSB;
   union {
   unsigned char Link;
   unsigned char Flag;
   unsigned char Reserved1;
   unsigned char VendorUnique;
   };
} CDB6READWRITETAPE;

typedef struct _READ_POSITION
{
   unsigned char Operation;
   union {
   unsigned char BlockType;
   unsigned char Reserved1;
   unsigned char Lun;
   };
   unsigned char Reserved2[7];
   unsigned char Control;
} READ_POSITION;

typedef struct _SPACE_TAPE_MARKS
{
   unsigned char OperationCode;
   union {
   unsigned char Code;
   unsigned char Reserved;
   unsigned char LogicalUnitNumber;
   };
   unsigned char NumMarksMSB;
   unsigned char NumMarks;
   unsigned char NumMarksLSB;
   UNNAMED_TAG_5A89084 Byte6;
} SPACE_TAPE_MARKS;

typedef struct _WRITE_TAPE_MARKS
{
   unsigned char OperationCode;
   union {
   unsigned char Immediate;
   unsigned char WriteSetMarks;
   unsigned char Reserved;
   unsigned char LogicalUnitNumber;
   };
   unsigned char TransferLength[3];
   unsigned char Control;
} WRITE_TAPE_MARKS;

typedef struct _PARTITION
{
   unsigned char OperationCode;
   union {
   unsigned char Immediate;
   unsigned char Sel;
   unsigned char PartitionSelect;
   };
   unsigned char Reserved1[3];
   unsigned char Control;
} PARTITION;

typedef struct _REQUEST_BLOCK_ADDRESS
{
   unsigned char OperationCode;
   unsigned char Reserved1[3];
   unsigned char AllocationLength;
   union {
   unsigned char Link;
   unsigned char Flag;
   unsigned char Reserved2;
   unsigned char VendorUnique;
   };
} REQUEST_BLOCK_ADDRESS;

typedef struct _SEEK_BLOCK
{
   unsigned char OperationCode;
   union {
   unsigned char Immediate;
   unsigned char Reserved1;
   };
   unsigned char BlockAddress[3];
   union {
   unsigned char Link;
   unsigned char Flag;
   unsigned char Reserved2;
   unsigned char VendorUnique;
   };
} SEEK_BLOCK;

typedef struct _MEDIA_REMOVAL
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char Reserved2[2];
   union {
   unsigned char Prevent;
   unsigned char Persistant;
   unsigned char Reserved3;
   };
   unsigned char Control;
} MEDIA_REMOVAL;

typedef struct _START_STOP
{
   unsigned char OperationCode;
   union {
   unsigned char Immediate;
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char Reserved2[2];
   union {
   unsigned char Start;
   unsigned char LoadEject;
   unsigned char Reserved3;
   };
   unsigned char Control;
} START_STOP;

typedef struct _ERASE
{
   unsigned char OperationCode;
   union {
   unsigned char Long;
   unsigned char Immediate;
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char Reserved2[3];
   unsigned char Control;
} ERASE;

typedef struct _SEEK
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char LogicalBlockAddress[4];
   unsigned char Reserved2[3];
   unsigned char Control;
} SEEK;

typedef struct _PRINT
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved;
   unsigned char LogicalUnitNumber;
   };
   unsigned char TransferLength[3];
   unsigned char Control;
} PRINT;

typedef struct _LOGSELECT
{
   unsigned char OperationCode;
   union {
   unsigned char SPBit;
   unsigned char PCRBit;
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   union {
   unsigned char Reserved;
   unsigned char PCBit;
   };
   unsigned char Reserved2[4];
   unsigned char ParameterListLength[2];
   unsigned char Control;
} LOGSELECT;

typedef struct _LOGSENSE
{
   unsigned char OperationCode;
   union {
   unsigned char SPBit;
   unsigned char PPCBit;
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   union {
   unsigned char PageCode;
   unsigned char PCBit;
   };
   unsigned char Reserved2;
   unsigned char Reserved3;
   unsigned char ParameterPointer[2];
   unsigned char AllocationLength[2];
   unsigned char Control;
} LOGSENSE;

typedef struct _LOCATE
{
   unsigned char OperationCode;
   union {
   unsigned char Immediate;
   unsigned char CPBit;
   unsigned char BTBit;
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char Reserved3;
   unsigned char LogicalBlockAddress[4];
   unsigned char Reserved4;
   unsigned char Partition;
   unsigned char Control;
} LOCATE;

typedef struct _MODE_SELECT10
{
   unsigned char OperationCode;
   union {
   unsigned char SPBit;
   unsigned char Reserved1;
   unsigned char PFBit;
   unsigned char LogicalUnitNumber;
   };
   unsigned char Reserved2[5];
   unsigned char ParameterListLength[2];
   unsigned char Control;
} MODE_SELECT10;

typedef struct _MODE_SELECT
{
   unsigned char OperationCode;
   union {
   unsigned char SPBit;
   unsigned char Reserved1;
   unsigned char PFBit;
   unsigned char LogicalUnitNumber;
   };
   unsigned char Reserved2[2];
   unsigned char ParameterListLength;
   unsigned char Control;
} MODE_SELECT;

typedef struct _MODE_SENSE10
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char Dbd;
   unsigned char Reserved2;
   unsigned char LogicalUnitNumber;
   };
   union {
   unsigned char PageCode;
   unsigned char Pc;
   };
   unsigned char Reserved3[4];
   unsigned char AllocationLength[2];
   unsigned char Control;
} MODE_SENSE10;

typedef struct _MODE_SENSE
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char Dbd;
   unsigned char Reserved2;
   unsigned char LogicalUnitNumber;
   };
   union {
   unsigned char PageCode;
   unsigned char Pc;
   };
   unsigned char Reserved3;
   unsigned char AllocationLength;
   unsigned char Control;
} MODE_SENSE;

typedef struct _NEC_READ_CDDA
{
   unsigned char OperationCode;
   unsigned char Reserved0;
   unsigned char LogicalBlockByte0;
   unsigned char LogicalBlockByte1;
   unsigned char LogicalBlockByte2;
   unsigned char LogicalBlockByte3;
   unsigned char Reserved1;
   unsigned char TransferBlockByte0;
   unsigned char TransferBlockByte1;
   unsigned char Control;
} NEC_READ_CDDA;

typedef struct _PLXTR_READ_CDDA
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved0;
   unsigned char LogicalUnitNumber;
   };
   unsigned char LogicalBlockByte0;
   unsigned char LogicalBlockByte1;
   unsigned char LogicalBlockByte2;
   unsigned char LogicalBlockByte3;
   unsigned char TransferBlockByte0;
   unsigned char TransferBlockByte1;
   unsigned char TransferBlockByte2;
   unsigned char TransferBlockByte3;
   unsigned char SubCode;
   unsigned char Control;
} PLXTR_READ_CDDA;

typedef struct _READ_CD_MSF
{
   unsigned char OperationCode;
   union {
   unsigned char RelativeAddress;
   unsigned char Reserved1;
   unsigned char ExpectedSectorType;
   unsigned char Lun;
   };
   unsigned char Reserved2;
   unsigned char StartingM;
   unsigned char StartingS;
   unsigned char StartingF;
   unsigned char EndingM;
   unsigned char EndingS;
   unsigned char EndingF;
   unsigned char Reserved3;
   union {
   unsigned char Reserved4;
   unsigned char ErrorFlags;
   unsigned char IncludeEDC;
   unsigned char IncludeUserData;
   unsigned char HeaderCode;
   unsigned char IncludeSyncData;
   };
   union {
   unsigned char SubChannelSelection;
   unsigned char Reserved5;
   };
   unsigned char Control;
} READ_CD_MSF;

typedef struct _READ_CD
{
   unsigned char OperationCode;
   union {
   unsigned char RelativeAddress;
   unsigned char Reserved0;
   unsigned char ExpectedSectorType;
   unsigned char Lun;
   };
   unsigned char StartingLBA[4];
   unsigned char TransferBlocks[3];
   union {
   unsigned char Reserved2;
   unsigned char ErrorFlags;
   unsigned char IncludeEDC;
   unsigned char IncludeUserData;
   unsigned char HeaderCode;
   unsigned char IncludeSyncData;
   };
   union {
   unsigned char SubChannelSelection;
   unsigned char Reserved3;
   };
   unsigned char Control;
} READ_CD;

typedef struct _SUBCHANNEL
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved0;
   unsigned char Msf;
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   union {
   unsigned char Reserved2;
   unsigned char SubQ;
   unsigned char Reserved3;
   };
   unsigned char Format;
   unsigned char Reserved4[2];
   unsigned char TrackNumber;
   unsigned char AllocationLength[2];
   unsigned char Control;
} SUBCHANNEL;

typedef struct _STOP_PLAY_SCAN
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char Lun;
   };
   unsigned char Reserved2[7];
   unsigned char Control;
} STOP_PLAY_SCAN;

typedef struct _SCAN_CD
{
   unsigned char OperationCode;
   union {
   unsigned char RelativeAddress;
   unsigned char Reserved1;
   unsigned char Direct;
   unsigned char Lun;
   };
   unsigned char StartingAddress[4];
   unsigned char Reserved2[3];
   union {
   unsigned char Reserved3;
   unsigned char Type;
   };
   unsigned char Reserved4;
   unsigned char Control;
} SCAN_CD;

typedef struct _MSF
{
   unsigned char Reserved1;
   unsigned char StartingM;
   unsigned char StartingS;
   unsigned char StartingF;
   unsigned char EndingM;
   unsigned char EndingS;
   unsigned char EndingF;
   unsigned char Reserved2;
} MSF;

typedef struct _LBA
{
   unsigned char StartingBlockAddress[4];
   unsigned char PlayLength[4];
} LBA;

typedef struct _PLAY_CD
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char CMSF;
   unsigned char ExpectedSectorType;
   unsigned char Lun;
   };
   union {
   _LBA LBA;
   _MSF MSF;
   };
   union {
   unsigned char Audio;
   unsigned char Composite;
   unsigned char Port1;
   unsigned char Port2;
   unsigned char Reserved2;
   unsigned char Speed;
   };
   unsigned char Control;
} PLAY_CD;

typedef struct _PLAY_AUDIO_MSF
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char Reserved2;
   unsigned char StartingM;
   unsigned char StartingS;
   unsigned char StartingF;
   unsigned char EndingM;
   unsigned char EndingS;
   unsigned char EndingF;
   unsigned char Control;
} PLAY_AUDIO_MSF;

typedef struct _PLAY_AUDIO
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char StartingBlockAddress[4];
   unsigned char Reserved2;
   unsigned char PlayLength[2];
   unsigned char Control;
} PLAY_AUDIO;

typedef struct _READ_HEADER
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char Msf;
   unsigned char Reserved2;
   unsigned char Lun;
   };
   unsigned char LogicalBlockAddress[4];
   unsigned char Reserved3;
   unsigned char AllocationLength[2];
   unsigned char Control;
} READ_HEADER;

typedef struct _READ_TRACK_INFORMATION
{
   unsigned char OperationCode;
   union {
   unsigned char Track;
   unsigned char Reserved1;
   unsigned char Reserved2;
   unsigned char Lun;
   };
   unsigned char BlockAddress[4];
   unsigned char Reserved3;
   unsigned char AllocationLength[2];
   unsigned char Control;
} READ_TRACK_INFORMATION;

typedef struct _READ_DISK_INFORMATION
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char Lun;
   };
   unsigned char Reserved2[5];
   unsigned char AllocationLength[2];
   unsigned char Control;
} READ_DISK_INFORMATION;

typedef struct _READ_TOC
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved0;
   unsigned char Msf;
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   union {
   unsigned char Format2;
   unsigned char Reserved2;
   };
   unsigned char Reserved3[3];
   unsigned char StartingTrack;
   unsigned char AllocationLength[2];
   union {
   unsigned char Control;
   unsigned char Format;
   };
} READ_TOC;

typedef struct _PAUSE_RESUME
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char Reserved2[6];
   unsigned char Action;
   unsigned char Control;
} PAUSE_RESUME;

typedef struct _CDB12
{
   unsigned char OperationCode;
   union {
   unsigned char RelativeAddress;
   unsigned char Reserved1;
   unsigned char ForceUnitAccess;
   unsigned char DisablePageOut;
   unsigned char LogicalUnitNumber;
   };
   unsigned char LogicalBlock[4];
   unsigned char TransferLength[4];
   unsigned char Reserved2;
   unsigned char Control;
} CDB12;

typedef struct _CDB10
{
   unsigned char OperationCode;
   union {
   unsigned char RelativeAddress;
   unsigned char Reserved1;
   unsigned char ForceUnitAccess;
   unsigned char DisablePageOut;
   unsigned char LogicalUnitNumber;
   };
   unsigned char LogicalBlockByte0;
   unsigned char LogicalBlockByte1;
   unsigned char LogicalBlockByte2;
   unsigned char LogicalBlockByte3;
   unsigned long LogicalBlock;
   unsigned char Reserved2;
   unsigned char TransferBlocksMsb;
   unsigned char TransferBlocksLsb;
   unsigned long TransferBlocks;
   unsigned char Control;
} CDB10;

typedef struct _CDB6FORMAT
{
   unsigned char OperationCode;
   union {
   unsigned char FormatControl;
   unsigned char LogicalUnitNumber;
   };
   unsigned char FReserved1;
   unsigned char InterleaveMsb;
   unsigned char InterleaveLsb;
   unsigned char FReserved2;
} CDB6FORMAT;

typedef struct _CDB6VERIFY
{
   unsigned char OperationCode;
   union {
   unsigned char Fixed;
   unsigned char ByteCompare;
   unsigned char Immediate;
   unsigned char Reserved;
   unsigned char LogicalUnitNumber;
   };
   unsigned char VerificationLength[3];
   unsigned char Control;
} CDB6VERIFY;

typedef struct _CDB6INQUIRY
{
   unsigned char OperationCode;
   union {
   unsigned char Reserved1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char PageCode;
   unsigned char IReserved;
   unsigned char AllocationLength;
   unsigned char Control;
} CDB6INQUIRY;

typedef struct _CDB6READWRITE
{
   unsigned char OperationCode;
   union {
   unsigned char LogicalBlockMsb1;
   unsigned char LogicalUnitNumber;
   };
   unsigned char LogicalBlockMsb0;
   unsigned char LogicalBlockLsb;
   unsigned char TransferBlocks;
   unsigned char Control;
} CDB6READWRITE;

typedef struct _CDB6GENERIC
{
   unsigned char OperationCode;
   union {
   unsigned char Immediate;
   unsigned char CommandUniqueBits;
   unsigned char LogicalUnitNumber;
   };
   unsigned char CommandUniqueBytes[3];
   union {
   unsigned char Link;
   unsigned char Flag;
   unsigned char Reserved;
   unsigned char VendorUnique;
   };
} CDB6GENERIC;

typedef struct _DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY
{
   unsigned char ChallengeLevel;
   unsigned char ChallengeID;
   unsigned long ChallengeValue;
   unsigned char ResponseModifier;
   unsigned long ResponseValue;
} DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY;

typedef struct _XBOX_REFURB_INFO
{
   unsigned long Signature;
   unsigned long PowerCycleCount;
   _LARGE_INTEGER FirstSetTime;
} XBOX_REFURB_INFO;

typedef struct _MODE_READ_WRITE_RECOVERY_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved1;
   unsigned char PSBit;
   };
   unsigned char PageLength;
   union {
   unsigned char DCRBit;
   unsigned char DTEBit;
   unsigned char PERBit;
   unsigned char EERBit;
   unsigned char RCBit;
   unsigned char TBBit;
   unsigned char ARRE;
   unsigned char AWRE;
   };
   unsigned char ReadRetryCount;
   unsigned char Reserved4[4];
   unsigned char WriteRetryCount;
   unsigned char Reserved5[3];
} MODE_READ_WRITE_RECOVERY_PAGE;

typedef struct _FORMATTED_CAPACITY_DESCRIPTOR
{
   unsigned char NumberOfBlocks[4];
   union {
   unsigned char Maximum;
   unsigned char Valid;
   };
   unsigned char BlockLength[3];
} FORMATTED_CAPACITY_DESCRIPTOR;

typedef struct _XBOX_TIMEZONE_DATE
{
   unsigned char Month;
   unsigned char Day;
   unsigned char DayOfWeek;
   unsigned char Hour;
} XBOX_TIMEZONE_DATE;

typedef struct _DVDX2_ADVANCED_DRIVE_CONTROL_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved;
   unsigned char PSBit;
   };
   unsigned char PageLength;
   unsigned char SpindleSpeedControl;
   unsigned char Reserved2[9];
} DVDX2_ADVANCED_DRIVE_CONTROL_PAGE;

typedef struct _PCI_MSI_CAPABILITY
{
   _PCI_CAPABILITIES_HEADER Header;
   _PCI_MSI_MESSAGE_CONTROL MessageControl;
   UNNAMED_TAG_1D0105E MessageAddress;
   UNNAMED_TAG_4D1445C Data;
} PCI_MSI_CAPABILITY;

typedef union UNNAMED_TAG_4D0C28A
{
   union {
   _PCI_MSI_64BIT_DATA Bit64;
   _PCI_MSI_32BIT_DATA Bit32;
   };
} UNNAMED_TAG_4D0C28A;

typedef struct _PCI_MSI_32BIT_DATA
{
   short MessageData;
   unsigned char Padding1;
   unsigned char Padding2;
   unsigned long Unused;
} PCI_MSI_32BIT_DATA;

typedef struct _PCI_MSI_64BIT_DATA
{
   unsigned long MessageUpperAddress;
   short MessageData;
} PCI_MSI_64BIT_DATA;

typedef union UNNAMED_TAG_5B49DAC
{
   union {
   _PCI_MSI_MESSAGE_ADDRESS Register;
   unsigned long Raw;
   };
} UNNAMED_TAG_5B49DAC;

typedef struct _PCI_MSI_MESSAGE_ADDRESS
{
   union {
   unsigned long Reserved;
   unsigned long Address;
   };
} PCI_MSI_MESSAGE_ADDRESS;

typedef struct _PCI_MSI_MESSAGE_CONTROL
{
   union {
   short MSIEnable;
   short MultipleMessageCapable;
   short MultipleMessageEnable;
   short CapableOf64Bits;
   short Reserved;
   };
} PCI_MSI_MESSAGE_CONTROL;

typedef struct _PCI_CAPABILITIES_HEADER
{
   unsigned char CapabilityID;
   unsigned char Next;
} PCI_CAPABILITIES_HEADER;

typedef struct _DUMP_POINTERS
{
   void *  AdapterObject;
   void * MappedRegisterBase;
   void * DumpData;
   void * CommonBufferVa;
   _LARGE_INTEGER CommonBufferPa;
   unsigned long CommonBufferSize;
   unsigned char AllocateCommonBuffers;
   unsigned char Spare1[3];
   void * DeviceObject;
} DUMP_POINTERS;

typedef struct _LUN_LIST
{
   unsigned char LunListLength[4];
   unsigned char Reserved[4];
   unsigned char Lun[8] Lun[0];
} LUN_LIST;

typedef struct _SLOT_TABLE_INFORMATION
{
   union {
   unsigned char DiscChanged;
   unsigned char Reserved;
   unsigned char DiscPresent;
   };
   unsigned char Reserved2[3];
} SLOT_TABLE_INFORMATION;

typedef struct _IDE_DISK_EXTENSION
{
   _DEVICE_OBJECT * DeviceObject;
   _PARTITION_INFORMATION PartitionInformation;
} IDE_DISK_EXTENSION;

typedef struct _IO_SCSI_CAPABILITIES
{
   unsigned long Length;
   unsigned long MaximumTransferLength;
   unsigned long MaximumPhysicalPages;
   unsigned long SupportedAsynchronousEvents;
   unsigned long AlignmentMask;
   unsigned char TaggedQueuing;
   unsigned char AdapterScansDown;
   unsigned char AdapterUsesPio;
} IO_SCSI_CAPABILITIES;

typedef struct _MODE_RIGID_GEOMETRY_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved;
   unsigned char PageSavable;
   };
   unsigned char PageLength;
   unsigned char NumberOfCylinders[3];
   unsigned char NumberOfHeads;
   unsigned char StartWritePrecom[3];
   unsigned char StartReducedCurrent[3];
   unsigned char DriveStepRate[2];
   unsigned char LandZoneCyclinder[3];
   union {
   unsigned char RotationalPositionLock;
   unsigned char Reserved2;
   };
   unsigned char RotationOffset;
   unsigned char Reserved3;
   unsigned char RoataionRate[2];
   unsigned char Reserved4[2];
} MODE_RIGID_GEOMETRY_PAGE;

typedef struct _DVD_MANUFACTURER_DESCRIPTOR
{
   unsigned char ManufacturingInformation[2048];
} DVD_MANUFACTURER_DESCRIPTOR;

typedef struct _MODE_CACHING_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved;
   unsigned char PageSavable;
   };
   unsigned char PageLength;
   union {
   unsigned char ReadDisableCache;
   unsigned char MultiplicationFactor;
   unsigned char WriteCacheEnable;
   unsigned char Reserved2;
   };
   union {
   unsigned char WriteRetensionPriority;
   unsigned char ReadRetensionPriority;
   };
   unsigned char DisablePrefetchTransfer[2];
   unsigned char MinimumPrefetch[2];
   unsigned char MaximumPrefetch[2];
   unsigned char MaximumPrefetchCeiling[2];
} MODE_CACHING_PAGE;

typedef struct _DISK_INFORMATION
{
   unsigned char Length[2];
   union {
   unsigned char DiskStatus;
   unsigned char LastSessionStatus;
   unsigned char Erasable;
   unsigned char Reserved1;
   };
   unsigned char FirstTrackNumber;
   unsigned char NumberOfSessions;
   unsigned char LastSessionFirstTrack;
   unsigned char LastSessionLastTrack;
   union {
   unsigned char Reserved2;
   unsigned char GEN;
   unsigned char DBC_V;
   unsigned char DID_V;
   };
   unsigned char DiskType;
   unsigned char Reserved3[3];
   unsigned char DiskIdentification[4];
   unsigned char LastSessionLeadIn[4];
   unsigned char LastPossibleStartTime[4];
   unsigned char DiskBarCode[8];
   unsigned char Reserved4;
   unsigned char NumberOPCEntries;
   _OPC_TABLE_ENTRY OPCTable[0];
} DISK_INFORMATION;

typedef struct _OPC_TABLE_ENTRY
{
   unsigned char Speed[2];
   unsigned char OPCValue[6];
} OPC_TABLE_ENTRY;

typedef struct _DVD_LAYER_DESCRIPTOR
{
   union {
   unsigned char BookVersion;
   unsigned char BookType;
   };
   union {
   unsigned char MinimumRate;
   unsigned char DiskSize;
   };
   union {
   unsigned char LayerType;
   unsigned char TrackPath;
   unsigned char NumberOfLayers;
   unsigned char Reserved1;
   };
   union {
   unsigned char TrackDensity;
   unsigned char LinearDensity;
   };
   unsigned long StartingDataSector;
   unsigned long EndDataSector;
   unsigned long EndLayerZeroSector;
   union {
   unsigned char Reserved5;
   unsigned char BCAFlag;
   };
} DVD_LAYER_DESCRIPTOR;

typedef struct _XBOX_CONFIG_SECTOR
{
   unsigned long SectorBeginSignature;
   unsigned long Version;
   unsigned long SectorCount;
   unsigned char Data[492];
   unsigned long Checksum;
   unsigned long SectorEndSignature;
} XBOX_CONFIG_SECTOR;

typedef struct _NOTIFICATION_EVENT_STATUS_HEADER
{
   unsigned char EventDataLength[2];
   union {
   unsigned char NotificationClass;
   unsigned char Reserved;
   unsigned char NEA;
   };
   unsigned char SupportedEventClasses;
   unsigned char ClassEventData[0];
} NOTIFICATION_EVENT_STATUS_HEADER;

typedef struct _DVD_REGION
{
   unsigned char CopySystem;
   unsigned char RegionData;
   unsigned char SystemRegion;
   unsigned char ResetCount;
} DVD_REGION;

typedef struct _CDVD_FEATURE_SET_PAGE
{
   union {
   unsigned char PageCode;
   unsigned char Reserved;
   unsigned char PSBit;
   };
   unsigned char PageLength;
   unsigned char CDAudio[2];
   unsigned char EmbeddedChanger[2];
   unsigned char PacketSMART[2];
   unsigned char PersistantPrevent[2];
   unsigned char EventStatusNotification[2];
   unsigned char DigitalOutput[2];
   unsigned char CDSequentialRecordable[2];
   unsigned char DVDSequentialRecordable[2];
   unsigned char RandomRecordable[2];
   unsigned char KeyExchange[2];
   unsigned char Reserved2[2];
} CDVD_FEATURE_SET_PAGE;

typedef struct _RAW_VOLUME_EXTENSION
{
   _DEVICE_OBJECT * TargetDeviceObject;
   _SHARE_ACCESS ShareAccess;
   unsigned char Dismounted;
   _ERWLOCK VolumeMutex;
} RAW_VOLUME_EXTENSION;

typedef struct UNNAMED_TAG_49D3446
{
   _LIST_ENTRY ChildFcbList;
   unsigned long DirectoryByteOffsetLookupHint;
   _FAT_FCB_CLUSTER_CACHE_ENTRY ClusterCache[2];
   char OriginalFileName[0];
} UNNAMED_TAG_49D3446;

typedef struct UNNAMED_TAG_4226AB2
{
   _ERWLOCK FileMutex;
   _KTHREAD * FileMutexExclusiveOwner;
   _FAT_FCB_CLUSTER_CACHE_ENTRY ClusterCache[10];
   char OriginalFileName[0];
} UNNAMED_TAG_4226AB2;

typedef struct _FAT_VOLUME_METADATA
{
   unsigned long Signature;
   unsigned long SerialNumber;
   unsigned long SectorsPerCluster;
   unsigned long RootDirFirstCluster;
   short VolumeName[32];
   unsigned char OnlineData[2048];
} FAT_VOLUME_METADATA;

typedef struct _FAT_FCB_BASE
{
   unsigned char Flags;
   unsigned char PathNameLength;
   unsigned char FileNameLength;
   unsigned char FileAttributes;
   unsigned long ReferenceCount;
   _SHARE_ACCESS ShareAccess;
   unsigned char ClusterCacheLruHead;
} FAT_FCB_BASE;

typedef struct _FAT_VOLUME_EXTENSION
{
   union {
   _FSCACHE_EXTENSION CacheExtension;
   _DEVICE_OBJECT * TargetDeviceObject;
   };
   _LARGE_INTEGER PartitionLength;
   unsigned long SectorSize;
   _FAT_FCB * RootDirectoryFcb;
   unsigned long FileObjectCount;
   unsigned long NumberOfClusters;
   unsigned long BytesPerCluster;
   unsigned char SectorShift;
   unsigned char ClusterShift;
   unsigned char FatEntryShift;
   unsigned char Flags;
   __int64 FatByteOffset;
   __int64 FileAreaByteOffset;
   unsigned long NumberOfClustersAvailable;
   unsigned long FirstAvailableClusterHint;
   _ERWLOCK VolumeMutex;
   _RTL_CRITICAL_SECTION ClusterCacheMutex;
   _FAT_FCB_BASE VolumeFcb;
   unsigned long SerialNumber;
   long DismountBlockCount;
   _KEVENT * DismountUnblockEvent;
   _KTHREAD * VolumeMutexExclusiveOwner;
} FAT_VOLUME_EXTENSION;

typedef struct _FAT_CLUSTER_RUN
{
   unsigned long PhysicalClusterNumber;
   unsigned long ClusterRunLength;
} FAT_CLUSTER_RUN;

typedef struct _FAT_ASYNC_IO_DESCRIPTOR
{
   unsigned long MajorFunction;
   unsigned long IoLength;
   unsigned long IoLengthRemaining;
   unsigned long BufferOffset;
   unsigned long NextAsyncIoEntry;
   _FAT_FCB * FileFcb;
   _FAT_ASYNC_IO_ENTRY Entries[0];
} FAT_ASYNC_IO_DESCRIPTOR;

typedef struct _FAT_ASYNC_IO_ENTRY
{
   unsigned long PhysicalSector;
   unsigned long PhysicalIoLength;
} FAT_ASYNC_IO_ENTRY;

typedef struct _FAT_FCB
{
   unsigned char Flags;
   unsigned char PathNameLength;
   unsigned char FileNameLength;
   unsigned char FileAttributes;
   unsigned long ReferenceCount;
   _SHARE_ACCESS ShareAccess;
   unsigned char ClusterCacheLruHead;
   _LIST_ENTRY SiblingFcbLink;
   _FAT_FCB * ParentFcb;
   unsigned long FirstCluster;
   unsigned long EndingCluster;
   unsigned long FileSize;
   unsigned long AllocationSize;
   unsigned long DirectoryByteOffset;
   char * FileNameBuffer;
   _LARGE_INTEGER LastWriteTime;
   _FAT_TIME_STAMP CreationTime;
   _FAT_TIME_STAMP LastAccessTime;
   union {
   UNNAMED_TAG_51F44D4 File;
   UNNAMED_TAG_4999F75 Directory;
   };
} FAT_FCB;

typedef struct _DIRENT
{
   unsigned char FileNameLength;
   unsigned char FileAttributes;
   unsigned char FileName[42];
   unsigned long FirstCluster;
   unsigned long FileSize;
   _FAT_TIME_STAMP CreationTime;
   _FAT_TIME_STAMP LastWriteTime;
   _FAT_TIME_STAMP LastAccessTime;
} DIRENT;

typedef union _FAT_TIME_STAMP
{
   union {
   short DoubleSeconds;
   short Minute;
   short Hour;
   };
   union {
   short Day;
   short Month;
   short Year;
   };
   unsigned long AsULONG;
} FAT_TIME_STAMP;

typedef struct _FAT_FCB_CLUSTER_CACHE_ENTRY
{
   union {
   unsigned long PhysicalClusterNumber;
   unsigned long LruFlink;
   };
   union {
   unsigned long FileClusterNumber;
   unsigned long LruBlink;
   };
   unsigned long ClusterRunLength;
} FAT_FCB_CLUSTER_CACHE_ENTRY;

typedef struct _GDF_VOLUME_DESCRIPTOR
{
   unsigned char HeadSignature[20];
   unsigned long RootDirectoryFirstSector;
   unsigned long RootDirectoryFileSize;
   _LARGE_INTEGER TimeStamp;
   unsigned char Reserved[1992];
   unsigned char TailSignature[20];
} GDF_VOLUME_DESCRIPTOR;

typedef struct _GDF_DIRECTORY_ENTRY
{
   short LeftEntryIndex;
   short RightEntryIndex;
   unsigned long FirstSector;
   unsigned long FileSize;
   unsigned char FileAttributes;
   unsigned char FileNameLength;
   unsigned char FileName[1];
} GDF_DIRECTORY_ENTRY;

typedef struct _GDF_VOLUME_EXTENSION
{
   union {
   _FSCACHE_EXTENSION CacheExtension;
   _DEVICE_OBJECT * TargetDeviceObject;
   };
   _LARGE_INTEGER PartitionLength;
   unsigned long SectorSize;
   _GDF_FCB * VolumeFcb;
   _GDF_FCB * RootDirectoryFcb;
   unsigned long PartitionSectorCount;
   _LARGE_INTEGER TimeStamp;
   unsigned long FileObjectCount;
   unsigned char Dismounted;
} GDF_VOLUME_EXTENSION;

typedef struct _GDF_FCB
{
   unsigned long FirstSector;
   unsigned long FileSize;
   unsigned long ReferenceCount;
   _GDF_FCB * ParentFcb;
   _LIST_ENTRY SiblingFcbLink;
   _LIST_ENTRY ChildFcbList;
   unsigned char Flags;
   unsigned char FileNameLength;
   char FileName[0];
} GDF_FCB;

typedef union UNNAMED_TAG_46AA5AA
{
   union {
   __int64 ForwarderString;
   __int64 Function;
   __int64 Ordinal;
   __int64 AddressOfData;
   };
} UNNAMED_TAG_46AA5AA;

typedef struct NSR_TERM
{
   DESTAG Destag;
   unsigned char Res16[496];
} NSR_TERM;

typedef struct NSR_PART_H
{
   SHORTAD UASTable;
   SHORTAD UASBitmap;
   SHORTAD IntegTable;
   SHORTAD FreedTable;
   SHORTAD FreedBitmap;
   unsigned char Res40[88];
} NSR_PART_H;

typedef struct _DISK_PERFORMANCE
{
   _LARGE_INTEGER BytesRead;
   _LARGE_INTEGER BytesWritten;
   _LARGE_INTEGER ReadTime;
   _LARGE_INTEGER WriteTime;
   _LARGE_INTEGER IdleTime;
   unsigned long ReadCount;
   unsigned long WriteCount;
   unsigned long QueueDepth;
   unsigned long SplitCount;
   _LARGE_INTEGER QueryTime;
   unsigned long StorageDeviceNumber;
   short StorageManagerName[8];
} DISK_PERFORMANCE;

typedef struct _KD_PHYSICAL_PORT
{
   void * Initialize;
   void * ReceivePacket;
   void * SendPacket;
} KD_PHYSICAL_PORT;

typedef struct NSR_SBD
{
   DESTAG Destag;
   unsigned long BitCount;
   unsigned long ByteCount;
   unsigned char Bits[0];
} NSR_SBD;

typedef struct ICBPINTEG
{
   DESTAG Destag;
   ICBTAG Icbtag;
   TIMESTAMP Recording;
   unsigned char IntegType;
   unsigned char Res49[175];
   REGID ImpUseID;
   unsigned char ImpUse[256];
} ICBPINTEG;

typedef struct _DISK_GROW_PARTITION
{
   unsigned long PartitionNumber;
   unsigned long Padding1;
   _LARGE_INTEGER BytesToGrow;
} DISK_GROW_PARTITION;

typedef struct _CDROM_AUDIO_CONTROL
{
   unsigned char LbaFormat;
   unsigned char Padding1;
   short LogicalBlocksPerSecond;
} CDROM_AUDIO_CONTROL;

typedef struct _DISK_LOGGING
{
   unsigned char Function;
   unsigned char Padding1;
   unsigned char Padding2;
   unsigned char Padding3;
   void * BufferAddress;
   unsigned long BufferSize;
} DISK_LOGGING;

typedef struct ICBFILE
{
   DESTAG Destag;
   ICBTAG Icbtag;
   unsigned long UID;
   unsigned long GID;
   unsigned long Permissions;
   short LinkCount;
   unsigned char RecordFormat;
   unsigned char RecordDisplay;
   unsigned long RecordLength;
   __int64 InfoLength;
   __int64 BlocksRecorded;
   TIMESTAMP AccessTime;
   TIMESTAMP ModifyTime;
   TIMESTAMP AttributeTime;
   unsigned long Checkpoint;
   LONGAD IcbEA;
   REGID ImpUseID;
   __int64 UniqueID;
   unsigned long EALength;
   unsigned long AllocLength;
   unsigned char EAs[1];
   unsigned char Allocs[0];
} ICBFILE;

typedef union UNNAMED_TAG_22116E6
{
   union {
   UNNAMED_TAG_1A4C3D8 Create;
   UNNAMED_TAG_54E156B Read;
   UNNAMED_TAG_300E5D Write;
   UNNAMED_TAG_4F21B14 QueryDirectory;
   UNNAMED_TAG_1CF0D80 QueryFile;
   UNNAMED_TAG_4FD1ADF SetFile;
   UNNAMED_TAG_2E6C640 QueryVolume;
   UNNAMED_TAG_53262DC SetVolume;
   UNNAMED_TAG_6ACEDD FileSystemControl;
   UNNAMED_TAG_22E369C DeviceIoControl;
   UNNAMED_TAG_4D8A1A0 Scsi;
   UNNAMED_TAG_549AA61 IdexReadWrite;
   UNNAMED_TAG_E28EA6 Others;
   };
} UNNAMED_TAG_22116E6;

typedef struct UNNAMED_TAG_40CEB5B
{
   void * Argument1;
   void * Argument2;
   void * Argument3;
   void * Argument4;
} UNNAMED_TAG_40CEB5B;

typedef struct UNNAMED_TAG_1FF910B
{
   unsigned long Length;
   unsigned char * Buffer;
   unsigned long SectorNumber;
   unsigned long BufferOffset;
} UNNAMED_TAG_1FF910B;

typedef struct UNNAMED_TAG_10F7DEC
{
   void *  Srb;
} UNNAMED_TAG_10F7DEC;

typedef struct UNNAMED_TAG_1CFCAD2
{
   unsigned long OutputBufferLength;
   void * InputBuffer;
   unsigned long InputBufferLength;
   unsigned long IoControlCode;
} UNNAMED_TAG_1CFCAD2;

typedef struct UNNAMED_TAG_47747A0
{
   unsigned long OutputBufferLength;
   void * InputBuffer;
   unsigned long InputBufferLength;
   unsigned long FsControlCode;
} UNNAMED_TAG_47747A0;

typedef struct UNNAMED_TAG_5EE146
{
   unsigned long Length;
   int FsInformationClass;
} UNNAMED_TAG_5EE146;

typedef struct UNNAMED_TAG_C3E894
{
   unsigned long Length;
   int FileInformationClass;
   _FILE_OBJECT * FileObject;
} UNNAMED_TAG_C3E894;

typedef struct UNNAMED_TAG_1BC922B
{
   unsigned long Length;
   int FileInformationClass;
} UNNAMED_TAG_1BC922B;

typedef struct UNNAMED_TAG_5E5A1D
{
   unsigned long Length;
   _STRING * FileName;
   int FileInformationClass;
} UNNAMED_TAG_5E5A1D;

typedef struct UNNAMED_TAG_2271310
{
   unsigned long Length;
   union {
   unsigned long BufferOffset;
   void * CacheBuffer;
   };
   _LARGE_INTEGER ByteOffset;
} UNNAMED_TAG_2271310;

typedef struct UNNAMED_TAG_5CC3A82
{
   unsigned long DesiredAccess;
   unsigned long Options;
   short FileAttributes;
   short ShareAccess;
   _STRING * RemainingName;
} UNNAMED_TAG_5CC3A82;

typedef union UNNAMED_TAG_19998DD
{
   union {
   UNNAMED_TAG_5696679 s2;
   unsigned long ZeroInit;
   };
} UNNAMED_TAG_19998DD;

typedef struct UNNAMED_TAG_2A65C8D
{
   short Type;
   short DataInfoOffset;
} UNNAMED_TAG_2A65C8D;

typedef union UNNAMED_TAG_3587CAA
{
   union {
   UNNAMED_TAG_71E9BC s1;
   unsigned long Length;
   };
} UNNAMED_TAG_3587CAA;

typedef struct UNNAMED_TAG_34CB153
{
   short DataLength;
   short TotalLength;
} UNNAMED_TAG_34CB153;

typedef struct UNNAMED_TAG_1656B9
{
   unsigned long DriveMap;
   unsigned char DriveType[32];
} UNNAMED_TAG_1656B9;

typedef struct UNNAMED_TAG_3F30B8
{
   void * DirectoryHandle;
} UNNAMED_TAG_3F30B8;

typedef struct UNNAMED_TAG_5A89084
{
   short Minimum;
   short Maximum;
} UNNAMED_TAG_5A89084;

typedef struct UNNAMED_TAG_4D1445C
{
   short Minimum;
   short Maximum;
   short MaximumBlocks;
} UNNAMED_TAG_4D1445C;

typedef struct PARTMAP_GENERIC
{
   unsigned char Type;
   unsigned char Length;
   unsigned char Map[0];
} PARTMAP_GENERIC;

typedef union UNNAMED_TAG_1D0105E
{
   union {
   UNNAMED_TAG_3616E77 Generic;
   UNNAMED_TAG_4B871CC Port;
   UNNAMED_TAG_392A9BE Interrupt;
   UNNAMED_TAG_45B4CBE Memory;
   UNNAMED_TAG_3B298DF Dma;
   UNNAMED_TAG_2A36A39 DevicePrivate;
   UNNAMED_TAG_555BFE3 BusNumber;
   UNNAMED_TAG_1A60296 DeviceSpecificData;
   };
} UNNAMED_TAG_1D0105E;

typedef struct UNNAMED_TAG_4999F75
{
   unsigned long DataSize;
   unsigned long Reserved1;
   unsigned long Reserved2;
} UNNAMED_TAG_4999F75;

typedef struct UNNAMED_TAG_51F44D4
{
   unsigned long Start;
   unsigned long Length;
   unsigned long Reserved;
} UNNAMED_TAG_51F44D4;

typedef struct UNNAMED_TAG_E28EA6
{
   unsigned long Channel;
   unsigned long Port;
   unsigned long Reserved1;
} UNNAMED_TAG_E28EA6;

typedef struct UNNAMED_TAG_549AA61
{
   unsigned long Level;
   unsigned long Vector;
   unsigned long Affinity;
} UNNAMED_TAG_549AA61;

typedef struct UNNAMED_TAG_4D8A1A0
{
   _LARGE_INTEGER Start;
   unsigned long Length;
} UNNAMED_TAG_4D8A1A0;

typedef union UNNAMED_TAG_22E369C
{
   union {
   unsigned long PhysicalAddress;
   unsigned long VirtualSize;
   };
} UNNAMED_TAG_22E369C;

typedef struct _SUB_Q_MEDIA_CATALOG_NUMBER
{
   _SUB_Q_HEADER Header;
   unsigned char FormatCode;
   unsigned char Reserved[3];
   union {
   unsigned char Reserved1;
   unsigned char Mcval;
   };
   unsigned char MediaCatalog[15];
} SUB_Q_MEDIA_CATALOG_NUMBER;

typedef union _SUB_Q_CHANNEL_DATA
{
   union {
   _SUB_Q_CURRENT_POSITION CurrentPosition;
   _SUB_Q_MEDIA_CATALOG_NUMBER MediaCatalog;
   _SUB_Q_TRACK_ISRC TrackIsrc;
   };
} SUB_Q_CHANNEL_DATA;

typedef struct NSR_PVD
{
   DESTAG Destag;
   unsigned long VolDescSeqNum;
   unsigned long Number;
   unsigned char VolumeID[32];
   short VolSetSeq;
   short VolSetSeqMax;
   short Level;
   short LevelMax;
   unsigned long CharSetList;
   unsigned long CharSetListMax;
   unsigned char VolSetID[128];
   CHARSPEC CharsetDesc;
   CHARSPEC CharsetExplan;
   EXTENTAD Abstract;
   EXTENTAD Copyright;
   REGID Application;
   TIMESTAMP RecordTime;
   REGID ImpUseID;
   unsigned char ImpUse[64];
   unsigned long Predecessor;
   short Flags;
   unsigned char Res490[22];
} NSR_PVD;

typedef union UNNAMED_TAG_6ACEDD
{
   union {
   UNNAMED_TAG_3B97E81 Overlay;
   _KAPC Apc;
   void * CompletionKey;
   };
} UNNAMED_TAG_6ACEDD;

typedef struct UNNAMED_TAG_53262DC
{
   union {
   _KDEVICE_QUEUE_ENTRY DeviceQueueEntry;
   void * DriverContext[5];
   };
   _ETHREAD * Thread;
   _LIST_ENTRY ListEntry;
   union {
   _IO_STACK_LOCATION * CurrentStackLocation;
   unsigned long PacketType;
   };
   _FILE_OBJECT * OriginalFileObject;
} UNNAMED_TAG_53262DC;

typedef union UNNAMED_TAG_2E6C640
{
   union {
   UNNAMED_TAG_4C54AFF AsynchronousParameters;
   _LARGE_INTEGER AllocationSize;
   };
} UNNAMED_TAG_2E6C640;

typedef struct UNNAMED_TAG_4FD1ADF
{
   void * UserApcRoutine;
   void * UserApcContext;
} UNNAMED_TAG_4FD1ADF;

typedef struct NSR_FID
{
   DESTAG Destag;
   short Version;
   unsigned char Flags;
   unsigned char FileIDLen;
   LONGAD Icb;
   short ImpUseLen;
   unsigned char ImpUse[1];
   unsigned char FileID[1];
   unsigned char Padding[1];
} NSR_FID;

typedef struct PARTMAP_PHYSICAL
{
   unsigned char Type;
   unsigned char Length;
   short VolSetSeq;
   short Partition;
} PARTMAP_PHYSICAL;

typedef union UNNAMED_TAG_1CF0D80
{
   union {
   UNNAMED_TAG_4F3D9D2 Event;
   unsigned long RawEvent[4];
   };
} UNNAMED_TAG_1CF0D80;

typedef struct UNNAMED_TAG_4F21B14
{
   unsigned char Type;
   unsigned char Absolute;
   unsigned char Size;
   unsigned char Inserted;
   long SignalState;
   _LIST_ENTRY WaitListHead;
} UNNAMED_TAG_4F21B14;

typedef struct _FORMAT_PARAMETERS
{
   int MediaType;
   unsigned long StartCylinderNumber;
   unsigned long EndCylinderNumber;
   unsigned long StartHeadNumber;
   unsigned long EndHeadNumber;
} FORMAT_PARAMETERS;

typedef struct ICBTRM
{
   DESTAG Destag;
   ICBTAG Icbtag;
} ICBTRM;

typedef struct VSD_GENERIC
{
   unsigned char Type;
   unsigned char Ident[5];
   unsigned char Version;
   unsigned char Data[2041];
} VSD_GENERIC;

typedef struct VSD_BOOT2
{
   unsigned char Type;
   unsigned char Ident[5];
   unsigned char Version;
   unsigned char Res8;
   REGID Architecture;
   REGID BootIdent;
   unsigned long BootExt;
   unsigned long BootExtLen;
   unsigned long LoadAddr[2];
   unsigned long StartAddr[2];
   TIMESTAMP Timestamp;
   short Flags;
   unsigned char Res110[32];
   unsigned char BootUse[1906];
} VSD_BOOT2;

typedef struct ICBUASE
{
   DESTAG Destag;
   ICBTAG Icbtag;
   unsigned long AllocLen;
   unsigned char Allocs[0];
} ICBUASE;

typedef struct NSR_ANCHOR
{
   DESTAG Destag;
   EXTENTAD Main;
   EXTENTAD Reserve;
   unsigned char Res32[480];
} NSR_ANCHOR;

typedef struct UNNAMED_TAG_300E5D
{
   unsigned long LowPart;
   unsigned long HighPart;
} UNNAMED_TAG_300E5D;

typedef struct NSR_INTEG
{
   DESTAG Destag;
   TIMESTAMP Time;
   unsigned long Type;
   EXTENTAD Next;
   NSR_LVHD LVHD;
   unsigned long PartitionCount;
   unsigned long ImpUseLength;
   unsigned long Free[1];
   unsigned long Size[1];
   unsigned char ImpUse[0];
} NSR_INTEG;

typedef struct _VERIFY_INFORMATION
{
   _LARGE_INTEGER StartingOffset;
   unsigned long Length;
} VERIFY_INFORMATION;

typedef struct NSR_LVHD
{
   unsigned long UniqueID[2];
   unsigned char Res8[24];
} NSR_LVHD;

typedef struct NSR_LVOL
{
   DESTAG Destag;
   unsigned long VolDescSeqNum;
   CHARSPEC Charset;
   unsigned char VolumeID[128];
   unsigned long BlockSize;
   REGID DomainID;
   LONGAD FSD;
   unsigned long MapTableLength;
   unsigned long MapTableCount;
   REGID ImpUseID;
   unsigned char ImpUse[128];
   EXTENTAD Integrity;
   unsigned char MapTable[0];
} NSR_LVOL;

typedef struct _MAPPED_ADDRESS
{
   _MAPPED_ADDRESS * NextMappedAddress;
   void * MappedAddress;
   unsigned long NumberOfBytes;
   unsigned long Padding3;
   _LARGE_INTEGER IoAddress;
   unsigned long BusNumber;
} MAPPED_ADDRESS;

typedef struct _FORMAT_EX_PARAMETERS
{
   int MediaType;
   unsigned long StartCylinderNumber;
   unsigned long EndCylinderNumber;
   unsigned long StartHeadNumber;
   unsigned long EndHeadNumber;
   short FormatGapLength;
   short SectorsPerTrack;
   short SectorNumber[1];
} FORMAT_EX_PARAMETERS;

typedef struct _DRIVE_LAYOUT_INFORMATION
{
   unsigned long PartitionCount;
   unsigned long Signature;
   _PARTITION_INFORMATION PartitionEntry[1];
} DRIVE_LAYOUT_INFORMATION;

typedef struct UNNAMED_TAG_54E156B
{
   union {
   unsigned long RoundingMode;
   unsigned long Inexact;
   unsigned long Underflow;
   unsigned long Overflow;
   unsigned long ZeroDivide;
   unsigned long InvalidOperation;
   unsigned long OperandValid;
   unsigned long Format;
   unsigned long Precision;
   unsigned long Operation;
   unsigned long Spare;
   unsigned long HardwareException;
   };
} UNNAMED_TAG_54E156B;

typedef union UNNAMED_TAG_1A4C3D8
{
   union {
   short I16Value;
   short U16Value;
   long I32Value;
   unsigned long U32Value;
   void * StringValue;
   unsigned long CompareValue;
   _FP_32 Fp32Value;
   _LARGE_INTEGER I64Value;
   _ULARGE_INTEGER U64Value;
   _FP_64 Fp64Value;
   _FP_80 Fp80Value;
   _FP_128 Fp128Value;
   };
} UNNAMED_TAG_1A4C3D8;

typedef struct _CDROM_SUB_Q_DATA_FORMAT
{
   unsigned char Format;
   unsigned char Track;
} CDROM_SUB_Q_DATA_FORMAT;

typedef struct _UDF_VOLUME_EXTENSION
{
   union {
   _FSCACHE_EXTENSION CacheExtension;
   _DEVICE_OBJECT * TargetDeviceObject;
   };
   _LARGE_INTEGER PartitionLength;
   unsigned long SectorSize;
   _UDF_FCB * VolumeFcb;
   _UDF_FCB * RootDirectoryFcb;
   unsigned long PhysicalSectorCount;
   unsigned long PartitionSectorStart;
   unsigned long PartitionSectorCount;
   unsigned long FileObjectCount;
   unsigned char Dismounted;
} UDF_VOLUME_EXTENSION;

typedef struct _UDF_FCB
{
   unsigned char Flags;
   unsigned char FileNameLength;
   short EmbeddedDataOffset;
   unsigned long AllocationSectorStart;
   _LARGE_INTEGER FileSize;
   TIMESTAMP ModifyTime;
   unsigned long ReferenceCount;
   _UDF_FCB * ParentFcb;
   _LIST_ENTRY SiblingFcbLink;
   _LIST_ENTRY ChildFcbList;
   char FileName[0];
} UDF_FCB;

typedef struct _PERF_BIN
{
   unsigned long NumberOfBins;
   unsigned long TypeOfBin;
   _BIN_RANGE BinsRanges[1];
} PERF_BIN;

typedef struct VSD_BEA01
{
   unsigned char Type;
   unsigned char Ident[5];
   unsigned char Version;
   unsigned char Data[2041];
} VSD_BEA01;

typedef struct _IDE_SECURITY_DATA
{
   union {
   short Master;
   short Reserved1;
   short Maximum;
   short Reserved2;
   };
   unsigned char Password[32];
   short Reserved3[239];
} IDE_SECURITY_DATA;

typedef struct _SUB_Q_CURRENT_POSITION
{
   _SUB_Q_HEADER Header;
   unsigned char FormatCode;
   union {
   unsigned char Control;
   unsigned char ADR;
   };
   unsigned char TrackNumber;
   unsigned char IndexNumber;
   unsigned char AbsoluteAddress[4];
   unsigned char TrackRelativeAddress[4];
} SUB_Q_CURRENT_POSITION;

typedef struct _SENDCMDINPARAMS
{
   unsigned long cBufferSize;
   _IDEREGS irDriveRegs;
   unsigned char bDriveNumber;
   unsigned char bReserved[3];
   unsigned long dwReserved[4];
   unsigned char bBuffer[1];
} SENDCMDINPARAMS;

typedef struct _ATA_PASS_THROUGH
{
   _IDEREGS IdeReg;
   unsigned long DataBufferSize;
   void * DataBuffer;
} ATA_PASS_THROUGH;

typedef struct _IDEREGS
{
   unsigned char bFeaturesReg;
   unsigned char bSectorCountReg;
   unsigned char bSectorNumberReg;
   unsigned char bCylLowReg;
   unsigned char bCylHighReg;
   unsigned char bDriveHeadReg;
   unsigned char bCommandReg;
   unsigned char bHostSendsData;
} IDEREGS;

typedef union UNNAMED_TAG_5696679
{
   union {
   UNNAMED_TAG_1C1A7CB Port;
   UNNAMED_TAG_24A5AC8 Memory;
   };
} UNNAMED_TAG_5696679;

typedef struct UNNAMED_TAG_71E9BC
{
   void * TranslatedAddress;
   unsigned long Length;
} UNNAMED_TAG_71E9BC;

typedef struct _IDE_IDENTIFY_DATA
{
   short GeneralConfiguration;
   short NumberOfCylinders;
   short Reserved1;
   short NumberOfHeads;
   short Reserved2[2];
   short NumberOfSectorsPerTrack;
   short Reserved3[3];
   unsigned char SerialNumber[20];
   short Reserved4[3];
   unsigned char FirmwareRevision[8];
   unsigned char ModelNumber[40];
   union {
   short MaximumBlockTransfer;
   short Reserved5;
   };
   short Reserved6;
   short Capabilities;
   short Reserved7;
   union {
   short Reserved8;
   short PioCycleTimingMode;
   };
   short Reserved9;
   union {
   short TranslationFieldsValid;
   short Reserved10;
   };
   short NumberOfCurrentCylinders;
   short NumberOfCurrentHeads;
   short CurrentSectorsPerTrack;
   unsigned long CurrentSectorCapacity;
   short CurrentMultiSectorSetting;
   unsigned long UserAddressableSectors;
   union {
   short SingleWordDMASupport;
   short SingleWordDMAActive;
   };
   union {
   short MultiWordDMASupport;
   short MultiWordDMAActive;
   };
   union {
   short AdvancedPIOModes;
   short Reserved11;
   };
   short MinimumMWXferCycleTime;
   short RecommendedMWXferCycleTime;
   short MinimumPIOCycleTime;
   short MinimumPIOCycleTimeIORDY;
   short Reserved12[11];
   short MajorRevision;
   short MinorRevision;
   short Reserved13[6];
   union {
   short UltraDMASupport;
   short UltraDMAActive;
   };
   short Reserved14[38];
   union {
   short MediaStatusNotification;
   short Reserved15;
   short DeviceWriteProtect;
   short Reserved16;
   };
   union {
   short SecuritySupported;
   short SecurityEnabled;
   short SecurityLocked;
   short SecurityFrozen;
   short SecurityCountExpired;
   short SecurityEraseSupported;
   short Reserved17;
   short SecurityLevel;
   short Reserved18;
   };
   short Reserved19[127];
} IDE_IDENTIFY_DATA;

typedef struct NSR_PART
{
   DESTAG Destag;
   unsigned long VolDescSeqNum;
   short Flags;
   short Number;
   REGID ContentsID;
   unsigned char ContentsUse[128];
   unsigned long AccessType;
   unsigned long Start;
   unsigned long Length;
   REGID ImpUseID;
   unsigned char ImpUse[128];
   unsigned char Res356[156];
} NSR_PART;

typedef union UNNAMED_TAG_1A60296
{
   union {
   unsigned long ForwarderString;
   unsigned long Function;
   unsigned long Ordinal;
   unsigned long AddressOfData;
   };
} UNNAMED_TAG_1A60296;

typedef struct _KIPI_COUNTS
{
   unsigned long Freeze;
   unsigned long Packet;
   unsigned long DPC;
   unsigned long APC;
   unsigned long FlushSingleTb;
   unsigned long FlushMultipleTb;
   unsigned long FlushEntireTb;
   unsigned long GenericCall;
   unsigned long ChangeColor;
   unsigned long SweepDcache;
   unsigned long SweepIcache;
   unsigned long SweepIcacheRange;
   unsigned long FlushIoBuffers;
   unsigned long GratuitousDPC;
} KIPI_COUNTS;

typedef union UNNAMED_TAG_555BFE3
{
   union {
   unsigned char ShortName[8];
   UNNAMED_TAG_4BBD78C Name;
   unsigned long LongName[2];
   };
} UNNAMED_TAG_555BFE3;

typedef struct UNNAMED_TAG_2A36A39
{
   unsigned long Short;
   unsigned long Long;
} UNNAMED_TAG_2A36A39;

typedef struct CHARSPEC
{
   unsigned char Type;
   unsigned char Info[63];
} CHARSPEC;

typedef struct NSR_FSD
{
   DESTAG Destag;
   TIMESTAMP Time;
   short Level;
   short LevelMax;
   unsigned long CharSetList;
   unsigned long CharSetListMax;
   unsigned long FileSet;
   unsigned long FileSetDesc;
   CHARSPEC CharspecVolID;
   unsigned char VolID[128];
   CHARSPEC CharspecFileSet;
   unsigned char FileSetID[32];
   unsigned char Copyright[32];
   unsigned char Abstract[32];
   LONGAD IcbRoot;
   REGID DomainID;
   LONGAD NextExtent;
   unsigned char Res464[48];
} NSR_FSD;

typedef struct _DISK_HISTOGRAM
{
   _LARGE_INTEGER DiskSize;
   _LARGE_INTEGER Start;
   _LARGE_INTEGER End;
   _LARGE_INTEGER Average;
   _LARGE_INTEGER AverageRead;
   _LARGE_INTEGER AverageWrite;
   unsigned long Granularity;
   unsigned long Size;
   unsigned long ReadCount;
   unsigned long WriteCount;
   _HISTOGRAM_BUCKET * Histogram;
} DISK_HISTOGRAM;

typedef struct NSR_UASD
{
   DESTAG Destag;
   unsigned long VolDescSeqNum;
   unsigned long ExtentCount;
   EXTENTAD Extents[0];
} NSR_UASD;

typedef struct _REASSIGN_BLOCKS
{
   short Reserved;
   short Count;
   unsigned long BlockNumber[1];
} REASSIGN_BLOCKS;

typedef struct NSR_VD_GENERIC
{
   DESTAG Destag;
   unsigned long Sequence;
   unsigned char Data20[492];
} NSR_VD_GENERIC;

typedef struct __RAW_READ_INFO
{
   _LARGE_INTEGER DiskOffset;
   unsigned long SectorCount;
   int TrackMode;
} _RAW_READ_INFO;

typedef struct UNNAMED_TAG_3B298DF
{
   _PCI_DEVICE_ADDRESS Address[1];
   UNNAMED_TAG_7660C8 Interrupt;
} UNNAMED_TAG_3B298DF;

typedef struct UNNAMED_TAG_45B4CBE
{
   unsigned long Vector;
   unsigned long Affinity;
   unsigned char Irql;
} UNNAMED_TAG_45B4CBE;

typedef struct UNNAMED_TAG_392A9BE
{
   unsigned long LowPart;
   long HighPart;
} UNNAMED_TAG_392A9BE;

typedef struct _VOLUME_CONTROL
{
   unsigned char PortVolume[4];
} VOLUME_CONTROL;

typedef union UNNAMED_TAG_4B871CC
{
   union {
   unsigned long SymbolTableIndex;
   unsigned long VirtualAddress;
   };
} UNNAMED_TAG_4B871CC;

typedef struct NSR_EA_FILETIMES
{
   unsigned long EAType;
   unsigned char EASubType;
   unsigned char Res5[3];
   unsigned long EALength;
   unsigned long DataLength;
   unsigned long Existence;
   TIMESTAMP Stamps[0];
} NSR_EA_FILETIMES;

typedef struct TIMESTAMP
{
   union {
   short Zone;
   short Type;
   };
   short Year;
   unsigned char Month;
   unsigned char Day;
   unsigned char Hour;
   unsigned char Minute;
   unsigned char Second;
   unsigned char CentiSecond;
   unsigned char Usec100;
   unsigned char Usec;
} TIMESTAMP;

typedef struct _HISTOGRAM_BUCKET
{
   unsigned long Reads;
   unsigned long Writes;
} HISTOGRAM_BUCKET;

typedef union UNNAMED_TAG_3616E77
{
   union {
   unsigned long NameOrId;
   _IMAGE_RESOURCE_DIRECTORY_STRING * Name;
   short Id;
   };
   short NameIsPresent;
} UNNAMED_TAG_3616E77;

typedef struct _DISK_RECORD
{
   _LARGE_INTEGER ByteOffset;
   _LARGE_INTEGER StartTime;
   _LARGE_INTEGER EndTime;
   void * VirtualAddress;
   unsigned long NumberOfBytes;
   unsigned char DeviceNumber;
   unsigned char ReadRequest;
} DISK_RECORD;

typedef struct SHORTAD
{
   NSRLENGTH Length;
   unsigned long Start;
} SHORTAD;

typedef struct _PARTITION_INFORMATION
{
   _LARGE_INTEGER StartingOffset;
   _LARGE_INTEGER PartitionLength;
   unsigned long HiddenSectors;
   unsigned long PartitionNumber;
   unsigned char PartitionType;
   unsigned char BootIndicator;
   unsigned char RecognizedPartition;
   unsigned char RewritePartition;
} PARTITION_INFORMATION;

typedef struct UNNAMED_TAG_3B97E81
{
   void * OldStackBase;
   void * OldStackLimit;
} UNNAMED_TAG_3B97E81;

typedef struct _CDROM_DISK_DATA
{
   unsigned long DiskData;
} CDROM_DISK_DATA;

typedef struct _TRACK_DATA
{
   unsigned char Reserved;
   union {
   unsigned char Control;
   unsigned char Adr;
   };
   unsigned char TrackNumber;
   unsigned char Reserved1;
   unsigned char Address[4];
} TRACK_DATA;

typedef struct _CDROM_TOC
{
   unsigned char Length[2];
   unsigned char FirstTrack;
   unsigned char LastTrack;
   _TRACK_DATA TrackData[100];
} CDROM_TOC;

typedef struct LONGAD
{
   NSRLENGTH Length;
   NSRLBA Start;
   unsigned char ImpUse[6];
} LONGAD;

typedef struct ICBTAG
{
   unsigned long PriorDirectCount;
   short StratType;
   short StratParm;
   short MaxEntries;
   unsigned char Res10;
   unsigned char FileType;
   NSRLBA IcbParent;
   short Flags;
} ICBTAG;

typedef struct ICBIND
{
   DESTAG Destag;
   ICBTAG Icbtag;
   LONGAD Icb;
} ICBIND;

typedef struct VSD_NSR02
{
   unsigned char Type;
   unsigned char Ident[5];
   unsigned char Version;
   unsigned char Res7;
   unsigned char Data[2040];
} VSD_NSR02;

typedef struct _GETVERSIONINPARAMS
{
   unsigned char bVersion;
   unsigned char bRevision;
   unsigned char bReserved;
   unsigned char bIDEDeviceMap;
   unsigned long fCapabilities;
   unsigned long dwReserved[4];
} GETVERSIONINPARAMS;

typedef struct _SUB_Q_TRACK_ISRC
{
   _SUB_Q_HEADER Header;
   unsigned char FormatCode;
   unsigned char Reserved0;
   unsigned char Track;
   unsigned char Reserved1;
   union {
   unsigned char Reserved2;
   unsigned char Tcval;
   };
   unsigned char TrackIsrc[15];
} SUB_Q_TRACK_ISRC;

typedef struct _SENDCMDOUTPARAMS
{
   unsigned long cBufferSize;
   _DRIVERSTATUS DriverStatus;
   unsigned char bBuffer[1];
} SENDCMDOUTPARAMS;

typedef struct _CDROM_PLAY_AUDIO_MSF
{
   unsigned char StartingM;
   unsigned char StartingS;
   unsigned char StartingF;
   unsigned char EndingM;
   unsigned char EndingS;
   unsigned char EndingF;
} CDROM_PLAY_AUDIO_MSF;

typedef struct NSR_EA_GENERIC
{
   unsigned long EAType;
   unsigned char EASubType;
   unsigned char Res5[3];
   unsigned long EALength;
   unsigned char EAData[0];
} NSR_EA_GENERIC;

typedef struct _DISK_CACHE_INFORMATION
{
   unsigned char ParametersSavable;
   unsigned char ReadCacheEnabled;
   unsigned char WriteCacheEnabled;
   unsigned char Padding3;
   int ReadRetentionPriority;
   int WriteRetentionPriority;
   short DisablePrefetchTransferLength;
   unsigned char PrefetchScalar;
   unsigned char Padding8;
   union {
   UNNAMED_TAG_49AB408 ScalarPrefetch;
   UNNAMED_TAG_31EA4C8 BlockPrefetch;
   };
} DISK_CACHE_INFORMATION;

typedef struct _DRIVERSTATUS
{
   unsigned char bDriverError;
   unsigned char bIDEError;
   unsigned char bReserved[2];
   unsigned long dwReserved[2];
} DRIVERSTATUS;

typedef struct NSR_ALLOC
{
   DESTAG Destag;
   unsigned long Prev;
   unsigned long AllocLen;
} NSR_ALLOC;

typedef struct NSRLBA
{
   unsigned long Lbn;
   short Partition;
} NSRLBA;

typedef struct NSRLENGTH
{
   union {
   unsigned long Length;
   unsigned long Type;
   };
} NSRLENGTH;

typedef struct EXTAD
{
   NSRLENGTH ExtentLen;
   NSRLENGTH RecordedLen;
   unsigned long InfoLen;
   NSRLBA Start;
   unsigned char ImpUse[2];
} EXTAD;

typedef struct NSR_EAH
{
   DESTAG Destag;
   unsigned long EAImp;
   unsigned long EAApp;
} NSR_EAH;

typedef struct EXTENTAD
{
   unsigned long Len;
   unsigned long Lsn;
} EXTENTAD;

typedef struct NSR_VDP
{
   DESTAG Destag;
   unsigned long VolDescSeqNum;
   EXTENTAD Next;
   unsigned char Res28[484];
} NSR_VDP;

typedef struct _SET_PARTITION_INFORMATION
{
   unsigned char PartitionType;
} SET_PARTITION_INFORMATION;

typedef struct _BIN_RESULTS
{
   unsigned long NumberOfBins;
   unsigned long Padding1;
   _BIN_COUNT BinCounts[1];
} BIN_RESULTS;

typedef struct _BIN_RANGE
{
   _LARGE_INTEGER StartValue;
   _LARGE_INTEGER Length;
} BIN_RANGE;

typedef struct _BIN_COUNT
{
   _BIN_RANGE BinRange;
   unsigned long BinCount;
} BIN_COUNT;

typedef struct PARTMAP_PROXY
{
   unsigned char Type;
   unsigned char Length;
   unsigned char PartID[62];
} PARTMAP_PROXY;

typedef struct UNNAMED_TAG_4C54AFF
{
   unsigned long Length;
   short NumberOfRelocations;
   short NumberOfLinenumbers;
   unsigned long CheckSum;
   short Number;
   unsigned char Selection;
} UNNAMED_TAG_4C54AFF;

typedef struct UNNAMED_TAG_4F3D9D2
{
   unsigned char Name[18];
} UNNAMED_TAG_4F3D9D2;

typedef struct UNNAMED_TAG_24A5AC8
{
   unsigned long TagIndex;
   UNNAMED_TAG_5B1AF34 Misc;
   UNNAMED_TAG_1794B53 FcnAry;
   short TvIndex;
} UNNAMED_TAG_24A5AC8;

typedef union UNNAMED_TAG_1C1A7CB
{
   union {
   UNNAMED_TAG_18167A9 Function;
   UNNAMED_TAG_1731685 Array;
   };
} UNNAMED_TAG_1C1A7CB;

typedef struct UNNAMED_TAG_4BBD78C
{
   short Dimension[4];
} UNNAMED_TAG_4BBD78C;

typedef struct UNNAMED_TAG_7660C8
{
   unsigned long PointerToLinenumber;
   unsigned long PointerToNextFunction;
} UNNAMED_TAG_7660C8;

typedef union UNNAMED_TAG_31EA4C8
{
   union {
   UNNAMED_TAG_375CD69 LnSz;
   unsigned long TotalSize;
   };
} UNNAMED_TAG_31EA4C8;

typedef struct UNNAMED_TAG_49AB408
{
   short Linenumber;
   short Size;
} UNNAMED_TAG_49AB408;

typedef struct VSD_TEA01
{
   unsigned char Type;
   unsigned char Ident[5];
   unsigned char Version;
   unsigned char Data[2041];
} VSD_TEA01;

typedef struct _DISK_CONTROLLER_NUMBER
{
   unsigned long ControllerNumber;
   unsigned long DiskNumber;
} DISK_CONTROLLER_NUMBER;

typedef struct _SUB_Q_HEADER
{
   unsigned char Reserved;
   unsigned char AudioStatus;
   unsigned char DataLength[2];
} SUB_Q_HEADER;

typedef union UNNAMED_TAG_1794B53
{
   union {
   UNNAMED_TAG_3024B80 Bytes;
   UNNAMED_TAG_3D72684 Bits;
   };
} UNNAMED_TAG_1794B53;

typedef struct UNNAMED_TAG_5B1AF34
{
   union {
   unsigned long BaseMid;
   unsigned long Type;
   unsigned long Dpl;
   unsigned long Pres;
   unsigned long LimitHi;
   unsigned long Sys;
   unsigned long Reserved_0;
   unsigned long Default_Big;
   unsigned long Granularity;
   unsigned long BaseHi;
   };
} UNNAMED_TAG_5B1AF34;

typedef struct UNNAMED_TAG_1731685
{
   unsigned char BaseMid;
   unsigned char Flags1;
   unsigned char Flags2;
   unsigned char BaseHi;
} UNNAMED_TAG_1731685;

typedef struct _CDROM_SEEK_AUDIO_MSF
{
   unsigned char M;
   unsigned char S;
   unsigned char F;
} CDROM_SEEK_AUDIO_MSF;

typedef struct REGID
{
   unsigned char Flags;
   unsigned char Identifier[23];
   unsigned char Suffix[8];
} REGID;

typedef struct DESTAG
{
   short Ident;
   short Version;
   unsigned char Checksum;
   unsigned char Res5;
   short Serial;
   short CRC;
   short CRCLen;
   unsigned long Lbn;
} DESTAG;

typedef struct NSR_IMPUSE
{
   DESTAG Destag;
   unsigned long VolDescSeqNum;
   REGID ImpUseID;
   unsigned char ImpUse[460];
} NSR_IMPUSE;

typedef union UNNAMED_TAG_18167A9
{
   union {
   UNNAMED_TAG_1D7FE85 Port;
   UNNAMED_TAG_5970C1B Memory;
   UNNAMED_TAG_256757D Interrupt;
   UNNAMED_TAG_175C68D Dma;
   UNNAMED_TAG_553175F Generic;
   UNNAMED_TAG_337C7FB DevicePrivate;
   UNNAMED_TAG_E9A3DD BusNumber;
   UNNAMED_TAG_3F103DB AssignedResource;
   UNNAMED_TAG_21FDEA SubAllocateFrom;
   UNNAMED_TAG_4768173 ConfigData;
   };
} UNNAMED_TAG_18167A9;

typedef struct UNNAMED_TAG_375CD69
{
   unsigned long Priority;
   unsigned long Reserved1;
   unsigned long Reserved2;
} UNNAMED_TAG_375CD69;

typedef struct UNNAMED_TAG_3D72684
{
   unsigned char Type;
   unsigned char Reserved[3];
   void * AssignedResource;
   _LARGE_INTEGER Transformation;
} UNNAMED_TAG_3D72684;

typedef struct UNNAMED_TAG_3024B80
{
   void * AssignedResource;
} UNNAMED_TAG_3024B80;

typedef struct UNNAMED_TAG_4768173
{
   unsigned long Length;
   unsigned long MinBusNumber;
   unsigned long MaxBusNumber;
   unsigned long Reserved;
} UNNAMED_TAG_4768173;

typedef struct UNNAMED_TAG_21FDEA
{
   unsigned long Data[3];
} UNNAMED_TAG_21FDEA;

typedef struct UNNAMED_TAG_3F103DB
{
   unsigned long MinimumChannel;
   unsigned long MaximumChannel;
} UNNAMED_TAG_3F103DB;

typedef struct UNNAMED_TAG_E9A3DD
{
   unsigned long MinimumVector;
   unsigned long MaximumVector;
} UNNAMED_TAG_E9A3DD;

typedef struct UNNAMED_TAG_337C7FB
{
   unsigned long Length;
   unsigned long Alignment;
   _LARGE_INTEGER MinimumAddress;
   _LARGE_INTEGER MaximumAddress;
} UNNAMED_TAG_337C7FB;

typedef struct _DISK_GEOMETRY
{
   _LARGE_INTEGER Cylinders;
   int MediaType;
   unsigned long TracksPerCylinder;
   unsigned long SectorsPerTrack;
   unsigned long BytesPerSector;
} DISK_GEOMETRY;

typedef struct NSR_PATH
{
   unsigned char Type;
   unsigned char CompLen;
   unsigned char CompVer;
   unsigned char Comp[0];
} NSR_PATH;

typedef struct _DBGKD_DEBUG_DATA_HEADER64
{
   LIST_ENTRY64 List;
   unsigned long OwnerTag;
   unsigned long Size;
} DBGKD_DEBUG_DATA_HEADER64;

typedef struct _ACL_REVISION_INFORMATION
{
   unsigned long AclRevision;
} ACL_REVISION_INFORMATION;

typedef struct _COMPRESSED_DATA_INFO
{
   short CompressionFormatAndEngine;
   unsigned char CompressionUnitShift;
   unsigned char ChunkShift;
   unsigned char ClusterShift;
   unsigned char Reserved;
   short NumberOfChunks;
   unsigned long CompressedChunkSizes[1];
} COMPRESSED_DATA_INFO;

typedef struct HSTR__
{
   int unused;
} HSTR__;

typedef struct UNNAMED_TAG_553175F
{
   unsigned long size;
   unsigned long monochrome[1];
} UNNAMED_TAG_553175F;

typedef union _IMAGE_THUNK_DATA64::__unnamed
{
   union {
   __int64 ForwarderString;
   __int64 Function;
   __int64 Ordinal;
   __int64 AddressOfData;
   };
} IMAGE_THUNK_DATA64::__unnamed;

typedef struct IPersistStream
{
   union {
   (type???) IPersist;
   (type???) IsDirty;
   (type???) Load;
   (type???) Save;
   (type???) GetSizeMax;
   (type???) IPersistStream;
   (type???) IPersistStream;
   };
} IPersistStream;

typedef struct __s_GUID
{
   unsigned long Data1;
   short Data2;
   short Data3;
   unsigned char Data4[8];
} _s_GUID;

typedef struct _DSBUFFERDESC
{
   unsigned long dwSize;
   unsigned long dwFlags;
   unsigned long dwBufferBytes;
   tWAVEFORMATEX * lpwfxFormat;
   unsigned long dwMixBinMask;
   unsigned long dwInputMixBinMask;
} DSBUFFERDESC;

typedef struct _DXFILELOADMEMORY
{
   void * lpMemory;
   unsigned long dSize;
} DXFILELOADMEMORY;

typedef struct HDC__
{
   int unused;
} HDC__;

typedef struct UNNAMED_TAG_175C68D
{
   unsigned long size;
   unsigned long monochrome[7];
} UNNAMED_TAG_175C68D;

typedef struct _SYSTEM_TIMEOFDAY_INFORMATION
{
   _LARGE_INTEGER BootTime;
   _LARGE_INTEGER CurrentTime;
   _LARGE_INTEGER TimeZoneBias;
   unsigned long TimeZoneId;
   unsigned long Reserved;
   __int64 BootTimeBias;
   __int64 SleepTimeBias;
} SYSTEM_TIMEOFDAY_INFORMATION;

typedef struct _NAPDATA
{
   unsigned long NapLock;
   unsigned long Calls;
   unsigned long TimingErrors;
   unsigned long Padding3;
   _LARGE_INTEGER TotalTime;
   _LARGE_INTEGER FirstTime;
   _LARGE_INTEGER MaxTime;
   _LARGE_INTEGER MinTime;
} NAPDATA;

typedef struct _IMAGE_IMPORT_BY_NAME
{
   short Hint;
   unsigned char Name[1];
} IMAGE_IMPORT_BY_NAME;

typedef struct UNNAMED_TAG_256757D
{
   unsigned long size;
   unsigned long monochrome[3];
} UNNAMED_TAG_256757D;

typedef struct _FILE_DISPOSITION_INFORMATION
{
   unsigned char DeleteFile;
} FILE_DISPOSITION_INFORMATION;

typedef struct APU_OBJECT
{
   unsigned long uDeviceRef;
   unsigned char uObjectCode;
   unsigned char Padding2;
   unsigned char Padding3;
   unsigned char Padding4;
   unsigned long pParam;
} APU_OBJECT;

typedef struct CODEC_AUDIO_CREATE
{
   unsigned long pioBaseMixer;
   unsigned long pioBaseAci;
} CODEC_AUDIO_CREATE;

typedef struct APU_AP_FREE_CONTEXT_DMA
{
   unsigned long uDeviceRef;
   unsigned long uHandle;
} APU_AP_FREE_CONTEXT_DMA;

typedef struct APU_AP_ALLOC_CONTEXT_DMA
{
   unsigned long uDeviceRef;
   unsigned char uType;
   unsigned char Padding2;
   unsigned char Padding3;
   unsigned char Padding4;
   unsigned long uBaseAddress;
   unsigned long uMaxOffset;
   unsigned long uHandle;
} APU_AP_ALLOC_CONTEXT_DMA;

typedef struct AUDIO_INIT_DEVICE
{
   unsigned long pResList;
   unsigned char uRevisionID;
   unsigned char Padding2;
   unsigned char Padding3;
   unsigned char Padding4;
   unsigned long pDevObj;
   void * pISRFn;
   unsigned long pServiceContext;
   INTR_MASK IntrMask;
   unsigned long uDeviceRef;
} AUDIO_INIT_DEVICE;

typedef union INTR_MASK
{
   union {
   INTR_MASK::__unnamed codec;
   INTR_MASK::__unnamed apu;
   unsigned long uValue;
   };
} INTR_MASK;

typedef struct INTR_MASK::__unnamed
{
   union {
   unsigned long FEMethodOverFlow;
   unsigned long FEVoice;
   unsigned long FENotify;
   unsigned long DeltaPanic;
   unsigned long DeltaWarning;
   };
} INTR_MASK::__unnamed;

typedef struct Nv0A3Typedef
{
   unsigned long Reserved00[1984];
} Nv0A3Typedef;

typedef struct NVDE_WRITE_MEMORY_PARAMETERS
{
   unsigned long Address;
   unsigned long Size;
   unsigned long Data;
} NVDE_WRITE_MEMORY_PARAMETERS;

typedef struct NVDE_UNREGISTER_DEBUGGER_PARAMETERS
{
   unsigned long foo;
} NVDE_UNREGISTER_DEBUGGER_PARAMETERS;

typedef struct Nv03ChannelPio
{
   volatile Nv03SubchannelPio subchannel[8];
} Nv03ChannelPio;

typedef struct Nv03SubchannelPio
{
   unsigned long SetObject;
   volatile Nv03ControlPio control;
   union {
   volatile Nv000Typedef Nv01Root;
   volatile Nv001Typedef Nv01Class;
   volatile Nv002Typedef Nv01ContextDmaFromMemory;
   volatile Nv003Typedef Nv01ContextDmaToMemory;
   volatile Nv004Typedef Nv01Timer;
   volatile _Nv005Typedef Nv01Event;
   unsigned long NV006_TYPEDEF;
   unsigned long NV007_TYPEDEF;
   unsigned long NV008_TYPEDEF;
   unsigned long NV009_TYPEDEF;
   unsigned long NV00A_TYPEDEF;
   unsigned long NV00B_TYPEDEF;
   unsigned long NV00C_TYPEDEF;
   unsigned long NV00D_TYPEDEF;
   unsigned long NV00E_TYPEDEF;
   unsigned long NV00F_TYPEDEF;
   unsigned long NV010_TYPEDEF;
   unsigned long NV011_TYPEDEF;
   volatile Nv012Typedef Nv01ContextBeta;
   unsigned long NV013_TYPEDEF;
   unsigned long NV014_TYPEDEF;
   unsigned long NV015_TYPEDEF;
   unsigned long NV016_TYPEDEF;
   volatile Nv017Typedef Nv01ContextColorKey;
   volatile Nv018Typedef Nv01ContextPattern;
   volatile Nv019Typedef Nv01ContextClipRectangle;
   unsigned long NV01A_TYPEDEF;
   unsigned long NV01B_TYPEDEF;
   volatile Nv01cTypedef Nv01RenderSolidLin;
   volatile Nv01dTypedef Nv01RenderSolidTriangle;
   volatile Nv01eTypedef Nv01RenderSolidRectangle;
   volatile Nv01fTypedef Nv01ImageBlit;
   unsigned long NV020_TYPEDEF;
   volatile Nv021Typedef Nv01ImageFromCpu;
   unsigned long NV022_TYPEDEF;
   unsigned long NV023_TYPEDEF;
   unsigned long NV024_TYPEDEF;
   unsigned long NV025_TYPEDEF;
   unsigned long NV026_TYPEDEF;
   unsigned long NV027_TYPEDEF;
   unsigned long NV028_TYPEDEF;
   unsigned long NV029_TYPEDEF;
   unsigned long NV02A_TYPEDEF;
   unsigned long NV02B_TYPEDEF;
   unsigned long NV02C_TYPEDEF;
   unsigned long NV02D_TYPEDEF;
   unsigned long NV02E_TYPEDEF;
   unsigned long NV02F_TYPEDEF;
   volatile Nv030Typedef Nv01Null;
   unsigned long NV031_TYPEDEF;
   unsigned long NV032_TYPEDEF;
   unsigned long NV033_TYPEDEF;
   unsigned long NV034_TYPEDEF;
   unsigned long NV035_TYPEDEF;
   volatile Nv036Typedef Nv03StretchedImageFromCpu;
   volatile Nv037Typedef Nv03ScaledImageFromMemory;
   volatile Nv038Typedef Nv04DvdSubpicture;
   volatile Nv039Typedef Nv03MemoryToMemoryFormat;
   unsigned long NV03A_TYPEDEF;
   unsigned long NV03B_TYPEDEF;
   unsigned long NV03C_TYPEDEF;
   volatile Nv03dTypedef Nv01ContextDmaInMemory;
   volatile Nv03eTypedef Nv01ContextErrorToMemory;
   volatile Nv03fTypedef Nv01MemoryLocalPrivileged;
   volatile Nv040Typedef Nv01MemoryLocalUser;
   volatile Nv041Typedef Nv03VideoLutCursorPal;
   volatile Nv042Typedef Nv04ContextSurfaces2d;
   volatile Nv043Typedef Nv03ContextRop;
   volatile Nv044Typedef Nv04ContextPattern;
   volatile Nv045Typedef Nv03VideoLutCursorNtsc;
   volatile Nv046Typedef Nv04VideoLutCursorDac;
   volatile Nv047Typedef Nv04VideoOverlay;
   volatile Nv048Typedef Nv03Dx3TexturedTriangle;
   volatile Nv049Typedef NV05VideoLutCursorDac;
   volatile Nv04aTypedef Nv04GdiRectangleText;
   volatile Nv04bTypedef Nv03GdiRectangleText;
   unsigned long NV04C_TYPEDEF;
   volatile Nv04dTypedef Nv03ExternalVideoDecoder;
   volatile Nv04eTypedef Nv03ExternalVideoDecompressor;
   volatile Nv04fTypedef Nv01ExternalParallelBus;
   volatile Nv050Typedef Nv03ExternalMonitorBus;
   volatile Nv051Typedef Nv04ExternalSerialBus;
   volatile Nv052Typedef Nv04ContextSurfaceSwizzled;
   volatile Nv053Typedef Nv04ContextSurfaces3d;
   volatile Nv054Typedef Nv04Dx5TexturedTriangle;
   volatile Nv055Typedef Nv04Dx6MultiTextureTriangle;
   unsigned long Nv12CelsiusPrimitive;
   volatile Nv057Typedef Nv04ContextColorKey;
   volatile Nv058Typedef Nv03ContextSurface2dDestination;
   volatile Nv059Typedef Nv03ContextSurface2dSource;
   volatile Nv05aTypedef Nv03ContextSurface3dColor;
   volatile Nv05bTypedef Nv03ContextSurface3dDepth;
   volatile Nv05cTypedef Nv04RenderSolidLin;
   volatile Nv05dTypedef Nv04RenderSolidTriangle;
   volatile Nv05eTypedef Nv04RenderSolidRectangle;
   volatile Nv05fTypedef Nv04ImageBlit;
   volatile Nv060Typedef Nv04IndexedImageFromCpu;
   volatile Nv061Typedef Nv04ImageFromCpu;
   volatile Nv062Typedef Nv10ContextSurfaces2d;
   volatile Nv063Typedef Nv05ScaledImageFromMemory;
   volatile Nv064Typedef Nv05IndexedImageFromCpu;
   volatile Nv065Typedef Nv05ImageFromCpu;
   volatile _Nv066Typedef Nv05StretchedImageFromCpu;
   volatile Nv067Typedef Nv10VideoLutCursorDac;
   volatile Nv06fTypedef Nv04HeapOwner;
   unsigned long NV070_TYPEDEF;
   unsigned long NV071_TYPEDEF;
   volatile Nv072Typedef Nv04ContextBeta;
   unsigned long NV073_TYPEDEF;
   unsigned long NV074_TYPEDEF;
   unsigned long NV075_TYPEDEF;
   volatile Nv076Typedef Nv04StretchedImageFromCpu;
   volatile Nv077Typedef Nv04ScaledImageFromMemory;
   unsigned long NV078_TYPEDEF;
   unsigned long NV079_TYPEDEF;
   volatile Nv07aTypedef Nv10VideoOverlay;
   volatile Nv07bTypedef Nv10TextureFromCpu;
   volatile Nv07cTypedef Nv12VideoLutCursorDac;
   unsigned long NV07D_TYPEDEF;
   unsigned long NV07E_TYPEDEF;
   unsigned long NV07F_TYPEDEF;
   volatile Nv080Typedef Nv01Device0;
   volatile Nv081Typedef Nv01Device1;
   volatile Nv082Typedef Nv01Device2;
   volatile Nv083Typedef Nv01Device3;
   volatile Nv084Typedef Nv01Device4;
   volatile Nv085Typedef Nv01Device5;
   volatile Nv086Typedef Nv01Device6;
   volatile Nv087Typedef Nv01Device7;
   volatile Nv088Typedef Nv10DvdSubpicture;
   volatile Nv089Typedef Nv10ScaledImageFromMemory;
   volatile Nv093Typedef Nv10ContextSurfaces3d;
   volatile Nv094Typedef Nv10Dx5TexturedTriangle;
   volatile Nv095Typedef Nv10Dx6MultiTextureTriangle;
   unsigned long NVFF0_TYPEDEF;
   unsigned long NVFF1_TYPEDEF;
   unsigned long NVFF2_TYPEDEF;
   unsigned long NVFF3_TYPEDEF;
   unsigned long NVFF4_TYPEDEF;
   volatile Nvff5Typedef NvContextErrorToMemory;
   volatile Nvff6Typedef NvVideoColorKey;
   volatile Nvff7Typedef NvVideoScaler;
   volatile Nvff8Typedef NvVideoFromMemory;
   volatile Nvff9Typedef NvVideoColormap;
   volatile NvffaTypedef NvVideoSink;
   volatile NvffbTypedef NvPatchcordVideo;
   volatile NvffcTypedef NvContextDmaInMemory;
   volatile NvffdTypedef NvContextDmaToMemory;
   volatile NvffeTypedef NvContextDmaFromMemory;
   volatile NvfffTypedef NvClass;
   };
} Nv03SubchannelPio;

typedef struct Nv20KelvinPrimitive
{
   unsigned long ctx_Switch;
   unsigned long Reserved0004[63];
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long SetWarningEnable;
   unsigned long GetState;
   unsigned long WaitForIdle;
   unsigned long Reserved0114[3];
   unsigned long SetFlipRead;
   unsigned long SetFlipWrite;
   unsigned long SetFlipModulo;
   unsigned long FlipIncrementWrite;
   unsigned long FlipStall;
   unsigned long Reserved0134[3];
   unsigned long PmTrigger;
   unsigned long Reserved0144[15];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaA;
   unsigned long SetContextDmaB;
   unsigned long Reserved018c[1];
   unsigned long SetContextDmaState;
   unsigned long SetContextDmaColor;
   unsigned long SetContextDmaZeta;
   unsigned long SetContextDmaVertexA;
   unsigned long SetContextDmaVertexB;
   unsigned long SetContextDmaSemaphore;
   unsigned long SetContextDmaReport;
   unsigned long Reserved01ac[21];
   unsigned long SetSurfaceClipHorizontal;
   unsigned long SetSurfaceClipVertical;
   unsigned long SetSurfaceFormat;
   unsigned long SetSurfacePitch;
   unsigned long SetSurfaceColorOffset;
   unsigned long SetSurfaceZetaOffset;
   unsigned long Reserved0218[18];
   unsigned long SetCombinerAlphaICW[8];
   unsigned long Reserved0280[2];
   unsigned long SetCombinerSpecularFogCW0;
   unsigned long SetCombinerSpecularFogCW1;
   unsigned long SetControl0;
   unsigned long SetLightControl;
   unsigned long SetColorMaterial;
   unsigned long SetFogMode;
   unsigned long SetFogGenMode;
   unsigned long SetFogEnable;
   unsigned long SetFogColor;
   unsigned long Reserved02ac[2];
   unsigned long SetWindowClipType;
   unsigned long Reserved02b8[2];
   unsigned long SetWindowClipHorizontal[8];
   unsigned long SetWindowClipVertical[8];
   unsigned long SetAlphaTestEnable;
   unsigned long SetBlendEnable;
   unsigned long SetCullFaceEnable;
   unsigned long SetDepthTestEnable;
   unsigned long SetDitherEnable;
   unsigned long SetLightingEnable;
   unsigned long SetPointParamsEnable;
   unsigned long SetPointSmoothEnable;
   unsigned long SetLineSmoothEnable;
   unsigned long SetPolySmoothEnable;
   unsigned long SetSkinMode;
   unsigned long SetStencilTestEnable;
   unsigned long SetPolyOffsetPointEnable;
   unsigned long SetPolyOffsetLineEnable;
   unsigned long SetPolyOffsetFillEnable;
   unsigned long SetAlphaFunc;
   unsigned long SetAlphaRef;
   unsigned long SetBlendFuncSfactor;
   unsigned long SetBlendFuncDfactor;
   unsigned long SetBlendColor;
   unsigned long SetBlendEquation;
   unsigned long SetDepthFunc;
   unsigned long SetColorMask;
   unsigned long SetDepthMask;
   unsigned long SetStencilMask;
   unsigned long SetStencilFunc;
   unsigned long SetStencilFuncRef;
   unsigned long SetStencilFuncMask;
   unsigned long SetStencilOpFail;
   unsigned long SetStencilOpZfail;
   unsigned long SetStencilOpZpass;
   unsigned long SetShadeMode;
   unsigned long SetLineWidth;
   float SetPolygonOffsetScaleFactor;
   float SetPolygonOffsetBias;
   unsigned long SetFrontPolygonMode;
   unsigned long SetBackPolygonMode;
   float SetClipMin;
   float SetClipMax;
   unsigned long SetCullFace;
   unsigned long SetFrontFace;
   unsigned long SetNormalizationEnable;
   float SetMaterialEmission[3];
   float SetMaterialAlpha;
   unsigned long SetSpecularEnable;
   unsigned long SetLightEnableMask;
   Nv20KelvinPrimitive::__unnamed SetTexgen[4];
   unsigned long Reserved0400[8];
   unsigned long SetTextureMatrixEnable[4];
   unsigned long Reserved0430[3];
   unsigned long SetPointSize;
   float SetProjectionMatrix[16];
   float SetModelViewMatrix0[16];
   float SetModelViewMatrix1[16];
   float SetModelViewMatrix2[16];
   float SetModelViewMatrix3[16];
   float SetInverseModelViewMatrix0[16];
   float SetInverseModelViewMatrix1[16];
   float SetInverseModelViewMatrix2[16];
   float SetInverseModelViewMatrix3[16];
   float SetCompositeMatrix[16];
   float SetTextureMatrix0[16];
   float SetTextureMatrix1[16];
   float SetTextureMatrix2[16];
   float SetTextureMatrix3[16];
   unsigned long Reserved07c0[32];
   Nv20KelvinPrimitive::__unnamed SetTexgenPlane[4];
   unsigned long Reserved0940[32];
   float SetFogParams[3];
   unsigned long SetTexgenViewModel;
   float SetFogPlane[4];
   float SetSpecularParams[6];
   unsigned long SetSwathWidth;
   unsigned long SetFlatShadeOp;
   unsigned long Reserved0a00[4];
   float SetSceneAmbientColor[3];
   unsigned long Reserved0a1c[1];
   float SetViewportOffset[4];
   float SetPointParams[8];
   float SetEyePosition[4];
   unsigned long SetCombinerFactor0[8];
   unsigned long SetCombinerFactor1[8];
   unsigned long SetCombinerAlphaOCW[8];
   unsigned long SetCombinerColorICW[8];
   unsigned long SetColorKeyColor[4];
   float SetViewportScale[4];
   unsigned long SetTransformProgram[32];
   float SetTransformConstant[32];
   Nv20KelvinPrimitive::__unnamed SetBackLight[8];
   unsigned long Reserved0e00[128];
   Nv20KelvinPrimitive::__unnamed SetLight[8];
   unsigned long Reserved1400[31];
   unsigned long SetStippleControl;
   unsigned long SetStipplePattern[32];
   float SetVertex3f[3];
   unsigned long Reserved150c[3];
   float SetVertex4f[4];
   long SetVertex4s[2];
   float SetNormal3f[3];
   unsigned long Reserved153c[1];
   long SetNormal3s[2];
   unsigned long Reserved1548[2];
   float SetDiffuseColor4f[4];
   float SetDiffuseColor3f[3];
   unsigned long SetDiffuseColor4ub;
   float SetSpecularColor4f[4];
   float SetSpecularColor3f[3];
   unsigned long SetSpecularColor4ub;
   float SetTexcoord0_2f[2];
   long SetTexcoord0_2s;
   unsigned long Reserved159c[1];
   float SetTexcoord0_4f[4];
   long SetTexcoord0_4s[2];
   float SetTexcoord1_2f[2];
   long SetTexcoord1_2s;
   unsigned long Reserved15c4[1];
   float SetTexcoord1_4f[4];
   long SetTexcoord1_4s[2];
   float SetTexcoord2_2f[2];
   long SetTexcoord2_2s;
   unsigned long Reserved15ec[1];
   float SetTexcoord2_4f[4];
   long SetTexcoord2_4s[2];
   float SetTexcoord3_2f[2];
   long SetTexcoord3_2s;
   unsigned long Reserved1614[3];
   float SetTexcoord3_4f[4];
   long SetTexcoord3_4s[2];
   unsigned long Reserved1638[24];
   float SetFog1f;
   float SetWeight1f;
   float SetWeight2f[2];
   unsigned long Reserved16a8[2];
   float SetWeight3f[3];
   unsigned long SetEdgeFlag;
   float SetWeight4f[4];
   float SetTransformFixedConst3[4];
   float SetTransformFixedConst0[4];
   float SetTransformFixedConst1[4];
   float SetTransformFixedConst2[4];
   unsigned long InvalidateVertexCacheFile;
   unsigned long InvalidateVertexFile;
   unsigned long TlNop;
   unsigned long TlSync;
   unsigned long SetVertexDataArrayOffset[16];
   unsigned long SetVertexDataArrayFormat[16];
   float SetBackSceneAmbientColor[3];
   float SetBackMaterialAlpha;
   float SetBackMaterialEmission[3];
   unsigned long SetLogicOpEnable;
   unsigned long SetLogicOp;
   unsigned long SetTwoSideLightEn;
   unsigned long ClearReportValue;
   unsigned long SetZpassPixelCountEnable;
   unsigned long GetReport;
   float SetTLConstZero[3];
   float SetEyeDirection[3];
   float SetLinearFogConst[3];
   unsigned long SetShaderClipPlaneMode;
   unsigned long SetBeginEnd;
   unsigned long ArrayElement16;
   unsigned long Reserved1804[1];
   unsigned long ArrayElement32;
   unsigned long Reserved180c[1];
   unsigned long DrawArrays;
   unsigned long Reserved1814[1];
   unsigned long InlineArray;
   float SetEyeVector[3];
   unsigned long InlineVertexReuse;
   unsigned long Reserved182c[21];
   Nv20KelvinPrimitive::__unnamed SetVertexData2f[16];
   long SetVertexData2s[16];
   long SetVertexData4ub[16];
   Nv20KelvinPrimitive::__unnamed SetVertexData4s[16];
   Nv20KelvinPrimitive::__unnamed SetVertexData4f[16];
   Nv20KelvinPrimitive::__unnamed SetTexture[4];
   unsigned long Reserved1c00[89];
   unsigned long ParkAttribute;
   unsigned long UnparkAttribute;
   unsigned long SetSemaphoreOffset;
   unsigned long BackEndWriteSemaphoreRelease;
   unsigned long TextureReadSemaphoreRelease;
   unsigned long SetZMinMaxControl;
   unsigned long SetAntiAliasingControl;
   unsigned long SetCompressZBufferEn;
   unsigned long SetOccludeZStencilEn;
   unsigned long Reserved1d88[1];
   unsigned long SetZStencilClearValue;
   unsigned long SetColorClearValue;
   unsigned long ClearSurface;
   unsigned long SetClearRectHorizontal;
   unsigned long SetClearRectVertical;
   unsigned long Reserved1da0[16];
   unsigned long SetBeginPatch0;
   unsigned long SetBeginPatch1;
   unsigned long SetBeginPatch2;
   unsigned long SetBeginPatch3;
   unsigned long SetEndPatch;
   unsigned long SetBeginEndSwatch;
   unsigned long SetBeginEndCurve;
   unsigned long Reserved1dfc[1];
   float SetCurveCoefficients[4];
   unsigned long SetBeginTransition0;
   unsigned long SetBeginTransition1;
   unsigned long SetBeginTransition2;
   unsigned long SetEndTransition;
   unsigned long SetSpecularFogFactor[2];
   float SetBackSpecularParams[6];
   unsigned long SetCombinerColorOCW[8];
   unsigned long SetCombinerControl;
   unsigned long Reserved1e64[1];
   float SetShadowZSlopeThreshold;
   unsigned long SetShadowDepthFunc;
   unsigned long SetShaderStageProgram;
   unsigned long SetDotRGBMapping;
   unsigned long SetShaderOtherStageInput;
   unsigned long Reserved1e7c[1];
   float SetTransformData[4];
   unsigned long LaunchTransformProgram;
   unsigned long SetTransformExecutionMode;
   unsigned long SetTransformProgramCxtWriteEn;
   unsigned long SetTransformProgramLoad;
   unsigned long SetTransformProgramStart;
   unsigned long SetTransformConstantLoad;
   unsigned long Reserved1ea8[70];
   unsigned long DebugInit[10];
   unsigned long Reserved1fe8[6];
} Nv20KelvinPrimitive;

typedef struct Nv20KelvinPrimitive::__unnamed
{
   unsigned long S;
   unsigned long T;
   unsigned long R;
   unsigned long Q;
} Nv20KelvinPrimitive::__unnamed;

typedef struct HDESK__
{
   int unused;
} HDESK__;

typedef struct _IMAGE_THUNK_DATA64
{
   UNNAMED_TAG_4FB0845 u1;
} IMAGE_THUNK_DATA64;

typedef struct APU_AP_CREATE
{
   unsigned long pObjectDmaBuffer;
   unsigned long pObjectNotifiesBuffer;
   unsigned long pObjectGlobalNotifiesBuffer;
   APU_AP_FLAGS flags;
   unsigned long pioBase;
   unsigned long limitFifo;
   unsigned long limitBandwidth;
   unsigned long limitBlockClock;
   unsigned long overhead;
   unsigned long uVoiceCount;
   unsigned long uVoice3dCount;
   unsigned long uHRTFCount;
   unsigned long uSubmixCount;
   unsigned long uSegInCount;
   unsigned long uSGEInCount;
   unsigned long uSGEOutCount;
} APU_AP_CREATE;

typedef struct IDirectSound
{
   union {
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) public: unsigned long __stdcall IDirectSound::Release(void);
   (type???) GetCaps;
   (type???) public: long __stdcall IDirectSound::CreateSoundBuffer(struct _DSBUFFERDESC const *,struct IDirectSoundBuffer * *,struct IUnknown *);
   (type???) CreateSoundStream;
   (type???) GetSpeakerConfig;
   (type???) SetCooperativeLevel;
   (type???) Compact;
   (type???) DownloadEffectsImage;
   (type???) GetEffectData;
   (type???) SetEffectData;
   (type???) CommitEffectData;
   (type???) EnableHeadphones;
   (type???) SetMixBinHeadroom;
   (type???) SetAllParameters;
   (type???) SetDistanceFactor;
   (type???) SetDopplerFactor;
   (type???) SetOrientation;
   (type???) SetPosition;
   (type???) SetRolloffFactor;
   (type???) SetVelocity;
   (type???) SetI3DL2Listener;
   (type???) CommitDeferredSettings;
   (type???) GetTime;
   };
} IDirectSound;

typedef struct NV07A_ALLOCATION_PARAMETERS
{
   unsigned long version;
   NvP64 pInfo;
   unsigned long logicalHeadId;
} NV07A_ALLOCATION_PARAMETERS;

typedef struct POWER_STATE_HANDLER
{
   int Type;
   unsigned char RtcWake;
   unsigned char Spare[3];
   void * Handler;
   void * Context;
} POWER_STATE_HANDLER;

typedef struct _FILE_STREAM_INFORMATION
{
   unsigned long NextEntryOffset;
   unsigned long StreamNameLength;
   _LARGE_INTEGER StreamSize;
   _LARGE_INTEGER StreamAllocationSize;
   char StreamName[1];
} FILE_STREAM_INFORMATION;

typedef struct _D3DADAPTER_IDENTIFIER8
{
   char Driver[512];
   char Description[512];
   _LARGE_INTEGER DriverVersion;
   unsigned long VendorId;
   unsigned long DeviceId;
   unsigned long SubSysId;
   unsigned long Revision;
   _GUID DeviceIdentifier;
   unsigned long WHQLLevel;
} D3DADAPTER_IDENTIFIER8;

typedef struct _CM_VIDEO_DEVICE_DATA
{
   short Version;
   short Revision;
   unsigned long VideoClock;
} CM_VIDEO_DEVICE_DATA;

typedef struct Nv08ATypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextColorKey;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[86];
   unsigned long SetColorConversion;
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long Point;
   unsigned long SizeOut;
   unsigned long SizeIn;
   unsigned long Reserved02[60];
   Nv08ATypedef::__unnamed Color[896];
} Nv08ATypedef;

typedef struct Nv08ATypedef::__unnamed
{
   unsigned long a;
   unsigned long b;
} Nv08ATypedef::__unnamed;

typedef struct _IO_COUNTERS
{
   __int64 ReadOperationCount;
   __int64 WriteOperationCount;
   __int64 OtherOperationCount;
   __int64 ReadTransferCount;
   __int64 WriteTransferCount;
   __int64 OtherTransferCount;
} IO_COUNTERS;

typedef struct _TIME_ZONE_INFORMATION
{
   long Bias;
   short StandardName[32];
   _SYSTEMTIME StandardDate;
   long StandardBias;
   short DaylightName[32];
   _SYSTEMTIME DaylightDate;
   long DaylightBias;
} TIME_ZONE_INFORMATION;

typedef struct _OBJECT_TYPE_LIST
{
   short Level;
   short Sbz;
   _GUID * ObjectType;
} OBJECT_TYPE_LIST;

typedef struct _EXCEPTION_RECORD64
{
   long ExceptionCode;
   unsigned long ExceptionFlags;
   __int64 ExceptionRecord;
   __int64 ExceptionAddress;
   unsigned long NumberParameters;
   unsigned long __unusedAlignment;
   __int64 ExceptionInformation[15];
} EXCEPTION_RECORD64;

typedef struct _SID
{
   unsigned char Revision;
   unsigned char SubAuthorityCount;
   _SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
   unsigned long SubAuthority[1];
} SID;

typedef struct _FILE_FS_DEVICE_INFORMATION
{
   unsigned long DeviceType;
   unsigned long Characteristics;
} FILE_FS_DEVICE_INFORMATION;

typedef struct _IMAGE_IMPORT_DESCRIPTOR
{
   union {
   unsigned long Characteristics;
   unsigned long OriginalFirstThunk;
   };
   unsigned long TimeDateStamp;
   unsigned long ForwarderChain;
   unsigned long Name;
   unsigned long FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;

typedef struct _SYSTEM_FILECACHE_INFORMATION
{
   unsigned long CurrentSize;
   unsigned long PeakSize;
   unsigned long PageFaultCount;
   unsigned long MinimumWorkingSet;
   unsigned long MaximumWorkingSet;
   unsigned long CurrentSizeIncludingTransitionInPages;
   unsigned long PeakSizeIncludingTransitionInPages;
   unsigned long spare[2];
} SYSTEM_FILECACHE_INFORMATION;

typedef struct _MUTANT_BASIC_INFORMATION
{
   long CurrentCount;
   unsigned char OwnedByCaller;
   unsigned char AbandonedState;
} MUTANT_BASIC_INFORMATION;

typedef struct SYSTEM_POWER_CAPABILITIES
{
   unsigned char PowerButtonPresent;
   unsigned char SleepButtonPresent;
   unsigned char LidPresent;
   unsigned char SystemS1;
   unsigned char SystemS2;
   unsigned char SystemS3;
   unsigned char SystemS4;
   unsigned char SystemS5;
   unsigned char HiberFilePresent;
   unsigned char FullWake;
   unsigned char VideoDimPresent;
   unsigned char ApmPresent;
   unsigned char UpsPresent;
   unsigned char ThermalControl;
   unsigned char ProcessorThrottle;
   unsigned char ProcessorMinThrottle;
   unsigned char ProcessorThrottleScale;
   unsigned char spare2[4];
   unsigned char DiskSpinDown;
   unsigned char spare3[8];
   unsigned char SystemBatteriesPresent;
   unsigned char BatteriesAreShortTerm;
   BATTERY_REPORTING_SCALE BatteryScale[3];
   int AcOnLineWake;
   int SoftLidWake;
   int RtcWake;
   int MinDeviceWakeState;
   int DefaultLowLatencyWake;
} SYSTEM_POWER_CAPABILITIES;

typedef struct _SYSTEM_DPC_BEHAVIOR_INFORMATION
{
   unsigned long Spare;
   unsigned long DpcQueueDepth;
   unsigned long MinimumDpcRate;
   unsigned long AdjustDpcThreshold;
   unsigned long IdealDpcRate;
} SYSTEM_DPC_BEHAVIOR_INFORMATION;

typedef union _IO_STACK_LOCATION::__unnamed
{
   union {
   _IO_STACK_LOCATION::__unnamed::__unnamed Create;
   _IO_STACK_LOCATION::__unnamed::__unnamed Read;
   _IO_STACK_LOCATION::__unnamed::__unnamed Write;
   _IO_STACK_LOCATION::__unnamed::__unnamed QueryDirectory;
   _IO_STACK_LOCATION::__unnamed::__unnamed QueryFile;
   _IO_STACK_LOCATION::__unnamed::__unnamed SetFile;
   _IO_STACK_LOCATION::__unnamed::__unnamed QueryVolume;
   _IO_STACK_LOCATION::__unnamed::__unnamed SetVolume;
   _IO_STACK_LOCATION::__unnamed::__unnamed FileSystemControl;
   _IO_STACK_LOCATION::__unnamed::__unnamed DeviceIoControl;
   _IO_STACK_LOCATION::__unnamed::__unnamed Scsi;
   _IO_STACK_LOCATION::__unnamed::__unnamed IdexReadWrite;
   _IO_STACK_LOCATION::__unnamed::__unnamed Others;
   };
} IO_STACK_LOCATION::__unnamed;

typedef struct _IO_STACK_LOCATION::__unnamed::__unnamed
{
   unsigned long DesiredAccess;
   unsigned long Options;
   short FileAttributes;
   short ShareAccess;
   _STRING * RemainingName;
} IO_STACK_LOCATION::__unnamed::__unnamed;

typedef struct _FILE_FS_ATTRIBUTE_INFORMATION
{
   unsigned long FileSystemAttributes;
   long MaximumComponentNameLength;
   unsigned long FileSystemNameLength;
   char FileSystemName[1];
} FILE_FS_ATTRIBUTE_INFORMATION;

typedef union _PORT_MESSAGE::__unnamed
{
   union {
   _PORT_MESSAGE::__unnamed::__unnamed s1;
   unsigned long Length;
   };
} PORT_MESSAGE::__unnamed;

typedef struct _PORT_MESSAGE::__unnamed::__unnamed
{
   short DataLength;
   short TotalLength;
} PORT_MESSAGE::__unnamed::__unnamed;

typedef struct Nv06bTypedef
{
   unsigned long Reserved00[1984];
} Nv06bTypedef;

typedef struct _TOKEN_PRIVILEGES
{
   unsigned long PrivilegeCount;
   _LUID_AND_ATTRIBUTES Privileges[1];
} TOKEN_PRIVILEGES;

typedef struct tagSTATSTG
{
   short * pwcsName;
   unsigned long type;
   _ULARGE_INTEGER cbSize;
   _FILETIME mtime;
   _FILETIME ctime;
   _FILETIME atime;
   unsigned long grfMode;
   unsigned long grfLocksSupported;
   _GUID clsid;
   unsigned long grfStateBits;
   unsigned long reserved;
} tagSTATSTG;

typedef struct AUDIO_FREE_MEMORY
{
   unsigned long pLinearAddress;
   unsigned long uRef;
} AUDIO_FREE_MEMORY;

typedef struct _D3DRECTPATCH_INFO
{
   int StartVertexOffsetWidth;
   int StartVertexOffsetHeight;
   int Width;
   int Height;
   int Stride;
   int Basis;
   int Order;
} D3DRECTPATCH_INFO;

typedef struct _ERWLOCK
{
   long LockCount;
   unsigned long WritersWaitingCount;
   unsigned long ReadersWaitingCount;
   unsigned long ReadersEntryCount;
   _KEVENT WriterEvent;
   _KSEMAPHORE ReaderSemaphore;
} ERWLOCK;

typedef struct _KEY_FULL_INFORMATION
{
   _LARGE_INTEGER LastWriteTime;
   unsigned long TitleIndex;
   unsigned long ClassOffset;
   unsigned long ClassLength;
   unsigned long SubKeys;
   unsigned long MaxNameLen;
   unsigned long MaxClassLen;
   unsigned long Values;
   unsigned long MaxValueNameLen;
   unsigned long MaxValueDataLen;
   short Class[1];
} KEY_FULL_INFORMATION;

typedef struct _RTL_HEAP_USAGE
{
   unsigned long Length;
   unsigned long BytesAllocated;
   unsigned long BytesCommitted;
   unsigned long BytesReserved;
   unsigned long BytesReservedMaximum;
   _RTL_HEAP_USAGE_ENTRY * Entries;
   _RTL_HEAP_USAGE_ENTRY * AddedEntries;
   _RTL_HEAP_USAGE_ENTRY * RemovedEntries;
   unsigned long Reserved[8];
} RTL_HEAP_USAGE;

typedef struct UNNAMED_TAG_5970C1B
{
   unsigned long size;
   unsigned long monochrome[127];
} UNNAMED_TAG_5970C1B;

typedef struct _D3DXBONECOMBINATION
{
   unsigned long AttribId;
   unsigned long FaceStart;
   unsigned long FaceCount;
   unsigned long VertexStart;
   unsigned long VertexCount;
   unsigned long * BoneId;
} D3DXBONECOMBINATION;

typedef struct _PORT_DATA_INFORMATION
{
   unsigned long CountDataEntries;
   _PORT_DATA_ENTRY DataEntries[1];
} PORT_DATA_INFORMATION;

typedef struct _CM_MONITOR_DEVICE_DATA
{
   short Version;
   short Revision;
   short HorizontalScreenSize;
   short VerticalScreenSize;
   short HorizontalResolution;
   short VerticalResolution;
   short HorizontalDisplayTimeLow;
   short HorizontalDisplayTime;
   short HorizontalDisplayTimeHigh;
   short HorizontalBackPorchLow;
   short HorizontalBackPorch;
   short HorizontalBackPorchHigh;
   short HorizontalFrontPorchLow;
   short HorizontalFrontPorch;
   short HorizontalFrontPorchHigh;
   short HorizontalSyncLow;
   short HorizontalSync;
   short HorizontalSyncHigh;
   short VerticalBackPorchLow;
   short VerticalBackPorch;
   short VerticalBackPorchHigh;
   short VerticalFrontPorchLow;
   short VerticalFrontPorch;
   short VerticalFrontPorchHigh;
   short VerticalSyncLow;
   short VerticalSync;
   short VerticalSyncHigh;
} CM_MONITOR_DEVICE_DATA;

typedef struct _LDT_INFORMATION
{
   unsigned long Start;
   unsigned long Length;
   _LDT_ENTRY LdtEntries[1];
} LDT_INFORMATION;

typedef struct _SECURITY_QUALITY_OF_SERVICE
{
   unsigned long Length;
   int ImpersonationLevel;
   unsigned char ContextTrackingMode;
   unsigned char EffectiveOnly;
} SECURITY_QUALITY_OF_SERVICE;

typedef struct _CURDIR
{
   _UNICODE_STRING DosPath;
   void * Handle;
} CURDIR;

typedef struct HPEN__
{
   int unused;
} HPEN__;

typedef struct Nv04ControlDma
{
   unsigned long Ignored00[16];
   unsigned long Put;
   unsigned long Get;
   unsigned long Ignored01[2];
   unsigned long StallNotifier;
   unsigned long StallChannel;
   unsigned long Ignored02[2026];
} Nv04ControlDma;

typedef struct _RANGE_LIST_ITERATOR
{
   _LIST_ENTRY * RangeListHead;
   _LIST_ENTRY * MergedHead;
   void * Current;
   unsigned long Stamp;
} RANGE_LIST_ITERATOR;

typedef struct _PROCESS_DEVICEMAP_INFORMATION
{
   union {
   _PROCESS_DEVICEMAP_INFORMATION::__unnamed::__unnamed Set;
   _PROCESS_DEVICEMAP_INFORMATION::__unnamed::__unnamed Query;
   };
} PROCESS_DEVICEMAP_INFORMATION;

typedef struct _PROCESS_DEVICEMAP_INFORMATION::__unnamed::__unnamed
{
   void * DirectoryHandle;
} PROCESS_DEVICEMAP_INFORMATION::__unnamed::__unnamed;

typedef struct _SYSTEM_MEMORY_INFORMATION
{
   unsigned long InfoSize;
   unsigned long StringStart;
   _SYSTEM_MEMORY_INFO Memory[1];
} SYSTEM_MEMORY_INFORMATION;

typedef struct _CM_PNP_BIOS_DEVICE_NODE
{
   short Size;
   unsigned char Node;
   unsigned long ProductId;
   unsigned char DeviceType[3];
   short DeviceAttributes;
} CM_PNP_BIOS_DEVICE_NODE;

typedef struct _D3DFIELD_STATUS
{
   int Field;
   int VBlankCount;
} D3DFIELD_STATUS;

typedef struct NV07C_ALLOCATION_PARAMETERS
{
   unsigned long version;
   NvP64 pInfo;
   unsigned long logicalHeadId;
} NV07C_ALLOCATION_PARAMETERS;

typedef struct XNADDR
{
   unsigned char bSizeOfStruct;
   unsigned char bFlags;
   unsigned char abEnet[6];
   in_addr ina;
} XNADDR;

typedef struct _KIDTENTRY
{
   short Offset;
   short Selector;
   short Access;
   short ExtendedOffset;
} KIDTENTRY;

typedef union APU_AP_FLAGS
{
   union {
   APU_AP_FLAGS::__unnamed fields;
   unsigned long uValue;
   };
} APU_AP_FLAGS;

typedef struct APU_AP_FLAGS::__unnamed
{
   unsigned long ISO;
} APU_AP_FLAGS::__unnamed;

typedef struct _SECURITY_DESCRIPTOR
{
   unsigned char Revision;
   unsigned char Sbz1;
   short Control;
   void * Owner;
   void * Group;
   _ACL * Sacl;
   _ACL * Dacl;
} SECURITY_DESCRIPTOR;

typedef struct _PS_STATISTICS
{
   unsigned long Length;
   unsigned long ThreadCount;
   unsigned long HandleCount;
} PS_STATISTICS;

typedef struct HHOOK__
{
   int unused;
} HHOOK__;

typedef struct _KEY_WRITE_TIME_INFORMATION
{
   _LARGE_INTEGER LastWriteTime;
} KEY_WRITE_TIME_INFORMATION;

typedef struct D3DK::DISPLAYMODE
{
   unsigned long AvInfo;
   short Width;
   short Height;
   unsigned long DisplayMode;
} D3DK::DISPLAYMODE;

typedef struct D3DK::___D3DCYCLETIMER
{
   __int64 m_CycleStart;
   int m_perfctr;
   union {
   (type???) ___D3DCYCLETIMER;
   (type???) ~___D3DCYCLETIMER;
   (type???) __vecDelDtor;
   };
} D3DK::___D3DCYCLETIMER;

typedef struct D3DK::NV_PATCH_ALLOC_CONTROL
{
   void * context;
   void * pBase;
   void * pAvail;
   void * pAllocatedBase;
   int bytesAlloc;
   int bytesUsed;
   D3DK::NV_PATCH_ALLOC_CACHE * pCache;
} D3DK::NV_PATCH_ALLOC_CONTROL;

typedef struct D3DK::PAGE_ZERO
{
   unsigned long m_PushBufferJump;
} D3DK::PAGE_ZERO;

typedef struct D3DK::_D3DPERF
{
   __int64 m_TSCLastResetVal;
   __int64 m_TSCLastPresentVal;
   D3DK::_D3DWAITINFO m_FrameTimeMin;
   D3DK::_D3DWAITINFO m_FrameTimeMax;
   unsigned long m_BreakCount;
   int m_Breakperfctr;
   unsigned long * m_pPutLocationAtReset;
   unsigned long Padding7;
   __int64 m_PushBufferEndDwordsSkipped;
   unsigned long m_FrameRateIntervalTime;
   unsigned long m_dwDumpFPSInfoMask;
   void * m_pfnDumpFrameRateInfoHandler;
   unsigned long m_DumpWaitCycleTimesThreshold;
   void * m_pfnCycleThresholdHandler;
   int m_SetRenderStateOverridesOnReset;
   unsigned long m_ProfileSamples;
   unsigned long Padding16;
   __int64 m_TSCProfileStartTime;
   short m_ProfileData[105000];
   unsigned long m_ProfileBusyCounts[3];
   D3DK::_D3DOVERRIDERENDERSTATE m_RenderStateOverrides[144];
   D3DK::_D3DWAITINFO m_PerformanceCounters[30];
   unsigned long m_APICounters[235];
   unsigned long m_RenderStateCounters[144];
   unsigned long m_TextureStateCounters[32];
} D3DK::_D3DPERF;

typedef struct D3DK::Stream
{
   unsigned long Stride;
   unsigned long Offset;
   D3DVertexBuffer * pVertexBuffer;
} D3DK::Stream;

typedef struct D3DK::NV_PATCH_STATIC_DATA
{
   int RetessFDtag[2] RetessFDtag[2];
   unsigned long Padding1;
   unsigned long Padding2;
   D3DK::FDMatrix * RetessFDCache[2];
   int RetessFDMRU;
   D3DK::NV_PATCH_ALLOC_CACHE pCache[10];
} D3DK::NV_PATCH_STATIC_DATA;

typedef struct D3DK::_D3DWAITINFO
{
   unsigned long Count;
   unsigned long Padding1;
   __int64 Cycles;
} D3DK::_D3DWAITINFO;

typedef struct D3DK::_D3DPUSHBUFFERINFO
{
   unsigned long PushBufferSize;
   unsigned long PushSegmentSize;
   unsigned long PushSegmentCount;
   unsigned long * pPushBase;
   unsigned long * pPushLimit;
   unsigned long Padding5;
   __int64 PushBufferBytesWritten;
} D3DK::_D3DPUSHBUFFERINFO;

typedef struct D3DK::CPatch
{
   unsigned long m_dwFlags;
   unsigned long m_dwHandle;
   unsigned long m_subpatchcount;
   unsigned long m_dwHeight;
   unsigned long m_dwWidth;
   unsigned long m_dwOrder;
   unsigned long m_dwStride;
   unsigned long m_dwVertexOffset;
   int m_dwTypes[16];
   D3DK::FDMatrix * * m00;
   D3DK::FDMatrix * * m10;
   D3DK::FDMatrix * * m01;
   D3DK::FDMatrix * * m11;
   D3DK::NV_PATCH_FRAC_QUAD_GUARD_INFO * * guardQF;
   D3DK::NV_PATCH_QUAD_INFO * * cachedQuadInfo;
   D3DK::NV_PATCH_FRAC_TRI_GUARD_INFO * * guardTF;
   D3DK::NV_PATCH_INFO m_PatchData;
   union {
   (type???) setStream;
   (type???) Init;
   (type???) UnInit;
   (type???) getCachedData;
   (type???) saveCachedData;
   (type???) freeCached;
   (type???) allocCached;
   (type???) setupStreams;
   (type???) copyDataToScratch;
   (type???) copyDataToScratchTri;
   (type???) convertBsplineToBezier;
   (type???) convertCatmullRomToBezier;
   (type???) setBasis;
   (type???) getBasis;
   (type???) getInfo;
   (type???) setTessMode;
   (type???) setPrimMode;
   (type???) setTessellation;
   (type???) setOriginalTessellation;
   (type???) prepareBuffer;
   (type???) setVertexOffset;
   (type???) setAutoNormal;
   (type???) setAutoUV;
   (type???) setDimension;
   (type???) getWidth;
   (type???) getHeight;
   (type???) setOrder;
   (type???) getOrder;
   (type???) setStride;
   (type???) getStride;
   (type???) setTextureOffsets;
   (type???) getSeg;
   (type???) setCalc;
   (type???) getCalc;
   (type???) setVertexStride;
   };
} D3DK::CPatch;

typedef struct D3DK::CEnum
{
   union {
   (type???) Direct3D;
   (type???) MapUnknownFormat;
   };
} D3DK::CEnum;

typedef struct D3DK::VGATBL
{
   unsigned char columns;
   unsigned char rows;
   unsigned char char_height;
   unsigned char Padding3;
   short RegenLenght;
   D3DK::VGATBL::SEQ seq_regs;
   unsigned char PT_Misc;
   D3DK::VGATBL::CRTC crtc_regs;
   unsigned char PT_ATC[20];
   D3DK::VGATBL::GR gr_regs;
} D3DK::VGATBL;

typedef struct D3DK::VGATBL::GR
{
   unsigned char SetReset;
   unsigned char EnableSetReset;
   unsigned char ColorCmp;
   unsigned char ROP;
   unsigned char ReadMap;
   unsigned char Mode;
   unsigned char Misc;
   unsigned char CDC;
   unsigned char BitMask;
} D3DK::VGATBL::GR;

typedef struct D3DK::VGATBL::CRTC
{
   unsigned char HTotal;
   unsigned char HDispEnd;
   unsigned char HBlankS;
   unsigned char HBlankE;
   unsigned char HSyncS;
   unsigned char HSyncE;
   unsigned char VTotal;
   unsigned char Overflow;
   unsigned char PresetRowScan;
   unsigned char CellHeight;
   unsigned char CursorS;
   unsigned char CursorE;
   unsigned char RegenSHigh;
   unsigned char RegenSLow;
   unsigned char CursorPosHigh;
   unsigned char CursorPosLow;
   unsigned char VSyncS;
   unsigned char VSyncE;
   unsigned char VDispE;
   unsigned char RowOffset;
   unsigned char ULineRow;
   unsigned char VBlankS;
   unsigned char VBlandE;
   unsigned char Mode;
   unsigned char LineCompare;
} D3DK::VGATBL::CRTC;

typedef struct D3DK::VGATBL::SEQ
{
   unsigned char ClockMode;
   unsigned char MapMask;
   unsigned char FontAddr;
   unsigned char MemMode;
} D3DK::VGATBL::SEQ;

typedef struct D3DK::CMiniport::PUSHBUFFERFIXUPINFO
{
   unsigned long * pFixup;
   unsigned char * pStart;
   unsigned long ReturnOffset;
   unsigned long * ReturnAddress;
} D3DK::CMiniport::PUSHBUFFERFIXUPINFO;

typedef struct D3DK::CMiniport::OBJECTINFO
{
   unsigned long Handle;
   short SubChannel;
   short Engine;
   unsigned long ClassNum;
   unsigned long Instance;
   (type???) Init;
} D3DK::CMiniport::OBJECTINFO;

typedef struct D3DK::CMiniport::HW_HASHENTRY
{
   unsigned long ht_ObjectHandle;
   unsigned long ht_Context;
} D3DK::CMiniport::HW_HASHENTRY;

typedef struct D3DK::NV_PATCH_INFO
{
   int evalEnables;
   int swEnables;
   int nAttr;
   int maxAttr;
   int firstAttr;
   int maxOrder;
   int maxSwatch;
   int nSwatchU;
   int nSwatchV;
   int fracSwatchU;
   int fracSwatchV;
   int swatchFlags;
   int flags;
   int flipT;
   int flipU;
   int flipV;
   int flipUV;
   int flipTUV;
   unsigned char * cachedPB;
   unsigned long cachedPBSize;
   unsigned long cachedPBCounter;
   int reverse;
   D3DK::NV_PATCH_INFO::__unnamed tess;
   D3DK::NV_PATCH_INFO::__unnamed originaltess;
   int basis;
   int srcNormal;
   int dstNormal;
   int rational;
   float startu;
   float endu;
   float startv;
   float endv;
   int srcUV[8];
   int dstUV[8];
   D3DK::NV_PATCH_MAP_INFO maps[16];
   int backendType;
   unsigned char * buffer;
   int bufferLength;
   int vertexSize;
   void * context;
   D3DK::NV_PATCH_ALLOC_CACHE * pCache[10];
   int retVal;
   float * normalPatch;
   float * UVPatch;
   float * pSwatchCorner[2] pSwatchCorner[2] pSwatchCorner[16];
   unsigned long Padding45;
   unsigned long Padding46;
   unsigned long Padding47;
   unsigned long Padding48;
   unsigned long Padding49;
   unsigned long Padding50;
   unsigned long Padding51;
   unsigned long Padding52;
   unsigned long Padding53;
   unsigned long Padding54;
   unsigned long Padding55;
   unsigned long Padding56;
   unsigned long Padding57;
   unsigned long Padding58;
   unsigned long Padding59;
   unsigned long Padding60;
   unsigned long Padding61;
   unsigned long Padding62;
   unsigned long Padding63;
   unsigned long Padding64;
   unsigned long Padding65;
   unsigned long Padding66;
   unsigned long Padding67;
   unsigned long Padding68;
   unsigned long Padding69;
   unsigned long Padding70;
   unsigned long Padding71;
   unsigned long Padding72;
   unsigned long Padding73;
   unsigned long Padding74;
   unsigned long Padding75;
   unsigned long Padding76;
   unsigned long Padding77;
   unsigned long Padding78;
   unsigned long Padding79;
   unsigned long Padding80;
   unsigned long Padding81;
   unsigned long Padding82;
   unsigned long Padding83;
   unsigned long Padding84;
   unsigned long Padding85;
   unsigned long Padding86;
   unsigned long Padding87;
   unsigned long Padding88;
   unsigned long Padding89;
   unsigned long Padding90;
   unsigned long Padding91;
   unsigned long Padding92;
   float gridCorner[4] gridCorner[2] gridCorner[2] gridCorner[16];
   unsigned long Padding94;
   unsigned long Padding95;
   unsigned long Padding96;
   unsigned long Padding97;
   unsigned long Padding98;
   unsigned long Padding99;
   unsigned long Padding100;
   unsigned long Padding101;
   unsigned long Padding102;
   unsigned long Padding103;
   unsigned long Padding104;
   unsigned long Padding105;
   unsigned long Padding106;
   unsigned long Padding107;
   unsigned long Padding108;
   unsigned long Padding109;
   unsigned long Padding110;
   unsigned long Padding111;
   unsigned long Padding112;
   unsigned long Padding113;
   unsigned long Padding114;
   unsigned long Padding115;
   unsigned long Padding116;
   unsigned long Padding117;
   unsigned long Padding118;
   unsigned long Padding119;
   unsigned long Padding120;
   unsigned long Padding121;
   unsigned long Padding122;
   unsigned long Padding123;
   unsigned long Padding124;
   unsigned long Padding125;
   unsigned long Padding126;
   unsigned long Padding127;
   unsigned long Padding128;
   unsigned long Padding129;
   unsigned long Padding130;
   unsigned long Padding131;
   unsigned long Padding132;
   unsigned long Padding133;
   unsigned long Padding134;
   unsigned long Padding135;
   unsigned long Padding136;
   unsigned long Padding137;
   unsigned long Padding138;
   unsigned long Padding139;
   unsigned long Padding140;
   unsigned long Padding141;
   unsigned long Padding142;
   unsigned long Padding143;
   unsigned long Padding144;
   unsigned long Padding145;
   unsigned long Padding146;
   unsigned long Padding147;
   unsigned long Padding148;
   unsigned long Padding149;
   unsigned long Padding150;
   unsigned long Padding151;
   unsigned long Padding152;
   unsigned long Padding153;
   unsigned long Padding154;
   unsigned long Padding155;
   unsigned long Padding156;
   unsigned long Padding157;
   unsigned long Padding158;
   unsigned long Padding159;
   unsigned long Padding160;
   unsigned long Padding161;
   unsigned long Padding162;
   unsigned long Padding163;
   unsigned long Padding164;
   unsigned long Padding165;
   unsigned long Padding166;
   unsigned long Padding167;
   unsigned long Padding168;
   unsigned long Padding169;
   unsigned long Padding170;
   unsigned long Padding171;
   unsigned long Padding172;
   unsigned long Padding173;
   unsigned long Padding174;
   unsigned long Padding175;
   unsigned long Padding176;
   unsigned long Padding177;
   unsigned long Padding178;
   unsigned long Padding179;
   unsigned long Padding180;
   unsigned long Padding181;
   unsigned long Padding182;
   unsigned long Padding183;
   unsigned long Padding184;
   unsigned long Padding185;
   unsigned long Padding186;
   unsigned long Padding187;
   unsigned long Padding188;
   unsigned long Padding189;
   unsigned long Padding190;
   unsigned long Padding191;
   unsigned long Padding192;
   unsigned long Padding193;
   unsigned long Padding194;
   unsigned long Padding195;
   unsigned long Padding196;
   unsigned long Padding197;
   unsigned long Padding198;
   unsigned long Padding199;
   unsigned long Padding200;
   unsigned long Padding201;
   unsigned long Padding202;
   unsigned long Padding203;
   unsigned long Padding204;
   unsigned long Padding205;
   unsigned long Padding206;
   unsigned long Padding207;
   unsigned long Padding208;
   unsigned long Padding209;
   unsigned long Padding210;
   unsigned long Padding211;
   unsigned long Padding212;
   unsigned long Padding213;
   unsigned long Padding214;
   unsigned long Padding215;
   unsigned long Padding216;
   unsigned long Padding217;
   unsigned long Padding218;
   unsigned long Padding219;
   unsigned long Padding220;
   unsigned long Padding221;
   unsigned long Padding222;
   unsigned long Padding223;
   unsigned long Padding224;
   unsigned long Padding225;
   unsigned long Padding226;
   unsigned long Padding227;
   unsigned long Padding228;
   unsigned long Padding229;
   unsigned long Padding230;
   unsigned long Padding231;
   unsigned long Padding232;
   unsigned long Padding233;
   unsigned long Padding234;
   unsigned long Padding235;
   unsigned long Padding236;
   unsigned long Padding237;
   unsigned long Padding238;
   unsigned long Padding239;
   unsigned long Padding240;
   unsigned long Padding241;
   unsigned long Padding242;
   unsigned long Padding243;
   unsigned long Padding244;
   unsigned long Padding245;
   unsigned long Padding246;
   unsigned long Padding247;
   unsigned long Padding248;
   unsigned long Padding249;
   unsigned long Padding250;
   unsigned long Padding251;
   unsigned long Padding252;
   unsigned long Padding253;
   unsigned long Padding254;
   unsigned long Padding255;
   unsigned long Padding256;
   unsigned long Padding257;
   unsigned long Padding258;
   unsigned long Padding259;
   unsigned long Padding260;
   unsigned long Padding261;
   unsigned long Padding262;
   unsigned long Padding263;
   unsigned long Padding264;
   unsigned long Padding265;
   unsigned long Padding266;
   unsigned long Padding267;
   unsigned long Padding268;
   unsigned long Padding269;
   unsigned long Padding270;
   unsigned long Padding271;
   unsigned long Padding272;
   unsigned long Padding273;
   unsigned long Padding274;
   unsigned long Padding275;
   unsigned long Padding276;
   unsigned long Padding277;
   unsigned long Padding278;
   unsigned long Padding279;
   unsigned long Padding280;
   unsigned long Padding281;
   unsigned long Padding282;
   unsigned long Padding283;
   unsigned long Padding284;
   unsigned long Padding285;
   unsigned long Padding286;
   unsigned long Padding287;
   unsigned long Padding288;
   unsigned long Padding289;
   unsigned long Padding290;
   unsigned long Padding291;
   unsigned long Padding292;
   unsigned long Padding293;
   unsigned long Padding294;
   unsigned long Padding295;
   unsigned long Padding296;
   unsigned long Padding297;
   unsigned long Padding298;
   unsigned long Padding299;
   unsigned long Padding300;
   unsigned long Padding301;
   unsigned long Padding302;
   unsigned long Padding303;
   unsigned long Padding304;
   unsigned long Padding305;
   unsigned long Padding306;
   unsigned long Padding307;
   unsigned long Padding308;
   unsigned long Padding309;
   unsigned long Padding310;
   unsigned long Padding311;
   unsigned long Padding312;
   unsigned long Padding313;
   unsigned long Padding314;
   unsigned long Padding315;
   unsigned long Padding316;
   unsigned long Padding317;
   unsigned long Padding318;
   unsigned long Padding319;
   unsigned long Padding320;
   unsigned long Padding321;
   unsigned long Padding322;
   unsigned long Padding323;
   unsigned long Padding324;
   unsigned long Padding325;
   unsigned long Padding326;
   unsigned long Padding327;
   unsigned long Padding328;
   unsigned long Padding329;
   unsigned long Padding330;
   unsigned long Padding331;
   unsigned long Padding332;
   unsigned long Padding333;
   int setGridCorner;
   D3DK::NV_PATCH_CURVE_INFO tempCurve;
   D3DK::FDMatrix tempMatrix;
   D3DK::FDMatrix reparam;
   D3DK::FDMatrix * reduceTri[16];
   int bytesGuardCurve;
   int bytesGuardCurveAllAttr;
   D3DK::NV_PATCH_QUAD_INFO * quadInfo;
   void * pScratchBase;
   D3DK::FDMatrix * ppMatrixSetSS0[16];
   D3DK::NV_PATCH_CURVE_INFO * tempVBegin[16];
   D3DK::NV_PATCH_CURVE_INFO * tempVEnd[16];
   D3DK::NV_PATCH_CURVE_INFO * guardSetUInnerFrac[16];
   D3DK::NV_PATCH_CURVE_INFO * guardSetVInnerFrac[16];
   D3DK::NV_PATCH_CURVE_INFO * ppGuardSetUInnerFrac1[16] ppGuardSetUInnerFrac1[1];
   D3DK::NV_PATCH_CURVE_INFO * ppGuardSetVInnerFrac1[16] ppGuardSetVInnerFrac1[1];
   D3DK::NV_PATCH_CURVE_INFO * ppGuardSetUInnerFrac[16];
   D3DK::NV_PATCH_CURVE_INFO * ppGuardSetVInnerFrac[16];
} D3DK::NV_PATCH_INFO;

typedef struct D3DK::NV_PATCH_FRAC_TRI_GUARD_INFO
{
   D3DK::NV_PATCH_CURVE_INFO guard[2] guard[3];
   D3DK::NV_PATCH_CURVE_INFO guardCenter[3];
   float mid[4] mid[3];
   unsigned long Padding3;
   unsigned long Padding4;
   unsigned long Padding5;
   unsigned long Padding6;
   unsigned long Padding7;
   unsigned long Padding8;
   unsigned long Padding9;
   unsigned long Padding10;
   unsigned long Padding11;
   float center[4];
} D3DK::NV_PATCH_FRAC_TRI_GUARD_INFO;

typedef struct D3DK::NV_PATCH_EVAL_OUTPUT
{
   float vertexAttribs[4] vertexAttribs[16] vertexAttribs[43];
} D3DK::NV_PATCH_EVAL_OUTPUT;

typedef struct D3DK::NV_PATCH_CORNER_INFO
{
   float corners[4] corners[2] corners[2];
} D3DK::NV_PATCH_CORNER_INFO;

typedef struct D3DK::NV_PATCH_QUAD_INFO
{
   D3DK::NV_PATCH_CURVE_INFO * pU0[16];
   D3DK::NV_PATCH_CURVE_INFO * pU1[16];
   D3DK::NV_PATCH_CURVE_INFO * pV0[16];
   D3DK::NV_PATCH_CURVE_INFO * pV1[16];
   D3DK::NV_PATCH_CURVE_INFO * pUInner[16];
   D3DK::NV_PATCH_CURVE_INFO * pVInner[16];
   D3DK::NV_PATCH_CORNER_INFO cornAttr[16];
   float * pCorners[2] pCorners[2] pCorners[16];
   unsigned long Padding8;
   unsigned long Padding9;
   unsigned long Padding10;
   unsigned long Padding11;
   unsigned long Padding12;
   unsigned long Padding13;
   unsigned long Padding14;
   unsigned long Padding15;
   unsigned long Padding16;
   unsigned long Padding17;
   unsigned long Padding18;
   unsigned long Padding19;
   unsigned long Padding20;
   unsigned long Padding21;
   unsigned long Padding22;
   unsigned long Padding23;
   unsigned long Padding24;
   unsigned long Padding25;
   unsigned long Padding26;
   unsigned long Padding27;
   unsigned long Padding28;
   unsigned long Padding29;
   unsigned long Padding30;
   unsigned long Padding31;
   unsigned long Padding32;
   unsigned long Padding33;
   unsigned long Padding34;
   unsigned long Padding35;
   unsigned long Padding36;
   unsigned long Padding37;
   unsigned long Padding38;
   unsigned long Padding39;
   unsigned long Padding40;
   unsigned long Padding41;
   unsigned long Padding42;
   unsigned long Padding43;
   unsigned long Padding44;
   unsigned long Padding45;
   unsigned long Padding46;
   unsigned long Padding47;
   unsigned long Padding48;
   unsigned long Padding49;
   unsigned long Padding50;
   unsigned long Padding51;
   unsigned long Padding52;
   unsigned long Padding53;
   unsigned long Padding54;
   unsigned long Padding55;
   int nu0;
   int nu1;
   int nv0;
   int nv1;
   int uMaxSegs;
   int vMaxSegs;
   int uMinSegs;
   int vMinSegs;
   int needUInner;
   int needVInner;
   int stitchTop;
   int stitchRight;
   int stitchBottom;
   int stitchLeft;
   int stitchUBegin;
   int stitchUEnd;
   int stitchVBegin;
   int stitchVEnd;
   int u0Dir;
   int v0Dir;
   int u1Dir;
   int v1Dir;
   int uMaxDir;
   int vMaxDir;
   float du0;
   float du1;
   float dv0;
   float dv1;
   float duMax;
   float dvMax;
   D3DK::NV_PATCH_CURVE_INFO * pSwatchUBegin[16];
   D3DK::NV_PATCH_CURVE_INFO * pSwatchUEnd[16];
   D3DK::NV_PATCH_CURVE_INFO * pSwatchVBegin[16];
   D3DK::NV_PATCH_CURVE_INFO * pSwatchVEnd[16];
   D3DK::NV_PATCH_CURVE_INFO * pCurvesTop[16];
   D3DK::NV_PATCH_CURVE_INFO * pCurvesBot[16];
   D3DK::NV_PATCH_EVAL_OUTPUT * pOut1;
   D3DK::NV_PATCH_EVAL_OUTPUT * pOut2;
   D3DK::FDMatrix * m00[16];
   D3DK::FDMatrix * m01[16];
   D3DK::FDMatrix * m10[16];
   D3DK::FDMatrix * m11[16];
   D3DK::NV_PATCH_FRAC_QUAD_GUARD_INFO * guardQF[16];
   D3DK::NV_PATCH_FRAC_TRI_GUARD_INFO * guardTF[16];
} D3DK::NV_PATCH_QUAD_INFO;

typedef struct D3DK::FDMatrix
{
   int rows;
   int columns;
   int pad[2];
   float data[4] data[16] data[16];
} D3DK::FDMatrix;

typedef struct D3DK::NV_PATCH_ALLOC_CACHE
{
   void * pBaseCache;
   int bytesAllocCache;
   int countFreeCheck;
   int inUse;
   void * contextCache;
} D3DK::NV_PATCH_ALLOC_CACHE;

typedef struct D3DK::NV_PATCH_MAP_INFO
{
   int uorder;
   int vorder;
   float * rawData;
   int stride;
   int pitch;
   int ufStride;
   int vfStride;
   int maptype;
   int Originaltype;
   int dirtyFlags;
} D3DK::NV_PATCH_MAP_INFO;

typedef union D3DK::NV_PATCH_INFO::__unnamed
{
   union {
   D3DK::NV_PATCH_INFO::__unnamed::__unnamed tensor;
   D3DK::NV_PATCH_INFO::__unnamed::__unnamed tri;
   };
} D3DK::NV_PATCH_INFO::__unnamed;

typedef struct D3DK::NV_PATCH_INFO::__unnamed::__unnamed
{
   float nu0;
   float nu1;
   float nv0;
   float nv1;
} D3DK::NV_PATCH_INFO::__unnamed::__unnamed;

typedef struct D3DK::NV_PATCH_FRAC_QUAD_GUARD_INFO
{
   D3DK::NV_PATCH_CURVE_INFO guardU00;
   D3DK::NV_PATCH_CURVE_INFO guardU01;
   D3DK::NV_PATCH_CURVE_INFO guardU10;
   D3DK::NV_PATCH_CURVE_INFO guardU11;
   D3DK::NV_PATCH_CURVE_INFO guardV00;
   D3DK::NV_PATCH_CURVE_INFO guardV01;
   D3DK::NV_PATCH_CURVE_INFO guardV10;
   D3DK::NV_PATCH_CURVE_INFO guardV11;
   D3DK::NV_PATCH_CURVE_INFO guardUCenter0;
   D3DK::NV_PATCH_CURVE_INFO guardUCenter1;
   D3DK::NV_PATCH_CURVE_INFO guardVCenter0;
   D3DK::NV_PATCH_CURVE_INFO guardVCenter1;
   float u0Mid[4];
   float v0Mid[4];
   float u1Mid[4];
   float v1Mid[4];
   float center[4];
} D3DK::NV_PATCH_FRAC_QUAD_GUARD_INFO;

typedef struct D3DK::_D3DPERFNAMES
{
   char * m_PerformanceCounterNames[30];
   char * m_APICounterNames[235];
   D3DK::_D3DSTATENAME m_RenderStateNames[144];
   D3DK::_D3DSTATENAME m_TextureStateNames[32];
} D3DK::_D3DPERFNAMES;

typedef struct D3DK::_D3DSTATENAME
{
   unsigned long m_State;
   char * m_Name;
} D3DK::_D3DSTATENAME;

typedef struct D3DK::NV_PATCH_FRAC_GUARD_INFO
{
   D3DK::NV_PATCH_CURVE_INFO * guardU0;
   D3DK::NV_PATCH_CURVE_INFO * guardV0;
   D3DK::NV_PATCH_CURVE_INFO * guardUCenter;
   D3DK::NV_PATCH_CURVE_INFO * guardVCenter;
   float * uMid;
   float * vMid;
   float * center;
} D3DK::NV_PATCH_FRAC_GUARD_INFO;

typedef struct D3DK::NV_PATCH_CURVE_INFO
{
   int order;
   int pad[3];
   float coeffs[4] coeffs[16];
} D3DK::NV_PATCH_CURVE_INFO;

typedef struct D3DK::CDevice
{
   union {
   (type???) D3DDevice;
   _XMETAL_PushBuffer m_Pusher;
   };
   unsigned long m_DirtyFlags;
   unsigned long m_StateFlags;
   union {
   unsigned long m_PushBufferSize;
   unsigned long m_PushSegmentSize;
   };
   unsigned long Padding6;
   unsigned long Padding7;
   unsigned long Padding8;
   unsigned long * m_pPushBase;
   unsigned long * m_pPushLimit;
   unsigned long * m_pKickOff;
   unsigned long m_CpuTime;
   unsigned long m_PusherLastSegment;
   D3DK::Fence m_PusherSegment[16];
   D3DK::Fence m_PusherFence[64];
   unsigned long m_PusherPutRunSize;
   unsigned long m_PusherLastSize;
   unsigned long m_LastRunPushBufferTime;
   volatile unsigned long * m_pGpuTime;
   D3DPushBuffer * m_pPushBufferRecordResource;
   unsigned long m_PushBufferRecordWrapSize;
   unsigned long * m_pPushBufferRecordSavedThreshold;
   unsigned long * m_pPushBufferRecordSavedPut;
   D3DK::_HWREG * m_NvBase;
   unsigned long m_cRefs;
   D3DSurface * m_pRenderTarget;
   D3DSurface * m_pZBuffer;
   D3DK::PixelShader * m_pPixelShader;
   unsigned long m_ShaderUsesSpecFog;
   unsigned long m_ShaderAdjustsTexMode;
   unsigned long m_PSShaderStageProgram;
   unsigned long m_pPixelShaderConstants[16];
   D3DK::PixelShader m_UserPixelShader;
   D3DK::VertexShader * m_pVertexShader;
   unsigned long m_VertexShaderHandle;
   int m_IndexBase;
   D3DIndexBuffer * m_pIndexBuffer;
   D3DK::Light * m_pLights;
   unsigned long m_LightCount;
   D3DK::Light * m_pActiveLights;
   void * m_ReportAllocations[16];
   unsigned long m_TextureControl0Enabled[4];
   unsigned long m_TextureCubemapAndDimension[4];
   float m_WNear;
   float m_WFar;
   float m_InverseWFar;
   float m_ZScale;
   unsigned long m_TexGenInverseNeeded;
   float m_SuperSampleScaleX;
   float m_SuperSampleScaleY;
   float m_SuperSampleScale;
   float m_SuperSampleLODBias;
   unsigned long m_AlphaICW[8];
   unsigned long m_AlphaOCW[8];
   unsigned long m_ColorICW[8];
   unsigned long m_ColorOCW[8];
   unsigned long m_CombinerFlags;
   unsigned long m_ActiveCombinerStagesCount;
   unsigned long m_CachedIndexBase;
   _D3DMATRIX m_ProjectionViewportTransform;
   _D3DMATRIX m_ModelViewTransform[4];
   _D3DMATRIX m_ProjectionViewport;
   unsigned long m_VertexShaderInputHandle;
   unsigned long m_VertexShaderInputCount;
   _D3DSTREAM_INPUT m_VertexShaderInputStream[16];
   unsigned long m_InlineVertexDwords;
   unsigned long m_InlineStartOffset;
   unsigned long m_InlineDelta;
   D3DK::InlineAttributeData m_InlineAttributeData[16];
   unsigned long m_InlineAttributeCount;
   unsigned long Padding71;
   unsigned long Padding72;
   _D3DMATRIX m_Transform[10];
   _D3DVIEWPORT8 m_Viewport;
   _D3DMATERIAL8 m_Material;
   _D3DMATERIAL8 m_BackMaterial;
   D3DBaseTexture * m_Textures[4];
   D3DPalette * m_Palettes[4];
   float m_PixelShaderConstants[4] m_PixelShaderConstants[16];
   unsigned long Padding80;
   unsigned long Padding81;
   unsigned long Padding82;
   unsigned long Padding83;
   unsigned long Padding84;
   unsigned long Padding85;
   unsigned long Padding86;
   unsigned long Padding87;
   unsigned long Padding88;
   unsigned long Padding89;
   unsigned long Padding90;
   unsigned long Padding91;
   unsigned long Padding92;
   unsigned long Padding93;
   unsigned long Padding94;
   unsigned long Padding95;
   unsigned long Padding96;
   unsigned long Padding97;
   unsigned long Padding98;
   unsigned long Padding99;
   unsigned long Padding100;
   unsigned long Padding101;
   unsigned long Padding102;
   unsigned long Padding103;
   unsigned long Padding104;
   unsigned long Padding105;
   unsigned long Padding106;
   unsigned long Padding107;
   unsigned long Padding108;
   unsigned long Padding109;
   unsigned long Padding110;
   unsigned long Padding111;
   unsigned long Padding112;
   unsigned long Padding113;
   unsigned long Padding114;
   unsigned long Padding115;
   unsigned long Padding116;
   unsigned long Padding117;
   unsigned long Padding118;
   unsigned long Padding119;
   unsigned long Padding120;
   unsigned long Padding121;
   unsigned long Padding122;
   unsigned long Padding123;
   unsigned long Padding124;
   unsigned long Padding125;
   unsigned long Padding126;
   unsigned long Padding127;
   float m_VertexShaderConstants[4] m_VertexShaderConstants[192];
   unsigned long Padding129;
   unsigned long Padding130;
   unsigned long Padding131;
   unsigned long Padding132;
   unsigned long Padding133;
   unsigned long Padding134;
   unsigned long Padding135;
   unsigned long Padding136;
   unsigned long Padding137;
   unsigned long Padding138;
   unsigned long Padding139;
   unsigned long Padding140;
   unsigned long Padding141;
   unsigned long Padding142;
   unsigned long Padding143;
   unsigned long Padding144;
   unsigned long Padding145;
   unsigned long Padding146;
   unsigned long Padding147;
   unsigned long Padding148;
   unsigned long Padding149;
   unsigned long Padding150;
   unsigned long Padding151;
   unsigned long Padding152;
   unsigned long Padding153;
   unsigned long Padding154;
   unsigned long Padding155;
   unsigned long Padding156;
   unsigned long Padding157;
   unsigned long Padding158;
   unsigned long Padding159;
   unsigned long Padding160;
   unsigned long Padding161;
   unsigned long Padding162;
   unsigned long Padding163;
   unsigned long Padding164;
   unsigned long Padding165;
   unsigned long Padding166;
   unsigned long Padding167;
   unsigned long Padding168;
   unsigned long Padding169;
   unsigned long Padding170;
   unsigned long Padding171;
   unsigned long Padding172;
   unsigned long Padding173;
   unsigned long Padding174;
   unsigned long Padding175;
   unsigned long Padding176;
   unsigned long Padding177;
   unsigned long Padding178;
   unsigned long Padding179;
   unsigned long Padding180;
   unsigned long Padding181;
   unsigned long Padding182;
   unsigned long Padding183;
   unsigned long Padding184;
   unsigned long Padding185;
   unsigned long Padding186;
   unsigned long Padding187;
   unsigned long Padding188;
   unsigned long Padding189;
   unsigned long Padding190;
   unsigned long Padding191;
   unsigned long Padding192;
   unsigned long Padding193;
   unsigned long Padding194;
   unsigned long Padding195;
   unsigned long Padding196;
   unsigned long Padding197;
   unsigned long Padding198;
   unsigned long Padding199;
   unsigned long Padding200;
   unsigned long Padding201;
   unsigned long Padding202;
   unsigned long Padding203;
   unsigned long Padding204;
   unsigned long Padding205;
   unsigned long Padding206;
   unsigned long Padding207;
   unsigned long Padding208;
   unsigned long Padding209;
   unsigned long Padding210;
   unsigned long Padding211;
   unsigned long Padding212;
   unsigned long Padding213;
   unsigned long Padding214;
   unsigned long Padding215;
   unsigned long Padding216;
   unsigned long Padding217;
   unsigned long Padding218;
   unsigned long Padding219;
   unsigned long Padding220;
   unsigned long Padding221;
   unsigned long Padding222;
   unsigned long Padding223;
   unsigned long Padding224;
   unsigned long Padding225;
   unsigned long Padding226;
   unsigned long Padding227;
   unsigned long Padding228;
   unsigned long Padding229;
   unsigned long Padding230;
   unsigned long Padding231;
   unsigned long Padding232;
   unsigned long Padding233;
   unsigned long Padding234;
   unsigned long Padding235;
   unsigned long Padding236;
   unsigned long Padding237;
   unsigned long Padding238;
   unsigned long Padding239;
   unsigned long Padding240;
   unsigned long Padding241;
   unsigned long Padding242;
   unsigned long Padding243;
   unsigned long Padding244;
   unsigned long Padding245;
   unsigned long Padding246;
   unsigned long Padding247;
   unsigned long Padding248;
   unsigned long Padding249;
   unsigned long Padding250;
   unsigned long Padding251;
   unsigned long Padding252;
   unsigned long Padding253;
   unsigned long Padding254;
   unsigned long Padding255;
   unsigned long Padding256;
   unsigned long Padding257;
   unsigned long Padding258;
   unsigned long Padding259;
   unsigned long Padding260;
   unsigned long Padding261;
   unsigned long Padding262;
   unsigned long Padding263;
   unsigned long Padding264;
   unsigned long Padding265;
   unsigned long Padding266;
   unsigned long Padding267;
   unsigned long Padding268;
   unsigned long Padding269;
   unsigned long Padding270;
   unsigned long Padding271;
   unsigned long Padding272;
   unsigned long Padding273;
   unsigned long Padding274;
   unsigned long Padding275;
   unsigned long Padding276;
   unsigned long Padding277;
   unsigned long Padding278;
   unsigned long Padding279;
   unsigned long Padding280;
   unsigned long Padding281;
   unsigned long Padding282;
   unsigned long Padding283;
   unsigned long Padding284;
   unsigned long Padding285;
   unsigned long Padding286;
   unsigned long Padding287;
   unsigned long Padding288;
   unsigned long Padding289;
   unsigned long Padding290;
   unsigned long Padding291;
   unsigned long Padding292;
   unsigned long Padding293;
   unsigned long Padding294;
   unsigned long Padding295;
   unsigned long Padding296;
   unsigned long Padding297;
   unsigned long Padding298;
   unsigned long Padding299;
   unsigned long Padding300;
   unsigned long Padding301;
   unsigned long Padding302;
   unsigned long Padding303;
   unsigned long Padding304;
   unsigned long Padding305;
   unsigned long Padding306;
   unsigned long Padding307;
   unsigned long Padding308;
   unsigned long Padding309;
   unsigned long Padding310;
   unsigned long Padding311;
   unsigned long Padding312;
   unsigned long Padding313;
   unsigned long Padding314;
   unsigned long Padding315;
   unsigned long Padding316;
   unsigned long Padding317;
   unsigned long Padding318;
   unsigned long Padding319;
   unsigned long Padding320;
   unsigned long Padding321;
   unsigned long Padding322;
   unsigned long Padding323;
   unsigned long Padding324;
   unsigned long Padding325;
   unsigned long Padding326;
   unsigned long Padding327;
   unsigned long Padding328;
   unsigned long Padding329;
   unsigned long Padding330;
   unsigned long Padding331;
   unsigned long Padding332;
   unsigned long Padding333;
   unsigned long Padding334;
   unsigned long Padding335;
   unsigned long Padding336;
   unsigned long Padding337;
   unsigned long Padding338;
   unsigned long Padding339;
   unsigned long Padding340;
   unsigned long Padding341;
   unsigned long Padding342;
   unsigned long Padding343;
   unsigned long Padding344;
   unsigned long Padding345;
   unsigned long Padding346;
   unsigned long Padding347;
   unsigned long Padding348;
   unsigned long Padding349;
   unsigned long Padding350;
   unsigned long Padding351;
   unsigned long Padding352;
   unsigned long Padding353;
   unsigned long Padding354;
   unsigned long Padding355;
   unsigned long Padding356;
   unsigned long Padding357;
   unsigned long Padding358;
   unsigned long Padding359;
   unsigned long Padding360;
   unsigned long Padding361;
   unsigned long Padding362;
   unsigned long Padding363;
   unsigned long Padding364;
   unsigned long Padding365;
   unsigned long Padding366;
   unsigned long Padding367;
   unsigned long Padding368;
   unsigned long Padding369;
   unsigned long Padding370;
   unsigned long Padding371;
   unsigned long Padding372;
   unsigned long Padding373;
   unsigned long Padding374;
   unsigned long Padding375;
   unsigned long Padding376;
   unsigned long Padding377;
   unsigned long Padding378;
   unsigned long Padding379;
   unsigned long Padding380;
   unsigned long Padding381;
   unsigned long Padding382;
   unsigned long Padding383;
   unsigned long Padding384;
   unsigned long Padding385;
   unsigned long Padding386;
   unsigned long Padding387;
   unsigned long Padding388;
   unsigned long Padding389;
   unsigned long Padding390;
   unsigned long Padding391;
   unsigned long Padding392;
   unsigned long Padding393;
   unsigned long Padding394;
   unsigned long Padding395;
   unsigned long Padding396;
   unsigned long Padding397;
   unsigned long Padding398;
   unsigned long Padding399;
   unsigned long Padding400;
   unsigned long Padding401;
   unsigned long Padding402;
   unsigned long Padding403;
   unsigned long Padding404;
   unsigned long Padding405;
   unsigned long Padding406;
   unsigned long Padding407;
   unsigned long Padding408;
   unsigned long Padding409;
   unsigned long Padding410;
   unsigned long Padding411;
   unsigned long Padding412;
   unsigned long Padding413;
   unsigned long Padding414;
   unsigned long Padding415;
   unsigned long Padding416;
   unsigned long Padding417;
   unsigned long Padding418;
   unsigned long Padding419;
   unsigned long Padding420;
   unsigned long Padding421;
   unsigned long Padding422;
   unsigned long Padding423;
   unsigned long Padding424;
   unsigned long Padding425;
   unsigned long Padding426;
   unsigned long Padding427;
   unsigned long Padding428;
   unsigned long Padding429;
   unsigned long Padding430;
   unsigned long Padding431;
   unsigned long Padding432;
   unsigned long Padding433;
   unsigned long Padding434;
   unsigned long Padding435;
   unsigned long Padding436;
   unsigned long Padding437;
   unsigned long Padding438;
   unsigned long Padding439;
   unsigned long Padding440;
   unsigned long Padding441;
   unsigned long Padding442;
   unsigned long Padding443;
   unsigned long Padding444;
   unsigned long Padding445;
   unsigned long Padding446;
   unsigned long Padding447;
   unsigned long Padding448;
   unsigned long Padding449;
   unsigned long Padding450;
   unsigned long Padding451;
   unsigned long Padding452;
   unsigned long Padding453;
   unsigned long Padding454;
   unsigned long Padding455;
   unsigned long Padding456;
   unsigned long Padding457;
   unsigned long Padding458;
   unsigned long Padding459;
   unsigned long Padding460;
   unsigned long Padding461;
   unsigned long Padding462;
   unsigned long Padding463;
   unsigned long Padding464;
   unsigned long Padding465;
   unsigned long Padding466;
   unsigned long Padding467;
   unsigned long Padding468;
   unsigned long Padding469;
   unsigned long Padding470;
   unsigned long Padding471;
   unsigned long Padding472;
   unsigned long Padding473;
   unsigned long Padding474;
   unsigned long Padding475;
   unsigned long Padding476;
   unsigned long Padding477;
   unsigned long Padding478;
   unsigned long Padding479;
   unsigned long Padding480;
   unsigned long Padding481;
   unsigned long Padding482;
   unsigned long Padding483;
   unsigned long Padding484;
   unsigned long Padding485;
   unsigned long Padding486;
   unsigned long Padding487;
   unsigned long Padding488;
   unsigned long Padding489;
   unsigned long Padding490;
   unsigned long Padding491;
   unsigned long Padding492;
   unsigned long Padding493;
   unsigned long Padding494;
   unsigned long Padding495;
   unsigned long Padding496;
   unsigned long Padding497;
   unsigned long Padding498;
   unsigned long Padding499;
   unsigned long Padding500;
   unsigned long Padding501;
   unsigned long Padding502;
   unsigned long Padding503;
   unsigned long Padding504;
   unsigned long Padding505;
   unsigned long Padding506;
   unsigned long Padding507;
   unsigned long Padding508;
   unsigned long Padding509;
   unsigned long Padding510;
   unsigned long Padding511;
   unsigned long Padding512;
   unsigned long Padding513;
   unsigned long Padding514;
   unsigned long Padding515;
   unsigned long Padding516;
   unsigned long Padding517;
   unsigned long Padding518;
   unsigned long Padding519;
   unsigned long Padding520;
   unsigned long Padding521;
   unsigned long Padding522;
   unsigned long Padding523;
   unsigned long Padding524;
   unsigned long Padding525;
   unsigned long Padding526;
   unsigned long Padding527;
   unsigned long Padding528;
   unsigned long Padding529;
   unsigned long Padding530;
   unsigned long Padding531;
   unsigned long Padding532;
   unsigned long Padding533;
   unsigned long Padding534;
   unsigned long Padding535;
   unsigned long Padding536;
   unsigned long Padding537;
   unsigned long Padding538;
   unsigned long Padding539;
   unsigned long Padding540;
   unsigned long Padding541;
   unsigned long Padding542;
   unsigned long Padding543;
   unsigned long Padding544;
   unsigned long Padding545;
   unsigned long Padding546;
   unsigned long Padding547;
   unsigned long Padding548;
   unsigned long Padding549;
   unsigned long Padding550;
   unsigned long Padding551;
   unsigned long Padding552;
   unsigned long Padding553;
   unsigned long Padding554;
   unsigned long Padding555;
   unsigned long Padding556;
   unsigned long Padding557;
   unsigned long Padding558;
   unsigned long Padding559;
   unsigned long Padding560;
   unsigned long Padding561;
   unsigned long Padding562;
   unsigned long Padding563;
   unsigned long Padding564;
   unsigned long Padding565;
   unsigned long Padding566;
   unsigned long Padding567;
   unsigned long Padding568;
   unsigned long Padding569;
   unsigned long Padding570;
   unsigned long Padding571;
   unsigned long Padding572;
   unsigned long Padding573;
   unsigned long Padding574;
   unsigned long Padding575;
   unsigned long Padding576;
   unsigned long Padding577;
   unsigned long Padding578;
   unsigned long Padding579;
   unsigned long Padding580;
   unsigned long Padding581;
   unsigned long Padding582;
   unsigned long Padding583;
   unsigned long Padding584;
   unsigned long Padding585;
   unsigned long Padding586;
   unsigned long Padding587;
   unsigned long Padding588;
   unsigned long Padding589;
   unsigned long Padding590;
   unsigned long Padding591;
   unsigned long Padding592;
   unsigned long Padding593;
   unsigned long Padding594;
   unsigned long Padding595;
   unsigned long Padding596;
   unsigned long Padding597;
   unsigned long Padding598;
   unsigned long Padding599;
   unsigned long Padding600;
   unsigned long Padding601;
   unsigned long Padding602;
   unsigned long Padding603;
   unsigned long Padding604;
   unsigned long Padding605;
   unsigned long Padding606;
   unsigned long Padding607;
   unsigned long Padding608;
   unsigned long Padding609;
   unsigned long Padding610;
   unsigned long Padding611;
   unsigned long Padding612;
   unsigned long Padding613;
   unsigned long Padding614;
   unsigned long Padding615;
   unsigned long Padding616;
   unsigned long Padding617;
   unsigned long Padding618;
   unsigned long Padding619;
   unsigned long Padding620;
   unsigned long Padding621;
   unsigned long Padding622;
   unsigned long Padding623;
   unsigned long Padding624;
   unsigned long Padding625;
   unsigned long Padding626;
   unsigned long Padding627;
   unsigned long Padding628;
   unsigned long Padding629;
   unsigned long Padding630;
   unsigned long Padding631;
   unsigned long Padding632;
   unsigned long Padding633;
   unsigned long Padding634;
   unsigned long Padding635;
   unsigned long Padding636;
   unsigned long Padding637;
   unsigned long Padding638;
   unsigned long Padding639;
   unsigned long Padding640;
   unsigned long Padding641;
   unsigned long Padding642;
   unsigned long Padding643;
   unsigned long Padding644;
   unsigned long Padding645;
   unsigned long Padding646;
   unsigned long Padding647;
   unsigned long Padding648;
   unsigned long Padding649;
   unsigned long Padding650;
   unsigned long Padding651;
   unsigned long Padding652;
   unsigned long Padding653;
   unsigned long Padding654;
   unsigned long Padding655;
   unsigned long Padding656;
   unsigned long Padding657;
   unsigned long Padding658;
   unsigned long Padding659;
   unsigned long Padding660;
   unsigned long Padding661;
   unsigned long Padding662;
   unsigned long Padding663;
   unsigned long Padding664;
   unsigned long Padding665;
   unsigned long Padding666;
   unsigned long Padding667;
   unsigned long Padding668;
   unsigned long Padding669;
   unsigned long Padding670;
   unsigned long Padding671;
   unsigned long Padding672;
   unsigned long Padding673;
   unsigned long Padding674;
   unsigned long Padding675;
   unsigned long Padding676;
   unsigned long Padding677;
   unsigned long Padding678;
   unsigned long Padding679;
   unsigned long Padding680;
   unsigned long Padding681;
   unsigned long Padding682;
   unsigned long Padding683;
   unsigned long Padding684;
   unsigned long Padding685;
   unsigned long Padding686;
   unsigned long Padding687;
   unsigned long Padding688;
   unsigned long Padding689;
   unsigned long Padding690;
   unsigned long Padding691;
   unsigned long Padding692;
   unsigned long Padding693;
   unsigned long Padding694;
   unsigned long Padding695;
   unsigned long Padding696;
   unsigned long Padding697;
   unsigned long Padding698;
   unsigned long Padding699;
   unsigned long Padding700;
   unsigned long Padding701;
   unsigned long Padding702;
   unsigned long Padding703;
   unsigned long Padding704;
   unsigned long m_VertexShaderProgramSlots[4] m_VertexShaderProgramSlots[136];
   unsigned long Padding706;
   unsigned long Padding707;
   unsigned long Padding708;
   unsigned long Padding709;
   unsigned long Padding710;
   unsigned long Padding711;
   unsigned long Padding712;
   unsigned long Padding713;
   unsigned long Padding714;
   unsigned long Padding715;
   unsigned long Padding716;
   unsigned long Padding717;
   unsigned long Padding718;
   unsigned long Padding719;
   unsigned long Padding720;
   unsigned long Padding721;
   unsigned long Padding722;
   unsigned long Padding723;
   unsigned long Padding724;
   unsigned long Padding725;
   unsigned long Padding726;
   unsigned long Padding727;
   unsigned long Padding728;
   unsigned long Padding729;
   unsigned long Padding730;
   unsigned long Padding731;
   unsigned long Padding732;
   unsigned long Padding733;
   unsigned long Padding734;
   unsigned long Padding735;
   unsigned long Padding736;
   unsigned long Padding737;
   unsigned long Padding738;
   unsigned long Padding739;
   unsigned long Padding740;
   unsigned long Padding741;
   unsigned long Padding742;
   unsigned long Padding743;
   unsigned long Padding744;
   unsigned long Padding745;
   unsigned long Padding746;
   unsigned long Padding747;
   unsigned long Padding748;
   unsigned long Padding749;
   unsigned long Padding750;
   unsigned long Padding751;
   unsigned long Padding752;
   unsigned long Padding753;
   unsigned long Padding754;
   unsigned long Padding755;
   unsigned long Padding756;
   unsigned long Padding757;
   unsigned long Padding758;
   unsigned long Padding759;
   unsigned long Padding760;
   unsigned long Padding761;
   unsigned long Padding762;
   unsigned long Padding763;
   unsigned long Padding764;
   unsigned long Padding765;
   unsigned long Padding766;
   unsigned long Padding767;
   unsigned long Padding768;
   unsigned long Padding769;
   unsigned long Padding770;
   unsigned long Padding771;
   unsigned long Padding772;
   unsigned long Padding773;
   unsigned long Padding774;
   unsigned long Padding775;
   unsigned long Padding776;
   unsigned long Padding777;
   unsigned long Padding778;
   unsigned long Padding779;
   unsigned long Padding780;
   unsigned long Padding781;
   unsigned long Padding782;
   unsigned long Padding783;
   unsigned long Padding784;
   unsigned long Padding785;
   unsigned long Padding786;
   unsigned long Padding787;
   unsigned long Padding788;
   unsigned long Padding789;
   unsigned long Padding790;
   unsigned long Padding791;
   unsigned long Padding792;
   unsigned long Padding793;
   unsigned long Padding794;
   unsigned long Padding795;
   unsigned long Padding796;
   unsigned long Padding797;
   unsigned long Padding798;
   unsigned long Padding799;
   unsigned long Padding800;
   unsigned long Padding801;
   unsigned long Padding802;
   unsigned long Padding803;
   unsigned long Padding804;
   unsigned long Padding805;
   unsigned long Padding806;
   unsigned long Padding807;
   unsigned long Padding808;
   unsigned long Padding809;
   unsigned long Padding810;
   unsigned long Padding811;
   unsigned long Padding812;
   unsigned long Padding813;
   unsigned long Padding814;
   unsigned long Padding815;
   unsigned long Padding816;
   unsigned long Padding817;
   unsigned long Padding818;
   unsigned long Padding819;
   unsigned long Padding820;
   unsigned long Padding821;
   unsigned long Padding822;
   unsigned long Padding823;
   unsigned long Padding824;
   unsigned long Padding825;
   unsigned long Padding826;
   unsigned long Padding827;
   unsigned long Padding828;
   unsigned long Padding829;
   unsigned long Padding830;
   unsigned long Padding831;
   unsigned long Padding832;
   unsigned long Padding833;
   unsigned long Padding834;
   unsigned long Padding835;
   unsigned long Padding836;
   unsigned long Padding837;
   unsigned long Padding838;
   unsigned long Padding839;
   unsigned long Padding840;
   unsigned long Padding841;
   unsigned long Padding842;
   unsigned long Padding843;
   unsigned long Padding844;
   unsigned long Padding845;
   unsigned long Padding846;
   unsigned long Padding847;
   unsigned long Padding848;
   unsigned long Padding849;
   unsigned long Padding850;
   unsigned long Padding851;
   unsigned long Padding852;
   unsigned long Padding853;
   unsigned long Padding854;
   unsigned long Padding855;
   unsigned long Padding856;
   unsigned long Padding857;
   unsigned long Padding858;
   unsigned long Padding859;
   unsigned long Padding860;
   unsigned long Padding861;
   unsigned long Padding862;
   unsigned long Padding863;
   unsigned long Padding864;
   unsigned long Padding865;
   unsigned long Padding866;
   unsigned long Padding867;
   unsigned long Padding868;
   unsigned long Padding869;
   unsigned long Padding870;
   unsigned long Padding871;
   unsigned long Padding872;
   unsigned long Padding873;
   unsigned long Padding874;
   unsigned long Padding875;
   unsigned long Padding876;
   unsigned long Padding877;
   unsigned long Padding878;
   unsigned long Padding879;
   unsigned long Padding880;
   unsigned long Padding881;
   unsigned long Padding882;
   unsigned long Padding883;
   unsigned long Padding884;
   unsigned long Padding885;
   unsigned long Padding886;
   unsigned long Padding887;
   unsigned long Padding888;
   unsigned long Padding889;
   unsigned long Padding890;
   unsigned long Padding891;
   unsigned long Padding892;
   unsigned long Padding893;
   unsigned long Padding894;
   unsigned long Padding895;
   unsigned long Padding896;
   unsigned long Padding897;
   unsigned long Padding898;
   unsigned long Padding899;
   unsigned long Padding900;
   unsigned long Padding901;
   unsigned long Padding902;
   unsigned long Padding903;
   unsigned long Padding904;
   unsigned long Padding905;
   unsigned long Padding906;
   unsigned long Padding907;
   unsigned long Padding908;
   unsigned long Padding909;
   unsigned long Padding910;
   unsigned long Padding911;
   unsigned long Padding912;
   unsigned long Padding913;
   unsigned long Padding914;
   unsigned long Padding915;
   unsigned long Padding916;
   unsigned long Padding917;
   unsigned long Padding918;
   unsigned long Padding919;
   unsigned long Padding920;
   unsigned long Padding921;
   unsigned long Padding922;
   unsigned long Padding923;
   unsigned long Padding924;
   unsigned long Padding925;
   unsigned long Padding926;
   unsigned long Padding927;
   unsigned long Padding928;
   unsigned long Padding929;
   unsigned long Padding930;
   unsigned long Padding931;
   unsigned long Padding932;
   unsigned long Padding933;
   unsigned long Padding934;
   unsigned long Padding935;
   unsigned long Padding936;
   unsigned long Padding937;
   unsigned long Padding938;
   unsigned long Padding939;
   unsigned long Padding940;
   unsigned long Padding941;
   unsigned long Padding942;
   unsigned long Padding943;
   unsigned long Padding944;
   unsigned long Padding945;
   unsigned long Padding946;
   unsigned long Padding947;
   unsigned long Padding948;
   unsigned long Padding949;
   unsigned long Padding950;
   unsigned long Padding951;
   unsigned long Padding952;
   unsigned long Padding953;
   unsigned long Padding954;
   unsigned long Padding955;
   unsigned long Padding956;
   unsigned long Padding957;
   unsigned long Padding958;
   unsigned long Padding959;
   unsigned long Padding960;
   unsigned long Padding961;
   unsigned long Padding962;
   unsigned long Padding963;
   unsigned long Padding964;
   unsigned long Padding965;
   unsigned long Padding966;
   unsigned long Padding967;
   unsigned long Padding968;
   unsigned long Padding969;
   unsigned long Padding970;
   unsigned long Padding971;
   unsigned long Padding972;
   unsigned long Padding973;
   unsigned long Padding974;
   unsigned long Padding975;
   unsigned long Padding976;
   unsigned long Padding977;
   unsigned long Padding978;
   unsigned long Padding979;
   unsigned long Padding980;
   unsigned long Padding981;
   unsigned long Padding982;
   unsigned long Padding983;
   unsigned long Padding984;
   unsigned long Padding985;
   unsigned long Padding986;
   unsigned long Padding987;
   unsigned long Padding988;
   unsigned long Padding989;
   unsigned long Padding990;
   unsigned long Padding991;
   unsigned long Padding992;
   unsigned long Padding993;
   unsigned long Padding994;
   unsigned long Padding995;
   unsigned long Padding996;
   unsigned long Padding997;
   unsigned long Padding998;
   unsigned long Padding999;
   unsigned long Padding1000;
   unsigned long Padding1001;
   unsigned long Padding1002;
   unsigned long Padding1003;
   unsigned long Padding1004;
   unsigned long Padding1005;
   unsigned long Padding1006;
   unsigned long Padding1007;
   unsigned long Padding1008;
   unsigned long Padding1009;
   unsigned long Padding1010;
   unsigned long Padding1011;
   unsigned long Padding1012;
   unsigned long Padding1013;
   unsigned long Padding1014;
   unsigned long Padding1015;
   unsigned long Padding1016;
   unsigned long Padding1017;
   unsigned long Padding1018;
   unsigned long Padding1019;
   unsigned long Padding1020;
   unsigned long Padding1021;
   unsigned long Padding1022;
   unsigned long Padding1023;
   unsigned long Padding1024;
   unsigned long Padding1025;
   unsigned long Padding1026;
   unsigned long Padding1027;
   unsigned long Padding1028;
   unsigned long Padding1029;
   unsigned long Padding1030;
   unsigned long Padding1031;
   unsigned long Padding1032;
   unsigned long Padding1033;
   unsigned long Padding1034;
   unsigned long Padding1035;
   unsigned long Padding1036;
   unsigned long Padding1037;
   unsigned long Padding1038;
   unsigned long Padding1039;
   unsigned long Padding1040;
   unsigned long Padding1041;
   unsigned long Padding1042;
   unsigned long Padding1043;
   unsigned long Padding1044;
   unsigned long Padding1045;
   unsigned long Padding1046;
   unsigned long Padding1047;
   unsigned long Padding1048;
   unsigned long Padding1049;
   unsigned long Padding1050;
   unsigned long Padding1051;
   unsigned long Padding1052;
   unsigned long Padding1053;
   unsigned long Padding1054;
   unsigned long Padding1055;
   unsigned long Padding1056;
   unsigned long Padding1057;
   unsigned long Padding1058;
   unsigned long Padding1059;
   unsigned long Padding1060;
   unsigned long Padding1061;
   unsigned long Padding1062;
   unsigned long Padding1063;
   unsigned long Padding1064;
   unsigned long Padding1065;
   unsigned long Padding1066;
   unsigned long Padding1067;
   unsigned long Padding1068;
   unsigned long Padding1069;
   unsigned long Padding1070;
   unsigned long Padding1071;
   unsigned long Padding1072;
   unsigned long Padding1073;
   unsigned long Padding1074;
   unsigned long Padding1075;
   unsigned long Padding1076;
   unsigned long Padding1077;
   unsigned long Padding1078;
   unsigned long Padding1079;
   unsigned long Padding1080;
   unsigned long Padding1081;
   unsigned long Padding1082;
   unsigned long Padding1083;
   unsigned long Padding1084;
   unsigned long Padding1085;
   unsigned long Padding1086;
   unsigned long Padding1087;
   unsigned long Padding1088;
   unsigned long Padding1089;
   unsigned long Padding1090;
   unsigned long Padding1091;
   unsigned long Padding1092;
   unsigned long Padding1093;
   unsigned long Padding1094;
   unsigned long Padding1095;
   unsigned long Padding1096;
   unsigned long Padding1097;
   unsigned long Padding1098;
   unsigned long Padding1099;
   unsigned long Padding1100;
   unsigned long Padding1101;
   unsigned long Padding1102;
   unsigned long Padding1103;
   unsigned long Padding1104;
   unsigned long Padding1105;
   unsigned long Padding1106;
   unsigned long Padding1107;
   unsigned long Padding1108;
   unsigned long Padding1109;
   unsigned long Padding1110;
   unsigned long Padding1111;
   unsigned long Padding1112;
   unsigned long Padding1113;
   unsigned long m_ConstantMode;
   void * m_pFrameBufferBase;
   void * m_pAntiAliasBufferBase;
   unsigned long m_FrameBufferCount;
   D3DSurface m_FrameBufferSurfaces[3];
   void * m_pAutoDepthBuffer;
   D3DSurface m_AutoDepthSurface;
   unsigned long m_DisplayWidth;
   unsigned long m_DisplayHeight;
   _D3DTILE m_Tile[8];
   _D3DRECT m_ScissorsRects[8];
   unsigned long m_ScissorsCount;
   int m_ScissorsExclusive;
   volatile Nv206eControl * m_pControlDma;
   class D3DK::CMiniport m_Miniport;
   unsigned long m_PresentCount;
   unsigned long m_PresentationInterval;
   unsigned long m_dwOpcode;
   unsigned long m_dwSnapshot;
   unsigned long * m_pShaderCaptureBuffer;
   unsigned long * m_pShaderCapturePtr;
   unsigned long m_ColorContextDmaInstance;
   unsigned long m_ZetaContextDmaInstance;
   unsigned long m_CopyContextDmaInstance;
   unsigned char * m_pCachedContiguousMemoryBase;
   volatile NvNotification * m_pMemCopyNotifiers;
   volatile NvNotification * m_pKelvinNotifiers;
   union {
   (type???) public: long __thiscall D3DK::CDevice::Init(struct _D3DPRESENT_PARAMETERS_ *);
   (type???) public: void __thiscall D3DK::CDevice::UnInit(void);
   (type???) public: long __thiscall D3DK::CDevice::InitializeFrameBuffers(struct _D3DPRESENT_PARAMETERS_ *);
   (type???) public: void __thiscall D3DK::CDevice::FreeFrameBuffers(void);
   (type???) public: void __thiscall D3DK::CDevice::SetStateUP(void);
   (type???) public: void __thiscall D3DK::CDevice::SetStateVB(unsigned long);
   (type???) StartPush;
   (type???) StartPush;
   (type???) StartBeginEndBracket;
   (type???) EndBeginEndBracket;
   (type???) EndPush;
   (type???) public: void __thiscall D3DK::CDevice::KickOff(void);
   (type???) public: void __thiscall D3DK::CDevice::InitializePushBuffer(void);
   (type???) public: unsigned long * __thiscall D3DK::CDevice::MakeSpace(void);
   (type???) HwPut;
   (type???) HwGet;
   (type???) public: unsigned long * __thiscall D3DK::CDevice::GpuGet(void);
   (type???) GpuTime;
   (type???) Age;
   (type???) IsTimePending;
   (type???) RecordResourceReadPush;
   (type???) RecordSurfaceWritePush;
   };
} D3DK::CDevice;

typedef struct NvNotification::__unnamed
{
   unsigned long nanoseconds[2];
} NvNotification::__unnamed;

typedef struct NvNotification
{
   NvNotification::__unnamed timeStamp;
   unsigned long info32;
   short info16;
   short status;
} NvNotification;

typedef struct D3DK::CMiniport::VBLANKFLIPS
{
   int Pending;
   unsigned long Offset;
} D3DK::CMiniport::VBLANKFLIPS;

typedef struct D3DK::CMiniport::VIDEOMODETIMING
{
   unsigned long HorizontalVisible;
   unsigned long VerticalVisible;
   unsigned long Refresh;
   unsigned long HorizontalTotal;
   unsigned long HorizontalBlankStart;
   unsigned long HorizontalRetraceStart;
   unsigned long HorizontalRetraceEnd;
   unsigned long HorizontalBlankEnd;
   unsigned long VerticalTotal;
   unsigned long VerticalBlankStart;
   unsigned long VerticalRetraceStart;
   unsigned long VerticalRetraceEnd;
   unsigned long VerticalBlankEnd;
   unsigned long PixelClock;
   unsigned long HorizontalSyncPolarity;
   unsigned long VerticalSyncPolarity;
} D3DK::CMiniport::VIDEOMODETIMING;

typedef struct D3DK::CMiniport::HALINFO
{
   long FifoChID;
   unsigned long FifoMode;
   int FifoInUse;
   unsigned long FifoInstance;
   unsigned long FifoAllocCount;
   long FifoCacheDepth;
   unsigned long FifoObjectCount;
   unsigned long FifoIntrEn0;
   unsigned long FifoRetryCount;
   unsigned long FifoUserBase;
   unsigned long FifoContextAddr1;
   unsigned long FifoContextAddr2;
   unsigned long HashTableAddr;
   unsigned long GrChID;
   unsigned long GrCtxTable[2];
   unsigned long GrCtxTableBase;
   unsigned long GrCurrentObjects3d[2];
   unsigned long FbSave0;
   unsigned long FbSave1;
   unsigned long McSave;
   unsigned long McSaveIntrEn0;
} D3DK::CMiniport::HALINFO;

typedef struct D3DK::CMiniport::DACINFO
{
   unsigned long MClk;
   unsigned long VClk;
   unsigned long NVClk;
   unsigned long MPllM;
   unsigned long MPllN;
   unsigned long MPllO;
   unsigned long MPllP;
   unsigned long VPllM;
   unsigned long VPllN;
   unsigned long VPllO;
   unsigned long VPllP;
   unsigned long NVPllM;
   unsigned long NVPllN;
   unsigned long NVPllO;
   unsigned long NVPllP;
} D3DK::CMiniport::DACINFO;

typedef struct D3DK::CMiniport::GENERALINFO
{
   unsigned long ChipId;
   unsigned long VideoRamSize;
   unsigned long VideoRamType;
   unsigned long ChipIntrEn0;
   unsigned long MpVIPSlavePresent;
   unsigned long CrystalFreq;
   unsigned long MaskRevision;
} D3DK::CMiniport::GENERALINFO;

typedef struct D3DK::CMiniport
{
   void * m_RegisterBase;
   unsigned long m_PresentationInterval;
   unsigned long m_SurfacePitch;
   unsigned long m_DisplayMode;
   unsigned long m_Format;
   void * m_InstMem;
   _KINTERRUPT m_InterruptObject;
   _KDPC m_Dpc;
   int m_InterruptsEnabled;
   D3DK::CMiniport::GENERALINFO m_GenInfo;
   D3DK::CMiniport::DACINFO m_DacInfo;
   D3DK::CMiniport::HALINFO m_HalInfo;
   D3DK::CMiniport::VIDEOMODETIMING m_VideoModeTiming;
   unsigned long m_VideoModeDepth;
   unsigned long m_FreeInstAddr;
   _HAL_SHUTDOWN_REGISTRATION m_ShutdownRegistration;
   D3DK::CMiniport::VBLANKFLIPS m_VBlankFlips[5];
   unsigned long m_VBlankFlipNext;
   unsigned long m_VBlankQueueNext;
   void * m_pVerticalBlankCallback;
   _KEVENT m_VerticalBlankEvent;
   _KEVENT m_BusyBlockEvent;
   unsigned long m_CurrentAvInfo;
   int m_FirstFlip;
   volatile unsigned long m_VBlankFlipCount;
   _D3DGAMMARAMP m_GammaRamp[2];
   int m_GammaUpdated[2];
   unsigned long m_GammaCurrentIndex;
   volatile unsigned long m_VBlankCount;
   unsigned long m_OverlayVBlank;
   unsigned long m_DebugRegister[11];
   unsigned long m_PusherGetRunSize;
   union {
   (type???) public: int __thiscall D3DK::CMiniport::InitHardware(void);
   (type???) GetPresentFlagsFromAvInfo;
   (type???) public: static unsigned long __stdcall D3DK::CMiniport::GetDisplayCapabilities(void);
   (type???) public: void __thiscall D3DK::CMiniport::SetVideoMode(unsigned long,unsigned long,unsigned long,unsigned long,enum _D3DFORMAT,unsigned long,unsigned long);
   (type???) public: int __thiscall D3DK::CMiniport::InitDMAChannel(unsigned long,struct D3DK::CMiniport::OBJECTINFO *,struct D3DK::CMiniport::OBJECTINFO *,unsigned long,void * *);
   (type???) public: int __thiscall D3DK::CMiniport::BindToChannel(struct D3DK::CMiniport::OBJECTINFO *);
   (type???) public: int __thiscall D3DK::CMiniport::CreateGrObject(unsigned long,unsigned long,struct D3DK::CMiniport::OBJECTINFO *);
   (type???) public: int __thiscall D3DK::CMiniport::CreateCtxDmaObject(unsigned long,unsigned long,void *,unsigned long,struct D3DK::CMiniport::OBJECTINFO *);
   (type???) public: unsigned long __thiscall D3DK::CMiniport::SetDmaRange(unsigned long,struct D3DSurface *);
   (type???) public: int __thiscall D3DK::CMiniport::CreateTile(unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long);
   (type???) public: int __thiscall D3DK::CMiniport::DestroyTile(unsigned long,unsigned long);
   (type???) public: void __thiscall D3DK::CMiniport::ShutdownEngines(void);
   (type???) public: void __thiscall D3DK::CMiniport::DacProgramGammaRamp(struct _D3DGAMMARAMP *);
   (type???) public: int __thiscall D3DK::CMiniport::IsFlipPending(void);
   (type???) public: void __thiscall D3DK::CMiniport::DacProgramVideoStart(unsigned long);
   (type???) DisableInterrupts;
   (type???) EnableInterrupts;
   (type???) GetRefreshRate;
   (type???) public: static unsigned char __stdcall D3DK::CMiniport::Isr(struct _KINTERRUPT *,void *);
   (type???) public: static void __stdcall D3DK::CMiniport::Dpc(struct _KDPC *,void *,void *,void *);
   (type???) public: static void __stdcall D3DK::CMiniport::ShutdownNotification(struct _HAL_SHUTDOWN_REGISTRATION *);
   (type???) public: void __thiscall D3DK::CMiniport::TilingUpdateIdle(unsigned long *);
   (type???) public: void __thiscall D3DK::CMiniport::FixupPushBuffer(struct D3DK::CMiniport::PUSHBUFFERFIXUPINFO *,unsigned long);
   (type???) private: int __thiscall D3DK::CMiniport::InitEngines(void);
   (type???) private: int __thiscall D3DK::CMiniport::LoadEngines(void);
   (type???) private: int __thiscall D3DK::CMiniport::MapRegisters(void);
   (type???) private: int __thiscall D3DK::CMiniport::GetGeneralInfo(void);
   (type???) private: void __thiscall D3DK::CMiniport::InitGammaRamp(unsigned long);
   (type???) private: void __thiscall D3DK::CMiniport::SoftwareMethod(unsigned long,unsigned long);
   (type???) SetupPaletteAndGamma;
   (type???) private: unsigned long __thiscall D3DK::CMiniport::ReserveInstMem(unsigned long);
   (type???) private: void __thiscall D3DK::CMiniport::GetAddressInfo(void *,void * *,unsigned long *,int);
   (type???) private: unsigned long __thiscall D3DK::CMiniport::ServiceGrInterrupt(void);
   (type???) private: unsigned long __thiscall D3DK::CMiniport::VBlank(void);
   (type???) private: unsigned long __thiscall D3DK::CMiniport::ServiceFifoInterrupt(void);
   (type???) ServiceMediaPortInterrupt;
   (type???) ServiceVideoInterrupt;
   (type???) private: void __thiscall D3DK::CMiniport::HalMcControlInit(void);
   (type???) private: void __thiscall D3DK::CMiniport::HalFbControlInit(void);
   (type???) private: void __thiscall D3DK::CMiniport::HalVideoControlInit(void);
   (type???) HalMpControlInit;
   (type???) private: void __thiscall D3DK::CMiniport::HalGrControlInit(void);
   (type???) private: void __thiscall D3DK::CMiniport::HalGrControlLoad(void);
   (type???) private: void __thiscall D3DK::CMiniport::HalGrIdle(void);
   (type???) private: void __thiscall D3DK::CMiniport::HalGrLoadChannelContext(unsigned long);
   (type???) private: void __thiscall D3DK::CMiniport::HalGrUnloadChannelContext(unsigned long);
   (type???) private: void __thiscall D3DK::CMiniport::HalGrInitObjectContext(unsigned long,unsigned long);
   (type???) private: void __thiscall D3DK::CMiniport::HalGrInit3d(void);
   (type???) private: void __thiscall D3DK::CMiniport::HalFifoControlInit(void);
   (type???) private: void __thiscall D3DK::CMiniport::HalFifoControlLoad(void);
   (type???) private: void __thiscall D3DK::CMiniport::HalFifoContextSwitch(unsigned long);
   (type???) private: void __thiscall D3DK::CMiniport::HalFifoAllocDMA(unsigned long,unsigned long,unsigned long,struct D3DK::CMiniport::OBJECTINFO *);
   (type???) private: void __thiscall D3DK::CMiniport::HalFifoHashAdd(unsigned long,unsigned long,unsigned long,unsigned long,unsigned long);
   (type???) private: void __thiscall D3DK::CMiniport::HalDacControlInit(void);
   (type???) private: void __thiscall D3DK::CMiniport::HalDacLoad(void);
   (type???) HalDacUnload;
   (type???) HalDacProgramMClk;
   (type???) HalDacProgramNVClk;
   (type???) HalDacProgramPClk;
   (type???) private: void __thiscall D3DK::CMiniport::DumpClocks(void);
   (type???) GrDone;
   (type???) TmrDelay;
   (type???) UnlockCRTC;
   (type???) RestoreCRTCLock;
   (type???) ReadCRTCLock;
   (type???) IsOddField;
   };
} D3DK::CMiniport;

typedef struct _D3DRECT
{
   long x1;
   long y1;
   long x2;
   long y2;
} D3DRECT;

typedef struct D3DK::Light
{
   _D3DLIGHT8 Light8;
   unsigned long Flags;
   _D3DVECTOR Direction;
   float Falloff_L;
   float Falloff_M;
   float Falloff_N;
   float Scale;
   float W;
   D3DK::Light * pNext;
} D3DK::Light;

typedef struct D3DK::VertexShaderSlot
{
   unsigned long StreamIndex;
   unsigned long Offset;
   unsigned long SizeAndType;
   unsigned char Flags;
   unsigned char Source;
} D3DK::VertexShaderSlot;

typedef struct D3DK::VertexShader
{
   unsigned long Signature;
   unsigned long RefCount;
   unsigned long Flags;
   unsigned long MaxSlot;
   unsigned long TextureCount;
   unsigned long ProgramSize;
   unsigned long ProgramAndConstantsDwords;
   unsigned long Dimensionality[4];
   D3DK::VertexShaderSlot Slot[20];
   unsigned long ProgramAndConstants[1];
} D3DK::VertexShader;

typedef struct D3DK::FenceEncoding
{
   unsigned long m_SemaphoreCommand;
   unsigned long m_Time;
   unsigned long m_SetColorClearCommand1;
   unsigned long m_SetColorClearArgument1;
   unsigned long m_SetColorClearCommand2;
   unsigned long m_SetColorClearArgument2;
   unsigned long m_WaitForIdleCommand;
   unsigned long m_WaitForIdleArgument;
   unsigned long m_NoOperationCommand;
   unsigned long m_FenceCommand;
} D3DK::FenceEncoding;

typedef struct D3DK::Fence
{
   unsigned long Time;
   D3DK::FenceEncoding * pEncoding;
   unsigned long Distance;
} D3DK::Fence;

typedef struct D3DK::_FieldDescription
{
   unsigned long Method;
   char * MethodName;
   unsigned long ReplicationCount[2];
   unsigned long ReplicationStride[2];
   char * FieldName;
   unsigned long FieldHighBit;
   unsigned long FieldLowBit;
   char FieldType;
} D3DK::_FieldDescription;

typedef struct D3DK::_D3DOVERRIDERENDERSTATE
{
   int Override;
   unsigned long Value;
} D3DK::_D3DOVERRIDERENDERSTATE;

typedef struct D3DK::InlineAttributeData
{
   unsigned long UP_Count;
   unsigned long UP_Delta;
} D3DK::InlineAttributeData;

typedef union D3DK::_HWREG
{
   volatile unsigned long Reg032[1];
} D3DK::_HWREG;

typedef struct D3DK::PixelShader
{
   unsigned long Signature;
   unsigned long RefCount;
   unsigned long D3DOwned;
   _D3DPixelShaderDef * pPSDef;
} D3DK::PixelShader;

typedef struct _DSFX_I3DL2REVERB_PARAMS
{
   _DSFX_I3DL2REVERB_STATE State;
   _DSFX_I3DL2REVERB_DELAYLINE DelayLines[14];
   unsigned long dwReflectionsInputDelay[5];
   unsigned long dwShortReverbInputDelay;
   unsigned long dwLongReverbInputDelay[8];
   unsigned long dwReflectionsFeedbackDelay[4];
   unsigned long dwLongReverbFeedbackDelay;
   unsigned long dwShortReverbInputGain[8];
   unsigned long dwLongReverbInputGain;
   unsigned long dwLongReverbCrossfeedGain;
   unsigned long dwReflectionsOutputGain[4];
   unsigned long dwShortReverbOutputGain;
   unsigned long dwLongReverbOutputGain;
   unsigned long dwChannelCount;
   _DSFX_I3DL2REVERB_IIR IIR[10];
} DSFX_I3DL2REVERB_PARAMS;

typedef struct _KSWITCHFRAME
{
   unsigned long ExceptionList;
   unsigned long Eflags;
   unsigned long RetAddr;
} KSWITCHFRAME;

typedef struct _FILE_COMPRESSION_INFORMATION
{
   _LARGE_INTEGER CompressedFileSize;
   short CompressionFormat;
   unsigned char CompressionUnitShift;
   unsigned char ChunkShift;
   unsigned char ClusterShift;
   unsigned char Reserved[3];
} FILE_COMPRESSION_INFORMATION;

typedef struct D3DXMATERIAL
{
   _D3DMATERIAL8 MatD3D;
   char * pTextureFilename;
} D3DXMATERIAL;

typedef struct IStream
{
   union {
   (type???) ISequentialStream;
   (type???) Seek;
   (type???) SetSize;
   (type???) CopyTo;
   (type???) Commit;
   (type???) Revert;
   (type???) LockRegion;
   (type???) UnlockRegion;
   (type???) Stat;
   (type???) Clone;
   (type???) IStream;
   (type???) IStream;
   };
} IStream;

typedef struct _SE_IMPERSONATION_STATE
{
   void * Token;
   unsigned char CopyOnOpen;
   unsigned char EffectiveOnly;
   unsigned char Padding3;
   unsigned char Padding4;
   int Level;
} SE_IMPERSONATION_STATE;

typedef struct _DS3DLISTENER
{
   unsigned long dwSize;
   D3DXVECTOR3 vPosition;
   D3DXVECTOR3 vVelocity;
   D3DXVECTOR3 vOrientFront;
   D3DXVECTOR3 vOrientTop;
   float flDistanceFactor;
   float flRolloffFactor;
   float flDopplerFactor;
   (type???) public: __thiscall _DS3DLISTENER::_DS3DLISTENER(void);
} DS3DLISTENER;

typedef struct _IMAGE_TLS_DIRECTORY64
{
   __int64 StartAddressOfRawData;
   __int64 EndAddressOfRawData;
   __int64 AddressOfIndex;
   __int64 AddressOfCallBacks;
   unsigned long SizeOfZeroFill;
   unsigned long Characteristics;
} IMAGE_TLS_DIRECTORY64;

typedef struct _iobuf
{
   char * _ptr;
   int _cnt;
   char * _base;
   int _flag;
   int _file;
   int _charbuf;
   int _bufsiz;
   char * _tmpfname;
} iobuf;

typedef struct _IMAGE_NT_HEADERS64
{
   unsigned long Signature;
   _IMAGE_FILE_HEADER FileHeader;
   _IMAGE_OPTIONAL_HEADER64 OptionalHeader;
} IMAGE_NT_HEADERS64;

typedef struct _ldiv_t
{
   long quot;
   long rem;
} ldiv_t;

typedef struct _D3DMATERIAL8
{
   _D3DCOLORVALUE Diffuse;
   _D3DCOLORVALUE Ambient;
   _D3DCOLORVALUE Specular;
   _D3DCOLORVALUE Emissive;
   float Power;
} D3DMATERIAL8;

typedef struct AUDIO_ALLOC_MEMORY
{
   unsigned long uSize;
   unsigned long uAlignMask;
   unsigned long pLinearAddress;
   unsigned long uRef;
} AUDIO_ALLOC_MEMORY;

typedef struct _CM_SONIC_DEVICE_DATA
{
   short Version;
   short Revision;
   short DataConfigurationRegister;
   unsigned char EthernetAddress[8];
} CM_SONIC_DEVICE_DATA;

typedef union _KGDTENTRY::__unnamed
{
   union {
   _KGDTENTRY::__unnamed::__unnamed Bytes;
   _KGDTENTRY::__unnamed::__unnamed Bits;
   };
} KGDTENTRY::__unnamed;

typedef struct _KGDTENTRY::__unnamed::__unnamed
{
   unsigned char BaseMid;
   unsigned char Flags1;
   unsigned char Flags2;
   unsigned char BaseHi;
} KGDTENTRY::__unnamed::__unnamed;

typedef struct _UNICODE_PREFIX_TABLE
{
   short NodeTypeCode;
   short NameLength;
   _UNICODE_PREFIX_TABLE_ENTRY * NextPrefixTree;
   _UNICODE_PREFIX_TABLE_ENTRY * LastNextEntry;
} UNICODE_PREFIX_TABLE;

typedef struct _IMAGE_RESOURCE_DIRECTORY
{
   unsigned long Characteristics;
   unsigned long TimeDateStamp;
   short MajorVersion;
   short MinorVersion;
   short NumberOfNamedEntries;
   short NumberOfIdEntries;
} IMAGE_RESOURCE_DIRECTORY;

typedef struct _IO_RESOURCE_REQUIREMENTS_LIST
{
   unsigned long ListSize;
   int InterfaceType;
   unsigned long BusNumber;
   unsigned long SlotNumber;
   unsigned long Reserved[3];
   unsigned long AlternativeLists;
   _IO_RESOURCE_LIST List[1];
} IO_RESOURCE_REQUIREMENTS_LIST;

typedef struct _TIMER_BASIC_INFORMATION
{
   _LARGE_INTEGER RemainingTime;
   unsigned char TimerState;
} TIMER_BASIC_INFORMATION;

typedef struct _FILE_NOTIFY_INFORMATION
{
   unsigned long NextEntryOffset;
   unsigned long Action;
   unsigned long FileNameLength;
   char FileName[1];
} FILE_NOTIFY_INFORMATION;

typedef struct _TOKEN_GROUPS
{
   unsigned long GroupCount;
   _SID_AND_ATTRIBUTES Groups[1];
} TOKEN_GROUPS;

typedef union _IMAGE_SECTION_HEADER::__unnamed
{
   union {
   unsigned long PhysicalAddress;
   unsigned long VirtualSize;
   };
} IMAGE_SECTION_HEADER::__unnamed;

typedef struct XNKEY
{
   unsigned char ab[16];
} XNKEY;

typedef struct _CM_PCCARD_DEVICE_DATA
{
   unsigned char Flags;
   unsigned char ErrorCode;
   short Reserved;
   unsigned long BusData;
   unsigned long DeviceId;
   unsigned long LegacyBaseAddress;
   unsigned char IRQMap[16];
} CM_PCCARD_DEVICE_DATA;

typedef struct _KEY_NODE_INFORMATION
{
   _LARGE_INTEGER LastWriteTime;
   unsigned long TitleIndex;
   unsigned long ClassOffset;
   unsigned long ClassLength;
   unsigned long NameLength;
   short Name[1];
} KEY_NODE_INFORMATION;

typedef struct NvS64
{
   unsigned long low;
   long high;
} NvS64;

typedef struct _PROCESS_BASIC_INFORMATION
{
   long ExitStatus;
   _PEB * PebBaseAddress;
   unsigned long AffinityMask;
   long BasePriority;
   unsigned long UniqueProcessId;
   unsigned long InheritedFromUniqueProcessId;
} PROCESS_BASIC_INFORMATION;

typedef struct NvGraphicsState
{
   NvGraphicsState::_PerFragmentState PerFragmentState;
   NvGraphicsState::_PerVertexState PerVertexState;
   NvGraphicsState::_VertexArrayState VertexArrayState;
   NvGraphicsState::_PrimitiveAssmState PrimitiveAssmState;
} NvGraphicsState;

typedef struct NvGraphicsState::_PrimitiveAssmState
{
   unsigned long primAssm[48];
} NvGraphicsState::_PrimitiveAssmState;

typedef struct NvGraphicsState::_VertexArrayState
{
   unsigned long vertexOffset;
   unsigned long vertexFormat;
   unsigned long diffuseOffset;
   unsigned long diffuseFormat;
   unsigned long specularOffset;
   unsigned long specularFormat;
   unsigned long texCoord0Offset;
   unsigned long texCoord0Format;
   unsigned long texCoord1Offset;
   unsigned long texCoord1Format;
   unsigned long normalOffset;
   unsigned long normalFormat;
   unsigned long weightOffset;
   unsigned long weightFormat;
   unsigned long fogOffset;
   unsigned long fogFormat;
} NvGraphicsState::_VertexArrayState;

typedef struct NvGraphicsState::_PerVertexState
{
   float pad0[4];
   float primaryColor[4];
   float secondaryColor[3];
   float fogCoord;
   float texCoord[4] texCoord[2];
   unsigned long Padding5;
   unsigned long Padding6;
   unsigned long Padding7;
   unsigned long Padding8;
   unsigned long Padding9;
   unsigned long Padding10;
   float normal[3];
   float pad1;
   float vertexWeight;
   unsigned long pad2[7];
   unsigned long pad3;
   union {
   unsigned long edgeFlag;
   unsigned long pad4;
   };
   unsigned long pad5[2];
} NvGraphicsState::_PerVertexState;

typedef struct NvGraphicsState::_PerFragmentState
{
   union {
   unsigned long pad0;
   unsigned long alphaFunc;
   unsigned long pad1;
   unsigned long depthFunc;
   unsigned long pad2;
   unsigned long depthMask;
   unsigned long pad3;
   unsigned long alphaMask;
   unsigned long redMask;
   unsigned long greenMask;
   unsigned long blueMask;
   unsigned long pad4;
   };
   union {
   unsigned long pad5;
   unsigned long stencilFunc;
   unsigned long stencilRef;
   unsigned long pad6;
   unsigned long stencilMask;
   };
   union {
   unsigned long sfailOp;
   unsigned long zfailOp;
   unsigned long zpassOp;
   unsigned long pad7;
   };
   union {
   unsigned long blendEquation;
   unsigned long pad8;
   unsigned long srcBlend;
   unsigned long destBlend;
   unsigned long pad9;
   };
} NvGraphicsState::_PerFragmentState;

typedef struct _DSFX_I3DL2REVERB_DELAYLINE
{
   unsigned long dwBase;
   unsigned long dwLength;
} DSFX_I3DL2REVERB_DELAYLINE;

typedef struct _LD_FROM_DASHBOARD
{
   unsigned long dwContext;
   unsigned char Reserved[3068];
} LD_FROM_DASHBOARD;

typedef struct HCOLORSPACE__
{
   int unused;
} HCOLORSPACE__;

typedef struct _SYSTEM_REGISTRY_QUOTA_INFORMATION
{
   unsigned long RegistryQuotaAllowed;
   unsigned long RegistryQuotaUsed;
   unsigned long PagedPoolSize;
} SYSTEM_REGISTRY_QUOTA_INFORMATION;

typedef struct _SECURITY_ADVANCED_QUALITY_OF_SERVICE
{
   unsigned long Length;
   int ImpersonationLevel;
   unsigned char ContextTrackingMode;
   unsigned char EffectiveOnly;
   unsigned char Padding4;
   unsigned char Padding5;
   _SECURITY_TOKEN_PROXY_DATA * ProxyData;
   _SECURITY_TOKEN_AUDIT_DATA * AuditData;
} SECURITY_ADVANCED_QUALITY_OF_SERVICE;

typedef struct _DBGKD_CONTROL_REPORT
{
   unsigned long Dr6;
   unsigned long Dr7;
   short InstructionCount;
   short ReportFlags;
   unsigned char InstructionStream[16];
   short SegCs;
   short SegDs;
   short SegEs;
   short SegFs;
   unsigned long EFlags;
} DBGKD_CONTROL_REPORT;

typedef struct _D3DPixelShaderDefFile
{
   unsigned long FileID;
   _D3DPixelShaderDef Psd;
} D3DPixelShaderDefFile;

typedef struct _D3DPixelShaderDef
{
   unsigned long PSAlphaInputs[8];
   unsigned long PSFinalCombinerInputsABCD;
   unsigned long PSFinalCombinerInputsEFG;
   unsigned long PSConstant0[8];
   unsigned long PSConstant1[8];
   unsigned long PSAlphaOutputs[8];
   unsigned long PSRGBInputs[8];
   unsigned long PSCompareMode;
   unsigned long PSFinalCombinerConstant0;
   unsigned long PSFinalCombinerConstant1;
   unsigned long PSRGBOutputs[8];
   unsigned long PSCombinerCount;
   unsigned long PSTextureModes;
   unsigned long PSDotMapping;
   unsigned long PSInputTexture;
   unsigned long PSC0Mapping;
   unsigned long PSC1Mapping;
   unsigned long PSFinalCombinerConstants;
} D3DPixelShaderDef;

typedef union _IRP::__unnamed
{
   union {
   _IRP::__unnamed::__unnamed AsynchronousParameters;
   _LARGE_INTEGER AllocationSize;
   };
} IRP::__unnamed;

typedef struct _IRP::__unnamed::__unnamed
{
   void * UserApcRoutine;
   void * UserApcContext;
} IRP::__unnamed::__unnamed;

typedef struct _DSFX_CHORUS_MONO_PARAMS
{
   _DSFX_CHORUS_MONO_STATE State;
   unsigned long dwGain;
   unsigned long dwModScale;
} DSFX_CHORUS_MONO_PARAMS;

typedef struct _D3DRASTER_STATUS
{
   int InVBlank;
   int ScanLine;
} D3DRASTER_STATUS;

typedef struct _SYSTEM_AUDIT_OBJECT_ACE
{
   _ACE_HEADER Header;
   unsigned long Mask;
   unsigned long Flags;
   _GUID ObjectType;
   _GUID InheritedObjectType;
   unsigned long SidStart;
} SYSTEM_AUDIT_OBJECT_ACE;

typedef struct _FILE_FS_SIZE_INFORMATION
{
   _LARGE_INTEGER TotalAllocationUnits;
   _LARGE_INTEGER AvailableAllocationUnits;
   unsigned long SectorsPerAllocationUnit;
   unsigned long BytesPerSector;
} FILE_FS_SIZE_INFORMATION;

typedef struct _SYSTEM_OBJECT_INFORMATION
{
   unsigned long NextEntryOffset;
   void * Object;
   void * CreatorUniqueProcess;
   short CreatorBackTraceIndex;
   short Flags;
   long PointerCount;
   long HandleCount;
   unsigned long PagedPoolCharge;
   unsigned long NonPagedPoolCharge;
   void * ExclusiveProcessId;
   void * SecurityDescriptor;
   _OBJECT_NAME_INFORMATION NameInfo;
} SYSTEM_OBJECT_INFORMATION;

typedef struct _exception
{
   int type;
   char * name;
   double arg1;
   double arg2;
   double retval;
} exception;

typedef struct _RTL_TIME_ZONE_INFORMATION
{
   long Bias;
   short StandardName[32];
   _TIME_FIELDS StandardStart;
   long StandardBias;
   short DaylightName[32];
   _TIME_FIELDS DaylightStart;
   long DaylightBias;
} RTL_TIME_ZONE_INFORMATION;

typedef struct _SYSTEM_AUDIT_ACE
{
   _ACE_HEADER Header;
   unsigned long Mask;
   unsigned long SidStart;
} SYSTEM_AUDIT_ACE;

typedef struct _complex
{
   double x;
   double y;
} complex;

typedef struct BATTERY_REPORTING_SCALE
{
   unsigned long Granularity;
   unsigned long Capacity;
} BATTERY_REPORTING_SCALE;

typedef struct _CM_SCSI_DEVICE_DATA
{
   short Version;
   short Revision;
   unsigned char HostIdentifier;
} CM_SCSI_DEVICE_DATA;

typedef struct _POOLED_USAGE_AND_LIMITS
{
   unsigned long PeakPagedPoolUsage;
   unsigned long PagedPoolUsage;
   unsigned long PagedPoolLimit;
   unsigned long PeakNonPagedPoolUsage;
   unsigned long NonPagedPoolUsage;
   unsigned long NonPagedPoolLimit;
   unsigned long PeakPagefileUsage;
   unsigned long PagefileUsage;
   unsigned long PagefileLimit;
} POOLED_USAGE_AND_LIMITS;

typedef struct _IMAGE_RESOURCE_DIR_STRING_U
{
   short Length;
   short NameString[1];
} IMAGE_RESOURCE_DIR_STRING_U;

typedef struct D3DVolumeTexture
{
   union {
   (type???) D3DBaseTexture;
   (type???) GetLevelDesc;
   (type???) GetVolumeLevel;
   (type???) LockBox;
   (type???) UnlockBox;
   };
} D3DVolumeTexture;

typedef struct _SYSTEM_POWER_POLICY
{
   unsigned long Revision;
   POWER_ACTION_POLICY PowerButton;
   POWER_ACTION_POLICY SleepButton;
   POWER_ACTION_POLICY LidClose;
   int LidOpenWake;
   unsigned long Reserved;
   POWER_ACTION_POLICY Idle;
   unsigned long IdleTimeout;
   unsigned char IdleSensitivity;
   unsigned char Spare2[3];
   int MinSleep;
   int MaxSleep;
   int ReducedLatencySleep;
   unsigned long WinLogonFlags;
   unsigned long Spare3;
   unsigned long DozeS4Timeout;
   unsigned long BroadcastCapacityResolution;
   SYSTEM_POWER_LEVEL DischargePolicy[4];
   unsigned long VideoTimeout;
   unsigned char VideoDimDisplay;
   unsigned char Padding20;
   unsigned char Padding21;
   unsigned char Padding22;
   unsigned long VideoReserved[3];
   unsigned long SpindownTimeout;
   unsigned char OptimizeForPower;
   unsigned char FanThrottleTolerance;
   unsigned char ForcedThrottle;
   unsigned char MinThrottle;
   POWER_ACTION_POLICY OverThrottled;
} SYSTEM_POWER_POLICY;

typedef struct ID3DXSprite
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) GetDevice;
   (type???) Begin;
   (type???) Draw;
   (type???) DrawTransform;
   (type???) End;
   (type???) ID3DXSprite;
   (type???) ID3DXSprite;
   };
} ID3DXSprite;

typedef struct _s__ThrowInfo
{
   int attributes;
   void * pmfnUnwind;
   void * pForwardCompat;
   const _s__CatchableTypeArray * pCatchableTypeArray;
} s__ThrowInfo;

typedef struct _DSFX_MINIREVERB_PARAMS
{
   _DSFX_MINIREVERB_STATE State;
   unsigned long dwDelayLineLengths[8];
   unsigned long dwReflectionTaps[8];
   unsigned long dwReflectionGains[8];
   unsigned long dwInputIIRCoefficients[2];
   unsigned long dwInputIIRDelay;
   unsigned long dwOutputIIRCoefficients[2];
   unsigned long dwOutputIIRDelay;
} DSFX_MINIREVERB_PARAMS;

typedef struct _DESCRIPTOR_TABLE_ENTRY
{
   unsigned long Selector;
   _LDT_ENTRY Descriptor;
} DESCRIPTOR_TABLE_ENTRY;

typedef struct ID3DXSkinMesh
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) GetNumFaces;
   (type???) GetNumVertices;
   (type???) GetFVF;
   (type???) GetDeclaration;
   (type???) GetOptions;
   (type???) GetDevice;
   (type???) GetVertexBuffer;
   (type???) GetIndexBuffer;
   (type???) LockVertexBuffer;
   (type???) UnlockVertexBuffer;
   (type???) LockIndexBuffer;
   (type???) UnlockIndexBuffer;
   (type???) LockAttributeBuffer;
   (type???) UnlockAttributeBuffer;
   (type???) GetNumBones;
   (type???) GetOriginalMesh;
   (type???) SetBoneInfluence;
   (type???) GetNumBoneInfluences;
   (type???) GetBoneInfluence;
   (type???) GetMaxVertexInfluences;
   (type???) GetMaxFaceInfluences;
   (type???) ConvertToBlendedMesh;
   (type???) ConvertToIndexedBlendedMesh;
   (type???) GenerateSkinnedMesh;
   (type???) UpdateSkinnedMesh;
   (type???) ID3DXSkinMesh;
   (type???) ID3DXSkinMesh;
   };
} ID3DXSkinMesh;

typedef struct _SYSTEM_DEVICE_INFORMATION
{
   unsigned long NumberOfDisks;
   unsigned long NumberOfFloppies;
   unsigned long NumberOfCdRoms;
   unsigned long NumberOfTapes;
   unsigned long NumberOfSerialPorts;
   unsigned long NumberOfParallelPorts;
} SYSTEM_DEVICE_INFORMATION;

typedef struct _RTL_HEAP_WALK_ENTRY
{
   void * DataAddress;
   unsigned long DataSize;
   unsigned char OverheadBytes;
   unsigned char SegmentIndex;
   short Flags;
   union {
   _RTL_HEAP_WALK_ENTRY::__unnamed::__unnamed Block;
   _RTL_HEAP_WALK_ENTRY::__unnamed::__unnamed Segment;
   };
} RTL_HEAP_WALK_ENTRY;

typedef struct _RTL_HEAP_WALK_ENTRY::__unnamed::__unnamed
{
   unsigned long Settable;
   short TagIndex;
   short AllocatorBackTraceIndex;
   unsigned long Reserved[2];
} RTL_HEAP_WALK_ENTRY::__unnamed::__unnamed;

typedef struct _DSFILTERDESC
{
   unsigned long dwMode;
   unsigned long dwQCoefficient;
   unsigned long adwCoefficients[4];
} DSFILTERDESC;

typedef struct _PROCESS_SESSION_INFORMATION
{
   unsigned long SessionId;
} PROCESS_SESSION_INFORMATION;

typedef struct _FILE_TRACKING_INFORMATION
{
   void * DestinationFile;
   unsigned long ObjectInformationLength;
   char ObjectInformation[1];
} FILE_TRACKING_INFORMATION;

typedef struct UNNAMED_TAG_1D7FE85
{
   unsigned long size;
   unsigned long monochrome[63];
} UNNAMED_TAG_1D7FE85;

typedef struct _CSTRING
{
   short Length;
   short MaximumLength;
   const char * Buffer;
} CSTRING;

typedef struct _D3DGAMMARAMP
{
   unsigned char red[256];
   unsigned char green[256];
   unsigned char blue[256];
} D3DGAMMARAMP;

typedef struct _FPO_DATA
{
   unsigned long ulOffStart;
   unsigned long cbProcSize;
   unsigned long cdwLocals;
   short cdwParams;
   union {
   short cbProlog;
   short cbRegs;
   short fHasSEH;
   short fUseBP;
   short reserved;
   short cbFrame;
   };
} FPO_DATA;

typedef struct _DSENVELOPEDESC
{
   unsigned long dwEG;
   unsigned long dwMode;
   unsigned long dwDelay;
   unsigned long dwAttack;
   unsigned long dwHold;
   unsigned long dwDecay;
   unsigned long dwRelease;
   unsigned long dwSustain;
   long lPitchScale;
   long lFilterCutOff;
} DSENVELOPEDESC;

typedef struct _DSFX_AMPMOD_MONO_PARAMS
{
   _DSFX_AMPMOD_MONO_STATE State;
} DSFX_AMPMOD_MONO_PARAMS;

typedef struct _KTRAP_FRAME
{
   unsigned long DbgEbp;
   unsigned long DbgEip;
   unsigned long DbgArgMark;
   unsigned long DbgArgPointer;
   unsigned long TempSegCs;
   unsigned long TempEsp;
   unsigned long Edx;
   unsigned long Ecx;
   unsigned long Eax;
   _EXCEPTION_REGISTRATION_RECORD * ExceptionList;
   unsigned long Edi;
   unsigned long Esi;
   unsigned long Ebx;
   unsigned long Ebp;
   unsigned long ErrCode;
   unsigned long Eip;
   unsigned long SegCs;
   unsigned long EFlags;
   unsigned long HardwareEsp;
   unsigned long HardwareSegSs;
} KTRAP_FRAME;

typedef struct _DXFILELOADRESOURCE
{
   HINSTANCE__ * hModule;
   const short * lpName;
   const short * lpType;
} DXFILELOADRESOURCE;

typedef struct HINSTANCE__
{
   int unused;
} HINSTANCE__;

typedef struct _LAST_EXCEPTION_LOG
{
   _EXCEPTION_RECORD ExceptionRecord;
   _CONTEXT ContextRecord;
   unsigned long ControlPc;
   int Disposition;
   unsigned long HandlerData[5];
} LAST_EXCEPTION_LOG;

typedef struct IPersist
{
   union {
   (type???) IUnknown;
   (type???) GetClassID;
   (type???) IPersist;
   (type???) IPersist;
   };
} IPersist;

typedef struct _SYSTEM_POWER_INFORMATION
{
   unsigned long MaxIdlenessAllowed;
   unsigned long Idleness;
   unsigned long TimeRemaining;
   unsigned char CoolingMode;
} SYSTEM_POWER_INFORMATION;

typedef struct _D3DXPASS_DESC
{
   unsigned long Name;
} D3DXPASS_DESC;

typedef struct NVDE_TEST_PARAMETERS
{
   unsigned long CallBackAddress;
} NVDE_TEST_PARAMETERS;

typedef struct _FILE_PIPE_INFORMATION
{
   unsigned long ReadMode;
   unsigned long CompletionMode;
} FILE_PIPE_INFORMATION;

typedef struct _CM_ROM_BLOCK
{
   unsigned long Address;
   unsigned long Size;
} CM_ROM_BLOCK;

typedef struct _DSCAPS
{
   unsigned long dwFree2DBuffers;
   unsigned long dwFree3DBuffers;
   unsigned long dwFreeBufferSGEs;
   unsigned long dwMemoryAllocated;
} DSCAPS;

typedef struct _IMAGE_DOS_HEADER
{
   short e_magic;
   short e_cblp;
   short e_cp;
   short e_crlc;
   short e_cparhdr;
   short e_minalloc;
   short e_maxalloc;
   short e_ss;
   short e_sp;
   short e_csum;
   short e_ip;
   short e_cs;
   short e_lfarlc;
   short e_ovno;
   short e_res[4];
   short e_oemid;
   short e_oeminfo;
   short e_res2[10];
   long e_lfanew;
} IMAGE_DOS_HEADER;

typedef struct _ACCESS_DENIED_OBJECT_ACE
{
   _ACE_HEADER Header;
   unsigned long Mask;
   unsigned long Flags;
   _GUID ObjectType;
   _GUID InheritedObjectType;
   unsigned long SidStart;
} ACCESS_DENIED_OBJECT_ACE;

typedef struct _FILE_ALL_INFORMATION
{
   _FILE_BASIC_INFORMATION BasicInformation;
   _FILE_STANDARD_INFORMATION StandardInformation;
   _FILE_INTERNAL_INFORMATION InternalInformation;
   _FILE_EA_INFORMATION EaInformation;
   _FILE_ACCESS_INFORMATION AccessInformation;
   _FILE_POSITION_INFORMATION PositionInformation;
   _FILE_MODE_INFORMATION ModeInformation;
   _FILE_ALIGNMENT_INFORMATION AlignmentInformation;
   _FILE_NAME_INFORMATION NameInformation;
} FILE_ALL_INFORMATION;

typedef struct _FILE_NAME_INFORMATION
{
   unsigned long FileNameLength;
   char FileName[1];
} FILE_NAME_INFORMATION;

typedef struct _FILE_POSITION_INFORMATION
{
   _LARGE_INTEGER CurrentByteOffset;
} FILE_POSITION_INFORMATION;

typedef struct _FILE_INTERNAL_INFORMATION
{
   _LARGE_INTEGER IndexNumber;
} FILE_INTERNAL_INFORMATION;

typedef struct _FILE_STANDARD_INFORMATION
{
   _LARGE_INTEGER AllocationSize;
   _LARGE_INTEGER EndOfFile;
   unsigned long NumberOfLinks;
   unsigned char DeletePending;
   unsigned char Directory;
} FILE_STANDARD_INFORMATION;

typedef struct _FILE_BASIC_INFORMATION
{
   _LARGE_INTEGER CreationTime;
   _LARGE_INTEGER LastAccessTime;
   _LARGE_INTEGER LastWriteTime;
   _LARGE_INTEGER ChangeTime;
   unsigned long FileAttributes;
} FILE_BASIC_INFORMATION;

typedef struct _RTL_HEAP_PARAMETERS
{
   unsigned long Length;
   unsigned long SegmentReserve;
   unsigned long SegmentCommit;
   unsigned long DeCommitFreeBlockThreshold;
   unsigned long DeCommitTotalFreeThreshold;
   unsigned long MaximumAllocationSize;
   unsigned long VirtualMemoryThreshold;
   unsigned long InitialCommit;
   unsigned long InitialReserve;
   void * CommitRoutine;
   unsigned long Reserved[2];
} RTL_HEAP_PARAMETERS;

typedef struct _TOKEN_OWNER
{
   void * Owner;
} TOKEN_OWNER;

typedef struct HMETAFILE__
{
   int unused;
} HMETAFILE__;

typedef struct _SYSTEM_QUERY_TIME_ADJUST_INFORMATION
{
   unsigned long TimeAdjustment;
   unsigned long TimeIncrement;
   unsigned char Enable;
} SYSTEM_QUERY_TIME_ADJUST_INFORMATION;

typedef struct _DSFX_ECHO_MONO_PARAMS
{
   _DSFX_ECHO_MONO_STATE State;
   unsigned long dwGain;
} DSFX_ECHO_MONO_PARAMS;

typedef struct timeval
{
   long tv_sec;
   long tv_usec;
} timeval;

typedef struct _SECURITY_TOKEN_AUDIT_DATA
{
   unsigned long Length;
   unsigned long GrantMask;
   unsigned long DenyMask;
} SECURITY_TOKEN_AUDIT_DATA;

typedef struct _RTL_RANGE
{
   __int64 Start;
   __int64 End;
   void * UserData;
   void * Owner;
   unsigned char Attributes;
   unsigned char Flags;
} RTL_RANGE;

typedef struct _SYSTEM_INTERRUPT_INFORMATION
{
   unsigned long ContextSwitches;
   unsigned long DpcCount;
   unsigned long DpcRate;
   unsigned long TimeIncrement;
   unsigned long DpcBypassCount;
   unsigned long ApcBypassCount;
} SYSTEM_INTERRUPT_INFORMATION;

typedef struct Nv11CelsiusPrimitive
{
   unsigned long ctx_Switch;
   unsigned long Reserved0004[63];
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long SetWarningEnable;
   unsigned long GetState;
   unsigned long WaitForIdle;
   unsigned long Reserved0114[3];
   unsigned long SetFlipRead;
   unsigned long SetFlipWrite;
   unsigned long SetFlipModulo;
   unsigned long FlipIncrementWrite;
   unsigned long FlipStall;
   unsigned long Reserved0134[3];
   unsigned long PmTrigger;
   unsigned long Reserved0144[15];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaA;
   unsigned long SetContextDmaB;
   unsigned long SetContextDmaVertex;
   unsigned long SetContextDmaState;
   unsigned long SetContextDmaColor;
   unsigned long SetContextDmaZeta;
   unsigned long Reserved019c[25];
   unsigned long SetSurfaceClipHorizontal;
   unsigned long SetSurfaceClipVertical;
   unsigned long SetSurfaceFormat;
   unsigned long SetSurfacePitch;
   unsigned long SetSurfaceColorOffset;
   unsigned long SetSurfaceZetaOffset;
   unsigned long SetTextureOffset[2];
   unsigned long SetTextureFormat[2];
   unsigned long SetTextureControl0[2];
   unsigned long SetTextureControl1[2];
   unsigned long SetTextureControl2[2];
   unsigned long SetTextureImageRect[2];
   unsigned long SetTextureFilter[2];
   unsigned long SetTexturePalette[2];
   unsigned long Reserved0258[2];
   unsigned long SetCombinerAlphaICW[2];
   unsigned long SetCombinerColorICW[2];
   unsigned long SetCombineFactor[2];
   unsigned long SetCombinerAlphaOCW[2];
   unsigned long SetCombiner0ColorOCW;
   unsigned long SetCombiner1ColorOCW;
   unsigned long SetCombinerSpecularFogCW0;
   unsigned long SetCombinerSpecularFogCW1;
   unsigned long SetControl0;
   unsigned long SetLightControl;
   unsigned long SetColorMaterial;
   unsigned long SetFogMode;
   unsigned long SetFogGenMode;
   unsigned long SetFogEnable;
   unsigned long SetFogColor;
   unsigned long SetColorKeyColor[2];
   unsigned long SetWindowClipType;
   unsigned long Reserved02b8[2];
   unsigned long SetWindowClipHorizontal[8];
   unsigned long SetWindowClipVertical[8];
   unsigned long SetAlphaTestEnable;
   unsigned long SetBlendEnable;
   unsigned long SetCullFaceEnable;
   unsigned long SetDepthTestEnable;
   unsigned long SetDitherEnable;
   unsigned long SetLightingEnable;
   unsigned long SetPointParamsEnable;
   unsigned long SetPointSmoothEnable;
   unsigned long SetLineSmoothEnable;
   unsigned long SetPolySmoothEnable;
   unsigned long SetSkinEnable;
   unsigned long SetStencilTestEnable;
   unsigned long SetPolyOffsetPointEnable;
   unsigned long SetPolyOffsetLineEnable;
   unsigned long SetPolyOffsetFillEnable;
   unsigned long SetAlphaFunc;
   unsigned long SetAlphaRef;
   unsigned long SetBlendFuncSfactor;
   unsigned long SetBlendFuncDfactor;
   unsigned long SetBlendColor;
   unsigned long SetBlendEquation;
   unsigned long SetDepthFunc;
   unsigned long SetColorMask;
   unsigned long SetDepthMask;
   unsigned long SetStencilMask;
   unsigned long SetStencilFunc;
   unsigned long SetStencilFuncRef;
   unsigned long SetStencilFuncMask;
   unsigned long SetStencilOpFail;
   unsigned long SetStencilOpZfail;
   unsigned long SetStencilOpZpass;
   unsigned long SetShadeMode;
   unsigned long SetLineWidth;
   float SetPolygonOffsetScaleFactor;
   float SetPolygonOffsetBias;
   unsigned long SetFrontPolygonMode;
   unsigned long SetBackPolygonMode;
   float SetClipMin;
   float SetClipMax;
   unsigned long SetCullFace;
   unsigned long SetFrontFace;
   unsigned long SetNormalizationEnable;
   float SetMaterialEmission[3];
   float SetMaterialAlpha;
   unsigned long SetSpecularEnable;
   unsigned long SetLightEnableMask;
   Nv11CelsiusPrimitive::__unnamed SetTexgen[2];
   unsigned long SetTextureMatrix0Enable;
   unsigned long SetTextureMatrix1Enable;
   unsigned long SetTLMode;
   unsigned long SetPointSize;
   unsigned long SetSwathWidth;
   unsigned long SetFlatShadeOp;
   unsigned long Reserved03f8[2];
   float SetModelViewMatrix0[16];
   float SetModelViewMatrix1[16];
   float SetInverseModelViewMatrix0[16];
   float SetInverseModelViewMatrix1[16];
   float SetCompositeMatrix[16];
   float SetTextureMatrix0[16];
   float SetTextureMatrix1[16];
   unsigned long Reserved05c0[16];
   float SetTexgenSPlane0[4];
   float SetTexgenTPlane0[4];
   float SetTexgenRPlane0[4];
   float SetTexgenQPlane0[4];
   float SetTexgenSPlane1[4];
   float SetTexgenTPlane1[4];
   float SetTexgenRPlane1[4];
   float SetTexgenQPlane1[4];
   float SetFogParams[3];
   float SetFogPlane[4];
   unsigned long Reserved069c[1];
   float SetSpecularParams[6];
   unsigned long Reserved06b8[3];
   float SetSceneAmbientColor[3];
   unsigned long Reserved06d0[6];
   float SetViewportOffset[4];
   float SetPointParams[8];
   float SetEyePosition[4];
   unsigned long Flush;
   float SetEyeDirectionSW[3];
   unsigned long Reserved0738[50];
   Nv11CelsiusPrimitive::__unnamed SetLight[8];
   float SetVertex3f[3];
   unsigned long Reserved0c0c[3];
   float SetVertex4f[4];
   long SetVertex4s[2];
   float SetNormal3f[3];
   unsigned long Reserved0c3c[1];
   long SetNormal3s[2];
   unsigned long Reserved0c48[2];
   float SetDiffuseColor4f[4];
   float SetDiffuseColor3f[3];
   unsigned long SetDiffuseColor4ub;
   float SetSpecularColor4f[4];
   float SetSpecularColor3f[3];
   unsigned long SetSpecularColor4ub;
   float SetTexcoord0_2f[2];
   long SetTexcoord0_2s;
   unsigned long Reserved0c9c[1];
   float SetTexcoord0_4f[4];
   long SetTexcoord0_4s[2];
   float SetTexcoord1_2f[2];
   long SetTexcoord1_2s;
   unsigned long Reserved0cc4[1];
   float SetTexcoord1_4f[4];
   long SetTexcoord1_4s[2];
   float SetFog1f;
   float SetWeight1f;
   unsigned long Reserved0ce8[1];
   unsigned long SetEdgeFlag;
   unsigned long InvalidateVertexCacheFile;
   unsigned long InvalidateVertexFile;
   unsigned long TlNop;
   unsigned long TlSync;
   unsigned long SetVertexArrayOffset;
   unsigned long SetVertexArrayFormat;
   unsigned long SetDiffuseArrayOffset;
   unsigned long SetDiffuseArrayFormat;
   unsigned long SetSpecularArrayOffset;
   unsigned long SetSpecularArrayFormat;
   unsigned long SetTexCoord0ArrayOffset;
   unsigned long SetTexCoord0ArrayFormat;
   unsigned long SetTexCoord1ArrayOffset;
   unsigned long SetTexCoord1ArrayFormat;
   unsigned long SetNormalArrayOffset;
   unsigned long SetNormalArrayFormat;
   unsigned long SetWeightArrayOffset;
   unsigned long SetWeightArrayFormat;
   unsigned long SetFogArrayOffset;
   unsigned long SetFogArrayFormat;
   unsigned long SetLogicOpEnable;
   unsigned long SetLogicOp;
   unsigned long Reserved0d48[45];
   unsigned long SetBeginEnd;
   unsigned long ArrayElement16[128];
   unsigned long Reserved1000[63];
   unsigned long SetBeginEnd2;
   unsigned long ArrayElement32[64];
   unsigned long Reserved1200[127];
   unsigned long SetBeginEnd3;
   unsigned long DrawArrays[128];
   unsigned long DebugInit[10];
   unsigned long Reserved1628[117];
   unsigned long SetBeginEnd4;
   unsigned long InlineArray[512];
} Nv11CelsiusPrimitive;

typedef struct Nv11CelsiusPrimitive::__unnamed
{
   unsigned long S;
   unsigned long T;
   unsigned long R;
   unsigned long Q;
} Nv11CelsiusPrimitive::__unnamed;

typedef struct linger
{
   short l_onoff;
   short l_linger;
} linger;

typedef struct _SYSTEM_MEMORY_INFO
{
   unsigned char * StringOffset;
   short ValidCount;
   short TransitionCount;
   short ModifiedCount;
   short PageTableCount;
} SYSTEM_MEMORY_INFO;

typedef struct LIST_ENTRY64
{
   __int64 Flink;
   __int64 Blink;
} LIST_ENTRY64;

typedef struct _LDR_DATA_TABLE_ENTRY64
{
   LIST_ENTRY64 InLoadOrderLinks;
   LIST_ENTRY64 InMemoryOrderLinks;
   LIST_ENTRY64 InInitializationOrderLinks;
   __int64 DllBase;
   __int64 EntryPoint;
   unsigned long SizeOfImage;
   unsigned long Padding6;
   _STRING64 FullDllName;
   _STRING64 BaseDllName;
   unsigned long Flags;
   short LoadCount;
   short TlsIndex;
   union {
   LIST_ENTRY64 HashLinks;
   __int64 SectionPointer;
   };
   unsigned long CheckSum;
   unsigned long Padding15;
   union {
   unsigned long TimeDateStamp;
   __int64 LoadedImports;
   };
} LDR_DATA_TABLE_ENTRY64;

typedef struct IMAGE_LOAD_CONFIG_DIRECTORY64
{
   unsigned long Characteristics;
   unsigned long TimeDateStamp;
   short MajorVersion;
   short MinorVersion;
   unsigned long GlobalFlagsClear;
   unsigned long GlobalFlagsSet;
   unsigned long CriticalSectionDefaultTimeout;
   unsigned long DeCommitFreeBlockThreshold;
   unsigned long DeCommitTotalFreeThreshold;
   __int64 LockPrefixTable;
   unsigned long MaximumAllocationSize;
   unsigned long VirtualMemoryThreshold;
   unsigned long ProcessHeapFlags;
   unsigned long ProcessAffinityMask;
   short CSDVersion;
   short Reserved1;
   __int64 EditList;
   unsigned long Reserved[1];
} IMAGE_LOAD_CONFIG_DIRECTORY64;

typedef struct _SYSTEM_ALARM_ACE
{
   _ACE_HEADER Header;
   unsigned long Mask;
   unsigned long SidStart;
} SYSTEM_ALARM_ACE;

typedef struct _OBJECTID
{
   _GUID Lineage;
   unsigned long Uniquifier;
} OBJECTID;

typedef struct Nv12CelsiusPrimitive
{
   unsigned long ctx_Switch;
   unsigned long Reserved00[63];
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long SetWarningEnable;
   unsigned long GetState;
   unsigned long WaitForIdle;
   unsigned long Reserved01[3];
   unsigned long SyncSetRead;
   unsigned long SyncSetWrite;
   unsigned long SyncSetModulo;
   unsigned long SyncIncrementWrite;
   unsigned long SyncStall;
   unsigned long Reserved17[3];
   unsigned long PmTrigger;
   unsigned long Reserved02[15];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaA;
   unsigned long SetContextDmaB;
   unsigned long SetContextDmaVertex;
   unsigned long SetContextDmaState;
   unsigned long SetContextDmaColor;
   unsigned long SetContextDmaZeta;
   unsigned long Reserved03[25];
   unsigned long SetSurfaceClipHorizontal;
   unsigned long SetSurfaceClipVertical;
   unsigned long SetSurfaceFormat;
   unsigned long SetSurfacePitch;
   unsigned long SetSurfaceColorOffset;
   unsigned long SetSurfaceZetaOffset;
   unsigned long SetTextureOffset[2];
   unsigned long SetTextureFormat[2];
   unsigned long SetTextureControl0[2];
   unsigned long SetTextureControl1[2];
   unsigned long SetTextureControl2[2];
   unsigned long SetTextureImageRect[2];
   unsigned long SetTextureFilter[2];
   unsigned long SetTexturePalette[2];
   unsigned long Reserved04[2];
   unsigned long SetCombinerAlphaICW[2];
   unsigned long SetCombinerColorICW[2];
   unsigned long SetCombineFactor[2];
   unsigned long SetCombinerAlphaOCW[2];
   unsigned long SetCombiner0ColorOCW;
   unsigned long SetCombiner1ColorOCW;
   unsigned long SetCombinerSpecularFogCW0;
   unsigned long SetCombinerSpecularFogCW1;
   unsigned long SetControl0;
   unsigned long SetLightControl;
   unsigned long SetColorMaterial;
   unsigned long SetFogMode;
   unsigned long SetFogGenMode;
   unsigned long SetFogEnable;
   unsigned long SetFogColor;
   unsigned long SetColorKeyColor[2];
   unsigned long SetWindowClipType;
   unsigned long Reserved05[2];
   unsigned long SetWindowClipHorizontal[8];
   unsigned long SetWindowClipVertical[8];
   unsigned long SetAlphaTestEnable;
   unsigned long SetBlendEnable;
   unsigned long SetCullFaceEnable;
   unsigned long SetDepthTestEnable;
   unsigned long SetDitherEnable;
   unsigned long SetLightingEnable;
   unsigned long SetPointParamsEnable;
   unsigned long SetPointSmoothEnable;
   unsigned long SetLineSmoothEnable;
   unsigned long SetPolySmoothEnable;
   unsigned long SetSkinEnable;
   unsigned long SetStencilTestEnable;
   unsigned long SetPolyOffsetPointEnable;
   unsigned long SetPolyOffsetLineEnable;
   unsigned long SetPolyOffsetFillEnable;
   unsigned long SetAlphaFunc;
   unsigned long SetAlphaRef;
   unsigned long SetBlendFuncSfactor;
   unsigned long SetBlendFuncDfactor;
   unsigned long SetBlendColor;
   unsigned long SetBlendEquation;
   unsigned long SetDepthFunc;
   unsigned long SetColorMask;
   unsigned long SetDepthMask;
   unsigned long SetStencilMask;
   unsigned long SetStencilFunc;
   unsigned long SetStencilFuncRef;
   unsigned long SetStencilFuncMask;
   unsigned long SetStencilOpFail;
   unsigned long SetStencilOpZfail;
   unsigned long SetStencilOpZpass;
   unsigned long SetShadeMode;
   unsigned long SetLineWidth;
   float SetPolygonOffsetScaleFactor;
   float SetPolygonOffsetBias;
   unsigned long SetFrontPolygonMode;
   unsigned long SetBackPolygonMode;
   float SetClipMin;
   float SetClipMax;
   unsigned long SetCullFace;
   unsigned long SetFrontFace;
   unsigned long SetNormalizationEnable;
   unsigned long SetMaterialEmission[3];
   unsigned long SetMaterialAlpha;
   unsigned long SetSpecularEnable;
   unsigned long SetLightEnableMask;
   Nv12CelsiusPrimitive::__unnamed SetTexgen[2];
   unsigned long SetTextureMatrix0Enable;
   unsigned long SetTextureMatrix1Enable;
   unsigned long SetTLMode;
   unsigned long SetPointSize;
   unsigned long SetSwathWidth;
   unsigned long SetFlatShadeOp;
   unsigned long Reserved06[2];
   float SetModelViewMatrix0[16];
   float SetModelViewMatrix1[16];
   float SetInverseModelViewMatrix0[16];
   float SetInverseModelViewMatrix1[16];
   float SetCompositeMatrix[16];
   float SetTextureMatrix0[16];
   float SetTextureMatrix1[16];
   unsigned long Reserved07[16];
   float SetTexgenSPlane0[4];
   float SetTexgenTPlane0[4];
   float SetTexgenRPlane0[4];
   float SetTexgenQPlane0[4];
   float SetTexgenSPlane1[4];
   float SetTexgenTPlane1[4];
   float SetTexgenRPlane1[4];
   float SetTexgenQPlane1[4];
   float SetFogParams[3];
   float SetFogPlane[4];
   unsigned long Reserved08[1];
   float SetSpecularParams[6];
   unsigned long Reserved09[3];
   float SetSceneAmbientColor[3];
   unsigned long Reserved0a[6];
   float SetViewportOffset[4];
   float SetPointParams[8];
   float SetEyePosition[4];
   unsigned long Flush;
   float SetEyeDirectionSW[3];
   unsigned long Reserved0b[50];
   Nv12CelsiusPrimitive::__unnamed SetLight[8];
   float SetVertex3f[3];
   unsigned long Reserved0d[3];
   float SetVertex4f[4];
   short SetVertex4s[4];
   float SetNormal3f[3];
   unsigned long Reserved0e[1];
   short SetNormal3s[3];
   short Reserved0f[5];
   float SetDiffuseColor4f[4];
   float SetDiffuseColor3f[3];
   unsigned long SetDiffuseColor4ub;
   float SetSpecularColor4f[4];
   float SetSpecularColor3f[3];
   unsigned long SetSpecularColor4ub;
   float SetTexcoord0_2f[2];
   short SetTexcoord0_2s[2];
   unsigned long Reserved10[1];
   float SetTexcoord0_4f[4];
   short SetTexcoord0_4s[4];
   float SetTexcoord1_2f[2];
   short SetTexcoord1_2s[2];
   unsigned long Reserved11[1];
   float SetTexcoord1_4f[4];
   short SetTexcoord1_4s[4];
   float SetFog1f;
   float SetWeight1f;
   unsigned long Reserved12[1];
   unsigned long SetEdgeFlag;
   unsigned long InvalidateVertexCacheFile;
   unsigned long InvalidateVertexFile;
   unsigned long TlNop;
   unsigned long TlSync;
   unsigned long SetVertexArrayOffset;
   unsigned long SetVertexArrayFormat;
   unsigned long SetDiffuseArrayOffset;
   unsigned long SetDiffuseArrayFormat;
   unsigned long SetSpecularArrayOffset;
   unsigned long SetSpecularArrayFormat;
   unsigned long SetTexCoord0ArrayOffset;
   unsigned long SetTexCoord0ArrayFormat;
   unsigned long SetTexCoord1ArrayOffset;
   unsigned long SetTexCoord1ArrayFormat;
   unsigned long SetNormalArrayOffset;
   unsigned long SetNormalArrayFormat;
   unsigned long SetWeightArrayOffset;
   unsigned long SetWeightArrayFormat;
   unsigned long SetFogArrayOffset;
   unsigned long SetFogArrayFormat;
   unsigned long Reserved13[47];
   unsigned long SetBeginEnd;
   short ArrayElement16[256];
   unsigned long Reserved14[63];
   unsigned long SetBeginEnd2;
   unsigned long ArrayElement32[64];
   unsigned long Reserved15[127];
   unsigned long SetBeginEnd3;
   unsigned long DrawArrays[128];
   unsigned long DebugInit[10];
   unsigned long Reserved1628[117];
   unsigned long SetBeginEnd4;
   unsigned long InlineArray[512];
} Nv12CelsiusPrimitive;

typedef struct Nv12CelsiusPrimitive::__unnamed
{
   unsigned long S;
   unsigned long T;
   unsigned long R;
   unsigned long Q;
} Nv12CelsiusPrimitive::__unnamed;

typedef struct _PROCESS_ACCESS_TOKEN
{
   void * Token;
   void * Thread;
} PROCESS_ACCESS_TOKEN;

typedef struct _LDT_SIZE
{
   unsigned long Length;
} LDT_SIZE;

typedef struct UNNAMED_TAG_4FB0845
{
   unsigned long size;
   unsigned long monochrome[31];
} UNNAMED_TAG_4FB0845;

typedef struct _SYSTEM_FLAGS_INFORMATION
{
   unsigned long Flags;
} SYSTEM_FLAGS_INFORMATION;

typedef struct ISequentialStream
{
   union {
   (type???) IUnknown;
   (type???) Read;
   (type???) Write;
   (type???) ISequentialStream;
   (type???) ISequentialStream;
   };
} ISequentialStream;

typedef struct _D3DXRTS_DESC
{
   int Width;
   int Height;
   int Format;
   int DepthStencil;
   int DepthStencilFormat;
} D3DXRTS_DESC;

typedef struct ID3DXRenderToSurface
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) GetDevice;
   (type???) GetDesc;
   (type???) BeginScene;
   (type???) EndScene;
   (type???) ID3DXRenderToSurface;
   (type???) ID3DXRenderToSurface;
   };
} ID3DXRenderToSurface;

typedef struct NvV64
{
   unsigned long low;
   unsigned long high;
} NvV64;

typedef struct _FILE_RENAME_INFORMATION
{
   unsigned char ReplaceIfExists;
   unsigned char Padding1;
   unsigned char Padding2;
   unsigned char Padding3;
   void * RootDirectory;
   _STRING FileName;
} FILE_RENAME_INFORMATION;

typedef struct _IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY
{
   __int64 BeginAddress;
   __int64 EndAddress;
   __int64 ExceptionHandler;
   __int64 HandlerData;
   __int64 PrologEndAddress;
} IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY;

typedef struct _CM_FLOPPY_DEVICE_DATA
{
   short Version;
   short Revision;
   char Size[8];
   unsigned long MaxDensity;
   unsigned long MountDensity;
   unsigned char StepRateHeadUnloadTime;
   unsigned char HeadLoadTime;
   unsigned char MotorOffTime;
   unsigned char SectorLengthCode;
   unsigned char SectorPerTrack;
   unsigned char ReadWriteGapLength;
   unsigned char DataTransferLength;
   unsigned char FormatGapLength;
   unsigned char FormatFillCharacter;
   unsigned char HeadSettleTime;
   unsigned char MotorSettleTime;
   unsigned char MaximumTrackValue;
   unsigned char DataTransferRate;
} CM_FLOPPY_DEVICE_DATA;

typedef struct _SYSTEM_PERFORMANCE_INFORMATION
{
   _LARGE_INTEGER IdleProcessTime;
   _LARGE_INTEGER IoReadTransferCount;
   _LARGE_INTEGER IoWriteTransferCount;
   _LARGE_INTEGER IoOtherTransferCount;
   unsigned long IoReadOperationCount;
   unsigned long IoWriteOperationCount;
   unsigned long IoOtherOperationCount;
   unsigned long AvailablePages;
   unsigned long CommittedPages;
   unsigned long CommitLimit;
   unsigned long PeakCommitment;
   unsigned long PageFaultCount;
   unsigned long CopyOnWriteCount;
   unsigned long TransitionCount;
   unsigned long CacheTransitionCount;
   unsigned long DemandZeroCount;
   unsigned long PageReadCount;
   unsigned long PageReadIoCount;
   unsigned long CacheReadCount;
   unsigned long CacheIoCount;
   unsigned long DirtyPagesWriteCount;
   unsigned long DirtyWriteIoCount;
   unsigned long MappedPagesWriteCount;
   unsigned long MappedWriteIoCount;
   unsigned long PagedPoolPages;
   unsigned long NonPagedPoolPages;
   unsigned long PagedPoolAllocs;
   unsigned long PagedPoolFrees;
   unsigned long NonPagedPoolAllocs;
   unsigned long NonPagedPoolFrees;
   unsigned long FreeSystemPtes;
   unsigned long ResidentSystemCodePage;
   unsigned long TotalSystemDriverPages;
   unsigned long TotalSystemCodePages;
   unsigned long NonPagedPoolLookasideHits;
   unsigned long PagedPoolLookasideHits;
   unsigned long Spare3Count;
   unsigned long ResidentSystemCachePage;
   unsigned long ResidentPagedPoolPage;
   unsigned long ResidentSystemDriverPage;
   unsigned long CcFastReadNoWait;
   unsigned long CcFastReadWait;
   unsigned long CcFastReadResourceMiss;
   unsigned long CcFastReadNotPossible;
   unsigned long CcFastMdlReadNoWait;
   unsigned long CcFastMdlReadWait;
   unsigned long CcFastMdlReadResourceMiss;
   unsigned long CcFastMdlReadNotPossible;
   unsigned long CcMapDataNoWait;
   unsigned long CcMapDataWait;
   unsigned long CcMapDataNoWaitMiss;
   unsigned long CcMapDataWaitMiss;
   unsigned long CcPinMappedDataCount;
   unsigned long CcPinReadNoWait;
   unsigned long CcPinReadWait;
   unsigned long CcPinReadNoWaitMiss;
   unsigned long CcPinReadWaitMiss;
   unsigned long CcCopyReadNoWait;
   unsigned long CcCopyReadWait;
   unsigned long CcCopyReadNoWaitMiss;
   unsigned long CcCopyReadWaitMiss;
   unsigned long CcMdlReadNoWait;
   unsigned long CcMdlReadWait;
   unsigned long CcMdlReadNoWaitMiss;
   unsigned long CcMdlReadWaitMiss;
   unsigned long CcReadAheadIos;
   unsigned long CcLazyWriteIos;
   unsigned long CcLazyWritePages;
   unsigned long CcDataFlushes;
   unsigned long CcDataPages;
   unsigned long ContextSwitches;
   unsigned long FirstLevelTbFills;
   unsigned long SecondLevelTbFills;
   unsigned long SystemCalls;
} SYSTEM_PERFORMANCE_INFORMATION;

typedef struct _ACL_SIZE_INFORMATION
{
   unsigned long AceCount;
   unsigned long AclBytesInUse;
   unsigned long AclBytesFree;
} ACL_SIZE_INFORMATION;

typedef struct D3DPalette
{
   union {
   (type???) D3DResource;
   (type???) Lock;
   (type???) Unlock;
   (type???) GetSize;
   };
} D3DPalette;

typedef struct HRSRC__
{
   int unused;
} HRSRC__;

typedef struct XNetStartupParams
{
   unsigned char cfgSizeOfStruct;
   unsigned char cfgFlags;
   unsigned char cfgPrivatePoolSizeInPages;
   unsigned char cfgEnetReceiveQueueLength;
   unsigned char cfgIpFragMaxSimultaneous;
   unsigned char cfgIpFragMaxPacketDiv256;
   unsigned char cfgSockMaxSockets;
   unsigned char cfgSockDefaultRecvBufsizeInK;
   unsigned char cfgSockDefaultSendBufsizeInK;
   unsigned char cfgKeyRegMax;
   unsigned char cfgSecRegMax;
} XNetStartupParams;

typedef struct Nv0A0Typedef
{
   unsigned long Reserved00[1984];
} Nv0A0Typedef;

typedef struct _IMAGE_TLS_DIRECTORY32
{
   unsigned long StartAddressOfRawData;
   unsigned long EndAddressOfRawData;
   unsigned long AddressOfIndex;
   unsigned long AddressOfCallBacks;
   unsigned long SizeOfZeroFill;
   unsigned long Characteristics;
} IMAGE_TLS_DIRECTORY32;

typedef struct ID3DXMatrixStack
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) Pop;
   (type???) Push;
   (type???) LoadIdentity;
   (type???) LoadMatrix;
   (type???) MultMatrix;
   (type???) MultMatrixLocal;
   (type???) RotateAxis;
   (type???) RotateAxisLocal;
   (type???) RotateYawPitchRoll;
   (type???) RotateYawPitchRollLocal;
   (type???) Scale;
   (type???) ScaleLocal;
   (type???) Translate;
   (type???) TranslateLocal;
   (type???) GetTop;
   (type???) ID3DXMatrixStack;
   (type???) ID3DXMatrixStack;
   };
} ID3DXMatrixStack;

typedef struct _TIME_FIELDS
{
   short Year;
   short Month;
   short Day;
   short Hour;
   short Minute;
   short Second;
   short Milliseconds;
   short Weekday;
} TIME_FIELDS;

typedef struct _D3DDEVICE_CREATION_PARAMETERS
{
   int AdapterOrdinal;
   int DeviceType;
   HWND__ * hFocusWindow;
   unsigned long BehaviorFlags;
} D3DDEVICE_CREATION_PARAMETERS;

typedef struct _KEY_VALUE_BASIC_INFORMATION
{
   unsigned long TitleIndex;
   unsigned long Type;
   unsigned long NameLength;
   short Name[1];
} KEY_VALUE_BASIC_INFORMATION;

typedef struct NVDE_REGISTER_DEBUGGER_PARAMETERS
{
   unsigned long TrapEvent;
} NVDE_REGISTER_DEBUGGER_PARAMETERS;

typedef struct _OVERLAPPED
{
   unsigned long Internal;
   unsigned long InternalHigh;
   unsigned long Offset;
   unsigned long OffsetHigh;
   void * hEvent;
} OVERLAPPED;

typedef struct _PRIVILEGE_SET
{
   unsigned long PrivilegeCount;
   unsigned long Control;
   _LUID_AND_ATTRIBUTES Privilege[1];
} PRIVILEGE_SET;

typedef struct _KGDTENTRY
{
   short LimitLow;
   short BaseLow;
    unsigned char HighWord[4];
} KGDTENTRY;

typedef struct _KEY_VALUE_PARTIAL_INFORMATION_ALIGN64
{
   unsigned long Type;
   unsigned long DataLength;
   unsigned char Data[1];
} KEY_VALUE_PARTIAL_INFORMATION_ALIGN64;

typedef struct _TOKEN_STATISTICS
{
   _LUID TokenId;
   _LUID AuthenticationId;
   _LARGE_INTEGER ExpirationTime;
   int TokenType;
   int ImpersonationLevel;
   unsigned long DynamicCharged;
   unsigned long DynamicAvailable;
   unsigned long GroupCount;
   unsigned long PrivilegeCount;
   _LUID ModifiedId;
} TOKEN_STATISTICS;

typedef struct _RTL_RANGE_LIST
{
   _LIST_ENTRY ListHead;
   unsigned long Flags;
   unsigned long Count;
   unsigned long Stamp;
} RTL_RANGE_LIST;

typedef struct _SECURITY_DESCRIPTOR_RELATIVE
{
   unsigned char Revision;
   unsigned char Sbz1;
   short Control;
   unsigned long Owner;
   unsigned long Group;
   unsigned long Sacl;
   unsigned long Dacl;
} SECURITY_DESCRIPTOR_RELATIVE;

typedef struct _HARDWARE_PTE
{
   union {
   unsigned long Valid;
   unsigned long Write;
   unsigned long Owner;
   unsigned long WriteThrough;
   unsigned long CacheDisable;
   unsigned long Accessed;
   unsigned long Dirty;
   unsigned long LargePage;
   unsigned long Global;
   unsigned long GuardOrEndOfAllocation;
   unsigned long PersistAllocation;
   unsigned long reserved;
   unsigned long PageFrameNumber;
   };
} HARDWARE_PTE;

typedef struct _CM_COMPONENT_INFORMATION
{
   _DEVICE_FLAGS Flags;
   unsigned long Version;
   unsigned long Key;
   unsigned long AffinityMask;
} CM_COMPONENT_INFORMATION;

typedef struct HBITMAP__
{
   int unused;
} HBITMAP__;

typedef struct _FILE_NAMES_INFORMATION
{
   unsigned long NextEntryOffset;
   unsigned long FileIndex;
   unsigned long FileNameLength;
   char FileName[1];
} FILE_NAMES_INFORMATION;

typedef struct _D3DXATTRIBUTEWEIGHTS
{
   float Position;
   float Boundary;
   float Normal;
   float Diffuse;
   float Specular;
   float Tex[8];
} D3DXATTRIBUTEWEIGHTS;

typedef struct _PORT_DATA_ENTRY
{
   void * Base;
   unsigned long Size;
} PORT_DATA_ENTRY;

typedef struct _XCALCSIG_SIGNATURE
{
   unsigned char Signature[20];
} XCALCSIG_SIGNATURE;

typedef struct Nv0FFTypedef
{
   unsigned long Reserved00[1984];
} Nv0FFTypedef;

typedef struct D3DTexture
{
   union {
   (type???) D3DBaseTexture;
   (type???) GetLevelDesc;
   (type???) GetSurfaceLevel;
   (type???) LockRect;
   (type???) UnlockRect;
   };
} D3DTexture;

typedef struct D3DCubeTexture
{
   union {
   (type???) D3DBaseTexture;
   (type???) GetLevelDesc;
   (type???) GetCubeMapSurface;
   (type???) LockRect;
   (type???) UnlockRect;
   };
} D3DCubeTexture;

typedef struct ID3DXRenderToEnvMap
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) GetDevice;
   (type???) GetDesc;
   (type???) BeginCube;
   (type???) BeginSphere;
   (type???) BeginHemisphere;
   (type???) BeginParabolic;
   (type???) Face;
   (type???) End;
   (type???) ID3DXRenderToEnvMap;
   (type???) ID3DXRenderToEnvMap;
   };
} ID3DXRenderToEnvMap;

typedef struct CODEC_ACCESS_PARAMS
{
   unsigned long uDeviceRef;
   unsigned long BaseAddr;
   unsigned long Offset;
   unsigned long AccessType;
   CODEC_ACCESS_PARAMS::__unnamed Val;
} CODEC_ACCESS_PARAMS;

typedef union CODEC_ACCESS_PARAMS::__unnamed
{
   union {
   unsigned char u8;
   short u16;
   unsigned long u32;
   };
} CODEC_ACCESS_PARAMS::__unnamed;

typedef struct _FILE_END_OF_FILE_INFORMATION
{
   _LARGE_INTEGER EndOfFile;
} FILE_END_OF_FILE_INFORMATION;

typedef struct _XSOUNDTRACK_DATA
{
   int uSoundtrackId;
   int uSongCount;
   int uSoundtrackLength;
   short szName[32];
} XSOUNDTRACK_DATA;

typedef struct _div_t
{
   int quot;
   int rem;
} div_t;

typedef struct _PROCESSOR_POWER_INFORMATION
{
   unsigned long Number;
   unsigned long MaxMhz;
   unsigned long CurrentMhz;
   unsigned long MhzLimit;
   unsigned long MaxIdleState;
   unsigned long CurrentIdleState;
} PROCESSOR_POWER_INFORMATION;

typedef struct _SYSTEM_CONTEXT_SWITCH_INFORMATION
{
   unsigned long ContextSwitches;
   unsigned long FindAny;
   unsigned long FindLast;
   unsigned long FindIdeal;
   unsigned long IdleAny;
   unsigned long IdleCurrent;
   unsigned long IdleLast;
   unsigned long IdleIdeal;
   unsigned long PreemptAny;
   unsigned long PreemptCurrent;
   unsigned long PreemptLast;
   unsigned long SwitchToIdle;
} SYSTEM_CONTEXT_SWITCH_INFORMATION;

typedef struct _CLIENT_ID64
{
   __int64 UniqueProcess;
   __int64 UniqueThread;
} CLIENT_ID64;

typedef struct _MM_STATISTICS
{
   unsigned long Length;
   unsigned long TotalPhysicalPages;
   unsigned long AvailablePages;
   unsigned long VirtualMemoryBytesCommitted;
   unsigned long VirtualMemoryBytesReserved;
   unsigned long CachePagesCommitted;
   unsigned long PoolPagesCommitted;
   unsigned long StackPagesCommitted;
   unsigned long ImagePagesCommitted;
} MM_STATISTICS;

typedef union _POWER_STATE
{
   union {
   int SystemState;
   int DeviceState;
   };
} POWER_STATE;

typedef struct _FSCTL_VOLUME_METADATA
{
   unsigned long ByteOffset;
   unsigned long TransferLength;
   void * TransferBuffer;
} FSCTL_VOLUME_METADATA;

typedef struct _IMAGE_EXPORT_DIRECTORY
{
   unsigned long Characteristics;
   unsigned long TimeDateStamp;
   short MajorVersion;
   short MinorVersion;
   unsigned long Name;
   unsigned long Base;
   unsigned long NumberOfFunctions;
   unsigned long NumberOfNames;
   unsigned long AddressOfFunctions;
   unsigned long AddressOfNames;
   unsigned long AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY;

typedef struct _XBOX_KRNL_VERSION
{
   short Major;
   short Minor;
   short Build;
   short Qfe;
} XBOX_KRNL_VERSION;

typedef struct _EVENT_BASIC_INFORMATION
{
   int EventType;
   long EventState;
} EVENT_BASIC_INFORMATION;

typedef struct _PROCESS_PRIORITY_CLASS
{
   unsigned char Foreground;
   unsigned char PriorityClass;
} PROCESS_PRIORITY_CLASS;

typedef struct _REG_NOTIFY_INFORMATION
{
   unsigned long NextEntryOffset;
   int Action;
   unsigned long KeyLength;
   short Key[1];
} REG_NOTIFY_INFORMATION;

typedef struct _OBJECT_NAME_INFORMATION
{
   _STRING Name;
} OBJECT_NAME_INFORMATION;

typedef struct _XTHREAD_NOTIFICATION
{
   _LIST_ENTRY ListEntry;
   void * pfnNotifyRoutine;
} XTHREAD_NOTIFICATION;

typedef struct _IMAGE_ARCHIVE_MEMBER_HEADER
{
   unsigned char Name[16];
   unsigned char Date[12];
   unsigned char UserID[6];
   unsigned char GroupID[6];
   unsigned char Mode[8];
   unsigned char Size[10];
   unsigned char EndHeader[2];
} IMAGE_ARCHIVE_MEMBER_HEADER;

typedef struct _MEMORYSTATUS
{
   unsigned long dwLength;
   unsigned long dwMemoryLoad;
   unsigned long dwTotalPhys;
   unsigned long dwAvailPhys;
   unsigned long dwTotalPageFile;
   unsigned long dwAvailPageFile;
   unsigned long dwTotalVirtual;
   unsigned long dwAvailVirtual;
} MEMORYSTATUS;

typedef struct _CM_INT13_DRIVE_PARAMETER
{
   short DriveSelect;
   unsigned long MaxCylinders;
   short SectorsPerTrack;
   short MaxHeads;
   short NumberDrives;
} CM_INT13_DRIVE_PARAMETER;

typedef struct D3DSurface
{
   union {
   (type???) D3DPixelContainer;
   (type???) GetContainer;
   (type???) GetDesc;
   (type???) LockRect;
   (type???) UnlockRect;
   unsigned long Padding5;
   };
   unsigned long Padding6;
   unsigned long Padding7;
   unsigned long Padding8;
   unsigned long Padding9;
   D3DBaseTexture * Parent;
} D3DSurface;

typedef struct _DEVICE_FLAGS
{
   union {
   unsigned long Failed;
   unsigned long ReadOnly;
   unsigned long Removable;
   unsigned long ConsoleIn;
   unsigned long ConsoleOut;
   unsigned long Input;
   unsigned long Output;
   };
} DEVICE_FLAGS;

typedef struct mmtime_tag
{
   int wType;
   mmtime_tag::__unnamed u;
} mmtime_tag;

typedef union mmtime_tag::__unnamed
{
   union {
   unsigned long ms;
   unsigned long sample;
   unsigned long cb;
   unsigned long ticks;
   mmtime_tag::__unnamed::__unnamed smpte;
   mmtime_tag::__unnamed::__unnamed midi;
   };
} mmtime_tag::__unnamed;

typedef struct mmtime_tag::__unnamed::__unnamed
{
   unsigned char hour;
   unsigned char min;
   unsigned char sec;
   unsigned char frame;
   unsigned char fps;
   unsigned char dummy;
   unsigned char pad[2];
} mmtime_tag::__unnamed::__unnamed;

typedef struct _FILE_ALLOCATION_INFORMATION
{
   _LARGE_INTEGER AllocationSize;
} FILE_ALLOCATION_INFORMATION;

typedef struct _SYSTEMTIME
{
   short wYear;
   short wMonth;
   short wDayOfWeek;
   short wDay;
   short wHour;
   short wMinute;
   short wSecond;
   short wMilliseconds;
} SYSTEMTIME;

typedef struct _RTL_HANDLE_TABLE
{
   unsigned long MaximumNumberOfHandles;
   unsigned long SizeOfHandleTableEntry;
   unsigned long Reserved[2];
   _RTL_HANDLE_TABLE_ENTRY * FreeHandles;
   _RTL_HANDLE_TABLE_ENTRY * CommittedHandles;
   _RTL_HANDLE_TABLE_ENTRY * UnCommittedHandles;
   _RTL_HANDLE_TABLE_ENTRY * MaxReservedHandles;
} RTL_HANDLE_TABLE;

typedef struct _RTL_HANDLE_TABLE_ENTRY
{
   union {
   unsigned long Flags;
   _RTL_HANDLE_TABLE_ENTRY * NextFree;
   };
} RTL_HANDLE_TABLE_ENTRY;

typedef union _SLIST_HEADER
{
   union {
   __int64 Alignment;
   _SINGLE_LIST_ENTRY Next;
   };
   short Depth;
   short Sequence;
} SLIST_HEADER;

typedef struct _FILE_ATTRIBUTE_TAG_INFORMATION
{
   unsigned long FileAttributes;
   unsigned long ReparseTag;
} FILE_ATTRIBUTE_TAG_INFORMATION;

typedef struct _MESSAGE_RESOURCE_DATA
{
   unsigned long NumberOfBlocks;
   _MESSAGE_RESOURCE_BLOCK Blocks[1];
} MESSAGE_RESOURCE_DATA;

typedef struct _DEBUG_PARAMETERS
{
   unsigned long CommunicationPort;
   unsigned long BaudRate;
} DEBUG_PARAMETERS;

typedef struct _OSVERSIONINFOA
{
   unsigned long dwOSVersionInfoSize;
   unsigned long dwMajorVersion;
   unsigned long dwMinorVersion;
   unsigned long dwBuildNumber;
   unsigned long dwPlatformId;
   char szCSDVersion[128];
} OSVERSIONINFOA;

typedef struct IClassFactory
{
   union {
   (type???) IUnknown;
   (type???) CreateInstance;
   (type???) LockServer;
   (type???) IClassFactory;
   (type???) IClassFactory;
   };
} IClassFactory;

typedef struct _FILE_LINK_INFORMATION
{
   unsigned char ReplaceIfExists;
   unsigned char Padding1;
   unsigned char Padding2;
   unsigned char Padding3;
   void * RootDirectory;
   unsigned long FileNameLength;
   char FileName[1];
} FILE_LINK_INFORMATION;

typedef struct _IMAGE_SEPARATE_DEBUG_HEADER
{
   short Signature;
   short Flags;
   short Machine;
   short Characteristics;
   unsigned long TimeDateStamp;
   unsigned long CheckSum;
   unsigned long ImageBase;
   unsigned long SizeOfImage;
   unsigned long NumberOfSections;
   unsigned long ExportedNamesSize;
   unsigned long DebugDirectorySize;
   unsigned long SectionAlignment;
   unsigned long Reserved[2];
} IMAGE_SEPARATE_DEBUG_HEADER;

typedef struct tagRECT
{
   long left;
   long top;
   long right;
   long bottom;
} tagRECT;

typedef struct APU_EP_CREATE
{
   unsigned long pioBase;
} APU_EP_CREATE;

typedef struct Direct3D
{
   union {
   (type???) AddRef;
   (type???) Release;
   (type???) GetAdapterCount;
   (type???) GetAdapterIdentifier;
   (type???) GetAdapterModeCount;
   (type???) EnumAdapterModes;
   (type???) GetAdapterDisplayMode;
   (type???) CheckDeviceType;
   (type???) CheckDeviceFormat;
   (type???) CheckDeviceMultiSampleType;
   (type???) CheckDepthStencilMatch;
   (type???) GetDeviceCaps;
   (type???) CreateDevice;
   (type???) SetPushBufferSize;
   };
} Direct3D;

typedef struct _KDEVICE_QUEUE_ENTRY
{
   _LIST_ENTRY DeviceListEntry;
   unsigned long SortKey;
   unsigned char Inserted;
} KDEVICE_QUEUE_ENTRY;

typedef struct XNKID
{
   unsigned char ab[8];
} XNKID;

typedef struct _FILE_MOVE_CLUSTER_INFORMATION
{
   unsigned long ClusterCount;
   void * RootDirectory;
   unsigned long FileNameLength;
   char FileName[1];
} FILE_MOVE_CLUSTER_INFORMATION;

typedef struct ID3DXPMesh
{
   union {
   (type???) ID3DXBaseMesh;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) DrawSubset;
   (type???) GetNumFaces;
   (type???) GetNumVertices;
   (type???) GetFVF;
   (type???) GetDeclaration;
   (type???) GetOptions;
   (type???) GetDevice;
   (type???) CloneMeshFVF;
   (type???) CloneMesh;
   (type???) GetVertexBuffer;
   (type???) GetIndexBuffer;
   (type???) LockVertexBuffer;
   (type???) UnlockVertexBuffer;
   (type???) LockIndexBuffer;
   (type???) UnlockIndexBuffer;
   (type???) GetAttributeTable;
   (type???) ClonePMeshFVF;
   (type???) ClonePMesh;
   (type???) SetNumFaces;
   (type???) SetNumVertices;
   (type???) GetMaxFaces;
   (type???) GetMinFaces;
   (type???) GetMaxVertices;
   (type???) GetMinVertices;
   (type???) Save;
   (type???) Optimize;
   (type???) GetAdjacency;
   (type???) ID3DXPMesh;
   (type???) ID3DXPMesh;
   };
} ID3DXPMesh;

typedef struct ID3DXSPMesh
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) GetNumFaces;
   (type???) GetNumVertices;
   (type???) GetFVF;
   (type???) GetDeclaration;
   (type???) GetOptions;
   (type???) GetDevice;
   (type???) CloneMeshFVF;
   (type???) CloneMesh;
   (type???) ClonePMeshFVF;
   (type???) ClonePMesh;
   (type???) ReduceFaces;
   (type???) ReduceVertices;
   (type???) GetMaxFaces;
   (type???) GetMaxVertices;
   (type???) ID3DXSPMesh;
   (type???) ID3DXSPMesh;
   };
} ID3DXSPMesh;

typedef struct _SYSTEM_BASIC_INFORMATION
{
   unsigned long Reserved;
   unsigned long TimerResolution;
   unsigned long PageSize;
   unsigned long NumberOfPhysicalPages;
   unsigned long LowestPhysicalPageNumber;
   unsigned long HighestPhysicalPageNumber;
   unsigned long AllocationGranularity;
   unsigned long MinimumUserModeAddress;
   unsigned long MaximumUserModeAddress;
   unsigned long ActiveProcessorsAffinityMask;
   char NumberOfProcessors;
} SYSTEM_BASIC_INFORMATION;

typedef struct _KSYSTEM_TIME
{
   unsigned long LowPart;
   long High1Time;
   long High2Time;
} KSYSTEM_TIME;

typedef struct D3DXQUATERNION
{
   union {
   (type???) D3DXQUATERNION;
   (type???) D3DXQUATERNION;
   (type???) D3DXQUATERNION;
   (type???) operator float *;
   (type???) operator const float *;
   (type???) operator+=;
   (type???) operator-=;
   (type???) operator*=;
   (type???) operator*=;
   (type???) operator/=;
   (type???) operator+;
   (type???) operator+;
   (type???) operator-;
   (type???) operator-;
   (type???) operator*;
   (type???) operator*;
   (type???) operator/;
   (type???) operator==;
   (type???) operator!=;
   float x;
   };
   float y;
   float z;
   float w;
} D3DXQUATERNION;

typedef struct _IMAGE_RELOCATION
{
   union {
   unsigned long VirtualAddress;
   unsigned long RelocCount;
   };
   unsigned long SymbolTableIndex;
   short Type;
} IMAGE_RELOCATION;

typedef struct NvP64
{
   unsigned long offset;
   short selector;
   short reserved;
} NvP64;

typedef struct Nv03ControlPio
{
   unsigned long Reserved00[3];
   short Free;
   short Zero[3];
   unsigned long Reserved01[58];
} Nv03ControlPio;

typedef struct _D3DCAPS8
{
   int DeviceType;
   int AdapterOrdinal;
   unsigned long Caps;
   unsigned long Caps2;
   unsigned long Caps3;
   unsigned long PresentationIntervals;
   unsigned long CursorCaps;
   unsigned long DevCaps;
   unsigned long PrimitiveMiscCaps;
   unsigned long RasterCaps;
   unsigned long ZCmpCaps;
   unsigned long SrcBlendCaps;
   unsigned long DestBlendCaps;
   unsigned long AlphaCmpCaps;
   unsigned long ShadeCaps;
   unsigned long TextureCaps;
   unsigned long TextureFilterCaps;
   unsigned long CubeTextureFilterCaps;
   unsigned long VolumeTextureFilterCaps;
   unsigned long TextureAddressCaps;
   unsigned long VolumeTextureAddressCaps;
   unsigned long LineCaps;
   unsigned long MaxTextureWidth;
   unsigned long MaxTextureHeight;
   unsigned long MaxVolumeExtent;
   unsigned long MaxTextureRepeat;
   unsigned long MaxTextureAspectRatio;
   unsigned long MaxAnisotropy;
   float MaxVertexW;
   float GuardBandLeft;
   float GuardBandTop;
   float GuardBandRight;
   float GuardBandBottom;
   float ExtentsAdjust;
   unsigned long StencilCaps;
   unsigned long FVFCaps;
   unsigned long TextureOpCaps;
   unsigned long MaxTextureBlendStages;
   unsigned long MaxSimultaneousTextures;
   unsigned long VertexProcessingCaps;
   unsigned long MaxActiveLights;
   unsigned long MaxUserClipPlanes;
   unsigned long MaxVertexBlendMatrices;
   unsigned long MaxVertexBlendMatrixIndex;
   float MaxPointSize;
   unsigned long MaxPrimitiveCount;
   unsigned long MaxVertexIndex;
   unsigned long MaxStreams;
   unsigned long MaxStreamStride;
   unsigned long VertexShaderVersion;
   unsigned long MaxVertexShaderConst;
   unsigned long PixelShaderVersion;
   float MaxPixelShaderValue;
} D3DCAPS8;

typedef struct D3DXPLANE
{
   union {
   (type???) D3DXPLANE;
   (type???) D3DXPLANE;
   (type???) D3DXPLANE;
   (type???) operator float *;
   (type???) operator const float *;
   (type???) operator+;
   (type???) operator-;
   (type???) operator==;
   (type???) operator!=;
   float a;
   };
   float b;
   float c;
   float d;
} D3DXPLANE;

typedef struct _EISA_PORT_DESCRIPTOR
{
   union {
   unsigned char NumberPorts;
   unsigned char Reserved;
   unsigned char Shared;
   unsigned char MoreEntries;
   };
} EISA_PORT_DESCRIPTOR;

typedef struct _EISA_PORT_CONFIGURATION
{
   _EISA_PORT_DESCRIPTOR Configuration;
   short PortAddress;
} EISA_PORT_CONFIGURATION;

typedef struct _EISA_DMA_CONFIGURATION
{
   _DMA_CONFIGURATION_BYTE0 ConfigurationByte0;
   _DMA_CONFIGURATION_BYTE1 ConfigurationByte1;
} EISA_DMA_CONFIGURATION;

typedef struct _CM_EISA_FUNCTION_INFORMATION
{
   unsigned long CompressedId;
   unsigned char IdSlotFlags1;
   unsigned char IdSlotFlags2;
   unsigned char MinorRevision;
   unsigned char MajorRevision;
   unsigned char Selections[26];
   unsigned char FunctionFlags;
   unsigned char TypeString[80];
   _EISA_MEMORY_CONFIGURATION EisaMemory[9];
   _EISA_IRQ_CONFIGURATION EisaIrq[7];
   _EISA_DMA_CONFIGURATION EisaDma[4];
   _EISA_PORT_CONFIGURATION EisaPort[20];
   unsigned char InitializationData[60];
} CM_EISA_FUNCTION_INFORMATION;

typedef struct HMENU__
{
   int unused;
} HMENU__;

typedef struct _DSSTREAMDESC
{
   unsigned long dwFlags;
   unsigned long dwMaxAttachedPackets;
   tWAVEFORMATEX * lpwfxFormat;
   void * lpfnCallback;
   void * lpvContext;
   unsigned long dwMixBinMask;
} DSSTREAMDESC;

typedef struct _XINPUT_CAPABILITIES
{
   unsigned char SubType;
   short Reserved;
   _XINPUT_CAPABILITIES::__unnamed In;
   _XINPUT_CAPABILITIES::__unnamed Out;
} XINPUT_CAPABILITIES;

typedef union _XINPUT_CAPABILITIES::__unnamed
{
   _XINPUT_GAMEPAD Gamepad;
} XINPUT_CAPABILITIES::__unnamed;

typedef struct HTASK__
{
   int unused;
} HTASK__;

typedef struct _KEY_VALUE_PARTIAL_INFORMATION
{
   unsigned long TitleIndex;
   unsigned long Type;
   unsigned long DataLength;
   unsigned char Data[1];
} KEY_VALUE_PARTIAL_INFORMATION;

typedef struct _HARDERROR_MSG
{
   _PORT_MESSAGE h;
   long Status;
   unsigned long Padding2;
   _LARGE_INTEGER ErrorTime;
   unsigned long ValidResponseOptions;
   unsigned long Response;
   unsigned long NumberOfParameters;
   unsigned long UnicodeStringParameterMask;
   unsigned long Parameters[5];
} HARDERROR_MSG;

typedef struct _D3DDISPLAYMODE
{
   int Width;
   int Height;
   int RefreshRate;
   unsigned long Flags;
   int Format;
} D3DDISPLAYMODE;

typedef struct D3DFixup
{
   union {
   (type???) D3DResource;
   (type???) Reset;
   (type???) GetSize;
   (type???) GetSpace;
   unsigned long Padding4;
   };
   unsigned long Padding5;
   unsigned long Padding6;
   unsigned long Run;
   unsigned long Next;
   unsigned long Size;
} D3DFixup;

typedef struct _DSFX_AMPMOD_MONO_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[2];
   unsigned long dwOutMixbinPtrs[1];
} DSFX_AMPMOD_MONO_STATE;

typedef struct _SEMAPHORE_BASIC_INFORMATION
{
   long CurrentCount;
   long MaximumCount;
} SEMAPHORE_BASIC_INFORMATION;

typedef struct _LAUNCH_DATA
{
   unsigned char Data[3072];
} LAUNCH_DATA;

typedef struct IMPORT_OBJECT_HEADER
{
   short Sig1;
   short Sig2;
   short Version;
   short Machine;
   unsigned long TimeDateStamp;
   unsigned long SizeOfData;
   union {
   short Ordinal;
   short Hint;
   };
   union {
   short Type;
   short NameType;
   short Reserved;
   };
} IMPORT_OBJECT_HEADER;

typedef struct _ImageArchitectureEntry
{
   unsigned long FixupInstRVA;
   unsigned long NewInst;
} ImageArchitectureEntry;

typedef struct Nv06eTypedef
{
   unsigned long Reserved00[1984];
} Nv06eTypedef;

typedef struct _IMAGE_RESOURCE_DATA_ENTRY
{
   unsigned long OffsetToData;
   unsigned long Size;
   unsigned long CodePage;
   unsigned long Reserved;
} IMAGE_RESOURCE_DATA_ENTRY;

typedef struct IDirectXFileDataReference
{
   union {
   (type???) IDirectXFileObject;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) GetName;
   (type???) GetId;
   (type???) Resolve;
   (type???) IDirectXFileDataReference;
   (type???) IDirectXFileDataReference;
   };
} IDirectXFileDataReference;

typedef struct _DSFX_CHORUS_STEREO_PARAMS
{
   _DSFX_CHORUS_STEREO_STATE State;
   unsigned long dwGain;
   unsigned long dwModScale;
} DSFX_CHORUS_STEREO_PARAMS;

typedef struct _RTL_HEAP_TAG_INFO
{
   unsigned long NumberOfAllocations;
   unsigned long NumberOfFrees;
   unsigned long BytesAllocated;
} RTL_HEAP_TAG_INFO;

typedef struct _SYSTEM_KERNEL_DEBUGGER_INFORMATION
{
   unsigned char KernelDebuggerEnabled;
   unsigned char KernelDebuggerNotPresent;
} SYSTEM_KERNEL_DEBUGGER_INFORMATION;

typedef struct IDirectSoundBuffer
{
   union {
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) public: unsigned long __stdcall IDirectSoundBuffer::Release(void);
   (type???) SetFrequency;
   (type???) SetVolume;
   (type???) SetPitch;
   (type???) SetLFO;
   (type???) SetEG;
   (type???) SetFilter;
   (type???) SetHeadroom;
   (type???) SetOutputBuffer;
   (type???) SetMixBins;
   (type???) SetMixBinVolumes;
   (type???) SetAllParameters;
   (type???) SetConeAngles;
   (type???) SetConeOrientation;
   (type???) SetConeOutsideVolume;
   (type???) SetMaxDistance;
   (type???) SetMinDistance;
   (type???) SetMode;
   (type???) SetPosition;
   (type???) SetVelocity;
   (type???) SetI3DL2Source;
   (type???) public: long __stdcall IDirectSoundBuffer::Play(unsigned long,unsigned long,unsigned long);
   (type???) PlayEx;
   (type???) Stop;
   (type???) StopEx;
   (type???) SetLoopRegion;
   (type???) GetStatus;
   (type???) GetCurrentPosition;
   (type???) SetCurrentPosition;
   (type???) public: long __stdcall IDirectSoundBuffer::SetBufferData(void *,unsigned long);
   (type???) Lock;
   (type???) Unlock;
   (type???) Restore;
   (type???) SetNotificationPositions;
   };
} IDirectSoundBuffer;

typedef struct D3DPushBuffer
{
   union {
   (type???) D3DResource;
   (type???) Verify;
   (type???) BeginFixup;
   (type???) EndFixup;
   (type???) RunPushBuffer;
   (type???) SetModelView;
   (type???) SetVertexBlendModelView;
   (type???) SetVertexShaderInput;
   (type???) SetRenderTarget;
   (type???) SetTexture;
   (type???) SetPalette;
   (type???) EndVisibilityTest;
   (type???) SetVertexShaderConstant;
   (type???) Jump;
   (type???) GetSize;
   unsigned long Padding15;
   };
   unsigned long Padding16;
   unsigned long Padding17;
   unsigned long Size;
   unsigned long AllocationSize;
} D3DPushBuffer;

typedef struct IDirectXFileObject
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) GetName;
   (type???) GetId;
   (type???) IDirectXFileObject;
   (type???) IDirectXFileObject;
   };
} IDirectXFileObject;

typedef struct SYSTEM_BATTERY_STATE
{
   unsigned char AcOnLine;
   unsigned char BatteryPresent;
   unsigned char Charging;
   unsigned char Discharging;
   unsigned char Spare1[4];
   unsigned long MaxCapacity;
   unsigned long RemainingCapacity;
   unsigned long Rate;
   unsigned long EstimatedTime;
   unsigned long DefaultAlert1;
   unsigned long DefaultAlert2;
} SYSTEM_BATTERY_STATE;

typedef struct _SYSTEM_CALL_TIME_INFORMATION
{
   unsigned long Length;
   unsigned long TotalCalls;
   _LARGE_INTEGER TimeOfCalls[1];
} SYSTEM_CALL_TIME_INFORMATION;

typedef struct _FILE_PIPE_REMOTE_INFORMATION
{
   _LARGE_INTEGER CollectDataTime;
   unsigned long MaximumCollectionCount;
} FILE_PIPE_REMOTE_INFORMATION;

typedef struct _IMAGE_SECTION_HEADER
{
   unsigned char Name[8];
    unsigned char Misc[4];
   unsigned long VirtualAddress;
   unsigned long SizeOfRawData;
   unsigned long PointerToRawData;
   unsigned long PointerToRelocations;
   unsigned long PointerToLinenumbers;
   short NumberOfRelocations;
   short NumberOfLinenumbers;
   unsigned long Characteristics;
} IMAGE_SECTION_HEADER;

typedef struct _MESSAGE_RESOURCE_ENTRY
{
   short Length;
   short Flags;
   unsigned char Text[1];
} MESSAGE_RESOURCE_ENTRY;

typedef struct _ETHREAD
{
   _KTHREAD Tcb;
   _LARGE_INTEGER CreateTime;
   _LARGE_INTEGER ExitTime;
   union {
   long ExitStatus;
   void * OfsChain;
   };
   union {
   _LIST_ENTRY ReaperListEntry;
   _LIST_ENTRY ActiveTimerListHead;
   };
   void * UniqueThread;
   void * StartAddress;
   _LIST_ENTRY IrpList;
   void * DebugData;
} ETHREAD;

typedef struct _DBGKD_CONTROL_SET
{
   unsigned long TraceFlag;
   unsigned long Dr7;
   unsigned long CurrentSymbolStart;
   unsigned long CurrentSymbolEnd;
} DBGKD_CONTROL_SET;

typedef struct HWINEVENTHOOK__
{
   int unused;
} HWINEVENTHOOK__;

typedef union _PCI_DEVICE_ADDRESS::__unnamed
{
   union {
   _PCI_DEVICE_ADDRESS::__unnamed::__unnamed Port;
   _PCI_DEVICE_ADDRESS::__unnamed::__unnamed Memory;
   };
} PCI_DEVICE_ADDRESS::__unnamed;

typedef struct _PCI_DEVICE_ADDRESS::__unnamed::__unnamed
{
   void * TranslatedAddress;
   unsigned long Length;
} PCI_DEVICE_ADDRESS::__unnamed::__unnamed;

typedef struct tagSIZE
{
   long cx;
   long cy;
} tagSIZE;

typedef struct Nv206eControl
{
   unsigned long Ignored00[16];
   unsigned long Put;
   unsigned long Get;
   unsigned long Reference;
   unsigned long Ignored01[2029];
} Nv206eControl;

typedef struct WSAData
{
   short wVersion;
   short wHighVersion;
   char szDescription[257];
   char szSystemStatus[129];
   short iMaxSockets;
   short iMaxUdpDg;
   unsigned char Padding6;
   unsigned char Padding7;
   char * lpVendorInfo;
} WSAData;

typedef struct _LD_LAUNCH_DASHBOARD
{
   unsigned long dwReason;
   unsigned long dwContext;
   unsigned long dwParameter1;
   unsigned long dwParameter2;
   unsigned char Reserved[3056];
} LD_LAUNCH_DASHBOARD;

typedef struct _LPC_CLIENT_DIED_MSG
{
   _PORT_MESSAGE PortMsg;
   _LARGE_INTEGER CreateTime;
} LPC_CLIENT_DIED_MSG;

typedef struct _IMAGE_BASE_RELOCATION
{
   unsigned long VirtualAddress;
   unsigned long SizeOfBlock;
} IMAGE_BASE_RELOCATION;

typedef struct _SYSTEM_SESSION_PROCESS_INFORMATION
{
   unsigned long SessionId;
   unsigned long SizeOfBuf;
   void * Buffer;
} SYSTEM_SESSION_PROCESS_INFORMATION;

typedef struct ID3DXTechnique
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) GetDevice;
   (type???) GetDesc;
   (type???) GetPassDesc;
   (type???) IsParameterUsed;
   (type???) Validate;
   (type???) Begin;
   (type???) Pass;
   (type???) End;
   (type???) ID3DXTechnique;
   (type???) ID3DXTechnique;
   };
} ID3DXTechnique;

typedef struct D3DXMATRIX
{
   union {
   (type???) _D3DMATRIX;
   (type???) D3DXMATRIX;
   (type???) D3DXMATRIX;
   (type???) D3DXMATRIX;
   (type???) D3DXMATRIX;
   (type???) operator();
   (type???) operator();
   (type???) operator float *;
   (type???) operator const float *;
   (type???) operator*=;
   (type???) operator*=;
   (type???) operator+=;
   (type???) operator-=;
   (type???) operator/=;
   (type???) operator+;
   (type???) operator+;
   (type???) operator-;
   (type???) operator-;
   (type???) operator*;
   (type???) operator*;
   (type???) operator/;
   (type???) operator==;
   (type???) operator!=;
   };
} D3DXMATRIX;

typedef struct D3DXVECTOR4
{
   union {
   (type???) D3DXVECTOR4;
   (type???) D3DXVECTOR4;
   (type???) D3DXVECTOR4;
   (type???) operator float *;
   (type???) operator const float *;
   (type???) operator+=;
   (type???) operator-=;
   (type???) operator*=;
   (type???) operator/=;
   (type???) operator+;
   (type???) operator+;
   (type???) operator-;
   (type???) operator-;
   (type???) operator*;
   (type???) operator/;
   (type???) operator==;
   (type???) operator!=;
   float x;
   };
   float y;
   float z;
   float w;
} D3DXVECTOR4;

typedef struct ID3DXEffect
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) GetDevice;
   (type???) GetDesc;
   (type???) GetParameterDesc;
   (type???) GetTechniqueDesc;
   (type???) SetDword;
   (type???) GetDword;
   (type???) SetFloat;
   (type???) GetFloat;
   (type???) SetVector;
   (type???) GetVector;
   (type???) SetMatrix;
   (type???) GetMatrix;
   (type???) SetTexture;
   (type???) GetTexture;
   (type???) SetVertexShader;
   (type???) GetVertexShader;
   (type???) SetPixelShader;
   (type???) GetPixelShader;
   (type???) GetTechnique;
   (type???) CloneEffect;
   (type???) ID3DXEffect;
   (type???) ID3DXEffect;
   };
} ID3DXEffect;

typedef struct _KEY_VALUE_FULL_INFORMATION
{
   unsigned long TitleIndex;
   unsigned long Type;
   unsigned long DataOffset;
   unsigned long DataLength;
   unsigned long NameLength;
   short Name[1];
} KEY_VALUE_FULL_INFORMATION;

typedef struct _DSFX_I3DL2REVERB_IIR
{
   unsigned long dwDelay;
   unsigned long dwCoefficients[2];
} DSFX_I3DL2REVERB_IIR;

typedef struct _D3DXTECHNIQUE_DESC
{
   unsigned long Name;
   int Passes;
} D3DXTECHNIQUE_DESC;

typedef struct _EISA_MEMORY_CONFIGURATION
{
   _EISA_MEMORY_TYPE ConfigurationByte;
   unsigned char DataSize;
   short AddressLowWord;
   unsigned char AddressHighByte;
   short MemorySize;
} EISA_MEMORY_CONFIGURATION;

typedef struct Nv06eControl
{
   unsigned long Ignored00[16];
   unsigned long Put;
   unsigned long Get;
   unsigned long Reference;
   unsigned long Ignored01[2029];
} Nv06eControl;

typedef struct _RTL_PROCESS_LOCKS
{
   unsigned long NumberOfLocks;
   _RTL_PROCESS_LOCK_INFORMATION Locks[1];
} RTL_PROCESS_LOCKS;

typedef struct _RTL_HEAP_INFORMATION
{
   void * BaseAddress;
   unsigned long Flags;
   short EntryOverhead;
   short CreatorBackTraceIndex;
   unsigned long BytesAllocated;
   unsigned long BytesCommitted;
   unsigned long NumberOfTags;
   unsigned long NumberOfEntries;
   unsigned long NumberOfPseudoTags;
   unsigned long PseudoTagGranularity;
   unsigned long Reserved[5];
   _RTL_HEAP_TAG * Tags;
   _RTL_HEAP_ENTRY * Entries;
} RTL_HEAP_INFORMATION;

typedef struct _RTL_PROCESS_HEAPS
{
   unsigned long NumberOfHeaps;
   _RTL_HEAP_INFORMATION Heaps[1];
} RTL_PROCESS_HEAPS;

typedef struct _RTL_DEBUG_INFORMATION
{
   void * SectionHandleClient;
   void * ViewBaseClient;
   void * ViewBaseTarget;
   unsigned long ViewBaseDelta;
   void * EventPairClient;
   void * EventPairTarget;
   void * TargetProcessId;
   void * TargetThreadHandle;
   unsigned long Flags;
   unsigned long OffsetFree;
   unsigned long CommitSize;
   unsigned long ViewSize;
   _RTL_PROCESS_MODULES * Modules;
   _RTL_PROCESS_BACKTRACES * BackTraces;
   _RTL_PROCESS_HEAPS * Heaps;
   _RTL_PROCESS_LOCKS * Locks;
   void * SpecificHeap;
   void * TargetProcessHandle;
   void * Reserved[6];
} RTL_DEBUG_INFORMATION;

typedef struct _CM_SERIAL_DEVICE_DATA
{
   short Version;
   short Revision;
   unsigned long BaudClock;
} CM_SERIAL_DEVICE_DATA;

typedef struct _SYSTEM_VERIFIER_INFORMATION
{
   unsigned long NextEntryOffset;
   unsigned long Level;
   _STRING DriverName;
   unsigned long RaiseIrqls;
   unsigned long AcquireSpinLocks;
   unsigned long SynchronizeExecutions;
   unsigned long AllocationsAttempted;
   unsigned long AllocationsSucceeded;
   unsigned long AllocationsSucceededSpecialPool;
   unsigned long AllocationsWithNoTag;
   unsigned long TrimRequests;
   unsigned long Trims;
   unsigned long AllocationsFailed;
   unsigned long AllocationsFailedDeliberately;
   unsigned long Loads;
   unsigned long Unloads;
   unsigned long UnTrackedPool;
   unsigned long CurrentPagedPoolAllocations;
   unsigned long CurrentNonPagedPoolAllocations;
   unsigned long PeakPagedPoolAllocations;
   unsigned long PeakNonPagedPoolAllocations;
   unsigned long PagedPoolUsageInBytes;
   unsigned long NonPagedPoolUsageInBytes;
   unsigned long PeakPagedPoolUsageInBytes;
   unsigned long PeakNonPagedPoolUsageInBytes;
} SYSTEM_VERIFIER_INFORMATION;

typedef struct _D3DVIEWPORT8
{
   unsigned long X;
   unsigned long Y;
   unsigned long Width;
   unsigned long Height;
   float MinZ;
   float MaxZ;
} D3DVIEWPORT8;

typedef struct HFONT__
{
   int unused;
} HFONT__;

typedef struct _PREFIX_TABLE_ENTRY
{
   short NodeTypeCode;
   short NameLength;
   _PREFIX_TABLE_ENTRY * NextPrefixTree;
   _RTL_SPLAY_LINKS Links;
   _STRING * Prefix;
} PREFIX_TABLE_ENTRY;

typedef struct _PREFIX_TABLE
{
   short NodeTypeCode;
   short NameLength;
   _PREFIX_TABLE_ENTRY * NextPrefixTree;
} PREFIX_TABLE;

typedef struct Nv206eTypedef
{
   unsigned long Reserved00[1984];
} Nv206eTypedef;

typedef struct _LDR_DATA_TABLE_ENTRY
{
   _LIST_ENTRY InLoadOrderLinks;
   _LIST_ENTRY InMemoryOrderLinks;
   _LIST_ENTRY InInitializationOrderLinks;
   void * DllBase;
   void * EntryPoint;
   unsigned long SizeOfImage;
   _UNICODE_STRING FullDllName;
   _UNICODE_STRING BaseDllName;
   unsigned long Flags;
   short LoadCount;
   short TlsIndex;
   union {
   _LIST_ENTRY HashLinks;
   void * SectionPointer;
   };
   unsigned long CheckSum;
   union {
   unsigned long TimeDateStamp;
   void * LoadedImports;
   };
} LDR_DATA_TABLE_ENTRY;

typedef union _IMAGE_THUNK_DATA32::__unnamed
{
   union {
   unsigned long ForwarderString;
   unsigned long Function;
   unsigned long Ordinal;
   unsigned long AddressOfData;
   };
} IMAGE_THUNK_DATA32::__unnamed;

typedef struct _IO_RESOURCE_LIST
{
   short Version;
   short Revision;
   unsigned long Count;
   _IO_RESOURCE_DESCRIPTOR Descriptors[1];
} IO_RESOURCE_LIST;

typedef struct _RTL_HEAP_TAG
{
   unsigned long NumberOfAllocations;
   unsigned long NumberOfFrees;
   unsigned long BytesAllocated;
   short TagIndex;
   short CreatorBackTraceIndex;
   short TagName[24];
} RTL_HEAP_TAG;

typedef struct _FILE_FS_OBJECTID_INFORMATION
{
   unsigned char ObjectId[16];
   unsigned char ExtendedInfo[48];
} FILE_FS_OBJECTID_INFORMATION;

typedef struct _FILE_FS_LABEL_INFORMATION
{
   unsigned long VolumeLabelLength;
   char VolumeLabel[1];
} FILE_FS_LABEL_INFORMATION;

typedef struct IDirectXFileSaveObject
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) SaveTemplates;
   (type???) CreateDataObject;
   (type???) SaveData;
   (type???) IDirectXFileSaveObject;
   (type???) IDirectXFileSaveObject;
   };
} IDirectXFileSaveObject;

typedef struct IDirectXFileEnumObject
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) GetNextDataObject;
   (type???) GetDataObjectById;
   (type???) GetDataObjectByName;
   (type???) IDirectXFileEnumObject;
   (type???) IDirectXFileEnumObject;
   };
} IDirectXFileEnumObject;

typedef struct _HAL_SHUTDOWN_REGISTRATION
{
   void * NotificationRoutine;
   long Priority;
   _LIST_ENTRY ListEntry;
} HAL_SHUTDOWN_REGISTRATION;

typedef struct _ACCESS_ALLOWED_ACE
{
   _ACE_HEADER Header;
   unsigned long Mask;
   unsigned long SidStart;
} ACCESS_ALLOWED_ACE;

typedef struct _SYSTEM_CRASH_STATE_INFORMATION
{
   unsigned long ValidCrashDump;
   unsigned long ValidDirectDump;
} SYSTEM_CRASH_STATE_INFORMATION;

typedef struct HBRUSH__
{
   int unused;
} HBRUSH__;

typedef struct _DMA_CONFIGURATION_BYTE0
{
   union {
   unsigned char Channel;
   unsigned char Reserved;
   unsigned char Shared;
   unsigned char MoreEntries;
   };
} DMA_CONFIGURATION_BYTE0;

typedef struct _PROCESS_WS_WATCH_INFORMATION
{
   void * FaultingPc;
   void * FaultingVa;
} PROCESS_WS_WATCH_INFORMATION;

typedef struct _OBJECT_ATTRIBUTES
{
   void * RootDirectory;
   _STRING * ObjectName;
   unsigned long Attributes;
} OBJECT_ATTRIBUTES;

typedef struct _WSABUF
{
   unsigned long len;
   char * buf;
} WSABUF;

typedef struct _DSFX_ECHO_MONO_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[1];
   unsigned long dwOutMixbinPtrs[1];
} DSFX_ECHO_MONO_STATE;

typedef struct _DSFX_CHORUS_STEREO_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[3];
   unsigned long dwOutMixbinPtrs[2];
} DSFX_CHORUS_STEREO_STATE;

typedef union _IMAGE_SYMBOL::__unnamed
{
   union {
   unsigned char ShortName[8];
   _IMAGE_SYMBOL::__unnamed::__unnamed Name;
   unsigned long LongName[2];
   };
} IMAGE_SYMBOL::__unnamed;

typedef struct _IMAGE_SYMBOL::__unnamed::__unnamed
{
   unsigned long Short;
   unsigned long Long;
} IMAGE_SYMBOL::__unnamed::__unnamed;

typedef struct _ImageArchitectureHeader
{
   union {
   int AmaskValue;
   int AmaskShift;
   };
   unsigned long FirstEntryRVA;
} ImageArchitectureHeader;

typedef struct _IMAGE_COFF_SYMBOLS_HEADER
{
   unsigned long NumberOfSymbols;
   unsigned long LvaToFirstSymbol;
   unsigned long NumberOfLinenumbers;
   unsigned long LvaToFirstLinenumber;
   unsigned long RvaToFirstByteOfCode;
   unsigned long RvaToLastByteOfCode;
   unsigned long RvaToFirstByteOfData;
   unsigned long RvaToLastByteOfData;
} IMAGE_COFF_SYMBOLS_HEADER;

typedef struct _OSVERSIONINFOEXA
{
   unsigned long dwOSVersionInfoSize;
   unsigned long dwMajorVersion;
   unsigned long dwMinorVersion;
   unsigned long dwBuildNumber;
   unsigned long dwPlatformId;
   char szCSDVersion[128];
   short wServicePackMajor;
   short wServicePackMinor;
   short wSuiteMask;
   unsigned char wProductType;
   unsigned char wReserved;
} OSVERSIONINFOEXA;

typedef struct _FILE_MAILSLOT_SET_INFORMATION
{
   _LARGE_INTEGER * ReadTimeout;
} FILE_MAILSLOT_SET_INFORMATION;

typedef struct _WIN32_FILE_ATTRIBUTE_DATA
{
   unsigned long dwFileAttributes;
   _FILETIME ftCreationTime;
   _FILETIME ftLastAccessTime;
   _FILETIME ftLastWriteTime;
   unsigned long nFileSizeHigh;
   unsigned long nFileSizeLow;
} WIN32_FILE_ATTRIBUTE_DATA;

typedef struct _CM_MCA_POS_DATA
{
   short AdapterId;
   unsigned char PosData1;
   unsigned char PosData2;
   unsigned char PosData3;
   unsigned char PosData4;
} CM_MCA_POS_DATA;

typedef struct _D3DXPARAMETER_DESC
{
   unsigned long Name;
   int Type;
} D3DXPARAMETER_DESC;

typedef struct RTL_ACE_DATA
{
   unsigned char AceType;
   unsigned char InheritFlags;
   unsigned char AceFlags;
   unsigned char Padding3;
   unsigned long Mask;
   void * * Sid;
} RTL_ACE_DATA;

typedef struct _DSI3DL2LISTENER
{
   long lRoom;
   long lRoomHF;
   float flRoomRolloffFactor;
   float flDecayTime;
   float flDecayHFRatio;
   long lReflections;
   float flReflectionsDelay;
   long lReverb;
   float flReverbDelay;
   float flDiffusion;
   float flDensity;
   float flHFReference;
} DSI3DL2LISTENER;

typedef struct _D3DBOX
{
   int Left;
   int Top;
   int Right;
   int Bottom;
   int Front;
   int Back;
} D3DBOX;

typedef struct _D3DVOLUME_DESC
{
   int Format;
   int Type;
   unsigned long Usage;
   int Size;
   int Width;
   int Height;
   int Depth;
} D3DVOLUME_DESC;

typedef struct _RTL_GENERIC_TABLE
{
   _RTL_SPLAY_LINKS * TableRoot;
   _LIST_ENTRY InsertOrderList;
   _LIST_ENTRY * OrderedPointer;
   unsigned long WhichOrderedElement;
   unsigned long NumberGenericTableElements;
   void * CompareRoutine;
   void * AllocateRoutine;
   void * FreeRoutine;
   void * TableContext;
} RTL_GENERIC_TABLE;

typedef struct _FILE_FS_FULL_SIZE_INFORMATION
{
   _LARGE_INTEGER TotalAllocationUnits;
   _LARGE_INTEGER CallerAvailableAllocationUnits;
   _LARGE_INTEGER ActualAvailableAllocationUnits;
   unsigned long SectorsPerAllocationUnit;
   unsigned long BytesPerSector;
} FILE_FS_FULL_SIZE_INFORMATION;

typedef struct Nv06cTypedef
{
   unsigned long Reserved00[1984];
} Nv06cTypedef;

typedef struct _IMAGE_VXD_HEADER
{
   short e32_magic;
   unsigned char e32_border;
   unsigned char e32_worder;
   unsigned long e32_level;
   short e32_cpu;
   short e32_os;
   unsigned long e32_ver;
   unsigned long e32_mflags;
   unsigned long e32_mpages;
   unsigned long e32_startobj;
   unsigned long e32_eip;
   unsigned long e32_stackobj;
   unsigned long e32_esp;
   unsigned long e32_pagesize;
   unsigned long e32_lastpagesize;
   unsigned long e32_fixupsize;
   unsigned long e32_fixupsum;
   unsigned long e32_ldrsize;
   unsigned long e32_ldrsum;
   unsigned long e32_objtab;
   unsigned long e32_objcnt;
   unsigned long e32_objmap;
   unsigned long e32_itermap;
   unsigned long e32_rsrctab;
   unsigned long e32_rsrccnt;
   unsigned long e32_restab;
   unsigned long e32_enttab;
   unsigned long e32_dirtab;
   unsigned long e32_dircnt;
   unsigned long e32_fpagetab;
   unsigned long e32_frectab;
   unsigned long e32_impmod;
   unsigned long e32_impmodcnt;
   unsigned long e32_impproc;
   unsigned long e32_pagesum;
   unsigned long e32_datapage;
   unsigned long e32_preload;
   unsigned long e32_nrestab;
   unsigned long e32_cbnrestab;
   unsigned long e32_nressum;
   unsigned long e32_autodata;
   unsigned long e32_debuginfo;
   unsigned long e32_debuglen;
   unsigned long e32_instpreload;
   unsigned long e32_instdemand;
   unsigned long e32_heapsize;
   unsigned char e32_res3[12];
   unsigned long e32_winresoff;
   unsigned long e32_winreslen;
   short e32_devid;
   short e32_ddkver;
} IMAGE_VXD_HEADER;

typedef struct _FILE_DIRECTORY_INFORMATION
{
   unsigned long NextEntryOffset;
   unsigned long FileIndex;
   _LARGE_INTEGER CreationTime;
   _LARGE_INTEGER LastAccessTime;
   _LARGE_INTEGER LastWriteTime;
   _LARGE_INTEGER ChangeTime;
   _LARGE_INTEGER EndOfFile;
   _LARGE_INTEGER AllocationSize;
   unsigned long FileAttributes;
   unsigned long FileNameLength;
   char FileName[1];
} FILE_DIRECTORY_INFORMATION;

typedef struct _RTL_PROCESS_MODULE_INFORMATION
{
   void * Section;
   void * MappedBase;
   void * ImageBase;
   unsigned long ImageSize;
   unsigned long Flags;
   short LoadOrderIndex;
   short InitOrderIndex;
   short LoadCount;
   short OffsetToFileName;
   unsigned char FullPathName[256];
} RTL_PROCESS_MODULE_INFORMATION;

typedef struct _RTL_PROCESS_MODULES
{
   unsigned long NumberOfModules;
   _RTL_PROCESS_MODULE_INFORMATION Modules[1];
} RTL_PROCESS_MODULES;

typedef struct ANON_OBJECT_HEADER
{
   short Sig1;
   short Sig2;
   short Version;
   short Machine;
   unsigned long TimeDateStamp;
   _GUID ClassID;
   unsigned long SizeOfData;
} ANON_OBJECT_HEADER;

typedef struct _SECURITY_SEED_AND_LENGTH
{
   unsigned char Length;
   unsigned char Seed;
} SECURITY_SEED_AND_LENGTH;

typedef struct _DSFX_CHORUS_MONO_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[2];
   unsigned long dwOutMixbinPtrs[1];
} DSFX_CHORUS_MONO_STATE;

typedef struct _DIRECTORY_ENUM_CONTEXT
{
   unsigned long QueryOffset;
   _STRING TemplateFileName;
} DIRECTORY_ENUM_CONTEXT;

typedef struct _LPCSVR_INITIALIZE
{
   unsigned long ContextSize;
   void * ConnectFn;
   void * RequestFn;
   void * RundownFn;
   void * FilterFn;
} LPCSVR_INITIALIZE;

typedef struct _IMAGE_CE_RUNTIME_FUNCTION_ENTRY
{
   unsigned long FuncStart;
   union {
   unsigned long PrologLen;
   unsigned long FuncLen;
   unsigned long ThirtyTwoBit;
   unsigned long ExceptionFlag;
   };
} IMAGE_CE_RUNTIME_FUNCTION_ENTRY;

typedef struct _IMAGE_THUNK_DATA32
{
    unsigned char u1[4];
} IMAGE_THUNK_DATA32;

typedef struct HACCEL__
{
   int unused;
} HACCEL__;

typedef struct _OBJECT_HEADER
{
   long PointerCount;
   long HandleCount;
   _OBJECT_TYPE * Type;
   unsigned long Flags;
   _QUAD Body;
} OBJECT_HEADER;

typedef struct _QUAD
{
   double DoNotUseThisField;
} QUAD;

typedef struct D3DVolume
{
   union {
   (type???) D3DPixelContainer;
   (type???) GetContainer;
   (type???) GetDesc;
   (type???) LockBox;
   (type???) UnlockBox;
   unsigned long Padding5;
   };
   unsigned long Padding6;
   unsigned long Padding7;
   unsigned long Padding8;
   unsigned long Padding9;
   D3DBaseTexture * Parent;
} D3DVolume;

typedef struct _PCI_DEVICE_DESCRIPTOR
{
   unsigned long Bus;
   unsigned long Slot;
   short VendorID;
   short DeviceID;
   unsigned char BaseClass;
   unsigned char SubClass;
   unsigned char ProgIf;
   unsigned char Reserved[1];
   _PCI_DEVICE_DESCRIPTOR::__unnamed ResourceData;
} PCI_DEVICE_DESCRIPTOR;

typedef struct _PCI_DEVICE_DESCRIPTOR::__unnamed
{
   _PCI_DEVICE_ADDRESS Address[1];
   _PCI_DEVICE_DESCRIPTOR::__unnamed::__unnamed Interrupt;
} PCI_DEVICE_DESCRIPTOR::__unnamed;

typedef struct _PCI_DEVICE_DESCRIPTOR::__unnamed::__unnamed
{
   unsigned long Vector;
   unsigned long Affinity;
   unsigned char Irql;
} PCI_DEVICE_DESCRIPTOR::__unnamed::__unnamed;

typedef struct _FILE_NETWORK_OPEN_INFORMATION
{
   _LARGE_INTEGER CreationTime;
   _LARGE_INTEGER LastAccessTime;
   _LARGE_INTEGER LastWriteTime;
   _LARGE_INTEGER ChangeTime;
   _LARGE_INTEGER AllocationSize;
   _LARGE_INTEGER EndOfFile;
   unsigned long FileAttributes;
} FILE_NETWORK_OPEN_INFORMATION;

typedef struct _D3DTRIPATCH_INFO
{
   int StartVertexOffset;
   int NumVertices;
   int Basis;
   int Order;
} D3DTRIPATCH_INFO;

typedef struct HICON__
{
   int unused;
} HICON__;

typedef struct _DSI3DL2BUFFER
{
   long lDirect;
   long lDirectHF;
   long lRoom;
   long lRoomHF;
   float flRoomRolloffFactor;
   _DSI3DL2OBSTRUCTION Obstruction;
   _DSI3DL2OCCLUSION Occlusion;
} DSI3DL2BUFFER;

typedef struct _DSI3DL2OCCLUSION
{
   long lHFLevel;
   float flLFRatio;
} DSI3DL2OCCLUSION;

typedef struct _EXCEPTION_POINTERS
{
   unsigned long ep_xrecord;
   unsigned long ep_context;
} EXCEPTION_POINTERS;

typedef struct _KEY_VALUE_ENTRY
{
   _UNICODE_STRING * ValueName;
   unsigned long DataLength;
   unsigned long DataOffset;
   unsigned long Type;
} KEY_VALUE_ENTRY;

typedef struct _SYSTEM_PROCESS_INFORMATION
{
   unsigned long NextEntryOffset;
   unsigned long NumberOfThreads;
   _LARGE_INTEGER SpareLi1;
   _LARGE_INTEGER SpareLi2;
   _LARGE_INTEGER SpareLi3;
   _LARGE_INTEGER CreateTime;
   _LARGE_INTEGER UserTime;
   _LARGE_INTEGER KernelTime;
   _STRING ImageName;
   long BasePriority;
   void * UniqueProcessId;
   void * InheritedFromUniqueProcessId;
   unsigned long HandleCount;
   unsigned long SessionId;
   unsigned long SpareUl3;
   unsigned long PeakVirtualSize;
   unsigned long VirtualSize;
   unsigned long PageFaultCount;
   unsigned long PeakWorkingSetSize;
   unsigned long WorkingSetSize;
   unsigned long QuotaPeakPagedPoolUsage;
   unsigned long QuotaPagedPoolUsage;
   unsigned long QuotaPeakNonPagedPoolUsage;
   unsigned long QuotaNonPagedPoolUsage;
   unsigned long PagefileUsage;
   unsigned long PeakPagefileUsage;
   unsigned long PrivatePageCount;
   _LARGE_INTEGER ReadOperationCount;
   _LARGE_INTEGER WriteOperationCount;
   _LARGE_INTEGER OtherOperationCount;
   _LARGE_INTEGER ReadTransferCount;
   _LARGE_INTEGER WriteTransferCount;
   _LARGE_INTEGER OtherTransferCount;
} SYSTEM_PROCESS_INFORMATION;

typedef struct _EXCEPTION_RECORD32
{
   long ExceptionCode;
   unsigned long ExceptionFlags;
   unsigned long ExceptionRecord;
   unsigned long ExceptionAddress;
   unsigned long NumberParameters;
   unsigned long ExceptionInformation[15];
} EXCEPTION_RECORD32;

typedef struct _D3DXIMAGE_INFO
{
   int Width;
   int Height;
   int Depth;
   int MipLevels;
   int Format;
} D3DXIMAGE_INFO;

typedef struct _MICROCODE_UPDATE_DATA_BLOCK
{
   unsigned long HeaderVersion;
   unsigned long UpdateRevision;
   short Year;
   unsigned char Day;
   unsigned char Month;
   unsigned long Processor;
   unsigned long Checksum;
   unsigned long LoaderRevision;
   unsigned long ProcessorFlags;
   unsigned char Reserved[20];
   unsigned char UpdateData[2000];
} MICROCODE_UPDATE_DATA_BLOCK;

typedef struct _OSVERSIONINFOW
{
   unsigned long dwOSVersionInfoSize;
   unsigned long dwMajorVersion;
   unsigned long dwMinorVersion;
   unsigned long dwBuildNumber;
   unsigned long dwPlatformId;
   short szCSDVersion[128];
} OSVERSIONINFOW;

typedef struct _SYSTEM_CALL_COUNT_INFORMATION
{
   unsigned long Length;
   unsigned long NumberOfTables;
} SYSTEM_CALL_COUNT_INFORMATION;

typedef struct _PCI_DEVICE_ADDRESS
{
   unsigned char Type;
   unsigned char Valid;
   unsigned char Reserved[2];
    unsigned char u[8];
} PCI_DEVICE_ADDRESS;

typedef struct _EISA_IRQ_CONFIGURATION
{
   _EISA_IRQ_DESCRIPTOR ConfigurationByte;
   unsigned char Reserved;
} EISA_IRQ_CONFIGURATION;

typedef struct _EISA_IRQ_DESCRIPTOR
{
   union {
   unsigned char Interrupt;
   unsigned char Reserved;
   unsigned char LevelTriggered;
   unsigned char Shared;
   unsigned char MoreEntries;
   };
} EISA_IRQ_DESCRIPTOR;

typedef struct _IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY
{
   unsigned long BeginAddress;
   unsigned long EndAddress;
   unsigned long ExceptionHandler;
   unsigned long HandlerData;
   unsigned long PrologEndAddress;
} IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY;

typedef struct HENHMETAFILE__
{
   int unused;
} HENHMETAFILE__;

typedef struct _IMAGE_DEBUG_MISC
{
   unsigned long DataType;
   unsigned long Length;
   unsigned char Unicode;
   unsigned char Reserved[3];
   unsigned char Data[1];
} IMAGE_DEBUG_MISC;

typedef struct _OBJECT_HANDLE_TABLE
{
   long HandleCount;
   long FirstFreeTableEntry;
   void * NextHandleNeedingPool;
   void * * * RootTable;
   void * * BuiltinRootTable[8];
} OBJECT_HANDLE_TABLE;

typedef struct _RTL_PROCESS_LOCK_INFORMATION
{
   void * Address;
   short Type;
   short CreatorBackTraceIndex;
   void * OwningThread;
   long LockCount;
   unsigned long ContentionCount;
   unsigned long EntryCount;
   long RecursionCount;
   unsigned long NumberOfWaitingShared;
   unsigned long NumberOfWaitingExclusive;
} RTL_PROCESS_LOCK_INFORMATION;

typedef struct _IMAGE_LINENUMBER
{
   _IMAGE_LINENUMBER::__unnamed Type;
   short Linenumber;
} IMAGE_LINENUMBER;

typedef union _IMAGE_LINENUMBER::__unnamed
{
   union {
   unsigned long SymbolTableIndex;
   unsigned long VirtualAddress;
   };
} IMAGE_LINENUMBER::__unnamed;

typedef struct _KEY_NAME_INFORMATION
{
   unsigned long NameLength;
   short Name[1];
} KEY_NAME_INFORMATION;

typedef struct _OBJECT_SYMBOLIC_LINK
{
   void * LinkTargetObject;
   _STRING LinkTarget;
} OBJECT_SYMBOLIC_LINK;

typedef struct _VM_COUNTERS
{
   unsigned long PeakVirtualSize;
   unsigned long VirtualSize;
   unsigned long PageFaultCount;
   unsigned long PeakWorkingSetSize;
   unsigned long WorkingSetSize;
   unsigned long QuotaPeakPagedPoolUsage;
   unsigned long QuotaPagedPoolUsage;
   unsigned long QuotaPeakNonPagedPoolUsage;
   unsigned long QuotaNonPagedPoolUsage;
   unsigned long PagefileUsage;
   unsigned long PeakPagefileUsage;
} VM_COUNTERS;

typedef struct _OBJECT_TYPE
{
   void * AllocateProcedure;
   void * FreeProcedure;
   void * CloseProcedure;
   void * DeleteProcedure;
   void * ParseProcedure;
   void * DefaultObject;
   unsigned long PoolTag;
} OBJECT_TYPE;

typedef struct _D3DINDEXBUFFER_DESC
{
   int Format;
   int Type;
} D3DINDEXBUFFER_DESC;

typedef struct D3DResource
{
   union {
   (type???) AddRef;
   (type???) Release;
   (type???) GetDevice;
   (type???) GetType;
   (type???) SetPrivateData;
   (type???) GetPrivateData;
   (type???) FreePrivateData;
   (type???) IsBusy;
   (type???) BlockUntilNotBusy;
   (type???) MoveResourceMemory;
   (type???) Register;
   unsigned long Common;
   };
   unsigned long Data;
   unsigned long Lock;
} D3DResource;

typedef struct _TOKEN_USER
{
   _SID_AND_ATTRIBUTES User;
} TOKEN_USER;

typedef struct _D3DSTREAM_INPUT
{
   D3DVertexBuffer * VertexBuffer;
   int Stride;
   int Offset;
} D3DSTREAM_INPUT;

typedef struct _IMAGE_DEBUG_DIRECTORY
{
   unsigned long Characteristics;
   unsigned long TimeDateStamp;
   short MajorVersion;
   short MinorVersion;
   unsigned long Type;
   unsigned long SizeOfData;
   unsigned long AddressOfRawData;
   unsigned long PointerToRawData;
} IMAGE_DEBUG_DIRECTORY;

typedef struct _LDR_ENUM_RESOURCE_ENTRY
{
   _LDR_ENUM_RESOURCE_ENTRY::__unnamed Path[3];
   void * Data;
   unsigned long Size;
   unsigned long Reserved;
} LDR_ENUM_RESOURCE_ENTRY;

typedef union _LDR_ENUM_RESOURCE_ENTRY::__unnamed
{
   union {
   unsigned long NameOrId;
   _IMAGE_RESOURCE_DIRECTORY_STRING * Name;
   short Id;
   };
   short NameIsPresent;
} LDR_ENUM_RESOURCE_ENTRY::__unnamed;

typedef struct _IMAGE_RESOURCE_DIRECTORY_STRING
{
   short Length;
   char NameString[1];
} IMAGE_RESOURCE_DIRECTORY_STRING;

typedef struct _IMAGE_ROM_HEADERS
{
   _IMAGE_FILE_HEADER FileHeader;
   _IMAGE_ROM_OPTIONAL_HEADER OptionalHeader;
} IMAGE_ROM_HEADERS;

typedef struct _IMAGE_ROM_OPTIONAL_HEADER
{
   short Magic;
   unsigned char MajorLinkerVersion;
   unsigned char MinorLinkerVersion;
   unsigned long SizeOfCode;
   unsigned long SizeOfInitializedData;
   unsigned long SizeOfUninitializedData;
   unsigned long AddressOfEntryPoint;
   unsigned long BaseOfCode;
   unsigned long BaseOfData;
   unsigned long BaseOfBss;
   unsigned long GprMask;
   unsigned long CprMask[4];
   unsigned long GpValue;
} IMAGE_ROM_OPTIONAL_HEADER;

typedef struct _DSFX_DISTORTION_PARAMS
{
   _DSFX_DISTORTION_STATE State;
   unsigned long dwGain;
   unsigned long dwPreFilterB0;
   unsigned long dwPreFilterB1;
   unsigned long dwPreFilterB2;
   unsigned long dwPreFilterA1;
   unsigned long dwPreFilterA2;
   unsigned long dwPostFilterB0;
   unsigned long dwPostFilterB1;
   unsigned long dwPostFilterB2;
   unsigned long dwPostFilterA1;
   unsigned long dwPostFilterA2;
} DSFX_DISTORTION_PARAMS;

typedef struct _DSFX_DISTORTION_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[1];
   unsigned long dwOutMixbinPtrs[1];
} DSFX_DISTORTION_STATE;

typedef struct _KFLOATING_SAVE
{
   unsigned long ControlWord;
   unsigned long StatusWord;
   unsigned long ErrorOffset;
   unsigned long ErrorSelector;
   unsigned long DataOffset;
   unsigned long DataSelector;
   unsigned long Cr0NpxState;
   unsigned long Spare1;
} KFLOATING_SAVE;

typedef struct _RTL_CRITICAL_SECTION::__unnamed::__unnamed
{
   unsigned char Type;
   unsigned char Absolute;
   unsigned char Size;
   unsigned char Inserted;
   long SignalState;
   _LIST_ENTRY WaitListHead;
} RTL_CRITICAL_SECTION::__unnamed::__unnamed;

typedef union _RTL_CRITICAL_SECTION::__unnamed
{
   union {
   _RTL_CRITICAL_SECTION::__unnamed::__unnamed Event;
   unsigned long RawEvent[4];
   };
} RTL_CRITICAL_SECTION::__unnamed;

typedef struct _RTL_CRITICAL_SECTION
{
   _RTL_CRITICAL_SECTION::__unnamed Synchronization;
   long LockCount;
   long RecursionCount;
   void * OwningThread;
} RTL_CRITICAL_SECTION;

typedef struct _CM_RESOURCE_LIST
{
   unsigned long Count;
   _CM_FULL_RESOURCE_DESCRIPTOR List[1];
} CM_RESOURCE_LIST;

typedef struct _CM_PARTIAL_RESOURCE_DESCRIPTOR::__unnamed::__unnamed
{
   _LARGE_INTEGER Start;
   unsigned long Length;
} CM_PARTIAL_RESOURCE_DESCRIPTOR::__unnamed::__unnamed;

typedef union _CM_PARTIAL_RESOURCE_DESCRIPTOR::__unnamed
{
   union {
   _CM_PARTIAL_RESOURCE_DESCRIPTOR::__unnamed::__unnamed Generic;
   _CM_PARTIAL_RESOURCE_DESCRIPTOR::__unnamed::__unnamed Port;
   _CM_PARTIAL_RESOURCE_DESCRIPTOR::__unnamed::__unnamed Interrupt;
   _CM_PARTIAL_RESOURCE_DESCRIPTOR::__unnamed::__unnamed Memory;
   _CM_PARTIAL_RESOURCE_DESCRIPTOR::__unnamed::__unnamed Dma;
   _CM_PARTIAL_RESOURCE_DESCRIPTOR::__unnamed::__unnamed DevicePrivate;
   _CM_PARTIAL_RESOURCE_DESCRIPTOR::__unnamed::__unnamed BusNumber;
   _CM_PARTIAL_RESOURCE_DESCRIPTOR::__unnamed::__unnamed DeviceSpecificData;
   };
} CM_PARTIAL_RESOURCE_DESCRIPTOR::__unnamed;

typedef struct _CM_PARTIAL_RESOURCE_DESCRIPTOR
{
   unsigned char Type;
   unsigned char ShareDisposition;
   short Flags;
   _CM_PARTIAL_RESOURCE_DESCRIPTOR::__unnamed u;
} CM_PARTIAL_RESOURCE_DESCRIPTOR;

typedef struct _CM_PARTIAL_RESOURCE_LIST
{
   short Version;
   short Revision;
   unsigned long Count;
   _CM_PARTIAL_RESOURCE_DESCRIPTOR PartialDescriptors[1];
} CM_PARTIAL_RESOURCE_LIST;

typedef struct _CM_FULL_RESOURCE_DESCRIPTOR
{
   int InterfaceType;
   unsigned long BusNumber;
   _CM_PARTIAL_RESOURCE_LIST PartialResourceList;
} CM_FULL_RESOURCE_DESCRIPTOR;

typedef struct _D3DXRTE_DESC
{
   int Size;
   int Format;
   int DepthStencil;
   int DepthStencilFormat;
} D3DXRTE_DESC;

typedef struct _RTL_HEAP_USAGE_ENTRY
{
   _RTL_HEAP_USAGE_ENTRY * Next;
   void * Address;
   unsigned long Size;
   short AllocatorBackTraceIndex;
   short TagIndex;
} RTL_HEAP_USAGE_ENTRY;

typedef struct _DSLFODESC
{
   unsigned long dwLFO;
   unsigned long dwDelay;
   unsigned long dwDelta;
   long lPitchModulation;
   long lFilterCutOffRange;
   long lAmplitudeModulation;
} DSLFODESC;

typedef struct _INITIAL_TEB
{
   _INITIAL_TEB::__unnamed OldInitialTeb;
   void * StackBase;
   void * StackLimit;
   void * StackAllocationBase;
} INITIAL_TEB;

typedef struct _INITIAL_TEB::__unnamed
{
   void * OldStackBase;
   void * OldStackLimit;
} INITIAL_TEB::__unnamed;

typedef struct _SYSTEM_ALARM_OBJECT_ACE
{
   _ACE_HEADER Header;
   unsigned long Mask;
   unsigned long Flags;
   _GUID ObjectType;
   _GUID InheritedObjectType;
   unsigned long SidStart;
} SYSTEM_ALARM_OBJECT_ACE;

typedef struct _SINGLE_LIST_ENTRY
{
   _SINGLE_LIST_ENTRY * Next;
} SINGLE_LIST_ENTRY;

typedef struct HPALETTE__
{
   int unused;
} HPALETTE__;

typedef struct _LDR_DATA_TABLE_ENTRY32
{
   LIST_ENTRY32 InLoadOrderLinks;
   LIST_ENTRY32 InMemoryOrderLinks;
   LIST_ENTRY32 InInitializationOrderLinks;
   unsigned long DllBase;
   unsigned long EntryPoint;
   unsigned long SizeOfImage;
   _STRING32 FullDllName;
   _STRING32 BaseDllName;
   unsigned long Flags;
   short LoadCount;
   short TlsIndex;
   union {
   LIST_ENTRY32 HashLinks;
   unsigned long SectionPointer;
   };
   unsigned long CheckSum;
   union {
   unsigned long TimeDateStamp;
   unsigned long LoadedImports;
   };
} LDR_DATA_TABLE_ENTRY32;

typedef struct _DMA_CONFIGURATION_BYTE1
{
   union {
   unsigned char Reserved0;
   unsigned char TransferSize;
   unsigned char Timing;
   unsigned char Reserved1;
   };
} DMA_CONFIGURATION_BYTE1;

typedef struct _XINPUT_STATE
{
   unsigned long dwPacketNumber;
   _XINPUT_GAMEPAD Gamepad;
} XINPUT_STATE;

typedef struct _XINPUT_GAMEPAD
{
   short wButtons;
   unsigned char bAnalogButtons[8];
   short sThumbLX;
   short sThumbLY;
   short sThumbRX;
   short sThumbRY;
} XINPUT_GAMEPAD;

typedef struct _FILE_ACCESS_INFORMATION
{
   unsigned long AccessFlags;
} FILE_ACCESS_INFORMATION;

typedef struct D3DXVECTOR2
{
   union {
   (type???) D3DXVECTOR2;
   (type???) D3DXVECTOR2;
   (type???) D3DXVECTOR2;
   (type???) operator float *;
   (type???) operator const float *;
   (type???) operator+=;
   (type???) operator-=;
   (type???) operator*=;
   (type???) operator/=;
   (type???) operator+;
   (type???) operator+;
   (type???) operator-;
   (type???) operator-;
   (type???) operator*;
   (type???) operator/;
   (type???) operator==;
   (type???) operator!=;
   float x;
   };
   float y;
} D3DXVECTOR2;

typedef struct _D3DVERTEXBUFFER_DESC
{
   int Format;
   int Type;
} D3DVERTEXBUFFER_DESC;

typedef struct _SHARE_ACCESS
{
   unsigned char OpenCount;
   unsigned char Readers;
   unsigned char Writers;
   unsigned char Deleters;
   unsigned char SharedRead;
   unsigned char SharedWrite;
   unsigned char SharedDelete;
} SHARE_ACCESS;

typedef struct _EISA_MEMORY_TYPE
{
   union {
   unsigned char ReadWrite;
   unsigned char Cached;
   unsigned char Reserved0;
   unsigned char Type;
   unsigned char Shared;
   unsigned char Reserved1;
   unsigned char MoreEntries;
   };
} EISA_MEMORY_TYPE;

typedef struct _SYSTEM_POOL_ENTRY
{
   unsigned char Allocated;
   unsigned char Spare0;
   short AllocatorBackTraceIndex;
   unsigned long Size;
   union {
   unsigned char Tag[4];
   unsigned long TagUlong;
   void * ProcessChargedQuota;
   };
} SYSTEM_POOL_ENTRY;

typedef struct _SYSTEM_POOL_INFORMATION
{
   unsigned long TotalSize;
   void * FirstEntry;
   short EntryOverhead;
   unsigned char PoolTagPresent;
   unsigned char Spare0;
   unsigned long NumberOfEntries;
   _SYSTEM_POOL_ENTRY Entries[1];
} SYSTEM_POOL_INFORMATION;

typedef struct tagPOINTS
{
   short x;
   short y;
} tagPOINTS;

typedef struct ID3DXBuffer
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) GetBufferPointer;
   (type???) GetBufferSize;
   (type???) ID3DXBuffer;
   (type???) ID3DXBuffer;
   };
} ID3DXBuffer;

typedef struct _FILE_COMPLETION_INFORMATION
{
   void * Port;
   void * Key;
} FILE_COMPLETION_INFORMATION;

typedef struct _FIBER
{
   void * FiberData;
   _EXCEPTION_REGISTRATION_RECORD * ExceptionList;
   void * StackBase;
   void * StackLimit;
   void * DeallocationStack;
   _CONTEXT FiberContext;
   _Wx86TIB * Wx86Tib;
} FIBER;

typedef struct Nv09fTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[6];
   unsigned long SyncSetRead;
   unsigned long SyncSetWrite;
   unsigned long SyncSetModulo;
   unsigned long SyncIncrementWrite;
   unsigned long SyncStall;
   unsigned long SyncIncrementReadRange;
   unsigned long Reserved02[18];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextColorKey;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurfaces;
   unsigned long Reserved03[87];
   unsigned long SetOperation;
   unsigned long ControlPointIn;
   unsigned long ControlPointOut;
   unsigned long Size;
   unsigned long Reserved04[1853];
} Nv09fTypedef;

typedef struct _DSBPOSITIONNOTIFY
{
   unsigned long dwOffset;
   void * hEventNotify;
} DSBPOSITIONNOTIFY;

typedef struct _KPROCESSOR_STATE
{
   _CONTEXT ContextFrame;
   _KSPECIAL_REGISTERS SpecialRegisters;
} KPROCESSOR_STATE;

typedef struct _DESCRIPTOR
{
   short Pad;
   short Limit;
   unsigned long Base;
} DESCRIPTOR;

typedef struct _KSPECIAL_REGISTERS
{
   unsigned long Cr0;
   unsigned long Cr2;
   unsigned long Cr3;
   unsigned long Cr4;
   unsigned long KernelDr0;
   unsigned long KernelDr1;
   unsigned long KernelDr2;
   unsigned long KernelDr3;
   unsigned long KernelDr6;
   unsigned long KernelDr7;
   _DESCRIPTOR Gdtr;
   _DESCRIPTOR Idtr;
   short Tr;
   short Ldtr;
   unsigned long Reserved[6];
} KSPECIAL_REGISTERS;

typedef struct _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION
{
   _LARGE_INTEGER IdleTime;
   _LARGE_INTEGER KernelTime;
   _LARGE_INTEGER UserTime;
   _LARGE_INTEGER DpcTime;
   _LARGE_INTEGER InterruptTime;
   unsigned long InterruptCount;
} SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION;

typedef struct _D3DXATTRIBUTERANGE
{
   unsigned long AttribId;
   unsigned long FaceStart;
   unsigned long FaceCount;
   unsigned long VertexStart;
   unsigned long VertexCount;
} D3DXATTRIBUTERANGE;

typedef struct ID3DXMesh
{
   union {
   (type???) ID3DXBaseMesh;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) DrawSubset;
   (type???) GetNumFaces;
   (type???) GetNumVertices;
   (type???) GetFVF;
   (type???) GetDeclaration;
   (type???) GetOptions;
   (type???) GetDevice;
   (type???) CloneMeshFVF;
   (type???) CloneMesh;
   (type???) GetVertexBuffer;
   (type???) GetIndexBuffer;
   (type???) LockVertexBuffer;
   (type???) UnlockVertexBuffer;
   (type???) LockIndexBuffer;
   (type???) UnlockIndexBuffer;
   (type???) GetAttributeTable;
   (type???) LockAttributeBuffer;
   (type???) UnlockAttributeBuffer;
   (type???) ConvertPointRepsToAdjacency;
   (type???) ConvertAdjacencyToPointReps;
   (type???) GenerateAdjacency;
   (type???) Optimize;
   (type???) OptimizeInplace;
   (type???) ID3DXMesh;
   (type???) ID3DXMesh;
   };
} ID3DXMesh;

typedef struct D3DDevice
{
   union {
   (type???) AddRef;
   (type???) Release;
   (type???) GetDirect3D;
   (type???) GetDeviceCaps;
   (type???) GetDisplayMode;
   (type???) GetCreationParameters;
   (type???) Reset;
   (type???) Present;
   (type???) GetBackBuffer;
   (type???) GetRasterStatus;
   (type???) SetFlickerFilter;
   (type???) SetSoftDisplayFilter;
   (type???) SetGammaRamp;
   (type???) GetGammaRamp;
   (type???) CreateTexture;
   (type???) CreateVolumeTexture;
   (type???) CreateCubeTexture;
   (type???) CreateVertexBuffer;
   (type???) CreateIndexBuffer;
   (type???) CreatePalette;
   (type???) CreateRenderTarget;
   (type???) CreateDepthStencilSurface;
   (type???) CreateImageSurface;
   (type???) CopyRects;
   (type???) UpdateTexture;
   (type???) SetRenderTarget;
   (type???) GetRenderTarget;
   (type???) GetDepthStencilSurface;
   (type???) BeginScene;
   (type???) EndScene;
   (type???) Clear;
   (type???) SetTransform;
   (type???) GetTransform;
   (type???) MultiplyTransform;
   (type???) SetViewport;
   (type???) GetViewport;
   (type???) SetMaterial;
   (type???) GetMaterial;
   (type???) SetLight;
   (type???) GetLight;
   (type???) LightEnable;
   (type???) GetLightEnable;
   (type???) SetRenderState;
   (type???) GetRenderState;
   (type???) ApplyStateBlock;
   (type???) CaptureStateBlock;
   (type???) DeleteStateBlock;
   (type???) CreateStateBlock;
   (type???) GetTexture;
   (type???) SetTexture;
   (type???) GetTextureStageState;
   (type???) SetTextureStageState;
   (type???) DrawPrimitive;
   (type???) DrawIndexedPrimitive;
   (type???) DrawPrimitiveUP;
   (type???) DrawIndexedPrimitiveUP;
   (type???) CreateVertexShader;
   (type???) SetVertexShader;
   (type???) GetVertexShader;
   (type???) DeleteVertexShader;
   (type???) SetVertexShaderConstant;
   (type???) GetVertexShaderConstant;
   (type???) GetVertexShaderDeclaration;
   (type???) GetVertexShaderFunction;
   (type???) SetStreamSource;
   (type???) GetStreamSource;
   (type???) SetIndices;
   (type???) GetIndices;
   (type???) CreatePixelShader;
   (type???) SetPixelShader;
   (type???) SetPixelShaderProgram;
   (type???) GetPixelShader;
   (type???) DeletePixelShader;
   (type???) SetPixelShaderConstant;
   (type???) GetPixelShaderConstant;
   (type???) GetPixelShaderFunction;
   (type???) DrawRectPatch;
   (type???) DrawTriPatch;
   (type???) DeletePatch;
   (type???) SetShaderConstantMode;
   (type???) GetShaderConstantMode;
   (type???) LoadVertexShader;
   (type???) LoadVertexShaderProgram;
   (type???) SelectVertexShader;
   (type???) RunVertexStateShader;
   (type???) GetVertexShaderSize;
   (type???) GetVertexShaderType;
   (type???) DrawVertices;
   (type???) DrawIndexedVertices;
   (type???) DrawVerticesUP;
   (type???) DrawIndexedVerticesUP;
   (type???) PrimeVertexCache;
   (type???) GetPalette;
   (type???) SetPalette;
   (type???) SetTextureStageStateNotInline;
   (type???) SetRenderStateNotInline;
   (type???) SetBackMaterial;
   (type???) GetBackMaterial;
   (type???) UpdateOverlay;
   (type???) EnableOverlay;
   (type???) EnableCC;
   (type???) SendCC;
   (type???) GetCCStatus;
   (type???) BeginVisibilityTest;
   (type???) EndVisibilityTest;
   (type???) GetVisibilityTestResult;
   (type???) GetOverlayUpdateStatus;
   (type???) GetDisplayFieldStatus;
   (type???) SetVertexData2f;
   (type???) SetVertexData4f;
   (type???) SetVertexData2s;
   (type???) SetVertexData4s;
   (type???) SetVertexData4ub;
   (type???) SetVertexDataColor;
   (type???) Begin;
   (type???) End;
   (type???) CreateFixup;
   (type???) CreatePushBuffer;
   (type???) BeginPushBuffer;
   (type???) EndPushBuffer;
   (type???) RunPushBuffer;
   (type???) GetPushBufferOffset;
   (type???) Nop;
   (type???) GetProjectionViewportMatrix;
   (type???) SetModelView;
   (type???) GetModelView;
   (type???) SetVertexBlendModelView;
   (type???) GetVertexBlendModelView;
   (type???) SetVertexShaderInput;
   (type???) GetVertexShaderInput;
   (type???) SwitchTexture;
   (type???) Suspend;
   (type???) Resume;
   (type???) SetScissors;
   (type???) GetScissors;
   (type???) SetTile;
   (type???) GetTile;
   (type???) GetTileCompressionTags;
   (type???) SetTileCompressionTagBits;
   (type???) GetTileCompressionTagBits;
   (type???) IsBusy;
   (type???) BlockUntilIdle;
   (type???) KickPushBuffer;
   (type???) SetVerticalBlankCallback;
   (type???) BlockUntilVerticalBlank;
   (type???) InsertFence;
   (type???) IsFencePending;
   (type???) BlockOnFence;
   (type???) InsertCallback;
   (type???) FlushVertexCache;
   (type???) PersistDisplay;
   (type???) GetPersistedSurface;
   };
} D3DDevice;

typedef struct ID3DXBaseMesh
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) DrawSubset;
   (type???) GetNumFaces;
   (type???) GetNumVertices;
   (type???) GetFVF;
   (type???) GetDeclaration;
   (type???) GetOptions;
   (type???) GetDevice;
   (type???) CloneMeshFVF;
   (type???) CloneMesh;
   (type???) GetVertexBuffer;
   (type???) GetIndexBuffer;
   (type???) LockVertexBuffer;
   (type???) UnlockVertexBuffer;
   (type???) LockIndexBuffer;
   (type???) UnlockIndexBuffer;
   (type???) GetAttributeTable;
   (type???) ID3DXBaseMesh;
   (type???) ID3DXBaseMesh;
   };
} ID3DXBaseMesh;

typedef struct IUnknown
{
   union {
   (type???) ;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) IUnknown;
   (type???) IUnknown;
   };
} IUnknown;

typedef struct _KD_SYMBOLS_INFO
{
   void * BaseOfDll;
   unsigned long ProcessId;
   unsigned long CheckSum;
   unsigned long SizeOfImage;
} KD_SYMBOLS_INFO;

typedef struct _KERNEL_USER_TIMES
{
   _LARGE_INTEGER CreateTime;
   _LARGE_INTEGER ExitTime;
   _LARGE_INTEGER KernelTime;
   _LARGE_INTEGER UserTime;
} KERNEL_USER_TIMES;

typedef struct sockaddr_in
{
   short sin_family;
   short sin_port;
   in_addr sin_addr;
   char sin_zero[8];
} sockaddr_in;

typedef struct _RTL_PROCESS_BACKTRACE_INFORMATION
{
   char * SymbolicBackTrace;
   unsigned long TraceCount;
   short Index;
   short Depth;
   void * BackTrace[32];
} RTL_PROCESS_BACKTRACE_INFORMATION;

typedef struct _RTL_PROCESS_BACKTRACES
{
   unsigned long CommittedMemory;
   unsigned long ReservedMemory;
   unsigned long NumberOfBackTraceLookups;
   unsigned long NumberOfBackTraces;
   _RTL_PROCESS_BACKTRACE_INFORMATION BackTraces[1];
} RTL_PROCESS_BACKTRACES;

typedef struct _MEMORY_BASIC_INFORMATION
{
   void * BaseAddress;
   void * AllocationBase;
   unsigned long AllocationProtect;
   unsigned long RegionSize;
   unsigned long State;
   unsigned long Protect;
   unsigned long Type;
} MEMORY_BASIC_INFORMATION;

typedef struct _SYSTEM_PROCESSOR_INFORMATION
{
   short ProcessorArchitecture;
   short ProcessorLevel;
   short ProcessorRevision;
   short Reserved;
   unsigned long ProcessorFeatureBits;
} SYSTEM_PROCESSOR_INFORMATION;

typedef struct _ACCESS_DENIED_ACE
{
   _ACE_HEADER Header;
   unsigned long Mask;
   unsigned long SidStart;
} ACCESS_DENIED_ACE;

typedef struct IMAGE_LOAD_CONFIG_DIRECTORY32
{
   unsigned long Characteristics;
   unsigned long TimeDateStamp;
   short MajorVersion;
   short MinorVersion;
   unsigned long GlobalFlagsClear;
   unsigned long GlobalFlagsSet;
   unsigned long CriticalSectionDefaultTimeout;
   unsigned long DeCommitFreeBlockThreshold;
   unsigned long DeCommitTotalFreeThreshold;
   unsigned long LockPrefixTable;
   unsigned long MaximumAllocationSize;
   unsigned long VirtualMemoryThreshold;
   unsigned long ProcessHeapFlags;
   unsigned long ProcessAffinityMask;
   short CSDVersion;
   short Reserved1;
   unsigned long EditList;
   unsigned long Reserved[1];
} IMAGE_LOAD_CONFIG_DIRECTORY32;

typedef struct _FSCACHE_ELEMENT
{
   unsigned long BlockNumber;
   _FSCACHE_EXTENSION * CacheExtension;
   union {
   unsigned long UsageCount;
   unsigned long ReadInProgress;
   unsigned long ReadWaiters;
   unsigned long DeletePending;
   unsigned long Reserved;
   unsigned long CacheBufferBits;
   char * CacheBuffer;
   };
   _LIST_ENTRY ListEntry;
} FSCACHE_ELEMENT;

typedef struct _FSCACHE_EXTENSION
{
   _DEVICE_OBJECT * TargetDeviceObject;
   _LARGE_INTEGER PartitionLength;
   unsigned long SectorSize;
} FSCACHE_EXTENSION;

typedef struct _DSFX_FLANGE_STEREO_PARAMS
{
   _DSFX_FLANGE_STEREO_STATE State;
   unsigned long dwFeedback;
   unsigned long dwModScale;
} DSFX_FLANGE_STEREO_PARAMS;

typedef struct _FILE_EA_INFORMATION
{
   unsigned long EaSize;
} FILE_EA_INFORMATION;

typedef struct _KiIoAccessMap
{
   unsigned char DirectionMap[32];
   unsigned char IoMap[8196];
} KiIoAccessMap;

typedef struct _KTSS
{
   short Backlink;
   short Reserved0;
   unsigned long Esp0;
   short Ss0;
   short Reserved1;
   unsigned long Esp1;
   short Ss1;
   short Reserved2;
   unsigned long Esp2;
   short Ss2;
   short Reserved3;
   unsigned long CR3;
   unsigned long Eip;
   unsigned long EFlags;
   unsigned long Eax;
   unsigned long Ecx;
   unsigned long Edx;
   unsigned long Ebx;
   unsigned long Esp;
   unsigned long Ebp;
   unsigned long Esi;
   unsigned long Edi;
   short Es;
   short Reserved4;
   short Cs;
   short Reserved5;
   short Ss;
   short Reserved6;
   short Ds;
   short Reserved7;
   short Fs;
   short Reserved8;
   short Gs;
   short Reserved9;
   short LDT;
   short Reserved10;
   short Flags;
   short IoMapBase;
   _KiIoAccessMap IoMaps[1];
   unsigned char IntDirectionMap[32];
} KTSS;

typedef struct _RTL_BITMAP_RUN
{
   unsigned long StartingIndex;
   unsigned long NumberOfBits;
} RTL_BITMAP_RUN;

typedef struct _FILE_ALIGNMENT_INFORMATION
{
   unsigned long AlignmentRequirement;
} FILE_ALIGNMENT_INFORMATION;

typedef struct _IMAGE_SYMBOL
{
    unsigned char N[8];
   unsigned long Value;
   short SectionNumber;
   short Type;
   unsigned char StorageClass;
   unsigned char NumberOfAuxSymbols;
} IMAGE_SYMBOL;

typedef struct IDirectSoundStream
{
   union {
   (type???) XMediaObject;
   (type???) AddRef;
   (type???) Release;
   (type???) GetInfo;
   (type???) GetStatus;
   (type???) Process;
   (type???) Discontinuity;
   (type???) Flush;
   (type???) QueryInterface;
   (type???) SetFrequency;
   (type???) SetVolume;
   (type???) SetPitch;
   (type???) SetLFO;
   (type???) SetEG;
   (type???) SetFilter;
   (type???) SetHeadroom;
   (type???) SetOutputBuffer;
   (type???) SetMixBins;
   (type???) SetMixBinVolumes;
   (type???) SetAllParameters;
   (type???) SetConeAngles;
   (type???) SetConeOrientation;
   (type???) SetConeOutsideVolume;
   (type???) SetMaxDistance;
   (type???) SetMinDistance;
   (type???) SetMode;
   (type???) SetI3DL2Source;
   (type???) SetPosition;
   (type???) SetVelocity;
   (type???) Pause;
   (type???) IDirectSoundStream;
   (type???) IDirectSoundStream;
   };
} IDirectSoundStream;

typedef struct _DSFX_I3DL2REVERB_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[2];
   unsigned long dwOutMixbinPtrs[35];
} DSFX_I3DL2REVERB_STATE;

typedef struct _XGAME_FIND_DATA
{
   _WIN32_FIND_DATAA wfd;
   char szSaveGameDirectory[260];
   short szSaveGameName[128];
} XGAME_FIND_DATA;

typedef struct _WIN32_FIND_DATAA
{
   unsigned long dwFileAttributes;
   _FILETIME ftCreationTime;
   _FILETIME ftLastAccessTime;
   _FILETIME ftLastWriteTime;
   unsigned long nFileSizeHigh;
   unsigned long nFileSizeLow;
   unsigned long dwReserved0;
   unsigned long dwReserved1;
   char cFileName[260];
   char cAlternateFileName[14];
} WIN32_FIND_DATAA;

typedef struct NvU64
{
   unsigned long low;
   unsigned long high;
} NvU64;

typedef struct IDirectXFileData
{
   union {
   (type???) IDirectXFileObject;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) GetName;
   (type???) GetId;
   (type???) GetData;
   (type???) GetType;
   (type???) GetNextObject;
   (type???) AddDataObject;
   (type???) AddDataReference;
   (type???) AddBinaryObject;
   (type???) IDirectXFileData;
   (type???) IDirectXFileData;
   };
} IDirectXFileData;

typedef struct _PORT_VIEW
{
   unsigned long Length;
   void * SectionHandle;
   unsigned long SectionOffset;
   unsigned long ViewSize;
   void * ViewBase;
   void * ViewRemoteBase;
} PORT_VIEW;

typedef struct _QUOTA_LIMITS
{
   unsigned long PagedPoolLimit;
   unsigned long NonPagedPoolLimit;
   unsigned long MinimumWorkingSetSize;
   unsigned long MaximumWorkingSetSize;
   unsigned long PagefileLimit;
   unsigned long Padding5;
   _LARGE_INTEGER TimeLimit;
} QUOTA_LIMITS;

typedef struct _SYSTEM_LOOKASIDE_INFORMATION
{
   short CurrentDepth;
   short MaximumDepth;
   unsigned long TotalAllocates;
   unsigned long AllocateMisses;
   unsigned long TotalFrees;
   unsigned long FreeMisses;
   unsigned long Type;
   unsigned long Tag;
   unsigned long Size;
} SYSTEM_LOOKASIDE_INFORMATION;

typedef struct _SYSTEM_VDM_INSTEMUL_INFO
{
   unsigned long SegmentNotPresent;
   unsigned long VdmOpcode0F;
   unsigned long OpcodeESPrefix;
   unsigned long OpcodeCSPrefix;
   unsigned long OpcodeSSPrefix;
   unsigned long OpcodeDSPrefix;
   unsigned long OpcodeFSPrefix;
   unsigned long OpcodeGSPrefix;
   unsigned long OpcodeOPER32Prefix;
   unsigned long OpcodeADDR32Prefix;
   unsigned long OpcodeINSB;
   unsigned long OpcodeINSW;
   unsigned long OpcodeOUTSB;
   unsigned long OpcodeOUTSW;
   unsigned long OpcodePUSHF;
   unsigned long OpcodePOPF;
   unsigned long OpcodeINTnn;
   unsigned long OpcodeINTO;
   unsigned long OpcodeIRET;
   unsigned long OpcodeINBimm;
   unsigned long OpcodeINWimm;
   unsigned long OpcodeOUTBimm;
   unsigned long OpcodeOUTWimm;
   unsigned long OpcodeINB;
   unsigned long OpcodeINW;
   unsigned long OpcodeOUTB;
   unsigned long OpcodeOUTW;
   unsigned long OpcodeLOCKPrefix;
   unsigned long OpcodeREPNEPrefix;
   unsigned long OpcodeREPPrefix;
   unsigned long OpcodeHLT;
   unsigned long OpcodeCLI;
   unsigned long OpcodeSTI;
   unsigned long BopCount;
} SYSTEM_VDM_INSTEMUL_INFO;

typedef struct _COMPOUND_ACCESS_ALLOWED_ACE
{
   _ACE_HEADER Header;
   unsigned long Mask;
   short CompoundAceType;
   short Reserved;
   unsigned long SidStart;
} COMPOUND_ACCESS_ALLOWED_ACE;

typedef struct _WMAXMOFileContDesc
{
   short wTitleLength;
   short wAuthorLength;
   short wCopyrightLength;
   short wDescriptionLength;
   short wRatingLength;
   short * pTitle;
   short * pAuthor;
   short * pCopyright;
   short * pDescription;
   short * pRating;
} WMAXMOFileContDesc;

typedef struct _WMAXMOFileHeader
{
   unsigned long dwVersion;
   unsigned long dwSampleRate;
   unsigned long dwNumChannels;
   unsigned long dwDuration;
   unsigned long dwBitrate;
} WMAXMOFileHeader;

typedef struct XWmaFileMediaObject
{
   union {
   (type???) XFileMediaObject;
   (type???) AddRef;
   (type???) Release;
   (type???) GetInfo;
   (type???) GetStatus;
   (type???) Process;
   (type???) Discontinuity;
   (type???) Flush;
   (type???) Seek;
   (type???) GetLength;
   (type???) GetFileHeader;
   (type???) GetFileContentDescription;
   (type???) XWmaFileMediaObject;
   (type???) XWmaFileMediaObject;
   };
} XWmaFileMediaObject;

typedef struct XFileMediaObject
{
   union {
   (type???) XMediaObject;
   (type???) AddRef;
   (type???) Release;
   (type???) GetInfo;
   (type???) GetStatus;
   (type???) Process;
   (type???) Discontinuity;
   (type???) Flush;
   (type???) Seek;
   (type???) GetLength;
   (type???) XFileMediaObject;
   (type???) XFileMediaObject;
   };
} XFileMediaObject;

typedef struct _IMAGE_FUNCTION_ENTRY64
{
   __int64 StartingAddress;
   __int64 EndingAddress;
   union {
   __int64 EndOfPrologue;
   __int64 UnwindInfoAddress;
   };
} IMAGE_FUNCTION_ENTRY64;

typedef struct LIST_ENTRY32
{
   unsigned long Flink;
   unsigned long Blink;
} LIST_ENTRY32;

typedef struct _D3DLOCKED_BOX
{
   int RowPitch;
   int SlicePitch;
   void * pBits;
} D3DLOCKED_BOX;

typedef struct _DSFX_FLANGE_STEREO_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[3];
   unsigned long dwOutMixbinPtrs[2];
} DSFX_FLANGE_STEREO_STATE;

typedef struct _ACCESS_ALLOWED_OBJECT_ACE
{
   _ACE_HEADER Header;
   unsigned long Mask;
   unsigned long Flags;
   _GUID ObjectType;
   _GUID InheritedObjectType;
   unsigned long SidStart;
} ACCESS_ALLOWED_OBJECT_ACE;

typedef struct _IO_COMPLETION_BASIC_INFORMATION
{
   long Depth;
} IO_COMPLETION_BASIC_INFORMATION;

typedef struct _RTL_PERTHREAD_CURDIR
{
   _RTL_DRIVE_LETTER_CURDIR * CurrentDirectories;
   _UNICODE_STRING * ImageName;
   void * Environment;
} RTL_PERTHREAD_CURDIR;

typedef struct _FP_128
{
   unsigned long W[4];
} FP_128;

typedef struct _FP_80
{
   unsigned long W[3];
} FP_80;

typedef struct _FP_64
{
   unsigned long W[2];
} FP_64;

typedef struct _FP_32
{
   unsigned long W[1];
} FP_32;

typedef union _FP_IEEE_VALUE::__unnamed
{
   union {
   short I16Value;
   short U16Value;
   long I32Value;
   unsigned long U32Value;
   void * StringValue;
   unsigned long CompareValue;
   _FP_32 Fp32Value;
   _LARGE_INTEGER I64Value;
   _ULARGE_INTEGER U64Value;
   _FP_64 Fp64Value;
   _FP_80 Fp80Value;
   _FP_128 Fp128Value;
   };
} FP_IEEE_VALUE::__unnamed;

typedef struct _FP_IEEE_VALUE
{
   _FP_IEEE_VALUE::__unnamed Value;
   _FP_IEEE_VALUE::__unnamed Control;
} FP_IEEE_VALUE;

typedef struct _FP_IEEE_RECORD
{
   _FP_IEEE_VALUE Operand1;
   _FP_IEEE_VALUE Operand2;
   _FP_IEEE_VALUE Result;
} FP_IEEE_RECORD;

typedef struct _MESSAGE_RESOURCE_BLOCK
{
   unsigned long LowId;
   unsigned long HighId;
   unsigned long OffsetToEntries;
} MESSAGE_RESOURCE_BLOCK;

typedef struct SYSTEM_POWER_LEVEL
{
   unsigned char Enable;
   unsigned char Spare[3];
   unsigned long BatteryLevel;
   POWER_ACTION_POLICY PowerPolicy;
   int MinSystemState;
} SYSTEM_POWER_LEVEL;

typedef struct POWER_ACTION_POLICY
{
   int Action;
   unsigned long Flags;
   unsigned long EventCode;
} POWER_ACTION_POLICY;

typedef struct _IMAGE_OS2_HEADER
{
   short ne_magic;
   char ne_ver;
   char ne_rev;
   short ne_enttab;
   short ne_cbenttab;
   long ne_crc;
   short ne_flags;
   short ne_autodata;
   short ne_heap;
   short ne_stack;
   long ne_csip;
   long ne_sssp;
   short ne_cseg;
   short ne_cmod;
   short ne_cbnrestab;
   short ne_segtab;
   short ne_rsrctab;
   short ne_restab;
   short ne_modtab;
   short ne_imptab;
   long ne_nrestab;
   short ne_cmovent;
   short ne_align;
   short ne_cres;
   unsigned char ne_exetyp;
   unsigned char ne_flagsothers;
   short ne_pretthunks;
   short ne_psegrefbytes;
   short ne_swaparea;
   short ne_expver;
} IMAGE_OS2_HEADER;

typedef struct _DSFX_IIR2_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[1];
   unsigned long dwOutMixbinPtrs[1];
} DSFX_IIR2_STATE;

typedef struct _DSFX_IIR2_PARAMS
{
   _DSFX_IIR2_STATE State;
   unsigned long dwFilterB0;
   unsigned long dwFilterB1;
   unsigned long dwFilterB2;
   unsigned long dwFilterA1;
   unsigned long dwFilterA2;
} DSFX_IIR2_PARAMS;

typedef struct _D3DTILE
{
   unsigned long Flags;
   void * pMemory;
   unsigned long Size;
   unsigned long Pitch;
   unsigned long ZStartTag;
   unsigned long ZOffset;
} D3DTILE;

typedef struct _FX_SAVE_AREA
{
   _FLOATING_SAVE_AREA FloatSave;
   unsigned long Align16Byte[3];
} FX_SAVE_AREA;

typedef struct _KPRCB
{
   _KTHREAD * CurrentThread;
   _KTHREAD * NextThread;
   _KTHREAD * IdleThread;
   _KTHREAD * NpxThread;
   unsigned long InterruptCount;
   unsigned long DpcTime;
   unsigned long InterruptTime;
   unsigned long DebugDpcTime;
   unsigned long KeContextSwitches;
   unsigned long DpcInterruptRequested;
   _LIST_ENTRY DpcListHead;
   unsigned long DpcRoutineActive;
   void * DpcStack;
   unsigned long QuantumEnd;
   _FX_SAVE_AREA NpxSaveArea;
   void * DmEnetFunc;
   void * DebugMonitorData;
   void * DebugHaltThread;
   void * DebugDoubleFault;
} KPRCB;

typedef struct _KPCR
{
   _NT_TIB NtTib;
   _KPCR * SelfPcr;
   _KPRCB * Prcb;
   unsigned char Irql;
   unsigned char Padding4;
   unsigned char Padding5;
   unsigned char Padding6;
   _KPRCB PrcbData;
} KPCR;

typedef struct _CM_KEYBOARD_DEVICE_DATA
{
   short Version;
   short Revision;
   unsigned char Type;
   unsigned char Subtype;
   short KeyboardFlags;
} CM_KEYBOARD_DEVICE_DATA;

typedef struct _FILE_FS_CONTROL_INFORMATION
{
   _LARGE_INTEGER FreeSpaceStartFiltering;
   _LARGE_INTEGER FreeSpaceThreshold;
   _LARGE_INTEGER FreeSpaceStopFiltering;
   _LARGE_INTEGER DefaultQuotaThreshold;
   _LARGE_INTEGER DefaultQuotaLimit;
   unsigned long FileSystemControlFlags;
} FILE_FS_CONTROL_INFORMATION;

typedef struct _IMAGE_FUNCTION_ENTRY
{
   unsigned long StartingAddress;
   unsigned long EndingAddress;
   unsigned long EndOfPrologue;
} IMAGE_FUNCTION_ENTRY;

typedef struct _XMEDIAPACKET
{
   void * pvBuffer;
   unsigned long dwMaxSize;
   unsigned long * pdwCompletedSize;
   unsigned long * pdwStatus;
   union {
   void * hCompletionEvent;
   void * pContext;
   };
   __int64 * prtTimestamp;
} XMEDIAPACKET;

typedef struct _XMEDIAINFO
{
   unsigned long dwFlags;
   unsigned long dwInputSize;
   unsigned long dwOutputSize;
   unsigned long dwMaxLookahead;
} XMEDIAINFO;

typedef struct XAc97MediaObject
{
   union {
   (type???) XMediaObject;
   (type???) AddRef;
   (type???) Release;
   (type???) GetInfo;
   (type???) GetStatus;
   (type???) Process;
   (type???) Discontinuity;
   (type???) Flush;
   (type???) SetMode;
   (type???) GetCurrentPosition;
   (type???) XAc97MediaObject;
   (type???) XAc97MediaObject;
   };
} XAc97MediaObject;

typedef struct XMediaObject
{
   union {
   (type???) ;
   (type???) AddRef;
   (type???) Release;
   (type???) GetInfo;
   (type???) GetStatus;
   (type???) Process;
   (type???) Discontinuity;
   (type???) Flush;
   (type???) XMediaObject;
   (type???) XMediaObject;
   };
} XMediaObject;

typedef struct D3DIndexBuffer
{
   union {
   (type???) D3DResource;
   (type???) Lock;
   (type???) Unlock;
   (type???) GetDesc;
   };
} D3DIndexBuffer;

typedef struct _OBJECT_DIRECTORY
{
   _OBJECT_HEADER_NAME_INFO * HashBuckets[11];
} OBJECT_DIRECTORY;

typedef struct _OBJECT_HEADER_NAME_INFO
{
   _OBJECT_HEADER_NAME_INFO * ChainLink;
   _OBJECT_DIRECTORY * Directory;
   _STRING Name;
} OBJECT_HEADER_NAME_INFO;

typedef struct PROCESSOR_STATE_HANDLER
{
   unsigned char ThrottleScale;
   unsigned char ThrottleOnIdle;
   unsigned char Padding2;
   unsigned char Padding3;
   void * SetThrottle;
   unsigned long NumIdleHandlers;
   PROCESSOR_IDLE_HANDLER_INFO IdleHandler[3];
} PROCESSOR_STATE_HANDLER;

typedef struct PROCESSOR_IDLE_HANDLER_INFO
{
   unsigned long HardwareLatency;
   void * Handler;
} PROCESSOR_IDLE_HANDLER_INFO;

typedef struct _DSFX_AMPMOD_STEREO_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[3];
   unsigned long dwOutMixbinPtrs[2];
} DSFX_AMPMOD_STEREO_STATE;

typedef struct _DSFX_AMPMOD_STEREO_PARAMS
{
   _DSFX_AMPMOD_STEREO_STATE State;
} DSFX_AMPMOD_STEREO_PARAMS;

typedef struct _CM_EISA_SLOT_INFORMATION
{
   unsigned char ReturnCode;
   unsigned char ReturnFlags;
   unsigned char MajorRevision;
   unsigned char MinorRevision;
   short Checksum;
   unsigned char NumberFunctions;
   unsigned char FunctionInformation;
   unsigned long CompressedId;
} CM_EISA_SLOT_INFORMATION;

typedef struct HKEY__
{
   int unused;
} HKEY__;

typedef struct _D3DMATRIX
{
   float _11;
   float _12;
   float _13;
   float _14;
   float _21;
   float _22;
   float _23;
   float _24;
   float _31;
   float _32;
   float _33;
   float _34;
   float _41;
   float _42;
   float _43;
   float _44;
   float m[4] m[4];
} D3DMATRIX;

typedef struct _ADMINISTRATOR_POWER_POLICY
{
   int MinSleep;
   int MaxSleep;
   unsigned long MinVideoTimeout;
   unsigned long MaxVideoTimeout;
   unsigned long MinSpindownTimeout;
   unsigned long MaxSpindownTimeout;
} ADMINISTRATOR_POWER_POLICY;

typedef struct _IMAGE_NT_HEADERS
{
   unsigned long Signature;
   _IMAGE_FILE_HEADER FileHeader;
   _IMAGE_OPTIONAL_HEADER OptionalHeader;
} IMAGE_NT_HEADERS;

typedef struct _IMAGE_OPTIONAL_HEADER
{
   short Magic;
   unsigned char MajorLinkerVersion;
   unsigned char MinorLinkerVersion;
   unsigned long SizeOfCode;
   unsigned long SizeOfInitializedData;
   unsigned long SizeOfUninitializedData;
   unsigned long AddressOfEntryPoint;
   unsigned long BaseOfCode;
   unsigned long BaseOfData;
   unsigned long ImageBase;
   unsigned long SectionAlignment;
   unsigned long FileAlignment;
   short MajorOperatingSystemVersion;
   short MinorOperatingSystemVersion;
   short MajorImageVersion;
   short MinorImageVersion;
   short MajorSubsystemVersion;
   short MinorSubsystemVersion;
   unsigned long Win32VersionValue;
   unsigned long SizeOfImage;
   unsigned long SizeOfHeaders;
   unsigned long CheckSum;
   short Subsystem;
   short DllCharacteristics;
   unsigned long SizeOfStackReserve;
   unsigned long SizeOfStackCommit;
   unsigned long SizeOfHeapReserve;
   unsigned long SizeOfHeapCommit;
   unsigned long LoaderFlags;
   unsigned long NumberOfRvaAndSizes;
   _IMAGE_DATA_DIRECTORY DataDirectory[16];
} IMAGE_OPTIONAL_HEADER;

typedef struct _IMAGE_FILE_HEADER
{
   short Machine;
   short NumberOfSections;
   unsigned long TimeDateStamp;
   unsigned long PointerToSymbolTable;
   unsigned long NumberOfSymbols;
   short SizeOfOptionalHeader;
   short Characteristics;
} IMAGE_FILE_HEADER;

typedef struct _DSFX_MINIREVERB_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[1];
   unsigned long dwOutMixbinPtrs[12];
} DSFX_MINIREVERB_STATE;

typedef struct _IMAGE_RESOURCE_DIRECTORY_ENTRY
{
   union {
   unsigned long NameOffset;
   unsigned long NameIsString;
   unsigned long Name;
   short Id;
   };
   unsigned char Padding4;
   unsigned char Padding5;
   union {
   unsigned long OffsetToData;
   unsigned long OffsetToDirectory;
   unsigned long DataIsDirectory;
   };
} IMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef struct _DSI3DL2OBSTRUCTION
{
   long lHFLevel;
   float flLFRatio;
} DSI3DL2OBSTRUCTION;

typedef struct _ACL
{
   unsigned char AclRevision;
   unsigned char Sbz1;
   short AclSize;
   short AceCount;
   short Sbz2;
} ACL;

typedef struct _TOKEN_DEFAULT_DACL
{
   _ACL * DefaultDacl;
} TOKEN_DEFAULT_DACL;

typedef struct _CM_PNP_BIOS_INSTALLATION_CHECK
{
   unsigned char Signature[4];
   unsigned char Revision;
   unsigned char Length;
   short ControlField;
   unsigned char Checksum;
   unsigned long EventFlagAddress;
   short RealModeEntryOffset;
   short RealModeEntrySegment;
   short ProtectedModeEntryOffset;
   unsigned long ProtectedModeCodeBaseAddress;
   unsigned long OemDeviceId;
   short RealModeDataBaseAddress;
   unsigned long ProtectedModeDataBaseAddress;
} CM_PNP_BIOS_INSTALLATION_CHECK;

typedef struct _FILE_REPARSE_POINT_INFORMATION
{
   __int64 FileReference;
   unsigned long Tag;
} FILE_REPARSE_POINT_INFORMATION;

typedef struct _RTL_BITMAP
{
   unsigned long SizeOfBitMap;
   unsigned long * Buffer;
} RTL_BITMAP;

typedef struct _OBJECT_DIRECTORY_INFORMATION
{
   _STRING Name;
   unsigned long Type;
} OBJECT_DIRECTORY_INFORMATION;

typedef struct _DSFX_FLANGE_MONO_PARAMS
{
   _DSFX_FLANGE_MONO_STATE State;
   unsigned long dwFeedback;
   unsigned long dwModScale;
} DSFX_FLANGE_MONO_PARAMS;

typedef struct HMONITOR__
{
   int unused;
} HMONITOR__;

typedef struct Nv04ChannelPio
{
   volatile Nv04SubchannelPio subchannel[8];
} Nv04ChannelPio;

typedef struct NvfffTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   unsigned long Create;
   unsigned long Destroy;
   unsigned long Reserved02[1854];
} NvfffTypedef;

typedef struct NvffeTypedef::__unnamed
{
   unsigned long address[2];
   unsigned long limit;
} NvffeTypedef::__unnamed;

typedef struct NvffeTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   NvffeTypedef::__unnamed SetDmaSpecifier;
   unsigned long Reserved02[1853];
} NvffeTypedef;

typedef struct NvffdTypedef::__unnamed
{
   unsigned long address[2];
   unsigned long limit;
} NvffdTypedef::__unnamed;

typedef struct NvffdTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   NvffdTypedef::__unnamed SetDmaSpecifier;
   unsigned long Reserved02[1853];
} NvffdTypedef;

typedef struct NvffcTypedef::__unnamed
{
   unsigned long address[2];
   unsigned long limit;
} NvffcTypedef::__unnamed;

typedef struct NvffcTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   NvffcTypedef::__unnamed SetDmaSpecifier;
   unsigned long Reserved02[1853];
} NvffcTypedef;

typedef struct NvffbTypedef
{
   unsigned long Reserved00[1984];
} NvffbTypedef;

typedef struct NvffaTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[31];
   unsigned long SetVideoInput[64];
   unsigned long Reserved02[1856];
} NvffaTypedef;

typedef struct Nvff9Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaColormap;
   unsigned long Reserved01[30];
   unsigned long SetVideoOutput;
   unsigned long SetVideoInput;
   unsigned long Reserved02[64];
   unsigned long SetColormapStart;
   unsigned long SetColormapLength;
   unsigned long ColormapDirtyStart;
   unsigned long ColormapDirtyLength;
   unsigned long Reserved03[1850];
} Nvff9Typedef;

typedef struct Nvff8Typedef::__unnamed
{
   unsigned long offset;
   unsigned long pitch;
   unsigned long size;
   unsigned long format;
   unsigned long notify;
} Nvff8Typedef::__unnamed;

typedef struct Nvff8Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long StopTransfer;
   unsigned long SetPatch;
   unsigned long Reserved00[28];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage[2];
   unsigned long Reserved01[29];
   unsigned long SetVideoOutput;
   unsigned long Reserved02[63];
   Nvff8Typedef::__unnamed ImageScan[2];
   unsigned long GetOffsetNotify[2];
   unsigned long Reserved03[1844];
} Nvff8Typedef;

typedef struct Nvff7Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[31];
   unsigned long SetVideoOutput;
   unsigned long SetVideoInput;
   unsigned long Reserved02[62];
   unsigned long SetDeltaDuDx;
   unsigned long SetDeltaDvDy;
   unsigned long SetPoint;
   unsigned long Reserved03[1853];
} Nvff7Typedef;

typedef struct Nvff6Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[31];
   unsigned long SetVideoOutput;
   unsigned long SetVideoInput[3];
   unsigned long Reserved02[60];
   unsigned long SetColorFormat;
   unsigned long SetColorKey;
   unsigned long SetPoint;
   unsigned long SetSize;
   unsigned long Reserved03[1852];
} Nvff6Typedef;

typedef struct Nvff5Typedef::__unnamed
{
   unsigned long address[2];
   unsigned long limit;
} Nvff5Typedef::__unnamed;

typedef struct Nvff5Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   Nvff5Typedef::__unnamed SetDmaSpecifier;
   unsigned long Reserved02[1853];
} Nvff5Typedef;

typedef struct Nv205fTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[6];
   unsigned long SyncSetRead;
   unsigned long SyncSetWrite;
   unsigned long SyncSetModulo;
   unsigned long SyncIncrementWrite;
   unsigned long SyncStall;
   unsigned long SyncIncrementReadRange;
   unsigned long Reserved02[18];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextColorKey;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurfaces;
   unsigned long Reserved03[87];
   unsigned long SetOperation;
   unsigned long ControlPointIn;
   unsigned long ControlPointOut;
   unsigned long Size;
   unsigned long Reserved04[1853];
} Nv205fTypedef;

typedef struct Nv1189Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[88];
   unsigned long SetColorConversion;
   unsigned long SetColorFormat;
   unsigned long SetOperation;
   unsigned long ClipPoint;
   unsigned long ClipSize;
   unsigned long ImageOutPoint;
   unsigned long ImageOutSize;
   unsigned long DsDx;
   unsigned long DtDy;
   unsigned long Reserved02[56];
   unsigned long ImageInSize;
   unsigned long ImageInFormat;
   unsigned long ImageInOffset;
   unsigned long ImageInPoint;
   unsigned long Reserved03[1788];
} Nv1189Typedef;

typedef struct Nv095Typedef::__unnamed
{
   float sx;
   float sy;
   float sz;
   float rhw;
   unsigned long color;
   unsigned long specular;
   float tu0;
   float tv0;
   float tu1;
   float tv1;
} Nv095Typedef::__unnamed;

typedef struct Nv095Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaA;
   unsigned long SetContextDmaB;
   unsigned long SetContextSurfaces;
   unsigned long Reserved01[94];
   unsigned long Offset[2];
   unsigned long Format[2];
   unsigned long Filter[2];
   unsigned long Combine0Alpha;
   unsigned long Combine0Color;
   unsigned long Reserved02;
   unsigned long Combine1Alpha;
   unsigned long Combine1Color;
   unsigned long CombineFactor;
   unsigned long Blend;
   unsigned long Control0;
   unsigned long Control1;
   unsigned long Control2;
   unsigned long FogColor;
   unsigned long Reserved03[45];
   Nv095Typedef::__unnamed Tlmtvertex[8];
   unsigned long DrawPrimitive[48];
   unsigned long Reserved04[1664];
} Nv095Typedef;

typedef struct Nv094Typedef::__unnamed
{
   float sx;
   float sy;
   float sz;
   float rhw;
   unsigned long color;
   unsigned long specular;
   float tu;
   float tv;
} Nv094Typedef::__unnamed;

typedef struct Nv094Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaA;
   unsigned long SetContextDmaB;
   unsigned long SetContextSurfaces;
   unsigned long Reserved01[92];
   unsigned long ColorKeyValue;
   unsigned long Offset;
   unsigned long Format;
   unsigned long Filter;
   unsigned long Blend;
   unsigned long Control;
   unsigned long FogColor;
   unsigned long Reserved02[57];
   Nv094Typedef::__unnamed Tlvertex[16];
   unsigned long DrawPrimitive[64];
   unsigned long Reserved03[1600];
} Nv094Typedef;

typedef struct Nv093Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaColor;
   unsigned long SetContextDmaZeta;
   unsigned long Reserved01[91];
   unsigned long SetClipHorizontal;
   unsigned long SetClipVertical;
   unsigned long SetFormat;
   unsigned long SetClipSize;
   unsigned long SetPitch;
   unsigned long SetOffsetColor;
   unsigned long SetOffsetZeta;
   unsigned long Reserved02[1851];
} Nv093Typedef;

typedef struct Nv089Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[88];
   unsigned long SetColorConversion;
   unsigned long SetColorFormat;
   unsigned long SetOperation;
   unsigned long ClipPoint;
   unsigned long ClipSize;
   unsigned long ImageOutPoint;
   unsigned long ImageOutSize;
   unsigned long DsDx;
   unsigned long DtDy;
   unsigned long Reserved02[56];
   unsigned long ImageInSize;
   unsigned long ImageInFormat;
   unsigned long ImageInOffset;
   unsigned long ImageInPoint;
   unsigned long Reserved03[1788];
} Nv089Typedef;

typedef struct Nv088Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaOverlay;
   unsigned long SetContextDmaImageIn;
   unsigned long SetContextDmaImageOut;
   unsigned long Reserved01[92];
   unsigned long ImageOutPoint;
   unsigned long ImageOutSize;
   unsigned long ImageOutFormat;
   unsigned long ImageOutOffset;
   unsigned long ImageInDsDx;
   unsigned long ImageInDtDy;
   unsigned long ImageInSize;
   unsigned long ImageInFormat;
   unsigned long ImageInOffset;
   unsigned long ImageInPoint;
   unsigned long OverlayDsDx;
   unsigned long OverlayDtDy;
   unsigned long OverlaySize;
   unsigned long OverlayFormat;
   unsigned long OverlayOffset;
   unsigned long OverlayPoint;
   unsigned long Reserved02[1840];
} Nv088Typedef;

typedef struct Nv087Typedef
{
   unsigned long Reserved00[1984];
} Nv087Typedef;

typedef struct Nv086Typedef
{
   unsigned long Reserved00[1984];
} Nv086Typedef;

typedef struct Nv085Typedef
{
   unsigned long Reserved00[1984];
} Nv085Typedef;

typedef struct Nv084Typedef
{
   unsigned long Reserved00[1984];
} Nv084Typedef;

typedef struct Nv082Typedef
{
   unsigned long Reserved00[1984];
} Nv082Typedef;

typedef struct Nv081Typedef
{
   unsigned long Reserved00[1984];
} Nv081Typedef;

typedef struct Nv080Typedef
{
   unsigned long Reserved00[1984];
} Nv080Typedef;

typedef struct Nv07cTypedef::__unnamed
{
   unsigned long offset;
   unsigned long format;
} Nv07cTypedef::__unnamed;

typedef struct Nv07cTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long StopImage[2];
   unsigned long StopLut[2];
   unsigned long StopCursorImage[2];
   unsigned long StopDac[2];
   unsigned long Reserved00[22];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage[2];
   unsigned long SetContextDmaLut[2];
   unsigned long SetContextDmaCursor[2];
   unsigned long SetContextDmaSemaphore;
   unsigned long Reserved01[84];
   unsigned long SetSemaphoreOffset;
   unsigned long SetSemaphoreRelease;
   unsigned long SetOffsetRange;
   unsigned long GetOffset;
   Nv07cTypedef::__unnamed SetImage[2];
   Nv07cTypedef::__unnamed SetLut[2];
   Nv07cTypedef::__unnamed SetCursorImage[2];
   unsigned long SetCursorPoint;
   unsigned long Reserved03[3];
   Nv07cTypedef::__unnamed SetDac[2];
   unsigned long Reserved04[1824];
} Nv07cTypedef;

typedef struct Nv07bTypedef::__unnamed
{
   unsigned long a;
   unsigned long b;
} Nv07bTypedef::__unnamed;

typedef struct Nv07bTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextSurface;
   unsigned long Reserved01[94];
   unsigned long SetColorFormat;
   unsigned long Point;
   unsigned long Size;
   unsigned long ClipHorizontal;
   unsigned long ClipVertical;
   unsigned long Reserved02[59];
   Nv07bTypedef::__unnamed Color[896];
} Nv07bTypedef;

typedef struct Nv077Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[89];
   unsigned long SetColorFormat;
   unsigned long SetOperation;
   unsigned long ClipPoint;
   unsigned long ClipSize;
   unsigned long ImageOutPoint;
   unsigned long ImageOutSize;
   unsigned long DeltaDuDx;
   unsigned long DeltaDvDy;
   unsigned long Reserved02[56];
   unsigned long ImageInSize;
   unsigned long ImageInFormat;
   unsigned long ImageInOffset;
   unsigned long ImageInPoint;
   unsigned long Reserved03[1788];
} Nv077Typedef;

typedef struct Nv076Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextColorKey;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[88];
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long SizeIn;
   unsigned long DeltaDxDu;
   unsigned long DeltaDyDv;
   unsigned long ClipPoint;
   unsigned long ClipSize;
   unsigned long Point12d4;
   unsigned long Reserved02[57];
   unsigned long Color[1792];
} Nv076Typedef;

typedef struct Nv072Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   unsigned long SetBetaFactor;
   unsigned long Reserved02[1855];
} Nv072Typedef;

typedef struct Nv06fTypedef
{
   unsigned long Reserved00[1984];
} Nv06fTypedef;

typedef struct Nv067Typedef::__unnamed
{
   unsigned long offset;
   unsigned long format;
} Nv067Typedef::__unnamed;

typedef struct Nv067Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long StopImage[2];
   unsigned long StopLut[2];
   unsigned long StopCursorImage[2];
   unsigned long StopDac[2];
   unsigned long Reserved00[22];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage[2];
   unsigned long SetContextDmaLut[2];
   unsigned long SetContextDmaCursor[2];
   unsigned long Reserved01[88];
   unsigned long GetOffset;
   Nv067Typedef::__unnamed SetImage[2];
   Nv067Typedef::__unnamed SetLut[2];
   Nv067Typedef::__unnamed SetCursorImage[2];
   unsigned long SetCursorPoint;
   unsigned long Reserved03[3];
   Nv067Typedef::__unnamed SetDac[2];
   unsigned long Reserved04[1824];
} Nv067Typedef;

typedef struct _Nv066Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextColorKey;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[87];
   unsigned long SetColorConversion;
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long SizeIn;
   unsigned long DxDs;
   unsigned long DyDt;
   unsigned long ClipPoint;
   unsigned long ClipSize;
   unsigned long Point12d4;
   unsigned long Reserved02[57];
   unsigned long Color[1792];
} Nv066Typedef;

typedef struct Nv065Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextColorKey;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[86];
   unsigned long SetColorConversion;
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long Point;
   unsigned long SizeOut;
   unsigned long SizeIn;
   unsigned long Reserved02[60];
   unsigned long Color[1792];
} Nv065Typedef;

typedef struct Nv064Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaLut;
   unsigned long SetContextColorKey;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[143];
   unsigned long SetColorConversion;
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long IndexFormat;
   unsigned long LutOffset;
   unsigned long Point;
   unsigned long SizeOut;
   unsigned long SizeIn;
   unsigned long Indices[1792];
} Nv064Typedef;

typedef struct Nv063Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[88];
   unsigned long SetColorConversion;
   unsigned long SetColorFormat;
   unsigned long SetOperation;
   unsigned long ClipPoint;
   unsigned long ClipSize;
   unsigned long ImageOutPoint;
   unsigned long ImageOutSize;
   unsigned long DsDx;
   unsigned long DtDy;
   unsigned long Reserved02[56];
   unsigned long ImageInSize;
   unsigned long ImageInFormat;
   unsigned long ImageInOffset;
   unsigned long ImageInPoint;
   unsigned long Reserved03[1788];
} Nv063Typedef;

typedef struct Nv062Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImageSource;
   unsigned long SetContextDmaImageDestin;
   unsigned long Reserved01[93];
   unsigned long SetColorFormat;
   unsigned long SetPitch;
   unsigned long SetOffsetSource;
   unsigned long SetOffsetDestin;
   unsigned long Reserved02[1852];
} Nv062Typedef;

typedef struct Nv060Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaLut;
   unsigned long SetContextColorKey;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[143];
   unsigned long SetColorConversion;
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long IndexFormat;
   unsigned long LutOffset;
   unsigned long Point;
   unsigned long SizeOut;
   unsigned long SizeIn;
   unsigned long Indices[1792];
} Nv060Typedef;

typedef struct Nv05fTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextColorKey;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurfaces;
   unsigned long Reserved01[87];
   unsigned long SetOperation;
   unsigned long ControlPointIn;
   unsigned long ControlPointOut;
   unsigned long Size;
   unsigned long Reserved02[1853];
} Nv05fTypedef;

typedef struct Nv05eTypedef::__unnamed
{
   unsigned long point;
   unsigned long size;
} Nv05eTypedef::__unnamed;

typedef struct Nv05eTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[88];
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long Color;
   unsigned long Reserved02[62];
   Nv05eTypedef::__unnamed Rectangle[16];
   unsigned long Reserved03[1760];
} Nv05eTypedef;

typedef struct Nv05dTypedef::__unnamed
{
   long x;
   long y;
} Nv05dTypedef::__unnamed;

typedef struct Nv05dTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[88];
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long Color;
   unsigned long Reserved02[2];
   unsigned long TrianglePoint0;
   unsigned long TrianglePoint1;
   unsigned long TrianglePoint2;
   unsigned long Reserved03[1];
   long Triangle32Point0X;
   long Triangle32Point0Y;
   long Triangle32Point1X;
   long Triangle32Point1Y;
   long Triangle32Point2X;
   long Triangle32Point2Y;
   unsigned long Reserved04[50];
   unsigned long Trimesh[32];
   Nv05dTypedef::__unnamed Trimesh32[16];
   Nv05dTypedef::__unnamed ColorTriangle[8];
   Nv05dTypedef::__unnamed ColorTrimesh[16];
   unsigned long Reserved05[1664];
} Nv05dTypedef;

typedef struct Nv05cTypedef::__unnamed
{
   unsigned long point0;
   unsigned long point1;
} Nv05cTypedef::__unnamed;

typedef struct Nv05cTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[88];
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long Color;
   unsigned long Reserved02[62];
   Nv05cTypedef::__unnamed Lin[16];
   Nv05cTypedef::__unnamed Lin32[8];
   unsigned long PolyLin[32];
   Nv05cTypedef::__unnamed PolyLin32[16];
   Nv05cTypedef::__unnamed ColorPolyLin[16];
   unsigned long Reserved03[1632];
} Nv05cTypedef;

typedef struct Nv05bTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage;
   unsigned long Reserved01[94];
   unsigned long SetColorFormat;
   unsigned long Reserved02[1];
   unsigned long NvDummy;
   unsigned long SetImageOffset;
   unsigned long Reserved03[1852];
} Nv05bTypedef;

typedef struct Nv05aTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage;
   unsigned long Reserved01[94];
   unsigned long SetColorFormat;
   unsigned long Reserved02[1];
   unsigned long SetImagePitch;
   unsigned long SetImageOffset;
   unsigned long Reserved03[1852];
} Nv05aTypedef;

typedef struct Nv059Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage;
   unsigned long Reserved01[94];
   unsigned long SetColorFormat;
   unsigned long Reserved02[1];
   unsigned long SetImagePitch;
   unsigned long SetImageOffset;
   unsigned long Reserved03[1852];
} Nv059Typedef;

typedef struct Nv058Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage;
   unsigned long Reserved01[94];
   unsigned long SetColorFormat;
   unsigned long Reserved02[1];
   unsigned long SetImagePitch;
   unsigned long SetImageOffset;
   unsigned long Reserved03[1852];
} Nv058Typedef;

typedef struct Nv057Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   unsigned long SetColorFormat;
   unsigned long SetColor;
   unsigned long Reserved02[1854];
} Nv057Typedef;

typedef struct Nv055Typedef::__unnamed
{
   float sx;
   float sy;
   float sz;
   float rhw;
   unsigned long color;
   unsigned long specular;
   float tu0;
   float tv0;
   float tu1;
   float tv1;
} Nv055Typedef::__unnamed;

typedef struct Nv055Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaA;
   unsigned long SetContextDmaB;
   unsigned long SetContextSurfaces;
   unsigned long Reserved01[94];
   unsigned long Offset[2];
   unsigned long Format[2];
   unsigned long Filter[2];
   unsigned long Combine0Alpha;
   unsigned long Combine0Color;
   unsigned long Reserved02[1];
   unsigned long Combine1Alpha;
   unsigned long Combine1Color;
   unsigned long CombineFactor;
   unsigned long Blend;
   unsigned long Control0;
   unsigned long Control1;
   unsigned long Control2;
   unsigned long FogColor;
   unsigned long Reserved03[45];
   Nv055Typedef::__unnamed Tlmtvertex[8];
   unsigned long DrawPrimitive[48];
   unsigned long Reserved04[1664];
} Nv055Typedef;

typedef struct Nv054Typedef::__unnamed
{
   float sx;
   float sy;
   float sz;
   float rhw;
   unsigned long color;
   unsigned long specular;
   float tu;
   float tv;
} Nv054Typedef::__unnamed;

typedef struct Nv054Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaA;
   unsigned long SetContextDmaB;
   unsigned long SetContextSurfaces;
   unsigned long Reserved01[92];
   unsigned long ColorKey;
   unsigned long Offset;
   unsigned long Format;
   unsigned long Filter;
   unsigned long Blend;
   unsigned long Control;
   unsigned long FogColor;
   unsigned long Reserved02[57];
   Nv054Typedef::__unnamed Tlvertex[16];
   unsigned long DrawPrimitive[64];
   unsigned long Reserved03[1600];
} Nv054Typedef;

typedef struct Nv051Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long StopTransfer;
   unsigned long Reserved00[29];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   unsigned long WriteSize;
   unsigned long WriteAddress;
   unsigned long WriteData;
   unsigned long ReadSize;
   unsigned long ReadAddress;
   unsigned long ReadGetDataNotify;
   unsigned long SetInterruptNotify;
   unsigned long Reserved02[1849];
} Nv051Typedef;

typedef struct Nv050Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long StopTransfer;
   unsigned long Reserved00[29];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   unsigned long WriteSize;
   unsigned long WriteAddress;
   unsigned long WriteData;
   unsigned long ReadSize;
   unsigned long ReadAddress;
   unsigned long ReadGetDataNotify;
   unsigned long SetInterruptNotify;
   unsigned long Reserved02[1849];
} Nv050Typedef;

typedef struct Nv04fTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long StopTransfer;
   unsigned long Reserved00[29];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   unsigned long WriteSize;
   unsigned long WriteAddress;
   unsigned long WriteData;
   unsigned long ReadSize;
   unsigned long ReadAddress;
   unsigned long ReadGetDataNotify;
   unsigned long SetInterruptNotify;
   unsigned long Reserved02[1849];
} Nv04fTypedef;

typedef struct Nv04dTypedef::__unnamed
{
   unsigned long size;
   unsigned long offset;
   unsigned long format;
} Nv04dTypedef::__unnamed;

typedef struct Nv04dTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long StopTransferVbi;
   unsigned long StopTransferImage;
   unsigned long Reserved00[28];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaVbi[2];
   unsigned long SetContextDmaImage[2];
   unsigned long Reserved01[89];
   unsigned long SetImageConfig;
   unsigned long SetImageStartLine;
   Nv04dTypedef::__unnamed SetVbi[2];
   unsigned long GetVbiOffsetNotify[2];
   Nv04dTypedef::__unnamed SetImage[2];
   unsigned long GetImageOffsetNotify[2];
   unsigned long Reserved02[1838];
} Nv04dTypedef;

typedef struct Nv04aTypedef::__unnamed
{
   unsigned long point;
   unsigned long size;
} Nv04aTypedef::__unnamed;

typedef struct Nv04aTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaFonts;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[88];
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long SetMonochromeFormat;
   unsigned long Reserved02[61];
   unsigned long Color1A;
   Nv04aTypedef::__unnamed UnclippedRectangle[32];
   unsigned long Reserved03[61];
   unsigned long ClipPoint0B;
   unsigned long ClipPoint1B;
   unsigned long Color1B;
   Nv04aTypedef::__unnamed ClippedRectangle[32];
   unsigned long Reserved04[59];
   unsigned long ClipPoint0C;
   unsigned long ClipPoint1C;
   unsigned long Color1C;
   unsigned long SizeC;
   unsigned long PointC;
   unsigned long MonochromeColor1C[128];
   unsigned long Reserved05[121];
   unsigned long ClipPoint0E;
   unsigned long ClipPoint1E;
   unsigned long Color0E;
   unsigned long Color1E;
   unsigned long SizeInE;
   unsigned long SizeOutE;
   unsigned long PointE;
   unsigned long MonochromeColor01E[128];
   unsigned long Reserved06[124];
   unsigned long FontF;
   unsigned long ClipPoint0F;
   unsigned long ClipPoint1F;
   unsigned long Color1F;
   unsigned long CharacterColor1F[256];
   unsigned long Reserved07[252];
   unsigned long FontG;
   unsigned long ClipPoint0G;
   unsigned long ClipPoint1G;
   unsigned long Color1G;
   Nv04aTypedef::__unnamed CharacterColor1G[256];
} Nv04aTypedef;

typedef struct Nv049Typedef::__unnamed
{
   unsigned long offset;
   unsigned long format;
} Nv049Typedef::__unnamed;

typedef struct Nv049Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long StopImage[2];
   unsigned long StopLut[2];
   unsigned long StopCursorImage[2];
   unsigned long StopDac[2];
   unsigned long Reserved00[22];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage[2];
   unsigned long SetContextDmaLut[2];
   unsigned long SetContextDmaCursor[2];
   unsigned long Reserved01[88];
   unsigned long GetOffset;
   Nv049Typedef::__unnamed SetImage[2];
   Nv049Typedef::__unnamed SetLut[2];
   Nv049Typedef::__unnamed SetCursorImage[2];
   unsigned long SetCursorPoint;
   unsigned long Reserved03[3];
   Nv049Typedef::__unnamed SetDac[2];
   unsigned long Reserved04[1828];
} Nv049Typedef;

typedef struct Nv047Typedef::__unnamed
{
   unsigned long reserved05[23];
   unsigned long colorKey;
   unsigned long offset;
   unsigned long sizeIn;
   unsigned long pointIn;
   unsigned long dsDx;
   unsigned long dtDy;
   unsigned long pointOut;
   unsigned long sizeOut;
   unsigned long format;
} Nv047Typedef::__unnamed;

typedef struct Nv047Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[6];
   unsigned long StopOverlay[2];
   unsigned long Reserved01[22];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved02[6];
   unsigned long SetContextDmaOverlay[2];
   unsigned long Reserved03[86];
   unsigned long GetOffset;
   unsigned long Reserved04[64];
   Nv047Typedef::__unnamed SetOverlay[2];
   unsigned long SetOverlayPointOutA;
   unsigned long Reserved06[1727];
} Nv047Typedef;

typedef struct Nv046Typedef::__unnamed
{
   unsigned long offset;
   unsigned long format;
} Nv046Typedef::__unnamed;

typedef struct Nv046Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long StopImage[2];
   unsigned long StopLut[2];
   unsigned long StopCursorImage[2];
   unsigned long StopDac[2];
   unsigned long Reserved00[22];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage[2];
   unsigned long SetContextDmaLut[2];
   unsigned long SetContextDmaCursor[2];
   unsigned long Reserved01[88];
   unsigned long GetOffset;
   Nv046Typedef::__unnamed SetImage[2];
   Nv046Typedef::__unnamed SetLut[2];
   Nv046Typedef::__unnamed SetCursorImage[2];
   unsigned long SetCursorPoint;
   unsigned long Reserved03[3];
   Nv046Typedef::__unnamed SetDac[2];
   unsigned long Reserved04[1824];
} Nv046Typedef;

typedef struct Nv045Typedef::__unnamed
{
   unsigned long offset;
   unsigned long size;
   unsigned long format;
} Nv045Typedef::__unnamed;

typedef struct Nv045Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long StopTransfer;
   unsigned long Reserved00[29];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage[2];
   unsigned long SetContextDmaLut;
   unsigned long SetContextDmaCursor;
   unsigned long Reserved01[91];
   Nv045Typedef::__unnamed SetImage[2];
   unsigned long GetImageOffsetNotify[2];
   unsigned long SetLut[2];
   unsigned long SetCursorImage[2];
   unsigned long SetCursorPoint[2];
   unsigned long SetEncoder[2];
   unsigned long Reserved02[1840];
} Nv045Typedef;

typedef struct Nv044Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   unsigned long SetColorFormat;
   unsigned long SetMonochromeFormat;
   unsigned long SetMonochromeShape;
   unsigned long SetPatternSelect;
   unsigned long SetMonochromeColor0;
   unsigned long SetMonochromeColor1;
   unsigned long SetMonochromePattern0;
   unsigned long SetMonochromePattern1;
   unsigned long Reserved02[56];
   unsigned long SetPatternY8[16];
   unsigned long Reserved03[48];
   unsigned long SetPatternR5G6B5[32];
   unsigned long Reserved04[32];
   unsigned long SetPatternX1R5G5B5[32];
   unsigned long Reserved05[32];
   unsigned long SetPatternX8R8G8B8[64];
   unsigned long Reserved06[1536];
} Nv044Typedef;

typedef struct Nv043Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   unsigned long SetRop5;
   unsigned long Reserved02[1855];
} Nv043Typedef;

typedef struct Nv042Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImageSource;
   unsigned long SetContextDmaImageDestin;
   unsigned long Reserved01[93];
   unsigned long SetColorFormat;
   unsigned long SetPitch;
   unsigned long SetOffsetSource;
   unsigned long SetOffsetDestin;
   unsigned long Reserved02[1852];
} Nv042Typedef;

typedef struct Nv041Typedef::__unnamed
{
   unsigned long offset;
   unsigned long size;
   unsigned long format;
} Nv041Typedef::__unnamed;

typedef struct Nv041Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long StopTransfer;
   unsigned long Reserved00[29];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage[2];
   unsigned long SetContextDmaLut;
   unsigned long SetContextDmaCursor;
   unsigned long Reserved01[91];
   Nv041Typedef::__unnamed SetImage[2];
   unsigned long GetImageOffsetNotify[2];
   unsigned long SetLut[2];
   unsigned long SetCursorImage[2];
   unsigned long SetCursorPoint[2];
   unsigned long SetEncoder[2];
   unsigned long Reserved02[1840];
} Nv041Typedef;

typedef struct Nv040Typedef
{
   unsigned long Reserved00[1984];
} Nv040Typedef;

typedef struct Nv03fTypedef
{
   unsigned long Reserved00[1984];
} Nv03fTypedef;

typedef struct Nv03eTypedef
{
   unsigned long Reserved00[1984];
} Nv03eTypedef;

typedef struct Nv03dTypedef
{
   unsigned long Reserved00[1984];
} Nv03dTypedef;

typedef struct Nv039Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaBufferIn;
   unsigned long SetContextDmaBufferOut;
   unsigned long Reserved01[96];
   unsigned long OffsetIn;
   unsigned long OffsetOut;
   long PitchIn;
   long PitchOut;
   unsigned long LineLengthIn;
   unsigned long LineCount;
   unsigned long Format;
   unsigned long BufferNotify;
   unsigned long Reserved02[1845];
} Nv039Typedef;

typedef struct Nv038Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaOverlay;
   unsigned long SetContextDmaImageIn;
   unsigned long SetContextDmaImageOut;
   unsigned long Reserved01[92];
   unsigned long ImageOutPoint;
   unsigned long ImageOutSize;
   unsigned long ImageOutFormat;
   unsigned long ImageOutOffset;
   unsigned long ImageInDeltaDuDx;
   unsigned long ImageInDeltaDvDy;
   unsigned long ImageInSize;
   unsigned long ImageInFormat;
   unsigned long ImageInOffset;
   unsigned long ImageInPoint;
   unsigned long OverlayDeltaDuDx;
   unsigned long OverlayDeltaDvDy;
   unsigned long OverlaySize;
   unsigned long OverlayFormat;
   unsigned long OverlayOffset;
   unsigned long OverlayPoint;
   unsigned long Reserved02[1840];
} Nv038Typedef;

typedef struct Nv037Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextSurface;
   unsigned long Reserved01[90];
   unsigned long SetColorFormat;
   unsigned long SetOperation;
   unsigned long ClipPoint;
   unsigned long ClipSize;
   unsigned long ImageOutPoint;
   unsigned long ImageOutSize;
   unsigned long DeltaDuDx;
   unsigned long DeltaDvDy;
   unsigned long Reserved02[56];
   unsigned long ImageInSize;
   unsigned long ImageInPitch;
   unsigned long ImageInOffset;
   unsigned long ImageInPoint;
   unsigned long Reserved03[1788];
} Nv037Typedef;

typedef struct Nv036Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextColorKey;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextSurface;
   unsigned long Reserved01[89];
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long SizeIn;
   unsigned long DeltaDxDu;
   unsigned long DeltaDyDv;
   unsigned long ClipPoint;
   unsigned long ClipSize;
   unsigned long Point12d4;
   unsigned long Reserved02[57];
   unsigned long Color[1792];
} Nv036Typedef;

typedef struct Nv030Typedef
{
   unsigned long Reserved00[1984];
} Nv030Typedef;

typedef struct Nv021Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextColorKey;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextSurface;
   unsigned long Reserved01[88];
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long Point;
   unsigned long SizeOut;
   unsigned long SizeIn;
   unsigned long Reserved02[60];
   unsigned long Color[32];
   unsigned long Reserved03[1760];
} Nv021Typedef;

typedef struct Nv01fTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextColorKey;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextSurfaceSource;
   unsigned long SetContextSurfaceDestin;
   unsigned long Reserved01[87];
   unsigned long SetOperation;
   unsigned long ControlPointIn;
   unsigned long ControlPointOut;
   unsigned long Size;
   unsigned long Reserved02[1853];
} Nv01fTypedef;

typedef struct Nv01eTypedef::__unnamed
{
   unsigned long point;
   unsigned long size;
} Nv01eTypedef::__unnamed;

typedef struct Nv01eTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextSurface;
   unsigned long Reserved01[89];
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long Color;
   unsigned long Reserved02[62];
   Nv01eTypedef::__unnamed Rectangle[16];
   unsigned long Reserved03[1760];
} Nv01eTypedef;

typedef struct Nv01dTypedef::__unnamed
{
   long x;
   long y;
} Nv01dTypedef::__unnamed;

typedef struct Nv01dTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextSurface;
   unsigned long Reserved01[89];
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long Color;
   unsigned long Reserved02[2];
   unsigned long TrianglePoint0;
   unsigned long TrianglePoint1;
   unsigned long TrianglePoint2;
   unsigned long Reserved03[1];
   long Triangle32Point0X;
   long Triangle32Point0Y;
   long Triangle32Point1X;
   long Triangle32Point1Y;
   long Triangle32Point2X;
   long Triangle32Point2Y;
   unsigned long Reserved04[50];
   unsigned long Trimesh[32];
   Nv01dTypedef::__unnamed Trimesh32[16];
   Nv01dTypedef::__unnamed ColorTriangle[8];
   Nv01dTypedef::__unnamed ColorTrimesh[16];
   unsigned long Reserved05[1664];
} Nv01dTypedef;

typedef struct Nv01cTypedef::__unnamed
{
   unsigned long point0;
   unsigned long point1;
} Nv01cTypedef::__unnamed;

typedef struct Nv01cTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextSurface;
   unsigned long Reserved01[89];
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long Color;
   unsigned long Reserved02[62];
   Nv01cTypedef::__unnamed Lin[16];
   Nv01cTypedef::__unnamed Lin32[8];
   unsigned long PolyLin[32];
   Nv01cTypedef::__unnamed PolyLin32[16];
   Nv01cTypedef::__unnamed ColorPolyLin[16];
   unsigned long Reserved03[1632];
} Nv01cTypedef;

typedef struct Nv019Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   unsigned long SetPoint;
   unsigned long SetSize;
   unsigned long Reserved02[1854];
} Nv019Typedef;

typedef struct Nv018Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   unsigned long SetColorFormat;
   unsigned long SetMonochromeFormat;
   unsigned long SetMonochromeShape;
   unsigned long Reserved02[1];
   unsigned long SetMonochromeColor0;
   unsigned long SetMonochromeColor1;
   unsigned long SetMonochromePattern0;
   unsigned long SetMonochromePattern1;
   unsigned long Reserved03[1848];
} Nv018Typedef;

typedef struct Nv017Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   unsigned long SetColorFormat;
   unsigned long SetColor;
   unsigned long Reserved02[1854];
} Nv017Typedef;

typedef struct Nv012Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   unsigned long SetBeta1d31;
   unsigned long Reserved02[1855];
} Nv012Typedef;

typedef struct _Nv005Typedef
{
   unsigned long Reserved00[1984];
} Nv005Typedef;

typedef struct Nv004Typedef::__unnamed
{
   unsigned long nanoseconds[2];
} Nv004Typedef::__unnamed;

typedef struct Nv004Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long StopTransfer;
   unsigned long Reserved00[29];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved01[95];
   Nv004Typedef::__unnamed SetAlarmTime;
   unsigned long Reserved02[1];
   unsigned long SetAlarmNotify;
   unsigned long Reserved03[1852];
} Nv004Typedef;

typedef struct Nv003Typedef
{
   unsigned long Reserved00[1984];
} Nv003Typedef;

typedef struct Nv002Typedef
{
   unsigned long Reserved00[1984];
} Nv002Typedef;

typedef struct Nv001Typedef
{
   unsigned long Reserved00[1984];
} Nv001Typedef;

typedef struct Nv000Typedef
{
   unsigned long Reserved00[1984];
} Nv000Typedef;

typedef struct Nv04ControlPio
{
   unsigned long Reserved00[3];
   short Free;
   short Zero[3];
   unsigned long Reserved01[58];
} Nv04ControlPio;

typedef struct Nv04SubchannelPio
{
   unsigned long SetObject;
   volatile Nv04ControlPio control;
   union {
   volatile Nv000Typedef Nv01Root;
   volatile Nv001Typedef Nv01Class;
   volatile Nv002Typedef Nv01ContextDmaFromMemory;
   volatile Nv003Typedef Nv01ContextDmaToMemory;
   volatile Nv004Typedef Nv01Timer;
   volatile _Nv005Typedef Nv01Event;
   unsigned long NV006_TYPEDEF;
   unsigned long NV007_TYPEDEF;
   unsigned long NV008_TYPEDEF;
   unsigned long NV009_TYPEDEF;
   unsigned long NV00A_TYPEDEF;
   unsigned long NV00B_TYPEDEF;
   unsigned long NV00C_TYPEDEF;
   unsigned long NV00D_TYPEDEF;
   unsigned long NV00E_TYPEDEF;
   unsigned long NV00F_TYPEDEF;
   unsigned long NV010_TYPEDEF;
   unsigned long NV011_TYPEDEF;
   volatile Nv012Typedef Nv01ContextBeta;
   unsigned long NV013_TYPEDEF;
   unsigned long NV014_TYPEDEF;
   unsigned long NV015_TYPEDEF;
   unsigned long NV016_TYPEDEF;
   volatile Nv017Typedef Nv01ContextColorKey;
   volatile Nv018Typedef Nv01ContextPattern;
   volatile Nv019Typedef Nv01ContextClipRectangle;
   unsigned long NV01A_TYPEDEF;
   unsigned long NV01B_TYPEDEF;
   volatile Nv01cTypedef Nv01RenderSolidLin;
   volatile Nv01dTypedef Nv01RenderSolidTriangle;
   volatile Nv01eTypedef Nv01RenderSolidRectangle;
   volatile Nv01fTypedef Nv01ImageBlit;
   unsigned long NV020_TYPEDEF;
   volatile Nv021Typedef Nv01ImageFromCpu;
   unsigned long NV022_TYPEDEF;
   unsigned long NV023_TYPEDEF;
   unsigned long NV024_TYPEDEF;
   unsigned long NV025_TYPEDEF;
   unsigned long NV026_TYPEDEF;
   unsigned long NV027_TYPEDEF;
   unsigned long NV028_TYPEDEF;
   unsigned long NV029_TYPEDEF;
   unsigned long NV02A_TYPEDEF;
   unsigned long NV02B_TYPEDEF;
   unsigned long NV02C_TYPEDEF;
   unsigned long NV02D_TYPEDEF;
   unsigned long NV02E_TYPEDEF;
   unsigned long NV02F_TYPEDEF;
   volatile Nv030Typedef Nv01Null;
   unsigned long NV031_TYPEDEF;
   unsigned long NV032_TYPEDEF;
   unsigned long NV033_TYPEDEF;
   unsigned long NV034_TYPEDEF;
   unsigned long NV035_TYPEDEF;
   volatile Nv036Typedef Nv03StretchedImageFromCpu;
   volatile Nv037Typedef Nv03ScaledImageFromMemory;
   volatile Nv038Typedef Nv04DvdSubpicture;
   volatile Nv039Typedef Nv03MemoryToMemoryFormat;
   unsigned long NV03A_TYPEDEF;
   unsigned long NV03B_TYPEDEF;
   unsigned long NV03C_TYPEDEF;
   volatile Nv03dTypedef Nv01ContextDmaInMemory;
   volatile Nv03eTypedef Nv01ContextErrorToMemory;
   volatile Nv03fTypedef Nv01MemoryLocalPrivileged;
   volatile Nv040Typedef Nv01MemoryLocalUser;
   volatile Nv041Typedef Nv03VideoLutCursorPal;
   volatile Nv042Typedef Nv04ContextSurfaces2d;
   volatile Nv043Typedef Nv03ContextRop;
   volatile Nv044Typedef Nv04ContextPattern;
   volatile Nv045Typedef Nv03VideoLutCursorNtsc;
   volatile Nv046Typedef Nv04VideoLutCursorDac;
   volatile Nv047Typedef Nv04VideoOverlay;
   volatile Nv048Typedef Nv03Dx3TexturedTriangle;
   volatile Nv049Typedef NV05VideoLutCursorDac;
   volatile Nv04aTypedef Nv04GdiRectangleText;
   volatile Nv04bTypedef Nv03GdiRectangleText;
   unsigned long NV04C_TYPEDEF;
   volatile Nv04dTypedef Nv03ExternalVideoDecoder;
   volatile Nv04eTypedef Nv03ExternalVideoDecompressor;
   volatile Nv04fTypedef Nv01ExternalParallelBus;
   volatile Nv050Typedef Nv03ExternalMonitorBus;
   volatile Nv051Typedef Nv04ExternalSerialBus;
   volatile Nv052Typedef Nv04ContextSurfaceSwizzled;
   volatile Nv053Typedef Nv04ContextSurfaces3d;
   volatile Nv054Typedef Nv04Dx5TexturedTriangle;
   volatile Nv055Typedef Nv04Dx6MultiTextureTriangle;
   unsigned long Nv12CelsiusPrimitive;
   volatile Nv057Typedef Nv04ContextColorKey;
   volatile Nv058Typedef Nv03ContextSurface2dDestination;
   volatile Nv059Typedef Nv03ContextSurface2dSource;
   volatile Nv05aTypedef Nv03ContextSurface3dColor;
   volatile Nv05bTypedef Nv03ContextSurface3dDepth;
   volatile Nv05cTypedef Nv04RenderSolidLin;
   volatile Nv05dTypedef Nv04RenderSolidTriangle;
   volatile Nv05eTypedef Nv04RenderSolidRectangle;
   volatile Nv05fTypedef Nv04ImageBlit;
   volatile Nv060Typedef Nv04IndexedImageFromCpu;
   volatile Nv061Typedef Nv04ImageFromCpu;
   volatile Nv062Typedef Nv10ContextSurfaces2d;
   volatile Nv063Typedef Nv05ScaledImageFromMemory;
   volatile Nv064Typedef Nv05IndexedImageFromCpu;
   volatile Nv065Typedef Nv05ImageFromCpu;
   volatile _Nv066Typedef Nv05StretchedImageFromCpu;
   volatile Nv067Typedef Nv10VideoLutCursorDac;
   volatile Nv06fTypedef Nv04HeapOwner;
   unsigned long NV070_TYPEDEF;
   unsigned long NV071_TYPEDEF;
   volatile Nv072Typedef Nv04ContextBeta;
   unsigned long NV073_TYPEDEF;
   unsigned long NV074_TYPEDEF;
   unsigned long NV075_TYPEDEF;
   volatile Nv076Typedef Nv04StretchedImageFromCpu;
   volatile Nv077Typedef Nv04ScaledImageFromMemory;
   unsigned long NV078_TYPEDEF;
   unsigned long NV079_TYPEDEF;
   volatile Nv07aTypedef Nv10VideoOverlay;
   volatile Nv07bTypedef Nv10TextureFromCpu;
   volatile Nv07cTypedef Nv12VideoLutCursorDac;
   unsigned long NV07D_TYPEDEF;
   unsigned long NV07E_TYPEDEF;
   unsigned long NV07F_TYPEDEF;
   volatile Nv080Typedef Nv01Device0;
   volatile Nv081Typedef Nv01Device1;
   volatile Nv082Typedef Nv01Device2;
   volatile Nv083Typedef Nv01Device3;
   volatile Nv084Typedef Nv01Device4;
   volatile Nv085Typedef Nv01Device5;
   volatile Nv086Typedef Nv01Device6;
   volatile Nv087Typedef Nv01Device7;
   volatile Nv088Typedef Nv10DvdSubpicture;
   volatile Nv089Typedef Nv10ScaledImageFromMemory;
   volatile Nv093Typedef Nv10ContextSurfaces3d;
   volatile Nv094Typedef Nv10Dx5TexturedTriangle;
   volatile Nv095Typedef Nv10Dx6MultiTextureTriangle;
   unsigned long Nv20KelvinPrimitive;
   volatile Nv1189Typedef Nv11ScaledImageFromMemory;
   volatile Nv205fTypedef Nv20ImageBlit;
   unsigned long NVFF0_TYPEDEF;
   unsigned long NVFF1_TYPEDEF;
   unsigned long NVFF2_TYPEDEF;
   unsigned long NVFF3_TYPEDEF;
   unsigned long NVFF4_TYPEDEF;
   volatile Nvff5Typedef NvContextErrorToMemory;
   volatile Nvff6Typedef NvVideoColorKey;
   volatile Nvff7Typedef NvVideoScaler;
   volatile Nvff8Typedef NvVideoFromMemory;
   volatile Nvff9Typedef NvVideoColormap;
   volatile NvffaTypedef NvVideoSink;
   volatile NvffbTypedef NvPatchcordVideo;
   volatile NvffcTypedef NvContextDmaInMemory;
   volatile NvffdTypedef NvContextDmaToMemory;
   volatile NvffeTypedef NvContextDmaFromMemory;
   volatile NvfffTypedef NvClass;
   };
} Nv04SubchannelPio;

typedef struct Nv04bTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextSurface;
   unsigned long Reserved01[90];
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long SetMonochromeFormat;
   unsigned long Reserved02[61];
   unsigned long Color1A;
   Nv04bTypedef::__unnamed UnclippedRectangle[64];
   unsigned long Reserved03[125];
   unsigned long ClipPoint0B;
   unsigned long ClipPoint1B;
   unsigned long Color1B;
   Nv04bTypedef::__unnamed ClippedRectangle[64];
   unsigned long Reserved04[123];
   unsigned long ClipPoint0C;
   unsigned long ClipPoint1C;
   unsigned long Color1C;
   unsigned long SizeC;
   unsigned long PointC;
   unsigned long MonochromeColor1C[128];
   unsigned long Reserved05[122];
   unsigned long ClipPoint0D;
   unsigned long ClipPoint1D;
   unsigned long Color1D;
   unsigned long SizeInD;
   unsigned long SizeOutD;
   unsigned long PointD;
   unsigned long MonochromeColor1D[128];
   unsigned long Reserved06[121];
   unsigned long ClipPoint0E;
   unsigned long ClipPoint1E;
   unsigned long Color0E;
   unsigned long Color1E;
   unsigned long SizeInE;
   unsigned long SizeOutE;
   unsigned long PointE;
   unsigned long MonochromeColor01E[128];
   unsigned long Reserved07[640];
} Nv04bTypedef;

typedef struct Nv04bTypedef::__unnamed
{
   unsigned long point;
   unsigned long size;
} Nv04bTypedef::__unnamed;

typedef struct _UNICODE_PREFIX_TABLE_ENTRY
{
   short NodeTypeCode;
   short NameLength;
   _UNICODE_PREFIX_TABLE_ENTRY * NextPrefixTree;
   _UNICODE_PREFIX_TABLE_ENTRY * CaseMatch;
   _RTL_SPLAY_LINKS Links;
   _UNICODE_STRING * Prefix;
} UNICODE_PREFIX_TABLE_ENTRY;

typedef struct _STRING32
{
   short Length;
   short MaximumLength;
   unsigned long Buffer;
} STRING32;

typedef struct _BY_HANDLE_FILE_INFORMATION
{
   unsigned long dwFileAttributes;
   _FILETIME ftCreationTime;
   _FILETIME ftLastAccessTime;
   _FILETIME ftLastWriteTime;
   unsigned long dwVolumeSerialNumber;
   unsigned long nFileSizeHigh;
   unsigned long nFileSizeLow;
   unsigned long nNumberOfLinks;
   unsigned long nFileIndexHigh;
   unsigned long nFileIndexLow;
} BY_HANDLE_FILE_INFORMATION;

typedef struct _FILETIME
{
   unsigned long dwLowDateTime;
   unsigned long dwHighDateTime;
} FILETIME;

typedef struct _FILE_PIPE_LOCAL_INFORMATION
{
   unsigned long NamedPipeType;
   unsigned long NamedPipeConfiguration;
   unsigned long MaximumInstances;
   unsigned long CurrentInstances;
   unsigned long InboundQuota;
   unsigned long ReadDataAvailable;
   unsigned long OutboundQuota;
   unsigned long WriteQuotaAvailable;
   unsigned long NamedPipeState;
   unsigned long NamedPipeEnd;
} FILE_PIPE_LOCAL_INFORMATION;

typedef union _IMAGE_AUX_SYMBOL
{
   union {
   _IMAGE_AUX_SYMBOL::__unnamed Sym;
   _IMAGE_AUX_SYMBOL::__unnamed File;
   _IMAGE_AUX_SYMBOL::__unnamed Section;
   };
} IMAGE_AUX_SYMBOL;

typedef struct _IMAGE_AUX_SYMBOL::__unnamed
{
   unsigned long TagIndex;
   _IMAGE_AUX_SYMBOL::__unnamed::__unnamed Misc;
   _IMAGE_AUX_SYMBOL::__unnamed::__unnamed FcnAry;
   short TvIndex;
} IMAGE_AUX_SYMBOL::__unnamed;

typedef union _IMAGE_AUX_SYMBOL::__unnamed::__unnamed
{
   union {
   _IMAGE_AUX_SYMBOL::__unnamed::__unnamed::__unnamed LnSz;
   unsigned long TotalSize;
   };
} IMAGE_AUX_SYMBOL::__unnamed::__unnamed;

typedef struct _IMAGE_AUX_SYMBOL::__unnamed::__unnamed::__unnamed
{
   short Linenumber;
   short Size;
} IMAGE_AUX_SYMBOL::__unnamed::__unnamed::__unnamed;

typedef struct _s__RTTICompleteObjectLocator
{
   unsigned long signature;
   unsigned long offset;
   unsigned long cdOffset;
   _TypeDescriptor * pTypeDescriptor;
   const _s__RTTIClassHierarchyDescriptor * pClassDescriptor;
} s__RTTICompleteObjectLocator;

typedef struct _s__RTTIBaseClassDescriptor
{
   _TypeDescriptor * pTypeDescriptor;
   unsigned long numContainedBases;
   _PMD where;
   unsigned long attributes;
} s__RTTIBaseClassDescriptor;

typedef struct _s__RTTIBaseClassArray
{
   const _s__RTTIBaseClassDescriptor * arrayOfBaseClassDescriptors[0];
} s__RTTIBaseClassArray;

typedef struct _s__RTTIClassHierarchyDescriptor
{
   unsigned long signature;
   unsigned long attributes;
   unsigned long numBaseClasses;
   const _s__RTTIBaseClassArray * pBaseClassArray;
} s__RTTIClassHierarchyDescriptor;

typedef struct _D3DXEFFECT_DESC
{
   int Parameters;
   int Techniques;
   unsigned long Usage;
} D3DXEFFECT_DESC;

typedef struct _DRIVER_VERIFIER_THUNK_PAIRS
{
   void * PristineRoutine;
   void * NewRoutine;
} DRIVER_VERIFIER_THUNK_PAIRS;

typedef struct _FILE_MODE_INFORMATION
{
   unsigned long Mode;
} FILE_MODE_INFORMATION;

typedef struct _IMAGE_OPTIONAL_HEADER64
{
   short Magic;
   unsigned char MajorLinkerVersion;
   unsigned char MinorLinkerVersion;
   unsigned long SizeOfCode;
   unsigned long SizeOfInitializedData;
   unsigned long SizeOfUninitializedData;
   unsigned long AddressOfEntryPoint;
   unsigned long BaseOfCode;
   __int64 ImageBase;
   unsigned long SectionAlignment;
   unsigned long FileAlignment;
   short MajorOperatingSystemVersion;
   short MinorOperatingSystemVersion;
   short MajorImageVersion;
   short MinorImageVersion;
   short MajorSubsystemVersion;
   short MinorSubsystemVersion;
   unsigned long Win32VersionValue;
   unsigned long SizeOfImage;
   unsigned long SizeOfHeaders;
   unsigned long CheckSum;
   short Subsystem;
   short DllCharacteristics;
   __int64 SizeOfStackReserve;
   __int64 SizeOfStackCommit;
   __int64 SizeOfHeapReserve;
   __int64 SizeOfHeapCommit;
   unsigned long LoaderFlags;
   unsigned long NumberOfRvaAndSizes;
   _IMAGE_DATA_DIRECTORY DataDirectory[16];
} IMAGE_OPTIONAL_HEADER64;

typedef struct _IMAGE_DATA_DIRECTORY
{
   unsigned long VirtualAddress;
   unsigned long Size;
} IMAGE_DATA_DIRECTORY;

typedef struct _XMETAL_PushBuffer
{
   unsigned long * m_pPut;
   unsigned long * m_pThreshold;
} XMETAL_PushBuffer;

typedef struct in_addr::__unnamed::__unnamed
{
   unsigned char s_b1;
   unsigned char s_b2;
   unsigned char s_b3;
   unsigned char s_b4;
} in_addr::__unnamed::__unnamed;

typedef union in_addr::__unnamed
{
   union {
   in_addr::__unnamed::__unnamed S_un_b;
   in_addr::__unnamed::__unnamed S_un_w;
   unsigned long S_addr;
   };
} in_addr::__unnamed;

typedef struct in_addr
{
   in_addr::__unnamed S_un;
} in_addr;

typedef struct _DS3DBUFFER
{
   unsigned long dwSize;
   D3DXVECTOR3 vPosition;
   D3DXVECTOR3 vVelocity;
   unsigned long dwInsideConeAngle;
   unsigned long dwOutsideConeAngle;
   D3DXVECTOR3 vConeOrientation;
   long lConeOutsideVolume;
   float flMinDistance;
   float flMaxDistance;
   unsigned long dwMode;
   (type???) public: __thiscall _DS3DBUFFER::_DS3DBUFFER(void);
} DS3DBUFFER;

typedef struct _RTL_DRIVE_LETTER_CURDIR
{
   short Flags;
   short Length;
   unsigned long TimeStamp;
   _STRING DosPath;
} RTL_DRIVE_LETTER_CURDIR;

typedef struct Nv083Typedef
{
   unsigned long Reserved00[1984];
} Nv083Typedef;

typedef struct _POINTL
{
   long x;
   long y;
} POINTL;

typedef struct HWINSTA__
{
   int unused;
} HWINSTA__;

typedef struct _PORT_MESSAGE
{
    unsigned char u1[4];
    unsigned char u2[4];
   union {
   _CLIENT_ID ClientId;
   double DoNotUseThisField;
   };
   unsigned long MessageId;
   union {
   unsigned long ClientViewSize;
   unsigned long CallbackId;
   };
} PORT_MESSAGE;

typedef struct _D3DPRESENT_PARAMETERS_
{
   int BackBufferWidth;
   int BackBufferHeight;
   int BackBufferFormat;
   int BackBufferCount;
   unsigned long MultiSampleType;
   int SwapEffect;
   HWND__ * hDeviceWindow;
   int Windowed;
   int EnableAutoDepthStencil;
   int AutoDepthStencilFormat;
   unsigned long Flags;
   int FullScreen_RefreshRateInHz;
   int FullScreen_PresentationInterval;
} D3DPRESENT_PARAMETERS_;

typedef struct HWND__
{
   int unused;
} HWND__;

typedef struct HKL__
{
   int unused;
} HKL__;

typedef struct _SYSTEM_SET_TIME_ADJUST_INFORMATION
{
   unsigned long TimeAdjustment;
   unsigned char Enable;
} SYSTEM_SET_TIME_ADJUST_INFORMATION;

typedef struct _RTL_RELATIVE_NAME
{
   _STRING RelativeName;
   void * ContainingDirectory;
} RTL_RELATIVE_NAME;

typedef struct _LDT_ENTRY
{
   short LimitLow;
   short BaseLow;
   _LDT_ENTRY::__unnamed HighWord;
} LDT_ENTRY;

typedef union _LDT_ENTRY::__unnamed
{
   union {
   _LDT_ENTRY::__unnamed::__unnamed Bytes;
   _LDT_ENTRY::__unnamed::__unnamed Bits;
   };
} LDT_ENTRY::__unnamed;

typedef struct _LDT_ENTRY::__unnamed::__unnamed
{
   unsigned char BaseMid;
   unsigned char Flags1;
   unsigned char Flags2;
   unsigned char BaseHi;
} LDT_ENTRY::__unnamed::__unnamed;

typedef struct _FLOAT128
{
   __int64 LowPart;
   __int64 HighPart;
} FLOAT128;

typedef struct Nv053Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaColor;
   unsigned long SetContextDmaZeta;
   unsigned long Reserved01[91];
   unsigned long SetClipHorizontal;
   unsigned long SetClipVertical;
   unsigned long SetFormat;
   unsigned long SetClipSize;
   unsigned long SetPitch;
   unsigned long SetOffsetColor;
   unsigned long SetOffsetZeta;
   unsigned long Reserved02[1851];
} Nv053Typedef;

typedef struct Nv052Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage;
   unsigned long Reserved01[94];
   unsigned long SetFormat;
   unsigned long SetOffset;
   unsigned long Reserved02[1854];
} Nv052Typedef;

typedef struct _KMUTANT
{
   _DISPATCHER_HEADER Header;
   _LIST_ENTRY MutantListEntry;
   _KTHREAD * OwnerThread;
   unsigned char Abandoned;
} KMUTANT;

typedef struct _SECURITY_TOKEN_PROXY_DATA
{
   unsigned long Length;
   int ProxyClass;
   _UNICODE_STRING PathInfo;
   unsigned long ContainerMask;
   unsigned long ObjectMask;
} SECURITY_TOKEN_PROXY_DATA;

typedef struct IDirectXFileBinary
{
   union {
   (type???) IDirectXFileObject;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) GetName;
   (type???) GetId;
   (type???) GetSize;
   (type???) GetMimeType;
   (type???) Read;
   (type???) IDirectXFileBinary;
   (type???) IDirectXFileBinary;
   };
} IDirectXFileBinary;

typedef struct _DSEFFECTMAP
{
   void * lpvCodeSegment;
   unsigned long dwCodeSize;
   void * lpvStateSegment;
   unsigned long dwStateSize;
   void * lpvYMemorySegment;
   unsigned long dwYMemorySize;
   void * lpvScratchSegment;
   unsigned long dwScratchSize;
} DSEFFECTMAP;

typedef struct _DSEFFECTIMAGEDESC
{
   unsigned long dwEffectCount;
   unsigned long dwTotalScratchSize;
   _DSEFFECTMAP aEffectMaps[1];
} DSEFFECTIMAGEDESC;

typedef struct _RTL_HEAP_ENTRY
{
   unsigned long Size;
   short Flags;
   short AllocatorBackTraceIndex;
   _RTL_HEAP_ENTRY::__unnamed u;
} RTL_HEAP_ENTRY;

typedef union _RTL_HEAP_ENTRY::__unnamed
{
   union {
   _RTL_HEAP_ENTRY::__unnamed::__unnamed s1;
   _RTL_HEAP_ENTRY::__unnamed::__unnamed s2;
   };
} RTL_HEAP_ENTRY::__unnamed;

typedef struct _RTL_HEAP_ENTRY::__unnamed::__unnamed
{
   unsigned long Settable;
   unsigned long Tag;
} RTL_HEAP_ENTRY::__unnamed::__unnamed;

typedef struct _SYSTEM_OBJECTTYPE_INFORMATION
{
   unsigned long NextEntryOffset;
   unsigned long NumberOfObjects;
   unsigned long NumberOfHandles;
   unsigned long TypeIndex;
   unsigned long InvalidAttributes;
   _GENERIC_MAPPING GenericMapping;
   unsigned long ValidAccessMask;
   unsigned long PoolType;
   unsigned char SecurityRequired;
   unsigned char WaitableObject;
   unsigned char Padding10;
   unsigned char Padding11;
   _STRING TypeName;
} SYSTEM_OBJECTTYPE_INFORMATION;

typedef struct _STRING
{
   short Length;
   short MaximumLength;
   char * Buffer;
} STRING;

typedef struct _GENERIC_MAPPING
{
   unsigned long GenericRead;
   unsigned long GenericWrite;
   unsigned long GenericExecute;
   unsigned long GenericAll;
} GENERIC_MAPPING;

typedef struct tWAVEFORMATEX
{
   short wFormatTag;
   short nChannels;
   unsigned long nSamplesPerSec;
   unsigned long nAvgBytesPerSec;
   short nBlockAlign;
   short wBitsPerSample;
   short cbSize;
} tWAVEFORMATEX;

typedef struct xbox_adpcmwaveformat_tag
{
   tWAVEFORMATEX wfx;
   short wSamplesPerBlock;
} xbox_adpcmwaveformat_tag;

typedef struct _DSFX_ECHO_STEREO_PARAMS
{
   _DSFX_ECHO_STEREO_STATE State;
   unsigned long dwGain;
} DSFX_ECHO_STEREO_PARAMS;

typedef struct _NLSTABLEINFO
{
   _CPTABLEINFO OemTableInfo;
   _CPTABLEINFO AnsiTableInfo;
   short * UpperCaseTable;
   short * LowerCaseTable;
} NLSTABLEINFO;

typedef struct D3DBaseTexture
{
   union {
   (type???) D3DPixelContainer;
   (type???) GetLevelCount;
   };
} D3DBaseTexture;

typedef struct D3DPixelContainer
{
   union {
   (type???) D3DResource;
   unsigned long Padding1;
   };
   unsigned long Padding2;
   unsigned long Padding3;
   unsigned long Format;
   unsigned long Size;
} D3DPixelContainer;

typedef struct HRGN__
{
   int unused;
} HRGN__;

typedef struct Nv07aTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[6];
   unsigned long StopOverlay[2];
   unsigned long Reserved01[22];
   unsigned long SetContextDmaNotifies;
   unsigned long Reserved02[6];
   unsigned long SetContextDmaOverlay[2];
   unsigned long Reserved03[151];
   Nv07aTypedef::__unnamed SetOverlay[2];
   unsigned long SetOverlayPointOutA;
   unsigned long SetOverlayLuminanceA;
   unsigned long SetOverlayChrominanceA;
   unsigned long Reserved04[1725];
} Nv07aTypedef;

typedef struct Nv07aTypedef::__unnamed
{
   unsigned long reserved05[21];
   unsigned long luminance;
   unsigned long chrominance;
   unsigned long colorKey;
   unsigned long offset;
   unsigned long sizeIn;
   unsigned long pointIn;
   unsigned long duDx;
   unsigned long dvDy;
   unsigned long pointOut;
   unsigned long sizeOut;
   unsigned long format;
} Nv07aTypedef::__unnamed;

typedef struct fd_set
{
   int fd_count;
   int fd_array[64];
} fd_set;

typedef struct HGLRC__
{
   int unused;
} HGLRC__;

typedef struct _THREAD_BASIC_INFORMATION
{
   long ExitStatus;
   _TEB * TebBaseAddress;
   _CLIENT_ID ClientId;
   unsigned long AffinityMask;
   long Priority;
   long BasePriority;
} THREAD_BASIC_INFORMATION;

typedef struct _Wx86ThreadState
{
   unsigned long * CallBx86Eip;
   void * DeallocationCpu;
   unsigned char UseKnownWx86Dll;
   char OleStubInvoked;
} Wx86ThreadState;

typedef struct _GDI_TEB_BATCH
{
   unsigned long Offset;
   unsigned long HDC;
   unsigned long Buffer[310];
} GDI_TEB_BATCH;

typedef struct _PEB_FREE_BLOCK
{
   _PEB_FREE_BLOCK * Next;
   unsigned long Size;
} PEB_FREE_BLOCK;

typedef struct _PEB_LDR_DATA
{
   unsigned long Length;
   unsigned char Initialized;
   unsigned char Padding2;
   unsigned char Padding3;
   unsigned char Padding4;
   void * SsHandle;
   _LIST_ENTRY InLoadOrderModuleList;
   _LIST_ENTRY InMemoryOrderModuleList;
   _LIST_ENTRY InInitializationOrderModuleList;
} PEB_LDR_DATA;

typedef struct _PEB
{
   unsigned char InheritedAddressSpace;
   unsigned char ReadImageFileExecOptions;
   unsigned char BeingDebugged;
   unsigned char SpareBool;
   void * Mutant;
   void * ImageBaseAddress;
   _PEB_LDR_DATA * Ldr;
   void *  ProcessParameters;
   void * SubSystemData;
   void * ProcessHeap;
   void * FastPebLock;
   void * FastPebLockRoutine;
   void * FastPebUnlockRoutine;
   unsigned long EnvironmentUpdateCount;
   void * KernelCallbackTable;
   unsigned long SystemReserved[2];
   _PEB_FREE_BLOCK * FreeList;
   unsigned long TlsExpansionCounter;
   void * TlsBitmap;
   unsigned long TlsBitmapBits[2];
   void * ReadOnlySharedMemoryBase;
   void * ReadOnlySharedMemoryHeap;
   void * * ReadOnlyStaticServerData;
   void * AnsiCodePageData;
   void * OemCodePageData;
   void * UnicodeCaseTableData;
   unsigned long NumberOfProcessors;
   unsigned long NtGlobalFlag;
   unsigned long Padding28;
   _LARGE_INTEGER CriticalSectionTimeout;
   unsigned long HeapSegmentReserve;
   unsigned long HeapSegmentCommit;
   unsigned long HeapDeCommitTotalFreeThreshold;
   unsigned long HeapDeCommitFreeBlockThreshold;
   unsigned long NumberOfHeaps;
   unsigned long MaximumNumberOfHeaps;
   void * * ProcessHeaps;
   void * GdiSharedHandleTable;
   void * ProcessStarterHelper;
   unsigned long GdiDCAttributeList;
   void * LoaderLock;
   unsigned long OSMajorVersion;
   unsigned long OSMinorVersion;
   short OSBuildNumber;
   short OSCSDVersion;
   unsigned long OSPlatformId;
   unsigned long ImageSubsystem;
   unsigned long ImageSubsystemMajorVersion;
   unsigned long ImageSubsystemMinorVersion;
   unsigned long ImageProcessAffinityMask;
   unsigned long GdiHandleBuffer[34];
   void * PostProcessInitRoutine;
   void * TlsExpansionBitmap;
   unsigned long TlsExpansionBitmapBits[32];
   unsigned long SessionId;
   void * AppCompatInfo;
   _UNICODE_STRING CSDVersion;
} PEB;

typedef struct _NT_TIB
{
   _EXCEPTION_REGISTRATION_RECORD * ExceptionList;
   void * StackBase;
   void * StackLimit;
   void * SubSystemTib;
   union {
   void * FiberData;
   unsigned long Version;
   };
   void * ArbitraryUserPointer;
   _NT_TIB * Self;
} NT_TIB;

typedef struct _TEB
{
   _NT_TIB NtTib;
   void * EnvironmentPointer;
   _CLIENT_ID ClientId;
   void * ActiveRpcHandle;
   void * ThreadLocalStoragePointer;
   _PEB * ProcessEnvironmentBlock;
   unsigned long LastErrorValue;
   unsigned long CountOfOwnedCriticalSections;
   void * CsrClientThread;
   void * Win32ThreadInfo;
   unsigned long User32Reserved[26];
   unsigned long UserReserved[5];
   void * WOW32Reserved;
   unsigned long CurrentLocale;
   unsigned long FpSoftwareStatusRegister;
   void * SystemReserved1[54];
   long ExceptionCode;
   unsigned char SpareBytes1[44];
   _GDI_TEB_BATCH GdiTebBatch;
   _CLIENT_ID RealClientId;
   void * GdiCachedProcessHandle;
   unsigned long GdiClientPID;
   unsigned long GdiClientTID;
   void * GdiThreadLocalInfo;
   unsigned long Win32ClientInfo[62];
   void * glDispatchTable[233];
   unsigned long glReserved1[29];
   void * glReserved2;
   void * glSectionInfo;
   void * glSection;
   void * glTable;
   void * glCurrentRC;
   void * glContext;
   unsigned long LastStatusValue;
   _UNICODE_STRING StaticUnicodeString;
   short StaticUnicodeBuffer[261];
   unsigned char Padding36;
   unsigned char Padding37;
   void * DeallocationStack;
   void * TlsSlots[32];
   _LIST_ENTRY TlsLinks;
   void * Vdm;
   void * ReservedForNtRpc;
   void * DbgSsReserved[2];
   unsigned long HardErrorsAreDisabled;
   void * Instrumentation[16];
   void * WinSockData;
   unsigned long GdiBatchCount;
   unsigned char InDbgPrint;
   unsigned char SpareB1;
   unsigned char SpareB2;
   unsigned char SpareB3;
   unsigned long Spare3;
   void * ReservedForPerf;
   void * ReservedForOle;
   unsigned long WaitingOnLoaderLock;
   _Wx86ThreadState Wx86Thread;
   void * * TlsExpansionSlots;
   unsigned long ImpersonationLocale;
   unsigned long IsImpersonating;
   void * NlsCache;
} TEB;

typedef struct _ACE_HEADER
{
   unsigned char AceType;
   unsigned char AceFlags;
   short AceSize;
} ACE_HEADER;

typedef struct _DSFX_ECHO_STEREO_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[2];
   unsigned long dwOutMixbinPtrs[2];
} DSFX_ECHO_STEREO_STATE;

typedef struct _D3DLOCKED_RECT
{
   int Pitch;
   void * pBits;
} D3DLOCKED_RECT;

typedef struct _XINPUT_FEEDBACK
{
   _XINPUT_FEEDBACK_HEADER Header;
   _XINPUT_RUMBLE Rumble;
} XINPUT_FEEDBACK;

typedef struct _XINPUT_RUMBLE
{
   short wLeftMotorSpeed;
   short wRightMotorSpeed;
} XINPUT_RUMBLE;

typedef struct _XINPUT_FEEDBACK_HEADER
{
   unsigned long dwStatus;
   void * hEvent;
   unsigned char Reserved[58];
} XINPUT_FEEDBACK_HEADER;

typedef struct _XBOX_HARDWARE_INFO
{
   unsigned long Flags;
   unsigned char GpuRevision;
   unsigned char McpRevision;
   unsigned char reserved[2];
} XBOX_HARDWARE_INFO;

typedef struct tagPOINT
{
   long x;
   long y;
} tagPOINT;

typedef struct _REMOTE_PORT_VIEW
{
   unsigned long Length;
   unsigned long ViewSize;
   void * ViewBase;
} REMOTE_PORT_VIEW;

typedef struct Nv09eTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaImage;
   unsigned long Reserved01[94];
   unsigned long SetFormat;
   unsigned long SetOffset;
   unsigned long Reserved02[1854];
} Nv09eTypedef;

typedef struct _XINPUT_POLLING_PARAMETERS
{
   union {
   unsigned char fAutoPoll;
   unsigned char fInterruptOut;
   unsigned char ReservedMBZ1;
   };
   unsigned char bInputInterval;
   unsigned char bOutputInterval;
   unsigned char ReservedMBZ2;
} XINPUT_POLLING_PARAMETERS;

typedef struct _KINTERRUPT
{
   void * ServiceRoutine;
   void * ServiceContext;
   unsigned long BusInterruptLevel;
   unsigned long Irql;
   unsigned char Connected;
   unsigned char ShareVector;
   unsigned char Mode;
   unsigned char Padding7;
   unsigned long ServiceCount;
   unsigned long DispatchCode[22];
} KINTERRUPT;

typedef struct _RECTL
{
   long left;
   long top;
   long right;
   long bottom;
} RECTL;

typedef struct _CPTABLEINFO
{
   short CodePage;
   short MaximumCharacterSize;
   short DefaultChar;
   short UniDefaultChar;
   short TransDefaultChar;
   short TransUniDefaultChar;
   short DBCSCodePage;
   unsigned char LeadByte[12];
   unsigned char Padding8;
   unsigned char Padding9;
   short * MultiByteTable;
   void * WideCharTable;
   short * DBCSRanges;
   short * DBCSOffsets;
} CPTABLEINFO;

typedef struct NVDE_READ_MEMORY_PARAMETERS
{
   unsigned long Address;
   unsigned long Size;
   unsigned long Data;
} NVDE_READ_MEMORY_PARAMETERS;

typedef struct _D3DSURFACE_DESC
{
   int Format;
   int Type;
   unsigned long Usage;
   int Size;
   unsigned long MultiSampleType;
   int Width;
   int Height;
} D3DSURFACE_DESC;

typedef struct D3DVertexBuffer
{
   union {
   (type???) D3DResource;
   (type???) Lock;
   (type???) Unlock;
   (type???) GetDesc;
   };
} D3DVertexBuffer;

typedef struct _STRING64
{
   short Length;
   short MaximumLength;
   unsigned long Padding2;
   __int64 Buffer;
} STRING64;

typedef struct _s__CatchableTypeArray
{
   int nCatchableTypes;
   const _s__CatchableType * arrayOfCatchableTypes[0];
} s__CatchableTypeArray;

typedef struct _PMD
{
   int mdisp;
   int pdisp;
   int vdisp;
} PMD;

typedef struct _TypeDescriptor
{
   const void * pVFTable;
   void * spare;
   char name[0];
} TypeDescriptor;

typedef struct _s__CatchableType
{
   int properties;
   _TypeDescriptor * pType;
   _PMD thisDisplacement;
   int sizeOrOffset;
   void * copyFunction;
} s__CatchableType;

typedef struct _D3DLIGHT8
{
   int Type;
   _D3DCOLORVALUE Diffuse;
   _D3DCOLORVALUE Specular;
   _D3DCOLORVALUE Ambient;
   _D3DVECTOR Position;
   _D3DVECTOR Direction;
   float Range;
   float Falloff;
   float Attenuation0;
   float Attenuation1;
   float Attenuation2;
   float Theta;
   float Phi;
} D3DLIGHT8;

typedef struct _TOKEN_CONTROL
{
   _LUID TokenId;
   _LUID AuthenticationId;
   _LUID ModifiedId;
   _TOKEN_SOURCE TokenSource;
} TOKEN_CONTROL;

typedef struct _TOKEN_SOURCE
{
   char SourceName[8];
   _LUID SourceIdentifier;
} TOKEN_SOURCE;

typedef struct D3DXVECTOR3
{
   union {
   (type???) _D3DVECTOR;
   (type???) D3DXVECTOR3;
   (type???) D3DXVECTOR3;
   (type???) D3DXVECTOR3;
   (type???) public: __thiscall D3DXVECTOR3::D3DXVECTOR3(void);
   (type???) operator float *;
   (type???) operator const float *;
   (type???) operator+=;
   (type???) operator-=;
   (type???) operator*=;
   (type???) operator/=;
   (type???) operator+;
   (type???) operator+;
   (type???) operator-;
   (type???) operator-;
   (type???) operator*;
   (type???) operator/;
   (type???) operator==;
   (type???) operator!=;
   };
} D3DXVECTOR3;

typedef struct _D3DVECTOR
{
   float x;
   float y;
   float z;
} D3DVECTOR;

typedef struct _SYSTEM_POOLTAG_INFORMATION
{
   unsigned long Count;
   _SYSTEM_POOLTAG TagInfo[1];
} SYSTEM_POOLTAG_INFORMATION;

typedef struct _SYSTEM_POOLTAG
{
   union {
   unsigned char Tag[4];
   unsigned long TagUlong;
   };
   unsigned long PagedAllocs;
   unsigned long PagedFrees;
   unsigned long PagedUsed;
   unsigned long NonPagedAllocs;
   unsigned long NonPagedFrees;
   unsigned long NonPagedUsed;
} SYSTEM_POOLTAG;

typedef struct _DSFX_IIR_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[1];
   unsigned long dwOutMixbinPtrs[1];
} DSFX_IIR_STATE;

typedef struct _DSFX_IIR_PARAMS
{
   _DSFX_IIR_STATE State;
   unsigned long dwDelayLength;
   unsigned long dwGain;
   unsigned long dwType;
} DSFX_IIR_PARAMS;

typedef struct _IO_COMPLETION_CONTEXT
{
   void * Port;
   void * Key;
} IO_COMPLETION_CONTEXT;

typedef struct _FILE_OBJECT
{
   short Type;
   union {
   unsigned char DeletePending;
   unsigned char ReadAccess;
   unsigned char WriteAccess;
   unsigned char DeleteAccess;
   unsigned char SharedRead;
   unsigned char SharedWrite;
   unsigned char SharedDelete;
   unsigned char Reserved;
   };
   unsigned char Flags;
   _DEVICE_OBJECT * DeviceObject;
   void * FsContext;
   void * FsContext2;
   long FinalStatus;
   _LARGE_INTEGER CurrentByteOffset;
   _FILE_OBJECT * RelatedFileObject;
   _IO_COMPLETION_CONTEXT * CompletionContext;
   long LockCount;
   _KEVENT Lock;
   _KEVENT Event;
} FILE_OBJECT;

typedef struct _KDEVICE_QUEUE
{
   short Type;
   unsigned char Size;
   unsigned char Busy;
   _LIST_ENTRY DeviceListHead;
} KDEVICE_QUEUE;

typedef union _FILE_SEGMENT_ELEMENT
{
   union {
   void * Buffer;
   unsigned long Alignment;
   };
} FILE_SEGMENT_ELEMENT;

typedef struct _KEVENT
{
   _DISPATCHER_HEADER Header;
} KEVENT;

typedef struct _IO_STATUS_BLOCK
{
   union {
   long Status;
   void * Pointer;
   };
   unsigned long Information;
} IO_STATUS_BLOCK;

typedef struct _IRP
{
   short Type;
   short Size;
   unsigned long Flags;
   _LIST_ENTRY ThreadListEntry;
   _IO_STATUS_BLOCK IoStatus;
   char StackCount;
   char CurrentLocation;
   unsigned char PendingReturned;
   unsigned char Cancel;
   _IO_STATUS_BLOCK * UserIosb;
   _KEVENT * UserEvent;
   unsigned long Padding11;
    unsigned char Overlay[8];
   void * UserBuffer;
   _FILE_SEGMENT_ELEMENT * SegmentArray;
   unsigned long LockedBufferLength;
    unsigned char Tail[40];
} IRP;

typedef struct _DRIVER_OBJECT
{
   void * DriverStartIo;
   void * DriverDeleteDevice;
   void * DriverDismountVolume;
   void * MajorFunction[14];
} DRIVER_OBJECT;

typedef struct _DEVICE_OBJECT
{
   short Type;
   short Size;
   long ReferenceCount;
   _DRIVER_OBJECT * DriverObject;
   _DEVICE_OBJECT * MountedOrSelfDevice;
   _IRP * CurrentIrp;
   unsigned long Flags;
   void * DeviceExtension;
   unsigned char DeviceType;
   unsigned char StartIoFlags;
   char StackSize;
   unsigned char DeletePending;
   unsigned long SectorSize;
   unsigned long AlignmentRequirement;
   _KDEVICE_QUEUE DeviceQueue;
   _KEVENT DeviceLock;
   unsigned long StartIoKey;
} DEVICE_OBJECT;

typedef struct _IO_STACK_LOCATION
{
   unsigned char MajorFunction;
   unsigned char MinorFunction;
   unsigned char Flags;
   unsigned char Control;
   UNNAMED_TAG_29104D Parameters;
   _DEVICE_OBJECT * DeviceObject;
   _FILE_OBJECT * FileObject;
   void * CompletionRoutine;
   void * Context;
} IO_STACK_LOCATION;

typedef struct Nv061Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextColorKey;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextPattern;
   unsigned long SetContextRop;
   unsigned long SetContextBeta1;
   unsigned long SetContextBeta4;
   unsigned long SetContextSurface;
   unsigned long Reserved01[87];
   unsigned long SetOperation;
   unsigned long SetColorFormat;
   unsigned long Point;
   unsigned long SizeOut;
   unsigned long SizeIn;
   unsigned long Reserved02[60];
   unsigned long Color[1792];
} Nv061Typedef;

typedef struct Nv048Typedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long Reserved00[30];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaTexture;
   unsigned long SetContextClipRectangle;
   unsigned long SetContextSurfaceColor;
   unsigned long SetContextSurfaceZeta;
   unsigned long Reserved01[92];
   unsigned long TextureOffset;
   unsigned long TextureFormat;
   unsigned long TextureFilter;
   unsigned long FogColor;
   unsigned long Control0;
   unsigned long Control1;
   unsigned long Reserved02[825];
   Nv048Typedef::__unnamed Tlvertex[128];
} Nv048Typedef;

typedef struct Nv048Typedef::__unnamed
{
   unsigned long specular;
   unsigned long color;
   float sx;
   float sy;
   float sz;
   float rhw;
   float tu;
   float tv;
} Nv048Typedef::__unnamed;

typedef struct IDirectXFile
{
   union {
   (type???) IUnknown;
   (type???) QueryInterface;
   (type???) AddRef;
   (type???) Release;
   (type???) CreateEnumObject;
   (type???) CreateSaveObject;
   (type???) RegisterTemplates;
   (type???) IDirectXFile;
   (type???) IDirectXFile;
   };
} IDirectXFile;

typedef struct _FILE_MAILSLOT_QUERY_INFORMATION
{
   unsigned long MaximumMessageSize;
   unsigned long MailslotQuota;
   unsigned long NextMessageSize;
   unsigned long MessagesAvailable;
   _LARGE_INTEGER ReadTimeout;
} FILE_MAILSLOT_QUERY_INFORMATION;

typedef struct _DSFX_FLANGE_MONO_STATE
{
   unsigned long dwScratchOffset;
   unsigned long dwScratchLength;
   unsigned long dwYMemoryOffset;
   unsigned long dwYMemoryLength;
   unsigned long dwFlags;
   unsigned long dwInMixbinPtrs[2];
   unsigned long dwOutMixbinPtrs[1];
} DSFX_FLANGE_MONO_STATE;

typedef struct _IMAGE_BOUND_FORWARDER_REF
{
   unsigned long TimeDateStamp;
   short OffsetModuleName;
   short Reserved;
} IMAGE_BOUND_FORWARDER_REF;

typedef struct _IO_RESOURCE_DESCRIPTOR
{
   unsigned char Option;
   unsigned char Type;
   unsigned char ShareDisposition;
   unsigned char Spare1;
   short Flags;
   short Spare2;
   _IO_RESOURCE_DESCRIPTOR::__unnamed u;
} IO_RESOURCE_DESCRIPTOR;

typedef union _IO_RESOURCE_DESCRIPTOR::__unnamed
{
   union {
   _IO_RESOURCE_DESCRIPTOR::__unnamed::__unnamed Port;
   _IO_RESOURCE_DESCRIPTOR::__unnamed::__unnamed Memory;
   _IO_RESOURCE_DESCRIPTOR::__unnamed::__unnamed Interrupt;
   _IO_RESOURCE_DESCRIPTOR::__unnamed::__unnamed Dma;
   _IO_RESOURCE_DESCRIPTOR::__unnamed::__unnamed Generic;
   _IO_RESOURCE_DESCRIPTOR::__unnamed::__unnamed DevicePrivate;
   _IO_RESOURCE_DESCRIPTOR::__unnamed::__unnamed BusNumber;
   _IO_RESOURCE_DESCRIPTOR::__unnamed::__unnamed AssignedResource;
   _IO_RESOURCE_DESCRIPTOR::__unnamed::__unnamed SubAllocateFrom;
   _IO_RESOURCE_DESCRIPTOR::__unnamed::__unnamed ConfigData;
   };
} IO_RESOURCE_DESCRIPTOR::__unnamed;

typedef struct _IO_RESOURCE_DESCRIPTOR::__unnamed::__unnamed
{
   unsigned long Length;
   unsigned long Alignment;
   _LARGE_INTEGER MinimumAddress;
   _LARGE_INTEGER MaximumAddress;
} IO_RESOURCE_DESCRIPTOR::__unnamed::__unnamed;

typedef struct _LUID
{
   unsigned long LowPart;
   long HighPart;
} LUID;

typedef struct _LUID_AND_ATTRIBUTES
{
   _LUID Luid;
   unsigned long Attributes;
} LUID_AND_ATTRIBUTES;

typedef struct _XDEVICE_PREALLOC_TYPE
{
   _XPP_DEVICE_TYPE * DeviceType;
   unsigned long dwPreallocCount;
} XDEVICE_PREALLOC_TYPE;

typedef struct _XPP_DEVICE_TYPE
{
   unsigned long Reserved[3];
} XPP_DEVICE_TYPE;

typedef struct _PROCESS_FOREGROUND_BACKGROUND
{
   unsigned char Foreground;
} PROCESS_FOREGROUND_BACKGROUND;

typedef struct _IMAGE_BOUND_IMPORT_DESCRIPTOR
{
   unsigned long TimeDateStamp;
   short OffsetModuleName;
   short NumberOfModuleForwarderRefs;
} IMAGE_BOUND_IMPORT_DESCRIPTOR;

typedef struct _SID_IDENTIFIER_AUTHORITY
{
   unsigned char Value[6];
} SID_IDENTIFIER_AUTHORITY;

typedef struct tagPALETTEENTRY
{
   unsigned char peRed;
   unsigned char peGreen;
   unsigned char peBlue;
   unsigned char peFlags;
} tagPALETTEENTRY;

typedef struct _OSVERSIONINFOEXW
{
   unsigned long dwOSVersionInfoSize;
   unsigned long dwMajorVersion;
   unsigned long dwMinorVersion;
   unsigned long dwBuildNumber;
   unsigned long dwPlatformId;
   short szCSDVersion[128];
   short wServicePackMajor;
   short wServicePackMinor;
   short wSuiteMask;
   unsigned char wProductType;
   unsigned char wReserved;
} OSVERSIONINFOEXW;

typedef struct _FILE_FS_VOLUME_INFORMATION
{
   _LARGE_INTEGER VolumeCreationTime;
   unsigned long VolumeSerialNumber;
   unsigned long VolumeLabelLength;
   unsigned char SupportsObjects;
   char VolumeLabel[1];
} FILE_FS_VOLUME_INFORMATION;

typedef struct _LD_FROM_DEBUGGER_CMDLINE
{
   char szCmdLine[3072];
} LD_FROM_DEBUGGER_CMDLINE;

typedef struct _SYSTEM_HANDLE_TABLE_ENTRY_INFO
{
   short UniqueProcessId;
   short CreatorBackTraceIndex;
   unsigned char ObjectTypeIndex;
   unsigned char HandleAttributes;
   short HandleValue;
   void * Object;
   unsigned long GrantedAccess;
} SYSTEM_HANDLE_TABLE_ENTRY_INFO;

typedef struct _SYSTEM_HANDLE_INFORMATION
{
   unsigned long NumberOfHandles;
   _SYSTEM_HANDLE_TABLE_ENTRY_INFO Handles[1];
} SYSTEM_HANDLE_INFORMATION;

typedef struct _EXCEPTION_RECORD
{
   long ExceptionCode;
   unsigned long ExceptionFlags;
   _EXCEPTION_RECORD * ExceptionRecord;
   void * ExceptionAddress;
   unsigned long NumberParameters;
   unsigned long ExceptionInformation[15];
} EXCEPTION_RECORD;

typedef struct _KEY_BASIC_INFORMATION
{
   _LARGE_INTEGER LastWriteTime;
   unsigned long TitleIndex;
   unsigned long NameLength;
   short Name[1];
} KEY_BASIC_INFORMATION;

typedef struct sockaddr
{
   short sa_family;
   char sa_data[14];
} sockaddr;

typedef struct _Wx86TIB
{
   unsigned long Size;
   unsigned long InitialPc;
   void * StackBase;
   void * StackLimit;
   void * DeallocationStack;
   unsigned long LogFlags;
   unsigned long InitialSp;
   unsigned char SimulationCount;
   unsigned char InCpuSimulation;
   unsigned char EmulateInitialPc;
   unsigned char Initialized;
   _EXCEPTION_REGISTRATION_RECORD * ExceptionList;
   void * CpuContext;
   _CONTEXT * InitialExceptionContext;
   void * pCallersRIID;
   void * pCallersUnknown;
   unsigned long Flags;
   void * SelfRegDllName;
   void * SelfRegDllHandle;
} Wx86TIB;

typedef struct _FLOATING_SAVE_AREA
{
   short ControlWord;
   short StatusWord;
   short TagWord;
   short ErrorOpcode;
   unsigned long ErrorOffset;
   unsigned long ErrorSelector;
   unsigned long DataOffset;
   unsigned long DataSelector;
   unsigned long MXCsr;
   unsigned long Reserved2;
   unsigned char RegisterArea[128];
   unsigned char XmmRegisterArea[128];
   unsigned char Reserved4[224];
   unsigned long Cr0NpxState;
} FLOATING_SAVE_AREA;

typedef struct _CONTEXT
{
   unsigned long ContextFlags;
   _FLOATING_SAVE_AREA FloatSave;
   unsigned long Edi;
   unsigned long Esi;
   unsigned long Ebx;
   unsigned long Edx;
   unsigned long Ecx;
   unsigned long Eax;
   unsigned long Ebp;
   unsigned long Eip;
   unsigned long SegCs;
   unsigned long EFlags;
   unsigned long Esp;
   unsigned long SegSs;
} CONTEXT;

typedef struct _EXCEPTION_REGISTRATION_RECORD
{
   _EXCEPTION_REGISTRATION_RECORD * Next;
   void * Handler;
} EXCEPTION_REGISTRATION_RECORD;

typedef struct Nv04eTypedef
{
   unsigned long NoOperation;
   unsigned long Notify;
   unsigned long StopTransfer;
   unsigned long Reserved00[29];
   unsigned long SetContextDmaNotifies;
   unsigned long SetContextDmaData[2];
   unsigned long SetContextDmaImage[2];
   unsigned long Reserved01[91];
   Nv04eTypedef::__unnamed SetData[2];
   Nv04eTypedef::__unnamed SetImage[2];
   unsigned long Reserved02[1840];
} Nv04eTypedef;

typedef struct Nv04eTypedef::__unnamed
{
   unsigned long offset;
   unsigned long length;
   unsigned long notify;
} Nv04eTypedef::__unnamed;

typedef struct _SYSTEM_CRASH_DUMP_INFORMATION
{
   void * CrashDumpSection;
   void * hDumpSection;
} SYSTEM_CRASH_DUMP_INFORMATION;

typedef struct _SYSTEM_THREAD_INFORMATION
{
   _LARGE_INTEGER KernelTime;
   _LARGE_INTEGER UserTime;
   _LARGE_INTEGER CreateTime;
   unsigned long WaitTime;
   void * StartAddress;
   _CLIENT_ID ClientId;
   long Priority;
   long BasePriority;
   unsigned long ContextSwitches;
   unsigned long ThreadState;
   unsigned long WaitReason;
} SYSTEM_THREAD_INFORMATION;

typedef struct _CLIENT_ID
{
   void * UniqueProcess;
   void * UniqueThread;
} CLIENT_ID;

typedef struct _LARGE_INTEGER::__unnamed
{
   unsigned long LowPart;
   long HighPart;
} LARGE_INTEGER::__unnamed;

typedef union _LARGE_INTEGER
{
   unsigned long LowPart;
   long HighPart;
   union {
   _LARGE_INTEGER::__unnamed u;
   __int64 QuadPart;
   };
} LARGE_INTEGER;

typedef struct _SID_AND_ATTRIBUTES
{
   void * Sid;
   unsigned long Attributes;
} SID_AND_ATTRIBUTES;

typedef struct _GUID
{
   unsigned long Data1;
   short Data2;
   short Data3;
   unsigned char Data4[8];
} GUID;

typedef struct UNNAMED_TAG_29104D
{
   unsigned long size;
   unsigned long monochrome[15];
} UNNAMED_TAG_29104D;

typedef struct _D3DCOLORVALUE
{
   float r;
   float g;
   float b;
   float a;
} D3DCOLORVALUE;

typedef struct D3DXCOLOR
{
   union {
   (type???) D3DXCOLOR;
   (type???) D3DXCOLOR;
   (type???) D3DXCOLOR;
   (type???) D3DXCOLOR;
   (type???) D3DXCOLOR;
   (type???) operator unsigned long;
   (type???) operator float *;
   (type???) operator const float *;
   (type???) operator struct _D3DCOLORVALUE *;
   (type???) operator const struct _D3DCOLORVALUE *;
   (type???) operator struct _D3DCOLORVALUE &;
   (type???) operator const struct _D3DCOLORVALUE &;
   (type???) operator+=;
   (type???) operator-=;
   (type???) operator*=;
   (type???) operator/=;
   (type???) operator+;
   (type???) operator+;
   (type???) operator-;
   (type???) operator-;
   (type???) operator*;
   (type???) operator/;
   (type???) operator==;
   (type???) operator!=;
   float r;
   };
   float g;
   float b;
   float a;
} D3DXCOLOR;

typedef struct _PROCESS_HEAP_ENTRY
{
   void * lpData;
   unsigned long cbData;
   unsigned char cbOverhead;
   unsigned char iRegionIndex;
   short wFlags;
   union {
   _PROCESS_HEAP_ENTRY::__unnamed::__unnamed Block;
   _PROCESS_HEAP_ENTRY::__unnamed::__unnamed Region;
   };
} PROCESS_HEAP_ENTRY;

typedef struct _PROCESS_HEAP_ENTRY::__unnamed::__unnamed
{
   void * hMem;
   unsigned long dwReserved[3];
} PROCESS_HEAP_ENTRY::__unnamed::__unnamed;

typedef struct _SYSTEM_EXCEPTION_INFORMATION
{
   unsigned long AlignmentFixupCount;
   unsigned long ExceptionDispatchCount;
   unsigned long FloatingEmulationCount;
   unsigned long ByteWordEmulationCount;
} SYSTEM_EXCEPTION_INFORMATION;

typedef struct _IMAGE_IA64_RUNTIME_FUNCTION_ENTRY
{
   unsigned long BeginAddress;
   unsigned long EndAddress;
   unsigned long UnwindInfoAddress;
} IMAGE_IA64_RUNTIME_FUNCTION_ENTRY;

typedef struct _TOKEN_PRIMARY_GROUP
{
   void * PrimaryGroup;
} TOKEN_PRIMARY_GROUP;

typedef struct _RTL_SPLAY_LINKS
{
   _RTL_SPLAY_LINKS * Parent;
   _RTL_SPLAY_LINKS * LeftChild;
   _RTL_SPLAY_LINKS * RightChild;
} RTL_SPLAY_LINKS;

typedef struct _UNICODE_STRING
{
   short Length;
   short MaximumLength;
   short * Buffer;
} UNICODE_STRING;

typedef struct _DSEFFECTIMAGELOC
{
   unsigned long dwI3DL2ReverbIndex;
   unsigned long dwCrosstalkIndex;
} DSEFFECTIMAGELOC;

typedef struct _KSEMAPHORE
{
   _DISPATCHER_HEADER Header;
   long Limit;
} KSEMAPHORE;

typedef struct _KAPC
{
   short Type;
   char ApcMode;
   unsigned char Inserted;
   _KTHREAD * Thread;
   _LIST_ENTRY ApcListEntry;
   void * KernelRoutine;
   void * RundownRoutine;
   void * NormalRoutine;
   void * NormalContext;
   void * SystemArgument1;
   void * SystemArgument2;
} KAPC;

typedef struct _KDPC
{
   short Type;
   unsigned char Inserted;
   unsigned char Padding;
   _LIST_ENTRY DpcListEntry;
   void * DeferredRoutine;
   void * DeferredContext;
   void * SystemArgument1;
   void * SystemArgument2;
} KDPC;

typedef struct _ULARGE_INTEGER::__unnamed
{
   unsigned long LowPart;
   unsigned long HighPart;
} ULARGE_INTEGER::__unnamed;

typedef union _ULARGE_INTEGER
{
   unsigned long LowPart;
   unsigned long HighPart;
   union {
   _ULARGE_INTEGER::__unnamed u;
   __int64 QuadPart;
   };
} ULARGE_INTEGER;

typedef struct _KTIMER
{
   _DISPATCHER_HEADER Header;
   _ULARGE_INTEGER DueTime;
   _LIST_ENTRY TimerListEntry;
   _KDPC * Dpc;
   long Period;
} KTIMER;

typedef struct _KQUEUE
{
   _DISPATCHER_HEADER Header;
   _LIST_ENTRY EntryListHead;
   unsigned long CurrentCount;
   unsigned long MaximumCount;
   _LIST_ENTRY ThreadListHead;
} KQUEUE;

typedef struct _KWAIT_BLOCK
{
   _LIST_ENTRY WaitListEntry;
   _KTHREAD * Thread;
   void * Object;
   _KWAIT_BLOCK * NextWaitBlock;
   short WaitKey;
   short WaitType;
} KWAIT_BLOCK;

typedef struct _KPROCESS
{
   _LIST_ENTRY ReadyListHead;
   _LIST_ENTRY ThreadListHead;
   unsigned long StackCount;
   long ThreadQuantum;
   signed char BasePriority;
   unsigned char DisableBoost;
   unsigned char DisableQuantum;
} KPROCESS;

typedef struct _KAPC_STATE
{
   _LIST_ENTRY ApcListHead[2];
   _KPROCESS * Process;
   unsigned char KernelApcInProgress;
   unsigned char KernelApcPending;
   unsigned char UserApcPending;
   unsigned char ApcQueueable;
} KAPC_STATE;

typedef struct _LIST_ENTRY
{
   _LIST_ENTRY * Flink;
   _LIST_ENTRY * Blink;
} LIST_ENTRY;

typedef struct _DISPATCHER_HEADER
{
   unsigned char Type;
   unsigned char Absolute;
   unsigned char Size;
   unsigned char Inserted;
   long SignalState;
   _LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER;

typedef struct _KTHREAD
{
   _DISPATCHER_HEADER Header;
   _LIST_ENTRY MutantListHead;
   unsigned long KernelTime;
   void * StackBase;
   void * StackLimit;
   void * KernelStack;
   void * TlsData;
   unsigned char State;
   unsigned char Alerted[2];
   unsigned char Alertable;
   unsigned char NpxState;
   char Saturation;
   signed char Priority;
   unsigned char Padding;
   _KAPC_STATE ApcState;
   unsigned long ContextSwitches;
   long WaitStatus;
   unsigned char WaitIrql;
   char WaitMode;
   unsigned char WaitNext;
   unsigned char WaitReason;
   _KWAIT_BLOCK * WaitBlockList;
   _LIST_ENTRY WaitListEntry;
   unsigned long WaitTime;
   unsigned long KernelApcDisable;
   long Quantum;
   signed char BasePriority;
   unsigned char DecrementCount;
   signed char PriorityDecrement;
   unsigned char DisableBoost;
   unsigned char NpxIrql;
   char SuspendCount;
   unsigned char Preempted;
   unsigned char HasTerminated;
   _KQUEUE * Queue;
   _LIST_ENTRY QueueListEntry;
   _KTIMER Timer;
   _KWAIT_BLOCK TimerWaitBlock;
   _KAPC SuspendApc;
   _KSEMAPHORE SuspendSemaphore;
   _LIST_ENTRY ThreadListEntry;
} KTHREAD;

typedef struct _CM_DISK_GEOMETRY_DEVICE_DATA
{
   unsigned long BytesPerSector;
   unsigned long NumberOfCylinders;
   unsigned long SectorsPerTrack;
   unsigned long NumberOfHeads;
} CM_DISK_GEOMETRY_DEVICE_DATA;

typedef struct PROCESSOR_IDLE_TIMES
{
   __int64 StartTime;
   __int64 EndTime;
   unsigned long IdleHandlerReserved[4];
} PROCESSOR_IDLE_TIMES;

typedef struct _PROCESSOR_POWER_STATE
{
   void * IdleFunction;
   unsigned long Idle0KernelTimeLimit;
   unsigned long Idle0LastTime;
   void * IdleState;
   __int64 LastCheck;
   PROCESSOR_IDLE_TIMES IdleTimes;
   unsigned long IdleTime1;
   unsigned long PromotionCheck;
   unsigned long IdleTime2;
   unsigned char CurrentThrottle;
   unsigned char ThrottleLimit;
   unsigned char Spare1[2];
   unsigned long SetMember;
   void * AbortThrottle;
   __int64 DebugDelta;
   unsigned long DebugCount;
   unsigned long LastSysTime;
   unsigned long Spare2[10];
} PROCESSOR_POWER_STATE;

