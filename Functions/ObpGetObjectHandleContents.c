void *__userpurge ObpGetObjectHandleContents@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, void *Handle)
{
  unsigned int v4; // esi
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
      0x161u,
      0);
  if ( v4 >= (unsigned int)*(&ObpObjectHandleTable + 2)
    || (result = *(void **)(((unsigned __int8)Handle & 0xFC)
                          + *(&(*(&ObpObjectHandleTable + 3))->HandleCount + (((unsigned int)Handle & 0xFFFFFFFC) >> 8)))) == 0
    || (unsigned __int8)result & 1 )
  {
    result = 0;
  }
  return result;
}