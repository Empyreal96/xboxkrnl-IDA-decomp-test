BOOL __stdcall D3DK::IsResourceSetInDevice(D3DResource *pResource)
{
  _DWORD *v1; // esi
  BOOL result; // eax

  D3DK::CHECK(pResource, "IsResourceSetInDevice");
  result = 1;
  if ( !(pResource->Common & 0x780000) )
  {
    if ( (pResource->Common & 0x70000) != 327680 || (v1 = (_DWORD *)pResource[1].Lock) == 0 || !(*v1 & 0x780000) )
      result = 0;
  }
  return result;
}