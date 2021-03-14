void *__fastcall ObpCreateObjectHandle(int a1, int a2, void *Object)
{
  int v4; // ecx
  _OBJECT_HANDLE_TABLE **v5; // esi
  void *Handle; // [esp+8h] [ebp-4h]

  if ( !Object || (unsigned __int8)Object & 1 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
      0,
      "(Object != NULL) && !ObpIsFreeHandleLink(Object)",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
      0xE7u,
      0);
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
      0,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
      0xE9u,
      0);
  if ( *(&ObpObjectHandleTable + 1) == (_OBJECT_HANDLE_TABLE *)-1
    && !ObpExtendObjectHandleTable(a2, a1, (int *)"d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c", 0) )
  {
    return 0;
  }
  if ( !(*(_BYTE *)(&ObpObjectHandleTable + 1) & 1) )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
      0,
      "ObpIsFreeHandleLink(ObpObjectHandleTable.FirstFreeTableEntry)",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
      0xFAu,
      0);
  Handle = (void *)((unsigned int)*(&ObpObjectHandleTable + 1) & 0xFFFFFFFE);
  v4 = ((unsigned int)*(&ObpObjectHandleTable + 1) & 0xFFFFFFFE) >> 8;
  v5 = (_OBJECT_HANDLE_TABLE **)(*(&(*(&ObpObjectHandleTable + 3))->HandleCount + v4)
                               + (unsigned __int8)(*(_BYTE *)(&ObpObjectHandleTable + 1) & 0xFE));
  *(&ObpObjectHandleTable + 1) = *v5;
  if ( !(*(_BYTE *)(&ObpObjectHandleTable + 1) & 1) )
    RtlAssert(
      a2,
      v4,
      (int *)"d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
      (int)v5,
      "ObpIsFreeHandleLink(ObpObjectHandleTable.FirstFreeTableEntry)",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
      0x101u,
      0);
  ObpObjectHandleTable = (_OBJECT_HANDLE_TABLE *)((char *)ObpObjectHandleTable + 1);
  ++*((_DWORD *)Object - 3);
  *v5 = (_OBJECT_HANDLE_TABLE *)Object;
  return Handle;
}