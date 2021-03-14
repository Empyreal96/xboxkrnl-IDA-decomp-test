void __userpurge IopUserRundown(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _KAPC *Apc)
{
  int v5; // edx
  int v6; // ST0C_4

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v5, v6, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\internal.c", 0x54Eu, 0);
  }
  IoFreeIrp(a2, a1, (_IRP *)&Apc[-2].RundownRoutine);
}