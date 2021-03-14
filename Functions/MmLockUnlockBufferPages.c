void __userpurge MmLockUnlockBufferPages(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *BaseAddress, unsigned int NumberOfBytes, char UnlockPages)
{
  unsigned int v7; // ebx
  int v8; // edx
  int v9; // ecx
  _BYTE *v10; // esi
  int v11; // ecx
  int *v12; // esi
  int *v13; // edi
  unsigned int v14; // eax
  _BYTE *v15; // ebx
  KIRQL OldIrql_3; // [esp+Fh] [ebp+Fh]

  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
      0x35Bu,
      0);
  v7 = NumberOfBytes;
  if ( !NumberOfBytes )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "NumberOfBytes != 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
      0x35Cu,
      (char *)NumberOfBytes);
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  v10 = (_BYTE *)((((unsigned int)BaseAddress >> 20) & 0xFFC) - 1070596096);
  if ( !(*v10 & 1) )
    RtlAssert(
      v8,
      v9,
      (int *)BaseAddress,
      (int)v10,
      "MiGetPdeAddress(BaseAddress)->Hard.Valid != 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
      0x360u,
      0);
  if ( (unsigned int)BaseAddress + 2147483648 > 0xFFFFFFF && *v10 >= 0 )
  {
    v11 = 4194300;
    v12 = (int *)((((unsigned int)BaseAddress >> 10) & 0x3FFFFC) - 0x40000000);
    v13 = (int *)((((_DWORD)((_DWORD)BaseAddress + v7 - 1) >> 10) & 0x3FFFFC) - 0x40000000);
    do
    {
      if ( !(*(_BYTE *)v12 & 1) )
        RtlAssert(
          v8,
          v11,
          v13,
          (int)v12,
          "PointerPte->Hard.Valid != 0",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
          0x376u,
          0);
      v14 = (unsigned int)*v12 >> 12;
      if ( v14 <= MmHighestPhysicalPage )
      {
        v15 = (_BYTE *)(4 * v14 - 2080440320);
        if ( *v15 & 1 )
          RtlAssert(
            v8,
            v11,
            v13,
            (int)v12,
            "PageFrame->Pte.Hard.Valid == 0",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            0x37Eu,
            0);
        if ( !(v15[2] & 1) )
          RtlAssert(
            v8,
            v11,
            v13,
            (int)v12,
            "PageFrame->Busy.Busy != 0",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            0x37Fu,
            0);
        if ( !(v15[3] & 0xF0) )
          RtlAssert(
            v8,
            v11,
            v13,
            (int)v12,
            "PageFrame->Busy.BusyType != MmUnknownUsage",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            0x380u,
            0);
        if ( (*(_DWORD *)v15 & 0xF0000000) >= 0xB0000000 )
          RtlAssert(
            v8,
            v11,
            v13,
            (int)v12,
            "PageFrame->Busy.BusyType < MmMaximumUsage",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            0x381u,
            0);
        if ( UnlockPages )
        {
          if ( !*(_WORD *)v15 )
            RtlAssert(
              v8,
              v11,
              v13,
              (int)v12,
              "PageFrame->Busy.LockCount != 0",
              "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
              0x384u,
              0);
        }
        else if ( (*(_DWORD *)v15 & 0xFFFF) == 65534 )
        {
          RtlAssert(
            v8,
            v11,
            v13,
            (int)v12,
            "PageFrame->Busy.LockCount != MI_LOCK_COUNT_MAXIMUM",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            0x386u,
            0);
        }
        *(_WORD *)v15 += 4 * (UnlockPages == 0) - 2;
      }
      ++v12;
    }
    while ( v12 <= v13 );
  }
  KfLowerIrql(OldIrql_3);
}