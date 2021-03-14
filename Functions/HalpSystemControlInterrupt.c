int __stdcall HalpSystemControlInterrupt()
{
  int v0; // ecx
  unsigned __int8 v1; // al
  unsigned __int8 v2; // al
  unsigned __int8 v3; // al
  int *retaddr; // [esp+3Ch] [ebp+0h]

  KiPCR = -1;
  HalBeginSMBusInterrupt(0xCu, 27);
  v1 = __inbyte(0x8000u);
  v2 = v1 & 1;
  if ( v2 )
  {
    __outbyte(0x8000u, v2);
    HalpAcpiTimerCarry();
  }
  v3 = __inbyte(0x8020u);
  if ( v3 & 2 )
  {
    __outbyte(0x8020u, 2u);
    KeInsertQueueDpc(32800, v0, retaddr, &HalpSystemControlInterruptDpc, 0, 0);
  }
  _disable();
  return HalEndSystemLevelInterrupt(0xCu, 0);
}