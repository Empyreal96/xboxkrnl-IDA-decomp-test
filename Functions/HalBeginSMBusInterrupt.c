char __fastcall HalBeginSMBusInterrupt(unsigned int a1, char a2)
{
  char result; // al

  if ( a1 >= 8 )
  {
    result = 98;
    __outbyte(0x20u, 0x62u);
  }
  JUMPOUT(a2, dword_8004C5D0, &Hdsi300);
  LOBYTE(dword_8004C5D0) = a2;
  _enable();
  return result;
}