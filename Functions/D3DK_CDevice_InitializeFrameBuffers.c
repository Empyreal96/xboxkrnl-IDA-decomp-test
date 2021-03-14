// write access to const memory has been detected, the output may be wrong!
int __thiscall D3DK::CDevice::InitializeFrameBuffers(D3DK::CDevice *this, _D3DPRESENT_PARAMETERS_ *pPresentationParams)
{
  unsigned int v2; // ecx
  _D3DFORMAT v3; // eax
  int *v4; // edi
  _D3DFORMAT v5; // ST28_4
  unsigned int v6; // edx
  unsigned int v7; // ebx
  unsigned int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // esi
  unsigned int v12; // eax
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // ebx
  int *v16; // edi
  char *v17; // edx
  unsigned int v25; // eax
  int *v26; // edi
  unsigned int v27; // eax
  int v28; // edx
  int v29; // ecx
  unsigned int *v30; // ebx
  int v34; // ecx
  unsigned int v35; // ebx
  unsigned int v36; // esi
  signed int v41; // esi
  unsigned int *v42; // esi
  unsigned int *v43; // eax
  _D3DTILE tile; // [esp+0h] [ebp-4Ch]
  unsigned int backBufferWidth; // [esp+18h] [ebp-34h]
  unsigned int backBufferHeight; // [esp+1Ch] [ebp-30h]
  _D3DFORMAT postfilterFormat; // [esp+20h] [ebp-2Ch]
  unsigned int height; // [esp+24h] [ebp-28h]
  _D3DFORMAT autoDepthStencilFormat; // [esp+28h] [ebp-24h]
  unsigned int v50; // [esp+2Ch] [ebp-20h]
  int doAntiAlias; // [esp+30h] [ebp-1Ch]
  char *pFrame; // [esp+34h] [ebp-18h]
  unsigned int frameCount; // [esp+38h] [ebp-14h]
  unsigned int backBufferCount; // [esp+3Ch] [ebp-10h]
  unsigned int format; // [esp+40h] [ebp-Ch]
  unsigned int size; // [esp+44h] [ebp-8h]
  _XMETAL_PushBuffer *pPusher; // [esp+48h] [ebp-4h]

  pPusher = (_XMETAL_PushBuffer *)this;
  v2 = pPresentationParams->BackBufferCount;
  backBufferCount = 1;
  if ( v2 >= 1 )
    backBufferCount = v2;
  v3 = D3DK::MapToLinearD3DFORMAT(pPresentationParams->BackBufferFormat);
  v4 = (int *)v3;
  v5 = pPresentationParams->AutoDepthStencilFormat;
  postfilterFormat = v3;
  autoDepthStencilFormat = D3DK::MapToLinearD3DFORMAT(v5);
  v6 = pPresentationParams->BackBufferWidth;
  v7 = pPresentationParams->BackBufferHeight;
  pPusher[1388].m_pThreshold = (unsigned int *)pPresentationParams->FullScreen_PresentationInterval;
  pPusher[1065].m_pThreshold = (unsigned int *)(backBufferCount + 1);
  pPusher[1078].m_pThreshold = (unsigned int *)v6;
  pPusher[1079].m_pPut = (unsigned int *)v7;
  v8 = pPresentationParams->MultiSampleType & 0xFFFF;
  v9 = pPresentationParams->MultiSampleType & 0x3000;
  backBufferWidth = v6;
  backBufferHeight = v7;
  dword_800C25E0 = v8;
  doAntiAlias = v9;
  if ( !v9 )
  {
    v8 = 17;
    dword_800C25E0 = 17;
  }
  v10 = v8 & 0xF0000;
  if ( (v8 & 0xF0000) > 0x30000 )
  {
    if ( v10 == 0x40000 )
      v4 = (int *)18;
  }
  else if ( (v8 & 0xF0000) == 196608 )
  {
    v4 = (int *)30;
  }
  else if ( v10 == 0x10000 )
  {
    v4 = (int *)28;
  }
  else if ( v10 == 0x20000 )
  {
    v4 = (int *)17;
  }
  v11 = v6 * ((unsigned __int8)v8 >> 4);
  height = v7 * (v8 & 0xF);
  v12 = D3DK::CalcTilePitch(v11, (_D3DFORMAT)v4);
  v15 = D3DK::PixelJar::EncodeFormat(v4, v11, height, 1u, 1u, (_D3DFORMAT)v4, v12, 1, 0, 0, &format, &size);
  if ( doAntiAlias )
    frameCount = 1;
  else
    frameCount = backBufferCount + 1;
  if ( v15 & 0x3F )
    D3DK::DXGRIP(v4, "Assertion failure: %s", "(frameSize & (D3D_RENDER_MEMORY_ALIGNMENT - 1)) == 0");
  v16 = (int *)((v15 * frameCount + 0x3FFF) & 0xFFFFC000);
  v17 = (char *)MmAllocateContiguousMemoryEx(v13, v14, v11, (unsigned int)v16, 0, 0x3FFB000u, 0x4000u, 0x404u);
  if ( v17 )
  {
    _EAX = 1;
    _ECX = &D3D__AllocsContiguous;
    __asm { xadd    [ecx], this }
  }
  pFrame = v17;
  if ( !v17 )
    goto LABEL_38;
  pPusher[1064].m_pThreshold = (unsigned int *)v17;
  v25 = frameCount;
  if ( frameCount )
  {
    frameCount = 0;
    v50 = v25;
    do
    {
      D3DK::InitializeSurface(v16, (D3DSurface *)((char *)&pPusher[1066] + frameCount), format, size, pFrame);
      _ZF = v50 == 1;
      pFrame += v15;
      frameCount += 24;
      --v50;
    }
    while ( !_ZF );
  }
  if ( v11 != 1920 )
  {
    tile.Flags = 0;
    tile.pMemory = pPusher[1064].m_pThreshold;
    tile.Size = (unsigned int)v16;
    tile.Pitch = D3DK::PixelJar::GetPitch((D3DPixelContainer *)&pPusher[1066]);
    D3DDevice_SetTile(0, &tile);
  }
  if ( pPresentationParams->EnableAutoDepthStencil )
  {
    v26 = (int *)autoDepthStencilFormat;
    v27 = D3DK::CalcTilePitch(v11, autoDepthStencilFormat);
    v16 = (int *)((D3DK::PixelJar::EncodeFormat(v26, v11, height, 1u, 1u, (_D3DFORMAT)v26, v27, 1, 0, 0, &format, &size)
                 + 0x3FFF) & 0xFFFFC000);
    v30 = (unsigned int *)MmAllocateContiguousMemoryEx(v28, v29, v11, (unsigned int)v16, 0, 0x3FFB000u, 0x4000u, 0x404u);
    if ( !v30 )
    {
      D3DK::WARNING(v16, "InitializeFrameBuffers - unable to allocate Z buffer");
      return (int)&loc_80070009 + 5;
    }
    _EAX = 1;
    _ECX = &D3D__AllocsContiguous;
    __asm { xadd    [ecx], this }
    pPusher[1075].m_pPut = v30;
    D3DK::InitializeSurface(v16, (D3DSurface *)&pPusher[1075].m_pThreshold, format, size, v30);
    if ( v11 != 1920 )
    {
      tile.Flags = -2147483647;
      tile.pMemory = v30;
      tile.Size = (unsigned int)v16;
      tile.Pitch = D3DK::PixelJar::GetPitch((D3DPixelContainer *)&pPusher[1075].m_pThreshold);
      tile.ZOffset = 0;
      tile.ZStartTag = 0;
      if ( (D3DK::g_TextureFormat[autoDepthStencilFormat] & 0x3C) == 32 )
        tile.Flags = -2080374783;
      D3DDevice_SetTile(1u, &tile);
    }
  }
  if ( doAntiAlias )
  {
    v35 = D3DK::PixelJar::EncodeFormat(
            v16,
            backBufferWidth,
            backBufferHeight,
            1u,
            1u,
            postfilterFormat,
            0,
            1,
            0,
            0,
            &format,
            &size);
    if ( v35 & 0x3F )
      D3DK::DXGRIP(v16, "Assertion failure: %s", "(frameSize & (D3D_RENDER_MEMORY_ALIGNMENT - 1)) == 0");
    v36 = backBufferCount;
    v16 = (int *)MmAllocateContiguousMemoryEx(
                   backBufferCount * v35,
                   v34,
                   backBufferCount,
                   backBufferCount * v35,
                   0,
                   0x3FFB000u,
                   0x4000u,
                   0x404u);
    if ( !v16 )
      goto LABEL_38;
    _EAX = 1;
    _ECX = &D3D__AllocsContiguous;
    __asm { xadd    [ecx], this }
    if ( !v16 )
    {
LABEL_38:
      D3DK::WARNING(v16, "InitializeFrameBuffers - unable to allocate pre-filter buffer");
      return (int)&loc_80070009 + 5;
    }
    pPusher[1065].m_pPut = (unsigned int *)v16;
    if ( v36 >= 1 )
    {
      v41 = 3;
      autoDepthStencilFormat = backBufferCount;
      do
      {
        D3DK::InitializeSurface(v16, (D3DSurface *)&pPusher[v41 + 1066], format, size, v16);
        v16 = (int *)((char *)v16 + v35);
        v41 += 3;
        --autoDepthStencilFormat;
      }
      while ( autoDepthStencilFormat );
    }
  }
  v42 = XMETAL_StartPush(v16, pPusher);
  if ( doAntiAlias )
    v43 = (unsigned int *)2;
  else
    v43 = pPusher[1065].m_pThreshold;
  XMETAL_Push3f(v16, v42, 0x120u, 0.0, COERCE_FLOAT(1), *(float *)&v43);
  XMETAL_EndPush(v16, pPusher, v42 + 4);
  return 0;
}