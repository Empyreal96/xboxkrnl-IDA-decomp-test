// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DK::LazySetCombiners(D3DK::CDevice *pDevice)
{
  D3DK::CDevice *v1; // esi
  D3DK::PixelShader *v2; // eax
  unsigned int v3; // ebx
  int *v4; // edi
  unsigned int *v5; // eax
  int v6; // ecx
  unsigned int *v7; // edi
  unsigned int d3dStage; // [esp+8h] [ebp+8h]

  ++D3DK::g_PerfCounters.m_PerformanceCounters[24].Count;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == 24
    && D3DK::g_PerfCounters.m_PerformanceCounters[24].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
  {
    __debugbreak();
  }
  v1 = pDevice;
  v2 = pDevice->m_pPixelShader;
  pDevice->m_DirtyFlags &= 0xFFFFFFF7;
  if ( !v2 )
  {
    v3 = 0;
    do
    {
      d3dStage = v3;
      v4 = (int *)D3DK::ConstructColorCombiners(v1, v3, v3);
      D3DK::ConstructAlphaCombiners(v1, v3, v3, (int)v4);
      if ( !v4 && v3 )
        break;
      ++v3;
      if ( !v4 )
        break;
    }
    while ( d3dStage < 3 );
    v1->m_ActiveCombinerStagesCount = v3;
    if ( v3 < 8 )
    {
      v5 = &v1->m_ColorOCW[v3];
      v6 = 8 - v3;
      do
      {
        *(v5 - 8) = 0;
        *v5 = 0;
        *(v5 - 24) = 0;
        *(v5 - 16) = 0;
        ++v5;
        --v6;
      }
      while ( v6 );
    }
    v7 = XMETAL_StartPush(v4, &v1->m_Pusher);
    XMETAL_Push1f((int *)v7, v7, 0x1E60u, COERCE_FLOAT(v3));
    XMETAL_PushCount((int *)v7, v7 + 2, 0xAC0u, 8u);
    v7[3] = v1->m_ColorICW[0];
    v7[4] = v1->m_ColorICW[1];
    v7[5] = v1->m_ColorICW[2];
    v7[6] = v1->m_ColorICW[3];
    v7[7] = v1->m_ColorICW[4];
    v7[8] = v1->m_ColorICW[5];
    v7[9] = v1->m_ColorICW[6];
    v7[10] = v1->m_ColorICW[7];
    XMETAL_PushCount((int *)v7, v7 + 11, 0x1E40u, 8u);
    v7[12] = v1->m_ColorOCW[0];
    v7[13] = v1->m_ColorOCW[1];
    v7[14] = v1->m_ColorOCW[2];
    v7[15] = v1->m_ColorOCW[3];
    v7[16] = v1->m_ColorOCW[4];
    v7[17] = v1->m_ColorOCW[5];
    v7[18] = v1->m_ColorOCW[6];
    v7[19] = v1->m_ColorOCW[7];
    XMETAL_PushCount((int *)v7, v7 + 20, 0x260u, 8u);
    v7[21] = v1->m_AlphaICW[0];
    v7[22] = v1->m_AlphaICW[1];
    v7[23] = v1->m_AlphaICW[2];
    v7[24] = v1->m_AlphaICW[3];
    v7[25] = v1->m_AlphaICW[4];
    v7[26] = v1->m_AlphaICW[5];
    v7[27] = v1->m_AlphaICW[6];
    v7[28] = v1->m_AlphaICW[7];
    XMETAL_PushCount((int *)v7, v7 + 29, 0xAA0u, 8u);
    v7[30] = v1->m_AlphaOCW[0];
    v7[31] = v1->m_AlphaOCW[1];
    v7[32] = v1->m_AlphaOCW[2];
    v7[33] = v1->m_AlphaOCW[3];
    v7[34] = v1->m_AlphaOCW[4];
    v7[35] = v1->m_AlphaOCW[5];
    v7[36] = v1->m_AlphaOCW[6];
    v7[37] = v1->m_AlphaOCW[7];
    XMETAL_EndPush((int *)v7 + 38, &v1->m_Pusher, v7 + 38);
  }
}