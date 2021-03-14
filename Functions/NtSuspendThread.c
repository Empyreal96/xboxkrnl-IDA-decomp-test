int __userpurge NtSuspendThread@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *ThreadHandle, unsigned int *PreviousSuspendCount)
{
  int v6; // edx
  int v7; // ST0C_4
  int result; // eax
  int v9; // edx
  int v10; // edx
  int LocalPreviousSuspendCount; // [esp+14h] [ebp-20h]
  _ETHREAD *Thread; // [esp+18h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v6, v7, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\ps\\psspnd.c", 0x37u, 0);
  }
  result = ObReferenceObjectByHandle(a1, a2, a3, a4, ThreadHandle, &PsThreadObjectType, (void **)&Thread);
  if ( result >= 0 )
  {
    ms_exc.registration.TryLevel = 0;
    if ( Thread != (_ETHREAD *)thread && Thread->Tcb.HasTerminated )
    {
      ObfDereferenceObject(Thread, v9);
      ms_exc.registration.TryLevel = -1;
      result = -1073741749;
    }
    else
    {
      LocalPreviousSuspendCount = KeSuspendThread((int)Thread, v9, &Thread->Tcb);
      ObfDereferenceObject(Thread, v10);
      if ( PreviousSuspendCount )
        *PreviousSuspendCount = LocalPreviousSuspendCount;
      result = 0;
    }
  }
  return result;
}