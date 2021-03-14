// write access to const memory has been detected, the output may be wrong!
unsigned int *__usercall D3DK::CDevice::MakeSpace@<eax>(D3DK::CDevice *this@<ecx>, int *a2@<edi>)
{
  unsigned int *result; // eax
  unsigned int *v3; // esi
  unsigned int *v4; // edx
  int *v5; // edi
  unsigned int *v6; // eax
  D3DK::CDevice *v7; // ecx
  D3DK::CDevice *v8; // ecx
  unsigned int v9; // esi
  unsigned int *v10; // eax
  volatile unsigned int v11; // ebx
  unsigned int *v12; // eax
  D3DK::CDevice *v13; // eax
  int v14; // esi
  int *v15; // edi
  unsigned int v16; // ebx
  D3DK::FenceEncoding *v17; // edx
  unsigned __int64 v18; // rax
  int *v19; // edi
  unsigned int v20; // esi
  unsigned __int64 v26; // rax
  int *v27; // edi
  unsigned int *v28; // eax
  D3DK::CDevice *v29; // edx
  int *v30; // eax
  int i; // ecx
  unsigned int v32; // eax
  unsigned __int64 v33; // rax
  unsigned int v34; // edi
  unsigned int v35; // esi
  unsigned __int64 v41; // rax
  int *v42; // [esp-8h] [ebp-20h]
  unsigned int *pTarget; // [esp+4h] [ebp-14h]
  unsigned int *pSegment; // [esp+8h] [ebp-10h]
  unsigned int *pSegmenta; // [esp+8h] [ebp-10h]
  unsigned int *pStart; // [esp+Ch] [ebp-Ch]
  unsigned int *pEnd; // [esp+10h] [ebp-8h]
  D3DK::CDevice *v48; // [esp+14h] [ebp-4h]

  v48 = this;
  if ( this->m_StateFlags & 4 )
  {
    this->m_PushBufferRecordWrapSize += (unsigned int)this->m_Pusher.m_pPut - this->m_pPushBufferRecordResource->Data;
    this->m_Pusher.m_pPut = (unsigned int *)this->m_pPushBufferRecordResource->Data;
    result = this->m_Pusher.m_pPut;
  }
  else
  {
    v3 = this->m_Pusher.m_pPut;
    v4 = this->m_pPushLimit;
    v42 = a2;
    pEnd = (unsigned int *)((char *)this->m_Pusher.m_pPut + D3DK::CDevice::m_PushSegmentSize);
    v5 = (int *)((char *)this->m_Pusher.m_pPut
               + D3DK::CDevice::m_PushSegmentSize
               + (D3DK::CDevice::m_PushSegmentSize >> 1));
    pStart = this->m_Pusher.m_pPut;
    if ( v5 >= (int *)v4 )
    {
      if ( (unsigned int *)((char *)v3 + (D3DK::CDevice::m_PushSegmentSize >> 1)) > v4 )
      {
        ++D3DK::g_PerfCounters.m_PerformanceCounters[14].Count;
        if ( D3DK::g_PerfCounters.m_Breakperfctr == 14
          && D3DK::g_PerfCounters.m_PerformanceCounters[14].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
        {
          __debugbreak();
        }
        v6 = D3DK::CDevice::GpuGet(this, v5);
        v7 = v48;
        if ( v6 > v48->m_Pusher.m_pPut )
        {
          D3DK::DXGRIP(v5, "Assertion failure: %s", "GpuGet() <= m_Pusher.m_pPut");
          v7 = v48;
        }
        v7->m_PusherLastSize = (char *)v7->m_Pusher.m_pPut - (char *)v7->m_pPushBase;
        *v48->m_Pusher.m_pPut = D3DK::GetGPUAddressFromWC(v5, v48->m_pPushBase) + 1;
        v8 = v48;
        if ( v48->m_Pusher.m_pPut >= v48->m_pPushLimit )
        {
          D3DK::DXGRIP(v5, "Assertion failure: %s", "m_Pusher.m_pPut < m_pPushLimit");
          v8 = v48;
        }
        do
        {
          v9 = v8->m_pControlDma->Get;
          if ( v9 > 0x4000000 )
          {
            DbgPrint(v5, "DebugVerifyPhysical - Not a valid physical memory offset.");
            DbgPrint(v5, "\n");
            __debugbreak();
            v8 = v48;
          }
        }
        while ( (unsigned int *)(v9 | 0x80000000) == v8->m_pPushBase );
        D3DK::g_PerfCounters.m_PushBufferEndDwordsSkipped += (_DWORD)((char *)v8->m_pPushLimit
                                                                    - (char *)v8->m_Pusher.m_pPut) >> 2;
        v10 = v8->m_pPushBase;
        v8->m_Pusher.m_pPut = v10;
        this = v48;
        pStart = v10;
        v4 = (unsigned int *)((char *)v10 + D3DK::CDevice::m_PushSegmentSize);
        v3 = v10;
      }
      pEnd = v4;
    }
    v11 = *this->m_pGpuTime;
    v12 = D3DK::CDevice::GpuGet(this, v5);
    if ( v3 < v12 && v12 <= pEnd )
    {
      pTarget = (unsigned int *)((char *)v3 + (D3DK::CDevice::m_PushBufferSize >> 1));
      v13 = v48;
      v14 = v48->m_PusherLastSegment;
      v15 = (int *)(v48->m_CpuTime - v11);
      v16 = *((_DWORD *)&v48->m_Pusher.m_pPut + 3 * v14 + 9);
      v17 = v48->m_PusherSegment[v14].pEncoding;
      pSegment = &v48->m_PusherSegment[v14].pEncoding->m_SemaphoreCommand;
      if ( v48->m_CpuTime - v16 < (unsigned int)v15 )
      {
        while ( 1 )
        {
          if ( v17 < (D3DK::FenceEncoding *)pStart )
          {
            if ( !v13->m_PusherLastSize )
            {
              D3DK::DXGRIP(v15, "Assertion failure: %s", "m_PusherLastSize != 0");
              v13 = v48;
              v17 = (D3DK::FenceEncoding *)pSegment;
            }
            v17 = (D3DK::FenceEncoding *)((char *)v17 + v13->m_PusherLastSize);
          }
          if ( v17 < (D3DK::FenceEncoding *)pTarget )
            break;
          v14 = ((_BYTE)v14 - 1) & 0xF;
          if ( v14 == v13->m_PusherLastSegment )
            goto Spin_0;
          pSegment = &v13->m_PusherSegment[v14].pEncoding->m_SemaphoreCommand;
          v16 = *((_DWORD *)&v13->m_Pusher.m_pPut + 3 * v14 + 9);
          if ( v13->m_CpuTime - v16 >= (unsigned int)v15 )
            goto Spin_0;
          v17 = v13->m_PusherSegment[v14].pEncoding;
        }
        ++D3DK::g_PerfCounters.m_PerformanceCounters[6].Count;
        if ( D3DK::g_PerfCounters.m_Breakperfctr == 6
          && D3DK::g_PerfCounters.m_PerformanceCounters[6].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
        {
          __debugbreak();
        }
        v33 = __rdtsc();
        v34 = HIDWORD(v33);
        v35 = v33;
        D3DK::BlockOnTime(v16, 1);
        __asm { cpuid }
        v41 = __rdtsc() - __PAIR__(v34, v35);
        v27 = (int *)((v41 + D3DK::g_PerfCounters.m_PerformanceCounters[6].Cycles) >> 32);
        D3DK::g_PerfCounters.m_PerformanceCounters[6].Cycles += v41;
        if ( D3DK::g_PerfCounters.m_pfnCycleThresholdHandler
          && D3DK::g_PerfCounters.m_DumpWaitCycleTimesThreshold < (unsigned int)v41 )
        {
          D3DK::g_PerfCounters.m_pfnCycleThresholdHandler(PERF_PUSHBUFFER_WAITS, v41);
        }
      }
      else
      {
Spin_0:
        ++D3DK::g_PerfCounters.m_PerformanceCounters[12].Count;
        if ( D3DK::g_PerfCounters.m_Breakperfctr == 12
          && D3DK::g_PerfCounters.m_PerformanceCounters[12].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
        {
          __debugbreak();
        }
        v18 = __rdtsc();
        v19 = (int *)HIDWORD(v18);
        v20 = v18;
        do
        {
          pSegmenta = (unsigned int *)400;
          do
            pSegmenta = (unsigned int *)((char *)pSegmenta - 1);
          while ( pSegmenta );
          _EAX = D3DK::CDevice::GpuGet(v48, v19);
        }
        while ( pStart < _EAX && _EAX <= pEnd );
        __asm { cpuid }
        v26 = __rdtsc() - __PAIR__((unsigned int)v19, v20);
        v27 = (int *)((v26 + D3DK::g_PerfCounters.m_PerformanceCounters[12].Cycles) >> 32);
        D3DK::g_PerfCounters.m_PerformanceCounters[12].Cycles += v26;
        if ( D3DK::g_PerfCounters.m_pfnCycleThresholdHandler
          && D3DK::g_PerfCounters.m_DumpWaitCycleTimesThreshold < (unsigned int)v26 )
        {
          D3DK::g_PerfCounters.m_pfnCycleThresholdHandler(PERF_CPUSPINDURINGWAIT_TIME, v26);
        }
      }
      v28 = D3DK::CDevice::GpuGet(v48, v27);
      if ( pStart < v28 && v28 <= pEnd )
        D3DK::DXGRIP(v27, "Assertion failure: %s", "!((pStart < pGet) && (pGet <= pEnd))");
    }
    v48->m_Pusher.m_pThreshold = pEnd - 129;
    v29 = v48;
    v30 = (int *)(v48->m_Pusher.m_pThreshold + 128);
    for ( i = 0; (unsigned int *)v30 >= v48->m_Pusher.m_pPut; ++i )
    {
      *v30 = ((unsigned __int16)i << 16) | 0xBEEF;
      v29 = v48;
      --v30;
    }
    v32 = v29->m_StateFlags;
    if ( v32 & 0x800 )
      v29->m_StateFlags = v32 | 0x1000;
    else
      D3DK::SetFence(1u);
    D3DK::CDevice::KickOff(v48, v42);
    result = v48->m_Pusher.m_pPut;
  }
  return result;
}