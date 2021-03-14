int __userpurge PhyInitialize@<eax>(int *a1@<edi>, int forceReset, void *param)
{
  int v5; // edi
  signed int v6; // ebx
  int *v7; // edi
  int result; // eax
  int status; // [esp+4h] [ebp-Ch]
  unsigned int icshack; // [esp+8h] [ebp-8h]
  unsigned int miiStatus; // [esp+Ch] [ebp-4h]

  status = -2145452031;
  _ECX = &PhyLockFlag;
  _EDX = 1;
  __asm { cmpxchg [ecx], edx }
  if ( forceReset )
  {
    v5 = 0x8000;
    PhyInitFlag = 0;
    PhyLinkState = 0;
    forceReset = 0x8000;
    if ( !PhyWriteReg((int *)0x8000, -17825792, ($3A248F961AD0BF30135A1C166837D1FD *)0xFEF00000, 0, 0x8000u) )
      goto err;
    v6 = 1000;
    while ( 1 )
    {
      --v6;
      if ( !(forceReset & 0x8000) )
        break;
      KeStallExecutionProcessor(0x1F4u);
      if ( !PhyReadReg(
              (int *)0x8000,
              -17825792,
              ($3A248F961AD0BF30135A1C166837D1FD *)0xFEF00000,
              0,
              (unsigned int *)&forceReset) )
        goto err;
      if ( !v6 )
      {
        if ( forceReset & 0x8000 )
          goto err;
        break;
      }
    }
LABEL_8:
    v5 = 6000;
    miiStatus = 0;
    do
    {
      --v5;
      if ( miiStatus & 0x20 )
        break;
      KeStallExecutionProcessor(0x1F4u);
      if ( !PhyReadReg((int *)v5, -17825792, ($3A248F961AD0BF30135A1C166837D1FD *)0xFEF00000, 1u, &miiStatus) )
        goto err;
    }
    while ( v5 );
    if ( XboxHardwareInfo.McpRevision != -95
      && PhyReadReg((int *)v5, -17825792, ($3A248F961AD0BF30135A1C166837D1FD *)0xFEF00000, 0x18u, &icshack) )
    {
      BYTE1(icshack) &= 0xFEu;
      PhyWriteReg((int *)v5, -17825792, ($3A248F961AD0BF30135A1C166837D1FD *)0xFEF00000, 0x18u, icshack);
    }
    if ( PhyReadReg(
           (int *)v5,
           -17825792,
           ($3A248F961AD0BF30135A1C166837D1FD *)0xFEF00000,
           0,
           (unsigned int *)&forceReset) )
    {
      v5 = forceReset;
      if ( forceReset & 0x200 )
      {
        DbgPrint((int *)forceReset, "Auto-negotiation didn't succeed.\n");
        if ( miiStatus & 0xA200 )
        {
          v7 = (int *)(v5 & 0xFFFFFFBF | 0x2000);
          PhyLinkState |= 2u;
          goto LABEL_23;
        }
        if ( miiStatus & 0x800 )
        {
          v7 = (int *)(v5 & 0xFFFFDFFF | 0x40);
          PhyLinkState |= 4u;
LABEL_23:
          PhyLinkState |= 0x10u;
          PhyWriteReg(v7, -17825792, ($3A248F961AD0BF30135A1C166837D1FD *)0xFEF00000, 0, (unsigned int)v7);
          if ( PhyWaitForLinkUp(v7, ($3A248F961AD0BF30135A1C166837D1FD *)0xFEF00000) & 4 )
            PhyLinkState |= 1u;
          goto LABEL_25;
        }
      }
      else
      {
        PhyWaitForLinkUp((int *)forceReset, ($3A248F961AD0BF30135A1C166837D1FD *)0xFEF00000);
        if ( PhyUpdateLinkState((int *)v5, ($3A248F961AD0BF30135A1C166837D1FD *)0xFEF00000) )
        {
LABEL_25:
          PhyInitFlag = 1;
          goto LABEL_26;
        }
      }
    }
err:
    DbgPrint((int *)v5, "Ethernet PHY initialization failed.\n");
    goto exit;
  }
  if ( !PhyInitFlag )
    goto LABEL_8;
  PhyUpdateLinkState(a1, ($3A248F961AD0BF30135A1C166837D1FD *)0xFEF00000);
LABEL_26:
  status = 0;
exit:
  result = status;
  PhyLockFlag = 0;
  return result;
}