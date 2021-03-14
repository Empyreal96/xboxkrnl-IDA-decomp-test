_MMPTE *__userpurge MmMapIoSpace@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, unsigned int PhysicalAddress, unsigned int NumberOfBytes, unsigned int Protect)
{
  int v6; // edx
  int v7; // ecx
  _MMPTE *result; // eax
  unsigned int v9; // edi
  unsigned int v10; // esi
  _MMPTE *v11; // esi
  _MMPTE *i; // edx
  _MMPTE TempPte; // [esp+4h] [ebp-4h]
  unsigned int PhysicalAddressa; // [esp+10h] [ebp+8h]
  unsigned int PageFrameNumber; // [esp+14h] [ebp+Ch]

  if ( !NumberOfBytes )
    RtlAssert(a1, a2, a3, 0, "NumberOfBytes != 0", "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c", 0x2B3u, 0);
  if ( !MiMakeSystemPteProtectionMask(Protect, &TempPte) )
    return 0;
  v9 = PhysicalAddress;
  if ( Protect == 516 )
  {
    if ( PhysicalAddress >= 0xF8000000 && PhysicalAddress + NumberOfBytes <= 0xFFBFFFFF )
      return (_MMPTE *)v9;
  }
  else if ( Protect == 1028 && PhysicalAddress >= 0xF0000000 && PhysicalAddress + NumberOfBytes <= 0xF7FFFFFF )
  {
ReturnWriteCombinedAddress:
    KeFlushCurrentTbAndInvalidateAllCaches();
    return (_MMPTE *)v9;
  }
  v10 = ((PhysicalAddress & 0xFFF) + NumberOfBytes + 4095) >> 12;
  PhysicalAddressa = PhysicalAddress & 0xFFF;
  result = MiReserveSystemPtes(v6, v7, (int *)v9, (_MMPTE *)v10, &MmSystemPteRange, v10);
  if ( !result )
    return result;
  v11 = &result[v10];
  PageFrameNumber = v9 >> 12;
  for ( i = result; i < v11; ++PageFrameNumber )
  {
    TempPte.Long = (PageFrameNumber << 12) | TempPte.Long & 0xFFF;
    i->Long = TempPte.Long;
    ++i;
  }
  v9 = PhysicalAddressa + ((_DWORD)result << 10);
  if ( Protect & 0x600 )
    goto ReturnWriteCombinedAddress;
  return (_MMPTE *)v9;
}