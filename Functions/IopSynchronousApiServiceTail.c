int __userpurge IopSynchronousApiServiceTail@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, int ReturnedStatus, _KEVENT *Event, _IRP *Irp, _IO_STATUS_BLOCK *LocalIoStatus, _IO_STATUS_BLOCK *IoStatusBlock)
{
  int v8; // edx
  int v9; // ST10_4
  int result; // eax

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(0, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v8, v9, 0, a3, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\internal.c", 0x469u, 0);
  }
  result = ReturnedStatus;
  if ( ReturnedStatus == 259 )
  {
    KeWaitForSingleObject(a2, a1, Event, 0, 0, 0, 0);
    result = LocalIoStatus->Status;
  }
  *IoStatusBlock = *LocalIoStatus;
  return result;
}