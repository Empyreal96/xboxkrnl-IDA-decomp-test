// write access to const memory has been detected, the output may be wrong!
void __thiscall VBlob::render(VBlob *this)
{
  VBlob *v1; // ebx
  float x; // ST10_4
  double v3; // st7
  int v4; // esi
  D3DVertexBuffer *v5; // ST00_4
  VBlob::render::__l2::_decalvert *v6; // eax
  double v7; // st7
  double v8; // st6
  double v9; // st7
  double v10; // st6
  double v11; // st7
  double v12; // st7
  double v13; // st6
  float v14; // ST10_4
  D3DVertexBuffer *v15; // eax
  D3DVertexBuffer *v16; // ST0C_4
  float v17; // ST10_4
  bool v18; // zf
  bool v19; // sf
  float *v20; // esi
  double v21; // st7
  float v22; // ST10_4
  double v23; // st7
  double v24; // st7
  _D3DMATRIX matT; // [esp+10h] [ebp-170h]
  _D3DMATRIX id_mat; // [esp+50h] [ebp-130h]
  _D3DMATRIX matFinal; // [esp+90h] [ebp-F0h]
  _D3DMATRIX mat; // [esp+D0h] [ebp-B0h]
  D3DVECTOR4 cur_pos; // [esp+110h] [ebp-70h]
  unsigned int dw_alpha; // [esp+120h] [ebp-60h]
  D3DVECTOR4 val[5]; // [esp+124h] [ebp-5Ch]
  float cur_rad; // [esp+174h] [ebp-Ch]
  int i; // [esp+178h] [ebp-8h]
  VBlob::render::__l2::_decalvert *phalo_verts; // [esp+17Ch] [ebp-4h]

  v1 = this;
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_LIGHTING, 0) )
    D3DDevice_SetRenderState_Deferred(0, 0x5Cu, 0);
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_ZENABLE, 1u) )
    D3DDevice_SetRenderState_ZEnable(0, 1u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 0, D3DTSS_MINFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 14, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 0, D3DTSS_MAGFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 13, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 0, D3DTSS_MIPFILTER, 0) )
    D3DDevice_SetTextureState_Deferred(0, 0, 15, 0);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 0, D3DTSS_ADDRESSU, 3u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 10, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 0, D3DTSS_ADDRESSV, 3u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 11, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 0, D3DTSS_ADDRESSW, 3u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 12, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 1u, D3DTSS_MINFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 14, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 1u, D3DTSS_MAGFILTER, 2u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 13, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 1u, D3DTSS_MIPFILTER, 0) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 15, 0);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 1u, D3DTSS_ADDRESSU, 3u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 10, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 1u, D3DTSS_ADDRESSV, 3u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 11, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 1u, D3DTSS_ADDRESSW, 3u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 12, 3u);
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_ALPHABLENDENABLE, 1u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40304u, 1u, 0);
    dword_800C24B4 = 1;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_SRCBLEND, 0x302u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40344u, 0x302u, 0);
    dword_800C24C0 = 770;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_DESTBLEND, 0x303u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40348u, 0x303u, 0);
    dword_800C24C4 = 771;
  }
  D3DDevice_SetVertexShader(0, 0x102u);
  D3DDevice_SetPixelShader(0);
  SetIdentity(&id_mat);
  D3DDevice_SetTransform(D3DTS_WORLD, &id_mat);
  D3DDevice_SetTransform(0, &pMatrix);
  D3DDevice_SetTransform(D3DTS_PROJECTION, &dword_8010BEE4);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 0, 0, 4u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 0, 4u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 0, D3DTSS_COLORARG1, 2u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 2, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 0, D3DTSS_COLORARG2, 3u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 3, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 0, D3DTSS_ALPHAOP, 2u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 4, 2u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 0, D3DTSS_ALPHAARG1, 3u) )
    D3DDevice_SetTextureState_Deferred(0, 0, 6, 3u);
  if ( !D3DDevice_SetTextureState_ParameterCheck(0, 1u, 0, 1u) )
    D3DDevice_SetTextureState_Deferred(0, D3DTSS_COLORARG0, 0, 1u);
  x = 0.0 - 0.0;
  cur_rad = (fast_sqrt(x) * 1.3 + 1.0) * v1->m_fRadius;
  v3 = 0.0;
  if ( 0.0 >= 1.0 )
    v3 = 1.0;
  *(float *)&i = v3 * 255.0;
  dw_alpha = (signed int)*(float *)&i << 24;
  v4 = ((signed int)*(float *)&i << 24) | 0xA0FF40;
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_TEXTUREFACTOR, v4) )
    D3DDevice_SetRenderState_TextureFactor(0, v4);
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_SRCBLEND, 0x302u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40344u, 0x302u, 0);
    dword_800C24C0 = 770;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_DESTBLEND, 1u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40348u, 1u, 0);
    dword_800C24C4 = 1;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_ZWRITEENABLE, 0) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x4035Cu, 0, 0);
    dword_800C24C8 = 0;
  }
  D3DDevice_SetTexture(0, 0);
  v5 = v1->pHaloQuadVB;
  phalo_verts = 0;
  D3DVertexBuffer_Lock(0, v5, 0, 0x50u, (char **)&phalo_verts, 0);
  *(float *)&i = cur_rad * 5.1999998;
  Sub(&dword_8010BE74, &dword_8010BE64, &phalo_verts->p);
  Scale(&phalo_verts->p, *(float *)&i);
  phalo_verts->u = 0.0;
  phalo_verts->v = 1.0;
  Add(&dword_8010BE74, &dword_8010BE64, &phalo_verts[1].p);
  Scale(&phalo_verts[1].p, *(float *)&i);
  phalo_verts[1].u = 1.0;
  phalo_verts[1].v = 1.0;
  Sub(&dword_8010BE64, &dword_8010BE74, &phalo_verts[2].p);
  Scale(&phalo_verts[2].p, *(float *)&i);
  phalo_verts[2].u = 1.0;
  phalo_verts[2].v = 0.0;
  v6 = phalo_verts + 3;
  v6->p.x = -0.0 - 0.0;
  v6->p.y = -0.0 - 0.0;
  v6->p.z = -0.0 - 0.0;
  Scale(&phalo_verts[3].p, *(float *)&i);
  phalo_verts[3].u = 0.0;
  phalo_verts[3].v = 0.0;
  D3DDevice_SetStreamSource(0, 0, v1->pHaloQuadVB, 0x14u);
  D3DDevice_DrawVertices(D3DPT_TRIANGLEFAN, 0, 4u);
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_DESTBLEND, 0x303u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40348u, 0x303u, 0);
    dword_800C24C4 = 771;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_ZWRITEENABLE, 1u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x4035Cu, 1u, 0);
    dword_800C24C8 = 1;
  }
  D3DDevice_SetTexture(0, 0);
  D3DDevice_SetTexture(1u, 0);
  D3DDevice_SetVertexShader(0, v1->m_dwVShaderBlob);
  D3DDevice_SetPixelShader(v1->m_dwPShaderBlob);
  MulMats(&pMatrix, &dword_8010BEE4, &mat);
  SetTranspose(&mat, &matFinal);
  D3DDevice_SetVertexShaderConstant(4, &matFinal, 4u);
  val[0].x = 0.0;
  val[0].z = 2.0;
  val[0].w = 0.5;
  val[0].y = 1.0;
  v7 = cur_rad * v1->m_Scale.x;
  LODWORD(val[1].x) = dword_8010BE00[0];
  LODWORD(val[1].y) = dword_8010BE00[1];
  LODWORD(val[1].z) = dword_8010BE00[2];
  val[2].x = v7;
  v8 = cur_rad * v1->m_Scale.y;
  cur_pos.z = v1->m_Pos.z;
  val[4].z = cur_pos.z;
  val[2].y = v8;
  val[2].z = cur_rad * v1->m_Scale.z;
  val[2].w = 1.0;
  val[3].x = 1.0 / v7;
  val[3].y = 1.0 / v8;
  val[3].z = 1.0 / val[2].z;
  v9 = v1->m_Pos.x;
  cur_pos.x = v1->m_Pos.x;
  v10 = v1->m_Pos.y;
  cur_pos.y = v1->m_Pos.y;
  val[4].x = v9;
  val[4].y = v10;
  val[4].w = 0.0;
  D3DDevice_SetVertexShaderConstant(8, val, 5u);
  SetIdentity(&mat);
  v11 = cur_rad * v1->m_Scale.x;
  *(_QWORD *)&mat.m[3][0] = *(_QWORD *)&cur_pos.x;
  mat._11 = v11;
  v12 = cur_rad * v1->m_Scale.y;
  mat._43 = cur_pos.z;
  mat._22 = v12;
  mat._33 = cur_rad * v1->m_Scale.z;
  SetTranspose(&mat, &matT);
  D3DDevice_SetVertexShaderConstant(0, &matT, 4u);
  val[0].x = v1->m_BlobColor.x;
  val[0].y = v1->m_BlobColor.y;
  val[0].z = v1->m_BlobColor.z;
  val[0].w = v1->m_BlobColor.w;
  v13 = 0.0 * 4.0;
  if ( 0.0 * 4.0 > 1.0 )
    v13 = 1.0;
  v14 = v13 * (((0.0 - 0.0) * 0.80000001 + 0.0 * 1.2) * 4.0 + 0.30000001);
  Scale((_D3DVECTOR *)val, v14);
  val[1].x = v1->m_BlobColor.x;
  val[1].y = v1->m_BlobColor.y;
  val[1].z = v1->m_BlobColor.z;
  val[1].w = v1->m_BlobColor.w;
  Scale((_D3DVECTOR *)&val[1].x, 0.0);
  D3DDevice_SetPixelShaderConstant((int *)&val[2], 0, val, 2u);
  D3DDevice_SetIndices((int *)&val[2], v1->m_pBlobIB, 0);
  D3DDevice_SetStreamSource((int *)&val[2], 0, v1->m_pBlobVBConst, 0xCu);
  v15 = v1->m_pBlobVBChangingR;
  v16 = v1->m_pBlobVBChangingU;
  v1->m_pBlobVBChangingR = v16;
  v1->m_pBlobVBChangingU = v15;
  D3DDevice_SetStreamSource((int *)&val[2], 1u, v16, 0x10u);
  D3DDevice_DrawIndexedVertices(D3DPT_TRIANGLESTRIP, v1->m_dwNumIndices, D3D__IndexData);
  D3DDevice_SetVertexShader((int *)&val[2], v1->m_dwVShaderBloblet);
  D3DDevice_SetPixelShader(v1->m_dwPShaderBloblet);
  D3DDevice_SetVertexShaderConstant(4, &matFinal, 4u);
  val[0].x = 0.0;
  val[0].z = 2.0;
  val[0].w = 0.5;
  val[0].y = 1.0;
  LODWORD(val[1].x) = dword_8010BE00[0];
  LODWORD(val[1].y) = dword_8010BE00[1];
  LODWORD(val[1].z) = dword_8010BE00[2];
  D3DDevice_SetVertexShaderConstant(8, val, 2u);
  val[0].x = v1->m_BlobColor.x;
  val[0].y = v1->m_BlobColor.y;
  val[0].z = v1->m_BlobColor.z;
  val[0].w = v1->m_BlobColor.w;
  v17 = 0.0 * 0.30000001;
  Scale((_D3DVECTOR *)val, v17);
  val[1].x = v1->m_BlobColor.x;
  val[1].y = v1->m_BlobColor.y;
  val[1].z = v1->m_BlobColor.z;
  val[1].w = v1->m_BlobColor.w;
  Scale((_D3DVECTOR *)&val[1].x, 0.2);
  val[2].x = 2.0;
  val[2].y = 2.0;
  val[2].z = 2.0;
  val[2].w = 2.0;
  D3DDevice_SetPixelShaderConstant(0, 0, val, 3u);
  D3DDevice_SetIndices(0, v1->m_pBlobletIB, 0);
  D3DDevice_SetStreamSource(0, 0, v1->m_pBlobletVB, 0xCu);
  v18 = v1->m_NumBloblets == 0;
  v19 = v1->m_NumBloblets < 0;
  *(float *)&i = 0.0;
  if ( !v19 && !v18 )
  {
    v20 = &v1->m_Bloblets[0].vPosition.y;
    do
    {
      val[0].x = *(v20 - 1);
      val[0].w = 0.0;
      val[0].y = *v20;
      val[1].w = 1.0;
      v21 = v20[10];
      val[0].z = v20[1];
      val[1].x = v20[3];
      val[1].y = v20[4];
      v22 = v21;
      val[1].z = v20[5];
      v23 = *(v20 - 2) / fast_sqrt(v22);
      val[2].x = v23;
      val[2].y = v23;
      val[2].z = v23;
      val[2].w = 1.0;
      v24 = v20[10] * *(v20 - 2) - v23;
      val[3].x = v24 * v20[3];
      val[3].y = v24 * v20[4];
      val[3].z = v24 * v20[5];
      val[3].w = 1.0;
      D3DDevice_SetVertexShaderConstant(10, val, 4u);
      D3DDevice_DrawIndexedVertices(D3DPT_TRIANGLESTRIP, v1->m_dwNumBlobletIndices, D3D__IndexData);
      ++i;
      v20 += 14;
    }
    while ( i < v1->m_NumBloblets );
  }
  D3DDevice_SetPixelShader(0);
  D3DDevice_SetVertexShader(0, 0);
  D3DDevice_SetTexture(0, 0);
  D3DDevice_SetTexture(1u, 0);
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_ALPHABLENDENABLE, 0) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40304u, 0, 0);
    dword_800C24B4 = 0;
  }
}