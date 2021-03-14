int __fastcall GdfxCreateFcb(int a1, int a2, _GDF_FCB *ParentFcb, _STRING *FileName, _GDF_DIRECTORY_ENTRY *DirectoryEntry, _GDF_FCB **ReturnedFcb)
{
  int v6; // esi
  _GDF_FCB *v7; // edx
  _LIST_ENTRY *v8; // esi
  int result; // eax

  v6 = FileName->Length + 36;
  v7 = (_GDF_FCB *)ExAllocatePoolWithTag(
                     a2,
                     (int)FileName,
                     v6,
                     v6,
                     ((~DirectoryEntry->FileAttributes & 0x10) << 13) | 0x63447847);
  if ( v7 )
  {
    memset(v7, 0, v6);
    v7->ReferenceCount = 1;
    qmemcpy(v7->FileName, FileName->Buffer, FileName->Length);
    v7->FileNameLength = FileName->Length;
    v7->FirstSector = DirectoryEntry->FirstSector;
    v7->FileSize = DirectoryEntry->FileSize;
    ++ParentFcb->ReferenceCount;
    v7->ParentFcb = ParentFcb;
    v8 = ParentFcb->ChildFcbList.Flink;
    v7->SiblingFcbLink.Flink = ParentFcb->ChildFcbList.Flink;
    v7->SiblingFcbLink.Blink = &ParentFcb->ChildFcbList;
    v8->Blink = &v7->SiblingFcbLink;
    ParentFcb->ChildFcbList.Flink = &v7->SiblingFcbLink;
    if ( DirectoryEntry->FileAttributes & 0x10 )
    {
      v7->Flags |= 2u;
      v7->ChildFcbList.Blink = &v7->ChildFcbList;
      v7->ChildFcbList.Flink = &v7->ChildFcbList;
    }
    result = 0;
  }
  else
  {
    result = -1073741670;
  }
  *ReturnedFcb = v7;
  return result;
}