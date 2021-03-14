char __usercall KiDispatchInterrupt@<al>(int a1@<edx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
  _KTHREAD *v4; // eax
  int v5; // esi
  _KTHREAD *v6; // edi
  int v8; // [esp+4h] [ebp-8h]
  int v9; // [esp+8h] [ebp-4h]

  v4 = (_KTHREAD *)(&KiPCR + 20);
  _disable();
  if ( v4 != *(_KTHREAD **)&v4->Header.Type )
  {
    v8 = KiPCR;
    KiPCR = -1;
    LOBYTE(v4) = KiRetireDpcList(&KiPCR, (_DWORD **)&KiPCR + 20, a3, a4);
    KiPCR = v8;
  }
  _enable();
  if ( *(&KiPCR + 24) )
  {
    *(&KiPCR + 24) = 0;
    v4 = KiQuantumEnd(a2, a1);
    if ( v4 )
      goto kdi60;
  }
  else if ( *(&KiPCR + 11) )
  {
    v4 = (_KTHREAD *)*(&KiPCR + 11);
kdi60:
    v9 = a4;
    v8 = a3;
    v5 = (int)v4;
    v6 = (_KTHREAD *)*(&KiPCR + 10);
    *(&KiPCR + 11) = 0;
    *(&KiPCR + 10) = (unsigned int)v4;
    KiReadyThread(v6);
    LOBYTE(v4) = SwapContext((int *)&KiPCR, (int)v6, v5);
    return (char)v4;
  }
  return (char)v4;
}