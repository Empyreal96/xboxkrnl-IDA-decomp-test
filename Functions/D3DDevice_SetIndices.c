// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetIndices(int *a1@<edi>, D3DIndexBuffer *pIndexBuffer, unsigned int BaseVertexIndex)
{
  D3DIndexBuffer *v3; // edi
  int v4; // eax

  ++D3DK::g_PerfCounters.m_APICounters[118];
  if ( D3DK::g_pDevice->m_StateFlags & 4 && BaseVertexIndex )
    D3DK::DXGRIP(a1, "Can't set non-zero BaseVertexIndex while recording a push-buffer");
  if ( pIndexBuffer )
  {
    D3DK::InternalAddRef(a1, (D3DResource *)&pIndexBuffer->Common);
    D3D__IndexData = (unsigned __int16 *)pIndexBuffer->Data;
  }
  else
  {
    D3D__IndexData = 0;
  }
  v3 = D3DK::g_pDevice->m_pIndexBuffer;
  if ( v3 )
  {
    if ( !(v3->Common & 0x780000) )
      D3DK::DXGRIP((int *)v3, "Assertion failure: %s", "(pResource->Common & D3DCOMMON_INTREFCOUNT_MASK) != 0");
    if ( (v3->Common & 0x70000) == 327680 )
      D3DK::DXGRIP(
        (int *)v3,
        "Assertion failure: %s",
        "(pResource->Common & D3DCOMMON_TYPE_MASK) != D3DCOMMON_TYPE_SURFACE");
    v4 = v3->Common - 0x80000;
    v3->Common = v4;
    if ( !(v4 & 0x78FFFF) )
      D3DK::DestroyResource((D3DResource *)&v3->Common);
    D3DK::g_pDevice->m_pIndexBuffer = pIndexBuffer;
    D3DK::g_pDevice->m_IndexBase = BaseVertexIndex;
  }
  else
  {
    D3DK::g_pDevice->m_pIndexBuffer = pIndexBuffer;
    D3DK::g_pDevice->m_IndexBase = BaseVertexIndex;
  }
}