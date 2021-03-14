// write access to const memory has been detected, the output may be wrong!
int __userpurge D3DResource_GetType@<eax>(int *a1@<edi>, D3DResource *pResource)
{
  unsigned int v2; // eax
  int result; // eax
  unsigned int v4; // eax

  ++D3DK::g_PerfCounters.m_APICounters[193];
  D3DK::CHECK(pResource, "D3DResource_GetType");
  v2 = pResource->Common & 0x70000;
  if ( v2 <= 0x30000 )
  {
    switch ( v2 )
    {
      case 0x30000u:
        return 9;
      case 0u:
        return 6;
      case 0x10000u:
        return 7;
      case 0x20000u:
        return 8;
    }
    goto LABEL_13;
  }
  switch ( v2 )
  {
    case 0x40000u:
      v4 = pResource[1].Common;
      if ( v4 & 4 )
        result = 5;
      else
        result = ((pResource[1].Common & 0xF0) > 0x20) + 3;
      break;
    case 0x50000u:
      result = ((pResource[1].Common & 0xF0) > 0x20) + 1;
      break;
    case 0x60000u:
      result = 10;
      break;
    default:
LABEL_13:
      D3DK::DXGRIP(a1, "D3DResource_GetType - unknown type");
      return 0;
  }
  return result;
}