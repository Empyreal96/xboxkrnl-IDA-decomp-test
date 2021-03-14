// write access to const memory has been detected, the output may be wrong!
unsigned int __userpurge D3DResource_AddRef@<eax>(int *a1@<edi>, D3DResource *pResource)
{
  unsigned int result; // eax

  ++D3DK::g_PerfCounters.m_APICounters[188];
  D3DK::CHECK(pResource, "D3DResource_AddRef");
  if ( !(pResource->Common & 0xFFFF) && (pResource->Common & 0x70000) == 327680 && pResource[1].Lock )
    D3DResource_AddRef(a1, (D3DResource *)pResource[1].Lock);
  D3DK::ASSERTMSG(
    a1,
    (pResource->Common & 0xFFFF) != 0xFFFF,
    "D3DResource_AddRef overflow - was a Release() forgotten somewhere?");
  LOWORD(result) = LOWORD(pResource->Common) + 1;
  ++pResource->Common;
  return (unsigned __int16)result;
}