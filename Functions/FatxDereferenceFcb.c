void __userpurge FatxDereferenceFcb(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_FCB *Fcb)
{
  char *v4; // esi
  bool v5; // zf
  int v6; // eax
  _DWORD *v7; // ecx

  v4 = &Fcb->Flags;
  if ( !Fcb->ReferenceCount )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)Fcb,
      "Fcb->ReferenceCount > 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x973u,
      0);
  do
  {
    v5 = (*((_DWORD *)v4 + 1))-- == 1;
    if ( !v5 )
      break;
    if ( *v4 & 1 )
      RtlAssert(
        a1,
        a2,
        a3,
        (int)v4,
        "FatxIsFlagClear(Fcb->Flags, FAT_FCB_VOLUME)",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x988u,
        0);
    if ( *v4 & 2 && *((char **)v4 + 17) != v4 + 68 )
      RtlAssert(
        a1,
        a2,
        a3,
        (int)v4,
        "IsListEmpty(&Fcb->Directory.ChildFcbList)",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x990u,
        0);
    a3 = (int *)*((_DWORD *)v4 + 6);
    if ( a3 )
    {
      v6 = *((_DWORD *)v4 + 4);
      v7 = (_DWORD *)*((_DWORD *)v4 + 5);
      *v7 = v6;
      *(_DWORD *)(v6 + 4) = v7;
    }
    if ( *v4 < 0 )
      ExFreePool(*((void **)v4 + 12));
    ExFreePool(v4);
    v4 = (char *)a3;
  }
  while ( a3 );
}