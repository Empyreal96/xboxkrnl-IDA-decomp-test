int *__stdcall ObpResolveLinkTarget(_STRING *LinkTarget, void **ReturnedLinkTargetObject)
{
  int *v2; // edi
  char *v3; // eax
  bool v4; // zf
  KIRQL v5; // al
  _OBJECT_DIRECTORY *v6; // esi
  int v7; // edx
  int v8; // ecx
  int *v9; // esi
  char *v10; // esi
  int v12; // edx
  int v13; // ecx
  _OBJECT_ATTRIBUTES ObjectAttributes; // [esp+Ch] [ebp-2Ch]
  _IO_STATUS_BLOCK IoStatusBlock; // [esp+18h] [ebp-20h]
  _STRING ElementName; // [esp+20h] [ebp-18h]
  _STRING RemainingName; // [esp+28h] [ebp-10h]
  void *FileHandle; // [esp+30h] [ebp-8h]
  void *FoundObject; // [esp+34h] [ebp-4h]
  KIRQL OldIrql_3; // [esp+43h] [ebp+Bh]

  v2 = (int *)LinkTarget;
  v3 = LinkTarget->Buffer;
  v4 = (unsigned __int16)*(_DWORD *)&LinkTarget->Length == 0;
  *(_DWORD *)&RemainingName.Length = *(_DWORD *)&LinkTarget->Length;
  RemainingName.Buffer = v3;
  if ( v4 || *v3 != 92 )
    return (int *)-1073741811;
  v5 = KeRaiseIrqlToDpcLevel();
  v6 = ObpRootDirectoryObject;
  OldIrql_3 = v5;
  while ( 1 )
  {
    ObDissectName(RemainingName, &ElementName, &RemainingName);
    if ( RemainingName.Length && *RemainingName.Buffer == 92
      || !ObpLookupElementNameInDirectory(v7, v8, v2, (int)v6, v6, &ElementName, 1, &FoundObject) )
    {
      goto LABEL_12;
    }
    if ( !RemainingName.Length )
    {
      ++*((_DWORD *)FoundObject - 4);
      *ReturnedLinkTargetObject = FoundObject;
      v9 = 0;
LABEL_13:
      KfLowerIrql(OldIrql_3);
      return v9;
    }
    if ( *((_OBJECT_TYPE **)FoundObject - 2) != &ObDirectoryObjectType )
      break;
    v6 = (_OBJECT_DIRECTORY *)FoundObject;
  }
  v10 = (char *)FoundObject - 8;
  if ( !*(_DWORD *)(*((_DWORD *)FoundObject - 2) + 16) )
  {
LABEL_12:
    v9 = (int *)-1073741811;
    goto LABEL_13;
  }
  ++*((_DWORD *)FoundObject - 4);
  KfLowerIrql(OldIrql_3);
  v9 = (int *)(*(int (__stdcall **)(void *, _DWORD, signed int, int *, _STRING *, _DWORD, void **))(*(_DWORD *)v10 + 16))(
                FoundObject,
                0,
                64,
                v2,
                &RemainingName,
                0,
                ReturnedLinkTargetObject);
  if ( v9 == (int *)-1073741788 )
  {
    ObjectAttributes.RootDirectory = 0;
    ObjectAttributes.Attributes = 64;
    ObjectAttributes.ObjectName = (_STRING *)v2;
    v9 = NtOpenFile(v2, -1073741788, &FileHandle, 0, &ObjectAttributes, &IoStatusBlock, 7u, 1u);
    if ( (signed int)v9 >= 0 )
    {
      v9 = (int *)ObReferenceObjectByHandle(
                    v12,
                    v13,
                    v2,
                    (int)v9,
                    FileHandle,
                    &IoFileObjectType,
                    ReturnedLinkTargetObject);
      NtClose(v2, FileHandle);
    }
  }
  ObfDereferenceObject(FoundObject, v12);
  return v9;
}