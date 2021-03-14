unsigned int __userpurge PspUnhandledExceptionInSystemThread@<eax>(int *a1@<edi>, _EXCEPTION_POINTERS *ExceptionPointers)
{
  DbgPrint(a1, "PS: Unhandled Kernel Mode Exception Pointers = 0x%p\n", ExceptionPointers);
  DbgPrint(
    a1,
    "Code %x Addr %p\nInfo0 %p Info1 %p Info2 %p Info3 %p\n",
    *(_DWORD *)ExceptionPointers->ep_xrecord,
    *(_DWORD *)(ExceptionPointers->ep_xrecord + 12),
    *(_DWORD *)(ExceptionPointers->ep_xrecord + 20),
    *(_DWORD *)(ExceptionPointers->ep_xrecord + 24),
    *(_DWORD *)(ExceptionPointers->ep_xrecord + 28),
    *(_DWORD *)(ExceptionPointers->ep_xrecord + 32));
  return 0;
}