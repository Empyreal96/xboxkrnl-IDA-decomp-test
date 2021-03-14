int *__userpurge IoDeleteSymbolicLink@<eax>(int *a1@<edi>, int a2@<esi>, _STRING *SymbolicLinkName)
{
  int v3; // edx
  int v4; // ST0C_4
  int v5; // edx
  int v6; // ecx
  int *v7; // esi
  _OBJECT_ATTRIBUTES objectAttributes; // [esp+0h] [ebp-10h]
  void *linkHandle; // [esp+Ch] [ebp-4h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v3, v4, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c", 0x742u, 0);
  }
  objectAttributes.RootDirectory = 0;
  objectAttributes.ObjectName = SymbolicLinkName;
  objectAttributes.Attributes = 64;
  v7 = NtOpenSymbolicLinkObject(&linkHandle, &objectAttributes);
  if ( (signed int)v7 >= 0 )
  {
    v7 = (int *)NtMakeTemporaryObject(v5, v6, a1, (int)v7, linkHandle);
    if ( (signed int)v7 >= 0 )
      NtClose(a1, linkHandle);
  }
  return v7;
}