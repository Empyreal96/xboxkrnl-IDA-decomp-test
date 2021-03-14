// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DK::AntiAliasedCopy(tagRECT *Rect)
{
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx
  unsigned int *v5; // eax
  unsigned int *v6; // esi
  unsigned int *v7; // eax
  unsigned int *v8; // esi
  unsigned int *v9; // esi
  unsigned int *v10; // esi
  D3DK::AntiAliasedSavedState savedState; // [esp+Ch] [ebp-260h]
  unsigned int yScale; // [esp+264h] [ebp-8h]
  unsigned int flipAddress; // [esp+268h] [ebp-4h]

  v1 = D3DK::g_pDevice->m_FrameBufferCount;
  if ( v1 != 2 && v1 != 3 )
    D3DK::DXGRIP(
      (int *)D3DK::g_pDevice,
      "Assertion failure: %s",
      "(pDevice->m_FrameBufferCount == 2) || (pDevice->m_FrameBufferCount == 3)");
  if ( D3DK::g_pDevice->m_FrameBufferCount > 2 && D3DK::g_pDevice->m_PresentationInterval != 0x80000000 )
  {
    v2 = D3DK::g_pDevice->m_FrameBufferSurfaces[2].Data;
    v3 = D3DK::g_pDevice->m_FrameBufferSurfaces[2].Lock;
    D3DK::g_pDevice->m_FrameBufferSurfaces[2].Data = D3DK::g_pDevice->m_FrameBufferSurfaces[1].Data;
    D3DK::g_pDevice->m_FrameBufferSurfaces[2].Lock = D3DK::g_pDevice->m_FrameBufferSurfaces[1].Lock;
    D3DK::g_pDevice->m_FrameBufferSurfaces[1].Data = v2;
    D3DK::g_pDevice->m_FrameBufferSurfaces[1].Lock = v3;
  }
  D3DK::AntiAliasedSaveState((int *)D3DK::g_pDevice, &savedState);
  yScale = 0;
  v4 = 2;
  flipAddress = D3DK::g_pDevice->m_FrameBufferSurfaces[1].Data;
  D3DK::g_FlipAddress = flipAddress;
  D3DK::AntiAliasedSetState(
    (int *)D3DK::g_pDevice,
    &savedState,
    &D3DK::g_pDevice->m_FrameBufferSurfaces[1],
    D3DK::g_pDevice->m_FrameBufferSurfaces,
    v4);
  v5 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  v6 = v5;
  if ( D3DK::g_pDevice->m_PresentationInterval == 0x80000000 )
  {
    v7 = D3DK::AntiAliasedFilterBlt(v5, 0, yScale, Rect);
    v8 = v7;
    if ( D3DK::g_pDevice->m_PresentCount == 1 )
    {
      XMETAL_Push1f((int *)D3DK::g_pDevice, v7, 0x110u, 0.0);
      v8 += 2;
    }
    XMETAL_Push1f((int *)D3DK::g_pDevice, v8, 0x1D8Cu, *(float *)&flipAddress);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v8 + 2, 0x100u, COERCE_FLOAT(768));
    v9 = v8 + 4;
  }
  else if ( D3DK::g_pDevice->m_FrameBufferCount >= 3 )
  {
    XMETAL_Push1f((int *)D3DK::g_pDevice, v5, 0x130u, 0.0);
    v10 = D3DK::AntiAliasedFilterBlt(v6 + 2, 0, yScale, Rect);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v10, 0x110u, 0.0);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v10 + 2, 0x1D8Cu, *(float *)&flipAddress);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v10 + 4, 0x100u, COERCE_FLOAT(772));
    XMETAL_Push1f((int *)D3DK::g_pDevice, v10 + 6, 0x12Cu, 0.0);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v10 + 8, 0x100u, 0.0);
    v9 = v10 + 10;
  }
  else
  {
    XMETAL_Push1f((int *)D3DK::g_pDevice, v5, 0x12Cu, 0.0);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v6 + 2, 0x100u, 0.0);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v6 + 4, 0x110u, 0.0);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v6 + 6, 0x1D8Cu, *(float *)&flipAddress);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v6 + 8, 0x100u, COERCE_FLOAT(772));
    XMETAL_Push1f((int *)D3DK::g_pDevice, v6 + 10, 0x130u, 0.0);
    v9 = D3DK::AntiAliasedFilterBlt(v6 + 12, 0, yScale, Rect);
  }
  XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v9);
  D3DK::AntiAliasedRestoreState(&savedState);
}