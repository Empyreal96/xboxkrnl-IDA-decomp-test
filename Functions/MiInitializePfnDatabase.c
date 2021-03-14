void __usercall MiInitializePfnDatabase(int a1@<esi>)
{
  int v1; // edx
  int v2; // ecx
  int v3; // edx
  int v4; // ecx
  _IMAGE_NT_HEADERS *v5; // esi
  int *v6; // edi
  int v7; // esi
  int v8; // edx
  int v9; // ecx
  unsigned int v10; // edi
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  int v18; // edx
  unsigned int i; // eax
  int v20; // ecx
  int v21; // esi
  unsigned int v22; // ecx
  unsigned int v23; // eax
  unsigned int j; // eax
  signed int v25; // ecx
  int *v26; // eax
  int v27; // edx
  unsigned int *v28; // esi
  _IMAGE_NT_HEADERS *NtHeader; // [esp+Ch] [ebp-Ch]
  unsigned int v30; // [esp+10h] [ebp-8h]
  char OldIrql; // [esp+17h] [ebp-1h]

  OldIrql = KeRaiseIrqlToDpcLevel();
  if ( MmHighestPhysicalPage >= 0x10000 )
    RtlAssert(
      v1,
      v2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      a1,
      "MM_HIGHEST_PHYSICAL_PAGE < MM_PAGES_IN_PHYSICAL_MAP",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0xC0u,
      0);
  v5 = RtlImageNtHeader(osfile);
  NtHeader = v5;
  if ( !v5 )
    RtlAssert(
      v3,
      v4,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0,
      "NtHeader != NULL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0xC8u,
      0);
  if ( v5->FileHeader.NumberOfSections <= 0u )
    RtlAssert(
      v3,
      v4,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      (int)v5,
      "NtHeader->FileHeader.NumberOfSections > 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0xC9u,
      0);
  v6 = (int *)((v5->OptionalHeader.SizeOfImage + 4095) & 0xFFFFF000);
  v7 = ((4 * MmHighestPhysicalPage + 4) >> 12) + (((4 * MmHighestPhysicalPage + 4) & 0xFFF) != 0);
  RtlFillMemoryUlong((int *)0x83FF0000, v7 << 12, 131070);
  MiInsertPhysicalMemoryInFreeList(v8, v9, v6, v7, 0, 0x10u);
  v10 = ((unsigned int)(v6 + 0x4000) >> 12) & 0xFFFF;
  MiInsertPhysicalMemoryInFreeList(v11, v12, (int *)v10, v7, v10, 0x3FE0u);
  v30 = v7 + 16368;
  MiInsertPhysicalMemoryInFreeList(v13, v14, (int *)v10, v30, v30, MmHighestPhysicalPage + 1);
  if ( XboxBootFlags & 1 )
  {
    v16 = (*(_DWORD *)&word_80010028[4] >> 12) & 0xFFFF;
    v17 = v16
        + (((*(_DWORD *)&word_80010028[2] + *(_DWORD *)&word_80010028[8]) & 0xFFF) != 0)
        + ((unsigned int)(*(_DWORD *)&word_80010028[2] + *(_DWORD *)&word_80010028[8]) >> 12);
    while ( v16 < v17 )
    {
      MiRemovePageFromFreeList(v16, v15, (int *)v10);
      *(_DWORD *)(4 * v16 - 2080440320) = (v16 << 12) | 0x461;
      ++MmAllocatedPagesByUsage[9];
      ++v16;
    }
  }
  MiRemovePageFromFreeList(0xFu, v15, (int *)v10);
  MEMORY[0x83FF003C] = 63075;
  ++MmAllocatedPagesByUsage[9];
  for ( i = 16; i < v10; ++i )
  {
    *(_DWORD *)(4 * i - 2080440320) = (i << 12) | 0x463;
    ++MmNumberOfPhysicalPages;
    ++MmAllocatedPagesByUsage[9];
  }
  v20 = NtHeader->FileHeader.SizeOfOptionalHeader;
  v21 = (int)&NtHeader->OptionalHeader + v20;
  if ( *(_DWORD *)v21 != 2019914798 )
    RtlAssert(
      v18,
      v20,
      (int *)v10,
      v21,
      "(*(PULONG)TextSectionHeader->Name) == 'xet.'",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x15Cu,
      0);
  if ( !(*(_BYTE *)(v21 + 36) & 0x20) )
    RtlAssert(
      v18,
      v20,
      (int *)v10,
      v21,
      "(TextSectionHeader->Characteristics & IMAGE_SCN_CNT_CODE) != 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x15Du,
      0);
  v22 = 16;
  v23 = ((unsigned int)(*(_DWORD *)(v21 + 8) + 0x10000) >> 12) & 0xFFFF;
  if ( v23 > 0x10 )
  {
    do
      *(_DWORD *)(4 * v22++ - 2080440320) &= 0xFFFFFFFD;
    while ( v22 < v23 );
  }
  for ( j = 16368; j < v30; ++j )
  {
    *(_DWORD *)(4 * j - 2080440320) = (j << 12) | 0x463;
    ++MmNumberOfPhysicalPages;
    ++MmAllocatedPagesByUsage[9];
  }
  v25 = 16352;
  v26 = (int *)-2080374912;
  do
  {
    v27 = (v25 << 12) | 0x7B;
    *v26 = v27;
    ++MmNumberOfPhysicalPages;
    ++MmAllocatedPagesByUsage[9];
    ++v26;
    ++v25;
  }
  while ( (signed int)v26 < -2080374848 );
  if ( MmHighestPhysicalPage != 0x3FFF )
  {
    v10 = 32736;
    v28 = (unsigned int *)-2080309376;
    do
    {
      MiRemovePageFromFreeList(v10, v27, (int *)v10);
      *v28 = (v10 << 12) | 0x7B;
      ++MmAllocatedPagesByUsage[9];
      ++v28;
      ++v10;
    }
    while ( (signed int)v28 < -2080309312 );
  }
  MiRemovePageFromFreeList(0, v27, (int *)v10);
  MEMORY[0x83FF0000] = 1635;
  ++MmAllocatedPagesByUsage[9];
  KfLowerIrql(OldIrql);
}