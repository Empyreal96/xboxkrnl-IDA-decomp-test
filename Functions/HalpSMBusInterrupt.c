int __stdcall HalpSMBusInterrupt()
{
  void *v0; // eax
  int v1; // ecx
  int *retaddr; // [esp+3Ch] [ebp+0h]

  KiPCR = -1;
  HalBeginSMBusInterrupt(0xBu, 15);
  LOBYTE(v0) = __inbyte(0xC000u);
  __outbyte(0xC000u, (unsigned __int8)v0);
  KeInsertQueueDpc(49152, v1, retaddr, &HalpSMBusInterruptDpc, v0, 0);
  _disable();
  return HalEndSystemLevelInterrupt(0xBu, 0);
}