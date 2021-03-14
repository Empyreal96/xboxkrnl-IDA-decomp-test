void __usercall D3DK::SetState(int a1@<ebp>, int *a2@<edi>)
{
  unsigned int v2; // ebx

  v2 = D3DK::g_pDevice->m_DirtyFlags;
  if ( v2 )
  {
    if ( v2 & 1 )
      D3DK::LazySetPointParams(D3DK::g_pDevice);
    if ( v2 & 0x400 )
      D3DK::LazySetShaderStageProgram(D3DK::g_pDevice);
    if ( v2 & 8 )
      D3DK::LazySetCombiners(D3DK::g_pDevice);
    if ( v2 & 0x10 )
      D3DK::LazySetTextureState(D3DK::g_pDevice);
    if ( v2 & 0x40 )
      D3DK::LazySetSpecFogCombiner(a2, D3DK::g_pDevice);
    if ( v2 & 4 )
      D3DK::LazySetTextureTransform(D3DK::g_pDevice);
    if ( v2 & 0x20 )
      D3DK::LazySetLights(a2, D3DK::g_pDevice);
    if ( v2 & 2 )
      D3DK::LazySetTransform(a1, D3DK::g_pDevice);
    if ( D3DK::g_pDevice->m_DirtyFlags & 0x3FFFFC7F )
      D3DK::DXGRIP(
        a2,
        "Assertion failure: %s",
        "(pDevice->m_DirtyFlags & ~(DIRTY_VERTEXFORMAT_VB | DIRTY_VERTEXFORMAT_UP | DIRTY_VERTEXFORMAT_OFFSETS | DIRTY_DI"
        "RECT_INPUT | DIRTY_DIRECT_MODELVIEW)) == 0");
  }
}