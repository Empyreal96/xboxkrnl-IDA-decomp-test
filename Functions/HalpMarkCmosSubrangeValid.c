int __fastcall HalpMarkCmosSubrangeValid(int a1, int a2)
{
  int result; // eax

  BYTE1(result) = 85;
  do
  {
    __outbyte(0x72u, a2);
    LOBYTE(result) = BYTE1(result);
    __outbyte(0x71u, BYTE1(result));
    BYTE1(result) = ~BYTE1(result);
    ++a2;
    --a1;
  }
  while ( a1 );
  return result;
}