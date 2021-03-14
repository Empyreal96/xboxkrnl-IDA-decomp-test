void __userpurge MmSetAddressProtect(int a1@<edx>, int a2@<ecx>, int a3@<esi>, void *BaseAddress, unsigned int NumberOfBytes, unsigned int NewProtect)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  KIRQL v8; // al
  int v9; // edx
  int v10; // ecx
  unsigned int v11; // esi
  int *v12; // edi
  int v13; // ebx
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]

  v6 = (unsigned int)BaseAddress;
  if ( (unsigned int)BaseAddress + 2147483648 > 0xFFFFFFF && (unsigned int)BaseAddress + 805306368 > 0x1FFFFFFF )
    RtlAssert(
      a1,
      a2,
      (int *)BaseAddress,
      a3,
      "MI_IS_PHYSICAL_ADDRESS(BaseAddress) || MI_IS_SYSTEM_PTE_ADDRESS(BaseAddress)",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c",
      0x2F0u,
      0);
  v7 = NumberOfBytes;
  if ( !NumberOfBytes )
    RtlAssert(
      a1,
      a2,
      (int *)BaseAddress,
      a3,
      "NumberOfBytes != 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c",
      0x2F1u,
      (char *)NumberOfBytes);
  if ( MiMakeSystemPteProtectionMask(NewProtect, (_MMPTE *)&NumberOfBytes) )
  {
    v8 = KeRaiseIrqlToDpcLevel();
    v10 = 4194300;
    OldIrql_3 = v8;
    v11 = ((v6 >> 10) & 0x3FFFFC) - 0x40000000;
    v12 = (int *)((((v6 + v7 - 1) >> 10) & 0x3FFFFC) - 0x40000000);
    while ( v11 <= (unsigned int)v12 )
    {
      v13 = *(_DWORD *)v11;
      if ( !(*(_DWORD *)v11 & 1) )
        RtlAssert(
          v9,
          v10,
          v12,
          v11,
          "TempPte.Hard.Valid != 0",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c",
          0x304u,
          0);
      if ( (v13 & 0x1B) != NumberOfBytes )
      {
        *(_DWORD *)v11 = NumberOfBytes | v13 & 0xFFFFFFE4;
        __invlpg((void *)(v11 << 10));
      }
      v11 += 4;
    }
    if ( NewProtect & 0x600 )
      KeFlushCurrentTbAndInvalidateAllCaches();
    KfLowerIrql(OldIrql_3);
  }
}