void __fastcall HalpWriteUlongSMBusBlockData(unsigned int DataValue)
{
  __outbyte(0xC009u, DataValue);
  __outbyte(0xC009u, BYTE1(DataValue));
  __outbyte(0xC009u, BYTE2(DataValue));
  __outbyte(0xC009u, HIBYTE(DataValue));
  __outbyte(0xC006u, 4u);
}