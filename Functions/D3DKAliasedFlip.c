// write access to const memory has been detected, the output may be wrong!
void D3DK::AliasedFlip()
{
  unsigned int v0; // eax
  char *v1; // edx
  int v2; // ecx
  unsigned int v3; // edx
  int *v4; // edi
  unsigned int *v5; // edi
  int v6; // edi
  void *colorBase; // [esp+Ch] [ebp-4h]

  v0 = D3DK::g_pDevice->m_FrameBufferCount - 1;
  v1 = (char *)D3DK::g_pDevice + 24 * v0;
  v2 = (int)(v1 + 8532);
  v3 = *((_DWORD *)v1 + 2134);
  v4 = *(int **)v2;
  if ( D3DK::g_pDevice->m_FrameBufferCount != 1 )
  {
    do
    {
      *(_DWORD *)v2 = *(_DWORD *)(v2 - 24);
      *(_DWORD *)(v2 + 4) = *(_DWORD *)(v2 - 20);
      v2 -= 24;
      --v0;
    }
    while ( v0 );
  }
  D3DK::g_pDevice->m_FrameBufferSurfaces[0].Data = (unsigned int)v4;
  D3DK::g_pDevice->m_FrameBufferSurfaces[0].Lock = v3;
  colorBase = D3DK::CMiniport::SetDmaRange(&D3DK::g_pDevice->m_Miniport, 9u, D3DK::g_pDevice->m_FrameBufferSurfaces);
  v5 = XMETAL_StartPush(v4, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f((int *)v5, v5, 0x12Cu, 0.0);
  XMETAL_Push1f((int *)v5, v5 + 2, 0x100u, 0.0);
  D3DK::g_FlipAddress = D3DK::g_pDevice->m_FrameBufferSurfaces[1].Data;
  XMETAL_Push1f((int *)v5, v5 + 4, 0x110u, 0.0);
  XMETAL_Push1f((int *)v5, v5 + 6, 0x1D8Cu, 0.0);
  if ( D3DK::g_pDevice->m_PresentationInterval == 0x80000000 )
    XMETAL_Push1f((int *)v5, v5 + 8, 0x100u, COERCE_FLOAT(768));
  else
    XMETAL_Push1f((int *)v5, v5 + 8, 0x100u, COERCE_FLOAT(772));
  v6 = (int)(v5 + 10);
  if ( D3DK::g_pDevice->m_pRenderTarget == D3DK::g_pDevice->m_FrameBufferSurfaces )
  {
    XMETAL_Push1f((int *)v6, (unsigned int *)v6, 0x130u, 0.0);
    XMETAL_Push1f(
      (int *)v6,
      (unsigned int *)(v6 + 8),
      0x210u,
      COERCE_FLOAT(D3DK::g_pDevice->m_FrameBufferSurfaces[0].Data - (_DWORD)colorBase));
    XMETAL_EndPush((int *)(v6 + 16), &D3DK::g_pDevice->m_Pusher, (unsigned int *)(v6 + 16));
  }
  else
  {
    D3DK::g_pDevice->m_StateFlags |= 0x100u;
    XMETAL_EndPush((int *)v6, &D3DK::g_pDevice->m_Pusher, (unsigned int *)v6);
  }
}