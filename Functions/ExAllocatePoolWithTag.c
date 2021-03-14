int *__userpurge ExAllocatePoolWithTag@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, unsigned int NumberOfBytes, unsigned int Tag)
{
  unsigned int v5; // edi
  KIRQL v6; // al
  KIRQL v7; // bl
  int *result; // eax
  unsigned int v9; // ebx
  int v10; // edi
  PSINGLE_LIST_ENTRY v11; // esi
  int v12; // esi
  KIRQL v13; // al
  unsigned int *v14; // edx
  int *v15; // eax
  _LIST_ENTRY *v16; // ecx
  _LIST_ENTRY *v17; // ebx
  unsigned int v18; // ecx
  int v19; // ecx
  unsigned int v20; // eax
  unsigned int v21; // ecx
  int v22; // ecx
  int v23; // edi
  unsigned __int8 v24; // cl
  unsigned __int8 v25; // cl
  unsigned __int8 v26; // dl
  int v27; // ecx
  int v28; // ecx
  int v29; // edx
  int v30; // ecx
  int v31; // edx
  int v32; // eax
  unsigned __int8 v33; // cl
  bool v34; // zf
  int v35; // eax
  unsigned __int8 v36; // cl
  _DWORD *v37; // edi
  unsigned int v38; // [esp-10h] [ebp-28h]
  unsigned int *v39; // [esp-Ch] [ebp-24h]
  signed int v40; // [esp-8h] [ebp-20h]
  unsigned int v41; // [esp-4h] [ebp-1Ch]
  unsigned int v42; // [esp+10h] [ebp-8h]
  int *v43; // [esp+10h] [ebp-8h]
  char LockHandle; // [esp+17h] [ebp-1h]
  int *_EX_Blink; // [esp+20h] [ebp+8h]
  _LIST_ENTRY *_EX_Blinka; // [esp+20h] [ebp+8h]
  unsigned int _EX_Blinkb; // [esp+20h] [ebp+8h]

  v5 = NumberOfBytes;
  if ( !NumberOfBytes )
    RtlAssert(
      a1,
      a2,
      (int *)NumberOfBytes,
      a3,
      "NumberOfBytes != 0",
      "d:\\xbox-apr03\\private\\ntos\\ex\\pool.c",
      0x1E2u,
      (char *)NumberOfBytes);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    KeBugCheckEx(0xC2u, 8u, (unsigned __int8)dword_8004C5D0, 0, NumberOfBytes);
  if ( NumberOfBytes > 0xFD8 )
  {
    v6 = KeRaiseIrqlToDpcLevel();
    ++NonPagedPoolDescriptor.RunningAllocs;
    v7 = v6;
    _EX_Blink = MmAllocatePoolPages((int *)NumberOfBytes, NumberOfBytes);
    if ( _EX_Blink )
    {
      NonPagedPoolDescriptor.TotalBigPages += (v5 >> 12) + ((v5 & 0xFFF) != 0);
      KfLowerIrql(v7);
      if ( PoolBigPageTable )
      {
        if ( !ExpAddTagForBigPages(_EX_Blink, Tag, (v5 >> 12) + ((v5 & 0xFFF) != 0)) )
          Tag = 541542722;
        ExpInsertPoolTracker(Tag, (v5 + 4095) & 0xFFFFF000);
      }
    }
    else
    {
      KfLowerIrql(v7);
      DbgPrint((int *)v5, "EX: ExAllocatePool (%p) returning NULL\n", v5);
    }
    return _EX_Blink;
  }
  v9 = (NumberOfBytes + 39) >> 5;
  if ( v9 <= 8 )
  {
    v10 = 24 * v9 - 2147170264;
    ++*(_DWORD *)(v10 + 12);
    v11 = InterlockedPopEntrySList((PSLIST_HEADER)v10);
    if ( v11 )
    {
      v12 = (int)&v11[-2];
      ++*(_DWORD *)(v10 + 16);
      *(_BYTE *)(v12 + 2) = 1;
      *(_BYTE *)(v12 + 1) = -128;
      *(_DWORD *)(v12 + 4) = Tag;
      if ( PoolTrackTable )
        ExpInsertPoolTracker(Tag, 32 * *(unsigned __int8 *)(v12 + 3));
      result = (int *)(v12 + 8);
      *(_DWORD *)(v12 + 8) = 0;
      return result;
    }
  }
  v13 = KeRaiseIrqlToDpcLevel();
  ++NonPagedPoolDescriptor.RunningAllocs;
  LockHandle = v13;
  v14 = (unsigned int *)(8 * v9 - 2147170032);
  while ( (unsigned int *)(*v14 & 0xFFFFFFFE) == v14 )
  {
    v14 += 2;
    if ( v14 == &ExpTaggedPoolLock )
    {
      v15 = MmAllocatePoolPages((int *)&NonPagedPoolDescriptor.ListHeads[127], 0x1000u);
      if ( !v15 )
      {
        DbgPrint(
          (int *)&NonPagedPoolDescriptor.ListHeads[127],
          "EX: ExAllocatePool (%p) returning NULL\n",
          NumberOfBytes);
        KfLowerIrql(LockHandle);
        return 0;
      }
      ++NonPagedPoolDescriptor.TotalPages;
      *((_BYTE *)v15 + 2) = 0;
      *((_BYTE *)v15 + 3) = -128;
      *(_BYTE *)v15 = 0;
      v16 = NonPagedPoolDescriptor.ListHeads[127].Flink;
      v42 = (_DWORD)NonPagedPoolDescriptor.ListHeads[127].Flink & 0xFFFFFFFE;
      v17 = NonPagedPoolDescriptor.ListHeads[127].Blink;
      v14 = (unsigned int *)&NonPagedPoolDescriptor.ListHeads[127];
      if ( (_LIST_ENTRY *)(*(_DWORD *)(((_DWORD)NonPagedPoolDescriptor.ListHeads[127].Flink & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) != &NonPagedPoolDescriptor.ListHeads[127] )
        goto LABEL_71;
      if ( (_LIST_ENTRY *)(*(_DWORD *)((_DWORD)NonPagedPoolDescriptor.ListHeads[127].Blink & 0xFFFFFFFE) & 0xFFFFFFFE) != &NonPagedPoolDescriptor.ListHeads[127] )
      {
        v17 = NonPagedPoolDescriptor.ListHeads[127].Blink;
LABEL_71:
        ExpPoolBugCheckLine = 785;
        goto LABEL_72;
      }
      v15[2] = v42 | 1;
      v15[3] = (unsigned int)&NonPagedPoolDescriptor.ListHeads[127] | 1;
      v16 = (_LIST_ENTRY *)((unsigned int)(v15 + 2) | 1);
      *(_DWORD *)(v42 + 4) = v16;
      NonPagedPoolDescriptor.ListHeads[127].Flink = (_LIST_ENTRY *)((unsigned int)(v15 + 2) | 1);
      v17 = NonPagedPoolDescriptor.ListHeads[127].Blink;
      if ( (_LIST_ENTRY *)(*(_DWORD *)(((unsigned int)v16 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) != &NonPagedPoolDescriptor.ListHeads[127] )
        goto LABEL_69;
      if ( (_LIST_ENTRY *)(*(_DWORD *)((_DWORD)NonPagedPoolDescriptor.ListHeads[127].Blink & 0xFFFFFFFE) & 0xFFFFFFFE) != &NonPagedPoolDescriptor.ListHeads[127] )
      {
        v17 = NonPagedPoolDescriptor.ListHeads[127].Blink;
LABEL_69:
        ExpPoolBugCheckLine = 787;
LABEL_72:
        v41 = *(_DWORD *)((unsigned int)v17 & 0xFFFFFFFE) & 0xFFFFFFFE;
        v40 = *(_DWORD *)(((unsigned int)v16 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE;
        v39 = (unsigned int *)&NonPagedPoolDescriptor.ListHeads[127];
LABEL_73:
        v38 = 3;
LABEL_74:
        KeBugCheckEx(0x19u, v38, (unsigned int)v39, v40, v41);
      }
      if ( (int *)(*(_DWORD *)((v15[2] & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) != v15 + 2
        || (int *)(*(_DWORD *)(v15[3] & 0xFFFFFFFE) & 0xFFFFFFFE) != v15 + 2 )
      {
        ExpPoolBugCheckLine = 788;
        v30 = (int)(v15 + 2);
LABEL_51:
        v32 = v15[3];
LABEL_52:
        v41 = *(_DWORD *)(v32 & 0xFFFFFFFE) & 0xFFFFFFFE;
        v40 = *(_DWORD *)((*(_DWORD *)v30 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE;
        v39 = (unsigned int *)v30;
        goto LABEL_73;
      }
      v9 = (NumberOfBytes + 39) >> 5;
    }
  }
  v18 = *v14 & 0xFFFFFFFE;
  _EX_Blinka = (_LIST_ENTRY *)v18;
  v19 = *(_DWORD *)(v18 + 4);
  if ( (unsigned int *)(v19 & 0xFFFFFFFE) != v14
    || (unsigned int *)(*(_DWORD *)(v14[1] & 0xFFFFFFFE) & 0xFFFFFFFE) != v14 )
  {
    ExpPoolBugCheckLine = 625;
    goto LABEL_64;
  }
  v20 = *(_DWORD *)(*v14 & 0xFFFFFFFE) & 0xFFFFFFFE;
  v21 = v19 & 0xFFFFFFFE;
  *(_DWORD *)v21 = v20 | 1;
  v22 = v21 | 1;
  *(_DWORD *)(v20 + 4) = v22;
  if ( (unsigned int *)(*(_DWORD *)((*v14 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) != v14
    || (unsigned int *)(*(_DWORD *)(v14[1] & 0xFFFFFFFE) & 0xFFFFFFFE) != v14 )
  {
    ExpPoolBugCheckLine = 627;
LABEL_64:
    v41 = *(_DWORD *)(v14[1] & 0xFFFFFFFE) & 0xFFFFFFFE;
    v40 = *(_DWORD *)((*v14 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE;
    v39 = v14;
    goto LABEL_73;
  }
  v23 = (int)&_EX_Blinka[-1];
  if ( HIBYTE(_EX_Blinka[-1].Flink) < v9 )
    RtlAssert(
      (int)v14,
      v22,
      (int *)v23,
      -2,
      "Entry->BlockSize >= NeededSize",
      "d:\\xbox-apr03\\private\\ntos\\ex\\pool.c",
      0x276u,
      0);
  if ( *(_BYTE *)(v23 + 2) )
    RtlAssert(
      (int)v14,
      v22,
      (int *)v23,
      -2,
      "Entry->PoolType == 0",
      "d:\\xbox-apr03\\private\\ntos\\ex\\pool.c",
      0x278u,
      0);
  v24 = *(_BYTE *)(v23 + 3);
  if ( v24 != v9 )
  {
    v25 = v24 - v9;
    if ( *(_BYTE *)v23 )
    {
      *(_BYTE *)(v23 + 3) = v25;
      v15 = (int *)&_EX_Blinka[-1];
      v23 += 32 * v25;
      *(_BYTE *)v23 = HIBYTE(_EX_Blinka[-1].Flink);
      v28 = v23 + 32 * v9;
      if ( v28 & 0xFFF )
        *(_BYTE *)v28 = v9;
    }
    else
    {
      v15 = (int *)(v23 + 32 * v9);
      v26 = v25;
      *((_BYTE *)v15 + 3) = v25;
      v27 = (int)&v15[8 * v25];
      *(_BYTE *)v15 = v9;
      if ( v27 & 0xFFF )
        *(_BYTE *)v27 = v26;
    }
    *(_BYTE *)(v23 + 3) = v9;
    v29 = 8 * *((unsigned __int8 *)v15 + 3) - 2147170048;
    v30 = v29 + 8;
    *((_BYTE *)v15 + 2) = 0;
    v43 = (int *)v29;
    if ( (*(_DWORD *)((*(_DWORD *)(v29 + 8) & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) != v29 + 8
      || (*(_DWORD *)(*(_DWORD *)(v29 + 12) & 0xFFFFFFFE) & 0xFFFFFFFE) != v30 )
    {
      ExpPoolBugCheckLine = 702;
      v32 = *(_DWORD *)(v29 + 12);
      goto LABEL_52;
    }
    _EX_Blinkb = *(_DWORD *)(v29 + 12) & 0xFFFFFFFE;
    v15[2] = v30 | 1;
    v31 = (unsigned int)(v15 + 2) | 1;
    v15[3] = _EX_Blinkb | 1;
    *(_DWORD *)_EX_Blinkb = v31;
    *(_DWORD *)(v30 + 4) = v31;
    if ( (*(_DWORD *)((*(_DWORD *)v30 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) != v30
      || (*(_DWORD *)(v43[3] & 0xFFFFFFFE) & 0xFFFFFFFE) != v30 )
    {
      v15 = v43;
      ExpPoolBugCheckLine = 704;
      goto LABEL_51;
    }
    v30 = (int)(v15 + 2);
    if ( (int *)(*(_DWORD *)((v15[2] & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) != v15 + 2
      || (*(_DWORD *)(v15[3] & 0xFFFFFFFE) & 0xFFFFFFFE) != v30 )
    {
      ExpPoolBugCheckLine = 705;
      goto LABEL_51;
    }
  }
  v33 = *(_BYTE *)v23;
  v34 = *(_BYTE *)v23 == 0;
  *(_BYTE *)(v23 + 2) = 1;
  *(_BYTE *)(v23 + 1) = -128;
  if ( !v34 && (v35 = v23 - 32 * v33, *(_BYTE *)(v35 + 3) != v33)
    || (v36 = *(_BYTE *)(v23 + 3), v35 = v23 + 32 * v36, v35 & 0xFFF) && *(_BYTE *)v35 != v36 )
  {
    v41 = v23;
    v40 = 712;
    v39 = (unsigned int *)v35;
    ExpPoolBugCheckLine = 712;
    v38 = 5;
    goto LABEL_74;
  }
  KfLowerIrql(LockHandle);
  *(_DWORD *)(v23 + 4) = Tag;
  if ( PoolTrackTable )
    ExpInsertPoolTracker(Tag, 32 * *(unsigned __int8 *)(v23 + 3));
  v37 = (_DWORD *)(v23 + 8);
  *v37 = 0;
  v37[1] = 0;
  return v37;
}