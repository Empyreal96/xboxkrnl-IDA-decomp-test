// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_DrawVertices(_D3DPRIMITIVETYPE PrimitiveType, unsigned int StartVertex, unsigned int VertexCount)
{
  unsigned int v3; // ebx
  unsigned int v4; // esi
  unsigned int *v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // ecx
  _D3DPRIMITIVETYPE PrimitiveTypea; // [esp+14h] [ebp+8h]

  v3 = VertexCount;
  ++D3DK::g_PerfCounters.m_APICounters[44];
  D3DK::g_PerfCounters.m_PerformanceCounters[0].Count += VertexCount;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == PERF_VERTICES
    && D3DK::g_PerfCounters.m_PerformanceCounters[0].Count < D3DK::g_PerfCounters.m_BreakCount
    && VertexCount + D3DK::g_PerfCounters.m_PerformanceCounters[0].Count >= D3DK::g_PerfCounters.m_BreakCount )
  {
    __debugbreak();
  }
  if ( !VertexCount )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Zero VertexCount");
  if ( PrimitiveType == 0 || (signed int)PrimitiveType >= 10 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Invalid primitive type");
  if ( StartVertex > 0xFFFF )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Hardware can't take a StartVertex more than 0xffff");
  if ( StartVertex + VertexCount > 0xFFFF )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Hardware can't take more than 0xffff vertices");
  if ( D3DK::g_pDevice->m_dwSnapshot )
  {
    D3DK::HandleShaderSnapshot_DrawVertices(PrimitiveType, StartVertex, VertexCount);
  }
  else
  {
    D3DK::CDevice::SetStateVB(D3DK::g_pDevice, (int *)D3DK::g_pDevice, 0);
    v4 = ((VertexCount - 1) >> 8) + 1;
    v5 = XMETAL_StartPushCount((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, ((VertexCount - 1) >> 8) + 6);
    XMETAL_Push1f((int *)v5, v5, 0x17FCu, *(float *)&PrimitiveType);
    XMETAL_PushCount((int *)v5, v5 + 2, 0x40001810u, v4);
    if ( VertexCount > 0x100 )
    {
      v6 = ((VertexCount - 257) >> 8) + 1;
      PrimitiveTypea = ((VertexCount - 257) >> 8) + 1;
      do
      {
        v5[3] = StartVertex | 0xFF000000;
        ++v5;
        StartVertex += 256;
        v3 -= 256;
        v7 = v4--;
        if ( v7 <= 1 )
        {
          D3DK::DXGRIP((int *)v5, "Assertion failure: %s", "drawArraysCount-- > 1");
          v6 = PrimitiveTypea;
        }
        PrimitiveTypea = --v6;
      }
      while ( v6 );
    }
    if ( v4 != 1 )
      D3DK::DXGRIP((int *)v5, "Assertion failure: %s", "drawArraysCount == 1");
    if ( v3 < 1 )
      D3DK::DXGRIP((int *)v5, "Assertion failure: %s", "VertexCount >= 1");
    v5[3] = StartVertex | ((v3 - 1) << 24);
    XMETAL_Push1f((int *)v5, v5 + 4, 0x17FCu, 0.0);
    XMETAL_EndPush((int *)v5 + 6, &D3DK::g_pDevice->m_Pusher, v5 + 6);
  }
}