void __userpurge MmPersistContiguousMemory(int a1@<edx>, int a2@<ecx>, int a3@<esi>, void *BaseAddress, unsigned int NumberOfBytes, char Persist)
{
  unsigned int v6; // edi
  KIRQL v7; // al
  int v8; // edx
  int v9; // ecx
  int *v10; // esi
  int *i; // edi
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]

  v6 = (unsigned int)BaseAddress;
  if ( (unsigned int)BaseAddress + 2147483648 > 0xFFFFFFF )
    RtlAssert(
      a1,
      a2,
      (int *)BaseAddress,
      a3,
      "MI_IS_PHYSICAL_ADDRESS(BaseAddress)",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
      0x275u,
      0);
  if ( !NumberOfBytes )
    RtlAssert(
      a1,
      a2,
      (int *)BaseAddress,
      a3,
      "NumberOfBytes != 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
      0x276u,
      0);
  v7 = KeRaiseIrqlToDpcLevel();
  v9 = 4194300;
  OldIrql_3 = v7;
  v10 = (int *)(((v6 >> 10) & 0x3FFFFC) - 0x40000000);
  for ( i = (int *)((((v6 + NumberOfBytes - 1) >> 10) & 0x3FFFFC) - 0x40000000); v10 <= i; ++v10 )
  {
    if ( !(*(_BYTE *)v10 & 1) )
      RtlAssert(
        v8,
        v9,
        i,
        (int)v10,
        "PointerPte->Hard.Valid != 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        0x280u,
        0);
    *v10 = ((Persist != 0) << 10) | *v10 & 0xFFFFFBFF;
  }
  KfLowerIrql(OldIrql_3);
}