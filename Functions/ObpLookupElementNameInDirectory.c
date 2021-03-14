char __userpurge ObpLookupElementNameInDirectory@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _OBJECT_DIRECTORY *Directory, _STRING *ElementName, char ResolveSymbolicLink, void **ReturnedObject)
{
  char *v8; // eax
  char v9; // al
  _OBJECT_HEADER_NAME_INFO *v10; // eax
  _OBJECT_HEADER_NAME_INFO *i; // esi

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obdir.c",
      0x165u,
      0);
  if ( Directory != ObpDosDevicesDirectoryObject
    || !ResolveSymbolicLink
    || ElementName->Length != 2
    || (v8 = ElementName->Buffer, v8[1] != 58)
    || ((v9 = *v8, v9 < 97) || v9 > 122 ? (v9 < 65 || v9 > 90 ? (v10 = 0) : (v10 = *(_OBJECT_HEADER_NAME_INFO **)(4 * v9 - 2147151620))) : (v10 = *(_OBJECT_HEADER_NAME_INFO **)(4 * v9 - 2147151748)),
        !v10) )
  {
    for ( i = Directory->HashBuckets[ObpComputeHashIndex(ElementName)]; ; i = i->ChainLink )
    {
      if ( !i )
      {
        *ReturnedObject = 0;
        return 0;
      }
      if ( RtlEqualString(&i->Name, ElementName, 1) )
        break;
    }
    v10 = i + 2;
    if ( ResolveSymbolicLink )
    {
      if ( *(_OBJECT_TYPE **)&i[1].Name.Length == &ObSymbolicLinkObjectType )
        v10 = v10->ChainLink;
    }
  }
  *ReturnedObject = v10;
  return 1;
}