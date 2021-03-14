void *__userpurge MmMapAvTables@<eax>(int *a1@<edi>, unsigned int *SizeOfAVTables)
{
  int v2; // edx
  KIRQL v3; // bl
  unsigned int v4; // ST04_4
  unsigned int v5; // eax
  int v6; // edx
  int v7; // ecx
  void *result; // eax
  KIRQL v9; // al
  unsigned int v10; // ecx

  *SizeOfAVTables = *(_DWORD *)&word_80010028[8];
  if ( XboxBootFlags & 1 )
  {
    v3 = KeRaiseIrqlToDpcLevel();
    if ( !MmShadowAvTablesMapping )
    {
      v4 = *(_DWORD *)&word_80010028[8];
      v5 = MmGetPhysicalAddress(v2, a1, *(void **)&word_80010028[4]);
      MmShadowAvTablesMapping = MmMapIoSpace(v6, v7, a1, *(_DWORD *)&word_80010028[2] + v5, v4, 0x202u);
      if ( !MmShadowAvTablesMapping )
      {
        DbgPrint(a1, "MM: insufficient memory to allocate AV tables mapping\n");
        KeBugCheck(0x1Au);
      }
    }
    KfLowerIrql(v3);
    result = MmShadowAvTablesMapping;
  }
  else
  {
    v9 = KeRaiseIrqlToDpcLevel();
    v10 = MmAvTablesMappingCount++;
    if ( !v10 )
      MEMORY[0xC0300C0C] = -4194053;
    KfLowerIrql(v9);
    result = (void *)(*(_DWORD *)&word_80010028[4] + *(_DWORD *)&word_80010028[2] - 1056964608);
  }
  return result;
}