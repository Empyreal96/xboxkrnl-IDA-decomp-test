void __stdcall HalpDpcForSMBusRetry(_KDPC *Dpc, void *DeferredContext, void *SystemArgument1, void *SystemArgument2)
{
  unsigned __int8 v4; // al

  if ( HalpSMBusWriteTransaction && HalpSMBusNumberOfBytes == 4 )
    HalpWriteUlongSMBusBlockData(HalpSMBusWriteDataValue);
  v4 = __inbyte(0xC002u);
  __outbyte(0xC002u, v4 | 0x18);
}