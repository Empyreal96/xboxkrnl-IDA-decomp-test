void __stdcall CpPutByte(_CPPORT *Port, char Byte)
{
  _CPPORT *v2; // ecx

  if ( KdDbgPortsPresent )
  {
    v2 = Port;
    while ( !(CpReadLsr(v2, 32) & 0x20) )
      ;
    __outbyte((unsigned __int16)v2->Address, Byte);
  }
}