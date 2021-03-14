void *__userpurge ObpDestroyObjectHandle@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, void *Handle)
{
  unsigned int v4; // esi
  void **v5; // ecx
  void *result; // eax

  v4 = (unsigned int)Handle & 0xFFFFFFFC;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      v4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
      0x191u,
      0);
  if ( v4 >= (unsigned int)*(&ObpObjectHandleTable + 2) )
    return 0;
  v5 = (void **)(*(&(*(&ObpObjectHandleTable + 3))->HandleCount + (v4 >> 8)) + (unsigned __int8)v4);
  result = *v5;
  if ( !*v5 || (unsigned __int8)result & 1 )
    return 0;
  *v5 = *(&ObpObjectHandleTable + 1);
  ObpObjectHandleTable = (_OBJECT_HANDLE_TABLE *)((char *)ObpObjectHandleTable - 1);
  *(&ObpObjectHandleTable + 1) = (_OBJECT_HANDLE_TABLE *)(v4 | 1);
  return result;
}