// write access to const memory has been detected, the output may be wrong!
int __userpurge D3DK::CDevice::Init@<eax>(D3DK::CDevice *this@<ecx>, int *a2@<edi>, int a3@<esi>, _D3DPRESENT_PARAMETERS_ *pPresentationParams)
{
  int result; // eax
  int v5; // edx
  int v6; // ecx
  char *v7; // eax
  NvNotification *v8; // edi
  int *v9; // edi
  unsigned int *v10; // edx
  unsigned int *v18; // eax
  D3DK::CMiniport *v19; // esi
  int *v20; // edi
  volatile unsigned int v21; // ebx
  unsigned int v22; // edi
  unsigned int v23; // eax
  void *v24; // ecx
  unsigned int v25; // esi
  int *v26; // edi
  unsigned int v27; // ebx
  unsigned int v28; // eax
  D3DSurface *v29; // eax
  D3DK::CMiniport::OBJECTINFO RectCopyObj; // [esp+0h] [ebp-FCh]
  D3DK::CMiniport::OBJECTINFO KelvinObj; // [esp+10h] [ebp-ECh]
  D3DK::CMiniport::OBJECTINFO RectCopySurfacesObj; // [esp+20h] [ebp-DCh]
  D3DK::CMiniport::OBJECTINFO MemCopyObj; // [esp+30h] [ebp-CCh]
  D3DK::CMiniport::OBJECTINFO MemCopyNotifierCtxDma; // [esp+40h] [ebp-BCh]
  D3DK::CMiniport::OBJECTINFO SemaphoreCtxDma; // [esp+50h] [ebp-ACh]
  void *RegisterBase; // [esp+60h] [ebp-9Ch]
  D3DK::CMiniport::OBJECTINFO FromMemoryCtxDma; // [esp+64h] [ebp-98h]
  D3DK::CMiniport::OBJECTINFO InMemoryCtxDma; // [esp+74h] [ebp-88h]
  D3DK::CMiniport::OBJECTINFO NotifierCtxDma; // [esp+84h] [ebp-78h]
  D3DK::CMiniport::OBJECTINFO CachedMemoryCtxDma; // [esp+94h] [ebp-68h]
  D3DK::CMiniport::OBJECTINFO ToMemoryCtxDma; // [esp+A4h] [ebp-58h]
  D3DK::CMiniport::OBJECTINFO ColorCtxDma; // [esp+B4h] [ebp-48h]
  D3DK::CMiniport::OBJECTINFO CopyCtxDma; // [esp+C4h] [ebp-38h]
  D3DK::CMiniport::OBJECTINFO PusherCtxDma; // [esp+D4h] [ebp-28h]
  D3DK::CMiniport::OBJECTINFO ZetaCtxDma; // [esp+E4h] [ebp-18h]
  Nv206eControl *pControlDma; // [esp+F4h] [ebp-8h]
  D3DK::CDevice *v47; // [esp+F8h] [ebp-4h]

  v47 = this;
  result = D3DK::PresentationParametersParameterCheck(a2, pPresentationParams);
  if ( result >= 0 )
  {
    v47->m_pCachedContiguousMemoryBase = (char *)MmAllocateContiguousMemoryEx(v5, v6, a3, 0x60u, 0, 0x3FFAFFFu, 0, 4u);
    v7 = v47->m_pCachedContiguousMemoryBase;
    if ( v7 )
    {
      v47->m_pGpuTime = (volatile unsigned int *)v7;
      v47->m_pKelvinNotifiers = (NvNotification *)(v47->m_pGpuTime + 8);
      v47->m_pMemCopyNotifiers = v47->m_pKelvinNotifiers + 2;
      v8 = v47->m_pKelvinNotifiers;
      memset(v8, 0, 0x40u);
      v9 = (int *)&v8[4];
      v10 = (unsigned int *)MmAllocateContiguousMemoryEx(
                              (int)v47,
                              0,
                              a3,
                              (D3DK::CDevice::m_PushBufferSize + 12287) & 0xFFFFF000,
                              0,
                              0x3FFB000u,
                              0,
                              0x404u);
      if ( v10 )
      {
        _EAX = 1;
        _ECX = &D3D__AllocsContiguous;
        __asm { xadd    [ecx], this }
      }
      v47->m_pPushBase = v10;
      v18 = v47->m_pPushBase;
      if ( v18 )
      {
        v47->m_pPushLimit = &v18[D3DK::CDevice::m_PushBufferSize >> 2];
        D3DK::CDevice::InitializePushBuffer(v47, v9);
        D3DK::g_ParsePut = v47->m_pPushBase;
        v47->m_DirtyFlags |= 0x7FFu;
        v19 = &v47->m_Miniport;
        D3DK::CMiniport::InitHardware(&v47->m_Miniport, v9);
        D3DK::CMiniport::CreateCtxDmaObject(&v47->m_Miniport, 3u, 0x3Du, 0, 0x3FFAFFFu, &InMemoryCtxDma);
        D3DK::CMiniport::CreateCtxDmaObject(v19, 5u, 2u, 0, 0x3FFAFFFu, &FromMemoryCtxDma);
        D3DK::CMiniport::CreateCtxDmaObject(v19, 4u, 3u, 0, 0x3FFAFFFu, &ToMemoryCtxDma);
        D3DK::CMiniport::CreateCtxDmaObject(v19, 9u, 0x3Du, 0, 0x3FFAFFFu, &ColorCtxDma);
        v47->m_ColorContextDmaInstance = ColorCtxDma.Instance;
        D3DK::CMiniport::CreateCtxDmaObject(v19, 0xAu, 0x3Du, 0, 0x3FFAFFFu, &ZetaCtxDma);
        v47->m_ZetaContextDmaInstance = ZetaCtxDma.Instance;
        D3DK::CMiniport::CreateCtxDmaObject(v19, 0xBu, 0x3Du, 0, 0x3FFAFFFu, &CopyCtxDma);
        v47->m_CopyContextDmaInstance = CopyCtxDma.Instance;
        D3DK::CMiniport::CreateCtxDmaObject(v19, 2u, 3u, v47->m_pKelvinNotifiers, 0x1Fu, &NotifierCtxDma);
        D3DK::CMiniport::CreateCtxDmaObject(v19, 7u, 0x3Du, v47->m_pMemCopyNotifiers, 0x1Fu, &MemCopyNotifierCtxDma);
        D3DK::CMiniport::CreateCtxDmaObject(v19, 0xCu, 0x3Du, (void *)0x80000000, 0x10000000u, &CachedMemoryCtxDma);
        D3DK::CMiniport::CreateCtxDmaObject(v19, 8u, 0x3Du, (void *)v47->m_pGpuTime, 0x20u, &SemaphoreCtxDma);
        D3DK::CMiniport::CreateCtxDmaObject(v19, 6u, 2u, 0, 0x3FFAFFFu, &PusherCtxDma);
        D3DK::CMiniport::InitDMAChannel(v19, 0x206Eu, 0, &PusherCtxDma, 0, (void **)&pControlDma);
        D3DK::CMiniport::BindToChannel(v19, &PusherCtxDma);
        D3DK::CMiniport::BindToChannel(v19, &CachedMemoryCtxDma);
        D3DK::CMiniport::BindToChannel(v19, &NotifierCtxDma);
        D3DK::CMiniport::BindToChannel(v19, &MemCopyNotifierCtxDma);
        D3DK::CMiniport::BindToChannel(v19, &ToMemoryCtxDma);
        D3DK::CMiniport::BindToChannel(v19, &FromMemoryCtxDma);
        D3DK::CMiniport::BindToChannel(v19, &InMemoryCtxDma);
        D3DK::CMiniport::BindToChannel(v19, &ColorCtxDma);
        D3DK::CMiniport::BindToChannel(v19, &ZetaCtxDma);
        D3DK::CMiniport::BindToChannel(v19, &CopyCtxDma);
        D3DK::CMiniport::BindToChannel(v19, &SemaphoreCtxDma);
        D3DK::CMiniport::CreateGrObject(v19, 0xDu, 0x97u, &KelvinObj);
        D3DK::CMiniport::CreateGrObject(v19, 0xEu, 0x39u, &MemCopyObj);
        D3DK::CMiniport::CreateGrObject(v19, 0x10u, 0x9Fu, &RectCopyObj);
        D3DK::CMiniport::CreateGrObject(v19, 0x11u, 0x62u, &RectCopySurfacesObj);
        v47->m_NvBase = (D3DK::_HWREG *)v19->m_RegisterBase;
        v47->m_pControlDma = pControlDma;
        D3D__GpuGet = &v47->m_pControlDma->Get;
        D3D__GpuPut = &v47->m_pControlDma->Put;
        D3D__GpuReg = v47->m_NvBase->Reg032;
        D3D__GpuTime = v47->m_pGpuTime;
        D3D__PushBase = v47->m_pPushBase;
        D3D__PushLimit = v47->m_pPushLimit;
        v20 = (int *)v47->m_pPushBase;
        if ( ((_DWORD)v47->m_pPushBase & 0xF0000000) != 0x80000000 )
          D3DK::DXGRIP(v20, "AssertContiguous - the memory is not contiguous.");
        MEMORY[0x80000000] = ((unsigned int)v20 & 0xFFFFFFF) + 1;
        __wbinvd();
        D3DK::CDevice::KickOff(v47, MEMORY[0x80000000]);
        v21 = KeTickCount;
        while ( 1 )
        {
          v22 = v47->m_pControlDma->Get;
          if ( v22 > 0x4000000 )
          {
            DbgPrint((int *)v22, "DebugVerifyPhysical - Not a valid physical memory offset.");
            DbgPrint((int *)v22, "\n");
            __debugbreak();
          }
          if ( !((v22 ^ (_DWORD)v47->m_Pusher.m_pPut) & 0xFFFFFFF) )
            break;
          if ( KeTickCount - v21 > D3D__DeadlockTimeOutVal )
            RtlRip(0, 0, "Possible deadlock, blocked for more than 2 seconds.");
          if ( D3DK::g_DpcRIPFired )
          {
            RtlRip(0, 0, "Graphics processor error.");
            D3DK::g_DpcRIPFired = 0;
          }
          D3DK::BusyLoop();
        }
        MEMORY[0x80000000] = -559038737;
        D3DK::InitializeHardware();
        result = D3DK::CDevice::InitializeFrameBuffers(v47, pPresentationParams);
        if ( result >= 0 )
        {
          v23 = D3DK::PixelJar::GetPitch((D3DPixelContainer *)&v47->m_FrameBufferSurfaces[1].Common);
          D3DK::CMiniport::SetVideoMode(
            v19,
            (int *)v22,
            pPresentationParams->BackBufferWidth,
            pPresentationParams->BackBufferHeight,
            pPresentationParams->FullScreen_RefreshRateInHz,
            pPresentationParams->Flags,
            pPresentationParams->BackBufferFormat,
            pPresentationParams->FullScreen_PresentationInterval,
            v23);
          v24 = v47->m_Miniport.m_RegisterBase;
          v25 = v47->m_Miniport.m_DisplayMode;
          v26 = (int *)v47->m_Miniport.m_Format;
          v27 = v47->m_Miniport.m_SurfacePitch;
          RegisterBase = v47->m_Miniport.m_RegisterBase;
          v28 = 0;
          do
            v28 = AvSetDisplayMode((int)v24, (int)RegisterBase, RegisterBase, v28, v25, (unsigned int)v26, v27, 0);
          while ( v28 );
          v47->m_pVertexShader = &D3DK::g_FvfVertexShader;
          D3DDevice_SetVertexShader(v26, 2u);
          if ( v47->m_pAutoDepthBuffer )
            v29 = &v47->m_AutoDepthSurface;
          else
            v29 = 0;
          D3DDevice_SetRenderTarget(v47->m_FrameBufferSurfaces, v29);
          D3DK::InitializeD3dState(v26);
          D3DDevice_Clear(0, 0, 3u, 0, 1.0, 0);
          result = 0;
        }
      }
      else
      {
        D3DK::WARNING(v9, "CDevice::Init - unable to allocate push buffer, Init failed.");
        result = (int)&loc_80070009 + 5;
      }
    }
    else
    {
      D3DK::WARNING(a2, "CDevice::Init - unable to allocate notifier memory, Init failed.");
      result = (int)&loc_80070009 + 5;
    }
  }
  return result;
}