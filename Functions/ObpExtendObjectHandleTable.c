char __usercall ObpExtendObjectHandleTable@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  int v4; // edx
  int v5; // ecx
  int *v6; // ebx
  unsigned int v8; // eax
  unsigned int v9; // esi
  int *v10; // eax
  int v11; // edx
  int v12; // esi
  int v13; // ecx
  int *v14; // edi
  int v15; // eax
  int v16; // ecx
  void ***NewRootTable; // [esp+0h] [ebp-4h]

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
      0x56u,
      0);
  v6 = ExAllocatePoolWithTag(a1, a2, a4, 0x100u, 0x7448624Fu);
  if ( !v6 )
    return 0;
  v8 = (unsigned int)*(&ObpObjectHandleTable + 2);
  if ( !(*(_WORD *)(&ObpObjectHandleTable + 2) & 0x7FF) )
  {
    if ( *(&ObpObjectHandleTable + 2) )
    {
      v9 = (unsigned int)*(&ObpObjectHandleTable + 2) >> 8;
      v10 = ExAllocatePoolWithTag(
              v4,
              v5,
              (unsigned int)*(&ObpObjectHandleTable + 2) >> 8,
              4 * ((unsigned int)*(&ObpObjectHandleTable + 2) >> 8) + 32,
              0x7248624Fu);
      NewRootTable = (void ***)v10;
      if ( !v10 )
      {
        ExFreePool(v6);
        return 0;
      }
      qmemcpy(v10, *(&ObpObjectHandleTable + 3), 4 * v9);
      if ( *(&ObpObjectHandleTable + 3) != (_OBJECT_HANDLE_TABLE *)(&ObpObjectHandleTable + 4) )
        ExFreePool(*(&ObpObjectHandleTable + 3));
      v8 = (unsigned int)*(&ObpObjectHandleTable + 2);
    }
    else
    {
      NewRootTable = (void ***)(&ObpObjectHandleTable + 4);
    }
    *(&ObpObjectHandleTable + 3) = (_OBJECT_HANDLE_TABLE *)NewRootTable;
  }
  *(&(*(&ObpObjectHandleTable + 3))->HandleCount + (v8 >> 8)) = (int)v6;
  v11 = (int)*(&ObpObjectHandleTable + 3);
  v12 = (int)*(&ObpObjectHandleTable + 2);
  v13 = *(&(*(&ObpObjectHandleTable + 3))->HandleCount + ((unsigned int)*(&ObpObjectHandleTable + 2) >> 8))
      + *((unsigned __int8 *)&ObpObjectHandleTable + 8);
  v14 = v6;
  if ( v6 != (int *)v13 )
    RtlAssert(
      (int)*(&ObpObjectHandleTable + 3),
      v13,
      v6,
      (int)*(&ObpObjectHandleTable + 2),
      "HandleContents == ObpGetHandleContentsPointer(Handle)",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
      0xA6u,
      0);
  v15 = v12 | 1;
  *(&ObpObjectHandleTable + 1) = (_OBJECT_HANDLE_TABLE *)(v12 | 1);
  v16 = 63;
  do
  {
    v15 += 4;
    *v14 = v15;
    ++v14;
    --v16;
  }
  while ( v16 );
  *v14 = -1;
  if ( !v12 )
  {
    if ( v6 != (int *)(*(&ObpObjectHandleTable + 3))->HandleCount )
      RtlAssert(
        v11,
        0,
        0,
        0,
        "HandleContents == ObpGetHandleContentsPointer(Handle)",
        "d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
        0xC2u,
        0);
    *(&ObpObjectHandleTable + 1) = (_OBJECT_HANDLE_TABLE *)*v6;
    *v6 = 0;
  }
  if ( !(*(_BYTE *)(&ObpObjectHandleTable + 1) & 1) )
    RtlAssert(
      v11,
      v16,
      0,
      v12,
      "ObpIsFreeHandleLink(ObpObjectHandleTable.FirstFreeTableEntry)",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
      0xC8u,
      0);
  *(&ObpObjectHandleTable + 2) = (_OBJECT_HANDLE_TABLE *)(v12 + 256);
  return 1;
}