int __userpurge IoQueryVolumeInformation@<eax>(int *a1@<edi>, int a2@<esi>, _FILE_OBJECT *FileObject, _FSINFOCLASS FsInformationClass, unsigned int Length, void *FsInformation, unsigned int *ReturnedLength)
{
  int v7; // edx
  int v8; // ST14_4

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v7, v8, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c", 0x913u, 0);
  }
  return IopQueryXxxInformation(a1, a2, FileObject, FsInformationClass, Length, FsInformation, ReturnedLength, 0);
}