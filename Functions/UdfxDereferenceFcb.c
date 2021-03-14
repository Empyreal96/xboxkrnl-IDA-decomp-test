void __userpurge UdfxDereferenceFcb(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _UDF_FCB *Fcb)
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
      "d:\\xbox-apr03\\private\\ntos\\udfx\\fcbsup.c",
      0x198u,
      0);
  do
  {
    v5 = (*((_DWORD *)v4 + 7))-- == 1;
    if ( !v5 )
      break;
    if ( *v4 & 2 && *((char **)v4 + 11) != v4 + 44 )
      RtlAssert(
        a1,
        a2,
        a3,
        (int)v4,
        "IsListEmpty(&Fcb->ChildFcbList)",
        "d:\\xbox-apr03\\private\\ntos\\udfx\\fcbsup.c",
        0x1ABu,
        0);
    a3 = (int *)*((_DWORD *)v4 + 8);
    if ( a3 )
    {
      v6 = *((_DWORD *)v4 + 9);
      v7 = (_DWORD *)*((_DWORD *)v4 + 10);
      *v7 = v6;
      *(_DWORD *)(v6 + 4) = v7;
    }
    ExFreePool(v4);
    v4 = (char *)a3;
  }
  while ( a3 );
}