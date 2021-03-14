// write access to const memory has been detected, the output may be wrong!
void __thiscall SceneRenderer::render(SceneRenderer *this, bool b_with_shadows, bool b_use_blob_intensity)
{
  signed int v3; // ebx
  PrimitiveSet *v4; // ecx
  SceneRenderer *v5; // [esp+Ch] [ebp-4h]

  v5 = this;
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_ALPHABLENDENABLE, 0) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40304u, 0, 0);
    dword_800C24B4 = 0;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_ALPHATESTENABLE, 0) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40300u, 0, 0);
    dword_800C24B8 = 0;
  }
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 1u, D3DTSS_MINFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 14, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 1u, D3DTSS_MAGFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 13, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 1u, D3DTSS_MIPFILTER, 0) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 15, 0);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 1u, D3DTSS_ADDRESSU, 3u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 10, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 1u, D3DTSS_ADDRESSV, 3u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 11, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 1u, D3DTSS_ADDRESSW, 3u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 12, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 2u, D3DTSS_MINFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG1, 14, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 2u, D3DTSS_MAGFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG1, 13, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 2u, D3DTSS_MIPFILTER, 0) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG1, 15, 0);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 2u, D3DTSS_ADDRESSU, 3u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG1, 10, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 2u, D3DTSS_ADDRESSV, 3u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG1, 11, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 2u, D3DTSS_ADDRESSW, 3u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG1, 12, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 3u, D3DTSS_ADDRESSU, 4u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG2, 10, 4u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 3u, D3DTSS_ADDRESSV, 4u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG2, 11, 4u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 3u, D3DTSS_BORDERCOLOR, 0xFFFFFFFF) )
    D3DDevice_SetTextureState_BorderColor(3u, 0xFFFFFFFF);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 3u, D3DTSS_MINFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG2, 14, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 3u, D3DTSS_MAGFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG2, 13, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 3u, D3DTSS_MIPFILTER, 0) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG2, 15, 0);
  if ( b_with_shadows && !D3DDevice_SetRenderState_ParameterCheck((int *)3, D3DRS_SHADOWFUNC, 0x204u) )
    D3DDevice_SetRenderState_ShadowFunc((int *)3, 0x204u);
  v3 = 0;
  do
  {
    if ( v5->bUseLoDetail )
      v4 = v5->pSetLoDet[v3];
    else
      v4 = v5->pSetHiDet[v3];
    PrimitiveSet::render(v4, (int *)3, &light, b_use_blob_intensity);
    ++v3;
  }
  while ( v3 < 6 );
  if ( b_with_shadows && !D3DDevice_SetRenderState_ParameterCheck((int *)3, D3DRS_SHADOWFUNC, 0x207u) )
    D3DDevice_SetRenderState_ShadowFunc((int *)3, 0x207u);
  D3DDevice_SetTexture(3u, 0);
  D3DDevice_SetPixelShader(0);
}