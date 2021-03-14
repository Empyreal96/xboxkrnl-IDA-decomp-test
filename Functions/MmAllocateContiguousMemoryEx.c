unsigned int __userpurge MmAllocateContiguousMemoryEx@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, unsigned int NumberOfBytes, unsigned int LowestAcceptableAddress, unsigned int HighestAcceptableAddress, unsigned int Alignment, unsigned int Protect)
{
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // esi
  int v13; // ebx
  int *v14; // edi
  int v15; // edx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  unsigned int v19; // ebx
  unsigned int v20; // eax
  unsigned int v21; // ecx
  int v22; // edx
  unsigned int v23; // edi
  int v24; // esi
  int v25; // eax
  unsigned int v26; // ecx
  int v27; // edx
  int v28; // edi
  int *v29; // esi
  int v30; // eax
  signed int LowestAcceptablePageFrameNumber; // [esp+8h] [ebp-Ch]
  unsigned int PhysicalAperture; // [esp+Ch] [ebp-8h]
  _MMPTE TempPte; // [esp+10h] [ebp-4h]
  KIRQL OldIrql_3; // [esp+1Fh] [ebp+Bh]
  signed int PageFrameNumber; // [esp+20h] [ebp+Ch]
  unsigned int PageFrameNumbera; // [esp+20h] [ebp+Ch]
  unsigned int PageFrameNumberb; // [esp+20h] [ebp+Ch]
  unsigned int EndingPageFrameNumber; // [esp+24h] [ebp+10h]
  unsigned int EndingPageFrameNumbera; // [esp+24h] [ebp+10h]

  if ( !NumberOfBytes )
    RtlAssert(a1, a2, 0, a3, "NumberOfBytes != 0", "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c", 0xD7u, 0);
  if ( Protect & 0x800 )
  {
    BYTE1(Protect) &= 0xF7u;
    PhysicalAperture = 0x40000;
  }
  else
  {
    PhysicalAperture = 0;
  }
  if ( !MiMakeSystemPteProtectionMask(Protect, &TempPte) )
    return 0;
  v9 = HighestAcceptableAddress >> 12;
  v10 = LowestAcceptableAddress >> 12;
  LowestAcceptablePageFrameNumber = LowestAcceptableAddress >> 12;
  PageFrameNumber = HighestAcceptableAddress >> 12;
  if ( HighestAcceptableAddress >> 12 > 0x3FDF )
  {
    PageFrameNumber = 16351;
    v9 = 16351;
  }
  if ( v10 > v9 )
    LowestAcceptablePageFrameNumber = v9;
  if ( (Alignment - 1) & Alignment )
    RtlAssert(
      16351,
      v10,
      (int *)NumberOfBytes,
      Alignment,
      "(Alignment & (Alignment - 1)) == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
      0x104u,
      0);
  v11 = Alignment >> 12;
  if ( !(Alignment >> 12) )
    v11 = 1;
  v12 = (NumberOfBytes >> 12) + ((NumberOfBytes & 0xFFF) != 0);
  EndingPageFrameNumber = v11 - 1;
  v13 = ~(v11 - 1);
  v14 = (int *)((v13 & (v12 + v11 - 1)) - v12 + 1);
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  if ( MmAvailablePages >= v12 )
  {
    PageFrameNumbera = PageFrameNumber + 1;
InvalidCandidatePageFound:
    v16 = (v13 & PageFrameNumbera) - (_DWORD)v14;
    PageFrameNumbera = (v13 & PageFrameNumbera) - (_DWORD)v14;
    v17 = 0;
    while ( v16 >= LowestAcceptablePageFrameNumber )
    {
      v18 = *(_DWORD *)(4 * v16 - 2080440320);
      if ( v18 & 1 || v18 & 0x10000 && (_WORD)v18 )
        goto InvalidCandidatePageFound;
      if ( ++v17 >= v12 )
      {
        v19 = PageFrameNumbera;
        if ( PageFrameNumbera & EndingPageFrameNumber )
          RtlAssert(
            v15,
            v17,
            v14,
            v12,
            "(PageFrameNumber & (PfnAlignment - 1)) == 0",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            0x15Fu,
            0);
        v20 = PageFrameNumbera + v12 - 1;
        v21 = PageFrameNumbera;
        EndingPageFrameNumbera = PageFrameNumbera + v12 - 1;
        if ( PageFrameNumbera <= v20 )
        {
          v22 = PhysicalAperture;
          v23 = (PageFrameNumbera + PhysicalAperture) << 12;
          do
          {
            v24 = 4 * v21 - 2080440320;
            if ( !(*(_BYTE *)(v24 + 2) & 1) )
            {
              MiRemovePageFromFreeList(v21, v22, (int *)v23);
              v25 = v23 ^ (LOWORD(TempPte.Long) ^ (unsigned __int16)v23) & 0xFFF;
              TempPte.Long = v25;
              *(_DWORD *)v24 = v25;
              ++MmAllocatedPagesByUsage[9];
              v20 = EndingPageFrameNumbera;
            }
            v21 = PageFrameNumbera + 1;
            v23 += 4096;
            ++PageFrameNumbera;
          }
          while ( PageFrameNumbera <= v20 );
        }
        v26 = v19;
        PageFrameNumberb = v19;
        if ( v19 <= v20 )
        {
          v27 = PhysicalAperture;
          v28 = (v19 + PhysicalAperture) << 12;
          do
          {
            v29 = (int *)(4 * v26 - 2080440320);
            if ( !(*(_BYTE *)v29 & 1) )
            {
              MiRelocateBusyPage(v26, v27);
              v30 = v28 ^ (LOWORD(TempPte.Long) ^ (unsigned __int16)v28) & 0xFFF;
              TempPte.Long = v30;
              *v29 = v30;
              ++MmAllocatedPagesByUsage[9];
              v20 = EndingPageFrameNumbera;
            }
            v26 = PageFrameNumberb + 1;
            v28 += 4096;
            ++PageFrameNumberb;
          }
          while ( PageFrameNumberb <= v20 );
        }
        *(_BYTE *)(4 * v20 - 2080440320 + 1) |= 2u;
        if ( Protect & 0x600 )
          KeFlushCurrentTbAndInvalidateAllCaches();
        KfLowerIrql(OldIrql_3);
        return (v19 - 0x80000) << 12;
      }
      v16 = --PageFrameNumbera;
    }
  }
  KfLowerIrql(OldIrql_3);
  return 0;
}