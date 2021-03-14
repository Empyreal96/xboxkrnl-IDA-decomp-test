// write access to const memory has been detected, the output may be wrong!
int __userpurge D3DDevice_GetRenderTarget@<eax>(int *a1@<edi>, D3DSurface **ppRenderTarget)
{
  D3DSurface *v2; // eax

  ++D3DK::g_PerfCounters.m_APICounters[77];
  v2 = D3DK::g_pDevice->m_pRenderTarget;
  *ppRenderTarget = v2;
  if ( v2 )
    D3DResource_AddRef(a1, (D3DResource *)&v2->Common);
  return 0;
}