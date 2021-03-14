void __stdcall ExFreePool(void *P)
{
  char *v1; // ebx
  unsigned int v2; // esi
  char *v3; // eax
  KIRQL v4; // al
  int v5; // eax
  int v6; // edi
  unsigned __int8 *v7; // esi
  char v8; // al
  unsigned int v9; // eax
  int v10; // ecx
  KIRQL v11; // al
  unsigned __int8 v12; // cl
  int v13; // eax
  unsigned __int8 v14; // cl
  int v15; // ecx
  _DWORD *v16; // edx
  unsigned int v17; // ST20_4
  unsigned int v18; // edi
  _DWORD *v19; // edi
  unsigned int v20; // edx
  _DWORD *v21; // edx
  _DWORD *v22; // edi
  int v23; // ecx
  unsigned int v24; // ecx
  int v25; // edx
  int v26; // ecx
  unsigned __int8 v27; // bl
  int v28; // ecx
  int v29; // edx
  unsigned int v30; // edx
  int v31; // ebx
  unsigned int v32; // edx
  int v33; // ebx
  unsigned int v34; // [esp-10h] [ebp-24h]
  unsigned int v35; // [esp-10h] [ebp-24h]
  char *v36; // [esp-Ch] [ebp-20h]
  unsigned int v37; // [esp-Ch] [ebp-20h]
  char *v38; // [esp-8h] [ebp-1Ch]
  signed int v39; // [esp-8h] [ebp-1Ch]
  void *v40; // [esp-4h] [ebp-18h]
  int v41; // [esp-4h] [ebp-18h]
  unsigned int _EX_Flink; // [esp+Ch] [ebp-8h]
  unsigned int Combined; // [esp+10h] [ebp-4h]
  unsigned int Combineda; // [esp+10h] [ebp-4h]
  KIRQL LockHandle_3; // [esp+1Fh] [ebp+Bh]

  v1 = (char *)P;
  v2 = 0;
  if ( !((unsigned __int16)P & 0xFFF) )
  {
    if ( (unsigned __int8)dword_8004C5D0 > 2u )
    {
      v40 = P;
      v38 = 0;
      v3 = (char *)(unsigned __int8)dword_8004C5D0;
LABEL_4:
      v36 = v3;
      v34 = 9;
      goto LABEL_5;
    }
    if ( PoolTrackTable )
      v2 = ExpFindAndRemoveTagBigPages(P);
    v4 = KeRaiseIrqlToDpcLevel();
    ++NonPagedPoolDescriptor.RunningDeAllocs;
    LockHandle_3 = v4;
    v5 = MmFreePoolPages(v1);
    v6 = v5;
    if ( PoolTrackTable )
      ExpRemovePoolTracker(v2, v5 << 12);
    KeCheckForTimer(v1, v6 << 12);
    NonPagedPoolDescriptor.TotalBigPages -= v6;
    goto LABEL_79;
  }
  v7 = (unsigned __int8 *)P - 8;
  v8 = *((char *)P - 6);
  if ( !(v8 & 3) )
  {
    v40 = *(void **)v7;
    v38 = (char *)P - 8;
    v36 = (char *)883;
    v34 = 6;
    goto LABEL_5;
  }
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
  {
    v40 = P;
    v38 = 0;
    v3 = (char *)(unsigned __int8)dword_8004C5D0;
    goto LABEL_4;
  }
  if ( v7[1] != -128 )
  {
    v40 = P;
    v38 = (char *)P - 8;
    v36 = (char *)888;
    v34 = 7;
    goto LABEL_5;
  }
  v7[1] = 0;
  if ( !v8 )
  {
    v40 = 0;
    v38 = *(char **)v7;
    v36 = (char *)P - 8;
    v34 = 1;
LABEL_5:
    KeBugCheckEx(0xC2u, v34, (unsigned int)v36, (unsigned int)v38, (unsigned int)v40);
  }
  KeCheckForTimer((char *)P - 8, 32 * v7[3]);
  if ( PoolTrackTable )
    ExpRemovePoolTracker(*((_DWORD *)v7 + 1), 32 * v7[3]);
  v9 = v7[3];
  if ( v9 <= 8 )
  {
    v10 = 24 * v9 - 2147170264;
    if ( *(_WORD *)(v10 + 4) < *(_WORD *)(v10 + 8) )
    {
      InterlockedPushEntrySList((PSLIST_HEADER)v10, (PSINGLE_LIST_ENTRY)P);
      return;
    }
  }
  v11 = KeRaiseIrqlToDpcLevel();
  v12 = *v7;
  LockHandle_3 = v11;
  if ( *v7 && (v13 = (int)&v7[-32 * v12], *(_BYTE *)(v13 + 3) != v12)
    || (v14 = v7[3], v13 = (int)&v7[32 * v14], v13 & 0xFFF) && *(_BYTE *)v13 != v14 )
  {
    v41 = (int)(v1 - 8);
    v39 = 944;
    v37 = v13;
    ExpPoolBugCheckLine = 944;
    v35 = 5;
    goto LABEL_87;
  }
  ++NonPagedPoolDescriptor.RunningDeAllocs;
  Combined = 0;
  v15 = (int)&v7[32 * v7[3]];
  if ( v15 & 0xFFF && !*(_BYTE *)(v15 + 2) )
  {
    v16 = (_DWORD *)(v15 + 8);
    Combined = 1;
    if ( (*(_DWORD *)((*(_DWORD *)(v15 + 8) & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) != v15 + 8
      || (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v15 + 12) & 0xFFFFFFFE) & 0xFFFFFFFE) != v16 )
    {
      ExpPoolBugCheckLine = 966;
      v23 = *(_DWORD *)(v15 + 12);
      goto LABEL_53;
    }
    v17 = *v16 & 0xFFFFFFFE;
    v18 = *(_DWORD *)(v15 + 12) & 0xFFFFFFFE;
    *(_DWORD *)v18 = v17 | 1;
    *(_DWORD *)(v17 + 4) = v18 | 1;
    if ( (*(_DWORD *)((*(_DWORD *)(*v16 & 0xFFFFFFFE) & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) != (*v16 & 0xFFFFFFFE)
      || (*v16 ^ *(_DWORD *)(*(_DWORD *)((*v16 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE)) & 0xFFFFFFFE )
    {
      ExpPoolBugCheckLine = 968;
      v24 = *v16 & 0xFFFFFFFE;
      v25 = *(_DWORD *)(v24 + 4);
      goto LABEL_85;
    }
    if ( (*(_DWORD *)((*(_DWORD *)(*(_DWORD *)(v15 + 12) & 0xFFFFFFFE) & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) != (*(_DWORD *)(v15 + 12) & 0xFFFFFFFE)
      || (*(_DWORD *)(v15 + 12) ^ *(_DWORD *)(*(_DWORD *)((*(_DWORD *)(v15 + 12) & 0xFFFFFFFE) + 4) & 0xFFFFFFFE)) & 0xFFFFFFFE )
    {
      ExpPoolBugCheckLine = 969;
LABEL_52:
      v16 = (_DWORD *)(*(_DWORD *)(v15 + 12) & 0xFFFFFFFE);
      v23 = v16[1];
LABEL_53:
      v41 = *(_DWORD *)(v23 & 0xFFFFFFFE) & 0xFFFFFFFE;
      v39 = *(_DWORD *)((*v16 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE;
      v37 = (unsigned int)v16;
LABEL_86:
      v35 = 3;
LABEL_87:
      KeBugCheckEx(0x19u, v35, v37, v39, v41);
    }
    v7[3] += *(_BYTE *)(v15 + 3);
  }
  if ( *v7 )
  {
    v15 = (int)&v7[-32 * *v7];
    if ( !*(_BYTE *)(v15 + 2) )
    {
      v19 = (_DWORD *)(v15 + 8);
      _EX_Flink = *(_DWORD *)(v15 + 8) & 0xFFFFFFFE;
      Combined = 1;
      if ( (*(_DWORD *)(_EX_Flink + 4) & 0xFFFFFFFE) != v15 + 8
        || (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v15 + 12) & 0xFFFFFFFE) & 0xFFFFFFFE) != v19 )
      {
        ExpPoolBugCheckLine = 989;
        v26 = *(_DWORD *)(v15 + 12);
LABEL_59:
        v41 = *(_DWORD *)(v26 & 0xFFFFFFFE) & 0xFFFFFFFE;
        v39 = *(_DWORD *)((*v19 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE;
        v37 = (unsigned int)v19;
        goto LABEL_86;
      }
      v20 = *(_DWORD *)(v15 + 12) & 0xFFFFFFFE;
      *(_DWORD *)v20 = _EX_Flink | 1;
      *(_DWORD *)(_EX_Flink + 4) = v20 | 1;
      v21 = (_DWORD *)(*v19 & 0xFFFFFFFE);
      if ( (_DWORD *)(*(_DWORD *)((*v21 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) == v21
        && (_DWORD *)(*(_DWORD *)(*(_DWORD *)((*v19 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) & 0xFFFFFFFE) == v21 )
      {
        v22 = (_DWORD *)(*(_DWORD *)(v15 + 12) & 0xFFFFFFFE);
        if ( (_DWORD *)(*(_DWORD *)((*v22 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) == v22
          && (_DWORD *)(*(_DWORD *)(*(_DWORD *)((*(_DWORD *)(v15 + 12) & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) & 0xFFFFFFFE) == v22 )
        {
          *(_BYTE *)(v15 + 3) += v7[3];
          v7 = (unsigned __int8 *)v15;
          goto LABEL_48;
        }
        ExpPoolBugCheckLine = 992;
        goto LABEL_52;
      }
      ExpPoolBugCheckLine = 991;
      v24 = *v19 & 0xFFFFFFFE;
      v25 = *(_DWORD *)(v24 + 4);
LABEL_85:
      v41 = *(_DWORD *)(v25 & 0xFFFFFFFE) & 0xFFFFFFFE;
      v39 = *(_DWORD *)((*(_DWORD *)v24 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE;
      v37 = v24;
      goto LABEL_86;
    }
  }
LABEL_48:
  if ( (unsigned __int16)v7 & 0xFFF || (unsigned int)&v7[32 * v7[3]] & 0xFFF )
  {
    v27 = v7[3];
    v7[2] = 0;
    if ( Combined )
    {
      v28 = (int)&v7[32 * v27];
      if ( v28 & 0xFFF )
        *(_BYTE *)v28 = v27;
      v29 = 8 * v27 - 2147170048;
      v24 = v29 + 8;
      Combineda = 8 * v27 - 2147170048;
      if ( (*(_DWORD *)((*(_DWORD *)(v29 + 8) & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) != v29 + 8
        || (*(_DWORD *)(*(_DWORD *)(v29 + 12) & 0xFFFFFFFE) & 0xFFFFFFFE) != v24 )
      {
        ExpPoolBugCheckLine = 1043;
        goto LABEL_84;
      }
      v30 = *(_DWORD *)(v29 + 12) & 0xFFFFFFFE;
      v19 = v7 + 8;
      *((_DWORD *)v7 + 2) = v24 | 1;
      *((_DWORD *)v7 + 3) = v30 | 1;
      v31 = (unsigned int)(v7 + 8) | 1;
      *(_DWORD *)v30 = v31;
      *(_DWORD *)(v24 + 4) = v31;
      if ( (*(_DWORD *)((*(_DWORD *)v24 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) == v24
        && (*(_DWORD *)(*(_DWORD *)(Combineda + 12) & 0xFFFFFFFE) & 0xFFFFFFFE) == v24 )
      {
        if ( (_DWORD *)(*(_DWORD *)((*v19 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) == v19
          && (_DWORD *)(*(_DWORD *)(*((_DWORD *)v7 + 3) & 0xFFFFFFFE) & 0xFFFFFFFE) == v19 )
        {
          goto LABEL_79;
        }
        ExpPoolBugCheckLine = 1046;
        goto LABEL_81;
      }
      ExpPoolBugCheckLine = 1045;
    }
    else
    {
      v29 = 8 * v27 - 2147170048;
      v24 = v29 + 8;
      Combineda = 8 * v27 - 2147170048;
      if ( (*(_DWORD *)((*(_DWORD *)(v29 + 8) & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) != v29 + 8
        || (*(_DWORD *)(*(_DWORD *)(v29 + 12) & 0xFFFFFFFE) & 0xFFFFFFFE) != v24 )
      {
        ExpPoolBugCheckLine = 1050;
        goto LABEL_84;
      }
      v32 = *(_DWORD *)v24 & 0xFFFFFFFE;
      v19 = v7 + 8;
      *((_DWORD *)v7 + 2) = v32 | 1;
      *((_DWORD *)v7 + 3) = v24 | 1;
      v33 = (unsigned int)(v7 + 8) | 1;
      *(_DWORD *)(v32 + 4) = v33;
      *(_DWORD *)v24 = v33;
      if ( (*(_DWORD *)((v33 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) == v24
        && (*(_DWORD *)(*(_DWORD *)(Combineda + 12) & 0xFFFFFFFE) & 0xFFFFFFFE) == v24 )
      {
        if ( (_DWORD *)(*(_DWORD *)((*v19 & 0xFFFFFFFE) + 4) & 0xFFFFFFFE) == v19
          && (_DWORD *)(*(_DWORD *)(*((_DWORD *)v7 + 3) & 0xFFFFFFFE) & 0xFFFFFFFE) == v19 )
        {
          goto LABEL_79;
        }
        ExpPoolBugCheckLine = 1053;
LABEL_81:
        v26 = *((_DWORD *)v7 + 3);
        goto LABEL_59;
      }
      ExpPoolBugCheckLine = 1052;
    }
    v29 = Combineda;
LABEL_84:
    v25 = *(_DWORD *)(v29 + 12);
    goto LABEL_85;
  }
  MmFreePoolPages(v7);
  --NonPagedPoolDescriptor.TotalPages;
LABEL_79:
  KfLowerIrql(LockHandle_3);
}