_MMADDRESS_NODE *__fastcall MiLocateAddress(void *VirtualAddress)
{
  _MMADDRESS_NODE *result; // eax
  unsigned int v2; // ecx

  result = MmVadHint;
  if ( MmVadHint )
  {
    v2 = (unsigned int)VirtualAddress >> 12;
    if ( v2 < MmVadHint->StartingVpn || v2 > MmVadHint->EndingVpn )
    {
      result = MiLocateAddressInTree(v2, &MmVadRoot);
      if ( result )
        MmVadHint = result;
    }
  }
  return result;
}