void __userpurge NtUserIoApcDispatcher(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *ApcContext, _IO_STATUS_BLOCK *IoStatusBlock, unsigned int Reserved)
{
  unsigned int v7; // eax
  unsigned int v8; // ecx

  if ( (_BYTE)dword_8004C5D0 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == PASSIVE_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\io\\misc.c",
      0x1A7u,
      0);
  if ( (IoStatusBlock->Status & 0xC0000000) == -1073741824 )
  {
    v7 = RtlNtStatusToDosError(IoStatusBlock->Status);
    v8 = 0;
  }
  else
  {
    v8 = IoStatusBlock->Information;
    v7 = 0;
  }
  ((void (__stdcall *)(unsigned int, unsigned int, _IO_STATUS_BLOCK *))ApcContext)(v7, v8, IoStatusBlock);
}