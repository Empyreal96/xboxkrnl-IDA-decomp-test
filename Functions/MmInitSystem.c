int __usercall MmInitSystem@<eax>(int *a1@<edi>, int a2@<esi>)
{
  unsigned __int64 v2; // rax
  signed int v3; // eax
  signed int *v4; // edx
  unsigned int v5; // eax
  unsigned int *v6; // edx
  unsigned int *v7; // edi
  unsigned int v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int *v16; // [esp-8h] [ebp-10h]
  char MemoryTop; // [esp+7h] [ebp-1h]

  v2 = RDMSR((void *)0x277);
  if ( (_DWORD)v2 != 459014 || HIDWORD(v2) != 459014 )
    RtlAssert(
      SHIDWORD(v2),
      459014,
      a1,
      a2,
      "RDMSR(0x277) == 0x0007010600070106ui64",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mminit.c",
      0xBAu,
      0);
  v16 = a1;
  memset((void *)0xC0300000, 0, 0x800u);
  MEMORY[0xC0300FFC] = 0;
  v3 = -268435221;
  v4 = (signed int *)-1070592256;
  do
  {
    *v4 = v3;
    ++v4;
    v3 += 0x400000;
  }
  while ( (unsigned int)v4 <= 0xC0300F7C );
  v5 = v3 & 0xFE7 | 0xF8000018;
  v6 = (unsigned int *)-1070592128;
  do
  {
    *v6 = v5;
    ++v6;
    v5 += 0x400000;
  }
  while ( (unsigned int)v6 <= 0xC0300FF8 );
  HalReadWritePCISpace(0x400000, (int)v6, 0, 0, 0x87u, &MemoryTop, 1u, 0);
  MmHighestPhysicalPage = ((unsigned __int8)MemoryTop << 12) + 4095;
  if ( ((unsigned int)(unsigned __int8)MemoryTop << 12) + 4095 < 0x4000 )
  {
    MmDeveloperKitPteRange.AvailablePages = &MmAvailablePages;
    MmDeveloperKitPteRange.RemovePageRoutine = (unsigned int (__fastcall *)(_MMPFN_BUSY_TYPE, _MMPTE *))MiRemoveZeroPage;
  }
  if ( KeHasQuickBooted || XboxBootFlags & 1 && (MiCopyShadowROMDataSection(), KeHasQuickBooted) )
    MiReinitializePfnDatabase();
  else
    MiInitializePfnDatabase(4095);
  v7 = (unsigned int *)-1070594048;
  v8 = ((((MmHighestPhysicalPage << 12) - 2147479553) >> 20) & 0xFFC) - 1070596096;
  v9 = 67043431;
  if ( v8 < 0xC0300800 )
    goto LABEL_24;
  do
  {
    *v7 = v9;
    ++v7;
    v9 = ((v9 & 0xFFFFF000) + 4096) ^ v9 & 0xFFF;
  }
  while ( (unsigned int)v7 <= v8 );
  if ( (unsigned int)v7 <= 0xC03008FC )
  {
LABEL_24:
    v10 = ((unsigned int)(-1070593796 - (_DWORD)v7) >> 2) + 1;
    memset(v7, 0, 4 * v10);
    v7 += v10;
  }
  KeFlushCurrentTb();
  InitializePool((int *)v7);
  FscWriteFFsPtes = MiReserveSystemPtes(v11, v12, (int *)v7, (_MMPTE *)0xFFF, &MmSystemPteRange, 8u);
  if ( !FscWriteFFsPtes )
    RtlAssert(v13, v14, v16, a2, "FscWriteFFsPtes != NULL", "d:\\xbox-apr03\\private\\ntos\\mmx\\mminit.c", 0x159u, 0);
  return FscSetCacheSize(v14, v13, 0x10u);
}