unsigned __int32 __stdcall MmDiscardInitSection()
{
  int v0; // edx
  int v1; // ecx
  _IMAGE_NT_HEADERS *v2; // esi
  int v3; // ecx
  int v4; // esi
  unsigned int v5; // ecx
  void *v6; // edx
  unsigned int v7; // eax
  unsigned int v8; // esi
  int *v9; // edi
  int v10; // edx
  int v11; // ecx
  int *v13; // [esp+0h] [ebp-14h]
  int v14; // [esp+4h] [ebp-10h]
  char OldIrql; // [esp+13h] [ebp-1h]

  v2 = RtlImageNtHeader(osfile);
  if ( !v2 )
    RtlAssert(
      v0,
      v1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\mminit.c",
      0,
      "NtHeader != NULL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mminit.c",
      0x18Cu,
      0);
  if ( v2->FileHeader.NumberOfSections <= 0u )
    RtlAssert(
      v0,
      v1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\mminit.c",
      (int)v2,
      "NtHeader->FileHeader.NumberOfSections > 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mminit.c",
      0x18Du,
      0);
  v3 = (int)v2 + v2->FileHeader.SizeOfOptionalHeader;
  v4 = v3 + 40 * v2->FileHeader.NumberOfSections - 16;
  if ( *(_DWORD *)v4 != 1414090313 )
    RtlAssert(
      v0,
      v3,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\mminit.c",
      v4,
      "(*(PULONG)InitSectionHeader->Name) == 'TINI'",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mminit.c",
      0x197u,
      0);
  if ( !(*(_BYTE *)(v4 + 39) & 2) )
    RtlAssert(
      v0,
      v3,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\mminit.c",
      v4,
      "(InitSectionHeader->Characteristics & IMAGE_SCN_MEM_DISCARDABLE) != 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mminit.c",
      0x198u,
      0);
  v5 = *(_DWORD *)(v4 + 16);
  v6 = (void *)(*(_DWORD *)(v4 + 12) - 2147418112);
  memset(v6, 0xCCu, v5);
  v7 = ((unsigned int)v6 + 4095) & 0xFFFFF000;
  v8 = ((unsigned int)v6 + v5 + 4095) & 0xFFFFF000;
  v9 = (int *)((v7 >> 12) & 0xFFFF);
  MmTopOfKernelPhysicalAddress = MmGetPhysicalAddress((v8 >> 12) & 0xFFFF, v9, (void *)v7);
  OldIrql = KeRaiseIrqlToDpcLevel();
  while ( (unsigned int)v9 < ((v8 >> 12) & 0xFFFF) )
  {
    --MmAllocatedPagesByUsage[9];
    MiInsertPageInFreeList((unsigned int)v9, 0);
    v9 = (int *)((char *)v9 + 1);
  }
  KfLowerIrql(OldIrql);
  if ( v8 != ((RtlImageNtHeader(osfile)->OptionalHeader.SizeOfImage + 4095) & 0xFFFFF000) - 2147418112 )
    RtlAssert(
      v10,
      v11,
      v13,
      v14,
      "EndingVirtualAddress == (PUCHAR)PsNtosImageBase + ROUND_TO_PAGES(RtlImageNtHeader(PsNtosImageBase)->OptionalHeader.SizeOfImage)",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mminit.c",
      0x1C5u,
      0);
  return KeFlushCurrentTb();
}