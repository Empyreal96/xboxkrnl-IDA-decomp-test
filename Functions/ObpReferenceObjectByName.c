int *__stdcall ObpReferenceObjectByName(void *RootDirectoryHandle, _STRING *ObjectName, unsigned int Attributes, _OBJECT_TYPE *ObjectType, void *ParseContext, void **ReturnedObject)
{
  int v6; // edx
  int v7; // ecx
  char *v8; // eax
  _OBJECT_DIRECTORY *v9; // esi
  signed int v10; // esi
  int v12; // edx
  int v13; // ecx
  _OBJECT_TYPE *v14; // eax
  char v15; // cl
  int v16; // edx
  int v17; // ecx
  int *v18; // edi
  int v19; // edx
  int v20; // edx
  void *v21; // ecx
  _STRING ElementName; // [esp+Ch] [ebp-1Ch]
  _STRING RemainingName; // [esp+14h] [ebp-14h]
  int ResolveSymbolicLink; // [esp+1Ch] [ebp-Ch]
  void *ParsedObject; // [esp+20h] [ebp-8h]
  char OldIrql; // [esp+27h] [ebp-1h]

  *ReturnedObject = 0;
  OldIrql = KeRaiseIrqlToDpcLevel();
  if ( ObjectName )
  {
    v7 = *(_DWORD *)&ObjectName->Length;
    v8 = ObjectName->Buffer;
    *(_DWORD *)&RemainingName.Length = *(_DWORD *)&ObjectName->Length;
    RemainingName.Buffer = v8;
  }
  else
  {
    *(_DWORD *)&RemainingName.Length = 0;
    RemainingName.Buffer = 0;
  }
  LOBYTE(ResolveSymbolicLink) = 1;
  if ( RootDirectoryHandle )
  {
    if ( RootDirectoryHandle == (void *)-3 )
    {
      v9 = ObpDosDevicesDirectoryObject;
    }
    else
    {
      if ( RootDirectoryHandle != (void *)-4 )
      {
        v9 = (_OBJECT_DIRECTORY *)ObpGetObjectHandleContents(v6, v7, (int *)&ObDirectoryObjectType, RootDirectoryHandle);
        RootDirectoryHandle = v9;
        if ( !v9 )
        {
          v10 = -1073741816;
          goto CleanupAndExit_0;
        }
LABEL_8:
        if ( RemainingName.Length )
        {
          if ( *RemainingName.Buffer != 92 )
            goto OpenRootDirectory;
          goto LABEL_10;
        }
        goto LABEL_35;
      }
      v9 = ObpWin32NamedObjectsDirectoryObject;
    }
    RootDirectoryHandle = v9;
    goto LABEL_8;
  }
  if ( !RemainingName.Length || *RemainingName.Buffer != 92 )
  {
LABEL_10:
    v10 = -1073741773;
CleanupAndExit_0:
    KfLowerIrql(OldIrql);
    return (int *)v10;
  }
  v9 = ObpRootDirectoryObject;
  RootDirectoryHandle = ObpRootDirectoryObject;
  if ( RemainingName.Length != 1 )
  {
    if ( (_OBJECT_TYPE *)ObpRootDirectoryObject[-1].HashBuckets[9] != &ObDirectoryObjectType )
      RtlAssert(
        v6,
        v7,
        (int *)&ObDirectoryObjectType,
        (int)ObpRootDirectoryObject,
        "OBJECT_TO_OBJECT_HEADER(Directory)->Type == &ObDirectoryObjectType",
        "d:\\xbox-apr03\\private\\ntos\\obx\\obdir.c",
        0x23Du,
        0);
    goto LABEL_23;
  }
  ++RemainingName.Buffer;
  RemainingName.Length = 0;
  RemainingName.MaximumLength = 0;
OpenRootDirectory:
  while ( RemainingName.Length )
  {
    if ( (_OBJECT_TYPE *)v9[-1].HashBuckets[9] != &ObDirectoryObjectType )
    {
      if ( v9[-1].HashBuckets[9][1].ChainLink )
        goto InvokeParseProcedure;
      v10 = -1073741766;
      goto CleanupAndExit_0;
    }
LABEL_23:
    ObDissectName(RemainingName, &ElementName, &RemainingName);
    if ( RemainingName.Length )
    {
      if ( *RemainingName.Buffer == 92 )
        goto LABEL_10;
    }
    else if ( ObjectType == &ObSymbolicLinkObjectType )
    {
      LOBYTE(ResolveSymbolicLink) = 0;
    }
    if ( !ObpLookupElementNameInDirectory(
            v12,
            v13,
            (int *)&ObDirectoryObjectType,
            (int)v9,
            v9,
            &ElementName,
            ResolveSymbolicLink,
            &RootDirectoryHandle) )
    {
      v10 = RemainingName.Length != 0 ? -1073741766 : -1073741772;
      goto CleanupAndExit_0;
    }
    v9 = (_OBJECT_DIRECTORY *)RootDirectoryHandle;
  }
LABEL_35:
  v14 = (_OBJECT_TYPE *)v9[-1].HashBuckets[9];
  if ( !v14->ParseProcedure )
  {
    if ( ObjectType && ObjectType != v14 )
    {
      v10 = -1073741788;
    }
    else
    {
      ++v9[-1].HashBuckets[7];
      *ReturnedObject = v9;
      v10 = 0;
    }
    goto CleanupAndExit_0;
  }
InvokeParseProcedure:
  v15 = OldIrql;
  ++v9[-1].HashBuckets[7];
  KfLowerIrql(v15);
  if ( (_OBJECT_TYPE *)v9[-1].HashBuckets[9] != &IoFileObjectType )
  {
    HIWORD(v17) = HIWORD(ObjectName);
    if ( RemainingName.Buffer > ObjectName->Buffer )
    {
      LOWORD(v17) = ++RemainingName.Length;
      --RemainingName.Buffer;
      RemainingName.MaximumLength = RemainingName.Length;
      if ( *RemainingName.Buffer != 92 )
        RtlAssert(
          v16,
          v17,
          (int *)&ObDirectoryObjectType,
          (int)v9,
          "RemainingName.Buffer[0] == OBJ_NAME_PATH_SEPARATOR",
          "d:\\xbox-apr03\\private\\ntos\\obx\\obdir.c",
          0x2B2u,
          0);
    }
  }
  ParsedObject = 0;
  v18 = (int *)((int (__stdcall *)(_OBJECT_DIRECTORY *, _OBJECT_TYPE *, unsigned int, _STRING *, _STRING *, void *, void **))v9[-1].HashBuckets[9][1].ChainLink)(
                 v9,
                 ObjectType,
                 Attributes,
                 ObjectName,
                 &RemainingName,
                 ParseContext,
                 &ParsedObject);
  ObfDereferenceObject(v9, v19);
  if ( (signed int)v18 >= 0 )
  {
    v21 = ParsedObject;
    if ( !ParsedObject )
    {
      RtlAssert(
        v20,
        (int)ParsedObject,
        v18,
        (int)v9,
        "ParsedObject != NULL",
        "d:\\xbox-apr03\\private\\ntos\\obx\\obdir.c",
        0x2C7u,
        0);
      v21 = ParsedObject;
    }
    if ( ObjectType && ObjectType != *((_OBJECT_TYPE **)v21 - 2) )
    {
      ObfDereferenceObject(v21, v20);
      v18 = (int *)-1073741788;
    }
    else
    {
      *ReturnedObject = v21;
      v18 = 0;
    }
  }
  return v18;
}