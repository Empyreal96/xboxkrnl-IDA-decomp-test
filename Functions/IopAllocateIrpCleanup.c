int __userpurge IopAllocateIrpCleanup@<eax>(int a1@<edx>, int *a2@<edi>, int a3@<esi>, _FILE_OBJECT *FileObject, _KEVENT *EventObject)
{
  int v5; // edx
  int v6; // ST0C_4

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a2, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v5, v6, a2, a3, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\internal.c", 0x32u, 0);
  }
  if ( EventObject )
    ObfDereferenceObject(EventObject, a1);
  if ( FileObject->Flags & 1 )
    IopReleaseFileObjectLock((int)FileObject, a1);
  ObfDereferenceObject(FileObject, a1);
  return -1073741670;
}