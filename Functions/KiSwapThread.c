int __cdecl KiSwapThread()
{
  _KTHREAD *v0; // edx
  signed int v1; // ecx
  unsigned int v2; // esi
  unsigned int v3; // esi
  int v4; // ecx
  int v5; // esi
  signed int v6; // edi
  bool v7; // sf
  _DWORD *v8; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // ebp
  _KTHREAD *v11; // esi
  int v12; // edi
  char v13; // cl
  char v14; // al
  int v15; // edi
  KIRQL v16; // cl

  v0 = (_KTHREAD *)*(&KiPCR + 11);
  if ( !v0 )
  {
    v1 = 16;
    v2 = KiReadySummary >> 16;
    if ( !(KiReadySummary >> 16) )
    {
      v1 = 0;
      v2 = KiReadySummary;
    }
    if ( v2 >> 8 )
      v1 += 8;
    v3 = KiReadySummary >> v1;
    v4 = v1 + 3;
    if ( v3 >= 0x10 )
      v4 += 4;
    v5 = v4;
    v6 = KiReadySummary << ~(_BYTE)v4;
    v7 = v6 < 0;
    while ( !v7 )
    {
      --v5;
      v6 *= 2;
      v7 = v6 < 0;
      if ( !v6 )
      {
        KiIdleSummary = 1;
        v0 = &KiIdleThread;
        goto Swt140;
      }
    }
    v8 = *(_DWORD **)(8 * v5 - 2147151840);
    v0 = (_KTHREAD *)(*(_DWORD *)(8 * v5 - 2147151840) - 92);
    v9 = (_DWORD *)*v8;
    v10 = (_DWORD *)v8[1];
    *v10 = *v8;
    v9[1] = v10;
    if ( v9 == v10 )
      KiReadySummary ^= 1 << v5;
  }
Swt140:
  v11 = v0;
  v12 = *(&KiPCR + 10);
  *(&KiPCR + 11) = 0;
  *(&KiPCR + 10) = (unsigned int)v0;
  v13 = *(_BYTE *)(v12 + 84);
  v14 = SwapContext((int *)&KiPCR, v12, (int)v0);
  v15 = v11->WaitStatus;
  v16 = v11->WaitIrql;
  if ( v14 )
  {
    KfLowerIrql(1);
    KiDeliverApc();
    v16 = 0;
  }
  KfLowerIrql(v16);
  return v15;
}