unsigned int __stdcall D3DK::GetTextureFilter(unsigned int Stage)
{
  unsigned int *v1; // eax
  unsigned int v3; // esi
  bool v4; // cf
  bool v5; // zf
  unsigned int v6; // edi
  float f; // ST04_4
  int v8; // eax
  signed __int16 v9; // bx
  unsigned int v10; // eax
  unsigned int *pTextureStates; // [esp+10h] [ebp-8h]
  unsigned int *pTextureStatesa; // [esp+10h] [ebp-8h]
  unsigned int colorSign; // [esp+14h] [ebp-4h]
  unsigned int convolutionKernel; // [esp+20h] [ebp+8h]

  v1 = D3D__TextureState[Stage];
  pTextureStates = D3D__TextureState[Stage];
  if ( !D3D__TextureState[Stage] )
    return 0;
  v3 = D3D__TextureState[Stage][14];
  v4 = v3 < 3;
  v5 = v3 == 3;
  v6 = D3D__TextureState[Stage][13];
  convolutionKernel = 0x2000;
  if ( v3 >= 3 )
  {
LABEL_6:
    if ( (v4 || v5) && v6 <= 3 )
    {
      if ( !v1[18] )
      {
        v3 = 1;
        v6 = 1;
        goto LABEL_16;
      }
      v6 = 2;
    }
    else
    {
      if ( v3 == 5 || v6 == 5 )
        convolutionKernel = 0x4000;
      convolutionKernel |= 0x70000u;
      v6 = 4;
    }
    v3 = 2;
    goto LABEL_16;
  }
  if ( v6 >= 3 )
  {
    v4 = v3 < 3;
    v5 = v3 == 3;
    goto LABEL_6;
  }
LABEL_16:
  f = (*((float *)v1 + 16) + D3DK::g_pDevice->m_SuperSampleLODBias) * 256.0 + 0.5;
  v8 = D3DK::FloatToLong(f);
  v9 = v8;
  if ( v8 >= -4096 )
  {
    if ( v8 > 4095 )
      v9 = 4095;
  }
  else
  {
    v9 = -4096;
  }
  if ( *pTextureStates < 0x19 )
    colorSign = pTextureStates[20];
  else
    colorSign = -1073741824;
  v10 = pTextureStates[15];
  pTextureStatesa = (unsigned int *)pTextureStates[15];
  if ( v3 > 2 || v10 > 2 )
    D3DK::DXGRIP((int *)v6, "Assertion failure: %s", "(MinFilter <= D3DTEXF_LINEAR) && (MipFilter <= D3DTEXF_LINEAR)");
  if ( !v3 )
    D3DK::DXGRIP((int *)v6, "Assertion failure: %s", "MinFilter > D3DTEXF_NONE");
  return convolutionKernel | colorSign | (v6 << 24) | v9 & 0x1FFF | *(_DWORD *)(4
                                                                              * ((_DWORD)pTextureStatesa + 2 * v3 + v3)
                                                                              - 2146940752);
}