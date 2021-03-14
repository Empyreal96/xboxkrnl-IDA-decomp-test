char __stdcall UdfxFindOpenChildFcb(_UDF_FCB *DirectoryFcb, _STRING *FileName, _UDF_FCB **ReturnedFcb)
{
  _LIST_ENTRY *v3; // esi
  unsigned __int16 v4; // ax
  _UDF_FCB *v5; // esi
  bool v6; // zf
  char result; // al
  _STRING FcbFileName; // [esp+Ch] [ebp-8h]

  v3 = DirectoryFcb->ChildFcbList.Flink;
  if ( v3 == &DirectoryFcb->ChildFcbList )
  {
LABEL_5:
    *ReturnedFcb = 0;
    result = 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = BYTE1(v3[-5].Blink);
      v5 = (_UDF_FCB *)&v3[-5].Blink;
      v6 = v4 == FileName->Length;
      FcbFileName.Length = v4;
      FcbFileName.Buffer = &v5[1].Flags;
      if ( v6 )
      {
        if ( RtlEqualString(&FcbFileName, FileName, 1) )
          break;
      }
      v3 = v5->SiblingFcbLink.Flink;
      if ( v3 == &DirectoryFcb->ChildFcbList )
        goto LABEL_5;
    }
    *ReturnedFcb = v5;
    result = 1;
  }
  return result;
}