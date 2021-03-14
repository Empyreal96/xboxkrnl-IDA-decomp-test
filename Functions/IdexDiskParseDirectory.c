int *__stdcall IdexDiskParseDirectory(void *ParseObject, _OBJECT_TYPE *ObjectType, unsigned int Attributes, _STRING *CompleteName, _STRING *RemainingName, void *Context, void **Object)
{
  unsigned int v7; // edi
  int *result; // eax
  bool v9; // bl
  unsigned __int16 v10; // ax
  unsigned __int16 v11; // ax
  int v12; // edx
  char *v13; // eax
  char *v14; // ecx
  void **v15; // ebx
  _STRING ElementName; // [esp+8h] [ebp-8h]

  v7 = 0;
  *Object = 0;
  if ( !RemainingName->Length )
    return (int *)-1073741790;
  v9 = RemainingName->Buffer[RemainingName->Length - 1] == 92;
  ObDissectName(*RemainingName, &ElementName, RemainingName);
  v10 = RemainingName->Length;
  if ( RemainingName->Length && *RemainingName->Buffer == 92 )
    return (int *)-1073741773;
  if ( v9 || v10 )
  {
    --RemainingName->Buffer;
    v11 = v10 + 1;
    RemainingName->Length = v11;
    RemainingName->MaximumLength = v11;
  }
  if ( ElementName.Length <= IdexDiskPartitionPrefix.Length
    || !RtlPrefixString(0, &IdexDiskPartitionPrefix, &ElementName, 1) )
  {
    return (int *)(RemainingName->Length != 0 ? -1073741766 : -1073741772);
  }
  v13 = &ElementName.Buffer[IdexDiskPartitionPrefix.Length];
  v14 = &ElementName.Buffer[ElementName.Length];
  while ( v13 < v14 )
  {
    LOBYTE(v12) = *v13;
    if ( *v13 < 48 || (char)v12 > 57 )
      break;
    v12 = (char)v12;
    v7 = (char)v12 + 10 * v7 - 48;
    ++v13;
  }
  if ( v13 != v14 || v7 >= 0x14 )
    return (int *)(RemainingName->Length != 0 ? -1073741766 : -1073741772);
  v15 = (void **)(4 * v7 - 2147150752);
  do
  {
    if ( *v15 )
      return IoParseDevice(
               (int *)v7,
               (int)RemainingName,
               *v15,
               ObjectType,
               Attributes,
               CompleteName,
               RemainingName,
               Context,
               Object);
    result = IdexDiskPartitionCreate(v12, (int)v14, (int *)v7, v7);
  }
  while ( (signed int)result >= 0 );
  if ( result == (int *)-1073741772 )
  {
    if ( RemainingName->Length )
      result = (int *)-1073741766;
  }
  return result;
}