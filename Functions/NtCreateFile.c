int *__userpurge NtCreateFile@<eax>(int *a1@<edi>, int a2@<esi>, void **FileHandle, unsigned int DesiredAccess, _OBJECT_ATTRIBUTES *ObjectAttributes, _IO_STATUS_BLOCK *IoStatusBlock, _LARGE_INTEGER *AllocationSize, unsigned int FileAttributes, unsigned int ShareAccess, unsigned int CreateDisposition, unsigned int CreateOptions)
{
  int v11; // edx
  int v12; // ST24_4

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v11, v12, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\create.c", 0x5Cu, 0);
  }
  return IoCreateFile(
           a1,
           a2,
           FileHandle,
           DesiredAccess,
           ObjectAttributes,
           IoStatusBlock,
           AllocationSize,
           FileAttributes,
           ShareAccess,
           CreateDisposition,
           CreateOptions,
           0);
}