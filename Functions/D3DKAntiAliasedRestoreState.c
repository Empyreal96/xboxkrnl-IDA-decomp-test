void __stdcall D3DK::AntiAliasedRestoreState(D3DK::AntiAliasedSavedState *pSave)
{
  D3DK::AntiAliasedSavedState *v1; // esi
  int v2; // ebx
  unsigned int v3; // edi
  unsigned int *v4; // ebx
  unsigned int v5; // edi
  _D3DRENDERSTATETYPE v6; // edi
  unsigned int *v7; // ebx
  int notPure; // [esp+Ch] [ebp-4h]
  unsigned int *pSavea; // [esp+18h] [ebp+8h]

  v1 = pSave;
  D3DDevice_SetRenderTarget(pSave->pRenderTarget, pSave->pZBuffer);
  D3DResource_Release((int *)D3DK::g_pDevice, (D3DResource *)&pSave->pRenderTarget->Common);
  if ( pSave->pZBuffer )
    D3DResource_Release((int *)D3DK::g_pDevice, (D3DResource *)&pSave->pZBuffer->Common);
  D3DDevice_SetTexture(0, pSave->pTexture);
  if ( pSave->pTexture )
    D3DResource_Release((int *)D3DK::g_pDevice, (D3DResource *)&pSave->pTexture->Common);
  D3DDevice_SetPixelShader((unsigned int)pSave->pPixelShader);
  D3DDevice_SetVertexShader((int *)D3DK::g_pDevice, pSave->VertexShaderHandle);
  D3DDevice_SetViewport(&pSave->Viewport);
  v2 = ~(unsigned __int8)(D3DK::g_pDevice->m_StateFlags >> 4) & 1;
  notPure = ~(unsigned __int8)(D3DK::g_pDevice->m_StateFlags >> 4) & 1;
  D3DDevice_SetTextureStageStateNotInline(1u, 0, pSave->Stage1ColorOp);
  pSavea = pSave->RenderState;
  v3 = 0;
  do
  {
    if ( v2 || D3DK::g_AntiAliasedRenderStates[v3] >= 0x52 )
      D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)D3DK::g_AntiAliasedRenderStates[v3], *pSavea);
    v3 += 2;
    ++pSavea;
  }
  while ( v3 < 32 );
  v4 = v1->TextureState;
  v5 = 0;
  do
  {
    D3DDevice_SetTextureStageStateNotInline(0, (_D3DTEXTURESTAGESTATETYPE)D3DK::g_AntiAliasedTextureStates[v5], *v4);
    v5 += 2;
    ++v4;
  }
  while ( v5 < 22 );
  if ( notPure )
  {
    if ( v1->pPixelShader )
    {
      v6 = 0;
      v7 = v1->PixelShaderState;
      do
      {
        D3DDevice_SetRenderStateNotInline(v6++, *v7);
        ++v7;
      }
      while ( (unsigned int)v6 < 0x39 );
      D3DDevice_SetRenderStateNotInline(D3DRS_DEFERRED_MAX, v1->PSTextureModes);
    }
    D3DK::RestoreVertexShaders(v1->VertexShaders, 0x30u);
  }
}