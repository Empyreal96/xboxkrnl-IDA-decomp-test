unsigned __int16 __stdcall CpGetByte(_CPPORT *Port, char *Byte, char WaitForByte)
{
  unsigned __int16 result; // ax
  unsigned __int8 v4; // al
  int v5; // ecx
  char v6; // al

  if ( !Port->Address )
    return 1;
  if ( KdDbgPortsPresent )
    goto LABEL_6;
  if ( CpReadLsr(Port, 1) != -1 )
  {
    CpSetBaud(Port, Port->Baud);
    KdDbgPortsPresent = 1;
LABEL_6:
    if ( (WaitForByte != 0 ? 0x18FFF : 0) == -1 )
    {
LABEL_10:
      CpReadLsr(Port, 0);
    }
    else
    {
      while ( 1 )
      {
        v4 = CpReadLsr(Port, 1);
        if ( v4 == -1 )
          break;
        if ( v4 & 1 )
        {
          if ( v4 & 0xE )
          {
            *Byte = 0;
            result = 2;
          }
          else
          {
            v6 = __inbyte((unsigned __int16)Port->Address);
            *Byte = v6;
            result = 0;
          }
          return result;
        }
        if ( !v5 )
          goto LABEL_10;
      }
    }
  }
  return 1;
}