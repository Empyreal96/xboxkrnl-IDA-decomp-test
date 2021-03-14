void __userpurge IopUserCompletion(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _KAPC *Apc, void (__stdcall **NormalRoutine)(void *, void *, void *), void **NormalContext, void **SystemArgument1, void **SystemArgument2)
{
  int v9; // edx
  int v10; // ST0C_4

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v9, v10, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\internal.c", 0x52Du, 0);
  }
  IoFreeIrp(a2, a1, (_IRP *)&Apc[-2].RundownRoutine);
}