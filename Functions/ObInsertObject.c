int __stdcall ObInsertObject(void *Object, _OBJECT_ATTRIBUTES *ObjectAttributes, unsigned int ObjectPointerBias, void **ReturnedHandle)
{
  void *v4; // ebx
  _OBJECT_DIRECTORY *v5; // edi
  int v6; // edx
  void *v7; // ecx
  int *v8; // eax
  int v9; // ecx
  bool v10; // zf
  char *v11; // eax
  void *v12; // ecx
  _OBJECT_DIRECTORY *v13; // eax
  int v14; // esi
  int v15; // edx
  int v16; // ecx
  char *v17; // esi
  unsigned int v18; // eax
  int v19; // edx
  int *v20; // eax
  int v21; // ecx
  char *v22; // esi
  char v23; // al
  _DWORD *v24; // esi
  int v25; // edx
  _STRING v27; // [esp-10h] [ebp-38h]
  _STRING ElementName; // [esp+Ch] [ebp-1Ch]
  _STRING RemainingName; // [esp+14h] [ebp-14h]
  void *Handle; // [esp+1Ch] [ebp-Ch]
  void *FoundObject; // [esp+20h] [ebp-8h]
  char OldIrql; // [esp+27h] [ebp-1h]
  void *DosDevicesObject; // [esp+38h] [ebp+10h]

  v4 = Object;
  v5 = 0;
  OldIrql = KeRaiseIrqlToDpcLevel();
  Handle = 0;
  if ( !ObjectAttributes )
    goto LABEL_29;
  v8 = (int *)ObjectAttributes->ObjectName;
  if ( !v8 )
    goto LABEL_29;
  v9 = *v8;
  v10 = (unsigned __int16)*v8 == 0;
  *(_DWORD *)&RemainingName.Length = *v8;
  v11 = (char *)v8[1];
  RemainingName.Buffer = v11;
  if ( v10 )
  {
    RtlAssert(
      v6,
      v9,
      0,
      (int)ObjectAttributes,
      "RemainingName.Length != 0",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obcreate.c",
      0xD8u,
      0);
    v11 = RemainingName.Buffer;
  }
  v12 = ObjectAttributes->RootDirectory;
  if ( ObjectAttributes->RootDirectory )
  {
    if ( *v11 != 92 )
    {
      if ( v12 == (void *)-3 )
      {
        v5 = ObpDosDevicesDirectoryObject;
      }
      else if ( v12 == (void *)-4 )
      {
        v5 = ObpWin32NamedObjectsDirectoryObject;
      }
      else
      {
        v13 = (_OBJECT_DIRECTORY *)ObpGetObjectHandleContents(v6, (int)v12, 0, v12);
        v5 = v13;
        if ( !v13 )
        {
          v14 = -1073741816;
          goto CleanupAndExit_1;
        }
        if ( (_OBJECT_TYPE *)v13[-1].HashBuckets[9] != &ObDirectoryObjectType )
        {
LABEL_27:
          v14 = -1073741788;
          goto CleanupAndExit_1;
        }
        v11 = RemainingName.Buffer;
      }
      goto LABEL_15;
    }
LABEL_17:
    v14 = -1073741773;
    goto CleanupAndExit_1;
  }
  if ( *v11 != 92 )
    goto LABEL_17;
  v5 = ObpRootDirectoryObject;
LABEL_15:
  for ( v27.Buffer = v11; ; v27.Buffer = RemainingName.Buffer )
  {
    *(_DWORD *)&v27.Length = *(_DWORD *)&RemainingName.Length;
    ObDissectName(v27, &ElementName, &RemainingName);
    if ( !ObpLookupElementNameInDirectory(
            v15,
            v16,
            (int *)v5,
            (int)&ObDirectoryObjectType,
            v5,
            &ElementName,
            1,
            &FoundObject) )
    {
      if ( !RemainingName.Length )
        goto LABEL_29;
LABEL_24:
      v14 = -1073741766;
      goto CleanupAndExit_1;
    }
    v5 = 0;
    if ( !RemainingName.Length )
      break;
    v5 = (_OBJECT_DIRECTORY *)FoundObject;
    if ( *((_OBJECT_TYPE **)FoundObject - 2) != &ObDirectoryObjectType )
      goto LABEL_24;
  }
  if ( SLOBYTE(ObjectAttributes->Attributes) >= 0 )
  {
    v14 = -1073741771;
    goto CleanupAndExit_1;
  }
  v4 = FoundObject;
  v7 = Object;
  if ( *((_DWORD *)FoundObject - 2) != *((_DWORD *)Object - 2) )
    goto LABEL_27;
LABEL_29:
  Handle = ObpCreateObjectHandle((int)v7, v6, v4);
  if ( !Handle )
  {
    v14 = -1073741670;
    goto CleanupAndExit_1;
  }
  *((_DWORD *)v4 - 4) += ObjectPointerBias + 1;
  if ( !v5 )
    goto LABEL_47;
  v17 = (char *)Object - 32;
  v18 = ObpComputeHashIndex((_STRING *)Object - 3);
  *((_DWORD *)v4 - 1) |= 4u;
  *((_DWORD *)v17 + 1) = v5;
  v20 = (int *)&v5->HashBuckets[v18];
  v21 = *v20;
  *(_DWORD *)v17 = *v20;
  *v20 = (int)Object - 32;
  if ( v5 == ObpDosDevicesDirectoryObject && *((_WORD *)v17 + 4) == 2 )
  {
    v22 = (char *)*((_DWORD *)v17 + 3);
    if ( v22[1] == 58 )
    {
      DosDevicesObject = Object;
      if ( *((_OBJECT_TYPE **)Object - 2) == &ObSymbolicLinkObjectType )
        DosDevicesObject = *(void **)Object;
      v23 = *v22;
      if ( *v22 < 97 || v23 > 122 )
      {
        if ( v23 < 65 || v23 > 90 )
          goto LABEL_46;
        v24 = (_DWORD *)(4 * v23 - 2147151620);
        if ( *v24 )
          RtlAssert(
            v19,
            v21,
            (int *)v5,
            (int)v24,
            "ObpDosDevicesDriveLetterMap[DriveLetter - 'A'] == NULL",
            "d:\\xbox-apr03\\private\\ntos\\obx\\obcreate.c",
            0x1B3u,
            0);
      }
      else
      {
        v24 = (_DWORD *)(4 * v23 - 2147151748);
        if ( *v24 )
          RtlAssert(
            v19,
            v21,
            (int *)v5,
            (int)v24,
            "ObpDosDevicesDriveLetterMap[DriveLetter - 'a'] == NULL",
            "d:\\xbox-apr03\\private\\ntos\\obx\\obcreate.c",
            0x1B0u,
            0);
      }
      *v24 = DosDevicesObject;
    }
  }
LABEL_46:
  ++v5[-1].HashBuckets[7];
  ++*((_DWORD *)v4 - 4);
LABEL_47:
  if ( ObjectAttributes && ObjectAttributes->Attributes & 0x10 )
    *((_DWORD *)v4 - 1) |= 2u;
  v14 = v4 != Object ? 0x40000000 : 0;
CleanupAndExit_1:
  KfLowerIrql(OldIrql);
  ObfDereferenceObject(Object, v25);
  *ReturnedHandle = Handle;
  return v14;
}