void __userpurge PspQueueApcSpecialApc(int *a1@<edi>, int a2@<esi>, _KAPC *Apc, void (__stdcall **NormalRoutine)(void *, void *, void *), void **NormalContext, void **SystemArgument1, void **SystemArgument2)
{
  int v7; // edx
  int v8; // ST0C_4

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v7, v8, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\ps\\psctx.c", 0x20u, 0);
  }
  ExFreePool(Apc);
}