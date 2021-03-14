int __userpurge NtQueryDirectoryObject@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *DirectoryHandle, void *Buffer, unsigned int Length, char RestartScan, unsigned int *Context, unsigned int *ReturnedLength)
{
  int result; // eax
  unsigned int v11; // edi
  unsigned int v12; // ebx
  int v13; // esi
  int v14; // ecx
  _OBJECT_HEADER_NAME_INFO *v15; // edx
  unsigned int v16; // ecx
  int v17; // edx
  unsigned int BytesRequired; // [esp+0h] [ebp-8h]
  _OBJECT_DIRECTORY *Directory; // [esp+4h] [ebp-4h]
  int status; // [esp+10h] [ebp+8h]
  char OldIrql; // [esp+1Fh] [ebp+17h]

  if ( Length < 0xC )
    return -1073741811;
  result = ObReferenceObjectByHandle(a1, a2, a3, a4, DirectoryHandle, &ObDirectoryObjectType, (void **)&Directory);
  if ( result >= 0 )
  {
    v11 = 0;
    status = -2147483622;
    if ( RestartScan )
      v12 = 0;
    else
      v12 = *Context;
    v13 = 0;
    OldIrql = KeRaiseIrqlToDpcLevel();
    v14 = 0;
    while ( 2 )
    {
      v15 = Directory->HashBuckets[v14];
      while ( v15 )
      {
        if ( v13 == v12 )
        {
          v16 = v15->Name.Length;
          BytesRequired = v16 + 12;
          if ( v16 + 12 > Length )
          {
            v16 = Length - 12;
            status = -1073741789;
          }
          else
          {
            status = 0;
          }
          *((_DWORD *)Buffer + 2) = *(_DWORD *)(*(_DWORD *)&v15[1].Name.Length + 24);
          *((_DWORD *)Buffer + 1) = (char *)Buffer + 12;
          *(_WORD *)Buffer = v15->Name.Length;
          *((_WORD *)Buffer + 1) = v15->Name.Length;
          qmemcpy((char *)Buffer + 12, v15->Name.Buffer, v16);
          v11 = BytesRequired;
          *Context = v12 + 1;
          goto FoundDesiredIndex;
        }
        v15 = v15->ChainLink;
        ++v13;
      }
      if ( (unsigned int)++v14 < 0xB )
        continue;
      break;
    }
FoundDesiredIndex:
    KfLowerIrql(OldIrql);
    ObfDereferenceObject(Directory, v17);
    if ( ReturnedLength )
      *ReturnedLength = v11;
    result = status;
  }
  return result;
}