void __stdcall HalpKickoffWriteSMBus(char SlaveAddress, char CommandCode, char NumberOfBytes, unsigned int DataValue)
{
  unsigned __int16 v4; // ax
  unsigned __int8 v5; // al

  __outbyte(0xC004u, SlaveAddress & 0xFE);
  HalpSMBusWriteTransaction = 1;
  HalpSMBusNumberOfBytes = NumberOfBytes;
  HalpSMBusWriteDataValue = DataValue;
  HalpSMBusRetries = 20;
  __outbyte(0xC008u, CommandCode);
  if ( NumberOfBytes == 4 )
    HalpWriteUlongSMBusBlockData(DataValue);
  else
    __outword(0xC006u, DataValue);
  v4 = __inword(0xC000u);
  __outword(0xC000u, v4);
  if ( NumberOfBytes == 4 )
    v5 = 29;
  else
    v5 = (NumberOfBytes == 2) + 26;
  __outbyte(0xC002u, v5);
}