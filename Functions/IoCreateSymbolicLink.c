int *__userpurge IoCreateSymbolicLink@<eax>(int *a1@<edi>, int a2@<esi>, _STRING *SymbolicLinkName, _STRING *DeviceName)
{
  int v4; // edx
  int v5; // ST0C_4
  int *v6; // esi
  _OBJECT_ATTRIBUTES objectAttributes; // [esp+0h] [ebp-10h]
  void *linkHandle; // [esp+Ch] [ebp-4h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v4, v5, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c", 0x6D3u, 0);
  }
  objectAttributes.RootDirectory = 0;
  objectAttributes.ObjectName = SymbolicLinkName;
  objectAttributes.Attributes = 80;
  v6 = NtCreateSymbolicLinkObject(&linkHandle, &objectAttributes, DeviceName);
  if ( (signed int)v6 >= 0 )
    NtClose(a1, linkHandle);
  return v6;
}