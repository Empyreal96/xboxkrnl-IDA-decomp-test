// write access to const memory has been detected, the output may be wrong!
int __userpurge D3DDevice_GetDepthStencilSurface@<eax>(int *a1@<edi>, D3DSurface **ppZStencilSurface)
{
  D3DSurface *v2; // eax

  ++D3DK::g_PerfCounters.m_APICounters[57];
  v2 = D3DK::g_pDevice->m_pZBuffer;
  *ppZStencilSurface = v2;
  if ( !v2 )
    return -2005530522;
  D3DResource_AddRef(a1, (D3DResource *)&v2->Common);
  return 0;
}