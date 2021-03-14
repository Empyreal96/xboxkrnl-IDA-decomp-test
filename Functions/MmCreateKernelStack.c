int *__fastcall MmCreateKernelStack(int a1, int a2, unsigned int NumberOfBytes, char DebuggerThread)
{
  _MMPFN_BUSY_TYPE v4; // edx
  _MMPTERANGE *v5; // ecx
  unsigned int (__fastcall *v6)(_MMPFN_BUSY_TYPE, _MMPTE *); // eax
  int *result; // eax
  int *v8; // esi

  if ( !NumberOfBytes )
    RtlAssert(
      a2,
      a1,
      0,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c",
      "NumberOfBytes != 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c",
      0x426u,
      0);
  if ( NumberOfBytes & 0xFFF )
    RtlAssert(
      a2,
      a1,
      (int *)NumberOfBytes,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c",
      "(NumberOfBytes & (PAGE_SIZE - 1)) == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c",
      0x427u,
      0);
  v4 = 1;
  v5 = &MmSystemPteRange;
  v6 = MiRemoveAnyPage;
  if ( DebuggerThread )
  {
    v6 = MmDeveloperKitPteRange.RemovePageRoutine;
    v5 = &MmDeveloperKitPteRange;
    v4 = 10;
  }
  result = (int *)MiAllocateMappedMemory((int *)NumberOfBytes, v5, v4, 4u, NumberOfBytes, v6, 1);
  v8 = result;
  if ( result )
  {
    RtlFillMemoryUlong(result + 1024, NumberOfBytes, 1801548883);
    result = (int *)((char *)v8 + NumberOfBytes + 4096);
  }
  return result;
}