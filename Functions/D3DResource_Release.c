// write access to const memory has been detected, the output may be wrong!
unsigned int __userpurge D3DResource_Release@<eax>(int *a1@<edi>, D3DResource *pResource)
{
  unsigned int v2; // eax
  unsigned int result; // eax

  ++D3DK::g_PerfCounters.m_APICounters[196];
  D3DK::CHECK(pResource, "D3DResource_Release");
  v2 = pResource->Common;
  if ( (unsigned __int16)pResource->Common != 1 )
    goto LABEL_10;
  if ( (v2 & 0x70000) == 327680 )
  {
    if ( pResource[1].Lock )
      D3DResource_Release(a1, (D3DResource *)pResource[1].Lock);
  }
  v2 = pResource->Common;
  if ( pResource->Common & 0x780000 )
  {
LABEL_10:
    D3DK::ASSERTMSG(
      a1,
      (unsigned __int16)v2 != 0,
      "D3DResource_Release underflow - was an AddRef() forgotten somewhere?");
    LOWORD(result) = LOWORD(pResource->Common) - 1;
    --pResource->Common;
    result = (unsigned __int16)result;
  }
  else
  {
    D3DK::DestroyResource(pResource);
    result = 0;
  }
  return result;
}