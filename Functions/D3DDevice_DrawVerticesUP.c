// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_DrawVerticesUP(_D3DPRIMITIVETYPE PrimitiveType, unsigned int VertexCount, const void *pVertexStreamZeroData, unsigned int VertexStreamZeroStride)
{
  unsigned int v4; // ebx
  int *v5; // edi
  D3DK::CDevice *v6; // esi
  int *v7; // edi
  int *v8; // edi
  char *v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // edi
  unsigned int *v13; // esi
  unsigned int v14; // edx
  char *v15; // esi
  unsigned int *v16; // edi
  D3DK::InlineAttributeData *v17; // ebx
  unsigned int v18; // eax
  unsigned int v19; // ecx
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // eax
  unsigned int attributeCount; // [esp+10h] [ebp-Ch]
  char *pVertexStart; // [esp+14h] [ebp-8h]
  unsigned int *pPush; // [esp+24h] [ebp+8h]
  unsigned int *VertexCounta; // [esp+28h] [ebp+Ch]
  unsigned int VertexCountb; // [esp+28h] [ebp+Ch]
  signed int batchLimit; // [esp+2Ch] [ebp+10h]
  unsigned int batchCount; // [esp+30h] [ebp+14h]

  v4 = VertexCount;
  v5 = (int *)(D3DK::g_PerfCounters.m_APICounters[45]++ + 1);
  D3DK::g_PerfCounters.m_PerformanceCounters[0].Count += VertexCount;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == PERF_VERTICES
    && D3DK::g_PerfCounters.m_PerformanceCounters[0].Count < D3DK::g_PerfCounters.m_BreakCount
    && VertexCount + D3DK::g_PerfCounters.m_PerformanceCounters[0].Count >= D3DK::g_PerfCounters.m_BreakCount )
  {
    __debugbreak();
  }
  v6 = D3DK::g_pDevice;
  D3DK::CDevice::SetStateUP(D3DK::g_pDevice, v5);
  if ( D3DK::g_pDevice->m_DirtyFlags & 0x40000000 )
    D3DK::DXGRIP(v5, "Can't use Draw*UP calls with SetVertexShaderInput");
  if ( !VertexCount )
    D3DK::DXGRIP((int *)PrimitiveType, "Zero VertexCount");
  if ( PrimitiveType == 0 || (signed int)PrimitiveType >= 10 )
    D3DK::DXGRIP((int *)PrimitiveType, "Invalid primitive type");
  if ( !VertexStreamZeroStride )
    D3DK::DXGRIP((int *)PrimitiveType, "Invalid stride");
  if ( !pVertexStreamZeroData )
    D3DK::DXGRIP((int *)PrimitiveType, "NULL pointer");
  if ( (unsigned __int8)pVertexStreamZeroData & 3 || VertexStreamZeroStride & 3 )
    D3DK::DXGRIP((int *)PrimitiveType, "DWORD alignment is required for the UP stream data");
  v7 = 0;
  if ( D3DK::g_pDevice->m_InlineAttributeCount )
  {
    VertexCounta = &D3DK::g_pDevice->m_InlineAttributeData[0].UP_Delta;
    do
    {
      if ( *(_BYTE *)VertexCounta & 3 )
        D3DK::DXGRIP(v7, "DWORD alignment is required for every UP attribute");
      v7 = (int *)((char *)v7 + 1);
      VertexCounta += 2;
    }
    while ( (unsigned int)v7 < D3DK::g_pDevice->m_InlineAttributeCount );
  }
  if ( D3DK::g_pDevice->m_dwSnapshot )
  {
    D3DK::HandleShaderSnapshot_DrawVerticesUP(PrimitiveType, v4, pVertexStreamZeroData, VertexStreamZeroStride);
  }
  else
  {
    v8 = (int *)XMETAL_StartPush(v7, &D3DK::g_pDevice->m_Pusher);
    XMETAL_Push1f(v8, (unsigned int *)v8, 0x17FCu, *(float *)&PrimitiveType);
    XMETAL_EndPush(v8 + 2, &D3DK::g_pDevice->m_Pusher, (unsigned int *)v8 + 2);
    g_StartPut = D3DK::g_pDevice->m_Pusher.m_pPut;
    if ( D3DK::g_pDevice->m_StateFlags & 0x800 )
      D3DK::DXGRIP((int *)0x800, "Assertion failure: %s", "!(m_StateFlags & STATE_BEGINENDBRACKET)");
    v9 = (char *)pVertexStreamZeroData + D3DK::g_pDevice->m_InlineStartOffset;
    v10 = D3DK::g_pDevice->m_InlineDelta;
    D3DK::g_pDevice->m_StateFlags |= 0x800u;
    pVertexStart = v9;
    attributeCount = D3DK::g_pDevice->m_InlineAttributeCount;
    *(&D3DK::g_pDevice->m_InlineDelta + 2 * attributeCount) = VertexStreamZeroStride + v10;
    if ( v4 > 0x10 )
    {
      batchLimit = 0x7FF / D3DK::g_pDevice->m_InlineVertexDwords;
      goto LABEL_31;
    }
    v11 = 16;
    for ( batchLimit = 16; ; v11 = batchLimit )
    {
      if ( v11 >= v4 )
        v11 = v4;
      v12 = v11 * v6->m_InlineVertexDwords;
      batchCount = v11;
      VertexCountb = v4 - v11;
      v13 = XMETAL_StartPushCount((int *)v12, &v6->m_Pusher, v12 + 3);
      if ( !v12 || v12 >= 0x800 )
        D3DK::DXGRIP((int *)v12, "Assertion failure: %s", "(count) && (count < 2048)");
      pPush = v13 + 1;
      XMETAL_PushCount((int *)v12, v13, 0x40001818u, v12);
      v14 = batchCount;
      v15 = pVertexStart;
      v16 = pPush;
      do
      {
        v17 = D3DK::g_pDevice->m_InlineAttributeData;
        v18 = attributeCount;
        do
        {
          v19 = v17->UP_Count;
          qmemcpy(v16, v15, 4 * v17->UP_Count);
          v16 += v19;
          v15 += 4 * v19 + v17->UP_Delta;
          ++v17;
          --v18;
        }
        while ( v18 );
        --v14;
      }
      while ( v14 );
      pVertexStart = v15;
      if ( !VertexCountb )
        break;
      XMETAL_EndPush((int *)v16, &D3DK::g_pDevice->m_Pusher, v16);
      v6 = D3DK::g_pDevice;
      v4 = VertexCountb;
LABEL_31:
      ;
    }
    XMETAL_Push1f((int *)v16, v16, 0x17FCu, 0.0);
    XMETAL_EndPush((int *)v16, &D3DK::g_pDevice->m_Pusher, v16 + 2);
    v20 = (char *)D3DK::g_pDevice->m_Pusher.m_pPut - (char *)g_StartPut;
    if ( (v20 & 0x80000000) != 0 )
      v20 += D3DK::g_pDevice->m_PusherLastSize;
    if ( v20 > D3DK::CDevice::m_PushBufferSize >> 1 )
      D3DK::WARNING(
        (int *)v16,
        "Vertex or index data for this call exceeded half of the push-buffer size.\n"
        "Reduce the call size or increase the push-buffer size with SetPushBufferSize.\n");
    v21 = D3DK::g_pDevice->m_StateFlags;
    if ( !(v21 & 0x800) )
      D3DK::DXGRIP((int *)v16, "Assertion failure: %s", "m_StateFlags & STATE_BEGINENDBRACKET");
    v22 = D3DK::g_pDevice->m_StateFlags;
    if ( v22 & 0x1000 )
      D3DK::SetFence(1u);
    D3DK::g_pDevice->m_StateFlags &= 0xFFFFE7FF;
  }
}