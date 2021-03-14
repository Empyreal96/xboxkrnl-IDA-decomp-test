int __fastcall MiFreeMappedMemory(int a1, int a2, _MMPTERANGE *PteRange, void *BaseAddress, unsigned int NumberOfBytes)
{
  int v5; // esi
  _MMPTE *v6; // edi
  int v7; // edx
  int v8; // ecx
  _MMPTE *v9; // edi
  _MMPTE *v10; // esi
  unsigned int v11; // ebx
  _MMPTE v12; // eax
  _MMPTE v13; // eax
  int v14; // ebx
  int v15; // esi
  _MMPTE *PointerPte; // [esp+Ch] [ebp-4h]
  KIRQL OldIrql_3; // [esp+1Fh] [ebp+Fh]

  v5 = ((unsigned int)BaseAddress >> 10) & 0x3FFFFC;
  v6 = (_MMPTE *)(v5 - 0x40000000);
  if ( (_MMPTE *)(v5 - 0x40000000) < PteRange->FirstCommittedPte )
    RtlAssert(
      a2,
      a1,
      (int *)v6,
      v5,
      "MiGetPteAddress(BaseAddress) >= PteRange->FirstCommittedPte",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c",
      0x14Au,
      0);
  if ( v6 >= PteRange->LastCommittedPte )
    RtlAssert(
      a2,
      a1,
      (int *)v6,
      v5,
      "MiGetPteAddress(BaseAddress) < PteRange->LastCommittedPte",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c",
      0x14Bu,
      0);
  if ( (unsigned __int16)BaseAddress & 0xFFF )
    RtlAssert(
      a2,
      a1,
      (int *)v6,
      v5,
      "((ULONG_PTR)BaseAddress & (PAGE_SIZE - 1)) == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c",
      0x14Cu,
      0);
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  v9 = (_MMPTE *)(v5 - 0x40000000);
  v10 = (_MMPTE *)(v5 - 0x40000000);
  PointerPte = v10;
  if ( NumberOfBytes )
  {
    v8 = (NumberOfBytes >> 12) + ((NumberOfBytes & 0xFFF) != 0);
    v11 = (unsigned int)&v9[v8 - 1];
    if ( (unsigned int)v9 <= v11 )
    {
      do
      {
        v12.Long = v10->Long;
        if ( v10->Long & 1 )
        {
          v10->Long = 0;
          __invlpg((void *)((_DWORD)PointerPte << 10));
          MiReleasePageOwnership(v12.Long >> 12, v7);
        }
        ++v10;
        PointerPte = v10;
      }
      while ( (unsigned int)v10 <= v11 );
    }
  }
  else
  {
    do
    {
      if ( !(v10->Long & 1) )
        RtlAssert(
          v7,
          v8,
          (int *)v9,
          (int)v10,
          "PointerPte->Hard.Valid != 0",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c",
          0x178u,
          0);
      v13.Long = v10->Long;
      v10->Long = 0;
      v14 = (v13.Long >> 9) & 1;
      __invlpg((void *)((_DWORD)PointerPte << 10));
      MiReleasePageOwnership(v13.Long >> 12, v7);
      ++v10;
      PointerPte = v10;
    }
    while ( !v14 );
  }
  v15 = v10 - v9;
  MiReleaseSystemPtes(v7, v8, (int *)v9, PteRange, v9, v15);
  KfLowerIrql(OldIrql_3);
  return v15;
}