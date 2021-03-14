void __fastcall MiRelocateBusyPage(unsigned int PageFrameNumber, int a2)
{
  unsigned int v2; // ebx
  _MMPFN *v3; // ebx
  unsigned int v4; // eax
  int v5; // edx
  int v6; // esi
  _FSCACHE_ELEMENT *v7; // ecx
  _DWORD *v8; // ebx
  unsigned int v9; // eax
  int v10; // edx
  unsigned int *v11; // ebx
  int *v12; // edi
  int v13; // ecx
  __int16 v14; // ST28_2
  int v15; // ST0C_4
  void *v16; // edi
  _MMPFN *PageFrame; // [esp+Ch] [ebp-14h]
  char FullTlbFlush; // [esp+10h] [ebp-10h]
  _MMPTE TempPte; // [esp+14h] [ebp-Ch]
  _MMPTE TempPtea; // [esp+14h] [ebp-Ch]
  _MMPTE TempPteb; // [esp+14h] [ebp-Ch]
  _MMPTE TempPtec; // [esp+14h] [ebp-Ch]
  unsigned int v23; // [esp+18h] [ebp-8h]
  _MMPTE *PointerPde; // [esp+1Ch] [ebp-4h]
  _MMPTE *PointerPdea; // [esp+1Ch] [ebp-4h]
  _MMPTE *PointerPdeb; // [esp+1Ch] [ebp-4h]
  unsigned int PointerPdec; // [esp+1Ch] [ebp-4h]

  v2 = PageFrameNumber;
  v23 = PageFrameNumber;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x4AFu,
      0);
  v3 = (_MMPFN *)(4 * v2 - 2080440320);
  PageFrame = v3;
  if ( v3->Long & 1 )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0,
      "PageFrame->Pte.Hard.Valid == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x4B3u,
      0);
  if ( !(*((_BYTE *)&v3->Pte.Hard + 2) & 1) )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0,
      "PageFrame->Busy.Busy != 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x4B4u,
      0);
  if ( !(v3->Free.PackedPfnBlink & 0xF000u) )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0,
      "PageFrame->Busy.BusyType != MmUnknownUsage",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x4B5u,
      0);
  if ( v3->Free.PackedPfnFlink )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0,
      "PageFrame->Busy.LockCount == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x4B6u,
      0);
  v4 = v3->Long;
  v5 = v3->Long >> 28;
  v6 = 2;
  v7 = (_FSCACHE_ELEMENT *)(v5 - 2);
  FullTlbFlush = 0;
  if ( v5 == 2 )
  {
    v8 = (_DWORD *)-1070596096;
    while ( !(*v8 & 1) || *v8 >> 12 != v23 )
    {
      ++v8;
      if ( (unsigned int)v8 > 0xC03007FC )
        RtlAssert(
          v5,
          (int)v7,
          (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
          2,
          "PointerPde <= MiGetPdeAddress(MM_HIGHEST_USER_ADDRESS)",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
          0x4D6u,
          0);
    }
    v6 = (int)v8;
    goto LABEL_58;
  }
  v7 = (_FSCACHE_ELEMENT *)((v3->Long >> 28) - 3);
  if ( v3->Long >> 28 == 3 )
  {
    v6 = 4 * ((v4 >> 18) & 0x3FF) - 1070596096;
    if ( !(*(_BYTE *)v6 & 1) )
      RtlAssert(
        v5,
        0,
        (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        v6,
        "PointerPte->Hard.Valid != 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x4E5u,
        0);
    if ( *(_DWORD *)v6 >> 12 != v23 )
      RtlAssert(
        v5,
        (int)v7,
        (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        v6,
        "PointerPte->Hard.PageFrameNumber == PageFrameNumber",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x4E6u,
        0);
LABEL_58:
    FullTlbFlush = 1;
    goto LABEL_59;
  }
  v7 = (_FSCACHE_ELEMENT *)((v3->Long >> 28) - 5);
  if ( v3->Long >> 28 == 5 || (v7 = (_FSCACHE_ELEMENT *)((v3->Long >> 28) - 7), v3->Long >> 28 == 7) )
  {
    PointerPdeb = (_MMPTE *)-1070596096;
    TempPteb.Long = 805306368;
    while ( 1 )
    {
      if ( PointerPdeb->Long & 1 )
      {
        if ( (PointerPdeb->Long & 0x80u) != 0 )
          RtlAssert(
            v5,
            (int)v7,
            (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
            v6,
            "PointerPde->Hard.LargePage == 0",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
            0x504u,
            0);
        v6 = 4 * (TempPteb.Long + ((v3->Long >> 18) & 0x3FF));
        if ( *(_DWORD *)v6 )
        {
          if ( *(_DWORD *)v6 >> 12 == v23 )
            break;
        }
      }
      ++PointerPdeb;
      TempPteb.Long += 1024;
      if ( (unsigned int)PointerPdeb > 0xC03007FC )
        RtlAssert(
          v5,
          (int)v7,
          (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
          v6,
          "PointerPde <= MiGetPdeAddress(MM_HIGHEST_USER_ADDRESS)",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
          0x51Cu,
          0);
    }
  }
  else if ( v3->Long >> 28 == 8 )
  {
    if ( ((v4 >> 17) & 0x7FF) >= FscNumberOfCachePages )
      RtlAssert(
        v5,
        0,
        (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        2047,
        "PageFrame->FsCache.ElementIndex < FscNumberOfCachePages",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x4F2u,
        0);
    v7 = FscElementArray;
    v6 = ((*(_DWORD *)&FscElementArray[(v3->Long >> 17) & 0x7FF].0 >> 10) & 0x3FFFFC) - 0x40000000;
  }
  else
  {
    v7 = (_FSCACHE_ELEMENT *)((v3->Long >> 28) - 10);
    if ( v3->Long >> 28 == 10 )
    {
      if ( MmHighestPhysicalPage >= 0x4000 )
        RtlAssert(
          v5,
          0,
          (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
          2,
          "MM_HIGHEST_PHYSICAL_PAGE < MM_64M_PHYSICAL_PAGE",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
          0x529u,
          0);
      PointerPdea = (_MMPTE *)-1070593280;
      TempPtea.Long = 806027264;
      while ( 1 )
      {
        if ( PointerPdea->Long & 1 )
        {
          if ( (PointerPdea->Long & 0x80u) != 0 )
            RtlAssert(
              v5,
              (int)v7,
              (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
              v6,
              "PointerPde->Hard.LargePage == 0",
              "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
              0x537u,
              0);
          v6 = 4 * (TempPtea.Long + ((v3->Long >> 18) & 0x3FF));
          if ( *(_DWORD *)v6 & 1 )
          {
            if ( *(_DWORD *)v6 >> 12 == v23 )
              break;
          }
        }
        ++PointerPdea;
        TempPtea.Long += 1024;
        if ( (unsigned int)PointerPdea > 0xC0300BFC )
          RtlAssert(
            v5,
            (int)v7,
            (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
            v6,
            "PointerPde <= MiGetPdeAddress(MM_DEVKIT_PTE_END)",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
            0x54Au,
            0);
      }
    }
    else
    {
      if ( v5 == 10 )
        RtlAssert(
          10,
          (int)v7,
          (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
          2,
          "PageFrame->Busy.BusyType != MmDebuggerUsage",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
          0x556u,
          0);
      PointerPde = (_MMPTE *)-1070592768;
      TempPte.Long = 806158336;
      while ( 1 )
      {
        if ( PointerPde->Long & 1 )
        {
          if ( (PointerPde->Long & 0x80u) != 0 )
            RtlAssert(
              v5,
              (int)v7,
              (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
              v6,
              "PointerPde->Hard.LargePage == 0",
              "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
              0x564u,
              0);
          v6 = 4 * (TempPte.Long + ((v3->Long >> 18) & 0x3FF));
          if ( *(_DWORD *)v6 & 1 )
          {
            if ( *(_DWORD *)v6 >> 12 == v23 )
              break;
          }
        }
        ++PointerPde;
        TempPte.Long += 1024;
        if ( (unsigned int)PointerPde > 0xC0300EFC )
          RtlAssert(
            v5,
            (int)v7,
            (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
            v6,
            "PointerPde <= MiGetPdeAddress(MM_SYSTEM_PTE_END)",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
            0x577u,
            0);
      }
    }
  }
LABEL_59:
  MmNextDefaultPageColor = v23 & 0x1F;
  v9 = MiRemoveAnyPageFromFreeList((int)v7, v5);
  PointerPdec = v9 << 12;
  v11 = (unsigned int *)(4 * v9 - 2080440320);
  *v11 = (v9 << 12) | 0x63;
  v12 = *(int **)v6;
  v13 = *(_DWORD *)v6 >> 12;
  TempPtec.Long = v9;
  if ( v13 != v23 )
  {
    RtlAssert(
      v10,
      v13,
      v12,
      v6,
      "PointerPte->Hard.PageFrameNumber == PageFrameNumber",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x595u,
      0);
    v9 = TempPtec.Long;
  }
  v14 = PointerPdec | (unsigned __int16)v12 & 0xFFF;
  v15 = PointerPdec | (unsigned __int16)v12 & 0xFFF;
  v16 = (void *)((v9 - 0x80000) << 12);
  MiRelocateBusyPageHelper(
    (const void *)(v6 << 10),
    (void *)((v9 - 0x80000) << 12),
    (unsigned __int32 *)v6,
    v15,
    FullTlbFlush);
  *v11 = PageFrame->Long;
  __invlpg(v16);
  if ( v14 & 8 )
    KeFlushCurrentTbAndInvalidateAllCaches();
}