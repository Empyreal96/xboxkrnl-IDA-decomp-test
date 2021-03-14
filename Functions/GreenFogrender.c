// write access to const memory has been detected, the output may be wrong!
void __userpurge GreenFog::render(GreenFog *this@<ecx>, int *a2@<edi>, bool b_cmp_to_one)
{
  GreenFog *v3; // esi
  D3DTexture *v4; // eax
  D3DBaseTexture *s; // ST0C_4
  int *v6; // edi
  int *v7; // edi
  double v8; // st7
  double v9; // st7
  double v10; // st7
  _D3DMATRIX *v11; // eax
  float v12; // ST0C_4
  float *v13; // eax
  double v14; // st6
  double v15; // st6
  float v16; // ecx
  double v17; // st6
  signed int v18; // esi
  double v19; // st6
  double v20; // st7
  unsigned __int64 v21; // rax
  signed int v22; // ecx
  int v23; // ecx
  signed int v24; // eax
  int v25; // esi
  double v26; // st7
  float y; // ST04_4
  float x; // ST00_4
  _D3DMATRIX iden; // [esp+1Ch] [ebp-10Ch]
  _D3DMATRIX scaled; // [esp+5Ch] [ebp-CCh]
  D3DVECTOR4 val[6]; // [esp+9Ch] [ebp-8Ch]
  D3DVECTOR4 origin_scr; // [esp+FCh] [ebp-2Ch]
  D3DVECTOR4 origin; // [esp+10Ch] [ebp-1Ch]
  float v34; // [esp+11Ch] [ebp-Ch]
  float v35; // [esp+120h] [ebp-8h]
  float v36; // [esp+124h] [ebp-4h]
  signed int mul; // [esp+130h] [ebp+8h]
  float mula; // [esp+130h] [ebp+8h]
  float mulb; // [esp+130h] [ebp+8h]

  v3 = this;
  D3DDevice_SetVertexShader(a2, this->dwFogVShader);
  D3DDevice_SetPixelShader(v3->dwFogPShader);
  v4 = v3->pIntensityTextureR;
  s = (D3DBaseTexture *)&v3->pIntensityTextureU->Common;
  v3->pIntensityTextureR = (D3DTexture *)s;
  v3->pIntensityTextureU = v4;
  D3DDevice_SetTexture(0, s);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_MINFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 14, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_MAGFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 13, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_MIPFILTER, 0) )
    D3DDevice_SetTextureState_Deferred(0, 0, 15, 0);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 0, D3DTSS_ADDRESSU, 3u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 10, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)3, 0, D3DTSS_ADDRESSV, 3u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 11, 3u);
  v6 = (int *)1;
  LODWORD(v36) = (char *)v3 + 8;
  LODWORD(v35) = 3;
  do
  {
    D3DDevice_SetTexture((unsigned int)v6, *(D3DBaseTexture **)LODWORD(v36));
    if ( !D3DDevice_SetTextureState_ParameterCheck(v6, (unsigned int)v6, D3DTSS_MINFILTER, 2u) )
      D3DDevice_SetTextureState_Deferred(0, (_D3DTEXTURESTAGESTATETYPE)v6, 14, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck(v6, (unsigned int)v6, D3DTSS_MAGFILTER, 2u) )
      D3DDevice_SetTextureState_Deferred(0, (_D3DTEXTURESTAGESTATETYPE)v6, 13, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck(v6, (unsigned int)v6, D3DTSS_MIPFILTER, 0) )
      D3DDevice_SetTextureState_Deferred(0, (_D3DTEXTURESTAGESTATETYPE)v6, 15, 0);
    if ( !D3DDevice_SetTextureState_ParameterCheck(v6, (unsigned int)v6, D3DTSS_ADDRESSU, 1u) )
      D3DDevice_SetTextureState_Deferred(0, (_D3DTEXTURESTAGESTATETYPE)v6, 10, 1u);
    if ( !D3DDevice_SetTextureState_ParameterCheck(v6, (unsigned int)v6, D3DTSS_ADDRESSV, 1u) )
      D3DDevice_SetTextureState_Deferred(0, (_D3DTEXTURESTAGESTATETYPE)v6, 11, 1u);
    LODWORD(v36) += 4;
    v6 = (int *)((char *)v6 + 1);
    --LODWORD(v35);
  }
  while ( v35 != 0.0 );
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ALPHATESTENABLE, 1u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40300u, 1u, (int *)1);
    dword_800C24B8 = 1;
  }
  v7 = (int *)(b_cmp_to_one != 0 ? 514 : 519);
  if ( !D3DDevice_SetRenderState_ParameterCheck(v7, D3DRS_PS_MAX, (unsigned int)v7) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40354u, (unsigned int)v7, v7);
    dword_800C24AC = b_cmp_to_one != 0 ? 514 : 519;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ALPHAREF, 1u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40340u, 1u, (int *)1);
    dword_800C24BC = 1;
  }
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
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_DESTBLEND, 1u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40348u, 1u, (int *)1);
    dword_800C24C4 = 1;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ZWRITEENABLE, 0) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x4035Cu, 0, (int *)1);
    dword_800C24C8 = 0;
  }
  v8 = 0.0 * 0.69999999 - 0.1;
  if ( v8 < 0.0 )
    v8 = 0.0;
  val[0].x = 0.0 * v8;
  val[0].y = v8;
  val[0].z = 0.0 * v8;
  val[0].w = 1.0;
  v9 = (0.0 - 5.0) * 4.0;
  if ( v9 > 1.0 || v9 >= 0.0 )
  {
    if ( v9 > 1.0 )
      v9 = 1.0;
  }
  else
  {
    v9 = 0.0;
  }
  v10 = v9 * 0.75;
  val[1].x = 0.625 * v10;
  val[1].y = v10;
  val[1].z = v10 * 0.40000001;
  val[1].w = 0.0;
  D3DDevice_SetPixelShaderConstant((int *)2, 0, val, 2u);
  origin.x = 0.0;
  origin.y = 0.0;
  origin.z = 0.0;
  origin.w = 1.0;
  v11 = Camera::getWTP(&dword_8010BDA8);
  TransformPoint(&origin, v11, &origin_scr);
  v12 = 1.0 / origin_scr.w;
  Scale((_D3DVECTOR *)&origin_scr.x, v12);
  mul = 2;
  v13 = &val[0].z;
  v14 = 0.0 * 0.0 * 0.0049999999;
  v35 = origin_scr.y * v14 * 1.875;
  v36 = origin_scr.x * (0.0 * 0.0024999999) * 2.5;
  v34 = -v14;
  do
  {
    v15 = (double)mul;
    v16 = v34;
    --mul;
    v17 = (v15 * 0.33333334 - 0.2) * 0.60000002;
    *(v13 - 2) = v35 - 0.0 * v17;
    *(v13 - 1) = 0.0 * v17 - v36;
    *v13 = 0.0;
    v13 += 8;
    *(v13 - 7) = 0.0;
    *(v13 - 6) = v16;
    *(v13 - 5) = -(0.0 * 0.0024999999);
    *(v13 - 4) = 1.0;
    *(v13 - 3) = 1.0;
  }
  while ( mul > -1 );
  D3DDevice_SetVertexShaderConstant(0, val, 6u);
  D3DDevice_SetStreamSource((int *)2, 0, v3->pQuadVB, 0x1Cu);
  D3DDevice_DrawVertices(D3DPT_TRIANGLEFAN, 0, 4u);
  D3DDevice_SetPixelShader(0);
  D3DDevice_SetVertexShader((int *)2, 0);
  v18 = 0;
  do
    D3DDevice_SetTexture(v18++, 0);
  while ( v18 < 4 );
  v19 = (0.0 - 4.6999998) * 3.3333333;
  if ( v19 > 1.0 || v19 >= 0.0 )
  {
    if ( v19 > 1.0 )
      v19 = 1.0;
  }
  else
  {
    v19 = 0.0;
  }
  mula = v19;
  if ( 0.0 < 0.60000002 )
  {
    if ( 0.0 >= 0.12 )
      v20 = 1.0 - (0.0 - 0.12) * 1.6666666;
    else
      v20 = 0.0 * 8.333333;
    mula = v20;
  }
  v21 = (unsigned __int64)(mula * 255.0);
  v22 = 255;
  if ( (signed int)v21 <= 255 )
  {
    if ( (v21 & 0x80000000) == 0i64 )
    {
      if ( (signed int)v21 <= 255 )
        v22 = (unsigned __int64)(mula * 255.0);
    }
    else
    {
      v22 = 0;
    }
  }
  v23 = 2 * v22;
  v24 = 196;
  if ( v23 > 196 || (v24 = v23) != 0 )
  {
    v25 = (v24 << 24) | 0xA0FF60;
    if ( !D3DDevice_SetRenderState_ParameterCheck((int *)2, D3DRS_TEXTUREFACTOR, v25) )
      D3DDevice_SetRenderState_TextureFactor((int *)2, v25);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_COLORARG1, 3u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 2, 3u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_COLORARG2, 2u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 3, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, 0, 4u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 0, 4u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 1u, 0, 1u) )
      D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 0, 1u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_ALPHAARG1, 3u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 6, 3u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_ALPHAARG2, 2u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 7, 2u);
    if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_ALPHAOP, 4u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 4, 4u);
    Camera::getWTP(&dword_8010BDA8);
    mulb = 0.33000001 / mula;
    if ( 0.0 < 0.60000002 )
      mulb = 0.0 * 0.60000002 / (0.0 * 8.0);
    SetIdentity(&iden);
    v26 = 1.0 / mulb;
    y = v26;
    x = v26;
    SetScale(x, y, 0.0, &scaled);
    scaled._43 = 1.0;
    D3DDevice_SetTransform(D3DTS_WORLD, &scaled);
    D3DDevice_SetTransform(0, &iden);
    D3DDevice_SetTransform(D3DTS_PROJECTION, &iden);
    D3DDevice_SetTexture(0, 0);
    D3DDevice_SetVertexShader((int *)2, 0x202u);
    D3DDevice_DrawVertices(D3DPT_TRIANGLEFAN, 0, 4u);
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)2, D3DRS_ZWRITEENABLE, 1u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x4035Cu, 1u, (int *)2);
    dword_800C24C8 = 1;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)2, D3DRS_DESTBLEND, 0x303u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40348u, 0x303u, (int *)2);
    dword_800C24C4 = 771;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)2, D3DRS_PS_MAX, 0x203u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40354u, 0x203u, (int *)2);
    dword_800C24AC = 515;
  }
}