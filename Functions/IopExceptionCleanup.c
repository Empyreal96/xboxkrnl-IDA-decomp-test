void __userpurge IopExceptionCleanup(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _FILE_OBJECT *FileObject, _IRP *Irp, _KEVENT *EventObject)
{
  int v7; // edx
  int v8; // ST0C_4
  int v9; // edx

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v7, v8, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\internal.c", 0x2AAu, 0);
  }
  IoFreeIrp(a2, a1, Irp);
  if ( FileObject->Flags & 1 )
    IopReleaseFileObjectLock((int)FileObject, v9);
  if ( EventObject )
    ObfDereferenceObject(EventObject, v9);
  ObfDereferenceObject(FileObject, v9);
}