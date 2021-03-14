// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_DrawIndexedVertices(_D3DPRIMITIVETYPE PrimitiveType, unsigned int VertexCount, const unsigned __int16 *pIndexData)
{
  int *v3; // edi
  __m64 *v4; // ebx
  unsigned int v5; // ecx
  unsigned int v6; // ebx
  unsigned int v7; // ebx
  int v8; // ecx
  const unsigned __int16 *v9; // esi
  signed int v10; // ebx
  unsigned int v11; // ebx
  unsigned int v13; // ecx
  __m64 v14; // mm1
  __m64 v15; // mm2
  __m64 v16; // mm3
  __m64 v17; // mm4
  __m64 v18; // mm5
  __m64 v19; // mm6
  __m64 v20; // mm7
  __m64 *v22; // edi
  __m64 v23; // mm1
  __m64 v24; // mm2
  __m64 v25; // mm3
  __m64 v26; // mm4
  __m64 v27; // mm5
  __m64 v28; // mm6
  __m64 v29; // mm7
  unsigned int v30; // ebx
  unsigned int v31; // ST1C_4
  int *v32; // edi
  unsigned int *v33; // esi
  unsigned int v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // eax
  unsigned int arrayCount; // [esp+10h] [ebp-4h]
  __m64 *pPush; // [esp+1Ch] [ebp+8h]

  ++D3DK::g_PerfCounters.m_APICounters[40];
  D3DK::g_PerfCounters.m_PerformanceCounters[0].Count += VertexCount;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == PERF_VERTICES
    && D3DK::g_PerfCounters.m_PerformanceCounters[0].Count < D3DK::g_PerfCounters.m_BreakCount
    && VertexCount + D3DK::g_PerfCounters.m_PerformanceCounters[0].Count >= D3DK::g_PerfCounters.m_BreakCount )
  {
    __debugbreak();
  }
  v3 = (int *)PrimitiveType;
  if ( !VertexCount || VertexCount > 0x2000000 )
    D3DK::DXGRIP((int *)PrimitiveType, "Invalid VertexCount");
  if ( PrimitiveType == 0 || (signed int)PrimitiveType >= 10 )
    D3DK::DXGRIP((int *)PrimitiveType, "Invalid primitive type");
  if ( !pIndexData )
    D3DK::DXGRIP((int *)PrimitiveType, "Pointer to index data is NULL");
  if ( D3DK::g_pDevice->m_dwSnapshot )
  {
    D3DK::HandleShaderSnapshot_DrawIndexedVertices(PrimitiveType, VertexCount, pIndexData);
  }
  else
  {
    D3DK::CDevice::SetStateVB(D3DK::g_pDevice, (int *)PrimitiveType, D3DK::g_pDevice->m_IndexBase);
    g_StartPut = D3DK::g_pDevice->m_Pusher.m_pPut;
    if ( D3DK::g_pDevice->m_StateFlags & 0x800 )
      D3DK::DXGRIP((int *)PrimitiveType, "Assertion failure: %s", "!(m_StateFlags & STATE_BEGINENDBRACKET)");
    D3DK::g_pDevice->m_StateFlags |= 0x800u;
    v4 = (__m64 *)XMETAL_StartPushCount((int *)PrimitiveType, &D3DK::g_pDevice->m_Pusher, 0x209u);
    XMETAL_Push1f((int *)PrimitiveType, (unsigned int *)v4, 0x17FCu, *(float *)&PrimitiveType);
    v5 = VertexCount;
    ++v4;
    pPush = v4;
    v6 = ((unsigned int)-(signed int)v4 >> 2) & 7;
    if ( VertexCount >= 2 * v6 + 62 )
    {
      if ( v6 )
      {
        if ( v6 > 7 )
          D3DK::DXGRIP(v3, "Assertion failure: %s", "dwAlign <= 7");
        v7 = v6 - 1;
        XMETAL_PushCount(v3, (unsigned int *)pPush, 0x40001800u, v7);
        qmemcpy(&pPush->m64_i32[1], pIndexData, 4 * v7);
        v3 = &pPush->m64_i32[v7 + 1];
        v8 = (int)&pPush->m64_i32[v7 + 1];
        v9 = &pIndexData[2 * v7];
        v10 = VertexCount - 2 * v7;
        pPush = (__m64 *)v8;
        pIndexData = v9;
        VertexCount = v10;
        if ( v8 & 0x1F )
          D3DK::DXGRIP(v3, "Assertion failure: %s", "!((DWORD)pPush & 0x1f)");
        if ( v10 < 0 )
          D3DK::DXGRIP(v3, "Assertion failure: %s", "(INT) VertexCount >= 0");
        v5 = v10;
      }
      if ( v5 % 0x3FE < 0x3E )
        v11 = 511;
      else
        v11 = (((v5 % 0x3FE >> 1) + 1) & 0xFFFFFFF0) - 1;
      arrayCount = v11;
      do
      {
        XMETAL_PushCount(v3, (unsigned int *)pPush, 0x40001800u, v11);
        if ( v11 < 0x1F )
          D3DK::DXGRIP(v3, "Assertion failure: %s", "count >= 15 + 16");
        if ( ((_BYTE)v11 + 1) & 0xF )
          D3DK::DXGRIP(v3, "Assertion failure: %s", "!((count - 15) % 16)");
        _ESI = pIndexData;
        v13 = (arrayCount - 15) >> 4;
        __asm
        {
          prefetchnta byte ptr [esi+3Ch]
          prefetchnta byte ptr [esi+5Ch]
        }
        v14 = *(__m64 *)(pIndexData + 2);
        v15 = *(__m64 *)(pIndexData + 6);
        v16 = *(__m64 *)(pIndexData + 10);
        v17 = *(__m64 *)(pIndexData + 14);
        v18 = *(__m64 *)(pIndexData + 18);
        v19 = *(__m64 *)(pIndexData + 22);
        v20 = *(__m64 *)(pIndexData + 26);
        pPush->m64_i32[1] = *(_DWORD *)pIndexData;
        _mm_stream_pi(pPush + 1, v14);
        _mm_stream_pi(pPush + 2, v15);
        _mm_stream_pi(pPush + 3, v16);
        _mm_stream_pi(pPush + 4, v17);
        _mm_stream_pi(pPush + 5, v18);
        _mm_stream_pi(pPush + 6, v19);
        _mm_stream_pi(pPush + 7, v20);
        _ESI = (__m64 *)(pIndexData + 30);
        v22 = pPush + 8;
        do
        {
          __asm
          {
            prefetchnta byte ptr [esi+40h]
            prefetchnta byte ptr [esi+60h]
          }
          v23 = _ESI[1];
          v24 = _ESI[2];
          v25 = _ESI[3];
          v26 = _ESI[4];
          v27 = _ESI[5];
          v28 = _ESI[6];
          v29 = _ESI[7];
          _mm_stream_pi(v22, (__m64)_ESI->m64_u64);
          _mm_stream_pi(v22 + 1, v23);
          _mm_stream_pi(v22 + 2, v24);
          _mm_stream_pi(v22 + 3, v25);
          _mm_stream_pi(v22 + 4, v26);
          _mm_stream_pi(v22 + 5, v27);
          _mm_stream_pi(v22 + 6, v28);
          _mm_stream_pi(v22 + 7, v29);
          _ESI += 8;
          v22 += 8;
          --v13;
        }
        while ( v13 );
        pIndexData += 2 * v11;
        VertexCount -= 2 * v11;
        v3 = (int *)VertexCount;
        if ( (VertexCount & 0x80000000) != 0 )
          D3DK::DXGRIP((int *)VertexCount, "Assertion failure: %s", "(INT) VertexCount >= 0");
        XMETAL_EndPush((int *)VertexCount, &D3DK::g_pDevice->m_Pusher, (unsigned int *)&pPush->m64_i32[v11 + 1]);
        v11 = 511;
        pPush = (__m64 *)XMETAL_StartPushCount((int *)VertexCount, &D3DK::g_pDevice->m_Pusher, 0x204u);
        arrayCount = 511;
      }
      while ( VertexCount >= 0x3FE );
      _m_femms();
      v5 = VertexCount;
    }
    v30 = v5 >> 1;
    v31 = v5 >> 1;
    XMETAL_PushCount(v3, (unsigned int *)pPush, 0x40001800u, v5 >> 1);
    qmemcpy(&pPush->m64_i32[1], pIndexData, 4 * v31);
    v32 = &pPush->m64_i32[v31 + 1];
    v33 = (unsigned int *)&pPush->m64_i32[v30 + 1];
    if ( VertexCount & 1 )
    {
      XMETAL_Push1f(v32, (unsigned int *)&pPush->m64_i32[v30 + 1], 0x1808u, COERCE_FLOAT(pIndexData[2 * v30]));
      v33 = &pPush[1].m64_u32[v30 + 1];
    }
    XMETAL_Push1f(v32, v33, 0x17FCu, 0.0);
    XMETAL_EndPush(v32, &D3DK::g_pDevice->m_Pusher, v33 + 2);
    v34 = (char *)D3DK::g_pDevice->m_Pusher.m_pPut - (char *)g_StartPut;
    if ( (v34 & 0x80000000) != 0 )
      v34 += D3DK::g_pDevice->m_PusherLastSize;
    if ( v34 > D3DK::CDevice::m_PushBufferSize >> 1 )
      D3DK::WARNING(
        v32,
        "Vertex or index data for this call exceeded half of the push-buffer size.\n"
        "Reduce the call size or increase the push-buffer size with SetPushBufferSize.\n");
    v35 = D3DK::g_pDevice->m_StateFlags;
    if ( !(v35 & 0x800) )
      D3DK::DXGRIP(v32, "Assertion failure: %s", "m_StateFlags & STATE_BEGINENDBRACKET");
    v36 = D3DK::g_pDevice->m_StateFlags;
    if ( v36 & 0x1000 )
      D3DK::SetFence(1u);
    D3DK::g_pDevice->m_StateFlags &= 0xFFFFE7FF;
  }
}