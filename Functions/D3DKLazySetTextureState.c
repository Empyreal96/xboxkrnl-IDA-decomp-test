// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DK::LazySetTextureState(D3DK::CDevice *pDevice)
{
  int *v1; // ebx
  int v2; // esi
  unsigned int v3; // edi
  bool v4; // cf
  bool v5; // zf
  unsigned int v6; // eax
  unsigned int v7; // eax
  float f; // ST0C_4
  int v9; // eax
  signed __int16 v10; // si
  int *v11; // edi
  int v12; // ST20_4
  unsigned int *v13; // edi
  int address; // [esp+10h] [ebp-24h]
  int v15; // [esp+14h] [ebp-20h]
  signed int v16; // [esp+18h] [ebp-1Ch]
  unsigned int maxAnisotropy; // [esp+1Ch] [ebp-18h]
  unsigned int maxAnisotropya; // [esp+1Ch] [ebp-18h]
  signed int method; // [esp+20h] [ebp-14h]
  int control0; // [esp+24h] [ebp-10h]
  _DWORD *v21; // [esp+28h] [ebp-Ch]
  unsigned int convolutionKernel; // [esp+2Ch] [ebp-8h]
  unsigned int magFilter; // [esp+30h] [ebp-4h]

  ++D3DK::g_PerfCounters.m_PerformanceCounters[25].Count;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == 25
    && D3DK::g_PerfCounters.m_PerformanceCounters[25].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
  {
    __debugbreak();
  }
  pDevice->m_DirtyFlags &= 0xFFFFFFEF;
  method = 6932;
  v21 = pDevice->m_TextureControl0Enabled;
  v1 = dword_800C21F4;
  v16 = 4;
  do
  {
    address = *(v1 - 1) | ((*v1 | (v1[1] << 8)) << 8) | *(_DWORD *)(4 * (v1[17] & 0xFFFF) - 2146687704);
    v2 = v1[8] | v1[10] | (v1[6] << 26) | 0x3FFC0;
    control0 = v1[8] | v1[10] | (v1[6] << 26) | 0x3FFC0;
    if ( v21[436] )
    {
      v2 = v1[8] | v1[10] | (v1[6] << 26) | 0x4003FFC0;
      control0 = v1[8] | v1[10] | (v1[6] << 26) | 0x4003FFC0;
    }
    v3 = v1[3];
    v4 = v3 < 3;
    v5 = v3 == 3;
    v6 = v1[2];
    magFilter = v1[2];
    convolutionKernel = 0x2000;
    if ( v3 < 3 )
    {
      if ( v6 < 3 )
        goto LABEL_21;
      v4 = v3 < 3;
      v5 = v3 == 3;
    }
    if ( (v4 || v5) && v6 <= 3 )
    {
      v7 = v1[7];
      maxAnisotropy = v1[7];
      if ( v7 )
      {
        if ( v7 > 4 )
        {
          D3DK::DXGRIP((int *)v3, "Assertion failure: %s", "maxAnisotropy <= 4");
          v7 = maxAnisotropy;
        }
        v3 = 2;
        v2 |= 16 * (v7 - 1);
        magFilter = 2;
        control0 = v2;
      }
      else
      {
        v3 = 1;
        magFilter = 1;
        control0 = v2;
      }
    }
    else
    {
      if ( v3 == 5 || v6 == 5 )
        convolutionKernel = 0x4000;
      convolutionKernel |= 0x70000u;
      v3 = 2;
      magFilter = 4;
    }
LABEL_21:
    *v21 = v2 | 0x40000000;
    f = (*((float *)v1 + 5) + pDevice->m_SuperSampleLODBias) * 256.0 + 0.5;
    v9 = D3DK::FloatToLong(f);
    v10 = v9;
    if ( v9 >= -4096 )
    {
      if ( v9 > 4095 )
        v10 = 4095;
    }
    else
    {
      v10 = -4096;
    }
    if ( (unsigned int)*(v1 - 11) < 0x19 )
      maxAnisotropya = v1[9];
    else
      maxAnisotropya = -1073741824;
    v15 = v1[4];
    if ( v3 > 2 || (unsigned int)v1[4] > 2 )
      D3DK::DXGRIP((int *)v3, "Assertion failure: %s", "(MinFilter <= D3DTEXF_LINEAR) && (MipFilter <= D3DTEXF_LINEAR)");
    if ( !v3 )
      D3DK::DXGRIP(0, "Assertion failure: %s", "MinFilter > D3DTEXF_NONE");
    v11 = (int *)(v15 + 2 * v3 + v3);
    v12 = *(_DWORD *)(4 * (_DWORD)v11 - 2146940752);
    v13 = XMETAL_StartPush(v11, &pDevice->m_Pusher);
    XMETAL_Push2f((int *)v13, v13, method - 12, *(float *)&address, *(float *)&control0);
    XMETAL_Push1f(
      (int *)v13,
      v13 + 3,
      method,
      COERCE_FLOAT(convolutionKernel | maxAnisotropya | v12 | (magFilter << 24) | v10 & 0x1FFF));
    XMETAL_EndPush((int *)v13 + 5, &pDevice->m_Pusher, v13 + 5);
    v1 += 32;
    v5 = v16 == 1;
    ++v21;
    method += 64;
    --v16;
  }
  while ( !v5 );
}