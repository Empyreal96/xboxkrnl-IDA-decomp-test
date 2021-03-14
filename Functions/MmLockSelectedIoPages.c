int __userpurge MmLockSelectedIoPages@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _FILE_SEGMENT_ELEMENT *SegmentArray, unsigned int Length, _IRP *Irp, char MapUserBuffer)
{
  unsigned int v8; // ebx
  int v9; // edx
  int *v10; // edi
  unsigned int v11; // ecx
  int *v12; // edi
  _MMPTE *v13; // eax
  _IRP *v15; // esi
  int v16; // edx
  _FILE_SEGMENT_ELEMENT *v17; // eax
  _FILE_SEGMENT_ELEMENT *v18; // ecx
  bool v19; // cf
  unsigned int v20; // esi
  _BYTE *v21; // ebx
  _BYTE *v22; // esi
  unsigned int v23; // esi
  _BYTE *v24; // ebx
  _MMPTE *v25; // eax
  _FILE_SEGMENT_ELEMENT *EndingSegmentArray; // [esp+0h] [ebp-Ch]
  _FILE_SEGMENT_ELEMENT *EndingSegmentArraya; // [esp+0h] [ebp-Ch]
  _FILE_SEGMENT_ELEMENT *SegmentArrayClone; // [esp+4h] [ebp-8h]
  _MMPTE *MappingPte; // [esp+8h] [ebp-4h]
  char OldIrql; // [esp+23h] [ebp+17h]

  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
      0x406u,
      0);
  if ( !Length )
    RtlAssert(a1, a2, a3, a4, "Length != 0", "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c", 0x407u, 0);
  v8 = (Length + 4095) >> 12;
  EndingSegmentArray = (_FILE_SEGMENT_ELEMENT *)(4 * v8);
  v10 = ExAllocatePoolWithTag(a1, a2, 4 * v8, 4 * v8, 0x61536D4Du);
  SegmentArrayClone = (_FILE_SEGMENT_ELEMENT *)v10;
  if ( !v10 )
    return -1073741670;
  v11 = 4 * v8 >> 2;
  qmemcpy(v10, SegmentArray, 4 * v11);
  v12 = &v10[v11];
  if ( MapUserBuffer )
  {
    v13 = MiReserveSystemPtes(v9, 0, v12, (_MMPTE *)&SegmentArray[v11], &MmSystemPteRange, v8);
    MappingPte = v13;
    if ( !v13 )
    {
      ExFreePool(SegmentArrayClone);
      return -1073741670;
    }
    v15 = Irp;
    BYTE1(v15->Flags) |= 8u;
    Irp->UserBuffer = (void *)((_DWORD)v13 << 10);
  }
  else
  {
    MappingPte = 0;
    v15 = Irp;
  }
  OldIrql = KeRaiseIrqlToDpcLevel();
  v17 = SegmentArray;
  v18 = (_FILE_SEGMENT_ELEMENT *)((char *)EndingSegmentArray + (_DWORD)SegmentArray);
  v19 = SegmentArray < (_FILE_SEGMENT_ELEMENT *)((char *)EndingSegmentArray + (signed int)SegmentArray);
  EndingSegmentArraya = (_FILE_SEGMENT_ELEMENT *)((char *)EndingSegmentArray + (_DWORD)SegmentArray);
  if ( v19 )
  {
    do
    {
      v20 = (unsigned int)v17->Buffer;
      v21 = (_BYTE *)((((_DWORD)v17->Buffer >> 20) & 0xFFC) - 1070596096);
      if ( !(*v21 & 1) )
        RtlAssert(
          v16,
          (int)v18,
          (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
          v20,
          "MiGetPdeAddress(BufferAddress)->Hard.Valid != 0",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
          0x440u,
          0);
      if ( *v21 < 0 )
        RtlAssert(
          v16,
          (int)v18,
          (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
          v20,
          "MiGetPdeAddress(BufferAddress)->Hard.LargePage == 0",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
          0x441u,
          0);
      if ( v20 + 2147483648 <= 0xFFFFFFF )
      {
        v23 = (v20 >> 12) & 0xFFFF;
      }
      else
      {
        v22 = (_BYTE *)(((v20 >> 10) & 0x3FFFFC) - 0x40000000);
        if ( !(*v22 & 1) )
          RtlAssert(
            v16,
            (int)v18,
            (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            (int)v22,
            "MiGetPteAddress(BufferAddress)->Hard.Valid != 0",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
            0x445u,
            0);
        v23 = *(_DWORD *)v22 >> 12;
        if ( v23 <= MmHighestPhysicalPage )
        {
          v24 = (_BYTE *)(4 * v23 - 2080440320);
          if ( *v24 & 1 )
            RtlAssert(
              v16,
              (int)v18,
              (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
              v23,
              "PageFrame->Pte.Hard.Valid == 0",
              "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
              0x44Du,
              0);
          if ( !(v24[2] & 1) )
            RtlAssert(
              v16,
              (int)v18,
              (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
              v23,
              "PageFrame->Busy.Busy != 0",
              "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
              0x44Eu,
              0);
          if ( !(v24[3] & 0xF0) )
            RtlAssert(
              v16,
              (int)v18,
              (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
              v23,
              "PageFrame->Busy.BusyType != MmUnknownUsage",
              "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
              0x44Fu,
              0);
          if ( (*(_DWORD *)v24 & 0xF0000000) >= 0xB0000000 )
            RtlAssert(
              v16,
              (int)v18,
              (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
              v23,
              "PageFrame->Busy.BusyType < MmMaximumUsage",
              "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
              0x450u,
              0);
          if ( (*(_DWORD *)v24 & 0xFFFF) == 65534 )
            RtlAssert(
              v16,
              (int)v18,
              (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
              v23,
              "PageFrame->Busy.LockCount != MI_LOCK_COUNT_MAXIMUM",
              "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
              0x451u,
              0);
          *(_WORD *)v24 += 2;
        }
      }
      if ( MappingPte )
      {
        v25 = MappingPte;
        ++MappingPte;
        v25->Long = (v23 << 12) | 0x63;
      }
      v17 = SegmentArray + 1;
      ++SegmentArray;
    }
    while ( SegmentArray < EndingSegmentArraya );
    v15 = Irp;
  }
  KfLowerIrql(OldIrql);
  v15->SegmentArray = SegmentArrayClone;
  v15->LockedBufferLength = Length;
  return 0;
}