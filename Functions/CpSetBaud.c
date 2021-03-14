void __stdcall CpSetBaud(_CPPORT *Port, unsigned int Rate)
{
  char *v2; // ecx
  unsigned __int16 v3; // dx
  unsigned __int16 v4; // si
  unsigned __int8 v5; // al
  unsigned int divisorlatch; // [esp+18h] [ebp+Ch]

  v2 = Port->Address;
  v3 = (unsigned __int16)(Port->Address + 3);
  v4 = (unsigned __int16)(Port->Address + 1);
  Port->Baud = Rate;
  divisorlatch = 0x1C200 / Rate;
  v5 = __inbyte(v3);
  __outbyte(v3, v5 | 0x80);
  __outbyte(v4, BYTE1(divisorlatch));
  __outbyte(v4 - 1, divisorlatch);
  __outbyte((_WORD)v2 + 3, 3u);
}