void __usercall D3DK::CommonSetSurfaceFormat(D3DK::CDevice *pDevice@<eax>, int a2@<ecx>, int *a3@<edi>)
{
  int v3; // esi
  float f; // ST08_4
  int v5; // eax
  double v6; // st7
  int *v7; // eax
  int *v8; // edi
  float v9; // eax
  D3DSurface *pRenderTarget; // [esp+10h] [ebp-Ch]
  float minScale; // [esp+18h] [ebp-4h]

  v3 = a2;
  pRenderTarget = *(D3DSurface **)(a2 + 1036);
  minScale = 1.0;
  *(float *)(a2 + 1284) = 1.0;
  *(float *)(a2 + 1288) = 1.0;
  if ( (float)1.0 != *(float *)(a2 + 1292) )
  {
    *(float *)(a2 + 1292) = minScale;
    f = minScale + minScale + 0.5;
    v5 = D3DK::FloatToLong(f);
    v6 = *(float *)(4 * v5 - 2146985868);
    *(float *)(v3 + 1296) = *(float *)(4 * v5 - 2146985868);
    if ( minScale == 1.0 && v6 != 0.0 )
      D3DK::DXGRIP(a3, "Assertion failure: %s", "pDevice->m_SuperSampleLODBias == 0.0f");
    if ( minScale == 2.0 && *(_DWORD *)(v3 + 1296) != 1065353216 )
      D3DK::DXGRIP(a3, "Assertion failure: %s", "pDevice->m_SuperSampleLODBias == 1.0f");
    if ( minScale == 4.0 && *(_DWORD *)(v3 + 1296) != 0x40000000 )
      D3DK::DXGRIP(a3, "Assertion failure: %s", "pDevice->m_SuperSampleLODBias == 2.0f");
    *(_DWORD *)(v3 + 8) |= 1u;
    D3DDevice_SetRenderStateNotInline(D3DRS_LINEWIDTH, 0);
  }
  v7 = (int *)XMETAL_StartPush(a3, (_XMETAL_PushBuffer *)v3);
  v8 = v7;
  v9 = COERCE_FLOAT(
         D3DK::PixelJar::GetSurfaceFormat(
           v7,
           (D3DPixelContainer *)&pRenderTarget->Common,
           *(D3DPixelContainer **)(v3 + 1040)));
  XMETAL_Push1f(v8, (unsigned int *)v8, 0x208u, v9);
  XMETAL_EndPush(v8 + 2, (_XMETAL_PushBuffer *)v3, (unsigned int *)v8 + 2);
}