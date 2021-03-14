// write access to const memory has been detected, the output may be wrong!
void __userpurge LogoRenderer::render(LogoRenderer *this@<ecx>, int *a2@<edi>, _D3DMATRIX *mat_otw, bool b_force_3d_render)
{
  LogoRenderer *v4; // esi
  int *v5; // edi
  double v6; // st7
  double v7; // st6
  double v8; // st7
  unsigned int v9; // ST08_4
  _D3DMATRIX *v10; // eax
  unsigned __int8 v12; // c0
  unsigned __int8 v13; // c2
  double v14; // st7
  _D3DMATRIX flip; // [esp+14h] [ebp-D8h]
  _D3DMATRIX anim_otw; // [esp+54h] [ebp-98h]
  _D3DMATRIX tmp; // [esp+94h] [ebp-58h]
  float v18; // [esp+D4h] [ebp-18h]
  float v19; // [esp+D8h] [ebp-14h]
  float v20; // [esp+DCh] [ebp-10h]
  float v21; // [esp+E0h] [ebp-Ch]
  float w2; // [esp+E4h] [ebp-8h]
  float f_alpha; // [esp+E8h] [ebp-4h]
  float dw_alpha; // [esp+F8h] [ebp+Ch]
  signed int dw_alphaa; // [esp+F8h] [ebp+Ch]

  v4 = this;
  D3DDevice_SetVertexShader(a2, 0x102u);
  D3DDevice_SetPixelShader(0);
  if ( b_force_3d_render || 0.0 < 6.0 )
  {
    D3DDevice_SetTransform(D3DTS_WORLD, mat_otw);
    D3DDevice_SetTransform(0, &pMatrix);
    D3DDevice_SetTransform(D3DTS_PROJECTION, &dword_8010BEE4);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, 0, 2u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 0, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_COLORARG1, 2u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 2, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)1, 1u, 0, 1u) )
      D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 0, 1u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)4, 0, D3DTSS_ADDRESSU, 4u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 10, 4u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)4, 0, D3DTSS_ADDRESSV, 4u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 11, 4u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)0xFF000000, 0, D3DTSS_BORDERCOLOR, 0xFF000000) )
      D3DDevice_SetTextureState_BorderColor(0, 0xFF000000);
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)0xFF000000, D3DRS_ALPHABLENDENABLE, 0) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x40304u, 0, (int *)0xFF000000);
      dword_800C24B4 = 0;
    }
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)0xFF000000, D3DRS_ALPHATESTENABLE, 0) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x40300u, 0, (int *)0xFF000000);
      dword_800C24B8 = 0;
    }
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)0x900, D3DRS_CULLMODE, 0x900u) )
      D3DDevice_SetRenderState_CullMode(0x900u);
    D3DDevice_SetStreamSource((int *)0x900, 0, v4->pLipVB, 0x14u);
    D3DDevice_SetTexture(0, (D3DBaseTexture *)&v4->pLipTex->Common);
    v5 = (int *)5;
    D3DDevice_DrawIndexedVertices(D3DPT_TRIANGLELIST, v4->nLipIndices, v4->pLipIndices);
    D3DDevice_SetStreamSource((int *)5, 0, v4->pSurfaceVB, 0x14u);
    D3DDevice_SetTexture(0, (D3DBaseTexture *)&v4->pSurfaceTex->Common);
    D3DDevice_DrawIndexedVertices(D3DPT_TRIANGLELIST, v4->nSurfaceIndices, v4->pSurfaceIndices);
    D3DDevice_SetStreamSource((int *)5, 0, v4->pSurfaceTopVB, 0x14u);
    D3DDevice_SetTexture(0, (D3DBaseTexture *)&v4->pSurfaceTopTex->Common);
    D3DDevice_DrawIndexedVertices(D3DPT_TRIANGLELIST, v4->nSurfaceTopIndices, v4->pSurfaceTopIndices);
    D3DDevice_SetStreamSource((int *)5, 0, v4->pInteriorVB, 0x14u);
    v6 = (0.0 - 4.6999998) * 1.5384616 - 1.0;
    f_alpha = v6;
    v7 = -v6;
    if ( -v6 > 1.0 || v7 >= 0.0 )
    {
      if ( v7 > 1.0 )
        v7 = 1.0;
    }
    else
    {
      v7 = 0.0;
    }
    dw_alpha = v7;
    if ( v6 > 1.0 || v6 >= 0.0 )
    {
      if ( v6 > 1.0 )
        v6 = 1.0;
    }
    else
    {
      v6 = 0.0;
    }
    v8 = 1.0 - dw_alpha - v6;
    if ( v8 > 1.0 || v8 >= 0.0 )
    {
      if ( v8 > 1.0 )
        v8 = 1.0;
    }
    else
    {
      v8 = 0.0;
    }
    v9 = v4->dwInteriorVShader;
    w2 = v8;
    D3DDevice_SetVertexShader((int *)5, v9);
    D3DDevice_SetPixelShader(v4->dwInteriorPShader);
    v10 = Camera::getWTP(&dword_8010BDA8);
    MulMats(mat_otw, v10, &anim_otw);
    SetTranspose(&anim_otw, &flip);
    D3DDevice_SetVertexShaderConstant(0, &flip, 4u);
    tmp._11 = 0.81568003;
    tmp._12 = 1.0;
    if ( v12 | v13 )
    {
      tmp._13 = 0.59210002;
      tmp._14 = 1.0;
      tmp._21 = 0.81568003;
      tmp._22 = 1.0;
      tmp._23 = 0.59210002;
      tmp._24 = 1.0;
      tmp._31 = 0.81568003;
      tmp._32 = 1.0;
      tmp._33 = 0.52939999;
      tmp._34 = 1.0;
      tmp._41 = 0.81568003;
      tmp._42 = 1.0;
      tmp._43 = 0.52939999;
      tmp._44 = 1.0;
      v14 = dw_alpha;
    }
    else
    {
      *(_QWORD *)&tmp.m[2][0] = 4566613992734967464i64;
      tmp._13 = 0.52939999;
      tmp._33 = 0.0038999999;
      tmp._14 = 1.0;
      *(_QWORD *)&tmp.m[3][0] = 4527638040675647855i64;
      tmp._21 = 0.81568003;
      tmp._43 = 0.090099998;
      tmp._22 = 1.0;
      tmp._23 = 0.52939999;
      tmp._24 = 1.0;
      tmp._34 = 1.0;
      tmp._44 = 1.0;
      v14 = w2;
    }
    v19 = v14;
    v18 = v14;
    v20 = v14;
    v21 = 1.0;
    D3DDevice_SetVertexShaderConstant(4, &tmp, 5u);
    D3DDevice_DrawIndexedVertices(D3DPT_TRIANGLELIST, v4->nInteriorIndices, v4->pInteriorIndices);
  }
  else
  {
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ALPHABLENDENABLE, 1u) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x40304u, 1u, (int *)1);
      dword_800C24B4 = 1;
    }
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_SRCBLEND, 1u) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x40344u, 1u, (int *)1);
      dword_800C24C0 = 1;
    }
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_DESTBLEND, 0) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x40348u, 0, (int *)1);
      dword_800C24C4 = 0;
    }
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ZWRITEENABLE, 0) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x4035Cu, 0, (int *)1);
      dword_800C24C8 = 0;
    }
    SetIdentity(&anim_otw);
    D3DDevice_SetTransform(D3DTS_WORLD, &anim_otw);
    D3DDevice_SetTransform(0, &anim_otw);
    D3DDevice_SetTransform(D3DTS_PROJECTION, &anim_otw);
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_TEXTUREFACTOR, 0xFFFFFFFF) )
      D3DDevice_SetRenderState_TextureFactor((int *)1, 0xFFFFFFFF);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, 0, 2u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 0, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_COLORARG1, 2u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 2, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_COLORARG2, 2u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 3, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_ALPHAOP, 2u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 4, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 0, D3DTSS_ALPHAARG1, 3u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 6, 3u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 0, D3DTSS_ALPHAARG2, 3u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 7, 3u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)1, 1u, 0, 1u) )
      D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 0, 1u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)1, 0, D3DTSS_TEXTURETRANSFORMFLAGS, 0) )
      D3DDevice_SetTextureState_Deferred(0, 0, 9, 0);
    D3DDevice_SetTexture(0, (D3DBaseTexture *)&v4->pSlashTexture->Common);
    D3DDevice_SetVertexShader((int *)1, 0x202u);
    D3DDevice_SetStreamSource((int *)1, 0, 0, 0x1Cu);
    D3DDevice_DrawVertices(D3DPT_TRIANGLEFAN, 0, 4u);
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ZWRITEENABLE, 1u) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x4035Cu, 1u, (int *)1);
      dword_800C24C8 = 1;
    }
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ALPHABLENDENABLE, 0) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x40304u, 0, (int *)1);
      dword_800C24B4 = 0;
    }
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ALPHATESTENABLE, 0) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x40300u, 0, (int *)1);
      dword_800C24B8 = 0;
    }
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)0x900, D3DRS_CULLMODE, 0x900u) )
      D3DDevice_SetRenderState_CullMode(0x900u);
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ZWRITEENABLE, 1u) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x4035Cu, 1u, (int *)1);
      dword_800C24C8 = 1;
    }
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)4, 0, D3DTSS_ADDRESSU, 4u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 10, 4u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)4, 0, D3DTSS_ADDRESSV, 4u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 11, 4u);
    v5 = (int *)-16777216;
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)0xFF000000, 0, D3DTSS_BORDERCOLOR, 0xFF000000) )
      D3DDevice_SetTextureState_BorderColor(0, 0xFF000000);
    D3DDevice_SetTransform(D3DTS_WORLD, mat_otw);
    D3DDevice_SetTransform(0, &pMatrix);
    D3DDevice_SetTransform(D3DTS_PROJECTION, &dword_8010BEE4);
  }
  if ( v4->bRenderText && !v4->bHasWordmark )
  {
    D3DDevice_SetVertexShader(v5, 0x102u);
    D3DDevice_SetPixelShader(0);
    if ( !D3DDevice_SetRenderState_ParameterCheck(v5, D3DRS_ZENABLE, 0) )
      D3DDevice_SetRenderState_ZEnable(v5, 0);
    f_alpha = v4->fTMAlpha;
    dw_alphaa = (signed int)f_alpha << 24;
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ALPHABLENDENABLE, 1u) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x40304u, 1u, (int *)1);
      dword_800C24B4 = 1;
    }
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)0x302, D3DRS_SRCBLEND, 0x302u) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x40344u, 0x302u, (int *)0x302);
      dword_800C24C0 = 770;
    }
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)0x303, D3DRS_DESTBLEND, 0x303u) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x40348u, 0x303u, (int *)0x303);
      dword_800C24C4 = 771;
    }
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)0x303, D3DRS_TEXTUREFACTOR, dw_alphaa) )
      D3DDevice_SetRenderState_TextureFactor((int *)0x303, dw_alphaa);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, 0, 2u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 0, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_COLORARG1, 2u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 2, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_COLORARG2, 3u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 3, 3u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_ALPHAOP, 4u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 4, 4u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_ALPHAARG1, 2u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 6, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_ALPHAARG2, 3u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 7, 3u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)1, 1u, 0, 1u) )
      D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 0, 1u);
    D3DDevice_SetTexture(0, (D3DBaseTexture *)&v4->pTMTex->Common);
    D3DDevice_SetStreamSource((int *)1, 0, v4->pSlashTM_VB, 0x14u);
    D3DDevice_DrawIndexedVertices(D3DPT_TRIANGLELIST, v4->nSlashTM_Indices, v4->pSlashTM_Indices);
    D3DDevice_SetStreamSource((int *)1, 0, v4->pTextTM_VB, 0x14u);
    D3DDevice_DrawIndexedVertices(D3DPT_TRIANGLELIST, v4->nTextTM_Indices, v4->pTextTM_Indices);
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ALPHABLENDENABLE, 0) )
    {
      D3DDevice_SetRenderState_Simple(0, 0x40304u, 0, (int *)1);
      dword_800C24B4 = 0;
    }
    v5 = (int *)-10302957;
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)0xFF62CA13, D3DRS_TEXTUREFACTOR, 0xFF62CA13) )
      D3DDevice_SetRenderState_TextureFactor((int *)0xFF62CA13, 0xFF62CA13);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)0xFF62CA13, 0, D3DTSS_COLORARG1, 3u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 2, 3u);
    SetXRotation(1.5707964, &flip);
    MulMats(&flip, &v4->matText_Anim, (_D3DMATRIX *)((char *)&tmp + 16));
    MulMats((_D3DMATRIX *)((char *)&tmp + 16), mat_otw, &anim_otw);
    D3DDevice_SetVertexShader((int *)0xFF62CA13, 2u);
    D3DDevice_SetTransform(D3DTS_WORLD, &anim_otw);
    D3DDevice_SetStreamSource((int *)0xFF62CA13, 0, v4->pText_VB, 0xCu);
    D3DDevice_DrawIndexedVertices(D3DPT_TRIANGLELIST, v4->nText_Indices, v4->pText_Indices);
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)0xFF62CA13, D3DRS_ZENABLE, 1u) )
      D3DDevice_SetRenderState_ZEnable((int *)0xFF62CA13, 1u);
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(v5, D3DRS_CULLMODE, 0x901u) )
    D3DDevice_SetRenderState_CullMode(0x901u);
}