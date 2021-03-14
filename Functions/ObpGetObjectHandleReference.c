int __userpurge ObpGetObjectHandleReference@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *Handle)
{
  KIRQL v5; // al
  int v6; // edx
  int v7; // esi

  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obtable.c",
      0x126u,
      0);
  v5 = KeRaiseIrqlToDpcLevel();
  if ( ((unsigned int)Handle & 0xFFFFFFFC) >= (unsigned int)*(&ObpObjectHandleTable + 2)
    || (v6 = *(_DWORD *)(((unsigned __int8)Handle & 0xFC)
                       + *(&(*(&ObpObjectHandleTable + 3))->HandleCount + (((unsigned int)Handle & 0xFFFFFFFC) >> 8)))) == 0
    || v6 & 1 )
  {
    v7 = 0;
  }
  else
  {
    ++*(_DWORD *)(v6 - 16);
    v7 = v6;
  }
  KfLowerIrql(v5);
  return v7;
}