void __userpurge MmDbgReleaseAddress(int *a1@<edi>, void *VirtualAddress, _HARDWARE_PTE *Opaque)
{
  unsigned int v3; // esi
  int v4; // edx
  int v5; // ecx
  _HARDWARE_PTE *v6; // eax
  int PointerPte; // [esp+Ch] [ebp+8h]

  v3 = (unsigned int)VirtualAddress;
  if ( !MmIsAddressValid(VirtualAddress) )
    RtlAssert(
      v4,
      v5,
      a1,
      (int)VirtualAddress,
      "MmIsAddressValid(VirtualAddress)",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\debugsup.c",
      0x73u,
      0);
  if ( *Opaque )
  {
    PointerPte = (((unsigned int)VirtualAddress >> 20) & 0xFFC) - 1070596096;
    v6 = (_HARDWARE_PTE *)PointerPte;
    if ( *(_BYTE *)PointerPte >= 0 )
    {
      v6 = (_HARDWARE_PTE *)(((v3 >> 10) & 0x3FFFFC) - 0x40000000);
      PointerPte = ((v3 >> 10) & 0x3FFFFC) - 0x40000000;
    }
    *v6 = *Opaque;
    __invlpg((void *)(PointerPte << 10));
  }
}