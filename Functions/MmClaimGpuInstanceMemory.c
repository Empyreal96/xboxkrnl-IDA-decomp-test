unsigned int __stdcall MmClaimGpuInstanceMemory(unsigned int NumberOfBytes, unsigned int *NumberOfPaddingBytes)
{
  int v2; // esi
  int v3; // edx
  int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edi
  int v7; // ecx
  int v8; // edx
  unsigned int v9; // esi
  unsigned int v10; // ebx
  char *v12; // [esp+8h] [ebp-4h]
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]

  v2 = NumberOfBytes;
  *NumberOfPaddingBytes = 0x10000;
  if ( NumberOfBytes != -1 )
  {
    OldIrql_3 = KeRaiseIrqlToDpcLevel();
    v5 = MmNumberOfInstanceMemoryBytes;
    v6 = (v2 + 4095) & 0xFFFFF000;
    if ( v6 > MmNumberOfInstanceMemoryBytes )
    {
      RtlAssert(
        v3,
        v4,
        (int *)v6,
        v2,
        "NumberOfBytes <= MmNumberOfInstanceMemoryBytes",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        0x529u,
        0);
      v5 = MmNumberOfInstanceMemoryBytes;
    }
    v7 = 4095;
    v8 = (v5 & 0xFFF) != 0;
    v9 = 16368 - v8 - (v5 >> 12);
    v10 = 16368 - ((v6 & 0xFFF) != 0) - (v6 >> 12);
    if ( v9 < v10 )
    {
      v12 = (char *)((16368 - v8 - (v5 >> 12) - 507904) << 12);
      do
      {
        if ( !(*(_BYTE *)(4 * v9 - 2080440320) & 1) )
          RtlAssert(
            v8,
            v7,
            (int *)v6,
            v9,
            "MI_PFN_ELEMENT(PageFrameNumber)->Pte.Hard.Valid != 0",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            0x537u,
            0);
        MiInsertPageInFreeList(v9, 1);
        v7 = (int)(v12 - 0x4000000);
        __invlpg(v12 - 0x4000000);
        --MmAllocatedPagesByUsage[9];
        if ( MmHighestPhysicalPage != 0x3FFF )
        {
          if ( !(*(_BYTE *)(4 * v9 - 2080374784) & 1) )
            RtlAssert(
              v8,
              v7,
              (int *)v6,
              v9,
              "MI_PFN_ELEMENT(MM_64M_PHYSICAL_PAGE + PageFrameNumber)->Pte.Hard.Valid != 0",
              "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
              0x54Fu,
              0);
          MiInsertPageInFreeList(v9 + 0x4000, 1);
          v7 = (int)v12;
          __invlpg(v12);
          --MmAllocatedPagesByUsage[9];
        }
        v12 += 4096;
        ++v9;
      }
      while ( v9 < v10 );
    }
    MmNumberOfInstanceMemoryBytes = v6;
    KfLowerIrql(OldIrql_3);
  }
  return ((MmHighestPhysicalPage - 0x7FFFF) << 12) - *NumberOfPaddingBytes;
}