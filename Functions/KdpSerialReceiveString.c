unsigned int __stdcall KdpSerialReceiveString(char *Destination, unsigned int Length)
{
  char *v2; // esi
  unsigned int result; // eax

  if ( !Length )
    return 0;
  v2 = Destination;
  while ( 1 )
  {
    result = KdPortGetByte((char *)&Destination + 3);
    if ( result )
      break;
    *v2++ = HIBYTE(Destination);
    if ( !--Length )
      return 0;
  }
  return result;
}