signed int __stdcall MmQueryAddressProtect(void *VirtualAddress)
{
  KIRQL v1; // bl
  unsigned int v2; // ecx
  signed int v3; // esi

  v1 = KeRaiseIrqlToDpcLevel();
  v2 = *(_DWORD *)((((unsigned int)VirtualAddress >> 20) & 0xFFC) - 1070596096);
  if ( v2 & 1
    && ((v2 & 0x80u) != 0
     || (v2 = *(_DWORD *)((((unsigned int)VirtualAddress >> 10) & 0x3FFFFC) - 0x40000000), v2 & 1)
     || v2 && (unsigned int)VirtualAddress <= 0x7FFEFFFF) )
  {
    v3 = MiDecodePteProtectionMask(v2);
  }
  else
  {
    v3 = 0;
  }
  KfLowerIrql(v1);
  return v3;
}