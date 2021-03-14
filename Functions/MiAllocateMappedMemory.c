void *__userpurge MiAllocateMappedMemory@<eax>(int *a1@<edi>, _MMPTERANGE *PteRange, _MMPFN_BUSY_TYPE BusyType, unsigned int Protect, unsigned int NumberOfBytes, unsigned int (__fastcall *RemovePageRoutine)(_MMPFN_BUSY_TYPE, _MMPTE *), char AddBarrierPage)
{
  int v8; // edx
  int v9; // ecx
  unsigned int v10; // esi
  _MMPTERANGE *v11; // ebx
  int v12; // edx
  int v13; // ecx
  _MMPTE *v14; // edi
  unsigned int v15; // ebx
  unsigned int v16; // esi
  _MMPTE TempPte; // [esp+0h] [ebp-8h]
  char OldIrql; // [esp+7h] [ebp-1h]
  _MMPTE *StartingPte; // [esp+10h] [ebp+8h]
  int NumberOfPtes; // [esp+1Ch] [ebp+14h]

  if ( !MiMakeSystemPteProtectionMask(Protect, &TempPte) )
    return 0;
  OldIrql = KeRaiseIrqlToDpcLevel();
  v10 = (NumberOfBytes >> 12) + ((NumberOfBytes & 0xFFF) != 0);
  if ( !v10 )
    RtlAssert(v8, v9, a1, 0, "NumberOfPages != 0", "d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c", 0xBBu, 0);
  v11 = PteRange;
  if ( *PteRange->AvailablePages < v10 )
  {
    KfLowerIrql(OldIrql);
    return 0;
  }
  NumberOfPtes = (NumberOfBytes >> 12) + ((NumberOfBytes & 0xFFF) != 0);
  if ( AddBarrierPage )
    NumberOfPtes = v10 + 1;
  v14 = MiReserveSystemPtes(v8, v9, a1, (_MMPTE *)v10, PteRange, NumberOfPtes);
  StartingPte = v14;
  if ( !v14 )
    goto LABEL_10;
  if ( *v11->AvailablePages < v10 )
  {
    MiReleaseSystemPtes(v12, v13, (int *)v14, v11, v14, NumberOfPtes);
LABEL_10:
    KfLowerIrql(OldIrql);
    return 0;
  }
  if ( AddBarrierPage )
  {
    v14->Long = 0;
    ++v14;
  }
  v15 = (unsigned int)&v14[v10 - 1];
  if ( (unsigned int)v14 <= v15 )
  {
    LOWORD(v16) = TempPte.Long;
    do
    {
      v16 = v16 & 0xFFF | (RemovePageRoutine(BusyType, v14) << 12);
      v14->Long = v16;
      ++v14;
    }
    while ( (unsigned int)v14 <= v15 );
  }
  *(_BYTE *)(v15 + 1) |= 2u;
  if ( Protect & 0x600 )
    KeFlushCurrentTbAndInvalidateAllCaches();
  KfLowerIrql(OldIrql);
  return (void *)((_DWORD)StartingPte << 10);
}