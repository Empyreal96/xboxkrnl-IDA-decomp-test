void __userpurge GdfxDereferenceFcb(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _GDF_FCB *Fcb)
{
  _GDF_FCB *v4; // esi
  bool v5; // zf
  _LIST_ENTRY *v6; // eax
  _LIST_ENTRY *v7; // ecx

  v4 = Fcb;
  if ( !Fcb->ReferenceCount )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)Fcb,
      "Fcb->ReferenceCount > 0",
      "d:\\xbox-apr03\\private\\ntos\\gdfx\\fcbsup.c",
      0xD6u,
      0);
  do
  {
    v5 = v4->ReferenceCount-- == 1;
    if ( !v5 )
      break;
    if ( v4->Flags & 2 && v4->ChildFcbList.Flink != &v4->ChildFcbList )
      RtlAssert(
        a1,
        a2,
        a3,
        (int)v4,
        "IsListEmpty(&Fcb->ChildFcbList)",
        "d:\\xbox-apr03\\private\\ntos\\gdfx\\fcbsup.c",
        0xE9u,
        0);
    a3 = (int *)v4->ParentFcb;
    if ( a3 )
    {
      v6 = v4->SiblingFcbLink.Flink;
      v7 = v4->SiblingFcbLink.Blink;
      v7->Flink = v6;
      v6->Blink = v7;
    }
    ExFreePool(v4);
    v4 = (_GDF_FCB *)a3;
  }
  while ( a3 );
}