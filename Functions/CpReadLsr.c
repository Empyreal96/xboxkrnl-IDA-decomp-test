unsigned __int8 __stdcall CpReadLsr(_CPPORT *Port, char waiting)
{
  unsigned __int8 result; // al

  result = __inbyte(LOWORD(Port->Address) + 5);
  if ( result == -1 )
  {
    if ( (unsigned __int8)++KdDbgErrorCount >= 0x19u )
    {
      KdDbgPortsPresent = 0;
      KdDbgErrorCount = 0;
    }
    result = -1;
  }
  return result;
}