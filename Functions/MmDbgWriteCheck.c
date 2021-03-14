void *__stdcall MmDbgWriteCheck(void *VirtualAddress, _HARDWARE_PTE *Opaque)
{
  _HARDWARE_PTE *v2; // esi
  _BYTE *v4; // eax
  _HARDWARE_PTE v5; // ecx
  unsigned int PointerPte; // [esp+14h] [ebp+Ch]

  v2 = Opaque;
  *Opaque = 0;
  if ( !MmIsAddressValid(VirtualAddress) )
    return 0;
  v4 = (_BYTE *)((((unsigned int)VirtualAddress >> 20) & 0xFFC) - 1070596096);
  PointerPte = (((unsigned int)VirtualAddress >> 20) & 0xFFC) - 1070596096;
  if ( *v4 >= 0 )
  {
    v4 = (_BYTE *)((((unsigned int)VirtualAddress >> 10) & 0x3FFFFC) - 0x40000000);
    PointerPte = (((unsigned int)VirtualAddress >> 10) & 0x3FFFFC) - 0x40000000;
  }
  v5 = *(_HARDWARE_PTE *)v4;
  if ( !(*(_DWORD *)v4 & 2) )
  {
    *v2 = v5;
    *(_DWORD *)v4 = *(_DWORD *)&v5 | 2;
    __invlpg((void *)(PointerPte << 10));
  }
  return VirtualAddress;
}