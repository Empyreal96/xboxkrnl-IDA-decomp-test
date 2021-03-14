// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_Present(tagRECT *SourceRect, tagRECT *DestRect, void *DestWindowOverride, void *DirtyRegion)
{
  unsigned __int64 v4; // rax
  volatile unsigned int v5; // ebx
  unsigned int v6; // esi
  unsigned __int64 v12; // rax
  D3DBaseTexture *v13; // esi
  _DWORD *v14; // ebx
  void *v15; // eax
  void *v16; // esi
  signed int v17; // eax
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  unsigned int v22; // [esp+10h] [ebp-4h]

  ++D3DK::g_PerfCounters.m_APICounters[107];
  if ( D3DK::g_pDevice->m_StateFlags & 4 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Can't Present while recording a push-buffer");
  if ( D3DK::g_pDevice->m_dwOpcode )
    D3DK::HandleShaderSnapshotOpcode((int *)D3DK::g_pDevice);
  D3DK::SetFence(2u);
  if ( D3DK::g_pDevice->m_PresentCount - D3DK::g_pDevice->m_Miniport.m_VBlankFlipCount >= 2 )
  {
    ++D3DK::g_PerfCounters.m_PerformanceCounters[8].Count;
    if ( D3DK::g_PerfCounters.m_Breakperfctr == 8
      && D3DK::g_PerfCounters.m_PerformanceCounters[8].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
    {
      __debugbreak();
    }
    v4 = __rdtsc();
    v5 = KeTickCount;
    v22 = HIDWORD(v4);
    v6 = v4;
    do
    {
      D3DK::BusyLoop();
      _EAX = KeTickCount - v5;
      if ( KeTickCount - v5 > D3D__DeadlockTimeOutVal )
        RtlRip(0, 0, "Possible deadlock, blocked for more than 2 seconds.");
      LOBYTE(_EAX) = D3DK::g_DpcRIPFired;
      if ( D3DK::g_DpcRIPFired )
      {
        RtlRip(0, 0, "Graphics processor error.");
        D3DK::g_DpcRIPFired = 0;
      }
    }
    while ( D3DK::g_pDevice->m_PresentCount - D3DK::g_pDevice->m_Miniport.m_VBlankFlipCount >= 2 );
    __asm { cpuid }
    v12 = __rdtsc() - __PAIR__(v22, v6);
    D3DK::g_PerfCounters.m_PerformanceCounters[8].Cycles += v12;
    if ( D3DK::g_PerfCounters.m_pfnCycleThresholdHandler
      && D3DK::g_PerfCounters.m_DumpWaitCycleTimesThreshold < (unsigned int)v12 )
    {
      D3DK::g_PerfCounters.m_pfnCycleThresholdHandler(PERF_PRESENT_WAITS, v12);
    }
  }
  ++D3DK::g_pDevice->m_PresentCount;
  D3DK::AliasedFlip();
  D3DK::CDevice::KickOff(D3DK::g_pDevice, (int *)D3DK::g_pDevice);
  v13 = (D3DBaseTexture *)&D3DK::g_pDevice->m_FrameBufferSurfaces[1];
  if ( (D3DK::g_pDevice->m_FrameBufferSurfaces[1].Common & 0x70000) != 327680 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "PixelJar::IsSurface(pResource)");
  if ( D3DK::g_pDevice->m_FrameBufferSurfaces[1].Parent )
    v13 = D3DK::g_pDevice->m_FrameBufferSurfaces[1].Parent;
  v13->Lock = D3DK::g_pDevice->m_CpuTime;
  if ( D3DK::g_pDevice->m_Miniport.m_FirstFlip )
  {
    v14 = D3DK::g_pDevice->m_Miniport.m_RegisterBase;
    D3DK::KickOffAndWaitForIdle((int *)D3DK::g_pDevice);
    v14[1573376] = D3DK::g_FlipAddress;
    v15 = AvGetSavedDataAddress();
    v16 = v15;
    if ( v15 )
    {
      v17 = MmQueryAllocationSize(v15);
      MmPersistContiguousMemory(v18, v19, (int)v16, v16, v17, 0);
      MmFreeContiguousMemory(v20, v21, (int *)D3DK::g_pDevice, v16);
      AvSetSavedDataAddress(0);
    }
    AvSendTVEncoderOption(v14, 9u, 0, 0);
    D3DK::g_pDevice->m_Miniport.m_FirstFlip = 0;
  }
  D3DPERF_HandlePresent((int *)D3DK::g_pDevice);
}