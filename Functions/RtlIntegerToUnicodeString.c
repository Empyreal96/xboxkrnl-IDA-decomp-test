int __stdcall RtlIntegerToUnicodeString(unsigned int Value, unsigned int Base, _UNICODE_STRING *String)
{
  int result; // eax
  int v4; // ecx
  char ResultBuffer[16]; // [esp+0h] [ebp-18h]
  _STRING AnsiString; // [esp+10h] [ebp-8h]

  result = RtlIntegerToChar(Value, Base, 16, ResultBuffer);
  if ( result >= 0 )
  {
    AnsiString.Buffer = ResultBuffer;
    AnsiString.MaximumLength = 16;
    AnsiString.Length = strlen(ResultBuffer);
    result = RtlAnsiStringToUnicodeString(v4, (int)&ResultBuffer[1], String, &AnsiString, 0);
  }
  return result;
}