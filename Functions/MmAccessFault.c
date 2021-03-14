int __userpurge MmAccessFault@<eax>(int *a1@<edi>, char StoreInstruction, void *VirtualAddress, void *TrapInformation)
{
  int v4; // esi
  signed int v5; // eax
  void *v6; // ecx
  unsigned int PteProtectionMask; // [esp+8h] [ebp-Ch]
  int status; // [esp+Ch] [ebp-8h]
  char OldIrql; // [esp+13h] [ebp-1h]

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
  {
    status = -805306362;
LABEL_11:
    if ( TrapInformation )
      DbgPrint(
        a1,
        "MM: page fault touching %p, trap frame %p, eip %p\n",
        VirtualAddress,
        TrapInformation,
        *((_DWORD *)TrapInformation + 15));
    else
      DbgPrint(a1, "MM: page fault touching %p, trap frame %p\n", VirtualAddress, 0);
    return status;
  }
  a1 = (int *)VirtualAddress;
  status = -1073741819;
  if ( (unsigned int)VirtualAddress < 0x10000 || (unsigned int)VirtualAddress > 0x7FFDFFFF )
    goto LABEL_11;
  RtlEnterCriticalSectionAndRegion(&MmAddressSpaceLock);
  OldIrql = KeRaiseIrqlToDpcLevel();
  if ( *(_BYTE *)((((unsigned int)VirtualAddress >> 20) & 0xFFC) - 1070596096) & 1 )
  {
    a1 = (int *)((((unsigned int)VirtualAddress >> 10) & 0x3FFFFC) - 0x40000000);
    v4 = *a1;
    if ( *a1 )
    {
      PteProtectionMask = *a1 & 0x21B;
      v5 = MiDecodePteProtectionMask(PteProtectionMask);
      if ( v5 & 0x100 )
      {
        MiMakePteProtectionMask(v5 & 0xFFFFFEFF, &PteProtectionMask);
        *a1 = PteProtectionMask | v4 & 0xFFFFFDE4;
        __invlpg((void *)((_DWORD)a1 << 10));
        status = -2147483647;
      }
    }
  }
  KfLowerIrql(OldIrql);
  RtlLeaveCriticalSectionAndRegion(v6, (_KEVENT *)&MmAddressSpaceLock);
  if ( status < 0 && status != -2147483647 )
    goto LABEL_11;
  return status;
}