int __stdcall HalReadSMCTrayState(unsigned int *TrayState, unsigned int *TrayStateChangeCount)
{
  KIRQL v2; // al
  signed int v3; // esi
  int *v4; // edi
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  int v8; // ebx
  KIRQL v9; // al
  unsigned int LocalTrayState; // [esp+Ch] [ebp-4h]

  v2 = KeRaiseIrqlToDpcLevel();
  v3 = HalpTrayState;
  v4 = (int *)HalpTrayStateChangeCount;
  LocalTrayState = HalpTrayState;
  KfLowerIrql(v2);
  if ( v3 == -1 )
  {
    v7 = HalReadSMBusValue(v5, v6, v4, -1, 32, 3, 0, &LocalTrayState);
    v3 = LocalTrayState;
    v8 = v7;
    if ( v7 >= 0 )
    {
      v3 = LocalTrayState & 0x70;
      if ( v3 != 64 && v3 != 96 )
        v3 = 16;
      v9 = KeRaiseIrqlToDpcLevel();
      if ( v4 == (int *)HalpTrayStateChangeCount )
        HalpTrayState = v3;
      KfLowerIrql(v9);
    }
  }
  else
  {
    v8 = 0;
  }
  *TrayState = v3;
  if ( TrayStateChangeCount )
    *TrayStateChangeCount = (unsigned int)v4;
  return v8;
}