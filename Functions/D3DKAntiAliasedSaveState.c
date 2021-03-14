void __userpurge D3DK::AntiAliasedSaveState(int *a1@<edi>, D3DK::AntiAliasedSavedState *pSave)
{
  D3DSurface *v2; // ST00_4
  D3DSurface *v3; // eax
  D3DBaseTexture *v4; // eax
  unsigned int *v5; // ecx
  unsigned int v6; // eax
  unsigned int *v7; // ecx
  unsigned int v8; // eax
  unsigned int *v9; // ecx
  unsigned int v10; // eax

  v2 = D3DK::g_pDevice->m_pRenderTarget;
  pSave->pRenderTarget = v2;
  D3DResource_AddRef(a1, (D3DResource *)&v2->Common);
  v3 = D3DK::g_pDevice->m_pZBuffer;
  pSave->pZBuffer = v3;
  if ( v3 )
    D3DResource_AddRef(a1, (D3DResource *)&v3->Common);
  v4 = D3DK::g_pDevice->m_Textures[0];
  pSave->pTexture = v4;
  if ( v4 )
    D3DResource_AddRef(a1, (D3DResource *)&v4->Common);
  pSave->pPixelShader = D3DK::g_pDevice->m_pPixelShader;
  pSave->VertexShaderHandle = D3DK::g_pDevice->m_VertexShaderHandle;
  qmemcpy(&pSave->Viewport, &D3DK::g_pDevice->m_Viewport, sizeof(pSave->Viewport));
  pSave->Stage1ColorOp = 0;
  v5 = &pSave->RenderState[1];
  v6 = 0;
  do
  {
    *(v5 - 1) = *(_DWORD *)(4 * D3DK::g_AntiAliasedRenderStates[v6] - 2146688056);
    *v5 = *(_DWORD *)(4 * dword_8007A518[v6] - 2146688056);
    v5[1] = *(_DWORD *)(4 * dword_8007A520[v6] - 2146688056);
    v5[2] = *(_DWORD *)(4 * dword_8007A528[v6] - 2146688056);
    v5[3] = *(_DWORD *)(4 * dword_8007A530[v6] - 2146688056);
    v5[4] = *(_DWORD *)(4 * dword_8007A538[v6] - 2146688056);
    v5[5] = *(_DWORD *)(4 * dword_8007A540[v6] - 2146688056);
    v5[6] = *(_DWORD *)(4 * dword_8007A548[v6] - 2146688056);
    v6 += 16;
    v5 += 8;
  }
  while ( v6 < 32 );
  v7 = pSave->TextureState;
  v8 = 0;
  do
  {
    *v7 = *(_DWORD *)(4 * D3DK::g_AntiAliasedTextureStates[v8] - 2146688568);
    v8 += 2;
    ++v7;
  }
  while ( v8 < 22 );
  if ( pSave->pPixelShader )
  {
    v9 = pSave->PixelShaderState;
    v10 = 0;
    do
    {
      *v9 = D3D__RenderState[v10];
      ++v10;
      ++v9;
    }
    while ( v10 < 57 );
    pSave->PSTextureModes = 0;
  }
  qmemcpy(pSave->VertexShaders, D3DK::g_pDevice->m_VertexShaderProgramSlots, sizeof(pSave->VertexShaders));
}