char __stdcall GdfxFindOpenChildFcb(_GDF_FCB *DirectoryFcb, _STRING *FileName, _GDF_FCB **ReturnedFcb)
{
  _LIST_ENTRY *v3; // esi
  unsigned __int16 v4; // ax
  _GDF_FCB *v5; // esi
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
      v4 = BYTE1(v3[2].Flink);
      v5 = (_GDF_FCB *)&v3[-2];
      v6 = v4 == FileName->Length;
      FcbFileName.Length = v4;
      FcbFileName.Buffer = v5->FileName;
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