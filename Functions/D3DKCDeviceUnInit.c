// write access to const memory has been detected, the output may be wrong!
void __usercall D3DK::CDevice::UnInit(D3DK::CDevice *this@<ecx>, int *a2@<edi>)
{
  unsigned int *v2; // esi
  unsigned int v3; // esi
  _DWORD *v4; // eax
  int v5; // edx
  D3DResource *v6; // esi
  int v7; // eax
  int *v8; // edi
  int v9; // ecx
  D3DResource *v10; // esi
  D3DResource *v11; // esi
  int *v12; // edi
  D3DResource *v13; // esi
  unsigned int v14; // esi
  int v15; // edx
  unsigned int *v16; // esi
  _DWORD *v24; // eax
  D3DK::CDevice *v25; // [esp+0h] [ebp-4h]

  v25 = this;
  if ( this->m_StateFlags & 4 )
  {
    D3DK::DXGRIP(a2, "Assertion failure: %s", "!(m_StateFlags & (STATE_RECORDPUSHBUFFER))");
    this = v25;
  }
  if ( this->m_Pusher.m_pPut )
  {
    D3DK::KickOffAndWaitForIdle(a2);
    v2 = v25->m_pPushBase;
    if ( ((_DWORD)v25->m_pPushBase & 0xF0000000) != 0x80000000 )
      D3DK::DXGRIP(a2, "AssertContiguous - the memory is not contiguous.");
    *v25->m_Pusher.m_pPut = ((unsigned int)v2 & 0xFFFFFFF) + 1;
    v25->m_Pusher.m_pPut = v25->m_pPushBase;
    D3DK::CDevice::KickOff(v25, a2);
    a2 = (int *)KeTickCount;
    while ( 1 )
    {
      this = v25;
      v3 = v25->m_pControlDma->Get;
      if ( v3 > 0x4000000 )
      {
        DbgPrint(a2, "DebugVerifyPhysical - Not a valid physical memory offset.");
        DbgPrint(a2, "\n");
        __debugbreak();
        this = v25;
      }
      if ( !((v3 ^ (_DWORD)this->m_pPushBase) & 0xFFFFFFF) )
        break;
      D3DK::BusyLoop();
      if ( KeTickCount - (unsigned int)a2 > D3D__DeadlockTimeOutVal )
        RtlRip(0, 0, "Possible deadlock, blocked for more than 2 seconds.");
      if ( D3DK::g_DpcRIPFired )
      {
        RtlRip(0, 0, "Graphics processor error.");
        D3DK::g_DpcRIPFired = 0;
      }
    }
  }
  while ( D3DK::CMiniport::IsFlipPending(&this->m_Miniport) )
    this = v25;
  if ( unk_8004C824 )
  {
    v4 = *(_DWORD **)(unk_8004C824 + 32);
    if ( v4 )
    {
      *v4 = 0;
      v4[1] = 0;
      v4[2] = 0;
    }
  }
  D3DK::CDevice::FreeFrameBuffers(v25, a2);
  if ( v25->m_pRenderTarget || v25->m_pZBuffer )
    D3DK::DXGRIP(a2, "Assertion failure: %s", "(m_pRenderTarget == NULL) && (m_pZBuffer == NULL)");
  v5 = (int)v25;
  v6 = (D3DResource *)&v25->m_pIndexBuffer->Common;
  if ( v6 )
  {
    if ( !(v6->Common & 0x780000) )
      D3DK::DXGRIP(a2, "Assertion failure: %s", "(pResource->Common & D3DCOMMON_INTREFCOUNT_MASK) != 0");
    if ( (v6->Common & 0x70000) == 327680 )
      D3DK::DXGRIP(a2, "Assertion failure: %s", "(pResource->Common & D3DCOMMON_TYPE_MASK) != D3DCOMMON_TYPE_SURFACE");
    v7 = v6->Common - 0x80000;
    v6->Common = v7;
    if ( !(v7 & 0x78FFFF) )
      D3DK::DestroyResource(v6);
  }
  v8 = (int *)2992;
  do
  {
    v9 = (int)v25;
    v10 = *(D3DResource **)((char *)v25 + (_DWORD)v8 - 16);
    if ( v10 )
    {
      if ( !(v10->Common & 0x780000) )
        D3DK::DXGRIP(v8, "Assertion failure: %s", "(pResource->Common & D3DCOMMON_INTREFCOUNT_MASK) != 0");
      v5 = v10->Common & 0x70000;
      if ( v5 == 327680 )
        D3DK::DXGRIP(v8, "Assertion failure: %s", "(pResource->Common & D3DCOMMON_TYPE_MASK) != D3DCOMMON_TYPE_SURFACE");
      v9 = v10->Common - 0x80000;
      v10->Common = v9;
      if ( !(v9 & 0x78FFFF) )
        D3DK::DestroyResource(v10);
    }
    v11 = *(D3DResource **)((char *)&v25->m_Pusher.m_pPut + (_DWORD)v8);
    if ( v11 )
    {
      if ( !(v11->Common & 0x780000) )
        D3DK::DXGRIP(v8, "Assertion failure: %s", "(pResource->Common & D3DCOMMON_INTREFCOUNT_MASK) != 0");
      if ( (v11->Common & 0x70000) == 327680 )
        D3DK::DXGRIP(v8, "Assertion failure: %s", "(pResource->Common & D3DCOMMON_TYPE_MASK) != D3DCOMMON_TYPE_SURFACE");
      v9 = v11->Common - 0x80000;
      v11->Common = v9;
      if ( !(v9 & 0x78FFFF) )
        D3DK::DestroyResource(v11);
    }
    ++v8;
  }
  while ( (unsigned int)v8 < 0xBC0 );
  v12 = 0;
  do
  {
    v13 = *(D3DResource **)((char *)dword_800C1EE0 + (_DWORD)v12);
    if ( v13 )
    {
      if ( !(v13->Common & 0x780000) )
        D3DK::DXGRIP(v12, "Assertion failure: %s", "(pResource->Common & D3DCOMMON_INTREFCOUNT_MASK) != 0");
      v5 = v13->Common & 0x70000;
      if ( v5 == 327680 )
        D3DK::DXGRIP(
          v12,
          "Assertion failure: %s",
          "(pResource->Common & D3DCOMMON_TYPE_MASK) != D3DCOMMON_TYPE_SURFACE");
      v9 = v13->Common - 0x80000;
      v13->Common = v9;
      if ( !(v9 & 0x78FFFF) )
        D3DK::DestroyResource(v13);
    }
    v12 += 3;
  }
  while ( (unsigned int)v12 < 0xC0 );
  v14 = 1168;
  do
  {
    if ( *(unsigned int **)((char *)&v25->m_Pusher.m_pPut + v14) )
      MmFreeContiguousMemory(v5, v9, v12, *(void **)((char *)&v25->m_Pusher.m_pPut + v14));
    v14 += 4;
  }
  while ( v14 < 0x4D0 );
  if ( v25->m_pCachedContiguousMemoryBase )
    MmFreeContiguousMemory(v5, (int)v25, v12, v25->m_pCachedContiguousMemoryBase);
  v15 = (int)v25;
  v16 = v25->m_pPushBase;
  if ( v16 )
  {
    if ( !D3D__AllocsContiguous )
      D3DK::DXGRIP(v12, "Assertion failure: %s", "D3D__AllocsContiguous != 0");
    _EAX = -1;
    _ECX = &D3D__AllocsContiguous;
    __asm { xadd    [ecx], this }
    MmFreeContiguousMemory(v15, (int)&D3D__AllocsContiguous, v12, v16);
  }
  if ( v25->m_pLights )
    D3DK::MemFree(v25->m_pLights);
  v24 = v25->m_Miniport.m_RegisterBase;
  if ( v24 )
  {
    v24[80] = 0;
    D3DK::CMiniport::ShutdownEngines(&v25->m_Miniport);
  }
  memset(D3DK::g_Stream, 0, sizeof(D3DK::g_Stream));
}