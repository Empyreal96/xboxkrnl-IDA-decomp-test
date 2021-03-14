// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetRenderTarget(D3DSurface *pRenderTarget, D3DSurface *pZBuffer)
{
  D3DSurface *v2; // esi
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // ebx
  char v6; // al
  unsigned int v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // edx
  D3DSurface *v10; // eax
  D3DSurface *v11; // esi
  D3DSurface *v12; // esi
  void *v13; // ebx
  unsigned int *v14; // esi
  float v15; // eax
  unsigned int v16; // ebx
  D3DK::CDevice *v17; // eax
  unsigned int v18; // eax
  unsigned int *v19; // esi
  D3DK::CDevice *v20; // eax
  D3DK::CDevice *v21; // eax
  _D3DVIEWPORT8 viewport; // [esp+Ch] [ebp-2Ch]
  unsigned int pitch; // [esp+24h] [ebp-14h]
  unsigned int zetaBase; // [esp+28h] [ebp-10h]
  unsigned int Zpitch; // [esp+2Ch] [ebp-Ch]
  unsigned int height; // [esp+30h] [ebp-8h]
  unsigned int width; // [esp+34h] [ebp-4h]

  v2 = pRenderTarget;
  ++D3DK::g_PerfCounters.m_APICounters[158];
  if ( !pRenderTarget )
  {
    pRenderTarget = D3DK::g_pDevice->m_pRenderTarget;
    v2 = D3DK::g_pDevice->m_pRenderTarget;
  }
  v3 = v2->Size;
  if ( v3 )
    width = (v2->Size & 0xFFF) + 1;
  else
    width = 1 << ((v2->Format >> 20) & 0xF);
  if ( v3 )
    v4 = ((v3 >> 12) & 0xFFF) + 1;
  else
    v4 = 1 << (HIBYTE(v2->Format) & 0xF);
  height = v4;
  v5 = D3DK::PixelJar::GetPitch((D3DPixelContainer *)&v2->Common);
  pitch = v5;
  if ( pZBuffer )
    Zpitch = D3DK::PixelJar::GetPitch((D3DPixelContainer *)&pZBuffer->Common);
  else
    Zpitch = v5;
  if ( D3DK::g_TextureFormat[BYTE1(pRenderTarget->Format)] >= 0 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Invalid render target format.");
  if ( (pRenderTarget->Common & 0x70000) != 327680 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Render target not a true surface (D3DCOMMON_TYPE_SURFACE)");
  if ( pZBuffer && (pZBuffer->Common & 0x70000) != 327680 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "ZStencil not a true surface (D3DCOMMON_TYPE_SURFACE)");
  if ( pRenderTarget->Data & 0x3F )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "The data for a render target must be 64-byte aligned.");
  if ( width > 0x1000 || height > 0x1000 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "The render target can be at most 4096x4096.");
  if ( D3DK::g_TextureFormat[BYTE1(pRenderTarget->Format)] & 1 )
  {
    if ( v5 < 0x40 )
      D3DK::DXGRIP(
        (int *)D3DK::g_pDevice,
        "A swizzled render target needs a pitch >= 64 bytes (width * bytes per pixel, no padding).");
  }
  else if ( v5 < 0x40 || v5 > 0xFFFF || v5 & 0x3F )
  {
    D3DK::DXGRIP(
      (int *)D3DK::g_pDevice,
      "An unswizzled render target requires a pitch that is nonzero, a multiple of 64 and is less than 64K.");
  }
  if ( pZBuffer && (Zpitch < 0x40 || Zpitch > 0xFFFF || Zpitch & 0x3F) )
    D3DK::DXGRIP(
      (int *)D3DK::g_pDevice,
      "An ZBuffer requires a pitch that is nonzero, a multiple of 64 and is less than 64K.");
  if ( width == 1 && height != 1 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "A render target that is only 1 pixel wide must also be 1 pixel high.");
  if ( pZBuffer )
  {
    if ( D3DK::g_TextureFormat[BYTE1(pZBuffer->Format)] & 1 )
      D3DK::DXGRIP((int *)D3DK::g_pDevice, "A swizzled depth buffer can't be used in rendering.");
    v6 = D3DK::g_TextureFormat[BYTE1(pRenderTarget->Format)];
    if ( v6 & 1 && ((unsigned __int8)v6 ^ D3DK::g_TextureFormat[BYTE1(pZBuffer->Format)]) & 0x3C )
      D3DK::DXGRIP(
        (int *)D3DK::g_pDevice,
        "A swizzled render target requires a depth-buffer format with the same number of bits-per-pixel.");
    if ( !(D3DK::g_TextureFormat[BYTE1(pZBuffer->Format)] & 0x40) )
      D3DK::DXGRIP((int *)D3DK::g_pDevice, "Invalid depth buffer format.");
    if ( pRenderTarget->Data & 0x3F )
      D3DK::DXGRIP((int *)D3DK::g_pDevice, "The data for a ZBuffer must be 64-byte aligned.");
    v7 = pZBuffer->Size;
    if ( v7 )
      v8 = (pZBuffer->Size & 0xFFF) + 1;
    else
      v8 = 1 << ((pZBuffer->Format >> 20) & 0xF);
    if ( width > v8
      || (v7 ? (v9 = ((v7 >> 12) & 0xFFF) + 1) : (v9 = 1 << (HIBYTE(pZBuffer->Format) & 0xF)), height > v9) )
    {
      D3DK::DXGRIP((int *)D3DK::g_pDevice, "The depth buffer must be at least as big as the render target");
    }
  }
  D3DK::InternalAddRef((int *)D3DK::g_pDevice, (D3DResource *)&pRenderTarget->Common);
  v10 = D3DK::g_pDevice->m_pRenderTarget;
  if ( v10 )
  {
    v11 = D3DK::g_pDevice->m_pRenderTarget;
    if ( (v10->Common & 0x70000) != 327680 )
      D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "PixelJar::IsSurface(pResource)");
    if ( v11->Parent )
      v11 = (D3DSurface *)v11->Parent;
    v11->Lock = D3DK::g_pDevice->m_CpuTime;
    D3DK::InternalReleaseSurface((D3DResource *)&D3DK::g_pDevice->m_pRenderTarget->Common);
  }
  v12 = D3DK::g_pDevice->m_pZBuffer;
  D3DK::g_pDevice->m_pRenderTarget = pRenderTarget;
  if ( v12 )
  {
    if ( (v12->Common & 0x70000) != 327680 )
      D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "PixelJar::IsSurface(pResource)");
    if ( v12->Parent )
      v12 = (D3DSurface *)v12->Parent;
    v12->Lock = D3DK::g_pDevice->m_CpuTime;
    D3DK::InternalReleaseSurface((D3DResource *)&D3DK::g_pDevice->m_pZBuffer->Common);
  }
  D3DK::g_pDevice->m_pZBuffer = pZBuffer;
  if ( pZBuffer )
  {
    D3DK::InternalAddRef((int *)D3DK::g_pDevice, (D3DResource *)&pZBuffer->Common);
    D3DK::PixelJar::GetDepthBufferScale(
      (int *)D3DK::g_pDevice,
      (D3DPixelContainer *)&pZBuffer->Common,
      &D3DK::g_pDevice->m_ZScale);
  }
  v13 = D3DK::CMiniport::SetDmaRange(&D3DK::g_pDevice->m_Miniport, 9u, pRenderTarget);
  zetaBase = (unsigned int)D3DK::CMiniport::SetDmaRange(&D3DK::g_pDevice->m_Miniport, 0xAu, pZBuffer);
  v14 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  if ( pZBuffer )
    LODWORD(v15) = pZBuffer->Data - zetaBase;
  else
    v15 = 0.0;
  XMETAL_Push3f(
    (int *)D3DK::g_pDevice,
    v14,
    0x20Cu,
    COERCE_FLOAT((unsigned __int16)pitch | (Zpitch << 16)),
    COERCE_FLOAT(pRenderTarget->Data - (_DWORD)v13),
    v15);
  v16 = height;
  XMETAL_Push2f((int *)D3DK::g_pDevice, v14 + 4, 0x200u, COERCE_FLOAT(width << 16), COERCE_FLOAT(height << 16));
  D3DK::CommonSetControl0(v17, (unsigned int *)D3DK::g_pDevice, v14 + 7, (int *)D3DK::g_pDevice);
  XMETAL_Push1f((int *)D3DK::g_pDevice, v14 + 9, 0x30Cu, 0.0);
  XMETAL_Push1f((int *)D3DK::g_pDevice, v14 + 11, 0x32Cu, 0.0);
  v18 = D3DK::g_pDevice->m_StateFlags;
  v19 = v14 + 13;
  if ( v18 & 0x100 && pRenderTarget == D3DK::g_pDevice->m_FrameBufferSurfaces )
  {
    D3DK::g_pDevice->m_StateFlags = v18 & 0xFFFFFEFF;
    XMETAL_Push1f((int *)D3DK::g_pDevice, v19, 0x130u, 0.0);
    v19 += 2;
  }
  XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v19);
  D3DK::CommonSetSurfaceFormat(v20, (int)D3DK::g_pDevice, (int *)D3DK::g_pDevice);
  D3DK::CommonSetPassthroughProgram(v21, (int *)D3DK::g_pDevice);
  viewport.X = 0;
  viewport.Y = 0;
  viewport.MinZ = 0.0;
  viewport.Width = width;
  viewport.Height = v16;
  viewport.MaxZ = 1.0;
  D3DDevice_SetViewport(&viewport);
  D3DDevice_SetRenderStateNotInline(D3DRS_DXT1NOISEENABLE, 0);
}