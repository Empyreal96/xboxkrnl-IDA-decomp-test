void __fastcall KiUnlockDispatcherDatabase(KIRQL a1)
{
  KIRQL v1; // ST0C_1
  int v2; // esi
  _KTHREAD *v3; // edi
  char v4; // cl
  char v5; // al
  KIRQL v6; // cl

  if ( !dword_8004C5D8 )
    goto Kiu00;
  if ( a1 >= 2 )
  {
    if ( dword_8004C604 )
    {
Kiu00:
      KfLowerIrql(a1);
      return;
    }
    v1 = a1;
    HalRequestSoftwareInterrupt(2);
    KfLowerIrql(v1);
  }
  else
  {
    v2 = *(&KiPCR + 11);
    v3 = (_KTHREAD *)*(&KiPCR + 10);
    *(&KiPCR + 11) = 0;
    *(&KiPCR + 10) = v2;
    v3->WaitIrql = a1;
    KiReadyThread(v3);
    v4 = v3->WaitIrql;
    v5 = SwapContext((int *)&KiPCR, (int)v3, v2);
    v6 = *(_BYTE *)(v2 + 84);
    if ( v5 )
    {
      KfLowerIrql(1);
      KiDeliverApc();
      v6 = 0;
    }
    KfLowerIrql(v6);
  }
}