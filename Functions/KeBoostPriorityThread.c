void __userpurge KeBoostPriorityThread(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _KTHREAD *Thread, int Increment)
{
  KIRQL v6; // bl
  char v7; // al
  int v8; // edx

  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x1A9u,
      0);
  v6 = KeRaiseIrqlToDpcLevel();
  v7 = Thread->Priority;
  if ( v7 < 16 && !Thread->PriorityDecrement )
  {
    v8 = Increment + Thread->BasePriority;
    if ( v8 > v7 )
    {
      if ( v8 >= 16 )
        v8 = 15;
      Thread->Quantum = Thread->ApcState.Process->ThreadQuantum;
      KiSetPriorityThread(Thread, v8, a3);
    }
  }
  KiUnlockDispatcherDatabase(v6);
}