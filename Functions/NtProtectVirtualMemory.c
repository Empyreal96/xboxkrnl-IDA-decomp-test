int __userpurge NtProtectVirtualMemory@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void **BaseAddress, unsigned int *RegionSize, unsigned int NewProtect, unsigned int *OldProtect)
{
  signed int v9; // edi
  unsigned int v10; // esi
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // edi
  _MMADDRESS_NODE *v14; // eax
  signed int v15; // ecx
  unsigned int v16; // edi
  unsigned int v17; // ebx
  unsigned int v18; // eax
  char v19; // al
  unsigned int v20; // edx
  signed int v21; // esi
  int v22; // eax
  void *v23; // ecx
  unsigned int StartingAddress; // [esp+0h] [ebp-14h]
  unsigned int OldPteProtectionMask; // [esp+8h] [ebp-Ch]
  unsigned int PteProtectionMask; // [esp+Ch] [ebp-8h]
  char OldIrql; // [esp+13h] [ebp-1h]

  if ( (_BYTE)dword_8004C5D0 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == PASSIVE_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\virtual.c",
      0x5AEu,
      0);
  if ( !MiMakePteProtectionMask(NewProtect, &PteProtectionMask) )
    return -1073741755;
  v9 = (signed int)*BaseAddress;
  v10 = *RegionSize;
  if ( (unsigned int)*BaseAddress > 0x7FFEFFFF || 2147418111 - v9 < v10 || !v10 )
    return -1073741811;
  RtlEnterCriticalSectionAndRegion(&MmAddressSpaceLock);
  v11 = (v10 + v9 - 1) | 0xFFF;
  v12 = v9 & 0xFFFFF000;
  StartingAddress = v12;
  v13 = v12 >> 12;
  v14 = MiCheckForConflictingNode(v13, v11 >> 12, MmVadRoot);
  if ( !v14 || v13 < v14->StartingVpn || v11 >> 12 > v14->EndingVpn )
  {
    v21 = -1073741800;
ErrorReturn:
    RtlLeaveCriticalSectionAndRegion((void *)v15, (_KEVENT *)&MmAddressSpaceLock);
    return v21;
  }
  v15 = 4194300;
  v16 = ((StartingAddress >> 10) & 0x3FFFFC) - 0x40000000;
  v17 = ((v11 >> 10) & 0x3FFFFC) - 0x40000000;
  v18 = ((StartingAddress >> 10) & 0x3FFFFC) - 0x40000000;
  if ( v16 <= v17 )
  {
    while ( (v18 != v16 && v18 & 0xFFF || *(_BYTE *)((v15 & (v18 >> 10)) - 0x40000000) & 1) && *(_DWORD *)v18 )
    {
      v18 += 4;
      if ( v18 > v17 )
        goto LABEL_18;
    }
    v21 = -1073741779;
    goto ErrorReturn;
  }
LABEL_18:
  v19 = KeRaiseIrqlToDpcLevel();
  v20 = PteProtectionMask;
  OldIrql = v19;
  OldPteProtectionMask = PteProtectionMask;
  while ( v16 <= v17 )
  {
    v22 = *(_DWORD *)v16;
    if ( *(_DWORD *)v16 && (v22 & 0x21B) != v20 )
    {
      if ( OldPteProtectionMask == v20 )
        OldPteProtectionMask = v22 & 0x21B;
      *(_DWORD *)v16 = v20 | v22 & 0xFFFFFDE4;
      __invlpg((void *)(v16 << 10));
      v20 = PteProtectionMask;
    }
    v16 += 4;
  }
  if ( NewProtect & 0x600 )
    KeFlushCurrentTbAndInvalidateAllCaches();
  KfLowerIrql(OldIrql);
  RtlLeaveCriticalSectionAndRegion(v23, (_KEVENT *)&MmAddressSpaceLock);
  *RegionSize = v11 - StartingAddress + 1;
  *BaseAddress = (void *)StartingAddress;
  *OldProtect = MiDecodePteProtectionMask(OldPteProtectionMask);
  return 0;
}