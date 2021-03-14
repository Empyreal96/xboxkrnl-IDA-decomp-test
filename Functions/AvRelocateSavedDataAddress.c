void __userpurge AvRelocateSavedDataAddress(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *NewAddress, unsigned int NumberOfBytes)
{
  _DWORD *v6; // eax
  char *v7; // esi
  char *v8; // edi
  unsigned int v9; // ecx
  void *v10; // esi
  int *v11; // edi
  int v12; // edx
  int v13; // edx
  int v14; // ecx
  int v15; // eax
  int v16; // edx
  int v17; // ecx

  if ( !AvpSavedDataAddress )
    RtlAssert(a1, a2, a3, a4, "AvpSavedDataAddress != NULL", "d:\\xbox-apr03\\private\\ntos\\av\\modeset.c", 0x733u, 0);
  v6 = AvpSavedDataAddress;
  v7 = (char *)AvpSavedDataAddress;
  qmemcpy(NewAddress, AvpSavedDataAddress, 4 * (NumberOfBytes >> 2));
  v8 = (char *)NewAddress + 4 * (NumberOfBytes >> 2);
  v9 = NumberOfBytes & 3;
  qmemcpy(v8, &v7[4 * (NumberOfBytes >> 2)], v9);
  v10 = v6;
  v11 = (int *)(v6[1] - MmGetPhysicalAddress(NumberOfBytes, (int *)&v8[v9], v6));
  *((_DWORD *)NewAddress + 1) = (char *)v11 + MmGetPhysicalAddress(v12, v11, NewAddress);
  _mm_sfence();
  v15 = *((_DWORD *)NewAddress + 1);
  MEMORY[0xFD600800] = *((_DWORD *)NewAddress + 1);
  if ( AvpDump )
    DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6293504, v15);
  MEMORY[0xFD600100] = 1;
  if ( AvpDump )
    DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6291712, 1);
  MmPersistContiguousMemory(v13, v14, (int)v10, NewAddress, NumberOfBytes, 1);
  AvpSavedDataAddress = NewAddress;
  while ( !(MEMORY[0xFD600100] & 1) )
    ;
  MmFreeContiguousMemory(v16, v17, (int *)"%08X = %08X\n", v10);
}