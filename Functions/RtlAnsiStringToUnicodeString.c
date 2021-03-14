int __fastcall RtlAnsiStringToUnicodeString(int a1, int a2, _UNICODE_STRING *DestinationString, _STRING *SourceString, char AllocateDestinationString)
{
  _STRING *v5; // edi
  unsigned int v6; // eax
  int result; // eax
  bool v8; // zf
  int v9; // ecx
  int *v10; // eax
  int v11; // edi

  v5 = SourceString;
  v6 = 2 * SourceString->Length + 2;
  if ( v6 > 0xFFFF )
    return -1073741584;
  v8 = AllocateDestinationString == 0;
  v9 = 2 * SourceString->Length;
  DestinationString->Length = 2 * SourceString->Length;
  if ( v8 )
  {
    if ( (unsigned __int16)v9 >= DestinationString->MaximumLength )
      return -2147483643;
  }
  else
  {
    DestinationString->MaximumLength = v6;
    v10 = ExAllocatePoolWithTag(a2, v9, (int)DestinationString, v6, 0x67727453u);
    DestinationString->Buffer = (unsigned __int16 *)v10;
    if ( !v10 )
      return -1073741801;
  }
  v11 = RtlMultiByteToUnicodeN(
          DestinationString->Buffer,
          DestinationString->Length,
          (unsigned int *)&SourceString,
          v5->Buffer,
          v5->Length);
  if ( v11 >= 0 )
  {
    DestinationString->Buffer[(unsigned int)SourceString >> 1] = 0;
    result = 0;
  }
  else
  {
    if ( AllocateDestinationString )
    {
      ExFreePool(DestinationString->Buffer);
      DestinationString->Buffer = 0;
    }
    result = v11;
  }
  return result;
}