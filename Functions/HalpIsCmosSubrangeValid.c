int __fastcall HalpIsCmosSubrangeValid(int a1, int a2)
{
  int result; // eax

  BYTE1(result) = -86;
  do
  {
    __outbyte(0x72u, a2);
    LOBYTE(result) = __inbyte(0x71u);
    BYTE1(result) = ~BYTE1(result);
    ++a2;
    --a1;
  }
  while ( (_BYTE)result != BYTE1(result) && a1 );
  return result;
}