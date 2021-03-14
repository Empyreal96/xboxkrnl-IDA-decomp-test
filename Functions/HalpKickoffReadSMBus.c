void __stdcall HalpKickoffReadSMBus(char SlaveAddress, char CommandCode, char NumberOfBytes)
{
  unsigned __int16 v3; // ax
  unsigned __int8 v4; // al

  __outbyte(0xC004u, SlaveAddress | 1);
  __outbyte(0xC008u, CommandCode);
  v3 = __inword(0xC000u);
  HalpSMBusWriteTransaction = 0;
  HalpSMBusNumberOfBytes = NumberOfBytes;
  HalpSMBusRetries = 20;
  __outword(0xC000u, v3);
  if ( NumberOfBytes == 4 )
    v4 = 29;
  else
    v4 = (NumberOfBytes == 2) + 26;
  __outbyte(0xC002u, v4);
}