int *__userpurge NtOpenFile@<eax>(int *a1@<edi>, int a2@<esi>, void **FileHandle, unsigned int DesiredAccess, _OBJECT_ATTRIBUTES *ObjectAttributes, _IO_STATUS_BLOCK *IoStatusBlock, unsigned int ShareAccess, unsigned int OpenOptions)
{
  int v8; // edx
  int v9; // ST24_4

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v8, v9, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\create.c", 0x99u, 0);
  }
  return IoCreateFile(
           a1,
           a2,
           FileHandle,
           DesiredAccess,
           ObjectAttributes,
           IoStatusBlock,
           0,
           0,
           ShareAccess,
           1u,
           OpenOptions,
           0);
}