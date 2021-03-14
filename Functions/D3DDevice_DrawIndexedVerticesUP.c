// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_DrawIndexedVerticesUP(_D3DPRIMITIVETYPE PrimitiveType, unsigned int VertexCount, const void *pIndexData, const void *pVertexStreamZeroData, unsigned int VertexStreamZeroStride)
{
  unsigned int v5; // ebx
  int *v6; // edi
  unsigned int v7; // esi
  unsigned int *v8; // ebx
  unsigned int *v9; // esi
  char *v10; // ecx
  unsigned int v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // esi
  int *v14; // edi
  unsigned __int16 *v15; // edx
  unsigned int *v16; // edi
  int v17; // esi
  unsigned int v18; // eax
  D3DK::InlineAttributeData *v19; // ebx
  char *v20; // esi
  unsigned int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int attributeCount; // [esp+Ch] [ebp-14h]
  char *pVertexStart; // [esp+14h] [ebp-Ch]
  signed int batchLimit; // [esp+1Ch] [ebp-4h]
  unsigned int VertexCounta; // [esp+2Ch] [ebp+Ch]
  unsigned int batchCount; // [esp+34h] [ebp+14h]

  v5 = VertexCount;
  ++D3DK::g_PerfCounters.m_APICounters[41];
  D3DK::g_PerfCounters.m_PerformanceCounters[0].Count += VertexCount;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == PERF_VERTICES
    && D3DK::g_PerfCounters.m_PerformanceCounters[0].Count < D3DK::g_PerfCounters.m_BreakCount
    && VertexCount + D3DK::g_PerfCounters.m_PerformanceCounters[0].Count >= D3DK::g_PerfCounters.m_BreakCount )
  {
    __debugbreak();
  }
  v6 = (int *)D3DK::g_pDevice;
  D3DK::CDevice::SetStateUP(D3DK::g_pDevice, (int *)D3DK::g_pDevice);
  if ( D3DK::g_pDevice->m_DirtyFlags & 0x40000000 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Can't use Draw*UP calls with SetVertexShaderInput");
  if ( !VertexCount )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Zero VertexCount");
  if ( PrimitiveType == 0 || (signed int)PrimitiveType >= 10 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Invalid primitive type");
  if ( !VertexStreamZeroStride )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Invalid stride");
  if ( !pIndexData || !pVertexStreamZeroData )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "NULL pointer");
  if ( (unsigned __int8)pVertexStreamZeroData & 3 || VertexStreamZeroStride & 3 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "DWORD alignment is required for the UP stream data");
  v7 = 0;
  if ( D3DK::g_pDevice->m_InlineAttributeCount )
  {
    v8 = &D3DK::g_pDevice->m_InlineAttributeData[0].UP_Delta;
    do
    {
      if ( *(_BYTE *)v8 & 3 )
        D3DK::DXGRIP((int *)D3DK::g_pDevice, "DWORD alignment is required for every UP attribute");
      ++v7;
      v8 += 2;
    }
    while ( v7 < D3DK::g_pDevice->m_InlineAttributeCount );
    v5 = VertexCount;
  }
  if ( D3DK::g_pDevice->m_dwSnapshot )
  {
    D3DK::HandleShaderSnapshot_DrawIndexedVerticesUP(
      PrimitiveType,
      v5,
      pIndexData,
      pVertexStreamZeroData,
      VertexStreamZeroStride);
  }
  else
  {
    v9 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
    XMETAL_Push1f((int *)D3DK::g_pDevice, v9, 0x17FCu, *(float *)&PrimitiveType);
    XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v9 + 2);
    g_StartPut = D3DK::g_pDevice->m_Pusher.m_pPut;
    if ( D3DK::g_pDevice->m_StateFlags & 0x800 )
      D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "!(m_StateFlags & STATE_BEGINENDBRACKET)");
    v10 = (char *)pVertexStreamZeroData + D3DK::g_pDevice->m_InlineStartOffset;
    v11 = D3DK::g_pDevice->m_InlineAttributeCount;
    D3DK::g_pDevice->m_StateFlags |= 0x800u;
    pVertexStart = v10;
    attributeCount = v11;
    if ( v5 > 0x10 )
    {
      batchLimit = 0x7FF / D3DK::g_pDevice->m_InlineVertexDwords;
      goto LABEL_33;
    }
    v12 = 16;
    for ( batchLimit = 16; ; v12 = batchLimit )
    {
      if ( v12 >= v5 )
        v12 = v5;
      v13 = v12 * v6[506];
      batchCount = v12;
      VertexCounta = v5 - v12;
      v14 = (int *)XMETAL_StartPushCount(v6, (_XMETAL_PushBuffer *)v6, v13 + 3);
      if ( !v13 || v13 >= 0x800 )
        D3DK::DXGRIP(v14, "Assertion failure: %s", "(count) && (count < 2048)");
      XMETAL_PushCount(v14 + 1, (unsigned int *)v14, 0x40001818u, v13);
      v15 = (unsigned __int16 *)pIndexData;
      v16 = (unsigned int *)(v14 + 1);
      do
      {
        v17 = *v15;
        ++v15;
        v18 = attributeCount;
        v19 = D3DK::g_pDevice->m_InlineAttributeData;
        v20 = &pVertexStart[VertexStreamZeroStride * v17];
        do
        {
          v21 = v19->UP_Count;
          qmemcpy(v16, v20, 4 * v19->UP_Count);
          v16 += v21;
          v20 += 4 * v21 + v19->UP_Delta;
          ++v19;
          --v18;
        }
        while ( v18 );
        --batchCount;
      }
      while ( batchCount );
      pIndexData = v15;
      if ( !VertexCounta )
        break;
      XMETAL_EndPush((int *)v16, &D3DK::g_pDevice->m_Pusher, v16);
      v6 = (int *)D3DK::g_pDevice;
      v5 = VertexCounta;
LABEL_33:
      ;
    }
    XMETAL_Push1f((int *)v16, v16, 0x17FCu, 0.0);
    XMETAL_EndPush((int *)v16, &D3DK::g_pDevice->m_Pusher, v16 + 2);
    v22 = (char *)D3DK::g_pDevice->m_Pusher.m_pPut - (char *)g_StartPut;
    if ( (v22 & 0x80000000) != 0 )
      v22 += D3DK::g_pDevice->m_PusherLastSize;
    if ( v22 > D3DK::CDevice::m_PushBufferSize >> 1 )
      D3DK::WARNING(
        (int *)v16,
        "Vertex or index data for this call exceeded half of the push-buffer size.\n"
        "Reduce the call size or increase the push-buffer size with SetPushBufferSize.\n");
    v23 = D3DK::g_pDevice->m_StateFlags;
    if ( !(v23 & 0x800) )
      D3DK::DXGRIP((int *)v16, "Assertion failure: %s", "m_StateFlags & STATE_BEGINENDBRACKET");
    v24 = D3DK::g_pDevice->m_StateFlags;
    if ( v24 & 0x1000 )
      D3DK::SetFence(1u);
    D3DK::g_pDevice->m_StateFlags &= 0xFFFFE7FF;
  }
}