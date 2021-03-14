void __userpurge MiReleaseSystemPtes(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _MMPTERANGE *PteRange, _MMPTE *StartingPte, unsigned int NumberOfPtes)
{
  _MMPTERANGE *v6; // edi
  unsigned int v7; // esi
  int v8; // edx
  int v9; // ecx
  _MMPTERANGE *v10; // esi
  unsigned int v11; // eax
  _MMPTERANGE *v12; // ebx
  signed int v13; // eax
  bool v14; // zf
  _MMPTE v15; // eax
  signed int v16; // ebx
  signed int v17; // ecx
  unsigned int v18; // eax
  int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // ecx
  _MMPTE *v22; // [esp+Ch] [ebp-4h]
  KIRQL OldIrql_3; // [esp+1Fh] [ebp+Fh]

  if ( !NumberOfPtes )
    RtlAssert(a1, a2, a3, 0, "NumberOfPtes != 0", "d:\\xbox-apr03\\private\\ntos\\mmx\\sysptes.c", 0x10Du, 0);
  v6 = (_MMPTERANGE *)StartingPte;
  if ( StartingPte < PteRange->FirstCommittedPte )
    RtlAssert(
      a1,
      a2,
      (int *)StartingPte,
      NumberOfPtes,
      "StartingPte >= PteRange->FirstCommittedPte",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\sysptes.c",
      0x10Eu,
      0);
  v7 = 4 * NumberOfPtes;
  v22 = &StartingPte[NumberOfPtes];
  if ( v22 > PteRange->LastCommittedPte )
    RtlAssert(
      a1,
      (int)PteRange,
      (int *)StartingPte,
      v7,
      "StartingPte + NumberOfPtes <= PteRange->LastCommittedPte",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\sysptes.c",
      0x10Fu,
      0);
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  RtlFillMemoryUlong((int *)v6, v7, 0);
  v10 = PteRange;
  v11 = PteRange->HeadPte.Long;
  while ( (v11 & 0xFFFFFFFC) != -4 )
  {
    v12 = (_MMPTERANGE *)(v10->HeadPte.Long & 0xFFFFFFFC);
    if ( v10 != PteRange && v12 <= v10 )
      RtlAssert(
        v8,
        v9,
        (int *)v6,
        (int)v10,
        "PointerPte > LastPointerPte",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\sysptes.c",
        0x129u,
        0);
    if ( v12 > v6 )
    {
      v14 = v22 == (_MMPTE *)v12;
      if ( v22 > (_MMPTE *)v12 )
      {
        RtlAssert(
          v8,
          v9,
          (int *)v6,
          (int)v10,
          "PointerPte >= StartingPte + NumberOfPtes",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\sysptes.c",
          0x132u,
          0);
        v14 = v22 == (_MMPTE *)v12;
      }
      if ( v14 )
      {
        v15.Long = v12->HeadPte.Long;
        if ( v12->HeadPte.Long & 2 )
          v16 = 1;
        else
          v16 = (_DWORD)v12->FirstCommittedPte >> 2;
        NumberOfPtes += v16;
        v10->HeadPte.Long = v15.Long ^ (LOBYTE(v15.Long) ^ (unsigned __int8)v10->HeadPte.Long) & 3;
      }
      break;
    }
    if ( v12->HeadPte.Long & 2 )
      v13 = 1;
    else
      v13 = (_DWORD)v12->FirstCommittedPte >> 2;
    if ( (_MMPTERANGE *)((char *)v12 + 4 * v13) > v6 )
      RtlAssert(
        v8,
        v9,
        (int *)v6,
        (int)v10,
        "(PointerPte + (PointerPte->List.OneEntry ? 1 : MI_PTE_LIST_LARGE_BLOCK_SIZE(PointerPte))) <= StartingPte",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\sysptes.c",
        0x148u,
        0);
    v11 = v12->HeadPte.Long;
    v10 = v12;
  }
  v17 = 1;
  if ( NumberOfPtes <= 1 )
  {
    v6->HeadPte.Long |= 2u;
  }
  else
  {
    v18 = (unsigned int)v6->FirstCommittedPte;
    v6->HeadPte.Long &= 0xFFFFFFFD;
    v6->FirstCommittedPte = (_MMPTE *)(4 * NumberOfPtes | v18 & 3);
  }
  v6->HeadPte.Long = v10->HeadPte.Long ^ (v6->HeadPte.Long ^ v10->HeadPte.Long) & 3;
  v19 = (unsigned int)v6 ^ ((unsigned __int8)v6 ^ (unsigned __int8)v10->HeadPte.Long) & 3;
  v10->HeadPte.Long = v19;
  if ( v10 != PteRange )
  {
    if ( !(v19 & 2) )
      v17 = (_DWORD)v10->FirstCommittedPte >> 2;
    if ( (_MMPTERANGE *)((char *)v10 + 4 * v17) == v6 )
    {
      v20 = v19 & 0xFFFFFFFD;
      v10->HeadPte.Long = v20;
      v21 = (_DWORD)v10->FirstCommittedPte & 3 ^ 4 * (NumberOfPtes + v17);
      v10->HeadPte.Long = v6->HeadPte.Long ^ ((unsigned __int8)v20 ^ (unsigned __int8)v6->HeadPte.Long) & 3;
      v10->FirstCommittedPte = (_MMPTE *)v21;
    }
  }
  KfLowerIrql(OldIrql_3);
}