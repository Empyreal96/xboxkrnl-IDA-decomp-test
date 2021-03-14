void __userpurge MmUnlockSelectedIoPages(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _IRP *Irp)
{
  _IRP *v4; // esi
  unsigned int v5; // edi
  _MMPTE *v6; // edi
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int **v11; // eax
  bool i; // cf
  int *v13; // edi
  _BYTE *v14; // eax
  int *v15; // edi
  unsigned int v16; // eax
  int v17; // edi
  _FILE_SEGMENT_ELEMENT *EndingSegmentArray; // [esp+Ch] [ebp-Ch]
  _BYTE *v19; // [esp+10h] [ebp-8h]
  _FILE_SEGMENT_ELEMENT *SegmentArray; // [esp+14h] [ebp-4h]
  unsigned int NumberOfPages; // [esp+20h] [ebp+8h]
  KIRQL NumberOfPages_3; // [esp+23h] [ebp+Bh]

  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a1,
      a2,
      0,
      a3,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
      0x49Au,
      0);
  v4 = Irp;
  if ( !Irp->SegmentArray )
    RtlAssert(
      a1,
      a2,
      0,
      (int)Irp,
      "Irp->SegmentArray != NULL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
      0x49Bu,
      0);
  if ( !Irp->LockedBufferLength )
    RtlAssert(
      a1,
      a2,
      0,
      (int)Irp,
      "Irp->LockedBufferLength != 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
      0x49Cu,
      0);
  v5 = (Irp->LockedBufferLength + 4095) >> 12;
  NumberOfPages = (Irp->LockedBufferLength + 4095) >> 12;
  if ( v4->Flags & 0x800 )
  {
    if ( !v4->UserBuffer )
      RtlAssert(
        a1,
        a2,
        (int *)v5,
        (int)v4,
        "Irp->UserBuffer != NULL",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        0x4A7u,
        0);
    v6 = (_MMPTE *)((((_DWORD)v4->UserBuffer >> 10) & 0x3FFFFC) - 0x40000000);
    MiZeroAndFlushPtes(v6, NumberOfPages);
    MiReleaseSystemPtes(v7, v8, (int *)v6, &MmSystemPteRange, v6, NumberOfPages);
    v4->UserBuffer = 0;
    BYTE1(v4->Flags) &= 0xF7u;
    v5 = NumberOfPages;
  }
  NumberOfPages_3 = KeRaiseIrqlToDpcLevel();
  v11 = (int **)v4->SegmentArray;
  EndingSegmentArray = (_FILE_SEGMENT_ELEMENT *)&v11[v5];
  for ( i = v11 < (int **)EndingSegmentArray; ; i = &SegmentArray[1] < EndingSegmentArray )
  {
    SegmentArray = (_FILE_SEGMENT_ELEMENT *)v11;
    if ( !i )
      break;
    v13 = *v11;
    v14 = (_BYTE *)((((unsigned int)*v11 >> 20) & 0xFFC) - 1070596096);
    v19 = v14;
    if ( !(*v14 & 1) )
    {
      RtlAssert(
        v9,
        v10,
        v13,
        (int)v4,
        "MiGetPdeAddress(BufferAddress)->Hard.Valid != 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        0x4BFu,
        0);
      v14 = v19;
    }
    if ( *v14 < 0 )
      RtlAssert(
        v9,
        v10,
        v13,
        (int)v4,
        "MiGetPdeAddress(BufferAddress)->Hard.LargePage == 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        0x4C0u,
        0);
    if ( (unsigned int)v13 + 2147483648 > 0xFFFFFFF )
    {
      v15 = (int *)((((unsigned int)v13 >> 10) & 0x3FFFFC) - 0x40000000);
      if ( !(*(_BYTE *)v15 & 1) )
        RtlAssert(
          v9,
          v10,
          v15,
          (int)v4,
          "MiGetPteAddress(BufferAddress)->Hard.Valid != 0",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
          0x4C4u,
          0);
      v16 = (unsigned int)*v15 >> 12;
      if ( v16 <= MmHighestPhysicalPage )
      {
        v17 = 4 * v16 - 2080440320;
        if ( *(_BYTE *)v17 & 1 )
          RtlAssert(
            v9,
            v10,
            (int *)v17,
            (int)v4,
            "PageFrame->Pte.Hard.Valid == 0",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            0x4CCu,
            0);
        if ( !(*(_BYTE *)(v17 + 2) & 1) )
          RtlAssert(
            v9,
            v10,
            (int *)v17,
            (int)v4,
            "PageFrame->Busy.Busy != 0",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            0x4CDu,
            0);
        if ( !(*(_BYTE *)(v17 + 3) & 0xF0) )
          RtlAssert(
            v9,
            v10,
            (int *)v17,
            (int)v4,
            "PageFrame->Busy.BusyType != MmUnknownUsage",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            0x4CEu,
            0);
        if ( (*(_DWORD *)v17 & 0xF0000000) >= 0xB0000000 )
          RtlAssert(
            v9,
            v10,
            (int *)v17,
            (int)v4,
            "PageFrame->Busy.BusyType < MmMaximumUsage",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            0x4CFu,
            0);
        if ( !*(_WORD *)v17 )
          RtlAssert(
            v9,
            v10,
            (int *)v17,
            (int)v4,
            "PageFrame->Busy.LockCount != 0",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            0x4D0u,
            0);
        *(_WORD *)v17 -= 2;
      }
    }
    v11 = (int **)&SegmentArray[1];
  }
  KfLowerIrql(NumberOfPages_3);
  ExFreePool(v4->SegmentArray);
  v4->SegmentArray = 0;
}