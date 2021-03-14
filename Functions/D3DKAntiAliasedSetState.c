void __userpurge D3DK::AntiAliasedSetState(int *a1@<edi>, D3DK::AntiAliasedSavedState *pSave, D3DSurface *DstSurface, D3DSurface *SrcSurface, unsigned int Filter)
{
  unsigned int v5; // esi
  unsigned int v6; // esi
  int savedregs; // [esp+8h] [ebp+0h]

  v5 = 0;
  do
  {
    D3DDevice_SetRenderStateNotInline((_D3DRENDERSTATETYPE)D3DK::g_AntiAliasedRenderStates[v5], dword_8007A514[v5]);
    v5 += 2;
  }
  while ( v5 < 32 );
  v6 = 0;
  do
  {
    D3DDevice_SetTextureStageStateNotInline(
      0,
      (_D3DTEXTURESTAGESTATETYPE)D3DK::g_AntiAliasedTextureStates[v6],
      dword_8007A4BC[v6]);
    v6 += 2;
  }
  while ( v6 < 22 );
  D3DDevice_SetPixelShader(0);
  D3DDevice_SetVertexShader(a1, 0x104u);
  D3DDevice_SetRenderTarget(DstSurface, 0);
  D3DDevice_SetTextureStageStateNotInline(0, D3DTSS_MINFILTER, Filter);
  D3DDevice_SetTextureStageStateNotInline(0, D3DTSS_MAGFILTER, Filter);
  D3DDevice_SetTextureStageStateNotInline(1u, 0, 1u);
  qmemcpy(&pSave->SrcTexture, SrcSurface, sizeof(pSave->SrcTexture));
  pSave->SrcTexture.Common = pSave->SrcTexture.Common & 0xFFFCFFFF | 0x40000;
  D3DDevice_SetTexture(0, (D3DBaseTexture *)&pSave->SrcTexture.Common);
  D3DK::SetState((int)&savedregs, (int *)&pSave[1]);
}