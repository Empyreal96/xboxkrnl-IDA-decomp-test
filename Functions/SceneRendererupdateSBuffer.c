// write access to const memory has been detected, the output may be wrong!
void __thiscall SceneRenderer::updateSBuffer(SceneRenderer *this, bool b_hi_z)
{
  _D3DVECTOR ST0C_12_3; // ST0C_12
  double v3; // st7
  double v4; // st6
  int v5; // esi
  _D3DMATRIX *v6; // eax
  int *v7; // edi
  int *v8; // edi
  int *v9; // edi
  PrimitiveTypes v10; // eax
  PrimitiveSet *v11; // ecx
  _D3DMATRIX mat; // [esp+1Ch] [ebp-118h]
  _D3DMATRIX shadow_proj_mat; // [esp+5Ch] [ebp-D8h]
  _D3DMATRIX shadow_vp_mat; // [esp+9Ch] [ebp-98h]
  float fi; // [esp+DCh] [ebp-58h]
  _D3DVIEWPORT8 viewport; // [esp+E0h] [ebp-54h]
  _D3DVECTOR up; // [esp+F8h] [ebp-3Ch]
  _D3DVECTOR look_pt; // [esp+104h] [ebp-30h]
  PrimitiveTypes sb_types[4]; // [esp+110h] [ebp-24h]
  _D3DVECTOR eye_pos; // [esp+120h] [ebp-14h]
  D3DSurface *psurf; // [esp+12Ch] [ebp-8h]
  int i; // [esp+130h] [ebp-4h]

  eye_pos.x = 0.0;
  eye_pos.y = 0.0;
  i = (int)this;
  eye_pos.z = 40.0;
  if ( !b_hi_z )
    eye_pos.z = -30.0;
  ST0C_12_3.x = eye_pos.x;
  *(_QWORD *)&ST0C_12_3.y = *(_QWORD *)&eye_pos.y;
  VBlob::getLightForPosition(&stru_8010C21C, &eye_pos, &fi, ST0C_12_3);
  v3 = -1.0;
  if ( b_hi_z )
    v4 = 1.0;
  else
    v4 = -1.0;
  look_pt.x = eye_pos.x;
  look_pt.z = eye_pos.z + v4;
  look_pt.y = eye_pos.y;
  if ( !b_hi_z )
    v3 = 1.0;
  up.x = 0.0;
  up.y = v3;
  up.z = 0.0;
  Camera::lookAt(&dword_8010BDA8, &eye_pos, &look_pt, &up);
  Camera::setProjection(&dword_8010BDA8, 2.0943952, 1.0, 1.0, 500.0);
  qmemcpy(&shadow_proj_mat, &dword_8010BEE4, sizeof(shadow_proj_mat));
  SetIdentity(&shadow_vp_mat);
  shadow_vp_mat._41 = 256.5;
  shadow_vp_mat._42 = 256.5;
  shadow_vp_mat._11 = 256.0;
  shadow_vp_mat._22 = -256.0;
  shadow_vp_mat._33 = 65535.0;
  MulMats(&pMatrix, &shadow_proj_mat, &mat);
  v5 = i;
  if ( b_hi_z )
    v6 = (_D3DMATRIX *)(i + 356);
  else
    v6 = (_D3DMATRIX *)(i + 420);
  MulMats(&mat, &shadow_vp_mat, v6);
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)&shadow_vp_mat, D3DRS_ALPHABLENDENABLE, 0) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40304u, 0, (int *)&shadow_vp_mat);
    dword_800C24B4 = 0;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)&shadow_vp_mat, D3DRS_ALPHATESTENABLE, 0) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40300u, 0, (int *)&shadow_vp_mat);
    dword_800C24B8 = 0;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ZENABLE, 1u) )
    D3DDevice_SetRenderState_ZEnable((int *)1, 1u);
  if ( b_hi_z )
    D3DTexture_GetSurfaceLevel(*(D3DTexture **)(v5 + 348), 0, &psurf);
  else
    D3DTexture_GetSurfaceLevel(*(D3DTexture **)(v5 + 352), 0, &psurf);
  D3DDevice_SetRenderTarget(*(D3DSurface **)(v5 + 48), psurf);
  viewport.MinZ = 0.0;
  viewport.Width = 512;
  viewport.Height = 512;
  viewport.MaxZ = 1.0;
  viewport.X = 0;
  viewport.Y = 0;
  D3DDevice_SetViewport(&viewport);
  D3DDevice_Clear(0, 0, 1u, 0, 1.0, 0);
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_COLORWRITEENABLE, 0) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40358u, 0, (int *)1);
    dword_800C24D4 = 0;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_SOLIDOFFSETENABLE, 1u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40338u, 1u, (int *)1);
    dword_800C250C = 1;
  }
  i = *(_DWORD *)(v5 + 84);
  v7 = (int *)i;
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)i, D3DRS_POLYGONOFFSETZOFFSET, i) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40388u, (unsigned int)v7, v7);
    dword_800C2500 = (int)v7;
  }
  i = *(_DWORD *)(v5 + 88);
  v8 = (int *)i;
  if ( !D3DDevice_SetRenderState_ParameterCheck((int *)i, D3DRS_POLYGONOFFSETZSLOPESCALE, i) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40384u, (unsigned int)v8, v8);
    dword_800C24FC = (int)v8;
  }
  D3DDevice_SetVertexShader((int *)2, 2u);
  D3DDevice_SetPixelShader(0);
  D3DDevice_SetTransform(0, &pMatrix);
  D3DDevice_SetTransform(D3DTS_PROJECTION, &shadow_proj_mat);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, 0, 2u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 0, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 0, D3DTSS_COLORARG1, 3u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 2, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck((int *)2, 1u, 0, 1u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 0, 1u);
  i = 0;
  do
    D3DDevice_SetTexture(i++, 0);
  while ( i < 4 );
  sb_types[2] = 2;
  sb_types[0] = 3;
  sb_types[1] = 4;
  sb_types[3] = 1;
  v9 = 0;
  do
  {
    v10 = sb_types[(_DWORD)v9];
    if ( *(_BYTE *)(v5 + 92) )
      v11 = *(PrimitiveSet **)(v5 + 4 * v10 + 24);
    else
      v11 = *(PrimitiveSet **)(v5 + 4 * v10);
    PrimitiveSet::renderShadowMap(v11, b_hi_z);
    v9 = (int *)((char *)v9 + 1);
  }
  while ( (signed int)v9 < 4 );
  D3DDevice_SetRenderTarget(*(D3DSurface **)(v5 + 52), *(D3DSurface **)(v5 + 56));
  if ( !D3DDevice_SetRenderState_ParameterCheck(v9, D3DRS_COLORWRITEENABLE, 0x1010101u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40358u, 0x1010101u, v9);
    dword_800C24D4 = 16843009;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(v9, D3DRS_SOLIDOFFSETENABLE, 0) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40338u, 0, v9);
    dword_800C250C = 0;
  }
  D3DResource_Release(v9, (D3DResource *)&psurf->Common);
}