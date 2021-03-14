// write access to const memory has been detected, the output may be wrong!
void __usercall GreenFog::renderIntensityTexture(GreenFog *this@<ecx>, int *a2@<edi>)
{
  GreenFog *v2; // ebx
  _D3DMATRIX *v3; // eax
  float s; // ST14_4
  _D3DMATRIX iden; // [esp+14h] [ebp-9Ch]
  D3DVECTOR4 origin; // [esp+54h] [ebp-5Ch]
  D3DVECTOR4 val[4]; // [esp+64h] [ebp-4Ch]
  D3DSurface *pOldRT; // [esp+A4h] [ebp-Ch]
  D3DSurface *p_update_surf; // [esp+A8h] [ebp-8h]
  D3DSurface *pOldZ; // [esp+ACh] [ebp-4h]

  v2 = this;
  D3DDevice_GetRenderTarget(a2, &pOldRT);
  D3DDevice_GetDepthStencilSurface(a2, &pOldZ);
  D3DTexture_GetSurfaceLevel(v2->pIntensityTextureU, 0, &p_update_surf);
  D3DDevice_SetRenderTarget(p_update_surf, v2->pIntensityZ);
  D3DDevice_Clear(0, 0, 0xF3u, 0xFFFF0000, 1.0, 0);
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_ALPHATESTENABLE, 1u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40300u, 1u, 0);
    dword_800C24B8 = 1;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_ALPHAFUNC, 0x206u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x4033Cu, 0x206u, 0);
    dword_800C24B0 = 518;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_ALPHAREF, 1u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40340u, 1u, 0);
    dword_800C24BC = 1;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_ALPHABLENDENABLE, 1u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40304u, 1u, 0);
    dword_800C24B4 = 1;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_SRCBLEND, 1u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40344u, 1u, 0);
    dword_800C24C0 = 1;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_DESTBLEND, 0) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x40348u, 0, 0);
    dword_800C24C4 = 0;
  }
  D3DDevice_SetVertexShader(0, 0);
  D3DDevice_SetPixelShader(0);
  val[0].x = 1.0;
  val[0].y = 1.0;
  val[0].z = 1.0;
  val[0].w = 1.0;
  val[1].x = 0.0;
  val[1].y = 0.0;
  val[1].z = 0.0;
  val[1].w = 1.0;
  val[2].x = 0.0 * 0.0049999999;
  val[2].y = 0.0 * 0.0 * 0.0049999999;
  val[2].z = 0.0;
  val[2].w = 1.0;
  origin.x = 0.0;
  origin.y = 0.0;
  origin.z = 0.0;
  origin.w = 1.0;
  v3 = Camera::getWTP(&dword_8010BDA8);
  TransformPoint(&origin, v3, &val[3]);
  s = 1.0 / val[3].w;
  Scale((_D3DVECTOR *)&val[3].x, s);
  val[3].x = 0.5 - val[3].x * val[2].x;
  val[3].y = 0.5 - val[3].y * val[2].y;
  val[3].z = 0.5;
  val[3].w = 0.0;
  D3DDevice_SetVertexShaderConstant(16, val, 4u);
  SetIdentity(&iden);
  iden._43 = 1.0;
  iden._44 = 0.0;
  D3DDevice_SetVertexShaderConstant(0, &iden, 4u);
  D3DDevice_SetStreamSource(0, 0, v2->pIntensityQuadVB, 0xCu);
  D3DDevice_DrawVertices(D3DPT_TRIANGLEFAN, 0, 4u);
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_ZWRITEENABLE, 1u) )
  {
    D3DDevice_SetRenderState_Simple(0, 0x4035Cu, 1u, 0);
    dword_800C24C8 = 1;
  }
  if ( !D3DDevice_SetRenderState_ParameterCheck(0, D3DRS_ZENABLE, 1u) )
    D3DDevice_SetRenderState_ZEnable(0, 1u);
  val[0].x = 0.0125;
  val[0].y = 0.0125;
  val[0].z = 0.0125;
  val[0].w = 1.0;
  val[1].x = 40.0 - 0.0;
  val[1].y = 40.0 - 0.0;
  val[1].z = 40.0 - 0.0;
  val[1].w = 1.0;
  D3DDevice_SetVertexShaderConstant(16, val, 2u);
  SceneRenderer::renderZ(&dword_8010C028);
  D3DDevice_SetPixelShader(0);
  D3DDevice_SetVertexShader(0, 0);
  D3DDevice_Clear(0, 0, 3u, 0xFFFFFFFF, 1.0, 0);
  D3DDevice_SetRenderTarget(pOldRT, pOldZ);
  D3DResource_Release(0, (D3DResource *)&p_update_surf->Common);
  D3DResource_Release(0, (D3DResource *)&pOldRT->Common);
  D3DResource_Release(0, (D3DResource *)&pOldZ->Common);
}