void __usercall D3DK::CDevice::FreeFrameBuffers(D3DK::CDevice *this@<ecx>, int *a2@<edi>)
{
  int v2; // edx
  D3DSurface *v3; // eax
  D3DSurface *v4; // esi
  D3DSurface *v5; // esi
  int v6; // edx
  void *v7; // esi
  int v15; // edx
  void *v16; // esi
  void *v20; // esi
  int *v21; // edi
  int *v25; // [esp-4h] [ebp-10h]
  D3DK::CDevice *v26; // [esp+8h] [ebp-4h]

  v26 = this;
  if ( !AvGetSavedDataAddress() )
    AvSendTVEncoderOption(v26->m_Miniport.m_RegisterBase, 9u, 1u, 0);
  v2 = (int)v26;
  v3 = v26->m_pRenderTarget;
  if ( v3 )
  {
    v4 = v26->m_pRenderTarget;
    if ( (v3->Common & 0x70000) != 327680 )
      D3DK::DXGRIP(a2, "Assertion failure: %s", "PixelJar::IsSurface(pResource)");
    if ( v4->Parent )
      v4 = (D3DSurface *)v4->Parent;
    v4->Lock = v26->m_CpuTime;
    D3DK::InternalReleaseSurface((D3DResource *)&v26->m_pRenderTarget->Common);
    v2 = (int)v26;
    v26->m_pRenderTarget = 0;
  }
  v5 = v26->m_pZBuffer;
  if ( v5 )
  {
    if ( (v5->Common & 0x70000) != 327680 )
      D3DK::DXGRIP(a2, "Assertion failure: %s", "PixelJar::IsSurface(pResource)");
    if ( v5->Parent )
      v5 = (D3DSurface *)v5->Parent;
    v5->Lock = v26->m_CpuTime;
    D3DK::InternalReleaseSurface((D3DResource *)&v26->m_pZBuffer->Common);
    v26->m_pZBuffer = 0;
  }
  v25 = a2;
  if ( v26->m_pAutoDepthBuffer )
  {
    D3DDevice_SetTile(1u, 0);
    v6 = (int)v26;
    v7 = v26->m_pAutoDepthBuffer;
    if ( !D3D__AllocsContiguous )
      D3DK::DXGRIP(a2, "Assertion failure: %s", "D3D__AllocsContiguous != 0");
    _EAX = -1;
    _ECX = &D3D__AllocsContiguous;
    __asm { xadd    [ecx], this }
    MmFreeContiguousMemory(v6, (int)&D3D__AllocsContiguous, a2, v7);
    v26->m_pAutoDepthBuffer = 0;
    memset(&v26->m_AutoDepthSurface, 0, sizeof(v26->m_AutoDepthSurface));
    a2 = (int *)&v26->m_DisplayWidth;
  }
  if ( v26->m_pFrameBufferBase )
  {
    D3DDevice_SetTile(0, 0);
    v15 = (int)v26;
    v16 = v26->m_pFrameBufferBase;
    if ( !D3D__AllocsContiguous )
      D3DK::DXGRIP(a2, "Assertion failure: %s", "D3D__AllocsContiguous != 0");
    _EAX = -1;
    _ECX = &D3D__AllocsContiguous;
    __asm { xadd    [ecx], this }
    MmFreeContiguousMemory(v15, (int)&D3D__AllocsContiguous, a2, v16);
    v26->m_pFrameBufferBase = 0;
    memset(v26->m_FrameBufferSurfaces, 0, sizeof(v26->m_FrameBufferSurfaces));
  }
  v20 = v26->m_pAntiAliasBufferBase;
  v21 = v25;
  if ( v20 )
  {
    if ( !D3D__AllocsContiguous )
      D3DK::DXGRIP(v25, "Assertion failure: %s", "D3D__AllocsContiguous != 0");
    _EAX = -1;
    _ECX = &D3D__AllocsContiguous;
    __asm { xadd    [ecx], this }
    MmFreeContiguousMemory(v2, (int)&D3D__AllocsContiguous, v21, v20);
    v26->m_pAntiAliasBufferBase = 0;
  }
}