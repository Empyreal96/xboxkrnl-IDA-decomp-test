_MMPTE *__userpurge MiReserveSystemPtes@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _MMPTE *a4@<esi>, _MMPTERANGE *PteRange, unsigned int NumberOfPtes)
{
  _MMPTERANGE *v6; // ebx
  int v7; // edx
  unsigned int v8; // ecx
  unsigned int v9; // eax
  _MMPTE *i; // edi
  int v11; // ecx
  signed int v12; // eax
  unsigned int v13; // edi
  int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // edx
  _MMPTE *StartingPte; // [esp+0h] [ebp-8h]
  char OldIrql; // [esp+7h] [ebp-1h]
  _MMPTERANGE *PteRangea; // [esp+10h] [ebp+8h]

  if ( !NumberOfPtes )
    RtlAssert(a1, a2, a3, (int)a4, "NumberOfPtes != 0", "d:\\xbox-apr03\\private\\ntos\\mmx\\sysptes.c", 0x6Cu, 0);
  v6 = PteRange;
  OldIrql = KeRaiseIrqlToDpcLevel();
RetryOperation_1:
  v9 = v6->HeadPte.Long;
  for ( i = &v6->HeadPte; ; i = a4 )
  {
    if ( (v9 & 0xFFFFFFFC) == -4 )
    {
      v11 = NumberOfPtes;
      if ( i != (_MMPTE *)v6 )
      {
        v12 = i->Long & 2 ? 1 : i[1].Long >> 2;
        v7 = (int)&i[v12];
        if ( (_MMPTE *)v7 == v6->LastCommittedPte )
          v11 = NumberOfPtes - v12;
      }
      v13 = (v11 + 1023) & 0xFFFFFC00;
      if ( !v13 )
        RtlAssert(v7, v11, 0, (int)a4, "PtesToCommit > 0", "d:\\xbox-apr03\\private\\ntos\\mmx\\sysptes.c", 0xC0u, 0);
      StartingPte = v6->LastCommittedPte;
      if ( (_DWORD)((char *)v6->LastReservedPte - (char *)v6->LastCommittedPte) >> 2 <= v13
        || (v14 = v13 >> 10, *v6->AvailablePages < v13 >> 10) )
      {
        a4 = 0;
        goto ReturnPointerPte;
      }
      if ( v13 )
      {
        PteRangea = (_MMPTERANGE *)(((v13 - 1) >> 10) + 1);
        do
        {
          a4 = (_MMPTE *)((((_DWORD)v6->LastCommittedPte >> 10) & 0x3FFFFC) - 0x40000000);
          a4->Long = (v6->RemovePageRoutine(MmSystemPageTableUsage, a4) << 12) | 0x67;
          v6->LastCommittedPte += 1024;
          PteRangea = (_MMPTERANGE *)((char *)PteRangea - 1);
        }
        while ( PteRangea );
      }
      MiReleaseSystemPtes(v7, v14, (int *)v13, v6, StartingPte, v13);
      goto RetryOperation_1;
    }
    a4 = (_MMPTE *)(i->Long & 0xFFFFFFFC);
    if ( i != (_MMPTE *)v6 && a4 <= i )
      RtlAssert(
        v7,
        v8,
        (int *)i,
        (int)a4,
        "PointerPte > LastPointerPte",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\sysptes.c",
        0x80u,
        0);
    v9 = a4->Long;
    if ( a4->Long & 2 )
    {
      if ( NumberOfPtes == 1 )
        goto LABEL_31;
      continue;
    }
    v8 = a4[1].Long >> 2;
    if ( v8 == NumberOfPtes )
    {
      if ( NumberOfPtes == 1 )
        RtlAssert(
          v7,
          v8,
          (int *)i,
          (int)a4,
          "NumberOfPtes != 1",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\sysptes.c",
          0x91u,
          0);
LABEL_31:
      i->Long = a4->Long ^ (i->Long ^ a4->Long) & 3;
      goto ReturnPointerPte;
    }
    if ( v8 > NumberOfPtes )
      break;
  }
  v15 = (a4[1].Long >> 2) - NumberOfPtes;
  v16 = NumberOfPtes;
  if ( v15 <= 1 )
  {
    a4[v16].Long |= 2u;
  }
  else
  {
    v17 = a4[v16 + 1].Long;
    a4[v16].Long &= 0xFFFFFFFD;
    a4[v16 + 1].Long = 4 * v15 | v17 & 3;
  }
  a4[v16].Long = a4->Long ^ (a4[v16].Long ^ a4->Long) & 3;
  i->Long = ((unsigned __int8)i->Long ^ (unsigned __int8)(v16 * 4)) & 3 ^ (v16 * 4 + (i->Long & 0xFFFFFFFC));
ReturnPointerPte:
  KfLowerIrql(OldIrql);
  return a4;
}