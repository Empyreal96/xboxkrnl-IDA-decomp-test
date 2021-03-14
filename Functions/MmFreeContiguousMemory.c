void __userpurge MmFreeContiguousMemory(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, void *BaseAddress)
{
  unsigned int v4; // ebx
  int v5; // edx
  int v6; // ecx
  int *v7; // edi
  _BYTE *v8; // esi
  int v9; // esi
  KIRQL OldIrql_3; // [esp+1Bh] [ebp+Bh]

  if ( (unsigned int)BaseAddress + 2147483648 > 0xFFFFFFF )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)BaseAddress,
      "MI_IS_PHYSICAL_ADDRESS(BaseAddress)",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
      0x1EDu,
      0);
  v4 = ((unsigned int)BaseAddress >> 12) & 0xFFFF;
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  v7 = (int *)((v4 - 0x80000) << 12);
  do
  {
    v8 = (_BYTE *)(4 * v4 - 2080440320);
    if ( !(*v8 & 1) )
      RtlAssert(
        v5,
        v6,
        v7,
        (int)v8,
        "PageFrame->Pte.Hard.Valid != 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        0x1FCu,
        0);
    v9 = (*(_DWORD *)v8 >> 9) & 1;
    MiInsertPageInFreeList(v4, 0);
    v6 = (int)v7;
    __invlpg(v7);
    --MmAllocatedPagesByUsage[9];
    ++v4;
    v7 += 1024;
  }
  while ( !v9 );
  KfLowerIrql(OldIrql_3);
}