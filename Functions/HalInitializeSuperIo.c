char __stdcall HalInitializeSuperIo()
{
  unsigned __int8 v0; // al
  unsigned __int8 v1; // al

  __outbyte(0x2Eu, 0x55u);
  __outbyte(0x2Eu, 0x26u);
  v0 = __inbyte(0x2Fu);
  if ( v0 != 46 )
    return 0;
  __outbyte(0x2Eu, 0x27u);
  v1 = __inbyte(0x2Fu);
  if ( v1 )
    return 0;
  __outbyte(0x2Eu, 7u);
  __outbyte(0x2Fu, 4u);
  __outbyte(0x2Eu, 0x30u);
  __outbyte(0x2Fu, 1u);
  __outbyte(0x2Eu, 0x60u);
  __outbyte(0x2Fu, 3u);
  __outbyte(0x2Eu, 0x61u);
  __outbyte(0x2Fu, 0xF8u);
  __outbyte(0x2Eu, 0xAAu);
  return 1;
}