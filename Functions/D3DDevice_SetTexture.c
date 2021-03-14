// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetTexture(unsigned int Stage, D3DBaseTexture *pTexture)
{
  unsigned int v2; // esi
  D3DBaseTexture *v3; // ebx
  D3DBaseTexture *v4; // eax
  int v5; // ecx
  unsigned int *v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // ebx
  unsigned int height; // ST1C_4
  unsigned int v10; // eax
  int v11; // ebx
  float v12; // ecx
  unsigned int v13; // edx
  unsigned int *v14; // esi
  D3DBaseTexture *pPrevious; // [esp+14h] [ebp-4h]
  unsigned int *pPusha; // [esp+20h] [ebp+8h]
  unsigned int *pPush; // [esp+20h] [ebp+8h]

  v2 = Stage;
  ++D3DK::g_PerfCounters.m_APICounters[162];
  if ( Stage >= 4 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "D3DDevice_SetTexture - Bad texture stage.");
  v3 = pTexture;
  if ( pTexture && (pTexture->Common & 0x70000) != 0x40000 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "D3DDevice_SetTexture - not given a true texture (D3DCOMMON_TYPE_TEXTURE)");
  if ( pTexture == D3DK::g_pDevice->m_Textures[Stage] )
  {
    ++D3DK::g_PerfCounters.m_PerformanceCounters[20].Count;
    if ( D3DK::g_PerfCounters.m_Breakperfctr == 20
      && D3DK::g_PerfCounters.m_PerformanceCounters[20].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
    {
      __debugbreak();
    }
  }
  v4 = D3DK::g_pDevice->m_Textures[Stage];
  pPrevious = D3DK::g_pDevice->m_Textures[Stage];
  if ( v4 )
  {
    if ( (v4->Common & 0x70000) == 327680 )
    {
      D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "!PixelJar::IsSurface(pResource)");
      v4 = pPrevious;
    }
    v4->Lock = D3DK::g_pDevice->m_CpuTime;
    if ( !(v4->Common & 0x780000) )
    {
      D3DK::DXGRIP(
        (int *)D3DK::g_pDevice,
        "Assertion failure: %s",
        "(pResource->Common & D3DCOMMON_INTREFCOUNT_MASK) != 0");
      v4 = pPrevious;
    }
    if ( (v4->Common & 0x70000) == 327680 )
    {
      D3DK::DXGRIP(
        (int *)D3DK::g_pDevice,
        "Assertion failure: %s",
        "(pResource->Common & D3DCOMMON_TYPE_MASK) != D3DCOMMON_TYPE_SURFACE");
      v4 = pPrevious;
    }
    v5 = v4->Common - 0x80000;
    v4->Common = v5;
    if ( !(v5 & 0x78FFFF) )
      D3DK::DestroyResource((D3DResource *)&v4->Common);
  }
  D3DK::g_pDevice->m_Textures[Stage] = pTexture;
  if ( !pTexture )
  {
    v6 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v6, (Stage << 6) + 6924, 0.0);
    XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v6 + 2);
    D3DK::g_pDevice->m_TextureCubemapAndDimension[Stage] = -1;
    D3DK::g_pDevice->m_DirtyFlags |= 0x408u;
    return;
  }
  D3DK::InternalAddRef((int *)D3DK::g_pDevice, (D3DResource *)&pTexture->Common);
  pPusha = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push2f((int *)D3DK::g_pDevice, pPusha, (v2 + 108) << 6, *(float *)&pTexture->Data, *(float *)&pTexture->Format);
  v7 = pTexture->Size;
  pPush = pPusha + 3;
  if ( v7 )
  {
    v8 = (pTexture->Size & 0xFFF) + 1;
    height = ((v7 >> 12) & 0xFFF) + 1;
    v10 = D3DK::PixelJar::GetPitch((D3DPixelContainer *)&pTexture->Common);
    XMETAL_Push1f((int *)D3DK::g_pDevice, pPush, (v2 << 6) + 6928, COERCE_FLOAT(v10 << 16));
    XMETAL_Push1f((int *)D3DK::g_pDevice, pPush + 2, (v2 << 6) + 6940, COERCE_FLOAT(height | (v8 << 16)));
    pPush += 4;
    v3 = pTexture;
  }
  v11 = v3->Format & 0xF4;
  if ( D3DK::g_pDevice->m_TextureCubemapAndDimension[v2] == v11 )
  {
    if ( !pPrevious )
      D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "pPrevious != NULL");
  }
  else
  {
    v12 = *(float *)&D3DK::g_pDevice->m_TextureControl0Enabled[v2];
    D3DK::g_pDevice->m_TextureCubemapAndDimension[v2] = v11;
    XMETAL_Push1f((int *)D3DK::g_pDevice, pPush, (v2 << 6) + 6924, v12);
    v13 = D3DK::g_pDevice->m_DirtyFlags | 0x400;
    v14 = pPush + 2;
    pPush += 2;
    D3DK::g_pDevice->m_DirtyFlags = v13;
    if ( !pPrevious )
    {
      D3DK::g_pDevice->m_DirtyFlags = v13 | 8;
      XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v14);
      return;
    }
  }
  XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, pPush);
}