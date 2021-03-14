int __userpurge NtResumeThread@<eax>(int a1@<edx>, _ETHREAD *a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *ThreadHandle, unsigned int *PreviousSuspendCount)
{
  int v6; // edx
  int v7; // ST0C_4
  int result; // eax
  int v9; // edx
  int v10; // ecx
  int v11; // esi
  int v12; // edx
  _ETHREAD *Thread; // [esp+0h] [ebp-4h]

  Thread = a2;
  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v6, v7, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\ps\\psspnd.c", 0x8Du, 0);
  }
  result = ObReferenceObjectByHandle(a1, (int)a2, a3, a4, ThreadHandle, &PsThreadObjectType, (void **)&Thread);
  if ( result >= 0 )
  {
    v11 = KeResumeThread(v10, v9, &Thread->Tcb);
    ObfDereferenceObject(Thread, v12);
    if ( PreviousSuspendCount )
      *PreviousSuspendCount = v11;
    result = 0;
  }
  return result;
}