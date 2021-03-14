// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetStreamSource(int *a1@<edi>, unsigned int StreamNumber, D3DVertexBuffer *pVertexBuffer, unsigned int Stride)
{
  unsigned int v4; // esi
  int *v5; // edi
  D3DResource *v6; // edi
  int v7; // eax
  unsigned int v8; // ecx

  ++D3DK::g_PerfCounters.m_APICounters[161];
  if ( StreamNumber > 0xF )
    D3DK::DXGRIP(a1, "Invalid stream number");
  if ( Stride > 0xFF )
    D3DK::DXGRIP((int *)Stride, "NV2A allows a maximum stride of 255");
  v4 = 12 * StreamNumber;
  if ( pVertexBuffer == (D3DVertexBuffer *)dword_800C1EE0[3 * StreamNumber] && Stride == D3DK::g_Stream[v4 / 0xC].Stride )
  {
    ++D3DK::g_PerfCounters.m_PerformanceCounters[22].Count;
    if ( D3DK::g_PerfCounters.m_Breakperfctr == 22
      && D3DK::g_PerfCounters.m_PerformanceCounters[22].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
    {
      __debugbreak();
    }
  }
  if ( pVertexBuffer )
    D3DK::InternalAddRef((int *)Stride, (D3DResource *)&pVertexBuffer->Common);
  v5 = (int *)dword_800C1EE0[v4 / 4];
  if ( v5 )
  {
    if ( (*v5 & 0x70000) == 327680 )
      D3DK::DXGRIP(v5, "Assertion failure: %s", "!PixelJar::IsSurface(pResource)");
    v5[2] = D3DK::g_pDevice->m_CpuTime;
    v6 = (D3DResource *)dword_800C1EE0[v4 / 4];
    if ( !(v6->Common & 0x780000) )
      D3DK::DXGRIP((int *)v6, "Assertion failure: %s", "(pResource->Common & D3DCOMMON_INTREFCOUNT_MASK) != 0");
    if ( (v6->Common & 0x70000) == 327680 )
      D3DK::DXGRIP(
        (int *)v6,
        "Assertion failure: %s",
        "(pResource->Common & D3DCOMMON_TYPE_MASK) != D3DCOMMON_TYPE_SURFACE");
    v7 = v6->Common - 0x80000;
    v6->Common = v7;
    if ( !(v7 & 0x78FFFF) )
      D3DK::DestroyResource(v6);
  }
  v8 = D3DK::g_pDevice->m_DirtyFlags;
  if ( Stride == D3DK::g_Stream[v4 / 0xC].Stride )
    D3DK::g_pDevice->m_DirtyFlags = v8 | 0x200;
  else
    D3DK::g_pDevice->m_DirtyFlags = v8 | 0x280;
  dword_800C1EE0[v4 / 4] = (int)pVertexBuffer;
  D3DK::g_Stream[v4 / 0xC].Stride = Stride;
}