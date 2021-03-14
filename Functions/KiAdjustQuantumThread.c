void __userpurge KiAdjustQuantumThread(int *a1@<edi>, _KTHREAD *Thread)
{
  char v2; // bl
  char v3; // dl
  char v4; // al
  _KTHREAD *v5; // eax

  v2 = Thread->Priority;
  if ( v2 < 16 )
  {
    v3 = Thread->BasePriority;
    if ( v3 < 14 )
    {
      Thread->Quantum -= 10;
      if ( Thread->Quantum <= 0 )
      {
        Thread->Quantum = Thread->ApcState.Process->ThreadQuantum;
        v4 = v2 - Thread->PriorityDecrement - 1;
        if ( v4 < v3 )
          v4 = v3;
        Thread->PriorityDecrement = 0;
        if ( v4 == v2 )
        {
          if ( !dword_8004C5D8 )
          {
            v5 = KiFindReadyThread(v4);
            if ( v5 )
            {
              dword_8004C5D8 = (int)v5;
              v5->State = 3;
            }
          }
        }
        else
        {
          KiSetPriorityThread(Thread, v4, a1);
        }
      }
    }
  }
}