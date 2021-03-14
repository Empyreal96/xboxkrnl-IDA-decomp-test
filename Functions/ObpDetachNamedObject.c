void __userpurge ObpDetachNamedObject(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *Object, char OldIrql)
{
  _OBJECT_HEADER_NAME_INFO *v6; // edi
  char *v7; // eax
  char v8; // al
  _DWORD *v9; // esi
  unsigned int v10; // eax
  int v11; // edx
  int v12; // ecx
  _OBJECT_HEADER_NAME_INFO **v13; // ebx
  _OBJECT_HEADER_NAME_INFO *v14; // esi
  int v15; // edx
  int v16; // edx
  _OBJECT_HEADER_NAME_INFO *LastObjectHeaderNameInfo; // [esp+Ch] [ebp-8h]
  _OBJECT_DIRECTORY *Directory; // [esp+10h] [ebp-4h]

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obhandle.c",
      0x2Du,
      0);
  if ( !(*((char *)Object - 4) & 1) )
    RtlAssert(
      a1,
      a2,
      (int *)Object,
      a4,
      "ObpIsFlagSet(OBJECT_TO_OBJECT_HEADER(Object)->Flags, OB_FLAG_NAMED_OBJECT)",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obhandle.c",
      0x2Fu,
      0);
  if ( !(*((char *)Object - 4) & 4) )
    RtlAssert(
      a1,
      a2,
      (int *)Object,
      a4,
      "ObpIsFlagSet(OBJECT_TO_OBJECT_HEADER(Object)->Flags, OB_FLAG_ATTACHED_OBJECT)",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obhandle.c",
      0x30u,
      0);
  v6 = (_OBJECT_HEADER_NAME_INFO *)((char *)Object - 32);
  Directory = (_OBJECT_DIRECTORY *)*((_DWORD *)Object - 7);
  if ( Directory == ObpDosDevicesDirectoryObject && v6->Name.Length == 2 )
  {
    v7 = v6->Name.Buffer;
    if ( v7[1] == 58 )
    {
      v8 = *v7;
      if ( v8 < 97 || v8 > 122 )
      {
        if ( v8 < 65 || v8 > 90 )
          goto LABEL_19;
        v9 = (_DWORD *)(4 * v8 - 2147151620);
        if ( !*v9 )
          RtlAssert(
            a1,
            a2,
            (int *)v6,
            (int)v9,
            "ObpDosDevicesDriveLetterMap[DriveLetter - 'A'] != NULL",
            "d:\\xbox-apr03\\private\\ntos\\obx\\obhandle.c",
            0x45u,
            0);
      }
      else
      {
        v9 = (_DWORD *)(4 * v8 - 2147151748);
        if ( !*v9 )
          RtlAssert(
            a1,
            a2,
            (int *)v6,
            (int)v9,
            "ObpDosDevicesDriveLetterMap[DriveLetter - 'a'] != NULL",
            "d:\\xbox-apr03\\private\\ntos\\obx\\obhandle.c",
            0x42u,
            0);
      }
      *v9 = 0;
    }
  }
LABEL_19:
  v10 = ObpComputeHashIndex(&v6->Name);
  v12 = (int)Directory;
  v13 = &Directory->HashBuckets[v10];
  v14 = *v13;
  if ( *v13 == v6 )
    goto LABEL_29;
  do
  {
    LastObjectHeaderNameInfo = v14;
    v14 = v14->ChainLink;
    if ( !v14 )
      RtlAssert(
        v11,
        v12,
        (int *)v6,
        0,
        "CurrentObjectHeaderNameInfo != NULL",
        "d:\\xbox-apr03\\private\\ntos\\obx\\obhandle.c",
        0x5Du,
        0);
  }
  while ( v14 != v6 );
  if ( LastObjectHeaderNameInfo )
    LastObjectHeaderNameInfo->ChainLink = v14->ChainLink;
  else
LABEL_29:
    *v13 = v14->ChainLink;
  v6->ChainLink = 0;
  v6->Directory = 0;
  KfLowerIrql(OldIrql);
  ObfDereferenceObject(Directory, v15);
  ObfDereferenceObject(Object, v16);
}