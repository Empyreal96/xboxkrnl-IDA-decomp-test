char __userpurge FatxFindOpenChildFcb@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_FCB *DirectoryFcb, _STRING *FileName, _FAT_FCB **ReturnedFcb)
{
  _FAT_FCB *v6; // esi
  unsigned __int16 v7; // ax
  _FAT_FCB *v8; // esi
  bool v9; // zf
  char result; // al
  _STRING FcbFileName; // [esp+Ch] [ebp-8h]

  if ( !(DirectoryFcb->Flags & 2) )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)DirectoryFcb,
      "FatxIsFlagSet(DirectoryFcb->Flags, FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x132u,
      0);
  v6 = (_FAT_FCB *)DirectoryFcb->File.FileMutex.LockCount;
  if ( v6 == (_FAT_FCB *)&DirectoryFcb->68 )
  {
LABEL_7:
    *ReturnedFcb = 0;
    result = 0;
  }
  else
  {
    while ( 1 )
    {
      v7 = *((unsigned __int8 *)&v6[-1].Directory + 162);
      v8 = (_FAT_FCB *)((char *)v6 - 16);
      v9 = v7 == FileName->Length;
      FcbFileName.Length = v7;
      FcbFileName.Buffer = v8->FileNameBuffer;
      if ( v9 )
      {
        if ( RtlEqualString(&FcbFileName, FileName, 1) )
          break;
      }
      v6 = (_FAT_FCB *)v8->SiblingFcbLink.Flink;
      if ( v6 == (_FAT_FCB *)&DirectoryFcb->68 )
        goto LABEL_7;
    }
    *ReturnedFcb = v8;
    result = 1;
  }
  return result;
}